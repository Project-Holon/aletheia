/*
 * function: BTL_HANDLER_TOKUSEI_HarvestRestoreBerry
 * address:  0x021DCB38
 * packet:   pkt_ov093_021DCB38
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 *   func_021C7CF4  0x021C7CF4  thumb  ov093
 *   BTL_POKEPARAM_GetConsumedItem  0x021D6740  thumb  ov093
 *   PALANM_IsColorCodeKnown  0x020213C0  thumb
 *   BTL_POKEPARAM_GetItem  0x021D5B40  thumb  ov093
 *   func_021C8288  0x021C8288  thumb  ov093
 *   BTL_CALC_RollChanceOrFlag  0x021D85C0  thumb  ov093
 *   func_021C88A4  0x021C88A4  thumb  ov093
 *   func_021C8838  0x021C8838  thumb  ov093
 *   func_021C8860  0x021C8860  thumb  ov093
 *   func_021C88C8  0x021C88C8  thumb  ov093
 */
#include "../include/Obj07816.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int BTL_EVENT_GetVar(int key);
struct QI;
struct QK;
extern void *func_021C7CF4(int *p, int i);
extern u16 BTL_POKEPARAM_GetConsumedItem(struct QK *p);
extern int PALANM_IsColorCodeKnown(u32 a);
extern u16 BTL_POKEPARAM_GetItem(struct QI *p);
extern int func_021C8288(u8 *p);
extern int BTL_CALC_RollChanceOrFlag(int a, u32 b);
extern void *func_021C88A4(char *p, int a, int b);
extern void func_021C8838(void *p, int a, int b);
struct S;
extern void func_021C8860(struct S *p, u32 v);
extern void func_021C88C8(void *a, void *b);

void BTL_HANDLER_TOKUSEI_HarvestRestoreBerry(int a, void *b, int c)
{
    u8 *m;
    void *mon;
    u32 n;

    if (c == BTL_EVENT_GetVar(2)) {
        mon = func_021C7CF4(b, c);
        n = BTL_POKEPARAM_GetConsumedItem(mon);
        if (n != 0 && PALANM_IsColorCodeKnown(n) != 0 && BTL_POKEPARAM_GetItem(mon) == 0
            && (func_021C8288(b) == 1 || BTL_CALC_RollChanceOrFlag((int)b, 0x32) != 0)) {
            m = (u8 *)func_021C88A4(b, 0x20, c);
            ((struct Obj07816 *)m)->f0 |= 0x20 << 18;
            ((struct Obj07816 *)m)->f4 = n;
            m[6] = c;
            m[7] = 1;
            func_021C8838(m + 0xc, 2, 0x1db);
            func_021C8860((struct S *)(m + 0xc), c);
            func_021C8860((struct S *)(m + 0xc), n);
            func_021C88C8(b, m);
        }
    }
}
