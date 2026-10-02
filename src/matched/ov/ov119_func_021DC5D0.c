/*
 * function: func_021DC5D0
 * address: 0x021DC5D0
 * packet: pkt_ov119_021DC5D0
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020307B0 0x020307B0 arm
 */
extern void func_020307B0(int);
void func_021DC5D0(char *p)
{
    unsigned i;
    for (i = 0; i < 3; i++)
        func_020307B0(*(int *)(p + i * 4 + 0x1064));
}
