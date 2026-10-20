#ifndef GAME_OV047_FIELD_GIMMICK_BRIDGE_H
#define GAME_OV047_FIELD_GIMMICK_BRIDGE_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of field_gimmick_bridge.c, prototypes copied from their definitions. */

struct GameSystem;

#include "../ov021/fieldmap_types.h"
#include "../ov047/field_gimmick_bridge_types.h"

void FIELD_GIMMICK_BRIDGE_Init(FieldMap *fieldMap);
void FIELD_GIMMICK_BRIDGE_Exit(FieldMap *fieldMap);
void FIELD_GIMMICK_BRIDGE_Update(FieldMap *fieldMap);
void FIELD_GIMMICK_BRIDGE_ResetSave(struct GameSystem *gameSystem);
int FIELD_GIMMICK_BRIDGE_IsOnSwayTile(BridgeSwayWork *work);
/* END mkheaders: generated region */

#endif
