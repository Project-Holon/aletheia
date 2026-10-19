/*
 * file:     idle_screen.c
 * unit:     yes
 * function: IDLE_SCREEN_Run
 * address:  0x021BB8E0
 * region:   ov109
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * ov109: a stand-alone screen that nothing in the image loads. IDLE_SCREEN_Run
 * creates the BG system on heap 1, sets the VRAM banks and the two-screen
 * graphics mode, clears the main BG, sub BG, main OBJ and sub OBJ VRAM,
 * initialises BG layers 2, 3 (main) and 6, 7 (sub) from sTemplates, uploads the
 * graphics of archive 0x16 (character data and palette for BG frame 2, plus a 0x100 byte
 * whole palette), starts a fade-in on both screens and then spins forever on
 * UI_Update, FADE_Update and a VBlank wait. It never returns, so the
 * function has no epilogue.
 *
 * The overlay holds one function and three tables: the display config, the
 * VRAM bank config and four BG layer templates. Its static-initialiser list
 * is the empty terminator word at 0x021BBB0C; the rest up to 0x021BBB20 is
 * the 32 byte alignment padding.
 *
 * symbols:
 *   BG_SYS_Create  0x0203F8F4  arm
 *   BG_SYS_SetVramBanks  0x020433E0  arm
 *   MIi_CpuClear32  0x02082A7C  arm
 *   BG_SYS_SetGraphicsMode  0x0203FC28  arm
 *   BG_SYS_InitBgLayer  0x0203FCA0  arm
 *   BG_SYS_ClearSlot  0x020414EC  arm
 *   BG_SYS_SetMainPlaneVisible  0x020434DC  arm
 *   ARC_UTIL_UploadBgCharFromArchive  0x02049624  arm
 *   ARC_UTIL_UploadBgPaletteFromArchive  0x0204989C  arm
 *   ARC_UTIL_UploadPaletteFromArchiveWhole  0x02049B40  arm
 *   BG_SYS_ResetSubDisplay  0x0204361C  arm
 *   BG_SYS_SetLcdSwap  0x0204363C  arm
 *   FADE_Start  0x0204E720  arm
 *   UI_Update  0x02034F5C  arm
 *   FADE_Update  0x0204E638  arm
 *   OS_WaitIrq  0x0208459C  arm
 *   sDispConfig  0x021BBA4C  data  a4
 *   sVramBanks  0x021BBA5C  data  a4
 *   sTemplates  0x021BBA8C  data  a4
 */

#include "../types.h"

struct DispConfig {
    u32 dispMode;
    u32 bgMode;
    u32 subBgMode;
    u32 bg0As;
};

struct DispVram {
    u32 mainBg;
    u32 mainBgExtPltt;
    u32 subBg;
    u32 subBgExtPltt;
    u32 mainObj;
    u32 mainObjExtPltt;
    u32 subObj;
    u32 subObjExtPltt;
    u32 teximage;
    u32 texpltt;
    u32 mainMapping;
    u32 subMapping;
};

struct BgTemplate {
    u32 scrollX;
    u32 scrollY;
    u32 bufSize;
    u32 baseTile;
    unsigned char screenSize;
    unsigned char colorMode;
    unsigned char screenBase;
    unsigned char charBase;
    u32 tileDataSize;
    unsigned char extPltt;
    unsigned char priority;
    unsigned char areaOver;
    unsigned char pad_1b;
    u32 mosaic;
};

struct BgTemplateSet {
    struct BgTemplate layer[4];
};

extern void BG_SYS_Create(unsigned short heapId);
extern void BG_SYS_SetVramBanks(const struct DispVram *banks);
extern void MIi_CpuClear32(u32 value, void *dst, u32 size);
extern void BG_SYS_SetGraphicsMode(struct DispConfig *cfg);
extern void BG_SYS_InitBgLayer(u32 bgId, const struct BgTemplate *tmpl, u32 type);
extern void BG_SYS_ClearSlot(u32 i);
extern void BG_SYS_SetMainPlaneVisible(u32 mask, u32 enable);
extern unsigned int ARC_UTIL_UploadBgCharFromArchive(void *archiveID, void *memberIdx, void *bgId, void *tileOffset, unsigned int size, unsigned int heapID, unsigned short allocFlags);
extern void ARC_UTIL_UploadBgPaletteFromArchive(unsigned int archiveID, unsigned int memberIdx, unsigned int channel, unsigned int offset, unsigned int size, unsigned int heapID, unsigned short flags);
extern void ARC_UTIL_UploadPaletteFromArchiveWhole(unsigned int archiveID, unsigned int memberIdx, unsigned int kind, unsigned int dest, unsigned int size, unsigned short flags);
extern void BG_SYS_ResetSubDisplay(void);
extern void BG_SYS_SetLcdSwap(u32 swap);
extern void FADE_Start(unsigned int a, int b, int c, int d);
extern void UI_Update(void);
extern void FADE_Update(void);
extern void OS_WaitIrq(int clear, unsigned int irqFlags);

static const struct DispConfig sDispConfig = { 1, 0, 0, 0 };

static const struct DispVram sVramBanks = {
    0x1, 0, 0x4, 0, 0x10, 0, 0x100, 0, 0x2, 0x20, 0x100010, 0x10
};

static const struct BgTemplateSet sTemplates = {
    {
        { 0, 0, 0x2000, 0, 4, 0, 0, 2, 0x8000, 0, 0, 0, 0, 0 },
        { 0, 0, 0x2000, 0, 4, 0, 4, 4, 0x8000, 0, 0, 0, 0, 0 },
        { 0, 0, 0x800, 0, 1, 0, 0, 1, 0x8000, 0, 0, 0, 0, 0 },
        { 0, 0, 0x800, 0, 1, 0, 1, 2, 0x8000, 0, 0, 0, 0, 0 },
    }
};

void IDLE_SCREEN_Run(void)
{
    struct DispVram vramBanks;
    struct DispConfig dispConfig;
    struct BgTemplateSet templates;

    BG_SYS_Create(1);
    vramBanks = sVramBanks;
    BG_SYS_SetVramBanks(&vramBanks);
    MIi_CpuClear32(0, (void *)0x06000000, 0x80000);
    MIi_CpuClear32(0, (void *)0x06200000, 0x20000);
    MIi_CpuClear32(0, (void *)0x06400000, 0x40000);
    MIi_CpuClear32(0, (void *)0x06600000, 0x20000);
    dispConfig = sDispConfig;
    BG_SYS_SetGraphicsMode(&dispConfig);
    templates = sTemplates;
    BG_SYS_InitBgLayer(2, &templates.layer[0], 0);
    BG_SYS_ClearSlot(2);
    BG_SYS_InitBgLayer(3, &templates.layer[1], 0);
    BG_SYS_ClearSlot(3);
    BG_SYS_InitBgLayer(6, &templates.layer[2], 0);
    BG_SYS_ClearSlot(6);
    BG_SYS_InitBgLayer(7, &templates.layer[3], 0);
    BG_SYS_ClearSlot(7);
    BG_SYS_SetMainPlaneVisible(1, 0);
    BG_SYS_SetMainPlaneVisible(2, 0);
    BG_SYS_SetMainPlaneVisible(8, 0);
    BG_SYS_SetMainPlaneVisible(4, 1);
    *(vu32 *)0x04000000 = (*(vu32 *)0x04000000 & 0xFFCFFFEF) | 0x10;
    *(vu32 *)0x04001000 = (*(vu32 *)0x04001000 & 0xFFCFFFEF) | 0x10;
    ARC_UTIL_UploadBgCharFromArchive((void *)0x16, (void *)1, (void *)2, 0, 0, 0, 1);
    ARC_UTIL_UploadBgPaletteFromArchive(0x16, 2, 2, 0, 0, 0, 1);
    ARC_UTIL_UploadPaletteFromArchiveWhole(0x16, 0, 0, 0, 0x100, 1);
    BG_SYS_ResetSubDisplay();
    BG_SYS_SetLcdSwap(0);
    FADE_Start(0xC, 0x10, 0, 2);
    for (;;) {
        UI_Update();
        FADE_Update();
        OS_WaitIrq(1, 1);
    }
}
