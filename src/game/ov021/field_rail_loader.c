/*
 * file:     field_rail_loader.c
 * unit:     yes
 * function: FIELD_RAIL_LOADER_InitSetting, FIELD_RAIL_LOADER_Create, FIELD_RAIL_LOADER_Delete, FIELD_RAIL_LOADER_Load, FIELD_RAIL_LOADER_Unload, FIELD_RAIL_LOADER_GetSetting, FIELD_RAIL_LOADER_CreateScriptEvent, FIELD_RAIL_LOADER_VanishMmdl, FIELD_RAIL_LOADER_EmptyProc0, FIELD_RAIL_LOADER_EmptyProc1, FIELD_RAIL_LOADER_EmptyProc2, FIELD_RAIL_LOADER_EmptyProc3
 * address:  0x0219EF14
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 * Split from fldmmdl_g3dobj.c at 0x0219EF14 (__FILE__ anchor field_rail_loader.c at 0x0219EF44; 0x0219EF14 fills the loader setting with the loader data at 0x021DDDA0..0x021DDDF0).
 *
 * symbols:
 *   GFL_HEAP_Free  0x020307B0  arm
 *   GFL_HEAP_Alloc  0x02030734  arm
 *   MI_CpuFill8  0x02082BCC  arm
 *   FLDMMDL_SetMoveBit  0x0216D568  thumb  ov010
 *   d_021DDDB8     0x021DDDB8  data
 *   d_021DDDA0     0x021DDDA0  data
 *   d_021DDDAC     0x021DDDAC  data
 *   d_021DDE08     0x021DDE08  data
 *   ARC_UTIL_LoadMemberWithSize  0x0204A298  arm
 *   SCRIPT_SYS_CreateScriptEventSimple  0x02158768  thumb  ov010
 *   FLDMMDL_SetStatusBitVanish  0x0216DAC8  thumb  ov010
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

/* Counts and tables of the loaded rail data, and the rail system limits.
 * Sits at offset 8 of FieldRailLoader (0x30 bytes). */
typedef struct {
    u16 pointCount;
    u16 lineCount;
    u16 railCount;
    u16 cameraCount;
    u16 maxWalkers;       /* 0x14 */
    u16 maxLayers;        /* 3 */
    u16 maxViews;         /* 3 */
    u16 reserved;
    void *points;         /* 0x70 byte entries */
    void *lines;          /* 0x48 byte entries */
    void *rails;          /* 0x24 byte entries */
    void *cameras;        /* 0x24 byte entries */
    const void *cameraFuncs;   /* three function pointers */
    const void *pointFuncs;
    const void *lineFuncs;
} FieldRailSetting;

/* The rail data loader (0x38 bytes). */
typedef struct {
    u32 *data;            /* the loaded rail data file */
    u32 dataSize;
    FieldRailSetting setting;
    u32 entryInfo;        /* word the data header points at */
} FieldRailLoader;

/* Layout of the loaded rail data: offsets of its sections from its start. */
#define _SECTION_ENTRY_INFO 1
#define _SECTION_POINTS     2
#define _SECTION_LINES      3
#define _SECTION_RAILS      4
#define _SECTION_CAMERAS    5
#define _SECTION_END        6

#define _RAIL_DATA_ARCHIVE  0x4f

extern u32 GFL_HEAP_Free(void *mem);
extern void *GFL_HEAP_Alloc(unsigned int heapId, unsigned int size, int clear, const char *site, unsigned short line);
extern void MI_CpuFill8(void *dst, u32 value, u32 size);
extern void *FLDMMDL_SetMoveBit(void *mmdl, u32 bits);
extern int ARC_UTIL_LoadMemberWithSize(int archive, int member, int decompress, int heapId, u32 *outSize);
extern void *SCRIPT_SYS_CreateScriptEventSimple(int a0, int a1, int a2, int a3);
extern void FLDMMDL_SetStatusBitVanish(unsigned int *p, unsigned int v);
void FIELD_RAIL_LOADER_InitSetting(FieldRailSetting *setting);
FieldRailLoader *FIELD_RAIL_LOADER_Create(u32 heapId);
void FIELD_RAIL_LOADER_Delete(FieldRailLoader *loader);
void FIELD_RAIL_LOADER_Load(FieldRailLoader *loader, u32 member, u32 heapId);
void FIELD_RAIL_LOADER_Unload(FieldRailLoader *loader);
FieldRailSetting *FIELD_RAIL_LOADER_GetSetting(FieldRailLoader *loader);
int FIELD_RAIL_LOADER_CreateScriptEvent(u32 a, u32 b, u32 c, u32 e0, u32 e1, u16 id);
int FIELD_RAIL_LOADER_VanishMmdl(void *a, u32 b, u32 c, u32 d);
void FIELD_RAIL_LOADER_EmptyProc0(void);
void FIELD_RAIL_LOADER_EmptyProc1(void);
void FIELD_RAIL_LOADER_EmptyProc2(void);
void FIELD_RAIL_LOADER_EmptyProc3(void);
extern u32 d_021DDDB8[];     /* function table of the cameras */
extern u32 d_021DDDA0[];     /* function table of the points */
extern u32 d_021DDDAC[];     /* function table of the lines */
extern char d_021DDE08[];    /* __FILE__ */

/* Clear a setting and fill in the limits and function tables. */
void FIELD_RAIL_LOADER_InitSetting(FieldRailSetting *setting)
{
    MI_CpuFill8(setting, 0, 0x30);
    setting->maxWalkers = 0x14;
    setting->maxLayers = 3;
    setting->maxViews = 3;
    setting->cameraFuncs = d_021DDDB8;
    setting->pointFuncs = d_021DDDA0;
    setting->lineFuncs = d_021DDDAC;
}

FieldRailLoader *FIELD_RAIL_LOADER_Create(u32 heapId)
{
    FieldRailLoader *loader = (FieldRailLoader *)GFL_HEAP_Alloc((u16)heapId, 0x38, 1, d_021DDE08, 0xC0);
    FIELD_RAIL_LOADER_InitSetting(&loader->setting);
    return loader;
}

void FIELD_RAIL_LOADER_Delete(FieldRailLoader *loader)
{
    FIELD_RAIL_LOADER_Unload(loader);
    GFL_HEAP_Free(loader);
}

/* Load rail data file `member` and find its sections. */
void FIELD_RAIL_LOADER_Load(FieldRailLoader *loader, u32 member, u32 heapId)
{
    u32 size;
    loader->data = (u32 *)ARC_UTIL_LoadMemberWithSize(_RAIL_DATA_ARCHIVE, member, 0, (u16)heapId, &size);
    loader->dataSize = size;
    loader->setting.points = (u8 *)loader->data + loader->data[_SECTION_POINTS];
    loader->setting.pointCount = (loader->data[_SECTION_LINES] - loader->data[_SECTION_POINTS]) / 0x70;
    loader->setting.lines = (u8 *)loader->data + loader->data[_SECTION_LINES];
    loader->setting.lineCount = (loader->data[_SECTION_RAILS] - loader->data[_SECTION_LINES]) / 0x48;
    loader->setting.rails = (u8 *)loader->data + loader->data[_SECTION_RAILS];
    loader->setting.railCount = (loader->data[_SECTION_CAMERAS] - loader->data[_SECTION_RAILS]) / 0x24;
    loader->setting.cameras = (u8 *)loader->data + loader->data[_SECTION_CAMERAS];
    loader->setting.cameraCount = (loader->data[_SECTION_END] - loader->data[_SECTION_CAMERAS]) / 0x24;
    loader->entryInfo = *(u32 *)((u8 *)loader->data + loader->data[_SECTION_ENTRY_INFO]);
}

/* Free the loaded data and reset the setting. */
void FIELD_RAIL_LOADER_Unload(FieldRailLoader *loader)
{
    if (loader->data != 0) {
        GFL_HEAP_Free(loader->data);
        loader->data = 0;
    }
    FIELD_RAIL_LOADER_InitSetting(&loader->setting);
}

FieldRailSetting *FIELD_RAIL_LOADER_GetSetting(FieldRailLoader *loader)
{
    return &loader->setting;
}

/* 0219F01C..0219F054 are probably a field model move proc set, not loader
 * code (see misplaced.tsv). */
int FIELD_RAIL_LOADER_CreateScriptEvent(u32 a, u32 b, u32 c, u32 e0, u32 e1, u16 id)
{
return (int)SCRIPT_SYS_CreateScriptEventSimple(a, ((c << 16) >> 16), e1, *(u16 *)((u8 *)((u8 *)&e1) + 4));
}

int FIELD_RAIL_LOADER_VanishMmdl(void *mmdl, u32 unused1, u32 unused2, u32 unused3)
{
FLDMMDL_SetStatusBitVanish((unsigned int *)mmdl, 1);
return (int)FLDMMDL_SetMoveBit(mmdl, (1 << 15));
}

void FIELD_RAIL_LOADER_EmptyProc0(void)
{
}

void FIELD_RAIL_LOADER_EmptyProc1(void)
{
}

void FIELD_RAIL_LOADER_EmptyProc2(void)
{
}

void FIELD_RAIL_LOADER_EmptyProc3(void)
{
}
