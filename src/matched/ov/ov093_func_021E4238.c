/*
 * function: func_021E4238
 * address:  0x021E4238
 * packet:   pkt_ov093_021E4238
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 *   func_021C7CF4  0x021C7CF4  thumb  ov093
 *   BTL_POKEPARAM_TestTurnFlag  0x021D5BB0  thumb  ov093
 *   func_021C88A4  0x021C88A4  thumb  ov093
 *   func_021C88C8  0x021C88C8  thumb  ov093
 *   func_021C8838  0x021C8838  thumb  ov093
 *   func_021C8860  0x021C8860  thumb  ov093
 */
#include "../include/Obj13518.h"
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern int BTL_EVENT_GetVar(int key);
struct UtilWork;
extern void *func_021C7CF4(int *p, int i);
extern int BTL_POKEPARAM_TestTurnFlag(struct UtilWork *p, u32 n);
extern void *func_021C88A4(char *p, int a, int b);
extern void func_021C88C8(void *a, void *b);
extern void func_021C8838(void *p, int a, int b);
struct S;
extern void func_021C8860(struct S *p, u32 val);

void func_021E4238(int a0, u8 *s, int k, int *pf)
{
    u8 v;
    u8 *e;
    u8 *e2;

    if (k == BTL_EVENT_GetVar(3)) {
        v = BTL_EVENT_GetVar(4);
        if (BTL_POKEPARAM_TestTurnFlag(func_021C7CF4((int *)s, v), 7) != 0 || *pf != 0) {
            e = func_021C88A4((char *)s, 0x16, k);
            e[8] = v;
            ((struct Obj13518 *)e)->f4 = 7;
            func_021C88C8(s, e);
            e2 = func_021C88A4((char *)s, 4, k);
            func_021C8838(e2 + 4, 2, 526);
            func_021C8860((struct S *)(e2 + 4), v);
            func_021C88C8(s, e2);
        }
    }
}
