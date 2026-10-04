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

typedef unsigned int   u32;
typedef unsigned char  u8;
extern void func_021BB97C(u16 *p, u32 s);
extern void func_021BB99C(int, int, int, int);
extern int func_021BC1D0(int);
extern void func_021B9788(u8 *p, int a1, int a2, int a3);
extern void func_021BB98C(void *p, u32 s);
extern void func_021BC628(int);
extern void func_021B9E3C(int);

void func_021BC5CC(int p)
{
    *(int *)(*(int *)(p + 0x280) + 0x40) = 10;
    func_021BB97C((u16 *)p, *(int *)(p + 0x150));
    func_021BB99C(p, *(int *)(p + 0x150), 0, *(int *)(p + 0x38));
    if (func_021BC1D0(p) != -1) {
        func_021B9788((u8 *)p, 0x32, 1, (int)func_021BC628);
    } else {
        func_021B9788((u8 *)p, 0x32, 1, (int)func_021B9E3C);
    }
    func_021BB98C((void *)p, *(int *)(p + 0x150));
}
