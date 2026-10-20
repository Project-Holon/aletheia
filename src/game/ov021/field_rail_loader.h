#ifndef GAME_OV021_FIELD_RAIL_LOADER_H
#define GAME_OV021_FIELD_RAIL_LOADER_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of field_rail_loader.c, prototypes copied from their definitions. */

struct FieldRailLoader;
typedef struct FieldRailLoader FieldRailLoader;

#include "../ov021/field_rail_types.h"
#include "../types.h"

void FIELD_RAIL_LOADER_InitSetting(FieldRailSetting *setting);
FieldRailLoader *FIELD_RAIL_LOADER_Create(u32 heapId);
void FIELD_RAIL_LOADER_Delete(FieldRailLoader *loader);
void FIELD_RAIL_LOADER_Load(FieldRailLoader *loader, u32 member, u32 heapId);
void FIELD_RAIL_LOADER_Unload(FieldRailLoader *loader);
FieldRailSetting *FIELD_RAIL_LOADER_GetSetting(FieldRailLoader *loader);
int FLDMMDL_CreateTalkScriptEvent(u32 a, u32 b, u32 c, u32 e0, u32 e1, u16 id);
void FLDMMDL_MOVE_VanishProc(void *mmdl, u32 unused1, u32 unused2, u32 unused3);
void FIELD_RAIL_LOADER_EmptyProc0(void);
void FIELD_RAIL_LOADER_EmptyProc1(void);
void FIELD_RAIL_LOADER_EmptyProc2(void);
void FIELD_RAIL_LOADER_EmptyProc3(void);
/* END mkheaders: generated region */

#endif
