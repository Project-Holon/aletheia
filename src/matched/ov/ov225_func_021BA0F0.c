/*
 * function: MANUAL_COMMON_SetTouchbarSelection
 * address: 0x021BA0F0
 * packet: pkt_ov225_021BA0F0
 * region: ov225
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * trailing: 021BA152..021BA154 zero alignment padding, inspected in full show.
 * symbols:
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 *   MANUAL_COMMON_DrawTouchbarIdle 0x021BA28C thumb ov225
 *   MANUAL_COMMON_DrawTouchbarContinue 0x021BA368 thumb ov225
 */
#include "../include/Obj01788.h"
typedef unsigned char u8;
struct Obj;
extern void CLACT_SetActorDrawEnable(struct Obj *,unsigned);
extern void MANUAL_COMMON_DrawTouchbarIdle(char *);
extern void MANUAL_COMMON_DrawTouchbarContinue(char *);
void MANUAL_COMMON_SetTouchbarSelection(char *p,unsigned b,unsigned c)
{
    p[0xc]=b;p[0xd]=c;
    if(((struct Obj01788 *)p)->f8==3) {
        if(((struct Obj01788 *)p)->fC<=1) {
            CLACT_SetActorDrawEnable(*(struct Obj * *)&((struct Obj01788 *)p)->f38,0);CLACT_SetActorDrawEnable(*(struct Obj * *)&((struct Obj01788 *)p)->f3C,0);MANUAL_COMMON_DrawTouchbarIdle(p);return;
        }
        if(((struct Obj01788 *)p)->fD==0) {
            CLACT_SetActorDrawEnable(*(struct Obj * *)&((struct Obj01788 *)p)->f38,0);CLACT_SetActorDrawEnable(*(struct Obj * *)&((struct Obj01788 *)p)->f3C,1);
        } else if(((struct Obj01788 *)p)->fD==b-1) {
            CLACT_SetActorDrawEnable(*(struct Obj * *)&((struct Obj01788 *)p)->f38,1);CLACT_SetActorDrawEnable(*(struct Obj * *)&((struct Obj01788 *)p)->f3C,0);
        } else {
            CLACT_SetActorDrawEnable(*(struct Obj * *)&((struct Obj01788 *)p)->f38,1);CLACT_SetActorDrawEnable(*(struct Obj * *)&((struct Obj01788 *)p)->f3C,1);
        }
        MANUAL_COMMON_DrawTouchbarContinue(p);
    }
}
