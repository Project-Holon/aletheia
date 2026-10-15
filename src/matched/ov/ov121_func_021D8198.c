/*
 * function: MYSTERY_DeleteSaveMenu
 * address:  0x021D8198
 * packet:   pkt_021D8198
 * region:   ov121
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   MYSTERY_UTIL_DeleteMenu  0x021DA148  thumb
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj00326.h"

typedef unsigned int u32;

typedef unsigned char  u8;
extern void MYSTERY_UTIL_DeleteMenu(u8 *p);

void MYSTERY_DeleteSaveMenu(char *p)
{
    void *x = ((struct Obj00326 *)p)->f260;
    if (x != 0) {
        MYSTERY_UTIL_DeleteMenu(x);
        *(u32 *)&((struct Obj00326 *)p)->f260 = 0;
    }
}
