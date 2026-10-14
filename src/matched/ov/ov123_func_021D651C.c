/*
 * function: GSYNC_DISP_EnableActorAutoAnim
 * address:  0x021D651C
 * packet:   pkt_021D651C
 * region:   ov123
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   CLACT_SetActorAutoAnim  0x0204B92C  arm
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj22950.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

struct Obj;
extern void CLACT_SetActorAutoAnim(struct Obj *p, u32 v);

void GSYNC_DISP_EnableActorAutoAnim(u8 *p)
{
    CLACT_SetActorAutoAnim(((struct Obj22950 *)p)->fA8, 1);
}
