/*
 * function: MANUAL_COMMON_SetTouchbarState
 * address: 0x021BA068
 * packet: pkt_ov225_021BA068
 * region: ov225
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   TOUCHBAR_SetButtonVisible 0x021B6558 thumb ov067
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 *   MANUAL_COMMON_ResetTouchbar 0x021BA644 thumb ov225
 *   MANUAL_COMMON_DrawTouchbarIdle 0x021BA28C thumb ov225
 *   MANUAL_COMMON_DrawTouchbarStart 0x021BA2B0 thumb ov225
 *   MANUAL_COMMON_DrawTouchbarEnd 0x021BA30C thumb ov225
 */
#include "../include/Obj03964.h"
struct Obj;
extern void TOUCHBAR_SetButtonVisible(unsigned char *p, unsigned int id, unsigned int v);
extern void CLACT_SetActorDrawEnable(struct Obj *,unsigned);
extern void MANUAL_COMMON_ResetTouchbar(char *);
extern void MANUAL_COMMON_DrawTouchbarIdle(char *);
extern void MANUAL_COMMON_DrawTouchbarStart(char *);
extern void MANUAL_COMMON_DrawTouchbarEnd(char *);
void MANUAL_COMMON_SetTouchbarState(char *p,unsigned state)
{
    if(((struct Obj03964 *)p)->f8==state)return;
    switch(((struct Obj03964 *)p)->f8) {
    case 0:TOUCHBAR_SetButtonVisible(((struct Obj03964 *)p)->f4,0,0);break;
    case 3:CLACT_SetActorDrawEnable(*(struct Obj * *)&((struct Obj03964 *)p)->f38,0);CLACT_SetActorDrawEnable(*(struct Obj * *)&((struct Obj03964 *)p)->f3C,0);break;
    case 1:case 2:case 4:break;
    }
    ((struct Obj03964 *)p)->f8=state;MANUAL_COMMON_ResetTouchbar(p);
    switch(((struct Obj03964 *)p)->f8) {
    case 0:TOUCHBAR_SetButtonVisible(((struct Obj03964 *)p)->f4,0,1);MANUAL_COMMON_DrawTouchbarIdle(p);break;
    case 1:MANUAL_COMMON_DrawTouchbarStart(p);break;
    case 2:MANUAL_COMMON_DrawTouchbarEnd(p);break;
    case 3:case 4:break;
    }
}
