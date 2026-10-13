/*
 * function: IRC_COMPATIBLE_TOUCH_TEST_HandleFirstTouch
 * address: 0x021B8364
 * packet: pkt_ov103_021B8364
 * region: ov103
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 * IRC_APPBAR_GetResult 0x021B7250 thumb ov101
 * IRC_APPBAR_IsBusy 0x021B727C thumb ov101
 * IRC_COMPATIBLE_TOUCH_TEST_SetFinished 0x021B8358 thumb ov103
 * IRC_COMPATIBLE_TOUCH_TEST_IsStrokeFinished 0x021B9214 thumb ov103
 * IRC_COMPATIBLE_TOUCH_TEST_PrintMessage 0x021B8138 thumb ov103
 * IRC_COMPATIBLE_TOUCH_TEST_PrintMessageWithName 0x021B824C thumb ov103
 * IRC_COMPATIBLE_TOUCH_TEST_GetMarkers 0x021B7954 thumb ov103
 * IRC_COMPATIBLE_TOUCH_TEST_SetMarkerActive 0x021B8CA0 thumb ov103
 * GFL_USE_StopAllSe 0x02006210 thumb
 * IRC_COMPATIBLE_TOUCH_TEST_LoadGuideScreens 0x021B9060 thumb ov103
 * IRC_COMPATIBLE_TOUCH_TEST_PollTouchTrigger 0x021B8D54 thumb ov103
 * IRC_COMPATIBLE_TOUCH_TEST_SetMarkerPosition 0x021B8CB0 thumb ov103
 * GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 * IRC_COMPATIBLE_TOUCH_TEST_SetHandlerWithState 0x021B8348 thumb ov103
 * IRC_COMPATIBLE_TOUCH_TEST_SetHandler 0x021B8338 thumb ov103
 * IRC_COMPATIBLE_TOUCH_TEST_HandleSecondTouch 0x021B856C thumb ov103
 * IRC_COMPATIBLE_TOUCH_TEST_PrintMessageForPlayer 0x021B82DC thumb ov103
 * COMPATIBLE_IRC_SYS_GetValueDifference 0x021B6480 thumb ov101
 * IRC_COMPATIBLE_TOUCH_TEST_HandleAbort 0x021B8A44 thumb ov103
 * IRC_COMPATIBLE_TOUCH_TEST_FirstTouchRect 0x021B925C data a4
 */
#include "../include/Obj01388.h"
#include "../include/Obj22192.h"
#include "../include/Obj22194.h"
#include "../include/Obj22196.h"
#include "../include/Obj22197.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
extern int IRC_APPBAR_GetResult(int *);
extern int IRC_APPBAR_IsBusy(int);
extern void IRC_COMPATIBLE_TOUCH_TEST_SetFinished(u8 *);
extern int IRC_COMPATIBLE_TOUCH_TEST_IsStrokeFinished(void *);
extern void IRC_COMPATIBLE_TOUCH_TEST_PrintMessage(u8 *,void *,int,int,s16);
extern void IRC_COMPATIBLE_TOUCH_TEST_PrintMessageWithName(u8 *,void *,int,u8 *,s16,s16,int);
extern u8 *IRC_COMPATIBLE_TOUCH_TEST_GetMarkers(u8 *);
extern void IRC_COMPATIBLE_TOUCH_TEST_SetMarkerActive(u8 **p, int i, int v);
extern void GFL_USE_StopAllSe(void);
extern void IRC_COMPATIBLE_TOUCH_TEST_LoadGuideScreens(int,u16);
extern int IRC_COMPATIBLE_TOUCH_TEST_PollTouchTrigger(u32 *,u32 *);
extern void IRC_COMPATIBLE_TOUCH_TEST_SetMarkerPosition(u8 *,int,int,int);
extern void GFL_USE_PlaySeDefaultVolume(u32);
extern void IRC_COMPATIBLE_TOUCH_TEST_SetHandlerWithState(u32 p, u32 a, u16 b);
extern void IRC_COMPATIBLE_TOUCH_TEST_SetHandler(u32 p, u32 a);
extern void IRC_COMPATIBLE_TOUCH_TEST_HandleSecondTouch(u8 *,u16 *),IRC_COMPATIBLE_TOUCH_TEST_HandleAbort(u8 *,u16 *);
extern void IRC_COMPATIBLE_TOUCH_TEST_PrintMessageForPlayer(u8 *,u8 *,int);
extern int COMPATIBLE_IRC_SYS_GetValueDifference(int *);
extern u32 IRC_COMPATIBLE_TOUCH_TEST_FirstTouchRect[];
void IRC_COMPATIBLE_TOUCH_TEST_HandleFirstTouch(u8 *p,u16 *state)
{
    u32 *pos;
    u8 *q;
    int i;
    pos=(u32 *)(p+0xa3c);
    if(IRC_APPBAR_GetResult(*(int * *)&((struct Obj01388 *)p)->fA38)==1) {
        ((struct Obj22192 *)(*(u8 * *)&((struct Obj01388 *)p)->fB0C))->fC=1;
        IRC_COMPATIBLE_TOUCH_TEST_SetFinished(p);
    } else if(!IRC_APPBAR_IsBusy(*(int *)&((struct Obj01388 *)p)->fA38)) {
        switch(*state) {
        case 0:
            if(IRC_COMPATIBLE_TOUCH_TEST_IsStrokeFinished(p+0xa4c))
                IRC_COMPATIBLE_TOUCH_TEST_PrintMessage(p+0x184,p+0x174,17,0,0);
            else if(**(void ** *)&((struct Obj01388 *)p)->fB0C)
                IRC_COMPATIBLE_TOUCH_TEST_PrintMessageWithName(p+0x184,p+0x174,0,*(u8 * *)&((struct Obj22194 *)(*(u8 * *)&((struct Obj01388 *)p)->fB0C))->f8,0,0,55);
            else IRC_COMPATIBLE_TOUCH_TEST_PrintMessage(p+0x184,p+0x174,0,0,0);
            q=IRC_COMPATIBLE_TOUCH_TEST_GetMarkers(p);
            for(i=0;i<2;i++) IRC_COMPATIBLE_TOUCH_TEST_SetMarkerActive((u8 **)q,i,0);
            GFL_USE_StopAllSe();
            IRC_COMPATIBLE_TOUCH_TEST_LoadGuideScreens(1,55);
            ((struct Obj01388 *)p)->f740=0;
            *state=1;
            break;
        case 1:
            if(IRC_COMPATIBLE_TOUCH_TEST_PollTouchTrigger(IRC_COMPATIBLE_TOUCH_TEST_FirstTouchRect,pos)) {
                IRC_COMPATIBLE_TOUCH_TEST_LoadGuideScreens(0,55);
                ((struct Obj01388 *)p)->f740=0;
                ((struct Obj01388 *)p)->f744=0;
                q=IRC_COMPATIBLE_TOUCH_TEST_GetMarkers(p);
                IRC_COMPATIBLE_TOUCH_TEST_SetMarkerActive((u8 **)q,0,1);
                IRC_COMPATIBLE_TOUCH_TEST_SetMarkerPosition(q,0,pos[0],pos[1]);
                GFL_USE_PlaySeDefaultVolume(0x651);
                if(IRC_COMPATIBLE_TOUCH_TEST_IsStrokeFinished(p+0xa4c)) {
                    IRC_COMPATIBLE_TOUCH_TEST_PrintMessage(p+0x184,p+0x174,2,0,0);
                    IRC_COMPATIBLE_TOUCH_TEST_LoadGuideScreens(3,55);
                    IRC_COMPATIBLE_TOUCH_TEST_SetHandlerWithState((u32)p,(u32)IRC_COMPATIBLE_TOUCH_TEST_HandleSecondTouch,1);
                } else {
                    if(**(void ** *)&((struct Obj01388 *)p)->fB0C)
                        IRC_COMPATIBLE_TOUCH_TEST_PrintMessageWithName(p+0x184,p+0x174,1,*(u8 * *)&((struct Obj22196 *)(*(u8 * *)&((struct Obj01388 *)p)->fB0C))->f8,0,0,55);
                    else IRC_COMPATIBLE_TOUCH_TEST_PrintMessage(p+0x184,p+0x174,1,0,0);
                    IRC_COMPATIBLE_TOUCH_TEST_SetHandler((u32)p,(u32)IRC_COMPATIBLE_TOUCH_TEST_HandleSecondTouch);
                }
            } else if(!IRC_COMPATIBLE_TOUCH_TEST_IsStrokeFinished(p+0xa4c)) {
                if((((struct Obj01388 *)p)->f740)++>=180) {
                    ((struct Obj01388 *)p)->f740=0;
                    ((struct Obj01388 *)p)->f744^=1;
                    if(((struct Obj01388 *)p)->f744) IRC_COMPATIBLE_TOUCH_TEST_PrintMessageForPlayer(p+0x184,p,11);
                    else IRC_COMPATIBLE_TOUCH_TEST_PrintMessageForPlayer(p+0x184,p,0);
                }
            }
            break;
        }
    }
    if(COMPATIBLE_IRC_SYS_GetValueDifference(*(int * *)&((struct Obj22197 *)(*(u8 * *)&((struct Obj01388 *)p)->fB0C))->f4))
        IRC_COMPATIBLE_TOUCH_TEST_SetHandler((u32)p,(u32)IRC_COMPATIBLE_TOUCH_TEST_HandleAbort);
}
