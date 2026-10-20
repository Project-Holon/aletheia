#ifndef GAME_OV078_ENCEFF_RIPPLE_H
#define GAME_OV078_ENCEFF_RIPPLE_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of enceff_ripple.c, prototypes copied from their definitions. */

struct FieldMap;
struct GameEvent;
struct EncEffWork;

#include "../ov078/enceff_ripple_types.h"

void *ENCEFF_BuildRippleKind02(void *gameSystem, struct FieldMap *fieldMap);
void *ENCEFF_BuildRippleKind36(void *gameSystem, struct FieldMap *fieldMap);
void *ENCEFF_StartRipple(void *gameSystem);
int ENCEFF_RippleEventMain(struct GameEvent *event, int *state);
void ENCEFF_UpdateRipple(struct EncEffWork *eff);
void ENCEFF_DrawRipple(EncEffRipple *ripple);
int ENCEFF_StepRipple(EncEffRipple *ripple);
void *ENCEFF_StartRippleBurst(void *gameSystem);
/* END mkheaders: generated region */

#endif
