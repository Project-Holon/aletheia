/*
 * function: SAVE_EVENT_WriteEventIdWithDate
 * address:  0x0202F30C
 * packet:   pkt_0202F30C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GF_STANDARD_GetCachedDate   0x0203F4E4  arm
 *   ZONEDATA_IsRawZoneGroup4CTo69   0x02014034  thumb
 *   SAVE_EVENT_StoreVariant   0x0202F358  thumb
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/SAVE_EVENT_WriteEventIdWithDate.c \
 *       --func SAVE_EVENT_WriteEventIdWithDate --addr 0x0202F30C --cc 1.1p1 --thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct RtcDate;
extern void GF_STANDARD_GetCachedDate(struct RtcDate *date);
extern u32 ZONEDATA_IsRawZoneGroup4CTo69(u32 id);
extern void SAVE_EVENT_StoreVariant(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5);

void SAVE_EVENT_WriteEventIdWithDate(void *a0, u32 a1, u32 a2)
{
    u32 buf[4];

    GF_STANDARD_GetCachedDate((struct RtcDate *)buf);

    if (ZONEDATA_IsRawZoneGroup4CTo69((u16)a1) == 1)
        SAVE_EVENT_StoreVariant(a0, 0x753E, buf[0], buf[1], buf[2], a2);
    else
        SAVE_EVENT_StoreVariant(a0, a1, buf[0], buf[1], buf[2], a2);
}
