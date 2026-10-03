/*
 * function: func_0220053C
 * address: 0x0220053C
 * packet: pkt_ov135_0220053C
 * region: ov135
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021F4EC0 0x021F4EC0 thumb ov135
 *   func_021F4E98 0x021F4E98 thumb ov135
 *   func_021F4ED4 0x021F4ED4 thumb ov135
 *   func_022009A4 0x022009A4 thumb ov135
 *   func_02200A10 0x02200A10 thumb ov135
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void func_021F4EC0(u8 *, u32, u32);
extern void func_021F4E98(u8 *, u32, u32);
extern int func_021F4ED4(u8 *);
extern void func_022009A4(u8 *, int, int, int, int);
extern void func_02200A10(u8 *, int, int, int, int);
extern void func_020061E4(u32 a);
void func_0220053C(u8 *p, int mode)
{
    switch (mode) {
    case 0:
        if (*(u16 *)(p + 0x32) == 0) {
            func_021F4EC0(p, 5, 5);
            *(u32 *)(p + 0x28) = 9;
        } else if (*(u16 *)(p + 0x36) == 0) {
            func_021F4EC0(p, 7, 11);
            *(u32 *)(p + 0x18) = 2;
            *(u32 *)(p + 0x28) = 9;
            *(u16 *)(p + 0x36) = 0xE10;
        } else {
            func_022009A4(p, 40, 1, 0, 0xF0F);
            func_021F4E98(p, 11, 5);
            func_020061E4(0x557);
            *(u32 *)(p + 0xDFC) = 0;
        }
        break;
    case 1:
        *(u16 *)(p + 0xE1A) = 0;
        func_021F4EC0(p, 4, 13);
        *(u32 *)(p + 0x28) = 9;
        break;
    case 2:
        func_02200A10(p, 7, func_021F4ED4(p), 0, 0xF0F);
        func_021F4E98(p, 10, 12);
        break;
    }
}
