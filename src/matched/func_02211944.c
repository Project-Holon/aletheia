/*
 * function: func_02211944
 * address:  0x02211944
 * packet:   pkt_02211944
 * region:   ov198
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;

void func_02211944(u8 **p)
{
    u32 i;

    for (i = 0; i < 3; i++) {
        *(u8 *)(*p + i + 0x48) = 0xff;
    }
}

