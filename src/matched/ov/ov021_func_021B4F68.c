/*
 * function: SCRCMD_PROC_FLD_CallOv219Event
 * address:  0x021B4F68
 * packet:   pkt_ov021_021B4F68
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
 *   SCRIPT_SYS_CallEvent  0x0215897C  thumb  ov010
 *   GAMESYSTEM_GetFieldMap  0x0201210C  thumb
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   FIELD_STATUS_CreateSubProcEvent  0x020146F8  thumb
 *   abs_id_DB      0x000000DB  data
 *   d_02185F0C     0x02185F0C  data  ov219  a4
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u8 abs_id_DB[];
extern u8 d_02185F0C[];
extern void *SCRCMD_WORK_GetScriptWork(void *p);
extern void *SCRCMD_WORK_GetGameSystem(void *a0);
extern void SCRIPT_SYS_CallEvent(void *a, void *b);
struct Ctx;
extern void *GAMESYSTEM_GetFieldMap(const struct Ctx *p);
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
extern void *FIELD_STATUS_CreateSubProcEvent(char *a0, int a1, int a2, int a3, int a4);

int SCRCMD_PROC_FLD_CallOv219Event(u32 a, u32 b)
{
    void *r5;
    void *r4;
    void *r6;

    r5 = SCRCMD_WORK_GetGameSystem((void *)b);
    r4 = SCRCMD_WORK_GetScriptWork((void *)b);
    r6 = GAMESYSTEM_GetFieldMap((void *)r5);
    SCRIPT_SYS_CallEvent(r4, FIELD_STATUS_CreateSubProcEvent(r5, (int)r6, (int)abs_id_DB, (int)d_02185F0C, (int)GAMESYSTEM_GetGameData(r5)));
    return 1;
}
