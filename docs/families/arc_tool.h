/*
 * docs/families/arc_tool.h -- shared declarations for the arc_tool.c family.
 *
 * REFERENCE DOCUMENT ONLY.  Nothing includes this file; it is not part of any
 * translation unit and `match.py` never sees it.  It is the adjudicated union
 * of the declarations the family's byte-exact sources already carry, written
 * down once so a new attempt on an open function starts from the settled shape
 * instead of re-deriving it.
 *
 * Family: original source file **arc_tool.c**, 0x02048D54..0x0204A17C in the
 * ARM9 image (edges fuzzy by a function or two; 0x02048C58/0x02048CEC, the
 * name-table installer, is probably the head).  The file name is the
 * __FILE__ string at 0x020A7EE0, passed by func_02048D54 (line 0xbb),
 * func_02048E34 (0xfb), func_02048F9C (0x182), sub_020490F4 (0x209),
 * func_0204913C (0x21f) and the bounds asserts of func_02049250..func_02049578
 * (613, 619, 642, 665, 689, 713, 725): monotone in address, one TU.
 *
 * ISA: ARM throughout (always pass --arm).  Compiler: 1.1p1, no pin needed.
 *
 * Derived from the matched sources found with
 *   grep -l "address:  0x0204[89A]" src/matched/*.c
 * restricted to the range (37 files, 54 functions), plus wave 13's
 * func_02049A18.c and func_02049C28.c.
 *
 * ADJUDICATION RULE USED THROUGHOUT.  A load or store instruction constrains a
 * field; a name does not.  `and rN, rM, #0xff` in front of a call is the
 * CALLEE's u8 parameter (sub_0204968C, func_02049A18), not a cast in the
 * caller; `ldrh` of an incoming stack slot names a u16 parameter
 * (sub_02049658, func_02049B90); an `and`/`orr` then `lsl #16`/`lsr #16` on
 * the flag word is the u16 fourth parameter of func_0204A1BC / func_0204A380.
 */

#ifndef ARC_TOOL_H
#define ARC_TOOL_H

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

/* ------------------------------------------------------------------ *
 * 1.  The archive handle
 * ------------------------------------------------------------------ */

/* A 0x48-byte FSFile, optionally followed by arc_tool's own bookkeeping.
 * Stack-allocated (0x48) by the one-shot readers func_02048D54,
 * func_02048F9C, func_02049030, func_020490A8; heap-allocated (0x50) by the
 * persistent openers sub_020490F4 / func_0204913C, whose header walk
 * func_0204919C fills the three tail fields:
 *   +0x48  image base (u32)        -- FAT offset + FAT size + FNT delta
 *   +0x4C  FAT offset (u16)        -- read from file +0x0C, 2 bytes, into a
 *                                     zeroed u32/u16 so the top half is clear
 *   +0x4E  member count (u16)      -- func_0204961C returns it
 * (func_02049250, func_0204932C, func_020493D4, func_0204944C,
 *  func_020494F4, func_02049578 all spell exactly this struct). */
struct ArcFile {
    u8  file[0x48];
    u32 imageBase;          /* +0x48 */
    u16 fatOffset;          /* +0x4C */
    u16 count;              /* +0x4E */
};

/* A FAT entry is {u32 start, u32 end} at fatOffset + 0xC + member * 8; the
 * member's bytes begin at imageBase + 8 + start and run end - start.  Readers
 * that need only the start read 4 bytes, not 8 (func_0204944C,
 * func_020494F4, func_02049578). */

/* The archive-id table global (unit_02048DDC.c).  unk08 == 0: unk00 is the
 * 235-entry path table, opened by name; else unk00 is an array of 8-byte
 * {start, end} extents opened from memory.  `u32 * volatile unk00` and a
 * `volatile u32 end` are both load-bearing in func_02048DDC (see its header).
 * unit_02048C58.c spells it as three plain u32 (right for the writer). */
struct ArcIdTable {
    u32 * volatile unk00;
    u32            unk04;
    u32            unk08;
};
extern struct ArcIdTable g_02146A68;            /* 0x02146A68 */

extern const char sArcToolFile[];               /* 0x020A7EE0 "arc_tool.c" */
/* assertion texts: 0x020A7EEC (func_02048E34), 0x020A7F18 (func_02049250) */

/* ------------------------------------------------------------------ *
 * 2.  Resource blocks the loader layer hands out (0x02062xxx lookups)
 * ------------------------------------------------------------------ */

/* func_02062A4C / func_02062A00 fill a caller-owned pointer; the local is
 * re-read after every call (sub_0204979C, sub_0204982C). */
struct ArcRes {
    u8  pad_00[0x10];
    u32 unk_10;             /* the object's own size: "size 0 means this" */
    u32 unk_14;             /* data address */
};

/* func_02062B30's palette block (func_02049A18). */
struct ArcPal {
    u8  pad_00[0x08];
    u32 size;               /* +0x08 default size */
    u8  data[1];            /* +0x0C entries, u16 or u8 */
};

/* func_02062A98's PLTT block and func_02062AD4's PMCP count (func_02049C28).
 * Declare the out locals PLTT first, PMCP second: PMCP at sp+0. */
struct ArcPltt {
    u32 fmt;                /* +0x00  3 selects 0x20 bytes per PMCP unit,
                               anything else 0x200 */
    u8  pad_04[0x04];
    u32 size;               /* +0x08 */
    u32 data;               /* +0x0C advanced by the caller's offset */
};

/* ------------------------------------------------------------------ *
 * 3.  Prototypes, as the matched sources carry them
 * ------------------------------------------------------------------ */

/* One-shot readers over a stack handle */
extern void  func_02048D00(void *dst, u32 archive_id, u32 member, u32 mode,
                           u32 *size_out);
extern void *func_02048D54(u32 archive_id, u32 member, u32 heap, u32 mode,
                           u32 *size_out);
extern void  func_02048DDC(struct ArcFile *arc, u32 id);     /* bind by id */
extern u32   func_02048E34(struct ArcFile *arc, u32 member, u32 base,
                           u32 size);                        /* seek + size */
extern void  func_02048F4C(void *dst, u32 archive_id, u32 member);
extern void *func_02048F60(u32 archive_id, u32 member, u32 heap);
extern void  func_02048F74(void *dst, u32 archive_id, u32 member, u32 mode,
                           u32 *size_out);
extern void *func_02048F88(u32 archive_id, u32 member, u32 heap, u32 mode,
                           u32 *size_out);
extern void *func_02048F9C(const char *path, u32 member, u32 heap);
extern u32   func_02049030(u32 archive_id);                  /* member count */
extern u32   func_020490A8(u32 archive_id, u32 member);      /* member size  */

/* Persistent handles (0x50 bytes) */
extern void *sub_020490F4(u32 archive_id, u32 heap);
extern void *func_0204913C(void *mem, u32 len, u32 heap);
extern void  func_0204919C(struct ArcFile *arc);             /* header walk */
extern void *func_02049250(struct ArcFile *arc, u32 member, u32 heap);
extern void  func_0204932C(struct ArcFile *arc, u32 member, void *dst);
extern u32   func_020493D4(struct ArcFile *arc, u32 member);
extern void  func_0204944C(struct ArcFile *arc, u32 member, u32 offset,
                           u32 size, void *dst);
extern void  func_020494F4(struct ArcFile *arc, u32 member, u32 *out);
extern u32   func_02049578(struct ArcFile *arc, u32 member);
extern void  func_020495F4(struct ArcFile *arc, u32 size, void *dst);
extern u16   func_0204961C(struct ArcFile *arc);             /* count */

/* Resource loaders (the flag word's top bit forced on in the '...8000' twins) */
extern void *func_0204A1BC(u32 a0, u32 a1, u32 a2, u16 flags);
extern void *func_0204A380(u32 a0, u32 a1, u32 a2, u16 flags);

/* Graphics upload workers and their front ends */
extern u32  sub_0204968C(void *res, u32 a1, u32 a2, u32 size);
extern u32  sub_0204979C(void *res, u32 a1, u32 size);       /* packed handle */
extern u32  sub_0204982C(void *res, u32 kind, u32 a2, u32 size);
extern void func_02049A18(void *res, u32 channel, u32 a2, u32 add, u32 size,
                          u32 flag);                         /* EXACT wave 13 */
extern void func_02049C28(void *res, u32 kind, u32 offset, u32 dest,
                          u32 size);                         /* EXACT wave 13 */
/* The ten bind-then-hook helpers of unit_02049DB4.c and func_0204A03C..
 * func_0204A17C all read: res = loader(a0, a1, a2, flags); if (res &&
 * !hook(res, a3)) { free(res); return 0; } return res; */

/* Loader-layer lookups (0x02062xxx) and the release */
extern s32  func_02062A4C(void *res, struct ArcRes **out);
extern s32  func_02062A00(void *res, struct ArcRes **out);
extern int  func_02062B30(void *res, struct ArcPal **out);
extern int  func_02062A98(void *res, struct ArcPltt **out);
extern int  func_02062AD4(void *res, u16 **pmcp);
extern void func_020307B0(void *p);         /* spelled ENV_SetResourceSet in
                                               some siblings; it is the heap
                                               free */

/* Channel queries / uploads: ALL take a u8 channel (the caller's `and #0xff`) */
extern int  func_0204169C(u8 channel);      /* nonzero = 8-bit entries */
extern int  func_0204162C(u8 channel);
extern void func_02040AF0(u8 channel, void *data, u32 size, u32 a);
extern void func_020409E0(u8 channel, void *data, u32 size, u32 a);
extern void func_020409B4(u8 channel);
extern void func_02041B6C(u8 channel);
extern void func_02040B1C(u8 a0, u32 a1, u32 a2, u32 a3);

/* Tables */
extern void (*g_020A135C[])(u32 addr, u32 a1, u32 size);  /* 5 entries, MATCH
                                               blocker of sub_0204982C */
extern void (*g_020A1364[])(u32 data, u32 dest, u32 size);/* 8 entries, by
                                               kind, func_02049C28 */

/* ------------------------------------------------------------------ *
 * 4.  Shapes this family keeps repeating
 * ------------------------------------------------------------------ *
 *  - Bounds asserts pass TWO variadic values (count, member); the count is
 *    free in r3 from the guard's own cmp and only the member reaches the stack
 *    (docs/idioms/a-free-variadic-argument-is-the-value-the-guard-compared.md).
 *  - "size 0 means the object's own size" is written by reassigning the SIZE
 *    PARAMETER, never a new local (sub_0204968C, sub_0204982C, func_02049A18,
 *    func_02049C28 -- the last one closed on exactly this).
 *  - Pairs of wrappers calling one worker are kept in separate files so each
 *    attests the other (func_02048F4C/F74, func_02048F60/F88,
 *    func_02049B90/BDC).
 *  - Block-scoped loop counters, declared before the element pointer
 *    (func_02049A18).
 */

#endif /* ARC_TOOL_H */
