/*
 * function: WIFI_2DCHAR_SetActorDrawPriority
 * address:  0x021C4214
 * packet:   pkt_021C4214
 * region:   ov127
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   CLACT_SetActorDrawPriority  0x0204B800  arm
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj23014.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

struct Node;
extern void CLACT_SetActorDrawPriority(struct Node *node, u32 val);

void WIFI_2DCHAR_SetActorDrawPriority(u8 *p, u32 v)
{
    CLACT_SetActorDrawPriority(((struct Obj23014 *)p)->f4, (u8)v);
}
