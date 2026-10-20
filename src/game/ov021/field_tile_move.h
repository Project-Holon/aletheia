#ifndef GAME_OV021_FIELD_TILE_MOVE_H
#define GAME_OV021_FIELD_TILE_MOVE_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of field_tile_move.c, prototypes copied from their definitions. */

struct TileSpinEntry;
struct TileSpinWork;
struct TileSlideEntry;
struct TileBumpEntry;
struct TileSlideWork;
typedef struct TileSpinEntry TileSpinEntry;
typedef struct TileSpinWork TileSpinWork;
typedef struct TileSlideEntry TileSlideEntry;
typedef struct TileBumpEntry TileBumpEntry;
typedef struct TileSlideWork TileSlideWork;

#include "../types.h"
#include "../ov020/event_mapchange_types.h"

TileSpinEntry *FIELD_TILE_MOVE_FindSpinEntry(u16 attr);
int FIELD_TILE_MOVE_HasSpinEntry(u16 attr);
int FIELD_TILE_MOVE_SpinTaskMain(GameEvent *event, int *state, TileSpinWork *work);
GameEvent *FIELD_TILE_MOVE_StartSpinTask(GameEvent *parent, GameSystem *gameSystem, FieldMap *fieldMap);
int FIELD_TILE_MOVE_IsSpinTile(u16 attr);
u16 FIELD_TILE_MOVE_GetSpinStepAcmd(TileSpinWork *work);
u16 FIELD_TILE_MOVE_GetSpinStopDir(TileSpinWork *work);
int FIELD_TILE_MOVE_GetSpinInterval(TileSpinWork *work);
u16 FIELD_TILE_MOVE_GetSpinTileAttr(TileSpinWork *work);
void FIELD_TILE_MOVE_SpinTick(TileSpinWork *work);
void FIELD_TILE_MOVE_SpinStartStep(TileSpinWork *work);
void FIELD_TILE_MOVE_SpinSelectEntry(TileSpinWork *work);
int FIELD_TILE_MOVE_SpinIsBlocked(TileSpinWork *work);
void FIELD_TILE_MOVE_SpinFinish(TileSpinWork *work);
const TileSlideEntry *FIELD_TILE_MOVE_FindSlideEntry(u16 attr);
int FIELD_TILE_MOVE_HasSlideEntry(u16 attr);
TileBumpEntry *FIELD_TILE_MOVE_FindBumpEntry(u16 attr);
int FIELD_TILE_MOVE_SlideTaskMain(GameEvent *event, int *state, TileSlideWork *work);
GameEvent *FIELD_TILE_MOVE_StartSlideTask(GameEvent *parent, GameSystem *gameSystem, FieldMap *fieldMap);
int FIELD_TILE_MOVE_IsSlideTile(u16 attr);
u16 FIELD_TILE_MOVE_GetSlideStepAcmd(TileSlideWork *work);
u16 FIELD_TILE_MOVE_GetBumpAcmd(TileSlideWork *work);
u16 FIELD_TILE_MOVE_GetSlideTileAttr(TileSlideWork *work);
void FIELD_TILE_MOVE_SlideStartStep(TileSlideWork *work);
void FIELD_TILE_MOVE_SlideFinishBump(TileSlideWork *work);
void FIELD_TILE_MOVE_SlideSelectSlideEntry(TileSlideWork *work);
void FIELD_TILE_MOVE_SlideSelectBumpEntry(TileSlideWork *work);
int FIELD_TILE_MOVE_SlideShowSurfPokemon(TileSlideWork *work);
void FIELD_TILE_MOVE_SlidePlayBumpSe(TileSlideWork *work);
void FIELD_TILE_MOVE_SlidePlayBumpEffectSe(TileSlideWork *work);
void FIELD_TILE_MOVE_SlidePlayLoopSe(TileSlideWork *work);
void FIELD_TILE_MOVE_SlideStopLoopSe(TileSlideWork *work);
/* END mkheaders: generated region */

#endif
