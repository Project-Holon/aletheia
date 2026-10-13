/*
 * function: func_021FB49C
 * address:  0x021FB49C
 * packet:   pkt_ov094_021FB49C
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   VM_GetU32  0x0201134C  thumb
 *   func_021FCF2C  0x021FCF2C  thumb  ov094
 *   func_021F8700  0x021F8700  thumb  ov094
 *   BTLV_BG_StartScroll  0x022097CC  thumb  ov094
 */
#include "../include/Obj21663.h"
typedef unsigned int   u32;
struct Cursor;
extern u32 VM_GetU32(struct Cursor *p);
extern int func_021FCF2C(int a, int b);
extern int func_021F8700(void);
extern void BTLV_BG_StartScroll(int a, int b, int c, int d, int e, int f, int g, int h);

int func_021FB49C(struct Cursor *a, char *b)
{
    int t0, t1, t2, t3, t4, t5, v;

    t0 = VM_GetU32(a);
    t1 = VM_GetU32(a);
    t2 = VM_GetU32(a);
    t3 = VM_GetU32(a);
    t4 = VM_GetU32(a);
    t5 = VM_GetU32(a);
    v = func_021FCF2C((int)a, 14);
    BTLV_BG_StartScroll(func_021F8700(), v, t0, t1, t2, t3, t4, t5);
    return ((struct Obj21663 *)b)->f23C;
}
