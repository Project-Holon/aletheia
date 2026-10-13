/*
 * function: func_021D5950
 * address:  0x021D5950
 * packet:   pkt_021D5950
 * region:   ov123
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   MSGDATA_ReadString  0x02045CAC  arm
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj13972.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

extern int MSGDATA_ReadString(void *, int, void *);

int func_021D5950(u8 *p, int x)
{
    return MSGDATA_ReadString(((struct Obj13972 *)p)->f20, x, ((struct Obj13972 *)p)->f2C);
}
