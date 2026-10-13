/*
 * function: SCRCMD_ChangeSubscreenMode
 * address:  0x021D1B2C
 * packet:   pkt_ov021_021D1B2C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   SCRCMD_WORK_GetScriptWork  0x0215A5F4  thumb  ov010
 *   SCRIPT_WORK_ResetFieldParam  0x02158F58  thumb  ov010
 *   SCRIPT_WORK_ReadWorkValue  0x02159B10  thumb  ov010
 *   FIELDMAP_GetSubscreen  0x02188CCC  thumb  ov021
 *   SCRCMD_WORK_GetGameSystem  0x0215A5DC  thumb  ov010
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   SCRCMD_SUBSCREEN_ChangeModeTask  0x021D1AEC  thumb  ov021
 *   d_021DD608     0x021DD608  data  a4
 *   SCRIPT_SYS_CallEvent  0x0215897C  thumb  ov010
 *   SCRIPT_WORK_SetCheckFlag  0x02159144  thumb  ov010
 * Addresses are Black-image addresses.
 */

typedef unsigned int u32;

extern u32 d_021DD608[];

extern void *SCRCMD_WORK_GetScriptWork(void *p);
typedef unsigned char  u8;
extern int SCRIPT_WORK_ResetFieldParam(int a0);
extern unsigned int SCRIPT_WORK_ReadWorkValue(void *a, void *b);
extern u32 FIELDMAP_GetSubscreen(u8 *p);
extern void *SCRCMD_WORK_GetGameSystem(void *a0);
struct Desc;
struct Obj;
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern void *func_020124E8(struct Obj *p);
extern int SCRCMD_SUBSCREEN_ChangeModeTask(int a, int *seq, u32 *c);
extern void SCRIPT_SYS_CallEvent(void *vm, void *task);
extern void SCRIPT_WORK_SetCheckFlag(int n);

int SCRCMD_ChangeSubscreenMode(u32 a, u32 b)
{
    u32 r4, r5;
    u32 *e;
    void *r7;
    void *r6;
    u32 *p;

    r7 = SCRCMD_WORK_GetScriptWork((void *)b);
    e = (u32 *)SCRIPT_WORK_ResetFieldParam((int)r7);
    r5 = SCRIPT_WORK_ReadWorkValue((void *)a, (void *)b);
    r4 = FIELDMAP_GetSubscreen((u8 *)e[1]);
    r6 = SCRCMD_WORK_GetGameSystem((void *)b);
    r6 = func_020122C0(r6, 0, SCRCMD_SUBSCREEN_ChangeModeTask, 8);
    p = func_020124E8(r6);
    r5 = d_021DD608[r5];
    p[0] = r4;
    p[1] = r5;
    SCRIPT_SYS_CallEvent(r7, r6);
    SCRIPT_WORK_SetCheckFlag(8);
    return 1;
}
