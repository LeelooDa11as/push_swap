#!/usr/bin/env python3
"""Generate a small push_swap stack animation as a GIF using only stdlib."""
from pathlib import Path

WIDTH, HEIGHT = 420, 260
SCALE = 2
OUT = Path(__file__).resolve().parents[1] / "assets" / "push_swap_radix_pass.gif"

# 8-color global palette: white, black, gray, light gray, red, blue, green, orange
PALETTE = [
    (255, 255, 255), (25, 25, 25), (140, 140, 140), (235, 235, 235),
    (229, 79, 79), (75, 130, 220), (74, 170, 96), (239, 172, 70),
]
PALETTE_BYTES = bytes(c for rgb in PALETTE for c in rgb) + bytes(3 * (256 - len(PALETTE)))
COLORS = {0: 4, 1: 5, 2: 6, 3: 7}

# Tiny 3x5 font, scaled for labels.
FONT = {
    "A": ["010", "101", "111", "101", "101"], "B": ["110", "101", "110", "101", "110"],
    "I": ["111", "010", "010", "010", "111"], "T": ["111", "010", "010", "010", "010"],
    "P": ["110", "101", "110", "100", "100"], "R": ["110", "101", "110", "101", "101"],
    "S": ["011", "100", "010", "001", "110"], "H": ["101", "101", "111", "101", "101"],
    "U": ["101", "101", "101", "101", "111"], "O": ["111", "101", "101", "101", "111"],
    "N": ["101", "111", "111", "111", "101"], "E": ["111", "100", "110", "100", "111"],
    "X": ["101", "101", "010", "101", "101"], " ": ["000", "000", "000", "000", "000"],
    "0": ["111", "101", "101", "101", "111"], "1": ["010", "110", "010", "010", "111"],
    "2": ["111", "001", "111", "100", "111"], "3": ["111", "001", "111", "001", "111"],
    "-": ["000", "000", "111", "000", "000"], ":": ["000", "010", "000", "010", "000"],
}

def put_rect(pix, x, y, w, h, color):
    for yy in range(max(0, y), min(HEIGHT, y + h)):
        row = yy * WIDTH
        for xx in range(max(0, x), min(WIDTH, x + w)):
            pix[row + xx] = color

def put_text(pix, x, y, text, color=1, scale=3):
    cx = x
    for ch in text.upper():
        glyph = FONT.get(ch, FONT[" "])
        for gy, line in enumerate(glyph):
            for gx, bit in enumerate(line):
                if bit == "1":
                    put_rect(pix, cx + gx * scale, y + gy * scale, scale, scale, color)
        cx += 4 * scale

def draw_frame(a, b, note):
    pix = bytearray([0] * (WIDTH * HEIGHT))
    put_text(pix, 18, 16, "PUSH SWAP - RADIX BIT 1", 1, 3)
    put_text(pix, 48, 57, "STACK A", 1, 3)
    put_text(pix, 270, 57, "STACK B", 1, 3)
    put_text(pix, 18, 228, note, 1, 2)
    # stack lanes
    put_rect(pix, 36, 82, 150, 130, 3)
    put_rect(pix, 256, 82, 130, 130, 3)
    for x in (36, 186, 256, 386):
        put_rect(pix, x, 82, 2, 130, 2)
    put_rect(pix, 36, 212, 152, 2, 2)
    put_rect(pix, 256, 212, 132, 2, 2)

    def draw_stack(vals, x0):
        for i, val in enumerate(reversed(vals)):
            y = 190 - i * 28
            width = 35 + val * 22
            put_rect(pix, x0, y, width, 20, COLORS[val])
            put_rect(pix, x0, y, width, 2, 1)
            put_rect(pix, x0, y + 18, width, 2, 1)
            put_text(pix, x0 + width + 8, y + 4, str(val), 1, 2)
    draw_stack(a, 58)
    draw_stack(b, 278)
    return bytes(pix)

def lzw_encode(indices, min_code_size=8):
    clear = 1 << min_code_size
    end = clear + 1
    code_size = min_code_size + 1
    next_code = end + 1
    dictionary = {(i,): i for i in range(clear)}
    codes = [clear]
    w = ()
    for k in indices:
        wk = w + (k,)
        if wk in dictionary:
            w = wk
        else:
            codes.append(dictionary[w])
            if next_code < 4096:
                dictionary[wk] = next_code
                next_code += 1
                if next_code == (1 << code_size) and code_size < 12:
                    code_size += 1
            else:
                codes.append(clear)
                dictionary = {(i,): i for i in range(clear)}
                code_size = min_code_size + 1
                next_code = end + 1
            w = (k,)
    if w:
        codes.append(dictionary[w])
    codes.append(end)

    out = bytearray()
    cur = 0
    bits = 0
    code_size = min_code_size + 1
    next_code = end + 1
    for code in codes:
        cur |= code << bits
        bits += code_size
        while bits >= 8:
            out.append(cur & 0xFF)
            cur >>= 8
            bits -= 8
        if code == clear:
            code_size = min_code_size + 1
            next_code = end + 1
        else:
            next_code += 1
            if next_code == (1 << code_size) and code_size < 12:
                code_size += 1
    if bits:
        out.append(cur & 0xFF)
    return bytes(out)

def blocks(data):
    return b"".join(bytes([len(data[i:i + 255])]) + data[i:i + 255] for i in range(0, len(data), 255)) + b"\x00"

def make_gif(frames):
    header = b"GIF89a" + WIDTH.to_bytes(2, "little") + HEIGHT.to_bytes(2, "little") + b"\xF7\x00\x00" + PALETTE_BYTES
    loop = b"\x21\xFF\x0BNETSCAPE2.0\x03\x01\x00\x00\x00"
    body = bytearray(header + loop)
    for pixels, delay in frames:
        body += b"\x21\xF9\x04\x04" + delay.to_bytes(2, "little") + b"\x00\x00"
        body += b"\x2C\x00\x00\x00\x00" + WIDTH.to_bytes(2, "little") + HEIGHT.to_bytes(2, "little") + b"\x00"
        body += b"\x08" + blocks(lzw_encode(pixels, 8))
    body += b";"
    return bytes(body)

def main():
    states = [
        ([3, 0, 2, 1], [], "START: A HAS INDEXED INPUT"),
        ([0, 2, 1, 3], [], "3 HAS BIT 1: RA"),
        ([2, 1, 3], [0], "0 HAS BIT 0: PB"),
        ([1, 3], [2, 0], "2 HAS BIT 0: PB"),
        ([3, 1], [2, 0], "1 HAS BIT 1: RA"),
        ([2, 3, 1], [0], "PA: RETURN FROM B"),
        ([0, 2, 3, 1], [], "PA: PASS COMPLETE"),
    ]
    frames = [(draw_frame(a, b, note), 90) for a, b, note in states]
    OUT.parent.mkdir(exist_ok=True)
    OUT.write_bytes(make_gif(frames))
    print(f"wrote {OUT.relative_to(Path.cwd())}")

if __name__ == "__main__":
    main()
