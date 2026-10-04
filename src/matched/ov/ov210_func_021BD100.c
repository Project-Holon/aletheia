/*
 * function: func_021BD100
 * address:  0x021BD100
 * packet:   pkt_021BD100
 * region:   ov210
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02021ED8  0x02021ED8  thumb
 *
 * blocker: +0006 THM_CALL func_02021ED8       -> unresolved: 02021ED8 (arm, from name) has no witness outside 021BD100..021BD116
 * Addresses are Black-image addresses.
 */
#include "../include/Obj14675.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 func_02021ED8(const char *ptr);

u32 func_021BD100(u8 *p)
{
    if (func_02021ED8((const char *)(((struct Obj14675 *)p)->fC)) == 0) {
        return ((struct Obj14675 *)p)->f1C;
    }
    return 2;
}

