/*
 * function: func_0202F30C
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
 *   GF_STANDARD_SetField00_F4E4   0x0203F4E4  arm
 *   ZONEDATA_IsRawZoneGroup4CTo69   0x02014034  thumb
 *   func_0202F358   0x0202F358  thumb
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0202F30C.c \
 *       --func func_0202F30C --addr 0x0202F30C --cc 1.1p1 --thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct RtcDate;
extern void GF_STANDARD_SetField00_F4E4(struct RtcDate *date);
extern u32 ZONEDATA_IsRawZoneGroup4CTo69(u32 id);
extern void func_0202F358(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5);

void func_0202F30C(void *a0, u32 a1, u32 a2)
{
    u32 buf[4];

    GF_STANDARD_SetField00_F4E4((struct RtcDate *)buf);

    if (ZONEDATA_IsRawZoneGroup4CTo69((u16)a1) == 1)
        func_0202F358(a0, 0x753E, buf[0], buf[1], buf[2], a2);
    else
        func_0202F358(a0, a1, buf[0], buf[1], buf[2], a2);
}
