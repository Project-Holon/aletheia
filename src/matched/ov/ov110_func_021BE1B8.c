/*
 * function: PMS_INPUT_HandleSentenceMenuTouch
 * address: 0x021BE1B8
 * packet: pkt_ov110_021BE1B8
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * ABI: BABE8 forwards BC6DC's full-word getter result despite its legacy void declaration.
 * symbols:
 *   PMS_INPUT_VIEW_GetEditValue 0x021BABE8 thumb ov110
 *   PMS_INPUT_HitSentenceTypeTab 0x021BDB50 thumb ov110
 *   PMS_INPUT_SelectSentenceType 0x021BD740 thumb ov110
 *   PMS_INPUT_HitSentenceButtons 0x021BDAA4 thumb ov110
 *   PMS_INPUT_IsComplete 0x021BF680 thumb ov110
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   PMS_INPUT_VIEW_StartTask 0x021B9BEC thumb ov110
 *   PMS_INPUT_PrevSentence 0x021BD6F8 thumb ov110
 *   PMS_INPUT_NextSentence 0x021BD6B4 thumb ov110
 *   PMS_INPUT_VIEW_SetMenuItemMode 0x021BAC30 thumb ov110
 *   PMS_INPUT_ResetCursor 0x021BF82C thumb ov110
 *   PMS_INPUT_VIEW_IsTaskNotRunning 0x021B9C90 thumb ov110
 *   PMS_INPUT_SetSubHandler 0x021BF4F8 thumb ov110
 *   PMS_INPUT_SubHandleConfirm 0x021BF53C thumb ov110
 *   PMS_INPUT_SubHandleCancel 0x021BF608 thumb ov110
 *   PMS_INPUT_VIEW_IsIdle 0x021B9C74 thumb ov110
 *   PMS_INPUT_SetHandler 0x021BD7A0 thumb ov110
 *   PMS_INPUT_HandleConfirmButtons 0x021BE3B8 thumb ov110
 *   PMS_INPUT_HandleBrowse 0x021BE4C0 thumb ov110
 */
#include "../include/Obj00012.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef short s16;
typedef struct { s16 a; s8 b,c; } State;
typedef int (*Handler)(u8 *,void *);
extern int PMS_INPUT_VIEW_GetEditValue(u8 *p);
extern int PMS_INPUT_HitSentenceTypeTab(u32 *);
extern void PMS_INPUT_SelectSentenceType(u8 *p, void *out, int v);
extern int PMS_INPUT_HitSentenceButtons(u8 *);
extern int PMS_INPUT_IsComplete(u8 *);
extern void GFL_USE_PlaySeDefaultVolume(u32);
extern void PMS_INPUT_VIEW_StartTask(u8 *,int);
extern void PMS_INPUT_PrevSentence(State *,void *);
extern void PMS_INPUT_NextSentence(State *,void *);
extern void PMS_INPUT_VIEW_SetMenuItemMode(u8 *,int);
extern void PMS_INPUT_ResetCursor(u8 *);
extern int PMS_INPUT_VIEW_IsTaskNotRunning(unsigned int a, int b);
extern void PMS_INPUT_SetSubHandler(u8 *,u32);
extern void PMS_INPUT_SubHandleConfirm(u8 *,u32 *);
extern void PMS_INPUT_SubHandleCancel(u8 *,u32 *);
extern int PMS_INPUT_VIEW_IsIdle(unsigned int a);
extern void PMS_INPUT_SetHandler(u8 *,Handler);
extern int PMS_INPUT_HandleConfirmButtons(u8 *,u32 *);
extern int PMS_INPUT_HandleBrowse(u8 *,u32 *);
int PMS_INPUT_HandleSentenceMenuTouch(u8 *p,u32 *q)
{
    int hit;
    int index;
    switch(*q) {
    case 0:
        p[0x68]=PMS_INPUT_VIEW_GetEditValue(*(u8 * *)&((struct Obj00012 *)p)->f14);
        *q=1;
    case 1:
    case 2:
        index=PMS_INPUT_HitSentenceTypeTab((u32 *)p);
        if(index>-1) {
            ((struct Obj00012 *)p)->f4A=0;
            PMS_INPUT_SelectSentenceType((u8 *)(p+0x64),p+8,index);
            PMS_INPUT_VIEW_StartTask(*(u8 * *)&((struct Obj00012 *)p)->f14,3);
            GFL_USE_PlaySeDefaultVolume(1352);
            *q=3;
        } else {
            hit=PMS_INPUT_HitSentenceButtons(p);
            switch(hit) {
            case 0:
                if(PMS_INPUT_IsComplete(p)) GFL_USE_PlaySeDefaultVolume(1356);
                else GFL_USE_PlaySeDefaultVolume(1367);
                ((struct Obj00012 *)p)->f48=0;
                PMS_INPUT_VIEW_StartTask(*(u8 * *)&((struct Obj00012 *)p)->f14,8);
                *q=hit+4;
                break;
            case 1:
                GFL_USE_PlaySeDefaultVolume(1361);
                ((struct Obj00012 *)p)->f48=1;
                PMS_INPUT_VIEW_StartTask(*(u8 * *)&((struct Obj00012 *)p)->f14,8);
                *q=hit+4;
                break;
            case 2:
            case 4:
                GFL_USE_PlaySeDefaultVolume(1636);
                ((struct Obj00012 *)p)->f4A=0;
                PMS_INPUT_PrevSentence((State *)(p+0x64),p+8);
                PMS_INPUT_VIEW_StartTask(*(u8 * *)&((struct Obj00012 *)p)->f14,3);
                PMS_INPUT_VIEW_SetMenuItemMode(*(u8 * *)&((struct Obj00012 *)p)->f14,0);
                *q=3;
                break;
            case 3:
            case 5:
                GFL_USE_PlaySeDefaultVolume(1636);
                ((struct Obj00012 *)p)->f4A=0;
                PMS_INPUT_NextSentence((State *)(p+0x64),p+8);
                PMS_INPUT_VIEW_StartTask(*(u8 * *)&((struct Obj00012 *)p)->f14,3);
                PMS_INPUT_VIEW_SetMenuItemMode(*(u8 * *)&((struct Obj00012 *)p)->f14,1);
                *q=3;
                break;
            case 6:
            case 7:
                GFL_USE_PlaySeDefaultVolume(1356);
                PMS_INPUT_ResetCursor(p);
                ((struct Obj00012 *)p)->f4A=hit-6;
                PMS_INPUT_VIEW_StartTask(*(u8 * *)&((struct Obj00012 *)p)->f14,10);
                *q=8;
                break;
            }
        }
        break;
    case 3: if(PMS_INPUT_VIEW_IsTaskNotRunning((unsigned int)(*(u8 * *)&((struct Obj00012 *)p)->f14),3)) *q=0; break;
    case 4: *q=6; PMS_INPUT_SetSubHandler(p,(u32)PMS_INPUT_SubHandleConfirm); break;
    case 5: *q=6; PMS_INPUT_SetSubHandler(p,(u32)PMS_INPUT_SubHandleCancel); break;
    case 6: *q=2; break;
    case 7: if(PMS_INPUT_VIEW_IsIdle((unsigned int)(*(u8 * *)&((struct Obj00012 *)p)->f14))) PMS_INPUT_SetHandler(p,(Handler)PMS_INPUT_HandleConfirmButtons); break;
    case 8: if(PMS_INPUT_VIEW_IsIdle((unsigned int)(*(u8 * *)&((struct Obj00012 *)p)->f14))) PMS_INPUT_SetHandler(p,(Handler)PMS_INPUT_HandleBrowse); break;
    }
    return 0;
}
