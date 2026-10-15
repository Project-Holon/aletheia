/*
 * function: WIFICLUBACTOR_ExitLayer
 * address:  0x021B9DB0
 * packet:   pkt_021B95A0
 * region:   ov099
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   WF2DMAP_SCRDRAW_DeleteBitmapDesc  0x021C5A4C  thumb  ov127
 *
 * Tail call on the pointer 0x598 bytes in.
 */
#include "../include/Obj18155.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned long  u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed long    s32;
typedef int BOOL;

extern void WF2DMAP_SCRDRAW_DeleteBitmapDesc(u8 *p);

void WIFICLUBACTOR_ExitLayer(char *p)
{
    WF2DMAP_SCRDRAW_DeleteBitmapDesc(((struct Obj18155 *)p)->f598);
}
