/*
 * function: BSUBWAY_SCR_IsWinMax
 * address:  0x021C9FD0
 * packet:   pkt_ov021_021C9FD0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Latches bit 0 of +0xc once the +0x70 object's count reaches 7.
 *
 * symbols:
 *   GDS_PROFILE_GetFieldRecCount03  0x0200DA54  thumb
 * Addresses are Black-image addresses.
 */
#include "../include/Obj20232.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct {
    u8  pad0[0xc];
    u16 done : 1;
    u16 rest : 15;
} Latch;

struct Blk3C;
extern u16 GDS_PROFILE_GetFieldRecCount03(struct Blk3C *p);

int BSUBWAY_SCR_IsWinMax(u8 *p)
{
    if (((Latch *)p)->done == 0) {
        if (GDS_PROFILE_GetFieldRecCount03((struct Blk3C *)(((struct Obj20232 *)p)->f70)) < 7)
            return 0;
        ((Latch *)p)->done = 1;
    }
    return 1;
}
