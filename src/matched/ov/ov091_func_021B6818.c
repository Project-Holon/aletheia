/*
 * function: func_021B6818
 * address:  0x021B6818
 * packet:   pkt_ov091_021B6818
 * region:   ov091
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02030EAC  0x02030EAC  arm
 *   func_021B9A84  0x021B9A84  thumb  ov091
 *   func_021BBE44  0x021BBE44  thumb  ov091
 *   func_021BBAE0  0x021BBAE0  thumb  ov091
 *   func_021BB5FC  0x021BB5FC  thumb  ov091
 *   func_020452E8  0x020452E8  arm
 *   func_021BA890  0x021BA890  thumb  ov091
 *   func_02027FD8  0x02027FD8  thumb
 *   func_021B7268  0x021B7268  thumb  ov091
 *   func_021BCD80  0x021BCD80  thumb  ov091
 *   func_021B71B0  0x021B71B0  thumb  ov091
 *   func_021B7624  0x021B7624  thumb  ov091
 *   func_021B6FEC  0x021B6FEC  thumb  ov091
 *   func_020355D8  0x020355D8  arm
 */

typedef unsigned char u8;
typedef unsigned int u32;

extern void func_02030EAC(int a);
extern int func_021B9A84(u8 *p);
extern void func_021BBE44(int x);
extern void func_021BBAE0(u8 *p, int a);
extern void func_021BB5FC(u8 *p, int a);
extern void func_020452E8(int a);
extern void func_021BA890(u8 *p, int a);
extern void func_02027FD8(int a);
extern void func_021B7268(u8 *p);
extern void func_021BCD80(u8 *p);
extern void func_021B71B0(u8 *p);
extern void func_021B7624(u8 *p);
extern void func_021B6FEC(u8 *p);
extern void func_020355D8(int a);

#define W(o) (*(int *)(p + (o)))

int func_021B6818(u8 *p)
{
    u8 i;

    func_02030EAC(W(4));
    if (func_021B9A84(p) == 1) {
        func_021BBE44(W(0x108));
        func_021BBE44(W(0x10c));
        W(0x108) = 0;
        W(0x10c) = 0;
    }
    func_021BBAE0(p, W(0x154));
    func_021BB5FC(p, W(0x150));
    if (W(0x130) != 0)
        func_020452E8(W(0x130));
    for (i = 0; i < 6; i++)
        func_021BA890(p, ((int *)(p + 0x160))[i]);
    func_02027FD8(W(0x254));
    func_021B7268(p);
    if (func_021B9A84(p) == 1)
        func_021BCD80(p);
    func_021B71B0(p);
    func_021B7624(p);
    func_021B6FEC(p);
    if (W(0x18) == 1)
        *(int *)(W(0x280) + 0x34) = 0x18;
    if (W(0x1c) == 1)
        *(int *)(W(0x280) + 0x34) = 0x19;
    if (W(0x20) == 1)
        *(int *)(W(0x280) + 0x34) = 0x1a;
    func_020355D8(W(8));
    return 1;
}
