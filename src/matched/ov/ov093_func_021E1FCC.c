/*
 * function: HAND_WAZA_PerishSongClearNoEffect
 * address:  0x021E1FCC
 * packet:   pkt_ov093_021E1FCC
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 *   BTL_EVENT_GetFactorKey  0x021D70A8  thumb  ov093
 *   BTL_EVENT_OverwriteVar  0x021D76BC  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern int BTL_EVENT_GetVar(int key);
struct QQ;
extern u16 BTL_EVENT_GetFactorKey(struct QQ *p);
extern int BTL_EVENT_OverwriteVar(int key, u32 val);

void HAND_WAZA_PerishSongClearNoEffect(void *u, int a, int b)
{
    if (b == BTL_EVENT_GetVar(3)) {
        if (BTL_EVENT_GetVar(0x12) == BTL_EVENT_GetFactorKey(u))
            BTL_EVENT_OverwriteVar(0x40, 0);
    }
}
