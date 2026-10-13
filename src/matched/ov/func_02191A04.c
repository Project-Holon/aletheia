/*
 * function: FIELD_MSGBG_CreateBgWin
 * address:  0x02191A04
 * packet:   pkt_02191A04
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail call passing the object, a pass-through argument and the word at +8.
 *
 * symbols:
 *   FIELD_MSGBG_CreateBgWinFont  0x02191A10  thumb  ov021
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj17935.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u32 *FIELD_MSGBG_CreateBgWinFont(u16 *a, u32 b, u32 c);

void FIELD_MSGBG_CreateBgWin(u8 *p, int a)
{
    FIELD_MSGBG_CreateBgWinFont((u16 *)p, a, ((struct Obj17935 *)p)->f8);
}
