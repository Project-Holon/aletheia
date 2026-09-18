/*
 * function: func_02014A10
 * address:  0x02014A10
 * packet:   pkt_02014628
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 * symbols:
 *   tbl_0209E054  0x0209E054  data
 * Verified with:
 *   python tools/match.py one --src src/pending/func_02014A10.c \
 *       --func func_02014A10 --addr 0x02014A10 --cc 1.1p1 --thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed short s16;
typedef signed char s8;

extern u32 tbl_0209E054[];

u32 func_02014A10(u32 i)
{
    return (u16)tbl_0209E054[i];
}
