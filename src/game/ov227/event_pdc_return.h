#ifndef GAME_OV227_EVENT_PDC_RETURN_H
#define GAME_OV227_EVENT_PDC_RETURN_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of event_pdc_return.c, prototypes copied from their definitions. */

struct ProcSys;

#include "../types.h"

void *EVENT_PDC_RETURN_CreateArgs(u32 a, int b, u32 c, u32 heap);
void EVENT_PDC_RETURN_DeleteArgs(void *p);
int EVENT_PDC_RETURN_Init(struct ProcSys *procSys);
int EVENT_PDC_RETURN_Exit(struct ProcSys *procSys,void *b,void *c,char *p);
/* END mkheaders: generated region */

#endif
