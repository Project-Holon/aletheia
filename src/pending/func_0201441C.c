/*
 * function: func_0201441C
 * address:  0x0201441C
 * packet:   pkt_0201441C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 *
 * symbols:
 *   tbl_0209E050  0x0209E050  data
 * Verified with:
 *   python tools/match.py one --src src/pending/func_0201441C.c \
 *       --func func_0201441C --addr 0x0201441C --cc 1.1p1 --thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed short s16;
typedef signed char s8;

extern u8 tbl_0209E050[];

u32 func_0201441C(u32 i)
{
    return tbl_0209E050[i];
}
