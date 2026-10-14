/*
 * function: SCRCMD_RESEARCH_AreMissionTargetsAtGoal
 * address:  0x0216B994
 * packet:   pkt_ov010_0216B994
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   SCRCMD_RESEARCH_GetMissionTargetIds  0x0216BB90  thumb  ov010
 *   SCRCMD_RESEARCH_GetMissionTargetCount  0x0216BB80  thumb  ov010
 *   SCRCMD_RESEARCH_GetMissionGoal  0x0216BBB4  thumb  ov010
 *   SCRCMD_RESEARCH_GetTallyTotal  0x0216B970  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void SCRCMD_RESEARCH_GetMissionTargetIds(int index, u8 *out);
extern int SCRCMD_RESEARCH_GetMissionTargetCount(int index);
extern int SCRCMD_RESEARCH_GetMissionGoal(int index);
extern u32 SCRCMD_RESEARCH_GetTallyTotal(const u16 *p, int index);

int SCRCMD_RESEARCH_AreMissionTargetsAtGoal(int c, int vm)
{
    int i;
    u8 buf[4];
    int n;
    u32 lim;

    SCRCMD_RESEARCH_GetMissionTargetIds(vm, buf);
    n = (u8)SCRCMD_RESEARCH_GetMissionTargetCount(vm);
    lim = SCRCMD_RESEARCH_GetMissionGoal(vm);
    for (i = 0; i < n; i++) {
        if (SCRCMD_RESEARCH_GetTallyTotal((const u16 *)c, buf[i]) < lim) {
            return 0;
        }
    }
    return 1;
}
