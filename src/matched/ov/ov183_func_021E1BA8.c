/*
 * function: BR_CODEIN_ProfileApplyPendingStep
 * address: 0x021E1BA8
 * packet: pkt_ov183_021E1BA8
 * region: ov183
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * Extent remainder: zero alignment halfword at 021E1BFE.
 * symbols:
 *   BR_CODEIN_ProfileSetActorAnim 0x021E11D0 thumb ov183
 *   BR_CODEIN_ProfileUpdateActorVisible 0x021E0E4C thumb ov183
 *   BR_CODEIN_ProfileSetActorAnimFrame 0x021E0E90 thumb ov183
 *   BR_CODEIN_ProfileSetAnimSeq 0x021E1374 thumb ov183
 *   BR_CODEIN_ProfileSetActorPos 0x021E0D00 thumb ov183
 *   BR_CODEIN_ProfileClear 0x021E1C00 thumb ov183
 */
#include "../include/Obj00478.h"
extern void BR_CODEIN_ProfileSetActorAnim(char *,int);
extern void BR_CODEIN_ProfileUpdateActorVisible(char *);
extern void BR_CODEIN_ProfileSetActorAnimFrame(char *,int);
extern void BR_CODEIN_ProfileSetAnimSeq(char *,int);
extern void BR_CODEIN_ProfileSetActorPos(char *,int);
extern void BR_CODEIN_ProfileClear(char *);
void BR_CODEIN_ProfileApplyPendingStep(char *p)
{
    switch (((struct Obj00478 *)p)->f318) {
    case 0: break;
    case 1:
        BR_CODEIN_ProfileSetActorAnim(p,((struct Obj00478 *)p)->f31C);
        BR_CODEIN_ProfileUpdateActorVisible(p);
        BR_CODEIN_ProfileSetActorAnimFrame(p,1);
        BR_CODEIN_ProfileSetAnimSeq(p,2);
        ((struct Obj00478 *)p)->f318=255;
        break;
    case 2:
        BR_CODEIN_ProfileSetActorPos(p,((struct Obj00478 *)p)->f31C);
        BR_CODEIN_ProfileClear(p);
        break;
    case 255: break;
    }
}
