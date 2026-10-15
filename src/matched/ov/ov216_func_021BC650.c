/*
 * function: BEACON_DETAIL_GRA_CreateDetailActors
 * address: 0x021BC650
 * packet: pkt_ov216_021BC650
 * region: ov216
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   BEACON_DETAIL_GRA_GetClactUnit 0x021BCA38 thumb ov216
 *   BEACON_DETAIL_GRA_CreatePositionedActor 0x021BC614 thumb ov216
 *   CLACT_SetActorPaletteOffset 0x0204B6F4 arm
 */
#include "../include/Obj00366.h"
typedef unsigned int   u32;
struct Obj;
extern void *BEACON_DETAIL_GRA_GetClactUnit(char *p);
extern unsigned BEACON_DETAIL_GRA_CreatePositionedActor(unsigned short *p, unsigned manager, unsigned *r, short x, short y, unsigned char z, unsigned char a, unsigned char b, unsigned short flag);
extern void CLACT_SetActorPaletteOffset(struct Obj *o, u32 v, u32 flag);
void BEACON_DETAIL_GRA_CreateDetailActors(char *p)
{
    void *q=BEACON_DETAIL_GRA_GetClactUnit(((struct Obj00366 *)p)->f50);
    void *a=(void *)BEACON_DETAIL_GRA_CreatePositionedActor((short unsigned int *)p,(unsigned int)q,(unsigned int *)(p+0x80),128,120,0,0,2,0);
    ((struct Obj00366 *)p)->f264=a;
    CLACT_SetActorPaletteOffset(a,0,1);
    ((struct Obj00366 *)p)->f268=(void *)BEACON_DETAIL_GRA_CreatePositionedActor((short unsigned int *)p,(unsigned int)q,(unsigned int *)(p+0x5c),96,120,0,1,2,0);
}
