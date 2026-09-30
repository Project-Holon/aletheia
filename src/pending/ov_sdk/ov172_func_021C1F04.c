/*
 * function: func_021C1F04
 * address:  0x021C1F04
 * packet:   pkt_ov172_021C1F04
 * region:   ov172
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   DIFF
 *
 * sdk:      SSP_RGB555ToYUV888 (libssp.TWL.HYB.a jpegenc.o)
 *
 * RGB555 -> planar YCbCr (three padded planes, stride (w+7)&~7).
 *
 * Lane U28 (2026-09-30): rewritten from the vendor DWARF, replacing the flat
 * `i % stride` draft.  DWARF locals, in source declaration order (the reverse
 * of sdkobj.py's print): j, x, y, pRgb, ybuf, crbuf, image_width, rr, gg, bb.
 * Measured against the image (332 bytes):
 *   222 concrete bytes  flat draft (`u32 i`, `i % stride`, d0/d1/d2[], r/g/b)
 *   260 concrete bytes  + the DWARF locals but with an explicit
 *                       `if (y == 0) return;`   (344 bytes: the guard and the
 *                       `for` entry test both survive -> cmp+addls+popls)
 *    37 concrete bytes  this file (332 bytes, size EXACT)
 * The one lever that mattered: do NOT write the `y == 0` guard.  The `for`
 * entry test is rotated and folds straight into the `muls r8, sl, r1` flags,
 * which is exactly the image's `addeq sp, sp, #0x10 / popeq {...}`.  The four
 * literal-pool words (0x1d3, 0x4c9, 0x964, 0x80800) and the whole constant
 * setup (+0x3C..+0x64) now match the image byte for byte.
 *
 * Residue (one allocation tie, three registers + its knock-ons):
 *   +0x0008  image `mov r5, r1`   | ours `mov r6, r1`   (width)
 *   +0x0028  image `mov r6, r0`   | ours `mov r7, r0`   (pRgb)
 *   +0x0030  image `mov r7, #0`   | ours `mov r5, #0`   (x)
 * i.e. the image colours {width, pRgb, x} = {r5, r6, r7} in declaration order,
 * ours = {r6, r7, r5}; x gets the lowest register here.  Everything else in
 * the 37 bytes follows from it (+0x0068/0x0074/0x0078/0x00BC/0x00EC/0x011C/
 * 0x0124/0x0128/0x012C and the gg/rr mask pair at +0x0084..0x0090).
 * Also differing: +0x0020 image `add r4, r3, r8` | ours `add r4, r8, r3` (the
 * Cb-plane base; same encoding, different canonical operand order).
 *
 * Tried this lane, none below 37 (all 332 bytes unless noted): 9 local
 * declaration orders (x before j, pointers first), `j = x % image_width;` as a
 * separate statement, crbuf = ybuf + y * 2 (336), y = hpad * image_width,
 * ybuf[x + y], `((u16 *)((u8 *)ybuf + y))[x]` (340), a while loop (284), and
 * the three store orders (Cb first, Cr first).
 *
 * symbols:
 *   _u32_div_f  0x0209C2B0  arm
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/ov_sdk/ov172_func_021C1F04.c \
 *     --func func_021C1F04 --addr 0x021C1F04 --region ov172 --arm --cc 1.1p1 \
 *     --lang c99 --diff
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern u32 _u32_div_f(u32, u32);

void func_021C1F04(void *src, u32 width, u32 height, void *dst)
{
    u32 j;
    u32 x;
    u32 y;
    u16 *pRgb;
    u8 *ybuf;
    u8 *crbuf;
    u32 image_width;
    u32 rr;
    u32 gg;
    u32 bb;

    image_width = (width + 7) & ~7;
    y = image_width * ((height + 7) & ~7);
    pRgb = (u16 *)src;
    ybuf = (u8 *)dst;
    crbuf = ybuf + y + y;
    for (x = 0; x < y; x++) {
        bb = (x % image_width < width) ? *pRgb : 0;
        gg = (bb & 0x3e0) >> 2;
        rr = (bb & 0x1f) << 3;
        bb = (bb & 0x7c00) >> 7;
        ybuf[x] = (u8)((gg * 0x964 + rr * 0x4c9 + bb * 0x1d3 + 0x800) >> 12);
        j = (0x80800 - rr * 0x2b3 - gg * 0x54d + (bb << 11)) >> 12;
        if (j > 0xff)
            j = 0xff;
        ybuf[y + x] = (u8)j;
        j = ((rr << 11) + 0x80800 - gg * 0x6b3 - bb * 0x14d) >> 12;
        if (j > 0xff)
            j = 0xff;
        crbuf[x] = (u8)j;
        if (x % image_width < width)
            pRgb++;
    }
}
