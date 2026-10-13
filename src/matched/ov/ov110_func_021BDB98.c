/*
 * function: PMS_INPUT_HandleWordMenuTouch
 * address: 0x021BDB98
 * packet: pkt_ov110_021BDB98
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * control-flow: inner hits 2/3 reach DC0A; outer states 2/3 preserve p for F4F8.
 * lever: preserve incoming r0 p at DA84/DA94 calls with their ignored pointer argument.
 * symbols:
 *   PMS_INPUT_HitSingleWordButtons 0x021BDA84 thumb ov110
 *   PMS_INPUT_HitDoubleWordButtons 0x021BDA94 thumb ov110
 *   PMS_INPUT_IsComplete 0x021BF680 thumb ov110
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   PMS_INPUT_ResetCursor 0x021BF82C thumb ov110
 *   PMS_INPUT_VIEW_StartTask 0x021B9BEC thumb ov110
 *   PMS_INPUT_SetSubHandler 0x021BF4F8 thumb ov110
 *   PMS_INPUT_SubHandleConfirm 0x021BF53C thumb ov110
 *   PMS_INPUT_SubHandleCancel 0x021BF608 thumb ov110
 *   PMS_INPUT_VIEW_IsIdle 0x021B9C74 thumb ov110
 *   PMS_INPUT_SetHandler 0x021BD7A0 thumb ov110
 *   PMS_INPUT_HandleBrowse 0x021BE4C0 thumb ov110
 */
#include "../include/Obj00012.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef int (*Handler)(u8 *,void *);
extern int PMS_INPUT_HitSingleWordButtons(u8 *);
extern int PMS_INPUT_HitDoubleWordButtons(u8 *);
extern int PMS_INPUT_IsComplete(u8 *);
extern void GFL_USE_PlaySeDefaultVolume(u32);
extern void PMS_INPUT_ResetCursor(u8 *);
extern void PMS_INPUT_VIEW_StartTask(u8 *,int);
extern void PMS_INPUT_SetSubHandler(u8 *,u32);
extern void PMS_INPUT_SubHandleConfirm(u8 *,u32 *);
extern void PMS_INPUT_SubHandleCancel(u8 *,u32 *);
extern int PMS_INPUT_VIEW_IsIdle(unsigned int a);
extern void PMS_INPUT_SetHandler(u8 *,Handler);
extern int PMS_INPUT_HandleBrowse(u8 *,unsigned *);
int PMS_INPUT_HandleWordMenuTouch(u8 *p,u32 *q)
{
    int hit;
    switch(*q) {
    case 0:
    case 1:
        if(((struct Obj00012 *)p)->f4==0) hit=PMS_INPUT_HitSingleWordButtons(p);
        else hit=PMS_INPUT_HitDoubleWordButtons(p);
        switch(hit) {
        case 0:
            if(PMS_INPUT_IsComplete(p)) GFL_USE_PlaySeDefaultVolume(1356);
            else GFL_USE_PlaySeDefaultVolume(1367);
            *q=2;
            break;
        case 1:
            GFL_USE_PlaySeDefaultVolume(1361);
            *q=3;
            break;
        case 2:
        case 3:
            GFL_USE_PlaySeDefaultVolume(1356);
            PMS_INPUT_ResetCursor(p);
            ((struct Obj00012 *)p)->f4A=hit-2;
            PMS_INPUT_VIEW_StartTask(*(u8 * *)&((struct Obj00012 *)p)->f14,10);
            *q=5;
            break;
        }
        break;
    case 2: *q=4; PMS_INPUT_SetSubHandler(p,(u32)PMS_INPUT_SubHandleConfirm); break;
    case 3: *q=4; PMS_INPUT_SetSubHandler(p,(u32)PMS_INPUT_SubHandleCancel); break;
    case 4: *q=0; break;
    case 5:
        if(PMS_INPUT_VIEW_IsIdle((unsigned int)(*(u8 * *)&((struct Obj00012 *)p)->f14))) PMS_INPUT_SetHandler(p,(Handler)PMS_INPUT_HandleBrowse);
        break;
    }
    return 0;
}
