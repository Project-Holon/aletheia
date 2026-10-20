#ifndef GAME_OV119_POKEMONTRADE_2D_H
#define GAME_OV119_POKEMONTRADE_2D_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of pokemontrade_2d.c, prototypes copied from their definitions. */

struct BezierCurve;

#include "../types.h"
#include "../ov119/pokemontrade_types.h"
#include "../sdk_fx.h"
#include "../sdk_fx.h"
#include "../sdk_fx.h"
#include "../sdk_fx.h"

unsigned char POKETRADE_2D_GetMonMarkingIcon(void *mon, unsigned int heap);
void POKETRADE_2D_BuildBoxMarkingTable(char *p, int box, unsigned char *out);
void POKETRADE_2D_BuildPartyMarkingTable(char *p, void *party, unsigned char *out);
int POKETRADE_2D_BuildMarkingTablesFrom(char *p, int i);
void POKETRADE_2D_InitClactSystemMain(char *p);
void POKETRADE_2D_InitClactSystemSub(void *p);
void POKETRADE_2D_LoadBackgroundGfx(char *p);
void POKETRADE_2D_FreeBackgroundPalette(char *p);
void POKETRADE_2D_LoadSubBackgroundGfx(char *p);
void POKETRADE_2D_NoOp(void *p);
void POKETRADE_2D_LoadMainGfxAndMessageWindow(char *p);
void POKETRADE_2D_CreateFontResource(char *p);
void POKETRADE_2D_FreeMainResources(char *p);
void POKETRADE_2D_RegisterIconCharResources(char *p);
void POKETRADE_2D_LoadSummaryBackground(char *p, int shiftScroll, int bgIndex);
void POKETRADE_2D_ClearSummaryBackground(char *p);
unsigned short POKETRADE_2D_GetBoxScreenEntry(int i, int row, char *p, int mode);
int POKETRADE_2D_HitTestBoxGrid(char *p, int x, int y);
void POKETRADE_2D_DrawBoxGridScreen(char *p);
void POKETRADE_2D_LoadBoxScreenData(char *p, int d);
void POKETRADE_2D_FreeBoxScreenData(char *p);
void POKETRADE_2D_CreateBoxWindows(char *p);
void POKETRADE_2D_DeleteBoxWindows(char *p);
void POKETRADE_2D_DrawBoxNames(char *p);
void POKETRADE_2D_CreateBoxIconActors(char *p);
void POKETRADE_2D_DeleteBoxIconRow(char *p, int n);
void POKETRADE_2D_DeleteAllBoxIcons(char *p);
void POKETRADE_2D_DeleteOfferIcons(char *p);
void POKETRADE_2D_GetGridCellPos(int x, int y, unsigned short *out);
int POKETRADE_2D_ResolveGridCell(int v, int a, int b, char *p, int *out);
char *POKETRADE_2D_GetGridCellMon(int a, int b, char *p);
void POKETRADE_2D_PlaceBoxIconActors(char *p);
int POKETRADE_2D_IsBoxIconFiltered(char *p, int i);
int POKETRADE_2D_IsBoxIconMatch(int i, int x);
void POKETRADE_2D_SetIconObjMode(int unused, int actor, int enable);
void POKETRADE_2D_UpdateIconObjMode(char *p, int gridSlot, int column, int recordId, int cellKind, int row);
void POKETRADE_2D_CreateBoxIcon(char *p, int v, int a, int row, int flag);
int POKETRADE_2D_GetScrollColumn(char *p);
int POKETRADE_2D_GetVisibleColumnRange(char *p, int *out);
void POKETRADE_2D_UpdateVisibleColumns(int a, char *p, int b);
void POKETRADE_2D_UpdateBoxIconPositions(char *p);
void POKETRADE_2D_LoadBoxIconGfx(char *p, int b);
s32 POKETRADE_2D_WrapIndex12(s32 x);
void POKETRADE_2D_HideAllBoxIcons(int p);
int POKETRADE_2D_HitTestBoxIcons(char *p,int x,int y,int *outA,int *outB,int *outSlot,int *outColumn,int *outRow);
void POKETRADE_2D_SetupSummaryBgs(char *p,int mode);
void POKETRADE_2D_ExitSummaryBgs(int p);
void POKETRADE_2D_InitDisplayAndClact(char *p);
void POKETRADE_2D_SetupMainBgs(void *unused);
void POKETRADE_2D_Setup3DRenderState(void);
void POKETRADE_2D_InitG3DSystem(char *p);
void POKETRADE_2D_SetupSubBgs(char *p);
void POKETRADE_2D_ExitSubBgs(char *p);
void POKETRADE_2D_SetDisplayConfig(int i);
void POKETRADE_2D_RegisterMarkerResources(int p);
void POKETRADE_2D_ReleaseMarkerResources(char *p);
void POKETRADE_2D_RegisterIconSpriteResources(char *p);
void POKETRADE_2D_LoadMainPalette(char *p);
void POKETRADE_2D_CreateTouchbarActors(char *p);
void POKETRADE_2D_PlaceTouchbarActors(char *p, int b, int c);
void POKETRADE_2D_DeleteTouchbarActors(void *a);
void POKETRADE_2D_LoadSubScreenGfx(char *p);
void POKETRADE_2D_ClearSubScreen(char *p);
void POKETRADE_2D_CreateMarkingIcon(char *p, int side, void *mon);
void POKETRADE_2D_DeleteMarkingIcon(void *p);
void POKETRADE_2D_CreatePokerusIcon(char *p, int side, int flag, void *mon);
void POKETRADE_2D_CreateCuredPokerusIcon(char *p, int b, void *c);
void POKETRADE_2D_CreateSummaryIcons(char *p,void *mon,int flag);
void POKETRADE_2D_DeleteSummaryIcons(void *p);
void POKETRADE_2D_UploadWindowPalette(char *p, int n, u32 x);
void POKETRADE_2D_DeleteOfferIconActor(TradeWork *p, int a, int b);
void POKETRADE_2D_SetOfferIconsVisible(TradeWork *p, int a, int v);
void POKETRADE_2D_CreateOfferIconActor(char *p,int i,int j,void *mon,int selected,u32 visible);
void POKETRADE_2D_UpdateOfferIconHighlight(void *p, int a, int b);
void POKETRADE_2D_DeleteAllOfferIconActors(void *p);
void POKETRADE_2D_CreateFloatingIconActor(int p, int i, int j, int x, int y, void *q);
void POKETRADE_2D_StartIconFlight(char *p);
int POKETRADE_2D_UpdateIconFlight(char *p);
void POKETRADE_2D_DeleteFloatingIconActor(void *p);
void POKETRADE_2D_SetupSubBlend(void *p);
void POKETRADE_2D_CreateMarkerActor(char *p, int i);
void POKETRADE_2D_SetMarkerActorVisible(void *p, int i, int a);
void POKETRADE_2D_DeleteMarkerActor(void *p, int i);
void POKETRADE_2D_SetMarkerActorAnim(void *p, int i);
void POKETRADE_2D_CreateMarkerButtonActor(TradeWork *p, int z, int i);
void POKETRADE_2D_DeleteMarkerButtonPair(int p, int n);
void POKETRADE_2D_MovePickedIconActor(void *p, int i);
void POKETRADE_2D_DeletePickedIconActor(char *p);
int POKETRADE_2D_StepCursorSlide(char *p);
void POKETRADE_2D_SetCursorSlidePositions(const char *p);
void POKETRADE_2D_SetupCursorBg(char *p);
void POKETRADE_2D_CreateOfferWindows(char *p);
void POKETRADE_2D_DeleteOfferWindowActors(char *p);
void POKETRADE_2D_UpdateOfferWindowActors(char *p);
void POKETRADE_2D_LoadMonPalette(char *p, int side, void *mon);
void POKETRADE_2D_OnCursorAnimDone(char *p);
void POKETRADE_2D_CreateCursorActor(char *p, int x, int y);
void POKETRADE_2D_DeleteCursorActor(void *p);
int POKETRADE_2D_ClearCursorIfDisabled(void *p);
void POKETRADE_2D_FadePaletteBank(char *p, int bank, int mask);
void POKETRADE_2D_FadePaletteCopy(void *p, int capture, int bank, int mask);
void POKETRADE_2D_FadePaletteAll(void *p, int a);
void POKETRADE_2D_ScheduleMainPlaneVisible(void *p, int a);
void POKETRADE_2D_ScheduleSubPlaneVisible(void *p, int a);
void POKETRADE_2D_TaskSetMainPlaneVisible(void *p, int a);
void POKETRADE_2D_TaskSetSubPlaneVisible(void *p, int a);
void POKETRADE_2D_InitBezierCurve(struct BezierCurve *d, VecFx32 *a, VecFx32 *b, VecFx32 *c, VecFx32 *dd, int e);
int POKETRADE_2D_StepBezierCurve(struct BezierCurve *c);
/* END mkheaders: generated region */

#endif
