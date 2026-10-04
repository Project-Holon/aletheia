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

typedef unsigned int   u32;
typedef unsigned char  u8;
extern void func_021BB97C(u16 *p, u32 s);
extern void func_021BB9AC(int, int, int, int);
extern void func_021B9788(u8 *p, int a1, int a2, int a3);
extern void func_021BB98C(void *p, u32 s);
extern void func_021B9E20(u8 *p);

void func_021BC30C(int p)
{
    *(int *)(*(int *)(p + 0x280) + 0x40) = 10;
    func_021BB97C((u16 *)p, *(int *)(p + 0x150));
    func_021BB9AC(p, *(int *)(p + 0x150), 0, *(u16 *)(*(int *)(p + 0x280) + 0x44));
    func_021B9788((u8 *)p, 0x51, 1, (int)func_021B9E20);
    func_021BB98C((void *)p, *(int *)(p + 0x150));
}
