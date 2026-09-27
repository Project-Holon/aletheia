/*
 * function: func_02009F0C
 * address:  0x02009F0C
 * packet:   pkt_02009EDC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02009F0C.c \\
 *       --func func_02009F0C --addr 0x02009F0C --thumb --cc 1.1p1
 */

typedef unsigned char u8;
typedef unsigned int  u32;



u32 func_02009F0C(u32 a)
{
    if (a != 0 && a < 4) {
        return 1;
    }
    return 0;
}
