/*
 * file:     fld3d_ci.c
 * unit:     yes
 * function: FLD3D_CI_Create, FLD3D_CI_Delete, FLD3D_CI_SetupEffectUnit, FLD3D_CI_DrawEffect, FLD3D_CI_StartSequence, FLD3D_CI_StartPokemonSequence, FLD3D_CI_StartPartyMemberSequence, FLD3D_CI_StartNameSequence, FLD3D_CI_EventMain, FLD3D_CI_UpdateStartDelays, FLD3D_CI_UpdateTrackA, FLD3D_CI_UpdateTrackB, FLD3D_CI_SetupSequence, FLD3D_CI_EndSequence, FLD3D_CI_StartTrack, FLD3D_CI_FollowTargetCallback, FLD3D_CI_LoadSequence, FLD3D_CI_FreeSequence, FLD3D_CI_StartScreenCapture, FLD3D_CI_CaptureTask, FLD3D_CI_SaveLayerPriorities, FLD3D_CI_SaveVisiblePlanes, FLD3D_CI_RestoreLayerPriorities, FLD3D_CI_RestoreVisiblePlanes, FLD3D_CI_PokemonExtraTask, FLD3D_CI_PokemonFinishStep, FLD3D_CI_LoadPokemonIconTexture, FLD3D_CI_FadeOutTask, FLD3D_CI_FadeInTask, FLD3D_CI_FadeInAltTask, FLD3D_CI_IsAltFadeSequence, FLD3D_CI_LoadNameTexture, FLD3D_CI_NameFinishStep, FLD3D_CI_NameExtraTask, FLD3D_CI_GetTexDataOffset, FLD3D_CI_GetPlttDataOffset, FLD3D_CI_FindTexture, FLD3D_CI_FindPalette, FLD3D_CI_CopyName, FLD3D_CI_DrawMessageTexture, FLD3D_CI_StartMessageSequence, FLD3D_CI_DarkenCapturedScreen, FLD3D_CI_InitEventWork, FLD3D_CI_PlayCueSound, FLD3D_CI_DisplayRestoreTask
 * address:  0x021C1AF4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from field_player_grid_event.c, fld3d_ci.c by tools/splitfile.py.
 *
 * symbols:
 *   GAME_EVENT_Create  0x020122C0  thumb
 *   GAME_EVENT_GetWork  0x020124E8  thumb
 *   FIELD_PLAYER_GetMmdl  0x021A3074  thumb  ov021
 *   GFL_USE_PlaySeDefaultVolume  0x020061E4  thumb
 *   GFL_HEAP_Free  0x020307B0  arm
 *   MI_CpuFill8  0x02082BCC  arm
 *   GFL_HEAP_Alloc  0x02030734  arm
 *   TCB_DeleteTask  0x02030EAC  arm
 *   G3D_UTIL_Create  0x02047CFC  arm
 *   G3D_CAMERA_Create  0x02048A24  arm
 *   d_021DE3D8     0x021DE3D8  data  a4
 *   d_021DA6E8     0x021DA6E8  data  a4
 *   d_021DA6D0     0x021DA6D0  data  a4
 *   d_021DA6F4     0x021DA6F4  data  a4
 *   d_021DA6DC     0x021DA6DC  data  a4
 *   d_020A1EB8     0x020A1EB8  data  a4
 *   G3D_UTIL_AddUnit  0x02047E88  arm
 *   MTX_Identity33_  0x0207ADC4  arm
 *   G3D_CAMERA_Reset  0x02048AD0  arm
 *   G3D_UTIL_GetUnitObjIdx  0x020489F4  arm
 *   G3D_UTIL_GetUnitObjCount  0x02048A00  arm
 *   G3D_UTIL_GetObject  0x02048A18  arm
 *   G3D_SYSTEM_DrawObject  0x02047A60  arm
 *   GFL_HEAP_GetAllocatableSize  0x0203038C  arm
 *   d_021DA7F4     0x021DA7F4  data  ov021  a4
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAME_DATA_GetMyParty  0x02012934  thumb
 *   POKEPARTY_GetMember  0x0201AB28  thumb
 *   POKE_TOOL_GetPartyValue  0x02017E1C  thumb
 *   POKE_TOOL_IsShiny  0x02017EAC  thumb
 *   abs_id_4A      0x0000004A  data
 *   GF_OVERLAY_Load  0x02034AC4  arm
 *   GF_OVERLAY_Unload  0x02034A5C  arm
 *   FLD3D_CI_GetNameRow  0x021F54E0  thumb  ov074
 *   GAME_EVENT_GetGameSystem  0x020124E4  thumb
 *   GAMESYSTEM_GetFieldMap  0x0201210C  thumb
 *   FIELDMAP_GetMmdlSys  0x02188C7C  thumb  ov021
 *   FLDMMDL_SysPauseMove  0x0216D9A0  thumb  ov010
 *   GAME_EVENT_CallEvent  0x02012374  thumb
 *   FIELDMAP_GetFieldPlayer  0x02188CB4  thumb  ov021
 *   FLDMMDL_SetStatusBitVanish  0x0216DAC8  thumb  ov010
 *   FLDMMDL_SysSearchObjId  0x0216DE94  thumb  ov010
 *   FLDMMDL_DeleteMmdl  0x0216CF2C  thumb  ov010
 *   FIELDMAP_SetUpdateStopped  0x02189A58  thumb  ov021
 *   BG_SYS_SetPriority  0x0204047C  arm
 *   BG_SYS_SetGraphicsMode  0x0203FC28  arm
 *   GX_SetBankForBG  0x0207FDCC  arm
 *   G2x_SetBlendAlpha_  0x0207D63C  arm
 *   BG_SYS_SetPlaneVisible  0x02040588  arm
 *   FIELDMAP_GetFog  0x02188C64  thumb  ov021
 *   FIELD_FOG_SetFlag  0x021A01A4  thumb  ov021
 *   GFL_HEAP_GetHeapHead  0x02030830  arm
 *   FIELDMAP_SetDrawMode  0x021899F8  thumb  ov021
 *   GFL_USE_IsLoaderBusy  0x02005C64  thumb
 *   FLDMMDL_SetDirDispCheckPause  0x0216D5E0  thumb  ov010
 *   G3X_SetClearColor  0x0207DD24  arm
 *   FIELDMAP_GetLight  0x02188C60  thumb  ov021
 *   FIELD_LIGHT_Reflect  0x021A0568  thumb  ov021
 *   GFL_USE_AddMainTask  0x020056A0  thumb
 *   FIELDMAP_GetMsgBg  0x02188C54  thumb  ov021
 *   FIELDMAP_GetPlaceName  0x02188D20  thumb  ov021
 *   FIELD_MSGBG_ReloadBg  0x02193068  thumb  ov021
 *   FIELD_PLACE_NAME_RestoreWindow  0x021BC5D4  thumb  ov021
 *   FIELD_MSGBG_RequestSysFrame  0x021904D0  thumb  ov021
 *   BG_SYS_FreeSlot  0x020414AC  arm
 *   FLDMMDL_SysResumeMove  0x0216D9E4  thumb  ov010
 *   d_021DA710     0x021DA710  data  ov021  a4
 *   G3D_SYSTEM_GetObjectAnimeCount  0x0204779C  arm
 *   G3D_SYSTEM_IncObjectAnimeFrame  0x020478B8  arm
 *   G3D_SYSTEM_EnableObjectAnime  0x020477A4  arm
 *   PARTICLE_RESOURCE_GetType  0x02051B04  arm
 *   G3D_UTIL_RemoveUnit  0x020480E4  arm
 *   PARTICLE_StartEffectWithCallback  0x020515CC  arm
 *   ARC_TOOL_ReadMember  0x02048F4C  arm
 *   BG_SYS_GetMainVisiblePlanes  0x02043658  arm
 *   BG_SYS_SetMainVisiblePlanes  0x02043534  arm
 *   GAME_EVENT_GetParent  0x020124F0  thumb
 *   BMP_Delete  0x020437AC  arm
 *   PM_VOICE_GetPerapVoiceSave  0x02006CAC  thumb
 *   PM_VOICE_Play  0x02006984  thumb
 *   PM_VOICE_IsAnyActive  0x02006650  thumb
 *   PM_VOICE_GetVolume  0x02006B20  thumb
 *   PM_VOICE_AddVolume  0x02006A8C  thumb
 *   PM_VOICE_StopAll  0x020065D8  thumb
 *   BMP_Create  0x02043678  arm
 *   G3D_UTIL_GetResource  0x02048A0C  arm
 *   G3D_SYSTEM_GetTexVramKey  0x02047388  arm
 *   G3D_SYSTEM_GetPlttVramKey  0x020473B8  arm
 *   POKEGRA_GetArcID  0x0202D060  thumb
 *   POKEGRA_GetCgrArcIndex  0x0202D064  thumb
 *   POKEGRA_GetPalArcIndex  0x0202D0D4  thumb
 *   ARC_UTIL_LoadScreenDataFromArchive  0x02049E34  arm
 *   ARC_UTIL_LoadPaletteBlockFromArchive  0x02049F34  arm
 *   BMP_GetPixels  0x020437D4  arm
 *   MIi_CpuClear32  0x02082A7C  arm
 *   MIi_CpuCopy32  0x02082A90  arm
 *   BMP_ConvertToLinear  0x02044F64  arm
 *   NNS_GfdRegisterNewVramTransferTask  0x02061CA4  arm
 *   FADE_Start  0x0204E720  arm
 *   FADE_IsActive  0x0204E804  arm
 *   G3D_SYSTEM_GetResourceFile  0x02046F48  arm
 *   NNS_G3dGetTex  0x0206E964  arm
 *   ARC_UTIL_LoadBgCharDataFromArchive  0x02049DB4  arm
 *   GAME_DATA_GetMyStatus  0x02012944  thumb
 *   MYSTATUS_GetSex  0x02008550  thumb
 *   G3D_SYSTEM_SetSwapBuffersMode  0x02046BE0  arm
 *   d_021DE3E4     0x021DE3E4  data  ov021  a4
 *   d_021DE3F4     0x021DE3F4  data  ov021  a4
 *   d_021DE404     0x021DE404  data  ov021  a4
 *   d_021DE40C     0x021DE40C  data  ov021  a4
 *   d_021DE418     0x021DE418  data  ov021  a4
 *   d_021DE428     0x021DE428  data  ov021  a4
 *   d_021DE43C     0x021DE43C  data  ov021  a4
 *   d_021DE448     0x021DE448  data  ov021  a4
 *   MSGDATA_CreateFromArchive  0x02045B38  arm
 *   WORDSET_CreateDefault  0x0201EC64  thumb
 *   STRBUF_Create  0x020457B0  arm
 *   MSGDATA_AllocString  0x02045EC0  arm
 *   WORDSET_SetSlotMyStatus  0x0201F02C  thumb
 *   WORDSET_CopyTaggedText  0x0201F250  thumb
 *   STRBUF_Delete  0x02045808  arm
 *   WORDSET_Delete  0x0201ED04  thumb
 *   WORDSET_AppendUnpackedString  0x0201F4A0  thumb
 *   GF_FONT_Create  0x0201D7EC  thumb
 *   PRINTSYS_MeasureWidestLine  0x0201D304  thumb
 *   GF_FONT_Delete  0x0201D83C  thumb
 *   TEXT_TEXTURE_LoadTexPlttByName  0x0216FAB4  thumb  ov010
 *   MSGDATA_Delete  0x02045C04  arm
 *   d_021DA720     0x021DA720  data  ov021
 *   d_021DA700     0x021DA700  data  ov021
 *   G3D_UTIL_Delete  0x02047E54  arm  arm9
 *   G3D_CAMERA_Delete  0x02048AC4  arm  arm9
 *   NNS_G3dGetResDataByName  0x0206E62C  arm  arm9
 *   BG_SYS_GetPriority  0x020416D4  arm  arm9
 *   GX_ResetBankForBG  0x020808F4  arm  arm9
 *   FLD_PARTICLE_CreateEffect 0x021C1A48 thumb ov021
 *   FLD_PARTICLE_DeleteEffect 0x021C1A84 thumb ov021
 *   FLD_PARTICLE_LoadResource 0x021C1A98 thumb ov021
 *   FLD_PARTICLE_StartEmitter 0x021C1AA8 thumb ov021
 *   FLD_PARTICLE_IsEffectFinished 0x021C1AB4 thumb ov021
 *   GX_SetBankForLCDC  0x0208068C  arm  arm9
 *   STD_GetStringLength  0x0208CC78  arm  arm9
 */
#include "fld3d_ci_types.h"
#include "../sdk_ioreg.h"
#include "../ov074/fld3d_ci_name_types.h"

#include "../types.h"

typedef struct Bmp Bmp;

struct Bmp;

#include "../arm9/gfl_heap_wrap.h"


#ifdef __MWERKS__
#define G3D_UTIL_Create G3D_UTIL_Create_header
#define G3D_CAMERA_Create G3D_CAMERA_Create_header
#endif
#include "../arm9/g3d_util.h"
#include "../arm9/g3d_camera.h"
#ifdef __MWERKS__
#undef G3D_UTIL_Create
#undef G3D_CAMERA_Create
/* original prototypes: the definitions take u16 counts and heap id */
struct G3dUtil *G3D_UTIL_Create(int resCount, int objCount, int heapId);
struct G3dCamera *G3D_CAMERA_Create(int mode, int nearClip, int farClip, int fieldOfView, int aspectRatio, int scale, int roll, int flags, VecFx32 *eye, VecFx32 *target, VecFx32 *up, int heapId);
#endif





extern u32 MTX_Identity33_(u32);
struct G3dCamera;




struct G3dObjectStatus;
struct G3dObject;

#include "../arm9/g3d_system.h"

#include "../arm9/gfl_heap.h"

#include "../arm9/game_event.h"
struct GameEvent;

struct GameSystem;
struct GameData;

#include "../arm9/gamesystem.h"

#include "../arm9/game_data.h"
struct Party;
struct PokemonParam;

#include "../arm9/pokeparty.h"

#include "../arm9/poke_tool.h"


#include "../arm9/gf_overlay.h"


#include "../ov074/fld3d_ci_name.h"


struct FieldMap;
struct MmdlSys;

#include "fieldmap.h"

#include "../ov010/fldmmdl.h"

struct FieldPlayer;

struct Mmdl;

#include "field_player.h"





#include "../arm9/bg_sys.h"


#include "../arm9/gx_vramcnt.h"

#include "../arm9/g2.h"



#include "field_fog.h"



#include "../arm9/gfl_use.h"


#include "../arm9/g3x.h"


#include "field_light.h"

struct FieldMsgBg;

struct FieldPlaceName;


#include "field_msgbg.h"

#include "field_place_name.h"







#include "../arm9/particle.h"



#include "../arm9/arc_tool.h"

struct TcbTask;

#include "../arm9/tcb_list.h"





typedef short s16_p07;
#include "../arm9/bmp.h"
struct SaveBlock;

#include "../arm9/pm_voice.h"







struct G3dResource;



#include "../arm9/pokegra.h"



#include "../arm9/arc_util.h"



#include "../arm9/mi_memory.h"



#include "../arm9/nns_gfd_vram_transfer.h"

#include "../arm9/fade.h"



#include "../arm9/nns_g3d_res.h"

struct MyStatus;


#include "../arm9/mystatus.h"



#include "../arm9/std_string.h"
struct MsgBank;

#include "../arm9/msgdata.h"
struct WordSet;

#include "../arm9/gf_font.h"

/* DS-original prototypes: the DS code was built against narrower or wider integer parameters than the header; the host build uses the header. */
#ifdef __MWERKS__
#define STRBUF_Create STRBUF_Create_header
#endif
#include "../arm9/strbuf.h"
#ifdef __MWERKS__
#undef STRBUF_Create
extern struct Strbuf * STRBUF_Create(u32, u16);
#endif
struct Strbuf;


#include "../arm9/wordset.h"




struct GfFont;


#include "../arm9/printsys.h"

struct TexKey;

#include "../ov010/text_texture.h"





#include "fld_particle.h"





Fld3dCi *FLD3D_CI_Create(u32 heapId, FldParticle *particle);

void FLD3D_CI_Delete(Fld3dCi *ci);

int FLD3D_CI_SetupEffectUnit(Fld3dCi *ci, G3dUtilSetup *setup);

void FLD3D_CI_DrawEffect(Fld3dCi *ci);

void *FLD3D_CI_StartSequence(void *gameSystem, Fld3dCi *ci, int sequenceId);

void *FLD3D_CI_StartPokemonSequence(void *gameSystem, Fld3dCi *ci, int species, int form, int attr6E, int personality, int attr4C);

void *FLD3D_CI_StartPartyMemberSequence(void *gameSystem, Fld3dCi *ci, int partyPos);

void *FLD3D_CI_StartNameSequence(void *gameSystem, Fld3dCi *ci, int tableIndex, int fadeVariant);

int FLD3D_CI_EventMain(void *event, int *state, Fld3dCiEventWork *work);

int FLD3D_CI_UpdateStartDelays(Fld3dCi *ci);

int FLD3D_CI_UpdateTrackA(Fld3dCi *ci);

int FLD3D_CI_UpdateTrackB(Fld3dCi *ci);

void FLD3D_CI_SetupSequence(void *event, Fld3dCi *ci, Fld3dCiSeq *seq, int sequenceId);

void FLD3D_CI_EndSequence(Fld3dCi *ci, Fld3dCiSeq *seq);

void FLD3D_CI_StartTrack(Fld3dCi *ci, int track);

void FLD3D_CI_FollowTargetCallback(void *arg);

void FLD3D_CI_LoadSequence(Fld3dCiSeq *seq, u32 sequenceId, u32 heapId);

void FLD3D_CI_FreeSequence(Fld3dCiSeq *seq);

void FLD3D_CI_StartScreenCapture(Fld3dCi *ci);

void FLD3D_CI_CaptureTask(struct TcbTask *task, void *arg);

void FLD3D_CI_SaveLayerPriorities(Fld3dCi *ci);

void FLD3D_CI_SaveVisiblePlanes(Fld3dCi *ci);

void FLD3D_CI_RestoreLayerPriorities(Fld3dCi *ci);

void FLD3D_CI_RestoreVisiblePlanes(Fld3dCi *ci);

int FLD3D_CI_PokemonExtraTask(void *event, int *state);

int FLD3D_CI_PokemonFinishStep(void *event, Fld3dCi *ci);

void FLD3D_CI_LoadPokemonIconTexture(Fld3dCi *ci);

int FLD3D_CI_FadeOutTask(void *event, int *state);

int FLD3D_CI_FadeInTask(void *event, int *state);

int FLD3D_CI_FadeInAltTask(void *event, u32 *state);

int FLD3D_CI_IsAltFadeSequence(u16 sequenceId);

void FLD3D_CI_LoadNameTexture(Fld3dCi *ci, const char *texName, const char *plttName, u32 chrFile, u32 plttFile);

int FLD3D_CI_NameFinishStep(void *event, Fld3dCi *ci);

int FLD3D_CI_NameExtraTask(void *event, int *state);

int FLD3D_CI_GetTexDataOffset(Fld3dCiTexBlock *texBlock, Fld3dCiTexDictEntry *entry);

int FLD3D_CI_GetPlttDataOffset(Fld3dCiTexBlock *texBlock, Fld3dCiPlttDictEntry *entry);

int FLD3D_CI_FindTexture(Fld3dCiTexBlock *texBlock, const char *name);

int FLD3D_CI_FindPalette(Fld3dCiTexBlock *texBlock, const char *name);

void FLD3D_CI_CopyName(char *dst, const char *src);

void FLD3D_CI_DrawMessageTexture(void *playerStatus, Fld3dCi *ci, const char *texName, const char *plttName, u32 msgId, u32 centered);

void *FLD3D_CI_StartMessageSequence(void *gameSystem, Fld3dCi *ci, u32 nameMsgId);

void FLD3D_CI_DarkenCapturedScreen(u32 unused);

void FLD3D_CI_InitEventWork(Fld3dCi *ci, Fld3dCiEventWork *work);

void FLD3D_CI_PlayCueSound(Fld3dCi *ci);

void FLD3D_CI_DisplayRestoreTask(struct TcbTask *task, void *arg);

extern u8 d_021DE3D8;

extern const VecFx32 d_021DA6E8;

extern const VecFx32 d_021DA6D0;

extern const VecFx32 d_021DA6F4;

extern const VecFx32 d_021DA6DC;

extern const s16 d_020A1EB8[];

extern u32 d_021DA7F4[];

extern unsigned char abs_id_4A[];

extern const DispConfig d_021DA710;

extern char d_021DE3E4[];

extern char d_021DE3F4[];

extern char d_021DE404[];

extern char d_021DE40C[];

extern char d_021DE418[];

extern char d_021DE428[];

extern char d_021DE43C[];

extern char d_021DE448[];

extern Fld3dCiCue *d_021DA720[];

extern const DispConfig d_021DA700;

static inline void *MakeCamera(int kind, int fovSin, int fovCos, int aspect, int orthoExtent, int nearClip, int farClip, int scaleW, VecFx32 *pos, const VecFx32 *upsrc, VecFx32 *target, int heapId)
{
    VecFx32 up = *upsrc;
    return G3D_CAMERA_Create(kind, fovSin, fovCos, aspect, orthoExtent, nearClip, farClip, scaleW, pos, &up, target, heapId);
}

static inline void *MakePerspCamera(VecFx32 *pos, const VecFx32 *upsrc, VecFx32 *target, int heapId)
{
    return MakeCamera(0, d_020A1EB8[6], d_020A1EB8[7], 0x1555, 0, 0x1000, 0x400000, 0, pos, upsrc, target, heapId);
}

/*
 * note:     stack slots (high to low) pos1, tgt1, pos2, tgt2, up2, up1. The caller's block
 *           locals take the top slots in textual order; each up vector is an inline helper's
 *           local, and the first call reaching the helper one inline level deeper (through
 *           MakePerspCamera) is what puts up1 below up2. Both calls through MakeCamera directly: up1/up2
 *           swapped (2 bytes out). The zero targets need a brace initialiser in a declaration.
 */
Fld3dCi *FLD3D_CI_Create(u32 heapId, FldParticle *particle)
{
    Fld3dCi *ci;

    ci = GFL_HEAP_Alloc(heapId, 0x138, 1, (const char *)&d_021DE3D8, 0x158);
    ci->gfxUnits = G3D_UTIL_Create(8, 2, heapId);
    ci->heapId = heapId;
    ci->particle = particle;
    ci->effectUnit = -1;
    {
        VecFx32 perspPos = d_021DA6E8;
        VecFx32 perspTarget = {0, 0, 0};
        ci->cameraPersp = MakePerspCamera(&perspPos, &d_021DA6D0, &perspTarget, heapId);
    }
    {
        VecFx32 orthoPos = d_021DA6F4;
        VecFx32 orthoTarget = {0, 0, 0};
        ci->cameraOrtho = MakeCamera(2, 0x30000, -0x30000, -0x40000, 0x40000, 0x1000, 0x400000, 0, &orthoPos, &d_021DA6DC, &orthoTarget, heapId);
    }
    ci->cameraSelect = 0;
    return ci;
}

/*
 * Releases the effect handles and frees the object (EXACT*: trailing pad).
 */
void FLD3D_CI_Delete(Fld3dCi *ci)
{
    G3D_CAMERA_Delete(ci->cameraPersp);
    G3D_CAMERA_Delete(ci->cameraOrtho);
    G3D_UTIL_Delete(ci->gfxUnits);
    GFL_HEAP_Free(ci);
}

/* Adds the sequence's resource table as a graphics unit and resets the draw status. */
int FLD3D_CI_SetupEffectUnit(Fld3dCi *ci, G3dUtilSetup *setup)
{
    ci->effectUnit = G3D_UTIL_AddUnit(ci->gfxUnits, setup);
    ci->status.scale.x = (1 << 12);
    ci->status.scale.y = (1 << 12);
    ci->status.scale.z = (1 << 12);
    MTX_Identity33_((uptr)&ci->status.rotate);
    ci->status.trans.x = 0;
    ci->status.trans.y = 0;
    ci->status.trans.z = 0;
    return 0;
}

/* Draws every object of the effect unit with the current status. */
void FLD3D_CI_DrawEffect(Fld3dCi *ci)
{
    int first;
    int count;
    sptr object;
    u8 i;

    if (ci->cameraSelect == 0)
        G3D_CAMERA_Reset(ci->cameraPersp);
    else
        G3D_CAMERA_Reset(ci->cameraOrtho);
    if (ci->effectUnit != -1) {
        first = (int)G3D_UTIL_GetUnitObjIdx(ci->gfxUnits, (u16)ci->effectUnit);
        count = (int)G3D_UTIL_GetUnitObjCount(ci->gfxUnits, (u16)ci->effectUnit);
        for (i = 0; i < count; i++) {
            object = (int)G3D_UTIL_GetObject(ci->gfxUnits, (u16)(first + i));
            G3D_SYSTEM_DrawObject((void *)object, &ci->status);
        }
    }
}

/* Starts the game event of a cut-in sequence when there is memory for it. */
void *FLD3D_CI_StartSequence(void *gameSystem, Fld3dCi *ci, int sequenceId)
{
    void *event;

    if (GFL_HEAP_GetAllocatableSize(0x15) < d_021DA7F4[sequenceId])
        return 0;
    ci->started = 0;
    ci->finishState = 0;
    ci->frame = 0;
    ci->cueIndex = 0;
    ci->sequenceId = sequenceId;
    ci->extraTask = 0;
    ci->finishStep = 0;
    ci->cameraSelect = 0;
    event = GAME_EVENT_Create(gameSystem, 0, (GameEventFunc)FLD3D_CI_EventMain, 0x40);
    FLD3D_CI_InitEventWork(ci, GAME_EVENT_GetWork(event));
    return event;
}

/* Starts the pokemon cut-in (sequence 3) with the pokemon description in the arguments. */
void *FLD3D_CI_StartPokemonSequence(void *gameSystem, Fld3dCi *ci, int species, int form, int attr6E, int personality, int attr4C)
{
    Fld3dCiPokemon *pokemon;
    void *event;

    event = FLD3D_CI_StartSequence(gameSystem, ci, 3);
    if (event == 0)
        return 0;
    ci->extraTask = FLD3D_CI_PokemonExtraTask;
    ci->finishStep = FLD3D_CI_PokemonFinishStep;
    pokemon = &ci->arg.pokemon;
    pokemon->attr6E = attr6E;
    ci->arg.pokemon.species = species;
    pokemon->personality = personality;
    pokemon->form = form;
    pokemon->attr4C = attr4C;
    pokemon->cryDelay = 5;
    pokemon->cryPending = 1;
    pokemon->cryFadeWait = 0x1e;
    return event;
}

/* Starts the pokemon cut-in for the party member at partyPos. */
void *FLD3D_CI_StartPartyMemberSequence(void *gameSystem, Fld3dCi *ci, int partyPos)
{
    sptr mon;
    int species;
    int form;
    int attr6E;
    int personality;
    int attr4C;

    mon = (sptr)POKEPARTY_GetMember(GAME_DATA_GetMyParty(GAMESYSTEM_GetGameData(gameSystem)), partyPos);
    species = POKE_TOOL_GetPartyValue((void *)mon, 5, 0);
    form = POKE_TOOL_GetPartyValue((void *)mon, 0x6f, 0);
    attr6E = POKE_TOOL_GetPartyValue((void *)mon, 0x6e, 0);
    personality = POKE_TOOL_IsShiny((void *)mon);
    attr4C = POKE_TOOL_GetPartyValue((void *)mon, 0x4c, 0);
    return FLD3D_CI_StartPokemonSequence(gameSystem, ci, species, form, attr6E, personality, attr4C);
}

/* Starts a name cut-in whose icon files come from a table row. */
void *FLD3D_CI_StartNameSequence(void *gameSystem, Fld3dCi *ci, int tableIndex, int fadeVariant)
{
    const Fld3dCiNameRow *row;
    void *event;
    Fld3dCiEventWork *work;
    Fld3dCiIcon *icon;

    GF_OVERLAY_Load((sptr)abs_id_4A);
    row = FLD3D_CI_GetNameRow(tableIndex);
    event = FLD3D_CI_StartSequence(gameSystem, ci, (u8)row->sequenceId);
    if (event == 0) {
        GF_OVERLAY_Unload((sptr)abs_id_4A);
        return 0;
    }
    work = GAME_EVENT_GetWork(event);
    FLD3D_CI_InitEventWork(ci, work);
    work->fadeVariant = fadeVariant;
    if (row->nameLayout != 0)
        ci->extraTask = FLD3D_CI_NameExtraTask;
    else
        ci->extraTask = 0;
    ci->finishStep = FLD3D_CI_NameFinishStep;
    ci->cameraSelect = 2;
    icon = &ci->arg.icon;
    icon->nameMsgId = row->nameMsgId;
    icon->chrFile = row->chrFile;
    icon->plttFile = row->plttFile;
    if (row->nameLayout == 1)
        icon->hasSecondName = 1;
    else
        icon->hasSecondName = 0;
    if (row->sequenceId == 0xd && icon->hasSecondName != 0)
        icon->secondNameCentered = 1;
    else
        icon->secondNameCentered = 0;
    GF_OVERLAY_Unload((sptr)abs_id_4A);
    return event;
}

/* Main step of the cut-in game event: one state per call. */
int FLD3D_CI_EventMain(void *event, int *state, Fld3dCiEventWork *work)
{
    Fld3dCi *ci;
    void *gameSystem;
    void *fieldMap;
    int doneB;
    int doneC;
    uptr modelSys;
    uptr particleSys;
    DispConfig bgMode;

    ci = work->ci;
    gameSystem = GAME_EVENT_GetGameSystem(event);
    fieldMap = GAMESYSTEM_GetFieldMap(gameSystem);
    switch (*state) {
    case 0:
        if (work->hideFieldObjects)
            FLDMMDL_SysPauseMove(FIELDMAP_GetMmdlSys(fieldMap));
        FLD3D_CI_SaveLayerPriorities(ci);
        FLD3D_CI_SaveVisiblePlanes(ci);
        if (FLD3D_CI_IsAltFadeSequence(ci->sequenceId) == 0)
            GAME_EVENT_CallEvent(event, GAME_EVENT_Create(gameSystem, event, (GameEventFunc)FLD3D_CI_FadeOutTask, 0));
        (*state)++;
        break;
    case 1:
        (*state)++;
        if (ci->sequenceId == 0xb || ci->sequenceId == 0x12) {
            FLDMMDL_SetStatusBitVanish(FIELD_PLAYER_GetMmdl(FIELDMAP_GetFieldPlayer(fieldMap)), 1);
            break;
        }
        if (ci->sequenceId == 0x11) {
            u32 mmdl = (uptr)FLDMMDL_SysSearchObjId(FIELDMAP_GetMmdlSys(fieldMap), (u16)ci->arg.pokemon.species);
            if (mmdl)
                FLDMMDL_DeleteMmdl((struct Mmdl *)mmdl);
            break;
        }
    case 2:
        FIELDMAP_SetUpdateStopped(fieldMap, 1);
        FLD3D_CI_StartScreenCapture(ci);
        (*state)++;
        break;
    case 3:
        if (ci->captureDone == 0)
            break;
        BG_SYS_SetPriority(0, 0);
        BG_SYS_SetPriority(2, 1);
        bgMode = d_021DA710;
        BG_SYS_SetGraphicsMode(&bgMode);
        *(vu16 *)0x0400000C = (*(vu16 *)0x0400000C & 0x43) | 0x4084;
        GX_SetBankForBG(8);
        G2x_SetBlendAlpha_((u32 *)REG_BLDCNT_ADDR, 0, 4, 0, 0);
        BG_SYS_SetPlaneVisible(2, 1);
        FIELD_FOG_SetFlag(FIELDMAP_GetFog(fieldMap), 0);
        (*state)++;
        break;
    case 4:
        FLD3D_CI_SetupSequence(event, ci, &work->seq, (u8)ci->sequenceId);
        BG_SYS_SetPlaneVisible(2, 1);
        BG_SYS_SetPlaneVisible(0, 1);
        GFL_HEAP_GetHeapHead(ci->heapId);
        FIELDMAP_SetDrawMode(fieldMap, 1);
        if (work->seq.darkenScreen)
            FLD3D_CI_DarkenCapturedScreen(work->seq.darkenScreen);
        (*state)++;
        break;
    case 5:
        if (FLD3D_CI_IsAltFadeSequence(ci->sequenceId))
            GAME_EVENT_CallEvent(event, GAME_EVENT_Create(gameSystem, event, (GameEventFunc)FLD3D_CI_FadeInAltTask, 0));
        else
            GAME_EVENT_CallEvent(event, GAME_EVENT_Create(gameSystem, event, (GameEventFunc)FLD3D_CI_FadeInTask, 0));
        (*state)++;
        break;
    case 6:
        if (GFL_USE_IsLoaderBusy())
            break;
        (*state)++;
    case 7:
        {
            int doneA;
            int finished;
            ci->frame += 1;
            doneA = FLD3D_CI_UpdateStartDelays(ci);
            doneB = FLD3D_CI_UpdateTrackA(ci);
            doneC = FLD3D_CI_UpdateTrackB(ci);
            ci->startDone = doneA;
            ci->trackADone = doneB;
            ci->trackBDone = doneC;
            FLD3D_CI_PlayCueSound(ci);
            finished = 0;
            if (ci->finishStep)
                finished = ci->finishStep(event, ci);
            else if (ci->startDone && ci->trackADone && ci->trackBDone)
                finished = 1;
            if (finished == 0)
                break;
        }
        (*state)++;
        break;
    case 8:
        FIELDMAP_SetDrawMode(fieldMap, 0);
        FLD3D_CI_EndSequence(ci, &work->seq);
        if (FLD3D_CI_IsAltFadeSequence(ci->sequenceId)) {
            void *mmdlSys = FIELD_PLAYER_GetMmdl(FIELDMAP_GetFieldPlayer(fieldMap));
            FLDMMDL_SetStatusBitVanish(mmdlSys, 0);
            FLDMMDL_SetDirDispCheckPause((struct Mmdl *)mmdlSys, 1);
            FIELDMAP_SetUpdateStopped(fieldMap, 0);
        } else {
            BG_SYS_SetPlaneVisible(0, 0);
            G3X_SetClearColor(0, 0x1f, 0x7fff, 0, 0);
        }
        FIELD_FOG_SetFlag(FIELDMAP_GetFog(fieldMap), 1);
        (*state)++;
        break;
    case 9:
        FIELD_LIGHT_Reflect(FIELDMAP_GetLight(fieldMap), 1);
        ci->displayRestoreDone = 0;
        GFL_USE_AddMainTask(FLD3D_CI_DisplayRestoreTask, &ci->displayRestoreDone, 0);
        (*state)++;
        break;
    case 10:
        if (ci->displayRestoreDone == 0)
            break;
        GFL_HEAP_GetHeapHead(ci->heapId);
        modelSys = (uptr)FIELDMAP_GetMsgBg(fieldMap);
        particleSys = (uptr)FIELDMAP_GetPlaceName(fieldMap);
        FIELD_MSGBG_ReloadBg((struct FieldMsgBg *)modelSys);
        FIELD_PLACE_NAME_RestoreWindow((struct FieldPlaceName *)particleSys);
        FIELD_MSGBG_RequestSysFrame((struct FieldMsgBg *)modelSys);
        *(vu16 *)0x0400000C = (*(vu16 *)0x0400000C & 0x43) | 0x1f18;
        BG_SYS_FreeSlot(2);
        FLD3D_CI_RestoreLayerPriorities(ci);
        FLD3D_CI_RestoreVisiblePlanes(ci);
        FIELDMAP_SetUpdateStopped(fieldMap, 0);
        if (work->hideFieldObjects)
            FLDMMDL_SysResumeMove(FIELDMAP_GetMmdlSys(fieldMap));
        (*state)++;
        break;
    case 11:
        return 1;
    }
    return 0;
}

/* Counts down the two start delays and starts the animation tracks; 1 when both ran and the effect ended. */
int FLD3D_CI_UpdateStartDelays(Fld3dCi *ci)
{
    if (ci->started == 0) {
        if (ci->trackStarted[0] == 0) {
            if (ci->startDelay[0] != 0) {
                (ci->startDelay[0])--;
            } else {
                FLD3D_CI_StartTrack(ci, 0);
                ci->trackStarted[0] = 1;
            }
        }
        if (ci->trackStarted[1] == 0) {
            if (ci->startDelay[1] != 0) {
                (ci->startDelay[1])--;
            } else {
                FLD3D_CI_StartTrack(ci, 1);
                ci->trackStarted[1] = 1;
            }
        }
        if (ci->trackStarted[0] != 0 && ci->trackStarted[1] != 0)
            ci->started = 1;
    } else if (FLD_PARTICLE_IsEffectFinished(ci->particle) != 0) {
        return 1;
    }
    return 0;
}

/* Steps the first animation track after its wait delay; 1 when unused or finished. */
int FLD3D_CI_UpdateTrackA(Fld3dCi *ci)
{
    sptr object;
    u8 i;
    int result;
    int count;

    if (ci->trackWatched[0] == 0)
        return 1;
    if (ci->waitDelay[0] != 0) {
        (ci->waitDelay[0])--;
    } else {
        object = G3D_UTIL_GetObject(ci->gfxUnits, (int)G3D_UTIL_GetUnitObjIdx(ci->gfxUnits, (u16)(ci->effectUnit)));
        count = G3D_SYSTEM_GetObjectAnimeCount((G3dObject *)object);
        for (i = 0; i < count; i++)
            result = G3D_SYSTEM_IncObjectAnimeFrame((G3dObject *)object, i, 0x1000);
        if (result == 0)
            return 1;
    }
    return 0;
}

/* Same as above for the second animation track. */
int FLD3D_CI_UpdateTrackB(Fld3dCi *ci)
{
    sptr object;
    u8 i;
    int result;
    int count;

    if (ci->trackWatched[1] == 0)
        return 1;
    if (ci->waitDelay[1] != 0) {
        (ci->waitDelay[1])--;
    } else {
        object = (int)G3D_UTIL_GetObject(ci->gfxUnits, (u16)((int)G3D_UTIL_GetUnitObjIdx(ci->gfxUnits, (u16)(ci->effectUnit)) + 1));
        count = G3D_SYSTEM_GetObjectAnimeCount((G3dObject *)object);
        for (i = 0; i < count; i++)
            result = G3D_SYSTEM_IncObjectAnimeFrame((G3dObject *)object, i, 0x1000);
        if (result == 0)
            return 1;
    }
    return 0;
}

/* Loads the sequence data and resets the animation state of the cut-in. */
void FLD3D_CI_SetupSequence(void *event, Fld3dCi *ci, Fld3dCiSeq *seq, int sequenceId)
{
    sptr effectRes;
    u8 unit;
    int first;
    int unitCount;
    u8 j;
    sptr object;
    int animCount;
    int trackKind;

    ci->effect = FLD_PARTICLE_CreateEffect(ci->particle);
    FLD3D_CI_LoadSequence(seq, sequenceId, ci->heapId);
    FLD3D_CI_SetupEffectUnit(ci, &seq->setup);
    if (seq->effectResId != 0xFFFF) {
        effectRes = (sptr)FLD_PARTICLE_LoadResource(ci->particle, 0x73, seq->effectResId);
        FLD_PARTICLE_StartEmitter(ci->particle, (void *)effectRes, 1, 0);
    } else {
        effectRes = 0;
    }
    first = (int)G3D_UTIL_GetUnitObjIdx(ci->gfxUnits, (u16)ci->effectUnit);
    unitCount = (int)G3D_UTIL_GetUnitObjCount(ci->gfxUnits, (u16)ci->effectUnit);
    for (unit = 0; unit < unitCount; unit++) {
        object = (int)G3D_UTIL_GetObject(ci->gfxUnits, (u16)(first + unit));
        animCount = G3D_SYSTEM_GetObjectAnimeCount((G3dObject *)object);
        for (j = 0; j < animCount; j++)
            G3D_SYSTEM_EnableObjectAnime((G3dObject *)object, (u8)j);
    }
    ci->startDelay[0] = seq->startDelay[0];
    ci->startDelay[1] = seq->startDelay[1];
    ci->waitDelay[0] = seq->waitDelay[0];
    ci->waitDelay[1] = seq->waitDelay[1];
    if (effectRes != 0)
        trackKind = PARTICLE_RESOURCE_GetType((void *)effectRes);
    else
        trackKind = 0;
    if (trackKind == 2) {
        ci->trackStarted[0] = 0;
        ci->trackStarted[1] = 0;
    } else if (trackKind == 1) {
        ci->trackStarted[0] = 0;
        ci->trackStarted[1] = 1;
    } else {
        ci->trackStarted[0] = 1;
        ci->trackStarted[1] = 1;
    }
    ci->trackWatched[0] = 0;
    ci->trackWatched[1] = 0;
    if (seq->trackBCount != 0)
        ci->trackWatched[0] = 1;
    if (seq->trackCCount != 0)
        ci->trackWatched[1] = 1;
    if (ci->extraTask != 0) {
        object = (sptr)GAME_EVENT_GetGameSystem(event);
        GAME_EVENT_CallEvent(event, GAME_EVENT_Create((void *)object, event, (void *)(ci->extraTask), (int)0));
    }
}

/* Frees the sequence data, deletes the effect unit and the effect. */
void FLD3D_CI_EndSequence(Fld3dCi *ci, Fld3dCiSeq *seq)
{
    FLD3D_CI_FreeSequence(seq);
    G3D_UTIL_RemoveUnit(ci->gfxUnits, (u16)ci->effectUnit);
    ci->effectUnit = (~0);
    FLD_PARTICLE_DeleteEffect(ci->particle);
}

/*
 * EXACT*: the 72-byte listing extent runs on into the unlabelled leaf
 * FLD3D_CI_FollowTargetCallback (FLD3D_CI_FollowTargetCallback.c), whose EXACT entry attests the
 * pool word 0x021C24BD as matched.
 */
void FLD3D_CI_StartTrack(Fld3dCi *ci, int track)
{
    PARTICLE_StartEffectWithCallback(ci->effect, track, FLD3D_CI_FollowTargetCallback, 0);
}

/*
 * Unlabelled thumb leaf (push {r4} only), reached through the pool word
 * 0x021C24BD in FLD3D_CI_StartTrack. Char-pointer offsets give the same bytes
 * scheduled differently (34 differ); the struct-typed accesses keep the
 * zero-initialiser stores ahead of the loads, as in the original.
 */
void FLD3D_CI_FollowTargetCallback(void *arg)
{
    Fld3dCiFollow *follow = arg;
    VecFx32 offset = { 0, 0, 0 };
    offset.z = 0x40;
    follow->pos.x = offset.x + (*follow->target)->pos.x;
    follow->pos.y = offset.y + (*follow->target)->pos.y;
    follow->pos.z = offset.z + (*follow->target)->pos.z;
}

/* Reads sequence record sequenceId of archive 0x75 and builds the resource and track tables. */
void FLD3D_CI_LoadSequence(Fld3dCiSeq *seq, u32 sequenceId, u32 heapId)
{
    Fld3dCiSeqFile file;
    u16 ids[8];
    u8 trackACount, trackBCount, trackCCount, total, baseB, baseC;
    u8 i, j, n;

    ARC_TOOL_ReadMember(&file, 0x75, sequenceId);
    trackACount = 0;
    for (i = 0; i < 2; i++) {
        if (file.trackA[i] != 0xFFFF) {
            trackACount++;
        }
    }
    trackCCount = 0;
    trackBCount = 0;
    for (i = 0; i < 4; i++) {
        if (file.trackB[i] != 0xFFFF) {
            trackBCount++;
        }
    }
    for (i = 0; i < 4; i++) {
        if (file.trackC[i] != 0xFFFF) {
            trackCCount++;
        }
    }
    baseB = 0 + trackACount;
    baseC = baseB + trackBCount;
    total = trackACount + trackBCount + trackCCount;
    if (total != 0) {
        seq->resources = GFL_HEAP_Alloc(heapId, total * 12, 1, (const char *)&d_021DE3D8, 0x566);
    }
    if (trackACount != 0) {
        seq->tracks = GFL_HEAP_Alloc(heapId, trackACount * 16, 1, (const char *)&d_021DE3D8, 0x56a);
    }
    if (trackBCount != 0) {
        seq->refsB = GFL_HEAP_Alloc(heapId, trackBCount * 4, 1, (const char *)&d_021DE3D8, 0x56e);
    }
    if (trackCCount != 0) {
        seq->refsC = GFL_HEAP_Alloc(heapId, trackCCount * 4, 1, (const char *)&d_021DE3D8, 0x572);
    }
    seq->total = total;
    seq->trackACount = trackACount;
    seq->trackBCount = trackBCount;
    seq->trackCCount = trackCCount;
    seq->startDelay[0] = file.startDelay[0];
    seq->startDelay[1] = file.startDelay[1];
    seq->waitDelay[0] = file.waitDelay[0];
    seq->waitDelay[1] = file.waitDelay[1];
    ids[0] = file.trackA[0];
    ids[1] = file.trackA[1];
    ids[2] = file.trackB[0];
    ids[3] = file.trackB[1];
    ids[4] = file.trackB[2];
    ids[5] = file.trackC[0];
    ids[6] = file.trackC[1];
    ids[7] = file.trackC[2];
    n = 0;
    for (j = 0; j < 8; j++) {
        if (ids[j] != 0xFFFF) {
            seq->resources[n].arc = 0x73;
            seq->resources[n].dat = ids[j];
            seq->resources[n].type = 0;
            n++;
        }
    }
    for (i = 0; i < trackBCount; i++) {
        seq->refsB[i].anmResIdx = baseB + i;
        seq->refsB[i].anmDatIdx = 0;
    }
    for (i = 0; i < trackCCount; i++) {
        seq->refsC[i].anmResIdx = baseC + i;
        seq->refsC[i].anmDatIdx = 0;
    }
    for (i = 0; i < trackACount; i++) {
        seq->tracks[i].mdlResIdx = 0 + i;
        seq->tracks[i].mdlDatIdx = 0;
        seq->tracks[i].texResIdx = 0 + i;
    }
    if (trackACount >= 1) {
        seq->tracks[0].anmTbl = seq->refsB;
        seq->tracks[0].anmCount = trackBCount;
    }
    if (trackACount >= 2) {
        seq->tracks[1].anmTbl = seq->refsC;
        seq->tracks[1].anmCount = trackCCount;
    }
    seq->setup.resTbl = seq->resources;
    seq->setup.resCount = total;
    seq->setup.objCount = trackACount;
    seq->setup.objTbl = seq->tracks;
    seq->effectResId = file.effectResId;
    seq->darkenScreen = file.darkenScreen;
}

/*
 * Frees the four optional buffers (EXACT*: trailing pad).
 */
void FLD3D_CI_FreeSequence(Fld3dCiSeq *seq)
{
    if (seq->refsB != 0)
        GFL_HEAP_Free(seq->refsB);
    if (seq->refsC != 0)
        GFL_HEAP_Free(seq->refsC);
    if (seq->tracks != 0)
        GFL_HEAP_Free(seq->tracks);
    if (seq->resources != 0)
        GFL_HEAP_Free(seq->resources);
}

/*
 * Clears the capture flag and starts the capture task.
 */
void FLD3D_CI_StartScreenCapture(Fld3dCi *ci)
{
    ci->captureDone = 0;
    GX_SetBankForLCDC(8);
    GFL_USE_AddMainTask(FLD3D_CI_CaptureTask, &ci->captureDone, 0);
}

/*
 * VBlank task: arms display capture, ends itself, flags completion.
 */
void FLD3D_CI_CaptureTask(struct TcbTask *task, void *arg)
{
    u32 *done = arg;
    *(volatile u32 *)0x04000064 = 0x81330010;
    TCB_DeleteTask(task);
    if (done != 0)
        *done = 1;
}

/*
 * Saves the four layer priorities.
 */
void FLD3D_CI_SaveLayerPriorities(Fld3dCi *ci)
{
    int i;
    for (i = 0; i < 4; i++)
        ci->savedLayerPriority[i] = BG_SYS_GetPriority((u8)i);
}

void FLD3D_CI_SaveVisiblePlanes(Fld3dCi *ci)
{
    ci->savedVisiblePlanes = BG_SYS_GetMainVisiblePlanes();
}

/*
 * Restores the four saved layer priorities (EXACT*: unlabelled follower).
 */
void FLD3D_CI_RestoreLayerPriorities(Fld3dCi *ci)
{
    int i;
    for (i = 0; i < 4; i++)
        BG_SYS_SetPriority((u8)i, ci->savedLayerPriority[i]);
}

void FLD3D_CI_RestoreVisiblePlanes(Fld3dCi *ci)
{
    BG_SYS_SetMainVisiblePlanes(ci->savedVisiblePlanes);
}

/* Extra task of the pokemon cut-in: builds the pokemon icon texture, then frees its resources. */
int FLD3D_CI_PokemonExtraTask(void *event, int *state)
{
    Fld3dCi *ci;
    Fld3dCiEventWork *parentWork;

    parentWork = GAME_EVENT_GetWork(GAME_EVENT_GetParent(event));
    ci = parentWork->ci;
    GAMESYSTEM_GetFieldMap(GAME_EVENT_GetGameSystem(event));
    switch (*state) {
    case 0:
        FLD3D_CI_LoadPokemonIconTexture(ci);
        (*state)++;
        break;
    case 1:
        BMP_Delete(ci->canvas);
        GFL_HEAP_Free(ci->chrRes);
        GFL_HEAP_Free(ci->plttRes);
        (*state)++;
        break;
    case 2:
        return 1;
    }
    return 0;
}

/* Finish step of the pokemon cut-in: plays the cry after its delay and waits for it to fade. */
int FLD3D_CI_PokemonFinishStep(void *event, Fld3dCi *ci)
{
    int done;
    Fld3dCiPokemon *pokemon;
    char voiceBuf[4];

    pokemon = &ci->arg.pokemon;
    if (pokemon->cryPending != 0 && pokemon->cryDelay != 0) {
        (pokemon->cryDelay)--;
        if (pokemon->cryDelay == 0) {
            if (pokemon->species == 0x1b9) {
                PM_VOICE_GetPerapVoiceSave((struct SaveBlock **)voiceBuf);
                pokemon->cryHandle = PM_VOICE_Play(pokemon->species, pokemon->form, 0x40, 0, 0, 0, 0, (void **)voiceBuf);
            } else {
                pokemon->cryHandle = PM_VOICE_Play(pokemon->species, pokemon->form, 0x40, 0, 0, 0, 0, 0);
            }
        }
        pokemon->cryFadeWait = 0x1e;
        return 0;
    }
    done = 0;
    if (pokemon->cryDelay == 0) {
        if (PM_VOICE_IsAnyActive() == 0) {
            done = 1;
        } else if (pokemon->cryFadeWait != 0) {
            (pokemon->cryFadeWait)--;
        } else if (PM_VOICE_GetVolume(pokemon->cryHandle) > 0) {
            PM_VOICE_AddVolume(pokemon->cryHandle, done - 16);
        } else {
            PM_VOICE_StopAll();
            done = 1;
        }
    }
    if (ci->startDone != 0 && ci->trackADone != 0 && ci->trackBDone != 0 && done != 0)
        return 1;
    return 0;
}

/*
 * Twin of ov195 SHINKA_DEMO_VIEW_CreateGrid (same tile-copy body). The far argument block
 * at +0x9C needs a local pointer (args = ci->arg.args), and the two size calls
 * must land in int locals before the (u16) << 3 conversions.
 */
void FLD3D_CI_LoadPokemonIconTexture(Fld3dCi *ci)
{
    u16 heapId;
    u8 *tileBuf;
    int j;
    u32 texOffset;
    u32 plttOffset;
    u8 *chrSrc;
    u32 chrFile;
    u32 plttFile;
    void *texBlock;
    u32 *args;
    int texSize;
    int plttSize;
    int i;
    int tile;

    heapId = ci->heapId;
    ci->canvas = BMP_Create(16, 16, 32, heapId);
    tile = 0;
    texBlock = (void *)G3D_UTIL_GetResource(ci->gfxUnits, 0);
    texSize = G3D_SYSTEM_GetTexVramKey(texBlock);
    plttSize = G3D_SYSTEM_GetPlttVramKey(texBlock);
    texOffset = (u16)texSize << 3;
    plttOffset = (u16)plttSize << 3;
    args = ci->arg.args;
    chrFile = POKEGRA_GetCgrArcIndex(POKEGRA_GetArcID(), args[0], args[1], args[2], args[3], 0, args[4]);
    plttFile = POKEGRA_GetPalArcIndex(POKEGRA_GetArcID(), args[0], args[1], args[2], args[3], 0, args[4]);
    ci->chr = 0;
    ci->pltt = 0;
    ci->chrRes = ARC_UTIL_LoadScreenDataFromArchive(POKEGRA_GetArcID(), chrFile, 1, (&ci->chr), heapId);
    ci->plttRes = ARC_UTIL_LoadPaletteBlockFromArchive(POKEGRA_GetArcID(), plttFile, (&ci->pltt), heapId);
    chrSrc = ci->chr->raw;
    tileBuf = BMP_GetPixels(ci->canvas);
    MIi_CpuClear32(0, tileBuf, 0x2000);
    for (j = 0; j < 8; j++) {
        for (i = 0; i < 8; i++) {
            MIi_CpuCopy32(chrSrc + tile * 32, tileBuf + 0x440 + (i + j * 16) * 32, 32);
            tile++;
        }
    }
    for (j = 0; j < 8; j++) {
        for (i = 8; i < 12; i++) {
            MIi_CpuCopy32(chrSrc + tile * 32, tileBuf + 0x440 + (i + j * 16) * 32, 32);
            tile++;
        }
    }
    for (j = 8; j < 12; j++) {
        for (i = 0; i < 8; i++) {
            MIi_CpuCopy32(chrSrc + tile * 32, tileBuf + 0x440 + (i + j * 16) * 32, 32);
            tile++;
        }
    }
    for (j = 8; j < 12; j++) {
        for (i = 8; i < 12; i++) {
            MIi_CpuCopy32(chrSrc + tile * 32, tileBuf + 0x440 + (i + j * 16) * 32, 32);
            tile++;
        }
    }
    BMP_ConvertToLinear(ci->canvas, 0, heapId);
    NNS_GfdRegisterNewVramTransferTask(0, texOffset, (uptr)BMP_GetPixels(ci->canvas), 0x2000);
    NNS_GfdRegisterNewVramTransferTask((void *)1, plttOffset, (uptr)ci->pltt->raw, 0x20);
    GFL_HEAP_GetHeapHead(ci->heapId);
}

/* Fade task: fades the screen out. */
int FLD3D_CI_FadeOutTask(void *event, int *state)
{
    GAMESYSTEM_GetFieldMap(GAME_EVENT_GetGameSystem(event));
    switch (*state) {
    case 0:
        FADE_Start(4, 0, 0x10, -1);
        (*state)++;
        break;
    case 1:
        if (FADE_IsActive() == 0)
            return 1;
        break;
    }
    return 0;
}

/*
 * Fade-in task: start the fade, then wait for it to finish.
 */
int FLD3D_CI_FadeInTask(void *event, int *state)
{
    GAMESYSTEM_GetFieldMap(GAME_EVENT_GetGameSystem(event));
    switch (*state) {
    case 0:
        FADE_Start(4, 0x10, 0, -1);
        (*state)++;
        break;
    case 1:
        if (FADE_IsActive() == 0)
            return 1;
        break;
    }
    return 0;
}

int FLD3D_CI_FadeInAltTask(void *event, u32 *state)
{
    GAMESYSTEM_GetFieldMap(GAME_EVENT_GetGameSystem(event));
    switch (state[0]) {
    case 0:
        FADE_Start(3, 0x10, 0, 0);
        state[0]++;
        break;
    case 1:
        if (FADE_IsActive() == 0)
            return 1;
        break;
    }
    return 0;
}

/*
 * Unlabelled leaf: true for the two ids 0xC and 0x13.
 */
int FLD3D_CI_IsAltFadeSequence(u16 sequenceId)
{
    if (sequenceId == 0xc || sequenceId == 0x13)
        return 1;
    return 0;
}

/*
 * Sibling of FLD3D_CI_LoadPokemonIconTexture (same object layout at +0x88..+0x98), 16x16
 * tile copy with archive 0xB4 and file ids passed in.
 */
void FLD3D_CI_LoadNameTexture(Fld3dCi *ci, const char *texName, const char *plttName, u32 chrFile, u32 plttFile)
{
    u32 texOffset;
    u32 plttOffset;
    u16 heapId;
    u8 *tileBuf;
    int j;
    void *texBlock;
    void *modelRes;
    u8 *chrSrc;
    int i;
    int tile;

    heapId = ci->heapId;
    tile = 0;
    texBlock = (void *)G3D_UTIL_GetResource(ci->gfxUnits, 0);
    G3D_SYSTEM_GetTexVramKey(texBlock);
    G3D_SYSTEM_GetPlttVramKey(texBlock);
    modelRes = NNS_G3dGetTex(G3D_SYSTEM_GetResourceFile(texBlock));
    texOffset = FLD3D_CI_FindTexture(modelRes, texName);
    plttOffset = FLD3D_CI_FindPalette(modelRes, plttName);
    ci->chr = 0;
    ci->pltt = 0;
    ci->chrRes = ARC_UTIL_LoadBgCharDataFromArchive(0xb4, chrFile, 1, (&ci->chr), heapId);
    ci->plttRes = ARC_UTIL_LoadPaletteBlockFromArchive(0xb4, plttFile, (&ci->pltt), heapId);
    chrSrc = ci->chr->raw;
    tileBuf = BMP_GetPixels(ci->canvas);
    MIi_CpuClear32(0, tileBuf, 0x2000);
    for (j = 0; j < 16; j++) {
        for (i = 0; i < 16; i++) {
            MIi_CpuCopy32(chrSrc + tile * 32, tileBuf + (i + j * 16) * 32, 32);
            tile++;
        }
    }
    BMP_ConvertToLinear(ci->canvas, 0, heapId);
    NNS_GfdRegisterNewVramTransferTask(0, texOffset, (uptr)BMP_GetPixels(ci->canvas), 0x2000);
    NNS_GfdRegisterNewVramTransferTask((void *)1, plttOffset, (uptr)ci->pltt->raw, 0x20);
    GFL_HEAP_GetHeapHead(ci->heapId);
}

/*
 * GAME_EVENT_GetWork takes the event (the first parameter, still in r0 on the
 * path to the call): that is what keeps r0 live and puts the switch value
 * in r1.
 */
int FLD3D_CI_NameFinishStep(void *event, Fld3dCi *ci)
{
    switch (ci->finishState) {
    case 0:
        if (ci->startDone != 0 && ci->trackADone != 0 && ci->trackBDone != 0)
            ci->finishState = ci->finishState + 1;
        break;
    case 1:
        FADE_Start(((Fld3dCiEventWork *)GAME_EVENT_GetWork(event))->fadeVariant != 0 ? 0xC : 3, 0, 0x10, -1);
        ci->finishState += 1;
    case 2:
        if (FADE_IsActive() == 0)
            return 1;
        break;
    }
    return 0;
}

/* Extra task of the name cut-in: draws the name texture, then the optional second one. */
int FLD3D_CI_NameExtraTask(void *event, int *state)
{
    Fld3dCiEventWork *parentWork;
    void *gameSystem;
    void *playerStatus;
    Fld3dCi *ci;
    Fld3dCiIcon *icon;
    u32 chrFile;
    u32 plttFile;

    parentWork = GAME_EVENT_GetWork(GAME_EVENT_GetParent(event));
    gameSystem = GAME_EVENT_GetGameSystem(event);
    playerStatus = GAME_DATA_GetMyStatus(GAMESYSTEM_GetGameData(gameSystem));
    ci = parentWork->ci;
    GAMESYSTEM_GetFieldMap(gameSystem);
    icon = &ci->arg.icon;
    switch (*state) {
    case 0:
        ci->canvas = BMP_Create(16, 16, 32, ci->heapId);
        FLD3D_CI_LoadNameTexture(ci, d_021DE3E4, d_021DE3F4, icon->chrFile, icon->plttFile);
        (*state)++;
        break;
    case 1:
        BMP_Delete(ci->canvas);
        GFL_HEAP_Free(ci->chrRes);
        GFL_HEAP_Free(ci->plttRes);
        FLD3D_CI_DrawMessageTexture(playerStatus, ci, d_021DE404, d_021DE40C, icon->nameMsgId, 0);
        (*state)++;
        break;
    case 2:
        if (icon->hasSecondName == 0) {
            *state = 4;
            break;
        }
        ci->canvas = BMP_Create(16, 16, 32, ci->heapId);
        if (MYSTATUS_GetSex(playerStatus) == 0) {
            chrFile = 0;
            plttFile = 0x16;
        } else {
            chrFile = 1;
            plttFile = 0x17;
        }
        FLD3D_CI_LoadNameTexture(ci, d_021DE418, d_021DE428, chrFile, plttFile);
        (*state)++;
        break;
    case 3:
        BMP_Delete(ci->canvas);
        GFL_HEAP_Free(ci->chrRes);
        GFL_HEAP_Free(ci->plttRes);
        FLD3D_CI_DrawMessageTexture(playerStatus, ci, d_021DE43C, d_021DE448, 0, icon->secondNameCentered);
        (*state)++;
        break;
    case 4:
        ci->status.trans.x = 0;
        ci->status.trans.y = 0;
        ci->status.trans.z = 0xFFD44000;
        G3D_SYSTEM_SetSwapBuffersMode(0, 0);
        return 1;
    }
    return 0;
}

/* Byte offset of a texture's data inside the model resource. */
int FLD3D_CI_GetTexDataOffset(Fld3dCiTexBlock *texBlock, Fld3dCiTexDictEntry *entry)
{
    return (((entry->dataWord << 16) >> 13) + ((texBlock->texDataWord << 16) >> 13));
}

/* Byte offset of a palette's data inside the model resource. */
int FLD3D_CI_GetPlttDataOffset(Fld3dCiTexBlock *texBlock, Fld3dCiPlttDictEntry *entry)
{
    return ((entry->dataWord << 3) + ((texBlock->plttDataWord << 16) >> 13));
}

/*
 * Looks a texture up by name and returns its data offset (EXACT*: pad).
 */
int FLD3D_CI_FindTexture(Fld3dCiTexBlock *texBlock, const char *name)
{
    Fld3dCiNameKey key;
    void *entry;

    FLD3D_CI_CopyName((char *)&key, name);
    if (texBlock != 0)
        entry = NNS_G3dGetResDataByName((const NNSG3dResDict *)((u8 *)texBlock + 0x3C), (NNSG3dResName *)&key);
    else
        entry = 0;
    if (entry == 0)
        return 0;
    return FLD3D_CI_GetTexDataOffset(texBlock, entry);
}

/* Looks a palette up by name and returns its data offset. */
int FLD3D_CI_FindPalette(Fld3dCiTexBlock *texBlock, const char *name)
{
    Fld3dCiNameKey key;
    void *entry;

    FLD3D_CI_CopyName((char *)&key, name);
    if (texBlock != 0 && texBlock->plttDictOffset != 0)
        entry = NNS_G3dGetResDataByName((const NNSG3dResDict *)((u8 *)texBlock + texBlock->plttDictOffset), (NNSG3dResName *)&key);
    else
        entry = 0;
    if (entry == 0)
        return 0;
    return FLD3D_CI_GetPlttDataOffset(texBlock, entry);
}

/*
 * Copies a name into a zeroed 16-byte request block (EXACT*: pad).
 */
void FLD3D_CI_CopyName(char *dst, const char *src)
{
    int length = STD_GetStringLength(src);
    u8 i;
    for (i = 0; i < 4; i++)
        ((u32 *)dst)[i] = 0;
    for (i = 0; i < length; i++)
        dst[i] = src[i];
}

/* Renders a message into the name texture and its palette. */
void FLD3D_CI_DrawMessageTexture(void *playerStatus, Fld3dCi *ci, const char *texName, const char *plttName, u32 msgId, u32 centered)
{
    u8 texKey[0x14];
    void *wordSet;
    void *font;
    void *rawMsg;
    void *msgBank;
    void *texBlock;
    u16 heapId;
    void *text;
    int xOffset;
    u16 *palette;

    texBlock = (void *)G3D_UTIL_GetResource(ci->gfxUnits, 0);
    heapId = ci->heapId;
    msgBank = MSGDATA_CreateFromArchive(0, 2, 0xb0, heapId);
    if (msgId == 0) {
        wordSet = WORDSET_CreateDefault((u16)((heapId & 0x7FFF) | 0x8000));
        text = STRBUF_Create(8, (heapId & 0x7FFF) | 0x8000);
        rawMsg = MSGDATA_AllocString(msgBank, msgId);
        WORDSET_SetSlotMyStatus(wordSet, 0, playerStatus);
        WORDSET_CopyTaggedText(wordSet, text, rawMsg);
        STRBUF_Delete(rawMsg);
        WORDSET_Delete(wordSet);
    } else {
        rawMsg = MSGDATA_AllocString(msgBank, msgId);
        text = STRBUF_Create(0x10, (heapId & 0x7FFF) | 0x8000);
        WORDSET_AppendUnpackedString(text, rawMsg);
        STRBUF_Delete(rawMsg);
    }
    xOffset = 0;
    if (centered != 0) {
        font = GF_FONT_Create(0x17, 0, 0, 0, heapId);
        xOffset = PRINTSYS_MeasureWidestLine(text, font, 0);
        GF_FONT_Delete(font);
        xOffset = 0x3c - xOffset;
        if (xOffset < 0)
            xOffset = 0;
    }
    ci->plttRes = ARC_UTIL_LoadPaletteBlockFromArchive(0x17, 5, (&ci->pltt), heapId);
    palette = ci->pltt->raw;
    palette[1] = 0x7FFF;
    palette[2] = 0;
    TEXT_TEXTURE_LoadTexPlttByName(texBlock, (char *)texName, palette, (char *)plttName, (uptr)text, xOffset, 0, 0x440, heapId, (struct TexKey *)texKey);
    GFL_HEAP_Free(ci->plttRes);
    GFL_HEAP_Free(text);
    MSGDATA_Delete(msgBank);
}

/*
 * Starts the name cut-in 0x11 with its name message id (EXACT*: pad).
 */
void *FLD3D_CI_StartMessageSequence(void *gameSystem, Fld3dCi *ci, u32 nameMsgId)
{
    void *event = FLD3D_CI_StartSequence(gameSystem, ci, 0x11);
    if (event == 0)
        return 0;
    ci->arg.icon.nameMsgId = nameMsgId;
    return event;
}

/*
 * Halves every RGB555 colour in LCDC VRAM bank 0x06860000 (0xC000 halfwords)
 * to darken the captured screen. The parameter is unused (the caller passes
 * one). The channels are extracted into u8 locals (b, g, r, a), then halved
 * as separate `x = x >> 1` statements in b, g, r order; that keeps every
 * channel in its own register so the scheduler interleaves the four chains,
 * and the halving order picks which truncation is scheduled early. Casts
 * inline in the OR expression serialise the chains instead.
 */
void FLD3D_CI_DarkenCapturedScreen(u32 unused)
{
    int oldBankState = GX_ResetBankForBG();
    u16 *pixel = (u16 *)HW_LCDC_VRAM_D;
    int i;
    for (i = 0; i < 0xC000; i++) {
        u16 color = *pixel;
        u8 b = (color >> 10) & 0x1F;
        u8 g = (color >> 5) & 0x1F;
        u8 r = color & 0x1F;
        u8 a = (color >> 15) & 1;
        b = b >> 1;
        g = g >> 1;
        r = r >> 1;
        *pixel = (a << 15) | (b << 10) | (g << 5) | r;
        pixel++;
    }
    GX_SetBankForBG(oldBankState);
}

/*
 * Clears a 0x40-byte event work and stores its owner (EXACT*: pad).
 */
void FLD3D_CI_InitEventWork(Fld3dCi *ci, Fld3dCiEventWork *work)
{
    MI_CpuFill8(work, 0, 0x40);
    work->ci = ci;
    work->hideFieldObjects = 0;
    work->fadeVariant = 0;
}

/*
 * Plays the next sound effect of the current cue table when its frame is
 * reached.
 */
void FLD3D_CI_PlayCueSound(Fld3dCi *ci)
{
    Fld3dCiCue *cues = d_021DA720[ci->sequenceId];
    if (cues[ci->cueIndex].soundId != -1 && ci->frame == cues[ci->cueIndex].frame) {
        GFL_USE_PlaySeDefaultVolume(cues[ci->cueIndex].soundId);
        (ci->cueIndex)++;
    }
}

/*
 * VBlank task: applies the saved display setup, ends itself, flags completion.
 */
void FLD3D_CI_DisplayRestoreTask(struct TcbTask *task, void *arg)
{
    u32 *done = arg;
    DispConfig setup;
    BG_SYS_SetPlaneVisible(0, 1);
    setup = d_021DA700;
    BG_SYS_SetGraphicsMode(&setup);
    TCB_DeleteTask(task);
    if (done != 0)
        *done = 1;
}
