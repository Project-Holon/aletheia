/*
 * function: ZKNSEARCH_MAIN_EnterListPage4
 * address: 0x021BDB34
 * packet: pkt_ov210_021BDB34
 * region: ov210
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * prototype: 021BCB58 receives the caller's explicit r0 even though its body ignores it; BC5C8 reads no inputs.
 * symbols:
 *   ZKNSEARCH_MAIN_SetBrightness 0x021BC8B4 thumb ov210
 *   ZKNSEARCH_MAIN_InitListTexts4 0x021BEB0C thumb ov210
 *   ZKNSEARCH_COND_InitFrameList 0x021C0434 thumb ov210
 *   FRAME_LIST_UpdateInit 0x021B7A64 thumb ov067
 *   ZKNSEARCH_MAIN_UpdateCursorActors 0x021BF728 thumb ov210
 *   ZKNSEARCH_MAIN_ShowActorsPage4 0x021BF55C thumb ov210
 *   ZKNSEARCH_MAIN_LoadBgTile86 0x021BCB58 thumb ov210
 *   ZKNSEARCH_MAIN_ShowLayerSetB 0x021BC5C8 thumb ov210
 *   ZKNSEARCH_MAIN_SetFadeStateA 0x021BCD30 thumb ov210
 */
#include "../include/Obj06697.h"
typedef unsigned char u8;
extern void ZKNSEARCH_MAIN_SetBrightness(int);
extern void ZKNSEARCH_MAIN_InitListTexts4(u8 *);
extern void ZKNSEARCH_COND_InitFrameList(char *ctx);
struct S;
extern int FRAME_LIST_UpdateInit(struct S *p);
extern void ZKNSEARCH_MAIN_UpdateCursorActors(u8 *, int);
extern void ZKNSEARCH_MAIN_ShowActorsPage4(char *p);
extern void ZKNSEARCH_MAIN_LoadBgTile86(u8 *);
extern void ZKNSEARCH_MAIN_ShowLayerSetB(void);
extern void ZKNSEARCH_MAIN_SetFadeStateA(u8 *);
int ZKNSEARCH_MAIN_EnterListPage4(u8 *p)
{
    switch (p[0x2BA]) {
    case 0:
        p[0x2B9] = 3;
        ZKNSEARCH_MAIN_SetBrightness(1);
        ZKNSEARCH_MAIN_InitListTexts4(p);
        ZKNSEARCH_COND_InitFrameList((char *)p);
        p[0x2BA]++;
    case 1:
        if (FRAME_LIST_UpdateInit(((struct Obj06697 *)p)->f1E0) == 0) {
            ZKNSEARCH_MAIN_UpdateCursorActors(p, 0);
            ZKNSEARCH_MAIN_ShowActorsPage4((char *)p);
            ZKNSEARCH_MAIN_LoadBgTile86(p);
            ZKNSEARCH_MAIN_ShowLayerSetB();
            ZKNSEARCH_MAIN_SetFadeStateA(p);
            p[0x2BA] = 0;
            return 19;
        }
    }
    return 18;
}
