/*
 * file:     wm_icon.c
 * unit:     yes
 * function: GFL_NET_WM_ICON_Create, GFL_NET_WM_ICON_Draw, GFL_NET_WM_ICON_GetEngine, GFL_NET_WM_ICON_GetCharName, GFL_NET_WM_ICON_SetLevel, GFL_NET_WM_ICON_Delete, GFL_NET_WM_ICON_SetScreen, GFL_NET_WM_ICON_GetCharOffset, GFL_NET_WM_ICON_LoadGraphics, GFL_NET_WM_ICON_ClearOam, GFL_NET_WM_ICON_EasyStart, GFL_NET_WM_ICON_EasyEnd, GFL_NET_WM_ICON_EasySetLevel, GFL_NET_WM_ICON_EasySetScreen, GFL_NET_WM_ICON_EasyMain, GFL_NET_WM_ICON_EasyObjWindowOn, GFL_NET_WM_ICON_EasyObjWindowOff, GFL_NET_WM_ICON_SetDefaultPos, GFL_NET_WM_ICON_SetDefaultScreen, GFL_NET_WM_ICON_EasyGetEngine
 * address:  0x02036BD4
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Cut from touchpanel.c by tools/splitfile.py.
 *
 * symbols:
 *   GFL_HEAP_Alloc                    0x02030734  arm
 *   GFL_HEAP_Free                    0x020307B0  arm
 *   SAVEDATA_PanicFail                    0x02034714  arm
 *   GX_GetBankForOBJ                 0x02080C24  arm
 *   GX_GetBankForSubOBJ              0x02080C64  arm
 *   GX_LoadOAM                       0x0207E684  arm
 *   GXS_LoadOAM                      0x0207E708  arm
 *   func_0200F168                    0x0200F168  thumb
 *   func_0200F16C                    0x0200F16C  thumb
 *   ARC_TOOL_CreateHandle                    0x020490F4  arm
 *   func_02049B68                    0x02049B68  arm
 *   func_02049800                    0x02049800  arm
 *   ARC_TOOL_DeleteHandle                    0x02049238  arm
 *   _pTouchPanelWork                 0x021469C4  data
 *   _WmIconEasy                      0x021469C8  data
 *   wm_icon_File                     0x020A79F0  data
 *   wm_icon_AssertObjMapping         0x020A79FC  data
 *   wm_icon_HiddenOam                0x020A0810  data
 */
#include "touchpanel_shared_types.h"
#include "net_queue_shared_types.h"

typedef volatile u32   vu32;

#define REG_POWCNT          0x04000304

#define REG_DISPCNT         0x04000000

#define REG_DB_DISPCNT      0x04001000

#define HW_OAM              0x07000000

#define HW_DB_OAM           0x07000400

/* wm_icon.c: the wireless icon, 0x14 bytes */
typedef struct {
    union {
        u32 attr01;
        struct { u16 attr0; u16 attr1; };
    };
    u16 attr2;
    u16 _3;
} GXOamAttr;

typedef struct {
    u32 level;                   /* 0x00: signal level 0..3 */
    u16 x;                       /* 0x04 */
    u16 y;                       /* 0x06 */
    u8  pad08[4];
    u8  iconVariant;             /* 0x0C: picks the character set */
    u8  screen;                  /* 0x0D: 1 top, 2 bottom */
    u8  screenChanged;           /* 0x0E: may be on both OAMs */
    u8  objWindow;               /* 0x0F: draw an OBJ window under it */
    GXOamAttr *lastOam;          /* 0x10: OAM of the last draw */
} WmIcon;

/* wm_icon.c defaults and the one icon the Easy calls drive */
typedef struct {
    u16 defaultX;
    u16 defaultY : 14;
    u16 screen   : 2;
    WmIcon *icon;
} WmIconEasy;

/* net_device_table.c: archive data ids of the icon graphics */
typedef struct {
    u32 charData[2];
    u32 palette;
} WmIconArcData;

extern void *GFL_HEAP_Alloc(u32 heapId, u32 size, int clear, const char *file, u16 line);

extern u32 GFL_HEAP_Free(void *p);

extern void SAVEDATA_PanicFail(const char *file, u32 line, const char *expr);

extern u32  GX_GetBankForOBJ(void);

extern u32  GX_GetBankForSubOBJ(void);

extern void GX_LoadOAM(const void *src, u32 offset, u32 size);

extern void GXS_LoadOAM(const void *src, u32 offset, u32 size);

extern u32  func_0200F168(void);

extern void func_0200F16C(WmIconArcData *ids);

extern void *ARC_TOOL_CreateHandle(u32 arcId, u32 heapId);

extern void func_02049B68(void *arc, u32 dataId, int palType, int offset, int size, int heapId);

extern void func_02049800(void *arc, u32 dataId, int engine, int offset, int a4, int a5, int heapId);

extern void ARC_TOOL_DeleteHandle(void *arc);

/* wm_icon.c */
WmIcon *GFL_NET_WM_ICON_Create(u32 unused, u32 heapId, u32 x, u32 y, u32 iconVariant, WmIcon *icon, u32 screen, u32 screenChanged, u32 level);

void GFL_NET_WM_ICON_Draw(WmIcon *icon);

u32 GFL_NET_WM_ICON_GetEngine(const WmIcon *icon);

u32 GFL_NET_WM_ICON_GetCharName(u32 engine, u32 charNo);

WmIcon *GFL_NET_WM_ICON_SetLevel(WmIcon *icon, int level);

void GFL_NET_WM_ICON_Delete(WmIcon *icon);

void GFL_NET_WM_ICON_SetScreen(WmIcon *icon, u32 isTop, u32 heapId);

int GFL_NET_WM_ICON_GetCharOffset(int engine);

void GFL_NET_WM_ICON_LoadGraphics(int engine, int iconVariant, int heapId);

void GFL_NET_WM_ICON_ClearOam(void);

void GFL_NET_WM_ICON_EasyStart(u32 x, u32 y, u32 iconVariant, u32 heapId);

void GFL_NET_WM_ICON_EasyEnd(void);

u32 GFL_NET_WM_ICON_EasySetLevel(u32 level);

void GFL_NET_WM_ICON_EasySetScreen(u32 isTop, u32 heapId);

void GFL_NET_WM_ICON_EasyMain(void);

void GFL_NET_WM_ICON_EasyObjWindowOn(void);

void GFL_NET_WM_ICON_EasyObjWindowOff(void);

void GFL_NET_WM_ICON_SetDefaultPos(u16 x, u16 y);

void GFL_NET_WM_ICON_SetDefaultScreen(u32 screen);

u32 GFL_NET_WM_ICON_EasyGetEngine(void);

extern WmIconEasy _WmIconEasy;

extern const char wm_icon_File[];

extern const char wm_icon_AssertObjMapping[];

extern const u32 wm_icon_HiddenOam[8];

/* ==================================================================
 * wm_icon.c
 * ================================================================== */

/*
 * Sets up an icon (allocating it when icon is 0) and loads its graphics.
 * A default position set with GFL_NET_WM_ICON_SetDefaultPos wins over x and y.
 */
WmIcon *GFL_NET_WM_ICON_Create(u32 unused, u32 heapId, u32 x, u32 y, u32 iconVariant,
                      WmIcon *icon, u32 screen, u32 screenChanged, u32 level)
{
    if (icon == 0)
        icon = GFL_HEAP_Alloc((u16)(((u16)heapId & 0x7fff) | 0x8000), sizeof(WmIcon), 0,
                             wm_icon_File, 100);
    icon->x = x;
    icon->y = y;
    if (_WmIconEasy.defaultX != 0) {
        icon->x = _WmIconEasy.defaultX;
        icon->y = _WmIconEasy.defaultY;
    }
    icon->level = level;
    icon->iconVariant = iconVariant;
    icon->screenChanged = screenChanged;
    icon->screen = screen;
    icon->objWindow = 0;
    icon->lastOam = (GXOamAttr *)HW_OAM;
    GFL_NET_WM_ICON_LoadGraphics(GFL_NET_WM_ICON_GetEngine(icon), icon->iconVariant, (u16)heapId);
    return icon;
}

static inline void G2_SetOBJAttr(GXOamAttr *oam, int x, int y, int priority,
                                 int mode, BOOL mosaic, int effect, int shape,
                                 int color, int charName, int cParam, int rsParam)
{
    oam->attr01 = (u32)(((y & 0xff) << 0) |
                        (mode << 10) |
                        (mosaic << 12) |
                        effect |
                        (color << 13) |
                        shape |
                        ((x & 0x1ff) << 16) |
                        (rsParam << 25));
    oam->attr2 = (u16)((charName << 0) | (priority << 10) | (cParam << 12));
}

/*
 * Writes the icon's two 16x16 OAM entries (the first one an OBJ window
 * when objWindow is set) into the OAM of its engine, and hides the pair
 * in the OAM of the last draw when the engine changed.
 */
void GFL_NET_WM_ICON_Draw(WmIcon *icon)
{
    u32 engine;
    u32 name;
    GXOamAttr *oam;

    engine = GFL_NET_WM_ICON_GetEngine(icon);
    name = GFL_NET_WM_ICON_GetCharName(engine, icon->level);
    if (engine == 1) {
        oam = (GXOamAttr *)HW_OAM;
    } else {
        oam = (GXOamAttr *)HW_DB_OAM;
    }
    if (icon->objWindow == 1) {
        G2_SetOBJAttr(&oam[0], icon->x, icon->y, 0, 2, 0, 0, 0x40000000, 0, name, 14, 0);
    } else {
        G2_SetOBJAttr(&oam[0], 0, 0, 0, 0, 0, 0x200, 0x40000000, 0, 0, 0, 0);
    }
    G2_SetOBJAttr(&oam[1], icon->x, icon->y, 0, 0, 0, 0, 0x40000000, 0, name, 14, 0);
    if (oam != icon->lastOam) {
        G2_SetOBJAttr(&icon->lastOam[0], 0, 0, 0, 0, 0, 0x200, 0x40000000, 0, 0, 0, 0);
        G2_SetOBJAttr(&icon->lastOam[1], 0, 0, 0, 0, 0, 0x200, 0x40000000, 0, 0, 0, 0);
        icon->lastOam = oam;
    }
}

/* Engine of the icon's screen (1 main, 2 sub), from the LCD swap bit. */
u32 GFL_NET_WM_ICON_GetEngine(const WmIcon *icon)
{
    switch (icon->screen) {
    case 1:
        return ((*(u16 *)REG_POWCNT & 0x8000) >> 15) == 1 ? 1 : 2;
    case 2:
        return ((*(u16 *)REG_POWCNT & 0x8000) >> 15) == 1 ? 2 : 1;
    }
    return 1;
}

/* OBJ character name of charNo under the engine's OBJ mapping mode. */
u32 GFL_NET_WM_ICON_GetCharName(u32 engine, u32 charNo)
{
    int mapping;

    if (engine == 1) {
        GX_GetBankForOBJ();
        mapping = *(vu32 *)REG_DISPCNT & 0x00300010;
    } else {
        GX_GetBankForSubOBJ();
        mapping = *(vu32 *)REG_DB_DISPCNT & 0x00300010;
    }
    switch (mapping) {
    case 0x10:
        return charNo * 4;
    case 0x00100010:
        return charNo * 2;
    case 0x00200010:
        return charNo;
    case 0x00300010:
    default:
        SAVEDATA_PanicFail(wm_icon_File, 0xfb, wm_icon_AssertObjMapping);
        return charNo;
    }
}

WmIcon *GFL_NET_WM_ICON_SetLevel(WmIcon *icon, int level)
{
    if (level < 4)
        icon->level = level;
    return icon;
}

/* Hides the icon's entries in main OAM (and in sub OAM when the icon may
 * have been drawn there) and frees it. */
void GFL_NET_WM_ICON_Delete(WmIcon *icon)
{
    *(volatile u32 *)(HW_OAM + 0x0) = 0x40000200;
    *(volatile u16 *)(HW_OAM + 0x4) = 0;
    *(volatile u32 *)(HW_OAM + 0x8) = 0x40000200;
    *(volatile u16 *)(HW_OAM + 0xc) = 0;
    if (icon->screenChanged != 0) {
        volatile u32 *oam = (volatile u32 *)HW_DB_OAM;

        oam[0] = 0x40000200;
        ((volatile u16 *)oam)[2] = 0;
        oam[2] = 0x40000200;
        ((volatile u16 *)oam)[6] = 0;
    }
    GFL_HEAP_Free(icon);
}

void GFL_NET_WM_ICON_SetScreen(WmIcon *icon, u32 isTop, u32 heapId)
{
    icon->screen = (isTop != 0) ? 1 : 2;
    icon->screenChanged = 1;
    GFL_NET_WM_ICON_LoadGraphics(GFL_NET_WM_ICON_GetEngine(icon), icon->iconVariant, heapId);
}

/* OBJ VRAM offset of the icon characters; always 0. */
int GFL_NET_WM_ICON_GetCharOffset(int engine)
{
    if ((u32)engine == 1) {
        GX_GetBankForOBJ();
    } else {
        GX_GetBankForSubOBJ();
    }
    return 0;
}

/* Loads the icon palette and characters for the engine. */
void GFL_NET_WM_ICON_LoadGraphics(int engine, int iconVariant, int heapId)
{
    WmIconArcData ids;
    int objEngine;
    int palType;
    void *arc;
    int charIdx;
    int charOffset;

    arc = ARC_TOOL_CreateHandle(func_0200F168(), (u16)((heapId & 0x7fff) | 0x8000));
    func_0200F16C(&ids);
    if (engine == 1) {
        palType = 1;
        objEngine = 0;
    } else {
        palType = 5;
        objEngine = 1;
    }
    func_02049B68(arc, ids.palette, palType, 0x1c0, 0x20, heapId);
    charIdx = (iconVariant == 0) ? 1 : 0;
    charOffset = GFL_NET_WM_ICON_GetCharOffset(engine);
    func_02049800(arc, ids.charData[charIdx], objEngine, charOffset, 0, 0, heapId);
    ARC_TOOL_DeleteHandle(arc);
}

/* Hides the first four OAM entries of both engines. */
void GFL_NET_WM_ICON_ClearOam(void)
{
    GX_LoadOAM(wm_icon_HiddenOam, 0, sizeof(wm_icon_HiddenOam));
    GXS_LoadOAM(wm_icon_HiddenOam, 0, sizeof(wm_icon_HiddenOam));
}

/* (Re)creates the easy icon at a position; a new icon takes the default
 * screen and level 3. */
void GFL_NET_WM_ICON_EasyStart(u32 x, u32 y, u32 iconVariant, u32 heapId)
{
    WmIcon *icon;

    GFL_NET_WM_ICON_ClearOam();
    icon = _WmIconEasy.icon;
    if (icon != 0) {
        u8  screen;
        u32 level;
        u8  screenChanged;

        screenChanged = icon->screenChanged;
        screen = icon->screen;
        level = icon->level;
        GFL_NET_WM_ICON_EasyEnd();
        _WmIconEasy.icon = GFL_NET_WM_ICON_Create(0, heapId, x, y, iconVariant,
                                         _WmIconEasy.icon,
                                         screen, screenChanged, level);
    } else {
        _WmIconEasy.icon = GFL_NET_WM_ICON_Create(0, heapId, x, y, iconVariant,
                                         icon, _WmIconEasy.screen, 0, 3);
    }
}

void GFL_NET_WM_ICON_EasyEnd(void)
{
    GFL_NET_WM_ICON_ClearOam();
    if (_WmIconEasy.icon == 0)
        return;
    GFL_NET_WM_ICON_Delete(_WmIconEasy.icon);
    _WmIconEasy.icon = 0;
}

u32 GFL_NET_WM_ICON_EasySetLevel(u32 level)
{
    WmIcon *icon;

    icon = _WmIconEasy.icon;
    if (icon == 0)
        return (u32)icon;
    return (u32)GFL_NET_WM_ICON_SetLevel(icon, level);
}

void GFL_NET_WM_ICON_EasySetScreen(u32 isTop, u32 heapId)
{
    GFL_NET_WM_ICON_SetDefaultScreen(isTop != 0 ? 1 : 2);
    if (_WmIconEasy.icon != 0)
        GFL_NET_WM_ICON_SetScreen(_WmIconEasy.icon, isTop, heapId);
}

void GFL_NET_WM_ICON_EasyMain(void)
{
    if (_WmIconEasy.icon == 0)
        return;
    GFL_NET_WM_ICON_Draw(_WmIconEasy.icon);
}

void GFL_NET_WM_ICON_EasyObjWindowOn(void)
{
    WmIcon *icon;

    icon = _WmIconEasy.icon;
    if (icon != 0)
        icon->objWindow = 1;
}

void GFL_NET_WM_ICON_EasyObjWindowOff(void)
{
    WmIcon *icon;

    icon = _WmIconEasy.icon;
    if (icon != 0)
        icon->objWindow = 0;
}

void GFL_NET_WM_ICON_SetDefaultPos(u16 x, u16 y)
{
    _WmIconEasy.defaultX = x;
    _WmIconEasy.defaultY = y;
}

void GFL_NET_WM_ICON_SetDefaultScreen(u32 screen)
{
    _WmIconEasy.screen = (u16)screen;
}

u32 GFL_NET_WM_ICON_EasyGetEngine(void)
{
    if (_WmIconEasy.icon == 0) {
        return 1;
    }
    return GFL_NET_WM_ICON_GetEngine(_WmIconEasy.icon);
}
