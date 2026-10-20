#ifndef ALETHEIA_OV047_FIELD_GIMMICK_BRIDGE_TYPES_H
#define ALETHEIA_OV047_FIELD_GIMMICK_BRIDGE_TYPES_H

/*
 * Field gimmick 31 (overlay 47): while the player stands on a no-dash tile
 * the player model bobs up and down, as on a swaying bridge. Each cycle of
 * the sway picks a random amplitude from a four entry table.
 */

#include "../ov021/fieldmap_types.h"
#include "../ov010/fldmmdl_types.h"

#include "../types.h"

struct GameSystem;
struct GameData;
struct GimmickWork;
typedef struct FieldPlayer FieldPlayer;

/* Id of this gimmick in the gimmick work. */
#define FIELD_GIMMICK_ID_BRIDGE_SWAY 31

/* Work id of the sway work in the field map work table. */
#define BRIDGE_SWAY_WORK_ID 1

/* The sway work (0x14 bytes, field map work id 1). */
typedef struct BridgeSwayWork {
    FieldPlayer *player;    /* 0x00 */
    Mmdl *playerMmdl;       /* 0x04: model that receives the draw offset */
    VecFx32 drawOffset;     /* 0x08: only y is written, in fx32 */
} BridgeSwayWork;

/* The sway state in the gimmick save area (4 bytes). */
typedef struct BridgeSwaySave {
    s16 angle;              /* 0x00: sway phase in degrees, 0..359 */
    s16 amplitude;          /* 0x02: peak height of the current cycle, in tiles */
} BridgeSwaySave;

/* The functions of overlay 21 and arm9 that the gimmick uses. */

void FIELD_GIMMICK_BRIDGE_Init(FieldMap *fieldMap);
void FIELD_GIMMICK_BRIDGE_Exit(FieldMap *fieldMap);
void FIELD_GIMMICK_BRIDGE_Update(FieldMap *fieldMap);
void FIELD_GIMMICK_BRIDGE_ResetSave(struct GameSystem *gameSystem);
int FIELD_GIMMICK_BRIDGE_IsOnSwayTile(BridgeSwayWork *work);

#endif
