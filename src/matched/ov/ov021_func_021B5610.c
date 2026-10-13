/*
 * function: SCRCMD_PROC_FLD_CallOv056Event
 * address:  0x021B5610
 * packet:   pkt_ov021_021B5610
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
 *   SCRIPT_WORK_ReadWorkValue  0x02159B10  thumb  ov010
 *   GIMMICK_INIT_SetCartLanesFlags  0x021F36C0  thumb  ov037
 *   SCRIPT_SYS_CallEvent  0x0215897C  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct Ctx;

extern void *SCRCMD_WORK_GetScriptWork(void *p);
extern void *SCRCMD_WORK_GetGameSystem(void *a0);
extern void *GAMESYSTEM_GetFieldMap(const struct Ctx *p);
extern unsigned int SCRIPT_WORK_ReadWorkValue(void *a0, void *a1);
extern void *GIMMICK_INIT_SetCartLanesFlags(void *a, u8 *b, u32 c);
extern void SCRIPT_SYS_CallEvent(void *vm, void *task);

int SCRCMD_PROC_FLD_CallOv056Event(void *a0, void *a1)
{
    void *r6 = SCRCMD_WORK_GetScriptWork(a1);
    void *r7 = SCRCMD_WORK_GetGameSystem(a1);
    u8 *t = GAMESYSTEM_GetFieldMap(r7);
    unsigned int v = SCRIPT_WORK_ReadWorkValue(a0, a1);

    SCRIPT_SYS_CallEvent(r6, GIMMICK_INIT_SetCartLanesFlags(r7, t, (u16)(v - 1)));
    return 1;
}
