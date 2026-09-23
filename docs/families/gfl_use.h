/*
 * docs/families/gfl_use.h -- shared declarations for the gfl_use.c family
 * (0x0200545C..0x020065FC in the ARM9 image; the __FILE__ anchor is the
 * string at 0x020A7004 "gfl_use.c", named by the pool word at 0x020055EC
 * inside sub_0200545C, see layout/file_anchors.txt line 5).
 *
 * REFERENCE DOCUMENT ONLY.  Nothing includes this file; it is not part of
 * any translation unit and match.py never sees it.  Every declaration below
 * is taken from an EXACT file in src/matched, named beside it.
 *
 * NOTE ON EXTENT.  The anchor's function sub_0200545C is the system boot
 * set-up (arenas, heaps, graphics, card and sound bring-up).  The span after
 * it is the system-record helpers (src/matched/unit_0200560C.c,
 * src/matched/unit_020056A0.c) and then a long run of small unrelated
 * accessors up to 0x020065FC.  The start is soft: 0x020051D8..0x02005454
 * (pkt_020051D8) is the same boot path and most likely the same file.
 *
 * LINKER VENEERS.  0x02005B6C (ldr pc,[pc,#-4] over 0x02704364) and the four
 * stubs 0x020053E4, 0x02005420, 0x02005428, 0x02005454 are mwld long-branch
 * veneers into the TWL-only arm9i module, which this project does not
 * extract.  They are not compiled from C and are not decompilation targets
 * (docs/idioms/a-four-byte-arm-function-in-a-thumb-packet-is-a-long-branch-veneer.md).
 */

#ifndef GFL_USE_H
#define GFL_USE_H

typedef unsigned int       u32;
typedef unsigned long long u64;

/* The system heaps record, pointed to by GflSys.heaps.
 * src/matched/unit_020056A0.c (seed/mul/add, +0x20 heap),
 * src/matched/unit_0200560C.c (+0x18..+0x24). */
struct GflHeaps {
    u64   seed;       /* +0x00  sub_020056EC / sub_02005728: 64-bit LCG state */
    u64   mul;        /* +0x08  LCG multiplier */
    u64   add;        /* +0x10  LCG increment */
    void *unk18;      /* +0x18  sub_0200545C: func_02030CBC(4, +0x1C) */
    void *unk1C;      /* +0x1C  sub_0200545C: func_02030734(..., 0x119) */
    void *unk20;      /* +0x20  sub_020056A0 / sub_020056BC: allocation heap */
    void *unk24;      /* +0x24  sub_0200545C: func_02030734(..., 0x11C) */
};

/* The system record at 0x020AA194.  src/matched/unit_0200560C.c,
 * src/matched/unit_020056A0.c, src/matched/func_0200567C.c. */
struct GflSys {
    void *unk00;              /* +0x00  hook argument (sub_02005640) */
    u32   unk04;              /* +0x04  extra heap id (sub_0200545C) */
    void (*unk08)(void *);    /* +0x08  hook (sub_02005640, sub_02005654) */
    u32   unk0C;              /* +0x0C  cleared at the end of boot */
    struct GflHeaps *heaps;   /* +0x10  func_02030734(0, 0x28, ...) result */
    void *unk14;              /* +0x14  0x3F00-byte block from OS_AllocFromHeap */
};
extern struct GflSys g_020AA194;

/* Heap allocator (time_icon.c tail), src/matched/unit_020056A0.c. */
extern void *func_02030DA8(void *heap, u32 size, u32 align, u32 tag);
extern void  func_02030D28(void *heap);
extern void  func_0203F034(void);
extern void  func_0203F258(void *heap);

/* _ull_mul, MSL runtime (layout/runtime_arm9.txt), ARM. */
/* 0x0209C054 */

#endif /* GFL_USE_H */
