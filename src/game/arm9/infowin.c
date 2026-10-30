/*
 * file:     infowin.c
 * unit:     yes
 * function: INFOWIN_Init, INFOWIN_Update, INFOWIN_Exit, INFOWIN_DrawTask, INFOWIN_WriteScreen, INFOWIN_LoadCharacters, INFOWIN_LoadGraphics, INFOWIN_UpdateClock
 * address:  0x02024A20
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
 *   TCB_DeleteTask   0x02030EAC  arm
 *   GFL_HEAP_Alloc  0x02030734  arm
 *   GFL_USE_AddMainTask  0x020056A0  thumb
 *   GFL_HEAP_Free  0x020307B0  arm
 *   MI_CpuFill8   0x02082BCC  arm
 *   UI_GetPowerState       0x0203568C  arm
 *   GAME_DATA_GetWifiList       0x0201283C  thumb
 *   GAME_DATA_IsConfigFlagSet       0x02012BB0  thumb
 *   gInfoWin            0x0214693C  data
 *   infowin_File        0x020A7478  data
 *   GFL_NET_GetRunState       0x0203CD98  arm
 *   GFL_NET_GetInitParam       0x0203D798  arm
 *   GFL_NET_GetNegotiationNum       0x0203D1B4  arm
 *   GFL_NET_IsNetTypeWifi       0x0203D29C  arm
 *   WIH_DWC_PollStatus       0x0201058C  thumb
 *   GAME_BEACON_GetNextNewLogIndex       0x02026CA0  thumb
 *   d_0209F830          0x0209F830  data a4
 *   d_0209F834          0x0209F834  data a2
 *   d_0209F838          0x0209F838  data a4
 *   d_0209F840          0x0209F840  data a4
 *   d_0209F848          0x0209F848  data a4
 *   d_0209F852          0x0209F852  data a2
 *   d_0209F868          0x0209F868  data a4
 *   d_0209F870          0x0209F870  data a2
 *   BG_SYS_DrawTileEx       0x020410D0  arm
 *   BG_SYS_PushTile       0x020409B4  arm
 *   UI_GetFrameRate       0x02035630  arm
 *   OS_IsRunOnTwl       0x02085D3C  arm
 *   ARC_TOOL_CreateHandle       0x020490F4  arm
 *   BG_SYS_CreateRun       0x0203FA08  arm
 *   ARC_UTIL_UploadPaletteFromHandleWhole       0x02049B68  arm
 *   ARC_UTIL_UploadBgCharFromHandle       0x02049658  arm
 *   ARC_TOOL_DeleteHandle  0x02049238  arm
 *   BG_SYS_SetTileEntry       0x02041300  arm
 *   GF_STANDARD_GetCachedTime       0x0203F4CC  arm
 *   BG_SYS_FreeTileRun  0x0203FB44  arm
 *   BG_SYS_LoadPltt  0x02040E78  arm
 *   TCB_AddTask  0x02030DA8  arm
 */
struct Node;
struct BigObj;

#include "../types.h"
#include "../version.h"

/* Tile width of the two status icons (selection mode and link) and the column of the link icon. */
#if LANGUAGE == LANGUAGE_GERMAN || LANGUAGE == LANGUAGE_JAPANESE
#define INFOWIN_SEL_WIDTH 4
#define INFOWIN_LINK_X 14
#define INFOWIN_LINK_WIDTH 4
#elif LANGUAGE == LANGUAGE_SPANISH
#define INFOWIN_SEL_WIDTH 3
#define INFOWIN_LINK_X 13
#define INFOWIN_LINK_WIDTH 5
#else
#define INFOWIN_SEL_WIDTH 3
#define INFOWIN_LINK_X 13
#define INFOWIN_LINK_WIDTH 6
#endif
#include "net_types.h"

#include "gf_standard_types.h"

typedef struct {
    u16 paletteBits;
    u16 wait     : 6;
    u16 current    : 5;
    u16 end    : 5;
    u16 color : 15;
    u16 direction   : 1;
    u16 speed   : 5;
    u16 waitCount   : 6;
    u16 pad    : 5;
} PaletteFadeParam;

typedef struct {
    u16 *defaultWork;
    u16 *transWork;
    u32 size;
    PaletteFadeParam param;
} PaletteFadeWork;

typedef struct {
    PaletteFadeWork work[14];
    u16 requestFlag : 2;
    u16 requestBits  : 14;
    u16 transBits : 14;
    u16 taskActive  : 1;
    u16 autoTrans : 1;
    u8  forceStop;
} PaletteFade;

struct InfoWin {
    u32 charBase;
    u16 redrawFlags;
    u8  bgFrame;
    u8  palette;
    u8  blinkCount;
    u8  unusedByte;
    u8  unusedBytes[2];
    struct WifiList *wifiConfig;
    u32 wifiMode;
    u32 colonBlink;
    u32 isPm;
    u8  minute;
    u8  hour;
    u8  frameCount;
    u8  batteryLevel;
    u32 linkActive;
    void *task;
};

struct Sel6 { u8 v[6]; };

struct Ofs6 { u16 v[6]; };

struct InfoWinDrawBuffer {
    u16 scr[4];     /* +0x00 */
    struct Sel6 sel; /* +0x08 */
    u16 col[2];     /* +0x0E */
#if LANGUAGE == LANGUAGE_JAPANESE
    u16 ap[4];      /* 12-hour clock marker */
#endif
    struct Ofs6 ofs; /* +0x12 */
    u16 clk[10];    /* +0x1E */
};
struct TcbSystem;
struct TcbTask;

struct TcbTask;
#include "tcb_list.h"
#include "gfl_use.h"
#include "gfl_heap_wrap.h"
#include "mi_memory.h"
#include "ui.h"
struct GameData;
struct FieldState;
#include "game_data.h"
struct GameData;
#include "net.h"
#include "wih_dwc.h"
#include "game_beacon.h"
/* Original DS prototype: the caller passes the tile arguments as words; the host build uses the header. */
#ifdef __MWERKS__
#define BG_SYS_SetTileEntry BG_SYS_SetTileEntry_header
#endif
#include "bg_sys.h"
#ifdef __MWERKS__
#undef BG_SYS_SetTileEntry
extern void BG_SYS_SetTileEntry(u32 a, u16 b, u32 c, u32 d, u32 e, u32 f, u32 g);
#endif
#include "arc_tool.h"
#include "arc_util.h"
#include "gf_standard.h"
#include "os_emulator.h"
void INFOWIN_Init(u8 bgFrame, u8 palette, void *gameData, u16 heap);
void INFOWIN_Update(void);
int INFOWIN_Exit(void);
void INFOWIN_DrawTask(struct TcbTask *task, void *work);
void INFOWIN_WriteScreen(u32 base, u32 blk, u8 x, u8 y, u8 w, u8 h);
void INFOWIN_LoadCharacters(int tile, const void *src, int count);
void INFOWIN_LoadGraphics(u32 a, u32 b, u16 c);
void INFOWIN_UpdateClock(void);

extern struct InfoWin *gInfoWin;
extern const char infowin_File[];
extern const u16 d_0209F834[];
extern const u32 d_0209F840[];
extern const u16 d_0209F848[];
extern const u16 d_0209F852[][2];
extern const u32 d_0209F838[];
extern const struct Ofs6 d_0209F870;
extern const struct Sel6 d_0209F868;
extern const u16 d_0209F830[];

/*
 * note:     infowin constructor.  The heap id is u16: as u32 mwcc reuses r3
 *           for the allocator call instead of reloading the spilled home
 *           (17 bytes).  Found by tools/permuter.py --types.
 */
void INFOWIN_Init(u8 bgFrame, u8 palette, void *gameData, u16 heap)
{
    gInfoWin = GFL_HEAP_Alloc(heap, sizeof(*gInfoWin), 0, infowin_File, PM_SRC_LINE(0x103, 0x103 - 54));
    MI_CpuFill8(gInfoWin, 0, sizeof(*gInfoWin));
    gInfoWin->bgFrame = bgFrame;
    gInfoWin->palette = palette;
    INFOWIN_LoadGraphics(bgFrame, palette, heap);
    gInfoWin->task = GFL_USE_AddMainTask(INFOWIN_DrawTask, gInfoWin, 1);
    gInfoWin->linkActive = 0;
    gInfoWin->batteryLevel = UI_GetPowerState();
    if (gameData != 0) {
        gInfoWin->wifiConfig = GAME_DATA_GetWifiList(gameData);
        gInfoWin->wifiMode = GAME_DATA_IsConfigFlagSet(gameData);
    } else {
        gInfoWin->wifiConfig = 0;
        gInfoWin->wifiMode = 0;
    }
    gInfoWin->blinkCount = 0;
    INFOWIN_Update();
    gInfoWin->redrawFlags = 0x3f;
}

/*
 * note:     infowin per-frame state poll (the TCB-less update): clock tick,
 *           link/wireless state, then the dirty bits of +0x04.  Two shape
 *           facts carry the whole match: every flag update is spelled out
 *           (`f = (u16)(f | X)`, which reuses the tested load; `|=` re-reads
 *           it), and every clear mask is the u16 constant (the pool holds
 *           0x0000EFFF, not ~0x1000).
 */
void INFOWIN_Update(void)
{
    int flag = 0;
    u8 n = 0;
    GFLNetSession *link = 0;
    u32 bits;
    int idx;

    if (gInfoWin == 0)
        return;

    INFOWIN_UpdateClock();
    gInfoWin->frameCount++;
    if (gInfoWin->frameCount > 60) {
        u8 v = UI_GetPowerState();
        if (gInfoWin->batteryLevel != v) {
            gInfoWin->batteryLevel = v;
            gInfoWin->redrawFlags = (u16)(gInfoWin->redrawFlags | 0x20);
        }
        gInfoWin->frameCount = 0;
    }

    if (GFL_NET_GetRunState() == 1) {
        link = GFL_NET_GetInitParam();
        n = GFL_NET_GetNegotiationNum();
        if (GFL_NET_IsNetTypeWifi() == 1)
            flag = 1;
    }

    if (n < 2 && flag == 0) {
        bits = WIH_DWC_PollStatus(gInfoWin->wifiConfig);
        idx = 0;
        if (gInfoWin->wifiMode == 1 && GAME_BEACON_GetNextNewLogIndex(&idx) != 0x1E) {
            gInfoWin->redrawFlags = (u16)(gInfoWin->redrawFlags | 0x10);
            gInfoWin->redrawFlags = (u16)(gInfoWin->redrawFlags | 0x1000);
        } else {
            gInfoWin->redrawFlags = (u16)(gInfoWin->redrawFlags | 0x10);
            gInfoWin->redrawFlags = (u16)(gInfoWin->redrawFlags & 0xEFFF);
        }
        if (!(bits & 2)) {
            if (((gInfoWin->redrawFlags & 0x200) ? 1 : 0) == 1) {
                gInfoWin->redrawFlags = (u16)(gInfoWin->redrawFlags | 4);
                gInfoWin->redrawFlags = (u16)(gInfoWin->redrawFlags & 0xFDFF);
            }
        }
        if (bits & 0x3C) {
            if (bits & 0xC) {
                gInfoWin->redrawFlags = (u16)(gInfoWin->redrawFlags | 0x10);
                gInfoWin->redrawFlags = (u16)(gInfoWin->redrawFlags | 0x400);
                gInfoWin->redrawFlags = (u16)(gInfoWin->redrawFlags | 0x800);
            } else if (((gInfoWin->redrawFlags & 0x400) ? 1 : 0) == 0) {
                gInfoWin->blinkCount = 0;
                gInfoWin->redrawFlags = (u16)(gInfoWin->redrawFlags & 0xF7FF);
                gInfoWin->redrawFlags = (u16)(gInfoWin->redrawFlags | 0x10);
                gInfoWin->redrawFlags = (u16)(gInfoWin->redrawFlags | 0x400);
            }
        } else if (((gInfoWin->redrawFlags & 0x400) ? 1 : 0) == 1) {
            gInfoWin->blinkCount = 0;
            gInfoWin->redrawFlags = (u16)(gInfoWin->redrawFlags | 0x10);
            gInfoWin->redrawFlags = (u16)(gInfoWin->redrawFlags & 0xFBFF);
            gInfoWin->redrawFlags = (u16)(gInfoWin->redrawFlags & 0xF7FF);
        }
        if (bits & 0x3C0) {
            if (gInfoWin->linkActive == 0) {
                gInfoWin->redrawFlags = (u16)(gInfoWin->redrawFlags | 8);
                gInfoWin->linkActive = 1;
            }
        } else if (gInfoWin->linkActive != 0) {
            gInfoWin->redrawFlags = (u16)(gInfoWin->redrawFlags | 8);
            gInfoWin->linkActive = 0;
        }
    } else if (link != 0) {
        if (link->init.bNetType == 3) {
            if (((gInfoWin->redrawFlags & 0x200) ? 1 : 0) == 0) {
                gInfoWin->redrawFlags = (u16)(gInfoWin->redrawFlags | 4);
                gInfoWin->redrawFlags = (u16)(gInfoWin->redrawFlags | 0x200);
            }
        } else if (((gInfoWin->redrawFlags & 0x200) ? 1 : 0) == 1) {
            gInfoWin->redrawFlags = (u16)(gInfoWin->redrawFlags | 4);
            gInfoWin->redrawFlags = (u16)(gInfoWin->redrawFlags & 0xFDFF);
        }
        if (link->init.bNetType == 0 || link->init.bNetType == 4 || link->init.bNetType == 5) {
            if (((gInfoWin->redrawFlags & 0x400) ? 1 : 0) == 0) {
                gInfoWin->redrawFlags = (u16)(gInfoWin->redrawFlags | 0x10);
                gInfoWin->redrawFlags = (u16)(gInfoWin->redrawFlags | 0x400);
                gInfoWin->redrawFlags = (u16)(gInfoWin->redrawFlags & 0xF7FF);
                gInfoWin->blinkCount = 0;
            }
            if (link->init.gameKind == 2) {
                gInfoWin->redrawFlags = (u16)(gInfoWin->redrawFlags | 0x10);
                gInfoWin->redrawFlags = (u16)(gInfoWin->redrawFlags | 0x400);
                gInfoWin->redrawFlags = (u16)(gInfoWin->redrawFlags | 0x800);
            }
        } else if (((gInfoWin->redrawFlags & 0x400) ? 1 : 0) == 1) {
            gInfoWin->redrawFlags = (u16)(gInfoWin->redrawFlags | 0x10);
            gInfoWin->redrawFlags = (u16)(gInfoWin->redrawFlags & 0xFBFF);
            gInfoWin->redrawFlags = (u16)(gInfoWin->redrawFlags & 0xF7FF);
            gInfoWin->blinkCount = 0;
        }
        if (link->init.bNetType == 1 || link->init.bNetType == 2 || link->init.bNetType == 6) {
            if (gInfoWin->linkActive == 0) {
                gInfoWin->redrawFlags = (u16)(gInfoWin->redrawFlags | 8);
                gInfoWin->linkActive = 1;
            }
        } else if (gInfoWin->linkActive != 0) {
            gInfoWin->redrawFlags = (u16)(gInfoWin->redrawFlags | 8);
            gInfoWin->linkActive = 0;
        }
    }
}

int INFOWIN_Exit(void)
{
    if (gInfoWin != 0) {
        TCB_DeleteTask(gInfoWin->task);
        BG_SYS_FreeTileRun(gInfoWin->bgFrame, gInfoWin->charBase, 1 << 12);
        GFL_HEAP_Free(gInfoWin);
        gInfoWin = 0;
        return 0;
    } else {
        return (sptr)gInfoWin;
    }
}

/*
 * note:     infowin redraw task (the TCB callback INFOWIN_Init registers):
 *           clock digits, battery/link/wireless icons, per dirty bit of
 *           +0x04.  Levers, in the order they closed it: tens use `/ 10`
 *           and ones `% 10` (the remainder comes back in r1); every access
 *           goes through the global (reloaded at each join); the two
 *           six-entry tables are struct copies (local initialised arrays);
 *           `k = (c) ? a : b` for all three tile selectors; the draw call
 *           in each arm of block 0x10; `done = 1` after the block-0 draw.
 */
void INFOWIN_DrawTask(struct TcbTask *task, void *work)
{
    struct InfoWinDrawBuffer buf;
    int done;
    int k;

    done = 0;
    if (gInfoWin == 0)
        return;

    if (gInfoWin->redrawFlags & 1) {
        if (gInfoWin->hour < 10) {
            buf.clk[0] = gInfoWin->charBase + ((gInfoWin->palette << 12) + 0xF);
            buf.clk[5] = gInfoWin->charBase + ((gInfoWin->palette << 12) + 0x1F);
        } else {
            buf.clk[0] = gInfoWin->charBase + ((gInfoWin->palette << 12) + (gInfoWin->hour / 10 + 1));
            buf.clk[5] = buf.clk[0] + 0x10;
        }
        buf.clk[1] = gInfoWin->charBase + ((gInfoWin->palette << 12) + (gInfoWin->hour % 10 + 1));
        k = (gInfoWin->colonBlink != 0) ? 11 : 15;
        buf.clk[2] = gInfoWin->charBase + ((gInfoWin->palette << 12) + k);
        buf.clk[3] = gInfoWin->charBase + ((gInfoWin->palette << 12) + (gInfoWin->minute / 10 + 1));
        buf.clk[4] = gInfoWin->charBase + ((gInfoWin->palette << 12) + (gInfoWin->minute % 10 + 1));
        buf.clk[6] = buf.clk[1] + 0x10;
        k = (gInfoWin->colonBlink != 0) ? 27 : 31;
        buf.clk[7] = gInfoWin->charBase + ((gInfoWin->palette << 12) + k);
        buf.clk[8] = buf.clk[3] + 0x10;
        buf.clk[9] = buf.clk[4] + 0x10;
        BG_SYS_DrawTileEx(gInfoWin->bgFrame, 1, 0, 5, 2, (void *)buf.clk, 0, 0, 5, 2);
#if LANGUAGE == LANGUAGE_JAPANESE
        if (gInfoWin->isPm == 1) {
            buf.ap[0] = ((gInfoWin->palette << 12) + 0xD) + gInfoWin->charBase;
            buf.ap[2] = ((gInfoWin->palette << 12) + 0x1D) + gInfoWin->charBase;
        } else {
            buf.ap[0] = ((gInfoWin->palette << 12) + 0xC) + gInfoWin->charBase;
            buf.ap[2] = ((gInfoWin->palette << 12) + 0x1C) + gInfoWin->charBase;
        }
        buf.ap[1] = ((gInfoWin->palette << 12) + 0xE) + gInfoWin->charBase;
        buf.ap[3] = ((gInfoWin->palette << 12) + 0x1E) + gInfoWin->charBase;
        BG_SYS_DrawTileEx(gInfoWin->bgFrame, 6, 0, 2, 2, (void *)buf.ap, 0, 0, 2, 2);
#endif
        done = 1;
        gInfoWin->redrawFlags = gInfoWin->redrawFlags - 1;
    }

    if (gInfoWin->redrawFlags & 4) {
        u8 sel = (gInfoWin->redrawFlags & 0x200) ? 1 : 0;
        INFOWIN_WriteScreen(d_0209F834[sel], gInfoWin->palette, 9, 0, INFOWIN_SEL_WIDTH, 2);
        INFOWIN_LoadCharacters(6, &d_0209F840[sel], 2);
        done = 1;
        gInfoWin->redrawFlags = gInfoWin->redrawFlags - 4;
    }

    if (gInfoWin->redrawFlags & 8) {
        INFOWIN_WriteScreen(d_0209F848[gInfoWin->linkActive], gInfoWin->palette, INFOWIN_LINK_X, 0, INFOWIN_LINK_WIDTH, 2);
        INFOWIN_LoadCharacters(8, d_0209F852[gInfoWin->linkActive], 2);
        done = 1;
        gInfoWin->redrawFlags = gInfoWin->redrawFlags - 8;
    }

    if (gInfoWin->redrawFlags & 0x10) {
        INFOWIN_WriteScreen(0x20, gInfoWin->palette, 0x13, 0, 7, 2);
        if (gInfoWin->redrawFlags & 0x800) {
            u8 t;
            u8 ph;
            if (UI_GetFrameRate() == 0x1E)
                gInfoWin->blinkCount = gInfoWin->blinkCount + 2;
            else
                gInfoWin->blinkCount = gInfoWin->blinkCount + 1;
            if (gInfoWin->blinkCount >= 0x50)
                gInfoWin->blinkCount = 0;
            t = gInfoWin->blinkCount / 16;
            ph = gInfoWin->blinkCount % 16;
            if (t < 4) {
                int d;
                u8 c;
                d = ph - 8;
                if (d < 0)
                    d = -d;
                ph = 8 - d;
                c = ph * 13 / 8 + 6;
                buf.col[0] = (c << 5) | c | (c << 10);
                c = ph * 22 / 8 + 9;
                buf.col[1] = (c << 5) | c | (c << 10);
                INFOWIN_LoadCharacters(10, buf.col, 2);
            } else {
                INFOWIN_LoadCharacters(10, &d_0209F838[0], 2);
            }
        } else {
            u8 sel = (gInfoWin->redrawFlags & 0x1400) ? 1 : 0;
            INFOWIN_LoadCharacters(10, &d_0209F838[sel], 2);
        }
        done = 1;
        gInfoWin->redrawFlags = gInfoWin->redrawFlags - 0x10;
    }

    if (gInfoWin->redrawFlags & 0x20) {
        u8 *sp8 = buf.sel.v;
        buf.ofs = d_0209F870;
        buf.sel = d_0209F868;
        if (OS_IsRunOnTwl()) {
            k = sp8[gInfoWin->batteryLevel];
        } else {
            k = (gInfoWin->batteryLevel == 5) ? 5 : 4;
        }
        buf.scr[0] = gInfoWin->charBase + ((gInfoWin->palette << 12) + buf.ofs.v[k]);
        buf.scr[2] = buf.scr[0] + 0x10;
        buf.scr[1] = buf.scr[0] + 0x400;
        buf.scr[3] = buf.scr[2] + 0x400;
        BG_SYS_DrawTileEx(gInfoWin->bgFrame, 0x1C, 0, 2, 2, (void *)buf.scr, 0, 0, 2, 2);
        INFOWIN_LoadCharacters(13, d_0209F830, 1);
        done = 1;
        gInfoWin->redrawFlags = gInfoWin->redrawFlags - 0x20;
    }

    if (done == 1)
        BG_SYS_PushTile(gInfoWin->bgFrame);
}

/*
 * note:     infowin tile-rect writer: fills a w*h u16 screen buffer with
 *           charbase + base + (pal << 12) + i + j*16 and hands it to
 *           BG_SYS_DrawTileEx.  x/y/w/h are u8 (the callee takes u8 w/h);
 *           `j * 16`, not `j << 4`, fixes the adds operand order.
 */
void INFOWIN_WriteScreen(u32 base, u32 blk, u8 x, u8 y, u8 w, u8 h)
{
    u16 buf[14];
    u8 i;
    u8 j;
    u32 p;
    struct InfoWin *q;

    i = 0;
    if (i < w) {
        p = base + (blk << 12);
        q = gInfoWin;
        do {
            for (j = 0; j < h; j++) {
                buf[j * w + i] = (u16)(q->charBase + (i + p + j * 16));
            }
            i++;
        } while (i < w);
    }
    BG_SYS_DrawTileEx(gInfoWin->bgFrame, x, y, w, h, (void *)buf, 0, 0, w, h);
}

void INFOWIN_LoadCharacters(int tile, const void *src, int count)
{
    BG_SYS_LoadPltt(gInfoWin->bgFrame, (void *)src, count * 2, (tile + (gInfoWin->palette << 4)) * 2);
}

void INFOWIN_LoadGraphics(u32 a, u32 b, u16 c)
{
    void *env;
    u32 sel = 0;

    if (a > 3) {
        sel = 4;
    }

    env = ARC_TOOL_CreateHandle(0x32, c);
    gInfoWin->charBase = BG_SYS_CreateRun(a, 1 << 12, 1);
    ARC_UTIL_UploadPaletteFromHandleWhole(env, 0, sel, b << 5, 0x20, c);
    ARC_UTIL_UploadBgCharFromHandle(env, 1, a, gInfoWin->charBase, 0, 0, c);
    ARC_TOOL_DeleteHandle(env);
    BG_SYS_SetTileEntry(a, (u16)(gInfoWin->charBase + 0xf), 0, 0, 0x20, 1, b);
    BG_SYS_SetTileEntry(a, (u16)(gInfoWin->charBase + 0x1f), 0, 1, 0x20, 1, b);
    BG_SYS_PushTile(a);
}

void INFOWIN_UpdateClock(void)
{
    RTCTime time;
    u32 v;

    GF_STANDARD_GetCachedTime(&time);
    v = time.second & 1;

    if (time.hour != gInfoWin->hour) {
        gInfoWin->hour = time.hour;
        if (gInfoWin->hour >= 0xc) {
#if LANGUAGE == LANGUAGE_JAPANESE
            gInfoWin->hour -= 0xc;
#endif
            gInfoWin->isPm = 1;
        } else {
            gInfoWin->isPm = 0;
        }
        gInfoWin->redrawFlags |= 1;
    }

    if (time.minute != gInfoWin->minute) {
        gInfoWin->minute = time.minute;
        gInfoWin->redrawFlags |= 1;
    }

    if (v != gInfoWin->colonBlink) {
        gInfoWin->colonBlink = v;
        gInfoWin->redrawFlags |= 1;
    }
}
