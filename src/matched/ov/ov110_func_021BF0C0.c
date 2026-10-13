/*
 * function: PMS_INPUT_HandleWordListTouch
 * address: 0x021BF0C0
 * packet: pkt_ov110_021BF0C0
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: emit case 5 before cases 1/2/3 as in the original jump table.
 * symbols:
 *   PMS_INPUT_HitBackButton 0x021BE7F0 thumb ov110
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   PMS_INPUT_VIEW_StartTask 0x021B9BEC thumb ov110
 *   PMS_INPUT_HandleBrowse 0x021BE4C0 thumb ov110
 *   PMS_INPUT_HitScrollBarDrag 0x021BF08C thumb ov110
 *   PMS_WORDLIST_DragTo 0x021BF408 thumb ov110
 *   PMS_INPUT_HitWordList 0x021BEF4C thumb ov110
 *   PMS_INPUT_PickWord 0x021BF444 thumb ov110
 *   PMS_INPUT_HandleMenu 0x021BD894 thumb ov110
 */
#include "../include/Obj00493.h"
typedef unsigned char u8;
typedef unsigned int u32;
typedef int (*Handler)(u8 *, void *);
extern int PMS_INPUT_HitBackButton(void);
extern void GFL_USE_PlaySeDefaultVolume(u32);
extern void PMS_INPUT_VIEW_StartTask(u8 *, int);
extern int PMS_INPUT_HandleBrowse(u8 *, unsigned *);
extern int PMS_INPUT_HitScrollBarDrag(u8 *);
extern int PMS_WORDLIST_DragTo(u8 *, u8 *);
extern int PMS_INPUT_HitWordList(u8 *);
extern int PMS_INPUT_PickWord(u8 *);
extern int PMS_INPUT_HandleMenu(u8 *, void *);
void PMS_INPUT_HandleWordListTouch(u8 *p, u32 *q)
{
    if (!PMS_INPUT_HitBackButton()) {
        GFL_USE_PlaySeDefaultVolume(1361);
        PMS_INPUT_VIEW_StartTask(*(u8 * *)&((struct Obj00493 *)p)->f14, 13);
        *(Handler *)&((struct Obj00493 *)p)->f28 = (Handler)PMS_INPUT_HandleBrowse;
        *q = 4;
        return;
    }
    if (PMS_INPUT_HitScrollBarDrag(p) == 1) {
        switch (PMS_WORDLIST_DragTo(*(u8 * *)&((struct Obj00493 *)p)->f14, p + 84)) {
        case 2:
            PMS_INPUT_VIEW_StartTask(*(u8 * *)&((struct Obj00493 *)p)->f14, 31);
            *q = 3;
            break;
        case 3:
            PMS_INPUT_VIEW_StartTask(*(u8 * *)&((struct Obj00493 *)p)->f14, 31);
            PMS_INPUT_VIEW_StartTask(*(u8 * *)&((struct Obj00493 *)p)->f14, 19);
            *q = 3;
            break;
        }
        return;
    }
    switch (PMS_INPUT_HitWordList(p)) {
    case 0: break;
    case 5:
        GFL_USE_PlaySeDefaultVolume(1356);
        PMS_INPUT_PickWord(p);
        *(Handler *)&((struct Obj00493 *)p)->f28 = PMS_INPUT_HandleMenu;
        PMS_INPUT_VIEW_StartTask(*(u8 * *)&((struct Obj00493 *)p)->f14, 34);
        PMS_INPUT_VIEW_StartTask(*(u8 * *)&((struct Obj00493 *)p)->f14, 14);
        *q = 4;
        break;
    case 1:
        GFL_USE_PlaySeDefaultVolume(1352);
        PMS_INPUT_VIEW_StartTask(*(u8 * *)&((struct Obj00493 *)p)->f14, 19);
        break;
    case 2:
        GFL_USE_PlaySeDefaultVolume(1352);
        PMS_INPUT_VIEW_StartTask(*(u8 * *)&((struct Obj00493 *)p)->f14, 31);
        *q = 3;
        break;
    case 3:
        GFL_USE_PlaySeDefaultVolume(1352);
        PMS_INPUT_VIEW_StartTask(*(u8 * *)&((struct Obj00493 *)p)->f14, 20);
        PMS_INPUT_VIEW_StartTask(*(u8 * *)&((struct Obj00493 *)p)->f14, 19);
        *q = 2;
        break;
    case 4: break;
    }
}
