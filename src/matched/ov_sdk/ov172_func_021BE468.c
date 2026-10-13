/*
 * function: func_021BE468
 * address:  0x021BE468
 * packet:   pkt_ov172_021BE468
 * region:   ov172
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * wave7: sdkobj confirms the object is Metrowerks 4.0.0.1024 -> dsi/1.1p1 and its
 *        322-byte listing is byte-identical to the image, with DWARF locals
 *        result(r0), b(r0), s(r0), p([fb+0]) (reverse source: p, s, b, result),
 *        which the draft already matches.  The residue is confined to the three
 *        table clears: the image materialises each pointer immediately before
 *        its own strh and assigns r3=D, r0=C, r2=B, ours hoists the three ldrs
 *        (r0, r2, r3) and sinks the B store past the MIi_CpuClearFast argument
 *        setup.  The 6 chain permutations and 5 other clear-block spellings
 *        already measured here stay at 21-31; wave7 found no source shape for
 *        the interleave under 1.1p1.
 *
 * sdk:      Mel_JPEGDecodeExif (libssp.TWL.HYB.a jpegdec.o)
 *
 * symbols:
 *   MIi_CpuClearFast  0x02082AC0  arm
 *   func_021C0BB4  0x021C0BB4  arm  ov172
 *   g_021C88F0     0x021C88F0  data
 *   g_021C8D1C     0x021C8D1C  data ov172
 *   g_021C8C1C     0x021C8C1C  data ov172
 *   g_021C8B1C     0x021C8B1C  data ov172
 *   g_021C959C     0x021C959C  data ov172
 *
 * Static: clears the decoder state, validates the SOI marker and walks the marker segments until
 * the APP1 (Exif) segment, which SSP_ExifDecode parses.
 *
 * Lane U8 (2026-09-30): the three table clears are written in the order the image's *literal pool*
 * holds them (0x021C8C1C, 0x021C8B1C, 0x021C8D1C), not the order the image's `strh` stores run in.
 * With that order our pool AND our store order both come out exactly as the image's (the previous
 * order had the pool rotated and the stores reversed, which is what the "pool vs stores" note in
 * docs/notes/lane_t9_ov172_sdk_rows.md was recording). 34 -> 31 concrete bytes; the whole body from
 * +0x4C on was and stays byte-identical.
 * Residue: the prologue block only, two clusters.
 *   +0x0014  image `mov r8, r0` | ours `mov r6, r2`   (parameter home-copies come out in the
 *            order option, length, a; the image uses a, option, length. Same destination registers.)
 *   +0x0020  image `ldr r3, [pc, #0x124]` | ours `ldr r2, [pc, #0x124]`  (which register each of the
 *            four prologue pointers lands in, and the interleave of loads/stores: the image keeps
 *            `mov r0, r5` / `mov r2, #0x1000` for the call at +0x40/+0x44, ours hoists them to
 *            +0x38/+0x3C, which is why r0 is not free for the third pointer.)
 * Tried and rejected this lane (all compile, none below 31): every permutation of the three clears
 * (6), the call moved before/inside the clears, `bits = 0` moved after the clears, three spellings
 * of the call arguments, a comma-joined clear statement, and two local declaration orders.
 * Declaration order is confirmed by DWARF (locals listed result, b, s, p = reverse source order).
 *
 * Lane U67 (2026-09-30): the three clears are a *chained assignment*
 *   `g_021C8C1C[0x40] = g_021C8D1C[0] = g_021C8B1C[0] = 0;`
 * That single change fixed the parameter home-copies (+0x14..+0x1C now `mov r8,r0` / `mov r6,r2` /
 * `mov r7,r1` exactly as the image) and keeps the correct literal pool and store order; 31 -> 21
 * concrete bytes.  Measured over all 6 chain permutations (21/22/23/23/24 diffs; only the
 * `C1C = D1C = B1C` order gives the image's pool D,C,B *and* store order D,C,B — and only the chained
 * form reproduces the image's home-copy order at all; the same order written as three statements
 * gives the right pool/stores but the copies come out option,length,a for 31).
 * Remaining 21 bytes, all inside the clear block at +0x20..+0x44: the image materialises each
 * pointer immediately before its own `strh` (ldr r3/sth, ldr r0/sth, ldr r2/sth, then the call's
 * `mov r0,r5` / `mov r2,#0x1000`), ours issues the three `ldr`s first and sinks the second and third
 * `strh` past the call-argument setup.  Register rotation is a consequence: image r3,r0,r2 | ours
 * r0,r2,r3.  `bits = 0` before vs after the chain, parenthesised/cast forms of the chain and the
 * esc/bits store order do not move it.
 */

typedef struct {
    int byte;
    unsigned int pad0;
    unsigned int length;
    unsigned int esc;
    unsigned int bits;
} BitState;

extern BitState g_021C88F0;
extern short g_021C8B1C[];
extern unsigned char g_021C959C[];
extern void MIi_CpuClearFast(unsigned long data, void *destp, unsigned long size);
extern long func_021C0BB4(unsigned char *src, unsigned long src_size, int *cur, int option);

int func_021BE468(unsigned char *a, unsigned long length, int option)
{
    int p;
    int s;
    unsigned char b;
    long result;

    g_021C88F0.esc = 0;
    g_021C88F0.bits = 0;
    g_021C8B1C[0] = g_021C8B1C[0xC0] = g_021C8B1C[0x100] = 0;
    MIi_CpuClearFast(0, g_021C959C, 0x1000);
    g_021C88F0.length = length;
    if (length <= 2) return 0;
    if (a[0] != 0xFF || a[1] != 0xD8) return 0;
    p = 2;
    while ((unsigned long)(p + 1) < length) {
        s = a[p++];
        if (s == 0xFF) {
            b = a[p++];
            if (b == 0xD9) break;
            if ((unsigned long)(p + 1) >= length) return 0;
            s = (a[p] << 8) | a[p + 1];
            if (b == 0xE1) {
                result = func_021C0BB4(a, length, &p, option);
                if (result != 0 && result != 1) return 0;
                break;
            }
            p += s;
        }
    }
    return -(p <= g_021C88F0.length);
}
