/*
 * unit:     yes
 * function: func_021E7760, func_021E7810
 * address:  0x021E7760
 * packet:   pkt_ov093_021E7760
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 *   func_021C88A4  0x021C88A4  thumb  ov093
 *   func_021C88C8  0x021C88C8  thumb  ov093
 *   d_021F2714     0x021F2714  data   ov093  a4
 */
#include "../include/Obj00663.h"
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern int BTL_EVENT_GetVar(int key);
extern void *func_021C88A4(char *p, int a, int b);
extern void func_021C88C8(void *a, void *b);
extern int d_021F2714[];

void func_021E7760(int a, int b, int c)
{
    u8 *p;

    if (c == BTL_EVENT_GetVar(3)) {
        p = func_021C88A4((char *)b, 0xe, c);
        ((struct Obj00663 *)p)->f4 = 2;
        ((struct Obj00663 *)p)->fC = -1;
        p[0xf] = 1;
        p[0x10] = c;
        p[0xe] = 1;
        func_021C88C8((void *)b, p);
        p = func_021C88A4((char *)b, 0xe, c);
        ((struct Obj00663 *)p)->f4 = 4;
        ((struct Obj00663 *)p)->fC = -1;
        p[0xf] = 1;
        p[0x10] = c;
        p[0xe] = 1;
        func_021C88C8((void *)b, p);
        p = func_021C88A4((char *)b, 0xe, c);
        ((struct Obj00663 *)p)->f4 = 1;
        ((struct Obj00663 *)p)->fC = 2;
        p[0xf] = 1;
        p[0x10] = c;
        p[0xe] = 1;
        func_021C88C8((void *)b, p);
        p = func_021C88A4((char *)b, 0xe, c);
        ((struct Obj00663 *)p)->f4 = 3;
        ((struct Obj00663 *)p)->fC = 2;
        p[0xf] = 1;
        p[0x10] = c;
        p[0xe] = 1;
        func_021C88C8((void *)b, p);
        p = func_021C88A4((char *)b, 0xe, c);
        ((struct Obj00663 *)p)->f4 = 5;
        ((struct Obj00663 *)p)->fC = 2;
        p[0xf] = 1;
        p[0x10] = c;
        p[0xe] = 1;
        func_021C88C8((void *)b, p);
    }
}

int *func_021E7810(int *p)
{
    *p = 1;
    return d_021F2714;
}
