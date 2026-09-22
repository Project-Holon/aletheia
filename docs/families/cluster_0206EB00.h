/*
 * docs/families/cluster_0206EB00.h -- shared declarations for the
 * pseudo-family at 0x0206EB00..0x02070360 in the ARM9 image.
 *
 * REFERENCE DOCUMENT ONLY.  Nothing includes this file; it is not part of any
 * translation unit and `match.py` never sees it.  It is the adjudicated union
 * of the declarations the family's byte-exact sources carry, written down once
 * so an attempt on an open member starts from the settled shape.
 *
 * WHAT THIS IS.  No __FILE__ anchor covers this range, so this is an address
 * cluster, not a recovered translation unit.  It is ONE subsystem: the
 * per-node animation channel decoder of a 3D model animation player.
 *   - func_0206EE60 is the driver.  Given the animation root, a node index and
 *     the 20.12 cursor t, it walks the node's record and fills an Out block
 *     (flags word, a 3x3 rotation at +0x28, scale/translation words at
 *     +0x4C..+0x54), then emits it through the root's hook.
 *   - three samplers per channel kind, each in a "plain" (no lerp) and a
 *     "lerp" flavour.  The driver picks the lerp flavour when the cursor has
 *     a fraction and root->f08 bit 0 is set:
 *         scalar      func_0206F214 (plain)   func_0206F36C (lerp)
 *         vector-2    func_0206F4C8 (plain)   func_0206F6B0 (lerp)
 *         rotation    func_0206F844 (plain)   func_0206FC5C (lerp)
 *   - func_0206FFA0 decodes one packed rotation (an axis permutation or a
 *     13-bit-packed quantised row set) into a 3x3 matrix; the rotation
 *     samplers call it per key.
 *   - func_0206EBB8 / func_0206EC50 / func_0206ECE0 fetch the "current
 *     node" through the global stash at 0x02148DB0 and decode its three
 *     flag groups (translation, rotation, scale/extra) directly.
 *   - func_02070274 (u8) and func_0207010C (RGB555) are the byte and colour
 *     key samplers of the NEXT subsystem (the track engine of
 *     docs/families/cluster_02070360.h, whose func_02070524 / func_02070624
 *     are their scalar and vector siblings); they share the flag cascade
 *     below and are listed here because they sit in this packet.
 *
 * Derived from src/matched/func_0206EB00.c, func_0206EBB8.c,
 * func_0206EC50.c, func_0206EE60.c, func_0206F214.c, func_0206F36C.c,
 * func_0206F6B0.c, func_0206F844.c, func_0206FFA0.c, func_0207010C.c,
 * func_02070274.c, and the DIFF sources in docs/notes/pkt_0206EB00.c.txt
 * (0x0206ECE0) and docs/notes/pkt_0206F4C8.c.txt (0x0206F4C8, 0x0206FC5C).
 *
 * ============================================================================
 * THE COMPILER PIN.  READ THIS BEFORE WRITING ANY C FOR THIS FAMILY.
 * ============================================================================
 * The family is a 2.0 unit.  Two tells, both in docs/FRONTEND-PINS.md:
 *   - "kept branches": a guard body of four to six instructions that
 *     dsi/1.1p1 -O4,p would predicate is kept as a branch (func_0206EBB8,
 *     func_0206F36C, func_0206F6B0, func_0207010C);
 *   - "64-bit multiply by a constant": `(long long)x * 3` compiles to
 *     umull + asr + ONE mla in the image.  ../2.0/sp2 always adds a
 *     `mov rZ, #0` / `mla hi, lo, rZ, hi` for the constant's zero high word;
 *     ../2.0/sp2p2 (and sp2p3/sp2p4) fold it.  func_0206F214 is EXACT only
 *     under ../2.0/sp2p2, and func_0206F4C8 (the vector-2 version of the same
 *     blend) is size-exact only under it.
 * Every EXACT member is EXACT under ../2.0/sp2p2 as well as ../2.0/sp2, so
 * sp2p2 is the better family pin; the earlier members keep ../2.0/sp2 in
 * their headers because that is what they were verified and filed with.
 * func_02070274 and func_0206EC50 are compiler-neutral (EXACT under 1.1p1).
 *
 * ISA: ARM throughout.  Always pass `--arm`.
 * ============================================================================
 *
 * ADJUDICATION RULE.  A load or store constrains a field; a name does not.
 */

#ifndef CLUSTER_0206EB00_H
#define CLUSTER_0206EB00_H

typedef unsigned char      u8;
typedef unsigned short     u16;
typedef unsigned int       u32;
typedef signed   short     s16;
typedef signed   int       s32;

/* ================================================================== *
 * 1.  The animation root ("Hdr" in the sampler sources)
 *
 *   +0x04  u16 key count; `cnt04 - 1 == t >> 12` means "the last key"
 *          (func_0206F36C, func_0206F6B0, func_0206FC5C: `ldrh r?,[h,#4]`).
 *   +0x08  flags: bit 0 = lerp allowed (func_0206EE60), bit 1 = wrap the
 *          last key against key 0 (the three lerp samplers).
 *   +0x0C  byte offset of the rotation-axis table   (func_0206FC5C,
 *   +0x10  byte offset of the quantised-row table     func_0206EE60 pass
 *          them to func_0206FFA0 as root + off).
 *   +0x14  u16 per-node record offsets, indexed by node (func_0206EE60).
 *   The plain samplers func_0206F214 / func_0206F4C8 take the same pointer
 *   as a plain byte base (`u8 *base`) and never read a field of it.
 * ================================================================== */
typedef struct {
    u32 f00;
    u16 cnt04;              /* 0x04  key count                                */
    u16 pad06;
    u32 f08;                /* 0x08  bit0 lerp allowed, bit1 wrap last key    */
    u32 f0c;                /* 0x0c  axis table offset                        */
    u32 f10;                /* 0x10  row table offset                         */
    u16 recoff[1];          /* 0x14  per-node record offsets                  */
} AnmRoot;

/* ================================================================== *
 * 2.  The channel record (every sampler's third argument, "Rec")
 *
 *   +0x00  flags: bits 31:30 key stride (0 full / 1 half / 2 quarter), bit 29
 *          key width (s16 vs s32 / V2s vs V2i), bits 28:16 key count n
 *          (masked with the pool word 0x1FFF0000 then `lsr #16`).
 *   +0x04  byte offset of the key block from the root.
 * The driver passes a CURSOR into the node record here: each channel is two
 * words when sampled, one (or two) literal words otherwise.
 * ================================================================== */
typedef struct { u32 flags; u32 off04; } Rec;

/* Key element types.  Index them as structs, not as `int` subscripts
   (`((V2i *)p)[k].x`), or the compiler emits an extra `lsl` (func_0206F6B0). */
typedef struct { s16 x; s16 y; } V2s;
typedef struct { s32 x; s32 y; } V2i;

/* ================================================================== *
 * 3.  Out -- the decoded node transform (func_0206EE60's fourth argument,
 *     func_0206EBB8 / func_0206EC50 / func_0206ECE0's only argument)
 *
 *   +0x00  flags: |= 4 rotation-less (EBB8), |= 2 (ECE0), |= 1 (EC50),
 *          = 7 dead channel (EE60).
 *   +0x28  MtxFx33 rotation, nine s32 (ECE0 writes it; EE60 hands it to the
 *          rotation samplers and fills +0x40..+0x48 from the other two rows
 *          by the cross product).
 *   +0x4c, +0x50, +0x54  three scalar channels (EBB8 writes them as
 *          out[0x13..0x15]; EE60 through func_0206F214 / func_0206F36C).
 * ================================================================== */
typedef struct {
    u32 f00;
    u8  pad04[0x24];
    s32 m[9];               /* 0x28  rotation                                 */
    u32 f4c, f50, f54;      /* 0x4c  scalar channels                          */
} Out;

/* ================================================================== *
 * 4.  The global stash at 0x02148DB0 ("Root" in EBB8/EC50/ECE0, "Disp" in
 *     EE60 -- the same object)
 *
 *   +0x00  the current header; its byte +1 is the node index.  It is ALSO
 *          the hook's third argument (EC50 keeps it live in r2 from
 *          0x0206EC5C to the `blx`; EE60 passes `d->first`).
 *   +0xD4  the bank: byte +1 entry count, u16 +6 table offset; entry i is at
 *          bank + off + 4 + (*(u16 *)(bank + off)) * i and holds a u32
 *          offset of the node from the bank.
 *   +0xE8  hook(out, payload, first, extra) -- FOUR arguments.  EC50 passes
 *          the node flag word as `extra`, EE60 passes (f00 & 1) ? 4 : 0.
 * ================================================================== */
typedef struct { u8 unk00; u8 idx01; } StashHdr;
typedef struct { u8 unk00; u8 cnt01; u8 unk02[4]; u16 off06; } Bank;
typedef struct {
    StashHdr *h;            /* 0x00                                           */
    u8   pad04[0xD0];
    Bank *bank;             /* 0xd4                                           */
    u8   pad_d8[0x10];
    void (*hook)(void *out, void *payload, StashHdr *first, u32 extra); /* e8 */
} Stash;
extern Stash *g_02148DB0;               /* 0x02148DB0                         */

/* The node resolve shared by EBB8, EC50 and ECE0 is TWO NESTED INLINE
   HELPERS (func_0206EC50.c).  The double `beq` on one `cmp bank, #0` is the
   two inlined null tests.  Written flat with gotos it produces the same
   instructions (EBB8 is filed that way) but a different register numbering
   in EC50 and ECE0; written as helpers EC50 is byte-exact under both front
   ends:

   static inline u8 *entry_of(Bank *b, u32 idx) {
       u8 *t;
       if (b != 0 && idx < b->cnt01) {
           t = (u8 *)b + b->off06;
           return t + 4 + (*(u16 *)t) * idx;
       }
       return 0;
   }
   static inline u8 *resolve(Bank *b, u32 idx) {
       u8 *e;
       if (b != 0) {
           e = entry_of(b, idx);
           if (e != 0)
               return (u8 *)b + *(u32 *)e;
       }
       return 0;
   }
*/

/* ================================================================== *
 * 5.  The permutation tables (func_0206ECE0, func_0206FFA0)
 *
 * FOUR separate ABS32 symbols, each a column of 4-byte rows, indexed by the
 * rotation's axis nibble k.  Declare one extern per column with a 4-byte
 * stride struct; one array indexed [k*4+n] loses three pool words.  The
 * pool order in both users is 1998, 1999, 199A, 199B, and 1998 is the
 * FIRST lookup (ECE0's older note had 1999 first; the pool proves it).
 *
 * THE COLUMNS ARE `const` (proved wave 10, func_0206FFA0 EXACT): both users
 * load column 1998 before the store to m[k] and 1999 before the store to
 * m[s1]; mwcc hoists a load above a store through `out` only when the
 * object is const.  Non-const costs 32 bytes in FFA0 and 37 in ECE0.
 * ================================================================== */
typedef struct { u8 c; u8 pad[3]; } Perm;
extern const Perm g_020A1998[];         /* 0x020A1998  row slot for u         */
extern const Perm g_020A1999[];         /* 0x020A1999  row slot for v         */
extern const Perm g_020A199A[];         /* 0x020A199A  slot for +-v           */
extern const Perm g_020A199B[];         /* 0x020A199B  slot for +-u           */

/* ================================================================== *
 * 6.  Prototypes, each with the function that evidences it
 * ================================================================== */

/* src/matched/func_0206EB00.c */
void func_0206EB00(char *dst, char *src, char *tbl);
/* src/matched/func_0206EB7C.c (1.1p1) */
/* void func_0206EB7C(u32 a, Hdr0206EB7C *h, u32 b); */
/* src/matched/func_0206EBB8.c: fills out[0x13..0x15] or sets out[0] |= 4 */
void func_0206EBB8(u32 *out);
/* src/matched/func_0206EC50.c */
void func_0206EC50(void *out);
/* DIFF (384/14, sp2p2, wave 10), docs/notes/pkt_0206EB00.c.txt: fills
   out->m or sets out->f00 |= 2.  Takes an Out * (m[9] stores as out->m[..]) */
void func_0206ECE0(Out *out);
/* src/matched/func_0206EE60.c (../2.0/sp2p2, wave 10): the driver */
void func_0206EE60(AnmRoot *root, u32 node, u32 t, Out *out);
/* src/matched/func_0206F214.c (../2.0/sp2p2): scalar, plain */
void func_0206F214(int *out, int t, Rec *r, u8 *base);
/* src/matched/func_0206F36C.c: scalar, lerp */
void func_0206F36C(int *out, int t, Rec *r, AnmRoot *h);
/* DIFF (2 bytes, sp2p2): vector-2, plain */
void func_0206F4C8(int *out, int t, Rec *r, u8 *base);
/* src/matched/func_0206F6B0.c: vector-2, lerp */
void func_0206F6B0(int *out, int t, Rec *r, AnmRoot *h);
/* src/matched/func_0206F844.c (../2.0/sp2p2, wave 10): rotation, plain
   (func_0206FFA0, VEC_Normalize) */
void func_0206F844(int *out, int t, Rec *r, AnmRoot *h);
/* DIFF (836/8, ../2.0/sp2, wave 9): rotation, lerp; decodes keys k and k2 into two stack matrices,
   lerps rows 0 and 1, normalises them, and rebuilds row 2 by the cross
   product when either decode returned 1, else lerps and normalises it. */
void func_0206FC5C(int *out, int t, Rec *r, AnmRoot *h);
/* src/matched/func_0206FFA0.c (../2.0/sp2p2, wave 10): returns 0 for an
   axis-permutation key (id bit 15), 1 for a quantised-row key (whose row 2
   the caller must rebuild) */
int  func_0206FFA0(int *out, s16 *axis, s16 *rows, u32 id);
/* src/matched/func_0207010C.c: RGB555 key sampler */
u16  func_0207010C(u8 *base, u32 flags, u32 idx);
/* src/matched/func_02070274.c: u8 key sampler */
u16  func_02070274(u8 *base, u32 flags, u32 idx);

/* Callees outside the family. */
extern void func_020834A8(void *m);          /* thumb, MtxFx33 init, 1 arg  */
extern void VEC_Normalize(const void *src, void *dst);     /* 0x0207CCA4    */

/* ================================================================== *
 * 7.  Recurring source levers (all measured in this family)
 *
 *  - Width choices are written s16-arm FIRST as a plain if/else; the lerp
 *    tails' two arms are spelled exactly as func_02070524's `two:` block.
 *  - In a `last:` block the mask `t & 0xfff` is assigned BEFORE `mul = 1`,
 *    or 2.0 derives 0xfff as `rsb rX, rOne, #0x1000` and drops the pool word.
 *  - The masked cursor of the rotation sampler is a NEW variable (`frac`),
 *    not `t` reassigned, or t is kept in a callee-saved register throughout.
 *  - Index pairs for the 3:1 blend are fresh variables (i0, j), and the
 *    shared `two:` block takes its own index (func_0207010C).
 *  - A `k & 2` arm that rewrites k goes through a named temporary in
 *    func_0206F214; direct `k = k >> 2` moves k out of r4.
 * ================================================================== */

/* ================================================================== *
 * 8.  Rotation samplers (wave 9, func_0206FC5C 836/8, func_0206F844 1048/10)
 *
 *  - The row-2 cross product is three temporaries from DIRECT field reads,
 *    stored after all three are computed:
 *        a = (m[1]*m[5] - m[2]*m[4]) >> 12;
 *        b = (m[2]*m[3] - m[0]*m[5]) >> 12;
 *        c = (m[0]*m[4] - m[1]*m[3]) >> 12;   m[6] = a; m[7] = b; m[8] = c;
 *    Six bound locals merge five loads into `ldmib` (32 bytes short in FC5C).
 *    (func_0206EE60 takes the same form; wave 10 withdrew the "six
 *    locals" reading, which was only right while lerp was spelled wrong.)
 *  - The decode-or accumulator: `ok = 0; ok |= dec(..); ok |= dec(..);`
 *    directly gives the folded `orr rX, r0, #0`; F844's 3:1 arm writes
 *    `ok = 0` before its index split and gets the image's `mov sl, #0`.
 *  - The second key of a pair is `((u16 *)p + k2)[1]`, not `p[k2 + 1]`.
 *  - Load order at entry is p, k, oa, ob, f (flags last) in FC5C.
 * ECE0 (384/40): the flag word is re-read INTO THE SAME variable after the
 * func_020834A8 call, or k is sunk past the call (105).  The wave-8 41-byte
 * source read an uninitialised pointer and is retracted.
 * ================================================================== */

/* ================================================================== *
 * 9.  Wave 10 levers (FFA0, EE60, F844 EXACT; ECE0 40 -> 14)
 *
 *  - A 0/1 flag chosen by a two-test guard is ONE conditional expression:
 *        lerp = ((t & 0xfff) != 0 && (root->f08 & 1) != 0) ? 1 : 0;
 *    (EE60).  The goto and if/else forms give the image's instructions
 *    but swap the flag and the cursor (63 bytes); a bare `&&` is 944.
 *  - EE60's cofactor block is the FC5C form too (three direct-read
 *    temporaries); the "six locals" rule of section 8 is withdrawn.
 *  - A decode accumulator private to one arm is a block-scoped variable
 *    with its initialiser (`u32 ok2 = 0;` at the top of F844's 3:1 arm).
 *  - FFA0's packed arm goes row by row: load, store >> 3, fold into p.
 *  - ECE0: an Out * parameter with out->m[..] stores, the flag groups as a
 *    wrapping if (flag-2 block last), and the perm tail in FFA0's shape.
 *    Left: node r4 / k r5 against the image's r5 / r4.
 * ================================================================== */

#endif /* CLUSTER_0206EB00_H */
