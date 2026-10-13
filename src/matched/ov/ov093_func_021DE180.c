/*
 * function: BTL_HANDLER_ITEM_HitBackAttacker
 * address:  0x021DE180
 * packet:   pkt_ov093_021DE180
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
 *   BTL_POKEPARAM_IsFainted  0x021D5B68  thumb  ov093
 *   BTL_HANDLER_ITEM_GetParam  0x021DCFF8  thumb  ov093
 *   func_021C88A4  0x021C88A4  thumb  ov093
 *   BTL_CALC_DivideMaxHpMin1  0x021D7B74  thumb  ov093
 *   func_021C8838  0x021C8838  thumb  ov093
 *   func_021C8860  0x021C8860  thumb  ov093
 *   BTL_EVENT_GetFactorKey  0x021D70A8  thumb  ov093
 *   func_021C88C8  0x021C88C8  thumb  ov093
 */
#include "../include/Obj10068.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int BTL_EVENT_GetVar(int key);
struct QQ;
extern void *func_021C7CF4(int *p, int i);
extern int BTL_POKEPARAM_IsFainted(void *p);
extern int BTL_HANDLER_ITEM_GetParam(int a, int b);
extern void *func_021C88A4(char *p, int a, int b);
extern int BTL_CALC_DivideMaxHpMin1(u8 *p, u32 k);
extern void func_021C8838(void *p, int a, int b);
struct S;
extern void func_021C8860(struct S *p, u32 v);
extern u16 BTL_EVENT_GetFactorKey(struct QQ *p);
extern void func_021C88C8(void *a, void *b);

void BTL_HANDLER_ITEM_HitBackAttacker(int a, void *b, int c, int *d)
{
    u8 *m;
    void *mon;
    u8 k;
    u8 j;

    if (c == BTL_EVENT_GetVar(2) && *d != 0) {
        k = *d - 1;
        mon = func_021C7CF4(b, k);
        if (BTL_POKEPARAM_IsFainted(mon) == 0) {
            j = BTL_HANDLER_ITEM_GetParam(a, 2);
            m = (u8 *)func_021C88A4(b, 7, c);
            m[6] = k;
            ((struct Obj10068 *)m)->f4 = BTL_CALC_DivideMaxHpMin1(mon, j);
            func_021C8838(m + 0xc, 2, 0x407);
            func_021C8860((struct S *)(m + 0xc), m[6]);
            func_021C8860((struct S *)(m + 0xc), c);
            func_021C8860((struct S *)(m + 0xc), BTL_EVENT_GetFactorKey((void *)a));
            func_021C88C8(b, m);
        }
    }
}
