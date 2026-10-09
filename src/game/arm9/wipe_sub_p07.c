/*
 * file:     wipe_sub_p07.c
 * unit:     yes
 * function: func_02023EF4, func_02023F60, func_02023F98, func_02023FD8, func_02024004, func_02024044, func_020240FC, func_02024104, func_02024108, func_0202411C, func_02024120, func_02024124, func_02024128, func_02024134, func_02024144, func_02024148, func_0202414C, func_02024150, func_02024158, func_02024160, func_02024168, func_0202419C, func_020241E0, func_0202421C, func_02024224, func_02024230, func_0202428C, func_020242A4, func_020242C0, func_020242D8, func_02024344, func_0202435C, func_02024368, func_0202441C, func_02024450
 * address:  0x02023EF4
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
 *   G2x_SetBlendBrightness_   0x0207D658  arm
 *   func_02023E9C             0x02023E9C  thumb
 *   data_0214691C             0x0214691C  data
 *   data_021468FC             0x021468FC  data
 *   func_0207D658  0x0207D658  arm
 *   func_02082BCC  0x02082BCC  arm
 *   g_wipe_main    0x0214691C  data
 *   g_wipe_flags   0x021468FC  data
 *   g_wipe_subrec  0x021468FC  data
 *   g_021468FC    0x021468FC  data
 *   g2_021468FC   0x021468FC  data
 *   g_0214691C    0x0214691C  data
 *   func_02023E0C 0x02023E0C  thumb
 *   d_021468FC  0x021468FC  data
 *   func_02030734  0x02030734  arm
 *   func_020071CC  0x020071CC  thumb
 *   func_02024988  0x02024988  thumb
 *   func_02012FE4  0x02012FE4  thumb
 *   func_020142E8  0x020142E8  thumb
 *   MI_CpuCopy8    0x02082D44  arm
 *   file_020A745C  0x020A745C  data
 *   sub_020307B0  0x020307B0  arm
 *   sub_02024570  0x02024570  thumb
 *   unit_020355C4  0x020355C4  arm
 *   func_020355D8 0x020355D8 arm
 *   _ll_mul        0x0209C054  arm
 *   tbl_020A1B38   0x020A1B38  data
 *   func_02024598  0x02024598  thumb
 *   Table_0209F724   0x0209F724  data
 *   func_0201EC64    0x0201EC64  thumb
 *   func_0201ED04    0x0201ED04  thumb
 *   func_0201EFC8    0x0201EFC8  thumb
 *   func_0201EFFC    0x0201EFFC  thumb
 *   func_0201F250    0x0201F250  thumb
 *   func_020457B0    0x020457B0  arm
 *   func_02045808    0x02045808  arm
 *   func_02045B38    0x02045B38  arm
 *   func_02045C04    0x02045C04  arm
 *   func_02045EC0    0x02045EC0  arm
 *   sub_02045B38    0x02045B38  arm
 *   sub_02045EC0    0x02045EC0  arm
 *   - 0x02082D44 is called (src, dest, size), i.e. MI_CpuCopy8's order, not
 */
#include "../../matched/include/Obj15744.h"

struct Anim;
struct Sub020071CCCtrl;
struct Rec8;
struct Data;
struct Obj_0202411C;
struct MsgBank;
struct Rec;
struct U16Vec;
struct WordSet;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef signed short   s16;

typedef unsigned int   u32;

typedef int            s32;

struct Obj_02023EF4 {
    u8  kind;        /* +0x00 */
    u8  f01;         /* +0x01 */
    u8  f02;         /* +0x02 */
    u8  b0 : 1;      /* +0x03 */
    u8  b1 : 1;
    u8  b2 : 1;
    u8  b3 : 1;
    u8  rest : 4;
    u8  pad04[4];
    void *f08;       /* +0x08 */
    void *f0c;       /* +0x0c */
    u8  slot[8];     /* +0x10 */
    u16 f18[2];      /* +0x18 */
};

struct Src02024128 {
    unsigned char pad[0x18];
    unsigned short a;
    unsigned short b;
};

typedef struct {unsigned char pad[3];unsigned char flag:1;unsigned char rest:7;} Bits_02024150;

typedef struct {unsigned char pad[3];unsigned char rest:3;unsigned char flag:1;unsigned char last:4;} Bits_02024160;

typedef struct Pair { u16 x,y; } Pair;

typedef struct Input {
    u8 mode; u8 pad01[15]; u16 values10[4]; u16 values18[2];
} Input;

struct Obj_0202411C {
    u8  f0;
    u8  pad1[0x17];
    u16 f18;    /* 0x18 */
    u16 f1A;    /* 0x1A */
};

struct T {
    u8  pad00[1];
    u8  f01;
    u8  f02;
    u8  pad03[0xd];
    u16 f10;
    u16 f12;
    u16 f14;
    u16 f16;
    u16 f18;
    u16 f1a;
};

typedef signed int       s32_02024230;

typedef signed long long s64;

typedef int             s32_0202428C;

struct Struct_0202441C {
    u16 arcFileIdx;
    u16 strIdx;
};

extern void G2x_SetBlendBrightness_(u32 addr, int plane, int brightness);
extern void func_02023E9C(void *rec, void *p, u16 steps, s16 from,
                          u32 a4, u32 a5);
extern void func_0207D658(u32 addr, int plane, int brightness);
extern void func_02082BCC(void *p, u32 v, u32 n);
extern void func_02023E0C(struct Anim *p);
extern void *func_02030734(u32 heap, u32 sz, int c, const char *file, u16 line);
extern void *func_020071CC(struct Sub020071CCCtrl *ctrl, u32 id);
extern void *func_02024988(int a0);
extern void *func_02012FE4(struct Sub020071CCCtrl *a0);
extern u32 func_020142E8(void *bitmap, s32 id);
extern void MI_CpuCopy8(const void *src, void *dst, u32 n);
extern u32 sub_020307B0(void *p);
extern void sub_02024570(struct Rec8 *dst, const struct Rec8 *src);
extern int func_02024534(const struct Data *p1, const struct Data *p2);
extern u32 unit_020355C4(void);
extern void func_020355D8(void *);
extern void func_02024598(void *p0, int p1, int p2);
extern struct WordSet *func_0201EC64(u32 heap);
extern u32 func_0201ED04(struct WordSet *p);
extern void func_0201EFC8(struct WordSet *p, u32 i, u32 v);
extern void func_0201EFFC(struct WordSet *p, u32 i, u32 v);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern void  *func_020457B0(u32 size, u16 heap);
extern void func_02045808(struct U16Vec *vec);
extern void  *func_02045B38(int a, int b, u32 id, u16 heap);
extern u32 func_02045C04(struct Rec *rec);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern struct MsgBank *sub_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern void *sub_02045EC0(struct MsgBank *bank, u32 index);
void func_02023EF4(void *p, u16 steps, s16 from, s16 to, u32 mask);
void func_02023F60(u32 a0, u32 a1, u32 mask);
void func_02023F98(u32 mask);
void func_02023FD8(void);
int func_02024004(int a);
struct Obj_02023EF4 *func_02024044(u32 kind, u32 a1, void *src, u32 flag, void *sys, u32 hh);
void func_020240FC(void *t);
void func_02024104(u16 *p, u16 v);
void func_02024108(u16 *dst, const u16 *src);
int func_0202411C(unsigned char *p);
int func_02024120(u8 *p);
unsigned int func_02024124(unsigned short *p);
void func_02024128(struct Src02024128 *p, unsigned short *__restrict out);
void func_02024134(char *a, void *b);
u32 func_02024144(const u8 *p);
void *func_02024148(char *p);
void *func_0202414C(char *p);
int func_02024150(Bits_02024150 *p);
u32 func_02024158(const u8 *p);
int func_02024160(Bits_02024160 *p);
void func_02024168(const Input *p,u16 *a,u16 *b);
u32 func_0202419C(struct Obj_0202411C *p, u16 *q, u32 a);
void func_020241E0(struct T *p, u16 *a1, u16 *a2);
void func_0202421C(void);
void func_02024224(void *a,void *b);
void func_02024230(s16 *out, u32 count, u16 step, s32_02024230 amp);
void sub_0202428C(void *obj);
void func_020242A4(void *obj, u32 id);
void func_020242C0(void *a, void *b, void *c);
void func_020242D8(void *slot, u32 idx);
void func_02024344(void *obj);
void *func_0202435C(void *slots, unsigned int heap);
void *sub_02024368(u16 *slots, u32 heap, int count);
void *func_0202441C(const struct Struct_0202441C *obj, u32 heapId);
int func_02024450(const u16 *p);
extern char data_0214691C[];
extern char data_021468FC[];
extern u32 g_wipe_main[];
extern u32 g_wipe_subrec[];
extern u32 g_wipe_flags[];
extern u8 g_021468FC[];
extern u8 g2_021468FC[];
extern u8 g_0214691C[];
extern u32 d_021468FC[];
extern u8 file_020A745C[];
extern const s16 tbl_020A1B38[];
extern u16 Table_0209F724[];











/*
 * Front end for func_02023E9C: given a record pointer and a two-bit engine
 * mask, it arms the record once per selected engine. Each arm first sets
 * the hardware blend-brightness register for that engine to the starting
 * value through G2x_SetBlendBrightness_ (0x0207D658), then calls
 * func_02023E9C with the shared step/from/to triple and the two stack
 * arguments (the starting value, and the engine bit itself as the tag).
 *
 * The two pool words 0x04000050 and 0x04001050 are the main and sub
 * engine's BLDCNT/BLDY block; both arms are written out in full rather
 * than factored behind a helper, which is what keeps them as two separate
 * call sequences rather than one tail-merged site.
 *
 * Note the second engine's register word is the plain constant 0x04001050
 * in the pool, not 0x04000050 + 0x1000 computed at run time.
 *
 * RESOLVED 2026-09-21 (wave3 wipe_sub). This file sat in src/pending at
 * MATCH with the note below blaming a missing `literal` witness for the two
 * ABS32 pool words. The blocker was not evidentiary: the symbols block named
 * the tables at 0x0202691C and 0x020268FC, but the ROM pool words at
 * 0x02023F54 and 0x02023F5C are 0x0214691C and 0x021468FC. Because a MATCH
 * wildcards the relocation field, the wrong address was never compared and
 * the typo read as an attestation failure. With the real addresses both
 * sites resolve as `literal` (6 and 12 witnesses image-wide, e.g. the pool
 * words at 0x02023FCC and 0x02023FD0 in the neighbouring unit) and the
 * function is EXACT. Earlier prose, kept for the record:
 *
 * [stale] capped at MATCH; blocking evidence class literal; neither word
 * appears in any literal pool at another address. -- wrong on both counts,
 * see above.
 *
 * Both engines pass the same record pointer p to func_02023E9C; the first
 * argument is the engine's own descriptor table, and the last argument is
 * the engine bit (1 or 2), which func_02023E9C stores to f04.
 *
 * G2x_SetBlendBrightness_ takes three arguments (addr, plane, brightness)
 * and both arms pass all three. The first arm emits no `mov r2` because
 * `from` is still live in r2 from entry; the second arm reloads it from r6
 * after the intervening call. An earlier spelling declared a two-argument
 * extern for the first arm, which matched the bytes but left r2 unnamed
 * (docs/idioms/an-argument-passed-through-a-register-must-be-named-in-the-c.md).
 */
void func_02023EF4(void *p, u16 steps, s16 from, s16 to, u32 mask)
{
    if (p == 0) {
        return;
    }

    if (mask & 1) {
        G2x_SetBlendBrightness_(0x04000050, to, from);
        func_02023E9C(data_0214691C, p, steps, from, (u32)to, 1);
    }

    if (mask & 2) {
        G2x_SetBlendBrightness_(0x04001050, to, from);
        func_02023E9C(data_021468FC, p, steps, from, (u32)to, 2);
    }
}











void func_02023F60(u32 a0, u32 a1, u32 mask)
{
    if (mask & 1) {
        func_0207D658(0x04000050, a1, a0);
    }
    if (mask & 2) {
        func_0207D658(0x04001050, a1, a0);
    }
    func_02023F98(mask);
}











/*
 * The teardown counterpart of func_02023EF4: given the same two-bit engine
 * mask, it zeroes each selected engine's 0x20-byte blend record and clears
 * that engine's active flag.  Main engine's record is at 0x0214691C and its
 * flag at 0x021468FC+0x3c; the sub engine's record is at 0x021468FC+0x20
 * and its flag at 0x021468FC+0x1c.  The two arms are written out in full.
 *
 * THE POOL HAS A DUPLICATE OF 0x021468FC, AND WHICH USES SHARE A SLOT IS
 * THE WHOLE FINDING.  The three pool words are
 *
 *     0x02023FCC  .word 0x0214691C     <- arm 1's memset base
 *     0x02023FD0  .word 0x021468FC     <- BOTH flag stores
 *     0x02023FD4  .word 0x021468FC     <- arm 2's memset base
 *
 * mwccarm emits one pool word per source SYMBOL, in order of first use, so
 * the slot count and the sharing pattern read straight back as the number of
 * distinct externs and which statements name which.  The obvious spelling --
 * one `g_wipe_sub` at 0x021468FC for all three of its uses -- CSEs the two
 * 0x021468FC references into one slot, and the third slot then re-emits
 * 0x0214691C: 64 bytes, every instruction right, two bytes out at 0x02023FD4
 * and nothing any amount of statement shuffling reaches (63 single mutations
 * and a full permuter.py hill pass left it untouched, because it is a pool
 * layout decision, not an allocation one).
 *
 * What reproduces it is TWO distinct externs at 0x021468FC, split along the
 * image's own sharing: `g_wipe_flags` names the object both arms' flag stores
 * reach (+0x3c for main, +0x1c for sub, one slot between them) and
 * `g_wipe_subrec` names the one arm 2 memsets (its own slot).  Whether the
 * original really had two objects at one address or one object the compiler
 * saw through two declarations is not decidable from the bytes; what the
 * bytes do fix is that three source-level names were in play, not two.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02023F98.c \
 *       --func func_02023F98 --addr 0x02023F98 --cc 1.1p1 --thumb
 */
void func_02023F98(u32 mask)
{
    if (mask & 1) {
        func_02082BCC(g_wipe_main, 0, 0x20);
        g_wipe_flags[0x3c / 4] = 0;
    }
    if (mask & 2) {
        func_02082BCC(g_wipe_subrec, 0, 0x20);
        g_wipe_flags[0x1c / 4] = 0;
    }
}











/*
 *           outside 02023FD8..02024004; the only two branches to it in the
 *           image are these two
 *
 * Byte-correct, MATCH-capped.  NOT in the manifest; see src/pending/README.md.
 *
 * All 44 concrete bytes (30 of code, then three literal words) reproduce
 * exactly.  The listing extent is 108 because the next labelled start in
 * asm/arm9/src/008_02021014.s is 0x02024044; the 64 bytes between are the
 * unlabelled function at 0x02024004 and its pool, so the entry also carries
 * the `*` of a listing-extent mismatch.  The worklist size is 32 code bytes.
 *
 * Two guards on a global struct: the word at +0x3C first, then the word at
 * +0x1C, each calling func_02023E0C with a global address when it is set.
 *
 * The pool is THREE words and the first and third hold the same address
 * 0x021468FC.  mwccarm emits a pool word per source symbol, so a source that
 * reached the same object through one name would have CSEd the two loads into
 * one slot and one register (which is what the obvious spelling does: it
 * compares the field in r1 and reuses r0 for the call argument, 40 bytes).
 * The original loads the base twice, from two slots, so it is written here
 * with two names for the one address, g_021468FC for the field base and
 * g2_021468FC for the second call's argument.  That is the whole difference
 * between DIFF and MATCH here; both declarations are the same claim and both
 * are attested `literal` from outside (x6 from 0x02023F5C and friends).
 *
 * It cannot reach EXACT while func_02023E0C is unfiled: 0x02023E0C is
 * labelled in the listings but every branch to it image-wide is one of these
 * two, so the `label` class has no witness outside the compared range.  It
 * closes the day 0x02023E0C gets a manifest entry (a large function outside
 * the 0-64 byte band, so not this lane's work), and that also releases
 * src/pending/func_020052EC.c, whose first site names this address.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/func_02023FD8.c \
 *       --func func_02023FD8 --addr 0x02023FD8 --cc 1.1p1 --thumb
 */
void func_02023FD8(void)
{
    if (*(u32 *)(g_021468FC + 0x3c) != 0) {
        func_02023E0C((struct Anim *)g_0214691C);
    }
    if (*(u32 *)(g_021468FC + 0x1c) != 0) {
        func_02023E0C((struct Anim *)g2_021468FC);
    }
}











/*
 * Unlabelled Thumb leaf (no prologue, so disasm.py prints the run as ARM
 * data). A three-way guard on the object at 0x021468FC: mode 3 needs both
 * the +0x3C and +0x1C words clear, mode 1 only +0x3C, mode 2 only +0x1C;
 * anything else returns 0. The pointer is loaded from the pool word at
 * 0x02024040.
 *
 * Addresses are Black-image addresses.
 */
int func_02024004(int a)
{
    if (a == 3) {
        if (d_021468FC[0x3C / 4] == 0 && d_021468FC[0x1C / 4] == 0)
            return 1;
    } else if (a == 1) {
        if (d_021468FC[0x3C / 4] == 0)
            return 1;
    } else if (a == 2) {
        if (d_021468FC[0x1C / 4] == 0)
            return 1;
    }
    return 0;
}









/*
 * pmsi_param.c's constructor (the __FILE__ anchor at 0x020A745C reads
 * "pmsi_param.c", line 0x56).  Allocates the 0x20-byte parameter object,
 * hangs two sub-objects off it, seeds the flag byte at +3 and then takes
 * one of two initialisation paths on `kind`.
 *
 * Four spellings are load-bearing and each was isolated against the bytes:
 *   - `hh` is a u32 parameter narrowed by an EXPLICIT (u16) cast at the
 *     allocator call.  A u16 parameter gives `ldrh` at +0x08 where the
 *     original loads a full word and narrows with lsls/lsrs #0x10.
 *   - func_020142E8 returns u32 and the result is narrowed by an explicit
 *     (u8) cast before the bitfield store.  Declaring the return u8 folds
 *     the `lsls #0x18 / lsrs #0x18` pair away and loses 4 bytes.
 *   - `flag` is likewise u32 with an explicit (u8) cast into the bitfield:
 *     the original's `lsls r2,r7,#0x18 / lsrs r2,r2,#0x18` is that cast,
 *     and the following `lsls #0x1f / lsrs #0x1c` is the 1-bit bitfield at
 *     bit 3 (docs/idioms/shift-pair-with-no-matching-type-is-a-bitfield.md).
 *   - 0x02082D44 is called (src, dest, size), i.e. MI_CpuCopy8's order, not
 *     memcpy's: the original loads r0 from `src` and r1 from `o + 0x10`.
 *     Spelling it memcpy(dst, src, n) swaps r0/r1 and costs two bytes.
 *
 * `o->b0 = ...` and `o->b1 = 0` must stay two separate bitfield writes
 * (bics/orrs then bics), not a folded mask.
 *
 * EXACT*: the inferred extent runs to 344 bytes because the follower at
 * 0x020240F4 is the unlabelled 8-byte thunk func_020240FC and the run of
 * unlabelled leaf accessors after it (they save no lr, so disasm.py never
 * labels them).  The compiled 184 bytes are byte-identical.  Unlabelled
 * follower to seed into layout/function_starts.txt: 0x020240F4.
 *
 * Verified with:
 *   python3 tools/match.py one --src src/matched/func_02024044.c \
 *       --func func_02024044 --addr 0x02024044 --thumb --cc 1.1p1
 */
struct Obj_02023EF4 *func_02024044(u32 kind, u32 a1, void *src, u32 flag,
                          void *sys, u32 hh)
{
    struct Obj_02023EF4 *o;
    s32 i;

    o = (struct Obj_02023EF4 *)func_02030734((u16)hh, 0x20, 1, (const char *)file_020A745C, 0x56);
    o->kind = (u8)kind;
    o->f08 = func_020071CC(sys, 0x37);
    o->f0c = func_02024988((int)sys);
    o->b0 = (u8)func_020142E8((void *)func_02012FE4(sys), 0x960);
    o->b1 = 0;
    o->f01 = 1;
    o->f02 = 0;
    o->b3 = (u8)flag;
    if (kind == 2) {
        if (src == 0) {
            func_020242A4(o->slot, 0);
        } else {
            MI_CpuCopy8(src, o->slot, 8);
            o->b2 = 1;
        }
    } else {
        for (i = 0; i < 2; i++) {
            o->f18[i] = 0xFFFF;
        }
    }
    return o;
}








/*
 * An eight-byte tail-call thunk: the pool word at +4 holds 0x020307B0, the callee's
 * address with its low bit clear, i.e. an ARM target (docs/idioms/tail-call-is-a-pool-word-and-bx.md).
 * Unlabelled in the listing and absent from the worklist - found by scanning
 * the image for the `ldr r3, [pc, #0]; bx r3` shape whose following word names
 * an existing manifest entry - and filed from the bytes.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020240FC.c \
 *       --func func_020240FC --addr 0x020240FC --thumb --cc 1.1p1
 */
void func_020240FC(void *t)
{
    sub_020307B0(t);
}







void func_02024104(u16 *p, u16 v)
{
    p[0xC] = v;
}






void func_02024108(u16 *dst, const u16 *src)
{
    dst[8] = src[0];
    dst[9] = src[1];
    dst[10] = src[2];
    dst[11] = src[3];
}








/*
 * Unlabelled Thumb leaf accessor: byte at +1.
 */
int func_0202411C(unsigned char *p)
{
    return p[1];
}








/*
 * Tiny Thumb leaf that blocks an ov110 caller; filed by wave D2 lane 06.
 */
int func_02024120(u8 *p) { return p[2]; }








/*
 * Unlabelled Thumb leaf accessor: halfword at +0x18.
 */
unsigned int func_02024124(unsigned short *p)
{
    return p[12];
}









/*
 * Unlabelled Thumb leaf accessor: copy the halfwords at +0x18 and +0x1a to out. __restrict on out makes both loads precede both stores.
 */
void func_02024128(struct Src02024128 *p, unsigned short *__restrict out)
{
    out[0] = p->a;
    out[1] = p->b;
}






/*
 * Unlabelled Thumb tail-call thunk: sub_02024570(b, a + 0x10), where sub_02024570 copies a halfword pair.
 */
void func_02024134(char *a, void *b)
{
    sub_02024570(b, (const struct Rec8 *)(a + 0x10));
}






u32 func_02024144(const u8 *p) { return p[0]; }






void *func_02024148(char *p){return *(void **)(p+8);}






void *func_0202414C(char *p){return *(void **)(p+12);}






int func_02024150(Bits_02024150 *p){return p->flag;}







/*
 * Unlabelled Thumb leaf in the ARM9 module: extracts bit 2 of the byte at
 * +3. Pairs with func_02024160, which extracts bit 3.
 *
 * Addresses are Black-image addresses.
 */
u32 func_02024158(const u8 *p)
{
    return ((u32)*(const u8 *)&((struct Obj15744 *)p)->f3 << 29) >> 31;
}






int func_02024160(Bits_02024160 *p){return p->flag;}






void func_02024168(const Input *p,u16 *a,u16 *b) {
    Pair v;
    switch(p->mode) {
    case 0: a[0]=p->values18[0]; break;
    case 1:
        v=*(const Pair *)p->values18; *(Pair *)a=v; break;
    case 2:
        b[0]=p->values10[0]; b[1]=p->values10[1];
        v=*(const Pair *)(p->values10+2); *(Pair *)(b+2)=v; break;
    }
}







u32 func_0202419C(struct Obj_0202411C *p, u16 *q, u32 a)
{
    switch (p->f0) {
    case 0:
        if (*q == p->f18) {
            return 1;
        }
        return 0;
    case 1:
        if (q[0] == p->f18 && q[1] == p->f1A) {
            return 1;
        }
        return 0;
    case 2:
        break;
    }

    return func_02024534((const struct Data *)((u8 *)p + 0x10), (const struct Data *)a);
}






void func_020241E0(struct T *p, u16 *a1, u16 *a2)
{
    int i;

    p->f02 = (func_0202419C((struct Obj_0202411C *)p, a1, (u32)a2) == 0);
    p->f01 = 0;
    for (i = 0; i < 2; i++) {
        *(u16 *)((char *)p + i * 2 + 0x18) = a1[i];
    }
    p->f10 = a2[0];
    p->f12 = a2[1];
    p->f14 = a2[2];
    p->f16 = a2[3];
}




/*
 * An eight-byte tail-call thunk: the pool word at +4 holds 0x020355C4, the callee's
 * address with its low bit clear, i.e. an ARM target (docs/idioms/tail-call-is-a-pool-word-and-bx.md).
 * Unlabelled in the listing and absent from the worklist - found by scanning
 * the image for the `ldr r3, [pc, #0]; bx r3` shape whose following word names
 * an existing manifest entry - and filed from the bytes.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0202421C.c \
 *       --func func_0202421C --addr 0x0202421C --thumb --cc 1.1p1
 */
void func_0202421C(void)
{
    unit_020355C4();
}





void func_02024224(void *a,void *b) { func_020355D8(b); }






/*
 * pmsi_param.c: fill out[0..count) with amp * sin(phase), phase advancing
 * by step through 16 bits.  The table is FX_SinCosTable_ at 0x020A1B38
 * (sin/cos s16 pairs, hence the stride of two halfwords: the SDK's
 * FX_SinIdx); the old notes misread the pool word as 0x02021B38.
 *
 * The last byte of docs/notes/func_02024230.c.txt was the phase type: it is
 * a plain u16.  The wrap is then `lsrs` (u16 narrowing) and the index is
 * still `asrs` because the u16 promotes to int before the shift.  The s64
 * temporary for the widened table value is the permuter's find from wave 5.
 */
void func_02024230(s16 *out, u32 count, u16 step, s32_02024230 amp)
{
    u32 i;
    u16 phase;

    phase = 0;
    i = 0;
    while (i < count) {
        s64 v = (s64)tbl_020A1B38[(phase >> 4) * 2];
        s64 prod = v * (s64)amp;

        out[i] = (s16)((s32_02024230)((prod + 0x800) >> 12) >> 12);
        i++;
        phase = (u16)(phase + step);
    }
}






/*
 * A slot-clearing sibling of func_020242A4 (src/matched/sub_020242A4.c):
 * the same three-halfword sentinel fill, but the leading id field is
 * also set to the sentinel instead of taking a caller-supplied id, so
 * there is no second parameter. The loop counter is signed, the same
 * `blt` tell as the sibling function.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_0202428C.c \
 *       --func sub_0202428C --addr 0x0202428C --cc 1.1p1 --thumb
 */
void sub_0202428C(void *obj)
{
    u16 *p = (u16 *)obj;
    s32_0202428C i;

    p[0] = 0xFFFF;
    for (i = 0; i < 2; i++) {
        p[i + 2] = 0xFFFF;
    }
}






/*
 * The common slot initialiser shared by func_02024344 and the four arms of
 * func_020242D8 (src/matched/unit_020242D8.c): store the id, zero the
 * flag halfword at +2, then a two-iteration loop seeds the trailing
 * halfwords at +4 and +6 with a shared 0xFFFF sentinel. The loop counter
 * is signed (the original's `blt`, not `blo`, on a literal trip count of
 * 2); an unsigned counter compiles to `blo` instead.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_020242A4.c \
 *       --func func_020242A4 --addr 0x020242A4 --cc 1.1p1 --thumb
 */
void func_020242A4(void *obj, u32 id)
{
    u16 *p = (u16 *)obj;
    s32 i;

    p[0] = (u16)id;
    p[1] = 0;
    for (i = 0; i < 2; i++) {
        p[i + 2] = 0xFFFF;
    }
}






void func_020242C0(void *a, void *b, void *c)
{
    func_020242A4(a, (u32)b);
    func_02024598(a, (int)b, (int)c);
}






/*
 * A whole translation unit, matched as one byte range.
 *
 * func_020242D8 dispatches on a 0..3 index through a dense jump table
 * (docs/idioms/dense-switch-is-a-pc-relative-halfword-table.md); an index
 * over 3 lands on the shared epilogue with neither a call nor a store,
 * which only a `default: break;` with nothing else in it produces. Each
 * arm calls the shared initialiser func_020242A4 (its own file,
 * src/matched/sub_020242A4.c, EXACT) with a small id, then overwrites the
 * flag halfword and one trailing field with plain 16-bit constants; the
 * four constants are narrowed by the `strh`, not addresses. Case 3 passes
 * the same id as case 1 (2) but a different flag (0xd instead of 0), so
 * the four arms cannot be collapsed by id alone.
 *
 * func_02024344 is the same shape as one switch arm inlined outside a
 * switch: call func_020242A4 with id 0, then overwrite the flag and
 * trailing field it just set.
 *
 * The two functions are contiguous with no gap: func_020242D8's own
 * literal pool (the four constants) runs right up to func_02024344's
 * entry point.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_020242D8.c \
 *       --addr 0x020242D8 --thumb
 */
void func_020242D8(void *slot, u32 idx)
{
    u16 *p = (u16 *)slot;

    switch (idx) {
    case 0:
        func_020242A4(slot, 1);
        p[1] = 0;
        p[2] = 0x5D2;
        break;
    case 1:
        func_020242A4(slot, 2);
        p[1] = 0;
        p[2] = 0x5CD;
        break;
    case 2:
        func_020242A4(slot, 3);
        p[1] = 0;
        p[2] = 0x667;
        break;
    case 3:
        func_020242A4(slot, 2);
        p[1] = 0xd;
        p[2] = 0x573;
        break;
    default:
        break;
    }
}






void func_02024344(void *obj)
{
    u16 *p = (u16 *)obj;

    func_020242A4(obj, 0);
    p[1] = 1;
    p[2] = 0x58F;
}






/*
 * sub_02024368 with a count of 2: a tail call through the pool.  Seeded in
 * layout/function_starts.txt from the bl sites in ov010, ov069 and ov093
 * (w6_fix18).
 */
void *func_0202435C(void *slots, unsigned int heap)
{
    return sub_02024368(slots, heap, 2);
}






/*
 * Archived graphics-slot loader: opens the bank named by the id table at
 * 0x0209F724 for the requested stream, unpacks a scratch buffer out of
 * it, and walks the caller's two-halfword slot array telling the slot
 * manager what each entry is.
 *
 * A slot word of 0xffff means "empty" and is registered with the
 * fixed-size flag; otherwise bit 11 of the word says whether the value
 * carries a 0x7ff payload (registered masked) or is a plain size
 * (registered whole).  The two branches into the size-carrying
 * registration merge on one call site, so they are written as two
 * separate calls in the source and left to the compiler.
 *
 * The 0x100 buffer request is materialised as `movs r5, #2` followed by
 * `adds r5, #0xfe`: the 2 already sits in r5 from the previous call's
 * argument, and 2 + 0xfe is four bytes either way.
 */
void *sub_02024368(u16 *slots, u32 heap, int count)
{
    void *obj;
    void *buf;
    void *slot;
    void *k;
    int i;

    obj = func_0201EC64((u16)heap);
    for (i = 0; i < count; i++) {
        u16 v = slots[i + 2];

        if (v != 0xffff) {
            if ((v >> 11) & 1) {
                func_0201EFFC(obj, i, v & 0x7ff);
            } else {
                func_0201EFC8(obj, i, v);
            }
        } else {
            func_0201EFFC(obj, i, 1);
        }
    }
    slot = func_02045B38(0, 2, Table_0209F724[slots[0]], (u16)heap);
    buf = func_020457B0(0x100, (u16)heap);
    k = func_02045EC0(slot, slots[1]);
    func_0201F250(obj, buf, k);
    func_02045808(k);
    func_02045C04(slot);
    func_0201ED04(obj);
    return buf;
}




void *func_0202441C(const struct Struct_0202441C *obj, u32 heapId)
{
    void *str;
    void *bank;
    u16 hid = (u16)heapId;

    bank = sub_02045B38(0, 2, Table_0209F724[obj->arcFileIdx], hid);
    str = sub_02045EC0(bank, obj->strIdx);
    func_02045C04(bank);

    return str;
}


int func_02024450(const u16 *p)
{
    if (*p != 0xFFFF) {
        return 1;
    }
    return 0;
}
