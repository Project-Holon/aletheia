/*
 * file:     pdc_main.c
 * unit:     yes
 * function: PDC_MAIN_Create, PDC_MAIN_Update, PDC_MAIN_Delete, PDC_MAIN_SetStep, PDC_MAIN_InitGraphics, PDC_MAIN_ExitGraphics, PDC_MAIN_StepIntro, PDC_MAIN_StepConfirm, PDC_MAIN_StepChooseItem, PDC_MAIN_StepDeclined, PDC_MAIN_StartFadeIn
 * address:  0x021B61E8
 * region:   ov098
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from pdc.c, PDC_MSG_BlendUpdate.c by tools/splitfile.py.
 *
 * symbols:
 *   GFL_HEAP_Alloc 0x02030734 arm
 *   GF_OVERLAY_Load  0x02034AC4  arm
 *   GF_OVERLAY_Unload 0x02034A5C arm
 *   GF_FONT_Create 0x0201D7EC thumb
 *   BTLV_EFFECT_CreateSetup 0x021F73F0 thumb ov094
 *   BTLV_EFFECT_Init 0x021F7544 thumb ov094
 *   GFL_HEAP_Free 0x020307B0 arm
 *   BTLV_EFFECT_GetPalanm 0x021F86E0 thumb ov094
 *   BTLV_INPUT_CreateDefault 0x02202058 thumb ov094
 *   TCBL_Create 0x0203101C arm
 *   MYITEM_SAVEDATA_CreateBagCursor 0x02008254 thumb
 *   gPdcMainSrcName 0x021B6E68 data a1
 *   gPdcViewParams 0x021B6D80 data a2
 *   TCBL_Main 0x020310C4 arm
 *   BTLV_EFFECT_Main 0x021F78E4 thumb ov094
 *   BTLV_INPUT_UpdateInfoWindow 0x02202228 thumb ov094
 *   TCBL_Destroy 0x02031140 arm
 *   BTLV_EFFECT_Exit 0x021F7808 thumb ov094
 *   BTLV_INPUT_Delete 0x022021F4 thumb ov094
 *   GF_FONT_Delete 0x0201D83C thumb
 *   BG_SYS_Create 0x0203F8F4 arm
 *   BMP_WIN_Init 0x02045088 arm
 *   GF_FONT_InitTextColor 0x0201DD60 thumb
 *   BG_SYS_SetVramBanks 0x020433E0 arm
 *   BG_SYS_SetGraphicsMode 0x0203FC28 arm
 *   G3D_SYSTEM_Init 0x02046440 arm
 *   G3D_SYSTEM_SetSwapBuffersMode 0x02046BE0 arm
 *   G3X_SetFog 0x0207DC44 arm
 *   CLACT_InitSystem 0x0204A48C arm
 *   BG_SYS_EnableBg0WithPriority 0x0204044C arm
 *   BG_SYS_SetMainPlaneVisible 0x020434DC arm
 *   gPdcDispVram 0x021B6DF4 data a4
 *   gPdcDispConfig 0x021B6DB0 data a4
 *   gPdcClactInit 0x021B6DD8 data a4
 *   BMP_WIN_Exit 0x020450C8 arm
 *   BG_SYS_Delete 0x0203F9B4 arm
 *   CLACT_ExitSystem 0x0204A5AC arm
 *   G3D_SYSTEM_Exit 0x02046788 arm
 *   BTLV_EFFECT_SetPokeSpriteKey  0x021F7EE8  thumb  ov094
 *   BTLV_EFFECT_StartEffect  0x021F7998  thumb  ov094
 *   BTLV_EFFECT_IsBusy  0x021F7EB4  thumb  ov094
 *   BTLV_EFFECT_GaugeInitSlotFromPartyPoke  0x021F8090  thumb  ov094
 *   BTLV_INPUT_ChangeScreen  0x0220270C  thumb  ov094
 *   BTLV_INPUT_ProcessTouchInput  0x02202DC4  thumb  ov094
 *   gPdcMenuLayoutA     0x021B6D98  data   ov098  a4
 *   gPdcMenuLayoutB     0x021B6DC0  data   ov098  a4
 *   ov196_id 0x000000C4 data
 *   ov197_id 0x000000C5 data
 *   BTLV_INPUT_StartPaletteFadeTask 0x022025D8 thumb ov094
 *   BTLV_INPUT_IsScreenBusy 0x022026FC thumb ov094
 *   BTLV_INPUT_StartScreenFadeTask 0x0220266C thumb ov094
 *   B_BAG_MAIN_Create 0x0220C834 thumb ov197
 *   BTLV_EFFECT_StartEffectWithColor 0x021F7CFC thumb ov094
 *   BTLV_EFFECT_ResumeVm 0x021F7C0C thumb ov094
 *   MYITEM_SAVEDATA_RemoveItem 0x02007F1C thumb
 *   GFL_USE_CancelChangeAndPlayBgm 0x02005D90 thumb
 *   GFL_USE_IsBgmPlaying 0x02005F38 thumb
 *   KEY_GetTrg 0x020362DC arm
 *   TOUCHPANEL_GetTrg 0x02035C60 arm
 *   FADE_Start 0x0204E720 arm
 *   FADE_IsActive 0x0204E804 arm
 *   PALANM_GetPairedCodeForFirst 0x0202142C thumb
 *   POKE_TOOL_SetPartyValue 0x02017E40 thumb
 *   GFL_USE_FadeOutBgm  0x02005E30  thumb
 *   GXx_GetMasterBrightness_ 0x0207D55C arm
 *   PDC_GetGameData 0x021B613C thumb ov098
 *   PDC_GetMon 0x021B6140 thumb ov098
 *   PDC_GetScene 0x021B6144 thumb ov098
 *   PDC_GetMyItem 0x021B614C thumb ov098
 *   PDC_GetConfig 0x021B6150 thumb ov098
 *   PDC_GetPokedexSave 0x021B6154 thumb ov098
 *   PDC_MSG_Create 0x021B67D4 thumb ov098
 *   PDC_MSG_Delete 0x021B68DC thumb ov098
 *   PDC_MSG_PrintMessage0 0x021B6910 thumb ov098
 *   PDC_MSG_PrintMessage3 0x021B694C thumb ov098
 *   PDC_MSG_PrintMessage1 0x021B6988 thumb ov098
 *   PDC_MSG_PrintMessage2 0x021B69C4 thumb ov098
 *   PDC_MSG_PrintMessage4 0x021B6A00 thumb ov098
 *   PDC_MSG_Update 0x021B6A3C thumb ov098
 *   PDC_MSG_StartFadeIn 0x021B6B5C thumb ov098
 *   PDC_MSG_UpdateFade 0x021B6B68 thumb ov098
 *   PDC_MSG_TakeStreamEnded 0x021B6B74 thumb ov098
 */
#include "pdc_types.h"

#define BLDCNT (*(volatile u16 *)0x04000050)

#define SBLDCNT (*(volatile u16 *)0x04001050)

#define POWCNT (*(volatile u16 *)0x04000304)

#define DISP3DCNT (*(volatile u16 *)0x04000060)

#define BG0CNT (*(volatile u16 *)0x04000008)

#define MASTER_BRIGHT_MAIN ((unsigned short *)0x0400006c)

struct DispVram;
struct DispConfig;
struct Cfg;
struct PdcWindowGfx;
struct PdcPanel;

/* Four halfwords handed to the overlay 94 screen builder (data gPdcViewParams). */
struct PdcViewParams {
    u16 x;
    u16 y;
    u16 width;
    u16 height;
};

extern void *GFL_HEAP_Alloc(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern int GF_OVERLAY_Load(int overlayId);
extern void GF_OVERLAY_Unload(int overlayId);
extern struct GfFont *GF_FONT_Create(int, int, int, int, u32 heapId);
struct BtlvEffFieldSituation;
struct BtlvEffSetup;
extern struct BtlvEffSetup *BTLV_EFFECT_CreateSetup(int rule, int competitor, struct BtlvEffFieldSituation *situation, int isMultiMode, u16 *trainerTypes, void *battle, int param, u16 heap);
extern void BTLV_EFFECT_Init(struct BtlvEffSetup *setup, void *font, u16 heap);
extern u32 GFL_HEAP_Free(void *p);
struct PalAnmSlot;
extern struct PalAnmSlot *BTLV_EFFECT_GetPalanm(void);
struct BtlvInput;
extern struct BtlvInput *BTLV_INPUT_CreateDefault(int infoWinParam, int battleType, int palAnm, int font, int cursorVisible, u16 heap);
struct TcblSystem;
extern struct TcblSystem *TCBL_Create(u16 heap, u16 tag, u32 count, u32 workSize);
struct BagCursor;
extern struct BagCursor *MYITEM_SAVEDATA_CreateBagCursor(u32 heapId);
struct TcblSystem;
extern void TCBL_Main(struct TcblSystem *tcbl);
extern void BTLV_EFFECT_Main(void);
struct BtlvInput;
extern void BTLV_INPUT_UpdateInfoWindow(struct BtlvInput *input);
extern void TCBL_Destroy(struct TcblSystem *tcbl);
extern void BTLV_EFFECT_Exit(void);
extern void BTLV_INPUT_Delete(struct BtlvInput *input);
extern unsigned int GF_FONT_Delete(struct GfFont *font);
extern void BG_SYS_Create(u16);
extern void BMP_WIN_Init(u16);
extern void GF_FONT_InitTextColor(void);
extern void BG_SYS_SetVramBanks(const struct DispVram *);
extern void BG_SYS_SetGraphicsMode(struct DispConfig *);
extern void G3D_SYSTEM_Init(u32, u32, u32, u32, u16, u32, void (*)(void));
extern void G3D_SYSTEM_SetSwapBuffersMode(u32, u32);
extern void G3X_SetFog(int, int, int, int);
struct DispVramCfg;
struct SysInit;
extern void CLACT_InitSystem(struct SysInit *cfg, struct DispVramCfg *res_cfg, u32 heapId);
extern void BG_SYS_EnableBg0WithPriority(u32);
extern void BG_SYS_SetMainPlaneVisible(u32, u32);
extern void BMP_WIN_Exit(void);
extern void BG_SYS_Delete(void);
extern void CLACT_ExitSystem(void);
extern void G3D_SYSTEM_Exit(void);
extern void BTLV_EFFECT_SetPokeSpriteKey(void *poke, int key);
extern void BTLV_EFFECT_StartEffect(u32 a);
extern int BTLV_EFFECT_IsBusy(void);
struct ZukanSave;
extern void BTLV_EFFECT_GaugeInitSlotFromPartyPoke(struct ZukanSave *zukanSave, void *partyPoke, u32 slotIdx);
extern void BTLV_INPUT_ChangeScreen(struct BtlvInput *input, int mode, void *arg);
extern int BTLV_INPUT_ProcessTouchInput(struct PdcMenu *menu, char *b, char *c);
extern void BTLV_INPUT_StartPaletteFadeTask(struct BtlvInput *input, int flag);
extern int BTLV_INPUT_IsScreenBusy(struct BtlvInput *input);
extern void BTLV_INPUT_StartScreenFadeTask(struct BtlvInput *input);
extern void B_BAG_MAIN_Create(u8 *arg);
extern void BTLV_EFFECT_StartEffectWithColor(u32, u16, u8, int, int);
extern void BTLV_EFFECT_ResumeVm(void);
extern u32 MYITEM_SAVEDATA_RemoveItem(struct MyItem *myItem, u16 itemId, u16 quantity, u16 heapId);
extern void GFL_USE_CancelChangeAndPlayBgm(u32 bgmNo, u32 trackMask);
extern int GFL_USE_IsBgmPlaying(void);
extern u32 KEY_GetTrg(void);
extern int TOUCHPANEL_GetTrg(void);
extern void FADE_Start(u32, int, int, int);
extern int FADE_IsActive(void);
extern unsigned short PALANM_GetPairedCodeForFirst(int value);
extern void POKE_TOOL_SetPartyValue(struct PokemonParam *pp, u32 paramId, u32 value);
extern void GFL_USE_FadeOutBgm(u32 a);
extern int GXx_GetMasterBrightness_(volatile u16 *reg);

extern struct GameData *PDC_GetGameData(struct PdcArgs *args);
extern struct PokemonParam *PDC_GetMon(struct PdcArgs *args);
extern void *PDC_GetScene(struct PdcArgs *args);
extern struct MyItem *PDC_GetMyItem(struct PdcArgs *args);
extern struct Config *PDC_GetConfig(struct PdcArgs *args);
extern struct PokedexSave *PDC_GetPokedexSave(struct PdcArgs *args);
extern struct PdcMsg *PDC_MSG_Create(struct GfFont *font, struct Config *config, struct Tcbl *tcbl, u32 heapId);
extern void PDC_MSG_Delete(struct PdcMsg *msg);
extern void PDC_MSG_PrintMessage0(struct PdcMsg *msg, struct PdcArgs *args);
extern void PDC_MSG_PrintMessage3(struct PdcMsg *msg, struct PdcArgs *args);
extern void PDC_MSG_PrintMessage1(struct PdcMsg *msg, struct PdcArgs *args);
extern void PDC_MSG_PrintMessage2(struct PdcMsg *msg, struct PdcArgs *args);
extern void PDC_MSG_PrintMessage4(struct PdcMsg *msg, struct PdcArgs *args);
extern int PDC_MSG_Update(struct PdcMsg *msg);
extern void PDC_MSG_StartFadeIn(struct PdcMsg *msg);
extern int PDC_MSG_UpdateFade(struct PdcMsg *msg);
extern int PDC_MSG_TakeStreamEnded(struct PdcMsg *msg);

struct PdcSys *PDC_MAIN_Create(struct PdcArgs *args, u16 heapId);
int PDC_MAIN_Update(struct PdcSys *sys);
void PDC_MAIN_Delete(struct PdcSys *sys);
void PDC_MAIN_SetStep(struct PdcSys *sys, PdcStep step);
void PDC_MAIN_InitGraphics(u16 heapId);
void PDC_MAIN_ExitGraphics(void);
int PDC_MAIN_StepIntro(struct PdcSys *sys);
int PDC_MAIN_StepConfirm(struct PdcSys *sys);
int PDC_MAIN_StepChooseItem(struct PdcSys *sys);
int PDC_MAIN_StepDeclined(struct PdcSys *sys);
void PDC_MAIN_StartFadeIn(int speed);

extern const char gPdcMainSrcName[];
extern const struct PdcViewParams gPdcViewParams;
extern const struct DispVram gPdcDispVram;
extern struct DispConfig gPdcDispConfig;
extern const struct Cfg gPdcClactInit;
extern char gPdcMenuLayoutA[];
extern char gPdcMenuLayoutB[];
extern char ov196_id[], ov197_id[];

struct PdcSys *PDC_MAIN_Create(struct PdcArgs *args, u16 heapId)
{
    struct PdcSys *sys;
    struct PdcViewParams params;
    void *screen;
    struct GameData *gameData;

    sys = GFL_HEAP_Alloc(heapId, 0x78, 1, gPdcMainSrcName, 0x5e);
    sys->heapId = heapId;
    sys->args = args;
    PDC_MAIN_InitGraphics(sys->heapId);
    sys->font = GF_FONT_Create(23, 0, 0, 0, sys->heapId);
    sys->msgFont = GF_FONT_Create(23, 2, 0, 0, sys->heapId);
    sys->state = 0;
    params = gPdcViewParams;
    screen = BTLV_EFFECT_CreateSetup(0, 0, PDC_GetScene(args), 0, (u16 *)&params, 0, 0, sys->heapId);
    BTLV_EFFECT_Init(screen, sys->msgFont, sys->heapId);
    GFL_HEAP_Free(screen);
    gameData = PDC_GetGameData(args);
    sys->menu = (struct PdcMenu *)BTLV_INPUT_CreateDefault((int)gameData, (int)0, (int)BTLV_EFFECT_GetPalanm(), (int)sys->font, (int)(&sys->menuWork), sys->heapId);
    sys->tcbl = (struct Tcbl *)TCBL_Create(heapId, heapId, 64, 128);
    sys->mon = PDC_GetMon(args);
    sys->msg = PDC_MSG_Create(sys->font, PDC_GetConfig(args), sys->tcbl, sys->heapId);
    sys->workBuf = MYITEM_SAVEDATA_CreateBagCursor(sys->heapId);
    PDC_MAIN_SetStep(sys, PDC_MAIN_StepIntro);
    return sys;
}

int PDC_MAIN_Update(struct PdcSys *sys)
{
    PdcStep step;
    TCBL_Main((struct TcblSystem *)sys->tcbl);
    BTLV_EFFECT_Main();
    BTLV_INPUT_UpdateInfoWindow((struct BtlvInput *)sys->menu);
    step = sys->step;
    if (step != 0) return step(sys);
    return 0;
}

void PDC_MAIN_Delete(struct PdcSys *sys)
{
    TCBL_Destroy((struct TcblSystem *)sys->tcbl);
    PDC_MSG_Delete(sys->msg);
    BTLV_EFFECT_Exit();
    BTLV_INPUT_Delete((struct BtlvInput *)sys->menu);
    GF_FONT_Delete(sys->font);
    GF_FONT_Delete(sys->msgFont);
    PDC_MAIN_ExitGraphics();
    GFL_HEAP_Free(sys->workBuf);
    GFL_HEAP_Free(sys);
}

void PDC_MAIN_SetStep(struct PdcSys *sys, PdcStep step) { sys->state = 0; sys->step = step; }

void PDC_MAIN_InitGraphics(u16 heapId)
{
    BG_SYS_Create(heapId);
    BMP_WIN_Init(heapId);
    GF_FONT_InitTextColor();
    BG_SYS_SetVramBanks(&gPdcDispVram);
    BLDCNT = 0;
    SBLDCNT = 0;
    POWCNT = (u16)(POWCNT | 0x8000);
    BG_SYS_SetGraphicsMode(&gPdcDispConfig);
    G3D_SYSTEM_Init(0, 1, 0, 1, 0, heapId, 0);
    G3D_SYSTEM_SetSwapBuffersMode(1, 0);
    DISP3DCNT = (u16)((DISP3DCNT & ~0x3000) | 8);
    DISP3DCNT &= (u16)~0x3020;
    DISP3DCNT = (u16)((DISP3DCNT & ~0x3000) | 16);
    G3X_SetFog(0, 0, 0, 0);
    BG0CNT = (u16)((BG0CNT & ~3) | 1);
    CLACT_InitSystem((struct SysInit *)(&gPdcClactInit), (struct DispVramCfg *)&gPdcDispVram, heapId);
    BG_SYS_EnableBg0WithPriority(1);
    BG_SYS_SetMainPlaneVisible(16, 1);
}

void PDC_MAIN_ExitGraphics(void)
{
    BMP_WIN_Exit(); BG_SYS_Delete(); CLACT_ExitSystem(); G3D_SYSTEM_Exit();
}

/* Step 1: opening message, fade in, first message. */
int PDC_MAIN_StepIntro(struct PdcSys *sys)
{
    struct PokedexSave *pokedexSave;

    switch (sys->state) {
    case 0:
        PDC_MSG_StartFadeIn(sys->msg);
        sys->state++;
        break;
    case 1:
        if (PDC_MSG_UpdateFade(sys->msg) != 0) {
            BTLV_EFFECT_SetPokeSpriteKey(sys->mon, 1);
            BTLV_EFFECT_StartEffect(0x231);
            PDC_MAIN_StartFadeIn(2);
            sys->state++;
        }
        break;
    case 2:
        if (BTLV_EFFECT_IsBusy() == 0) {
            PDC_MSG_PrintMessage0(sys->msg, sys->args);
            sys->state++;
        }
        break;
    case 3:
        if (PDC_MSG_Update(sys->msg) != 0) {
            pokedexSave = PDC_GetPokedexSave(sys->args);
            BTLV_EFFECT_GaugeInitSlotFromPartyPoke((struct ZukanSave *)pokedexSave, PDC_GetMon(sys->args), 1);
            PDC_MSG_StartFadeIn(sys->msg);
            sys->state++;
        }
        break;
    case 4:
        if (PDC_MSG_UpdateFade(sys->msg) != 0) {
            BTLV_EFFECT_StartEffect(0x23e);
            sys->state++;
        }
        break;
    case 5:
        if (BTLV_EFFECT_IsBusy() == 0)
            PDC_MAIN_SetStep(sys, PDC_MAIN_StepConfirm);
        break;
    }
    return 0;
}

/* Step 2: question message and the confirmation menu; picks the next step. */
int PDC_MAIN_StepConfirm(struct PdcSys *sys)
{
    int choice;

    switch (sys->state) {
    case 0:
        PDC_MSG_PrintMessage3(sys->msg, sys->args);
        sys->state++;
        break;
    case 1:
        if (PDC_MSG_Update(sys->msg) != 0) {
            BTLV_INPUT_ChangeScreen((struct BtlvInput *)sys->menu, 7, 0);
            sys->state++;
        }
        break;
    case 2:
        choice = BTLV_INPUT_ProcessTouchInput(sys->menu, gPdcMenuLayoutA, gPdcMenuLayoutB);
        if (choice != -1) {
            if (choice != 0)
                PDC_MAIN_SetStep(sys, PDC_MAIN_StepDeclined);
            else
                PDC_MAIN_SetStep(sys, PDC_MAIN_StepChooseItem);
        }
        break;
    }
    return 0;
}

/* Step 3: item list, the chosen item goes into the bag, closing messages. Returns 1 when done. */
int PDC_MAIN_StepChooseItem(struct PdcSys *sys)
{
    u32 itemCode;
    switch (sys->state) {
    case 0:
        sys->select.myItem = PDC_GetMyItem(sys->args);
        sys->select.workBuf = sys->workBuf;
        sys->select.mode = 3;
        sys->select.font = sys->font;
        sys->select.heapId = sys->heapId;
        sys->select.chosenItem = 0;
        sys->select.reserved20 = 0;
        sys->select.cursorPos = 0; sys->select.scrollPos = 0; sys->select.done = 0;
        sys->select.menuWork = (u8 *)&sys->menuWork;
        sys->select.enabled = 1;
        BTLV_INPUT_StartPaletteFadeTask((struct BtlvInput *)sys->menu, 1);
        GF_OVERLAY_Load((int)ov196_id);
        sys->state++;
        break;
    case 1:
        if (!BTLV_INPUT_IsScreenBusy((struct BtlvInput *)sys->menu)) {
            GF_OVERLAY_Load((int)ov197_id);
            B_BAG_MAIN_Create((u8 *)(&sys->select));
            sys->state++;
        }
        break;
    case 2:
        if (sys->select.done) {
            GF_OVERLAY_Unload((int)ov196_id); GF_OVERLAY_Unload((int)ov197_id);
            BTLV_INPUT_StartScreenFadeTask((struct BtlvInput *)sys->menu);
            if (sys->select.chosenItem == 0) sys->state = 3;
            else {
                MYITEM_SAVEDATA_RemoveItem(PDC_GetMyItem(sys->args), sys->select.chosenItem, 1, sys->heapId);
                sys->state = 4;
            }
        }
        break;
    case 3:
        if (!BTLV_INPUT_IsScreenBusy((struct BtlvInput *)sys->menu)) PDC_MAIN_SetStep(sys, PDC_MAIN_StepConfirm);
        break;
    case 4:
        if (!BTLV_INPUT_IsScreenBusy((struct BtlvInput *)sys->menu)) {
            PDC_MSG_PrintMessage1(sys->msg, sys->args);
            sys->state++;
        }
        break;
    case 5:
        if (PDC_MSG_Update(sys->msg)) {
            BTLV_EFFECT_StartEffectWithColor(1, sys->select.chosenItem, 4, 1, 0);
            sys->state++;
        }
        break;
    case 6:
        if (!BTLV_EFFECT_IsBusy()) {
            PDC_MSG_PrintMessage2(sys->msg, sys->args);
            sys->state++;
        }
        break;
    case 7:
        if (PDC_MSG_TakeStreamEnded(sys->msg)) GFL_USE_CancelChangeAndPlayBgm(0x518, 0xffff);
        if (PDC_MSG_Update(sys->msg)) sys->state++;
        break;
    case 8:
        if (!GFL_USE_IsBgmPlaying()) {
            BTLV_EFFECT_ResumeVm(); GFL_USE_CancelChangeAndPlayBgm(0x47c, 0xffff);
            sys->state++;
        }
        break;
    case 9:
        if (!BTLV_EFFECT_IsBusy()) {
            sys->timer = 80;
            sys->state++;
        }
        break;
    case 10:
        if (((u32)KEY_GetTrg() & 3) || TOUCHPANEL_GetTrg() || --sys->timer == 0) {
            FADE_Start(3, 0, 16, 2);
            sys->state++;
        }
        break;
    case 11:
        if (!FADE_IsActive()) {
            itemCode = PALANM_GetPairedCodeForFirst(sys->select.chosenItem);
            POKE_TOOL_SetPartyValue(PDC_GetMon(sys->args), 152, itemCode);
            return 1;
        }
        break;
    }
    return 0;
}

/* Step 3 alternative: the player declined; fade out and return 2. */
int PDC_MAIN_StepDeclined(struct PdcSys *sys)
{
    switch (sys->state) {
    case 0:
        PDC_MSG_PrintMessage4(sys->msg, sys->args);
        sys->state++;
        break;
    case 1:
        if (PDC_MSG_Update(sys->msg) != 0) {
            FADE_Start(3, 0, 0x10, 2);
            GFL_USE_FadeOutBgm(8);
            sys->state++;
        }
        break;
    case 2:
        if (FADE_IsActive() == 0)
            return 2;
        break;
    }
    return 0;
}

void PDC_MAIN_StartFadeIn(int speed) { if (GXx_GetMasterBrightness_(MASTER_BRIGHT_MAIN) <= 0) FADE_Start(3,16,0,speed); else FADE_Start(12,16,0,speed); }
