/*
 * function: func_021CF7DC
 * address:  0x021CF7DC
 * packet:   pkt_ov021_021CF7DC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Script command: starts the func_021CF844 task over a 0xD8-byte work and
 * fills its header.
 *
 * symbols:
 *   SCRCMD_WORK_GetGameSystem  0x0215A5DC  thumb  ov010
 *   SCRCMD_WORK_GetGameData  0x0215A5E4  thumb  ov010
 *   SCRCMD_WORK_GetScriptWork  0x0215A5F4  thumb  ov010
 *   SCRIPT_WORK_ReadWorkPointer  0x02159AE8  thumb  ov010
 *   SCRIPT_SYS_CallEvent  0x0215897C  thumb  ov010
 *   func_020122C0  0x020122C0  thumb
 *   GAME_DATA_GetMyStatus  0x02012944  thumb
 *   func_020124E8  0x020124E8  thumb
 *   func_02008530  0x02008530  thumb
 *   func_021CF844  0x021CF844  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct Work {
    u32 f00;
    u32 f04;
    u16 *f08;
    u32 f0c;
} Work;

extern void *SCRCMD_WORK_GetGameSystem(void *vm);
extern void *SCRCMD_WORK_GetGameData(void *vm);
extern void *SCRCMD_WORK_GetScriptWork(void *vm);
extern u16 *SCRIPT_WORK_ReadWorkPointer(void *c, void *vm);
extern void  SCRIPT_SYS_CallEvent(void *vm, void *task);
struct Desc;
struct Obj;
struct Sub0200852CObj;
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern u8 *GAME_DATA_GetMyStatus(void *p);
extern void *func_020124E8(struct Obj *p);
extern u32 func_02008530(const struct Sub0200852CObj *obj);
extern int func_021CF844(void *a, int *task, struct Work *w);

int func_021CF7DC(void *c, void *vm)
{
    void *owner = SCRCMD_WORK_GetScriptWork(vm);
    void *sys = SCRCMD_WORK_GetGameSystem(vm);
    void *heap = SCRCMD_WORK_GetGameData(vm);
    u16 *var = SCRIPT_WORK_ReadWorkPointer(c, vm);
    void *task;
    void *h2;
    Work *w;

    task = func_020122C0(sys, 0, func_021CF844, 0xd8);
    h2 = GAME_DATA_GetMyStatus(heap);
    w = func_020124E8(task);
    w->f00 = func_02008530(h2);
    w->f0c = 0;
    w->f04 = 0;
    w->f08 = var;
    SCRIPT_SYS_CallEvent(owner, task);
    return 1;
}
