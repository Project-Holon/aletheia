/*
 * function: func_0215D34C
 * address:  0x0215D34C
 * packet:   pkt_ov010_0215D34C
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   DIFF
 *
 * Script command: start the ov010 link sequence (func_02155A98) for mode
 * 0/1, or push the ov112 proc through func_02014808 otherwise.
 * Size-exact, 17 bytes out: the image keeps vm in r4 and c in r5 (the
 * mode byte, the task work and the box then reuse r4); this C swaps them.
 * Cursor idiom applied; declaration orders and permuter seed 9604 flat.
 * Also blocked after that (MATCH): ov112_id reaches func_02014808's r2,
 * not an OVERLAY_ID_CONSUMERS entry, and the pooled callback
 * 0x0215DF6C has no func_ label (seed).
 *
 * symbols:
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_0215A5DC  0x0215A5DC  thumb  ov010
 *   func_0215A5E4  0x0215A5E4  thumb  ov010
 *   func_0201210C  0x0201210C  thumb
 *   func_02158F58  0x02158F58  thumb  ov010
 *   func_02159B10  0x02159B10  thumb  ov010
 *   func_02012F80  0x02012F80  thumb
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   MI_CpuFill8    0x02082BCC  arm
 *   func_02155A98  0x02155A98  thumb  ov010
 *   func_0215898C  0x0215898C  thumb  ov010
 *   func_02012A30  0x02012A30  thumb
 *   func_02011290  0x02011290  thumb
 *   func_02012F44  0x02012F44  thumb
 *   func_02030734  0x02030734  arm
 *   func_0200A640  0x0200A640  thumb
 *   func_02014808  0x02014808  thumb
 *   func_0215897C  0x0215897C  thumb  ov010
 *   func_0215DE58  0x0215DE58  thumb  ov010
 *   func_0215DF6C  0x0215DF6C  thumb  ov010
 *   ov112_id       0x00000070  data
 *   d_02172914     0x02172914  data
 *   d_021F8360     0x021F8360  data
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct Ctx {
    u8 pad00[0x14];
    u8 *pc;             /* 0x14 */
} Ctx;

typedef struct Starter {
    void *seq;          /* 0x00 */
    void *link;         /* 0x04 */
    u32 mode;           /* 0x08 */
} Starter;

typedef struct Args {
    u32 f00;            /* 0x00 */
    u32 f04;            /* 0x04 */
    void *f08;          /* 0x08 */
} Args;

typedef struct Box {
    Args *args;         /* 0x00 */
} Box;

typedef u32 (*TaskFn)(void *task, u32 *state, void *work);

extern void *func_0215A5F4(void *vm);
extern void *func_0215A5DC(void *vm);
extern void *func_0215A5E4(void *vm);
extern void *func_0201210C(void *evt);
extern void func_02158F58(void *a);
extern u16 func_02159B10(Ctx *c, void *vm);
extern void *func_02012F80(void *sys);
extern void *func_020122C0(void *a, u32 b, TaskFn fn, u32 size);
extern Starter *func_020124E8(void *task);
extern void MI_CpuFill8(void *dst, u8 val, u32 size);
extern void *func_02155A98(void *a, void *b, u32 c, u32 d, void *link);
extern void func_0215898C(void *a, void *task);
extern void func_02012A30(void *sys);
extern void func_02011290(Ctx *c);
extern void *func_02012F44(void *sys);
extern void *func_02030734(u32 heap, u32 size, int clear, const char *site, u16 tag);
extern void *func_0200A640(void *sv);
extern void *func_02014808(void *evt, void *proc, u32 id, void *data, Args *args, TaskFn fn, Box *box);
extern void func_0215897C(void *a, void *task);
extern u32 func_0215DE58(void *task, u32 *state, void *work);
extern u32 func_0215DF6C(void *task, u32 *state, void *work);
extern u8 ov112_id[];
extern const char d_02172914[];
extern u8 d_021F8360[];

int func_0215D34C(Ctx *c, void *vm)
{
    void *a;
    void *evt;
    void *sys;
    void *proc;
    u16 arg;
    u8 mode;

    a = func_0215A5F4(vm);
    evt = func_0215A5DC(vm);
    sys = func_0215A5E4(vm);
    proc = func_0201210C(evt);
    func_02158F58(a);
    arg = func_02159B10(c, vm);
    mode = *c->pc;
    c->pc++;
    if (mode <= 1) {
        void *link = func_02012F80(sys);
        u32 d = 1;
        void *task;
        Starter *s;

        if (mode == 0)
            d = 0;
        task = func_020122C0(evt, 0, func_0215DE58, sizeof(Starter));
        s = func_020124E8(task);
        MI_CpuFill8(s, 0, sizeof(Starter));
        s->seq = func_02155A98(evt, sys, (u8)arg, d, link);
        s->link = link;
        s->mode = d;
        func_0215898C(a, task);
        func_02012A30(sys);
        func_02011290(c);
        return 1;
    } else {
        void *sv = func_02012F44(sys);
        Box *box;

        box = func_02030734(4, sizeof(Box), 1, d_02172914, 0xA9);
        box->args = func_02030734(4, 0x14, 1, d_02172914, 0xAA);
        box->args->f00 = 0;
        box->args->f08 = func_0200A640(sv);
        box->args->f04 = 1;
        func_0215897C(a, func_02014808(evt, proc, (u32)ov112_id, d_021F8360, box->args, func_0215DF6C, box));
        return 1;
    }
}
