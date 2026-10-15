/*
 * function: VIEWER_MAIN_LoadBgResources
 * address:  0x021C453C
 * packet:   pkt_ov111_021C453C
 * region:   ov111
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   VIEWER_MAIN_SetupBgSlot  0x021C436C  thumb  ov111
 *   VIEWER_MAIN_ClearBgSlot  0x021C43C4  thumb  ov111
 *   VIEWER_MAIN_UploadBg  0x021C58E0  thumb  ov111
 *   VIEWER_MAIN_CopyBg3  0x021C5958  thumb  ov111
 *   VIEWER_MAIN_GetBgParamA  0x021C4524  thumb  ov111
 *   VIEWER_MAIN_GetBgParamB  0x021C4530  thumb  ov111
 *   ARC_UTIL_LoadBgCharDataFromArchive  0x02049DB4  arm
 *   ARC_UTIL_LoadPaletteDataFromArchive  0x02049EB4  arm
 *   ARC_UTIL_UploadBgCharFromArchive  0x02049624  arm
 *   func_0204989C  0x0204989C  arm
 *   func_02049B40  0x02049B40  arm
 *   APP_ICON_GetArchiveId  0x020275E4  thumb
 *   APP_ICON_GetStatusFrameFileId  0x02027628  thumb
 *   APP_ICON_GetStatusDataFileId  0x0202762C  thumb
 *   BG_SYS_FillTileMap  0x020413B0  arm
 *   BG_SYS_PushTile  0x020409B4  arm
 *   d_021C86E8     0x021C86E8  data  a4
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    u8 kind;
    u8 pad1[2];
    u8 b3;
    u8 f4_0 : 1;
    u8 f4_1 : 1;
    u8 f4_2 : 1;
    u8 f4_3 : 1;
    u8 f4_4 : 1;
    u8 f4_5 : 1;
    u8 f4_6 : 1;
    u8 f4_7 : 1;
    u8 pad5;
    u8 b6;
    u8 pad7[0x74 - 7];
    u8 bitmap[1];
} Info;

typedef struct {
    u16 heap;
    u8 pad2[0x28 - 2];
    Info *info;
    u8 pix[0x302C - 0x2C];
    void *f302C;
    void *f3030;
    u8 pad3034[0x31D8 - 0x3034];
    void *f31D8;
    void *f31DC;
} Work;

extern void VIEWER_MAIN_SetupBgSlot(Work *p, int k, int alt);
extern void VIEWER_MAIN_ClearBgSlot(Work *p, int k);
extern void VIEWER_MAIN_UploadBg(Work *p);
extern void VIEWER_MAIN_CopyBg3(const u8 *src, u8 *dst);
extern int VIEWER_MAIN_GetBgParamA(int x);
extern int VIEWER_MAIN_GetBgParamB(int x);
extern void *ARC_UTIL_LoadBgCharDataFromArchive(u32 a0, u32 a1, u32 a2, u32 a3, u16 a4);
extern void *ARC_UTIL_LoadPaletteDataFromArchive(u32 a0, u32 a1, u32 a2, u32 a3, u16 a4);
extern u32 ARC_UTIL_UploadBgCharFromArchive(void *a0, void *a1, void *a2, void *a3, u32 a4, u32 a5, u16 a6);
extern void func_0204989C(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u16 flags);
extern void func_02049B40(u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern u32 APP_ICON_GetArchiveId(void);
extern u32 APP_ICON_GetStatusFrameFileId(void);
extern u32 APP_ICON_GetStatusDataFileId(void);
extern void BG_SYS_FillTileMap(u8 index, u8 x0, u8 y0, u8 w, u8 h, u8 pal);
extern void BG_SYS_PushTile(u32 layer);
extern const u32 d_021C86E8[][2];

void VIEWER_MAIN_LoadBgResources(Work *p)
{
    VIEWER_MAIN_SetupBgSlot(p, p->info->b3, p->info->f4_2);
    if (p->info->f4_7 == 0) {
        p->f302C = ARC_UTIL_LoadBgCharDataFromArchive(0x28, 0x1F, 0, (u32)(&p->f3030), p->heap);
        if (p->info->f4_1 == 0) {
            p->f31D8 = ARC_UTIL_LoadPaletteDataFromArchive(0x28, 0x2B, 0, (u32)(&p->f31DC), p->heap);
        } else {
            p->f31D8 = ARC_UTIL_LoadPaletteDataFromArchive(0x28, 0x2C, 0, (u32)(&p->f31DC), p->heap);
        }
    } else {
        p->f302C = ARC_UTIL_LoadBgCharDataFromArchive(0x29, d_021C86E8[p->info->b6][0], 0, (u32)(&p->f3030), p->heap);
        p->f31D8 = ARC_UTIL_LoadPaletteDataFromArchive(0x29, 0x20, 0, (u32)(&p->f31DC), p->heap);
        VIEWER_MAIN_ClearBgSlot(p, p->info->b6);
    }
    VIEWER_MAIN_UploadBg(p);
    ARC_UTIL_UploadBgCharFromArchive((void *)0x28, (void *)VIEWER_MAIN_GetBgParamA(p->info->kind), (void *)6, 0, 0, 0, p->heap);
    func_0204989C(0x28, VIEWER_MAIN_GetBgParamB(p->info->kind), 6, 0, 0, 0, p->heap);
    ARC_UTIL_UploadBgCharFromArchive((void *)0x28, (void *)0x1E, (void *)5, 0, 0, 0, p->heap);
    func_0204989C(0x28, 0x28, 5, 0, 0, 0, p->heap);
    ARC_UTIL_UploadBgCharFromArchive((void *)0x28, (void *)0x1E, (void *)3, 0, 0, 0, p->heap);
    func_0204989C(0x28, 0x28, 3, 0, 0, 0, p->heap);
    func_02049B40(0x28, 0xF, 0, 0, 0x20, p->heap);
    VIEWER_MAIN_CopyBg3(p->info->bitmap, p->pix);
    ARC_UTIL_UploadBgCharFromArchive((void *)APP_ICON_GetArchiveId(), (void *)APP_ICON_GetStatusFrameFileId(), (void *)4, 0, 0, 0, p->heap);
    func_0204989C(APP_ICON_GetArchiveId(), APP_ICON_GetStatusDataFileId(), 4, 0, 0, 0, p->heap);
    BG_SYS_FillTileMap(4, 0, 0x15, 0x20, 3, 0xC);
    BG_SYS_PushTile(4);
}
