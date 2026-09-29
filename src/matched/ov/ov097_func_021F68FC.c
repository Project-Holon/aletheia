/*
 * function: func_021F68FC
 * address:  0x021F68FC
 * packet:   pkt_ov097_021F68FC
 * region:   ov097
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020490F4  0x020490F4  arm
 *   func_02049658  0x02049658  arm
 *   func_020498F4  0x020498F4  arm
 *   func_02049B68  0x02049B68  arm
 *   func_02049238  0x02049238  arm
 *   func_02040EBC  0x02040EBC  arm
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef signed char s8;
typedef unsigned int u32;
typedef int s32;

extern void *func_020490F4(u32 a, u32 b);
extern void func_02049658(void *h, u32 a, u32 b, u32 c, u32 d, u32 e, u32 f);
extern void func_020498F4(void *h, u32 a, u32 b, u32 c, u32 d, u32 e, u32 f);
extern void func_02049B68(void *h, u32 a, u32 b, u32 c, u32 d, u32 e);
extern void func_02049238(void *h);
extern void func_02040EBC(u32 a, u32 b);

void func_021F68FC(void)
{
    void *h;
    h = func_020490F4(0x64, 0x8071);
    func_02049658(h, 0x12, 2, 0, 0, 1, 0x8071);
    func_020498F4(h, 0, 2, 0, 0, 1, 0x8071);
    func_02049B68(h, 0x13, 0, 0, 0, 0x8071);
    func_020498F4(h, 0x10, 1, 0, 0x800, 1, 0x8071);
    func_02049238(h);
    func_02040EBC(4, 0);
}
