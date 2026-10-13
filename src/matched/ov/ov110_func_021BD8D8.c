/*
 * function: PMS_INPUT_HandleSingleWordMenuButtons
 * address: 0x021BD8D8
 * packet: pkt_ov110_021BD8D8
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   PMS_INPUT_VIEW_IsIdle 0x021B9C74 thumb ov110
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   PMS_INPUT_VIEW_StartTask 0x021B9BEC thumb ov110
 *   PMS_INPUT_SetSubHandler 0x021BF4F8 thumb ov110
 *   PMS_INPUT_SubHandleConfirm 0x021BF53C thumb ov110
 *   PMS_INPUT_SubHandleCancel 0x021BF608 thumb ov110
 *   PMS_INPUT_ResetCursor 0x021BF82C thumb ov110
 *   PMS_INPUT_IsComplete 0x021BF680 thumb ov110
 *   PMS_INPUT_SetHandler 0x021BD7A0 thumb ov110
 *   PMS_INPUT_HandleConfirmButtons 0x021BE3B8 thumb ov110
 *   PMS_INPUT_HandleBrowse 0x021BE4C0 thumb ov110
 */
#include "../include/Obj00012.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef int (*Handler)(u8 *,void *);
extern int PMS_INPUT_VIEW_IsIdle(unsigned int a);
extern void GFL_USE_PlaySeDefaultVolume(u32);
extern void PMS_INPUT_VIEW_StartTask(u8 *,int);
extern void PMS_INPUT_SetSubHandler(u8 *,u32);
extern void PMS_INPUT_SubHandleConfirm(u8 *,u32 *);
extern void PMS_INPUT_SubHandleCancel(u8 *,u32 *);
extern void PMS_INPUT_ResetCursor(u8 *);
extern int PMS_INPUT_IsComplete(u8 *);
extern void PMS_INPUT_SetHandler(u8 *,Handler);
extern int PMS_INPUT_HandleConfirmButtons(u8 *,u32 *);
extern int PMS_INPUT_HandleBrowse(u8 *,unsigned *);
int PMS_INPUT_HandleSingleWordMenuButtons(u8 *p,u32 *q) {
    switch(*q) {
    case 0:
        if(PMS_INPUT_VIEW_IsIdle((unsigned int)(*(u8 * *)&((struct Obj00012 *)p)->f14))) {
            if(((struct Obj00012 *)p)->f34&64) {
                GFL_USE_PlaySeDefaultVolume(1352); ((struct Obj00012 *)p)->f48=1;
                PMS_INPUT_VIEW_StartTask(*(u8 * *)&((struct Obj00012 *)p)->f14,7); *q=1;
            } else if(((struct Obj00012 *)p)->f34&136) {
                GFL_USE_PlaySeDefaultVolume(1352); ((struct Obj00012 *)p)->f48=0;
                PMS_INPUT_VIEW_StartTask(*(u8 * *)&((struct Obj00012 *)p)->f14,7); *q=1;
            } else if(((struct Obj00012 *)p)->f34&2) {
                GFL_USE_PlaySeDefaultVolume(1361); PMS_INPUT_SetSubHandler(p,(u32)PMS_INPUT_SubHandleCancel);
            } else if(((struct Obj00012 *)p)->f34&1) {
                GFL_USE_PlaySeDefaultVolume(1356); PMS_INPUT_ResetCursor(p);
                PMS_INPUT_VIEW_StartTask(*(u8 * *)&((struct Obj00012 *)p)->f14,10); *q=5;
            }
        }
        break;
    case 1:
        if(PMS_INPUT_VIEW_IsIdle((unsigned int)(*(u8 * *)&((struct Obj00012 *)p)->f14))) {
            if(((struct Obj00012 *)p)->f34&64) {
                GFL_USE_PlaySeDefaultVolume(1352);
                if(((struct Obj00012 *)p)->f48) { ((struct Obj00012 *)p)->f48^=1; PMS_INPUT_VIEW_StartTask(*(u8 * *)&((struct Obj00012 *)p)->f14,17); }
                else { PMS_INPUT_VIEW_StartTask(*(u8 * *)&((struct Obj00012 *)p)->f14,9); *q=0; }
            } else if(((struct Obj00012 *)p)->f34&128) {
                GFL_USE_PlaySeDefaultVolume(1352);
                if(((struct Obj00012 *)p)->f48) { PMS_INPUT_VIEW_StartTask(*(u8 * *)&((struct Obj00012 *)p)->f14,9); *q=0; }
                else { ((struct Obj00012 *)p)->f48^=1; PMS_INPUT_VIEW_StartTask(*(u8 * *)&((struct Obj00012 *)p)->f14,17); }
            } else if(((struct Obj00012 *)p)->f34&8) {
                GFL_USE_PlaySeDefaultVolume(1352); ((struct Obj00012 *)p)->f48=0; PMS_INPUT_VIEW_StartTask(*(u8 * *)&((struct Obj00012 *)p)->f14,17);
            } else if(((struct Obj00012 *)p)->f34&1) {
                if(((struct Obj00012 *)p)->f48==0) {
                    if(PMS_INPUT_IsComplete(p)) GFL_USE_PlaySeDefaultVolume(1356); else GFL_USE_PlaySeDefaultVolume(1367);
                    *q=2;
                } else { GFL_USE_PlaySeDefaultVolume(1361); *q=3; }
            } else if(((struct Obj00012 *)p)->f34&2) { GFL_USE_PlaySeDefaultVolume(1361); *q=3; }
        }
        break;
    case 2: *q=4; PMS_INPUT_SetSubHandler(p,(u32)PMS_INPUT_SubHandleConfirm); break;
    case 3: *q=4; PMS_INPUT_SetSubHandler(p,(u32)PMS_INPUT_SubHandleCancel); break;
    case 4: *q=1; break;
    case 6: if(PMS_INPUT_VIEW_IsIdle((unsigned int)(*(u8 * *)&((struct Obj00012 *)p)->f14))) PMS_INPUT_SetHandler(p,(Handler)PMS_INPUT_HandleConfirmButtons); break;
    case 5: if(PMS_INPUT_VIEW_IsIdle((unsigned int)(*(u8 * *)&((struct Obj00012 *)p)->f14))) PMS_INPUT_SetHandler(p,(Handler)PMS_INPUT_HandleBrowse); break;
    }
    return 0;
}
