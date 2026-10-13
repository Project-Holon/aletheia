/*
 * function: WIFICLUB_DeleteTouchBar
 * address:  0x021BB4D0
 * packet:   pkt_021B95A0
 * region:   ov099
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   TOUCHBAR_Delete  0x021B639C  thumb  ov067
 *
 * Releases the pointer 0x9AC bytes into the block and clears the slot.
 */
#include "../include/Obj00008.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned long  u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed long    s32;
typedef int BOOL;

extern void TOUCHBAR_Delete(u8 *p);

void WIFICLUB_DeleteTouchBar(char *p)
{
    void *q = ((struct Obj00008 *)p)->f9AC;

    if (q != 0) {
        TOUCHBAR_Delete(q);
        ((struct Obj00008 *)p)->f9AC = 0;
    }
}
