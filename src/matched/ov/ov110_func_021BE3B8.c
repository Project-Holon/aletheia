/*
 * function: PMS_INPUT_HandleConfirmButtons
 * address: 0x021BE3B8
 * packet: pkt_ov110_021BE3B8
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   PMS_INPUT_VIEW_IsIdle 0x021B9C74 thumb ov110
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   PMS_INPUT_VIEW_StartTask 0x021B9BEC thumb ov110
 *   PMS_INPUT_SetSubHandler 0x021BF4F8 thumb ov110
 *   PMS_INPUT_SubHandleConfirm 0x021BF53C thumb ov110
 *   PMS_INPUT_SubHandleCancel 0x021BF608 thumb ov110
 *   PMS_INPUT_SetHandler 0x021BD7A0 thumb ov110
 *   PMS_INPUT_HandleMenu 0x021BD894 thumb ov110
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
extern void PMS_INPUT_SetHandler(u8 *,Handler);
extern int PMS_INPUT_HandleMenu(u8 *,void *);
int PMS_INPUT_HandleConfirmButtons(u8 *p,u32 *q) {
    switch(*q) {
    case 0:
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
                GFL_USE_PlaySeDefaultVolume(1356);
                if(((struct Obj00012 *)p)->f48==0) *q=1; else *q=2;
            } else if(((struct Obj00012 *)p)->f34&2) { GFL_USE_PlaySeDefaultVolume(1356); *q=2; }
        }
        break;
    case 1: *q=3; PMS_INPUT_SetSubHandler(p,(u32)PMS_INPUT_SubHandleConfirm); break;
    case 2: *q=4; PMS_INPUT_SetSubHandler(p,(u32)PMS_INPUT_SubHandleCancel); break;
    case 3:
    case 4: *q=0; break;
    case 5: if(PMS_INPUT_VIEW_IsIdle((unsigned int)(*(u8 * *)&((struct Obj00012 *)p)->f14))) PMS_INPUT_SetHandler(p,PMS_INPUT_HandleMenu); break;
    }
    return 0;
}
