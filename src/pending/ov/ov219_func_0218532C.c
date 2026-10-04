/*
 * function: func_0218532C
 * address:  0x0218532C
 * packet:   pkt_ov219_0218532C
 * region:   ov219
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   DIFF
 * 2026-10-04 (wD2 lane 09): 284 vs 288 bytes, 163 bytes differ, same frame.
 * Semantics read from the listing (x,y at +0xC2F4/+0xC2F8, count at +0x14,
 * 0x30-byte records, s16 fields +0x18/+0x1a, u16 flag +0x40). Residue: the
 * original keeps only lo2 (r6) in a register and spills ylo/yhi/hi2; ours puts
 * yhi in r6, so the wrap test and the range test swap order, and the loop
 * colours ex/ey/e as r1/r2/r0 instead of r0/r1/r2. Tried: lo2/hi2 set through
 * y16 before the temp (89->163 bytes better than the first draft), declaring
 * lo2/hi2 first (169, worse). Not tried: wrap test through different locals.
 *
 * symbols:
 *   func_02185D08  0x02185D08  thumb  ov219
 *   func_02185D64  0x02185D64  thumb  ov219
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef short s16;

extern void func_02185D08(int *p);
extern u32 func_02185D64(int *p, int *q);

int func_0218532C(char *p, u32 *out)
{
    int ret = 0;
    int xlo, xhi, ylo, yhi, lo2, hi2;
    u32 i;
    u32 best;
    u32 bestd;
    int cur[2];
    int cx, cy;

    cx = *(int *)(p + 0xC2F4);
    cy = *(int *)(p + 0xC2F8);
    xlo = (s16)(cx - 0x80);
    xhi = (s16)(cx + 0x80);
    ylo = (s16)(cy - 0x80);
    yhi = (s16)(cy + 0x80);
    best = *(u32 *)(p + 0x14);
    bestd = 0x100;
    cur[0] = cx;
    cur[1] = cy;
    func_02185D08(cur);
    {
        int d = yhi - ylo;
        if (d < 0) d = -d;
        if (d > 0x100) {
            int y16 = (s16)*(int *)(p + 0xC2F8);
            int t;
            lo2 = y16;
            hi2 = y16;
            t = (y16 > 0) ? y16 - 0x10000 : y16 + 0x10000;
            ylo = yhi = t;
            lo2 -= 0x80;
            hi2 += 0x80;
            ylo -= 0x80;
            yhi += 0x80;
        } else {
            lo2 = ylo;
            hi2 = yhi;
        }
    }
    for (i = 0; i < *(u32 *)(p + 0x14); i++) {
        char *e = p + i * 0x30;
        int ex = *(s16 *)(e + 0x18);
        if (ex > xlo && ex < xhi) {
            int ey = *(s16 *)(e + 0x1a);
            if ((ey > ylo && ey < yhi) || (ey > lo2 && ey < hi2)) {
                if (*(u16 *)(e + 0x40) != 0) {
                    int pt[2];
                    u32 dd;
                    pt[0] = ex;
                    pt[1] = *(s16 *)(e + 0x1a);
                    func_02185D08(pt);
                    dd = func_02185D64(cur, pt);
                    if (dd < bestd) {
                        bestd = dd;
                        best = i;
                    }
                }
            }
        }
    }
    *out = best;
    if (best != *(u32 *)(p + 0x14))
        ret = 1;
    return ret;
}
