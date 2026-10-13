/*
 * function: PLEASURE_BOAT_ScrCmdGetStat
 * address:  0x021C8868
 * packet:   pkt_ov021_021C8868
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   SCRCMD_WORK_GetScriptWork  0x0215A5F4  thumb  ov010
 *   SCRCMD_WORK_GetGameSystem  0x0215A5DC  thumb  ov010
 *   GAMESYSTEM_GetFieldMap  0x0201210C  thumb
 *   FIELDMAP_GetGameSystem  0x02188C80  thumb  ov021
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAME_DATA_GetEventState  0x02012ED0  thumb
 *   VM_GetU16  0x02011330  thumb
 *   SCRIPT_WORK_ReadWorkPointer  0x02159AE8  thumb  ov010
 *   PLEASURE_BOAT_GetStat  0x021C8738  thumb  ov021
 */

extern void *SCRCMD_WORK_GetScriptWork(void *p);
extern void *SCRCMD_WORK_GetGameSystem(void *a0);
struct Ctx;
extern void *GAMESYSTEM_GetFieldMap(const struct Ctx *p);
extern void *FIELDMAP_GetGameSystem(void *p);
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
typedef unsigned char  u8;
struct Big;
extern u8 *GAME_DATA_GetEventState(struct Big *p);
typedef unsigned short u16;
struct Stream;
extern u16 VM_GetU16(struct Stream *s);
extern unsigned short *SCRIPT_WORK_ReadWorkPointer(void *a0, void *a1);
extern int PLEASURE_BOAT_GetStat(char *p, int k);

int PLEASURE_BOAT_ScrCmdGetStat(int a, int b)
{
    int *r4;
    int r7;
    unsigned short *r5;

    SCRCMD_WORK_GetScriptWork((void *)b);
    r4 = (int *)GAME_DATA_GetEventState(GAMESYSTEM_GetGameData((void *)FIELDMAP_GetGameSystem(GAMESYSTEM_GetFieldMap(SCRCMD_WORK_GetGameSystem((void *)b)))));
    r7 = VM_GetU16((struct Stream *)a);
    r5 = SCRIPT_WORK_ReadWorkPointer((void *)a, (void *)b);
    *r5 = PLEASURE_BOAT_GetStat((char *)(*r4), r7);
    return 0;
}
