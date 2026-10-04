/*
 * function: func_021BB498
 * address:  0x021BB498
 * packet:   pkt_ov100_021BB498
 * region:   ov100
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_0207E3D0 0x0207E3D0 arm
 *   func_02027974 0x02027974 thumb
 *   func_02028178 0x02028178 thumb
 *   func_02040618 0x02040618 arm
 *   func_0204A600 0x0204A600 arm
 *   func_0201C4E4 0x0201C4E4 thumb
 *   func_0200FB24 0x0200FB24 thumb
 *   func_0200FB38 0x0200FB38 thumb
 *   func_0202223C 0x0202223C thumb
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void func_0207E3D0(void *, int, int);
extern void func_02027974(u8 *);
extern void func_02028178(u8 *);
extern void func_02040618(u32, u32, u32);
extern void func_0204A600(void);
extern u32 func_0201C4E4(u8 *);
extern u32 func_0200FB24(void);
extern void func_0200FB38(void);
extern void func_0202223C(u32, u32);
u32 func_021BB498(u32 a, u32 b, u32 c, u8 *p)
{
    void (*cb)(u8 *) = *(void (**)(u8 *))(p + 0x248);
    u32 ret = 1;
    u32 flag;
    if ((*(volatile u32 *)0x02FFFC3C & 7) == 1) {
        func_0207E3D0(p + *(u16 *)(p + 0x240) * 32, 0, 0x20);
        *(u16 *)(p + 0x240) = *(u16 *)(p + 0x240) + 1;
        if (*(u16 *)(p + 0x240) == 9) {
            flag = ret;
            goto L;
        }
        if (*(u16 *)(p + 0x240) >= 0x12) *(u16 *)(p + 0x240) = 0;
    }
    flag = 0;
L:
    *(u32 *)(p + 0xCEC) = flag;
    if (cb) {
        cb(p);
        if (*(u32 *)(p + 0x248)) ret = 0;
    }
    if (*(u32 *)(p + 0xCC0)) func_02027974(*(u8 **)(p + 0xCC0));
    if (*(u32 *)(p + 0xCE0)) func_02028178(*(u8 **)(p + 0xCE0));
    if (*(u32 *)(p + 0xCE4)) func_02028178(*(u8 **)(p + 0xCE4));
    func_02040618(4, 3, *(u32 *)(p + 0xC9C));
    *(u32 *)(p + 0xC9C) = *(u32 *)(p + 0xC9C) - 1;
    func_0204A600();
    func_0201C4E4(*(u8 **)(p + 0xCB8));
    if (func_0200FB24()) {
        func_0200FB38();
        *(u32 *)(*(u8 **)(p + 0x244) + 0x1C) = 12;
        ret = 1;
        func_0202223C(0, 0);
        func_0202223C(1, 0);
    }
    return ret;
}
