/*
 * file:     hall_of_fame_scene.c
 * unit:     yes
 * function: HALL_OF_FAME_InitBackgrounds, HALL_OF_FAME_ExitBackgrounds, HALL_OF_FAME_LoadBackgroundGraphics, HALL_OF_FAME_SetupBlendRegs, HALL_OF_FAME_InitText, HALL_OF_FAME_ExitText, HALL_OF_FAME_StartBgm, HALL_OF_FAME_ReleaseWaveArc, HALL_OF_FAME_CollectPartyMons, HALL_OF_FAME_LoadMonInfo, HALL_OF_FAME_PrepareMonVoice, HALL_OF_FAME_Setup3dState, HALL_OF_FAME_Init3d, HALL_OF_FAME_Exit3d, HALL_OF_FAME_DrawMonSprite3d, HALL_OF_FAME_DrawParticles, HALL_OF_FAME_InitParticleHeap, HALL_OF_FAME_ExitParticleHeap, HALL_OF_FAME_InitParticleManager, HALL_OF_FAME_ExitParticleManager, HALL_OF_FAME_CreateMonParticle, HALL_OF_FAME_DeleteMonParticle, HALL_OF_FAME_StartMonParticle, HALL_OF_FAME_CreateBackdropParticle, HALL_OF_FAME_DeleteBackdropParticle, HALL_OF_FAME_StartBackdropParticle, HALL_OF_FAME_SetParticleCamera, HALL_OF_FAME_InitMcss, HALL_OF_FAME_ExitMcss, HALL_OF_FAME_AddMonSprite, HALL_OF_FAME_DeleteMonSprite, HALL_OF_FAME_MoveMonSpriteX, HALL_OF_FAME_OnMonAnimDone, HALL_OF_FAME_StartMonAnimCallback, HALL_OF_FAME_RunState, HALL_OF_FAME_StateInit, HALL_OF_FAME_StateExit, HALL_OF_FAME_StateWaitFade, HALL_OF_FAME_StateWaitCounter, HALL_OF_FAME_StateSetupMonScene, HALL_OF_FAME_StateTeardownMonScene, HALL_OF_FAME_StateMonSequence, HALL_OF_FAME_StateSetupTrainerScene, HALL_OF_FAME_StateTeardownTrainerScene, HALL_OF_FAME_StateTrainerScene, HALL_OF_FAME_BeginFadeIn, HALL_OF_FAME_BeginFadeOut, HALL_OF_FAME_BeginCountdown, HALL_OF_FAME_RandomizeJitter, HALL_OF_FAME_ApplyJitterStep, HALL_OF_FAME_EnableBgEffects, HALL_OF_FAME_InitActorSystem, HALL_OF_FAME_ExitActorSystem, HALL_OF_FAME_UpdateActors, HALL_OF_FAME_MoveActorBy, HALL_OF_FAME_GetActorPos, HALL_OF_FAME_MoveActorRelative, HALL_OF_FAME_SetActorVisible, HALL_OF_FAME_PlayActorAnim, HALL_OF_FAME_IsActorAnimActive, HALL_OF_FAME_ResetResourceIds, HALL_OF_FAME_ReleaseCharacter, HALL_OF_FAME_ReleasePalette, HALL_OF_FAME_ReleaseCellAnim, HALL_OF_FAME_ReleaseAllResources, HALL_OF_FAME_CreateActorFromTemplate, HALL_OF_FAME_DeleteActor, HALL_OF_FAME_DeleteAllActors, HALL_OF_FAME_LoadMonActors
 * address:  0x021B6254
 * region:   ov180
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   BG_SYS_InitBgLayer 0x0203FCA0 arm
 *   BUTTON_MAN_RotScaleMtx22 0x02051E74 arm
 *   G2x_SetBGyAffine_ 0x0207D59C arm
 *   BG_SYS_ChangeScroll 0x02041EE4 arm
 *   BG_SYS_ChangeCenter 0x02041FB0 arm
 *   BG_SYS_SetMainPlaneVisible 0x020434DC arm
 *   BG_SYS_SetSubPlaneVisible 0x02043598 arm
 *   BG_SYS_LoadPlttEntry 0x02040EBC arm
 *   gHallOfFameBgSetup 0x021B80E8 data ov180 a4
 *   BG_SYS_FreeLayerBuf 0x020403F4 arm
 *   ARC_TOOL_CreateHandle  0x020490F4  arm
 *   ARC_UTIL_UploadPaletteFromHandleWhole  0x02049B68  arm
 *   ARC_UTIL_UploadBgCharFromHandle  0x02049658  arm
 *   ARC_UTIL_UploadBgPaletteFromHandle  0x020498F4  arm
 *   ARC_TOOL_DeleteHandle  0x02049238  arm
 *   G2x_SetBlendAlpha_ 0x0207D63C arm
 *   MSGDATA_CreateFromArchive 0x02045B38 arm
 *   GF_FONT_Create 0x0201D7EC thumb
 *   WORDSET_CreateDefault 0x0201EC64 thumb
 *   STRBUF_Create 0x020457B0 arm
 *   STRBUF_Delete 0x02045808 arm
 *   WORDSET_Delete 0x0201ED04 thumb
 *   GF_FONT_Delete 0x0201D83C thumb
 *   MSGDATA_Delete 0x02045C04 arm
 *   gHallOfFameWaveArcIds 0x021B8018 data a4
 *   GFL_USE_LoadWaveArcSet 0x02005A98 thumb
 *   GFL_USE_CancelChangeAndPlayBgm 0x02005D90 thumb
 *   GFL_USE_ReleaseWaveArcSet 0x02005B04 thumb
 *   POKEPARTY_GetCount 0x0201AA18 thumb
 *   POKEPARTY_GetMember 0x0201AB28 thumb
 *   POKE_TOOL_DecodePartyParam 0x02017D30 thumb
 *   POKE_TOOL_GetPartyValue 0x02017E1C thumb
 *   POKE_TOOL_EncodePartyParam 0x02017D70 thumb
 *   PM_VOICE_GetPerapVoiceSave 0x02006CAC thumb
 *   PM_VOICE_Prepare 0x020069D4 thumb
 *   G3X_SetFog 0x0207DC44 arm
 *   G3X_SetClearColor 0x0207DD24 arm
 *   G3D_SYSTEM_SetLight 0x02046A94 arm
 *   G3D_SYSTEM_SetSwapBuffersMode 0x02046BE0 arm
 *   gHallOfFameLights 0x021B8040 data a4
 *   G3D_SYSTEM_Init 0x02046440 arm
 *   G3D_UTIL_Create 0x02047CFC arm
 *   G3D_UTIL_Delete  0x02047E54  arm
 *   G3D_SYSTEM_Exit  0x02046788  arm
 *   G3D_SYSTEM_DrawStart 0x02047964 arm
 *   G3D_SYSTEM_ApplyLookAt 0x020479D8 arm
 *   MCSS_Main 0x02014C08 thumb
 *   MCSS_Draw 0x02014D2C thumb
 *   G3D_SYSTEM_DrawEnd 0x02047970 arm
 *   DOUBLE3DDISP_GetMode 0x0204EA38 arm
 *   PARTICLE_Main 0x02050BE8 arm
 *   DOUBLE3DDISP_SetDrawDone 0x0204EA4C arm
 *   DOUBLE3DDISP_Init 0x0204E8C0 arm
 *   DOUBLE3DDISP_Exit 0x0204EA0C arm
 *   PARTICLE_InitManager 0x02050B80 arm
 *   PARTICLE_ExitManager 0x02050ED4 arm
 *   PARTICLE_CreateSystemDefault 0x02050C04 arm
 *   PARTICLE_LoadArchiveMember 0x0205121C arm
 *   PARTICLE_SetupSystem 0x02051230 arm
 *   gHallOfFameEffectArchives 0x021B8108 data a4
 *   PARTICLE_DeleteSystem  0x02050DB8  arm
 *   PARTICLE_StartEffect 0x020515B4 arm
 *   gHallOfFameMonEffectOrigin 0x021B80CC data a4
 *   PARTICLE_ReleaseCamera 0x02051758 arm
 *   PARTICLE_InitCamera 0x02051648 arm
 *   MCSS_Init 0x02014B08 thumb
 *   MCSS_SetTextureTransAdrs 0x02016020 thumb
 *   MCSS_SetOrthoMode 0x02015BF0 thumb
 *   G3D_CAMERA_Create 0x02048A24 arm
 *   G3D_CAMERA_Reset 0x02048AD0 arm
 *   gHallOfFameCameraPos 0x021B8034 data a4
 *   gHallOfFameCameraTarget 0x021B801C data a4
 *   gHallOfFameCameraUp 0x021B8028 data a4
 *   G3D_CAMERA_Delete  0x02048AC4  arm
 *   MCSS_Exit  0x02014BA8  thumb
 *   gHallOfFameMonScale 0x021B80C0 data a4
 *   MCSS_TOOL_MakeAddWorkFromPP 0x02017100 thumb
 *   MCSS_Add 0x020159C8 thumb
 *   MCSS_SetScale 0x02015CAC thumb
 *   MCSS_SetAnmStopFlag 0x02015E04 thumb
 *   MCSS_Del  0x02015BA4  thumb
 *   MCSS_GetPosition 0x02015C30 thumb
 *   MCSS_SetPosition 0x02015C48 thumb
 *   _fflt 0x0209BDBC arm
 *   _fmul 0x0209C95C arm
 *   _fdiv 0x0209CB8C arm
 *   _ffix 0x0209C494 arm
 *   MCSS_SetAnimCallback  0x02015F2C  thumb
 *   gHallOfFameStateTable 0x021B814C data a4
 *   HALL_OF_FAME_DrawMonScene 0x021B7D5C thumb ov180
 *   HALL_OF_FAME_DrawTrainerScene 0x021B7F30 thumb ov180
 *   BG_SYS_SetMainVisiblePlanes 0x02043534 arm
 *   BG_SYS_SetSubVisiblePlanes 0x020435F4 arm
 *   GXx_SetMasterBrightness_ 0x0207D534 arm
 *   HALL_OF_FAME_InitGraphicsSystem 0x021B6210 thumb ov180
 *   HALL_OF_FAME_ExitGraphicsSystem 0x021B621C thumb ov180
 *   WIPE_SYS_EndCheck 0x020221A4 thumb
 *   HALL_OF_FAME_SetVramBanks 0x021B61D4 thumb ov180
 *   HALL_OF_FAME_SetupDisplay 0x021B6224 thumb ov180
 *   HALL_OF_FAME_CreateMonSceneObjects 0x021B7CF0 thumb ov180
 *   HALL_OF_FAME_AddVBlankTaskMon 0x021B6158 thumb ov180
 *   HALL_OF_FAME_RemoveVBlankTask 0x021B6188 thumb ov180
 *   HALL_OF_FAME_DeleteMonSceneObjects 0x021B7D44 thumb ov180
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   GFL_USE_IsSeqPlaying 0x02006254 thumb
 *   HALL_OF_FAME_PrintMonInfo 0x021B78E0 thumb ov180
 *   HALL_OF_FAME_UpdatePlatePositions 0x021B7C08 thumb ov180
 *   HALL_OF_FAME_LoadUiPalette 0x021B7750 thumb ov180
 *   PM_VOICE_Start 0x02006A64 thumb
 *   PM_VOICE_IsSlotActive 0x02006BD0 thumb
 *   BG_SYS_SetLcdSwap 0x0204363C arm
 *   HALL_OF_FAME_CreateTrainerSceneObjects 0x021B7D80 thumb ov180
 *   HALL_OF_FAME_AddVBlankTaskTrainer 0x021B6170 thumb ov180
 *   HALL_OF_FAME_DeleteTrainerSceneObjects 0x021B7F0C thumb ov180
 *   GFL_USE_IsBgmFading 0x02005E50 thumb
 *   GFL_USE_CancelChangeAndStopBgm 0x02005D28 thumb
 *   HALL_OF_FAME_SetPlateEnabled 0x021B7C60 thumb ov180
 *   MCSS_ResetAnmStopFlag 0x02015E4C thumb
 *   HALL_OF_FAME_SpawnSparkles 0x021B7F38 thumb ov180
 *   KEY_GetTrg 0x020362DC arm
 *   TOUCHPANEL_GetTrg 0x02035C60 arm
 *   GFL_USE_FadeOutBgm 0x02005E30 thumb
 *   WIPE_SYS_Start 0x0202208C thumb
 *   GFL_USE_GetRandom 0x020056EC thumb
 *   BG_SYS_ChangeRotation  0x02041F28  arm
 *   gHallOfFameClactConfigMain 0x021B827C data a4
 *   gHallOfFameClactConfigSub 0x021B8298 data a4
 *   HALL_OF_FAME_GetVramBanksAddr 0x021B61FC thumb ov180
 *   CLACT_InitSystem 0x0204A48C arm
 *   CLACT_CreateUnit 0x0204B100 arm
 *   BMP_OAM_CreateSys 0x02025538 thumb
 *   BMP_OAM_DeleteSys 0x02025588 thumb
 *   CLACT_DeleteUnit 0x0204B1CC arm
 *   CLACT_ExitSystem 0x0204A5AC arm
 *   CLACT_GetActorAutoAnim 0x0204B944 arm
 *   CLACT_AddActorAnimFrame 0x0204B8D4 arm
 *   CLACT_DrawSystem 0x0204A600 arm
 *   CLACT_AddActorSurfacePos 0x0204B404 arm
 *   CLACT_GetActorSurfacePos 0x0204B454 arm
 *   CLACT_SetActorDrawEnable  0x0204B3DC  arm
 *   CLACT_SetActorAnimFrame 0x0204B8C4 arm
 *   CLACT_SetActorAnimSeq 0x0204B878 arm
 *   CLACT_SetActorAutoAnim 0x0204B92C arm
 *   CLACT_IsActorAnimActive  0x0204B98C  arm
 *   d_021B90CC     0x021B90CC  data  ov180  a4
 *   d_021B90E4     0x021B90E4  data  ov180  a4
 *   CLACT_ReleaseCharacter 0x0204A8D4 arm
 *   CLACT_ReleasePalette 0x0204ADA4 arm
 *   CLACT_ReleaseCellAnim  0x0204AFD8  arm
 *   CLACT_CreateActor 0x0204B294 arm
 *   CLACT_DeleteActor  0x0204B3B4  arm
 *   gHallOfFameMonTopTemplate 0x021B8174 data ov180 a4
 *   gHallOfFameMonBottomTemplate 0x021B818C data a4
 *   POKEGRA_OpenHandle 0x0202D7C8 thumb
 *   POKE_TOOL_CastToBoxParam 0x020185F0 thumb
 *   POKE_TOOL_DecodeBoxParam 0x02017DBC thumb
 *   POKEGRA_RegisterCgrPP 0x0202D934 thumb
 *   POKEGRA_RegisterPalettePP 0x0202D8D0 thumb
 *   POKEGRA_RegisterCellAnimPP 0x0202D9A4 thumb
 *   POKE_TOOL_EncodeBoxParam 0x02017DE4 thumb
 */
#include "hall_of_fame.h"
#include "../sdk_ioreg.h"
#include "../arm9/g3d_util.h"

#define REG(a) (*(volatile u16 *)(a))

struct BgTemplate;
struct Mtx22;
struct GfFont;
struct MsgBank;
struct WordSet;
struct Util;
struct U16Vec;
struct Sub02005A98Hdr;
struct Sav;
struct Util;
struct McssSys;
struct Light;
struct Stats;
struct Sub150;
struct Cfg;
struct Bank;
struct ClactVec2;
struct ClactActor;
struct ClactVec2;

/* Background setup block handed to the background init call (32 bytes). */
typedef struct HofBgSetup {
    u32 words[8];
} HofBgSetup;

/* 2x2 rotation and scale matrix. */
typedef struct HofMtx {
    int m[4];
} HofMtx;

typedef struct HofVec3 {
    int x, y, z;
} HofVec3;

/* Camera description of the particle system. */
typedef struct HofParticleCamera {
    int kind;                       /* 0x00 */
    int pitch;                      /* 0x04 */
    int yaw;                        /* 0x08 */
    int minPos;                     /* 0x0C */
    int maxPos;                     /* 0x10 */
    int reserved10;                 /* 0x14 */
    int scale;                      /* 0x18 */
    int reserved1C;                 /* 0x1C */
} HofParticleCamera;

/* Work record the 3D sprite system fills from a party member (36 bytes). */
typedef struct HofMcssParams {
    unsigned words[9];
} HofMcssParams;

/* Configuration of the actor system (28 bytes). */
typedef struct HofClactConfig {
    unsigned words[7];
} HofClactConfig;
union MtxFx22;

#include "../arm9/nns_g3d_anm_calc_types.h"
#include "../arm9/nns_g3d_anm_types.h"
#include "../sdk_nnsfnd.h"
#include "../arm9/bg_sys.h"
#include "../arm9/button_man.h"
#include "../arm9/g2.h"
#include "../arm9/arc_tool.h"
#include "../arm9/arc_util.h"
#include "../arm9/msgdata.h"
#include "../arm9/gf_font.h"
struct Strbuf;
#include "../arm9/strbuf.h"
#include "../arm9/wordset.h"
struct SndWaveSetHeader;
#include "../arm9/gfl_use.h"
struct Party;
#include "../arm9/pokeparty.h"
struct PokemonParam;
#include "../arm9/poke_tool.h"
struct SaveBlock;
#include "../arm9/pm_voice.h"
#include "../arm9/g3x.h"
struct G3dLight;
#include "../arm9/g3d_system.h"
#include "../arm9/mcss.h"
#include "../arm9/double3Ddisp.h"
struct ParticleSys;
struct VecFx32;
struct G3dCamera;
#include "../arm9/g3d_camera.h"
struct G3dCamera;
struct McssAddWork;
struct McssWork;
#include "../arm9/gx.h"
#include "../arm9/wipe.h"
#include "../arm9/key.h"
#include "../arm9/touchpanel.h"
struct DispVramCfg;
struct ClactSysInit;
#include "../arm9/clact.h"
struct BmpOamSys;
#include "../arm9/bmp_oam.h"
#include "../arm9/particle.h"
extern void CLACT_SetActorAnimFrame(struct ClactActor *,u32),CLACT_SetActorAnimSeq(struct ClactActor *,u16),CLACT_SetActorAutoAnim(struct ClactActor *,u32);
#include "../arm9/pokegra.h"
struct BoxPokemon;
extern int (*gHallOfFameStateTable[])(HallOfFameWork *);
extern const HofBgSetup gHallOfFameBgSetup;
extern const u32 gHallOfFameWaveArcIds[];
extern const unsigned char gHallOfFameLights[];
extern int gHallOfFameEffectArchives[];
extern HofVec3 gHallOfFameMonEffectOrigin;
extern unsigned gHallOfFameCameraPos[];
extern unsigned gHallOfFameCameraTarget[];
extern unsigned gHallOfFameCameraUp[];
extern const HofVec3 gHallOfFameMonScale;
extern const HofClactConfig gHallOfFameClactConfigMain, gHallOfFameClactConfigSub;
extern const HallOfFameActorTemplate gHallOfFameMonTopTemplate, gHallOfFameMonBottomTemplate;

void HALL_OF_FAME_InitBackgrounds(void)
{
    HofBgSetup bg = gHallOfFameBgSetup;
    HofMtx mtx;
    BG_SYS_InitBgLayer(3, (const struct BgTemplate *)&bg, 2);
    BG_SYS_InitBgLayer(7, (const struct BgTemplate *)&bg, 2);
    BUTTON_MAN_RotScaleMtx22((union MtxFx22 *)&mtx, 0, (s32)4096, 4096, 0);
    G2x_SetBGyAffine_(REG_BG3PA_ADDR, (union MtxFx22 *)(&mtx), 0, 0, 0, 0);
    G2x_SetBGyAffine_(REG_DB_BG3PA_ADDR, (union MtxFx22 *)(&mtx), 0, 0, 0, 0);
    BG_SYS_ChangeScroll(3, 0, 160);
    BG_SYS_ChangeScroll(3, 3, 112);
    BG_SYS_ChangeScroll(7, 0, 160);
    BG_SYS_ChangeScroll(7, 3, -152);
    BG_SYS_ChangeCenter(3, 9, 160);
    BG_SYS_ChangeCenter(3, 12, 160);
    BG_SYS_ChangeCenter(7, 9, 160);
    BG_SYS_ChangeCenter(7, 12, 160);
    BG_SYS_SetMainPlaneVisible(8, 1);
    BG_SYS_SetSubPlaneVisible(8, 1);
    BG_SYS_LoadPlttEntry(0, 0);
    BG_SYS_LoadPlttEntry(4, 0);
}

void HALL_OF_FAME_ExitBackgrounds(void)
{
    BG_SYS_SetMainPlaneVisible(8, 0);
    BG_SYS_SetSubPlaneVisible(8, 0);
    BG_SYS_FreeLayerBuf(7);
    BG_SYS_FreeLayerBuf(3);
}

void HALL_OF_FAME_LoadBackgroundGraphics(void)
{
    u8 *handle = ARC_TOOL_CreateHandle(0xd8, 0x8d);
    ARC_UTIL_UploadPaletteFromHandleWhole(handle, 1, 2, 0x6000, 0x20, 0x8d);
    ARC_UTIL_UploadPaletteFromHandleWhole(handle, 1, 6, 0x6000, 0x20, 0x8d);
    ARC_UTIL_UploadBgCharFromHandle(handle, 0x16, 3, 0, 0, 0, 0x8d);
    ARC_UTIL_UploadBgCharFromHandle(handle, 0x16, 7, 0, 0, 0, 0x8d);
    ARC_UTIL_UploadBgPaletteFromHandle(handle, 0x1c, 3, 0, 0, 0, 0x8d);
    ARC_UTIL_UploadBgPaletteFromHandle(handle, 0x1c, 7, 0, 0, 0, 0x8d);
    ARC_TOOL_DeleteHandle(handle);
}

void HALL_OF_FAME_SetupBlendRegs(void)
{
    G2x_SetBlendAlpha_((void *)REG_BLDCNT_ADDR, 1, 46, 6, 10);
    G2x_SetBlendAlpha_((void *)REG_DB_BLDCNT_ADDR, 1, 46, 6, 10);
}

void HALL_OF_FAME_InitText(HallOfFameWork *work)
{
    work->msgData = MSGDATA_CreateFromArchive(0, 2, 32, HOF_HEAP_ID);
    work->fontMain = GF_FONT_Create(23, 0, 0, 0, HOF_HEAP_ID);
    work->fontSub = GF_FONT_Create(23, 3, 0, 0, HOF_HEAP_ID);
    work->wordSet = WORDSET_CreateDefault(HOF_HEAP_ID);
    work->strBuf = STRBUF_Create(1024, HOF_HEAP_ID);
}

void HALL_OF_FAME_ExitText(HallOfFameWork *work)
{
    STRBUF_Delete(work->strBuf);
    WORDSET_Delete(work->wordSet);
    GF_FONT_Delete(work->fontSub);
    GF_FONT_Delete(work->fontMain);
    MSGDATA_Delete(work->msgData);
}

void HALL_OF_FAME_StartBgm(HallOfFameWork *work)
{
    work->waveArcSet = GFL_USE_LoadWaveArcSet(gHallOfFameWaveArcIds, 1);
    GFL_USE_CancelChangeAndPlayBgm(1015, 65535);
}

void HALL_OF_FAME_ReleaseWaveArc(HallOfFameWork *work)
{
    GFL_USE_ReleaseWaveArcSet(work->waveArcSet);
}

void HALL_OF_FAME_CollectPartyMons(HallOfFameWork *work)
{
    unsigned i;
    void *mon;
    unsigned saved;
    work->monCount = 0;
    for (i = 0; i < POKEPARTY_GetCount(work->args->party); i++) {
        mon = POKEPARTY_GetMember(work->args->party, i);
        saved = POKE_TOOL_DecodePartyParam(mon);
        if (POKE_TOOL_GetPartyValue(mon, 76, 0) == 0) {
            work->partyMons[work->monCount] = mon;
            work->monCount++;
        }
        POKE_TOOL_EncodePartyParam(mon, saved);
    }
}

void HALL_OF_FAME_LoadMonInfo(HallOfFameWork *work)
{
    void *mon;
    unsigned saved;
    mon = work->partyMons[work->monIndex];
    saved = POKE_TOOL_DecodePartyParam(mon);
    work->species = POKE_TOOL_GetPartyValue(mon, 5, 0);
    work->effectStyle = POKE_TOOL_GetPartyValue(mon, 174, 0);
    work->form = POKE_TOOL_GetPartyValue(mon, 111, 0);
    POKE_TOOL_EncodePartyParam(mon, saved);
}

void HALL_OF_FAME_PrepareMonVoice(HallOfFameWork *work)
{
    unsigned recordedVoice;
    if (work->species == 441) {
        PM_VOICE_GetPerapVoiceSave((struct SaveBlock **)&recordedVoice);
        work->voiceHandle = PM_VOICE_Prepare(work->species, work->form, 64, 0, 0, 0, 0, (void **)(&recordedVoice));
    } else {
        work->voiceHandle = PM_VOICE_Prepare(work->species, work->form, 64, 0, 0, 0, 0, 0);
    }
}

/*
 * volatile: 021B660A..021B6648 re-read hardware 0x04000008 and 0x04000060; hardware write 0x04000580.
 */
void HALL_OF_FAME_Setup3dState(void)
{
    unsigned i;
    BG_SYS_SetMainPlaneVisible(1, 1);
    REG(REG_BG0CNT_ADDR) = REG(REG_BG0CNT_ADDR) & ~3;
    REG(REG_DISP3DCNT_ADDR) = (u16)((REG(REG_DISP3DCNT_ADDR) & ~0x3002) | 2);
    REG(REG_DISP3DCNT_ADDR) &= (u16)~0x3010;
    REG(REG_DISP3DCNT_ADDR) &= (u16)~0x3004;
    REG(REG_DISP3DCNT_ADDR) = (u16)((REG(REG_DISP3DCNT_ADDR) & ~0x3000) | 8);
    REG(REG_DISP3DCNT_ADDR) &= (u16)~0x3020;
    G3X_SetFog(0, 0, 0, 0);
    G3X_SetClearColor(0, 0, 32767, 63, 0);
    *(volatile unsigned *)0x04000580 = 0xBFFF0000;
    for (i = 0; i < 4; i++)
        G3D_SYSTEM_SetLight((unsigned char)i, (struct G3dLight *)(gHallOfFameLights + i * 8));
    G3D_SYSTEM_SetSwapBuffersMode(1, 0);
}

void HALL_OF_FAME_Init3d(HallOfFameWork *work)
{
    G3D_SYSTEM_Init(0, 1, 0, 1, 4096, HOF_HEAP_ID, HALL_OF_FAME_Setup3dState);
    work->g3dUtil = G3D_UTIL_Create(32, 32, HOF_HEAP_ID);
}

void HALL_OF_FAME_Exit3d(HallOfFameWork *work)
{
    G3D_UTIL_Delete(work->g3dUtil);
    G3D_SYSTEM_Exit();
}

void HALL_OF_FAME_DrawMonSprite3d(HallOfFameWork *work)
{
    G3D_SYSTEM_DrawStart();
    G3D_SYSTEM_ApplyLookAt();
    MCSS_Main(work->mcss);
    MCSS_Draw(work->mcss);
    G3D_SYSTEM_DrawEnd();
}

void HALL_OF_FAME_DrawParticles(HallOfFameWork *work)
{
    G3D_SYSTEM_DrawStart();
    G3D_SYSTEM_ApplyLookAt();
    if (DOUBLE3DDISP_GetMode() == 1) {
        HALL_OF_FAME_SetParticleCamera(work, work->monParticle, 1);
        HALL_OF_FAME_SetParticleCamera(work, work->backdropParticle, 1);
    } else {
        HALL_OF_FAME_SetParticleCamera(work, work->monParticle, 0);
        HALL_OF_FAME_SetParticleCamera(work, work->backdropParticle, 0);
    }
    PARTICLE_Main();
    G3D_SYSTEM_DrawEnd();
    DOUBLE3DDISP_SetDrawDone();
}

void HALL_OF_FAME_InitParticleHeap(void)
{
    DOUBLE3DDISP_Init(HOF_HEAP_ID);
}

void HALL_OF_FAME_ExitParticleHeap(void)
{
    DOUBLE3DDISP_Exit();
}

void HALL_OF_FAME_InitParticleManager(void)
{
    PARTICLE_InitManager(HOF_HEAP_ID);
}

void HALL_OF_FAME_ExitParticleManager(void)
{
    PARTICLE_ExitManager();
}

void HALL_OF_FAME_CreateMonParticle(HallOfFameWork *work)
{
    work->monParticle = (void *)PARTICLE_CreateSystemDefault((sptr)work->monParticleWork, HOF_PARTICLE_WORK_SIZE, 1, HOF_HEAP_ID);
    PARTICLE_SetupSystem(work->monParticle, (void *)PARTICLE_LoadArchiveMember(216, gHallOfFameEffectArchives[work->effectStyle], HOF_HEAP_ID), 1, 0);
}

void HALL_OF_FAME_DeleteMonParticle(HallOfFameWork *work)
{
    PARTICLE_DeleteSystem(work->monParticle);
    work->monParticle = 0;
}

void HALL_OF_FAME_StartMonParticle(HallOfFameWork *work, int effect)
{
    HofVec3 origin;
    origin = gHallOfFameMonEffectOrigin;
    PARTICLE_StartEffect(work->monParticle, effect, (sptr)&origin);
}

void HALL_OF_FAME_CreateBackdropParticle(HallOfFameWork *work)
{
    work->backdropParticle = (void *)PARTICLE_CreateSystemDefault((sptr)work->backdropParticleWork, HOF_PARTICLE_WORK_SIZE, 1, HOF_HEAP_ID);
    PARTICLE_SetupSystem(work->backdropParticle, (void *)PARTICLE_LoadArchiveMember(216, 51, HOF_HEAP_ID), 1, 0);
}

void HALL_OF_FAME_DeleteBackdropParticle(HallOfFameWork *work)
{
    PARTICLE_DeleteSystem(work->backdropParticle);
    work->backdropParticle = 0;
}

void HALL_OF_FAME_StartBackdropParticle(HallOfFameWork *work, int effect)
{
    int origin[3] = {0, 0, 0};
    PARTICLE_StartEffect(work->backdropParticle, effect, (sptr)origin);
}

void HALL_OF_FAME_SetParticleCamera(HallOfFameWork *work, void *particle, int mode)
{
    HofParticleCamera cam;
    if (particle != 0) {
        if (mode == 1) {
            cam.pitch = 0x4000;
            cam.yaw = -0x4000;
        } else {
            cam.pitch = 0xE000;
            cam.yaw = 0x6000;
        }
        cam.minPos = -0x5548;
        cam.maxPos = 0x5548;
        cam.kind = 2;
        cam.scale = cam.kind << 21;
        cam.reserved10 = 0;
        cam.reserved1C = 0;
        PARTICLE_ReleaseCamera(particle);
        PARTICLE_InitCamera(particle, (struct ParticleCameraParams *)&cam, 0x2000, 0, 0, 0, HOF_HEAP_ID);
    }
}

void HALL_OF_FAME_InitMcss(HallOfFameWork *work)
{
    work->mcss = MCSS_Init((unsigned int)1, (unsigned int)HOF_HEAP_ID);
    MCSS_SetTextureTransAdrs(work->mcss, 0);
    MCSS_SetOrthoMode(work->mcss);
    work->camera = G3D_CAMERA_Create(2, 0x60000, 0xFFFA0000, 0xFFF80000, 0x80000, 0x1000, 0x400000, 0, (struct VecFx32 *)gHallOfFameCameraPos, (struct VecFx32 *)gHallOfFameCameraTarget, (struct VecFx32 *)gHallOfFameCameraUp, HOF_HEAP_ID);
    G3D_CAMERA_Reset(work->camera);
}

void HALL_OF_FAME_ExitMcss(HallOfFameWork *work)
{
    HALL_OF_FAME_DeleteMonSprite(work);
    G3D_CAMERA_Delete(work->camera);
    MCSS_Exit(work->mcss);
}

void HALL_OF_FAME_AddMonSprite(HallOfFameWork *work)
{
    HofMcssParams params;
    HofVec3 scale = gHallOfFameMonScale;
    MCSS_TOOL_MakeAddWorkFromPP(work->partyMons[work->monIndex], (struct McssAddWork *)&params, 0);
    work->monSprite = MCSS_Add(work->mcss, 0xb0000, -196608, 0, (struct McssAddWork *)&params);
    MCSS_SetScale(work->monSprite, (u32 *)&scale);
    MCSS_SetAnmStopFlag(work->monSprite);
}

/*
 * 2026-10-05: the callee MCSS_Del takes a second argument (r1 = the field value tested); the caller passes it.
 */
void HALL_OF_FAME_DeleteMonSprite(HallOfFameWork *work)
{
    void *sprite = work->monSprite;
    if (sprite != 0) {
        MCSS_Del(work->mcss, sprite);
        work->monSprite = 0;
    }
}

void HALL_OF_FAME_MoveMonSpriteX(HallOfFameWork *work, int step)
{
    HofVec3 pos;
    float delta;
    MCSS_GetPosition(work->monSprite, (u32 *)&pos);
    if (step > 0)
        delta = 0.5f * (float)(step << 12);
    else
        delta = (float)(step << 12) / 0.5f;
    pos.x = pos.x + (int)delta;
    MCSS_SetPosition(work->monSprite, (u32 *)&pos);
}

/*
 *   MCSS_SetAnmStopFlag (0x02015E04) stays wildcarded because the target is an
 *   unlabelled leaf emitted inside a .word run -- no traced func_ start,
 *   no branch outside this range, no literal pool word elsewhere, so
 *   `label` and `sole-ref/code` both refuse.  Evidence class: label /
 *   sole-ref/code (target not a traced function start).
 */
void HALL_OF_FAME_OnMonAnimDone(HallOfFameWork *work)
{
    MCSS_SetAnmStopFlag(work->monSprite);
    work->monAnimDone = 1;
}

void HALL_OF_FAME_StartMonAnimCallback(HallOfFameWork *work)
{
    work->monAnimDone = 0;
    MCSS_SetAnimCallback(work->monSprite, (uptr)work, (uptr)HALL_OF_FAME_OnMonAnimDone, 0);
}

int HALL_OF_FAME_RunState(HallOfFameWork *work)
{
    work->state = gHallOfFameStateTable[work->state](work);
    if (work->state == HOF_STATE_DONE)
        return 0;
    if (work->renderMode == 1) {
        HALL_OF_FAME_DrawMonScene(work);
        HALL_OF_FAME_DrawParticles(work);
    } else if (work->renderMode == 2) {
        HALL_OF_FAME_DrawTrainerScene(work);
        HALL_OF_FAME_DrawMonSprite3d(work);
        HALL_OF_FAME_EnableBgEffects(work);
    }
    return 1;
}

int HALL_OF_FAME_StateInit(HallOfFameWork *work)
{
    BG_SYS_SetMainVisiblePlanes(0);
    BG_SYS_SetSubVisiblePlanes(0);
    *(volatile unsigned short *)0x04000050 = 0;
    *(volatile unsigned short *)0x04001050 = 0;
    GXx_SetMasterBrightness_((void *)REG_MASTER_BRIGHT_ADDR, -16);
    GXx_SetMasterBrightness_((void *)REG_DB_MASTER_BRIGHT_ADDR, -16);
    HALL_OF_FAME_InitGraphicsSystem();
    HALL_OF_FAME_InitText(work);
    HALL_OF_FAME_StartBgm(work);
    HALL_OF_FAME_CollectPartyMons(work);
    return 4;
}

int HALL_OF_FAME_StateExit(HallOfFameWork *work)
{
    HALL_OF_FAME_ReleaseWaveArc(work);
    HALL_OF_FAME_ExitText(work);
    HALL_OF_FAME_ExitGraphicsSystem();
    GXx_SetMasterBrightness_((void *)REG_MASTER_BRIGHT_ADDR, -16);
    GXx_SetMasterBrightness_((void *)REG_DB_MASTER_BRIGHT_ADDR, -16);
    *(volatile unsigned short *)0x04000050 = 0;
    *(volatile unsigned short *)0x04001050 = 0;
    BG_SYS_SetMainVisiblePlanes(0);
    BG_SYS_SetSubVisiblePlanes(0);
    return 10;
}

int HALL_OF_FAME_StateWaitFade(HallOfFameWork *work)
{
    if (WIPE_SYS_EndCheck() == 1)
        return work->nextState;
    return 2;
}

int HALL_OF_FAME_StateWaitCounter(HallOfFameWork *work)
{
    if (work->counter == 0)
        return work->nextState;
    work->counter -= 1;
    return 3;
}

int HALL_OF_FAME_StateSetupMonScene(HallOfFameWork *work)
{
    HALL_OF_FAME_SetVramBanks(0);
    HALL_OF_FAME_SetupDisplay();
    HALL_OF_FAME_Init3d(work);
    HALL_OF_FAME_InitParticleManager();
    HALL_OF_FAME_InitParticleHeap();
    HALL_OF_FAME_InitActorSystem(work, 0);
    HALL_OF_FAME_CreateMonSceneObjects(work);
    HALL_OF_FAME_SetupBlendRegs();
    HALL_OF_FAME_AddVBlankTaskMon(work);
    work->renderMode = 1;
    return 5;
}

int HALL_OF_FAME_StateTeardownMonScene(HallOfFameWork *work)
{
    HALL_OF_FAME_RemoveVBlankTask(work);
    *(u16 *)0x04000050 = 0;
    *(u16 *)0x04001050 = 0;
    HALL_OF_FAME_DeleteMonSceneObjects(work);
    HALL_OF_FAME_ExitActorSystem(work);
    HALL_OF_FAME_ExitParticleHeap();
    HALL_OF_FAME_ExitParticleManager();
    HALL_OF_FAME_Exit3d(work);
    work->renderMode = 0;
    return 7;
}

/*
 * trailing: zero halfword alignment padding at 0x021B6F32.
 * Bound: original stack allocation 24 bytes is six output coordinate pairs, each two signed halfwords.
 * Caller evidence: 021B74B4's forwarded r0 is consumed; 021B7268 and 021B723C return their verified state values.
 */
int HALL_OF_FAME_StateMonSequence(HallOfFameWork *work)
{
    short coords[12];
    int busy;
    switch (work->step) {
    case 0:
        ++work->step;
        return HALL_OF_FAME_BeginCountdown(work, 32);
    case 1:
        GFL_USE_PlaySeDefaultVolume(0x79B);
        ++work->step;
        break;
    case 2:
        if (++work->counter == 48) {
            GFL_USE_PlaySeDefaultVolume(0x79C);
            work->counter = 0;
            ++work->step;
        }
        break;
    case 3:
        if (GFL_USE_IsSeqPlaying(0x79C) == 0) {
            GFL_USE_PlaySeDefaultVolume(0x79A);
            HALL_OF_FAME_LoadMonInfo(work);
            HALL_OF_FAME_PrepareMonVoice(work);
            HALL_OF_FAME_CreateMonParticle(work);
            HALL_OF_FAME_CreateBackdropParticle(work);
            HALL_OF_FAME_LoadMonActors(work);
            HALL_OF_FAME_PrintMonInfo(work);
            HALL_OF_FAME_UpdatePlatePositions(work);
            HALL_OF_FAME_LoadUiPalette(work);
            ++work->step;
            return HALL_OF_FAME_BeginFadeIn(work, 5);
        }
        break;
    case 4:
        if (work->counter == 22) {
            ++work->step;
            return HALL_OF_FAME_BeginCountdown(work, 8);
        } else {
            HALL_OF_FAME_MoveActorRelative(work, HOF_ACTOR_MON_BOTTOM, -16, 0);
            ++work->counter;
        }
        break;
    case 5:
        HALL_OF_FAME_StartMonParticle(work, 0);
        HALL_OF_FAME_StartMonParticle(work, 1);
        ++work->step;
        return HALL_OF_FAME_BeginCountdown(work, 8);
    case 6:
        HALL_OF_FAME_StartBackdropParticle(work, 1);
        ++work->step;
        /* fall through */
    case 7:
        HALL_OF_FAME_GetActorPos(work, HOF_ACTOR_PLATE_LEFT, &coords[11], &coords[10]);
        if (coords[11] != 168)
            HALL_OF_FAME_MoveActorRelative(work, HOF_ACTOR_PLATE_LEFT, 16, 0);
        else {
            GFL_USE_PlaySeDefaultVolume(0x57A);
            HALL_OF_FAME_RandomizeJitter(work);
            work->anchorX = coords[11];
            work->anchorY = coords[10];
            ++work->step;
        }
        HALL_OF_FAME_UpdatePlatePositions(work);
        break;
    case 8:
        HALL_OF_FAME_StartBackdropParticle(work, 0);
        ++work->step;
        /* fall through */
    case 9:
        busy = HALL_OF_FAME_ApplyJitterStep(work, HOF_ACTOR_PLATE_LEFT);
        HALL_OF_FAME_GetActorPos(work, HOF_ACTOR_PLATE_RIGHT, &coords[9], &coords[8]);
        if (coords[9] != 88)
            HALL_OF_FAME_MoveActorRelative(work, HOF_ACTOR_PLATE_RIGHT, -16, 0);
        else if (busy == 0) {
            GFL_USE_PlaySeDefaultVolume(0x57A);
            HALL_OF_FAME_RandomizeJitter(work);
            work->anchorX = coords[9];
            work->anchorY = coords[8];
            ++work->step;
        }
        HALL_OF_FAME_UpdatePlatePositions(work);
        break;
    case 10:
        busy = HALL_OF_FAME_ApplyJitterStep(work, HOF_ACTOR_PLATE_RIGHT);
        HALL_OF_FAME_GetActorPos(work, HOF_ACTOR_MON_TOP, &coords[7], &coords[6]);
        if (coords[7] != 48)
            HALL_OF_FAME_MoveActorRelative(work, HOF_ACTOR_MON_TOP, 16, 0);
        else if (busy == 0) {
            GFL_USE_PlaySeDefaultVolume(0x57A);
            HALL_OF_FAME_RandomizeJitter(work);
            work->anchorX = coords[7];
            work->anchorY = coords[6];
            ++work->step;
        }
        HALL_OF_FAME_UpdatePlatePositions(work);
        break;
    case 11:
        if (HALL_OF_FAME_ApplyJitterStep(work, HOF_ACTOR_MON_TOP) == 0) {
            PM_VOICE_Start(work->voiceHandle);
            HALL_OF_FAME_SetActorVisible(work, HOF_ACTOR_VOICE_MARK, 1);
            HALL_OF_FAME_PlayActorAnim(work, HOF_ACTOR_VOICE_MARK, 6);
            ++work->step;
            return HALL_OF_FAME_BeginCountdown(work, 128);
        }
        break;
    case 12:
        if (PM_VOICE_IsSlotActive(work->voiceHandle) == 0 && HALL_OF_FAME_IsActorAnimActive(work, HOF_ACTOR_VOICE_MARK) == 0)
            ++work->step;
        break;
    case 13:
        HALL_OF_FAME_GetActorPos(work, HOF_ACTOR_MON_TOP, &coords[5], &coords[4]);
        if (coords[5] != -48)
            HALL_OF_FAME_MoveActorRelative(work, HOF_ACTOR_MON_TOP, -16, 0);
        else
            ++work->step;
        break;
    case 14:
        HALL_OF_FAME_GetActorPos(work, HOF_ACTOR_PLATE_RIGHT, &coords[3], &coords[2]);
        if (coords[3] != 264)
            HALL_OF_FAME_MoveActorRelative(work, HOF_ACTOR_PLATE_RIGHT, 16, 0);
        else
            ++work->step;
        HALL_OF_FAME_UpdatePlatePositions(work);
        break;
    case 15:
        HALL_OF_FAME_GetActorPos(work, HOF_ACTOR_PLATE_LEFT, &coords[1], &coords[0]);
        if (coords[1] != -8) {
            HALL_OF_FAME_MoveActorRelative(work, HOF_ACTOR_PLATE_LEFT, -16, 0);
            HALL_OF_FAME_UpdatePlatePositions(work);
        } else {
            ++work->step;
            return HALL_OF_FAME_BeginFadeOut(work, 5, 6);
        }
        break;
    case 16:
        HALL_OF_FAME_DeleteBackdropParticle(work);
        HALL_OF_FAME_DeleteMonParticle(work);
        ++work->monIndex;
        if (work->monIndex == work->monCount) {
            work->monIndex = 0;
            work->step = 0;
            return 6;
        } else
            work->step = 3;
        break;
    }
    return 5;
}

/*
 * trailing: zero halfword alignment padding at 0x021B6F7E.
 */
int HALL_OF_FAME_StateSetupTrainerScene(HallOfFameWork *work)
{
    BG_SYS_SetLcdSwap(0);
    HALL_OF_FAME_SetVramBanks(1);
    HALL_OF_FAME_SetupDisplay();
    HALL_OF_FAME_InitBackgrounds();
    HALL_OF_FAME_LoadBackgroundGraphics();
    HALL_OF_FAME_Init3d(work);
    HALL_OF_FAME_InitMcss(work);
    HALL_OF_FAME_InitActorSystem(work, 1);
    HALL_OF_FAME_CreateTrainerSceneObjects(work);
    HALL_OF_FAME_AddVBlankTaskTrainer(work);
    work->renderMode = 2;
    return HALL_OF_FAME_BeginFadeIn(work, 8);
}

int HALL_OF_FAME_StateTeardownTrainerScene(HallOfFameWork *work)
{
    HALL_OF_FAME_RemoveVBlankTask(work);
    HALL_OF_FAME_DeleteTrainerSceneObjects(work);
    HALL_OF_FAME_ExitActorSystem(work);
    HALL_OF_FAME_ExitBackgrounds();
    HALL_OF_FAME_ExitMcss(work);
    HALL_OF_FAME_Exit3d(work);
    work->renderMode = 0;
    return 1;
}

/*
 * Caller evidence: 021B74B4 leaves its forwarded return in r0, read here; 02005E50 is the matched zero-argument GFL_USE_IsBgmFading.
 */
int HALL_OF_FAME_StateTrainerScene(HallOfFameWork *work)
{
    int ready;
    if (work->exiting == 1 && WIPE_SYS_EndCheck() == 1 && GFL_USE_IsBgmFading() == 0) {
        GFL_USE_CancelChangeAndStopBgm();
        return 9;
    }
    switch (work->step) {
    case 0:
        ++work->step;
        return HALL_OF_FAME_BeginCountdown(work, 32);
    case 1:
        GFL_USE_PlaySeDefaultVolume(0x79D);
        ++work->step;
        break;
    case 2:
        if (work->counter != 51) {
            HALL_OF_FAME_MoveActorRelative(work, HOF_ACTOR_TRAINER_TOP, 0, 8);
            HALL_OF_FAME_MoveActorRelative(work, HOF_ACTOR_TRAINER_BOTTOM, 0, 8);
            ++work->counter;
        } else {
            GFL_USE_PlaySeDefaultVolume(0x57A);
            ++work->step;
            return HALL_OF_FAME_BeginCountdown(work, 32);
        }
        break;
    case 3:
        HALL_OF_FAME_SetActorVisible(work, HOF_ACTOR_RING_TOP, 1);
        HALL_OF_FAME_SetActorVisible(work, HOF_ACTOR_RING_BOTTOM, 1);
        HALL_OF_FAME_PlayActorAnim(work, HOF_ACTOR_RING_TOP, 2);
        HALL_OF_FAME_PlayActorAnim(work, HOF_ACTOR_RING_BOTTOM, 2);
        ++work->step;
        break;
    case 4:
        if (HALL_OF_FAME_IsActorAnimActive(work, HOF_ACTOR_RING_TOP) == 0) {
            GFL_USE_PlaySeDefaultVolume(0x79E);
            ++work->step;
            return HALL_OF_FAME_BeginCountdown(work, 16);
        }
        break;
    case 5:
        HALL_OF_FAME_SetPlateEnabled(work, 3, 1);
        ++work->step;
        return HALL_OF_FAME_BeginCountdown(work, 32);
    case 6:
        HALL_OF_FAME_SetPlateEnabled(work, 2, 1);
        ++work->step;
        break;
    case 7:
        if (work->counter == 300) {
            work->counter = 0;
            ++work->step;
        } else
            ++work->counter;
        break;
    case 8:
        ready = 0;
        if (work->monIndex == 0) {
            if (work->counter == 256)
                ready = 1;
        } else {
            if (work->counter == 128)
                ready = 1;
        }
        if (ready == 1) {
            HALL_OF_FAME_AddMonSprite(work);
            work->counter = 0;
            ++work->step;
        } else
            ++work->counter;
        break;
    case 9:
        if (work->counter != 20) {
            HALL_OF_FAME_MoveMonSpriteX(work, -8);
            ++work->counter;
        } else {
            MCSS_ResetAnmStopFlag(work->monSprite);
            work->counter = 0;
            ++work->step;
        }
        break;
    case 10:
        if (work->counter != 128)
            ++work->counter;
        else {
            HALL_OF_FAME_StartMonAnimCallback(work);
            work->counter = 0;
            ++work->step;
        }
        break;
    case 11:
        if (work->monAnimDone != 0) {
            if (work->counter != 24) {
                HALL_OF_FAME_MoveMonSpriteX(work, -8);
                ++work->counter;
            } else {
                HALL_OF_FAME_DeleteMonSprite(work);
                work->counter = 0;
                ++work->monIndex;
                if (work->monIndex == work->monCount)
                    work->monIndex = 0;
                work->step = 8;
            }
        }
        break;
    }
    if (work->step >= 6)
        HALL_OF_FAME_SpawnSparkles(work);
    if (work->step >= 8 && work->exiting == 0 && ((KEY_GetTrg() & 3) != 0 || TOUCHPANEL_GetTrg() == 1)) {
        work->exiting = 1;
        GFL_USE_FadeOutBgm(220);
        HALL_OF_FAME_BeginFadeOut(work, 9, 188);
    }
    return 8;
}

int HALL_OF_FAME_BeginFadeIn(HallOfFameWork *work, int nextState)
{
    WIPE_SYS_Start(0, 1, 1, 0, 6, 1, HOF_HEAP_ID);
    work->nextState = nextState;
    return 2;
}

/*
 * follower: 0x021B7268 store-return stub included in this verified unit.
 */
int HALL_OF_FAME_BeginFadeOut(HallOfFameWork *work, int nextState, int duration)
{
    WIPE_SYS_Start(0, 0, 0, 0, duration, 1, HOF_HEAP_ID);
    work->nextState = nextState;
    return 2;
}

int HALL_OF_FAME_BeginCountdown(HallOfFameWork *work, int frames)
{
    work->counter = frames;
    work->nextState = work->state;
    return 3;
}

void HALL_OF_FAME_RandomizeJitter(HallOfFameWork *work)
{
    u32 i;
    work->jitterIndex = 0;
    for (i = 0; i < HOF_JITTER_COUNT; i++) {
        work->jitterX[i] = GFL_USE_GetRandom(8) - 4;
        work->jitterY[i] = GFL_USE_GetRandom(8) - 4;
    }
}

int HALL_OF_FAME_ApplyJitterStep(HallOfFameWork *work, int actor)
{
    if (work->jitterIndex == HOF_JITTER_COUNT) {
        HALL_OF_FAME_MoveActorBy(work, actor, work->anchorX, work->anchorY);
        return 0;
    }
    HALL_OF_FAME_MoveActorBy(work, actor, work->anchorX + work->jitterX[work->jitterIndex], work->anchorY + work->jitterY[work->jitterIndex]);
    work->jitterIndex++;
    return 1;
}

void HALL_OF_FAME_EnableBgEffects(HallOfFameWork *work)
{
    BG_SYS_ChangeRotation(3, 1, 1);
    BG_SYS_ChangeRotation(7, 1, 1);
}

void HALL_OF_FAME_InitActorSystem(HallOfFameWork *work, int subScreen)
{
    if (subScreen == 0) {
        HofClactConfig cfg = gHallOfFameClactConfigMain;
        CLACT_InitSystem((struct ClactSysInit *)&cfg, (struct DispVramCfg *)(HALL_OF_FAME_GetVramBanksAddr(subScreen)), HOF_HEAP_ID);
    } else {
        HofClactConfig cfg = gHallOfFameClactConfigSub;
        CLACT_InitSystem((struct ClactSysInit *)&cfg, (struct DispVramCfg *)(HALL_OF_FAME_GetVramBanksAddr(subScreen)), HOF_HEAP_ID);
    }
    work->clactUnit = CLACT_CreateUnit(249, 0, HOF_HEAP_ID);
    work->oamSys = BMP_OAM_CreateSys(HOF_HEAP_ID, work->clactUnit);
    HALL_OF_FAME_ResetResourceIds(work);
    BG_SYS_SetMainPlaneVisible(16, 1);
    BG_SYS_SetSubPlaneVisible(16, 1);
}

void HALL_OF_FAME_ExitActorSystem(HallOfFameWork *work)
{
    BMP_OAM_DeleteSys(work->oamSys);
    CLACT_DeleteUnit(work->clactUnit);
    CLACT_ExitSystem();
}

void HALL_OF_FAME_UpdateActors(HallOfFameWork *work)
{
    u32 i;
    for (i = 0; i < HOF_ACTOR_COUNT; i++) {
        if (work->actors[i] && CLACT_GetActorAutoAnim((struct ClactActor *)work->actors[i]) != 1)
            CLACT_AddActorAnimFrame((struct ClactActor *)work->actors[i], 4096);
    }
    CLACT_DrawSystem();
}

void HALL_OF_FAME_MoveActorBy(HallOfFameWork *work, int actor, short x, short y)
{
    struct {
        short x, y;
    } delta;
    delta.x = x;
    delta.y = y;
    CLACT_AddActorSurfacePos(work->actors[actor], (const struct ClactVec2 *)&delta, 0);
}

void HALL_OF_FAME_GetActorPos(HallOfFameWork *work, int actor, short *x, short *y)
{
    struct {
        short x, y;
    } pos;
    CLACT_GetActorSurfacePos((struct ClactActor *)work->actors[actor], (struct ClactVec2 *)&pos, 0);
    *x = pos.x;
    *y = pos.y;
}

void HALL_OF_FAME_MoveActorRelative(HallOfFameWork *work, int actor, int dx, int dy)
{
    struct {
        short y, x;
    } pos;
    HALL_OF_FAME_GetActorPos(work, actor, &pos.x, &pos.y);
    pos.x = pos.x + dx;
    pos.y = pos.y + dy;
    HALL_OF_FAME_MoveActorBy(work, actor, pos.x, pos.y);
}

void HALL_OF_FAME_SetActorVisible(HallOfFameWork *work, int actor, int visible)
{
    struct ClactActor *obj = work->actors[actor];
    if (obj)
        CLACT_SetActorDrawEnable((struct ClactActor *)obj, visible);
}

void HALL_OF_FAME_PlayActorAnim(HallOfFameWork *work, int actor, int seq)
{
    CLACT_SetActorAnimFrame(work->actors[actor], 0);
    CLACT_SetActorAnimSeq(work->actors[actor], seq);
    CLACT_SetActorAutoAnim(work->actors[actor], 1);
}

int HALL_OF_FAME_IsActorAnimActive(HallOfFameWork *work, int actor)
{
    return CLACT_IsActorAnimActive((struct ClactActor *)work->actors[actor]);
}

void HALL_OF_FAME_ResetResourceIds(HallOfFameWork *work)
{
    unsigned i;
    for (i = 0; i < HOF_CHAR_COUNT; i++)
        work->charIds[i] = -1;
    for (i = 0; i < HOF_PALETTE_COUNT; i++)
        work->paletteIds[i] = -1;
    for (i = 0; i < HOF_CELL_ANIM_COUNT; i++)
        work->cellAnimIds[i] = -1;
}

void HALL_OF_FAME_ReleaseCharacter(HallOfFameWork *work, int index)
{
    if (work->charIds[index] != ~0u) {
        CLACT_ReleaseCharacter(work->charIds[index]);
        work->charIds[index] = ~0u;
    }
}

void HALL_OF_FAME_ReleasePalette(HallOfFameWork *work, int index)
{
    if (work->paletteIds[index] != ~0u) {
        CLACT_ReleasePalette(work->paletteIds[index]);
        work->paletteIds[index] = ~0u;
    }
}

void HALL_OF_FAME_ReleaseCellAnim(HallOfFameWork *work, int index)
{
    if (work->cellAnimIds[index] != -1) {
        CLACT_ReleaseCellAnim(work->cellAnimIds[index]);
        work->cellAnimIds[index] = -1;
    }
}

/*
 * EXACT* tail: two zero alignment bytes after the function.
 */
void HALL_OF_FAME_ReleaseAllResources(HallOfFameWork *work)
{
    u32 i;
    for (i = 0; i < HOF_CHAR_COUNT; i++)
        HALL_OF_FAME_ReleaseCharacter(work, i);
    for (i = 0; i < HOF_PALETTE_COUNT; i++)
        HALL_OF_FAME_ReleasePalette(work, i);
    for (i = 0; i < HOF_CELL_ANIM_COUNT; i++)
        HALL_OF_FAME_ReleaseCellAnim(work, i);
}

struct ClactActor *HALL_OF_FAME_CreateActorFromTemplate(HallOfFameWork *work, const HallOfFameActorTemplate *tmpl)
{
    return CLACT_CreateActor(work->clactUnit, work->charIds[tmpl->charIndex], work->paletteIds[tmpl->paletteIndex], work->cellAnimIds[tmpl->cellAnimIndex], (void *)tmpl, tmpl->priority, HOF_HEAP_ID);
}

void HALL_OF_FAME_DeleteActor(HallOfFameWork *work, int actor)
{
    if (work->actors[actor] != 0) {
        CLACT_DeleteActor((struct ClactActor *)work->actors[actor]);
        work->actors[actor] = 0;
    }
}

void HALL_OF_FAME_DeleteAllActors(HallOfFameWork *work)
{
    unsigned int i;
    for (i = 0; i < HOF_ACTOR_COUNT; i++)
        HALL_OF_FAME_DeleteActor(work, i);
}

void HALL_OF_FAME_LoadMonActors(HallOfFameWork *work)
{
    sptr bank;
    void *mon;
    u32 lock;
    if (work->actors[HOF_ACTOR_MON_TOP]) {
        HALL_OF_FAME_DeleteActor(work, 0);
        HALL_OF_FAME_ReleaseCharacter(work, 0);
        HALL_OF_FAME_ReleasePalette(work, 0);
        HALL_OF_FAME_ReleaseCellAnim(work, 0);
    }
    if (work->actors[HOF_ACTOR_MON_BOTTOM]) {
        HALL_OF_FAME_DeleteActor(work, 1);
        HALL_OF_FAME_ReleaseCharacter(work, 1);
        HALL_OF_FAME_ReleasePalette(work, 1);
        HALL_OF_FAME_ReleaseCellAnim(work, 1);
    }
    bank = (sptr)POKEGRA_OpenHandle(HOF_HEAP_ID);
    mon = POKE_TOOL_CastToBoxParam(work->partyMons[work->monIndex]);
    lock = POKE_TOOL_DecodeBoxParam(mon);
    work->charIds[0] = POKEGRA_RegisterCgrPP(bank, mon, 0, 0, HOF_HEAP_ID);
    work->paletteIds[0] = POKEGRA_RegisterPalettePP(bank, mon, 0, 0, 96, HOF_HEAP_ID);
    work->cellAnimIds[0] = POKEGRA_RegisterCellAnimPP(mon, 0, 2, 0, HOF_HEAP_ID);
    work->charIds[1] = POKEGRA_RegisterCgrPP(bank, mon, 1, 0, HOF_HEAP_ID);
    work->paletteIds[1] = POKEGRA_RegisterPalettePP(bank, mon, 1, 0, 128, HOF_HEAP_ID);
    work->cellAnimIds[1] = POKEGRA_RegisterCellAnimPP(mon, 1, 2, 0, HOF_HEAP_ID);
    POKE_TOOL_EncodeBoxParam(mon, lock);
    ARC_TOOL_DeleteHandle((u8 *)bank);
    work->actors[HOF_ACTOR_MON_TOP] = HALL_OF_FAME_CreateActorFromTemplate(work, &gHallOfFameMonTopTemplate);
    work->actors[HOF_ACTOR_MON_BOTTOM] = HALL_OF_FAME_CreateActorFromTemplate(work, &gHallOfFameMonBottomTemplate);
}
