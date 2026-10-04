/*
 * function: func_02158F78
 * address:  0x02158F78
 * packet:   pkt_02158F78
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Reads the word field at +0x30.
 *
 * symbols:
 *   (none)

 * Addresses are Black-image addresses.
 */
#include "../include/Obj17632.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;


u32 func_02158F78(u8 *p)
{
    return ((struct Obj17632 *)p)->f30;
}

