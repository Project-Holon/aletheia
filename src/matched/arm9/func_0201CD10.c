/*
 * function: func_0201CD10
 * address:  0x0201CD10
 * packet:   pkt_0201CD10
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02045770  0x02045770  arm
 *   func_020311B8  0x020311B8  arm
 *   TCBL_GetWork  0x02031290  arm
 *   STRBUF_GetChars  0x02045A90  arm
 *   func_0201CEE0  0x0201CEE0  thumb
 *   PRINTSYS_SetupJob  0x0201C808  thumb
 *   PRINTSYS_SplitWait   0x0201CDF4  thumb
 *
 * The printsys text-record constructor: registers func_0201CEE0 as a
 * task with a 0x50-byte work area, builds the PrintCtx at +0x34 through
 * PRINTSYS_SetupJob, splits the signed speed argument into the sign/magnitude
 * pairs at +0x18..+0x1D, and initialises every other field of struct Rec
 * (the same layout src/matched/func_0201CEE0.c consumes).  Returns the
 * record.
 *
 * The two-load swap the notes carried at +0x28/+0x30 (a4 read before a1)
 * was a declaration fact, not a scheduling one:
 *  - PRINTSYS_SetupJob's real prototype (src/matched/PRINTSYS_SetupJob.c) is
 *    (struct PrintCtx *, void *, void *, s16, s16), so a1 and a2 are s16
 *    parameters here;
 *  - the byte stored to +0x20 is the tenth argument declared `u16 a9`.
 *    Thumb ldrh cannot use sp as a base, which is where the notes'
 *    `*(u16 *)((u8 *)&a4 + 0x14)` came from; taking a4's address to fake
 *    it pinned the a4 load late.  With a9 a real u16 parameter nothing
 *    takes an address and the loads schedule as in the image.
 */
typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed int     s32;

struct PrintCtx {
    s16   unk00;
    s16   unk02;
    s32   unk04 : 10;
    u32   unk04b : 22;
    u16   unk08;
    u16   unk0A;
    u16   unk0C;
    u16   unk0E;
    void *unk10;
    void *unk14;
    void *unk18;
};

struct Rec {
    u32  state;        /* 0x00 */
    u32  mode;         /* 0x04 */
    u32  f08;          /* 0x08 */
    u32  win;          /* 0x0c */
    void *task;        /* 0x10 */
    u16 *cur;          /* 0x14 */
    u8   f18;
    u8   f19;
    u8   f1a;
    u8   f1b;
    u8   f1c;
    u8   f1d;
    u8   wait;         /* 0x1e */
    u8   scroll;       /* 0x1f */
    u8   color;        /* 0x20 */
    u8   cbres;        /* 0x21 */
    struct {
        u8 b0 : 1;
        u8 b1 : 1;
        u8 b2 : 1;
        u8 b3 : 1;
        u8 b4 : 1;
        u8 rest : 3;
    } flags;           /* 0x22 */
    u8   pad23;
    u8 (*cb)(u32);     /* 0x24 */
    u32  f28;
    u32  f2c;
    u32  cbarg;        /* 0x30 */
    struct PrintCtx ctx; /* 0x34 */
};

struct Descriptor;
extern void *func_02045770(struct Descriptor *p);
extern void *func_020311B8(u32 a0, void *fn, u32 sz, u32 a3);
struct S02030FB4;
extern void *TCBL_GetWork(struct S02030FB4 *p);
struct U16Vec;
extern u16 *STRBUF_GetChars(struct U16Vec *vec);
extern void  func_0201CEE0(void *task, struct Rec *p);
extern void PRINTSYS_SetupJob(struct PrintCtx *p, void *w, void *x, u32 y, s16 z);
extern void  PRINTSYS_SplitWait(s32 v, u8 *out);

struct Rec *func_0201CD10(u32 a0, s16 a1, s16 a2, u32 a3,
                          u32 a4, s32 a5, u32 a6, u32 a7, u32 a8, u16 a9,
                          u32 a10)
{
    struct Rec *o;
    void *r;
    u32 h;
    u8 pair[2];

    h = (u32)func_02045770((struct Descriptor *)a0);
    r = func_020311B8(a6, (void *)func_0201CEE0, 0x50, a7);
    o = TCBL_GetWork(r);

    o->task = r;
    PRINTSYS_SetupJob(&o->ctx, (void *)a4, (void *)h, a1, a2);
    PRINTSYS_SplitWait(a5, pair);
    o->f19 = pair[1];
    {
        u8 lo = pair[0];
        o->f18 = lo;
        o->f1c = lo;
        o->f1a = lo;
    }
    {
        u8 hi = o->f19;
        o->f1d = hi;
        o->f1b = hi;
    }
    o->cur = STRBUF_GetChars((struct U16Vec *)a3);
    o->wait = 0;
    o->cb = (u8 (*)(u32))a10;
    o->f28 = 0;
    o->f2c = 0;
    o->cbarg = 0;
    o->f08 = a0;
    o->win = h;
    o->state = 0;
    o->color = a9;
    o->mode = 1;
    o->scroll = 0;
    o->flags.b2 = 0;
    o->flags.b0 = 0;
    o->flags.b1 = 0;
    o->cbres = 0;
    o->flags.b3 = 0;
    o->flags.b4 = 0;
    return o;
}
