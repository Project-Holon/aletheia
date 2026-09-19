/*
 * function: func_02036D64
 * address:  0x02036D64
 * packet:   pkt_02036CA8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

u32 func_02036D64(u8 *p)
{
    switch (p[0xd]) {
    case 1:
        return ((*(u16 *)0x04000304 & 0x8000) >> 15) == 1 ? 1 : 2;
    case 2:
        return ((*(u16 *)0x04000304 & 0x8000) >> 15) == 1 ? 2 : 1;
    }
    return 1;
}
