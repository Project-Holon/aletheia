/*
 * function: func_0204A39C
 * address:  0x0204A39C
 * packet:   pkt_0204A39C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * symbols:
 *   func_020493D4    0x020493D4 arm
 *   func_02030734    0x02030734 arm
 *   func_0204932C    0x0204932C arm
 *   MI_UncompressLZ8 0x020834C0 arm
 *   func_020307B0    0x020307B0 arm
 *   lbl_020A7F30     0x020A7F30 data
 *
 * arc_util.c: load one archive member into a fresh heap block, optionally
 * LZ8-decompressing it into a second block.  ARM, not Thumb (the old
 * pending file compiled Thumb and read ISA).
 *
 * Shape facts the image fixes: the allocation is written in both arms of
 * the decompress test (the image cross-jumps them onto one call, with
 * *out_size re-read at the join); the heap id is a u32 narrowed at each
 * use; the NULL check wraps the rest rather than returning early, so every
 * exit shares `mov r0, r4; pop`; on a failed second allocation the result
 * is the NULL block (buf = d unconditionally).  The decompressing arm is
 * line 1709 and the plain arm 1713: the pool order says so.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0204A39C.c  *       --func func_0204A39C --addr 0x0204A39C --arm --cc 1.1p1
 */
#include "../include/Obj16076.h"

typedef unsigned int u32;
typedef unsigned short u16;

struct ArcFile;
extern u32 func_020493D4(struct ArcFile *arc, u32 member);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void func_0204932C(struct ArcFile *arc, u32 member, void *dst);
extern void MI_UncompressLZ8(const void *src, void *dest);
extern void func_020307B0(void *ptr);
extern const char lbl_020A7F30[];

void *func_0204A39C(void *narc, int fileId, int decompress, u32 heapId, u32 *out_size)
{
    void *buf;
    void *d;

    *out_size = func_020493D4(narc, fileId);
    if (decompress != 0) {
        buf = func_02030734((u16)(((u16)heapId & 0x7FFF) | 0x8000), *out_size, 0, lbl_020A7F30, 1709);
    } else {
        buf = func_02030734((u16)heapId, *out_size, 0, lbl_020A7F30, 1713);
    }
    if (buf != 0) {
        func_0204932C(narc, fileId, buf);
        if (decompress != 0) {
            *out_size = ((struct Obj16076 *)buf)->f0 >> 8;
            d = func_02030734((u16)heapId, *out_size, 0, lbl_020A7F30, 1725);
            if (d != 0) {
                MI_UncompressLZ8(buf, d);
                func_020307B0(buf);
            }
            buf = d;
        }
    }
    return buf;
}
