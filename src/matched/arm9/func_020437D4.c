/*
 * function: func_020437D4
 * address:  0x020437D4
 * packet:   pkt_0204361C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * TU: bmp.c.  Accessor for the pixel buffer of a bitmap descriptor.
 * Saves no lr, so disasm.py leaves it unlabelled and it prints inside a run
 * of `.word`s; it is kept as its own file rather than folded into a unit so
 * that its callers have a `matched` witness.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020437D4.c  *       --func func_020437D4 --addr 0x020437D4 --cc 1.1p1 --arm
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

void *func_020437D4(const struct Bmp *bmp)
{
    return bmp->pixels;
}
