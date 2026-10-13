/*
 * file:     map_matrix.c
 * unit:     yes
 * function: func_02159B48, func_02159B94, func_02159BBC, func_02159BC4, func_02159BD4, func_02159BF4, func_02159BF8, func_02159BFC, func_02159C00, func_02159C20, func_02159C2C, func_02159C48, func_02159C68, func_02159CC4, func_02159D04, func_02159D68
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
 *   func_02048F60  0x02048F60  arm
 *   func_02159D04  0x02159D04  thumb  ov010
 *   func_020307B0  0x020307B0  arm
 *   func_02159D68  0x02159D68  thumb  ov010
 *   func_02159C2C  0x02159C2C  thumb  ov010
 *   func_02159B94  0x02159B94  thumb  ov010
 *   func_02082A48  0x02082A48  arm
 *   func_02082A90  0x02082A90  arm
 *   func_02159CC4  0x02159CC4  thumb  ov010
 *   func_02159D84  0x02159D84  thumb  ov010
 *   func_02159DC8  0x02159DC8  thumb  ov010
 *   func_02159DCC  0x02159DCC  thumb  ov010
 *   func_02159DEC  0x02159DEC  thumb  ov010
 *   func_02159E00  0x02159E00  thumb  ov010
 */
typedef unsigned char u8;

typedef unsigned int u32;

typedef unsigned short u16;

/*
 * Runtime map matrix (0x152C bytes, a/0/0/9 sub-file decoded by
 * func_02159D04).  zoneGrid holds one zone id per block, mapGrid one
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
extern void *func_02048F60(u32 archive_id, u32 member, u32 heap);
void func_02159D04(struct MapMatrix *matrix, const struct MatrixFile *file, u32 matrixId, u16 zoneId);
extern u32 func_020307B0(void *p);
extern int func_02159D68(int pos);
u16 func_02159BC4(const struct MapMatrix *matrix, u32 x, u32 z);
int func_02159B94(struct MapMatrix *matrix, int matrixId, u16 zoneId, int heapId);
int func_02159C2C(const struct MapMatrix *matrix, int x, int z);
extern void func_02082A48(u32 value, void *dst, u32 size);
extern void func_02082A90(const void *src, void *dst, u32 size);
struct MapReplace *func_02159D84(int heapId, int gameSystem);
u32 func_02159DC8(struct MapReplace *replace);
u32 func_02159DCC(struct MapReplace *replace, int index);
int func_02159DEC(struct MapReplace *replace);
int func_02159E00(struct MapReplace *replace, u32 *oldId, u32 *newId);
void func_02159C68(struct MapMatrix *matrix, struct MapReplace *replace, int heapId);
extern const char d_021728AC[];


struct MapMatrix *func_02159B48(int heapId)
{
    struct MapMatrix *matrix = func_02030734(heapId, sizeof(struct MapMatrix), 1, d_021728AC, 0x4b);
    matrix->heapId = heapId;
    func_02082A7C(-1, matrix->mapGrid, sizeof(matrix->mapGrid));
    func_02082A7C(0xffff, matrix->zoneGrid, sizeof(matrix->zoneGrid));
    return matrix;
}



int func_02159B94(struct MapMatrix *matrix, int matrixId, u16 zoneId, int heapId)
{
    void *file = func_02048F60(9, matrixId, heapId);
    func_02159D04(matrix, file, matrixId, zoneId);
    return func_020307B0(file);
}



/*
 * Thumb tail call into ENV_SetResourceSet (ARM, 0x020307B0): `ldr r3,
 * [pc, #0]; bx r3` plus the pool word, the shape of the arm9 copy
 * VM_Delete.  Unlabelled in the listing (no prologue, called only from
 * arm9), so it is emitted as data words.
 */
void func_02159BBC(struct MapMatrix *matrix)
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
 *   python tools/match.py one --src src/matched/func_02159BC4.c \
 *       --func func_02159BC4 --addr 0x02159BC4 --region ov010 --cc 1.1p1 --thumb
 */
u16 func_02159BC4(const struct MapMatrix *matrix, u32 x, u32 z)
{
    return matrix->zoneGrid[x + z * matrix->width];
}


/* Zone id at a world position: both coordinates go through the block conversion. */
int func_02159BD4(const struct MapMatrix *matrix, int posX, int posZ)
{
    int blockX = func_02159D68(posX);
    int blockZ = func_02159D68(posZ);
    return func_02159BC4(matrix, blockX, blockZ);
}



/*
 * Unlabelled leaf accessor (prints as .word): returns the width.
 * Sole blocker of ov021 func_02189B30's MATCH.
 */
unsigned short func_02159BF4(const struct MapMatrix *matrix)
{
    return matrix->width;
}



/*
 * Unlabelled leaf accessor (prints as .word): returns the height.
 * Sole blocker of ov021 func_02189B30's MATCH.
 */
unsigned short func_02159BF8(const struct MapMatrix *matrix)
{
    return matrix->height;
}



/*
 * Unlabelled leaf accessor (prints as .word): returns the block count.
 * Sole blocker of ov021 func_02189B30's MATCH.
 */
int func_02159BFC(const struct MapMatrix *matrix)
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
 *   python tools/match.py one --src src/matched/sub_02159C00.c \
 *       --func sub_02159C00 --addr 0x02159C00 --region ov010 --cc 1.1p1 --thumb
 */
void sub_02159C00(struct MapMatrix *matrix, u32 width, u32 height)
{
    u32 count = width * height;

    if (width <= 30 && height <= 30 && count <= 900) {
        matrix->width = (u16)width;
        matrix->height = (u16)height;
        matrix->count = count;
    }
}


u32 *func_02159C20(struct MapMatrix *matrix)
{
    return matrix->mapGrid;
}





int func_02159C2C(const struct MapMatrix *matrix, int x, int z)
{
    if (z >= 0 && z < matrix->height && x >= 0 && x < matrix->width)
        return 1;
    return 0;
}








int func_02159C48(const struct MapMatrix *matrix, int posX, int posZ)
{
    int blockX = func_02159D68(posX);
    int blockZ = func_02159D68(posZ);
    return func_02159C2C(matrix, blockX, blockZ);
}








/*
 * Apply the loaded replace record: kind 2 reloads the whole matrix from
 * the new matrix id, kind 1 swaps every map index equal to the old id.
 */
void func_02159C68(struct MapMatrix *matrix, struct MapReplace *replace, int heapId)
{
    u32 oldId;
    u32 newId;
    int kind = func_02159E00(replace, &oldId, &newId);
    switch (kind) {
    case 0:
        break;
    case 2:
        func_02159B94(matrix, (u16)newId, matrix->zoneId, heapId);
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








void func_02159CC4(struct MapMatrix *matrix, int gameSystem, int heapId)
{
    struct MapReplace *replace = func_02159D84(heapId, gameSystem);
    int recordCount = func_02159DC8(replace);
    int i;
    for (i = 0; i < recordCount; i++) {
        u32 recordMatrixId = func_02159DCC(replace, i);
        if (recordMatrixId == matrix->matrixId)
            func_02159C68(matrix, replace, heapId);
    }
    func_02159DEC(replace);
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
void func_02159D04(struct MapMatrix *matrix, const struct MatrixFile *file,
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
    func_02082A90(cells, matrix->mapGrid, count * 4);

    zoneGrid = matrix->zoneGrid;
    if (matrix->mode == 1) {
        zoneCells = cells + matrix->count;
        for (i = 0; i < matrix->count; i++)
            zoneGrid[i] = (u16)zoneCells[i];
    } else {
        func_02082A48(zoneId, zoneGrid, sizeof(matrix->zoneGrid));
    }
}


/*
 * World position (fx32) to matrix block index: one block is 32 grids of 16
 * units each.
 *
 * extent: two bytes of zero alignment padding at 0x02159D82.
 */
int func_02159D68(int pos)
{
    return pos / 4096 / 16 / 32;
}
