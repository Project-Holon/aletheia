/*
 * unit:     yes
 * function: BTL_TOKUSEI_Hydration_CureStatusInRain, BTL_TOKUSEI_GetHydrationHandlers
 * address:  0x021D9A68
 * packet:   pkt_ov093_021D9A68
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 *   func_021C8288  0x021C8288  thumb  ov093
 *   func_021C7CF4  0x021C7CF4  thumb  ov093
 *   BTL_POKEPARAM_GetMajorStatusIndex  0x021D62A8  thumb  ov093
 *   func_021C88B4  0x021C88B4  thumb  ov093
 *   func_021C88A4  0x021C88A4  thumb  ov093
 *   func_021C88C8  0x021C88C8  thumb  ov093
 *   gHydrationHandlers     0x021F05A8  data   a4
 */
#include "../include/Obj07809.h"

typedef unsigned char u8;
typedef unsigned int u32;

extern int BTL_EVENT_GetVar(int);
struct Unk021D62A8;
extern int func_021C8288(u8 *p);
extern void *func_021C7CF4(int *p, int i);
extern int BTL_POKEPARAM_GetMajorStatusIndex(struct Unk021D62A8 *p);
extern void func_021C88B4(void *a, int k, int b);
extern void *func_021C88A4(char *p, int a, int b);
extern void func_021C88C8(void *a, void *b);
extern int gHydrationHandlers[];

void BTL_TOKUSEI_Hydration_CureStatusInRain(int a, void *b, int c)
{
    u8 *p;

    if (c == BTL_EVENT_GetVar(2) && func_021C8288(b) == 2) {
        if (BTL_POKEPARAM_GetMajorStatusIndex(func_021C7CF4(b, c))) {
            func_021C88B4(b, 2, c);
            p = func_021C88A4(b, 0xb, c);
            ((struct Obj07809 *)p)->f4 = 0x24;
            p[8] = c;
            p[0x14] = 1;
            ((struct Obj07809 *)p)->f0 |= 0x2000000;
            func_021C88C8(b, p);
            func_021C88B4(b, 3, c);
        }
    }
}

int *BTL_TOKUSEI_GetHydrationHandlers(int *p)
{
    *p = 1;
    return gHydrationHandlers;
}
