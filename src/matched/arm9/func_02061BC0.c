/*
 * function: func_02061BC0
 * address:  0x02061BC0
 * packet:   pkt_0206123C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Returns the base pointer plus the +0xa halfword shifted left four.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02061BC0.c \
 *       --func func_02061BC0 --addr 0x02061BC0 --arm --cc 1.1p1
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

u32 func_02061BC0(u8 *p)
{
    return *(u32 *)p + ((u32)*(u16 *)(p + 0xa) << 4);
}
