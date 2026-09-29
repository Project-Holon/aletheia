/*
 * function: func_021BC5CC
 * address:  0x021BC5CC
 * packet:   pkt_ov091_021BC5CC
 * region:   ov091
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_021BB97C  0x021BB97C  thumb  ov091
 *   func_021BB99C  0x021BB99C  thumb  ov091
 *   func_021BC1D0  0x021BC1D0  thumb  ov091
 *   func_021B9788  0x021B9788  thumb  ov091
 *   func_021BB98C  0x021BB98C  thumb  ov091
 *   func_021BC628  0x021BC628  thumb  ov091
 *   func_021B9E3C  0x021B9E3C  thumb  ov091
 */

typedef unsigned short u16;

extern void func_021BB97C(int, int);
extern void func_021BB99C(int, int, int, int);
extern int func_021BC1D0(int);
extern void func_021B9788(int, int, int, void (*)(int));
extern void func_021BB98C(int, int);
extern void func_021BC628(int);
extern void func_021B9E3C(int);

void func_021BC5CC(int p)
{
    *(int *)(*(int *)(p + 0x280) + 0x40) = 10;
    func_021BB97C(p, *(int *)(p + 0x150));
    func_021BB99C(p, *(int *)(p + 0x150), 0, *(int *)(p + 0x38));
    if (func_021BC1D0(p) != -1) {
        func_021B9788(p, 0x32, 1, func_021BC628);
    } else {
        func_021B9788(p, 0x32, 1, func_021B9E3C);
    }
    func_021BB98C(p, *(int *)(p + 0x150));
}
