#ifndef GAME_OV091_PLIST_PLATE_H
#define GAME_OV091_PLIST_PLATE_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of plist_plate.c, prototypes copied from their definitions. */

#include "../ov091/plist_plate_types.h"
#include "../ov091/pokelist_types.h"
#include "../types.h"

PlistPlate *PLIST_PLATE_Create(PokelistWork *work, int slot, void *mon);
PlistPlate *PLIST_PLATE_CreateEmpty(PokelistWork *work, int slot);
void PLIST_PLATE_Delete(void *unused, PlistPlate *plate);
void PLIST_PLATE_Update(PokelistWork *work, PlistPlate *plate);
void PLIST_PLATE_CreateActors(PokelistWork *work, PlistPlate *plate);
void PLIST_PLATE_CreateMonIcon(PokelistWork *work, PlistPlate *plate);
void PLIST_PLATE_Draw(PokelistWork *work, PlistPlate *plate, int isRefresh);
void PLIST_PLATE_DrawMonInfo(PokelistWork *work, PlistPlate *plate, int isRefresh);
void PLIST_PLATE_DrawHpBar(PokelistWork *work, PlistPlate *plate);
void PLIST_PLATE_DrawEgg(PokelistWork *work, PlistPlate *plate);
void PLIST_PLATE_SetSelected(PokelistWork *work, PlistPlate *plate, int selected);
void PLIST_PLATE_SetPalette(PokelistWork *work, PlistPlate *plate, int palette);
void PLIST_PLATE_SetSlideOffset(PokelistWork *work, const PlistPlate *plate, int slideX);
void PLIST_PLATE_ClearSlideTrail(PokelistWork *work, PlistPlate *plate, int slideX);
void PLIST_PLATE_SetMon(PokelistWork *work, PlistPlate *plate, void *mon, int slideX);
void PLIST_PLATE_Redraw(PokelistWork *work, PlistPlate *plate);
void PLIST_PLATE_RedrawHp(PokelistWork *work, PlistPlate *plate);
void PLIST_PLATE_StartHpAnim(PokelistWork *work, PlistPlate *plate);
int PLIST_PLATE_StepHpAnim(PokelistWork *work, PlistPlate *plate);
int PLIST_PLATE_IsOccupied(void *unused, PlistPlate *plate);
void PLIST_PLATE_GetCenterPos(void *unused, PlistPlate *plate, PlistPlatePos *out);
void PLIST_PLATE_GetTouchRect(PokelistWork *work, PlistPlate *plate, PlistPlateRect *out);
int PLIST_PLATE_GetLabelState(PlistPlate *plate);
void PLIST_PLATE_SetLabelState(PokelistWork *work, PlistPlate *plate, int labelState);
u16 PLIST_PLATE_GetHp(PokelistWork *work, PlistPlate *plate);
int PLIST_PLATE_IsEgg(PokelistWork *work, PlistPlate *plate);
void PLIST_PLATE_UpdateLabelState(PokelistWork *work, PlistPlate *plate);
int PLIST_PLATE_CheckSelection(PokelistWork *work, PlistPlate *plate);
u8 PLIST_PLATE_GetHpBarColor(PlistPlate *plate);
void PLIST_PLATE_GetActorOffset(PlistPlate *plate, int x, int y, PlistPlatePos *out);
/* END mkheaders: generated region */

#endif
