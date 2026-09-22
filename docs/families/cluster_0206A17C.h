/*
 * docs/families/cluster_0206A17C.h -- shared declarations for the
 * pseudo-family cluster_0206A17C (0x0206A17C..0x0206AE94 in the ARM9 image).
 *
 * PSEUDO-FAMILY.  The upper half of the ARM9 image carries no __FILE__
 * anchors, so this cluster was formed by address adjacency plus shared
 * callees and data objects, NOT by a string anchor.  Two things hold it
 * together and are the whole basis of the grouping:
 *
 *   g_02148B4C  the "rig register block": a ~0x264-byte control block whose
 *               word at +0xFC is a bitmask of which sub-rigs have been
 *               initialised.  Everything from 0x0206A700 to 0x0206AE94
 *               reads or writes that one word.
 *   the Ent chain  a nested cell/attribute table walked out of a header at
 *               h+8, shared by 0x0206A19C..0x0206A700 and by the matched
 *               file src/matched/func_0206A67C.c.
 *
 * WHAT THE SUBSYSTEM IS.  Two cooperating halves of the same 3D model /
 * animation rig:
 *
 *   PART 1, 0x0206A17C..0x0206A700 -- the ANIMATION TABLE WALKER.  Resolves
 *     entries out of a two-level table (a cell table found at h + *(u32*)(h+8),
 *     then a per-entry attribute table at Ent.tbl) and dispatches each live
 *     entry, paired with a context entry looked up through func_0206E62C,
 *     to one of the two per-entry appliers func_0206A19C / func_0206A3CC.
 *     0x0206A2CC and 0x0206A4AC are the two bulk drivers; func_0206A5B4 is
 *     the single-entry form and func_0206A67C the clear-all sweep.
 *
 *   PART 2, 0x0206A700..0x0206AE94 -- the RIG REGISTER BLOCK.  A block of
 *     mode setup / teardown routines over g_02148B4C: func_0206A700 builds
 *     it, func_0206A8FC enters a mode (nine registrations through
 *     func_0206DDA4, sets bit 0), func_0206A854 leaves it (clears bits 0 and
 *     1), func_0206A9DC / func_0206AA0C publish three-word records into it,
 *     and a family of lazy accessors (func_0206AAD4, func_0206AD20,
 *     func_0206ADBC, func_0206ADF4) each guard one bit of the +0xFC mask,
 *     run a one-time initialiser and return their slot.  func_0206AB18 is
 *     the 4x4 fixed-point matrix inverse those initialisers call.
 *
 * A NOTE ON THE COMPILER.  This cluster is unusually pin-heavy: eight of its
 * members carry `compiler: ../2.0/sp2` on the "kept constants" / "kept
 * branches" tells recorded in docs/FRONTEND-PINS.md.  When a function here
 * comes out the right shape but four bytes short with constants hoisted into
 * callee-saved registers, try the pin before rewriting the C.
 *
 * REFERENCE DOCUMENT ONLY.  Nothing includes this file; it is not part of
 * any translation unit and match.py never sees it.  Every declaration is
 * derived from an EXACT/EXACT* file in src/matched, and the evidencing
 * function is named in the comment beside it.
 *
 * Addresses are Black-image addresses throughout.
 */

#ifndef CLUSTER_0206A17C_H
#define CLUSTER_0206A17C_H

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed   short s16;
typedef signed   int   s32;

/* ================================================================== *
 * PART 1: the animation table walker, 0x0206A17C..0x0206A700
 * ================================================================== */

/* One table entry.  Eight bytes, and every field below is pinned by at least
 * one EXACT file.  The same struct is spelled identically in
 * src/matched/func_0206A5B4.c and src/matched/func_0206A67C.c.
 *
 * +1 (count) is the entry count the bulk drivers bound their loop by; it is
 * read as a BYTE (`ldrb r0, [r3, #1]`), which is what fixes it at u8.
 * +3 (flags) bit 0 is the "already done" mark: func_0206A67C clears it on
 * every entry, and the drivers skip an entry that has it set.
 * +6 (tbl) is the offset from the entry to its own attribute table, whose
 * first halfword is that table's record stride. */
struct Ent {
    u8  f0;
    u8  count;      /* +1  func_0206A67C: the loop bound, ldrb          */
    u8  f2;
    u8  flags;      /* +3  func_0206A67C: bit 0 is the done mark        */
    u16 f4;
    u16 tbl;        /* +6  func_0206A5B4: offset to the attribute table */
};

/* The base/entry resolution every function of this half opens with, written
 * out here once because all four matched files spell it the same way:
 *
 *     base = (h != 0 && *(u32 *)(h + 8) != 0) ? h + *(u32 *)(h + 8) : 0;
 *     e1   = (Ent *)(base + *(u16 *)(base + K));   K = 0 or 2
 *
 * The ternary is load-bearing: written as an if/else with a store in each arm
 * the front end emits a cross-jump and the function grows (measured in
 * docs/notes/pkt_0206A19C.c.txt).  K is 0 for the func_0206A19C driver and 2
 * for the func_0206A3CC driver, which is the only difference between the two.
 *
 * Entry resolution inside the loop, also identical in all four:
 *     t2 = e1->tbl;  st = *(u16 *)((char *)e1 + t2);
 *     t  = (Ent *)((char *)e1 + t2 + 4 + st * i);
 */

/* The context lookup.  Takes TWO arguments -- the null check on r1 at
 * 0x0206E630 is the evidence, and reading it as one-argument is what left an
 * earlier pass 60 bytes short (docs/notes/pkt_0206A19C.c.txt). */
extern void *func_0206E62C(void *p, void *q);           /* 0x0206E62C */

/* The two per-entry appliers.  Both take the base, the entry, the caller's
 * context and the context entry, in that order; the 4th argument is the
 * func_0206E62C result, not the first table lookup (func_0206A5B4). */
extern void func_0206A19C(void *a, struct Ent *b, void *c, void *d);
extern void func_0206A3CC(void *a, struct Ent *b, void *c, struct Ent *d);

extern int  func_0206A2CC(char *h, char *c);            /* bulk, via A19C  */
extern int  func_0206A4AC(char *h, char *c);            /* bulk, via A3CC  */
extern int  func_0206A5B4(char *h, char *c, u32 i2, u32 i3);  /* one entry */
extern void func_0206A67C(char *h);                     /* clear every done bit */

/* PROVEN wave 10: PART 1 IS NITROSYSTEM G3D TEXTURE/PALETTE BINDING.
 * Four EXACT files (func_0206A19C/2CC/3CC/4AC) were closed by writing them
 * as the NitroSystem source is shaped, with its types and static inlines,
 * after 4600+ permuter compiles on raw-offset spellings had stalled:
 *
 *   func_0206A2CC  NNS_G3dBindMdlTex(mdl, tex)           -> BOOL
 *   func_0206A19C  bindMdlTex_Internal_(mat, bind, tex, texData)
 *   func_0206A4AC  NNS_G3dBindMdlPltt(mdl, tex)          -> BOOL
 *   func_0206A3CC  bindMdlPltt_Internal_(mat, bind, tex, plttData)
 *   func_0206E62C  NNS_G3dGetResDataByName(dict, name)
 *   (func_0206A5B4 / func_0206A67C are then very likely the ...Ex /
 *    NNS_G3dReleaseMdlTex-style forms; not re-derived here.)
 *
 * Layouts every one of those four files pins (use these, not struct Ent):
 *   ResDict      { u8 revision; u8 numEntry; u16 sizeDictBlk; u16 dummy;
 *                  u16 ofsEntry; }                  -- the "Ent" above is this
 *   entry header { u16 sizeUnit; u16 sizeTotal; }   data at +4, names
 *                  (16 bytes each) at hdr + sizeTotal
 *   ResMat       { u16 ofsDictTexToMatList; u16 ofsDictPlttToMatList;
 *                  ResDict dict; }  -- so the material dict is mat + 4
 *   ResMdl       ofsMat at +8
 *   ResTex       texInfo.vramKey +0x08, tex4x4Info.vramKey +0x18,
 *                plttInfo.vramKey +0x2c, plttInfo.ofsDict (u16) +0x34,
 *                texInfo dict +0x3c
 *   bind record  { u16 offset; u8 numIdx; u8 flag; }  (bit 0 = bound; this is
 *                the "count at +1 / flags at +3" pair read off the records,
 *                NOT fields of the dictionary header)
 *   TexData      { u32 texImageParam; u32 extraParam; } width = bits 0..10,
 *                height = bits 11..21 of extraParam
 *   PlttData     { u16 offset; u16 flag; }
 *   MatData      texImageParam +0x14, texPlttBase (u16) +0x1c,
 *                origWidth/origHeight (u16) +0x20/+0x22, magW/magH +0x24/+0x28
 *
 * The load-bearing inline shapes:
 *   GetMat(mdl):  `if (mdl && mdl->ofsMat) return mdl + ofsMat; return 0;`
 *                 -- the SAME guard as a ternary is the 9-byte r8/sb swap.
 *   GetMatDataByIdx(mat, idx): `if (mat) { d = GetResDataByIdx(&mat->dict,
 *                 idx); if (d) return mat + *d; } return 0;`
 *   Gfd key address: (key & 0xffff) << 3, then >> 3 at the use: 2.0 folds the
 *                 pair to `bic #0xe0000000`, which is where that odd bic
 *                 comes from.  In the pltt binder the result goes into a u16
 *                 local (plttBase and vramOffset are both u16).
 */

/* ================================================================== *
 * PART 2: the rig register block, 0x0206A700..0x0206AE94
 * ================================================================== */

/* The block itself.  Declared as a plain u32 array rather than a struct
 * because that is how every matched file spells it, and because the spelling
 * is load-bearing: func_0206AA0C records that naming the flag word and the
 * record slot as SEPARATE externs makes the front end hoist the flag load
 * above the record store and costs a pool register.  One object, indexed.
 *
 * Known slots, each named by the matched file that pins it:
 *   [0x00]        func_0206A854:  the key word of the 0x3e registration
 *   [0x01..]      func_0206A854:  the 0x3e record itself (g + 4)
 *   [0x1f] +0x7c  func_0206A8FC:  the value of the 0xE registration
 *   [0x25] +0x94  func_0206AA8C:  a packed (value | bits<<16 | flag<<15) word
 *   [0x26] +0x98  func_0206AAB0:  the same, one slot up
 *   [0x28] +0xa0  func_0206AE94:  four bytes unpacked one per out-parameter
 *   [0x38] +0xe0  func_0206A9DC:  a published three-word record
 *   [0x3b] +0xec  func_0206AA0C:  a published three-word record
 *   [0x3f] +0xfc  EVERYWHERE:     the "initialised sub-rigs" bitmask
 */
extern u32 g_02148B4C[];

/* The +0xFC bitmask, one bit per lazily-initialised sub-rig.  Each bit is
 * claimed by exactly one accessor, which tests it, runs the initialiser once
 * and sets it.  Bit 0/1 are the mode pair rather than a lazy init. */
#define RIG_MODE_ON     0x01   /* func_0206A8FC sets, func_0206A854 clears */
#define RIG_MODE_ALT    0x02   /* both of the above clear                  */
#define RIG_INIT_C4C    0x08   /* func_0206AAD4 -> g_02148C4C              */
#define RIG_INIT_D0C    0x10   /* func_0206AD20 -> g_02148D0C              */
#define RIG_INIT_C7C    0x80   /* func_0206ADBC / func_0206ADF4            */
#define RIG_PUBLISHED   0xa4   /* func_0206A9DC / func_0206AA0C clear this */

/* The sub-rig slots, each its own object because each is its own pool word. */
extern u32 g_02148B50[];   /* func_0206A884 / func_0206A8FC: 0x11 record   */
extern u32 g_02148B54[];   /* func_0206A700 / func_0206AD20               */
extern u32 g_02148B98[];   /* func_0206A884 / func_0206AAD4: 0xC record   */
extern u32 g_02148BC8[];   /* func_0206A8FC: base of the 0xE record (+4)  */
extern u32 g_02148C08[];   /* func_0206A8FC: 0xF record AND func_0207B0A4 */
extern u32 g_02148C44[];   /* func_0206A8FC: the 0x2a record              */
extern u32 g_02148C4C[];   /* func_0206AAD4                              */
extern u32 g_02148C7C[];   /* func_0206ADBC                              */
extern u32 g_02148CAC[];   /* func_0206ADF4                              */
extern u32 g_02148D0C[];   /* func_0206AD20                              */

/* The table-registration helper the mode entry points drive.  Nine calls in
 * func_0206A8FC, four in func_0206A884, one in func_0206A854.  (a) is a key,
 * (b) the record's address, (c) its length. */
extern void func_0206DDA4(u32 a, void *b, u32 c);       /* 0x0206DDA4 */

/* Filled by func_0206A8FC into a twelve-byte stack record. */
extern void func_0207B0A4(void *a, void *b);            /* 0x0207B0A4 */

/* The one-time initialisers the lazy accessors guard, and the matrix helper
 * two of them hand their slot pair to. */
extern void func_0207B67C(u32 *a, u32 *b);              /* 0x0207B67C */
extern void func_0206AD64(void);                        /* 0x0206AD64 */

/* The 4x4 fixed-point matrix inverse: Gauss-Jordan with partial pivoting over
 * a 1.19.12 fixed-point 4x4, returning 0 on success and -1 on a singular
 * matrix.  EXACT since wave 10 (src/matched/func_0206AB18.c): (a) is the
 * source MtxFx44, copied into the 0x40-byte stack working copy with
 * MI_Copy64B (0x02082BA0); (b) is the destination, set to identity by
 * MTX_Identity44_ (0x0207BDB4) and accumulated into.  Row normalisation uses
 * FX_InvFx64c (0x0207C788, one argument) and the rounded FX_Mul32x64c inline;
 * elimination is an unrounded (fx64)a * b >> 12.  The last 17 bytes were
 * VARIABLE IDENTITY: the elimination-row loop variable must be the same
 * variable that recorded the pivot row. */
typedef struct { s32 m[4][4]; } MtxFx44;
extern int  func_0206AB18(const MtxFx44 *src, MtxFx44 *dst);  /* 0x0206AB18 */

/* The mode entry points and the publishers. */
extern void func_0206A700(void);    /* build the block                      */
extern void func_0206A884(void);    /* four registrations, mode bit 1       */
extern void func_0206A8FC(void);    /* nine registrations, mode bit 0 on    */
extern void func_0206A854(void);    /* one registration, mode bits 0/1 off  */
extern void func_0206A9DC(void *p); /* publish a 3-word record at [0x38]    */
extern void func_0206AA0C(void *p); /* publish a 3-word record at [0x3b]    */
extern void func_0206AA8C(u32 v, u32 bits, u32 flag);
extern void func_0206AAB0(u32 v, u32 bits, u32 flag);
extern void func_0206AA3C(int idx, int a, int b, int c);
extern void func_0206AA78(int idx, u32 v);
extern void func_0206AE94(u32 *a0, u32 *a1, u32 *a2, u32 *a3);

/* The lazy accessors: each tests its bit, initialises once, returns its slot. */
extern u32 *func_0206AAD4(void);
extern u32 *func_0206AD20(void);
extern u32 *func_0206ADBC(void);
extern u32 *func_0206ADF4(void);

#endif /* CLUSTER_0206A17C_H */
