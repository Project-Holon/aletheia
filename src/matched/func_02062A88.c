/*
 * function: func_02062A88
 * address:  0x02062A88
 * packet:   pkt_0206296C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * *
 * One-field offset-to-pointer fixup for the second 'RAHC' consumer, same fixup: the u32 at +0x14 is a
 * self-relative offset that becomes an absolute pointer.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02062A88.c  *       --func func_02062A88 --addr 0x02062A88 --cc 1.1p1
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;


void func_02062A88(u8 *block)
{
    *(u32 *)(block + 0x14) = *(u32 *)(block + 0x14) + (u32)block;
}
