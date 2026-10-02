/*
 * function: func_02156B18
 * address: 0x02156B18
 * packet: pkt_ov009_02156B18
 * region: ov009
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   g_021A8264 0x021A8264 data ov009 a4
 *   func_02155D2C 0x02155D2C thumb ov009
 * The fifth input is visibly loaded into r0 before the call.
 */
typedef unsigned char u8;
extern u8 *g_021A8264;
extern void func_02155D2C(int);
void func_02156B18(int a, int b, int c, int d, int e)
{
    *(int *)(g_021A8264 + 0x778) = 0;
    if (a == 0 && b == 0)
        func_02155D2C(e);
}
