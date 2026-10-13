/*
 * function: FIELD_PLAYER_CORE_WaitModelReady
 * address:  0x021A39E4
 * packet:   pkt_ov021_021A39E4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FIELD_PLAYER_CORE_GetMmdl  0x021A3960  thumb  ov021
 *   FLDMMDL_CallDrawGetProc  0x0216D7A8  thumb  ov010
 */
#include "../include/Obj12729.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

void *FIELD_PLAYER_CORE_GetMmdl(u8 *p);
int FLDMMDL_CallDrawGetProc(void *p, unsigned int v);

int FIELD_PLAYER_CORE_WaitModelReady(u8 *p)
{
    if (FLDMMDL_CallDrawGetProc(FIELD_PLAYER_CORE_GetMmdl(p), 0) != 0xFFFF) {
        if (((struct Obj12729 *)p)->f2C == 1)
            return 1;
        (((struct Obj12729 *)p)->f2C)++;
    }
    return 0;
}
