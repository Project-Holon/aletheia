/*
 * function: PDWACC_MESSAGE_DeleteButtonManager
 * address:  0x021D92B8
 * packet:   pkt_021D92B8
 * region:   ov123
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
#include "../include/Obj10453.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

extern void BUTTON_MAN_Delete(void *);

void PDWACC_MESSAGE_DeleteButtonManager(u8 *p)
{
    if (((struct Obj10453 *)p)->f1C) {
        BUTTON_MAN_Delete(((struct Obj10453 *)p)->f1C);
        *(u32 *)&((struct Obj10453 *)p)->f1C = 0;
    }
}
