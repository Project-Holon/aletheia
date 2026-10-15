/*
 * function: GTSNEGO_MSG_SetDecide
 * address:  0x021D8638
 * packet:   pkt_021D8638
 * region:   ov120
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * blocker:  MATCH (tail-call ABS32 to 0x0202822C: no witness outside the range; the only reference image-wide is this pool word)
 *
 * symbols:
 *   APP_TASKMENU_WIN_SetDecide  0x0202822C  thumb
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj22848.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

extern void APP_TASKMENU_WIN_SetDecide(char *p, int v);

void GTSNEGO_MSG_SetDecide(u8 *p)
{
    APP_TASKMENU_WIN_SetDecide(((struct Obj22848 *)p)->fC4, 1);
}
