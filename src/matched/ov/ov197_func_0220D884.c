/*
 * function: B_BAG_MAIN_CheckCancel
 * address:  0x0220D884
 * packet:   pkt_0220D884
 * region:   ov197
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */
#include "../include/Obj25114.h"
#include "../include/Obj25115.h"
#include "../include/Obj25116.h"

typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

int B_BAG_MAIN_CheckCancel(char **p)
{
    if (((struct Obj25114 *)(*p))->f20 == 1) {
        ((struct Obj25115 *)(*p))->f16 = 0;
        ((struct Obj25116 *)(*p))->f18 = 0;
        return 1;
    }
    return 0;
}
