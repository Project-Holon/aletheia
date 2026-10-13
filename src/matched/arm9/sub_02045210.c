/*
 * function: BMP_WIN_Alloc
 * address:  0x02045210
 * packet:   pkt_020445F4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 *
 * status:   EXACT
 *
 * symbols:
 *   g_02146A50     0x02146A50  data
 *   str_020A7E70   0x020A7E70  data
 *   func_02030734  0x02030734  arm
 *   func_02043678  0x02043678  arm
 *
 * The constructor shared by BMP_WIN_Create and BMP_WIN_CreateAt: build the
 * sixteen-byte descriptor for one BG layer on the subsystem heap recorded by
 * BMP_WIN_Init, fill in its geometry, and attach the tile buffer
 * func_02043678 hands back.
 *
 *   +0x00  u16  two bitfields: a 15-bit tag set to 0x7fb2, and the 8bpp
 *               flag in bit 15
 *   +0x02  u8   layer
 *   +0x03  u8   screen base
 *   +0x04  u8   character base
 *   +0x05  u8   width in tiles       (also at +0x07)
 *   +0x06  u8   height in tiles      (also at +0x08)
 *   +0x09  u8   palette
 *   +0x0a  u16  character offset in VRAM
 *   +0x0c  void *tile buffer
 *
 * The tag is one 15-bit field, not two adjacent fields of 8 and 7 bits:
 * splitting it produces two read-modify-writes (bic #0xff / orr #0xb2 then
 * bic #0x7f00 / orr #0x7f00) instead of the single masked write the original
 * has, where the constant 0x7fb2 needs two `orr`s only because it is not one
 * ARM immediate.  The 8bpp bit is a second read-modify-write because its
 * assignment is separated from the tag by the byte stores.
 *
 * The width parameter is u8, not u32: assigning a u32 to the two u8 width
 * fields makes the compiler materialise `(u8)width` once with `and #0xff`
 * and store that register twice, where the original stores the incoming
 * register directly.  Same for the width argument of func_02043678.
 *
 * The 0xffff8000 mask is materialised as `sub r0, fp, #0x8000` off the
 * register already holding the allocator's zero third argument, the
 * rematerialisation idiom in
 * docs/idioms/a-small-constant-is-rematerialised-off-a-zero-register-unless-an-argument-shares-it.md.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/BMP_WIN_Alloc.c \
 *       --func BMP_WIN_Alloc --addr 0x02045210 --cc 1.1p1 --arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct BgLayer {
    u16 tag : 15;
    u16 is8bpp : 1;
    u8  layer;
    u8  screenBase;
    u8  charBase;
    u8  width;
    u8  height;
    u8  width2;
    u8  height2;
    u8  palette;
    u16 charOffset;
    void *tiles;
};

extern u16 *g_02146A50;
extern const char str_020A7E70[];

struct Bmp;
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern struct Bmp *func_02043678(u32 width, u32 height, u32 depth, u16 heap);

struct BgLayer *BMP_WIN_Alloc(u32 layer, u32 screenBase, u32 charBase,
                             u8 width, u8 height, u8 palette, u32 charOffset,
                             u8 is8bpp)
{
    struct BgLayer *o;
    u32 tileSize = is8bpp == 0 ? 0x20 : 0x40;

    o = func_02030734(*g_02146A50, 0x10, 0, str_020A7E70, 0xd5);

    o->tag = 0x7fb2;
    o->layer = layer;
    o->screenBase = screenBase;
    o->charBase = charBase;
    o->width = width;
    o->height = height;
    o->width2 = width;
    o->height2 = height;
    o->palette = palette;
    o->charOffset = charOffset;
    o->is8bpp = is8bpp;

    o->tiles = func_02043678(width, height, tileSize, *g_02146A50);
    return o;
}
