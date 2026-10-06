/*
 * unit:     yes
 * address:  0x0201C6B4
 * packet:   pkt_0201C450
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: sub_0201C6B4, sub_0201C6C4, sub_0201C6EC
 *
 * symbols:
 *   g_0214655C   0x0214655C  data
 *
 * Three queries on the printsys.c ring object.  sub_0201C6B4 reports the ring
 * empty, sub_0201C6EC resets it, and sub_0201C6C4 walks it looking for a record
 * whose +0x14 field is the caller's pointer.
 *
 * sub_0201C6C4 is where func_0201D7C4's arity was recovered.  The walk reads `q`
 * back out of the call's result and the original keeps `q` in r1 across the
 * loop, spending an `adds r1, r0, #0` to get it there; every source shape that
 * declares func_0201D7C4 with one parameter puts `q` in r0 instead and is eight
 * bytes wrong with identical control flow.  r1 is the callee's second argument
 * register and `q` is already in it at the call, so the register choice is the
 * only evidence in the image that the call passes two arguments.  See
 * docs/idioms/a-loop-carried-value-in-a-callees-argument-register-names-the-arity.md.
 *
 * The doubled `beq` at the top of the loop is an explicit null guard in front of
 * the `while`, not a rotation artefact: `if (q != 0) { while (q != 0) ... }`
 * emits both tests and nothing merges them.
 *
 * Left open at 0x0201C6FC: sub_0201C6FC, sub_0201C724 and sub_0201C758 reproduce
 * every concrete byte and cap at MATCH, because func_0201D6D8's only caller in
 * the image is the one inside sub_0201C758; they are parked in
 * src/pending/unit_0201C6FC.c.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201C6B4.c \
 *       --addr 0x0201C6B4 --thumb
 */

typedef unsigned char      u8;
typedef unsigned short     u16;
typedef unsigned int       u32;
typedef signed short       s16;
typedef unsigned long long u64;

struct PrintCtx {
    s16 unk00;
    s16 unk02;
    u32 unk04;
    u16 unk08;
    u16 unk0A;
    u16 unk0C;
    u16 unk0E;
    void *unk10;
    void *unk14;
    void *unk18;
};

union Ticks {
    u64 v;
    struct {
        u32 lo;
        u32 hi;
    } w;
};

struct PrintSys {
    u16 unk00;
    u16 unk02;
    u16 unk04;
    u8  unk06;
    u8  unk07;
    union Ticks unk08;
    struct PrintCtx *unk10;
    struct PrintCtx *unk14;
};

extern struct PrintCtx g_0214655C;

struct Rec2;
struct Ring;
extern void func_0203D1B4(void);
extern void *func_0201D7C4(struct PrintSys *p, void *q);
extern u32   func_0201D6B8(void *s);
extern u32 func_0201D6C4(const struct Ring *p);
extern void  func_0201D6D8(struct PrintSys *p, void *a, void *b);

extern void sub_0201C808(struct PrintCtx *p, void *w, void *x, u32 y, s16 z);
extern void sub_0201C8A4(struct Rec2 *p, u16 v);
extern void sub_0201C8BC(u8 *a0, int a1);

void sub_0201C758(struct PrintSys *p, struct PrintCtx *c, void *s);

u32 sub_0201C6B4(const struct PrintSys *p)
{
    if (p->unk10 == 0) {
        return 1;
    }
    return 0;
}

u32 sub_0201C6C4(struct PrintSys *p, void *v)
{
    struct PrintCtx *q = p->unk10;

    if (q != 0) {
        while (q != 0) {
            if (q->unk14 == v) {
                return 1;
            }
            q = func_0201D7C4(p, q);
        }
    }
    return 0;
}

void sub_0201C6EC(struct PrintSys *p)
{
    p->unk00 = 0;
    p->unk02 = p->unk04;
    p->unk14 = 0;
    p->unk10 = 0;
}

