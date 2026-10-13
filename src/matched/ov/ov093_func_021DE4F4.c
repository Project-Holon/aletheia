/*
 * function: BTL_HANDLER_ITEM_KingsRockFlingFlinch
 * address:  0x021DE4F4
 * packet:   pkt_ov093_021DE4F4
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
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int BTL_EVENT_GetVar(int key);
extern void *func_021C88A4(char *p, int a, int b);
extern void func_021C88C8(void *a, void *b);

void BTL_HANDLER_ITEM_KingsRockFlingFlinch(int a, void *b, int c)
{
    u8 *m;

    if (c == BTL_EVENT_GetVar(2)) {
        m = (u8 *)func_021C88A4(b, 0x2b, c);
        m[4] = c;
        m[5] = 100;
        func_021C88C8(b, m);
    }
}
