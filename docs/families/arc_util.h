/*
 * docs/families/arc_util.h -- the arc_util.c family (NARC helpers), around
 * 0x0204A28C..0x0204A48C in the ARM9 image; ARM code, not Thumb.  The
 * __FILE__ string is at 0x020A7F30 (literal class, 14 references).
 *
 * REFERENCE DOCUMENT ONLY; nothing includes it.  Written 2026-09-23 (wave 15
 * tail lane) from src/matched/func_0204A39C.c.
 */

#ifndef ARC_UTIL_H
#define ARC_UTIL_H

typedef unsigned short u16;
typedef unsigned int   u32;

extern const char lbl_020A7F30[];                       /* "arc_util.c" */

extern u32   func_020493D4(void *narc, int fileId);      /* member size */
extern void  func_0204932C(void *narc, int fileId, void *dest); /* read member */
extern void *func_02030734(u32 heapId, u32 size, u32 align, const char *file, u32 line);
extern void  func_020307B0(void *ptr);                  /* free */
extern void  MI_UncompressLZ8(const void *src, void *dest);     /* 0x020834C0 */

/* Load member fileId; if decompress, allocate from the heap's other end
 * ((heapId & 0x7fff) | 0x8000, line 1709) and LZ8-expand into a second
 * block (line 1725), freeing the packed one; otherwise line 1713.  Heap ids
 * are u32 parameters narrowed with (u16) at every use (lsl/lsr #16 each time). */
extern void *func_0204A39C(void *narc, int fileId, int decompress, u32 heapId, u32 *out_size);

#endif /* ARC_UTIL_H */
