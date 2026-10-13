#ifndef ALETHEIA_OV077_ENCEFF_GRID_TYPES_H
#define ALETHEIA_OV077_ENCEFF_GRID_TYPES_H

/*
 * Encounter effect library of overlay 0x4D: the screen is cut into a grid of
 * cells (a cell is cellWidth x cellHeight tiles of 8 pixels). Each cell is a
 * textured quad that a step callback starts one after another; a cell
 * callback turns it until it is done. The effect ends when every cell is done.
 * Overlay 0x4F (ov079) is the user of this library.
 */

/* The includer must include enceff_base_types.h first. */

struct GameSystem;
struct GameEvent;
struct EncEffWork;
struct EncEffGridWork;

/* One cell, 0x40 bytes. */
typedef struct EncEffGridCell {
    VecFx32 pos;                /* 0x00 position of the cell centre */
    u8 reserved0C[0xC];
    s32 angleX;                 /* 0x18 rotation, 16 bit angle << 4 (fx32) */
    s32 angleY;                 /* 0x1C */
    s32 angleZ;                 /* 0x20 */
    s32 velocityX;              /* 0x24 only ov081 reads it (slide speed of the cell) */
    u8 reserved28[8];
    s32 phase;                  /* 0x30 state of the cell callback */
    s32 active;                 /* 0x34 set by the step callback to start the cell */
    s32 finished;               /* 0x38 */
    int (*cellCallback)(struct EncEffGridCell *cell);   /* 0x3C returns nonzero when the cell is done, may be NULL */
} EncEffGridCell;

#define ENCEFF_GRID_CELL_MAX 0xC0

/* State of the step callback of the user of the library. */
typedef struct EncEffGridStepState {
    int nextCell;               /* 0x00 next cell to start */
    int delay;                  /* 0x04 frames to wait before the next cell */
} EncEffGridStepState;

/* Work of the grid effect, 0x3080 bytes. */
typedef struct EncEffGridWork {
    EncEffGridCell cell[ENCEFF_GRID_CELL_MAX];  /* 0x0000 */
    EncEffGridStepState step;   /* 0x3000 */
    u16 cols;                   /* 0x3008 */
    u16 rows;                   /* 0x300A */
    u8 reserved300C[0x64];
    void (*stepCallback)(struct EncEffGridWork *work);  /* 0x3070 called every frame */
    u32 fadeScreens;            /* 0x3074 screens of the closing fade (0xC or 3) */
    u32 clearColor;             /* 0x3078 3D clear colour (0x7FFF or 0) */
} EncEffGridWork;

/* What a user of the library passes to ENCEFF create (0x14 bytes). */
typedef struct EncEffGridParam {
    int cellWidth;              /* 0x00 tiles, divides 32 */
    int cellHeight;             /* 0x04 tiles, divides 24 */
    void (*initCallback)(EncEffGridWork *work);         /* 0x08 may be NULL, runs after the cells are placed */
    void (*stepCallback)(EncEffGridWork *work);         /* 0x0C */
    int (*cellCallback)(EncEffGridCell *cell);          /* 0x10 */
} EncEffGridParam;

extern struct FieldMap *GAMESYSTEM_GetFieldMap(struct GameSystem *gameSystem);
extern struct EncEffWork *FIELDMAP_GetEncEff(struct FieldMap *fieldMap);
extern void *ENCEFF_AllocWork(struct EncEffWork *eff, u32 size, u32 heapId);
extern EncEffGridWork *ENCEFF_GetWork(struct EncEffWork *eff);

#endif
