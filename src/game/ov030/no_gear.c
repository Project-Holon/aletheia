/*
 * file:     no_gear.c
 * unit:     yes
 * function: NO_GEAR_StoreStepFunc, NO_GEAR_SetStepFunc, NO_GEAR_LoadGraphics, NO_GEAR_SetupBackgrounds, NO_GEAR_Init, NO_GEAR_ReleaseGraphics, NO_GEAR_Step, NO_GEAR_Create, NO_GEAR_Update, NO_GEAR_Destroy
 * address:  0x021EFEC0
 * region:   ov030
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   ARC_TOOL_CreateHandle  0x020490F4  arm
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAME_DATA_GetMyStatus  0x02012944  thumb
 *   MYSTATUS_GetOutfitVariant  0x02008550  thumb
 *   ARC_UTIL_UploadPaletteFromHandleWhole  0x02049B68  arm
 *   ARC_UTIL_RegisterObjCharFromHandle  0x02049740  arm
 *   ARC_UTIL_UploadBgPaletteAddFromHandle  0x02049990  arm
 *   ARC_TOOL_DeleteHandle  0x02049238  arm
 *   GFL_NET_RestartWithDefaultTimeout  0x0203D34C  arm
 *   BG_SYS_SetSubPlaneVisible  0x02043598  arm
 *   gNoGearPaletteFileIds     0x021F0134  data  ov030  a4
 *   gNoGearCharFileIds     0x021F0140  data  ov030  a4
 *   BG_SYS_SetPlaneVisible  0x02040588  arm
 *   BG_SYS_InitBgLayer  0x0203FCA0  arm
 *   BG_SYS_SetVisibleLayer  0x0204047C  arm
 *   BG_SYS_SetTileEntry  0x02041300  arm
 *   BG_SYS_PushTile  0x020409B4  arm
 *   gNoGearBgTemplateMain     0x021F014C  data  ov030  a4
 *   gNoGearBgTemplateMid     0x021F016C  data  ov030  a4
 *   gNoGearBgTemplateBack     0x021F018C  data  ov030  a4
 *   BG_SYS_DeleteHalf  0x0203FB44  arm
 *   BG_SYS_FreeLayerBuf  0x020403F4  arm
 *   GFL_HEAP_Alloc  0x02030734  arm
 *   str_021F01C0   0x021F01C0  data   ov030  a1
 *   GAME_DATA_GetWifiList 0x0201283C thumb
 *   WIH_DWC_PollStatus 0x0201058C thumb
 *   NO_GEAR_ReleaseGraphics  0x021F007C  thumb  ov030
 *   GFL_HEAP_Free  0x020307B0  arm
 */
#include "../ov021/field_subscreen_types.h"

struct GameSystem;
struct GameData;
struct PlayerStatus;
struct ArchiveHandle;

/* Background setup record handed to the BG system (one per screen layer). */
struct BgTemplate {
    u32 scrollX;
    u32 scrollY;
    u32 bufSize;
    u32 baseTile;
    u8  screenSize;
    u8  colorMode;
    u8  screenBase;
    u8  charBase;
    u32 extPaletteSlot;
    u8  priority;
    u8  areaOver;
    u8  dummy;
    u8  mosaicFlag;
    u32 mosaic;
};

/* Panel shown on the lower screen when the save has no C-Gear (0x20 bytes). */
typedef struct NoGearWork {
    void (*stepFunc)(struct NoGearWork *work);
    u32 pad04;
    u16 heapId;
    u16 pad0A;
    u32 pad0C[2];
    u32 charBlock;                  /* BG char area: low 16 bits offset, high 16 bits size */
    struct GameSystem *gameSystem;
    u32 pad1C;
} NoGearWork;

extern struct ArchiveHandle *ARC_TOOL_CreateHandle(u32 archiveId, u32 heapId);
extern struct GameData *GAMESYSTEM_GetGameData(const struct GameSystem *gameSystem);
extern struct PlayerStatus *GAME_DATA_GetMyStatus(struct GameData *gameData);
extern u8 MYSTATUS_GetOutfitVariant(const struct PlayerStatus *player);
extern void ARC_UTIL_UploadPaletteFromHandleWhole(struct ArchiveHandle *archive, u32 fileId, u32 bgId, u32 offset, u32 size, u16 heapId);
extern u32 ARC_UTIL_RegisterObjCharFromHandle(struct ArchiveHandle *archive, u32 fileId, u32 bgId, u32 offset, u32 size, u16 heapId);
extern u32 ARC_UTIL_UploadBgPaletteAddFromHandle(struct ArchiveHandle *archive, u32 fileId, u32 bgId, u32 x, u32 y, u32 width, u32 height, u16 heapId);
extern void ARC_TOOL_DeleteHandle(struct ArchiveHandle *archive);
extern void GFL_NET_RestartWithDefaultTimeout(u32 a, u32 b);
extern void BG_SYS_SetSubPlaneVisible(u32 planeMask, u32 enable);
extern void BG_SYS_SetPlaneVisible(unsigned char bgId, unsigned char visible);
extern void BG_SYS_InitBgLayer(u32 bgId, const struct BgTemplate *template, u32 type);
extern void BG_SYS_SetVisibleLayer(int bgId, unsigned short priority);
extern void BG_SYS_SetTileEntry(u32 bgId, int a1, int a2, int a3, u8 width, u8 height, u8 mode);
extern void BG_SYS_PushTile(u32 bgId);
extern void BG_SYS_DeleteHalf(u32 bgId, u32 offset, u32 size);
extern void BG_SYS_FreeLayerBuf(u32 bgId);
extern void *GFL_HEAP_Alloc(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void *GAME_DATA_GetWifiList(struct GameData *gameData);
extern u32 WIH_DWC_PollStatus(void *key);
void NO_GEAR_StoreStepFunc(void (**slot)(NoGearWork *), void (*stepFunc)(NoGearWork *));
void NO_GEAR_SetStepFunc(NoGearWork *work, void (*stepFunc)(NoGearWork *), int line);
void NO_GEAR_LoadGraphics(NoGearWork *work);
void NO_GEAR_SetupBackgrounds(void);
void NO_GEAR_Init(NoGearWork *work);
void NO_GEAR_ReleaseGraphics(NoGearWork *work);
void NO_GEAR_Step(NoGearWork *work);
NoGearWork *NO_GEAR_Create(void *cgearSave, FieldSubscreen *subscreen, struct GameSystem *gameSystem);
void NO_GEAR_Update(NoGearWork *work);
void NO_GEAR_Hook(void);
extern const u32 gNoGearPaletteFileIds[];
extern const u32 gNoGearCharFileIds[];
extern struct BgTemplate gNoGearBgTemplateMain;
extern struct BgTemplate gNoGearBgTemplateMid;
extern struct BgTemplate gNoGearBgTemplateBack;
extern char str_021F01C0[];
typedef unsigned short u16;
typedef unsigned int   u32;
struct NoGearWork;
extern u32 GFL_HEAP_Free(void *block);
#define REG_DB_BLDCNT_SUB  (*(volatile u16 *)0x04001050)

void NO_GEAR_StoreStepFunc(void (**slot)(NoGearWork *), void (*stepFunc)(NoGearWork *))
{
    *slot = stepFunc;
}



/*
 * Tail call to the unlabelled ov030 leaf NO_GEAR_StoreStepFunc; its ABS32 pool word
 * is now witnessed by the EXACT shard entry for NO_GEAR_StoreStepFunc (matched x1).
 */
void NO_GEAR_SetStepFunc(NoGearWork *work, void (*stepFunc)(NoGearWork *), int line)
{
    NO_GEAR_StoreStepFunc(&work->stepFunc, stepFunc);
}



void NO_GEAR_LoadGraphics(NoGearWork *work)
{
    struct ArchiveHandle *archive;
    int variant;

    archive = ARC_TOOL_CreateHandle(0x1E, work->heapId);
    variant = MYSTATUS_GetOutfitVariant(GAME_DATA_GetMyStatus(GAMESYSTEM_GetGameData(work->gameSystem)));
    ARC_UTIL_UploadPaletteFromHandleWhole(archive, gNoGearPaletteFileIds[variant], 4, 0, 0, work->heapId);
    work->charBlock = ARC_UTIL_RegisterObjCharFromHandle(archive, gNoGearCharFileIds[variant], 6, 0, 0, work->heapId);
    ARC_UTIL_UploadBgPaletteAddFromHandle(archive, 3, 6, 0, (u16)work->charBlock, 0, 0, work->heapId);
    ARC_TOOL_DeleteHandle(archive);
    GFL_NET_RestartWithDefaultTimeout(0, work->heapId);
    BG_SYS_SetSubPlaneVisible(0x10, 1);
}



void NO_GEAR_SetupBackgrounds(void)
{
    int bgId;

    for (bgId = 4; bgId <= 7; bgId++) {
        BG_SYS_SetPlaneVisible((u8)bgId, 0);
    }
    {
        struct BgTemplate template = gNoGearBgTemplateMain;
        BG_SYS_InitBgLayer(6, &template, 0);
        BG_SYS_SetPlaneVisible((u8)6, 1);
        BG_SYS_SetVisibleLayer(6, 3);
        BG_SYS_SetTileEntry(6, 0, 0, 0, 0x20, 0x20, 0x11);
        BG_SYS_PushTile(6);
    }
    {
        struct BgTemplate template = gNoGearBgTemplateMid;
        BG_SYS_InitBgLayer(5, &template, 0);
        BG_SYS_SetPlaneVisible((u8)5, 1);
        BG_SYS_SetVisibleLayer(5, 1);
        BG_SYS_SetTileEntry(5, 0, 0, 0, 0x20, 0x20, 0x11);
        BG_SYS_PushTile(5);
    }
    {
        struct BgTemplate template = gNoGearBgTemplateBack;
        BG_SYS_InitBgLayer(4, &template, 0);
        BG_SYS_SetPlaneVisible((u8)4, 1);
        BG_SYS_SetVisibleLayer(4, 2);
        BG_SYS_SetTileEntry(4, 0, 0, 0, 0x20, 0x20, 0x11);
        BG_SYS_PushTile(4);
    }
}


void NO_GEAR_Init(NoGearWork *work)
{
    NO_GEAR_SetupBackgrounds();
    NO_GEAR_LoadGraphics(work);
    NO_GEAR_SetStepFunc(work, NO_GEAR_Step, 0x149);
}



/*
 * (followed by an unlabelled 2-byte `bx lr` stub at 0x021F00C4)
 */
void NO_GEAR_ReleaseGraphics(NoGearWork *work)
{
    u32 charBlock = work->charBlock;

    BG_SYS_DeleteHalf(6, (u16)charBlock, (u16)(charBlock >> 16));
    BG_SYS_FreeLayerBuf(4);
    BG_SYS_FreeLayerBuf(5);
    BG_SYS_FreeLayerBuf(6);
    BG_SYS_SetPlaneVisible(4, 0);
    BG_SYS_SetPlaneVisible(5, 0);
    BG_SYS_SetPlaneVisible(6, 0);
    BG_SYS_SetSubPlaneVisible(0x10, 0);
}


/*
 * extent: empty callback bx lr, two-byte alignment then separate constructor
 * starts 0x021F00C8; callback alone is reproduced.
 * interface: NO_GEAR_Init installs this callback and NO_GEAR_Update invokes
 * it with its object pointer in r0. Empty body does not read that context.
 */
void NO_GEAR_Step(NoGearWork *work)
{
}



NoGearWork *NO_GEAR_Create(void *cgearSave, FieldSubscreen *subscreen, struct GameSystem *gameSystem)
{
    NoGearWork *work;

    work = GFL_HEAP_Alloc(0x15, 0x20, 1, str_021F01C0, 0x17A);
    work->heapId = 0x15;
    work->gameSystem = gameSystem;
    NO_GEAR_Init(work);
    return work;
}


/*
 * extent: empty follower NO_GEAR_Hook then two-byte zero padding.
 */
void NO_GEAR_Update(NoGearWork *work)
{
    if (work->stepFunc != 0) {
        work->stepFunc(work);
    }
    WIH_DWC_PollStatus(GAME_DATA_GetWifiList(GAMESYSTEM_GetGameData(work->gameSystem)));
}


void NO_GEAR_Hook(void)
{
}

/* Frees the BG resources of the panel, clears the sub screen blend, frees the work. */
void NO_GEAR_Destroy(struct NoGearWork *work)
{
    NO_GEAR_ReleaseGraphics(work);
    REG_DB_BLDCNT_SUB = 0;
    GFL_HEAP_Free(work);
}
