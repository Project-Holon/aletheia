/*
 * function: func_02169500
 * address:  0x02169500
 * packet:   pkt_02169500
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Copies a 12-byte record from q into p + 0x4.
 *
 * symbols:
 *   (none)

 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef struct S12 { u32 a, b, c; } S12;


void func_02169500(u8 *p, u8 *q)
{
    *(S12 *)(p + 0x4) = *(S12 *)q;
}

