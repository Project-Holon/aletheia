#ifndef ALETHEIA_OV021_FIELD_G3D_MAPPER_TYPES_H
#define ALETHEIA_OV021_FIELD_G3D_MAPPER_TYPES_H

#include "../ov010/field_g3d_map_types.h"
#include "fieldmap_types.h"

/*
 * Field 3D mapper (field_g3d_mapper.c). The mapper keeps a window of
 * cols x rows block slots over a larger grid of map blocks (gridWidth x
 * gridDepth cells, several layers high in layout 3). Each frame it lays the
 * window out around the focus position, moves the loaded blocks whose id is
 * still in the window, releases the others and starts loading the new ones.
 * Each slot owns one FieldG3dMap (ov010 field_g3d_map.c).
 */

struct FieldBuildModel;
struct FieldGroundAnime;
struct FieldWfbc;
struct HeightEx;
typedef struct G3dResource G3dResource;

/* How the window cells are placed over the grid (FieldG3dMapper.layout). */
enum {
    FIELD_G3D_MAPPER_LAYOUT_LINEAR = 0,   /* every block in order, no window */
    FIELD_G3D_MAPPER_LAYOUT_WINDOW = 1,   /* window clipped at the grid border */
    FIELD_G3D_MAPPER_LAYOUT_WRAP = 2,     /* window wraps around the grid border */
    FIELD_G3D_MAPPER_LAYOUT_LAYERS = 3    /* two grid layers nearest the focus height */
};

/* One entry of the block grid: the map model index of the block, -1 when the block is empty. */
typedef struct FieldG3dMapperGridEntry {
    unsigned int mapModelIndex;
} FieldG3dMapperGridEntry;

/* One cell of the window layout: the block id wanted there and its position. */
typedef struct FieldG3dMapperCell {
    unsigned int gridIndex;               /* 0x00, index into the block grid, -1 when the cell is empty */
    VecFx32 pos;                          /* 0x04 */
} FieldG3dMapperCell;

/* Resource handle record of one slot (0x14 bytes), filled by FIELD_G3D_MAPPER_InitSlotRes. */
typedef struct FieldG3dMapperSlotRes {
    struct FieldGroundAnime *groundAnimeSlot; /* 0x00, handle from FIELD_GROUND_ANIME_Setup7404 */
    struct FieldBuildModel *buildModel;       /* 0x04 */
    struct FieldWfbc *wfbc;                   /* 0x08 */
    int slotIndex;                            /* 0x0C */
    unsigned short heapId;                    /* 0x10 */
    unsigned short pad12;                     /* 0x12 */
} FieldG3dMapperSlotRes;

/* One block slot (0x28 bytes). */
typedef struct FieldG3dMapperSlot {
    FieldG3dMap *map;                     /* 0x00 */
    FieldG3dMapperSlotRes res;            /* 0x04 */
    FieldG3dMapperCell cell;              /* 0x18, cell this slot currently shows */
} FieldG3dMapperSlot;

/* Setup parameters, copied from the per map type table (same words as FieldMapMapperParam). */
typedef struct FieldG3dMapperSetup {
    int cellSize;                         /* 0x00, fx32 */
    int layerHeight;                      /* 0x04, fx32 */
    unsigned short cols;                  /* 0x08, window columns */
    unsigned short rows;                  /* 0x0A, window rows */
    unsigned int layout;                  /* 0x0C, FIELD_G3D_MAPPER_LAYOUT_* */
    int mapArchiveId;                     /* 0x10 */
    unsigned short gridWidth;             /* 0x14 */
    unsigned short gridDepth;             /* 0x16 */
    unsigned int blockCount;              /* 0x18 */
    FieldG3dMapperGridEntry *blockGrid;   /* 0x1C, gridWidth x gridDepth entries per layer, 0 when not set */
    unsigned int textureMode;             /* 0x20, 1: load the shared texture set */
    unsigned int textureIds[2];           /* 0x24, archive id and texture set id */
    int groundAnimeIds[2];                /* 0x2C, -1 when absent */
    int blockBufferSize;                  /* 0x34 */
    unsigned char drawReserve;            /* 0x38 */
    unsigned char pad39[3];               /* 0x39 */
} FieldG3dMapperSetup;

/*
 * Result list of the mapper queries. Same entries as FieldG3dMapHitList, but
 * the count is a halfword at 0x100.
 */
typedef struct FieldG3dMapperHitList {
    FieldG3dMapHit hits[16];              /* 0x00 */
    unsigned short count;                 /* 0x100 */
} FieldG3dMapperHitList;

/* Default hit header (kind, index, flags) of the height boxes. */
typedef struct FieldG3dMapperHitHead {
    unsigned short kind;
    unsigned short index;
    unsigned short flags;
} FieldG3dMapperHitHead;

/* Parameter block of FIELD_GROUND_ANIME_Create, written by FIELD_G3D_MAPPER_CreateGroundAnime. */
typedef struct FieldG3dMapperGroundAnimeParam {
    unsigned short useFlags;              /* 0x00, low byte: first id set, high byte: second id set */
    unsigned short slotCount;             /* 0x02 */
    unsigned short pad04;                 /* 0x04 */
    unsigned short firstId;               /* 0x06 */
    unsigned short pad08;                 /* 0x08 */
    unsigned short secondId;              /* 0x0A */
} FieldG3dMapperGroundAnimeParam;

/* The mapper work (0x74 bytes). */
typedef struct FieldG3dMapper {
    unsigned short heapId;                /* 0x00 */
    unsigned short pad02;                 /* 0x02 */
    int cellSize;                         /* 0x04, fx32 */
    int layerHeight;                      /* 0x08, fx32 */
    unsigned int layout;                  /* 0x0C, FIELD_G3D_MAPPER_LAYOUT_* */
    int mapArchiveId;                     /* 0x10 */
    unsigned short gridWidth;             /* 0x14 */
    unsigned short gridDepth;             /* 0x16 */
    unsigned int blockCount;              /* 0x18 */
    FieldG3dMapperGridEntry *blockGrid;   /* 0x1C, 0 when no grid is set */
    unsigned int textureMode;             /* 0x20 */
    FieldG3dMapperSlot *slots;            /* 0x24, slotCount entries */
    FieldG3dMapperCell *cells;            /* 0x28, slotCount entries */
    unsigned char cols;                   /* 0x2C */
    unsigned char rows;                   /* 0x2D */
    unsigned short slotCount;             /* 0x2E, cols * rows */
    unsigned int focusCell;               /* 0x30, grid cell of the focus position */
    VecFx32 focusPos;                     /* 0x34 */
    unsigned char drawReserve;            /* 0x40 */
    unsigned char sortedCount;            /* 0x41, entries of drawOrder in use */
    unsigned char lastDrawnCount;         /* 0x42 */
    unsigned char drawnCount;             /* 0x43 */
    unsigned char *drawOrder;             /* 0x44, slot indices, 0xFF unused */
    int drawBudget;                       /* 0x48 */
    unsigned char fitCount;               /* 0x4C */
    unsigned char scanline;               /* 0x4D */
    unsigned char pad4E[2];               /* 0x4E */
    unsigned int frameStamp;              /* 0x50 */
    VecFx32 originOffset;                 /* 0x54 */
    G3dResource *textureRes;              /* 0x60, shared texture set or 0 */
    struct FieldBuildModel *buildModel;   /* 0x64 */
    struct FieldGroundAnime *groundAnime; /* 0x68 */
    struct FieldWfbc *wfbc;               /* 0x6C */
    struct HeightEx *heightEx;            /* 0x70 */
} FieldG3dMapper;

#endif
