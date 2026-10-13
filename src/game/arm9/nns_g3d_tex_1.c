/*
 * file:     nns_g3d_tex_1.c
 * function: func_02069C74
 * address:  0x02069C74
 * packet:   pkt_020694D8
 * region:   arm9
 * compiler: ../2.0/sp2
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * symbols:
 *   sHandlerCount  0x020A821C  data
 *   sHandlerKeys   0x020A8240  data
 *   sHandlerFns    0x020A8244  data
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/func_02069C74.c \
 *       --func func_02069C74 --addr 0x02069C74 --arm --cc ../2.0/sp2
 *
 * BLOCKER: capped at MATCH for lack of an outside witness.  All three ABS32
 * pool words -- 0x020A821C (sHandlerCount), 0x020A8240 (sHandlerKeys) and
 * 0x020A8244 (sHandlerFns) -- occur NOWHERE else in the image; this function's
 * own pool at 0x02069D08..0x02069D10 is the only occurrence of each, so the
 * `literal` class has no witness outside the compared range.  Every concrete
 * byte is correct.  A --suggest-split cut is impossible: this is one function.
 *
 * Pin: ../2.0/sp2, the "kept branches" tell -- 1.1p1 -O4,p predicates the
 * second key test (`ldrheq`/`cmpeq`) and lands at 148 bytes against the
 * original's 160.  See docs/FRONTEND-PINS.md and docs/notes/func_02069C74.c.txt.
 *
 * The handler's arity is (Obj *, Key *, u32): that is what makes `o` and `key`
 * live across the initialisation block and gives the image's five-register
 * `push {r3, r4, r5, r6, r7, lr}`.  The entry test must be spelled
 * `i = 0; if (i >= n) return;` for the image's `popls`; `n == 0` gives `popeq`.
 */

typedef signed int s32;
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;

typedef struct {
    u8  tag;
    u8  pad1;
    u16 id;
    u32 pad4;
} HandlerKey;

typedef struct {
    u8  tag;
    u8  pad1;
    u16 id;
} Key;

typedef struct {
    u32 state00;
    u32 cap04;
    Key *key08;
    u32 unk0C;
    u32 unk10;
    u32 unk14;
    u8  pri18;
    u8  flag19;
} Obj;

extern u32 sHandlerCount;
extern HandlerKey sHandlerKeys[];
extern u8 sHandlerFns[];

void func_02069C74(Obj *o, Key *key, u32 a2, u32 a3)
{
    u8 tag;
    u32 i;
    u32 n;

    o->state00 = 0;
    o->key08 = key;
    o->unk10 = 0;
    o->pri18 = 0x7f;
    o->cap04 = 0x1000;
    o->unk14 = a3;
    o->flag19 = 0;
    o->unk0C = 0;

    n = sHandlerCount;
    i = 0;
    if (i >= n) return;
    tag = key->tag;
    do {
        if (tag != sHandlerKeys[i].tag) goto next;
        if (key->id != sHandlerKeys[i].id) goto next;
        if (*(void (**)(Obj *, Key *, u32))(sHandlerFns + (i << 3)) == 0) return;
        (*(void (**)(Obj *, Key *, u32))(sHandlerFns + (i << 3)))(o, key, a2);
        return;
next:
        i++;
    } while (i < n);
}
