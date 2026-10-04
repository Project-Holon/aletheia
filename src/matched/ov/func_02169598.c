/*
 * function: func_02169598
 * address:  0x02169598
 * packet:   pkt_02169598
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Reads the word field at +0x2c.
 *
 * symbols:
 *   (none)

 * Addresses are Black-image addresses.
 */
#include "../include/Obj17745.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;


u32 func_02169598(u8 *p)
{
    return ((struct Obj17745 *)p)->f2C;
}

