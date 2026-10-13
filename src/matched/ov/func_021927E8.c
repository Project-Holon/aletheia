/*
 * function: FIELD_MSGBG_ExitCursor
 * address:  0x021927E8
 * packet:   pkt_021927E8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Clears the leading byte and tail calls on the word at +4.
 *
 * symbols:
 *   BMP_Delete  0x020437AC  arm
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj12068.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Obj020437AC;
extern void BMP_Delete(struct Obj020437AC *p);

void FIELD_MSGBG_ExitCursor(u32 *p)
{
    ((struct Obj12068 *)p)->f0 = 0;
    BMP_Delete((struct Obj020437AC *)p[1]);
}
