/*
 * function: ERROR_SCREEN_LoadBackground
 * address:  0x021B6298
 * packet:   pkt_ov017_021B6298
 * region:   ov017
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Loads a background from archive 0x16: clears 0x4000 bytes of character
 * VRAM, then unpacks file 1 (characters), file 2 (screen) and file 0
 * (palette, 0x20 bytes to 0x05000000), flushing and copying each and
 * freeing the file buffer after each.
 *
 * The copy goes through an inline wrapper (or a dst local): a plain
 * call argument f(src, g(), p->size) loads the size after g(); the
 * original loads it before g() and keeps it in r5.
 *
 * symbols:
 *   G2_GetBG1CharPtr  0x0207E24C  arm
 *   MIi_CpuClear32  0x02082A7C  arm
 *   ARC_UTIL_LoadMember  0x0204A1BC  arm
 *   NNS_G2dGetUnpackedCharacterDataEx  0x02062A4C  arm
 *   DWCi_ScreenDC_FlushRange  0x020862F0  arm
 *   MIi_CpuCopy16  0x02082A60  arm
 *   func_020307B0  0x020307B0  arm
 *   NNS_G2dGetUnpackedScreenData  0x02062B30  arm
 *   G2_GetBG1ScrPtr  0x0207DFB4  arm
 *   NNS_G2dGetUnpackedPaletteCompressInfo  0x02062AD4  arm
 *   NNS_G2dGetUnpackedPaletteData  0x02062A98  arm
 */

typedef unsigned char u8;
typedef unsigned int u32;

typedef struct Chr {
    u8 pad00[0x10];
    u32 f10;
    void *f14;
} Chr;

typedef struct Scr {
    u8 pad00[0x8];
    u32 f08;
    u8 f0c[1];
} Scr;

typedef struct Pal {
    u8 pad00[0xc];
    void *f0c;
} Pal;

extern void *G2_GetBG1CharPtr(void);
extern void MIi_CpuClear32(u32 v, void *dst, u32 size);
extern int ARC_UTIL_LoadMember(int a0, int a1, int a2, int a3);
struct NitroFileHeader;
extern signed int NNS_G2dGetUnpackedCharacterDataEx(struct NitroFileHeader *file, void **out);
extern void DWCi_ScreenDC_FlushRange(void *p, u32 size);
extern void MIi_CpuCopy16(void *src, void *dst, u32 size);
extern u32 func_020307B0(void *p);
extern int NNS_G2dGetUnpackedScreenData(void *file, void **out);
extern void *G2_GetBG1ScrPtr(void);
typedef signed int     s32;
struct NitroFileHeader;
extern s32 NNS_G2dGetUnpackedPaletteCompressInfo(struct NitroFileHeader *file, void **out);
extern s32 NNS_G2dGetUnpackedPaletteData(struct NitroFileHeader *file, void **out);

static inline void Copy(void *src, void *dst, u32 size)
{
    MIi_CpuCopy16(src, dst, size);
}

void ERROR_SCREEN_LoadBackground(void)
{
    Chr *chr;
    Scr *scr;
    Pal *pal;
    void *cmp;
    void *file;

    MIi_CpuClear32(0, G2_GetBG1CharPtr(), 0x4000);

    file = (void *)ARC_UTIL_LoadMember(0x16, 1, 0, 1);
    if (NNS_G2dGetUnpackedCharacterDataEx(file, (void **)(&chr))) {
        DWCi_ScreenDC_FlushRange(chr->f14, chr->f10);
        Copy(chr->f14, G2_GetBG1CharPtr(), chr->f10);
    }
    func_020307B0(file);

    file = (void *)ARC_UTIL_LoadMember(0x16, 2, 0, 1);
    if (NNS_G2dGetUnpackedScreenData(file, (void **)(&scr))) {
        DWCi_ScreenDC_FlushRange(scr->f0c, scr->f08);
        Copy(scr->f0c, G2_GetBG1ScrPtr(), scr->f08);
    }
    func_020307B0(file);

    file = (void *)ARC_UTIL_LoadMember(0x16, 0, 0, 1);
    NNS_G2dGetUnpackedPaletteCompressInfo(file, &cmp);
    if (NNS_G2dGetUnpackedPaletteData(file, (void **)(&pal))) {
        DWCi_ScreenDC_FlushRange(pal->f0c, 0x20);
        Copy(pal->f0c, (void *)0x05000000, 0x20);
    }
    func_020307B0(file);
}
