#ifndef GAME_OV227_EVENT_PDC_RETURN_H
#define GAME_OV227_EVENT_PDC_RETURN_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of event_pdc_return.c, prototypes copied from their definitions. */

struct ProcSys;
struct GameData;
struct PokemonParam;

#include "../types.h"

void *EVENT_PDC_RETURN_CreateArgs(const struct GameData *gameData, int mode, struct PokemonParam *mon, u32 heap);
void EVENT_PDC_RETURN_DeleteArgs(void *p);
int EVENT_PDC_RETURN_Init(struct ProcSys *procSys);
int EVENT_PDC_RETURN_Exit(struct ProcSys *procSys,void *b,void *c,char *p);
/* END mkheaders: generated region */

#endif
