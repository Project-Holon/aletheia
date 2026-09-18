/*
 * function: func_0201F53C
 * address:  0x0201F53C
 * packet:   pkt_0201F4A0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 * symbols:
 *   tbl_0209E8C8  0x0209E8C8  data
 * Verified with:
 *   python tools/match.py one --src src/pending/func_0201F53C.c \
 *       --func func_0201F53C --addr 0x0201F53C --cc 1.1p1 --thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed short s16;
typedef signed char s8;

extern u8 tbl_0209E8C8[];

u32 func_0201F53C(u32 i)
{
    return tbl_0209E8C8[i];
}
