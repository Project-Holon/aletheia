/*
 * function: BTL_HANDLER_ITEM_StickyBarb_Transfer
 * address:  0x021DF150
 * packet:   pkt_ov093_021DF150
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
 *   func_021C7CF4  0x021C7CF4  thumb  ov093
 *   BTL_POKEPARAM_GetItem  0x021D5B40  thumb  ov093
 *   WAZA_TOOL_GetFlag  0x0201BEB8  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int BTL_EVENT_GetVar(int key);
extern void *func_021C88A4(char *p, int a, int b);
extern void func_021C88C8(void *a, void *b);
struct QI;
extern void *func_021C7CF4(int *p, int i);
extern u16 BTL_POKEPARAM_GetItem(struct QI *p);
extern u32 WAZA_TOOL_GetFlag(u16 id, u32 bit);

void BTL_HANDLER_ITEM_StickyBarb_Transfer(int a, void *b, int c)
{
    u8 t;
    u8 *r;

    if (c == BTL_EVENT_GetVar(4) && BTL_EVENT_GetVar(0x46) == 0) {
        if (WAZA_TOOL_GetFlag(BTL_EVENT_GetVar(0x12), 0) != 0) {
            t = BTL_EVENT_GetVar(3);
            if (BTL_POKEPARAM_GetItem(func_021C7CF4(b, t)) == 0) {
                r = (u8 *)func_021C88A4(b, 0x24, c);
                r[4] = t;
                func_021C88C8(b, r);
            }
        }
    }
}
