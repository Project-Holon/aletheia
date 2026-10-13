/*
 * function: func_021D7710
 * address:  0x021D7710
 * packet:   pkt_021D7710
 * region:   ov120
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BUTTON_MAN_Delete  0x02051C6C  arm
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj10401.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

extern void BUTTON_MAN_Delete(void *);

void func_021D7710(u8 *p)
{
    if (((struct Obj10401 *)p)->f8) {
        BUTTON_MAN_Delete(((struct Obj10401 *)p)->f8);
        *(u32 *)&((struct Obj10401 *)p)->f8 = 0;
    }
}
