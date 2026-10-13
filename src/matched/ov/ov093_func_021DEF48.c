/*
 * function: BTL_HANDLER_ITEM_Leftovers_Heal
 * address:  0x021DEF48
 * packet:   pkt_ov093_021DEF48
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 *   func_021C88A4  0x021C88A4  thumb  ov093
 *   func_021C88C8  0x021C88C8  thumb  ov093
 *   func_021C8838  0x021C8838  thumb  ov093
 *   func_021C8860  0x021C8860  thumb  ov093
 *   func_021C7CF4  0x021C7CF4  thumb  ov093
 *   BTL_CALC_DivideMaxHpMin1  0x021D7B74  thumb  ov093
 *   BTL_POKEPARAM_IsHpFull  0x021D5B48  thumb  ov093
 *   BTL_EVENT_GetFactorKey  0x021D70A8  thumb  ov093
 */
#include "../include/Obj13496.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int BTL_EVENT_GetVar(int key);
extern void *func_021C88A4(char *p, int a, int b);
extern void func_021C88C8(void *a, void *b);
extern void func_021C8838(void *p, int a, int b);
struct S;
extern void func_021C8860(struct S *p, u32 v);
struct QQ;
extern void *func_021C7CF4(int *p, int i);
extern int BTL_CALC_DivideMaxHpMin1(u8 *p, u32 k);
extern int BTL_POKEPARAM_IsHpFull(u8 *p);
extern u16 BTL_EVENT_GetFactorKey(struct QQ *p);

void BTL_HANDLER_ITEM_Leftovers_Heal(int a, void *b, int c)
{
    void *m;
    u8 *r;

    if (c == BTL_EVENT_GetVar(2)) {
        m = func_021C7CF4(b, c);
        if (BTL_POKEPARAM_IsHpFull(m) == 0) {
            r = (u8 *)func_021C88A4(b, 5, c);
            r[6] = c;
            ((struct Obj13496 *)r)->f4 = BTL_CALC_DivideMaxHpMin1(m, 16);
            func_021C8838(r + 8, 2, 0x392);
            func_021C8860((struct S *)(r + 8), c);
            func_021C8860((struct S *)(r + 8), BTL_EVENT_GetFactorKey((void *)a));
            func_021C88C8(b, r);
        }
    }
}
