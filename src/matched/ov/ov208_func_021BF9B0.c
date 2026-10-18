/*
 * function: ZUKAN_DETAIL_AREA_Main
 * address:  0x021BF9B0
 * packet:   pkt_ov208_021BF9B0
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   ZUKAN_DETAIL_COMMON_GetWorkPtr  0x021BC3B4  thumb  ov208
 *   ov208_func_021BC3B8  0x021BC3B8  thumb  ov208
 *   GX_SetGraphicsMode  0x0207D4B0  arm
 *   data_021C85C0  0x021C85C0  data
 *   data_021C8618  0x021C8618  data
 *   BG_SYS_FreeLayerBuf  0x020403F4  arm
 *   BG_SYS_InitBgLayer  0x0203FCA0  arm
 *   BG_SYS_FreeSlot  0x020414AC  arm
 *   func_02040588  0x02040588  arm
 *   BG_SYS_FillScrollArea  0x02040618  arm
 *   BG_SYS_SetVisibleLayer  0x0204047C  arm
 *   ZUKAN_DETAIL_AREA_LoadMapGraphics  0x021C0090  thumb  ov208
 *   ov208_func_021C0134  0x021C0134  thumb  ov208
 *   ZUKAN_DETAIL_AREA_CreateTownIconActors  0x021C0450  thumb  ov208
 *   ZUKAN_DETAIL_AREA_CreateTownMarkerActors  0x021C0544  thumb  ov208
 *   ZUKAN_DETAIL_COMMON_LoadBgPaletteAlloc  0x021BC844  thumb  ov208
 *   ZUKAN_DETAIL_AREA_CreateTextWindows  0x021C0788  thumb  ov208
 *   ZUKAN_DETAIL_AREA_LoadSubScreenGraphics  0x021C08E8  thumb  ov208
 *   ZUKAN_DETAIL_AREA_LoadMarkerResources  0x021C0B10  thumb  ov208
 *   ov208_func_021C1AD4  0x021C1AD4  thumb  ov208
 *   CLACT_SetActorObjMode  0x0204B688  arm
 *   ZUKAN_DETAIL_AREA_MovePlayerMarkerToTown  0x021C0C50  thumb  ov208
 *   ZUKAN_DETAIL_AREA_SetPlayerMarkerVisible  0x021C0C8C  thumb  ov208
 *   ZUKAN_DETAIL_COMMON_CopyHwPalettesToSlots  0x021BC758  thumb  ov208
 *   ov208_func_021BC718  0x021BC718  thumb  ov208
 *   ov208_func_021BC4F4  0x021BC4F4  thumb  ov208
 *   ZUKAN_DETAIL_AREA_SetIconsNormalMode  0x021C24F0  thumb  ov208
 *   ZUKAN_DETAIL_COMMON_StartBlendIn  0x021BC4D8  thumb  ov208
 *   ov208_func_021BC6D8  0x021BC6D8  thumb  ov208
 *   ZUKAN_DETAIL_TOUCHBAR_GetMode  0x021BDAD0  thumb  ov208
 *   ZUKAN_DETAIL_COMMON_GetMaxValue  0x021BC3BC  thumb  ov208
 *   ZUKAN_DETAIL_TOUCHBAR_SetMode  0x021BDAAC  thumb  ov208
 *   ZUKAN_DETAIL_TOUCHBAR_SetEnabled  0x021BDAD4  thumb  ov208
 *   ZUKAN_DETAIL_TOUCHBAR_SetPaletteForKind  0x021BDBB8  thumb  ov208
 *   ov208_func_021BDC48  0x021BDC48  thumb  ov208
 *   ZUKAN_DETAIL_COMMON_GetSource  0x021BC3A4  thumb  ov208
 *   GAME_DATA_CheckSaveFlag  0x02012BF8  thumb
 *   ZUKAN_DETAIL_TOUCHBAR_SetButtonAnimSeq  0x021BDC14  thumb  ov208
 *   ZUKAN_DETAIL_HEADBAR_GetIconKind  0x021BE840  thumb  ov208
 *   ZUKAN_DETAIL_HEADBAR_SetIconKind  0x021BE82C  thumb  ov208
 *   ZUKAN_DETAIL_HEADBAR_SetIconSpecies  0x021BE844  thumb  ov208
 *   ZUKAN_DETAIL_COMMON_IsBlendBusy  0x021BC4C8  thumb  ov208
 *   ov208_func_021BC6C8  0x021BC6C8  thumb  ov208
 *   ZUKAN_DETAIL_TOUCHBAR_ClearButtonState  0x021BDBA0  thumb  ov208
 *   ZUKAN_DETAIL_AREA_SetMapActorsNormalMode  0x021C2458  thumb  ov208
 *   ov208_func_021C1D0C  0x021C1D0C  thumb  ov208
 *   ov208_func_021C1D24  0x021C1D24  thumb  ov208
 *   ZUKAN_DETAIL_AREA_UpdateBlendPulse  0x021C23BC  thumb  ov208
 *   ov208_func_021C10B8  0x021C10B8  thumb  ov208
 *   ZUKAN_DETAIL_AREA_SetMapActorsAlphaMode  0x021C24A4  thumb  ov208
 *   ZUKAN_DETAIL_COMMON_StartBlendOut  0x021BC4E4  thumb  ov208
 *   ov208_func_021BC6F8  0x021BC6F8  thumb  ov208
 *   ZUKAN_DETAIL_HEADBAR_SetIconForm  0x021BE854  thumb  ov208
 *   ov208_func_021BDAE8  0x021BDAE8  thumb  ov208
 *   ZUKAN_DETAIL_AREA_SetIconsAlphaMode  0x021C252C  thumb  ov208
 *   ov208_func_021BC508  0x021BC508  thumb  ov208
 *   ZUKAN_DETAIL_AREA_NoOpLoad  0x021C0130  thumb  ov208
 *   ov208_func_021BC99C  0x021BC99C  thumb  ov208
 *   ov208_func_021C0968  0x021C0968  thumb  ov208
 *   ZUKAN_DETAIL_AREA_UpdateSelectorAnim  0x021C0A8C  thumb  ov208
 *   ZUKAN_DETAIL_AREA_UpdateMode  0x021C1810  thumb  ov208
 *   ZUKAN_DETAIL_COMMON_UpdateBlendFades  0x021BC46C  thumb  ov208
 *   ov208_func_021BC678  0x021BC678  thumb  ov208
 *   ZUKAN_DETAIL_AREA_UpdatePrintQueues  0x021C0714  thumb  ov208
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef int            s32;

struct BgTemplate {
    u32 w[8];
};

struct BgEntry {
    u32 bg;
    struct BgTemplate tmpl;
    u32 type;
    u32 on;
};

extern const struct BgEntry data_021C85C0[2];
extern const struct BgEntry data_021C8618[2];

extern void *ZUKAN_DETAIL_COMMON_GetWorkPtr(int key);
extern void *ov208_func_021BC3B8(int key);
extern void GX_SetGraphicsMode(int dispMode, int bgMode, int bg0_2d3d);
extern void BG_SYS_FreeLayerBuf(u32 i);
extern void BG_SYS_InitBgLayer(u8 bgId, const struct BgTemplate *tmpl, u8 type);
extern void BG_SYS_FreeSlot(u8 bgId);
extern void func_02040588(u8 which, u8 enable);
extern void BG_SYS_FillScrollArea(u32 bgId, u32 which, u32 value);
extern void BG_SYS_SetVisibleLayer(int idx, unsigned short val);
extern void ZUKAN_DETAIL_AREA_LoadMapGraphics(u16 *heap, u8 *p, int key);
extern void ov208_func_021C0134(u16 *heap, u8 *p, int key);
extern void ZUKAN_DETAIL_AREA_CreateTownIconActors(u16 *heap, u8 *p, int key);
extern void ZUKAN_DETAIL_AREA_CreateTownMarkerActors(u16 *heap, u8 *p, int key);
extern u32  ZUKAN_DETAIL_COMMON_LoadBgPaletteAlloc(u16 heap, u32 kind, u8 layer, u8 pal, u8 objPal);
extern void ZUKAN_DETAIL_AREA_CreateTextWindows(u16 *heap, u8 *p, int key);
extern void ZUKAN_DETAIL_AREA_LoadSubScreenGraphics(u16 *heap, u8 *p, int key);
extern void ZUKAN_DETAIL_AREA_LoadMarkerResources(u16 *heap, u8 *p, int key);
extern void ov208_func_021C1AD4(u16 *heap, u8 *p, int key);
struct Actor;
extern void CLACT_SetActorObjMode(struct Actor *actor, u32 value);
extern void ZUKAN_DETAIL_AREA_MovePlayerMarkerToTown(u16 *heap, u8 *p, int key);
extern void ZUKAN_DETAIL_AREA_SetPlayerMarkerVisible(u16 *heap, u8 *p, int key, int on);
extern void ZUKAN_DETAIL_COMMON_CopyHwPalettesToSlots(u32 fade);
extern void ov208_func_021BC718(u32 fade);
extern void ov208_func_021BC4F4(int sub, u32 blend);
extern void ZUKAN_DETAIL_AREA_SetIconsNormalMode(u16 *heap, u8 *p, int key);
extern void ZUKAN_DETAIL_COMMON_StartBlendIn(u32 blend);
extern void ov208_func_021BC6D8(u32 fade);
extern int  ZUKAN_DETAIL_TOUCHBAR_GetMode(void *s);
extern u16  ZUKAN_DETAIL_COMMON_GetMaxValue(char *p);
extern void ZUKAN_DETAIL_TOUCHBAR_SetMode(void *s, u32 mode, u32 kind, u32 flag);
extern void ZUKAN_DETAIL_TOUCHBAR_SetEnabled(void *s, int v);
extern void ZUKAN_DETAIL_TOUCHBAR_SetPaletteForKind(void *s, u32 kind);
extern void ov208_func_021BDC48(void *s, u32 on);
extern int  ZUKAN_DETAIL_COMMON_GetSource(int key);
extern int GAME_DATA_CheckSaveFlag(int a0, int a1);
extern void ZUKAN_DETAIL_TOUCHBAR_SetButtonAnimSeq(void *s, int b);
extern int  ZUKAN_DETAIL_HEADBAR_GetIconKind(void *icon);
extern void ZUKAN_DETAIL_HEADBAR_SetIconKind(void *icon, int kind);
extern void ZUKAN_DETAIL_HEADBAR_SetIconSpecies(void *icon);
extern int  ZUKAN_DETAIL_COMMON_IsBlendBusy(u32 blend);
extern int  ov208_func_021BC6C8(u32 fade);
extern void ZUKAN_DETAIL_TOUCHBAR_ClearButtonState(void *s);
extern void ZUKAN_DETAIL_AREA_SetMapActorsNormalMode(u16 *heap, u8 *p, int key);
extern void ov208_func_021C1D0C(u16 *heap, u8 *p, int key);
extern void ov208_func_021C1D24(u16 *heap, u8 *p, int key);
extern void ZUKAN_DETAIL_AREA_UpdateBlendPulse(u8 *p);
extern void ov208_func_021C10B8(u16 *heap, u8 *p, int key);
extern void ZUKAN_DETAIL_AREA_SetMapActorsAlphaMode(u16 *heap, u8 *p, int key);
extern void ZUKAN_DETAIL_COMMON_StartBlendOut(u32 blend);
extern void ov208_func_021BC6F8(u32 fade);
extern void ZUKAN_DETAIL_HEADBAR_SetIconForm(void *icon);
extern void ov208_func_021BDAE8(void *s, int v);
extern void ZUKAN_DETAIL_AREA_SetIconsAlphaMode(u16 *heap, u8 *p, int key);
extern void ov208_func_021BC508(int sub, u32 blend);
extern void ZUKAN_DETAIL_AREA_NoOpLoad(u16 *heap, u8 *p, int key);
extern void ov208_func_021BC99C(u32 win);
extern void ov208_func_021C0968(u16 *heap, u8 *p, int key);
extern void ZUKAN_DETAIL_AREA_UpdateSelectorAnim(u16 *heap, u8 *p, int key);
extern void ZUKAN_DETAIL_AREA_UpdateMode(u16 *heap, u8 *p, int key);
extern void ZUKAN_DETAIL_COMMON_UpdateBlendFades(u32 main, u32 sub);
extern void ov208_func_021BC678(u32 fade);
extern void ZUKAN_DETAIL_AREA_UpdatePrintQueues(u16 *heap, u8 *p, int key);

#define W(o) (*(u32 *)(p + (o)))

int ZUKAN_DETAIL_AREA_Main(void *proc, int *seq, u16 *heap, u8 *p, int key)
{
    void *scene;
    void *icon;
    u32 j;
    u32 k;
    u8 i;
    int ready;

    scene = ZUKAN_DETAIL_COMMON_GetWorkPtr(key);
    icon = ov208_func_021BC3B8(key);
    switch (*seq) {
    case 0:
        *seq = 1;
        GX_SetGraphicsMode(1, 5, 0);
        for (j = 0; j < 2; j++) {
            BG_SYS_FreeLayerBuf((u8)data_021C85C0[j].bg);
            BG_SYS_InitBgLayer(data_021C85C0[j].bg, &data_021C85C0[j].tmpl, data_021C85C0[j].type);
            BG_SYS_FreeSlot(data_021C85C0[j].bg);
            func_02040588(data_021C85C0[j].bg, data_021C85C0[j].on);
        }
        for (i = 0; i <= 7; i++) {
            if (i != 1 && i != 5) {
                BG_SYS_FillScrollArea(i, 0, 0);
                BG_SYS_FillScrollArea(i, 3, 0);
                BG_SYS_FreeSlot(i);
            }
        }
        BG_SYS_SetVisibleLayer(2, 2);
        BG_SYS_SetVisibleLayer(3, 3);
        BG_SYS_SetVisibleLayer(0, 1);
        BG_SYS_SetVisibleLayer(6, 1);
        BG_SYS_SetVisibleLayer(7, 2);
        BG_SYS_SetVisibleLayer(4, 3);
        ZUKAN_DETAIL_AREA_LoadMapGraphics(heap, p, key);
        ov208_func_021C0134(heap, p, key);
        ZUKAN_DETAIL_AREA_CreateTownIconActors(heap, p, key);
        ZUKAN_DETAIL_AREA_CreateTownMarkerActors(heap, p, key);
        W(8) = ZUKAN_DETAIL_COMMON_LoadBgPaletteAlloc(*heap, 1, 4, 9, 10);
        ZUKAN_DETAIL_AREA_CreateTextWindows(heap, p, key);
        ZUKAN_DETAIL_AREA_LoadSubScreenGraphics(heap, p, key);
        ZUKAN_DETAIL_AREA_LoadMarkerResources(heap, p, key);
        ov208_func_021C1AD4(heap, p, key);
        CLACT_SetActorObjMode((struct Actor *)(*(u32 *)(p + W(0x64) * 4 + 0x5c)), 1);
        ZUKAN_DETAIL_AREA_MovePlayerMarkerToTown(heap, p, key);
        if (W(0x90) == 1)
            ZUKAN_DETAIL_AREA_SetPlayerMarkerVisible(heap, p, key, 1);
        ZUKAN_DETAIL_COMMON_CopyHwPalettesToSlots(W(0x420));
        ov208_func_021BC718(W(0x420));
        break;
    case 1:
        *seq = 2;
        ov208_func_021BC4F4(1, W(0x41c));
        ZUKAN_DETAIL_AREA_SetIconsNormalMode(heap, p, key);
        break;
    case 2:
        *seq = 3;
        ZUKAN_DETAIL_COMMON_StartBlendIn(W(0x418));
        ov208_func_021BC6D8(W(0x420));
        if (ZUKAN_DETAIL_TOUCHBAR_GetMode(scene) != 2) {
            ZUKAN_DETAIL_TOUCHBAR_SetMode(scene, 0, 1, ZUKAN_DETAIL_COMMON_GetMaxValue((char *)key) > 1);
            ZUKAN_DETAIL_TOUCHBAR_SetEnabled(scene, 0);
        } else {
            ZUKAN_DETAIL_TOUCHBAR_SetPaletteForKind(scene, 1);
        }
        ov208_func_021BDC48(scene, 0);
        W(0x88) = 0;
        ZUKAN_DETAIL_TOUCHBAR_SetButtonAnimSeq(scene, GAME_DATA_CheckSaveFlag(ZUKAN_DETAIL_COMMON_GetSource(key), 18));
        if (ZUKAN_DETAIL_HEADBAR_GetIconKind(icon) != 2) {
            ZUKAN_DETAIL_HEADBAR_SetIconKind(icon, 1);
            ZUKAN_DETAIL_HEADBAR_SetIconSpecies(icon);
        }
        break;
    case 3:
        if (ZUKAN_DETAIL_COMMON_IsBlendBusy(W(0x418)) == 0 && ov208_func_021BC6C8(W(0x420)) == 0
            && ZUKAN_DETAIL_TOUCHBAR_GetMode(scene) == 2 && ZUKAN_DETAIL_HEADBAR_GetIconKind(icon) == 2) {
            ZUKAN_DETAIL_TOUCHBAR_ClearButtonState(scene);
            ZUKAN_DETAIL_AREA_SetMapActorsNormalMode(heap, p, key);
            ov208_func_021C1D0C(heap, p, key);
            *seq = 4;
        }
        break;
    case 4:
        if (W(0x84) == 0) {
            ov208_func_021BDC48(scene, 1);
            W(0x88) = 1;
            *seq = 5;
        }
        break;
    case 5:
        if (W(0x424) != 0) {
            ov208_func_021C1D24(heap, p, key);
            *seq = 6;
        } else {
            if (W(0x90) == 1)
                ZUKAN_DETAIL_AREA_UpdateBlendPulse(p);
            ov208_func_021C10B8(heap, p, key);
        }
        break;
    case 6:
        if (W(0x84) == 0) {
            ZUKAN_DETAIL_AREA_SetMapActorsAlphaMode(heap, p, key);
            *seq = 7;
            ZUKAN_DETAIL_COMMON_StartBlendOut(W(0x418));
            ov208_func_021BC6F8(W(0x420));
            ZUKAN_DETAIL_HEADBAR_SetIconForm(icon);
            if (W(0x424) == 2)
                ov208_func_021BDAE8(scene, 0);
        }
        break;
    case 7:
        ready = 0;
        if (ZUKAN_DETAIL_COMMON_IsBlendBusy(W(0x418)) == 0 && ov208_func_021BC6C8(W(0x420)) == 0
            && ZUKAN_DETAIL_HEADBAR_GetIconKind(icon) == 0) {
            if (W(0x424) == 2) {
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
        ZUKAN_DETAIL_AREA_SetIconsAlphaMode(heap, p, key);
        ov208_func_021BC508(1, W(0x41c));
        break;
    case 9:
        ZUKAN_DETAIL_AREA_NoOpLoad(heap, p, key);
        GX_SetGraphicsMode(1, 0, 0);
        for (k = 0; k < 2; k++) {
            BG_SYS_FreeLayerBuf((u8)data_021C8618[k].bg);
            BG_SYS_InitBgLayer(data_021C8618[k].bg, &data_021C8618[k].tmpl, data_021C8618[k].type);
            BG_SYS_FreeSlot(data_021C8618[k].bg);
            func_02040588(data_021C8618[k].bg, data_021C8618[k].on);
        }
        return 1;
    }
    if (*seq >= 2) {
        ov208_func_021BC99C(W(8));
        ov208_func_021C0968(heap, p, key);
        ZUKAN_DETAIL_AREA_UpdateSelectorAnim(heap, p, key);
    }
    ZUKAN_DETAIL_AREA_UpdateMode(heap, p, key);
    ZUKAN_DETAIL_COMMON_UpdateBlendFades(W(0x418), W(0x41c));
    ov208_func_021BC678(W(0x420));
    ZUKAN_DETAIL_AREA_UpdatePrintQueues(heap, p, key);
    return 0;
}
