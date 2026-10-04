/*
 * function: func_0216C538
 * address:  0x0216C538
 * packet:   pkt_ov010_0216C538
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Starts the func_0216C484 task over a 0xD8-byte work: points it at the
 * caller's result fields, picks the party (the player's, or the one at
 * +0x7C8 when `useOwn` is set), and fills the party-screen and summary
 * argument blocks; the screen mode (0x14, 0x15 or 0x16) follows the
 * caller's kind at +9.
 *
 * MATCH (2026-09-28 tree_ov010_4; levers: declaration order q, task, p
 * for the frame slots, the summary block pointer formed before the
 * func_0200CA1C call). The one wildcard is arm9 0x0201A354, an unlabelled
 * Thumb thunk (`movs r0, #0x69; bx` to 0x02048F60) inside the listing's
 * ARM data run: a seed for the ARM9 session.
 *
 * symbols:
 *   func_020120F4  0x020120F4  thumb
 *   func_0201210C  0x0201210C  thumb
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   func_0216C484  0x0216C484  thumb  ov010
 *   func_02012934  0x02012934  thumb
 *   MI_CpuFill8    0x02082BCC  arm
 *   func_0201A354  0x0201A354  thumb
 *   func_0200CA1C  0x0200CA1C  thumb
 *   func_0201AA18  0x0201AA18  thumb
 *   func_0200CA38  0x0200CA38  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct SummaryArgs {
    void *party;        /* 0x08 */
    u32 f04;
    void *p;            /* 0x10 */
    u8 f0c;             /* 0x14 */
    u8 f0d;             /* 0x15 */
    u8 count;           /* 0x16 */
    u8 pad0f;
    u8 f10;             /* 0x18 */
    u8 pad11[7];
    void *f18;          /* 0x20 */
    u8 pad1c[0xC];
} SummaryArgs;

typedef struct PartyArgs {
    void *party;        /* 0x30 */
    u8 pad04[0x10];
    void *f14;          /* 0x44 */
    u8 pad18[0x1C];
    u32 f34;            /* 0x64 */
    u32 f38;            /* 0x68 */
    u8 pad3c[0x5C];
} PartyArgs;

typedef struct PartyTaskWork {
    void *sys;          /* 0x00 */
    void *q;            /* 0x04 */
    SummaryArgs sum;    /* 0x08 */
    PartyArgs pa;       /* 0x30 */
    void *outC8;        /* 0xC8 */
    void *outCC;        /* 0xCC */
    void *outD0;        /* 0xD0 */
    u8 padD4[4];
} PartyTaskWork;

typedef struct PartyCaller {
    u8 pad00[9];
    u8 kind;            /* 0x009 */
    u8 pad0A[0x72];
    u8 f7c[6];          /* 0x07C */
    u16 f82;            /* 0x082 */
    u16 f84;            /* 0x084 */
    u8 pad86[0x7C8 - 0x86];
    void *party;        /* 0x7C8 */
} PartyCaller;

struct BigObj;
struct Ctx;
struct Desc;
struct Obj;
extern void *func_020120F4(const struct Ctx *p);
extern void *func_0201210C(const struct Ctx *p);
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern void *func_020124E8(struct Obj *p);
extern int func_0216C484(int a, int *st, int *o);
extern void *func_02012934(const struct BigObj *p);
extern void MI_CpuFill8(void *dst, u8 val, u32 size);
extern void *func_0201A354(int a, int b);
extern void *func_0200CA1C(void *p);
extern u32 func_0201AA18(void *p);
extern void *func_0200CA38(void *p);

void *func_0216C538(PartyCaller *c, void *sys, int useOwn)
{
    void *q;
    void *task;
    void *p;
    PartyTaskWork *w;
    void *party;
    PartyArgs *pa;
    SummaryArgs *sum;
    void *h;
    u32 mode;
    u32 sel;

    p = func_020120F4(sys);
    q = func_0201210C(sys);
    task = func_020122C0(sys, 0, func_0216C484, sizeof(PartyTaskWork));
    w = func_020124E8(task);
    w->sys = sys;
    w->q = q;
    w->outD0 = c->f7c;
    w->outCC = &c->f82;
    w->outC8 = &c->f84;
    if (useOwn == 0)
        party = func_02012934(p);
    else
        party = c->party;
    mode = 0x14;
    sel = 0;
    pa = &w->pa;
    MI_CpuFill8(pa, 0, sizeof(PartyArgs));
    pa->party = party;
    switch (c->kind) {
    case 1:
    case 6:
        mode = 0x15;
        sel = 1;
        break;
    case 2:
    case 3:
    case 7:
    case 8:
        mode = 0x16;
        sel = 2;
        break;
    }
    pa->f14 = func_0201A354(mode, 4);
    pa->f34 = 0x16;
    pa->f38 = sel;
    sum = &w->sum;
    h = func_0200CA1C(p);
    MI_CpuFill8(sum, 0, sizeof(SummaryArgs));
    sum->party = party;
    sum->f0c = 1;
    sum->count = func_0201AA18(party);
    sum->f0d = 0;
    sum->f10 = 0;
    sum->p = p;
    sum->f18 = func_0200CA38(h);
    return task;
}
