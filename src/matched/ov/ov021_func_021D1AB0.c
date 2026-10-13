/*
 * function: SCRCMD_WaitMmdlIcaAnime
 * address:  0x021D1AB0
 * packet:   pkt_ov021_021D1AB0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Formerly MATCH on unwitnessed callees; their matched entries now witness them.
 *
 * symbols:
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   SCRIPT_SYS_CallEvent  0x0215897C  thumb  ov010
 *   SCRIPT_WORK_GetReturnParam  0x0215910C  thumb  ov010
 *   SCRCMD_WORK_GetGameSystem  0x0215A5DC  thumb  ov010
 *   SCRCMD_WORK_GetScriptWork  0x0215A5F4  thumb  ov010
 *   SCRCMD_MMDL_ICA_WaitTask  0x021D1A9C  thumb  ov021
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void *SCRCMD_WORK_GetScriptWork(void *p);
extern u32 SCRIPT_WORK_GetReturnParam(void *p);
extern void *SCRCMD_WORK_GetGameSystem(void *a0);
struct Desc;
struct Obj;
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern void *func_020124E8(struct Obj *p);
extern void SCRIPT_SYS_CallEvent(void *vm, void *task);
extern int SCRCMD_MMDL_ICA_WaitTask(u32 a, u32 b, u32 c, u32 d);

int SCRCMD_WaitMmdlIcaAnime(u32 a, u32 b)
{
    void *x = SCRCMD_WORK_GetScriptWork((void *)b);
    void *task = func_020122C0((void *)SCRCMD_WORK_GetGameSystem((void *)b), 0, SCRCMD_MMDL_ICA_WaitTask, 4);
    u32 *w = func_020124E8(task);

    *w = SCRIPT_WORK_GetReturnParam(x);
    SCRIPT_SYS_CallEvent(x, task);
    return 1;
}
