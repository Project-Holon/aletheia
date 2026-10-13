/*
 * function: BTL_HANDLER_ITEM_MicleBerryRaiseAccuracy
 * address:  0x021DE058
 * packet:   pkt_ov093_021DE058
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
 *   func_021C88A4  0x021C88A4  thumb  ov093
 *   BTLV_CORE_MakeSlotKind1Value  0x021E89D4  thumb  ov093
 *   func_021C8838  0x021C8838  thumb  ov093
 *   func_021C8860  0x021C8860  thumb  ov093
 *   BTL_EVENT_GetFactorKey  0x021D70A8  thumb  ov093
 *   func_021C88C8  0x021C88C8  thumb  ov093
 */
#include "../include/Obj10067.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int BTL_EVENT_GetVar(int key);
struct QQ;
extern void *func_021C7CF4(int *p, int i);
extern void *func_021C88A4(char *p, int a, int b);
extern int BTLV_CORE_MakeSlotKind1Value(u32 a);
extern void func_021C8838(void *p, int a, int b);
struct S;
extern void func_021C8860(struct S *p, u32 v);
extern u16 BTL_EVENT_GetFactorKey(struct QQ *p);
extern void func_021C88C8(void *a, void *b);

void BTL_HANDLER_ITEM_MicleBerryRaiseAccuracy(void *a, void *b, int c, u8 *a3)
{
    u8 *m;

    if (c == BTL_EVENT_GetVar(2)) {
        func_021C7CF4(b, c);
        m = (u8 *)func_021C88A4(b, 0xc, c);
        m[0xf] = c;
        ((struct Obj10067 *)m)->f4 = 0x22;
        ((struct Obj10067 *)m)->f8 = BTLV_CORE_MakeSlotKind1Value(0x78);
        func_021C8838(m + 0x14, 2, 0x404);
        func_021C8860((struct S *)(m + 0x14), c);
        func_021C8860((struct S *)(m + 0x14), BTL_EVENT_GetFactorKey(a));
        func_021C88C8(b, m);
    }
}
