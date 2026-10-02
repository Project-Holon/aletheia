/*
 * function: func_02158F90
 * address:  0x02158F90
 * packet:   pkt_02158F90
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Reads the word field at +0x8.
 *
 * symbols:
 *   (none)

 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;


void *func_02158F90(void *p)
{
    return *(void **)((u8 *)p + 0x8);
}

