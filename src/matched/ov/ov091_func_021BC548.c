/*
 * function: func_021BC548
 * address:  0x021BC548
 * packet:   pkt_ov091_021BC548
 * region:   ov091
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_021BB464  0x021BB464  thumb  ov091
 *   func_021BB97C  0x021BB97C  thumb  ov091
 *   func_021BB99C  0x021BB99C  thumb  ov091
 *   func_021BB9EC  0x021BB9EC  thumb  ov091
 *   func_021B9788  0x021B9788  thumb  ov091
 *   func_021BB98C  0x021BB98C  thumb  ov091
 *   func_021B9E44  0x021B9E44  thumb  ov091
 */

typedef unsigned short u16;

extern u16 func_021BB464(int, int);
extern void func_021BB97C(int, int);
extern void func_021BB99C(int, int, int, int);
extern void func_021BB9EC(int, int, int, u16, int);
extern void func_021B9788(int, int, int, void (*)(int));
extern void func_021BB98C(int, int);
extern void func_021B9E44(int);

void func_021BC548(int p)
{
    u16 h;
    u16 v;
    h = func_021BB464(p, *(int *)(p + *(int *)(p + 0x2c) * 4 + 0x160));
    *(int *)(*(int *)(p + 0x280) + 0x40) = 10;
    func_021BB97C(p, *(int *)(p + 0x150));
    func_021BB99C(p, *(int *)(p + 0x150), 0, *(int *)(p + 0x38));
    v = *(u16 *)(p + 0x11c);
    if (v != 0) {
        func_021BB9EC(p, *(int *)(p + 0x150), 1, h - v, 3);
        func_021B9788(p, 0x2c, 1, func_021B9E44);
    } else {
        func_021B9788(p, 0x32, 1, func_021B9E44);
    }
    func_021BB98C(p, *(int *)(p + 0x150));
}
