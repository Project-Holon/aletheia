#ifndef GAME_ARM9_MUSICAL_DIST_SAVE_H
#define GAME_ARM9_MUSICAL_DIST_SAVE_H

struct MusicalDist *MUSICAL_DIST_SAVE_Create(void *game_sys, u32 heap_id);
struct MusicalDist *MUSICAL_DIST_SAVE_CreateFromData(void *game_sys, const void *data, u32 size, u32 heap_id);

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of musical_dist_save.c, prototypes copied from their definitions. */

struct MusicalDist;
struct BlockImage;

#include "../types.h"

struct MusicalDist *MUSICAL_DIST_SAVE_Create(void *game_sys, u32 heap_id);
void MUSICAL_DIST_SAVE_Delete(struct MusicalDist *dist);
struct MusicalDist *MUSICAL_DIST_SAVE_CreateFromData(void *game_sys, const void *data, u32 size, u32 heap_id);
u32 MUSICAL_DIST_SAVE_ProcessApply(struct MusicalDist *dist);
u32 MUSICAL_DIST_SAVE_GetPayload(struct MusicalDist *dist);
u32 MUSICAL_DIST_SAVE_GetPayloadSize(struct MusicalDist *dist);
u32 MUSICAL_DIST_SAVE_GetBlockSize(void);
void MUSICAL_DIST_SAVE_NoOp(void);
u32 MUSICAL_DIST_SAVE_IsFooterSet(struct BlockImage *image);
/* END mkheaders: generated region */

#endif
