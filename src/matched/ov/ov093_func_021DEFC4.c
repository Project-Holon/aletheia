/*
 * unit: yes
 * function: BTL_HANDLER_ITEM_BlackSludge_HealOrDamage, BTL_HANDLER_ITEM_GetDestinyKnotHandlers
 * address: 0x021DEFC4
 * packet: pkt_ov093_021DEFC4
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BTL_EVENT_GetVar 0x021D775C thumb ov093
 *   func_021C83D4 0x021C83D4 thumb ov093
 *   BTL_POKEPARAM_GetTypePair 0x021D57FC thumb ov093
 *   BTLV_CORE_HasByte 0x021E8D24 thumb ov093
 *   func_021C7CF4 0x021C7CF4 thumb ov093
 *   func_021C88A4 0x021C88A4 thumb ov093
 *   BTL_HANDLER_ITEM_GetParam 0x021DCFF8 thumb ov093
 *   BTL_CALC_DivideMaxHpMin1 0x021D7B74 thumb ov093
 *   func_021C8010 0x021C8010 thumb ov093
 *   func_021C8838 0x021C8838 thumb ov093
 *   func_021C8860 0x021C8860 thumb ov093
 *   BTL_EVENT_GetFactorKey 0x021D70A8 thumb ov093
 *   func_021C88C8 0x021C88C8 thumb ov093
 *   d_021F154C 0x021F154C data a4
 */
#include "../include/Obj03702.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern int BTL_EVENT_GetVar(int key);
struct QQ;
extern int func_021C83D4(u8 *p);
extern u16 BTL_POKEPARAM_GetTypePair(void *p);
extern int BTLV_CORE_HasByte(int x, int k);
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
void BTL_HANDLER_ITEM_BlackSludge_HealOrDamage(int a, void *b, int c)
{
    void *m;
    u8 *r;
    if (c == BTL_EVENT_GetVar(2) && func_021C83D4(b) == 0) {
        m = func_021C7CF4(b, c);
        if (BTLV_CORE_HasByte(BTL_POKEPARAM_GetTypePair(m), 3)) {
            r = (u8 *)func_021C88A4(b, 5, c);
            r[6] = c;
            ((struct Obj03702 *)r)->f4 = BTL_CALC_DivideMaxHpMin1(m, BTL_HANDLER_ITEM_GetParam(a, 2));
            func_021C8838(r + 8, 2, 0x392);
            func_021C8860((struct S *)(r + 8), c);
            func_021C8860((struct S *)(r + 8), BTL_EVENT_GetFactorKey((void *)a));
            func_021C88C8(b, r);
        } else {
            r = (u8 *)func_021C88A4(b, 7, c);
            r[6] = c;
            ((struct Obj03702 *)r)->f4 = BTL_CALC_DivideMaxHpMin1(m, 8);
            r[7] |= 2;
            ((struct Obj03702 *)r)->f8 = 0x25f;
            r[10] = func_021C8010(b, c);
            r[11] = 6;
            func_021C8838(r + 12, 2, 0x40e);
            func_021C8860((struct S *)(r + 12), c);
            func_021C8860((struct S *)(r + 12), BTL_EVENT_GetFactorKey((void *)a));
            func_021C88C8(b, r);
        }
    }
}
extern u8 d_021F154C[];
void *BTL_HANDLER_ITEM_GetDestinyKnotHandlers(int *p) { *p = 1; return d_021F154C; }
