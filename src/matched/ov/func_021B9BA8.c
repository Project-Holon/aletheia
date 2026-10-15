/*
 * function: WIFICLUBACTOR_IsCursorFree
 * address:  0x021B9BA8
 * packet:   pkt_021B95A0
 * region:   ov099
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   WF2DMAP_OBJ_GetSlot  0x021C49A4  thumb  ov127
 *
 * True when the object 0x570 bytes in is not of class 5.
 */
#include "../include/Obj18150.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned long  u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed long    s32;
typedef int BOOL;

extern int WF2DMAP_OBJ_GetSlot(u8 *p, unsigned int i);

BOOL WIFICLUBACTOR_IsCursorFree(char *p)
{
    if (WF2DMAP_OBJ_GetSlot(*(void **)((struct Obj18150 *)p)->f570, 5) == 0) {
        return 1;
    }

    return 0;
}
