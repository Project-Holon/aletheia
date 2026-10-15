/*
 * function: SCRCMD_RESEARCH_GetMissionElapsedHours
 * address:  0x0216BB18
 * packet:   pkt_ov010_0216BB18
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BEACON_GetBlock  0x0200C0F0  thumb
 *   BEACON_GetEntryCount  0x0200C32C  thumb
 *   BEACON_GetLastTime  0x0200C37C  thumb
 *   GF_STANDARD_SetupRtc  0x0203F524  arm
 *   RTC_ConvertSecondToDateTime  0x020891E0  arm
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long long u64;

extern void *BEACON_GetBlock(void *sys);
struct Blk34;
extern u8 BEACON_GetEntryCount(struct Blk34 *p);
extern unsigned long long BEACON_GetLastTime(struct Blk34 *p);
extern u64 GF_STANDARD_SetupRtc();
struct RTCDate;
struct RTCTime;
extern void RTC_ConvertSecondToDateTime(struct RTCDate *date, struct RTCTime *time, long long sec);

int SCRCMD_RESEARCH_GetMissionElapsedHours(void *sys)
{
    u32 a[7];
    void *r4;
    u64 t;

    r4 = BEACON_GetBlock(sys);
    if (BEACON_GetEntryCount(r4) == 0) {
        return 0;
    }
    t = BEACON_GetLastTime(r4);
    RTC_ConvertSecondToDateTime((struct RTCDate *)(a + 3), (struct RTCTime *)a, GF_STANDARD_SetupRtc() - t);
    if (a[3] != 0 || a[4] > 1 || a[5] > 1) {
        return 24;
    }
    return (u16)a[0];
}
