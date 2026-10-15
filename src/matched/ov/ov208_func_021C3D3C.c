/*
 * function: ZUKAN_DETAIL_FORM_Main
 * address:  0x021C3D3C
 * packet:   pkt_ov208_021C3D3C
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   ov208_func_021BC3A8  0x021BC3A8  thumb  ov208
 *   ov208_func_021BC3B4  0x021BC3B4  thumb  ov208
 *   ov208_func_021BC3B8  0x021BC3B8  thumb  ov208
 *   func_02040618  0x02040618  arm
 *   func_020414AC  0x020414AC  arm
 *   func_0204047C  0x0204047C  arm
 *   ov208_func_021BDCA4  0x021BDCA4  thumb  ov208
 *   GX_SetGraphicsMode  0x0207D4B0  arm
 *   ov208_func_021BCF58  0x021BCF58  thumb  ov208
 *   ZUKAN_DETAIL_FORM_InitModelSystem  0x021C4F78  thumb  ov208
 *   ZUKAN_DETAIL_FORM_CreateTextWindows  0x021C48CC  thumb  ov208
 *   ZUKAN_DETAIL_FORM_CreateArrowActors  0x021C625C  thumb  ov208
 *   ZUKAN_DETAIL_FORM_RefreshFormEntries  0x021C5664  thumb  ov208
 *   ZUKAN_DETAIL_FORM_LoadIconResources  0x021C52F0  thumb  ov208
 *   ZUKAN_DETAIL_FORM_RebuildModels  0x021C580C  thumb  ov208
 *   CLACT_SetActorObjMode  0x0204B688  arm
 *   MCSS_SetVanishFlag  0x02015EA0  thumb
 *   MCSS_SetPaletteFade  0x02015F50  thumb
 *   ZUKAN_DETAIL_COMMON_LoadBgPaletteRange  0x021BC9BC  thumb  ov208
 *   ZUKAN_DETAIL_COMMON_LoadBgPaletteAlloc  0x021BC844  thumb  ov208
 *   ZUKAN_DETAIL_COMMON_CopyHwPalettesToSlots  0x021BC758  thumb  ov208
 *   ov208_func_021BC718  0x021BC718  thumb  ov208
 *   ov208_func_021BC4F4  0x021BC4F4  thumb  ov208
 *   ZUKAN_DETAIL_FORM_SetActorsNormalMode  0x021C7E74  thumb  ov208
 *   MCSS_CheckPaletteFade  0x0201600C  thumb
 *   ov208_func_021BC6D8  0x021BC6D8  thumb  ov208
 *   ZUKAN_DETAIL_TOUCHBAR_GetMode  0x021BDAD0  thumb  ov208
 *   ZUKAN_DETAIL_COMMON_GetMaxValue  0x021BC3BC  thumb  ov208
 *   ZUKAN_DETAIL_TOUCHBAR_SetMode  0x021BDAAC  thumb  ov208
 *   ZUKAN_DETAIL_TOUCHBAR_SetEnabled  0x021BDAD4  thumb  ov208
 *   ZUKAN_DETAIL_TOUCHBAR_SetPaletteForKind  0x021BDBB8  thumb  ov208
 *   ov208_func_021BDC48  0x021BDC48  thumb  ov208
 *   ov208_func_021BC3A4  0x021BC3A4  thumb  ov208
 *   GAME_DATA_CheckSaveFlag  0x02012BF8  thumb
 *   ov208_func_021BDC14  0x021BDC14  thumb  ov208
 *   ZUKAN_DETAIL_HEADBAR_GetIconKind  0x021BE840  thumb  ov208
 *   ZUKAN_DETAIL_HEADBAR_SetIconKind  0x021BE82C  thumb  ov208
 *   ZUKAN_DETAIL_HEADBAR_SetIconSpecies  0x021BE844  thumb  ov208
 *   MCSS_ResetVanishFlag  0x02015EB0  thumb
 *   ov208_func_021BC6C8  0x021BC6C8  thumb  ov208
 *   ZUKAN_DETAIL_TOUCHBAR_ClearButtonState  0x021BDBA0  thumb  ov208
 *   ZUKAN_DETAIL_FORM_UpdateState  0x021C5D64  thumb  ov208
 *   ov208_func_021BC6F8  0x021BC6F8  thumb  ov208
 *   ZUKAN_DETAIL_HEADBAR_SetIconForm  0x021BE854  thumb  ov208
 *   ov208_func_021BDAE8  0x021BDAE8  thumb  ov208
 *   ZUKAN_DETAIL_FORM_SetActorsAlphaMode  0x021C7EF8  thumb  ov208
 *   ov208_func_021BC508  0x021BC508  thumb  ov208
 *   ov208_func_021C51A0  0x021C51A0  thumb  ov208
 *   ov208_func_021C4FDC  0x021C4FDC  thumb  ov208
 *   ov208_func_021BCF6C  0x021BCF6C  thumb  ov208
 *   func_02030D28  0x02030D28  arm
 *   MCSS_Main  0x02014C08  thumb
 *   ZUKAN_DETAIL_FORM_StopModelAnim  0x021C5214  thumb  ov208
 *   ZUKAN_DETAIL_FORM_UpdateArrowAnim  0x021C692C  thumb  ov208
 *   ZUKAN_DETAIL_FORM_UpdateSlideLeft  0x021C6E98  thumb  ov208
 *   ZUKAN_DETAIL_FORM_UpdateScrollInput  0x021C6BB4  thumb  ov208
 *   ZUKAN_DETAIL_FORM_UpdateSlideRight  0x021C75FC  thumb  ov208
 *   ZUKAN_DETAIL_FORM_UpdateSlideBoth  0x021C7860  thumb  ov208
 *   ov208_func_021BC99C  0x021BC99C  thumb  ov208
 *   ZUKAN_DETAIL_COMMON_UpdateBlendFades  0x021BC46C  thumb  ov208
 *   ov208_func_021BC678  0x021BC678  thumb  ov208
 *   ZUKAN_DETAIL_FORM_UpdatePrintQueues  0x021C4B2C  thumb  ov208
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef int            s32;

extern void *ov208_func_021BC3A8(int key);
extern void *ov208_func_021BC3B4(int key);
extern void *ov208_func_021BC3B8(int key);
extern void func_02040618(u32 bgId, u32 which, u32 value);
extern void func_020414AC(u32 bgId);
extern void func_0204047C(int idx, unsigned short val);
extern void ov208_func_021BDCA4(void *s, u8 v);
extern void GX_SetGraphicsMode(int dispMode, int bgMode, int bg0_2d3d);
extern void ov208_func_021BCF58(void *s, int x);
extern void ZUKAN_DETAIL_FORM_InitModelSystem(u16 *heap, u8 *p, int key);
extern void ZUKAN_DETAIL_FORM_CreateTextWindows(u16 *heap, u8 *p, int key);
extern void ZUKAN_DETAIL_FORM_CreateArrowActors(u16 *heap, u8 *p, int key);
extern void ZUKAN_DETAIL_FORM_RefreshFormEntries(u16 *heap, u8 *p, int key);
extern void ZUKAN_DETAIL_FORM_LoadIconResources(u16 *heap, u8 *p, int key);
extern void ZUKAN_DETAIL_FORM_RebuildModels(u16 *heap, u8 *p, int key);
struct Actor;
struct Ctx;
struct McssFade;
extern void CLACT_SetActorObjMode(struct Actor *actor, u32 value);
extern void MCSS_SetVanishFlag(void *p);
extern void MCSS_SetPaletteFade(struct McssFade *w, u32 cur, u32 target, s32 step, u32 e);
extern u32  ZUKAN_DETAIL_COMMON_LoadBgPaletteRange(int skip, u16 heap, u8 layer, u8 count, u8 pal, u8 palOfs,
                                u32 arc, u32 chr, u32 scr, u32 cell, u32 chrOfs);
extern u32  ZUKAN_DETAIL_COMMON_LoadBgPaletteAlloc(u16 heap, u32 kind, u8 layer, u8 pal, u8 objPal);
extern void ZUKAN_DETAIL_COMMON_CopyHwPalettesToSlots(u32 fade);
extern void ov208_func_021BC718(u32 fade);
extern void ov208_func_021BC4F4(int sub, u32 blend);
extern void ZUKAN_DETAIL_FORM_SetActorsNormalMode(u16 *heap, u8 *p, int key);
extern int MCSS_CheckPaletteFade(void *p);
extern void ov208_func_021BC6D8(u32 fade);
extern int  ZUKAN_DETAIL_TOUCHBAR_GetMode(void *s);
extern u16  ZUKAN_DETAIL_COMMON_GetMaxValue(char *p);
extern void ZUKAN_DETAIL_TOUCHBAR_SetMode(void *s, u32 mode, u32 kind, u32 flag);
extern void ZUKAN_DETAIL_TOUCHBAR_SetEnabled(void *s, int v);
extern void ZUKAN_DETAIL_TOUCHBAR_SetPaletteForKind(void *s, u32 kind);
extern void ov208_func_021BDC48(void *s, u32 on);
extern int  ov208_func_021BC3A4(int key);
extern int GAME_DATA_CheckSaveFlag(int a0, int a1);
extern void ov208_func_021BDC14(void *s, int b);
extern int  ZUKAN_DETAIL_HEADBAR_GetIconKind(void *icon);
extern void ZUKAN_DETAIL_HEADBAR_SetIconKind(void *icon, int kind);
extern void ZUKAN_DETAIL_HEADBAR_SetIconSpecies(void *icon);
extern void MCSS_ResetVanishFlag(void *p);
extern int  ov208_func_021BC6C8(u32 fade);
extern void ZUKAN_DETAIL_TOUCHBAR_ClearButtonState(void *s);
extern void ZUKAN_DETAIL_FORM_UpdateState(u16 *heap, u8 *p, int key);
extern void ov208_func_021BC6F8(u32 fade);
extern void ZUKAN_DETAIL_HEADBAR_SetIconForm(void *icon);
extern void ov208_func_021BDAE8(void *s, int v);
extern void ZUKAN_DETAIL_FORM_SetActorsAlphaMode(u16 *heap, u8 *p, int key);
extern void ov208_func_021BC508(int flag, int *p);
extern void ov208_func_021C51A0(u8 *mdl, u32 sys);
extern void ov208_func_021C4FDC(u16 *heap, u8 *p, int key);
extern void ov208_func_021BCF6C(void *s);
extern void func_02030D28(struct Ctx *c);
extern void MCSS_Main(char *self);
extern void ZUKAN_DETAIL_FORM_StopModelAnim(u8 *mdl);
extern void ZUKAN_DETAIL_FORM_UpdateArrowAnim(u16 *heap, u8 *p, int key);
extern void ZUKAN_DETAIL_FORM_UpdateSlideLeft(u16 *heap, u8 *p, int key);
extern void ZUKAN_DETAIL_FORM_UpdateScrollInput(u16 *heap, u8 *p, int key);
extern void ZUKAN_DETAIL_FORM_UpdateSlideRight(u16 *heap, u8 *p, int key);
extern void ZUKAN_DETAIL_FORM_UpdateSlideBoth(u16 *heap, u8 *p, int key);
extern void ov208_func_021BC99C(u32 win);
extern void ZUKAN_DETAIL_COMMON_UpdateBlendFades(u32 main, u32 sub);
extern void ov208_func_021BC678(u32 fade);
extern void ZUKAN_DETAIL_FORM_UpdatePrintQueues(u16 *heap, u8 *p, int key);

#define W(o) (*(u32 *)(p + (o)))
#define OBJ(i) (*(u32 *)(p + (i) * 0x44 + 0xc))

int ZUKAN_DETAIL_FORM_Main(void *proc, int *seq, u16 *heap, u8 *p, int key)
{
    void *res;
    void *scene;
    void *icon;
    u8 i;
    int done;
    int settled;
    int ready;
    int idle;

    res = ov208_func_021BC3A8(key);
    scene = ov208_func_021BC3B4(key);
    icon = ov208_func_021BC3B8(key);
    switch (*seq) {
    case 0:
        *seq = 1;
        for (i = 0; i <= 7; i++) {
            if (i != 1 && i != 5) {
                func_02040618(i, 0, 0);
                func_02040618(i, 3, 0);
                func_020414AC(i);
            }
        }
        func_0204047C(0, 0);
        func_0204047C(2, 2);
        func_0204047C(3, 3);
        func_0204047C(6, 1);
        func_0204047C(4, 3);
        func_0204047C(7, 2);
        ov208_func_021BDCA4(scene, 2);
        GX_SetGraphicsMode(1, 0, 1);
        ov208_func_021BCF58(res, *heap);
        ZUKAN_DETAIL_FORM_InitModelSystem(heap, p, key);
        ZUKAN_DETAIL_FORM_CreateTextWindows(heap, p, key);
        ZUKAN_DETAIL_FORM_CreateArrowActors(heap, p, key);
        ZUKAN_DETAIL_FORM_RefreshFormEntries(heap, p, key);
        ZUKAN_DETAIL_FORM_LoadIconResources(heap, p, key);
        ZUKAN_DETAIL_FORM_RebuildModels(heap, p, key);
        CLACT_SetActorObjMode((struct Actor *)(*(u32 *)(p + W(0x144) * 4 + 0x13c)), 1);
        MCSS_SetVanishFlag((void *)W(0xc));
        MCSS_SetPaletteFade((struct McssFade *)W(0xc), 16, 16, 0, 0);
        if (W(0x94) != 0) {
            MCSS_SetVanishFlag((void *)W(0x94));
            MCSS_SetPaletteFade((struct McssFade *)W(0x94), 16, 16, 0, 0);
        }
        W(0x5b4) = ZUKAN_DETAIL_COMMON_LoadBgPaletteRange(0, *heap, 7, 1, 1, 0, 0x9f, 2, 12, 0x23, 0);
        W(0x5b8) = ZUKAN_DETAIL_COMMON_LoadBgPaletteAlloc(*heap, 3, 3, 1, 2);
        W(0x5bc) = ZUKAN_DETAIL_COMMON_LoadBgPaletteAlloc(*heap, 3, 4, 2, 3);
        ZUKAN_DETAIL_COMMON_CopyHwPalettesToSlots(W(0x6ac));
        ov208_func_021BC718(W(0x6ac));
        break;
    case 1:
        *seq = 2;
        ov208_func_021BC4F4(0, W(0x6a4));
        ov208_func_021BC4F4(1, W(0x6a8));
        ZUKAN_DETAIL_FORM_SetActorsNormalMode(heap, p, key);
        break;
    case 2:
        *seq = 3;
        break;
    case 3:
        done = 1;
        if (MCSS_CheckPaletteFade((void *)W(0xc)) != 0)
            done = 0;
        if (W(0x94) != 0 && MCSS_CheckPaletteFade((void *)W(0x94)) != 0)
            done = 0;
        if (done) {
            *seq = 4;
            ov208_func_021BC6D8(W(0x6ac));
            if (ZUKAN_DETAIL_TOUCHBAR_GetMode(scene) != 2) {
                ZUKAN_DETAIL_TOUCHBAR_SetMode(scene, 0, 3, ZUKAN_DETAIL_COMMON_GetMaxValue((char *)key) > 1);
                ZUKAN_DETAIL_TOUCHBAR_SetEnabled(scene, 0);
            } else {
                ZUKAN_DETAIL_TOUCHBAR_SetPaletteForKind(scene, 3);
            }
            ov208_func_021BDC48(scene, 0);
            ov208_func_021BDC14(scene, GAME_DATA_CheckSaveFlag(ov208_func_021BC3A4(key), 20));
            if (ZUKAN_DETAIL_HEADBAR_GetIconKind(icon) != 2) {
                ZUKAN_DETAIL_HEADBAR_SetIconKind(icon, 3);
                ZUKAN_DETAIL_HEADBAR_SetIconSpecies(icon);
            }
            MCSS_ResetVanishFlag((void *)W(0xc));
            MCSS_SetPaletteFade((struct McssFade *)W(0xc), 16, 0, -2, 0);
            if (W(0x94) != 0) {
                MCSS_ResetVanishFlag((void *)W(0x94));
                MCSS_SetPaletteFade((struct McssFade *)W(0x94), 16, 0, -2, 0);
            }
        }
        break;
    case 4:
        done = 1;
        if (MCSS_CheckPaletteFade((void *)W(0xc)) != 0)
            done = 0;
        if (W(0x94) != 0 && MCSS_CheckPaletteFade((void *)W(0x94)) != 0)
            done = 0;
        if (ov208_func_021BC6C8(W(0x6ac)) == 0 && ZUKAN_DETAIL_TOUCHBAR_GetMode(scene) == 2
            && ZUKAN_DETAIL_HEADBAR_GetIconKind(icon) == 2 && done) {
            ZUKAN_DETAIL_TOUCHBAR_ClearButtonState(scene);
            ov208_func_021BDC48(scene, 1);
            *seq = 5;
        }
        break;
    case 5:
        if (W(0x6b0) != 0) {
            *seq = 6;
            for (i = 0; i < 4; i++) {
                if (OBJ(i) != 0)
                    MCSS_SetPaletteFade((struct McssFade *)OBJ(i), 0, 0, 0, 0);
            }
        } else {
            ZUKAN_DETAIL_FORM_UpdateState(heap, p, key);
        }
        break;
    case 6:
        settled = 1;
        for (i = 0; i < 4; i++) {
            if (OBJ(i) != 0 && MCSS_CheckPaletteFade((void *)OBJ(i)) != 0) {
                settled = 0;
                break;
            }
        }
        if (settled) {
            *seq = 7;
            ov208_func_021BC6F8(W(0x6ac));
            ZUKAN_DETAIL_HEADBAR_SetIconForm(icon);
            if (W(0x6b0) == 2)
                ov208_func_021BDAE8(scene, 0);
            for (i = 0; i < 4; i++) {
                if (OBJ(i) != 0)
                    MCSS_SetPaletteFade((struct McssFade *)OBJ(i), 0, 16, -2, 0);
            }
        }
        break;
    case 7:
        ready = 0;
        idle = 1;
        for (i = 0; i < 4; i++) {
            if (OBJ(i) != 0 && MCSS_CheckPaletteFade((void *)OBJ(i)) != 0) {
                idle = 0;
                break;
            }
        }
        if (ov208_func_021BC6C8(W(0x6ac)) == 0 && ZUKAN_DETAIL_HEADBAR_GetIconKind(icon) == 0 && idle) {
            if (W(0x6b0) == 2) {
                if (ZUKAN_DETAIL_TOUCHBAR_GetMode(scene) == 0)
                    ready = 1;
            } else {
                ready = 1;
            }
        }
        if (ready)
            *seq = 8;
        break;
    case 8:
        *seq = 9;
        ZUKAN_DETAIL_FORM_SetActorsAlphaMode(heap, p, key);
        ov208_func_021BC508(0, (int *)W(0x6a4));
        ov208_func_021BC508(1, (int *)W(0x6a8));
        break;
    case 9:
        for (i = 0; i < 4; i++)
            ov208_func_021C51A0(p + 0xc + i * 0x44, W(8));
        ov208_func_021C4FDC(heap, p, key);
        ov208_func_021BCF6C(res);
        GX_SetGraphicsMode(1, 0, 0);
        return 1;
    }
    if (W(8) != 0) {
        func_02030D28((struct Ctx *)W(0x120));
        MCSS_Main((char *)W(8));
        for (i = 0; i < 4; i++)
            ZUKAN_DETAIL_FORM_StopModelAnim(p + 0xc + i * 0x44);
    }
    if (*seq >= 3) {
        ZUKAN_DETAIL_FORM_UpdateArrowAnim(heap, p, key);
        ZUKAN_DETAIL_FORM_UpdateSlideLeft(heap, p, key);
        ZUKAN_DETAIL_FORM_UpdateScrollInput(heap, p, key);
        ZUKAN_DETAIL_FORM_UpdateSlideRight(heap, p, key);
        ZUKAN_DETAIL_FORM_UpdateSlideBoth(heap, p, key);
        ov208_func_021BC99C(W(0x5b8));
        ov208_func_021BC99C(W(0x5bc));
    }
    ZUKAN_DETAIL_COMMON_UpdateBlendFades(W(0x6a4), W(0x6a8));
    ov208_func_021BC678(W(0x6ac));
    ZUKAN_DETAIL_FORM_UpdatePrintQueues(heap, p, key);
    return 0;
}
