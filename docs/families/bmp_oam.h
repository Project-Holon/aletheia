/*
 * docs/families/bmp_oam.h -- shared declarations for the bmp_oam.c family
 * (0x02025508..0x02025CD0 in the ARM9 image; edges fuzzy by a function or
 * two at both ends).  The family builds, positions, uploads and tears down
 * a RECTANGULAR GRID OF OAM CELLS that together display one bitmap: the
 * bitmap is cut into 32x16-pixel cells, one hardware sprite per cell, and
 * every operation in the family is the same rows x cols double loop
 * applied to a different per-cell worker in the clact/actor library at
 * 0x0204Axxx-0x0204Bxxx.
 *
 * The __FILE__ anchor is 0x020A7494, loaded as the allocator's fourth
 * argument by func_02025538 (line 0x73) and func_020255A0 (line 0xA3).
 * The two line numbers are monotone in address, the usual second check
 * that this is one original translation unit.
 *
 * REFERENCE DOCUMENT ONLY.  Nothing includes this file; it is not part of
 * any translation unit and match.py never sees it.  Every declaration
 * below is derived from a file in src/matched that is EXACT (or, where
 * said so explicitly, from a byte-correct src/pending file or a
 * size-exact docs/notes source), and the function that evidences each
 * field or parameter is named beside it.
 *
 * ADJUDICATION RULE.  A load or store instruction constrains a field; a
 * name does not.  `ldrsh` with a register offset proves signedness
 * (docs/idioms/ldrsh-register-offset-is-signedness.md); an `ldrh` proves
 * a halfword field where a plain `ldr` plus a shift pair would prove a
 * word narrowed at the use.
 *
 * Addresses are Black-image addresses throughout (docs/AGENT-BRIEF.md
 * section 8).  Nothing here encodes a guess about the White layout.
 */

#ifndef BMP_OAM_H
#define BMP_OAM_H

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

/* ------------------------------------------------------------------ *
 * 1.  struct Grid -- the 0xCC-byte grid object.
 *
 * The size is evidenced twice over: func_020255A0 passes the literal
 * 0xCC to func_02030734, and the two byte fields at +0xCA/+0xCB are the
 * last members every other function in the family reads.  TWO PARALLEL
 * POINTER ARRAYS, not an array of structs: the constructor's cell cursor
 * advances by FOUR bytes per cell (`lsls r1, r7, #2`) and reaches both
 * arrays off the same register (`str r0, [r6, #4]` and
 * `str r0, [r6, #0x68]`), which is what fixes 0x68 - 0x04 = 0x64 bytes,
 * i.e. 25 pointers, as the first array's extent.
 * ------------------------------------------------------------------ */
struct Grid {
    void *bmp;       /* +0x000  func_020255A0 stores param->bmp here and
                      *         func_020257D0 reads it back as the source
                      *         bitmap for every upload. */
    void *act[25];   /* +0x004  one clact actor per cell, created by
                      *         func_0204B294.  Walked by func_02025774,
                      *         func_0202597C, func_020259C4,
                      *         func_02025A0C, func_02025A54 and
                      *         func_0202590C, all with the SAME index
                      *         expression `(i * cols + j) * 4 + 4`.
                      *         25 and not 24: +0x68 is where the second
                      *         array starts, and the constructor's own
                      *         store at [r6,#0x64] (the f14 word below)
                      *         lands inside this array's tail, so the
                      *         last slot is never a cell.  See the note
                      *         on +0x64. */
    void *res[24];   /* +0x068  one resource handle per cell, from
                      *         func_0204A7A0.  Released by func_0202570C
                      *         through func_0204A8D4 while act[] is
                      *         released through func_0204B3B4. */
    u16   flags;     /* +0x0C8  passed as func_0204B404's third argument
                      *         by func_0202590C, which is what makes it
                      *         a halfword; func_020255A0 seeds it from
                      *         param->f12. */
    u8    cols;      /* +0x0CA  cells across.  Every loop in the family
                      *         reads it with `ldrb`, so it is a byte;
                      *         func_020255A0 computes it as
                      *         width/32 rounded up. */
    u8    rows;      /* +0x0CB  cells down, height/16 rounded up. */
};

/* NOTE on +0x64.  func_020255A0 stores param->f14 (the actor-system
 * handle it also passes to func_0204A7A0 and func_02025A9C) at
 * `[g + 0x64]`, which is act[24] by the layout above.  func_020257D0
 * reads +0x64 as its ENGINE SELECTOR, not as a cell pointer, and its own
 * struct spelling (src/matched/func_020257D0.c) declares the word at
 * +0x64 separately from the cell array for exactly this reason.  The two
 * spellings are the same object: the grid never has 25 live cells (24 is
 * 0x18, the descriptor-size constant the family's sibling at
 * func_02025538 allocates), so the 25th slot is repurposed.  Recorded
 * here so a reader does not take the two sources for two structs.
 *
 * func_020257D0.c calls the same object `struct Obj` with the pointer
 * array split into `u32 cell[24]` at +0x68 and a separate `engine` word
 * at +0x64; func_0202570C.c calls it `struct Grid` with `a[25]`/`b[24]`.
 * Both are byte-exact against their own ranges; the union is above.
 */

/* ------------------------------------------------------------------ *
 * 2.  struct Param -- the 0x18-byte creation record.
 * Read only by func_020255A0 (docs/notes/pkt_020255A0.c.txt, size-exact
 * at 364/364, 16 bytes out), which is where every offset below comes
 * from.  The two signed coordinate loads are `movs r0,#4 / ldrsh r1,[r4,r0]`
 * and `movs r0,#6 / ldrsh r1,[r4,r0]`: the register-offset ldrsh is the
 * only encoding that exists, and it is what proves x and y are s16.
 * ------------------------------------------------------------------ */
struct Param {
    void *bmp;   /* +0x00  the source bitmap; a struct Bmp * in the
                  *        bmp.c sense (docs/families/bmp.h), since
                  *        func_020437DC and func_020437E4 take it. */
    s16   x;     /* +0x04  base pixel x, `ldrsh` with a register offset */
    s16   y;     /* +0x06  base pixel y, likewise                       */
    u32   f8;    /* +0x08  func_0204B294's third argument (`ldr r2,[r4,#8]`) */
    u32   fc;    /* +0x0c  narrowed to a byte for func_0204B6F4's second
                  *        argument (`ldr` then `lsls #0x18 / lsrs #0x18`,
                  *        which is a WORD field narrowed at the use, not
                  *        a byte field -- an `ldrb` would be shorter) */
    u8    f10;   /* +0x10  -> point +6, plain `ldrb`  */
    u8    f11;   /* +0x11  -> point +7, plain `ldrb`  */
    u16   f12;   /* +0x12  -> grid->flags and func_0204B294's sixth
                  *        argument; `ldrh` at both sites */
    u32   f14;   /* +0x14  the actor-system handle; passed to
                  *        func_0204A7A0, func_02025A9C and stored at
                  *        grid +0x64 */
};

/* ------------------------------------------------------------------ *
 * 3.  struct Sys -- the module/system object, the family's first
 * argument almost everywhere.  Only four things are ever touched.
 * ------------------------------------------------------------------ */
struct Sys {
    u32 f0;       /* +0x00  func_0204B294's first argument (the owner);
                   *        func_02025588 frees the object itself */
    u16 f4;       /* +0x04  the HEAP ID.  `ldrh r0,[r5,#4]` in
                   *        func_02025538 and again in func_020255A0
                   *        where it is the allocator's first argument,
                   *        which is what makes it a halfword rather than
                   *        a word */
    u16 f6;       /* +0x06  padding/unused in this family              */
    u32 f8;       /* +0x08  the 2-D ENGINE SELECTOR: 0 picks the main
                   *        engine.  func_020255A0 caches it and hands it
                   *        to func_02025A9C; func_020257D0 reads the
                   *        same selector off its own object at +0x64 */
    u32 slot[3];  /* +0x0c  three VRAM/palette slot cursors, seeded with
                   *        -1 by func_02025538 (a three-iteration loop
                   *        storing 0xFFFFFFFF at +0xc, +0x10, +0x14) and
                   *        released back by func_02025B18, which is the
                   *        matching three-iteration loop that skips the
                   *        -1 entries.  func_02025A9C fills slot[mode]
                   *        lazily; func_020255A0 reads slot[mode] as
                   *        func_0204B294's fourth argument. */
};

/* ------------------------------------------------------------------ *
 * 4.  struct Point -- the 8-byte packed placement record passed by
 * address to func_0204B404 and func_0204B294.  Two s16 coordinates and
 * two bytes; func_020255A0 zeroes it with FOUR halfword stores through
 * one pointer (`strh r0,[r1]` .. `strh r0,[r1,#6]`), which is why the
 * spelling that reproduces the prologue is a u16 cursor over the object
 * rather than four member assignments -- member assignments to f6/f7
 * emit two `strb` and lose four bytes.
 * ------------------------------------------------------------------ */
struct Point {
    s16 x;   /* +0x00  base x plus (column << 5): cells are 32 px wide  */
    s16 y;   /* +0x02  base y plus (row    << 4): cells are 16 px tall  */
    u16 f4;  /* +0x04  zeroed and never written again in this family    */
    u8  f6;  /* +0x06  from param->f10                                  */
    u8  f7;  /* +0x07  from param->f11                                  */
};

/* The 32x16 cell geometry is evidenced independently three times:
 *   func_020255A0  cols = width  / 32 rounded up, rows = height / 16
 *                  rounded up (`lsrs #5` / `lsrs #4` with a signed
 *                  remainder test spelled as the rors quartet);
 *   func_0202590C  x steps by `j << 5`, y by `i << 4`;
 *   func_020257D0  a full cell row is 0x80 bytes = 32 x 16 / 8 * 2 at
 *                  4bpp, and the partial last column uploads
 *                  ((w % 32) / 8) * 32.
 * So the cell is 32 px across and 16 px down in every reading. */

/* ------------------------------------------------------------------ *
 * 5.  gModeTable -- the 0x0209F87C mode table.
 *
 * THREE 12-BYTE RECORDS at 0x0209F87C, 0x0209F888 and 0x0209F894, each
 * {0x130, a, b} with (a,b) = (0,1), (3,4), (6,7).  The base is
 * 0x0209F87C and NOT 0x0209F880: func_020255A0's pool word is
 * 0x0209F87C and it indexes `[r0, mode*12]` to read the first member,
 * while func_02025A9C's two pool words 0x0209F880 and 0x0209F884 are
 * base+4 and base+8 of the SAME symbol (the pool-base-for-a-far-field
 * idiom).  Declaring the table at 0x0209F880 with a
 * {a, b, c} record compiles to the same bytes but splits one object into
 * two and downgrades both of func_02025A9C's relocation sites from
 * `literal` (witnessed by func_020255A0's own pool word at 0x02025708,
 * outside the range) to `sole-ref`.  The 0x0209F87C spelling is
 * therefore the one to use.
 * ------------------------------------------------------------------ */
struct ModeEntry {
    u32 size;  /* +0x00  0x130 in all three records; func_020255A0 passes
                *        it as func_0204A7A0's first argument */
    u32 a;     /* +0x04  func_0204AF28's second argument (func_02025A9C) */
    u32 b;     /* +0x08  func_0204AF28's third  argument (func_02025A9C) */
};
extern const struct ModeEntry gModeTable[3];   /* 0x0209F87C data */

/* ------------------------------------------------------------------ *
 * 6.  The 0x0209FA34 record table -- 19 entries, 12-byte stride.
 * A completely separate table from gModeTable, shared by the family's
 * four lookup functions.  Only three of its twelve bytes are ever read,
 * and each reader declares its own byte offset as its own extern, which
 * is why four addresses two bytes apart appear in the symbols blocks:
 *   +0x00  the key   (u8)   -- func_02025B3C, func_02025B64
 *   +0x02  a u16 id        -- func_02025BA0
 *   +0x04  a u32 value     -- func_02025C44 via 0x0209FA38
 *   +0x08  a u8  value     -- func_02025C44 via 0x0209FA3C
 *   +0x09  a u8  value     -- func_02025B64 via 0x0209FA3D
 * Spelling any of these as an offset off the 0x0209FA34 symbol changes
 * the pointer arithmetic mwccarm emits and stops reproducing the bytes,
 * so they stay separate declarations (src/pending/sub_02025BA0.c's
 * header records the experiment).
 * ------------------------------------------------------------------ */
extern const u8  g_0209FA34[];   /* 0x0209FA34 data, the key column   */
extern const u16 g_0209FA36[];   /* 0x0209FA36 data, the id column    */
extern const u8  g_0209FA38[];   /* 0x0209FA38 data, the u32 column   */
extern const u8  g_0209FA3C[];   /* 0x0209FA3C data, the u8  column   */
extern const u8  g_0209FA3D[];   /* 0x0209FA3D data, the second u8    */

/* ------------------------------------------------------------------ *
 * 7.  Lifetime: the constructor/destructor pair.
 * ------------------------------------------------------------------ */

/* 0x020255A0  docs/notes/pkt_020255A0.c.txt -- size-exact 364/364, 8
 * concrete bytes out since wave 13 (the width call reads g->bmp, the
 * field just stored), all 12 relocations RESOLVED.  Allocates the
 * 0xCC-byte grid, derives cols and rows from the bitmap's pixel extents
 * (rounding each up), then for every cell creates a resource through
 * func_0204A7A0 and an actor through func_0204B294, sets the actor's
 * byte field through func_0204B6F4 and clears it through
 * func_0204BA20.  The two loop counters are u8 (each iteration ends with
 * the `lsls #0x18 / lsrs #0x18` truncation pair), and so are cols and
 * rows. */
struct Grid *func_020255A0(struct Sys *sys, struct Param *param);

/* 0x0202570C  EXACT*, src/matched/func_0202570C.c.  The mirror image:
 * for every cell, release res[] through func_0204A8D4 and act[] through
 * func_0204B3B4, then free the grid.  Counters are u8 here too. */
void func_0202570C(struct Grid *g);

/* ------------------------------------------------------------------ *
 * 8.  The per-cell forwarders.  Six functions, one shape.  Each is the
 * rows x cols double loop with a single call in the body and NOTHING
 * else, which is why they are byte-identical apart from the callee and
 * are kept in separate files (each then gives the others' call sites a
 * `matched` witness).  The two byte extents are re-read from memory on
 * every iteration rather than cached in a register
 * (docs/idioms/keeping-a-cursor-in-a-named-local-costs-a-callee-saved-
 * register.md): caching either one costs a push/pop pair.
 *
 * The counter type is the one thing that differs and it is byte-evidenced
 * per function: func_02025774 uses u8 counters, func_0202597C,
 * func_020259C4, func_02025A0C and func_02025A54 use int.
 * ------------------------------------------------------------------ */
void func_02025774(struct Grid *g, u32 a);  /* EXACT, -> func_0204B3DC */
void func_0202597C(struct Grid *g, u32 a);  /* EXACT, -> func_0204B688 */
void func_020259C4(struct Grid *g, u32 a);  /* EXACT, -> func_0204B800 */
void func_02025A0C(struct Grid *g, u32 a);  /* EXACT, -> func_0204B84C */
void func_02025A54(struct Grid *g, u32 a);  /* EXACT, -> func_0204B6F4,
                                             * with a literal 0 third
                                             * argument */

/* 0x0202590C  EXACT*, src/matched/func_0202590C.c.  The reposition pass:
 * the same double loop, but it builds a struct Point per cell first.
 * The x/y parameters are s16 and NOT int -- only the narrow parameter
 * type puts the two spills ahead of the object copy in the prologue. */
void func_0202590C(struct Grid *g, s16 x, s16 y);

/* 0x020257D0  EXACT, src/matched/func_020257D0.c.  The VRAM upload.
 * Not a plain forwarder: it walks cell rows, picks GX_LoadOBJ or
 * GXS_LoadOBJ once from the engine selector and reaches the chosen
 * pointer through `blx r3` for every transfer.  A full cell row is 0x80
 * bytes and only the last column of the last row uploads the partial
 * remainder. */
void func_020257D0(struct Grid *g);

/* ------------------------------------------------------------------ *
 * 9.  The 0x18-byte sibling descriptor (func_02025538's object).  A
 * SEPARATE, smaller object from struct Grid: same +0x4 halfword heap id
 * and the same three-slot cursor array, but no cell arrays.  It is the
 * per-Sys record the grid family hangs off, which is why func_02025B18's
 * slot loop and func_02025538's seeding loop both run over exactly three
 * entries at +0xc.
 * ------------------------------------------------------------------ */

/* 0x02025538  EXACT, src/matched/func_02025538.c.  Allocates the 0x18
 * bytes (file 0x020A7494, line 0x73), records a1 at +0, the halfword a0
 * at +4, seeds slot[0..2] with -1 and stores
 * func_020490F4(0x33, (a0 & 0x7FFF) | 0x8000) at +8. */
void *func_02025538(u32 a0, u32 a1);

/* 0x02025588  EXACT, src/matched/func_02025588.c.  Releases +8 through
 * func_02049238, runs func_02025B18's slot loop, frees the object. */
void func_02025588(void *p);

/* 0x02025B18  EXACT*, src/matched/sub_02025B18.c.  Releases each slot
 * that is not -1 through sub_0204AFD8 and re-seeds it with -1.  This is
 * the exact inverse of func_02025538's seeding loop, which is the
 * evidence that the three words at +0xc are one array and not three
 * unrelated fields. */
void func_02025B18(void *p);

/* 0x02025A9C  EXACT since wave 13, src/matched/func_02025A9C.c: the
 * 0x00200010 arm sets mode = 0 itself and is written FIRST (supersedes
 * the "empty arm" reading below).  Was: docs/notes/pkt_02025A9C.c.txt --
 * size-exact 124/124, 2
 * concrete bytes out, all 3 relocations RESOLVED once gModeTable is
 * declared at 0x0209F87C (section 5).  Reads the requested engine's
 * DISPCNT (0x04000000 or 0x04001000), masks it with 0x00300010 and maps
 * the result to a slot index 0/1/2; then, lazily, fills slot[mode]
 * through func_0204AF28 and returns mode either way.  The 0x00200010
 * case is a real EMPTY arm that must be written before `default:`. */
u32 func_02025A9C(struct Sys *sys, u32 engine, u32 arg);

/* ------------------------------------------------------------------ *
 * 10.  The lookup group over the 0x0209FA34 table.
 * ------------------------------------------------------------------ */

/* 0x02025B3C  EXACT, src/matched/sub_02025B3C.c.  Linear search over the
 * 19 keys; returns the matching INDEX, or 0 (not -1) when nothing
 * matches, so a caller cannot tell "matched slot 0" from "no match". */
u32 func_02025B3C(u32 key);

/* 0x02025B64  MATCH, src/pending/func_02025B64.c.  The same search, but
 * it returns the +0x09 byte of the matching record instead of the index,
 * and 0 on no match.  Byte-correct; capped at MATCH because 0x0209FA3D
 * has no witness outside 0x02025B64..0x02025B94 -- it is interior to the
 * table object, so sole-ref/data refuses it, and the only pool word
 * naming it image-wide is this function's own. */
u8 func_02025B64(u32 v);

/* 0x02025BA0  MATCH*, src/pending/sub_02025BA0.c.  Bounds-checked read
 * of the +0x02 halfword column; out of range returns the sentinel 0xE7.
 * Same blocker as func_02025B64 at 0x0209FA36, and additionally EXACT*
 * -- the listing's extent runs to 76 bytes because the 24-byte function
 * is followed by unlabelled filler and pool.  NOTE: the source recorded
 * in docs/notes/pkt_02025BA0.c.txt is the same 24-byte function and
 * reports DIFF only because the note's re-verification compares it
 * against that 76-byte extent; src/pending/sub_02025BA0.c is the
 * byte-correct file. */
u32 func_02025BA0(u32 idx);

/* 0x02025B94  EXACT, src/matched/sub_02025B94.c.  The two-stage lookup
 * func_02025B3C then func_02025BA0, the first result flowing straight
 * into the second call's argument register. */
u32 func_02025B94(u32 a);

/* 0x02025C44  EXACT, src/matched/func_02025C44.c.  Looks the key up with
 * func_02025B3C and, on a non-zero index, writes the +0x04 word and the
 * +0x08 byte of the record out through the two pointer arguments. */
int func_02025C44(u32 key, u32 *out_word, u32 *out_byte);

/* 0x02025BEC  EXACT (as a unit), src/matched/unit_02025BEC.c.  A
 * three-argument predicate over func_02025B64's column, plus the two
 * wrappers sub_02025C1C and sub_02025C30 that return their first or
 * second argument on success and 0 on failure. */
u32 func_02025BEC(u32 a, u32 b, u32 c);
u32 sub_02025C1C(u32 a, u32 b, u32 c);
u32 sub_02025C30(u32 a, u32 b, u32 c);

/* ------------------------------------------------------------------ *
 * 11.  Externals the family depends on, with the evidence for each.
 * Everything at 0x0204Axxx/0x0204Bxxx is the clact/actor library
 * (docs/families/clact.h); everything at 0x0204Dxxx and below is the
 * general runtime.
 * ------------------------------------------------------------------ */
extern const u8 bmp_oam_File[];   /* 0x020A7494 data, the __FILE__ anchor;
                                   * func_02025538 line 0x73 and
                                   * func_020255A0 line 0xA3 */

extern void *func_02030734(u32 heap, u32 size, u32 clear,
                           const u8 *file, u32 line);  /* 0x02030734 arm */
extern void  func_020307B0(void *p);                   /* 0x020307B0 arm */

/* bmp.c accessors, docs/families/bmp.h.  Both hand back the extent in
 * PIXELS, which is why func_020255A0 divides by 32 and 16 rather than by
 * a tile count. */
extern u32   func_020437DC(void *bmp);   /* 0x020437DC arm, width  */
extern u32   func_020437E4(void *bmp);   /* 0x020437E4 arm, height */
extern void *func_020437D4(void *bmp);   /* 0x020437D4 arm, pixels */
extern u32   func_020437EC(void *bmp);   /* 0x020437EC arm, byte size */

/* clact/actor library. */
extern void *func_0204A7A0(u32 size, u32 sysHandle, u32 heap);
                                         /* 0x0204A7A0 arm, returns s32 in
                                          * docs/notes/func_0204A7A0.c.txt;
                                          * func_020255A0 stores the result
                                          * as a pointer */
extern void  func_0204A8D4(void *res);   /* 0x0204A8D4 arm, the inverse  */
extern void *func_0204ABBC(u32 cell, u32 engine);  /* 0x0204ABBC arm      */
extern void  func_0204ADA4(u32 a);       /* 0x0204ADA4 arm               */
extern void  sub_0204AFD8(u32 slot);     /* 0x0204AFD8 arm               */
extern void *func_0204AF28(u32 arg, u32 a, u32 b, u16 w);  /* 0x0204AF28 arm */
extern void *func_0204B294(u32 owner, void *res, u32 c, u32 slot,
                           struct Point *pt, u16 f12, u16 heap);
                                         /* 0x0204B294 arm, seven
                                          * arguments: three go on the
                                          * stack, which is what fixes the
                                          * two trailing halfwords (both
                                          * `ldrh`).  src/matched/
                                          * sub_0204B294.c is the callee. */
extern void  func_0204B3B4(void *act);   /* 0x0204B3B4 arm, destroy      */
extern void  func_0204B3DC(void *act, u32 a);              /* 0x0204B3DC */
extern void  func_0204B404(void *act, struct Point *pt, u16 flags);
                                                           /* 0x0204B404 */
extern void  sub_0204B454(void *act, struct Point *out, u32 space);
                                                           /* 0x0204B454 */
extern void  func_0204B688(void *act, u32 a);              /* 0x0204B688 */
extern void  func_0204B6F4(void *act, u32 v, u32 b);       /* 0x0204B6F4 */
extern void  func_0204B800(void *act, u32 a);              /* 0x0204B800 */
extern void  func_0204B84C(void *act, u32 a);              /* 0x0204B84C */
extern void  func_0204BA20(void *act, u32 v);              /* 0x0204BA20 */

extern void  GX_LoadOBJ(void *src, u32 off, u32 n);   /* 0x0207E780 arm */
extern void  GXS_LoadOBJ(void *src, u32 off, u32 n);  /* 0x0207E804 arm */
extern void  func_020862F0(void *p, u32 n);           /* 0x020862F0 arm */

#endif /* BMP_OAM_H */
