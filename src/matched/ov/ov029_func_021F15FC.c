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
extern u32 func_02049990(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u16 a7);
void func_021F15FC(char *p, int flag)
{
    if (flag == 0)
        func_02049990((void *)(*(int *)(p + 0x24)), 1, 5, 0, (u16)*(u32 *)(p + 0x14), 0, 0, 0x70);
}
