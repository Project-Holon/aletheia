/*
 * function: GURU2_MAIN_StateToPlay
 * address:  0x021DF050
 * packet:   pkt_021DF050
 * region:   ov137
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GFL_NET_SYSTEM_GetCurrentAid  0x02039338  arm
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj23754.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

extern u16 GFL_NET_SYSTEM_GetCurrentAid(void);

int GURU2_MAIN_StateToPlay(u8 *p)
{
    GFL_NET_SYSTEM_GetCurrentAid();
    ((struct Obj23754 *)p)->f0 = 0x1b;
    return 0;
}
