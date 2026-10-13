/*
 * function: PMS_INPUT_HandleBrowseKeys
 * address: 0x021BE580
 * packet: pkt_ov110_021BE580
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * ABI: BAF7C reads the selection still live in r1 from E6A6 through the ordinary-mode arm.
 * symbols:
 *   PMSI_SEARCH_Run 0x021BB054 thumb ov110
 *   PMS_INPUT_OpenWordList 0x021BD868 thumb ov110
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   PMS_INPUT_VIEW_StartTask 0x021B9BEC thumb ov110
 *   PMS_INPUT_ResetCursor 0x021BF82C thumb ov110
 *   PMSI_SEARCH_PopKey 0x021BAFAC thumb ov110
 *   PMS_INPUT_HandleMenu 0x021BD894 thumb ov110
 *   PMS_INPUT_CategoryHasWords 0x021BEB44 thumb ov110
 *   PMSI_SEARCH_PushKey 0x021BAF7C thumb ov110
 *   PMS_INPUT_MoveCursor 0x021BEB60 thumb ov110
 */
#include "../include/Obj00189.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef int (*Handler)(u8 *,void *);
extern int PMSI_SEARCH_Run(u8 *);
extern void PMS_INPUT_OpenWordList(u8 *);
extern void GFL_USE_PlaySeDefaultVolume(u32);
extern void PMS_INPUT_VIEW_StartTask(u8 *,int);
extern void PMS_INPUT_ResetCursor(u8 *);
extern int PMSI_SEARCH_PopKey(u32 p);
extern int PMS_INPUT_HandleMenu(u8 *,void *);
extern int PMS_INPUT_CategoryHasWords(u8 *);
extern void PMSI_SEARCH_PushKey(unsigned p, int v);
extern int PMS_INPUT_MoveCursor(u8 *);
void PMS_INPUT_HandleBrowseKeys(u8 *p,u32 *q)
{
    if((((struct Obj00189 *)p)->f34&8) && p[0x69]==1) {
        ((struct Obj00189 *)p)->f4C=252;
        if(PMSI_SEARCH_Run(*(u8 * *)&((struct Obj00189 *)p)->f1C)) {
            PMS_INPUT_OpenWordList(p);
            *q=2;
            return;
        }
        GFL_USE_PlaySeDefaultVolume(1367);
        PMS_INPUT_VIEW_StartTask(*(u8 * *)&((struct Obj00189 *)p)->f14,18);
        return;
    }
    if(((struct Obj00189 *)p)->f3C==0 || (((struct Obj00189 *)p)->f34&4)) {
        GFL_USE_PlaySeDefaultVolume(1355);
        p[0x69]^=1;
        PMS_INPUT_ResetCursor(p);
        PMS_INPUT_VIEW_StartTask(*(u8 * *)&((struct Obj00189 *)p)->f14,25);
        *q=4;
        return;
    }
    if(((struct Obj00189 *)p)->f34&2) {
        if(p[0x69]==1 && PMSI_SEARCH_PopKey((u32)(*(u8 * *)&((struct Obj00189 *)p)->f1C))) {
            ((struct Obj00189 *)p)->f50=((struct Obj00189 *)p)->f4C;
            *q=1;
            if(((struct Obj00189 *)p)->f4C!=253) {
                ((struct Obj00189 *)p)->f4C=253;
                PMS_INPUT_VIEW_StartTask(*(u8 * *)&((struct Obj00189 *)p)->f14,18);
            }
            GFL_USE_PlaySeDefaultVolume(1363);
            PMS_INPUT_VIEW_StartTask(*(u8 * *)&((struct Obj00189 *)p)->f14,32);
            PMSI_SEARCH_Run(*(u8 * *)&((struct Obj00189 *)p)->f1C);
            PMS_INPUT_VIEW_StartTask(*(u8 * *)&((struct Obj00189 *)p)->f14,30);
            return;
        }
        if(p[0x69]==1 && ((struct Obj00189 *)p)->f4C!=254) {
            ((struct Obj00189 *)p)->f4C=254;
            PMS_INPUT_VIEW_StartTask(*(u8 * *)&((struct Obj00189 *)p)->f14,18);
        }
        GFL_USE_PlaySeDefaultVolume(1361);
        PMS_INPUT_VIEW_StartTask(*(u8 * *)&((struct Obj00189 *)p)->f14,11);
        *(Handler *)&((struct Obj00189 *)p)->f28=PMS_INPUT_HandleMenu;
        *q=2;
        return;
    }
    if(((struct Obj00189 *)p)->f34&1) {
        if(((struct Obj00189 *)p)->f4C==252) {
            if(PMSI_SEARCH_Run(*(u8 * *)&((struct Obj00189 *)p)->f1C)) {
                PMS_INPUT_OpenWordList(p);
                *q=2;
                return;
            }
            GFL_USE_PlaySeDefaultVolume(1367);
            return;
        } else if(((struct Obj00189 *)p)->f4C==253) {
            if(p[0x69]==1 && PMSI_SEARCH_PopKey((u32)(*(u8 * *)&((struct Obj00189 *)p)->f1C))) {
                ((struct Obj00189 *)p)->f50=((struct Obj00189 *)p)->f4C;
                *q=1;
                GFL_USE_PlaySeDefaultVolume(1363);
                PMS_INPUT_VIEW_StartTask(*(u8 * *)&((struct Obj00189 *)p)->f14,32);
                PMSI_SEARCH_Run(*(u8 * *)&((struct Obj00189 *)p)->f1C);
                PMS_INPUT_VIEW_StartTask(*(u8 * *)&((struct Obj00189 *)p)->f14,30);
                return;
            }
            GFL_USE_PlaySeDefaultVolume(1367);
            return;
        } else if(((struct Obj00189 *)p)->f4C==254) {
            GFL_USE_PlaySeDefaultVolume(1361);
            PMS_INPUT_VIEW_StartTask(*(u8 * *)&((struct Obj00189 *)p)->f14,11);
            *(Handler *)&((struct Obj00189 *)p)->f28=PMS_INPUT_HandleMenu;
            *q=2;
            return;
        } else if(p[0x69]==0) {
            PMS_INPUT_VIEW_StartTask(*(u8 * *)&((struct Obj00189 *)p)->f14,33);
            if(PMS_INPUT_CategoryHasWords(p)) {
                PMS_INPUT_OpenWordList(p);
                *q=2;
                return;
            }
            GFL_USE_PlaySeDefaultVolume(1367);
            return;
        } else {
            PMSI_SEARCH_PushKey((unsigned int)(*(u8 * *)&((struct Obj00189 *)p)->f1C),((struct Obj00189 *)p)->f4C);
            GFL_USE_PlaySeDefaultVolume(1356);
            PMSI_SEARCH_Run(*(u8 * *)&((struct Obj00189 *)p)->f1C);
            PMS_INPUT_VIEW_StartTask(*(u8 * *)&((struct Obj00189 *)p)->f14,30);
            PMS_INPUT_VIEW_StartTask(*(u8 * *)&((struct Obj00189 *)p)->f14,33);
            return;
        }
    }
    if(PMS_INPUT_MoveCursor(p)) {
        GFL_USE_PlaySeDefaultVolume(1352);
        PMS_INPUT_VIEW_StartTask(*(u8 * *)&((struct Obj00189 *)p)->f14,18);
    }
}
