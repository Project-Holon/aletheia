/*
 * function: func_0216E434
 * address:  0x0216E434
 * packet:   pkt_0216E434
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Classify an id: 1 for the eight 'special' values, the id itself otherwise.
 *
 * symbols:
 *   (none)
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
u32 func_0216E434(u32 a)
{
switch (a) {
case 4:
case 5:
case 6:
case 7:
case 8:
case 11:
case 12:
case 13:
return 1;
}
return a;
}
