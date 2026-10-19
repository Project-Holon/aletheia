/*
 * function: SCRCMD_PROC_FLD_LoadItemRows
 * address:  0x021B3834
 * packet:   pkt_ov021_021B3834
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   FILE_UTIL_IsMachineItem  0x02021288  thumb
 */
#include "../include/Obj19995.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern u32 FILE_UTIL_IsMachineItem(u32 id);

u32 SCRCMD_PROC_FLD_LoadItemRows(u8 *p, int n)
{
    u32 r = FILE_UTIL_IsMachineItem(((struct Obj19995 *)p)->f0);
    int i;

    for (i = 0; i < n; i++) {
        FILE_UTIL_IsMachineItem(*(u16 *)(p + i * 8));
    }
    return r;
}
