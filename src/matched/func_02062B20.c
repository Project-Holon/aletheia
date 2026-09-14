/*
 * function: func_02062B20
 * address:  0x02062B20
 * packet:   pkt_0206296C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * *
 * One-field offset-to-pointer fixup for the palette bank ('TTLP' / NCLR body): the u32 at +0xc is a
 * self-relative offset that becomes an absolute pointer.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02062B20.c  *       --func func_02062B20 --addr 0x02062B20 --cc 1.1p1
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;


void func_02062B20(u8 *block)
{
    *(u32 *)(block + 0xc) = *(u32 *)(block + 0xc) + (u32)block;
}
