/*
 * docs/families/savedata.h -- shared declarations for the savedata.c family
 * (0x02033908..0x02033BF8 in the ARM9 image; __FILE__ anchor "savedata.c" at
 * 0x020A78CC, referenced from 0x020339B0, 0x02033A80, 0x02033B5C and
 * 0x02033BA4 per layout/file_anchors.txt).
 *
 * REFERENCE DOCUMENT ONLY.  Nothing includes this file; it is not part of any
 * translation unit and match.py never sees it.  Every declaration is taken
 * from a file in src/matched that is EXACT, named beside it.
 *
 * Addresses are Black-image addresses throughout.
 */

#ifndef SAVEDATA_H
#define SAVEDATA_H

typedef unsigned char u8;
typedef unsigned int  u32;

/* One entry of the caller's block table, 0xc bytes: the id (checked against
 * its own index), and at +4 the size callback func_02033A3C calls.
 * func_02033A3C, func_02033A88. */
struct SaveSrc { u32 id; u32 (*size)(void); u32 w08; };

/* One entry of the computed layout, 0xc bytes: id, size, offset.
 * func_02033A88 writes size and offset with one `stmib`. */
struct SaveDst { u32 id; u32 size; u32 offset; };

/* The 0x1c-byte table header func_02033908 allocates and fills. */
struct SaveTable {
    struct SaveSrc *src;   /* +0x00  func_02033908 a1 */
    u32 count;             /* +0x04  func_02033908 a2; bound of every loop */
    u32 f08;               /* +0x08  func_02033908 a4; base added to the total */
    u32 f0c;               /* +0x0c  func_02033A88: the computed end */
    u32 f10;               /* +0x10  func_02033908 a3; the limit asserted */
    struct SaveDst *dst;   /* +0x14  func_02033908: count * 12 bytes, heap */
    u32 f18;               /* +0x18  func_02033908 a6 */
};

/* Size of block i, rounded up to 4; asserts i < count (line 0x85). */
extern u32 func_02033A3C(struct SaveTable *p, u32 i);

/* Lay the blocks out: each offset is the running total, each step adds
 * v + size rounded up to 0x100; then f0c = f08 + total + f18 and assert it
 * fits under f10 (line 0xb3).  The assert helper at 0x02034734 takes FIVE
 * arguments (file, line, message, value, limit); reading it as four is what
 * kept this function DIFF until wave 16. */
extern void func_02033A88(struct SaveTable *p, u32 v);

/* The two assertion helpers used across the family (ARM). */
extern void func_02034714(const u8 *file, int line, const u8 *msg);
extern void func_02034734(const u8 *file, int line, const u8 *msg,
                          u32 v, u32 limit);

#endif /* SAVEDATA_H */
