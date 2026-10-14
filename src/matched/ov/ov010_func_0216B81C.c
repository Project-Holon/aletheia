/*
 * function: SCRCMD_RESEARCH_CmdGetMissionStatus
 * address:  0x0216B81C
 * packet:   pkt_ov010_0216B81C
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   SCRCMD_WORK_GetGameData  0x0215A5E4  thumb  ov010
 *   GAME_DATA_GetSaveControl  0x02012EBC  thumb
 *   func_0200C0E8  0x0200C0E8  thumb
 *   SCRIPT_WORK_ReadWorkValue  0x02159B10  thumb  ov010
 *   SCRIPT_WORK_ReadWorkPointer  0x02159AE8  thumb  ov010
 *   func_0200C32C  0x0200C32C  thumb
 *   SCRCMD_RESEARCH_GetCurrentMissionStatus  0x0216B8B8  thumb  ov010
 *   SCRCMD_RESEARCH_GetMissionStatus  0x0216B91C  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct Big;

extern void *SCRCMD_WORK_GetGameData(void *a0);
extern void *GAME_DATA_GetSaveControl(struct Big *p);
extern void *func_0200C0E8(void *sys);
extern unsigned int SCRIPT_WORK_ReadWorkValue(void *a0, void *a1);
extern u16 *SCRIPT_WORK_ReadWorkPointer(void *a0, void *a1);
struct Blk34;
extern u8 func_0200C32C(struct Blk34 *p);
extern int SCRCMD_RESEARCH_GetCurrentMissionStatus(int a0, u16 *a1);
extern int SCRCMD_RESEARCH_GetMissionStatus(int a0, int a1, u16 *a2);

int SCRCMD_RESEARCH_CmdGetMissionStatus(int c, int vm)
{
    void *r6;
    void *t;
    int r5;
    u16 *r4;

    r6 = GAME_DATA_GetSaveControl((struct Big *)SCRCMD_WORK_GetGameData((void *)vm));
    t = func_0200C0E8(r6);
    r5 = (u8)SCRIPT_WORK_ReadWorkValue((void *)c, (void *)vm);
    r4 = SCRIPT_WORK_ReadWorkPointer((void *)c, (void *)vm);
    if (r5 == func_0200C32C(t)) {
        SCRCMD_RESEARCH_GetCurrentMissionStatus((int)r6, r4);
    } else {
        SCRCMD_RESEARCH_GetMissionStatus((int)r6, r5, r4);
    }
    return 0;
}
