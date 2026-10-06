/*
 * function: func_021FA884
 * address: 0x021FA884
 * packet: pkt_ov094_021FA884
 * region: ov094
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02030734 0x02030734 arm
 *   func_020307B0 0x020307B0 arm
 *   func_0201134C 0x0201134C thumb
 *   func_020515CC 0x020515CC arm
 *   func_021FE38C 0x021FE38C thumb ov094
 *   func_021FD1A8 0x021FD1A8 thumb ov094
 *   func_021FD1CC 0x021FD1CC thumb ov094
 *   d_0220AE68 0x0220AE68 data ov094 a1
 */
#include "../include/Obj00325.h"
typedef unsigned short u16;
typedef unsigned int u32;
extern char d_0220AE68[];
extern void *func_02030734(u32, u32, int, const char *, u16);
extern u32 func_020307B0(void *p);
struct Cursor;
extern u32 func_0201134C(struct Cursor *p);
extern int func_020515CC(int *p, int a, int b, int c);
extern u32 func_021FE38C(char *, u32);
extern int func_021FD1A8(char *, int);
extern void func_021FD1CC(void *p);
int func_021FA884(void *a, char *s)
{
    int *p;
    int idx;
    int x;
    p = func_02030734((u16)((((struct Obj00325 *)s)->f238 & 0x7fff) | 0x8000), 0x5c, 1, d_0220AE68, 0x8a2);
    idx = func_021FD1A8(s, func_021FE38C(s, func_0201134C(a)));
    x = func_0201134C(a);
    p[0] = (int)a;
    p[8] = func_0201134C(a);
    p[1] = 8;
    p[10] = func_0201134C(a);
    p[11] = func_0201134C(a);
    p[12] = func_0201134C(a);
    p[2] = func_0201134C(a);
    p[3] = 0;
    p[4] = func_0201134C(a);
    p[5] = 0;
    p[9] = func_0201134C(a);
    p[7] = func_0201134C(a);
    p[17] = 0x1000;
    p[18] = func_0201134C(a);
    p[19] = 0x1000;
    p[20] = func_0201134C(a);
    p[21] = func_0201134C(a);
    if (p[21] == 0) p[21] = 1;
    if (idx != 16) {
        if (func_020515CC(*(int **)(s + 0xc + idx * 4), x, (int)func_021FD1CC, (int)p) == -1) {
            func_020307B0(p);
        }
    } else {
        func_020307B0(p);
    }
    return ((struct Obj00325 *)s)->f23C;
}
