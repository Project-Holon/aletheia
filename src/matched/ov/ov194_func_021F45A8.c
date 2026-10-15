/*
 * function: NAMEIN_GRAPHIC_IsNameValid
 * address:  0x021F45A8
 * packet:   pkt_021F45A8
 * region:   ov194
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   NAMEIN_GRAPHIC_GetLength 0x021F23F4 thumb
 *   NAMEIN_GRAPHIC_GetSecondaryLength 0x021F23F8 thumb
 *   NAMEIN_GRAPHIC_HasNonSpace 0x021F253C thumb
 */
#include "../include/Obj24919.h"

typedef unsigned int   u32;
typedef unsigned char  u8;
extern u32 NAMEIN_GRAPHIC_GetLength(const u8 *p);
extern u32 NAMEIN_GRAPHIC_GetSecondaryLength(const u8 *p);
extern int NAMEIN_GRAPHIC_HasNonSpace(u8 *p);

int NAMEIN_GRAPHIC_IsNameValid(int p)
{
    int *q = *(int * *)&((struct Obj24919 *)p)->f2C4;

    if (*q == 0 || *q == 3) {
        if (NAMEIN_GRAPHIC_GetLength((const u8 *)(p + 0x68)) == 0 && NAMEIN_GRAPHIC_GetSecondaryLength((const u8 *)(p + 0x68)) == 0) {
            return 0;
        }
        if (NAMEIN_GRAPHIC_HasNonSpace((u8 *)(p + 0x68)) == 0) {
            return 0;
        }
    }
    return 1;
}
