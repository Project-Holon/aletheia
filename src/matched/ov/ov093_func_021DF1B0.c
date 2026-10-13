/*
 * unit: yes
 * function: BTL_HANDLER_ITEM_StickyBarb_TurnEndDamage, BTL_HANDLER_ITEM_GetPowerWeightHandlers, BTL_HANDLER_ITEM_GetPowerBracerHandlers, BTL_HANDLER_ITEM_GetPowerBeltHandlers, BTL_HANDLER_ITEM_GetPowerLensHandlers, BTL_HANDLER_ITEM_GetPowerBandHandlers, BTL_HANDLER_ITEM_GetPowerAnkletHandlers
 * address: 0x021DF1B0
 * packet: pkt_ov093_021DF1B0
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BTL_EVENT_GetVar 0x021D775C thumb ov093
 *   func_021C7CF4 0x021C7CF4 thumb ov093
 *   func_021C88A4 0x021C88A4 thumb ov093
 *   BTL_HANDLER_ITEM_GetParam 0x021DCFF8 thumb ov093
 *   BTL_CALC_DivideMaxHpMin1 0x021D7B74 thumb ov093
 *   func_021C8010 0x021C8010 thumb ov093
 *   func_021C8838 0x021C8838 thumb ov093
 *   func_021C8860 0x021C8860 thumb ov093
 *   BTL_EVENT_GetFactorKey 0x021D70A8 thumb ov093
 *   func_021C88C8 0x021C88C8 thumb ov093
 *   d_021F138C 0x021F138C data a4
 *   d_021F1434 0x021F1434 data a4
 *   d_021F15A4 0x021F15A4 data a4
 *   d_021F1554 0x021F1554 data a4
 *   d_021F15B4 0x021F15B4 data a4
 *   d_021F15C4 0x021F15C4 data a4
 */
#include "../include/Obj05218.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern int BTL_EVENT_GetVar(int key);
struct QQ;
extern void *func_021C7CF4(int *p, int i);
extern void *func_021C88A4(char *p, int a, int b);
extern int BTL_HANDLER_ITEM_GetParam(int a, int b);
extern int BTL_CALC_DivideMaxHpMin1(u8 *p, u32 k);
extern int func_021C8010(u8 *p, unsigned int v);
extern void func_021C8838(void *p, int a, int b);
struct S;
extern void func_021C8860(struct S *p, u32 v);
extern u16 BTL_EVENT_GetFactorKey(struct QQ *p);
extern void func_021C88C8(void *a, void *b);
void BTL_HANDLER_ITEM_StickyBarb_TurnEndDamage(int a, void *b, int c)
{
    void *m;
    u8 *r;
    if (c == BTL_EVENT_GetVar(2)) {
        m = func_021C7CF4(b, c);
        r = (u8 *)func_021C88A4(b, 7, c);
        r[6] = c;
        ((struct Obj05218 *)r)->f4 = BTL_CALC_DivideMaxHpMin1(m, BTL_HANDLER_ITEM_GetParam(a, 2));
        r[7] |= 2;
        ((struct Obj05218 *)r)->f8 = 0x25f;
        r[10] = func_021C8010(b, c);
        r[11] = 6;
        func_021C8838(r + 12, 2, 0x40e);
        func_021C8860((struct S *)(r + 12), c);
        func_021C8860((struct S *)(r + 12), BTL_EVENT_GetFactorKey((void *)a));
        func_021C88C8(b, r);
    }
}
extern u8 d_021F138C[], d_021F1434[], d_021F15A4[], d_021F1554[], d_021F15B4[], d_021F15C4[];
void *BTL_HANDLER_ITEM_GetPowerWeightHandlers(int *p) { *p = 1; return d_021F138C; }
void *BTL_HANDLER_ITEM_GetPowerBracerHandlers(int *p) { *p = 1; return d_021F1434; }
void *BTL_HANDLER_ITEM_GetPowerBeltHandlers(int *p) { *p = 1; return d_021F15A4; }
void *BTL_HANDLER_ITEM_GetPowerLensHandlers(int *p) { *p = 1; return d_021F1554; }
void *BTL_HANDLER_ITEM_GetPowerBandHandlers(int *p) { *p = 1; return d_021F15B4; }
void *BTL_HANDLER_ITEM_GetPowerAnkletHandlers(int *p) { *p = 1; return d_021F15C4; }
