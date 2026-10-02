/*
 * function: func_021DC5F0
 * address: 0x021DC5F0
 * packet: pkt_ov119_021DC5F0
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020076A4 0x020076A4 thumb
 */
extern int func_020076A4(int);
void func_021DC5F0(char *p)
{
    int v = func_020076A4(*(int *)(p + 0x828));
    *(int *)(p + 0x634) = v * 6 + 2;
    *(int *)(p + 0x630) = v;
    *(int *)(p + 0x638) = v * 0x14 + 0xC;
    *(int *)(p + 0x63C) = v * 0xA0 + 0x60;
}
