/*
 * function: func_021FA358
 * address: 0x021FA358
 * packet: pkt_ov094_021FA358
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

int func_021FA358(void *a, char *s)
{
    int *p;
    int slot;
    int arg;
    int result;

    p = func_02030734((u16)((((struct Obj00325 *)s)->f238 & 0x7fff) | 0x8000), 0x5c, 1, d_0220AE68, 0x77d);
    slot = func_021FD1A8(s, func_021FE38C(s, VM_GetU32(a)));
    arg = VM_GetU32(a);
    p[0] = (int)a;
    p[1] = 8;
    p[2] = 8;
    p[10] = VM_GetU32(a);
    p[11] = VM_GetU32(a);
    p[12] = VM_GetU32(a);
    p[13] = VM_GetU32(a);
    p[14] = VM_GetU32(a);
    p[15] = VM_GetU32(a);
    p[3] = 0;
    p[4] = VM_GetU32(a);
    p[5] = 0;
    p[6] = VM_GetU32(a);
    VM_GetU32(a);
    p[17] = VM_GetU32(a);
    p[18] = VM_GetU32(a);
    p[19] = VM_GetU32(a);
    p[20] = VM_GetU32(a);
    if (slot != 16) {
        result = PARTICLE_StartEffectWithCallback(*(int **)(s + 12 + slot * 4), arg, (int)func_021FD1CC, (int)p);
        if (result == -1)
            func_020307B0(p);
    } else {
        func_020307B0(p);
    }
    return ((struct Obj00325 *)s)->f23C;
}
