/*
 * function: func_021FA794
 * address: 0x021FA794
 * packet: pkt_ov094_021FA794
 * region: ov094
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   VM_GetU32 0x0201134C thumb
 *   func_02030734 0x02030734 arm
 *   func_020307B0 0x020307B0 arm
 *   PARTICLE_StartEffectWithCallback 0x020515CC arm
 *   func_021FE38C 0x021FE38C thumb ov094
 *   func_021FD1A8 0x021FD1A8 thumb ov094
 *   func_021FD1CC 0x021FD1CC thumb ov094
 *   d_0220AE68 0x0220AE68 data ov094 a1
 */
#include "../include/Obj00325.h"
typedef unsigned short u16;
typedef unsigned int u32;
extern char d_0220AE68[];
struct Cursor;
extern u32 VM_GetU32(struct Cursor *p);
extern void *func_02030734(u32, u32, int, const char *, u16);
extern u32 func_020307B0(void *p);
extern int PARTICLE_StartEffectWithCallback(int *p, int a, int b, int c);
extern unsigned int func_021FE38C(char *, unsigned int);
extern int func_021FD1A8(char *p, int v);
extern void func_021FD1CC(void *p);

int func_021FA794(void *a, char *s)
{
    int *p;
    int slot;
    int arg;

    p = func_02030734((u16)((((struct Obj00325 *)s)->f238 & 0x7fff) | 0x8000), 0x5c, 1, d_0220AE68, 0x868);
    slot = func_021FD1A8(s, func_021FE38C(s, VM_GetU32(a)));
    arg = VM_GetU32(a);
    p[0] = (int)a;
    p[8] = VM_GetU32(a);
    p[1] = VM_GetU32(a);
    p[2] = VM_GetU32(a);
    p[3] = 0;
    p[4] = VM_GetU32(a);
    p[5] = 0;
    p[9] = VM_GetU32(a);
    p[7] = VM_GetU32(a);
    p[17] = 0x1000;
    p[18] = VM_GetU32(a);
    p[19] = 0x1000;
    p[20] = VM_GetU32(a);
    p[21] = VM_GetU32(a);
    if (p[21] == 0)
        p[21] = 1;
    if (slot != 16) {
        if (PARTICLE_StartEffectWithCallback(*(int **)(s + 12 + slot * 4), arg, (int)func_021FD1CC, (int)p) == -1)
            func_020307B0(p);
    } else {
        func_020307B0(p);
    }
    return ((struct Obj00325 *)s)->f23C;
}
