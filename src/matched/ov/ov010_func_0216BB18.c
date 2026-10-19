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
 *   MISC_GetBlock  0x0200C0F0  thumb
 *   MISC_GetResearchMissionIndex  0x0200C32C  thumb
 *   MISC_GetLastTime  0x0200C37C  thumb
 *   GF_STANDARD_GetRtcTimestamp  0x0203F524  arm
 *   RTC_ConvertSecondToDateTime  0x020891E0  arm
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long long u64;

extern void *MISC_GetBlock(void *sys);
struct Blk34;
extern u8 MISC_GetResearchMissionIndex(struct Blk34 *p);
extern unsigned long long MISC_GetLastTime(struct Blk34 *p);
extern u64 GF_STANDARD_GetRtcTimestamp();
struct RTCDate;
struct RTCTime;
extern void RTC_ConvertSecondToDateTime(struct RTCDate *date, struct RTCTime *time, long long sec);

int SCRCMD_RESEARCH_GetMissionElapsedHours(void *sys)
{
    u32 a[7];
    void *r4;
    u64 t;

    r4 = MISC_GetBlock(sys);
    if (MISC_GetResearchMissionIndex(r4) == 0) {
        return 0;
    }
    t = MISC_GetLastTime(r4);
    RTC_ConvertSecondToDateTime((struct RTCDate *)(a + 3), (struct RTCTime *)a, GF_STANDARD_GetRtcTimestamp() - t);
    if (a[3] != 0 || a[4] > 1 || a[5] > 1) {
        return 24;
    }
    return (u16)a[0];
}
