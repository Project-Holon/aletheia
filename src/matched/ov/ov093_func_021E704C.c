/*
 * function: func_021E704C
 * address:  0x021E704C
 * packet:   pkt_ov093_021E704C
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
 *   BTL_POKEPARAM_GetItem  0x021D5B40  thumb  ov093
 *   BTLV_CORE_EventScaleDamage  0x021E8860  thumb  ov093
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int BTL_EVENT_GetVar(int key);
struct QI;
extern void *func_021C7CF4(int *p, int i);
extern u16 BTL_POKEPARAM_GetItem(struct QI *p);
extern void BTLV_CORE_EventScaleDamage(int n);

void func_021E704C(int a, void *b, int c)
{
    if (c == BTL_EVENT_GetVar(3)) {
        if (BTL_POKEPARAM_GetItem(func_021C7CF4(b, c)) == 0)
            BTLV_CORE_EventScaleDamage(2);
    }
}
