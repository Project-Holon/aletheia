/*
 * function: func_0215C95C
 * address:  0x0215C95C
 * packet:   pkt_ov010_0215C95C
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
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
 *
 * symbols:
 *   func_0215A5DC  0x0215A5DC  thumb  ov010
 *   func_02012138  0x02012138  thumb
 *   func_020120F4  0x020120F4  thumb
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_02158344  0x02158344  thumb  ov010
 *   func_02030734  0x02030734  arm
 *   func_02012B58  0x02012B58  thumb
 *   func_0215841C  0x0215841C  thumb  ov010
 *   func_02175FB4  0x02175FB4  thumb  ov011
 *   func_0215840C  0x0215840C  thumb  ov010
 *   func_02012EBC  0x02012EBC  thumb
 *   func_0200BE48  0x0200BE48  thumb
 *   func_02175648  0x02175648  thumb  ov011
 *   func_0215C63C  0x0215C63C  thumb  ov010
 *   d_021728F0     0x021728F0  data  a1
 *   d_021BA758     0x021BA758  data  ov099  a1
 *   ov071_id       0x00000047  data
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

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

extern void *func_0215A5DC(void *vm);
struct Big;
struct BigObj;
struct Ctx;
struct Out;
extern u32 func_02012138(const struct Ctx *p);
extern void *func_020120F4(const struct Ctx *p);
extern void *func_0215A5F4(void *vm);
extern int func_02158344(int a0);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern u8 func_02012B58(const struct BigObj *p);
extern u8 func_0215841C(void *p);
extern int func_02175FB4(u8 *p);
extern Name20 *func_0215840C(LinkState *s, int idx);
extern void *func_02012EBC(struct Big *p);
extern u16 *func_0200BE48(void *sys);
extern void func_02175648(void *sv, struct Out *o);
extern void func_0215C63C(void *c, void *vm, u32 ovId, const void *proc, void *work, u32 arg0, u32 arg1);
extern const char d_021728F0[];
extern const u8 d_021BA758[];
extern u8 ov071_id[];

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
