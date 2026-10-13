/*
 * file:     unit_06898FB8.c
 * function: func_06898FB8
 * address:  0x06898FB8
 * packet:   pkt_ov095_06898FB8
 * region:   ov095
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021C8838  0x021C8838  thumb
 *   func_021C8860  0x021C8860  thumb
 *   func_021C88A4  0x021C88A4  thumb
 *   func_021C88C8  0x021C88C8  thumb
 *   BTL_EVENT_GetVar  0x021D775C  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int BTL_EVENT_GetVar(int a);
extern u8 *func_021C88A4(int p, int n, u8 v);
extern void func_021C8838(u8 *p, int n, int c);
extern void func_021C8860(u8 *p, u8 v);
extern void func_021C88C8(int p, u8 *q);

void func_06898FB8(int a0, int p, int a2, int *s)
{
    u8 v;
    u8 *t;

    if (*s != 0) {
        v = BTL_EVENT_GetVar(4);
        t = func_021C88A4(p, 4, v);
        func_021C8838(t + 4, 2, 0x347);
        func_021C8860(t + 4, v);
        func_021C88C8(p, t);
        *s = 0;
    }
}
