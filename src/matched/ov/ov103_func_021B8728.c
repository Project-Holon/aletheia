/*
 * function: IRC_COMPATIBLE_TOUCH_TEST_HandleThirdTouch
 * address: 0x021B8728
 * packet: pkt_ov103_021B8728
 * region: ov103
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * lever: grouped offset sums retain the original off/state colors; signed conversion of an unsigned second offset calculation prevents unwanted common subexpression retention.
 * permuter: historical types300 consumed; never repeated in wave77.
 * behavior: off/tmp/tmp1 assigned before uses; original supported callback order retained; out point fields read only after8D9C success and both initialized by that body. No new volatile or narrowed pointers.
 * symbols:
 *   IRC_APPBAR_GetResult 0x021B7250 thumb ov101
 *   IRC_APPBAR_IsBusy 0x021B727C thumb ov101
 *   IRC_COMPATIBLE_TOUCH_TEST_SetFinished 0x021B8358 thumb ov103
 *   IRC_COMPATIBLE_TOUCH_TEST_PollTouchHeld 0x021B8D9C thumb ov103
 *   IRC_COMPATIBLE_TOUCH_TEST_RecordStroke 0x021B91B4 thumb ov103
 *   IRC_COMPATIBLE_TOUCH_TEST_PrintMessage 0x021B8138 thumb ov103
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   IRC_COMPATIBLE_TOUCH_TEST_SetHandler 0x021B8338 thumb ov103
 *   IRC_COMPATIBLE_TOUCH_TEST_HandleScoring 0x021B8828 thumb ov103
 *   IRC_COMPATIBLE_TOUCH_TEST_GetMarkers 0x021B7954 thumb ov103
 *   IRC_COMPATIBLE_TOUCH_TEST_SetMarkerActive 0x021B8CA0 thumb ov103
 *   IRC_COMPATIBLE_TOUCH_TEST_SetMarkerPosition 0x021B8CB0 thumb ov103
 *   IRC_COMPATIBLE_TOUCH_TEST_ClearStroke 0x021B91A8 thumb ov103
 *   IRC_COMPATIBLE_TOUCH_TEST_HandleFirstTouch 0x021B8364 thumb ov103
 *   COMPATIBLE_IRC_SYS_GetValueDifference 0x021B6480 thumb ov101
 *   IRC_COMPATIBLE_TOUCH_TEST_HandleAbort 0x021B8A44 thumb ov103
 *   IRC_COMPATIBLE_TOUCH_TEST_SecondTouchRect 0x021B926C data a4
  */
#include "../include/Obj13737.h"
#include "../include/Obj22202.h"
#include "../include/Obj22203.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef enum { OFFSET_AAC = 0xaac } Offset;
extern int IRC_APPBAR_GetResult(int *);
extern int IRC_APPBAR_IsBusy(int);
extern void IRC_COMPATIBLE_TOUCH_TEST_SetFinished(u8 *);
extern int IRC_COMPATIBLE_TOUCH_TEST_PollTouchHeld(u32 *,u32 *);
extern int IRC_COMPATIBLE_TOUCH_TEST_RecordStroke(u8 *,u32 *);
extern void IRC_COMPATIBLE_TOUCH_TEST_PrintMessage(u8 *,void *,int,int,short);
extern void GFL_USE_PlaySeDefaultVolume(u32);
extern void IRC_COMPATIBLE_TOUCH_TEST_SetHandler(u32,u32);
extern void IRC_COMPATIBLE_TOUCH_TEST_HandleScoring(u8 *,u16 *),IRC_COMPATIBLE_TOUCH_TEST_HandleFirstTouch(u8 *,u16 *),IRC_COMPATIBLE_TOUCH_TEST_HandleAbort(u8 *,u16 *);
extern u8 *IRC_COMPATIBLE_TOUCH_TEST_GetMarkers(u8 *);
extern void IRC_COMPATIBLE_TOUCH_TEST_SetMarkerActive(u8 **,int,int);
extern void IRC_COMPATIBLE_TOUCH_TEST_SetMarkerPosition(u8 *,int,int,int);
extern void IRC_COMPATIBLE_TOUCH_TEST_ClearStroke(void *);
extern int COMPATIBLE_IRC_SYS_GetValueDifference(int *);
extern u32 IRC_COMPATIBLE_TOUCH_TEST_SecondTouchRect[];
void IRC_COMPATIBLE_TOUCH_TEST_HandleThirdTouch(u8 *p,u16 *state)
{
    struct { int x,y; } point;
    Offset off;
    Offset tmp;
    u8 *tmp1;
    off=OFFSET_AAC;
    if(IRC_APPBAR_GetResult(*(int **)(p+(off-0x74)))==1) {
        tmp=(Offset)off;
        tmp1=*(u8 **)(p+(tmp+0x60))+12;
        ((struct Obj22202 *)tmp1)->f0=1;
        IRC_COMPATIBLE_TOUCH_TEST_SetFinished(p);
    } else if(IRC_APPBAR_IsBusy(*(int *)(p+(int)((u32)off-0x74)))==0) {
        switch(*state) {
        case 0: {
            void *obj;
            if(IRC_COMPATIBLE_TOUCH_TEST_PollTouchHeld(IRC_COMPATIBLE_TOUCH_TEST_SecondTouchRect,(u32 *)&point)) {
                if(IRC_COMPATIBLE_TOUCH_TEST_RecordStroke(p+off,IRC_COMPATIBLE_TOUCH_TEST_SecondTouchRect)) {
                    IRC_COMPATIBLE_TOUCH_TEST_PrintMessage(p+0x184,p+0x174,3,0,0);
                    GFL_USE_PlaySeDefaultVolume(0x654);
                    IRC_COMPATIBLE_TOUCH_TEST_SetHandler((u32)p,(u32)IRC_COMPATIBLE_TOUCH_TEST_HandleScoring);
                }
                if(off) {}
                obj=IRC_COMPATIBLE_TOUCH_TEST_GetMarkers(p);
                IRC_COMPATIBLE_TOUCH_TEST_SetMarkerActive(obj,1,1);
                IRC_COMPATIBLE_TOUCH_TEST_SetMarkerPosition(obj,1,point.x,point.y);
            } else {
                obj=IRC_COMPATIBLE_TOUCH_TEST_GetMarkers(p);
                IRC_COMPATIBLE_TOUCH_TEST_SetMarkerActive(obj,1,0);
                IRC_COMPATIBLE_TOUCH_TEST_ClearStroke(p+off);
                *state=1;
            }
            break;
        }
        case 1:
            (((struct Obj13737 *)p)->f738)++;
            IRC_COMPATIBLE_TOUCH_TEST_SetHandler((u32)p,(u32)IRC_COMPATIBLE_TOUCH_TEST_HandleFirstTouch);
            break;
        }
    }
    if(COMPATIBLE_IRC_SYS_GetValueDifference(*(int * *)&((struct Obj22203 *)(*(u8 * *)&((struct Obj13737 *)p)->fB0C))->f4))
        IRC_COMPATIBLE_TOUCH_TEST_SetHandler((u32)p,(u32)IRC_COMPATIBLE_TOUCH_TEST_HandleAbort);
}
