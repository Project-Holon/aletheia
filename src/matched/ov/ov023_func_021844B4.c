/*
 * function: func_021844B4
 * address: 0x021844B4
 * packet: pkt_ov023_021844B4
 * region: ov023
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02039338 0x02039338 arm
 *   func_02185AB0 0x02185AB0 thumb ov023
 */
typedef unsigned short u16;
extern u16 func_02039338(void);
extern void func_02185AB0(char *p, int msg, int arg);
void func_021844B4(int a, int b, int c, char *p)
{
    *(u16 *)(p + 0x928a) = 1;
    if (func_02039338() != 0)
        func_02185AB0(p, 0x12, 0);
}
