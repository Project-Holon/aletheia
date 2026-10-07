/*
 * function: func_02178E84
 * address:  0x02178E84
 * packet:   pkt_ov014_02178E84
 * region:   ov014
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   g_021797A8     0x021797A8  data  a4
 *   func_02178138  0x02178138  thumb  ov014
 *   func_0217814C  0x0217814C  thumb  ov014
 *   func_02178F1C  0x02178F1C  thumb  ov014
 *   func_02087C6C  0x02087C6C  arm
 */

#include "../include/G_S.h"

typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;

extern struct S *g_021797A8;
void func_02178138(int a);
void func_0217814C(int a);
int func_02178F1C(u16 n);
void func_02087C6C(u16 *p);

int func_02178E84(void)
{
    u16 t[3];
    int r;
    int ok;
    u32 x;

    func_02087C6C(t);
    x = *(volatile u32 *)0x02FFFC3C;
    *(u32 *)(((u8 *)g_021797A8) + 0x1E9C) = t[2] + (t[1] + (t[0] + x));
    *(u32 *)(((u8 *)g_021797A8) + 0x1E9C) = *(u32 *)(((u8 *)g_021797A8) + 0x1E9C) * 0x10DCD + 0x3039;
    *(u16 *)(((u8 *)g_021797A8) + 0x1EAC) = 0;
    *(u16 *)(((u8 *)g_021797A8) + 0x1EAE) = 0x65;
    func_02178138(3);
    ok = 1;
    r = func_02178F1C(1);
    if (r == 0x18) {
        func_0217814C(0x18);
        func_02178138(9);
        return 0;
    }
    if (r != 2) {
        func_0217814C(r);
        func_02178138(9);
        return 0;
    }
    return ok;
}
