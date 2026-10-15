/*
 * function: FIELD_MSGBG_ReleaseSysFrame
 * address:  0x02190378
 * packet:   pkt_ov021_02190378
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BG_SYS_FreeLayerBuf  0x020403F4  arm  arm9
 */
#include "../include/Obj09473.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

extern void BG_SYS_FreeLayerBuf(u32 i);

int FIELD_MSGBG_ReleaseSysFrame(u8 *a)
{
    if (((struct Obj09473 *)a)->f4 != 0xff) {
        BG_SYS_FreeLayerBuf((u8)(((struct Obj09473 *)a)->f4));
        ((struct Obj09473 *)a)->f4 = 0xff;
        return 1;
    }
    return 0;
}
