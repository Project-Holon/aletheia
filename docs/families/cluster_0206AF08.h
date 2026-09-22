/*
 * docs/families/cluster_0206AF08.h -- shared declarations for the
 * pseudo-family cluster_0206AF08 (0x0206AF08..0x0206BEA0 in the ARM9 image),
 * covering the adjacent clusters pkt_0206AF08 (0x0206AF08..0x0206B4A0) and
 * pkt_0206B7A8 (0x0206B7A8..0x0206BA18) and the pkt_0206AFE4 run between
 * them.
 *
 * PSEUDO-FAMILY.  The upper half of the ARM9 image carries no __FILE__
 * anchors, so this cluster was formed by address adjacency plus shared
 * callees and data objects, NOT by a string anchor.  Three things hold it
 * together and are the whole basis of the grouping:
 *
 *   the Node list    a singly-linked list of "channel" nodes -- entry count
 *                    as a BYTE at +0x19, a u16 entry array at +0x1a, a
 *                    callback at +0x0c and the next pointer at +0x10.  Four
 *                    of the six members of pkt_0206AF08 walk it, each with a
 *                    different verb (test, blend, collect).
 *   the Rec          a 0x38-byte animation record, produced by the object
 *                    constructor func_0206B4A0 into a 0x188-byte object and
 *                    consumed by the script pumps at 0x0206B458 and above.
 *   the handler table 0x020A83B8, the 32-entry opcode dispatch that
 *                    func_0206B458's loop indexes with the low five bits of
 *                    the byte under the program pointer at +0x00.
 *
 * WHAT THE SUBSYSTEM IS.  An ANIMATION CHANNEL EVALUATOR and the SCRIPT
 * MACHINE that drives it -- the layer that sits under the 3D model rig of
 * docs/families/cluster_0206A17C.h and produces the transforms it consumes.
 * Three cooperating halves:
 *
 *   PART 1, 0x0206AF08..0x0206B4A0 -- the CHANNEL LIST.  Every function here
 *     walks the same node list for one entry index.  func_0206AF08 fires the
 *     first live entry's callback and returns whether anything fired;
 *     func_0206B3D0 is the same walk ORing each callback's word into the
 *     caller's out-parameter; func_0206B63C collects the live entries into a
 *     bitmap; and func_0206AFE4 is the weighted blend, the subsystem's real
 *     work, normalising each node's +0x04 weight against the running total
 *     through the hardware divider sub_0207C768 and accumulating a full
 *     0x58-byte transform.  func_0206AF74 is the three-word mix primitive
 *     that blend calls three times per node.
 *
 *   PART 2, 0x0206B458..0x0206B7A8 -- the SCRIPT OBJECT.  func_0206B4A0
 *     builds a 0x188-byte object out of a config record and a script blob,
 *     then hands it to func_0206B458, the interpreter loop: clear bit 6 of
 *     the flag word at +0x08, read the opcode byte, dispatch its low five
 *     bits through 0x020A83B8 with the top three bits as the argument, and
 *     repeat until bit 5 of the flag word says stop.  func_0206B6A4 is the
 *     entry point that owns the object's stack frame, re-entrant through the
 *     stash pointer g_02148DB0.  func_0206B780 and func_0206B7A8 are the two
 *     one-line hooks the opcodes call.
 *
 *   PART 3, 0x0206B7D0..0x0206BEA0 -- the OPCODE BODIES.  Three sizes of the
 *     same opcode shape, one per operand count: func_0206B94C (two bytes),
 *     func_0206B7D0 (three bytes) and func_0206BA18 (the three-argument
 *     form, still open).  All three share the "three stops" skeleton -- read
 *     the state byte through a hook pointer, zero when the hook is null,
 *     then run up to three re-entrant stops at states 1, 2 and 3, each
 *     clearing bit 6 of the flag word, calling the hook and re-reading the
 *     state.  The bodies between the stops are what differ.
 *
 * ============================================================================
 * THE COMPILER PIN.  READ THIS BEFORE WRITING ANY C FOR THIS CLUSTER.
 * ============================================================================
 *
 * This cluster is split between the two front ends, and which half a function
 * falls in is decided by its SIZE and SHAPE, not by its address:
 *
 *   ../2.0/sp2   func_0206AFE4  func_0206B458  func_0206B4A0  func_0206B63C
 *                func_0206B6A4  func_0206B7D0  func_0206B94C  (and
 *                func_0206BF50 next door)
 *   1.1p1        func_0206AF08  func_0206AF74  func_0206B3D0  func_0206B780
 *                func_0206B7A8
 *
 * The 1.1p1 half is exactly the set of short leaves with no repeated literal
 * and no guard block short enough to predicate.  Everything longer is 2.0.
 * Two tells, both in docs/FRONTEND-PINS.md and both measured on members of
 * this cluster:
 *
 *   kept constants  1.1p1 hoists a literal that is live at more than one
 *                   point into a callee-saved register and rebuilds other
 *                   constants off it.  func_0206AFE4 is the clean case: the
 *                   clear length 0x58 goes to r4 and the -1 sentinel comes
 *                   back as `sub r0, r4, #0x59`, four bytes over the image.
 *   kept branches   1.1p1 -O4,p predicates any guard body of five
 *                   instructions or fewer.  func_0206B63C is the clean case:
 *                   the image's `tst r2, #0x100` / `beq` over a five-
 *                   instruction bitmap set becomes `asrne/andne/ldrne/orrne/
 *                   strne`, four bytes under.
 *
 * FOUR notes in docs/notes/ for this range spent whole passes measuring
 * respellings against those two walls before the pin was known
 * (func_0206B458, func_0206B7D0, pkt_0206AF08, pkt_0206AFE4 -- between them
 * some twenty rejected spellings).  In every case the C was already correct.
 * SYMPTOM TO RECOGNISE INSTANTLY: a compile that is four bytes off with every
 * instruction present, or a push/pop list one register wider than the image's.
 * Change the compiler, not the source.
 *
 * ISA: ARM throughout, which is itself a cluster property -- the ARM9 static
 * module is Thumb almost everywhere else.
 *
 * REFERENCE DOCUMENT ONLY.  Nothing includes this file; it is not part of any
 * translation unit and match.py never sees it.  Every declaration below is
 * derived from an EXACT/EXACT* file in src/matched, and the evidencing
 * function is named in the comment beside it.
 *
 * Addresses are Black-image addresses throughout.
 */

#ifndef CLUSTER_0206AF08_H
#define CLUSTER_0206AF08_H

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed   short s16;
typedef signed   int   s32;

/* ================================================================== *
 * PART 1: the channel list, 0x0206AF08..0x0206B4A0
 * ================================================================== */

/* One channel node.  Every field below is pinned by at least one EXACT file,
 * and all four walkers spell the layout identically.
 *
 * +0x04 (weight) is only read by func_0206AFE4, which compares it SIGNED
 * against 0 and against 0x1000 (`ble`, `bgt`), so it is s32 and 0x1000 is
 * 1.0 in 20.12 fixed point.
 * +0x19 (count) is the loop bound, read as a BYTE (`ldrb r0, [r2, #0x19]`).
 * Read into a `u32` index it gives the unsigned `bhs` of func_0206AF08; read
 * into an `int i` loop counter it gives the signed `ble`/`blt` of
 * func_0206B63C.  Both spellings are in matched files and both are right for
 * their own function -- do not unify them.
 * +0x1a (entries) is a u16 array indexed by the same index.  Bits 8-9 are a
 * two-bit kind field: (e & 0x300) == 0x100 is the "live" test every walker
 * makes, and e & 0xff is the argument handed to the callback. */
struct Node0206AF08 {
    u32  f00;
    s32  weight;              /* +0x04  func_0206AFE4: signed, 20.12       */
    u32  f08;
    void (*cb)(void *out, struct Node0206AF08 *self, u32 arg);
                              /* +0x0c  func_0206AF08                      */
    struct Node0206AF08 *next;/* +0x10  func_0206AF08                      */
    u8   pad14[5];
    u8   count;               /* +0x19  func_0206AF08: ldrb, the bound     */
    u16  v[1];                /* +0x1a  func_0206AF08                      */
};

#define NODE_KIND_MASK   0x300  /* func_0206AF08: the two-bit kind field   */
#define NODE_KIND_LIVE   0x100  /* func_0206AF08: the value that fires     */
#define NODE_ARG_MASK    0x0ff  /* func_0206AF08: the callback's argument  */

/* The accumulated transform func_0206AFE4 builds, 0x58 bytes.  The callbacks
 * write the same shape into a stack copy, which is why the blend can clear
 * the output with one MIi_CpuClearFast(0, out, 0x58).
 *
 * +0x00 is a flag word ANDed across every contributor (so a bit survives only
 * if every node set it); bits 1, 2, 4, 8 and 0x10 select which of the five
 * triples below are blended and which are taken as scalars.
 * +0x4c is the only triple whose product is taken 64-bit -- the image's
 * `smull` / `lsr #12` / `orr lsl #20` against the plain `mul` / `asr #12` of
 * the +0x28 and +0x34 arms.  That is what fixes the `(long long)` cast there
 * and forbids it elsewhere (func_0206AFE4). */
struct Acc0206AF08 {
    u32 flags;     /* +0x00  func_0206AFE4: ANDed across contributors      */
    s32 f04[3];    /* +0x04  blended by func_0206AF74, gate bit 0          */
    s32 f10[3];    /* +0x10  blended by func_0206AF74, gate bit 3          */
    s32 f1c[3];    /* +0x1c  blended by func_0206AF74, gate bit 4          */
    s32 f28[3];    /* +0x28  32-bit product, gate bit 1; a basis axis      */
    s32 f34[3];    /* +0x34  32-bit product, gate bit 1; a basis axis      */
    s32 f40[3];    /* +0x40  the third basis axis, built by VEC_CrossProduct */
    s32 f4c[3];    /* +0x4c  64-bit product, gate bit 2                    */
};

/* The three-word mix primitive.  `dst` MUST be spelled `volatile`: with a
 * plain `s32 *` mwcc groups the `flag` arm into three hoisted loads, three
 * adds and three stores, while the image is strictly sequential ldr/add/str
 * per word.  `src` must stay plain -- making it volatile too reverses the two
 * loads in the else arm.  (func_0206AF74, and the same lever closes the
 * `stm` fusion in func_0206B4A0 below.) */
extern void func_0206AF74(volatile s32 *dst, s32 *src, s32 v, int flag);

/* The four walkers.  All three integer results are 0/1 "did anything fire". */
extern int  func_0206AF08(u32 a0, struct Node0206AF08 *n, u32 idx);
extern int  func_0206AFE4(struct Acc0206AF08 *out,
                          struct Node0206AF08 *n, u32 idx);
extern int  func_0206B3D0(u32 *out, struct Node0206AF08 *n, u32 idx);
extern void func_0206B63C(u32 *bitmap, struct Node0206AF08 *n);

/* The fixed-point helpers func_0206AFE4 reaches for.  sub_0207C768 is the
 * hardware divider (a two-call wrapper, not compiled C); the two VEC_
 * routines are the SDK's. */
extern s32  sub_0207C768(s32 num, s32 den);              /* 0x0207C768 */
extern void VEC_CrossProduct(const s32 *a, const s32 *b, s32 *c); /* 0x0207CAE8 */
extern void VEC_Normalize(const s32 *a, s32 *b);         /* 0x0207CCA4 */
extern void MIi_CpuClearFast(u32 val, void *dst, u32 len);        /* 0x02082AC0 */
extern void MIi_CpuCopy32(const void *src, void *dst, u32 len);   /* 0x02082A90 */

/* ================================================================== *
 * PART 2: the script object, 0x0206B458..0x0206B7A8
 * ================================================================== */

/* The config record func_0206B4A0 unpacks.  +0x04 is the script blob (its own
 * header carries four self-relative offsets at +0x04/+0x08/+0x0c and a pair
 * of table keys at +0x15/+0x16); +0x30 is an OVERRIDE program pointer, used
 * verbatim when non-null, which is the detail an earlier pass read backwards
 * (docs/notes/pkt_0206AFE4.c.txt). */
struct Cfg0206B4A0 {
    u32   flags;              /* +0x00  four bits mirrored into the object */
    u8   *blob;               /* +0x04  the script blob                    */
    u8    pad08[0x20 - 0x08];
    u32   f20;                /* +0x20  optional slot value                */
    u8    f24;                /* +0x24  its index, bounded by 0x20         */
    u8    f25;                /* +0x25  its byte payload                   */
    u8    pad26[0x28 - 0x26];
    void (*hook)(void *obj);  /* +0x28  optional pre-run hook              */
    u8    pad2c[0x30 - 0x2c];
    u8   *pc_override;        /* +0x30  func_0206B4A0: used verbatim       */
};

/* The 0x188-byte script object.  +0x04 MUST be declared `volatile`: without
 * it every front end fuses the +0x00 and +0x04 stores into `stm r5, {r0, r4}`
 * and the constructor comes out four bytes short.  The source must also store
 * +0x04 BEFORE +0x00, the opposite of the image's order -- the scheduler
 * sinks it.  (func_0206B4A0.) */
struct Obj0206B458 {
    u8   *pc;                 /* +0x00  the program counter, stepped by
                               *        the opcode bodies                  */
    struct Cfg0206B4A0 *volatile cfg;   /* +0x04  volatile, see above      */
    u32   flags;              /* +0x08  bit 5 stops the loop, bit 6 is the
                               *        per-opcode re-entry mark           */
    u32   slots[0x20];        /* +0x0c  func_0206B4A0                      */
    u8    bytes[0x20];        /* +0x8c  func_0206B4A0                      */
    u8    padac[0xc4 - 0xac];
    u32   fc4;                /* +0xc4  set to 1 at construction           */
    u8    padc8[0xd4 - 0xc8];
    u8   *sec0;               /* +0xd4  blob + 0x40, or null               */
    u8   *sec1;               /* +0xd8  blob + blob[2], or null            */
    u8   *sec2;               /* +0xdc  blob + blob[3], or null            */
    u32   fe0;                /* +0xe0  blob[7]                            */
    u32   fe4;                /* +0xe4  blob[8]                            */
    u32   fe8;                /* +0xe8  g_020A829C[blob[0x15]]             */
    u32   fec;                /* +0xec  g_020A8290[blob[0x15]]             */
    u32   ff0;                /* +0xf0  g_020A82A8[blob[0x16]]             */
};

#define OBJ_FLAG_STOP    0x20   /* func_0206B458: bit 5, leave the loop    */
#define OBJ_FLAG_REENTER 0x40   /* func_0206B7D0: bit 6, the stop mark     */

/* The opcode dispatch table.  Indexed by the low five bits of the byte under
 * the program counter; the handler takes the object and the top three bits.
 * 14 witnesses image-wide, so it resolves as `data_table` (func_0206B458). */
typedef void (*Cb0206B458)(struct Obj0206B458 *obj, u32 arg);
extern Cb0206B458 g_020A83B8[];

/* The three table picks func_0206B4A0 makes, each its own pool word and so
 * its own object. */
extern u32 g_020A8290[];   /* func_0206B4A0: keyed by blob[0x15] -> +0xec  */
extern u32 g_020A829C[];   /* func_0206B4A0: keyed by blob[0x15] -> +0xe8  */
extern u32 g_020A82A8[];   /* func_0206B4A0: keyed by blob[0x16] -> +0xf0  */

/* The re-entrancy stash: non-null means an outer func_0206B6A4 frame already
 * owns a work area, so the inner call borrows it instead of building one. */
extern u32 g_02148DB0;     /* func_0206B6A4 */

extern void func_0206B458(struct Obj0206B458 *obj);   /* the interpreter   */
extern void func_0206B4A0(struct Obj0206B458 *obj,
                          struct Cfg0206B4A0 *cfg);   /* the constructor   */
extern void func_0206B6A4(void *p);                   /* the entry point   */

/* The two one-line opcode hooks.  Both hand the callback THE OBJECT ITSELF,
 * which is why the target lives in r1 and r0 still holds the object at the
 * `blx` -- reading them as no-argument callbacks is what left an earlier pass
 * three bytes out on each (docs/notes/pkt_0206AF08.c.txt). */
extern void func_0206B780(void *p);   /* +0x0c hook, then ++p->f00         */
extern void func_0206B7A8(void *p);   /* +0x10 hook, then p->f08 |= 0x20   */

/* ================================================================== *
 * PART 3: the opcode bodies, 0x0206B7D0..0x0206BEA0
 * ================================================================== */

/* The opcode object: the same 0x188-byte object as Part 2, seen through the
 * fields the bodies use.  The hook pointer and the state byte differ by one
 * slot between the two-byte and three-byte forms, which is the cleanest
 * single tell for which body you are looking at:
 *
 *   func_0206B94C  hook at +0x18, state at +0x8f, pc += 2
 *   func_0206B7D0  hook at +0x14, state at +0x8e, pc += 3
 *   func_0206BA18  hook at +0x1c, state at +0x90, no pc step (its operands
 *                  are passed in registers by the dispatcher)
 *
 * THE THREE-STOP SKELETON, identical in all three and worth writing out once:
 *
 *     st = p->hook ? p->state : 0;
 *     if (st == 1) { p->flags &= ~0x40; p->hook(p);
 *                    st = p->hook ? p->state : 0;
 *                    flag = p->flags & 0x40; } else flag = 0;
 *     if (flag == 0) { ...body A... }
 *     if (st == 2) { ...same re-entry as st == 1... } else flag = 0;
 *     if (flag == 0) { ...body B... }
 *     if (st == 3) { p->flags &= ~0x40; p->hook(p); }
 *
 * The ternary must be written where it stands, AFTER the field stores that
 * precede it: hoisting it is what 1.1p1 does and what costs func_0206B7D0
 * twelve bytes under the wrong front end. */

/* The record the three-argument form resolves and publishes, 0x38 bytes.
 * Reference only -- func_0206BA18 is still open and its two table pool words
 * (0x02148DB4, 0x020A1954) have no witness outside its own range, so it caps
 * at MATCH until some other user of either table is filed.  See the appended
 * section of docs/notes/func_0206B7D0.c.txt. */
struct Rec0206BA18 {
    u32 f00;       /* bits 0-4 are "field absent" marks, bit 5 a blob flag */
    u32 f04;       /* merged under g_020A1954[(src->f1e >> 6) & 7]         */
    u32 f08;       /* merged under g_020A1954[(src->f1e >> 9) & 7]         */
    u32 f0c;       /* merged under src->f10; bits 16-20 are the live mask  */
    u32 f10;
    u32 f14;
    u32 f18;
    u32 f1c;
    s16 f20;
    s16 f22;
    u32 f24;
    u32 f28;
    u16 f2c;
    u16 f2e;
    u32 f30;
    u32 f34;
};

extern u32 g_02148DB4[];   /* func_0206BA18: the module record table       */
extern u32 g_020A1954[];   /* func_0206BA18: the per-channel merge masks   */
extern u32 g_02148B4C[];   /* the rig register block of cluster_0206A17C;
                            * func_0206BA18 reads its +0x94/+0x98/+0x9c    */

extern void func_0206DDA4(u32 key, void *rec, u32 len);  /* 0x0206DDA4     */

extern void func_0206B7D0(void *p);   /* three-byte opcode                 */
extern void func_0206B94C(void *p);   /* two-byte opcode                   */
extern void func_0206BA18(void *p, u32 kind, void *src, u32 id);


/* ================================================================== *
 * WAVE 10 ADDENDUM (2026-09-22) -- func_0206BA18 EXACT (../2.0/sp2)
 * ================================================================== *
 * func_0206BA18 is EXACT as src/matched/func_0206BA18.c.  The two pool
 * words the note above called witness-less (0x02148DB4, 0x020A1954) now
 * resolve as sole-ref/self once the compile is byte-correct, so it is NOT
 * capped at MATCH.  This cluster is NitroSystem g3d's SBC interpreter:
 * func_0206B458 is the SBC loop, 0x020A83B8 the 32-entry opcode table,
 * func_0206BA18 = MAT's internal default body (rs, opFlag, matData,
 * idxMat), the Rec is NNSG3dMatAnmResult, the object's +0xd8 is the
 * NNSG3dResMat whose dictionary sits at +4.  Three levers closed it:
 *   - the material lookup is the NNS inline pair GetResDataByIdx
 *     (`dict && idx < numEntry` ? &hdr->data[0] + sizeUnit*idx : 0) and
 *     GetMatDataByIdx with the null test of the material block INSIDE the
 *     inline and ONE shared `return 0` (that is the image's lone
 *     `mov r1,#0` the old note could not reproduce);
 *   - the texture-matrix trailer tests are NEGATED, NNS style,
 *     `if (!(flag & SCALEONE)) copy; else res->flag |= 1;` -- the positive
 *     form does not if-convert the flag arm;
 *   - func_0206DDA4 is a packed geometry-command send, (op, data, n):
 *     cmd[0] = 0x00293130 (DIF_AMB, SPE_EMI, POLYGON_ATTR) is passed as op,
 *     cmd[4] = 0x2b2a (TEXIMAGE_PARAM, TEXPLTT_BASE).
 * The same GetResDataByIdx inline is what closed cluster_0206E62C.h.
 */

#endif /* CLUSTER_0206AF08_H */
