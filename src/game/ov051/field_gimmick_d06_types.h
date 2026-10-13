#ifndef ALETHEIA_OV051_FIELD_GIMMICK_D06_TYPES_H
#define ALETHEIA_OV051_FIELD_GIMMICK_D06_TYPES_H

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

#include "field_gimmick_d06_ids.h"

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

/* Bits of the move failure mask of func_02163994 (collision test of an object against a cell). */
#define GIMMICK_D06_MOVE_FAIL_IGNORED 0x01      /* not a reason to stop the slide */
#define GIMMICK_D06_MOVE_FAIL_TERRAIN 0x02      /* the terrain of the cell blocks */

/* Animation command bases of the objects (see func_02197E7C: a base plus the direction). */
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

typedef int (*GameEventFunc)(struct GameEvent *event, int *seq, void *work);

/* The functions of overlay 21 and arm9 that the gimmick uses. */
extern u16 func_02188C84(struct FieldMap *fieldMap);
extern struct GameSystem *func_02188C80(struct FieldMap *fieldMap);
extern struct GameData *func_020120F4(const struct GameSystem *gameSystem);
extern struct GimmickWork *func_02012EC4(struct GameData *gameData);
extern GimmickD06Save *func_0200B3A4(struct GimmickWork *gimmickWork, u32 gimmickId);
extern struct FieldEffectSys *func_02188CD0(struct FieldMap *fieldMap);
extern u16 func_02188C9C(struct FieldMap *fieldMap);
extern struct MmdlSys *func_02188C7C(struct FieldMap *fieldMap);
extern struct FieldPlayer *func_02188CB4(struct FieldMap *fieldMap);
extern struct G3dMapper *func_02188C98(struct FieldMap *fieldMap);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern u32 func_020307B0(void *memory);
extern void func_021ABE30(struct FieldEffectSys *effects, int *effectIds, int count);
extern struct GameEvent *func_020122C0(struct GameSystem *gameSystem, struct GameEvent *parent,
                                       GameEventFunc func, u32 workSize);
extern void *func_020124E8(struct GameEvent *event);
extern void func_02082C60(void *dst, int data, int size);
extern void func_020061E4(u32 seId);

/* Map objects (ov010). */
extern int func_0216DD1C(struct MmdlSys *mmdlSys, struct Mmdl **mmdlOut, u32 *iterator);
extern u16 func_0216D588(struct Mmdl *mmdl);
extern struct Mmdl *func_0216DDC0(struct MmdlSys *mmdlSys, u32 gridX, u32 gridZ, u32 flag);
extern struct Mmdl *func_0216CE6C(struct MmdlSys *mmdlSys, short gridX, short gridZ, u16 dir, u16 objId,
                                  u16 objCode, u16 moveCode, int zoneId);
extern int func_0216D3CC(struct Mmdl *mmdl);
extern void func_0216D410(struct Mmdl *mmdl, int acmd);
extern int func_0216D454(struct Mmdl *mmdl);
extern int func_0216D480(struct Mmdl *mmdl);
extern void func_0216D88C(const struct Mmdl *mmdl, VecFx32 *pos);
extern int func_0216D83C(const struct Mmdl *mmdl);
extern int func_0216D854(struct Mmdl *mmdl);
extern int func_0216D86C(const struct Mmdl *mmdl);
extern u32 func_0216D8AC(struct Mmdl *mmdl);
extern void func_02164208(int dir, VecFx32 *pos, int amount);
extern void func_02164240(int dir, short *gridX, short *gridZ, short amount);
extern void func_02164280(int gridX, int gridZ, VecFx32 *out);
extern int func_02163994(struct Mmdl *mmdl, int x, int y, int z, u32 dir);
extern int func_02197E7C(int dir, int acmdBase);

/* Player and map attributes. */
extern void func_021A3038(struct FieldPlayer *player, VecFx32 *outPos);
extern struct Mmdl *func_021A3074(struct FieldPlayer *player);
extern int func_021AB0D4(struct G3dMapper *mapper, const VecFx32 *pos);
extern int func_021AB0F0(int attr);
extern int func_021AB3F8(int terrainId);

/* The d06denki effect (ov021). */
extern struct FieldEffectObj *func_021C9064(struct FieldEffectSys *effects, const VecFx32 *pos, struct Mmdl *mmdl);
extern struct FieldEffectObj *func_021C9258(struct FieldEffectSys *effects, const VecFx32 *pos);
extern void func_021C928C(struct FieldEffectObj *effect);
extern void func_021C909C(struct FieldEffectObj *effect);
extern void func_021C90AC(struct FieldEffectObj *effect);
extern int func_021C90D0(struct FieldEffectObj *effect);

/* Defined in unplaced/ov051_func_021F3D94.c. */
extern int func_021F3D94(int zoneId);

#endif
