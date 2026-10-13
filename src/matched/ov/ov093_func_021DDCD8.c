/*
 * function: BTL_HANDLER_ITEM_WeakenHitOfType
 * address:  0x021DDCD8
 * packet:   pkt_ov093_021DDCD8
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
 *   BTL_POKEPARAM_HasSubstitute  0x021D6D7C  thumb  ov093
 *   BTL_EVENT_MultiplyVar  0x021D7704  thumb  ov093
 *   func_021C7EC4  0x021C7EC4  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;

extern int BTL_EVENT_GetVar(int key);
extern void *func_021C7CF4(int *p, int i);
extern u32 BTL_POKEPARAM_HasSubstitute(u8 *p);
extern void BTL_EVENT_MultiplyVar(int a, int b);
extern u32 func_021C7EC4(u8 *p);

int BTL_HANDLER_ITEM_WeakenHitOfType(int a, u8 *b, int c, int *d, u8 e, int f)
{
    if (c == BTL_EVENT_GetVar(4) && e == BTL_EVENT_GetVar(0x16)
        && (f != 0 || BTL_EVENT_GetVar(0x38) > 3)
        && BTL_POKEPARAM_HasSubstitute(func_021C7CF4((int *)b, c)) == 0) {
        BTL_EVENT_MultiplyVar(0x35, 0x800);
        if (func_021C7EC4(b) == 0)
            *d = 1;
        return 1;
    }
    return 0;
}
