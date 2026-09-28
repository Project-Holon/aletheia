/*
 * function: func_02166D30
 * address:  0x02166D30
 * packet:   pkt_ov010_02166D30
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 *
 * Script command: reads a kind and three variable pointers, starts the
 * func_02166E50 task over a 0x1C-byte work, and for kinds 0..5 opens the
 * matching window (func_02024044), optionally filled with a message.
 *
 * MATCH, first draft (2026-09-28 tree_ov010_4): byte-correct; the one
 * wildcard is the bl to arm9 0x02024108, a Thumb function (`ldrh r2, [r1]`
 * ...) with no witness outside this file (seed for the ARM9 session).
 *
 * symbols:
 *   func_0215A5DC  0x0215A5DC  thumb  ov010
 *   func_0215A5E4  0x0215A5E4  thumb  ov010
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_02159B10  0x02159B10  thumb  ov010
 *   func_02159AE8  0x02159AE8  thumb  ov010
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   MI_CpuFill8    0x02082BCC  arm
 *   func_0215897C  0x0215897C  thumb  ov010
 *   func_02012EBC  0x02012EBC  thumb
 *   func_02024044  0x02024044  thumb
 *   func_020120F4  0x020120F4  thumb
 *   func_0200E6F0  0x0200E6F0  thumb
 *   func_0200E6FC  0x0200E6FC  thumb
 *   func_02024108  0x02024108  thumb
 *   func_02166E50  0x02166E50  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct ChoiceWork {
    u32 kind;           /* 0x00 */
    u16 *var0;          /* 0x04 */
    u16 *var1;          /* 0x08 */
    u16 *result;        /* 0x0C */
    void *win;          /* 0x10 */
    u32 msg;            /* 0x14 */
    u32 hasMsg;         /* 0x18 */
} ChoiceWork;

extern void *func_0215A5DC(void *vm);
extern void *func_0215A5E4(void *vm);
extern void *func_0215A5F4(void *vm);
extern u16 func_02159B10(void *c, void *vm);
extern u16 *func_02159AE8(void *c, void *vm);
extern void *func_020122C0(void *sys, u32 prio, void (*fn)(void *, void *), u32 size);
extern void *func_020124E8(void *task);
extern void MI_CpuFill8(void *dst, u8 val, u32 size);
extern void func_0215897C(void *vm, void *task);
extern void *func_02012EBC(void *p);
extern void *func_02024044(u32 kind, u32 a1, void *src, u32 flag, void *heap, u32 b);
extern void *func_020120F4(void *p);
extern void *func_0200E6F0(void *p);
extern void func_0200E6FC(void *a, u32 id, void *dest);
extern void func_02024108(void *win, void *src);
extern void func_02166E50(void *task, void *work);

int func_02166D30(void *c, void *vm)
{
    u8 buf[8];
    u16 *result;
    u16 *var1;
    u16 *var0;
    void *sys;
    void *heap;
    void *owner;
    ChoiceWork *w;
    void *task;
    u16 kind;
    u32 mode;

    sys = func_0215A5DC(vm);
    heap = func_0215A5E4(vm);
    owner = func_0215A5F4(vm);
    kind = func_02159B10(c, vm);
    var0 = func_02159AE8(c, vm);
    var1 = func_02159AE8(c, vm);
    result = func_02159AE8(c, vm);
    mode = 0;
    task = func_020122C0(sys, 0, func_02166E50, sizeof(ChoiceWork));
    w = func_020124E8(task);
    MI_CpuFill8(w, 0, sizeof(ChoiceWork));
    w->kind = kind;
    w->var0 = var0;
    w->var1 = var1;
    w->result = result;
    *result = 0;
    switch (kind) {
    case 0:
        w->msg = 1;
        w->hasMsg = 1;
        mode = 2;
        break;
    case 1:
        w->msg = 2;
        w->hasMsg = 1;
        mode = 2;
        break;
    case 2:
        w->msg = 3;
        w->hasMsg = 1;
        mode = 2;
        break;
    case 3:
        w->msg = 4;
        w->hasMsg = 1;
        mode = 2;
        break;
    case 4:
        w->hasMsg = 0;
        break;
    case 5:
        w->hasMsg = 0;
        mode = 1;
        break;
    default:
        w->win = 0;
        func_0215897C(owner, task);
        return 1;
    }
    w->win = func_02024044(mode, 0, 0, 0, func_02012EBC(heap), 1);
    if (w->hasMsg) {
        func_0200E6FC(func_0200E6F0(func_02012EBC(func_020120F4(sys))), w->msg, buf);
        func_02024108(w->win, buf);
    }
    func_0215897C(owner, task);
    return 1;
}
