/*
 * function: SCRCMD_RESEARCH_CmdGetResearchRank
 * address:  0x0216B504
 * packet:   pkt_0216B504
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 * blocked:  listing 52 compiled 50
 *
 * symbols:
 *   SCRCMD_WORK_GetScriptWork  0x0215A5F4  thumb  ov010
 *   SCRCMD_WORK_GetGameData  0x0215A5E4  thumb  ov010
 *   GAME_DATA_GetSaveControl  0x02012EBC  thumb
 *   func_0200C0F0  0x0200C0F0  thumb
 *   SCRIPT_WORK_ReadWorkPointer  0x02159AE8  thumb  ov010
 *   func_0200C224  0x0200C224  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct Big;

extern void *SCRCMD_WORK_GetScriptWork(void *p);
extern void *SCRCMD_WORK_GetGameData(void *a0);
extern void *GAME_DATA_GetSaveControl(struct Big *p);
extern void *func_0200C0F0(void *sys);
extern u16 *SCRIPT_WORK_ReadWorkPointer(void *a0, void *a1);
struct Blk34;
extern u8 func_0200C224(struct Blk34 *p);

int SCRCMD_RESEARCH_CmdGetResearchRank(int a0, int a1)
{
    int t4;
    int t5;
    void *t6;
    void *p;
    u16 *q;
    void *v0;
    void *v1;

t4 = a1 + 0;
t5 = a0 + 0;
a0 = t4 + 0;
    v0 = SCRCMD_WORK_GetScriptWork((void *)a0);
loc_0216B510:
a0 = t4 + 0;
    v1 = SCRCMD_WORK_GetGameData((void *)a0);
loc_0216B516:
    p = GAME_DATA_GetSaveControl((struct Big *)v1);
loc_0216B51A:
    t6 = func_0200C0F0(p);
loc_0216B51E:
a0 = t5 + 0;
a1 = t4 + 0;
    q = SCRIPT_WORK_ReadWorkPointer((void *)a0, (void *)a1);
loc_0216B528:
    a0 = func_0200C224(t6);
loc_0216B530:
*q = a0;
a0 = 0;
    return a0;}
