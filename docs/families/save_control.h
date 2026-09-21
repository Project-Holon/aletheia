/*
 * docs/families/save_control.h -- shared declarations for the
 * save_control.c family (0x02006F20..0x02007A80 in the ARM9 image).  The
 * __FILE__ anchor the constructor passes is sub_02006F20_File (see
 * docs/notes/func_02006F20.c.txt); the assertion helpers further down the
 * range pass the empty string at 0x020A7064 instead.
 *
 * The family is the save-stream CONTROL BLOCK: one 0x38-byte object,
 * allocated once by func_02006F20 and parked in the module pointer
 * sub_02006F20_Ptr, that tracks nine independent save streams in its
 * +0x14 slot array.  Three layers share the file:
 *
 *   0x02006F20..0x020071CC  CONSTRUCTION AND WHOLE-BLOCK POLICY: the
 *                           constructor, the overlay-assisted mode probe,
 *                           and the bulk open/close passes that walk all
 *                           nine slots.
 *   0x020071CC..0x02007454  PER-SLOT STREAM OPS: open one slot, close one
 *                           slot, test whether a slot is open, and fetch a
 *                           slot's buffer.  This is where the wave-6 work
 *                           landed.
 *   0x02007454..0x02007A80  THE BOXED-RECORD ACCESSORS: a 0x3E0-byte
 *                           header with a 0x22-word entry array, reached
 *                           through the slot pointers above.
 *
 * REFERENCE DOCUMENT ONLY.  Nothing includes this file; it is not part of
 * any translation unit and match.py never sees it.  Every declaration below
 * is derived from a file in src/matched that is EXACT, and the matched
 * function that evidences each field or parameter is named in the comment
 * beside it.
 *
 * Addresses are Black-image addresses throughout (docs/AGENT-BRIEF.md
 * section 8).  Nothing here encodes a guess about the White layout.  The
 * nine-slot count and the 0x18-byte descriptor stride are content
 * constants and are flagged as such where they appear.
 */

#ifndef SAVE_CONTROL_H
#define SAVE_CONTROL_H

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

/* ------------------------------------------------------------------ *
 * 1.  THE CONTROL BLOCK  (0x38 bytes)
 *
 * func_02006F20 allocates it with func_02030734(heap, 0x38, 1, file,
 * 0x58) and stores the pointer to sub_02006F20_Ptr.  The layout below is
 * corroborated by SIX independent matched files, which is why it is the
 * canonical spelling here: src/matched/unit_020071CC.c, unit_020072A4.c,
 * unit_02007324.c, func_02007168.c, func_0200725C.c and func_020072CC.c
 * all declare the same offsets.
 * ------------------------------------------------------------------ */
struct SaveCtrl {
    u8    unk00;        /* +0x00  "idle/ready" flag, set to 1 by the
                         *        constructor and cleared on the
                         *        load-needed paths; func_02006F20 */
    u8    unk01;        /* +0x01  "load pending" flag, the mirror of unk00;
                         *        func_02006F20, func_020070C8 */
    u8    unk02;        /* +0x02  "clean" flag, set to 1 by the constructor
                         *        and cleared by state 1; func_02006F20 */
    u8    unk03;        /* +0x03  not written by any matched source */
    u8    unk04;        /* +0x04  mode, from the overlay probe
                         *        func_021DFE90(); func_02006F20 */
    u8    unk05;        /* +0x05  sub-mode, from func_021DFE98(ov);
                         *        func_02006F20 */
    u8    pad06[6];     /* +0x06  unwritten; unit_020071CC.c spells the gap
                         *        this way, func_02007168.c spells the same
                         *        region unk06/unk07 + u32 unk08 */
    u32   unk0C;        /* +0x0C  the STATUS BITMASK.  Bit 0 is "state 2",
                         *        bit 11 (0x800) is "sub-mode 1", and bits
                         *        2..10 are the per-slot failure bits the
                         *        nine-slot loops set: slot i owns bit
                         *        i + 2.  func_02006F20, func_020070C8 */
    void *unk10;        /* +0x10  the backup-system handle from
                         *        func_0203192C(g_0209D938, heap);
                         *        func_02006F20, func_020070C8 */
    void *unk14[9];     /* +0x14  the NINE STREAM SLOTS.  Content constant:
                         *        nine is the slot count in Black.  A slot
                         *        is non-null exactly while its stream is
                         *        open; unit_020072A4.c asserts non-null
                         *        before closing.  func_0200725C,
                         *        func_020072CC, unit_020072A4,
                         *        unit_02007324 */
};

/* ------------------------------------------------------------------ *
 * 2.  THE STREAM DESCRIPTOR TABLE  (0x18 bytes per entry, at 0x0209D950)
 *
 * A flat array indexed by slot id; the open functions compute
 * &table[id] with an explicit `id * 0x18` multiply.  Content constant:
 * the 0x18 stride.  Evidence: func_0200725C.c, func_020072CC.c and
 * unit_02007324.c, which each carry their own pool word for the base.
 * ------------------------------------------------------------------ */
struct SaveDesc {
    u8 data[0x18];
};

extern struct SaveDesc  g_SaveDescTable[];  /* 0x0209D950 */
extern struct SaveCtrl *sub_02006F20_Ptr;   /* the module singleton */

/* ------------------------------------------------------------------ *
 * 3.  PROTOTYPES, with the parameter types the bytes actually constrain.
 *
 * TYPE NOTE, established in wave 6 and true of the whole family: a HEAP ID
 * is u8, not u32, in this file's own definitions.  Narrowing the PARAMETER
 * is what reproduces the original's spill schedule in func_0200725C and
 * func_020072CC; a u32 parameter with a u8 local copy, or a u8 in the
 * callee prototype alone, both stay DIFF.  The matched CALLERS
 * (src/matched/unit_0200B4E0.c, unit_0200B5CC.c) declare the same
 * arguments u32; that is a caller-side widening, and the conflict is
 * recorded rather than silently resolved.
 * ------------------------------------------------------------------ */

/* construction and whole-block policy */
struct SaveCtrl *func_02006F20(int heap);                 /* the constructor */
int   func_020070C8(struct SaveCtrl *c);                  /* bulk re-open pass */

/* per-slot stream ops */
u32   func_0200725C(struct SaveCtrl *c, u32 id, u8 heap);
u32   func_020072CC(struct SaveCtrl *c, u32 id, u8 heap,
                    void *buf, u32 size);
void  func_020072A4(struct SaveCtrl *c, u32 id);          /* close one slot */
void  sub_02007324(struct SaveCtrl *c, u32 id, u32 heap,
                   u32 a, u32 b);                         /* unit_02007324.c */
void  sub_0200734C(struct SaveCtrl *c, u32 id);           /* unit_02007324.c */
u32   func_02008784(struct SaveCtrl *c, u32 id);          /* is slot open? */
u32  *func_020087D4(struct SaveCtrl *c, u32 id);          /* slot's buffer */

/* ------------------------------------------------------------------ *
 * 4.  THE BACKUP-SYSTEM EDGE
 *
 * ARGUMENT-ORDER NOTE, established in wave 6: func_02031DC0's second and
 * third arguments are (heap, buf), NOT (buf, heap).  The image names the
 * order directly -- heap is loaded into r1 from its stack home while the
 * func_020087D4 result is dereferenced into r2 -- and getting it backwards
 * leaves a flat 5-byte residue that no statement reordering, temporary or
 * type change can move (tools/permuter.py could not shift it in 74 and 90
 * mutations respectively).  src/matched/func_02031DC0.c spells its own
 * parameters (Obj *, u32 a1, u32 a2); this is which of the two is heap.
 * ------------------------------------------------------------------ */
extern void *func_0203192C(struct SaveDesc *desc, u32 heap);
extern void *func_02031948(struct SaveDesc *desc, u8 heap, void *buf,
                           u32 size, u32 c);
extern int   func_02031DC0(void *stream, u32 heap, u32 buf);
extern void  func_0203195C(void *stream);

#endif /* SAVE_CONTROL_H */
