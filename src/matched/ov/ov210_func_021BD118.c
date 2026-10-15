/*
 * function: ZKNSEARCH_MAIN_EnterSearchResult
 * address: 0x021BD118
 * packet: pkt_ov210_021BD118
 * region: ov210
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   PALANM_GetFadeRequestBits 0x02021ED8 thumb
 *   ZKNSEARCH_MAIN_SetBrightness 0x021BC8B4 thumb ov210
 *   ZKNSEARCH_MAIN_LoadBgTile93 0x021BCA84 thumb ov210
 *   ZKNSEARCH_MAIN_UpdateResultTexts 0x021BE564 thumb ov210
 *   ZKNSEARCH_MAIN_ShowResultActors 0x021BF418 thumb ov210
 *   ZKNSEARCH_MAIN_ShowLayerSetA 0x021BC5B4 thumb ov210
 *   ZKNSEARCH_MAIN_SetFadeStateA 0x021BCD30 thumb ov210
 *   ZKNSEARCH_MAIN_InitCursorMove 0x021BFEAC thumb ov210
 *   GXx_SetMasterBrightness_ 0x0207D534 arm
 *   ZKNSEARCH_MAIN_StartScrollMove 0x021BCE0C thumb ov210
 *   ZKNSEARCH_MAIN_RequestPaletteFade 0x021BC82C thumb ov210
 */
#include "../include/Obj01779.h"
typedef unsigned char u8;
typedef unsigned int u32;
extern u32 PALANM_GetFadeRequestBits(const char *);
extern void ZKNSEARCH_MAIN_SetBrightness(int);
extern void ZKNSEARCH_MAIN_LoadBgTile93(void *a0);
extern void ZKNSEARCH_MAIN_UpdateResultTexts(u8 *);
extern u32 ZKNSEARCH_MAIN_ShowResultActors(u8 *);
extern void ZKNSEARCH_MAIN_ShowLayerSetA(u32);
extern void ZKNSEARCH_MAIN_SetFadeStateA(u8 *);
extern void ZKNSEARCH_MAIN_InitCursorMove(char *ctx, int index);
typedef unsigned short u16;
extern void GXx_SetMasterBrightness_(volatile u16 *reg, int brightness);
extern void ZKNSEARCH_MAIN_StartScrollMove(char *, int);
extern void ZKNSEARCH_MAIN_RequestPaletteFade(char *p, u8 b, u8 c);
int ZKNSEARCH_MAIN_EnterSearchResult(u8 *p)
{
    if (PALANM_GetFadeRequestBits(*(char * *)&((struct Obj01779 *)p)->fC) != 0) return 3;
    ZKNSEARCH_MAIN_SetBrightness(1);
    ZKNSEARCH_MAIN_LoadBgTile93(p);
    ZKNSEARCH_MAIN_UpdateResultTexts(p);
    ZKNSEARCH_MAIN_ShowLayerSetA(ZKNSEARCH_MAIN_ShowResultActors(p));
    ZKNSEARCH_MAIN_SetFadeStateA(p);
    if (p[0x2b9] == 255) {
        ZKNSEARCH_MAIN_InitCursorMove((char *)p, 0);
        GXx_SetMasterBrightness_((void *)0x0400006c, 0);
        GXx_SetMasterBrightness_((void *)0x0400106c, 0);
        ZKNSEARCH_MAIN_StartScrollMove((char *)p, -8);
        ZKNSEARCH_MAIN_RequestPaletteFade((char *)p, 16, 0);
        return 4;
    } else {
        ZKNSEARCH_MAIN_InitCursorMove((char *)p, p[0x2b9]);
        return 4;
    }
}
