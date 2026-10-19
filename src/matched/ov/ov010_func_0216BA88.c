/*
 * function: SCRCMD_RESEARCH_GetMissionShortfall
 * address:  0x0216BA88
 * packet:   pkt_ov010_0216BA88
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   SYMBOL_SAVE_GetBitBlock  0x0200E394  thumb
 *   MISC_GetFromSave  0x0200C0E8  thumb
 *   MISC_GetResearchMissionIndex  0x0200C32C  thumb
 *   SCRCMD_RESEARCH_GetMissionTargetIds  0x0216BB90  thumb  ov010
 *   SCRCMD_RESEARCH_GetMissionTargetCount  0x0216BB80  thumb  ov010
 *   SCRCMD_RESEARCH_GetMissionGoal  0x0216BBB4  thumb  ov010
 *   SCRCMD_RESEARCH_GetTallyTotal  0x0216B970  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void *SYMBOL_SAVE_GetBitBlock(void *a0);
extern void *MISC_GetFromSave(void *sys);
struct Blk34;
extern u8 MISC_GetResearchMissionIndex(struct Blk34 *p);
extern void SCRCMD_RESEARCH_GetMissionTargetIds(int index, u8 *out);
extern int SCRCMD_RESEARCH_GetMissionTargetCount(int index);
extern int SCRCMD_RESEARCH_GetMissionGoal(int index);
extern u32 SCRCMD_RESEARCH_GetTallyTotal(const u16 *p, int index);

u16 SCRCMD_RESEARCH_GetMissionShortfall(int c)
{
    int i;
    u8 buf[4];
    int n;
    u32 lim;
    u32 best;
    void *r7;
    int r4;

    r7 = SYMBOL_SAVE_GetBitBlock((void *)c);
    r4 = MISC_GetResearchMissionIndex(MISC_GetFromSave((void *)c));
    lim = SCRCMD_RESEARCH_GetMissionGoal(r4);
    n = (u8)SCRCMD_RESEARCH_GetMissionTargetCount(r4);
    SCRCMD_RESEARCH_GetMissionTargetIds(r4, buf);
    best = 1009998;
    for (i = 0; i < n; i++) {
        u32 v = SCRCMD_RESEARCH_GetTallyTotal(r7, buf[i]);
        if (v < best) {
            best = v;
        }
    }
    return lim - best;
}
