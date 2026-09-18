/*
 * function: func_02072894
 * address:  0x02072894
 * packet:   pkt_02072894
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   MATCH
 * blocker:  label class: 0x0208A0A4 (SDK) has exactly one caller in the image
 *           and it is this function, so no branch outside 0x02072894..0x020728E8
 *           witnesses it.  Every concrete byte reproduces.
 *
 * symbols:
 *   g_0214BAC0   0x0214BAC0  data
 *   g_0214BB00   0x0214BB00  data
 *   func_0208A0A4 0x0208A0A4  arm
 *
 * r1 (b) is parked in lr as soon as it is read, because the predicated
 * `ldrge r1, [pc]` that materialises the table base clobbers r1 before the
 * call; the fourth argument (c) is copied into r3 first for the same reason,
 * r2 being needed for b again at the call.
 */

typedef unsigned char  u8;
typedef signed char    s8;
typedef unsigned int   u32;

extern s8  g_0214BAC0[];
extern u8  g_0214BB00[];
extern u32 func_0208A0A4(u8 *, u32, u32, u32);

u32 func_02072894(u32 a, u32 b, u32 c)
{
    s8 idx = g_0214BAC0[0];
    u8 *p;

    if (idx < 0) p = 0;
    else         p = g_0214BB00 + idx * 0x11E0;
    if (p == 0) return 0;
    return func_0208A0A4(p, a, b, c);
}
