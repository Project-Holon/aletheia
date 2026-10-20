#ifndef GAME_OV030_NO_GEAR_H
#define GAME_OV030_NO_GEAR_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of no_gear.c, prototypes copied from their definitions. */

struct NoGearWork;
struct GameSystem;
typedef struct NoGearWork NoGearWork;

#include "../ov021/field_subscreen_types.h"

void NO_GEAR_StoreStepFunc(void (**slot)(NoGearWork *), void (*stepFunc)(NoGearWork *));
void NO_GEAR_SetStepFunc(NoGearWork *work, void (*stepFunc)(NoGearWork *), int line);
void NO_GEAR_LoadGraphics(NoGearWork *work);
void NO_GEAR_SetupBackgrounds(void);
void NO_GEAR_Init(NoGearWork *work);
void NO_GEAR_ReleaseGraphics(NoGearWork *work);
void NO_GEAR_Step(NoGearWork *work);
NoGearWork *NO_GEAR_Create(void *cgearSave, FieldSubscreen *subscreen, struct GameSystem *gameSystem);
void NO_GEAR_Update(NoGearWork *work);
void NO_GEAR_Hook(void);
void NO_GEAR_Destroy(struct NoGearWork *work);
/* END mkheaders: generated region */

#endif
