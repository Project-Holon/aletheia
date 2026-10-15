/*
 * function: ZKNSEARCH_MAIN_EnterListPage1
 * address: 0x021BD500
 * packet: pkt_ov210_021BD500
 * region: ov210
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * prototype: 021BCAC8 receives the caller's explicit r0 even though its body ignores it; BC5C8 reads no inputs.
 * symbols:
 *   ZKNSEARCH_MAIN_SetBrightness 0x021BC8B4 thumb ov210
 *   ZKNSEARCH_MAIN_InitListTexts 0x021BE83C thumb ov210
 *   ZKNSEARCH_MENU_InitFrameList 0x021C0234 thumb ov210
 *   FRAME_LIST_UpdateInit 0x021B7A64 thumb ov067
 *   ZKNSEARCH_MAIN_ShowActorsPage1 0x021BF480 thumb ov210
 *   ZKNSEARCH_MAIN_LoadBgTile89 0x021BCAC8 thumb ov210
 *   ZKNSEARCH_MAIN_ShowLayerSetB 0x021BC5C8 thumb ov210
 *   ZKNSEARCH_MAIN_SetFadeStateA 0x021BCD30 thumb ov210
 */
#include "../include/Obj06694.h"
typedef unsigned char u8;
extern void ZKNSEARCH_MAIN_SetBrightness(int);
extern void ZKNSEARCH_MAIN_InitListTexts(u8 *);
extern void ZKNSEARCH_MENU_InitFrameList(char *ctx);
struct S;
extern int FRAME_LIST_UpdateInit(struct S *p);
extern void ZKNSEARCH_MAIN_ShowActorsPage1(int p);
extern void ZKNSEARCH_MAIN_LoadBgTile89(u8 *);
extern void ZKNSEARCH_MAIN_ShowLayerSetB(void);
extern void ZKNSEARCH_MAIN_SetFadeStateA(u8 *);
int ZKNSEARCH_MAIN_EnterListPage1(u8 *p)
{
    switch (p[0x2BA]) {
    case 0:
        p[0x2B9] = 0;
        ZKNSEARCH_MAIN_SetBrightness(1);
        ZKNSEARCH_MAIN_InitListTexts(p);
        ZKNSEARCH_MENU_InitFrameList((char *)p);
        p[0x2BA]++;
    case 1:
        if (FRAME_LIST_UpdateInit(((struct Obj06694 *)p)->f1E0) == 0) {
            ZKNSEARCH_MAIN_ShowActorsPage1((int)p);
            ZKNSEARCH_MAIN_LoadBgTile89(p);
            ZKNSEARCH_MAIN_ShowLayerSetB();
            ZKNSEARCH_MAIN_SetFadeStateA(p);
            p[0x2BA] = 0;
            return 10;
        }
    }
    return 9;
}
