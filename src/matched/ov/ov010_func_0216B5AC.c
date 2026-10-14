/*
 * function: SCRCMD_RESEARCH_CmdGetMissionTargets
 * address:  0x0216B5AC
 * packet:   pkt_ov010_0216B5AC
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   SCRCMD_WORK_GetScriptWork  0x0215A5F4  thumb  ov010
 *   SCRCMD_WORK_GetGameData  0x0215A5E4  thumb  ov010
 *   GAME_DATA_GetSaveControl  0x02012EBC  thumb
 *   func_0200C0F0  0x0200C0F0  thumb
 *   SCRIPT_WORK_ReadWorkPointer  0x02159AE8  thumb  ov010
 *   func_0200C33C  0x0200C33C  thumb
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
extern int func_0200C33C(struct Blk34 *p, u32 i);

int SCRCMD_RESEARCH_CmdGetMissionTargets(int a0, int a1)
{
    void *h;
    u16 *p0;
    u16 *p1;
    u16 *p2;

    SCRCMD_WORK_GetScriptWork((void *)a1);
    h = func_0200C0F0(GAME_DATA_GetSaveControl((struct Big *)SCRCMD_WORK_GetGameData((void *)a1)));
    p0 = SCRIPT_WORK_ReadWorkPointer((void *)a0, (void *)a1);
    p1 = SCRIPT_WORK_ReadWorkPointer((void *)a0, (void *)a1);
    p2 = SCRIPT_WORK_ReadWorkPointer((void *)a0, (void *)a1);
    *p0 = func_0200C33C(h, 0);
    *p1 = func_0200C33C(h, 1);
    *p2 = func_0200C33C(h, 2);
    return 0;
}
