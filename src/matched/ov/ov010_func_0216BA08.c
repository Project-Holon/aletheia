/*
 * function: SCRCMD_RESEARCH_AreAllTargetValuesRecorded
 * address: 0x0216BA08
 * packet: pkt_ov010_0216BA08
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: two-byte zero alignment padding at 0216BA3E follows.
 * symbols:
 *   BEACON_GetFromSave 0x0200C0E8 thumb
 *   BEACON_GetEntryCount 0x0200C32C thumb
 *   BEACON_GetRecentValue 0x0200C34C thumb
 *   SCRCMD_RESEARCH_GetMissionTargetCount 0x0216BB80 thumb ov010
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void *BEACON_GetFromSave(void *);
struct Blk34;
extern u8 BEACON_GetEntryCount(struct Blk34 *p);
extern u16 BEACON_GetRecentValue(struct Blk34 *p, u32 i);
extern int SCRCMD_RESEARCH_GetMissionTargetCount(int);
int SCRCMD_RESEARCH_AreAllTargetValuesRecorded(void *p)
{
    void *q;
    int i, n;
    q = BEACON_GetFromSave(p);
    n = (u8)SCRCMD_RESEARCH_GetMissionTargetCount(BEACON_GetEntryCount(q));
    for (i = 0; i < n; i++) {
        if (BEACON_GetRecentValue(q, (u8)i) == 0) return 0;
    }
    return 1;
}
