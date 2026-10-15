/*
 * function: ZKNSEARCH_MAIN_EnterListPage5
 * address: 0x021BDD90
 * packet: pkt_ov210_021BDD90
 * region: ov210
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * prototype: 021BCB88 receives the caller's explicit r0 even though its body ignores it; BC5C8 reads no inputs.
 * symbols:
 *   ZKNSEARCH_MAIN_SetBrightness 0x021BC8B4 thumb ov210
 *   ZKNSEARCH_MAIN_InitListTexts5 0x021BEBE8 thumb ov210
 *   ZKNSEARCH_RESULT_InitFrameList 0x021C04CC thumb ov210
 *   FRAME_LIST_UpdateInit 0x021B7A64 thumb ov067
 *   ZKNSEARCH_MAIN_UpdateCursorActors 0x021BF728 thumb ov210
 *   ZKNSEARCH_MAIN_ShowActorsPage5 0x021BF5B8 thumb ov210
 *   ZKNSEARCH_MAIN_LoadBgTile87 0x021BCB88 thumb ov210
 *   ZKNSEARCH_MAIN_ShowLayerSetB 0x021BC5C8 thumb ov210
 *   ZKNSEARCH_MAIN_SetFadeStateA 0x021BCD30 thumb ov210
 */
#include "../include/Obj06698.h"
typedef unsigned char u8;
extern void ZKNSEARCH_MAIN_SetBrightness(int);
extern void ZKNSEARCH_MAIN_InitListTexts5(u8 *);
extern void ZKNSEARCH_RESULT_InitFrameList(char *ctx);
struct S;
extern int FRAME_LIST_UpdateInit(struct S *p);
extern void ZKNSEARCH_MAIN_UpdateCursorActors(u8 *, int);
extern void ZKNSEARCH_MAIN_ShowActorsPage5(char *p);
extern void ZKNSEARCH_MAIN_LoadBgTile87(u8 *);
extern void ZKNSEARCH_MAIN_ShowLayerSetB(void);
extern void ZKNSEARCH_MAIN_SetFadeStateA(u8 *);
int ZKNSEARCH_MAIN_EnterListPage5(u8 *p)
{
    switch (p[0x2BA]) {
    case 0:
        p[0x2B9] = 4;
        ZKNSEARCH_MAIN_SetBrightness(1);
        ZKNSEARCH_MAIN_InitListTexts5(p);
        ZKNSEARCH_RESULT_InitFrameList((char *)p);
        p[0x2BA]++;
    case 1:
        if (FRAME_LIST_UpdateInit(((struct Obj06698 *)p)->f1E0) == 0) {
            ZKNSEARCH_MAIN_UpdateCursorActors(p, 0);
            ZKNSEARCH_MAIN_ShowActorsPage5((char *)p);
            ZKNSEARCH_MAIN_LoadBgTile87(p);
            ZKNSEARCH_MAIN_ShowLayerSetB();
            ZKNSEARCH_MAIN_SetFadeStateA(p);
            p[0x2BA] = 0;
            return 22;
        }
    }
    return 21;
}
