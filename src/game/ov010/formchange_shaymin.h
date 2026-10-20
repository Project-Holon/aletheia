#ifndef GAME_OV010_FORMCHANGE_SHAYMIN_H
#define GAME_OV010_FORMCHANGE_SHAYMIN_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of formchange_shaymin.c, prototypes copied from their definitions. */

struct GameData;
struct Party;
struct TimeOfDay;
typedef struct TimeOfDay TimeOfDay;

#include "../types.h"

void FORMCHANGE_RevertShaymin(struct GameData *gameData, struct Party *party);
int FORMCHANGE_RevertShayminIfTimeOfDayChanged(struct GameData *gameData, struct Party *party, int elapsedMinutes, TimeOfDay *time, int season);
int FORMCHANGE_RevertShayminAtNight(struct GameData *gameData, struct Party *party, u32 *hour, int season);
void FORMCHANGE_RevertShayminAndRegister(struct GameData *gameData, struct Party *party);
/* END mkheaders: generated region */

#endif
