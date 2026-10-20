#ifndef GAME_ARM9_MUSICAL_SHOT_H
#define GAME_ARM9_MUSICAL_SHOT_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of musical_shot.c, prototypes copied from their definitions. */

struct MusicalShot;
struct SaveControl;
struct MusicalShotPhoto;

#include "../types.h"

u32 MUSICAL_SHOT_GetSize(void);
void MUSICAL_SHOT_Init(struct MusicalShot *shot);
struct MusicalShot *MUSICAL_SHOT_GetFromSave(struct SaveControl *save);
void MUSICAL_SHOT_CopyPhoto(struct MusicalShotPhoto *dest, const struct MusicalShotPhoto *src);
void MUSICAL_SHOT_CopyPhotoRev(const struct MusicalShotPhoto *src, struct MusicalShotPhoto *dest);
u16 *MUSICAL_SHOT_GetTitle(struct MusicalShot *shot);
u8 *MUSICAL_SHOT_GetExtraData(struct MusicalShot *shot);
/* END mkheaders: generated region */

#endif
