/*
 * function: func_021B892C
 * address:  0x021B892C
 * packet:   pkt_ov091_021B892C
 * region:   ov091
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * The six-byte buffer is a block-scope initialised array
 * (an-initialised-local-array-takes-its-address-before-the-stores.md):
 * six assignments sink `add r7, sp, #4` below the stores.
 *
 * symbols:
 *   func_021BAFA0  0x021BAFA0  thumb  ov091
 *   func_0204B3DC  0x0204B3DC  arm
 *   func_021BB43C  0x021BB43C  thumb  ov091
 *   func_02019E54  0x02019E54  thumb
 *   func_021B9788  0x021B9788  thumb  ov091
 *   func_021B9E20  0x021B9E20  thumb  ov091
 *   func_020061E4  0x020061E4  thumb
 *   func_021BB97C  0x021BB97C  thumb  ov091
 *   func_021BB9EC  0x021BB9EC  thumb  ov091
 *   func_021BB98C  0x021BB98C  thumb  ov091
 *   func_021BBE5C  0x021BBE5C  thumb  ov091
 *   func_021BBE68  0x021BBE68  thumb  ov091
 */
#include "../include/Obj06210.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

#define W(o) (*(u32 *)(p + (o)))

extern void func_021BAFA0(u8 *a, u8 *s, int k);
struct Obj;
extern void func_0204B3DC(struct Obj *p, unsigned int v);
extern int func_021BB43C(int *p);
extern int  func_02019E54(u32 a0, u32 a1, u32 a2);
extern void func_021B9788(u8 *p, int a1, int a2, int a3);
extern void func_021B9E20(u8 *p);
extern void func_020061E4(u32 id);
extern void func_021BB97C(u8 *p, u32 obj);
extern void func_021BB9EC(int a, int b, int c, int d, unsigned char e);
extern void func_021BB98C(void *p, u32 s);
extern void func_021BBE5C(int h, int f);
extern void func_021BBE68(int h, int f);

void func_021B892C(u8 *p)
{
    u8 *q;
    u8 i;
    int n;
    int r;

    q = (u8 *)((u32 *)W(0x280))[0x14 / 4];
    if (W(0x2c) != 6) {
        if ((int)W(0x2c) <= 5) {
            func_021BAFA0(p, (u8 *)(*(int *)(p + W(0x2c) * 4 + 0x160)), 0);
            func_0204B3DC((struct Obj *)W(0x1d8), 0);
        }
        W(0x2c) = 6;
    }
    ((u32 *)W(0x280))[0x3c / 4] = 6;
    {
        u8 buf[6] = {0, 0, 0, 0, 0, 0};
        for (i = 0; i < 6; i++) {
            n = func_021BB43C((int *)(*(int *)(p + i * 4 + 0x160)));
            if (n <= 5) {
                buf[n] = i + 1;
            }
        }
        r = func_02019E54((u32)q, *(u32 *)W(0x280), (u32)buf);
    }
    if (q[2] > p[0x105]) {
        func_021B9788(p, q[2] + 0x56, 1, (int)func_021B9E20);
        func_020061E4(0x557);
        return;
    }
    if (q[3] < p[0x105]) {
        func_021B9788(p, q[3] + 0x5c, 1, (int)func_021B9E20);
        func_020061E4(0x557);
        return;
    }
    if (r == 1) {
        func_021BB97C(p, W(0x150));
        func_021BB9EC((int)p, W(0x150), 0, ((struct Obj06210 *)q)->f6, 3);
        func_021B9788(p, 0x92, 1, (int)func_021B9E20);
        func_020061E4(0x557);
        func_021BB98C(p, W(0x150));
        return;
    }
    if (r == 7) {
        func_021B9788(p, 0x94, 1, (int)func_021B9E20);
        func_020061E4(0x557);
        return;
    }
    func_021BBE5C(W(0x10c), 0);
    func_021BBE68(W(0x108), 1);
    p[0xc] = 0xc;
    ((u32 *)W(0x280))[0x3c / 4] = 6;
    ((u32 *)W(0x280))[0x40 / 4] = 0;
    W(0x118) = 1;
    func_020061E4(0x54c);
}
