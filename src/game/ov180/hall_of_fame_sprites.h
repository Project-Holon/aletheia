#ifndef GAME_OV180_HALL_OF_FAME_SPRITES_H
#define GAME_OV180_HALL_OF_FAME_SPRITES_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of hall_of_fame_sprites.c, prototypes copied from their definitions. */

#include "../ov180/hall_of_fame_types.h"

void HALL_OF_FAME_LoadUiPalette(HallOfFameWork *work);
void HALL_OF_FAME_DeleteTextPlate(HallOfFameWork *work, int plate);
void HALL_OF_FAME_DeleteAllTextPlates(HallOfFameWork *work);
void HALL_OF_FAME_PrintToPlate(HallOfFameWork *work, int plate, void *font, void *str, int x, int y);
void HALL_OF_FAME_CreateMonPlates(HallOfFameWork *work);
void HALL_OF_FAME_PrintMonInfo(HallOfFameWork *work);
void HALL_OF_FAME_CreateTrainerPlates(HallOfFameWork *work);
void HALL_OF_FAME_UpdatePlatePositions(HallOfFameWork *work);
void HALL_OF_FAME_SetPlateEnabled(HallOfFameWork *work, int plate, unsigned enabled);
void HALL_OF_FAME_LoadUiResources(HallOfFameWork *work);
void HALL_OF_FAME_CreateMonSceneObjects(HallOfFameWork *work);
void HALL_OF_FAME_DeleteMonSceneObjects(HallOfFameWork *work);
void HALL_OF_FAME_DrawMonScene(HallOfFameWork *work);
void HALL_OF_FAME_CreateTrainerSceneObjects(HallOfFameWork *work);
void HALL_OF_FAME_DeleteTrainerSceneObjects(HallOfFameWork *work);
void HALL_OF_FAME_DrawTrainerScene(HallOfFameWork *work);
void HALL_OF_FAME_SpawnSparkles(HallOfFameWork *work);
/* END mkheaders: generated region */

#endif
