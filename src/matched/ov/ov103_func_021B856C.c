/*
 * function: IRC_COMPATIBLE_TOUCH_TEST_HandleSecondTouch
 * address: 0x021B856C
 * packet: pkt_ov103_021B856C
 * region: ov103
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 * IRC_APPBAR_GetResult 0x021B7250 thumb ov101
 * IRC_APPBAR_IsBusy 0x021B727C thumb ov101
 * IRC_COMPATIBLE_TOUCH_TEST_SetFinished 0x021B8358 thumb ov103
 * IRC_COMPATIBLE_TOUCH_TEST_PollTouchHeld 0x021B8D9C thumb ov103
 * IRC_COMPATIBLE_TOUCH_TEST_RecordStroke 0x021B91B4 thumb ov103
 * IRC_COMPATIBLE_TOUCH_TEST_IsStrokeFinished 0x021B9214 thumb ov103
 * IRC_COMPATIBLE_TOUCH_TEST_ClearStroke 0x021B91A8 thumb ov103
 * IRC_COMPATIBLE_TOUCH_TEST_PrintMessage 0x021B8138 thumb ov103
 * IRC_COMPATIBLE_TOUCH_TEST_PrintMessageWithName 0x021B824C thumb ov103
 * IRC_COMPATIBLE_TOUCH_TEST_LoadGuideScreens 0x021B9060 thumb ov103
 * IRC_COMPATIBLE_TOUCH_TEST_GetMarkers 0x021B7954 thumb ov103
 * IRC_COMPATIBLE_TOUCH_TEST_SetMarkerActive 0x021B8CA0 thumb ov103
 * IRC_COMPATIBLE_TOUCH_TEST_SetMarkerPosition 0x021B8CB0 thumb ov103
 * IRC_COMPATIBLE_TOUCH_TEST_SetHandler 0x021B8338 thumb ov103
 * IRC_COMPATIBLE_TOUCH_TEST_HandleThirdTouch 0x021B8728 thumb ov103
 * IRC_COMPATIBLE_TOUCH_TEST_HandleFirstTouch 0x021B8364 thumb ov103
 * IRC_COMPATIBLE_TOUCH_TEST_HandleAbort 0x021B8A44 thumb ov103
 * COMPATIBLE_IRC_SYS_GetValueDifference 0x021B6480 thumb ov101
 * GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 * IRC_COMPATIBLE_TOUCH_TEST_FirstTouchRect 0x021B925C data a4
 * IRC_COMPATIBLE_TOUCH_TEST_SecondTouchRect 0x021B926C data a4
 */
#include "../include/Obj04428.h"
#include "../include/Obj22198.h"
#include "../include/Obj22200.h"
#include "../include/Obj22201.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
extern int IRC_APPBAR_GetResult(int *);
extern int IRC_APPBAR_IsBusy(int);
extern void IRC_COMPATIBLE_TOUCH_TEST_SetFinished(u8 *);
extern int IRC_COMPATIBLE_TOUCH_TEST_PollTouchHeld(u32 *,u32 *);
extern int IRC_COMPATIBLE_TOUCH_TEST_RecordStroke(u8 *,u32 *);
extern int IRC_COMPATIBLE_TOUCH_TEST_IsStrokeFinished(void *);
extern void IRC_COMPATIBLE_TOUCH_TEST_ClearStroke(void *);
extern void IRC_COMPATIBLE_TOUCH_TEST_PrintMessage(u8 *,void *,int,int,s16);
extern void IRC_COMPATIBLE_TOUCH_TEST_PrintMessageWithName(u8 *,void *,int,u8 *,s16,s16,int);
extern void IRC_COMPATIBLE_TOUCH_TEST_LoadGuideScreens(int,u16);
extern u8 *IRC_COMPATIBLE_TOUCH_TEST_GetMarkers(u8 *);
extern void IRC_COMPATIBLE_TOUCH_TEST_SetMarkerActive(u8 **p, int i, int v);
extern void IRC_COMPATIBLE_TOUCH_TEST_SetMarkerPosition(u8 *,int,int,int);
extern void IRC_COMPATIBLE_TOUCH_TEST_SetHandler(u32 p, u32 a);
extern void IRC_COMPATIBLE_TOUCH_TEST_HandleThirdTouch(u8 *,u16 *),IRC_COMPATIBLE_TOUCH_TEST_HandleFirstTouch(u8 *,u16 *),IRC_COMPATIBLE_TOUCH_TEST_HandleAbort(u8 *,u16 *);
extern int COMPATIBLE_IRC_SYS_GetValueDifference(int *);
extern void GFL_USE_PlaySeDefaultVolume(u32);
extern u32 IRC_COMPATIBLE_TOUCH_TEST_FirstTouchRect[],IRC_COMPATIBLE_TOUCH_TEST_SecondTouchRect[];
void IRC_COMPATIBLE_TOUCH_TEST_HandleSecondTouch(u8 *p,u16 *state)
{
    u32 xy[2];
    u32 *pos;
    u8 *history,*q;
    pos=(u32 *)(p+0xa44);
    history=p+0xa4c;
    if(IRC_APPBAR_GetResult(*(int * *)&((struct Obj04428 *)p)->fA38)==1) {
        ((struct Obj22198 *)(*(u8 * *)&((struct Obj04428 *)p)->fB0C))->fC=1;
        IRC_COMPATIBLE_TOUCH_TEST_SetFinished(p);
    } else if(!IRC_APPBAR_IsBusy(*(int *)&((struct Obj04428 *)p)->fA38)) {
        switch(*state) {
        case 0:
            if(IRC_COMPATIBLE_TOUCH_TEST_PollTouchHeld(IRC_COMPATIBLE_TOUCH_TEST_FirstTouchRect,xy)) {
                if(IRC_COMPATIBLE_TOUCH_TEST_RecordStroke(history,IRC_COMPATIBLE_TOUCH_TEST_FirstTouchRect)) {
                    IRC_COMPATIBLE_TOUCH_TEST_PrintMessage(p+0x184,p+0x174,2,0,0);
                    IRC_COMPATIBLE_TOUCH_TEST_LoadGuideScreens(3,55);
                    *state=1;
                }
                q=IRC_COMPATIBLE_TOUCH_TEST_GetMarkers(p);
                IRC_COMPATIBLE_TOUCH_TEST_SetMarkerActive((u8 **)q,0,1);
                IRC_COMPATIBLE_TOUCH_TEST_SetMarkerPosition(q,0,xy[0],xy[1]);
            } else {
                if(IRC_COMPATIBLE_TOUCH_TEST_IsStrokeFinished(history)) {
                    IRC_COMPATIBLE_TOUCH_TEST_PrintMessage(p+0x184,p+0x174,2,0,0);
                    IRC_COMPATIBLE_TOUCH_TEST_LoadGuideScreens(3,55);
                    *state=1;
                } else IRC_COMPATIBLE_TOUCH_TEST_ClearStroke(history);
                *state=2;
            }
            break;
        case 1:
            if(IRC_COMPATIBLE_TOUCH_TEST_PollTouchHeld(IRC_COMPATIBLE_TOUCH_TEST_SecondTouchRect,pos)) {
                IRC_COMPATIBLE_TOUCH_TEST_LoadGuideScreens(0,55);
                if(**(void ** *)&((struct Obj04428 *)p)->fB0C)
                    IRC_COMPATIBLE_TOUCH_TEST_PrintMessageWithName(p+0x184,p+0x174,1,*(u8 * *)&((struct Obj22200 *)(*(u8 * *)&((struct Obj04428 *)p)->fB0C))->f8,0,0,55);
                else IRC_COMPATIBLE_TOUCH_TEST_PrintMessage(p+0x184,p+0x174,1,0,0);
                IRC_COMPATIBLE_TOUCH_TEST_SetHandler((u32)p,(u32)IRC_COMPATIBLE_TOUCH_TEST_HandleThirdTouch);
                q=IRC_COMPATIBLE_TOUCH_TEST_GetMarkers(p);
                IRC_COMPATIBLE_TOUCH_TEST_SetMarkerActive((u8 **)q,1,1);
                IRC_COMPATIBLE_TOUCH_TEST_SetMarkerPosition(q,1,pos[0],pos[1]);
                GFL_USE_PlaySeDefaultVolume(0x656);
            } else if(!IRC_COMPATIBLE_TOUCH_TEST_PollTouchHeld(IRC_COMPATIBLE_TOUCH_TEST_FirstTouchRect,xy)) *state=2;
            break;
        case 2:
            (((struct Obj04428 *)p)->f738)++;
            IRC_COMPATIBLE_TOUCH_TEST_SetHandler((u32)p,(u32)IRC_COMPATIBLE_TOUCH_TEST_HandleFirstTouch);
            break;
        }
    }
    if(COMPATIBLE_IRC_SYS_GetValueDifference(*(int * *)&((struct Obj22201 *)(*(u8 * *)&((struct Obj04428 *)p)->fB0C))->f4))
        IRC_COMPATIBLE_TOUCH_TEST_SetHandler((u32)p,(u32)IRC_COMPATIBLE_TOUCH_TEST_HandleAbort);
}
