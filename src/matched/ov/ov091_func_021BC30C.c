/*
 * function: func_021BC30C
 * address:  0x021BC30C
 * packet:   pkt_ov091_021BC30C
 * region:   ov091
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_021BB97C  0x021BB97C  thumb  ov091
 *   func_021BB9AC  0x021BB9AC  thumb  ov091
 *   func_021B9788  0x021B9788  thumb  ov091
 *   func_021BB98C  0x021BB98C  thumb  ov091
 *   func_021B9E20  0x021B9E20  thumb  ov091
 */

typedef unsigned short u16;

extern void func_021BB97C(int, int);
extern void func_021BB9AC(int, int, int, int);
extern void func_021B9788(int, int, int, void (*)(int));
extern void func_021BB98C(int, int);
extern void func_021B9E20(int);

void func_021BC30C(int p)
{
    *(int *)(*(int *)(p + 0x280) + 0x40) = 10;
    func_021BB97C(p, *(int *)(p + 0x150));
    func_021BB9AC(p, *(int *)(p + 0x150), 0, *(u16 *)(*(int *)(p + 0x280) + 0x44));
    func_021B9788(p, 0x51, 1, func_021B9E20);
    func_021BB98C(p, *(int *)(p + 0x150));
}
