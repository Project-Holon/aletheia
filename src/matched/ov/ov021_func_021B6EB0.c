/*
 * function: SCRCMD_POKEMON_FLD_IsLibertyPassGift
 * address:  0x021B6EB0
 * packet:   pkt_ov021_021B6EB0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */
#include "../include/Obj12850.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

int SCRCMD_POKEMON_FLD_IsLibertyPassGift(u32 *o, int k)
{
    if (k != 2) {
        return 0;
    }
    if (((struct Obj12850 *)o)->fB0 != 0x7FE) {
        return 0;
    }
    if (o[0] == 0x23E) {
        return 1;
    }
    return 0;
}
