#ifndef GAME_OV021_FIELD_PALACE_SYS_H
#define GAME_OV021_FIELD_PALACE_SYS_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of field_palace_sys.c, prototypes copied from their definitions. */

struct FieldPalaceSys;
struct GameSystem;
struct GameData;
typedef struct FieldPalaceSys FieldPalaceSys;

#include "../types.h"

FieldPalaceSys *FIELD_PALACE_SYS_Create(u16 heapId, struct GameSystem *gameSystem, void *fieldMap, u16 zoneId);
void FIELD_PALACE_SYS_Delete(FieldPalaceSys *sys);
u8 *FIELD_PALACE_SYS_GetPalTable(FieldPalaceSys *sys);
void FIELD_PALACE_SYS_SetupPalTable(FieldPalaceSys *sys, u16 zoneId, u16 heapId);
void FIELD_PALACE_SYS_LoadPalTable(FieldPalaceSys *sys, u32 fileId, int zoneId, int season, u16 heapId);
int FIELD_PALACE_SYS_IsZoneFlagSet(struct GameData *gameData, int zoneId);
/* END mkheaders: generated region */

#endif
