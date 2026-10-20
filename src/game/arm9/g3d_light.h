#ifndef GAME_ARM9_G3D_LIGHT_H
#define GAME_ARM9_G3D_LIGHT_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of g3d_light.c, prototypes copied from their definitions. */

struct LightSlotValue;
struct LightSetDesc;
struct LightSlot;
struct Rgb555;

#include "../types.h"

struct LightSlotValue *G3D_LIGHT_CreateSlots(const struct LightSetDesc *set, u16 heapID);
u32 G3D_LIGHT_DeleteSlots(void *slots);
void G3D_LIGHT_ApplySlots(struct LightSlot *slots);
void G3D_LIGHT_GetDirection(struct LightSlot *slots, u8 i, struct Rgb555 *out);
void G3D_LIGHT_SetDirection(struct LightSlot *slots, u8 i, struct Rgb555 *in);
void G3D_LIGHT_GetColor(struct LightSlot *slots, u8 i, u16 *out);
void G3D_LIGHT_SetColor(struct LightSlot *slots, u32 i, u16 *in);
/* END mkheaders: generated region */

#endif
