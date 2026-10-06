/*
 * unit:     yes
 * function: func_021E5870, func_021E58CC
 * address:  0x021E5870
 * packet:   pkt_ov093_021E5870
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021D775C  0x021D775C  thumb  ov093
 *   func_021C88A4  0x021C88A4  thumb  ov093
 *   func_021E89C0  0x021E89C0  thumb  ov093
 *   func_021C8838  0x021C8838  thumb  ov093
 *   func_021C8860  0x021C8860  thumb  ov093
 *   func_021C88C8  0x021C88C8  thumb  ov093
 *   d_021F24F4     0x021F24F4  data   ov093  a4
 */
#include "../include/Obj13528.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_021D775C(int key);
extern void *func_021C88A4(char *p, int a, int b);
typedef struct { u32 v; } Word;

extern Word func_021E89C0(void);
extern void func_021C8838(void *p, int a, int b);
struct S;
extern void func_021C8860(struct S *p, u32 v);
extern void func_021C88C8(void *a, void *b);
extern int d_021F24F4[];

void func_021E5870(int a, void *b, int c)
{
    u8 *m;
    u8 k;

    if (c == func_021D775C(3)) {
        k = func_021D775C(6);
        m = (u8 *)func_021C88A4(b, 0xc, c);
        m[0xf] = k;
        ((struct Obj13528 *)m)->f4 = 0x10;
        *(Word *)(m + 8) = func_021E89C0();
        func_021C8838(m + 0x14, 2, 0x235);
        func_021C8860((struct S *)(m + 0x14), k);
        func_021C88C8(b, m);
    }
}

int *func_021E58CC(int *p)
{
    *p = 1;
    return d_021F24F4;
}
