/*
 * file:     scrcmd_proc_p09.c
 * unit:     yes
 * function: func_0215C89C, func_0215C95C, func_0215CA64, func_0215CAB4, func_0215CB08, func_0215CBF0, func_0215CC38, func_0215CC4C, func_0215CCE8, func_0215CD3C, func_0215CD80
 * address:  0x0215C89C
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
 *   func_0215A5F4 0x0215A5F4 thumb ov010
 *   func_0215A5DC 0x0215A5DC thumb ov010
 *   func_020120F4 0x020120F4 thumb
 *   func_0201210C 0x0201210C thumb
 *   func_02159AE8 0x02159AE8 thumb ov010
 *   func_02159B10 0x02159B10 thumb ov010
 *   func_02012934 0x02012934 thumb
 *   func_0201AB28 0x0201AB28 thumb
 *   func_02012944 0x02012944 thumb
 *   func_0216F948 0x0216F948 thumb ov010
 *   func_0216F918 0x0216F918 thumb ov010
 *   func_02030734 0x02030734 arm
 *   func_02014808 0x02014808 thumb
 *   func_0215897C 0x0215897C thumb ov010
 *   func_0215C870 0x0215C870 thumb ov010
 *   d_021728F0 0x021728F0 data a1
 *   ov173_id 0x000000AD data
 *   d_021B81D0 0x021B81D0 data ov173 a4
 *   func_02012138  0x02012138  thumb
 *   func_02158344  0x02158344  thumb  ov010
 *   func_02012B58  0x02012B58  thumb
 *   func_0215841C  0x0215841C  thumb  ov010
 *   func_02175FB4  0x02175FB4  thumb  ov011
 *   func_0215840C  0x0215840C  thumb  ov010
 *   func_02012EBC  0x02012EBC  thumb
 *   func_0200BE48  0x0200BE48  thumb
 *   func_02175648  0x02175648  thumb  ov011
 *   func_0215C63C  0x0215C63C  thumb  ov010
 *   d_021BA758     0x021BA758  data  ov099  a1
 *   ov071_id       0x00000047  data
 *   func_02158F50  0x02158F50  thumb  ov010
 *   func_02161B90  0x02161B90  thumb  ov010
 *   func_0215A5E4  0x0215A5E4  thumb  ov010
 *   ov174_id       0x000000AE  data
 *   d_021B74A0     0x021B74A0  data  a1 ov174
 *   func_02165344  0x02165344  thumb  ov010
 *   ov221_id       0x000000DD  data
 *   ov222_id       0x000000DE  data
 *   ov224_id       0x000000E0  data
 *   d_021BA1A4     0x021BA1A4  data  ov221  a4
 *   d_021BA250     0x021BA250  data  ov222  a4
 *   d_021B9BF8     0x021B9BF8  data  ov224  a4
 *   ov223_id       0x000000DF  data
 *   d_021BC8C4     0x021BC8C4  data  ov223
 *   func_020124AC  0x020124AC  thumb
 *   func_02154438  0x02154438  thumb  ov002
 *   ov002_id       0x00000002  data
 *   func_021543BC  0x021543BC  thumb  ov003
 *   ov003_id       0x00000003  data
 *   func_02034AC4  0x02034AC4  arm
 *   func_02034A5C  0x02034A5C  arm
 *   func_021F36C0  0x021F36C0  thumb  ov037
 *   ov037_id       0x00000025  data
 *   func_021F36E8 0x021F36E8 thumb ov037
 */
struct BigObj;
struct Ctx;
struct Big;
struct Out;
struct Desc;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef struct Relearn {
    void *mon;          /* 0x00 */
    void *sess;         /* 0x04 */
    u32 f08;            /* 0x08 */
    void *sys;          /* 0x0C */
    void *moves;        /* 0x10 */
    u8 pad14[5];
    u8 f19;             /* 0x19 */
} Relearn;

typedef struct Name20 {
    u16 s[20];
} Name20;

typedef struct Profile16 {
    u32 w[4];
} Profile16;

typedef struct Rec28 {
    u8 data[0x28];
} Rec28;

typedef struct LinkState {
    u8 pad00[0x86];
    u16 self : 3;       /* 0x086 */
    u16 rest : 13;
    u8 pad88[0x1AC - 0x88];
    Rec28 recs[1];      /* 0x1AC */
} LinkState;

typedef struct ProfileWork {
    void *sys;          /* 0x00 */
    Name20 name;        /* 0x04 */
    Profile16 profile;  /* 0x2C */
    u8 slot;            /* 0x3C */
    u8 remote;          /* 0x3D */
    u8 pad3E[2];
} ProfileWork;

typedef struct Box8_0215CAB4 {
    u16 v;              /* 0x00 */
    u16 pad02;
    void *sys;          /* 0x04 */
} Box8_0215CAB4;

typedef struct Box8_0215CB08 {
    void *sys;          /* 0x00 */
    u32 v;              /* 0x04 */
} Box8_0215CB08;

typedef struct Req {
    void *sys;          /* 0x00 */
    u32 one;            /* 0x04 */
    u32 flag;           /* 0x08 */
    u32 kind;           /* 0x0C */
} Req;

typedef signed int     s32;

typedef struct { u32 a; u32 b; } Arg;

extern void *func_0215A5F4(void *vm);
extern void *func_0215A5DC(void *vm);
extern void *func_020120F4(const struct Ctx *p);
extern void *func_0201210C(const struct Ctx *p);
extern u16 *func_02159AE8(void *a0, void *a1);
extern u32 func_02159B10(void *c, void *vm);
extern void *func_02012934(const struct BigObj *p);
extern void *func_0201AB28(void *list, u32 i);
extern u8 *func_02012944(void *p);
extern u16 *func_0216F948(void *mon, u32 heap);
extern void *func_0216F918(u32 heap);
extern void *func_02030734(u32 heap, u32 size, int flags, const char *file, u16 line);
extern void *func_02014808(char *a0, int a1, int a2, int a3, int a4, int a5, int a6);
extern void func_0215897C(void *p, void *v);
extern int func_0215C870(int a0, int a1);
extern u32 func_02012138(const struct Ctx *p);
extern int func_02158344(int a0);
extern u8 func_02012B58(const struct BigObj *p);
extern u8 func_0215841C(void *p);
extern int func_02175FB4(u8 *p);
extern Name20 *func_0215840C(LinkState *s, int idx);
extern void *func_02012EBC(struct Big *p);
extern u16 *func_0200BE48(void *sys);
extern void func_02175648(void *sv, struct Out *o);
extern void func_0215C63C(void *c, void *vm, u32 ovId, const void *proc, void *work, u32 arg0, u32 arg1);
extern void *func_02158F50(void *p);
extern void *func_02161B90(void *p, void *a1, int kind, int sub, int flag);
extern void *func_0215A5E4(void *vm);
extern void func_02165344(void);
extern struct Desc *func_020124AC(void *a0, u32 a1, u32 (*fn)(void *, u32), u32 a3);
extern void func_02154438(s32 a, s32 *b);
extern void func_021543BC(void);
extern int func_02034AC4(s32 handle);
extern void func_02034A5C(s32 handle);
extern void func_021F36C0(unsigned int a0, int a1, int a2);
extern void func_021F36E8(void *, int);
int func_0215C89C(void *c, void *vm);
int func_0215C95C(void *c, void *vm);
int func_0215CA64(void *c, void *vm);
int func_0215CAB4(void *c, void *vm);
int func_0215CB08(void *c, void *vm);
int func_0215CBF0(void *c, void *vm);
int func_0215CC38(int a0, int a1);
int func_0215CC4C(void *c, void *vm);
int func_0215CCE8(void *a, void *b);
int func_0215CD3C(void *a, void *b);
int func_0215CD80(void *a, void *b);
extern const char d_021728F0[];
extern const u8 d_021B81D0[];
extern u8 ov173_id[];
extern const u8 d_021BA758[];
extern u8 ov071_id[];
extern const u8 d_021B74A0[];
extern u8 ov174_id[];
extern const u8 d_021BA1A4[];
extern const u8 d_021BA250[];
extern const u8 d_021B9BF8[];
extern u8 ov221_id[];
extern u8 ov222_id[];
extern u8 ov224_id[];
extern const u8 d_021BC8C4[];
extern u8 ov223_id[];
extern u8 ov002_id[];
extern char ov003_id[];
extern char ov037_id[];


static inline void init_record(Relearn *r, void *mon, void *sess, void *sys, void *moves)
{
    enum One { ONE = 1 } one;
    r->mon = mon;
    r->sess = sess;
    r->f08 = 0;
    r->sys = sys;
    r->moves = moves;
    one = ONE;
    r->f19 = one;
}

/*
 * lever: enum one assigned immediately before the f19 store in the inline
 * record initializer separates it from the constant return and selects r0.
 */
int func_0215C89C(void *c, void *vm)
{
    void *slot;
    void *sys;
    void *w;
    void *x;
    u32 a;
    u32 idx;
    void *mon;
    void *sess;
    void *moves;
    Relearn *r;
    u32 *h;

    slot = func_0215A5F4(vm);
    sys = func_0215A5DC(vm);
    w = func_020120F4(sys);
    x = func_0201210C(sys);
    a = (u32)func_02159AE8(c, vm);
    idx = func_02159B10(c, vm);
    mon = func_0201AB28(func_02012934(w), idx);
    sess = func_02012944(w);
    moves = func_0216F948(mon, 4);
    r = func_0216F918(4);
    init_record(r, mon, sess, sys, moves);
    h = func_02030734(4, 8, 0, d_021728F0, 0x19B);
    h[0] = (u32)r;
    h[1] = a;
    func_0215897C(slot, func_02014808(sys, (int)x, (u32)ov173_id, (int)d_021B81D0, (int)r, (int)((void *)func_0215C870), (int)h));
    return 1;
}


/*
 * Script command: opens the ov071 process on a 0x40-byte work. When the
 * current link record is usable (another player's slot, flagged, and
 * marked at +0x922) the work takes that player's name and profile;
 * otherwise it is filled from the local player. The chosen slot index
 * (0 for the local player) is stored at +0x3C.
 *
 * MATCH, bytes exact (2026-09-28 tree_ov010_4; lever: one `idx` local
 * set in both arms, which is what keeps the r6 zero). Three wildcards:
 * ov011 0x02175FB4 is an unlabelled leaf (`ldrb r0, [r0, #0x10]; bx lr`),
 * and the pooled 0x47 (ov071_id) and 0x021BA758 (the ov071 process
 * template) only reach an overlay loader through func_0215C63C, so no
 * class attests them.
 *
 * 2026-10-05 (wave D9): d_021BA758 now resolves with the ov099 token on its symbols line (`data  ov099  a1`; other covering overlays stay contested or unresolved). Only ov071_id remains: it reaches func_0215C63C, which is not in match.py OVERLAY_ID_CONSUMERS (forwards r2 to func_020120B4 r1); a data token on the id line does not help. Needs the consumer entry (tools), not C.
 */
int func_0215C95C(void *c, void *vm)
{
    void *sys;
    void *p;
    void *q;
    ProfileWork *w;
    LinkState *st;
    u8 idx;

    sys = func_0215A5DC(vm);
    p = (void *)func_02012138(sys);
    q = func_020120F4(sys);
    func_0215A5F4(vm);
    st = (LinkState *)func_02158344((int)p);
    w = func_02030734(4, sizeof(ProfileWork), 1, d_021728F0, 0x1BC);
    if (st != 0 && st->self != func_02012B58(q)
        && func_02175FB4((u8 *)(&st->recs[func_0215841C(q)])) == 1
        && ((u8 *)st)[0x922] == 1) {
        idx = func_0215841C(q);
        w->name = *func_0215840C(st, idx);
        w->profile = *(Profile16 *)((u8 *)st + 0x914);
        w->remote = 1;
    } else {
        func_0200BE48(func_02012EBC(q));
        func_02175648(q, (struct Out *)(&w->profile));
        idx = 0;
        w->remote = 0;
    }
    w->sys = sys;
    w->slot = idx;
    func_0215C63C(c, vm, (u32)ov071_id, d_021BA758, w, 0, 0);
    return 1;
}


/*
 * Script command: reads two words and stores func_02161B90's result
 * (over the system and the script's cell) in the script's slot.
 */
int func_0215CA64(void *c, void *vm)
{
    void *slot;
    void *sys;
    u32 a;
    u32 b;

    slot = func_0215A5F4(vm);
    sys = func_0215A5DC(vm);
    a = func_02159B10(c, vm);
    b = func_02159B10(c, vm);
    func_0215897C(slot, func_02161B90(sys, func_02158F50(slot), a, b, 0));
    return 1;
}


/*
 * Script command: reads one halfword and the system, boxes them in an
 * 8-byte record and opens overlay 0xAE over it.
 *
 * Bytes exact.
 *
 * 2026-10-05 (wave D9): EXACT. The ov174 token on the d_021B74A0 data line (the
 * proc table lives in ov174, which this function loads) gave the witness; the
 * ov174_id word then resolved through the overlay_id walk. Source unchanged.
 */
int func_0215CAB4(void *c, void *vm)
{
    u16 v;
    Box8_0215CAB4 *b;

    v = func_02159B10(c, vm);
    b = func_02030734(4, 8, 1, d_021728F0, 0x205);
    b->v = v;
    b->sys = func_0215A5E4(vm);
    func_0215C63C(c, vm, (u32)ov174_id, d_021B74A0, b, 0, 0);
    return 1;
}


/*
 * Script command: reads a mode (0-2) and a word; unless the mode is 2
 * calls func_02165344, then boxes the system object (and the word) in a
 * hand-off record and opens overlay 0xDD, 0xDE or 0xE0 over it through
 * func_0215C63C.
 *
 * MATCH, bytes exact. Blockers: the three overlay ids (ABS32 0xDD, 0xDE,
 * 0xE0) have no witness: `overlay_id` would carry them, but func_0215C63C
 * (which forwards its r2 to func_020120B4's r1) is not in match.py's
 * OVERLAY_ID_CONSUMERS. d_021BA250 (ov222) and d_021B9BF8 (ov224) are
 * contested hints that resolve once the function loads those overlays
 * through an overlay_id site. d_021BA1A4 (ov221) already resolves.
 *
 * 2026-10-05 (wave D9): re-tried overlay tokens on the contested hints; they stay contested because the id sites do not attest. Residue is the three id words (ov221_id, ov222_id, ov224_id) reaching func_0215C63C, which is not in OVERLAY_ID_CONSUMERS; add that consumer (r2 -> func_020120B4 r1) and the hints resolve. Not fixable in C.
 */
int func_0215CB08(void *c, void *vm)
{
    void *sys;
    void *sub;
    u32 mode;
    u32 v;
    Box8_0215CB08 *b;
    void **w;

    sys = func_020120F4(func_0215A5DC(vm));
    sub = func_02012944(sys);
    mode = func_02159B10(c, vm);
    v = func_02159B10(c, vm);
    if (mode != 2) {
        func_02165344();
    }
    switch (mode) {
    case 0:
        b = func_02030734(4, 8, 1, d_021728F0, 0x22B);
        b->sys = sys;
        b->v = v;
        func_0215C63C(c, vm, (u32)ov221_id, d_021BA1A4, b, 0, 0);
        break;
    case 1:
        b = func_02030734(4, 8, 1, d_021728F0, 0x233);
        b->sys = sys;
        b->v = v;
        func_0215C63C(c, vm, (u32)ov222_id, d_021BA250, b, 0, 0);
        break;
    case 2:
        w = func_02030734(4, 4, 1, d_021728F0, 0x23C);
        *w = sub;
        func_0215C63C(c, vm, (u32)ov224_id, d_021B9BF8, w, 0, 0);
        break;
    }
    return 1;
}


/*
 * Script command: reads one word from the script stream, boxes it in a
 * 4-byte hand-off record and opens overlay 0xDF over it.
 *
 * 2026-10-05 (D9 lane 02): d_021BC8C4 resolves with the ov223 token (the overlay it points into) on its data line; ov223_id resolves as an overlay id word.
 *
 * 2026-10-05 (wave D8): ov223_id and d_021BC8C4 are data with no witness; not fixable in C. Source re-read against the listing, unchanged.
 */
int func_0215CBF0(void *c, void *vm)
{
    u32 v;
    u32 *w;

    v = (u32)func_02159AE8(c, vm);
    w = func_02030734(4, 8, 1, d_021728F0, 0x254);
    w[0] = v;
    func_0215C63C(c, vm, (u32)ov223_id, d_021BC8C4, w, 0, 0);
    return 1;
}


int func_0215CC38(int a0, int a1)
{
    int t4;
    void *v0;
    void *v1;

t4 = a1 + 0;
a0 = t4 + 0;
    v0 = func_0215A5F4((void *)a0);
loc_0215CC42:
a0 = t4 + 0;
    v1 = func_0215A5DC((void *)a0);
loc_0215CC48:
a0 = 1;
    return a0;}


/*
 * Script command: reads a kind (0xF-0x13 mapped to 0-4) and a flag (0/1),
 * builds a four-word request on the stack and launches func_02154438
 * (ov002) through func_020124AC, parking the result in the script's slot.
 */
int func_0215CC4C(void *c, void *vm)
{
    void *slot;
    void *sys;
    u32 kind;
    u32 flag;
    u32 k;
    u32 f;
    Req r;

    slot = func_0215A5F4(vm);
    sys = func_0215A5DC(vm);
    kind = func_02159B10(c, vm);
    flag = func_02159B10(c, vm);
    switch (kind) {
    case 0xF:
        k = 0;
        break;
    case 0x10:
        k = 1;
        break;
    case 0x11:
        k = 2;
        break;
    case 0x12:
        k = 3;
        break;
    case 0x13:
        k = 4;
        break;
    }
    switch (flag) {
    case 0:
        f = 0;
        break;
    case 1:
        f = 1;
        break;
    }
    r.sys = func_0201210C(sys);
    r.one = 1;
    r.flag = f;
    r.kind = k;
    func_0215897C(slot, func_020124AC(sys, (u32)ov002_id, (void *)func_02154438, (u32)(&r)));
    return 1;
}


/*
 * The ov003 callback 0x021543BC (unlabelled leaf, formerly the blocker) is
 * matched in pkt_ov003_021543BC and attests as matched.
 */
int func_0215CCE8(void *a, void *b)
{
    Arg arg;
    void *t = func_0215A5F4(b);
    void *h = func_0215A5DC(b);
    u32 k = !func_02159B10(a, b) ? 1 : 2;
    arg.a = (u32)func_0201210C(h);
    arg.b = k;
    func_0215897C(t, func_020124AC(h, (u32)ov003_id, (void *)func_021543BC, (u32)(&arg)));
    return 1;
}


int func_0215CD3C(void *a, void *b)
{
    void *h = func_0215A5DC(b);
    u16 *p = func_02159AE8(a, b);
    u16 *q = func_02159AE8(a, b);
    func_02034AC4((u32)ov037_id);
    func_021F36C0((unsigned int)h, *p, *q);
    func_02034A5C((u32)ov037_id);
    return 0;
}


int func_0215CD80(void *a, void *b)
{
    void *p = func_0215A5DC(b);
    int v = func_02159B10(a, b);
    func_02034AC4((int)ov037_id);
    func_021F36E8(p, v);
    func_02034A5C((int)ov037_id);
    return 0;
}
