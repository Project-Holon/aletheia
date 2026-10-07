/*
 * file:     time_icon_p02.c
 * unit:     yes
 * function: func_0202E818, func_0202E82C, func_0202E83C, func_0202E848, func_0202E888, func_0202E8A4, func_0202E8B8, func_0202E8CC, func_0202E8D8, func_0202E930, func_0202E938, func_0202E940, func_0202E9AC, func_0202EA20, func_0202EA40, func_0202EB04, func_0202EB0C, func_0202EB14, func_0202EB44, func_0202EB4C, func_0202EB60, func_0202EB7C, func_0202EB9C
 * address:  0x0202E818
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02012138  0x02012138  thumb
 *   func_02158468  0x02158468  thumb
 *   func_0203F4E4  0x0203F4E4  arm
 *   func_0201298C  0x0201298C  thumb
 *   func_020084F4  0x020084F4  thumb
 *   func_02008534  0x02008534  thumb
 *   func_02030734  0x02030734  arm
 *   blink_palanm_File    0x020A7804  data
 *   func_02049F78      0x02049F78  arm
 *   func_02082D44      0x02082D44  arm
 *   func_020307B0      0x020307B0  arm
 *   g_020A1B38  0x020A1B38  data
 *   func_02061CA4  0x02061CA4  arm
 *   func_02085D3C  0x02085D3C  arm
 *   func_0202EB0C  0x0202EB0C  thumb
 *   func_02087E60  0x02087E60  arm
 *   func_02087DC4  0x02087DC4  arm
 *   sub_0202EB0C   0x0202EB0C  thumb
 *   func_02087DE0  0x02087DE0  arm
 *   func_02087C88  0x02087C88  arm
 *   func_0200974C  0x0200974C  thumb
 *   func_0200856C  0x0200856C  thumb
 *   func_0202ECB0  0x0202ECB0  thumb
 *   func_0202ED00  0x0202ED00  thumb
 *   func_0202ED60  0x0202ED60  thumb
 *   func_0202EC44  0x0202EC44  thumb
 *   func_0202EC24  0x0202EC24  thumb
 *   func_0202EC7C  0x0202EC7C  thumb
 */
#include "../../matched/include/Obj06926.h"
#include "../../matched/include/Obj08811.h"
#include "../../matched/include/Obj15860.h"

struct Ctx;
struct RtcDate;
struct Sub0200852CObj;
struct Sub020097BCObj;
struct Blink;
struct OSOwnerInfo;
struct Ent0202EC24;
typedef unsigned char u8;

typedef struct S { u8 pad00[4]; int f04; } S;

typedef unsigned int   u32;

typedef signed int    s32_0202E818;

struct Date0202E888 {
    s32_0202E818 unk00;
    s32_0202E818 unk04;
    s32_0202E818 unk08;
    s32_0202E818 unk0C;
};

typedef unsigned short u16;

struct CodeIn_0202E940 {
    u32 w00;      /* 0x00 */
    u32 w04;      /* 0x04 */
    void *buf;    /* 0x08 */
    u16 h0c;      /* 0x0c */
    u16 h0e;      /* 0x0e */
    u16 h10;      /* 0x10 */
    u16 h12;      /* 0x12 */
    u32 w14;      /* 0x14 */
    u16 h18;      /* 0x18 */
};

struct CodeIn_0202E9AC {
    void *w00;    /* 0x00 */
    void *w04;    /* 0x04 */
    void *buf;    /* 0x08 */
    u16 h0c;      /* 0x0c */
    u16 h0e;      /* 0x0e */
    u16 h10;      /* 0x10 */
    u16 h12;      /* 0x12 */
    u32 w14;      /* 0x14 */
    u16 h18;      /* 0x18 */
};

struct Obj0202EA20 {
    void *unk00;
    void *unk04;
    void *unk08;
};

typedef signed short s16;

struct Row {
    u16 *src;
    u16 *dst;
    u16 *out;
    u16 unk0c;
    u16 count;
    u16 phase;
    u32 unk14;
};

struct CodeIn_0202EB04 {
    void *w00;
    void *w04;
    void *buf;
    u16   h0c;
    u16   h0e;
    u16   h10;
};

struct DeviceInfo {
    u32 bit0:1;
    u32 pad:4;
    u32 bit5:1;
};

struct Info0202EB60 {
    u8 unk00;
    u8 unk01;
    u8 unk02;
    u8 unk03;
    u8 pad[0x50];
};

typedef int           s32_0202EB44;

struct Slot {
    u8  pad[0x26];
    u8      : 3;
    u8 mark : 1;
    u8      : 4;
    u8  pad2;
};

extern u32 func_02012138(const struct Ctx *p);
extern int func_02158468(int a0);
extern void func_0203F4E4(struct RtcDate *date);
extern u8 func_0201298C(s32_0202E818 a, u8 b);
extern int func_02009D1C(struct Sub020097BCObj *obj, struct Sub0200852CObj *p, u32 *out);
extern u16 *func_020084F4(void *p);
extern u16 func_02008534(const struct Sub0200852CObj *obj);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void *func_02049F78(void *a0, u32 a1, u32 a2, u32 a3);
extern void  func_02082D44(void *dst, const void *src, int size);
extern u32 func_020307B0(void *p);
extern s32_0202E818 func_02061CA4(void *p, u32 a, u32 b, s32_0202E818 size);
extern u32 func_02085D3C(void);
extern u32 func_0202EB0C(void);
extern struct DeviceInfo *func_02087E60(void);
u32 sub_0202EB0C(void);
int func_0202EB14(void);
extern void func_02087DC4(void);
extern int func_02087DE0(void);
extern void func_02087C88(struct OSOwnerInfo *info);
extern u8 func_0200856C(const struct Sub0200852CObj *obj);
extern struct Slot *func_0200974C(u32 a);
extern s32_0202EB44  func_0202ECB0(struct Slot *t, void *b);
extern void func_0202ED00(struct Slot *t, u32 n);
extern void func_0202ED60(u32 a, void *b, u32 c);
extern u32  func_0202EC44(struct Slot *t, u32 a);
extern u32 func_0202EC24(const struct Ent0202EC24 *p);
extern s32_0202EB44 func_0202EC7C(struct Slot *a0, u32 a1);
int func_0202E818(int *p);
void *func_0202E82C(S *p);
int func_0202E83C(void *a0);
int func_0202E848(int a0, int a1, int a2);
u8 sub_0202E888(void);
u8 sub_0202E8A4(u8 x);
u8 sub_0202E8B8(s32_0202E818 x);
u8 sub_0202E8CC(s32_0202E818 a, s32_0202E818 b);
int func_0202E8D8(char *a0, int a1, char *a2);
u16 *func_0202E930(void *p);
u16 func_0202E938(void *p);
struct CodeIn_0202E940 *func_0202E940(u16 a0, u16 a1, u32 a2, u16 heap);
void func_0202EB44(void);
u32 sub_0202EB4C(void);
void sub_0202EB60(u8 *a, u8 *b);
u32 func_0202EB7C(u32 a0, u32 a1);
u32 func_0202EB9C(u32 a, void *b);
extern const char blink_palanm_File[];
extern s16 g_020A1B38[];



/*
 * Unlabelled Thumb leaf: nonzero if either of two words at +4 or +8 is set.
 */
int func_0202E818(int *p)
{
    if (p[1] != 0 || p[2] != 0)
        return 1;
    return 0;
}





void *func_0202E82C(S *p)
{
    if (p->f04 != 0)
        return (char *)p + 0x2C;
    return (char *)p + 0xC;
}





int func_0202E83C(void *a0)
{
    return func_02158468(func_02012138(a0));
}





int func_0202E848(int a0, int a1, int a2){ int t0, t1, t2, t3; t0 = func_02012B70((int)((a0 + 0) + 0)); if ((unsigned int)(t0) != (unsigned int)(0)) { t1 = func_02012984((int)((a0 + 0) + 0)); ((struct Obj06926 *)((char *)((a1 + 0))))->f0 = (unsigned short)t1; ((struct Obj08811 *)((char *)((a2 + 0))))->f0 = (unsigned short)((struct Obj06926 *)((char *)((a1 + 0))))->f0; return 0; } else { t2 = func_02012984((int)((a0 + 0) + 0)); ((struct Obj06926 *)((char *)((a1 + 0))))->f0 = (unsigned short)t2; t3 = func_0202E888((int)t2); ((struct Obj08811 *)((char *)((a2 + 0))))->f0 = (unsigned short)t3; if ((unsigned int)(((struct Obj06926 *)((char *)((a1 + 0))))->f0) != (unsigned int)(((struct Obj08811 *)((char *)((a2 + 0))))->f0)) { return 1; } else { return 0; } } }





/*
 * A whole translation unit, matched as one byte range.
 *
 * Four small date helpers. sub_0202E888 asks the ARM clock getter for a
 * 0x10-byte record and reduces its second word to a two-bit value;
 * sub_0202E8A4 and sub_0202E8B8 step that value forwards and backwards
 * around the same four-element cycle.
 *
 * The `lsrs #0x1F` / `lsls #0x1E` / `subs` / `rors #0x1E` quartet in the
 * two steppers is a signed `% 4` and nothing else: `& 3` is a two
 * instruction `movs`/`ands`, which is exactly what sub_0202E888 uses at
 * the top, and `/ 4` carries a different rounding correction. Both
 * spellings appear four instructions apart in the same 80 bytes, so the
 * pair of them pins the signedness of each operand independently.
 *
 * The `lsls #0x18` / `lsrs #0x18` at the end of all three is the `(u8)`
 * return type.
 *
 * sub_0202E8CC is a twelve byte pool-word-and-bx tail call
 * (docs/idioms/tail-call-is-a-pool-word-and-bx.md) that narrows its
 * second argument to `u8` on the way through. It nearly cost the file a
 * cut: the pool word at 0x0202E8D4 is the only occurrence of 0x0201298D
 * anywhere in the image, 0x0201298C carries no `func_` label, and the
 * pool word is inside this range, so the `literal` class has nothing and
 * no cut can reach further since the range cannot be smaller than that
 * one function. The `matched` class covers it instead: 0x0201298C is
 * already an EXACT manifest entry from earlier work, and that witness is
 * a compilation rather than a byte of this range.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0202E888.c \
 *       --addr 0x0202E888 --thumb
 */
u8 sub_0202E888(void)
{
    struct Date0202E888 d;

    func_0203F4E4((struct RtcDate *)(&d));
    return (u8)((d.unk04 - 1) & 3);
}





u8 sub_0202E8A4(u8 x)
{
    return (u8)((x + 1) % 4);
}





u8 sub_0202E8B8(s32_0202E818 x)
{
    return (u8)((x + 3) % 4);
}





u8 sub_0202E8CC(s32_0202E818 a, s32_0202E818 b)
{
    return func_0201298C(a, (u8)b);
}





/*
 * Six-byte record matcher against a three-slot table at a0+0x22 (six bytes
 * apart).  Both loop counters are `unsigned char` - the lsls 0x18 / lsrs 0x18
 * pair after each increment is the narrowing, and the comparisons are `blo`,
 * so signed ints give `blt` instead.
 *
 * Do NOT bind the record base to a local `char *p`: writing the inner compare
 * as `p[0x22 + j]` makes the compiler hoist `adds r4, a0, i*6` ahead of the
 * ok/j initialisers and differs by six bytes.  Spelling the base out as
 * `a0 + i * 6` inside the compare leaves the hoist where the original has it
 * (after `movs r6,#1` and `movs r3,#0`).
 *
 * EXACT*: the compared extent ran long by the follower's padding - the
 * follower at 0x0202E930 is a two-halfword `ldr r3,[pc]; bx r3` long-branch
 * veneer with no label of its own.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0202E8D8.c \
 *       --func func_0202E8D8 --addr 0x0202E8D8 --cc 1.1p1 --thumb
 */
int func_0202E8D8(char *a0, int a1, char *a2)
{
    unsigned char i;
    unsigned char j;

    if (a1 == 0) {
        return 0;
    }
    for (i = 0; i < 3; i++) {
        int ok = 1;

        for (j = 0; j < 6; j++) {
            if (*(unsigned char *)(a0 + i * 6 + 0x22 + j)
                    != *(unsigned char *)(a2 + j)) {
                ok = 0;
                break;
            }
        }
        if (ok == 1) {
            return func_02009D1C((struct Sub020097BCObj *)a1, (struct Sub0200852CObj *)((int)a0), 0);
        }
    }
    return 0;
}




/*
 * An unlabelled forwarding leaf after func_0202E8D8's pop: a pool-word tail
 * call to func_020084F4 (the u16 pointer accessor), the caller's argument passed through
 * untouched ("ldr r3, [pc]; bx r3").  Called from the overlays only (see
 * layout/function_starts.txt).
 */
u16 *func_0202E930(void *p)
{
    return func_020084F4(p);
}




/*
 * An unlabelled forwarding leaf after func_0202E8D8's pop: a pool-word tail
 * call to func_02008534 (the u16 getter), the caller's argument passed through
 * untouched ("ldr r3, [pc]; bx r3").  Called from the overlays only (see
 * layout/function_starts.txt).
 */
u16 func_0202E938(void *p)
{
    return func_02008534(p);
}




/*
 * TU: blink_palanm.c (__FILE__ 0x020A7804, lines 0x3c and 0x3d).
 *
 * The mode chain must write `p->w14` in EVERY arm, not into a local read
 * once at the end: with the local the scheduler hoists `movs r0, #0xf`
 * above the `cmp` and saves the branch, and the tail comes out two bytes
 * short (docs/idioms/a-shared-exit-block-is-written-out-in-each-arm.md).
 */
struct CodeIn_0202E940 *func_0202E940(u16 a0, u16 a1, u32 a2, u16 heap)
{
    struct CodeIn_0202E940 *p;

    p = func_02030734(heap, sizeof(struct CodeIn_0202E940), 0, blink_palanm_File, 0x3c);
    p->buf = func_02030734(heap, (u32)a1 * 2, 0, blink_palanm_File, 0x3d);
    p->h0c = a0;
    p->h0e = a1;
    p->h10 = 0;
    p->h12 = 0;
    p->h18 = heap;
    if (a2 == 0xfffe) {
        p->w14 = 0xe;
    } else if (a2 == 0xffff) {
        p->w14 = 0x1e;
    } else if (a2 <= 3) {
        p->w14 = 0xf;
    } else {
        p->w14 = 0x1f;
    }

    return p;
}




/*
 * TU: blink_palanm.c (__FILE__ 0x020A7804, lines 0x83 and 0x84).
 */
void func_0202E9AC(struct CodeIn_0202E9AC *p, u8 *a1, u32 a2, u32 a3, u32 a4)
{
    void *tmp;
    void *handle;
    u8 *base;

    p->w00 = func_02030734(p->h18, (u32)p->h0e * 2, 0, blink_palanm_File,
                           0x83);
    p->w04 = func_02030734(p->h18, (u32)p->h0e * 2, 0, blink_palanm_File,
                           0x84);
    handle = func_02049F78(a1, a2, (u32)(&tmp), p->h18);
    base = *(u8 * *)&((struct Obj15860 *)tmp)->fC;
    func_02082D44(base + a3 * 2, p->w00, (int)((u32)p->h0e * 2));
    func_02082D44(base + a4 * 2, p->w04, (int)((u32)p->h0e * 2));
    func_020307B0(handle);
}


/*
 * A whole translation unit, matched as one byte range.
 *
 * A four-call destructor: three owned pointers and then the object
 * itself, freed in the order unk04, unk00, unk08, self. The order is the
 * source's, because this compiler does not reorder calls, so the object's
 * second field is whatever the constructor allocated first.
 *
 * Matched as a one-function unit because the two bytes of `00 00` after
 * its last instruction are the linker's inter-section fill, so `one`
 * reports EXACT* for a padding gap rather than for an unlabelled
 * follower; `tu` compares the section as laid out.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0202EA20.c
 *       --addr 0x0202EA20 --thumb
 */
u32 sub_0202EA20(struct Obj0202EA20 *p)
{
    func_020307B0(p->unk04);
    func_020307B0(p->unk00);
    func_020307B0(p->unk08);
    return func_020307B0(p);
}


/*
 * blink_palanm.c: the per-frame BGR555 cross-fade.  Advances the phase word
 * at +0x10 by 0x400 (wrapping at 0x10000), takes the fade scale as
 * (table[phase >> 4 pair, second entry] + 0x1000) / 2 from the signed table
 * at 0x020A1B38, blends every pixel of the src row toward the dst row into
 * the output row, then hands the output row to func_02061CA4.
 *
 * Two facts closed it (wave 13).  The pixels are u16 locals, not s32: with
 * `s32 b` the dst channel extraction is scheduled differently (46 out).  And
 * the final pack is `(r << 10) | (bl | (g << 5))`: the channel ORed last is
 * the one the compiler evaluates FIRST, so red is blended and held, then
 * blue, then green, exactly the image's order; the left-nested
 * `(r << 10) | (g << 5) | bl` evaluates green before blue.
 *
 * EXACT* because the listing extent runs 8 bytes long: the unlabelled leaf
 * at 0x0202EB04 (src/matched/func_0202EB04.c) follows the pool word.
 */
s32_0202E818 func_0202EA40(struct Row *p)
{
    s32_0202E818 scale;
    u32 i;
    u16 a;
    u16 b;
    s32_0202E818 r;
    s32_0202E818 g;
    s32_0202E818 bl;

    if (p->phase + 0x400 >= 0x10000) {
        p->phase = p->phase - 0xFC00;
    } else {
        p->phase = p->phase + 0x400;
    }

    scale = (g_020A1B38[((p->phase >> 4) << 1) + 1] + 0x1000) / 2;

    for (i = 0; i < p->count; i++) {
        a = p->src[i];
        b = p->dst[i];
        r = (u8)(((a >> 10) & 0x1f)
                 + (((((b >> 10) & 0x1f) - ((a >> 10) & 0x1f)) * scale) >> 12));
        bl = (u8)((a & 0x1f)
                  + ((((b & 0x1f) - (a & 0x1f)) * scale) >> 12));
        g = (u8)(((a >> 5) & 0x1f)
                 + (((((b >> 5) & 0x1f) - ((a >> 5) & 0x1f)) * scale) >> 12));
        p->out[i] = (u16)((r << 10) | (bl | (g << 5)));
    }

    return func_02061CA4((void *)p->unk14, p->unk0c * 2, (u32)p->out, p->count * 2);
}


/*
 * blink_palanm.c: resets the fade phase word at +0x10 of the blink context
 * (the word func_0202EA40 advances by 0x400 per frame).  An unlabelled leaf
 * with no prologue sitting after func_0202EA40's pool word at 0x0202EB00, so
 * the listing folds it into func_0202EA40's extent (204 against the real
 * 196); seed 0x0202EB04 into layout/function_starts.txt.
 */
void func_0202EB04(struct CodeIn_0202EB04 *p)
{
    p->h10 = 0;
}


/*
 * A pool-word-and-bx tail call into an ARM SDK entry point
 * (docs/idioms/tail-call-is-a-pool-word-and-bx.md), eight bytes with no
 * prologue. Its result is compared against 1 by src/matched/sub_0202EB4C.c,
 * which is the only caller.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_0202EB0C.c \
 *       --func sub_0202EB0C --addr 0x0202EB0C --cc 1.1p1 --thumb
 */
u32 sub_0202EB0C(void)
{
    return func_02085D3C();
}


int func_0202EB14(void)
{
    if (func_0202EB0C()) {
        if (func_02087E60()->bit0 && func_02087E60()->bit5) {
            return 1;
        }
        return 0;
    }
    return 0;
}



/*
 * Unlabelled Thumb leaf in the ARM9 module: a bare tail call.
 *
 * Addresses are Black-image addresses.
 */
void func_0202EB44(void)
{
    func_02087DC4();
}



/*
 * Neither call sets an argument register, so both callees are declared
 * with no parameters: the `blx` to the ARM helper follows a `cmp r0, #1`
 * and leaves r0 holding the 1 it was compared against, which is a
 * leftover and not an argument
 * (docs/idioms/a-forwarding-call-passes-one-argument-and-the-rest-are-leftovers.md).
 * Declaring either callee with a parameter costs an `adds r0, ...` the
 * original does not have.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_0202EB4C.c \
 *       --func sub_0202EB4C --addr 0x0202EB4C --cc 1.1p1 --thumb
 */
u32 sub_0202EB4C(void)
{
    if (sub_0202EB0C() == 1) {
        return func_02087DE0();
    }
    return 1;
}



/*
 * Fills an 0x54-byte structure on the stack from an ARM SDK getter and
 * copies two of its bytes out through the two pointer parameters. The
 * whole 0x54 bytes are reserved even though only offsets 2 and 3 are
 * read, so the stack object is the SDK's structure and not a pair of
 * bytes; `add r0, sp, #0` is emitted twice, once for the call and once
 * as the base of the two loads, which is what a named local rather than
 * a re-taken address looks like here.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_0202EB60.c \
 *       --func sub_0202EB60 --addr 0x0202EB60 --cc 1.1p1 --thumb
 */
void sub_0202EB60(u8 *a, u8 *b)
{
    struct Info0202EB60 info;

    func_02087C88((struct OSOwnerInfo *)(&info));
    *a = info.unk02;
    *b = info.unk03;
}



/*
 * Byte-correct, MATCH-capped.  NOT in the manifest; see src/pending/README.md.
 *
 * All 30 concrete bytes are right; the call to func_0202EB9C is the only open
 * site and it is blocked on `label`: the sole branch to 0x0202EB9C image-wide
 * is the one inside this function, so there is no witness outside the
 * compared range and no cut helps (the range cannot be smaller than the one
 * function holding the call).  It closes when func_0202EB9C itself gets a
 * manifest entry or a second caller appears.
 *
 * The trailing `*` is the unlabelled follower at 0x0202EB9C: the listing's
 * extent runs 32 bytes against 30 compiled because the follower carries no
 * `func_` label in the generated listing (disasm.py only labels a prologue
 * that saves lr, and this one's first instruction is not visible from here).
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/func_0202EB7C.c \
 *       --func func_0202EB7C --addr 0x0202EB7C --cc 1.1p1 --thumb
 */
u32 func_0202EB7C(u32 a0, u32 a1)
{
    if (func_0200856C((const struct Sub0200852CObj *)a1) == 0) {
        return 0;
    }
    return func_0202EB9C(a0, (void *)a1);
}



/*
 * note:     the slot-table dispatcher of blink_palanm.c (look the record up;
 *           remove and notify, or insert by key under the count-capped
 *           policy).  Closed in wave 16 under 1.1p1, no pin: the notify
 *           call is written in BOTH arms of the count test.  1.1p1 then
 *           cross-jumps the two notify tails (the then-arm's `b` at
 *           0x0202EC04, reached by the inner `blo` as a jump to a jump) and
 *           no longer merges the two func_0202ED00 calls, and the a/b/v
 *           register rotation of docs/notes/pkt_0202EB9C.c.txt resolves
 *           with it.  `mark` is the +0x26 bit-3 field of
 *           docs/families/blink_palanm.h.
 */
u32 func_0202EB9C(u32 a, void *b)
{
    struct Slot *t;
    u32 n;
    u32 v;

    t = func_0200974C(a);
    n = func_0202ECB0(t, b);

    if (n != 0x14) {
        if (t[n].mark)
            v = 1;
        else
            v = 0;
        func_0202ED00(t, n);
        func_0202ED60(a, b, v);
        return 1;
    }

    v = func_0200856C(b);
    if (func_0202EC44(t, v) < 5) {
        if (func_0202EC24((const struct Ent0202EC24 *)t) >= 0x14)
            func_0202ED00(t, 0);
        func_0202ED60(a, b, 0);
    } else {
        func_0202ED00(t, func_0202EC7C(t, v));
        func_0202ED60(a, b, 0);
    }
    return 2;
}
