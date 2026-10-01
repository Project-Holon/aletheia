/*
 * function: func_021B7128
 * address: 0x021B7128
 * packet: pkt_ov173_021B7128
 * region: ov173
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021B6FB4 0x021B6FB4 thumb ov173
 *   func_021B70D8 0x021B70D8 thumb ov173
 *   func_0201F81C 0x0201F81C thumb
 *   func_0201F878 0x0201F878 thumb
 *   func_02045B38 0x02045B38 arm
 *   func_02045C04 0x02045C04 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u32 func_021B6FB4(char *);
extern void func_021B70D8(char *);
extern void *func_0201F81C(u32, u32);
extern void func_0201F878(void *, u32, u32, u32, u32);
extern void *func_02045B38(u32, u32, u32, u32);
extern void func_02045C04(void *);
void func_021B7128(char *p)
{
    u32 i;
    u16 move;
    void *bank;
    *(u8 *)(p + 0x1b8) = func_021B6FB4(p);
    *(void **)(p + 0x58) = func_0201F81C(*(u8 *)(p + 0x1b8), 0x4f);
    i = 0;
    bank = func_02045B38(0, 2, 0xcb, 0x4f);
    for (; i < *(u8 *)(p + 0x1b8); i++) {
        move = ((u16 *)*(void **)(*(char **)p + 0x10))[i];
        if (move != 0xffff) {
            func_0201F878(*(void **)(p + 0x58), (u32)bank, move, move, 0x4f);
        } else {
            func_0201F878(*(void **)(p + 0x58), *(u32 *)(p + 0x44), 0x20, -2, 0x4f);
            break;
        }
    }
    func_02045C04(bank);
    *(u8 *)(p + 0x1bb) = 0;
    *(u8 *)(p + 0x1bc) = *(u16 *)(*(char **)p + 0x14);
    func_021B70D8(p);
}
