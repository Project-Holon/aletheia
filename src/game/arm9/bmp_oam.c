/*
 * file:     bmp_oam.c
 * unit:     yes
 * function: ACTOR_TOOL_Create, ACTOR_TOOL_Delete, ACTOR_TOOL_AllocRun, ACTOR_TOOL_FreeRun, ACTOR_TOOL_LoadChar, ACTOR_TOOL_LoadCharSimple, ACTOR_TOOL_LoadCharPalAnm, ACTOR_TOOL_LoadCharSimplePalAnm, ACTOR_TOOL_GetCharBlock, ACTOR_TOOL_FreeChar, BMP_OAM_CreateSys, BMP_OAM_DeleteSys, BMP_OAM_Create, BMP_OAM_Delete, BMP_OAM_SetEnabled, BMP_OAM_GetEnabled, BMP_OAM_UploadChars, BMP_OAM_GetPos, BMP_OAM_SetPos, BMP_OAM_SetObjMode, BMP_OAM_SetDrawPriority, BMP_OAM_SetBgPriority, BMP_OAM_SetPalette, BMP_OAM_AcquireModeSlot, BMP_OAM_ReleaseModeSlots, func_02025B38, func_02025B3C, func_02025B64, func_02025B94, func_02025BA0, func_02025BB8, func_02025BD0, func_02025BE8, func_02025BEC, func_02025C1C, func_02025C30, func_02025C44
 * address:  0x02025318
 * region:   arm9
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
 *   g_020A7484     0x020A7484  data
 *   func_020307B0  0x020307B0  arm
 *   CLACT_RegisterPaletteEx  0x0204AC18  arm
 *   CLACT_RegisterPaletteCompressed  0x0204ACEC  arm
 *   PALANM_CopyHwPaletteToSlot   0x020216D4  thumb
 *   CLACT_ReleasePalette  0x0204ADA4  arm
 *   func_020490F4  0x020490F4  arm
 *   g_020A7494      0x020A7494  data
 *   ARC_TOOL_DeleteHandle  0x02049238  arm
 *   BMP_GetWidth  0x020437DC  arm
 *   BMP_GetHeight  0x020437E4  arm
 *   CLACT_RegisterEmptyCharacter  0x0204A7A0  arm
 *   CLACT_CreateActor  0x0204B294  arm
 *   CLACT_SetActorPaletteOffset  0x0204B6F4  arm
 *   CLACT_SetActorVisible  0x0204BA20  arm
 *   gModeTable     0x0209F87C  data
 *   CLACT_ReleaseCharacter  0x0204A8D4  arm
 *   CLACT_DeleteActor  0x0204B3B4  arm
 *   CLACT_SetActorDrawEnable  0x0204B3DC  arm
 *   CLACT_GetActorDrawEnable  0x0204B3F4  arm
 *   BMP_GetPixels  0x020437D4  arm
 *   BMP_GetByteSize  0x020437EC  arm
 *   DWCi_ScreenDC_FlushRange  0x020862F0  arm
 *   CLACT_GetCharacterVramAddress  0x0204ABBC  arm
 *   GX_LoadOBJ     0x0207E780  arm
 *   GXS_LoadOBJ    0x0207E804  arm
 *   CLACT_GetActorSurfacePos  0x0204B454  arm
 *   CLACT_AddActorSurfacePos  0x0204B404  arm
 *   CLACT_SetActorObjMode  0x0204B688  arm
 *   CLACT_SetActorDrawPriority  0x0204B800  arm
 *   CLACT_SetActorBgPriority  0x0204B84C  arm
 *   CLACT_RegisterCellAnim  0x0204AF28  arm
 *   CLACT_ReleaseCellAnim  0x0204AFD8  arm
 *   g_0209FA34  0x0209FA34  data
 *   g_0209FA35  0x0209FA35  data
 *   g_0209FA36  0x0209FA36  data
 *   g_0209FA38  0x0209FA38  data
 *   g_0209FA3C  0x0209FA3C  data
 *   g_0209FA3D  0x0209FA3D  data
 *   CLACT_GetPaletteVramAddress  0x0204AEF4  arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed int     s32;

struct Actor;
struct Bmp;

/* Slot allocator for actor character/palette runs: two banks (main and sub
 * engine), 16 slots each; 0xFF marks a free slot, an allocated run is
 * stamped with its start index. */
struct ActorTool {
    u32 pad;
    u8  slotCount[2];
    u8  slot[2][16];
};

/* Initial position and flags handed to the actor creator. */
struct ActorInitParam {
    s16 x;
    s16 y;
    u16 animIndex;
    u8  drawPriority;
    u8  bgPriority;
};

struct OamPos {
    s16 x;
    s16 y;
};

/* Per-screen OAM setup: the actor system, the arc handle and one lazily
 * created resource slot per OBJ mapping mode. */
struct BmpOamSys {
    void *clact;
    u16   heapId;
    u16   pad;
    void *arcTool;
    s32   slot[3];
};

/* One bitmap shown as a rows x cols grid of 32x16 OBJ actors. */
struct BmpOam {
    const struct Bmp *bmp;
    struct Actor     *act[24];
    u32               engine;
    u32               res[24];
    u16               space;
    u8                cols;
    u8                rows;
};

struct BmpOamParam {
    const struct Bmp *bmp;
    s16               x;
    s16               y;
    u32               animResId;
    u32               palette;
    u8                drawPriority;
    u8                bgPriority;
    u16               space;
    u32               engine;
};

struct ModeEntry {
    u32 size;
    u32 resArcId;
    u32 resEntryId;
};

extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern u32 func_020307B0(void *block);
extern s32 CLACT_RegisterPaletteEx(void *src, u32 resId, u32 bank, u32 vramOff, u16 reserved, u16 len, u16 flags);
extern int CLACT_RegisterPaletteCompressed(void *src, u32 resId, u32 bank, u32 vramOff, u16 flags);
extern void PALANM_CopyHwPaletteToSlot(void *palSlots, u32 bank, u32 off, u32 size);
extern void CLACT_ReleasePalette(u32 charOffset);
extern void *func_020490F4(u32 arcId, u32 heapId);
extern void ARC_TOOL_DeleteHandle(void *arcTool);
extern u16 BMP_GetWidth(const struct Bmp *bmp);
extern u16 BMP_GetHeight(const struct Bmp *bmp);
extern s32 CLACT_RegisterEmptyCharacter(u32 size, u32 engine, u16 heapId);
extern struct Actor *CLACT_CreateActor(void *clact, u32 charRes, u32 animResId, s32 resSlot,
                                   const struct ActorInitParam *initParam, u16 space, u16 heapId);
extern void CLACT_SetActorPaletteOffset(struct Actor *actor, u32 palette, u32 flag);
extern void CLACT_SetActorVisible(struct Actor *actor, u32 visible);
extern void CLACT_ReleaseCharacter(u32 charRes);
extern void CLACT_DeleteActor(struct Actor *actor);
extern void CLACT_SetActorDrawEnable(struct Actor *actor, unsigned int enabled);
extern u32 CLACT_GetActorDrawEnable(struct Actor *actor);
extern void *BMP_GetPixels(const struct Bmp *bmp);
extern u32 BMP_GetByteSize(const struct Bmp *bmp);
extern void  DWCi_ScreenDC_FlushRange(void *buf, u32 size);
extern int CLACT_GetCharacterVramAddress(u32 charRes, u32 engine);
extern void  GX_LoadOBJ(void *src, u32 off, u32 n);
extern void  GXS_LoadOBJ(void *src, u32 off, u32 n);
extern int CLACT_GetPaletteVramAddress(int charOffset, int bank);
extern void CLACT_GetActorSurfacePos(struct Actor *actor, struct OamPos *out, u16 space);
extern void CLACT_AddActorSurfacePos(struct Actor *actor, const struct OamPos *pos, u32 space);
extern void CLACT_SetActorObjMode(struct Actor *actor, u32 objMode);
extern void CLACT_SetActorDrawPriority(struct Actor *actor, u32 drawPriority);
extern void CLACT_SetActorBgPriority(struct Actor *actor, u32 bgPriority);
extern s32 CLACT_RegisterCellAnim(void *arcTool, u32 arcId, u32 entryId, u32 heapId);
extern void CLACT_ReleaseCellAnim(u32 resSlot);

struct ActorTool *ACTOR_TOOL_Create(u32 heapId, u8 bank0Count, u8 bank1Count);
void ACTOR_TOOL_Delete(struct ActorTool *tool);
int ACTOR_TOOL_AllocRun(struct ActorTool *tool, int len, u32 bank);
void ACTOR_TOOL_FreeRun(struct ActorTool *tool, u32 start, u32 bank);
s32 ACTOR_TOOL_LoadChar(struct ActorTool *tool, void *src, u32 resId, u32 bank, u32 len, u32 flags);
int ACTOR_TOOL_LoadCharSimple(struct ActorTool *tool, void *src, u32 resId, u32 bank, u32 len, u32 flags);
u32 ACTOR_TOOL_LoadCharPalAnm(void *palSlots, struct ActorTool *tool, void *src, u32 resId, u32 bank, u32 len, u32 flags);
u32 ACTOR_TOOL_LoadCharSimplePalAnm(void *palSlots, struct ActorTool *tool, void *src, u32 resId, u32 bank, u32 len, u32 flags);
unsigned int ACTOR_TOOL_GetCharBlock(int tool, int charOffset, int bank);
void ACTOR_TOOL_FreeChar(struct ActorTool *tool, u32 charOffset, u32 bank);
struct BmpOamSys *BMP_OAM_CreateSys(u32 heapId, void *clact);
void BMP_OAM_DeleteSys(struct BmpOamSys *sys);
struct BmpOam *BMP_OAM_Create(struct BmpOamSys *sys, const struct BmpOamParam *param);
void BMP_OAM_Delete(struct BmpOam *bmpOam);
void BMP_OAM_SetEnabled(struct BmpOam *bmpOam, u32 enabled);
int BMP_OAM_GetEnabled(const struct BmpOam *bmpOam);
void BMP_OAM_UploadChars(struct BmpOam *bmpOam);
void BMP_OAM_GetPos(struct BmpOam *bmpOam, s16 *outX, s16 *outY);
void BMP_OAM_SetPos(struct BmpOam *bmpOam, s16 x, s16 y);
void BMP_OAM_SetObjMode(struct BmpOam *bmpOam, u32 objMode);
void BMP_OAM_SetDrawPriority(struct BmpOam *bmpOam, u32 drawPriority);
void BMP_OAM_SetBgPriority(struct BmpOam *bmpOam, u32 bgPriority);
void BMP_OAM_SetPalette(struct BmpOam *bmpOam, u32 palette);
u32 BMP_OAM_AcquireModeSlot(struct BmpOamSys *sys, u32 engine, void *arcTool);
void BMP_OAM_ReleaseModeSlots(struct BmpOamSys *sys);
int func_02025B38(void);
u32 func_02025B3C(u32 key);
u8 func_02025B64(u32 key);
u32 func_02025B94(u32 key);
u32 func_02025BA0(u32 recIdx);
u32 func_02025BB8(u32 recIdx);
u32 func_02025BD0(u32 recIdx);
int func_02025BE8(void);
u32 func_02025BEC(u32 id, u32 minValue, u32 flag);
u32 sub_02025C1C(u32 id, u32 minValue, u32 flag);
u32 sub_02025C30(u32 id, u32 minValue, u32 flag);
int func_02025C44(u32 key, u32 *outWord, u32 *outByte);

extern char  g_020A7484[];
extern u32   g_020A7494[];
extern const struct ModeEntry gModeTable[];

/* A table of 19 records of 12 bytes at 0x0209FA34. Each field is reached
 * through its own symbol (the original code loads a separate pool word per
 * field; one array plus offsets compiles differently):
 *   +0 key (u8)   +1 u8   +2 id (u16)   +4 u32   +8 u8   +9 u8 */
extern const u8 g_0209FA34[];
extern const u8 g_0209FA35[];
extern const u8 g_0209FA36[];
extern const u8 g_0209FA38[];
extern const u8 g_0209FA3C[];
extern const u8 g_0209FA3D[];

struct ActorTool *ACTOR_TOOL_Create(u32 heapId, u8 bank0Count, u8 bank1Count)
{
    struct ActorTool *tool = func_02030734(heapId, 0x28, 1, g_020A7484, 0x51);
    int bank, slotIdx;

    tool->slotCount[0] = bank0Count;
    tool->slotCount[1] = bank1Count;
    for (bank = 0; bank < 2; bank++) {
        for (slotIdx = 0; slotIdx < 0x10; slotIdx++) {
            tool->slot[bank][slotIdx] = 0xff;
        }
    }
    return tool;
}

void ACTOR_TOOL_Delete(struct ActorTool *tool)
{
    func_020307B0(tool);
}

/*
 * Allocate a run of len free (0xFF) slots in one bank and stamp every slot of
 * the run with its start index; returns the start, or 0.  ACTOR_TOOL_FreeRun
 * frees what this stamps.
 *
 * The scan loop's bound is written `j < i + len` in the loop condition, and
 * `end = i + len` is computed only after the scan, for the fill.  With `end`
 * assigned before the scan and used as its bound, the registers rotate
 * differently from the image.
 */
int ACTOR_TOOL_AllocRun(struct ActorTool *tool, int len, u32 bank)
{
    int start, slotIdx, end;
    u32 bankSel = 1;
    u8 *bankSlots;

    if (bank == 0)
        bankSel = 0;
    start = 0;
    if (start < tool->slotCount[bankSel]) {
        do {
            if (tool->slot[bankSel][start] == 0xff) {
                for (slotIdx = start; slotIdx < start + len; slotIdx++) {
                    if (tool->slot[bankSel][slotIdx] != 0xff) {
                        start = slotIdx;
                        break;
                    }
                }
                end = start + len;
                if (slotIdx == end) {
                    for (slotIdx = start; slotIdx < end; slotIdx++) {
                        bankSlots = (u8 *)tool + (bankSel << 4);
                        bankSlots[slotIdx + 6] = (u8)start;
                    }
                    return start;
                }
            }
            start++;
        } while (start < tool->slotCount[bankSel]);
    }
    return 0;
}

/*
 * Free the run that ACTOR_TOOL_AllocRun stamped with index i in one bank: every
 * slot from i on that still holds i goes back to 0xFF.  The cursor is an int
 * while the index it starts from is the u32 parameter; that keeps the two
 * copies of the cursor in different registers, as in the image.
 */
void ACTOR_TOOL_FreeRun(struct ActorTool *tool, u32 start, u32 bank)
{
    u32 bankSel = 1;
    int slotIdx;

    if (bank == 0)
        bankSel = 0;
    for (slotIdx = start; tool->slot[bankSel][slotIdx] == start; slotIdx++)
        tool->slot[bankSel][slotIdx] = 0xff;
}

s32 ACTOR_TOOL_LoadChar(struct ActorTool *tool, void *src, u32 resId, u32 bank, u32 len, u32 flags)
{
    u32 runStart = ACTOR_TOOL_AllocRun(tool, len, bank);

    return CLACT_RegisterPaletteEx(src, resId, bank, (runStart & 0x7ff) << 5, 0, (u16)len, (u16)flags);
}

int ACTOR_TOOL_LoadCharSimple(struct ActorTool *tool, void *src, u32 resId, u32 bank, u32 len, u32 flags)
{
    u32 runStart = ACTOR_TOOL_AllocRun(tool, len, bank);

    return CLACT_RegisterPaletteCompressed(src, resId, bank, (runStart & 0x7ff) << 5, (u16)flags);
}

/*
 * Create one map tile: a4's flag word picks the 3-versus-2 mode, the tile is
 * built by ACTOR_TOOL_LoadChar over (a1, a2, a3, a4, a5, a6), its width comes back
 * from ACTOR_TOOL_GetCharBlock packed into the low half of a5's shifted word and the
 * tile is handed to PALANM_CopyHwPaletteToSlot with a5 shifted up five.
 */
u32 ACTOR_TOOL_LoadCharPalAnm(void *palSlots, struct ActorTool *tool, void *src, u32 resId, u32 bank, u32 len, u32 flags)
{
    u32 palBankType = 2;
    u32 charOffset;
    u32 charBlock;

    if (bank != 0) {
        palBankType = 3;
    }
    charOffset = ACTOR_TOOL_LoadChar(tool, src, resId, bank, len, flags);
    charBlock = ACTOR_TOOL_GetCharBlock((int)tool, charOffset, bank);
    PALANM_CopyHwPaletteToSlot(palSlots, palBankType, (u16)(charBlock << 4), len << 5);
    return charOffset;
}

/*
 * The wide-tile twin of ACTOR_TOOL_LoadCharPalAnm: identical body, but the tile builder
 * is ACTOR_TOOL_LoadCharSimple rather than ACTOR_TOOL_LoadChar.
 */
u32 ACTOR_TOOL_LoadCharSimplePalAnm(void *palSlots, struct ActorTool *tool, void *src, u32 resId, u32 bank, u32 len, u32 flags)
{
    u32 palBankType = 2;
    u32 charOffset;
    u32 charBlock;

    if (bank != 0) {
        palBankType = 3;
    }
    charOffset = ACTOR_TOOL_LoadCharSimple(tool, src, resId, bank, len, flags);
    charBlock = ACTOR_TOOL_GetCharBlock((int)tool, charOffset, bank);
    PALANM_CopyHwPaletteToSlot(palSlots, palBankType, (u16)(charBlock << 4), len << 5);
    return charOffset;
}

/* The first argument is not used by the body. */
unsigned int ACTOR_TOOL_GetCharBlock(int tool, int charOffset, int bank)
{
    int rawBlock = CLACT_GetPaletteVramAddress(charOffset, bank);

    return (unsigned int)rawBlock >> 5;
}

void ACTOR_TOOL_FreeChar(struct ActorTool *tool, u32 charOffset, u32 bank)
{
    u32 charBlock = ACTOR_TOOL_GetCharBlock((int)tool, charOffset, bank);

    ACTOR_TOOL_FreeRun(tool, charBlock, bank);
    CLACT_ReleasePalette(charOffset);
}

/*
 * Allocate the 0x18-byte setup object (tag 0x73), record the heap id and the
 * actor system, seed the three mode slots with -1 and allocate the arc
 * handle through func_020490F4 with the heap field forced to a 0x8000-based
 * value.
 */
struct BmpOamSys *BMP_OAM_CreateSys(u32 heapId, void *clact)
{
    struct BmpOamSys *sys;
    int modeIdx;

    sys = func_02030734(heapId, 0x18, 1, (const char *)g_020A7494, 0x73);
    sys->heapId = heapId;
    sys->clact = clact;
    for (modeIdx = 0; modeIdx < 3; modeIdx++) {
        sys->slot[modeIdx] = -1;
    }
    sys->arcTool = func_020490F4(0x33, (u16)((heapId & 0x7fff) | 0x8000));
    return sys;
}

void BMP_OAM_DeleteSys(struct BmpOamSys *sys)
{
    ARC_TOOL_DeleteHandle(sys->arcTool);
    BMP_OAM_ReleaseModeSlots(sys);
    func_020307B0(sys);
}

/*
 * Build a grid of OAM actors over a bitmap, one 32x16 cell per actor, each
 * with its own character resource allocated by mode.
 *
 * `param` must be a `const struct BmpOamParam *`: with const, the stores into
 * pt and the grid no longer order the param field loads, which gives the
 * image's instruction order.
 */
struct BmpOam *BMP_OAM_Create(struct BmpOamSys *sys, const struct BmpOamParam *param)
{
    struct ActorInitParam actorParam;
    u32 mapMode;
    struct BmpOam *bmpOam;
    u8 rows;
    u8 rowIdx;
    u8 colIdx;
    u32 arcTool;
    u8 cols;
    u8 *cellRow;
    struct BmpOam *cell;
    u32 yOffset;
    u32 animResId;

    {
        u16 *zero = (u16 *)&actorParam;
        zero[0] = 0;
        zero[1] = 0;
        zero[2] = 0;
        zero[3] = 0;
    }

    bmpOam = func_02030734(sys->heapId, 0xcc, 1, (const char *)g_020A7494, 0xa3);
    bmpOam->bmp = param->bmp;
    cols = (u8)(BMP_GetWidth(bmpOam->bmp) >> 5);
    rows = (u8)(BMP_GetHeight(param->bmp) >> 4);
    if ((s32)BMP_GetWidth(param->bmp) % 32 != 0) {
        cols = (u8)(cols + 1);
    }
    if ((s32)BMP_GetHeight(param->bmp) % 16 != 0) {
        rows = (u8)(rows + 1);
    }
    bmpOam->cols = cols;
    bmpOam->rows = rows;
    bmpOam->space = param->space;
    bmpOam->engine = param->engine;

    arcTool = (u32)sys->arcTool;
    for (rowIdx = 0; rowIdx < rows; rowIdx++) {
        for (colIdx = 0; colIdx < cols; colIdx++) {
            cellRow = (u8 *)bmpOam + rowIdx * cols * 4;
            yOffset = rowIdx << 4;
            mapMode = BMP_OAM_AcquireModeSlot(sys, param->engine, (void *)arcTool);
            cell = (struct BmpOam *)(cellRow + colIdx * 4);
            cell->res[0] = CLACT_RegisterEmptyCharacter(gModeTable[mapMode].size, param->engine, sys->heapId);
            actorParam.x = (s16)(param->x + (colIdx << 5));
            actorParam.y = (s16)(param->y + yOffset);
            animResId = param->animResId;
            actorParam.drawPriority = param->drawPriority;
            actorParam.bgPriority = param->bgPriority;
            {
                struct Actor *actor = CLACT_CreateActor(sys->clact, cell->res[0], animResId, sys->slot[mapMode], &actorParam,
                                                  param->space, sys->heapId);
                u32 palette = (u8)param->palette;
                cell->act[0] = actor;
                CLACT_SetActorPaletteOffset(actor, palette, 0);
            }
            CLACT_SetActorVisible(cell->act[0], 0);
        }
    }
    return bmpOam;
}

/*
 * Tear down the grid: for every cell of the rows x cols grid, release the
 * cell's resource and actor, then free the object itself.
 */
void BMP_OAM_Delete(struct BmpOam *bmpOam)
{
    u8 rowIdx, colIdx;

    for (rowIdx = 0; rowIdx < bmpOam->rows; rowIdx++) {
        for (colIdx = 0; colIdx < bmpOam->cols; colIdx++) {
            CLACT_ReleaseCharacter(bmpOam->res[colIdx + rowIdx * bmpOam->cols]);
            CLACT_DeleteActor(bmpOam->act[colIdx + rowIdx * bmpOam->cols]);
        }
    }
    func_020307B0(bmpOam);
}

void BMP_OAM_SetEnabled(struct BmpOam *bmpOam, u32 enabled)
{
    u8 rowIdx;
    u8 colIdx;

    for (rowIdx = 0; rowIdx < bmpOam->rows; rowIdx++) {
        for (colIdx = 0; colIdx < bmpOam->cols; colIdx++) {
            CLACT_SetActorDrawEnable(bmpOam->act[rowIdx * bmpOam->cols + colIdx], enabled);
        }
    }
}

/* Forwards the state of the first actor. */
int BMP_OAM_GetEnabled(const struct BmpOam *bmpOam)
{
    return CLACT_GetActorDrawEnable(bmpOam->act[0]);
}

/*
 * Upload a tiled bitmap to OBJ VRAM one cell row at a time.  The engine
 * selector picks GX_LoadOBJ or GXS_LoadOBJ once, up front, and the chosen
 * function pointer is spilled to [sp] and reached through blx r3 for every
 * one of the (rows x cols) transfers.
 *
 * The 0x80-or-remainder width is the tell: a full cell row is 0x80 bytes,
 * and only the last column of the last row uploads the partial remainder
 * ((w % 32) / 8) * 32, which falls back to a whole 0x80 when it lands on
 * zero.  The signed shift quartet around the remainder is what says the
 * width helper hands back a signed int, not the u16 its other callers use.
 */
void BMP_OAM_UploadChars(struct BmpOam *bmpOam)
{
    void (*loadObj)(void *, u32, u32);
    u8 *pixels;
    s32 tileCols;
    s32 tileRows;
    s32 col;
    u32 dstAddr;
    s32 row;
    u32 srcOff;
    u32 lastColBytes;
    u32 oddRows;
    u32 bytes;
    u32 nextRowOff;
    void *charAddr;

    pixels = (u8 *)BMP_GetPixels(bmpOam->bmp);
    DWCi_ScreenDC_FlushRange(pixels, BMP_GetByteSize(bmpOam->bmp));
    if (bmpOam->engine == 0) {
        loadObj = GX_LoadOBJ;
    } else {
        loadObj = GXS_LoadOBJ;
    }
    tileCols = (s32)((u32)BMP_GetWidth(bmpOam->bmp) >> 3);
    tileRows = (s32)((u32)BMP_GetHeight(bmpOam->bmp) >> 3);
    lastColBytes = (u32)((((s32)(u32)BMP_GetWidth(bmpOam->bmp) % 32) / 8) * 32);
    if (lastColBytes == 0) {
        lastColBytes = 0x80;
    }
    srcOff = 0;
    row = 0;
    nextRowOff = tileCols << 5;
    row = 0;
    {
        s32 rowCount = bmpOam->rows;
        if (rowCount <= 0) {
            return;
        }
    }
    oddRows = tileRows & 1;
    do {
        for (col = 0; col < bmpOam->cols; col++) {
            if (col == bmpOam->cols - 1) {
                bytes = lastColBytes;
            } else {
                bytes = 0x80;
            }
            charAddr = (void *)CLACT_GetCharacterVramAddress(bmpOam->res[col + row * bmpOam->cols], bmpOam->engine);
            dstAddr = (u32)charAddr;
            loadObj(pixels + srcOff, dstAddr, bytes);
            if (row == bmpOam->rows - 1 && oddRows != 0) {
            } else {
                dstAddr += 0x80;
                loadObj(pixels + nextRowOff, dstAddr, bytes);
            }
            srcOff += bytes;
            nextRowOff += bytes;
        }
        srcOff += tileCols << 5;
        nextRowOff += tileCols << 5;
        row++;
    } while (row < bmpOam->rows);
}

void BMP_OAM_GetPos(struct BmpOam *bmpOam, s16 *outX, s16 *outY)
{
    struct OamPos pos;

    CLACT_GetActorSurfacePos(bmpOam->act[0], &pos, bmpOam->space);
    *outX = pos.x;
    *outY = pos.y;
}

/*
 * Repositions every cell of the rows x cols grid: each cell gets the base
 * position offset by its column (x, step 32) and its row (y, step 16).  The
 * x/y parameters are s16, not int: only the narrow parameter type puts the
 * two spills ahead of the object copy in the prologue.
 */
void BMP_OAM_SetPos(struct BmpOam *bmpOam, s16 x, s16 y)
{
    struct OamPos pos;
    int rowIdx, colIdx;

    for (rowIdx = 0; rowIdx < bmpOam->rows; rowIdx++) {
        for (colIdx = 0; colIdx < bmpOam->cols; colIdx++) {
            pos.x = (s16)(x + (colIdx << 5));
            pos.y = (s16)(y + (rowIdx << 4));
            CLACT_AddActorSurfacePos(bmpOam->act[colIdx + rowIdx * bmpOam->cols], &pos, bmpOam->space);
        }
    }
}

void BMP_OAM_SetObjMode(struct BmpOam *bmpOam, u32 objMode)
{
    int rowIdx;
    int colIdx;

    for (rowIdx = 0; rowIdx < bmpOam->rows; rowIdx++) {
        for (colIdx = 0; colIdx < bmpOam->cols; colIdx++) {
            CLACT_SetActorObjMode(bmpOam->act[rowIdx * bmpOam->cols + colIdx], objMode);
        }
    }
}

void BMP_OAM_SetDrawPriority(struct BmpOam *bmpOam, u32 drawPriority)
{
    int rowIdx;
    int colIdx;

    for (rowIdx = 0; rowIdx < bmpOam->rows; rowIdx++) {
        for (colIdx = 0; colIdx < bmpOam->cols; colIdx++) {
            CLACT_SetActorDrawPriority(bmpOam->act[rowIdx * bmpOam->cols + colIdx], drawPriority);
        }
    }
}

void BMP_OAM_SetBgPriority(struct BmpOam *bmpOam, u32 bgPriority)
{
    int rowIdx;
    int colIdx;

    for (rowIdx = 0; rowIdx < bmpOam->rows; rowIdx++) {
        for (colIdx = 0; colIdx < bmpOam->cols; colIdx++) {
            CLACT_SetActorBgPriority(bmpOam->act[rowIdx * bmpOam->cols + colIdx], bgPriority);
        }
    }
}

void BMP_OAM_SetPalette(struct BmpOam *bmpOam, u32 palette)
{
    int rowIdx;
    int colIdx;

    for (rowIdx = 0; rowIdx < bmpOam->rows; rowIdx++) {
        for (colIdx = 0; colIdx < bmpOam->cols; colIdx++) {
            CLACT_SetActorPaletteOffset(bmpOam->act[rowIdx * bmpOam->cols + colIdx], palette, 0);
        }
    }
}

/*
 * Map the engine's DISPCNT OBJ-mapping bits (mask 0x00300010) to a slot
 * index 0/1/2 and lazily fill that slot through CLACT_RegisterCellAnim with the
 * gModeTable record's two ids.
 *
 * The 0x00200010 arm is not empty: it sets mode = 0 itself, and it is
 * written first of the four arms.  The body is then cross-jumped onto
 * default's identical `mode = 0`, which is why the image branches to the same
 * address on both sides of the last compare.  With the arm empty the compiler
 * jumps past the zeroing; with `mode = 0` in any other position it lays the
 * arm out separately.
 */
u32 BMP_OAM_AcquireModeSlot(struct BmpOamSys *sys, u32 engine, void *arcTool)
{
    volatile u32 *dispcnt; /* DISPCNT of engine A (0x04000000) or B (0x04001000): hardware */
    u32 mapMode;

    if (engine == 0) {
        dispcnt = (volatile u32 *)0x04000000;
    } else {
        dispcnt = (volatile u32 *)0x04001000;
    }

    switch (*dispcnt & 0x00300010) {
    case 0x00200010:
        mapMode = 0;
        break;
    case 0x00100010:
        mapMode = 1;
        break;
    case 0x00000010:
        mapMode = 2;
        break;
    default:
        mapMode = 0;
        break;
    }

    if (sys->slot[mapMode] != -1) {
        return mapMode;
    }

    sys->slot[mapMode] = CLACT_RegisterCellAnim(arcTool, gModeTable[mapMode].resArcId,
                                    gModeTable[mapMode].resEntryId, sys->heapId);
    return mapMode;
}

void BMP_OAM_ReleaseModeSlots(struct BmpOamSys *sys)
{
    int modeIdx;

    for (modeIdx = 0; modeIdx < 3; modeIdx++) {
        if (sys->slot[modeIdx] != -1) {
            CLACT_ReleaseCellAnim(sys->slot[modeIdx]);
            sys->slot[modeIdx] = -1;
        }
    }
}

int func_02025B38(void)
{
    return 19;
}

/*
 * Linear search over the 19 records (12-byte stride), matching on the key
 * byte of each; returns the matching index, or 0 (not -1) when nothing
 * matches, so a caller cannot tell "matched record 0" from "no match".
 */
u32 func_02025B3C(u32 key)
{
    u32 recIdx;

    for (recIdx = 0; recIdx < 0x13; recIdx++) {
        if (key == g_0209FA34[recIdx * 0xc]) {
            return recIdx;
        }
    }
    return 0;
}

u8 func_02025B64(u32 key)
{
    u32 recIdx;

    for (recIdx = 0; recIdx < 0x13; recIdx++) {
        if (key == g_0209FA34[recIdx * 0xc]) {
            return g_0209FA3D[recIdx * 0xc];
        }
    }
    return 0;
}

/*
 * Two-stage lookup: map a caller value to a record index with
 * func_02025B3C, then map that index to an id with func_02025BA0.
 */
u32 func_02025B94(u32 key)
{
    return func_02025BA0(func_02025B3C(key));
}

/*
 * Bounds-checked lookup of the u16 at offset +2 of record idx; out of range
 * returns the sentinel 0xE7.
 *
 * The table address (0x0209FA36) is two bytes into the record array that
 * func_02025B3C searches.  Declaring it as an offset from g_0209FA34
 * changes the code the compiler emits for the pointer arithmetic, so it
 * keeps its own symbol.
 */
u32 func_02025BA0(u32 recIdx)
{
    if (recIdx < 0x13) {
        return *(const u16 *)(g_0209FA36 + recIdx * 0xc);
    }
    return 0xE7;
}

u32 func_02025BB8(u32 recIdx)
{
    if (recIdx < 19)
        return g_0209FA34[recIdx * 12];
    return 0;
}

u32 func_02025BD0(u32 recIdx)
{
    if (recIdx < 19)
        return g_0209FA35[recIdx * 12];
    return 18;
}

int func_02025BE8(void)
{
    return 0x69;
}

/*
 * Three-argument predicate: out of range (`a >= 0xE9`) fails immediately;
 * otherwise it looks `a` up through func_02025B64 and fails if the result
 * is below `b`; otherwise, when `c == 1`, it fails unless `a` is one of two
 * special-cased values (0x69 or 0).  Every early exit is a direct `return`,
 * not a shared tail.
 *
 * sub_02025C1C and sub_02025C30 both wrap the predicate with the same
 * shape, "return the value on success, 0 on failure", differing only in
 * which argument is guarded: the first, or the second.
 */
u32 func_02025BEC(u32 id, u32 minValue, u32 flag)
{
    if (id >= 0xE9) {
        return 0;
    }
    if (func_02025B64(id) < minValue) {
        return 0;
    }
    if (flag == 1) {
        if (id != 0x69 && id != 0) {
            return 0;
        }
    }
    return 1;
}

u32 sub_02025C1C(u32 id, u32 minValue, u32 flag)
{
    u32 result = id;

    if (!func_02025BEC(id, minValue, flag)) {
        result = 0;
    }
    return result;
}

u32 sub_02025C30(u32 id, u32 minValue, u32 flag)
{
    u32 result = minValue;

    if (!func_02025BEC(id, minValue, flag)) {
        result = 0;
    }
    return result;
}

int func_02025C44(u32 key, u32 *outWord, u32 *outByte)
{
    u32 recIdx = func_02025B3C(key);
    u32 recOff;

    if (recIdx == 0) {
        return 0;
    }
    recOff = recIdx * 12;
    *outWord = *(const u32 *)(g_0209FA38 + recOff);
    *outByte = g_0209FA3C[recOff];
    return 1;
}
