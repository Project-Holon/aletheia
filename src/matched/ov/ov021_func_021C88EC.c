/*
 * function: PLEASURE_BOAT_ScrCmdSetPassengerInfo
 * address:  0x021C88EC
 * packet:   pkt_ov021_021C88EC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   SCRCMD_WORK_GetScriptWork  0x0215A5F4  thumb  ov010
 *   SCRCMD_WORK_GetGameSystem  0x0215A5DC  thumb  ov010
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAME_DATA_GetEventState  0x02012ED0  thumb
 *   SCRIPT_WORK_ReadWorkValue  0x02159B10  thumb  ov010
 *   VM_GetU16  0x02011330  thumb
 *   PLEASURE_BOAT_SetPassengerOccupied  0x021C87D4  thumb  ov021
 */

extern void *SCRCMD_WORK_GetScriptWork(void *p);
extern void *SCRCMD_WORK_GetGameSystem(void *a0);
struct Ctx;
struct Big;
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
extern unsigned char *GAME_DATA_GetEventState(struct Big *p);
extern unsigned int SCRIPT_WORK_ReadWorkValue(void *a, void *b);
typedef unsigned short u16;
struct Stream;
extern u16 VM_GetU16(struct Stream *s);
extern void PLEASURE_BOAT_SetPassengerOccupied(char *p, int i, int v);

int PLEASURE_BOAT_ScrCmdSetPassengerInfo(int a, int b)
{
    int *r7;
    int sp;
    int r5;
    int v;

    SCRCMD_WORK_GetScriptWork((void *)b);
    r7 = (int *)GAME_DATA_GetEventState(GAMESYSTEM_GetGameData(SCRCMD_WORK_GetGameSystem((void *)b)));
    sp = (int)SCRIPT_WORK_ReadWorkValue((void *)a, (void *)b);
    r5 = VM_GetU16((struct Stream *)a);
    VM_GetU16((struct Stream *)a);
    v = (int)SCRIPT_WORK_ReadWorkValue((void *)a, (void *)b);
    switch (r5) {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
        break;
    case 8:
        PLEASURE_BOAT_SetPassengerOccupied((char *)(*r7), sp, v == 1);
        break;
    }
    return 0;
}
