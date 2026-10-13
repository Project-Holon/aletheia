/*
 * function: BMP_Create
 * address:  0x02043678
 * packet:   pkt_0204361C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * TU: bmp.c.  The __FILE__ pointer at 0x020A7E68 reads "bmp.c", lines 97
 * and 103 here.
 *
 * Allocate a bitmap descriptor and its pixel buffer on the same heap.  The
 * width and height reach the descriptor multiplied by 8 (they arrive in
 * tiles), the buffer is width * height * depth bytes, and the descriptor is
 * allocated uncleared while the buffer is cleared.  The `__FILE__` pointer
 * is reloaded into r3 for the second call rather than kept, because r3 is
 * an argument register.
 *
 * symbols:
 *   func_02030734  0x02030734  arm
 *   bmp_File       0x020A7E68  data
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/BMP_Create.c \
 *       --func BMP_Create --addr 0x02043678 --cc 1.1p1 --arm
 */

typedef unsigned short u16;
typedef unsigned int   u32;

struct Bmp {
    void *pixels; /* 0x00 */
    u16   width;  /* 0x04 */
    u16   height; /* 0x06 */
    u16   depth;  /* 0x08 */
    u16   unk0a;  /* 0x0a */
};

extern const char bmp_File[];

extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);

struct Bmp *BMP_Create(u32 width, u32 height, u32 depth, u16 heap)
{
    struct Bmp *bmp;

    bmp = func_02030734(heap, sizeof(struct Bmp), 0, bmp_File, 97);

    bmp->width  = width * 8;
    bmp->height = height * 8;
    bmp->depth  = depth;

    bmp->pixels = func_02030734(heap, depth * (width * height), 1,
                                bmp_File, 103);
    bmp->unk0a = 0;

    return bmp;
}
