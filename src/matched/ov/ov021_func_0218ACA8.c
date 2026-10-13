/*
 * function: FIELD_EVENT_CHECK_CreateGPowerExpireEvent
 * address:  0x0218ACA8
 * packet:   pkt_ov021_0218ACA8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GPOWER_GetExpiringPowerId  0x02010F18  thumb
 *   GAME_EVENT_CreateOverlayEvent  0x020124AC  thumb
 *   abs_id_83      0x00000053  data
 *   GPOWER_EVENT_CreateTimeoutScriptEvent  0x021F532C  thumb  ov083
 */

typedef unsigned char u8;
typedef unsigned int  u32;

struct Desc;

extern u8 abs_id_83[];
extern u8 GPOWER_GetExpiringPowerId(void);
extern struct Desc *GAME_EVENT_CreateOverlayEvent(void *a0, u32 a1, u32 (*fn)(void *, u32), u32 a3);
extern void GPOWER_EVENT_CreateTimeoutScriptEvent(void *p);

struct Desc *FIELD_EVENT_CHECK_CreateGPowerExpireEvent(void *a)
{
    if (GPOWER_GetExpiringPowerId() == 0x30) {
        return 0;
    }
    return GAME_EVENT_CreateOverlayEvent(a, (u32)abs_id_83, (u32 (*)(void *, u32))GPOWER_EVENT_CreateTimeoutScriptEvent, 0);
}
