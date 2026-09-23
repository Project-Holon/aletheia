/*
 * docs/families/g3d_system.h -- shared declarations for the g3d_system.c
 * family (the 3D graphics system / scene driver),
 * 0x02046440..0x02047C8C in the ARM9 image.  Edges are fuzzy by a function
 * or two at both ends.
 *
 * REFERENCE DOCUMENT ONLY.  Nothing includes this file; it is not part of
 * any translation unit and match.py never sees it.  It is the adjudicated
 * union of the declarations that the family's byte-exact sources already
 * carry, written down once so a new attempt on an open function starts from
 * the settled shape instead of re-deriving it.
 *
 * Derived from the 47 matched sources found with
 *   grep -l "address:  0x02046[4-9A-F]\|address:  0x02047[0-9A-C]" \
 *        src/matched/*.c
 * Each declaration names the matched function that evidences it.
 *
 * ADJUDICATION RULE USED THROUGHOUT.  A load instruction constrains a field
 * and a name does not.  `ldrb [r,#N]` fixes a byte at exactly +N; `ldrsh`
 * proves s16 (there is no immediate-offset ldrsh, see
 * docs/idioms/ldrsh-register-offset-is-signedness.md); a shift pair proves a
 * bitfield's width.  A file that only passes a pointer through constrains
 * nothing, so its `void *` spelling never outranks a file that dereferences.
 *
 * Addresses are Black-image addresses throughout (docs/AGENT-BRIEF.md s8).
 */

#ifndef G3D_SYSTEM_H
#define G3D_SYSTEM_H

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

/* ------------------------------------------------------------------ *
 * THE SINGLETON POINTER at 0x02146A5C.
 *
 * Every file in the family reaches the system through this one word.  It
 * is a POINTER, not the object: every use is `ldr rX,[pool]; ldr rY,[rX]`
 * (func_02046B40, func_02047970, func_020479D8, func_02047564), so the
 * pool word holds &g_02146A5C and the object lives one indirection down.
 *
 * ONE SPELLING CONFLICT, resolved.  func_02047C8C declares g_02146A5C as a
 * three-word STRUCT (`{ Ctx *obj; u32 f4; u32 f8; }`) and reaches +4/+8
 * directly; every other file declares it as `Ctx *` / `u32 *` and reaches
 * the object.  They are the same three words: 0x02146A5C+0 is the object
 * pointer and +4/+8 are two u32 counters that only func_02047C8C touches.
 * The struct spelling is preferred here because it is the only one that
 * constrains +4 and +8; a file that needs only the object pointer may keep
 * writing `extern struct G3dCtx *g_02146A5C;` and still be byte-exact,
 * because the first member is at offset zero.
 * ------------------------------------------------------------------ */

struct G3dCtx;

struct G3dSysGlobal {
    struct G3dCtx *obj;     /* +0x00  the context; func_02046B40, func_02047970 */
    u32            f04;     /* +0x04  counter, += ov->h26; func_02047C8C */
    u32            f08;     /* +0x08  counter, += ov->h24; func_02047C8C */
};

extern struct G3dSysGlobal g_02146A5C;

/* ------------------------------------------------------------------ *
 * THE CONTEXT at *(void **)0x02146A5C.  Fields are quoted only where a
 * load or store in a matched file fixes the offset.
 *
 *   +0x18  u16   a resource/heap id, read as `ldrh [r,#0x18]` and passed
 *                as func_02030734's first argument (func_02047564's note,
 *                func_02047400).
 *   +0x1C  u32   a mode selector, switched three ways 0/1/2 (func_02046858).
 *   +0x20..+0x38 u32  six consecutive words consumed as func_0207C408's
 *                arguments and stack arguments (func_02046858).
 *   +0x5C  Blk   three words, the first of three camera/view blocks
 *   +0x68  Blk   three words, the second
 *   +0x74  Blk   three words, the third
 *                All three proved by the `add rX, r3, #0x5c/#0x68/#0x74`
 *                plus `ldm/stm {r0,r1,r2}` triples in func_02046B40 and
 *                func_020479D8; they are func_0207BCA0's first three
 *                arguments.
 *   +0x88  fn    a `blx`-through function pointer, `ldr r0,[r0,#0x88]`
 *                (func_020479D8, func_02047A60, func_02047AC8).
 *   +0x94  u32   set to 1 by func_02047970.
 *   +0x98  fn    an optional callback `(void *p, u32 v)`, run only when
 *                non-null (func_02047C8C).
 *   +0x9C  u32   that callback's second argument (func_02047C8C).
 * ------------------------------------------------------------------ */

typedef struct { u32 w[3]; } Blk;   /* func_02046B40: ldm/stm {r0,r1,r2} */

struct G3dCtx {
    u8   pad_00[0x18];
    u16  heap_id;           /* +0x18  func_02047400, func_02047564 */
    u16  pad_1a;
    u32  mode;              /* +0x1C  func_02046858 */
    u32  args[7];           /* +0x20..+0x38  func_02046858 */
    u8   pad_3c[0x20];
    Blk  view0;             /* +0x5C  func_02046B40, func_020479D8 */
    Blk  view1;             /* +0x68 */
    Blk  view2;             /* +0x74 */
    u8   pad_80[0x08];
    void (*f88)(void);      /* +0x88  func_020479D8, func_02047A60 */
    u8   pad_8c[0x08];
    u32  f94;               /* +0x94  func_02047970 */
    void (*f98)(void *p, u32 v);   /* +0x98  func_02047C8C */
    u32  f9c;               /* +0x9C  func_02047C8C */
};

/* ------------------------------------------------------------------ *
 * THE HARDWARE / REGISTER BLOCK at 0x02148B4C.
 *
 * Only one field is ever touched in this family, the word at +0xFC, and
 * always as a read-modify-write that clears a small mask:
 *
 *   `&= ~0xE8`  func_02046B40, func_020479D8    (the three-view path)
 *   `&= ~0xA4`  func_02047A60, func_02047AC8    (the teardown path)
 *   `&= ~0x50`  func_02046858                   (the render path)
 *
 * func_02046B40 spells it `u32 g_02148B4C[]` and indexes [0x3F]; that is
 * the same word as +0xFC and either spelling is byte-exact.  The array
 * spelling is kept below because it is what the matched file carries.
 * ------------------------------------------------------------------ */

extern u32 g_02148B4C[];        /* g_02148B4C[0x3F] == +0xFC */

/* The three destination blocks the views are broadcast into.  Their order
 * and their 12-byte size are fixed by the `ldm/stm {r0,r1,r2}` triples of
 * func_02046B40 and by their consecutive addresses. */
extern Blk g_02148D8C;          /* func_02046B40 */
extern Blk g_02148D98;
extern Blk g_02148DA4;

/* func_0207BCA0's fourth argument, always passed as `&g_02148B98`. */
extern Blk g_02148B98;          /* func_02046B40 */

/* The `__FILE__`-style string this family's allocations pass as
 * func_02030734's fourth argument (func_02047564's note, func_02047400). */
extern u32 g_020A7EA8;

/* ------------------------------------------------------------------ *
 * THE TAGGED RECORD.  Two record kinds share one layout and differ only in
 * the halfword tag at +0: 0x7A14 (func_02047504, allocated by
 * func_02047400) and 0x59D1 (func_0204762C, allocated by func_02047564).
 * The destructor of each drops the tag to `tag - 1` before freeing, which
 * is why the new value arrives as `sub r1, r4, #1` and not as a second
 * pooled literal.
 * ------------------------------------------------------------------ */

#define G3D_TAG_7A14  0x7A14    /* func_02047400 / func_02047504 */
#define G3D_TAG_59D1  0x59D1    /* func_02047564 / func_0204762C */

struct G3dRec {
    u16 tag;        /* +0x00  func_02047504, func_0204762C */
    u16 unk_02;
    u32 unk_04;     /* +0x04  the handle handed to func_0206E358/0206E388 */
    u32 unk_08;     /* +0x08  the owner; func_02047400, func_02047564 */
    u32 unk_0c;     /* +0x0C  func_02047400 only */
};

/* ------------------------------------------------------------------ *
 * THE OWNER RECORD, what func_02047788 / func_0204755C return through.
 * Both are the same one-line accessor `int f(int *p){ return p[1]; }`, so
 * the only field either constrains is +0x04.  func_02047B4C then adds 0x14
 * to that pointer (guarded against null) and reads six s16 at +0x18..+0x22
 * and a u32 at +0x24 of the result.
 * ------------------------------------------------------------------ */

struct G3dOwner {
    u32   pad_00;
    void *f04;      /* +0x04  func_02047788, func_0204755C, func_02047B4C */
    u32   pad_08;
    void *f0c;      /* +0x0C  func_02047564 */
};

/* ------------------------------------------------------------------ *
 * PROTOTYPES, family-internal, with the parameter types the matched
 * sources carry.  Every one is ARM.
 * ------------------------------------------------------------------ */

extern int  func_02047788(int *p);          /* returns p[1] */
extern int  func_0204755C(int *p);          /* returns p[1] */
extern int  func_02047554(int *p);
extern void func_02047504(struct G3dRec *p);    /* free a 0x7A14 record */
extern void func_0204762C(struct G3dRec *p);    /* free a 0x59D1 record */
extern int  func_02047C04(void *obj);
extern int  func_02047B4C(void);
extern void func_02047C8C(void *p);
extern void func_02047970(void);
extern void func_02046B40(u8 *a0);

/* ------------------------------------------------------------------ *
 * EXTERNAL CALLS this family makes, with the arity the matched sources
 * prove.  These live outside 0x02046440..0x02047C8C.
 * ------------------------------------------------------------------ */

extern void *func_02030734(u16 heap, u32 size, u32 zero, const void *file,
                           u32 line);           /* five args, the 5th on the
                                                   stack; func_02047564 note */
extern void  func_020307B0(void *p);            /* free; func_02047504 */

extern void  func_0207BCA0(void *a0, void *a1, void *a2, void *a3);
                                                /* func_02046B40 */
/* func_02046858 (EXACT, wave 11) pins the three projection setters.  Mode 0
 * passes SEVEN arguments (no +0x2C), modes 1 and 2 EIGHT; the last is always
 * &g_02148B54, and the one before it is +0x38, or 0x1000 when +0x38 is zero
 * (two calls per mode, not an OR).  Declaring `u32 *hw = g_02148B4C;` before
 * the dispatch is what puts the register block in r4 across each call and
 * makes the prologue push {r4, lr}; every arm clears hw[0x3F] bits 0x50 and
 * returns on its own. */
extern u8    g_02148B54[];
extern void  func_0207C408(u32 a0, u32 a1, u32 a2, u32 a3,
                           u32 s0, u32 s1, void *s2);
extern void  func_0207C1D0(u32 a0, u32 a1, u32 a2, u32 a3,
                           u32 s0, u32 s1, u32 s2, void *s3);
extern void  func_0207C554(u32 a0, u32 a1, u32 a2, u32 a3,
                           u32 s0, u32 s1, u32 s2, void *s3);

/* func_02046440 (EXACT, wave 11), the constructor.  Seven parameters:
 *   (u32 texMode, u32 texSize, u32 plttMode, u32 plttSize,
 *    u16 fifoSize, s16 heap, void (*setup)(void))
 * The HEAP PARAMETER IS s16: as u16 the compiler re-reads it from its stack
 * home after the first allocation instead of holding it in r8, and every
 * later instruction shifts by one.  The context fields it fixes: +0x10 and
 * +0x14 are the palette and texture VRAM-manager buffers (+0x14 is also
 * the field cleared by the palette arm's else-branch -- an original bug,
 * reproduced), +0x8C/+0x90 the two mode arguments, +0x98/+0x9C zeroed at
 * the end.  Its three stack buffers are declared in the order s32 (0x20
 * bytes), s36 (0x24), r (4 x u16), later declaration lower.  SDK calls it
 * makes, by address: G3X_InitMtxStack 0x0207DB1C, G3X_SetFog 0x0207DC44,
 * G3X_SetClearColor 0x0207DD24; the default path also writes the SDK
 * inline defaults to DISP3DCNT (0x04000060), SWAP_BUFFERS (0x04000540 = 2)
 * and VIEWPORT (0x04000580 = 0xBFFF0000).  Data it copies from:
 * 0x020A1308 (32 bytes), 0x020A1E38 (+0x8C/+0x8E s16), 0x020A1300
 * (4 x u16), 0x020A1328 (36 bytes), all `sole-ref` attested. */

extern void  func_0206DDA4(u32 cmd, void *buf, u32 count);  /* func_02047C04 */
extern void  func_0206DB80(void);                           /* func_02047970 */
extern int   func_0207DEA4(void *p);                        /* func_02047C04 */

extern void  func_0206E358(u32 ctx, u32 field);   /* func_02047504 */
extern void  func_0206E388(u32 ctx, u32 field);   /* func_0204762C */
extern int   func_0206E348(u32 ctx);              /* func_02047400 */
extern int   func_0206E364(u32 ctx, int a, int b);/* func_02047564 */
extern int   func_0206E954(u32 h);                /* func_02047400 */
extern int   func_0206E964(u32 h);                /* func_02047400, func_02047564 */
extern int   func_0206E9A4(int a, int b);         /* func_02047564 (EXACT in wave 16:
                                                   the owner parameter a1 is
                                                   const; src/matched/func_02047564.c) */

extern void  func_0206A2CC(void *a, void *b);     /* func_02047400 */
extern void  func_0206A4AC(void *a, void *b);     /* func_02047400 */
extern void  func_0206A9DC(void *p);              /* func_02047A60, func_02047AC8 */
extern void  func_0206AA0C(void *p);              /* func_02047A60, func_02047AC8 */
extern void  func_0206B6A4(void *p);              /* func_02047C8C */
extern void  func_0206DDA4_dup(void);             /* (placeholder, unused) */
extern void  func_02069C74(int a, int b, int c, int d);   /* func_02047564 */
extern void  func_02069D14(int a, void *b);               /* func_02047400 */

extern void  MI_CpuFill8(void *dst, u8 v, u32 n); /* 0x02082BCC; func_02047A60 */

/* WAVE 15 (2026-09-23): 0x02148B4C IS NitroSystem's NNS_G3dGlb (NNSG3dGlb,
 * NitroSystem-071126 glbstate.h): cameraMtx at +0x4C (== g_02148B98), flag
 * at +0xFC (the `&= ~mask` word), camPos/camUp/camTarget at +0x240/+0x24C/
 * +0x258 (== g_02148D8C/D98/DA4).  The copies + MTX_LookAt (0x0207BCA0) +
 * `flag &= ~0xE8` are the inline NNS_G3dGlbLookAt(const VecFx32 *camPos,
 * const VecFx32 *camUp, const VecFx32 *target); written as that inline over
 * the one struct, func_020479D8 is EXACT (src/matched/func_020479D8.c holds
 * the full struct layout).  func_02046B40 is the same inline preceded by the
 * three stores into the context. */

#endif /* G3D_SYSTEM_H */
