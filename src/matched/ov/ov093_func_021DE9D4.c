/*
 * function: BTL_HANDLER_ITEM_Choice_LockMove
 * address:  0x021DE9D4
 * packet:   pkt_ov093_021DE9D4
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
 *   BTLV_CORE_MakeSlotKind1Value  0x021E89D4  thumb  ov093
 */
#include "../include/Obj07819.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int BTL_EVENT_GetVar(int key);
extern void *func_021C88A4(char *p, int a, int b);
extern void func_021C88C8(void *a, void *b);
extern int BTLV_CORE_MakeSlotKind1Value(u32 a);

void BTL_HANDLER_ITEM_Choice_LockMove(int a, void *b, int c)
{
    u16 v;
    u8 *r;

    if (c == BTL_EVENT_GetVar(3)) {
        v = BTL_EVENT_GetVar(0x12);
        if (v != 0xa5) {
            r = (u8 *)func_021C88A4(b, 12, c);
            r[0xf] = c;
            ((struct Obj07819 *)r)->f4 = 0x1b;
            ((struct Obj07819 *)r)->f8 = BTLV_CORE_MakeSlotKind1Value(v);
            r[0x10] = 2;
            func_021C88C8(b, r);
        }
    }
}
