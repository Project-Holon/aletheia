/*
 * function: BTL_CLIENT_GetEscapeBlocker
 * address:  0x021CF8D4
 * packet:   pkt_ov093_021CF8D4
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_CLIENT_IsHeldItemEffective  0x021CF89C  thumb  ov093
 *   BTL_POKEPARAM_GetItem  0x021D5B40  thumb  ov093
 *   BTL_CLIENT_FindTrapper  0x021CF9B4  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern int BTL_CLIENT_IsHeldItemEffective(u8 *p, void *q);
struct QI;
extern u16 BTL_POKEPARAM_GetItem(struct QI *p);
extern u32 BTL_CLIENT_FindTrapper(u8 *p, void *q, u8 *a, u16 *b);

u32 BTL_CLIENT_GetEscapeBlocker(u8 *p, void *q, u8 *a, u16 *b)
{
    u32 r;
    if (BTL_CLIENT_IsHeldItemEffective(p, q) != 0) {
        if (BTL_POKEPARAM_GetItem(q) == 0x127) {
            return 4;
        }
    }
    r = BTL_CLIENT_FindTrapper(p, q, a, b);
    if (r == 4) {
        *a = 0x1f;
        *b = 0;
        r = 4;
    }
    return r;
}
