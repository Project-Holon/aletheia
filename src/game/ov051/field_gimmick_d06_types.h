#ifndef ALETHEIA_OV051_FIELD_GIMMICK_D06_TYPES_H
#define ALETHEIA_OV051_FIELD_GIMMICK_D06_TYPES_H

#include "../types.h"

/*
 * Field gimmick D06 (overlay 51): the floating electric stones. The player
 * pushes a stone; it slides over the floor until something blocks it. A stone
 * that comes to rest against an electric panel tile (terrain id
 * MAP_ATTR_TERRAIN_ELECTRIC_PANEL, drawn by the d06denki effect) keeps its
 * charge; the panels pulse when a stone is pushed onto them.
 *
 * One table row per zone holds the grid positions of that zone: the stones
 * the first time the player enters it, and the electric panels.
 */

#include "../ov051/field_gimmick_d06_ids.h"

/* Include ov021/fld_exp_obj_types.h first (the compiler resolves includes against the source file directory). */

struct FieldMap;
struct GameSystem;
struct GameData;
struct GimmickWork;
struct GameEvent;
struct Mmdl;
struct MmdlSys;
struct FieldPlayer;
struct FieldEffectSys;
struct FieldEffectObj;
struct G3dMapper;

/* Object id of the stones among the map objects. */
#define GIMMICK_D06_STONE_OBJ_ID 0xFD

#define GIMMICK_D06_STONE_MAX 12
#define GIMMICK_D06_PANEL_MAX 14

/* Most tiles the scan of a push looks ahead. */
#define GIMMICK_D06_SLIDE_SCAN_MAX 32

/* Bits of the move failure mask of FLDMMDL_MOVE_HitCheckMoveCurrent (collision test of an object against a cell). */
#define GIMMICK_D06_MOVE_FAIL_IGNORED 0x01      /* not a reason to stop the slide */
#define GIMMICK_D06_MOVE_FAIL_TERRAIN 0x02      /* the terrain of the cell blocks */

/* Animation command bases of the objects (see FLDMMDL_ACMD_ConvertCodeByDir: a base plus the direction). */
#define GIMMICK_D06_ACMD_SLIDE_FAST 0x08        /* more than four tiles left */
#define GIMMICK_D06_ACMD_SLIDE_MID  0x0C        /* three or four tiles left */
#define GIMMICK_D06_ACMD_SLIDE_SLOW 0x10        /* one or two tiles left */
#define GIMMICK_D06_ACMD_PLAYER_BUMP 0x1C       /* the player pushes against the stone */

/* Sound effects. */
#define GIMMICK_D06_SE_PUSH_START 0x6CE         /* push that moves the stone */
#define GIMMICK_D06_SE_SLIDE_END  0x6A3         /* the slide ends */
#define GIMMICK_D06_SE_PUSH_BLOCKED 0x55A       /* push of a stone that cannot move */

/* A cell of the map. */
typedef struct GimmickD06GridPos {
    s32 x;
    s32 y;          /* height level */
    s32 z;
} GimmickD06GridPos;

/* The cells of one zone (0xC bytes). */
typedef struct GimmickD06ZoneTable {
    s32 zoneId;
    s32 count;
    const GimmickD06GridPos *positions;
} GimmickD06ZoneTable;

/* One stone: its object and the effect that follows it (8 bytes). */
typedef struct GimmickD06StoneSlot {
    struct Mmdl *mmdl;
    struct FieldEffectObj *follow;
} GimmickD06StoneSlot;

struct GimmickD06Save;

/* The runtime work of the gimmick (0xA4 bytes, owned by the gimmick save area). */
typedef struct GimmickD06Work {
    s32 zoneId;                                                 /* 0x00 */
    struct GimmickD06Save *save;                                /* 0x04 */
    struct FieldMap *fieldMap;                                  /* 0x08 */
    GimmickD06StoneSlot stones[GIMMICK_D06_STONE_MAX];         /* 0x0C */
    struct FieldEffectObj *panelPulse[GIMMICK_D06_PANEL_MAX];  /* 0x6C */
} GimmickD06Work;

/* The gimmick save area (8 bytes, one per gimmick id). */
typedef struct GimmickD06Save {
    u8 placed;                  /* 0x00: the stones of the zone were created once */
    u8 pad01[3];
    GimmickD06Work *work;       /* 0x04: runtime work while the map is loaded */
} GimmickD06Save;

/* Work of the event that slides a stone (0x10 bytes). */
typedef struct GimmickD06SlideEvent {
    u16 direction;              /* 0x00: push direction */
    u16 slotIndex;              /* 0x02: index of the stone in the work */
    s32 stepsLeft;              /* 0x04: tiles still to slide; 0 when the stone cannot move */
    GimmickD06StoneSlot *slot;  /* 0x08 */
    GimmickD06Work *work;       /* 0x0C */
} GimmickD06SlideEvent;

#include "../arm9/game_event.h"

/* The functions of overlay 21 and arm9 that the gimmick uses. */

/* Map objects (ov010). */

/* Player and map attributes. */

/* The d06denki effect (ov021). */

/* Defined in unplaced/FIELD_GIMMICK_D06_GetGimmickId.c. */

#endif
