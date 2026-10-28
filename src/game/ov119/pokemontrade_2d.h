#ifndef GAME_OV119_POKEMONTRADE_2D_H
#define GAME_OV119_POKEMONTRADE_2D_H
struct TcbTask;

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of pokemontrade_2d.c, prototypes copied from their definitions. */

struct GameData;
struct ClactActor;
struct BezierCurve;

#include "../ov119/pokemontrade_types.h"
#include "../types.h"
#include "../sdk_fx.h"
#include "../sdk_fx.h"
#include "../sdk_fx.h"
#include "../sdk_fx.h"

unsigned char POKETRADE_2D_GetMonMarkingIcon(void *mon, unsigned int heap);
void POKETRADE_2D_BuildBoxMarkingTable(TradeWork *p, int box, unsigned char *out);
void POKETRADE_2D_BuildPartyMarkingTable(TradeWork *p, void *party, unsigned char *out);
int POKETRADE_2D_BuildMarkingTablesFrom(TradeWork *p, int i);
void POKETRADE_2D_InitClactSystemMain(TradeWork *p);
void POKETRADE_2D_InitClactSystemSub(TradeWork *p);
void POKETRADE_2D_LoadBackgroundGfx(TradeWork *p);
void POKETRADE_2D_FreeBackgroundPalette(TradeWork *p);
void POKETRADE_2D_LoadSubBackgroundGfx(TradeWork *p);
void POKETRADE_2D_NoOp(void *p);
void POKETRADE_2D_LoadMainGfxAndMessageWindow(TradeWork *p);
void POKETRADE_2D_CreateFontResource(TradeWork *p);
void POKETRADE_2D_FreeMainResources(TradeWork *p);
void POKETRADE_2D_RegisterIconCharResources(TradeWork *p);
void POKETRADE_2D_LoadSummaryBackground(TradeWork *p, int shiftScroll, int bgIndex);
void POKETRADE_2D_ClearSummaryBackground(TradeWork *p);
unsigned short POKETRADE_2D_GetBoxScreenEntry(int i, int row, TradeWork *p, int mode);
int POKETRADE_2D_HitTestBoxGrid(TradeWork *p, int x, int y);
void POKETRADE_2D_DrawBoxGridScreen(TradeWork *p);
void POKETRADE_2D_LoadBoxScreenData(TradeWork *p, int d);
void POKETRADE_2D_FreeBoxScreenData(TradeWork *p);
void POKETRADE_2D_CreateBoxWindows(TradeWork *p);
void POKETRADE_2D_DeleteBoxWindows(TradeWork *p);
void POKETRADE_2D_DrawBoxNames(TradeWork *p);
void POKETRADE_2D_CreateBoxIconActors(TradeWork *p);
void POKETRADE_2D_DeleteBoxIconRow(TradeWork *p, int n);
void POKETRADE_2D_DeleteAllBoxIcons(TradeWork *p);
void POKETRADE_2D_DeleteOfferIcons(TradeWork *p);
void POKETRADE_2D_GetGridCellPos(int x, int y, unsigned short *out);
void *POKETRADE_2D_ResolveGridCell(struct GameData *v, int a, int b, TradeWork *p, int *out);
char *POKETRADE_2D_GetGridCellMon(int a, int b, TradeWork *p);
void POKETRADE_2D_PlaceBoxIconActors(TradeWork *p);
int POKETRADE_2D_IsBoxIconFiltered(TradeWork *p, int i);
int POKETRADE_2D_IsBoxIconMatch(int i, int x);
void POKETRADE_2D_SetIconObjMode(void *unused, struct ClactActor *actor, int enable);
void POKETRADE_2D_UpdateIconObjMode(TradeWork *p, int gridSlot, int column, void *mon, int cellKind, int row);
void POKETRADE_2D_CreateBoxIcon(TradeWork *p, struct GameData *v, int a, int row, int flag);
int POKETRADE_2D_GetScrollColumn(TradeWork *p);
int POKETRADE_2D_GetVisibleColumnRange(TradeWork *p, int *out);
void POKETRADE_2D_UpdateVisibleColumns(struct GameData *a, TradeWork *p, int b);
void POKETRADE_2D_UpdateBoxIconPositions(TradeWork *p);
void POKETRADE_2D_LoadBoxIconGfx(TradeWork *p, int b);
s32 POKETRADE_2D_WrapIndex12(s32 x);
void POKETRADE_2D_HideAllBoxIcons(TradeWork *p);
struct ClactActor *POKETRADE_2D_HitTestBoxIcons(TradeWork *p,int x,int y,int *outA,int *outB,int *outSlot,int *outColumn,int *outRow);
void POKETRADE_2D_SetupSummaryBgs(TradeWork *p,int mode);
void POKETRADE_2D_ExitSummaryBgs(TradeWork *p);
void POKETRADE_2D_InitDisplayAndClact(TradeWork *p);
void POKETRADE_2D_SetupMainBgs(void *unused);
void POKETRADE_2D_Setup3DRenderState(void);
void POKETRADE_2D_InitG3DSystem(TradeWork *p);
void POKETRADE_2D_SetupSubBgs(TradeWork *p);
void POKETRADE_2D_ExitSubBgs(TradeWork *p);
void POKETRADE_2D_SetDisplayConfig(int i);
void POKETRADE_2D_RegisterMarkerResources(TradeWork *p);
void POKETRADE_2D_ReleaseMarkerResources(TradeWork *p);
void POKETRADE_2D_RegisterIconSpriteResources(TradeWork *p);
void POKETRADE_2D_LoadMainPalette(TradeWork *p);
void POKETRADE_2D_CreateTouchbarActors(TradeWork *p);
void POKETRADE_2D_PlaceTouchbarActors(TradeWork *p, int b, int c);
void POKETRADE_2D_DeleteTouchbarActors(void *a);
void POKETRADE_2D_LoadSubScreenGfx(TradeWork *p);
void POKETRADE_2D_ClearSubScreen(TradeWork *p);
void POKETRADE_2D_CreateMarkingIcon(TradeWork *p, int side, void *mon);
void POKETRADE_2D_DeleteMarkingIcon(TradeIconSlot *p);
void POKETRADE_2D_CreatePokerusIcon(TradeWork *p, int side, int flag, void *mon);
void POKETRADE_2D_CreateCuredPokerusIcon(TradeWork *p, int b, void *c);
void POKETRADE_2D_CreateSummaryIcons(TradeWork *p,void *mon,int flag);
void POKETRADE_2D_DeleteSummaryIcons(TradeWork *p);
void POKETRADE_2D_UploadWindowPalette(TradeWork *p, int n, u32 x);
void POKETRADE_2D_DeleteOfferIconActor(TradeWork *p, int a, int b);
void POKETRADE_2D_SetOfferIconsVisible(TradeWork *p, int a, int v);
void POKETRADE_2D_CreateOfferIconActor(TradeWork *p,int i,int j,void *mon,int selected,u32 visible);
void POKETRADE_2D_UpdateOfferIconHighlight(TradeWork *p, int a, int b);
void POKETRADE_2D_DeleteAllOfferIconActors(TradeWork *p);
void POKETRADE_2D_CreateFloatingIconActor(TradeWork *p, int i, int j, int x, int y, void *q);
void POKETRADE_2D_StartIconFlight(TradeWork *p);
int POKETRADE_2D_UpdateIconFlight(TradeWork *p);
void POKETRADE_2D_DeleteFloatingIconActor(TradeWork *p);
void POKETRADE_2D_SetupSubBlend(void *p);
void POKETRADE_2D_CreateMarkerActor(TradeWork *p, int i);
void POKETRADE_2D_SetMarkerActorVisible(TradeWork *p, int i, int a);
void POKETRADE_2D_DeleteMarkerActor(TradeWork *p, int i);
void POKETRADE_2D_SetMarkerActorAnim(TradeWork *p, int i);
void POKETRADE_2D_CreateMarkerButtonActor(TradeWork *p, int z, int i);
void POKETRADE_2D_DeleteMarkerButtonPair(TradeWork *p, int n);
void POKETRADE_2D_MovePickedIconActor(TradeWork *p, int i);
void POKETRADE_2D_DeletePickedIconActor(TradeWork *p);
int POKETRADE_2D_StepCursorSlide(TradeWork *p);
void POKETRADE_2D_SetCursorSlidePositions(TradeWork *p);
void POKETRADE_2D_SetupCursorBg(TradeWork *p);
void POKETRADE_2D_CreateOfferWindows(TradeWork *work);
void POKETRADE_2D_DeleteOfferWindowActors(TradeWork *p);
void POKETRADE_2D_UpdateOfferWindowActors(TradeWork *p);
void POKETRADE_2D_LoadMonPalette(TradeWork *p, int side, void *mon);
void POKETRADE_2D_OnCursorAnimDone(void *param, u32 frame);
void POKETRADE_2D_CreateCursorActor(TradeWork *p, int x, int y);
void POKETRADE_2D_DeleteCursorActor(TradeWork *p);
int POKETRADE_2D_ClearCursorIfDisabled(TradeWork *p);
void POKETRADE_2D_FadePaletteBank(TradeWork *p, int bank, int mask);
void POKETRADE_2D_FadePaletteCopy(TradeWork *p, int capture, int bank, int mask);
void POKETRADE_2D_FadePaletteAll(TradeWork *p, int a);
void POKETRADE_2D_ScheduleMainPlaneVisible(void *p, int a);
void POKETRADE_2D_ScheduleSubPlaneVisible(void *p, int a);
void POKETRADE_2D_TaskSetMainPlaneVisible(struct TcbTask *p, void *a);
void POKETRADE_2D_TaskSetSubPlaneVisible(struct TcbTask *p, void *a);
void POKETRADE_2D_InitBezierCurve(struct BezierCurve *d, VecFx32 *a, VecFx32 *b, VecFx32 *c, VecFx32 *dd, int e);
int POKETRADE_2D_StepBezierCurve(struct BezierCurve *c);
/* END mkheaders: generated region */

#endif
