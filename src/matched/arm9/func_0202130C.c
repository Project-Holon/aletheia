/*
 * unit:     no
 * address:  0x0202130C
 * packet:   pkt_02020D5C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: func_0202130C
 *
 * symbols:
 *   func_02021288  0x02021288  thumb
 *
 * Maps an id in one of func_02021288's two accepted windows onto a byte-wide
 * slot number, in three ranges with three different subtrahends: 0x26A.. off
 * 0x20E, 0x1A4..0x269 off 0x145, and the rest off 0x148.  Ids the window test
 * rejects answer 0xFF.
 *
 * Only two pool words: 0x26A is loaded once and 0x1A4 derived from it with
 * `subs r0, #0xc6`, the same constant-sharing func_020212B0 does.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0202130C.c \
 *       --func func_0202130C --addr 0x0202130C --cc 1.1p1 --thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u32 func_02021288(u32 id);

u32 func_0202130C(u32 id)
{
    if (func_02021288(id) == 0) {
        return 0xFF;
    }
    if (id >= 0x26A) {
        return (u8)(id - 0x20E);
    }
    if (id >= 0x1A4) {
        return (u8)(id - 0x145);
    }
    return (u8)(id - 0x148);
}
