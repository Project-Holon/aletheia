/*
 * file:     btlv_b_gauge_p09.c
 * unit:     yes
 * function: func_02208D38, func_02208D50, func_02208DAC
 * address:  0x02208D38
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0209C2B0  0x0209C2B0  arm
 *   func_0204B3DC  0x0204B3DC  arm
 *   func_02030734 0x02030734 arm
 *   func_020490F4 0x020490F4 arm
 *   func_0204B100 0x0204B100 arm
 *   func_0204A6C8 0x0204A6C8 arm
 *   func_0204AF28 0x0204AF28 arm
 *   func_0204ABF0 0x0204ABF0 arm
 *   func_021F86E0 0x021F86E0 thumb ov094
 *   func_0204AEF4 0x0204AEF4 arm
 *   func_020216D4 0x020216D4 thumb
 *   func_0204B294 0x0204B294 arm
 *   func_0204B454 0x0204B454 arm
 *   func_0204B92C 0x0204B92C arm
 *   func_0204B878 0x0204B878 arm
 *   func_021F86D4 0x021F86D4 thumb ov094
 *   func_02030DA8 0x02030DA8 arm
 *   func_021F896C 0x021F896C thumb ov094
 *   func_02049238 0x02049238 arm
 *   func_020061E4 0x020061E4 thumb
 *   func_022090B4 0x022090B4 thumb ov094
 *   func_02209214 0x02209214 thumb ov094
 *   d_0220AED0 0x0220AED0 data a4
 *   d_0220AB6C 0x0220AB6C data a4
 *   d_0220AB7C 0x0220AB7C data a4
 */
struct Obj;
struct Bank;
struct PalAnmSlot;
struct Actor;
struct PtS;
typedef unsigned int u32;

typedef struct {
    int f00;                /* 0x40 in the work area */
    int h04;                /* 0x44 */
    int h08;                /* 0x48 */
    char pad0c[0x40 - 0x0c];
    int state;              /* 0x80 */
    char pad44[0x80 - 0x44];
} Row;

typedef struct {
    char pad00[0x40];
    Row r[8];               /* 0x40 */
    struct {
        u32 lo : 4;
        u32 b4 : 1;
        u32 mid : 16;
        u32 hi : 11;
    } flags;                /* 0x440 */
} W;

typedef unsigned short u16;

typedef short s16;

typedef struct { s16 x, y, z, w; } Pos;

typedef struct { s16 x, y; } Vec2;

typedef struct { void *h; int goal, home, step, frame, wait; Vec2 pos; } Entry;

typedef struct {
    u32 h0, h4, h8, hc;
    Entry e[7];
    int state, active, sound;
    u16 heap;
} Work;

typedef struct { int side; int idx[6]; } Arg;

typedef struct { s16 x0, y0, x1, y1; } Origin;

typedef unsigned char  u8;

typedef signed int     s32;

extern int func_0209C2B0(int a, int b);
extern void func_0204B3DC(struct Obj *p, unsigned int v);
extern void *func_02030734(u16, u32, int, const char *, u16);
extern void *func_020490F4(u32 id, u32 heap);
extern struct Bank *func_0204B100(int count, u8 flag, u32 heapId);
extern s32 func_0204A6C8(void *a, u32 b, u32 c, u32 a3, u16 flags);
extern s32 func_0204AF28(void *owner, u32 first, u32 second, u32 mode);
extern s32 func_0204ABF0(void *a, u32 b, u32 c, u32 d, u16 g);
extern int func_021F86E0(void);
extern int func_0204AEF4(u32 idx, u32 alternate);
extern void func_020216D4(struct PalAnmSlot *slots, u32 bank, u32 off, u32 size);
extern struct Obj *func_0204B294(void *, unsigned int, unsigned int, unsigned int, const void *, u16, u16);
extern void func_0204B454(struct Actor *actor, struct PtS *out, u16 space);
extern void func_0204B92C(struct Obj *p, u32 v);
extern void func_0204B878(struct Obj *p, u16 value);
extern void *func_021F86D4(void);
extern void *func_02030DA8(void *, void (*)(void *, void *), void *, u32);
extern void func_021F896C(void *h, void (*cb)(void *), int arg);
extern void func_02049238(void *);
extern void func_020061E4(u32 a);
extern void func_022090B4(void *, void *);
extern void func_02209214(void *);
int func_02208D38(int a, int b, int c);
void func_02208D50(W *w, int i, int b);
Work *func_02208DAC(const Arg *arg, u32 heapId);
extern const char d_0220AED0[];
extern const Origin d_0220AB6C[];
extern const u32 d_0220AB7C[][5];


int func_02208D38(int a, int b, int c)
{
    int r = func_0209C2B0(a * c, b);
    if (r == 0 && a != 0)
        r = 1;
    return r;
}


/*
 * Lever: the flag word at 0x440 is a bitfield struct (bit 4 read as
 * lsls #27 / lsrs #31); a plain u32 with `(f >> 4) & 1` gives lsrs/ands
 * and a different register assignment.
 */
void func_02208D50(W *w, int i, int b)
{
    if ((w->r[i].state == 2 || w->r[i].state == 3) && b == 1 && (i & 1) == 0) {
        func_0204B3DC((struct Obj *)w->r[i].h04, w->flags.b4);
        func_0204B3DC((struct Obj *)w->r[i].h08, w->flags.b4 ? 0 : 1);
    } else {
        func_0204B3DC((struct Obj *)w->r[i].h04, b);
        func_0204B3DC((struct Obj *)w->r[i].h08, b);
    }
}

/*
 * lever: const Arg * lets the side load schedule above the pos zero stores;
 *   pos is initialised in an inner block (a top-level initializer is
 *   emitted at function entry); the stack locals are declared arc, heap,
 *   base so they land at 0x1c, 0x18, 0x14.
 */
Work *func_02208DAC(const Arg *arg, u32 heapId)
{
    void *arc;
    int heap;
    int base;
    Work *w;
    Work **ctx;
    int i;

    heap = (heapId & 0x7fff) | 0x8000;
    w = func_02030734(heap, 0xe4, 1, d_0220AED0, 0x7a);
    arc = func_020490F4(0xb, (u16)heap);
    w->heap = heap;
    w->h0 = (u32)func_0204B100(7, 0, w->heap);
    w->h4 = func_0204A6C8(arc, 0xbd, 0, 0, w->heap);
    w->h8 = func_0204AF28(arc, 0xbf, 0xc0, w->heap);
    w->hc = func_0204ABF0(arc, 0xbe, 0, 0xc0, w->heap);
    func_020216D4((struct PalAnmSlot *)func_021F86E0(), 2, (u16)(func_0204AEF4(w->hc, 0) >> 1), 0x20);
    {
    Pos pos = {0, 0, 0, 0};
    int side = arg->side;
    base = d_0220AB6C[side].x0;
    pos.x = base + (side == 0 ? 0x80 : -0x80);
    pos.y = d_0220AB6C[arg->side].y0;
    for (i = 0; i < 6; i++) {
        w->e[i].h = func_0204B294((void *)w->h0, w->h4, w->hc, w->h8, &pos, 0, w->heap);
        func_0204B454(w->e[i].h, (struct PtS *)&w->e[i].pos, 0);
        func_0204B92C(w->e[i].h, 1);
        func_0204B878(w->e[i].h, d_0220AB7C[arg->side][arg->idx[i]]);
        w->e[i].frame = d_0220AB7C[2][arg->idx[i]];
        w->e[i].wait = (i + 1) * 6;
        w->e[i].home = base;
        w->e[i].goal = base + (i + 1) * (arg->side == 0 ? -2 : 2);
        w->e[i].step = arg->side == 0 ? -12 : 12;
        base += arg->side == 0 ? 15 : -15;
    }
    pos.x = d_0220AB6C[arg->side].x1 + (arg->side == 0 ? 0x80 : -0x80);
    pos.y = d_0220AB6C[arg->side].y1;
    w->e[i].h = func_0204B294((void *)w->h0, w->h4, w->hc, w->h8, &pos, 0, w->heap);
    func_0204B454(w->e[i].h, (struct PtS *)&w->e[i].pos, 0);
    func_0204B92C(w->e[i].h, 1);
    func_0204B878(w->e[i].h, d_0220AB7C[arg->side][4]);
    w->e[i].frame = d_0220AB7C[arg->side][4];
    w->e[i].wait = 0;
    w->e[i].home = w->e[i].goal = d_0220AB6C[arg->side].x1;
    w->e[i].step = arg->side == 0 ? -0x10 : 0x10;
    ctx = func_02030734(heap, 4, 0, d_0220AED0, 0xec);
    *ctx = w;
    func_021F896C(func_02030DA8(func_021F86D4(), func_022090B4, ctx, 0), func_02209214, 0);
    w->active = 1;
    func_02049238(arc);
    func_020061E4(0x570);
    return w;
    }
}
