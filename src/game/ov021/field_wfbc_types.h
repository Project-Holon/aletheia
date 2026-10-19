#ifndef OV021_FIELD_WFBC_TYPES_H
#define OV021_FIELD_WFBC_TYPES_H

/* Needs u8, u16, u32 and u64. */
#include "../ov020/field_wfbc_data_local_types.h"

struct ArcHandle;
struct MmdlSys;
struct WfbcNpcData;

/* Cell of the 8x8 block grid: offset from the block's origin cell, block type (0xFF: none). */
typedef struct FieldWfbcBlockPos {
    u8 offsetX : 4;
    u8 offsetZ : 4;
    u8 type;
} FieldWfbcBlockPos;

/* Placed block cell (4 bytes). */
typedef struct FieldWfbcBlock {
    FieldWfbcBlockPos pos;
    u16 blockId;
} FieldWfbcBlock;

/* Block layout loaded from the WFBC archive (0x600 bytes): grid and the block ids per type. */
typedef struct FieldWfbcBlockTable {
    FieldWfbcBlockPos layout[8][8];
    u32 blockIds[22][16];
} FieldWfbcBlockTable;

/* Connect (door) that only exists while its block is placed (8 bytes). */
typedef struct FieldWfbcConnectEntry {
    u16 blockType;
    u16 blockId;
    u32 connectIndex;
} FieldWfbcConnectEntry;

#include "../sdk_math.h"

/* Random source that picks the block variants (0x24 bytes). */
typedef struct FieldWfbcBlockRand {
    MATHRandContext32 rand;
    u16 randRange;   /* 1 with no people, else the summed record values + 2 */
    u16 npcIdSum;
    int peopleNum;
    u32 seed;        /* player id of the town owner */
} FieldWfbcBlockRand;

/* One resident on the map (0x50 bytes). */
typedef struct FieldWfbcPeople {
    u16 isActive;
    u8 pad02[2];
    WfbcNpcRecord npcRecord;
    WfbcPerson person;
    u16 gridX;
    u16 gridZ;
} FieldWfbcPeople;

/* White Forest / Black City runtime of the field map (0x144 bytes). */
typedef struct FieldWfbc {
    u8 cityType;
    u8 isBackPeople;   /* the people come from the back list; nothing is written back */
    u8 pad02[2];
    FieldWfbcPeople *people;   /* 10 entries */
    WfbcData *saveData;
    struct WfbcNpcData *npcData;
    struct ArcHandle *arcHandle;
    FieldWfbcBlockTable *blockTable;
    FieldWfbcBlock blocks[8][8];
    u8 *mmdlPosTable;
    FieldWfbcBlockRand blockRand;
    struct MmdlSys *mmdlSys;
} FieldWfbc;

#endif
