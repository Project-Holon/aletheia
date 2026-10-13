/*
 * function: func_021D652C
 * address:  0x021D652C
 * packet:   pkt_021D652C
 * region:   ov123
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   CLACT_SetActorAnimSeq  0x0204B878  arm
 *   CLACT_SetActorAutoAnim  0x0204B92C  arm
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj13977.h"

typedef unsigned int u32;

typedef unsigned short u16;
struct Obj;
extern void CLACT_SetActorAnimSeq(struct Obj *p, u16 value);
extern void CLACT_SetActorAutoAnim(struct Obj *p, u32 v);

void func_021D652C(char *p)
{
    CLACT_SetActorAnimSeq(((struct Obj13977 *)p)->fA8, 1);
    CLACT_SetActorAutoAnim(((struct Obj13977 *)p)->fA8, 1);
}
