/*
 * function: func_02177704
 * address: 0x02177704
 * packet: pkt_ov014_02177704
 * region: ov014
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   g_021797A4 0x021797A4 data a4
 *   func_020307B0 0x020307B0 arm
 */
extern void *g_021797A4;
typedef unsigned int   u32;
extern u32 func_020307B0(void *p);
void func_02177704(void)
{
    if (g_021797A4 != 0) {
        func_020307B0(g_021797A4);
        g_021797A4 = 0;
    }
}
