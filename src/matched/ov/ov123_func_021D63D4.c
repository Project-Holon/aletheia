/*
 * function: GSYNC_DISP_SetMainActorAnimSeq
 * address:  0x021D63D4
 * packet:   pkt_021D63D4
 * region:   ov123
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   CLACT_SetActorAnimSeq  0x0204B878  arm
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj22949.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

struct Obj;
extern void CLACT_SetActorAnimSeq(struct Obj *p, u16 value);

void GSYNC_DISP_SetMainActorAnimSeq(u8 *p)
{
    CLACT_SetActorAnimSeq(((struct Obj22949 *)p)->fA8, 2);
}
