/*
 * function: func_0216E95C
 * address:  0x0216E95C
 * packet:   pkt_ov010_0216E95C
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Set up the scripted catching-tutorial battle (Minccino Lv7 against
 * Patrat Lv2) and push func_0216EB98 as its task. First draft.
 *
 * symbols:
 *   func_020120F4  0x020120F4  thumb
 *   func_02013090  0x02013090  thumb
 *   func_0201A920  0x0201A920  thumb
 *   func_020173EC  0x020173EC  thumb
 *   func_02030734  0x02030734  arm
 *   func_0201756C  0x0201756C  thumb
 *   func_02017E40  0x02017E40  thumb
 *   func_0201A98C  0x0201A98C  thumb
 *   func_021AA304  0x021AA304  thumb  ov021
 *   func_020135C0  0x020135C0  thumb
 *   func_020307B0  0x020307B0  arm
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   func_0216F02C  0x0216F02C  thumb  ov010
 *   func_021CF5D8  0x021CF5D8  thumb
 *   func_0216EB98  0x0216EB98  thumb  ov010
 *   d_02172B54     0x02172B54  data
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long long u64;

typedef struct Loc {
    u32 f00;            /* 0x00 */
    u32 f04;            /* 0x04 */
    u8 pad08[8];
} Loc;

typedef struct Holder {
    u8 pad00[0x18];
    u8 f18[4];          /* 0x18 */
} Holder;

typedef struct Work {
    u8 pad00[8];
    Holder *f08;        /* 0x08 */
    u8 pad0C[0x14 - 0x0C];
    u32 f14;            /* 0x14 */
    u8 pad18[0x24 - 0x18];
    u32 f24;            /* 0x24 */
} Work;

typedef u32 (*TaskFn)(void *task, u32 *state, Work *work);

struct Ctx;
struct Desc;
struct Obj;
struct Party;
struct PartyMon;
extern void *func_020120F4(const struct Ctx *p);
extern void *func_02013090(u32 heap);
extern void *func_0201A920(u16 heap);
extern u32 func_020173EC(void);
extern void *func_02030734(u32 heap, u32 size, int clear, const char *site, u16 tag);
extern void func_0201756C(void *mon, u16 species, u16 level, u64 id);
extern void func_02017E40(void *p, u32 id, u32 v);
extern u32 func_0201A98C(struct Party *p, const struct PartyMon *src);
extern void func_021AA304(Loc *loc, void *ctx, u32 a);
extern void func_020135C0(void *bs, void *ctx, void *p1, void *p2, Loc *loc, u32 heap);
extern void func_020307B0(void *p);
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern void *func_020124E8(struct Obj *p);
extern void func_0216F02C(Work *w, void *a, void *bs);
extern void func_021CF5D8(u16 species, u32 a, u32 b, u32 c, u32 *d, void *e);
extern u32 func_0216EB98(void *task, u32 *state, Work *work);
extern const char d_02172B54[];

void *func_0216E95C(void *sys, u32 arg, u32 heap)
{
    Loc loc;
    u16 h;
    void *ctx;
    void *bs;
    void *party1;
    void *party2;
    void *mon;
    void *task;
    Work *w;

    h = (heap & 0x7FFF) | 0x8000;
    ctx = func_020120F4(sys);
    bs = func_02013090(heap);
    party1 = func_0201A920(h);
    party2 = func_0201A920(h);
    mon = func_02030734(h, func_020173EC(), 1, d_02172B54, 0x1DA);
    func_0201756C(mon, 572, 7, 0);
    func_02017E40(mon, 0x36, 1);
    func_02017E40(mon, 0x37, 45);
    func_02017E40(mon, 0x38, 0);
    func_02017E40(mon, 0x39, 0);
    func_0201A98C(party1, mon);
    func_0201756C(mon, 504, 2, 0);
    func_02017E40(mon, 0x36, 33);
    func_02017E40(mon, 0x37, 43);
    func_02017E40(mon, 0x38, 0);
    func_02017E40(mon, 0x39, 0);
    func_0201A98C(party2, mon);
    func_021AA304(&loc, ctx, arg);
    loc.f04 = 5;
    loc.f00 = 0;
    func_020135C0(bs, ctx, party1, party2, &loc, heap);
    func_020307B0(mon);
    func_020307B0(party2);
    func_020307B0(party1);
    task = func_020122C0(sys, 0, func_0216EB98, 0x28);
    w = func_020124E8(task);
    func_0216F02C(w, sys, bs);
    w->f14 = 1;
    func_021CF5D8(504, 5, 0, arg, &w->f24, w->f08->f18);
    w->f24 = 0;
    return task;
}
