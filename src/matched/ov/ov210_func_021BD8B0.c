/*
 * function: ZKNSEARCH_MAIN_EnterListPage3
 * address: 0x021BD8B0
 * packet: pkt_ov210_021BD8B0
 * region: ov210
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * prototype: 021BCB28 receives the caller's explicit r0 even though its body ignores it; BC5C8 reads no inputs.
 * symbols:
 *   ZKNSEARCH_MAIN_SetBrightness 0x021BC8B4 thumb ov210
 *   ZKNSEARCH_MAIN_InitListTexts3 0x021BE9D4 thumb ov210
 *   ZKNSEARCH_LIST_InitFrameList2 0x021C0384 thumb ov210
 *   FRAME_LIST_UpdateInit 0x021B7A64 thumb ov067
 *   ZKNSEARCH_MAIN_UpdateCursorActors 0x021BF728 thumb ov210
 *   ZKNSEARCH_MAIN_ShowActorsPage3 0x021BF500 thumb ov210
 *   ZKNSEARCH_MAIN_LoadBgTile90 0x021BCB28 thumb ov210
 *   ZKNSEARCH_MAIN_ShowLayerSetB 0x021BC5C8 thumb ov210
 *   ZKNSEARCH_MAIN_SetFadeStateA 0x021BCD30 thumb ov210
 */
#include "../include/Obj06696.h"
typedef unsigned char u8;
extern void ZKNSEARCH_MAIN_SetBrightness(int);
extern void ZKNSEARCH_MAIN_InitListTexts3(u8 *);
extern void ZKNSEARCH_LIST_InitFrameList2(char *ctx);
struct S;
extern int FRAME_LIST_UpdateInit(struct S *p);
extern void ZKNSEARCH_MAIN_UpdateCursorActors(u8 *, int);
extern void ZKNSEARCH_MAIN_ShowActorsPage3(char *p);
extern void ZKNSEARCH_MAIN_LoadBgTile90(u8 *);
extern void ZKNSEARCH_MAIN_ShowLayerSetB(void);
extern void ZKNSEARCH_MAIN_SetFadeStateA(u8 *);
int ZKNSEARCH_MAIN_EnterListPage3(u8 *p)
{
    switch (p[0x2BA]) {
    case 0:
        p[0x2B9] = 2;
        ZKNSEARCH_MAIN_SetBrightness(1);
        ZKNSEARCH_MAIN_InitListTexts3(p);
        ZKNSEARCH_LIST_InitFrameList2((char *)p);
        p[0x2BA]++;
    case 1:
        if (FRAME_LIST_UpdateInit(((struct Obj06696 *)p)->f1E0) == 0) {
            ZKNSEARCH_MAIN_UpdateCursorActors(p, 0);
            ZKNSEARCH_MAIN_ShowActorsPage3((char *)p);
            ZKNSEARCH_MAIN_LoadBgTile90(p);
            ZKNSEARCH_MAIN_ShowLayerSetB();
            ZKNSEARCH_MAIN_SetFadeStateA(p);
            p[0x2BA] = 0;
            return 16;
        }
    }
    return 15;
}
