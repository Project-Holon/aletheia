/*
 * function: PMS_INPUT_HandleBrowseTouch
 * address: 0x021BE934
 * packet: pkt_ov110_021BE934
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * ABI: E800/E8B4/E890 receive the object visibly loaded by this caller.
 * symbols:
 *   PMS_INPUT_HitBrowseTopButtons 0x021BE7B8 thumb ov110
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   PMS_INPUT_VIEW_StartTask 0x021B9BEC thumb ov110
 *   PMS_INPUT_HandleMenu 0x021BD894 thumb ov110
 *   PMS_INPUT_ResetCursor 0x021BF82C thumb ov110
 *   PMS_INPUT_HitCategoryCell 0x021BE800 thumb ov110
 *   PMS_INPUT_DATA_GetCategoryWordCount 0x021B999C thumb ov110
 *   PMS_INPUT_OpenWordList 0x021BD868 thumb ov110
 *   PMS_INPUT_HitInitialCell 0x021BE8B4 thumb ov110
 *   PMSI_SEARCH_PushKey 0x021BAF7C thumb ov110
 *   PMSI_SEARCH_Run 0x021BB054 thumb ov110
 *   PMS_INPUT_HitInitialButtons 0x021BE890 thumb ov110
 *   PMSI_SEARCH_PopKey 0x021BAFAC thumb ov110
 */
#include "../include/Obj00586.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef int (*Handler)(u8 *,void *);
extern int PMS_INPUT_HitBrowseTopButtons(u8 *);
extern void GFL_USE_PlaySeDefaultVolume(u32);
extern void PMS_INPUT_VIEW_StartTask(u8 *,int);
extern int PMS_INPUT_HandleMenu(u8 *,void *);
extern void PMS_INPUT_ResetCursor(u8 *);
extern int PMS_INPUT_HitCategoryCell(u8 *);
extern u32 PMS_INPUT_DATA_GetCategoryWordCount(u8 *,int);
extern void PMS_INPUT_OpenWordList(u8 *);
extern int PMS_INPUT_HitInitialCell(u8 *);
extern void PMSI_SEARCH_PushKey(unsigned p, int v);
extern int PMSI_SEARCH_Run(u8 *);
extern int PMS_INPUT_HitInitialButtons(void *a0);
extern int PMSI_SEARCH_PopKey(u32 p);
void PMS_INPUT_HandleBrowseTouch(u8 *p,u32 *q)
{
    int r;
    switch(PMS_INPUT_HitBrowseTopButtons(p)) {
    case 1:
        GFL_USE_PlaySeDefaultVolume(1361);
        PMS_INPUT_VIEW_StartTask(*(u8 * *)&((struct Obj00586 *)p)->f14,11);
        *(Handler *)&((struct Obj00586 *)p)->f28=PMS_INPUT_HandleMenu;
        *q=2;
        return;
    case 2:
        GFL_USE_PlaySeDefaultVolume(1355);
        p[0x69]^=1;
        PMS_INPUT_ResetCursor(p);
        PMS_INPUT_VIEW_StartTask(*(u8 * *)&((struct Obj00586 *)p)->f14,25);
        *q=4;
        return;
    }
    if(p[0x69]==0) {
        r=PMS_INPUT_HitCategoryCell(p);
        if(r>=0) {
            ((struct Obj00586 *)p)->f4C=r;
            PMS_INPUT_VIEW_StartTask(*(u8 * *)&((struct Obj00586 *)p)->f14,33);
            if(r>=12 || !PMS_INPUT_DATA_GetCategoryWordCount(*(u8 * *)&((struct Obj00586 *)p)->f18,((struct Obj00586 *)p)->f4C)) {
                GFL_USE_PlaySeDefaultVolume(1367);
                return;
            }
            PMS_INPUT_OpenWordList(p);
            *q=2;
            return;
        }
    } else {
        r=PMS_INPUT_HitInitialCell(p);
        if(r>-1) {
            ((struct Obj00586 *)p)->f4C=r;
            PMSI_SEARCH_PushKey((unsigned int)(*(u8 * *)&((struct Obj00586 *)p)->f1C),((struct Obj00586 *)p)->f4C);
            PMSI_SEARCH_Run(*(u8 * *)&((struct Obj00586 *)p)->f1C);
            PMS_INPUT_VIEW_StartTask(*(u8 * *)&((struct Obj00586 *)p)->f14,30);
            GFL_USE_PlaySeDefaultVolume(1356);
            PMS_INPUT_VIEW_StartTask(*(u8 * *)&((struct Obj00586 *)p)->f14,33);
            return;
        }
        switch(PMS_INPUT_HitInitialButtons(p)) {
        case 0:
            ((struct Obj00586 *)p)->f4C=252;
            if(PMSI_SEARCH_Run(*(u8 * *)&((struct Obj00586 *)p)->f1C)) {
                PMS_INPUT_OpenWordList(p);
                *q=2;
                return;
            } else {
                GFL_USE_PlaySeDefaultVolume(1367);
                return;
            }
        case 1:
            ((struct Obj00586 *)p)->f4C=253;
            if(PMSI_SEARCH_PopKey((u32)(*(u8 * *)&((struct Obj00586 *)p)->f1C))) {
                ((struct Obj00586 *)p)->f50=((struct Obj00586 *)p)->f4C;
                *q=1;
                GFL_USE_PlaySeDefaultVolume(1363);
                PMS_INPUT_VIEW_StartTask(*(u8 * *)&((struct Obj00586 *)p)->f14,32);
                PMSI_SEARCH_Run(*(u8 * *)&((struct Obj00586 *)p)->f1C);
                PMS_INPUT_VIEW_StartTask(*(u8 * *)&((struct Obj00586 *)p)->f14,30);
                return;
            } else {
                GFL_USE_PlaySeDefaultVolume(1367);
                return;
            }
        case 2:
            ((struct Obj00586 *)p)->f4C=254;
            GFL_USE_PlaySeDefaultVolume(1361);
            PMS_INPUT_VIEW_StartTask(*(u8 * *)&((struct Obj00586 *)p)->f14,11);
            *(Handler *)&((struct Obj00586 *)p)->f28=PMS_INPUT_HandleMenu;
            *q=2;
            break;
        case -1:
            break;
        }
    }
}
