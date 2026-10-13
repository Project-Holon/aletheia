/*
 * function: PMS_INPUT_HandleWordListKeys
 * address: 0x021BEE60
 * packet: pkt_ov110_021BEE60
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   PMS_WORDLIST_MoveByKeys 0x021BF208 thumb ov110
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   PMS_INPUT_VIEW_StartTask 0x021B9BEC thumb ov110
 *   PMS_INPUT_HandleBrowse 0x021BE4C0 thumb ov110
 *   PMS_INPUT_HandleMenu 0x021BD894 thumb ov110
 *   PMS_INPUT_PickWord 0x021BF444 thumb ov110
 */
#include "../include/Obj01394.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef int (*Handler)(u8 *,void *);
extern int PMS_WORDLIST_MoveByKeys(u8 *,u32);
extern void GFL_USE_PlaySeDefaultVolume(u32);
extern void PMS_INPUT_VIEW_StartTask(u8 *,int);
extern int PMS_INPUT_HandleBrowse(u8 *p, unsigned *q);
extern int PMS_INPUT_HandleMenu(u8 *,void *);
extern int PMS_INPUT_PickWord(u8 *);
void PMS_INPUT_HandleWordListKeys(u8 *p,u32 *q) {
    switch(PMS_WORDLIST_MoveByKeys(p+0x54,((struct Obj01394 *)p)->f38)) {
    case 1: GFL_USE_PlaySeDefaultVolume(1352); PMS_INPUT_VIEW_StartTask(*(u8 * *)&((struct Obj01394 *)p)->f14,19); return;
    case 2: GFL_USE_PlaySeDefaultVolume(1352); PMS_INPUT_VIEW_StartTask(*(u8 * *)&((struct Obj01394 *)p)->f14,20); *q=1; return;
    case 3: GFL_USE_PlaySeDefaultVolume(1352); PMS_INPUT_VIEW_StartTask(*(u8 * *)&((struct Obj01394 *)p)->f14,20); PMS_INPUT_VIEW_StartTask(*(u8 * *)&((struct Obj01394 *)p)->f14,19); *q=2; return;
    }
    if(((struct Obj01394 *)p)->f34&2) {
        GFL_USE_PlaySeDefaultVolume(1361); PMS_INPUT_VIEW_StartTask(*(u8 * *)&((struct Obj01394 *)p)->f14,13);
        *(Handler *)&((struct Obj01394 *)p)->f28=(Handler)PMS_INPUT_HandleBrowse; *q=4; return;
    } else if(((struct Obj01394 *)p)->f34&1) {
        if(((struct Obj01394 *)p)->f60!=0) {
            GFL_USE_PlaySeDefaultVolume(1361); PMS_INPUT_VIEW_StartTask(*(u8 * *)&((struct Obj01394 *)p)->f14,13);
            *(Handler *)&((struct Obj01394 *)p)->f28=(Handler)PMS_INPUT_HandleBrowse; *q=4; return;
        } else {
            GFL_USE_PlaySeDefaultVolume(1356); ((struct Obj01394 *)p)->f62=65535;
            PMS_INPUT_PickWord(p);
            PMS_INPUT_VIEW_StartTask(*(u8 * *)&((struct Obj01394 *)p)->f14,34); PMS_INPUT_VIEW_StartTask(*(u8 * *)&((struct Obj01394 *)p)->f14,14);
            *(Handler *)&((struct Obj01394 *)p)->f28=PMS_INPUT_HandleMenu; *q=4;
        }
    }
}
