/*
 * docs/families/billboard.h -- shared declarations for the billboard.c family.
 *
 * REFERENCE DOCUMENT ONLY.  Nothing includes this file; it is not part of any
 * translation unit and `match.py` never sees it.  It is the adjudicated union
 * of the declarations the family's byte-exact sources already carry, written
 * down once so a new attempt on an open function starts from the settled shape
 * instead of re-deriving it.
 *
 * Family: original source file **billboard.c**, 0x0204EBD4..0x0204F7DC in the
 * ARM9 image (edges fuzzy by a function or two).  The file name is not a
 * guess: src/matched/func_0204EBD4.c resolves the __FILE__ pool word of the
 * constructor's three func_02030734 calls to 0x020A7FA4, and the bytes there
 * spell "billboard.c"; its start is pinned by the NUL terminator of
 * "battle_disp.c" at 0x020A7FA3.  The three allocation line numbers, 153 /
 * 159 / 161, are monotone in address, the second independent check that this
 * is one original translation unit.  The next anchor down, 0x020A7FB0 =
 * "billboard_act.c", bounds the family from below.
 *
 * Sibling family: **billboard_act.c**, 0x0204FE94..0x02050B80, anchor
 * 0x020A7FB0, documented in docs/families/billboard_act.h.  That file is the
 * ACTOR layer OVER this one: it builds a billboard.c board (func_0204EBD4) as
 * its sub-object at +4 and calls into this family for every graphics
 * primitive.  billboard_act.h's "billboard.c interface" section is the
 * caller's view of the prototypes below; where the two disagree, this file
 * wins, because its prototypes come from the callee's own matched source.
 *
 * Derived from the 38 matched sources found with
 *   grep -l "address:  0x0204E[B-F]\|address:  0x0204F[0-7]" src/matched/*.c
 *
 * ADJUDICATION RULE USED THROUGHOUT.  A load or store instruction constrains a
 * field; a name does not.  `ldrsb`/`ldrsh` prove signedness (there is no
 * immediate-offset form, docs/idioms/ldrsh-register-offset-is-signedness.md);
 * a shift pair of unequal amounts proves a bitfield's width and position; an
 * `asr` where a `lsr` would do proves the shifted value is signed.  Where two
 * matched files disagree, the file whose code actually constrains the field
 * wins and the losing spelling is recorded beside it as `WAS:`.
 */

#ifndef BILLBOARD_H
#define BILLBOARD_H

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

/* ------------------------------------------------------------------ */
/* THE FILE NAME.  Declared as an extern array pinned by address, never  */
/* as a literal __FILE__ (docs/idioms/file-string-is-an-abs32-into-the-  */
/* string-area.md).  Evidenced by src/matched/func_0204EBD4.c.          */
/* ------------------------------------------------------------------ */

extern const char sBillboard[];             /* 0x020A7FA4  "billboard.c" */

/* The 28-byte parameter blob the caller hands the constructor.  It must be a
 * 4-ALIGNED AGGREGATE (seven u32 words): mwcc expands the assignment to a
 * 16-byte ldm/stm pair with write-back plus a 12-byte pair without, reusing
 * the bases the write-back left behind
 * (docs/idioms/aggregate-assignment-is-ldm-stm.md).  A byte array compiles to
 * a copy loop instead.  Evidenced by src/matched/func_0204EBD4.c, and by the
 * identical expansion on the actor side in func_0204FE94.c.
 */
struct Blob28 { u32 w[7]; };
struct Blk3   { u32 w[3]; };                /* the 12-byte record of func_0204ED70 */

/* ------------------------------------------------------------------ */
/* STRUCT LAYOUTS                                                       */
/* ------------------------------------------------------------------ */

/* The board.  0x3c bytes, allocated at billboard.c line 153.  Two arrays hang
 * off it, and THEY ARE NOT THE SAME ARRAY -- this is the single fact a new
 * attempt in this family most often gets wrong:
 *
 *   +0x04  ptr0 -> an array of 0x28-byte SLOT records, count0 at +0x0c
 *   +0x08  ptr1 -> an array of 0x1c-byte ELEM records, count1 at +0x0e
 *
 * The 0x28 array is what func_0204EE0C scans, what the func_0204F150 /
 * func_0204F1A0 / func_0204F214 teardowns walk and what func_0204EEC8 fills.
 * The 0x1c array is what func_0204F428 allocates from and what func_0204F5A8
 * and func_0204F720 flip bits in.  Every offset below is constrained by a
 * load or a store in a matched source; the evidencing function is named per
 * field.
 */
struct Board {
    u16 id;                 /* 0x00  heap id, narrowed to u16   func_0204EBD4 */
    u16 pad0;               /* 0x02  (padding; never touched)                 */
    struct Slot *ptr0;      /* 0x04  0x28-byte slot array       func_0204EBD4 line 159 */
    struct Elem *ptr1;      /* 0x08  0x1c-byte elem array       func_0204EBD4 line 161 */
    u16 count0;             /* 0x0c  slot count                 func_0204EBD4, func_0204F27C */
    u16 count1;             /* 0x0e  elem count                 func_0204F428 */
    u8  blob[0x18];         /* 0x10  the 28-byte blob lands at +0x0c..+0x27   */
    u32 a28;                /* 0x28  look-at mode, 0 = G3_LookAt   func_0204EBD4, func_0204F7DC */
    u32 a2c;                /* 0x2c  1 = use b30..b34 as the normal  func_0204ED4C, func_0204F7DC */
    s16 b30;                /* 0x30  fixed normal x (fx16)      func_0204ED4C */
    s16 b32;                /* 0x32                             func_0204ED4C */
    s16 b34;                /* 0x34                             func_0204ED4C */
    s16 b36;                /* 0x36  S offset, ldrsh            func_0204F7DC  WAS: u16 (func_0204EDC4 only stores it) */
    s16 b38;                /* 0x38  T offset, ldrsh            func_0204F7DC  WAS: u16 */
};

/* func_0204F7DC's reading of the blob area (+0x10..+0x27), all EXACT-proved:
 *   +0x10 fx32 scale (G3_Scale x3, FX_Div denominator), +0x1c/+0x1e u16
 *   diffuse/ambient, +0x20/+0x22 u16 specular/emission, +0x24 u8 polygon-id
 *   base, +0x25 u8 quad-shape index into the {y0,y1,x0,x1} fx16 table at
 *   0x020A1514.  Evidenced by src/matched/func_0204F7DC.c.
 */

/* NOTE on count0.  It is a u16 but func_0204F27C's loop compares SIGNED
 * (`blt` on the back edge), so the loop counter is a plain `s32` and count0 is
 * promoted to int at the compare -- NOT an unsigned compare against a u16.
 * The same is true of count1 in func_0204F428, where the image is
 * `ldrh sb, [r4, #0xe]` followed by a signed `ble`; declaring the field s16
 * gives `ldrsh` and is one byte wrong.  Evidenced by src/matched/func_0204F27C.c
 * and docs/notes/pkt_0204F428.c.txt.
 *
 * NOTE on the re-read.  Board.ptr0 is re-loaded from the board at EVERY access
 * rather than bound to a pointer local, because the release callbacks may
 * change it.  Binding it costs a callee-saved register and loses the reloads.
 * Evidenced by src/matched/func_0204F150.c and func_0204F1A0.c.
 */

/* NOTE on the Elem +0x18 bitfield NAMES (func_0204F7DC reads all six):
 * alpha:5 (POLYGON_ATTR alpha), polyId:4 (added to Board +0x24 for the
 * polygon id), visible:1 (bit 9; func_0204F720 flips it), flipS:1, flipT:1,
 * light:4 (light mask; nonzero sends the normal, zero sends G3_Color(0x7FFF)).
 * func_0204F428 writes them as plain bitfield assignments, in the order
 * alpha, polyId, visible, light, flipS, flipT.
 */

/* The 0x28-byte SLOT record, the element of Board.ptr0. */
struct Slot {
    u32 f00;                /* payload handle; 0 = empty     func_0204EE0C, func_0204F150 */
    u16 f04;                /* 1 << (bank + 3)               func_0204EEC8 */
    u16 f06;                /* 1 << (sub  + 3)               func_0204EEC8 */
    u8  f08;                /* divisor byte                  func_0204EEC8, func_0204F344 */
    u8  f09;                /* second divisor byte           func_0204EEC8, func_0204F344 */
    u8  f0a;                /* f04 / f08                     func_0204EEC8 */
    u8  f0b;                /* f06 / f09                     func_0204EEC8 */
    u32 f0c;                /* (u16)f20 << 3; texture VRAM address   func_0204F044, func_0204F7DC */
    u32 f10;                /* (u16)f24 << 3; palette address        func_0204F044, func_0204F7DC */
    u32 f14;                /* state word; 5 = free; GXTexFmt when live  func_0204EE0C, func_0204F7DC */
    u32 f18;                /* GXTexSizeS                    func_0204EEC8, func_0204F7DC */
    u32 f1c;                /* GXTexSizeT                    func_0204EEC8, func_0204F7DC */
    u32 f20;                /*                               func_0204F044, func_0204F2E4 */
    u32 f24;                /*                               func_0204F044 */
};

/* NOTE on the free test.  func_0204EE0C's scan wants BOTH `f00 == 0` and
 * `f14 == 5`; the teardowns stamp 5 into f14 whether or not the release ran.
 * Evidenced by src/matched/func_0204EE0C.c, func_0204F150.c, func_0204F214.c.
 *
 * NOTE on the stride.  0x28 is not a power of two, so mwccarm emits a real
 * `mul` against a live register, never a shift.  Two spellings exist and they
 * are NOT interchangeable:
 *
 *   `&board->ptr0[idx]`                 -> `mov rN, #0x28` + `mla`
 *   `(u8 *)board->ptr0 + idx * 0x28`    -> `mul` + `add`
 *
 * The subscript form is what func_0204EF58 / func_0204EFC8 / func_0204F044
 * have; the byte-offset form is what func_0204F150 / func_0204F1A0 /
 * func_0204F214 have.  Copy the form from the function whose shape you are
 * reproducing; swapping them is four bytes and a whole register file.
 */

/* The 0x1c-byte ELEM record, the element of Board.ptr1.  The 14/2 bit split at
 * +0x00 and the 9/1/6 split at +0x18 are proved by the lsl/lsr pairs, which no
 * mask spelling reproduces
 * (docs/idioms/shift-pair-with-no-matching-type-is-a-bitfield.md).  Evidenced
 * by src/matched/func_0204F5A8.c and func_0204F720.c; the same 14-bit field
 * appears on the actor side in func_02050550.c.
 */
struct Vec3 { s32 a, b, c; };

struct Elem {               /* 0x1c bytes */
    u16 id  : 14;           /* 0x00  0x3FFF = free sentinel  func_0204F5A8, func_0204F428 */
    u16 mode : 2;           /* 0x00  bits 14-15              func_0204F428 */
    u16 f02;
    struct Vec3 f04;        /* 0x04  copied whole from the caller  func_0204F428 */
    u16 f10;                /* 0x10  texture cell index      func_0204F428, func_0204F7DC */
    u16 f12;                /* 0x12  scale x, READ ldrsh     func_0204F428, func_0204F684, func_0204F7DC */
    u16 f14;                /* 0x14  scale y, READ ldrsh     func_0204F428, func_0204F684, func_0204F7DC */
    u16 f16;                /* 0x16  Z rotation index        func_0204F428, func_0204F7DC */
    u16 f18;                /* 0x18  packed flags, see below func_0204F428, func_0204F720 */
    u16 f1a;
};

/* The +0x18 halfword of Elem, as func_0204F720 constrains it: bit 9 is a
 * 1-BIT BITFIELD assigned 1/0 in each arm, not a read-modify-write of the
 * whole halfword (both arms are conditional instructions and there is no
 * narrowing shift pair).  func_0204F428 writes the same halfword as six
 * separate read-modify-writes, in this order and no other:
 *   & ~0x1f | (k & 0x1f)   the 5-bit field from the 6th stacked parameter
 *   & ~0x1e0
 *   & ~0x200               (bit 9, the one func_0204F720 flips)
 *   & ~0xf000 | (w << 28) >> 16
 *   & ~0x400
 *   & ~0x800
 * Folding any two of them together changes the size.  Evidenced by
 * docs/notes/pkt_0204F428.c.txt.
 */

/* ------------------------------------------------------------------ */
/* THE TEXTURE TABLES                                                   */
/* ------------------------------------------------------------------ */

/* func_0204EEC8's three pool words.  gTexSizeTbl is a u32 array indexed by the
 * caller's index and scaled `lsl #2`; the other two are read at an 8-BYTE
 * STRIDE (`ldr ip, [r8, ip, lsl #3]`), and 0x020A14D8 is exactly 0x020A14D4 + 4,
 * so the two symbols are the two words of one 8-byte record type.
 *
 * EVIDENCE CEILING, and it is structural: layout/data_objects.txt registers
 * only 0x020A14C0 as an object start (row 516); 0x020A14D4 and 0x020A14D8 are
 * INTERIOR to it, and sole-ref/data refuses an address merely interior to a
 * labelled object.  The only pool words naming them image-wide are the two
 * inside func_0204EEC8 itself, so `literal` and `label` refuse them too.
 * func_0204EEC8 therefore caps at MATCH however byte-correct the C becomes.
 * (0x020A14C0 DOES resolve, as sole-ref/data.)
 */
struct Pair8 { u32 w; u32 pad; };           /* the 8-byte record stride */

extern const u32 gTexSizeTbl[];             /* 0x020A14C0, align 4 */
extern const struct Pair8 gTexParamS[];     /* 0x020A14D4, align 4, bank table */
extern const struct Pair8 gTexParamT[];     /* 0x020A14D8, align 4, sub  table */

/* The two release callbacks, installed at run time, called through the
 * pointer.  Evidenced by src/matched/func_0204F1A0.c and func_0204F214.c.
 */
typedef void (*BillboardRelease)(u32 handle);

extern BillboardRelease g_020A8144;
extern BillboardRelease g_020A814C;

/* ------------------------------------------------------------------ */
/* PROTOTYPES -- billboard.c's own functions                            */
/* ------------------------------------------------------------------ */

/* construction / destruction */
void *func_0204EBD4(u8 *src28, void *heap);                       /* EXACT  */
void  func_0204ED24(void *board);                                 /* EXACT* */

/* board field setters (all leaf, none saves lr, so disasm.py does not label
 * them -- docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md) */
void  func_0204ED4C(u8 *board, s16 *src3);                        /* EXACT  */
void  func_0204ED70(u8 *board, struct Blk3 *src);                 /* EXACT  */
void  func_0204ED80(u8 *board, u16 *src);                         /* EXACT  */
void  func_0204ED8C(u8 *board, u16 *src);                         /* EXACT  */
void  func_0204ED98(u8 *board, u16 *src);                         /* EXACT  */
void  func_0204EDA4(u8 *board, u16 *src);                         /* EXACT  */
void  func_0204EDB0(u8 *board, u8 *src);                          /* EXACT  */
void  func_0204EDBC(u8 *board, u8 val);                           /* EXACT, by VALUE,
                                                                   * not by pointer */
void  func_0204EDC4(u8 *board, u16 a, u16 b);                     /* EXACT  */
void  func_0204EDD0(s32 flags, u16 *outBank, u16 *outSub);        /* EXACT  */

/* slot allocation and fill */
int   func_0204EE0C(struct Board *b, u32 *outIdx);                /* EXACT  */
void  func_0204EE64(struct Slot *s, u32 heapId);                  /* EXACT  */
void  func_0204EEC8(struct Slot *s, u32 idx, s32 fmt,
                    u32 divisor, u8 c);                           /* DIFF, 58 bytes, all 5
                                                                   * relocations resolve
                                                                   * (sole-ref); see
                                                                   * docs/notes/pkt_0204EEC8.c.txt */
u32   func_0204EF58(struct Board *b, u32 a1, u32 a2, u32 a3,
                    u8 a4, u8 a5);                                /* EXACT  */
u32   func_0204EFC8(struct Board *b, u32 a1, u32 a2, u32 a3,
                    u32 a4, u8 a5, u8 a6);                        /* EXACT  */
int   func_0204F044(struct Board *b, int w, int h, int a3,
                    u32 a4, u8 a5, u8 a6);                        /* EXACT; the size fields
                                                                   * are `(u32)(f20 << 16) >> 13`,
                                                                   * NOT `(u32)(u16)f20 << 3` */

/* slot teardown */
void  func_0204F10C(void *board, u32 idx);                        /* EXACT  */
void  func_0204F150(u8 *board, s32 idx);                          /* EXACT  */
void  func_0204F1A0(struct Board *b, u32 idx);                    /* EXACT  */
void  func_0204F214(u8 *board, s32 idx);                          /* EXACT  */
void  func_0204F27C(struct Board *b);                             /* EXACT  */

/* slot getters */
/* func_0204F2B4 and func_0204F2CC are the +0x0c and +0x10 getters, and both
 * are filed with a FOUR-int parameter list and int-typed pointer arithmetic
 * rather than a struct: that spelling is what reproduces them, and the fourth
 * parameter is unused.  Do not "tidy" them into the struct form. */
void  func_0204F2B4(int board, int idx, int *out, int unused);    /* EXACT  */
void  func_0204F2CC(int board, int idx, int *out, int unused);    /* EXACT  */
void  func_0204F2E4(u8 *board, int idx, u32 *out);                /* EXACT  */
void  func_0204F344(void *board, int idx, int a2, int *out,
                    int *in, u8 flag);                            /* EXACT  */

/* elem allocation, flags and getters */
s32   func_0204F428(struct Board *b, u32 id, u16 v12, u16 v14,
                    struct Vec3 *src, u8 k, u32 w, u32 mode);     /* EXACT, plain BITFIELD
                                                                   * assignments on Elem */
void  func_0204F5A8(void *board, u32 idx);                        /* EXACT* */
void  func_0204F5E4(u8 *board, int idx, u16 *out);                /* EXACT  */
void  func_0204F604(void *board, u32 idx, u16 *src);              /* EXACT* */
void  func_0204F638(u8 *board, int idx, struct Trip *src);        /* EXACT, Trip is the
                                                                   * 3-halfword record
                                                                   * func_0204F638.c
                                                                   * declares */
void  func_0204F66C(int board, int idx, int src, int unused);     /* EXACT, four-int
                                                                   * spelling like
                                                                   * func_0204F2B4 */
void  func_0204F684(struct Manager0204F684 *b, int idx,
                    const s16 *p12, const s16 *p14);              /* EXACT  */
void  func_0204F6B4(u8 *board, int idx, u8 *px);                  /* EXACT, in unit_0204F6B4 */
void  func_0204F6DC(u8 *board, int idx, u8 *px);                  /* EXACT, in unit_0204F6B4 */
u32   func_0204F704(u8 *board, int idx);                          /* EXACT, in unit_0204F6B4 */
void  func_0204F720(void *board, u32 idx, u32 *flag);             /* EXACT* */
u32   func_0204F748(u8 *board, int idx);                          /* EXACT, RETURNS u32,
                                                                   * takes no out-pointer */
void  func_0204F764(void *board, u32 idx, u32 *val);              /* EXACT  */
void  func_0204F794(void *board, u32 idx, u32 *val);              /* EXACT* */
void  func_0204F7C4(u8 *board, int idx, u16 *src);                /* EXACT  */

/* the family's tail and draw pass; 1720 bytes.  Written against the NitroSDK
 * G3 immediate inlines (sdk/TwlSDK/include/nitro/gx/g3imm.h), transcribed as
 * static inlines over the 0x04000440.. registers; 0x0207C768 is FX_Div. */
void  func_0204F7DC(struct Board *b, struct Camera *cam,
                    struct Lights *lights);                       /* EXACT  */

/* unit_0204F6B4 folds func_0204F6B4, func_0204F6DC and func_0204F704 into one
 * tu-verified file; those three are EXACT as a unit, not individually filed. */

/* ------------------------------------------------------------------ */
/* OUTSIDE THE FAMILY -- helpers this family calls                      */
/* ------------------------------------------------------------------ */

void *func_02030734(int heap, int size, int align, const char *file, int line);
void  func_020307B0(void *p);
void  func_020307E0(void *p, u32 size);
void *func_02046F48(void *p);
void  func_02046EFC(u32 v);
u32   func_02046FF8(u32 heapId);
void *func_02047250(void *p);
u32   func_02047388(u32 heapId);
u32   func_020473B8(u32 heapId);
void  func_020470D0(u32 v);
u32   func_02046DB8(u32 a, u32 b);

/* THE DIVISION HELPER, and it is not an ordinary call.  0x0209C0A4 is
 * `_s32_div_f`, row 16 of layout/runtime_arm9.txt: the mwccarm/MSL runtime's
 * signed 32-bit divide, hand-written ARM assembly that is never compiled from
 * this project's C.  A `bl 0x209c0a4` in this family is a `/` or a `%` in the
 * source, NOT a call to a game function
 * (docs/idioms/runtime-helper-reloc.md).  Declare it in `symbols:` as
 * `_s32_div_f 0x0209C0A4 arm` and let the front end emit the call.  Evidenced
 * by src/matched/func_0204F344.c, where the four divisions are spelled out;
 * func_0204EEC8's two `bl`s are the same thing, and reading them as calls to
 * an unknown func_0209C0A4 is what docs/notes/pkt_0204EEC8.c.txt did.
 */
extern s32 _s32_div_f(s32 a, s32 b);        /* 0x0209C0A4, runtime */

#endif /* BILLBOARD_H */
