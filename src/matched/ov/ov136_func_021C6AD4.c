/*
 * function: MB_SEQ_StateFadeWait
 * address:  0x021C6AD4
 * packet:   pkt_021C6AD4
 * region:   ov136
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   WIPE_SYS_EndCheck  0x020221A4  thumb
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj23607.h"
#include "../include/Obj23608.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

extern u32 WIPE_SYS_EndCheck(void);

int MB_SEQ_StateFadeWait(u8 *p)
{
    if (WIPE_SYS_EndCheck() == 1)
        return ((struct Obj23608 *)((u8 *)((struct Obj23607 *)p)->f8))->f308;
    return 2;
}
