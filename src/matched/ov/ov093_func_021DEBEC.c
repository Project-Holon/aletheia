/*
 * function: BTL_HANDLER_ITEM_LifeOrb_RecoilDamage
 * address:  0x021DEBEC
 * packet:   pkt_ov093_021DEBEC
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
 *   func_021C8838  0x021C8838  thumb  ov093
 *   func_021C8860  0x021C8860  thumb  ov093
 *   func_021C7CF4  0x021C7CF4  thumb  ov093
 *   BTL_CALC_DivideMaxHpMin1  0x021D7B74  thumb  ov093
 */
#include "../include/Obj13494.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int BTL_EVENT_GetVar(int key);
extern void *func_021C88A4(char *p, int a, int b);
extern void func_021C88C8(void *a, void *b);
extern void func_021C8838(void *p, int a, int b);
struct S;
extern void func_021C8860(struct S *p, u32 v);
extern void *func_021C7CF4(int *p, int i);
extern int BTL_CALC_DivideMaxHpMin1(u8 *p, u32 k);

void BTL_HANDLER_ITEM_LifeOrb_RecoilDamage(int a, void *b, int c)
{
    void *m;
    u8 *r;

    if (c == BTL_EVENT_GetVar(3)) {
        m = func_021C7CF4(b, c);
        r = (u8 *)func_021C88A4(b, 7, c);
        r[6] = c;
        ((struct Obj13494 *)r)->f4 = BTL_CALC_DivideMaxHpMin1(m, 10);
        func_021C8838(r + 12, 2, 0x3f5);
        func_021C8860((struct S *)(r + 12), c);
        func_021C88C8(b, r);
    }
}
