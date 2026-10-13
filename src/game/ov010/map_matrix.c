/*
 * file:     map_matrix.c
 * unit:     yes
 * function: MAP_MATRIX_Create, MAP_MATRIX_Load, MAP_MATRIX_Delete, MAP_MATRIX_GetZoneId, MAP_MATRIX_GetZoneIdByPos, MAP_MATRIX_GetWidth, MAP_MATRIX_GetHeight, MAP_MATRIX_GetCount, func_02159C00, MAP_MATRIX_GetMapGrid, MAP_MATRIX_IsInRange, MAP_MATRIX_IsInRangeByPos, MAP_MATRIX_ApplyReplaceRecord, MAP_MATRIX_ApplyReplace, MAP_MATRIX_SetupFromFile, MAP_MATRIX_PosToBlock
 * address:  0x02159B48
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02030734  0x02030734  arm
 *   func_02082A7C  0x02082A7C  arm
 *   d_021728AC  0x021728AC  data
 *   ARC_TOOL_LoadMember  0x02048F60  arm
 *   MAP_MATRIX_SetupFromFile  0x02159D04  thumb  ov010
 *   func_020307B0  0x020307B0  arm
 *   MAP_MATRIX_PosToBlock  0x02159D68  thumb  ov010
 *   MAP_MATRIX_IsInRange  0x02159C2C  thumb  ov010
 *   MAP_MATRIX_Load  0x02159B94  thumb  ov010
 *   MIi_CpuClear16  0x02082A48  arm
 *   MIi_CpuCopy32  0x02082A90  arm
 *   MAP_MATRIX_ApplyReplace  0x02159CC4  thumb  ov010
 *   MAP_REPLACE_Create  0x02159D84  thumb  ov010
 *   MAP_REPLACE_GetRecordCount  0x02159DC8  thumb  ov010
 *   MAP_REPLACE_LoadRecord  0x02159DCC  thumb  ov010
 *   MAP_REPLACE_Delete  0x02159DEC  thumb  ov010
 *   MAP_REPLACE_CheckRecord  0x02159E00  thumb  ov010
 */
typedef unsigned char u8;

typedef unsigned int u32;

typedef unsigned short u16;

/*
 * Runtime map matrix (0x152C bytes, a/0/0/9 sub-file decoded by
 * MAP_MATRIX_SetupFromFile).  zoneGrid holds one zone id per block, mapGrid one
 * a/0/0/8 map-model index per block; both are row-major over width.
 */
struct MapMatrix {
    u16 heapId;
    u16 zoneId;
    u32 matrixId;
    u16 width;
    u16 height;
    u16 mode;               /* 1: the file carries its own zone grid */
    u16 pad0E;
    u32 count;              /* width * height, at most 900 */
    u16 zoneGrid[900];
    u32 mapGrid[900];
};

/* a/0/0/9 sub-file: header, count map indices, then count zone ids if mode == 1. */
struct MatrixFile {
    u16 mode;
    u16 pad02;
    u16 width;
    u16 height;
    u32 cells[];
};

struct MapReplace;

extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void func_02082A7C(int, void *, int);
extern void *ARC_TOOL_LoadMember(u32 archive_id, u32 member, u32 heap);
void MAP_MATRIX_SetupFromFile(struct MapMatrix *matrix, const struct MatrixFile *file, u32 matrixId, u16 zoneId);
extern u32 func_020307B0(void *p);
extern int MAP_MATRIX_PosToBlock(int pos);
u16 MAP_MATRIX_GetZoneId(const struct MapMatrix *matrix, u32 x, u32 z);
int MAP_MATRIX_Load(struct MapMatrix *matrix, int matrixId, u16 zoneId, int heapId);
int MAP_MATRIX_IsInRange(const struct MapMatrix *matrix, int x, int z);
extern void MIi_CpuClear16(u32 value, void *dst, u32 size);
extern void MIi_CpuCopy32(const void *src, void *dst, u32 size);
struct MapReplace *MAP_REPLACE_Create(int heapId, int gameSystem);
u32 MAP_REPLACE_GetRecordCount(struct MapReplace *replace);
u32 MAP_REPLACE_LoadRecord(struct MapReplace *replace, int index);
int MAP_REPLACE_Delete(struct MapReplace *replace);
int MAP_REPLACE_CheckRecord(struct MapReplace *replace, u32 *oldId, u32 *newId);
void MAP_MATRIX_ApplyReplaceRecord(struct MapMatrix *matrix, struct MapReplace *replace, int heapId);
extern const char d_021728AC[];


struct MapMatrix *MAP_MATRIX_Create(int heapId)
{
    struct MapMatrix *matrix = func_02030734(heapId, sizeof(struct MapMatrix), 1, d_021728AC, 0x4b);
    matrix->heapId = heapId;
    func_02082A7C(-1, matrix->mapGrid, sizeof(matrix->mapGrid));
    func_02082A7C(0xffff, matrix->zoneGrid, sizeof(matrix->zoneGrid));
    return matrix;
}



int MAP_MATRIX_Load(struct MapMatrix *matrix, int matrixId, u16 zoneId, int heapId)
{
    void *file = ARC_TOOL_LoadMember(9, matrixId, heapId);
    MAP_MATRIX_SetupFromFile(matrix, file, matrixId, zoneId);
    return func_020307B0(file);
}



/*
 * Thumb tail call into ENV_SetResourceSet (ARM, 0x020307B0): `ldr r3,
 * [pc, #0]; bx r3` plus the pool word, the shape of the arm9 copy
 * VM_Delete.  Unlabelled in the listing (no prologue, called only from
 * arm9), so it is emitted as data words.
 */
void MAP_MATRIX_Delete(struct MapMatrix *matrix)
{
    func_020307B0(matrix);
}



/*
 * Read one cell of the matrix zone grid, row-major over the matrix width.
 * Leaf, no relocations.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/MAP_MATRIX_GetZoneId.c \
 *       --func MAP_MATRIX_GetZoneId --addr 0x02159BC4 --region ov010 --cc 1.1p1 --thumb
 */
u16 MAP_MATRIX_GetZoneId(const struct MapMatrix *matrix, u32 x, u32 z)
{
    return matrix->zoneGrid[x + z * matrix->width];
}


/* Zone id at a world position: both coordinates go through the block conversion. */
int MAP_MATRIX_GetZoneIdByPos(const struct MapMatrix *matrix, int posX, int posZ)
{
    int blockX = MAP_MATRIX_PosToBlock(posX);
    int blockZ = MAP_MATRIX_PosToBlock(posZ);
    return MAP_MATRIX_GetZoneId(matrix, blockX, blockZ);
}



/*
 * Unlabelled leaf accessor (prints as .word): returns the width.
 * Sole blocker of ov021 FIELDMAP_SetupMapperParam's MATCH.
 */
unsigned short MAP_MATRIX_GetWidth(const struct MapMatrix *matrix)
{
    return matrix->width;
}



/*
 * Unlabelled leaf accessor (prints as .word): returns the height.
 * Sole blocker of ov021 FIELDMAP_SetupMapperParam's MATCH.
 */
unsigned short MAP_MATRIX_GetHeight(const struct MapMatrix *matrix)
{
    return matrix->height;
}



/*
 * Unlabelled leaf accessor (prints as .word): returns the block count.
 * Sole blocker of ov021 FIELDMAP_SetupMapperParam's MATCH.
 */
int MAP_MATRIX_GetCount(const struct MapMatrix *matrix)
{
    return matrix->count;
}



/*
 * Set the matrix dimensions, refusing anything that would not fit the two
 * fixed 900-entry grids: width and height are each capped at 30 and their
 * product at 900.  That is what pins the layout, since 0x14 + 900 * 2 is
 * exactly the 0x71C where mapGrid starts.
 *
 * The product is computed before the guards rather than after, so all three
 * checks share one exit and the whole body is a single conjunction
 * (docs/idioms/guard-chain-sharing-one-exit-block-is-a-single-conjunction.md).
 *
 * Another leaf with no lr save, so disasm.py left it unlabelled.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/MAP_MATRIX_SetSize.c \
 *       --func MAP_MATRIX_SetSize --addr 0x02159C00 --region ov010 --cc 1.1p1 --thumb
 */
void MAP_MATRIX_SetSize(struct MapMatrix *matrix, u32 width, u32 height)
{
    u32 count = width * height;

    if (width <= 30 && height <= 30 && count <= 900) {
        matrix->width = (u16)width;
        matrix->height = (u16)height;
        matrix->count = count;
    }
}


u32 *MAP_MATRIX_GetMapGrid(struct MapMatrix *matrix)
{
    return matrix->mapGrid;
}





int MAP_MATRIX_IsInRange(const struct MapMatrix *matrix, int x, int z)
{
    if (z >= 0 && z < matrix->height && x >= 0 && x < matrix->width)
        return 1;
    return 0;
}








int MAP_MATRIX_IsInRangeByPos(const struct MapMatrix *matrix, int posX, int posZ)
{
    int blockX = MAP_MATRIX_PosToBlock(posX);
    int blockZ = MAP_MATRIX_PosToBlock(posZ);
    return MAP_MATRIX_IsInRange(matrix, blockX, blockZ);
}








/*
 * Apply the loaded replace record: kind 2 reloads the whole matrix from
 * the new matrix id, kind 1 swaps every map index equal to the old id.
 */
void MAP_MATRIX_ApplyReplaceRecord(struct MapMatrix *matrix, struct MapReplace *replace, int heapId)
{
    u32 oldId;
    u32 newId;
    int kind = MAP_REPLACE_CheckRecord(replace, &oldId, &newId);
    switch (kind) {
    case 0:
        break;
    case 2:
        MAP_MATRIX_Load(matrix, (u16)newId, matrix->zoneId, heapId);
        return;
    case 1: {
        u32 i;
        for (i = 0; i < matrix->count; i++) {
            if (oldId == matrix->mapGrid[i])
                matrix->mapGrid[i] = newId;
        }
        break;
    }
    }
}








void MAP_MATRIX_ApplyReplace(struct MapMatrix *matrix, int gameSystem, int heapId)
{
    struct MapReplace *replace = MAP_REPLACE_Create(heapId, gameSystem);
    int recordCount = MAP_REPLACE_GetRecordCount(replace);
    int i;
    for (i = 0; i < recordCount; i++) {
        u32 recordMatrixId = MAP_REPLACE_LoadRecord(replace, i);
        if (recordMatrixId == matrix->matrixId)
            MAP_MATRIX_ApplyReplaceRecord(matrix, replace, heapId);
    }
    MAP_REPLACE_Delete(replace);
}








/*
 * The map-matrix decoder: unpack one a/0/0/9 sub-file into the runtime matrix.
 * Block one is copied into mapGrid.  Block two (mode == 1) is narrowed into
 * zoneGrid; without it zoneGrid is filled with the caller's zone id.
 *
 * final push 2026-10-05 G4L1: closed by storing zoneId first (before the
 * matrixId store).  That gives the parameter the earliest birth, so it takes
 * r7 (the later-born cells and pool take r6 and r4).  EXACT in c99 and c.
 */
void MAP_MATRIX_SetupFromFile(struct MapMatrix *matrix, const struct MatrixFile *file,
                   u32 matrixId, u16 zoneId)
{
    u32 count;
    const u32 *cells;
    const u32 *zoneCells;
    u32 i;
    u16 *zoneGrid;

    matrix->zoneId = zoneId;
    matrix->matrixId = matrixId;
    count = file->width * file->height;
    matrix->height = file->height;
    matrix->count = count;
    matrix->mode = file->mode;
    matrix->width = file->width;
    cells = file->cells;
    MIi_CpuCopy32(cells, matrix->mapGrid, count * 4);

    zoneGrid = matrix->zoneGrid;
    if (matrix->mode == 1) {
        zoneCells = cells + matrix->count;
        for (i = 0; i < matrix->count; i++)
            zoneGrid[i] = (u16)zoneCells[i];
    } else {
        MIi_CpuClear16(zoneId, zoneGrid, sizeof(matrix->zoneGrid));
    }
}


/*
 * World position (fx32) to matrix block index: one block is 32 grids of 16
 * units each.
 *
 * extent: two bytes of zero alignment padding at 0x02159D82.
 */
int MAP_MATRIX_PosToBlock(int pos)
{
    return pos / 4096 / 16 / 32;
}
