/*
 * function: func_020436FC
 * address:  0x020436FC
 * packet:   pkt_0204361C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * TU: bmp.c (__FILE__ 0x020A7E68, line 123).
 *
 * Wrap a pixel buffer the caller already owns in a fresh descriptor: same
 * 0xc-byte descriptor func_02043678 builds, but nothing is allocated for
 * the pixels and the kind byte at +0x0a is 1.  The heap id is the fifth
 * argument and arrives on the stack as a halfword.
 *
 * symbols:
 *   func_02030734  0x02030734  arm
 *   bmp_File       0x020A7E68  data
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020436FC.c  *       --func func_020436FC --addr 0x020436FC --cc 1.1p1 --arm
 */

typedef unsigned short u16;
typedef unsigned int   u32;

struct Bmp {
    void *pixels; /* 0x00 */
    u16   width;  /* 0x04 */
    u16   height; /* 0x06 */
    u16   depth;  /* 0x08 */
    u16   kind;   /* 0x0a */
};

extern const char bmp_File[];

extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);

struct Bmp *func_020436FC(void *pixels, u32 width, u32 height, u32 depth,
                            u16 heap)
{
    struct Bmp *bmp;

    bmp = func_02030734(heap, sizeof(struct Bmp), 0, bmp_File, 123);

    bmp->width  = width * 8;
    bmp->height = height * 8;
    bmp->pixels = pixels;
    bmp->depth  = depth;
    bmp->kind   = 1;

    return bmp;
}
