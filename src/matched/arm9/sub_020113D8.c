/*
 * function: TIMEZONE_GetNowTimeZone
 * address:  0x020113D8
 * packet:   pkt_02010BB8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GF_STANDARD_SetField00  0x0203F4CC  arm
 *   TIMEZONE_GetTimeZoneOfHour  0x020113F0  thumb
 *
 * Fills a 12-byte buffer through GF_STANDARD_SetField00 and tail-hands its own
 * argument and the buffer's first word to TIMEZONE_GetTimeZoneOfHour, a table lookup
 * that is a documented near miss (src/matched/sub_02011410.c's header has
 * the details) and so is declared here only, not defined.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_020113D8.c \
 *       --func TIMEZONE_GetNowTimeZone --addr 0x020113D8 --cc 1.1p1 --lang c99 --thumb
 */

typedef unsigned char u8;
typedef unsigned int  u32;

struct RtcTime;
extern void GF_STANDARD_SetField00(struct RtcTime *time);
extern int TIMEZONE_GetTimeZoneOfHour(int row, int col);

u32 TIMEZONE_GetNowTimeZone(u32 row)
{
    u32 buf[3];

    GF_STANDARD_SetField00((struct RtcTime *)buf);
    return TIMEZONE_GetTimeZoneOfHour(row, buf[0]);
}
