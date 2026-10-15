/*
 * function: MANUAL_COMMON_UpdateTouchbar
 * address: 0x021B9FBC
 * packet: pkt_ov225_021B9FBC
 * region: ov225
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   MANUAL_COMMON_UpdateTouchbarSlots 0x021BA240 thumb ov225
 *   TOUCHBAR_Update 0x021B63D0 thumb ov067
 *   TOUCHBAR_GetPressedButtonIdIfPressing 0x021B6470 thumb ov067
 *   TOUCHBAR_GetPressedButtonIdIfDone 0x021B6448 thumb ov067
 *   MANUAL_COMMON_UpdateTouchbarActors 0x021BA508 thumb ov225
 *   gManualCommonTouchbarButtonIds 0x021BBF2C data a4
 */
#include "../include/Obj00367.h"
typedef unsigned char u8;
typedef struct S S;
struct Entry {unsigned word[7];};
extern const struct Entry gManualCommonTouchbarButtonIds[];
extern void MANUAL_COMMON_UpdateTouchbarSlots(char *);
extern void TOUCHBAR_Update(struct S *p);
extern int TOUCHBAR_GetPressedButtonIdIfPressing(u8 *);
extern int TOUCHBAR_GetPressedButtonIdIfDone(u8 *);
extern void MANUAL_COMMON_UpdateTouchbarActors(char *);
void MANUAL_COMMON_UpdateTouchbar(char *p)
{
    ((struct Obj00367 *)p)->f24=-1;((struct Obj00367 *)p)->f28=-1;MANUAL_COMMON_UpdateTouchbarSlots(p);
    if(((struct Obj00367 *)p)->f20==1) {((struct Obj00367 *)p)->f20=0;return;}
    if(((struct Obj00367 *)p)->f20==0 || ((struct Obj00367 *)p)->f20==2) {
        TOUCHBAR_Update(*(S * *)&((struct Obj00367 *)p)->f4);
        if(((struct Obj00367 *)p)->f20==0) {
            int result=TOUCHBAR_GetPressedButtonIdIfPressing(*(u8 * *)&((struct Obj00367 *)p)->f4);
            if(result!=-1) {((struct Obj00367 *)p)->f20=2;((struct Obj00367 *)p)->f24=result;}
        } else {
            int result=TOUCHBAR_GetPressedButtonIdIfDone(*(u8 * *)&((struct Obj00367 *)p)->f4);
            if(result!=-1) {((struct Obj00367 *)p)->f20=1;((struct Obj00367 *)p)->f28=result;}
        }
    }
    if(((struct Obj00367 *)p)->f20==0 || ((struct Obj00367 *)p)->f20==3) {
        MANUAL_COMMON_UpdateTouchbarActors(p);
        if(((struct Obj00367 *)p)->f20==0) {
            if(((struct Obj00367 *)p)->f44==1) {((struct Obj00367 *)p)->f20=3;*(unsigned *)&((struct Obj00367 *)p)->f24=gManualCommonTouchbarButtonIds[*(u8 *)(p+0x40)].word[0];}
        } else {
            if(((struct Obj00367 *)p)->f44==3) {((struct Obj00367 *)p)->f20=1;*(unsigned *)&((struct Obj00367 *)p)->f28=gManualCommonTouchbarButtonIds[*(u8 *)(p+0x40)].word[0];}
        }
    }
}
