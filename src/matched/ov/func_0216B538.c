/*
 * function: SCRCMD_RESEARCH_CmdRaiseResearchRank
 * address:  0x0216B538
 * packet:   pkt_0216B538
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 * blocked:  listing 64 compiled 62
 *
 * symbols:
 *   SCRCMD_WORK_GetScriptWork  0x0215A5F4  thumb  ov010
 *   SCRCMD_WORK_GetGameData  0x0215A5E4  thumb  ov010
 *   GAME_DATA_GetSaveControl  0x02012EBC  thumb
 *   func_0200C0F0  0x0200C0F0  thumb
 *   func_0200C224  0x0200C224  thumb
 *   func_0200C22C  0x0200C22C  thumb
 *   GAME_BEACON_SetResearchTeamRank  0x02027138  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct Big;

extern void *SCRCMD_WORK_GetScriptWork(void *p);
extern void *SCRCMD_WORK_GetGameData(void *a0);
extern void *GAME_DATA_GetSaveControl(struct Big *p);
extern void *func_0200C0F0(void *sys);
struct Blk34;
extern u8 func_0200C224(struct Blk34 *p);
extern int func_0200C22C();
extern int GAME_BEACON_SetResearchTeamRank();

int SCRCMD_RESEARCH_CmdRaiseResearchRank(int a0, int a1)
{
    int t4;
    void *t5;
    void *p;
    void *v0;
    void *v1;

t4 = a1 + 0;
a0 = t4 + 0;
    v0 = SCRCMD_WORK_GetScriptWork((void *)a0);
loc_0216B542:
a0 = t4 + 0;
    v1 = SCRCMD_WORK_GetGameData((void *)a0);
loc_0216B548:
    p = GAME_DATA_GetSaveControl((struct Big *)v1);
loc_0216B54C:
    t5 = func_0200C0F0(p);
loc_0216B550:
    a0 = func_0200C224(t5);
loc_0216B556:
t4 = a0 + 0;
    if (t4 < 5) goto loc_0216B560;
loc_0216B55C:
a0 = 0;
    return a0;
loc_0216B560:
a1 = t4 + 1;
    a0 = func_0200C22C(t5, a1);
loc_0216B568:
a0 = t4 + 1;
a0 = a0 << 0x18;
a0 = (unsigned)a0 >> 0x18;
    a0 = GAME_BEACON_SetResearchTeamRank(a0);
loc_0216B572:
a0 = 0;
    return a0;}
