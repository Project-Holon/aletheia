/*
 * function: func_021F15FC
 * address: 0x021F15FC
 * packet: pkt_ov029_021F15FC
 * region: ov029
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02049990 0x02049990 arm
 */
typedef unsigned short u16;
typedef unsigned int u32;
extern void func_02049990(int, int, int, int, u16, int, int, int);
void func_021F15FC(char *p, int flag)
{
    if (flag == 0)
        func_02049990(*(int *)(p + 0x24), 1, 5, 0, (u16)*(u32 *)(p + 0x14), 0, 0, 0x70);
}
