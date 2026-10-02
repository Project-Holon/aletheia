/*
 * function: func_021770A8
 * address: 0x021770A8
 * packet: pkt_ov014_021770A8
 * region: ov014
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   g_021797A0 0x021797A0 data a4
 *   func_020307B0 0x020307B0 arm
 */
typedef unsigned char u8;
extern u8 *g_021797A0;
extern void func_020307B0(void *);
int func_021770A8(void *arg)
{
    if (*(void (**)(void *))(g_021797A0+4) != 0)
        (*(void (**)(void *))(g_021797A0+4))(arg);
    func_020307B0(g_021797A0);
    g_021797A0=0;
    return 1;
}
