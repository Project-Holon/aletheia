/*
 * function: func_021FA288
 * address: 0x021FA288
 * packet: pkt_ov094_021FA288
 * region: ov094
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0201134C 0x0201134C thumb
 *   func_02030734 0x02030734 arm
 *   func_020307B0 0x020307B0 arm
 *   func_021FE38C 0x021FE38C thumb ov094
 *   func_021FD1A8 0x021FD1A8 thumb ov094
 *   func_021FDD60 0x021FDD60 thumb ov094
 *   d_0220AE68 0x0220AE68 data ov094 a1
 */
#include "../include/Obj00325.h"
typedef unsigned short u16;
typedef unsigned int u32;
extern char d_0220AE68[];
struct Cursor;
extern u32 func_0201134C(struct Cursor *p);
extern void *func_02030734(u32, u32, int, const char *, u16);
extern u32 func_020307B0(void *p);
extern unsigned int func_021FE38C(char *, unsigned int);
extern int func_021FD1A8(char *p, int v);
extern void func_021FDD60(char *, int *, int, int);

int func_021FA288(void *a, char *s)
{
    int *p;
    int slot;
    int arg;

    p = func_02030734((u16)((((struct Obj00325 *)s)->f238 & 0x7fff) | 0x8000), 0x5c, 1, d_0220AE68, 0x74a);
    slot = func_021FD1A8(s, func_021FE38C(s, func_0201134C(a)));
    arg = func_0201134C(a);
    p[0] = (int)a;
    p[1] = func_0201134C(a);
    p[2] = func_0201134C(a);
    p[3] = 0;
    p[4] = func_0201134C(a);
    p[5] = 0;
    p[6] = func_0201134C(a);
    func_0201134C(a);
    p[17] = func_0201134C(a);
    p[18] = func_0201134C(a);
    p[19] = func_0201134C(a);
    p[20] = func_0201134C(a);
    if (p[2] == 8)
        p[2] = p[1];
    if (slot != 16)
        func_021FDD60(s, p, slot, arg);
    func_020307B0(p);
    return ((struct Obj00325 *)s)->f23C;
}
