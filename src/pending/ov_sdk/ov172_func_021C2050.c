/*
 * function: func_021C2050
 * address:  0x021C2050
 * packet:   pkt_ov172_021C2050
 * region:   ov172
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   DIFF
 * blocker:  measures DIFF (96/96, 35 concrete bytes), not MATCH: the whole loop
 *           body is one register rotation.  sdkobj confirms the vendor object is
 *           Metrowerks 4.0.0.1024 -> dsi/1.1p1 and its listing is byte-identical
 *           to the image, so the residue is a source shape this front end has
 *           not been given.  All body arithmetic instructions match opcode for
 *           opcode; the image homes the shared `ybuf + y` loop-invariant in r4
 *           (callee-saved) and the loaded yuyv in r1 (the dead `width` home),
 *           ours does the reverse (temp r1, yuyv r8) and the middle store's
 *           base/index are swapped.  Wave7 tried &ybuf[y+y], ybuf+(y<<1),
 *           2*y, (ybuf+y)+y, ybuf+(y+y), a named cb/yy temp, *(ybuf+y+x),
 *           crbuf-y+x, x!=y and while forms: none below 35.
 *
 * w9_nm: still 35 B. Tried: explicit cbbuf pointer (base + y, then + y), DWARF declaration order, size split (y = w*h; y >>= 1), while form, three result locals computed then stored, post-increment split. The object keeps yuyv in r1 (the width register), the Cb base in r4, and computes the third pair's masked half before the first store.
 *
 * Lane U38 (2026-09-30): ten more shapes, none below 35 (named Cb base `cbuf`
 * + `crbuf = cbuf + y` 43, the same declared first 41, `*(ybuf + y + x)` 35,
 * `(ybuf + y)[x]` malformed, DWARF (forward) declaration order 40, 44 for
 * y declared last, block-scoped `yuyv` inside the loop 35, `crbuf += y` 35,
 * combined forms 35).  Exact residue, first divergence +000C:
 *   image `add r4, r3, ip, lsl #1` | ours `add r1, r3, ip, lsl #1`
 * i.e. the loop word gets r1 (the register `width` died in) and the Cb base
 * (dst + 2y) gets r4, with the middle store `strh r8, [r3, r7]` /
 * `strh r6, [r4, r7]` / `strh r1, [lr, r7]`; ours has the Cb base in r1, the
 * word in r8, and the middle store as `strh r6, [r7, r1]` (base/index
 * swapped).  Both use the same push set and the same scratch registers, so
 * this is one colouring tie, not pressure.
 *
 * sdk:      SSP_YUV422ToYUV888 (jpegenc.o)
 *
 * symbols:
 *   (none)
 */

void func_021C2050(void *src, unsigned long width, unsigned long height, void *dst)
{
    unsigned long yuyv;
    unsigned long x;
    unsigned long y;
    unsigned long *pYuyv;
    unsigned short *ybuf;
    unsigned short *crbuf;

    pYuyv = (unsigned long *)src;
    ybuf = (unsigned short *)dst;
    y = (width * height) >> 1;
    crbuf = ybuf + y + y;
    for (x = 0; x < y; x++) {
        yuyv = *pYuyv++;
        ybuf[x] = (yuyv & 0xff) | ((yuyv & 0xff0000) >> 8);
        ybuf[y + x] = ((yuyv & 0xff00) >> 8) | (yuyv & 0xff00);
        crbuf[x] = ((yuyv & 0xff000000) >> 16) | (yuyv >> 24);
    }
}
