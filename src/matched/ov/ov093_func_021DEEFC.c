/*
 * function: BTL_HANDLER_ITEM_Leftovers_TriggerOnTurnEnd
 * address:  0x021DEEFC
 * packet:   pkt_ov093_021DEEFC
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
 *   BTL_POKEPARAM_IsHpFull  0x021D5B48  thumb  ov093
 *   BTL_EVENT_KeepFactorRunning  0x021D70C8  thumb  ov093
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int BTL_EVENT_GetVar(int key);
extern void *func_021C88A4(char *p, int a, int b);
extern void func_021C88C8(void *a, void *b);
extern void *func_021C7CF4(int *p, int i);
extern int BTL_POKEPARAM_IsHpFull(u8 *p);
extern void BTL_EVENT_KeepFactorRunning(int a);

void BTL_HANDLER_ITEM_Leftovers_TriggerOnTurnEnd(int a, void *b, int c)
{
    u32 *r;

    if (c == BTL_EVENT_GetVar(2)) {
        if (BTL_POKEPARAM_IsHpFull(func_021C7CF4(b, c)) == 0) {
            r = (u32 *)func_021C88A4(b, 0, c);
            r[1] = (r[1] & ~1) | 1;
            BTL_EVENT_KeepFactorRunning(a);
            func_021C88C8(b, r);
        }
    }
}
