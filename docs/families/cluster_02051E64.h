/*
 * docs/families/cluster_02051E64.h -- shared declarations for the
 * pseudo-family cluster_02051E64 (0x02051E64..0x02052DC8 in the ARM9 image).
 *
 * PSEUDO-FAMILY.  The upper half of the ARM9 image carries no __FILE__
 * anchors, so this cluster was formed by address adjacency plus shared
 * callees and data objects, NOT by a string anchor.  The nearest anchor,
 * button_man.c at 0x02051B84, sits just BELOW the cluster and does not
 * cover it.
 *
 * WHAT THE SUBSYSTEM IS.  A 3D scene/model manager: it owns a rig
 * (the "Head" below), a doubly-linked list of models (the "Node"), the
 * per-frame walk that ages and dispatches them, the geometry helpers that
 * place them, and the GX texture/palette upload pass that feeds them to the
 * hardware.  Three unrelated-looking halves, but they share the rig struct
 * and the same four list primitives, which is the whole basis of the
 * grouping:
 *
 *   PART 1, 0x02051E64..0x020522E4 -- GEOMETRY AND FIXED-POINT MATH.
 *     Small leaf helpers over the SDK's libfx: a scaled 2x2 rotation builder
 *     (0x02051E74, still DIFF), a ray/sphere intersection test
 *     (0x02051F34, still DIFF), a 3x3 vector scale (0x020520A4), the
 *     three-angle rotation composer (0x020520FC) and the look-at builder
 *     (0x020521BC).  The last three all read the shared interleaved sin/cos
 *     halfword table at 0x020A1B38 at index angle >> 4, sin at tbl[2*i] and
 *     cos at tbl[2*i+1].  0x02052274/0x020522E4 are a character-encoding
 *     converter that sits in the same address run but shares nothing else.
 *
 *   PART 2, 0x020524C8..0x02052984 -- THE LIST/RIG MANAGER.  Four
 *     primitives OUTSIDE the cluster do the actual list surgery and are the
 *     second half of the clustering evidence:
 *
 *       func_02058300  0x02058300  unlink a node from a list, returns it
 *       func_0205831C  (unused here)
 *       func_02058380  0x02058380  pop the head off a list, 0 when empty
 *       func_020583CC  0x020583CC  push a node onto a list
 *
 *     Every teardown and every retire in this half is a composition of those
 *     three.  0x020524C8 drains a container, 0x0205250C tears one node down,
 *     0x02052634 and 0x020525A0 pop-and-load one node, 0x020526A8 is the
 *     per-frame driver and 0x02052770 the per-node walk.
 *
 *   PART 3, 0x020528A8..0x02052A50 -- THE GX UPLOAD PASS.  Two twin
 *     routines walk the rig's 0x14-byte material rows at o->f2c and upload
 *     each row's resource: 0x020528D0 through GX_*LoadTexPltt (palettes) and
 *     0x02052984 through GX_*LoadTex (textures).  0x020528A8 and 0x020528BC
 *     are twelve-byte tail-call thunks that bind each to its own callback.
 *
 * FRONT-END PIN.  Most of this cluster is built by the 1.2 front end, not
 * dsi/1.1p1: `--cc ../1.2/sp2 --flags "-O4,p -proc arm946e"`.  The tells are
 * the `sub sp, sp, #4` frame pad (dsi/1.1p1 spends a dead `push {r3}`
 * instead) and the ARMv4T-style `pop {..., lr}; bx lr` epilogue, per
 * docs/idioms/an-armv4t-style-return-and-a-register-blx-name-a-1-2-front-end-not-a-proc-value.md.
 * The exceptions are the PART 1 math helpers and 0x02052274, which are
 * dsi/1.1p1 and compile 20 bytes longer under 1.2.  Check the pin per row;
 * the packet-level default is 1.2.
 *
 * REFERENCE DOCUMENT ONLY.  Nothing includes this file; it is not part of
 * any translation unit and match.py never sees it.  Every declaration is
 * derived from an EXACT file in src/matched, and the evidencing function is
 * named in the comment beside it.
 *
 * Addresses are Black-image addresses throughout.
 */

#ifndef CLUSTER_02051E64_H
#define CLUSTER_02051E64_H

typedef unsigned char      u8;
typedef unsigned short     u16;
typedef unsigned int       u32;
typedef signed   short     s16;
typedef signed   int       s32;
typedef long long          s64;

/* ================================================================== *
 * PART 1: geometry and fixed-point math, 0x02051E64..0x020522E4
 * ================================================================== */

/* func_020521BC, func_020520A4: the SDK's 1.19.12 fixed-point vector. */
struct Vec3 {
    int x;  /* 0x00 */
    int y;  /* 0x04 */
    int z;  /* 0x08 */
};

/* func_020520FC, func_020521BC.  Nine words, no padding. */
struct Mtx33 {
    int m[9];
};

/*
 * The shared interleaved sin/cos table, s16 pairs.  Indexed by
 * i = angle >> 4 (an arithmetic shift: the angles are signed), sin at
 * tbl[2*i] and cos at tbl[2*i+1].  Evidenced by func_020520FC and
 * func_020521BC; the `ldrsh` with a REGISTER offset is the only proof the
 * elements are signed, since no immediate-offset ldrsh encoding exists
 * (docs/idioms/ldrsh-register-offset-is-signedness.md).
 */
extern s16 tbl_020A1B38[];

/* SDK, all ARM unless marked.  Addresses from layout/symbols_sdk.txt. */
extern void MTX_Identity33_(struct Mtx33 *m);                   /* 0x0207ADC4 */
extern void MTX_RotX33_(struct Mtx33 *m, s16 s, s16 c);         /* 0x0207AF00 thumb */
extern void MTX_RotY33_(struct Mtx33 *m, s16 s, s16 c);         /* 0x0207AF1C thumb */
extern void MTX_RotZ33_(struct Mtx33 *m, s16 s, s16 c);         /* 0x0207AF38 thumb */
extern void MTX_Concat33(const struct Mtx33 *a, const struct Mtx33 *b,
                         struct Mtx33 *dst);                    /* 0x0207B388 */
extern int  VEC_Mag(const struct Vec3 *v);                      /* 0x0207CBD0 */
extern void VEC_Subtract(const struct Vec3 *a, const struct Vec3 *b,
                         struct Vec3 *d);                       /* 0x0207CA00 */
extern int  VEC_DotProduct(const struct Vec3 *a, const struct Vec3 *b); /* 0x0207CA68 */
extern void VEC_Normalize(const struct Vec3 *v, struct Vec3 *d); /* 0x0207CCA4 */
extern int  FX_Atan2Idx(int y, int x);                          /* 0x0207CFB8 */
/*
 * 0x0207C768 is NOT in layout/symbols_sdk.txt but sits immediately before
 * FX_DivFx64c (0x0207C788) in libfx's fx_cp.o and takes (numerator,
 * denominator) returning a 1.19.12 quotient: it is FX_Div.  Evidenced by
 * func_02051F34's use of it on two dot products.
 */
extern int  FX_Div(int num, int den);                           /* 0x0207C768 */

/* func_020520A4: dst = v * s, componentwise, in 1.19.12 with SDK rounding. */
void func_020520A4(const struct Vec3 *v, int s, struct Vec3 *dst);

/* func_020520FC: dst = RotZ(az) . RotY(ay) . RotX(ax), angles in 1/4096 turn. */
void func_020520FC(int ax, int ay, int az, struct Mtx33 *dst);

/* func_020521BC: look-at rotation for a direction vector (pitch X, yaw Y). */
void func_020521BC(const struct Vec3 *v, struct Mtx33 *dst);

/*
 * func_02052274 / func_020522E4: wide-to-narrow character conversion.
 * The converter writes one or two bytes and returns 1 for the two-byte
 * case; it reports "stop the run" by storing 1 into its scratch out-param.
 */
extern int func_020522E4(u8 *src, u8 *dst, u32 *scratch);        /* 0x020522E4 */
void func_02052274(u8 *src, u8 *dst, u32 n);

/* ================================================================== *
 * PART 2: the list / rig manager, 0x020524C8..0x02052984
 * ================================================================== */

/*
 * The four list primitives.  All four live outside the cluster and are
 * what holds it together; every teardown here is a composition of them.
 */
extern void *func_02058380(void *list);                /* pop head, 0 if empty */
extern void *func_02058300(void *list, void *node);    /* unlink, returns node */
extern void  func_020583CC(void *list, void *node);    /* push onto list */
extern void  func_02053A60(void *node, void *slot, void *scratch); /* load node */

/*
 * The class record, reached as `*node->f20` (doubly indirect).  Only the
 * fields func_02052770 touches are pinned; offsets 0x04..0x2f are unread.
 * Evidenced by func_02052770.
 */
struct Cls {
    u32 c00_lo  : 14;
    u32 c00_b14 : 1;    /* "retire when past the cap" */
    u32 c00_hi  : 17;
    u32 pad04[11];
    u16 pad30;
    u16 f32;            /* 0x32: lifetime, compared against node->f4c */
    u32 pad34[2];
    u16 f3c;            /* 0x3c: retire cap, 0 disables */
    u16 pad3e;
};

/*
 * The model node.  0x00/0x04 are the list links and are read BOTH ways:
 * func_020526A8 walks forward through f00 on one list and backward through
 * f04 on the other.  Evidenced by func_020526A8 and func_02052770.
 */
struct Node {
    struct Node *next;   /* 0x00 */
    struct Node *prev;   /* 0x04 */
    u32 f08;
    u32 f0c;             /* pending-work guard, must be 0 to retire */
    u32 pad10[2];
    u32 f18;             /* pending-work guard, must be 0 to retire */
    u32 f1c;
    struct Cls **f20;    /* 0x20 */
    /*
     * The +0x24 flag word.  Every read of it in the cluster is an
     * lsl/lsr shift PAIR, never a mask, so these are genuine bitfields
     * (docs/idioms/shift-pair-with-no-matching-type-is-a-bitfield.md).
     */
    u32 f24_b0 : 1;      /* kill: retire this node now */
    u32 f24_b1 : 1;
    u32 f24_b2 : 1;      /* suppressed: skip the dispatch */
    u32 f24_b3 : 1;      /* skip: func_020526A8's per-node guard */
    u32 f24_b4 : 1;      /* expired: age has reached the class lifetime */
    u32 f24_hi : 27;
    u16 pad28[18];
    u16 f4c;             /* 0x4c: age, in frames */
    u16 pad4e;
    u32 pad50[11];
    u32 f80;             /* 0x80: bits 16..18 are the 3-bit phase index */
};

/*
 * The rig.  Two lists (forward at 0x04, reverse at 0x0c), a recycle list at
 * 0x10, the material rows at 0x2c and a two-frame parity counter at 0x48.
 * Evidenced by func_020526A8 (0x04/0x0c/0x10/0x38/0x40/0x44),
 * func_02052770 (0x04/0x10/0x48) and func_020528D0 (0x2c/0x32).
 */
struct Head {
    u32 f00;
    struct Node *list;   /* 0x04: forward list */
    u32 f08;
    struct Node *rlist;  /* 0x0c: reverse list */
    u32 f10;             /* 0x10: recycle list */
    u32 pad14[6];
    struct Row *f2c;     /* 0x2c: material rows, 0x14 bytes each */
    u16 pad30;
    u16 f32;             /* 0x32: row count, SIGNED in the loop bound */
    u32 f34;
    u32 f38_lo  : 24;
    u32 f38_b24 : 1;     /* which list func_020526A8 walks */
    u32 f38_hi  : 7;
    u32 f3c;
    struct Node *cur;    /* 0x40: the node the callback is running on */
    u32 f44;             /* 0x44: the driver's argument */
    u16 f48;             /* 0x48: frame parity, 0 or 1 */
};

/* 0x020524C8: drain the list at p+4, tearing each node down. */
void func_020524C8(void *p);
/* 0x0205250C: tear one node down; both its sublists go to p+0x1c. */
void func_0205250C(char *p, char *q);
/* 0x02052634, 0x020525A0: pop one node and run its loader. */
int  func_02052634(char *p, int b, int c);
int  func_020525A0(char *p, int b, void (*fn)(void *));
/* 0x020526A8: the per-frame driver; pokes DISP3DCNT then walks one list. */
void func_020526A8(struct Head *h, u32 a);
/* 0x02052770: the per-node walk; ages, dispatches and retires. */
void func_02052770(struct Head *h);
extern void func_02053218(struct Head *h, struct Node *n);   /* dispatch */
extern void func_02052FC8(struct Head *h);                   /* per-node callback */

/*
 * DISP3DCNT.  func_020526A8 clears bits 12-13 and sets bit 3 on it every
 * frame.  It is a cast constant, never a relocation.
 */
#define REG_DISP3DCNT (*(volatile u16 *)0x04000060)

/* ================================================================== *
 * PART 3: the GX upload pass, 0x020528A8..0x02052A50
 * ================================================================== */

/*
 * A material row, 0x14 bytes, in the run at Head::f2c.  The first word is
 * the resource pointer; the VRAM handle the upload produces is written back
 * into the row.  NOTE the two twins disagree on WHERE: func_020528D0 (the
 * palette pass) stores at +0x08 and func_02052984 (the texture pass) at
 * +0x04, so they are two different handles in the same row, not one field.
 */
struct Row {
    struct Res *res;     /* 0x00 */
    u32 tex_vram;        /* 0x04, written by func_02052984 */
    u32 pltt_vram;       /* 0x08, written by func_020528D0 */
    u32 pad0c[2];
};

/*
 * The resource header.  +0x04 is a flag word whose low 4 bits are a
 * format/kind code: the palette pass compares it against 2, the texture
 * pass against 5, and both reads are the lsl #28 / lsr #28 shift pair, so
 * it is a 4-bit bitfield.  Spelling it `& 0xf` folds to a single
 * `and rN, rM, #0xf` and loses four bytes -- declare the field.
 * Evidenced by func_020528D0.
 */
struct Res {
    u32 f00;
    u32 kind   : 4;      /* 0x04 bits 0..3 */
    u32 f04_hi : 28;
    u32 f08;
    u32 f0c;             /* byte offset added to the row's first word */
    u32 f10;             /* size; zero means "nothing to upload" */
};

/*
 * The upload callback both passes take as their second argument.  It is
 * called through `blx fp`, so it is a real function pointer, not a bl.
 * Its first argument is the resource's SIZE word (res->f10), not the
 * resource pointer -- the image reuses the register the size guard already
 * loaded and emits no `mov r0, rN` before the blx.  Evidenced by
 * func_020528D0: adding the extra `mov` is a four-byte size error.
 */
typedef u32 (*GxAlloc)(void *size, u32 kind_is_special);

extern void GX_BeginLoadTexPltt(void);                       /* 0x0207FA0C */
extern void GX_LoadTexPltt(void *dst, u32 handle, u32 len);  /* 0x0207FA40 */
extern void GX_EndLoadTexPltt(void);                         /* 0x0207FADC */
extern void GX_BeginLoadTex(void);                           /* 0x0207F7A0 */
extern void GX_LoadTex(void *dst, u32 handle, void *len);    /* 0x0207F7FC */
extern void GX_EndLoadTex(void);                             /* 0x0207F9B4 */

/* 0x020528D0: upload every row's palette.  Always returns 1. */
int func_020528D0(struct Head *o, GxAlloc alloc);
/* 0x02052984: upload every row's texture.  Always returns 1. */
int func_02052984(struct Head *o, GxAlloc alloc);
/* 0x020528A8, 0x020528BC: the two tail-call thunks that bind the callbacks. */
void func_020528A8(u32 a0);
void func_020528BC(u32 a0);

/*
 * A CLUSTER-WIDE LESSON, paid for twice in wave 7.  When a call takes the
 * ADDRESS of a local (`&scratch`) or an offset from a parameter
 * (`(char *)h + 4`), write it INLINE at the call site.  Binding it to a
 * named pointer local hoisted above the loop gives THAT value the low
 * register colour and displaces the values the image wanted there -- a
 * clean two-cycle register swap that no permuter mutation moves (measured:
 * 266 single mutations on func_02052770, 164 on func_02052274, plus ten
 * hand spellings each by earlier lanes).  Written inline, the compiler
 * performs the hoist ITSELF and colours in the image's order.  This closed
 * func_02052770 (33 bytes out -> EXACT) and func_02052274 (8 -> EXACT).
 */

#endif /* CLUSTER_02051E64_H */
