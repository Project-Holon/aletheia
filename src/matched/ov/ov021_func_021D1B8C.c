/*
 * function: SCRCMD_ResetSubscreenMode
 * address:  0x021D1B8C
 * packet:   pkt_ov021_021D1B8C
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
 *   FIELDMAP_GetSubscreen  0x02188CCC  thumb  ov021
 *   SCRCMD_WORK_GetGameSystem  0x0215A5DC  thumb  ov010
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   SCRCMD_SUBSCREEN_ChangeModeTask  0x021D1AEC  thumb  ov021
 *   SCRIPT_SYS_CallEvent  0x0215897C  thumb  ov010
 *   SCRIPT_WORK_ResetCheckFlag  0x02159168  thumb  ov010
 * Addresses are Black-image addresses.
 */

typedef unsigned int u32;

extern void *SCRCMD_WORK_GetScriptWork(void *p);
typedef unsigned char  u8;
extern int SCRIPT_WORK_ResetFieldParam(int a0);
extern u32 FIELDMAP_GetSubscreen(u8 *p);
extern void *SCRCMD_WORK_GetGameSystem(void *a0);
struct Desc;
struct Obj;
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern void *func_020124E8(struct Obj *p);
extern int SCRCMD_SUBSCREEN_ChangeModeTask(int a, int *seq, u32 *c);
extern void SCRIPT_SYS_CallEvent(void *vm, void *task);
extern void SCRIPT_WORK_ResetCheckFlag(int n);

int SCRCMD_ResetSubscreenMode(u32 a, u32 b)
{
    u32 r4;
    void *r5;
    void *r6;
    u32 *p;

    r5 = SCRCMD_WORK_GetScriptWork((void *)b);
    r4 = FIELDMAP_GetSubscreen((u8 *)(((u32 *)SCRIPT_WORK_ResetFieldParam((int)r5))[1]));
    r6 = SCRCMD_WORK_GetGameSystem((void *)b);
    r6 = func_020122C0(r6, 0, SCRCMD_SUBSCREEN_ChangeModeTask, 8);
    p = func_020124E8(r6);
    p[0] = r4;
    p[1] = 0;
    SCRIPT_SYS_CallEvent(r5, r6);
    SCRIPT_WORK_ResetCheckFlag(8);
    return 1;
}
