/*
 * file:     wipe_sub_p14.c
 * unit:     yes
 * function: func_02023EF4, func_02023F60, func_02023F98, func_02023FD8, func_02024004, func_02024044
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
 *   - 0x02082D44 is called (src, dest, size), i.e. MI_CpuCopy8's order, not
 *   func_02030734  0x02030734  arm
 *   func_020071CC  0x020071CC  thumb
 *   func_02024988  0x02024988  thumb
 *   func_02012FE4  0x02012FE4  thumb
 *   func_020142E8  0x020142E8  thumb
 *   func_020242A4  0x020242A4  thumb
 *   MI_CpuCopy8    0x02082D44  arm
 *   file_020A745C  0x020A745C  data
 */
struct Anim;
struct Sub020071CCCtrl;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef signed short   s16;

typedef unsigned int   u32;

typedef int            s32;

struct Obj {
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
extern void  func_020242A4(void *obj, u32 id);
extern void MI_CpuCopy8(const void *src, void *dst, u32 n);
void func_02023EF4(void *p, u16 steps, s16 from, s16 to, u32 mask);
void func_02023F60(u32 a0, u32 a1, u32 mask);
void func_02023F98(u32 mask);
void func_02023FD8(void);
int func_02024004(int a);
struct Obj *func_02024044(u32 kind, u32 a1, void *src, u32 flag, void *sys, u32 hh);
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
struct Obj *func_02024044(u32 kind, u32 a1, void *src, u32 flag,
                          void *sys, u32 hh)
{
    struct Obj *o;
    s32 i;

    o = (struct Obj *)func_02030734((u16)hh, 0x20, 1, (const char *)file_020A745C, 0x56);
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
