/*
 * function: BTL_CALC_AdaptabilityBoostSameType
 * address:  0x021D8C0C
 * packet:   pkt_021B75A8
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BTL_CALC_AdaptabilityBoostSameType   0x021D8C0C  thumb ov093
 *   BTL_EVENT_GetVar   0x021D775C  thumb ov093
 *   BTL_EVENT_OverwriteVar   0x021D76BC  thumb ov093
 *
 * Shape F1 (o28), gated twice: BTL_EVENT_GetVar(2) must match c and
 * BTL_EVENT_GetVar(0x44) must be non-zero, then BTL_EVENT_OverwriteVar(0x35, 2 << 12).
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

int BTL_EVENT_GetVar(int a);
int BTL_EVENT_OverwriteVar(int key, u32 val);

void BTL_CALC_AdaptabilityBoostSameType(void *a, void *b, int c)
{
    if (c == BTL_EVENT_GetVar(2)) {
        if (BTL_EVENT_GetVar(0x44) != 0)
            BTL_EVENT_OverwriteVar(0x35, 2 << 12);
    }
}
