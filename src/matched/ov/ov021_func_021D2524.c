/*
 * function: SCRCMD_ShowPokeIconWindow
 * address:  0x021D2524
 * packet:   pkt_ov021_021D2524
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   SCRCMD_WORK_GetGameSystem  0x0215A5DC  thumb  ov010
 *   GAMESYSTEM_GetFieldMap  0x0201210C  thumb
 *   SCRIPT_WORK_ReadWorkValue  0x02159B10  thumb  ov010
 *   SCRCMD_WORK_GetScriptWork  0x0215A5F4  thumb  ov010
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   SCRCMD_POKE_ICON_InitWindow  0x021D25A4  thumb  ov021
 *   SCRCMD_POKE_ICON_CreateIcon  0x021D25F4  thumb  ov021
 *   SCRCMD_POKE_ICON_Task  0x021D26D0  thumb  ov021
 *   SCRIPT_SYS_CallEvent  0x0215897C  thumb  ov010
 * Addresses are Black-image addresses.
 */

typedef unsigned int u32;

extern void *SCRCMD_WORK_GetGameSystem(void *a0);
struct Ctx;
struct Desc;
struct Obj;
extern void *GAMESYSTEM_GetFieldMap(const struct Ctx *p);
extern unsigned int SCRIPT_WORK_ReadWorkValue(void *a, void *b);
extern void *SCRCMD_WORK_GetScriptWork(void *p);
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern void *func_020124E8(struct Obj *p);
extern void SCRCMD_POKE_ICON_InitWindow(u32 *p);
extern u32 SCRCMD_POKE_ICON_Task(u32 a, u32 *st, u32 *p);
extern void SCRCMD_POKE_ICON_CreateIcon(u32 *p, int a, int b, int c, int s0, int s1);
extern void SCRIPT_SYS_CallEvent(void *vm, void *task);

int SCRCMD_ShowPokeIconWindow(u32 a, u32 b)
{
    u32 r5, s1, s2, s3;
    void *r4;
    void *r6;
    void *r7;

    r6 = SCRCMD_WORK_GetGameSystem((void *)b);
    GAMESYSTEM_GetFieldMap(r6);
    s1 = SCRIPT_WORK_ReadWorkValue((void *)a, (void *)b);
    s2 = SCRIPT_WORK_ReadWorkValue((void *)a, (void *)b);
    s3 = SCRIPT_WORK_ReadWorkValue((void *)a, (void *)b);
    r5 = SCRIPT_WORK_ReadWorkValue((void *)a, (void *)b);
    r7 = SCRCMD_WORK_GetScriptWork((void *)b);
    r4 = func_020122C0(r6, 0, SCRCMD_POKE_ICON_Task, 0x18);
    r6 = func_020124E8(r4);
    SCRCMD_POKE_ICON_InitWindow(r6);
    SCRCMD_POKE_ICON_CreateIcon(r6, s1, s2, s3, r5, 0);
    SCRIPT_SYS_CallEvent(r7, r4);
    return 1;
}
