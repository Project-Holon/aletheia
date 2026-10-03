/*
 * function: func_021DD874
 * address: 0x021DD874
 * packet: pkt_ov171_021DD874
 * region: ov171
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: the first creation call passes 3 in r0, shared with its stack argument.
 * symbols:
 *   func_02045088 0x02045088 arm
 *   func_020450F0 0x020450F0 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int   u32;
extern void func_02045088(u16 heapId);
extern u32 func_020450F0(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
void func_021DD874(char *p)
{
    func_02045088(0x8c);
    *(int *)(p + 0xb48) = func_020450F0(3, 1, 0, 30, 2, 3, 1);
    *(int *)(p + 0xb50) = func_020450F0(5, 4, 7, 24, 15, 1, 1);
}
