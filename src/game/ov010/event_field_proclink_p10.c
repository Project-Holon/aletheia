/*
 * file:     event_field_proclink_p10.c
 * unit:     yes
 * function: func_0215FA44, func_0215FA54, func_0215FBF4, func_0215FC40
 * address:  0x0215FA44
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   abs_id_14      0x00000014  data
 *   sub_02034A5C   0x02034A5C  arm
 *   func_02012138  0x02012138  thumb
 *   func_020120F4  0x020120F4  thumb
 *   func_0201210C  0x0201210C  thumb
 *   func_02012374  0x02012374  thumb
 *   func_020120B4  0x020120B4  thumb
 *   func_020120F0  0x020120F0  thumb
 *   func_02012444  0x02012444  thumb
 *   func_020129B8  0x020129B8  thumb
 *   func_020144DC  0x020144DC  thumb
 *   func_020145CC  0x020145CC  thumb
 *   func_02005C44  0x02005C44  thumb
 *   func_02005D90  0x02005D90  thumb
 *   func_02005DF8  0x02005DF8  thumb
 *   func_02026400  0x02026400  thumb
 *   func_02026454  0x02026454  thumb
 *   func_02026460  0x02026460  thumb
 *   func_02158344  0x02158344  thumb  ov010
 *   func_021BE8D4  0x021BE8D4  thumb
 *   func_021BE92C  0x021BE92C  thumb
 *   func_0217CE08  0x0217CE08  thumb
 *   func_0217CDBC  0x0217CDBC  thumb
 *   func_0217FA24  0x0217FA24  thumb
 *   ov122_id       0x0000007A  data
 *   ov172_id       0x000000AC  data
 *   d_021D5764     0x021D5764  data  ov122
 *   d_021C7240     0x021C7240  data
 *   func_02188CCC  0x02188CCC  thumb  ov021
 *   func_020122C0  0x020122C0  thumb
 *   func_0201232C  0x0201232C  thumb
 *   func_020124E8  0x020124E8  thumb
 *   func_02012EBC  0x02012EBC  thumb
 *   func_02082BCC  0x02082BCC  arm
 *   func_0215FD0C  0x0215FD0C  thumb  ov010
 *   func_0215FED4  0x0215FED4  thumb  ov010
 *   func_0215FEF0  0x0215FEF0  thumb  ov010
 *   func_0215FEF4  0x0215FEF4  thumb  ov010
 *   func_021A0F90  0x021A0F90  thumb  ov021
 *   func_021A0EE4  0x021A0EE4  thumb  ov021
 *   func_020355D8  0x020355D8  arm
 */
struct Comm;
struct Ctx;
struct Evt;
struct IcaAnime;
struct Obj;
struct BigObj;
struct Desc;
struct Big;
struct Work;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef struct Work {
    void *sys;          /* 0x00 */
    u8 pad04[0x0C - 0x04];
    u8 f0c[0x1C - 0x0C];/* 0x0C */
    u32 f1c;            /* 0x1C */
    u32 f20;            /* 0x20 */
    u32 f24;            /* 0x24 */
    u32 f28;            /* 0x28 */
} Work;

/* record behind the descriptor: owner, its context, the context's head */
struct Rec_0215FBF4 {
    int   owner;
    void *ctx;
    void *head;
};

/* the 0x5C-byte record behind the descriptor */
struct Rec_0215FC40 {
    u16          id;     /* 0x00 */
    struct Desc *desc;   /* 0x04 */
    int          owner;  /* 0x08 */
    int          field;  /* 0x0C */
    u32          f10;
    u32          f14;
    int          f18;
    int          owner2; /* 0x1C */
    int          field2; /* 0x20 */
    struct Desc *desc2;  /* 0x24 */
    u32          f28;
    int          f2C;
    void        *fn30;
    void        *fn34;
    void        *fn38;
    void        *self;   /* 0x3C */
    u8           pad40[0x5C - 0x40];
};

extern void sub_02034A5C(int handle);
extern u32 func_02012138(const struct Ctx *p);
extern void *func_020120F4(const struct Ctx *p);
extern void *func_0201210C(const struct Ctx *p);
extern void func_02012374(struct Evt *evt, struct Evt **out);
extern void func_020120B4(struct IcaAnime *p, u32 id, void *a, void *b);
extern u32 func_020120F0(const struct Ctx *p);
extern void func_02012444(struct Obj *obj, u32 a1, u32 a2, u32 a3);
extern void func_020129B8(struct BigObj *p, u32 v);
extern int func_020144DC(int a0, int a1);
extern void *func_020145CC(void *sys);
extern u16 func_02005C44(void);
extern void func_02005D90(u32 h, u32 v);
extern void func_02005DF8(u32 v);
extern void func_02026400(struct Comm *p);
extern u32 func_02026454(void *obj);
extern u32 func_02026460(void *obj);
extern int func_02158344(int a0);
extern void *func_021BE8D4(void *sys, void *proc, u32 a, u32 b);
extern void *func_021BE92C(void *sys, void *proc, u32 a, u32 b, u32 c, u32 d, u32 e);
extern void *func_0217CE08(void *sys, void *proc, u32 a, u32 b);
extern void *func_0217CDBC(void *sys);
extern void *func_0217FA24(void *sys);
extern u32 func_02188CCC(u8 *p);
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern void func_0201232C(char *p, int a1, int a2);
extern void *func_020124E8(struct Obj *p);
extern void *func_02012EBC(struct Big *p);
extern void func_02082BCC();
extern int func_0215FD0C(void *task, void *unused, struct Ctx *c);
extern int func_0215FED4(void *a0, void *a1);
extern int func_0215FEF0(void);
extern int func_0215FEF4(u32 *a0, u32 *a1);
extern u32 func_021A0F90(u8 *p);
extern int func_021A0EE4();
extern void func_020355D8(u8 v);
void func_0215FA44(void);
int func_0215FA54(void *evt, u32 *state, Work *w);
struct Desc *func_0215FBF4(int a0, int a1, struct Desc *a2, int a3);
struct Desc *func_0215FC40(int a0, int a1, u16 a2);
extern unsigned char abs_id_14[];
extern u8 ov122_id[];
extern u8 ov172_id[];
extern u8 d_021D5764[];
extern u8 d_021C7240[];


/*
 * note:     wave 17 (overlay_id class): EXACT. The pooled overlay-id site
 *           abs_id_14 (20) resolves as `overlay_id` (a layout overlay index,
 *           loaded by a pc-relative load of this function, reaching the id
 *           register of a known overlay loader), which was the last blocker.
 *
 * Thumb tail call into the ARM sub_02034A5C with the id 0x14, which the
 * original loads from its own pool rather than as `movs r0, #0x14`: the
 * pooled small constant is an absolute linker symbol
 * (docs/idioms/a-pooled-small-constant-argument-is-a-linker-symbol.md).
 * Unlabelled in the listing (no lr-saving prologue, callers only in arm9);
 * the pair with func_0215FA34 (same id, into sub_02034AC4).
 */
void func_0215FA44(void)
{
    sub_02034A5C((int)abs_id_14);
}


/*
 * Proc main of an ov010 sub-sequence: 11 states that push the child
 * tasks, load ov122 and ov172, and pick the closing screen from w->f28.
 * Byte-correct (first draft plus one lever: in state 9 the `f28 == 2`
 * test and the call share an else block ending in the one `*state = 10`
 * store, so that store is the copy the other arms cross-jump to).
 * Former blocker (MATCH): the pooled 0xAC is ov172_id passed in r1 to
 * func_02012444, which is not in match.py's OVERLAY_ID_CONSUMERS
 * (func_02012444 stores r1 in a task descriptor, src/matched/func_02012444.c),
 * so the ABS32 at +0x190 has no witness.
 *
 * 2026-10-05 (D8 lane 15): overlay id sites now resolve; all relocations resolved, EXACT.
 */
int func_0215FA54(void *evt, u32 *state, Work *w)
{
    void *sys = w->sys;
    void *save = (void *)func_02012138(sys);
    void *ctx = func_020120F4(sys);
    void *proc = func_0201210C(sys);

    switch (*state) {
    case 0:
        func_02012374(evt, func_021BE8D4(sys, proc, 0, 0));
        (*state)++;
        break;
    case 1:
        func_02012374(evt, (struct Evt **)func_020144DC((int)sys, (int)proc));
        *state = 2;
        break;
    case 2:
        (*state)++;
    case 3:
        func_020120B4(sys, (u32)ov122_id, d_021D5764, w);
        (*state)++;
        break;
    case 4:
        if (func_020120F0(sys) != 0)
            break;
        switch (w->f20) {
        case 0:
            if (func_02158344((int)save) && w->f28 == 2)
                func_020129B8(ctx, 3);
            *state = 6;
            break;
        case 1:
            w->f24 = func_02005C44();
            func_02012444(evt, (u32)ov172_id, (u32)d_021C7240, (u32)w->f0c);
            *state = 5;
            break;
        default:
            *state = 6;
            break;
        }
        break;
    case 5:
        if (func_020120F0(sys) != 0)
            break;
        func_02005D90(w->f24, 0xFFFF);
        func_02005DF8(60);
        *state = 6;
        break;
    case 6:
        w->f1c = 0;
        (*state)++;
        break;
    case 7:
        func_02012374(evt, func_020145CC(sys));
        (*state)++;
        break;
    case 8:
        func_02012374(evt, func_021BE92C(sys, proc, 0, 0, 1, 0, 0));
        (*state)++;
        break;
    case 9:
        if (w->f20 == 0) {
            if (w->f28 == 0) {
                if (func_02026460(save))
                    break;
                if (func_02026454(save)) {
                    func_02026400(save);
                    break;
                }
                func_02012374(evt, func_0217CE08(sys, proc, 0x117, 0));
                *state = 10;
            } else if (w->f28 == 3) {
                func_02012374(evt, func_0217FA24(sys));
                *state = 10;
            } else {
                if (w->f28 != 2)
                    func_02012374(evt, func_0217CDBC(sys));
                *state = 10;
            }
        } else {
            *state = 10;
        }
        break;
    case 10:
        return 1;
    }
    return 0;
}


struct Desc *func_0215FBF4(int a0, int a1, struct Desc *a2, int a3)
{
    struct Rec_0215FBF4 *p;
    void *ctx;

    func_02188CCC((u8 *)a1);
    if (a3 != 0) {
        a2 = func_020122C0((void *)a0, 0, (void *)func_0215FA54, 0x34);
    } else {
        func_0201232C((char *)a2, (int)func_0215FA54, 0x34);
    }
    p = (struct Rec_0215FBF4 *)func_020124E8((struct Obj *)a2);
    ctx = func_020120F4((const struct Ctx *)a0);
    p->ctx = ctx;
    p->head = func_02012EBC((struct Big *)ctx);
    p->owner = a0;
    return a2;
}


struct Desc *func_0215FC40(int a0, int a1, u16 a2)
{
    int x;
    int sz = 0x5c;
    struct Desc *r7;
    struct Rec_0215FC40 *p;
    int r;

    x = func_02188CCC((u8 *)a1);
    r7 = func_020122C0((void *)a0, 0, (void *)func_0215FD0C, sz);
    p = (struct Rec_0215FC40 *)func_020124E8((struct Obj *)r7);
    func_02082BCC(p, 0, sz);
    p->owner = a0;
    p->desc = r7;
    p->field = a1;
    p->id = a2;
    p->f14 = 0;
    p->owner2 = a0;
    p->field2 = a1;
    p->desc2 = r7;
    p->fn30 = (void *)func_0215FED4;
    p->fn34 = (void *)func_0215FEF0;
    p->fn38 = (void *)func_0215FEF4;
    p->self = p;
    p->f2C = sz - 0x5d;
    r = func_021A0F90((u8 *)x);
    switch (r) {
    case 3:
        r = 3;
        break;
    case 4:
        r = 4;
        break;
    default:
        r = func_021A0EE4(func_02188CCC((u8 *)p->field), 0);
        break;
    }
    p->f18 = r;
    func_020355D8(1);
    return r7;
}
