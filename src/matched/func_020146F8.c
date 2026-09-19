/*
 * function: func_020146F8
 * address:  0x020146F8
 * packet:   pkt_02014628
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Promoted from src/pending/ (which was capped at MATCH on the ABS32 to
 * func_02014628) by filing func_02014628 itself: its EXACT manifest entry is
 * the outside witness that site needed.  The pending copy is left in place
 * and is now redundant.
 */

typedef unsigned int u32;

extern void *func_020122C0(char *a0, int a1, int a2, int a3);
extern u32 *func_020124E8(void);
extern void func_02014628(void);

void *func_020146F8(char *a0, int a1, int a2, int a3, int a4)
{
    void *r = func_020122C0(a0, 0, (int)func_02014628, 0x14);
    u32 *p = func_020124E8();

    p[0] = (u32)a0;
    p[1] = a1;
    p[2] = a2;
    p[3] = a3;
    p[4] = a4;
    return r;
}
