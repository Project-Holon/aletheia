/*
 * file:     viewer_actor.c
 * unit:     yes
 * function: VIEWER_ACTOR_CreateObjects, VIEWER_ACTOR_DeleteObjects, VIEWER_ACTOR_Init3D, VIEWER_ACTOR_Exit3D, VIEWER_ACTOR_CreateModel, VIEWER_ACTOR_DeleteModel, VIEWER_ACTOR_DrawModel, VIEWER_ACTOR_InitBgWindow, VIEWER_ACTOR_DeleteBgWindow, VIEWER_ACTOR_FlushBgWindow, VIEWER_ACTOR_CreateFont, VIEWER_ACTOR_DeleteFont, VIEWER_ACTOR_PrintQueMain, VIEWER_ACTOR_DispatchState, VIEWER_ACTOR_StepWaitWipeIn, VIEWER_ACTOR_UpdateMain, VIEWER_ACTOR_StepWaitActorAnim, VIEWER_ACTOR_StartWipe, VIEWER_ACTOR_StepWaitWipeOut, VIEWER_ACTOR_PrintTextAt, VIEWER_ACTOR_DrawLabel, VIEWER_ACTOR_WrapAngle, VIEWER_ACTOR_StepBounce, VIEWER_ACTOR_HandleDrag, VIEWER_ACTOR_HandleInput, VIEWER_ACTOR_FindNearestPreset, VIEWER_ACTOR_SelectActor, VIEWER_ACTOR_ToggleFavorite, VIEWER_ACTOR_SetPageCount, VIEWER_ACTOR_SetRowDrawEnable, VIEWER_ACTOR_UpdateRowVisibility, VIEWER_ACTOR_SetSelection, VIEWER_ACTOR_SaveBadgeTimers, VIEWER_ACTOR_LoadBadgeTimers, VIEWER_ACTOR_LoadPalette, VIEWER_ACTOR_LoadTexture, VIEWER_ACTOR_SetRowActorDrawEnable, VIEWER_ACTOR_RefreshRows, VIEWER_ACTOR_HandleScrollRepeat, VIEWER_ACTOR_ResetDragFlags, VIEWER_ACTOR_StepScrollCount, VIEWER_ACTOR_HandleTouchDrag
 * address:  0x021C75E4
 * region:   ov111
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   CLACT_CreateActor  0x0204B294  arm
 *   CLACT_SetActorAutoAnim  0x0204B92C  arm
 *   d_021C8AA0  0x021C8AA0  data
 *   CLACT_ReleaseCharacter  0x0204A8D4  arm
 *   CLACT_ReleasePalette  0x0204ADA4  arm
 *   CLACT_ReleaseCellAnim  0x0204AFD8  arm
 *   CLACT_DeleteUnit  0x0204B1CC  arm
 *   CLACT_ExitSystem  0x0204A5AC  arm
 *   G3D_SYSTEM_Init  0x02046440  arm
 *   G3D_LIGHT_CreateSlots  0x02048BC4  arm
 *   G3D_LIGHT_ApplySlots  0x02048C58  arm
 *   G3D_SYSTEM_SetProjection  0x02046858  arm
 *   BG_SYS_SetPlaneVisible  0x02040588  arm
 *   d_021C8810  0x021C8810  data
 *   d_021C896C  0x021C896C  data
 *   FX_SinCosTable_  0x020A1B38  data
 *   G3D_LIGHT_DeleteSlots  0x02048C4C  arm
 *   G3D_SYSTEM_Exit  0x02046788  arm
 *   G3D_UTIL_Create  0x02047CFC  arm
 *   G3D_UTIL_AddUnit  0x02047E88  arm
 *   G3D_UTIL_GetObject  0x02048A18  arm
 *   G3D_SYSTEM_GetObjectAnimeCount  0x0204779C  arm
 *   G3D_SYSTEM_EnableObjectAnime  0x020477A4  arm
 *   G3D_CAMERA_Create  0x02048A24  arm
 *   d_021C8834  0x021C8834  data
 *   d_021C8950  0x021C8950  data
 *   d_021C8938  0x021C8938  data
 *   d_021C8944  0x021C8944  data
 *   G3D_CAMERA_Delete  0x02048AC4  arm
 *   G3D_UTIL_RemoveUnit  0x020480E4  arm
 *   G3D_UTIL_Delete  0x02047E54  arm
 *   MTX_Identity33_  0x0207ADC4  arm
 *   G3D_CAMERA_Reset  0x02048AD0  arm
 *   G3D_SYSTEM_GetObjectAnimeFrame  0x02047828  arm
 *   G3D_SYSTEM_SetObjectAnimeFrame  0x0204784C  arm
 *   G3D_SYSTEM_DrawStart  0x02047964  arm
 *   G3D_SYSTEM_ApplyLookAt  0x020479D8  arm
 *   G3D_SYSTEM_DrawObject  0x02047A60  arm
 *   G3D_SYSTEM_DrawEnd  0x02047970  arm
 *   d_021C8E80  0x021C8E80  data
 *   BMP_WIN_Init  0x02045088  arm
 *   BMP_WIN_Create  0x020450F0  arm
 *   BMP_WIN_GetBmp  0x02045770  arm
 *   BMP_Clear  0x02043B5C  arm
 *   BMP_WIN_Delete  0x020452E8  arm
 *   BMP_WIN_Exit  0x020450C8  arm
 *   BMP_MENUWORK_DrawWindow  0x0201F73C  thumb
 *   BMP_WIN_TransferChars  0x02045334  arm
 *   BMP_WIN_MakeScreen  0x02045374  arm
 *   BMP_WIN_GetBgLayer  0x02045730  arm
 *   BG_SYS_PushTile  0x020409B4  arm
 *   GF_FONT_Create  0x0201D7EC  thumb
 *   PRINTSYS_QUE_Create  0x0201C440  thumb
 *   PRINTSYS_QUE_Delete  0x0201C4C0  thumb
 *   GF_FONT_Delete  0x0201D83C  thumb
 *   PRINTSYS_QUE_Main  0x0201C4E4  thumb
 *   PRINTSYS_QUE_IsExistTarget  0x0201C6C4  thumb
 *   d_021C8E58  0x021C8E58  data
 *   WIPE_SYS_EndCheck  0x020221A4  thumb
 *   PRINTSYS_QUE_IsFinished  0x0201C6B4  thumb
 *   CLACT_IsActorAnimActive  0x0204B98C  arm
 *   WIPE_SYS_Start  0x0202208C  thumb
 *   MSGDATA_ReadString  0x02045CAC  arm
 *   PRINTSYS_PrintQueColor  0x0201C724  thumb
 *   d_021C8894  0x021C8894  data
 *   STRBUF_Create  0x020457B0  arm
 *   TRCARD_SIGN_GetBadgeDate  0x02008A54  thumb
 *   WORDSET_SetSlotNumber  0x0201EFA4  thumb
 *   WORDSET_SetSlotMonth  0x0201F230  thumb
 *   WORDSET_CopyTaggedText  0x0201F250  thumb
 *   STRBUF_Delete  0x02045808  arm
 *   d_021C88B4  0x021C88B4  data
 *   TOUCHPANEL_HitTrg  0x02035C08  arm
 *   TOUCHPANEL_HitCont  0x02035BA4  arm
 *   TOUCHPANEL_GetPointCont  0x02035CB8  arm
 *   KEY_GetTrg  0x020362DC  arm
 *   GFL_USE_PlaySeDefaultVolume  0x020061E4  thumb
 *   VIEWER_ACTOR_HandleTouchDrag  0x021C842C  thumb
 *   d_021C898C  0x021C898C  data
 *   d_021C8808  0x021C8808  data
 *   CLACT_SetActorAnimSeq  0x0204B878  arm
 *   UI_SetInputMode  0x020355D8  arm
 *   GAME_DATA_ContainsRecentId  0x02012BF8  thumb
 *   GAME_DATA_SetRecentId  0x02012BE0  thumb
 *   CLACT_SetActorDrawEnable  0x0204B3DC  arm
 *   GAME_DATA_GetMiscSave  0x02012F08  thumb
 *   MISC_GetBadge  0x0200C234  thumb
 *   GF_STANDARD_CopyCachedRtc  0x0203F49C  arm
 *   TRCARD_SIGN_SetLastBadgeTime  0x02008A34  thumb
 *   TRCARD_SIGN_SetBadgeTimer  0x02008ADC  thumb
 *   TRCARD_SIGN_GetLastBadgeTime  0x02008A44  thumb
 *   TRCARD_SIGN_GetBadgeTimer  0x02008ACC  thumb
 *   RTC_ConvertDateTimeToSecond  0x02089004  arm
 *   RTC_ConvertSecondToDateTime  0x020891E0  arm
 *   _ll_sdiv  0x0209BE5C  arm
 *   GX_LoadOBJPltt  0x0207E51C  arm
 *   G3D_UTIL_GetResource  0x02048A0C  arm
 *   G3D_SYSTEM_GetResourceTex  0x02047250  arm
 *   NNS_GfdRegisterNewVramTransferTask  0x02061CA4  arm
 *   d_021C8874  0x021C8874  data
 */
#include "viewer_types.h"
#include "../version.h"

/* French, Italian and German print the month as a word; the others print its number. */
#define VIEWER_SET_MONTH(words, slot, month, mode) (PM_LANG_MONTH_AS_NAME ? WORDSET_SetSlotMonth(words, slot, month) : WORDSET_SetSlotNumber(words, slot, month, 2, mode, PM_LANG_HALF_WIDTH_DIGITS))

struct Obj;
struct Bank;
struct LightSlot;
struct LightSet;
struct G3dSys;
struct Ctx;
struct Rec;
struct AnmCtl;
struct Light;
struct Arg;
struct CharBuf;
struct Descriptor;
struct Cfg;
struct GfFont;
struct PrintSys;
struct Actor;
struct MsgBank;
struct U16Vec;
struct WordSet;
struct Blk34;
#include "../sdk_rtc.h"
struct Sub020089A8Obj;

typedef struct {
    int x;
    int y;
    int z;
    int cell;
    int chr;
    int anm;
} ViewerRowTemplate;

typedef struct {
    u16 x;
    u16 y;
    u16 z;
    u8 pri;
    u8 flags;
} ViewerRowPos;

typedef struct { int word[8]; } ViewerCamera;

#include "../sdk_fx.h"

typedef struct {
    VecFx32 trans;
    VecFx32 scale;
    MtxFx33 rot;
} ViewerTransform;

typedef struct {
    int value;
    int step;
} ViewerCounter;

#include "../sdk_rtc.h"

typedef struct {
    u8 rev;
    u8 numEntry;
    u16 sizeDictBlk;
    u16 dummy;
    u16 ofsEntry;
} ViewerTexDict;

typedef struct {
    u16 sizeUnit;
    u16 ofsName;
    u8 data[4];
} ViewerTexDictEntry;

typedef struct {
    u8 pad0[0x2C];
    u8 *plttData;
    u8 pad30[4];
    u16 ofsDict;
} ViewerTexInfo;

#include "../arm9/g3d_util.h"
#include "../arm9/clact.h"
#include "../arm9/g3d_system.h"
struct LightSetDesc;
struct LightSlotValue;
#include "../arm9/g3d_light.h"
struct G3dProjection;
#include "../arm9/bg_sys.h"
struct G3dObject;
#include "../arm9/g3d_camera.h"
#include "../arm9/fx_mtx33.h"
struct G3dCamera;
struct G3dObjectStatus;
#include "../arm9/bmp_win.h"
struct BmpWin;
struct Bmp;
typedef short s16_p07;
#include "../arm9/bmp.h"
#include "../arm9/bmp_menuwork.h"
#include "../arm9/gf_font.h"
struct PrintQueue;
#include "../arm9/printsys.h"
#include "../arm9/wipe.h"
struct Strbuf;
#include "../arm9/msgdata.h"
#include "../arm9/strbuf.h"
#include "../arm9/wordset.h"
#include "../arm9/touchpanel.h"
#include "../arm9/key.h"
#include "../arm9/gfl_use.h"
extern void VIEWER_ACTOR_HandleTouchDrag(ViewerTextWork *p, int idx);
#include "../arm9/ui.h"
#include "../arm9/game_data.h"
struct GameData;
struct MiscSave;
#include "../arm9/beacon.h"
#include "../arm9/gf_standard.h"
#include "../arm9/convert.h"
struct TrainerCardSignature;
#include "../arm9/trcard_sign.h"
#include "../arm9/gx_load2d.h"
#include "../arm9/nns_gfd_vram_transfer.h"
void VIEWER_ACTOR_CreateObjects(ViewerTextWork *p);
void VIEWER_ACTOR_DeleteObjects(ViewerTextWork *p);
void VIEWER_ACTOR_Init3D(ViewerTextWork *p);
void VIEWER_ACTOR_Exit3D(ViewerTextWork *p);
void VIEWER_ACTOR_CreateModel(ViewerTextWork *p);
void VIEWER_ACTOR_DeleteModel(ViewerTextWork *p);
void VIEWER_ACTOR_DrawModel(ViewerTextWork *p);
void VIEWER_ACTOR_InitBgWindow(ViewerTextWork *p);
void VIEWER_ACTOR_DeleteBgWindow(ViewerTextWork *p);
void VIEWER_ACTOR_FlushBgWindow(ViewerTextWork *p);
void VIEWER_ACTOR_CreateFont(ViewerTextWork *p);
void VIEWER_ACTOR_DeleteFont(ViewerTextWork *p);
void VIEWER_ACTOR_PrintQueMain(ViewerTextWork *p);
int VIEWER_ACTOR_DispatchState(ViewerTextWork *p);
int VIEWER_ACTOR_StepWaitWipeIn(ViewerTextWork *p);
int VIEWER_ACTOR_UpdateMain(ViewerTextWork *p);
int VIEWER_ACTOR_StepWaitActorAnim(ViewerTextWork *p);
int VIEWER_ACTOR_StartWipe(ViewerTextWork *p);
int VIEWER_ACTOR_StepWaitWipeOut(ViewerTextWork *p);
void VIEWER_ACTOR_PrintTextAt(ViewerTextWork *p, int x, int k, struct Strbuf *col);
void VIEWER_ACTOR_DrawLabel(ViewerTextWork *p, int mode, int idx);
int VIEWER_ACTOR_WrapAngle(int a, int b);
void VIEWER_ACTOR_StepBounce(ViewerTextWork *p);
void VIEWER_ACTOR_HandleDrag(ViewerTextWork *p, int unused, int touch, int x);
int VIEWER_ACTOR_HandleInput(ViewerTextWork *p);
int VIEWER_ACTOR_FindNearestPreset(int v);
void VIEWER_ACTOR_SelectActor(ViewerTextWork *p, int sel, int flag);
void VIEWER_ACTOR_ToggleFavorite(ViewerTextWork *p);
void VIEWER_ACTOR_SetPageCount(ViewerTextWork *p);
void VIEWER_ACTOR_SetRowDrawEnable(ViewerTextWork *p, int row, int v);
void VIEWER_ACTOR_UpdateRowVisibility(ViewerTextWork *p, int a, int b);
void VIEWER_ACTOR_SetSelection(ViewerTextWork *p, u16 v);
void VIEWER_ACTOR_SaveBadgeTimers(ViewerTextWork *p);
void VIEWER_ACTOR_LoadBadgeTimers(ViewerTextWork *p);
void VIEWER_ACTOR_LoadPalette(ViewerTextWork *p, int idx, int k);
void VIEWER_ACTOR_LoadTexture(ViewerTextWork *p, int idx, int k);
void VIEWER_ACTOR_SetRowActorDrawEnable(ViewerTextWork *p, int row, int n);
void VIEWER_ACTOR_RefreshRows(ViewerTextWork *p);
void VIEWER_ACTOR_HandleScrollRepeat(u8 *p, int value);
void VIEWER_ACTOR_ResetDragFlags(u8 *p);
void VIEWER_ACTOR_StepScrollCount(ViewerTextWork *p, int idx);
extern const ViewerRowTemplate d_021C8AA0[36];
extern const void *const d_021C8810;
extern const ViewerCamera d_021C896C;
extern const s16 FX_SinCosTable_[];
extern const unsigned char d_021C8834[];
extern const VecFx32 d_021C8950;
extern const VecFx32 d_021C8938;
extern const VecFx32 d_021C8944;
extern ViewerCounter d_021C8E80;
extern const int d_021C8894[];
extern const int d_021C88B4[8];
extern const unsigned char d_021C898C[];
extern const unsigned char d_021C8808[];
extern const int d_021C8874[];




/*
 * Addresses are Black-image addresses.
 */
void VIEWER_ACTOR_CreateObjects(ViewerTextWork *p)
{
    ViewerRowPos pos;
    int i;

    for (i = 0; i < 36; i++) {
        pos.x = d_021C8AA0[i].x;
        pos.y = d_021C8AA0[i].y;
        pos.z = d_021C8AA0[i].z;
        pos.flags = 0;
        pos.pri = 0x24 - i;
        p->actors.obj[i] = CLACT_CreateActor((struct Unit *)p->unit, p->resSet.set[d_021C8AA0[i].cell], p->resSet.set[d_021C8AA0[i].chr], p->resSet.set[d_021C8AA0[i].anm], (const struct ActorInitParam *)&pos, 0, 0x27);
        CLACT_SetActorAutoAnim(p->actors.obj[i], 1);
    }
}




void VIEWER_ACTOR_DeleteObjects(ViewerTextWork *p)
{
    CLACT_ReleaseCharacter(p->resSet.named.chr2);
    CLACT_ReleasePalette(p->resSet.named.palette2);
    CLACT_ReleaseCellAnim(p->resSet.named.cellAnim2);
    CLACT_ReleaseCharacter(p->resSet.named.chr);
    CLACT_ReleasePalette(p->resSet.named.palette);
    CLACT_ReleaseCellAnim(p->resSet.named.cellAnim);
    CLACT_DeleteUnit(p->unit);
    CLACT_ExitSystem();
}




void VIEWER_ACTOR_Init3D(ViewerTextWork *p)
{
    ViewerCamera cam;
    void *light;

    G3D_SYSTEM_Init(0, 1, 0, 1, 0x1000, 0x27, 0);
    light = G3D_LIGHT_CreateSlots((struct LightSetDesc *)(&d_021C8810), 0x27);
    p->lightSlot = light;
    G3D_LIGHT_ApplySlots(light);
    cam = d_021C896C;
    cam.word[1] = FX_SinCosTable_[0x16C];
    cam.word[2] = FX_SinCosTable_[0x16D];
    G3D_SYSTEM_SetProjection((struct G3dProjection *)(&cam));
    BG_SYS_SetPlaneVisible(0, 1);
    *(volatile u16 *)0x04000060 = (u16)((*(volatile u16 *)0x04000060 & ~(0x2000 | 0x1000)) | 0x8);
}




void VIEWER_ACTOR_Exit3D(ViewerTextWork *p)
{
    G3D_LIGHT_DeleteSlots(p->lightSlot);
    G3D_SYSTEM_Exit();
}




void VIEWER_ACTOR_CreateModel(ViewerTextWork *p)
{
    void *mdl;
    int i;
    int n;
    VecFx32 a;
    VecFx32 b;
    VecFx32 c;

    p->g3dUtil = G3D_UTIL_Create(10, 10, 0x27);
    p->g3dUnit = G3D_UTIL_AddUnit(p->g3dUtil, (const G3dUtilSetup *)d_021C8834);
    mdl = G3D_UTIL_GetObject(p->g3dUtil, p->g3dUnit);
    n = G3D_SYSTEM_GetObjectAnimeCount(mdl);
    for (i = 0; i < n; i++) {
        G3D_SYSTEM_EnableObjectAnime(mdl, (u16)i);
    }
    a = d_021C8950;
    b = d_021C8938;
    c = d_021C8944;
    p->camera = G3D_CAMERA_Create(0, FX_SinCosTable_[0x1C6], FX_SinCosTable_[0x1C7], 0x1555, 0, 0x1000, 0x400000, 0, &a, &c, &b, 0x27);
}




void VIEWER_ACTOR_DeleteModel(ViewerTextWork *p)
{
    G3D_CAMERA_Delete(p->camera);
    G3D_UTIL_RemoveUnit(p->g3dUtil, p->g3dUnit);
    G3D_UTIL_Delete(p->g3dUtil);
}




/*
 * closed:   blocking arm9 callees labelled and matched by seeds_3 (2026-09-28)
 *
 * Addresses are Black-image addresses.
 */
void VIEWER_ACTOR_DrawModel(ViewerTextWork *p)
{
    void *mdl;
    int out;
    ViewerTransform t;
    int n;
    int i;

    i = 0;
    t.scale.x = 0x1000;
    t.scale.y = 0x1000;
    t.scale.z = 0x1000;
    t.trans.x = 0;
    t.trans.y = 0;
    t.trans.z = 0;
    MTX_Identity33_(&t.rot);
    G3D_CAMERA_Reset(p->camera);
    mdl = G3D_UTIL_GetObject(p->g3dUtil, p->g3dUnit);
    n = G3D_SYSTEM_GetObjectAnimeCount(mdl);
    G3D_SYSTEM_GetObjectAnimeFrame(mdl, 0, &out);
    for (; i < n; i++) {
        G3D_SYSTEM_SetObjectAnimeFrame(mdl, (u16)i, &p->angle);
    }
    G3D_SYSTEM_DrawStart();
    G3D_SYSTEM_ApplyLookAt();
    G3D_SYSTEM_DrawObject(G3D_UTIL_GetObject(p->g3dUtil, p->g3dUnit), (struct G3dObjectStatus *)(&t));
    G3D_SYSTEM_DrawEnd();
    d_021C8E80.value += d_021C8E80.step;
}




void VIEWER_ACTOR_InitBgWindow(ViewerTextWork *p)
{
    BMP_WIN_Init(0x27);
    p->bgWindow = (void *)BMP_WIN_Create(4, 2, 10, 0x1C, 0xC, 0xF, 1);
    BMP_Clear(BMP_WIN_GetBmp(p->bgWindow), 0xF);
}




void VIEWER_ACTOR_DeleteBgWindow(ViewerTextWork *p)
{
    BMP_WIN_Delete(p->bgWindow);
    BMP_WIN_Exit();
}




void VIEWER_ACTOR_FlushBgWindow(ViewerTextWork *p)
{
    void *v;

    BMP_MENUWORK_DrawWindow(p->bgWindow, 0, 1, 0xE);
    v = p->bgWindow;
    BMP_WIN_TransferChars(v);
    BMP_WIN_MakeScreen(v);
    BG_SYS_PushTile(BMP_WIN_GetBgLayer(v));
}




void VIEWER_ACTOR_CreateFont(ViewerTextWork *p)
{
    p->font = GF_FONT_Create(0x17, 0, 0, 0, 0x27);
    p->printQue = (void *)PRINTSYS_QUE_Create((u32)0x27);
    p->printWindow = p->bgWindow;
    p->queDirty = 0;
}




void VIEWER_ACTOR_DeleteFont(ViewerTextWork *p)
{
    PRINTSYS_QUE_Delete(p->printQue);
    GF_FONT_Delete(p->font);
}




void VIEWER_ACTOR_PrintQueMain(ViewerTextWork *p)
{
    void *w;

    PRINTSYS_QUE_Main(p->printQue);
    w = p->printQue;
    if (p->queDirty) {
        if (PRINTSYS_QUE_IsExistTarget(w, BMP_WIN_GetBmp(p->printWindow)) == 0) {
            BMP_WIN_TransferChars(p->printWindow);
            p->queDirty = 0;
        }
    }
}




extern int (*const d_021C8E58[])(ViewerTextWork *p);




int VIEWER_ACTOR_DispatchState(ViewerTextWork *p)
{
    return d_021C8E58[p->state](p);
}




int VIEWER_ACTOR_StepWaitWipeIn(ViewerTextWork *p)
{
    if (WIPE_SYS_EndCheck()) {
        p->state = 1;
    }
    return 1;
}




int VIEWER_ACTOR_UpdateMain(ViewerTextWork *p)
{
    if (PRINTSYS_QUE_IsFinished(p->printQue) == 0) {
        return 1;
    }
    VIEWER_ACTOR_HandleInput((ViewerTextWork *)p);
    VIEWER_ACTOR_RefreshRows((ViewerTextWork *)p);
    return 1;
}




int VIEWER_ACTOR_StepWaitActorAnim(ViewerTextWork *p)
{
    switch (p->action) {
    case 0x12:
        if (CLACT_IsActorAnimActive(p->actors.named.actorC) == 0) {
            p->state = 3;
        }
    case 0x13:
        if (CLACT_IsActorAnimActive(p->actors.named.actorB) == 0) {
            p->state = 3;
        }
    case 0x10:
        if (CLACT_IsActorAnimActive(p->actors.named.actorA) == 0) {
            p->state = 3;
        }
    }
    return 1;
}




int VIEWER_ACTOR_StartWipe(ViewerTextWork *p)
{
    WIPE_SYS_Start(0, 0, 0, 0, 6, 1, 0x27);
    p->state = 4;
    return 1;
}




int VIEWER_ACTOR_StepWaitWipeOut(ViewerTextWork *p)
{
    if (WIPE_SYS_EndCheck()) {
        if (p->action == 0x12) {
            p->parent->exitCode = 0;
            p->parent->nextScreen = 1;
            p->state = 0;
        } else if (p->action == 0x13) {
            p->parent->exitCode = 0;
            p->parent->nextScreen = 0;
            p->state = 0;
        } else if (p->action == 0x10) {
            p->parent->exitCode = 3;
            p->state = 0;
        }
        return 0;
    }
    return 1;
}




void VIEWER_ACTOR_PrintTextAt(ViewerTextWork *p, int x, int k, struct Strbuf *col)
{
    void *v;

    MSGDATA_ReadString(p->msgBank, x + d_021C8894[k], (void *)col);
    v = p->printQue;
    PRINTSYS_PrintQueColor(v, (struct Bmp *)BMP_WIN_GetBmp(p->printWindow), (int)0, (s16)(x << 5), (struct Strbuf *)col, (struct GfFont *)p->font, (int)0x44F);
    p->queDirty = 1;
}




/*
 * callee:   0x02008A54 (arm9, labelled by seeds_3) is still a near miss; its one call site
 *           here attests through the sole-ref class (docs/notes/pkt_02008A54.c.txt)
 *
 * Addresses are Black-image addresses.
 */
void VIEWER_ACTOR_DrawLabel(ViewerTextWork *p, int mode, int idx)
{
    void *str;
    struct BadgeDate r;
    void *v;
    int i;

    str = STRBUF_Create(0x68, 0x27);
    BMP_Clear(BMP_WIN_GetBmp(p->bgWindow), 0xF);
    switch (mode) {
    case 0:
        r = TRCARD_SIGN_GetBadgeDate(p->saveBlock, idx);
        WORDSET_SetSlotNumber(p->wordSet, 0, r.year + 0x7D0, 4, 0, PM_LANG_HALF_WIDTH_DIGITS);
        VIEWER_SET_MONTH(p->wordSet, 1, r.month, 0);
        WORDSET_SetSlotNumber(p->wordSet, 2, r.day, 2, 0, PM_LANG_HALF_WIDTH_DIGITS);
        MSGDATA_ReadString(p->msgBank, idx * 3 + 0x58, str);
        WORDSET_CopyTaggedText(p->wordSet, p->strbuf, str);
        v = p->printQue;
        PRINTSYS_PrintQueColor(v, (struct Bmp *)BMP_WIN_GetBmp(p->printWindow), (int)0, (s16)0, (struct Strbuf *)p->strbuf, (struct GfFont *)p->font, (int)0x44F);
        p->queDirty = 1;
        for (i = 1; i < 3; i++) {
            MSGDATA_ReadString(p->msgBank, i + (idx * 3 + 0x58), str);
            v = p->printQue;
            PRINTSYS_PrintQueColor(v, (struct Bmp *)BMP_WIN_GetBmp(p->printWindow), (int)0, (s16)(i << 5), (struct Strbuf *)str, (struct GfFont *)p->font, (int)0x44F);
            p->queDirty = 1;
        }
        break;
    case 1:
        for (i = 0; i < 2; i++) {
            VIEWER_ACTOR_PrintTextAt((ViewerTextWork *)p, i, idx, str);
        }
        if (p->rowEnabled[idx]) {
            VIEWER_ACTOR_PrintTextAt((ViewerTextWork *)p, 2, idx, str);
        }
        break;
    }
    STRBUF_Delete(str);
}



int VIEWER_ACTOR_WrapAngle(int a, int b)
{
    if (a >= b) {
        return a % b;
    }
    if (a < 0) {
        a += 0x100000;
    }
    return a;
}



void VIEWER_ACTOR_StepBounce(ViewerTextWork *p)
{
    int v = p->spin;

    if (v > 0x1000) {
        p->spin = v - 0x190;
    } else if (v < -0x1000) {
        p->spin = v + 0x190;
    } else if (v == 0) {
        p->spin = 0x1000;
    }
}





void VIEWER_ACTOR_HandleDrag(ViewerTextWork *p, int unused, int touch, int x)
{
    int i;
    int v;
    int d;

    if (p->touchState == 0 && touch != 0) {
        p->dragStartAngle = p->angle;
        p->dragStartX = x;
    } else if (p->touchState == 1 && touch == 1) {
        p->angle = p->dragStartAngle + ((x - p->dragStartX) << 10);
        p->angle = VIEWER_ACTOR_WrapAngle(p->angle, 0x100000);
    } else if (p->touchState == 1 && touch == 0) {
        if (p->dragPrevX != 0) {
            p->spin = (p->dragX - p->dragPrevX) << 11;
        }
        if (p->spin > 40000) {
            p->spin = 40000;
        } else if (p->spin < -40000) {
            p->spin = -40000;
        }
    }
    if (p->touchState == 0 && touch == 0) {
        p->angle = p->angle + p->spin;
        p->angle = VIEWER_ACTOR_WrapAngle(p->angle, 0x100000);
        if (p->snap >= 0) {
            if (p->snapAngle > p->angle - 50000 && p->snapAngle < p->angle + 50000) {
                p->spin = 0;
                p->angle = p->snapAngle;
                p->snap = -1;
            }
        } else {
            VIEWER_ACTOR_StepBounce((ViewerTextWork *)p);
            for (i = 0; i < 8; i++) {
                v = d_021C88B4[i];
                if (v > p->angle - 10000 && v < p->angle + 10000) {
                    d = p->spin;
                    if (d < 0) {
                        d = -d;
                    }
                    if (d < 10000) {
                        p->angle = v;
                        p->spin = 0;
                    }
                }
            }
        }
    }
    p->dragPrevX = p->dragX;
    p->dragX = x;
    p->touchState = touch;
}





int VIEWER_ACTOR_HandleInput(ViewerTextWork *p)
{
    int x = 0;
    int y = 0;
    int flag = 0;
    int ret;
    int b;
    int a;
    int c;

    ret = TOUCHPANEL_HitTrg((const TouchHitTable *)d_021C898C);
    a = TOUCHPANEL_HitCont((const TouchHitTable *)d_021C898C);
    b = TOUCHPANEL_HitTrg((const TouchHitTable *)d_021C8808);
    c = TOUCHPANEL_HitCont((const TouchHitTable *)d_021C8808);
    TOUCHPANEL_GetPointCont((u32 *)(&x), (u32 *)(&y));
    if (KEY_GetTrg() & 2) {
        GFL_USE_PlaySeDefaultVolume(0x551);
        flag = 1;
        ret = 0x13;
    } else if (KEY_GetTrg() & 0x400) {
        GFL_USE_PlaySeDefaultVolume(0x551);
        ret = 0x12;
    } else if (KEY_GetTrg() & 0x800) {
        ret = 0x11;
    } else if (KEY_GetTrg() & 1) {
        ret = 0x10;
    }
    VIEWER_ACTOR_SelectActor((ViewerTextWork *)p, ret, flag);
    VIEWER_ACTOR_HandleDrag((ViewerTextWork *)p, b, c + 1, x);
    VIEWER_ACTOR_HandleTouchDrag((ViewerTextWork *)p, a);
    return ret;
}













int VIEWER_ACTOR_FindNearestPreset(int v)
{
    int i;

    for (i = 0; i < 8; i++) {
        if (d_021C88B4[i] > v - 10000 && d_021C88B4[i] < v + 10000) {
            break;
        }
    }
    if (i == 8) {
        i = 0;
    }
    return i;
}













void VIEWER_ACTOR_SelectActor(ViewerTextWork *p, int sel, int flag)
{
    int idx;

    if (sel == -1) {
        return;
    }
    switch (sel) {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
        if (p->rowEnabled[sel] == 0) {
            return;
        }
        GFL_USE_PlaySeDefaultVolume(0x65F);
        VIEWER_ACTOR_DrawLabel((ViewerTextWork *)p, 0, sel);
        VIEWER_ACTOR_FlushBgWindow((ViewerTextWork *)p);
        p->snap = 0;
        p->snapAngle = d_021C88B4[sel];
        p->spin = 40000;
        return;
    case 8:
    case 9:
    case 10:
    case 11:
    case 12:
    case 13:
    case 14:
    case 15:
        if (p->spin != 0) {
            return;
        }
        idx = VIEWER_ACTOR_FindNearestPreset(p->angle);
        GFL_USE_PlaySeDefaultVolume(0x65E);
        VIEWER_ACTOR_DrawLabel((ViewerTextWork *)p, 1, (sel - 8 + idx) % 8);
        VIEWER_ACTOR_FlushBgWindow((ViewerTextWork *)p);
        return;
    case 16:
        p->state = 2;
        p->action = sel;
        GFL_USE_PlaySeDefaultVolume(0x54C);
        CLACT_SetActorAnimSeq(p->actors.named.actorA, 0xC);
        return;
    case 17:
        VIEWER_ACTOR_ToggleFavorite((ViewerTextWork *)p);
        return;
    case 18:
        GFL_USE_PlaySeDefaultVolume(0x556);
        p->state = 2;
        p->action = sel;
        CLACT_SetActorAnimSeq(p->actors.named.actorC, 8);
        return;
    case 19:
        GFL_USE_PlaySeDefaultVolume(0x551);
        p->state = 2;
        p->action = sel;
        CLACT_SetActorAnimSeq(p->actors.named.actorB, 9);
        if (flag) {
            UI_SetInputMode(0);
        } else {
            UI_SetInputMode(1);
        }
        return;
    }
}













void VIEWER_ACTOR_ToggleFavorite(ViewerTextWork *p)
{
    int v = GAME_DATA_ContainsRecentId((struct GameData *)p->parent->gameData, 0x17) ^ 1;

    CLACT_SetActorAnimSeq(p->actors.named.actorD, v + 6);
    GAME_DATA_SetRecentId(p->parent->gameData, 0x17, v);
    GFL_USE_PlaySeDefaultVolume(0x646);
}













void VIEWER_ACTOR_SetPageCount(ViewerTextWork *p)
{
    p->page = 0;
    p->pageCount = p->rowCount / 10;
    if (p->rowCount % 10) {
        p->pageCount++;
    }
}













void VIEWER_ACTOR_SetRowDrawEnable(ViewerTextWork *p, int row, int v)
{
    int i;

    for (i = 0; i < 3; i++) {
        CLACT_SetActorDrawEnable(p->actors.named.rowSubActor[row * 3 + i], v);
    }
}











void VIEWER_ACTOR_UpdateRowVisibility(ViewerTextWork *p, int a, int b)
{
    void *obj;
    int i;

    obj = GAME_DATA_GetMiscSave(p->parent->gameData);
    for (i = 0; i < 8; i++) {
        if (MISC_GetBadge(obj, i)) {
            CLACT_SetActorDrawEnable(p->actors.named.rowActor[i], 1);
            VIEWER_ACTOR_SetRowDrawEnable((ViewerTextWork *)p, i, 1);
            p->rowEnabled[i] = 1;
        } else {
            CLACT_SetActorDrawEnable(p->actors.named.rowActor[i], 0);
            VIEWER_ACTOR_SetRowDrawEnable((ViewerTextWork *)p, i, 0);
            p->rowEnabled[i] = 0;
        }
    }
    CLACT_SetActorAnimSeq(p->actors.named.actorD, GAME_DATA_ContainsRecentId((struct GameData *)p->parent->gameData, 0x17) + 6);
}










void VIEWER_ACTOR_SetSelection(ViewerTextWork *p, u16 v)
{
    p->page = v;
    VIEWER_ACTOR_UpdateRowVisibility((ViewerTextWork *)p, v, p->pageCount);
    VIEWER_ACTOR_RefreshRows((ViewerTextWork *)p);
}










void VIEWER_ACTOR_SaveBadgeTimers(ViewerTextWork *p)
{
    RTCDate date;
    RTCTime time;
    s64 sec;
    int i;

    GF_STANDARD_CopyCachedRtc((RTCDate *)(&date), (RTCTime *)(&time));
    sec = RTC_ConvertDateTimeToSecond(&date, &time);
    TRCARD_SIGN_SetLastBadgeTime(p->saveBlock, (u32)sec, (u32)(sec >> 32));
    for (i = 0; i < 8; i++) {
        TRCARD_SIGN_SetBadgeTimer(p->saveBlock, i, p->badgeTimer[i]);
    }
}










void VIEWER_ACTOR_LoadBadgeTimers(ViewerTextWork *p)
{
    RTCDate date;
    RTCDate date2;
    RTCTime time;
    RTCTime time2;
    s64 saved;
    s64 hours;
    int i;

    saved = TRCARD_SIGN_GetLastBadgeTime(p->saveBlock);
    RTC_ConvertSecondToDateTime(&date2, &time2, saved);
    GF_STANDARD_CopyCachedRtc((RTCDate *)(&date), (RTCTime *)(&time));
    hours = (RTC_ConvertDateTimeToSecond(&date, &time) - saved) / 3600;
    if (hours < 0) {
        hours = 0;
    }
    for (i = 0; i < 8; i++) {
        p->badgeTimer[i] = TRCARD_SIGN_GetBadgeTimer(p->saveBlock, i);
        p->badgeTimer[i] -= hours * 2;
        if (p->badgeTimer[i] < 0) {
            p->badgeTimer[i] = 0;
        }
    }
    for (i = 0; i < 8; i++) {
        p->lastPaletteIndex[i] = 0xFF;
    }
}










void VIEWER_ACTOR_LoadPalette(ViewerTextWork *p, int idx, int k)
{
    if (k > 2) {
        k = 2;
    }
    GX_LoadOBJPltt((unsigned short *)p->res158[k]->data + idx * 16, idx * 32, 32);
}








static inline void *DictGetByIdx(const ViewerTexDict *d, u32 idx)
{
    if (d && idx < d->numEntry) {
        const ViewerTexDictEntry *h = (const ViewerTexDictEntry *)((const u8 *)d + d->ofsEntry);
        return (void *)((const u8 *)h->data + h->sizeUnit * idx);
    }
    return 0;
}








static inline const u16 *TexGetPltt(const ViewerTexInfo *t, u32 idx)
{
    if (t && t->ofsDict) {
        return DictGetByIdx((const ViewerTexDict *)((const u8 *)t + t->ofsDict), idx);
    }
    return 0;
}








void VIEWER_ACTOR_LoadTexture(ViewerTextWork *p, int idx, int k)
{
    u8 *dst;
    ViewerTexInfo *tex;
    const u16 *e;

    if (k > 2) {
        k = 2;
    }
    dst = p->res170[k]->data;
    tex = (ViewerTexInfo *)G3D_SYSTEM_GetResourceTex((void *)G3D_UTIL_GetResource(p->g3dUtil, 0));
    e = TexGetPltt(tex, idx);
    NNS_GfdRegisterNewVramTransferTask(1, (uptr)(tex->plttData + *e * 8), (dst + d_021C8874[idx] * 32), 0x20);
}







void VIEWER_ACTOR_SetRowActorDrawEnable(ViewerTextWork *p, int row, int n)
{
    int i;
    int lim = n - 3;

    for (i = 0; i < 3; i++) {
        if (n < 3) {
            CLACT_SetActorDrawEnable(p->actors.named.rowSubActor[row * 3 + i], 0);
        } else if (i <= lim) {
            CLACT_SetActorDrawEnable(p->actors.named.rowSubActor[row * 3 + i], 1);
        } else {
            CLACT_SetActorDrawEnable(p->actors.named.rowSubActor[row * 3 + i], 0);
        }
    }
}






void VIEWER_ACTOR_RefreshRows(ViewerTextWork *p)
{
    int i;

    for (i = 0; i < 8; i++) {
        p->paletteIndex[i] = p->badgeTimer[i] / 0x60;
        if (p->paletteIndex[i] > 5) {
            p->paletteIndex[i] = 5;
        }
        if (p->paletteIndex[i] != p->lastPaletteIndex[i]) {
            VIEWER_ACTOR_LoadPalette((ViewerTextWork *)p, i, p->paletteIndex[i]);
            VIEWER_ACTOR_LoadTexture((ViewerTextWork *)p, i, p->paletteIndex[i]);
            VIEWER_ACTOR_SetRowActorDrawEnable((ViewerTextWork *)p, i, p->paletteIndex[i]);
        }
        p->lastPaletteIndex[i] = p->paletteIndex[i];
    }
}






void VIEWER_ACTOR_HandleScrollRepeat(u8 *p, int value)
{
    if (p[5] == 0) {
        GFL_USE_PlaySeDefaultVolume(value > 0x210 ? 0x661 : 0x660);
        p[5] = 5;
    } else {
        p[5]--;
    }
}






void VIEWER_ACTOR_ResetDragFlags(u8 *p) { p[2] = 0; p[3] = 0; }






void VIEWER_ACTOR_StepScrollCount(ViewerTextWork *p, int idx)
{
    s32 *count = p->badgeTimer;

    if (count[idx] < 0x23F) {
        count[idx]++;
    }
}


/* Returns |cur - prev| and stores the drag direction (-1 back, 1 forward) in dir. */
static inline int CalcDragDelta(s8 *dir, u32 prev, u32 cur)
{
    int d;

    if (prev > cur) {
        d = prev - cur;
        *dir = -1;
    } else {
        d = cur - prev;
        *dir = 1;
    }
    return d;
}


/* Touch drag over an actor: adjusts the pressed actor's value by the drag delta. */
void VIEWER_ACTOR_HandleTouchDrag(ViewerTextWork *p, int idx)
{
    int hit = 0;
    u32 x = 0xFFFF;
    u32 y = 0xFFFF;
    int dx, dy;
    s8 s;

    TOUCHPANEL_GetPointCont(&x, &y);
    if (x != 0xFFFF && y != 0xFFFF && p->prevX != 0xFFFF && p->prevY != 0xFFFF && idx != -1
        && (u32)idx < 8 && p->rowEnabled[idx] != 0) {
        dx = CalcDragDelta(&p->dragDirX, p->prevX, x);
        if (dx >= 3 && dx <= 40) {
            dy = CalcDragDelta(&p->dragDirY, p->prevY, y);
            if (dy <= 40) {
                hit = 1;
                VIEWER_ACTOR_HandleScrollRepeat(p->scrollRepeat, p->badgeTimer[idx]);
            } else {
                VIEWER_ACTOR_ResetDragFlags(p->scrollRepeat);
            }
        } else if (dx <= 40) {
            dy = CalcDragDelta(&p->dragDirY, p->prevY, y);
            if (dy >= 3 && dy <= 40) {
                hit = 1;
                VIEWER_ACTOR_HandleScrollRepeat(p->scrollRepeat, p->badgeTimer[idx]);
            } else {
                VIEWER_ACTOR_ResetDragFlags(p->scrollRepeat);
            }
        }
        if (hit) {
            VIEWER_ACTOR_StepScrollCount(p, idx);
        }
    }
    p->prevX = x;
    p->prevY = y;
}
