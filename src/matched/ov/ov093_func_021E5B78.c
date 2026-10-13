/*
 * unit:     yes
 * function: func_021E5B78, func_021E5C0C
 * address:  0x021E5B78
 * packet:   pkt_ov093_021E5B78
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 *   func_021C7F24  0x021C7F24  thumb  ov093
 *   func_021C7F4C  0x021C7F4C  thumb  ov093
 *   func_021C8010  0x021C8010  thumb  ov093
 *   func_021C88A4  0x021C88A4  thumb  ov093
 *   func_021C88C8  0x021C88C8  thumb  ov093
 *   d_021F2CD8     0x021F2CD8  data   ov093  a4
 */
#include "../include/Obj02791.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int BTL_EVENT_GetVar(int key);
struct Flag;
extern int func_021C7F24(u8 *p, int i);
extern int func_021C7F4C(struct Flag *p);
extern int func_021C8010(u8 *p, unsigned int v);
extern void *func_021C88A4(char *p, int a, int b);
extern void func_021C88C8(void *a, void *b);
extern int d_021F2CD8[];

void func_021E5B78(int a, void *b, int c)
{
    u8 *m;

    if (c == BTL_EVENT_GetVar(3) && func_021C7F24(b, c) != 0 && func_021C7F4C(b) != 0) {
        m = (u8 *)func_021C88A4(b, 0x1e, c);
        ((struct Obj02791 *)m)->f4 = 4;
        m[8] = func_021C8010(b, c);
        ((struct Obj02791 *)m)->fC = c;
        m[0x1c] = 1;
        func_021C88C8(b, m);
        m = (u8 *)func_021C88A4(b, 0x17, c);
        m[8] = c;
        ((struct Obj02791 *)m)->f4 = 0xe;
        ((struct Obj02791 *)m)->f0 |= 1 << 24;
        func_021C88C8(b, m);
        m = (u8 *)func_021C88A4(b, 0x29, c);
        m[0x4c] = c;
        m[0x4d] = 1;
        ((struct Obj02791 *)m)->f0 |= 1 << 24;
        func_021C88C8(b, m);
    }
}

int *func_021E5C0C(int *p)
{
    *p = 3;
    return d_021F2CD8;
}
