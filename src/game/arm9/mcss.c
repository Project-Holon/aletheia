/*
 * file:     mcss.c
 * unit:     yes
 * function: MCSS_Init, MCSS_Exit, MCSS_Main, MCSS_OpenHandle, MCSS_CloseHandle, MCSS_SetTaskSystem, MCSS_SetLoadHook, MCSS_ReloadResource, MCSS_Draw, MCSS_DrawShadow, MCSS_Add, MCSS_Del, MCSS_SetOrthoMode, MCSS_ResetOrthoMode, MCSS_SetOrthoBillboardFlag, MCSS_ResetOrthoBillboardFlag, MCSS_GetPosition, MCSS_SetPosition, MCSS_GetOfsPosition, MCSS_SetOfsPosition, MCSS_GetScale, MCSS_SetScale, MCSS_GetShadowScale, MCSS_SetShadowScale, MCSS_GetRotate, MCSS_SetRotate, MCSS_SetOfsScale, MCSS_GetDrawScale, MCSS_SetDrawScale, MCSS_SetShadowRotateX, MCSS_SetShadowRotateZ, MCSS_SetShadowOffset, MCSS_SetMepachiFlag, MCSS_ResetMepachiFlag, MCSS_FlipMepachiFlag, MCSS_GetAnmStopFlag, MCSS_SetAnmStopFlag, MCSS_SetAnmStopFlagAlways, MCSS_ResetAnmStopFlag, MCSS_ResetAnmStopFlagAlways, MCSS_GetVanishFlag, MCSS_SetVanishFlag, MCSS_ResetVanishFlag, MCSS_FlipVanishFlag, MCSS_GetAnimCtrl, MCSS_GetAnimSeqNum, MCSS_GetStopCellNum, MCSS_GetStopCellIndex, MCSS_GetSizeX, MCSS_GetSizeY, MCSS_GetOfsX, MCSS_GetOfsY, MCSS_GetStopCellFlags, MCSS_SetAnimCallback, MCSS_SetCellCallback, MCSS_SetPaletteFade, MCSS_GetAlpha, MCSS_SetAlpha, MCSS_SetShadowAlpha, MCSS_SetShadowVanishFlag, MCSS_CheckPaletteFade, MCSS_SetTextureTransAdrs, MCSS_SetPaletteTransAdrs, MCSS_SetAnimeIndex, MCSS_GetMosaic, MCSS_SetMosaic, MCSS_SetGlobalScale, MCSS_SetAnimeSpeed, MCSS_GetAnimSeqNumEx, MCSS_CreatePaletteTransTask, MCSS_CreatePaletteCopyTask, MCSS_RestartAnime, MCSS_RequestAnimeStopAtStart, MCSS_SetWorkFlag, MCSS_SetSysParam, MCSS_SetSysFlag, MCSS_LoadResource, MCSS_LoadResourceShared, MCSS_TransTextureTask, MCSS_TransPaletteTask, MCSS_InitAnimCtrl, MCSS_InitEdgeColor, MCSS_UpdatePaletteFade, MCSS_FreeResource, MCSS_DeleteTextureTask, MCSS_DeletePaletteTask, MCSS_ApplyMosaic, MCSS_MulVecMtx44, MCSS_TOOL_MakeAddWorkFromPP, MCSS_TOOL_MakeAddWorkFromPPP, MCSS_TOOL_MakeAddWorkFromParam, MCSS_TOOL_MakeAddWorkFromTrainer, MCSS_TOOL_AddPokeMcss, MCSS_TOOL_SetSpindaSpotHook, MCSS_TOOL_SpindaSpotHook, MCSS_TOOL_DrawSpindaSpots, MCSS_TOOL_SetAnimeStopCallback, MCSS_TOOL_AnimeStopCallback
 * address:  0x02014B08
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from mcss.c by tools/splitfile.py.
 *
 * symbols:
 *   GFL_HEAP_Free   0x020307B0  arm
 *   ARC_TOOL_LoadMember       0x02048F60  arm
 *   GFL_HEAP_Alloc     0x02030734  arm
 *   NNSi_G2dInitVramHandleEx     0x020637D4  arm
 *   ARC_UTIL_LoadPaletteBlockFromArchive     0x02049F34  arm
 *   GFL_USE_AddMainTask     0x020056A0  thumb
 *   sFileMcss  0x020A72CC  data
 *   MCSS_CloseHandle   0x02014CD4  thumb
 *   TCBL_GetTaskUserData   0x02030EE8  arm
 *   GFL_HEAP_Free   0x020307B0  arm
 *   TCB_DeleteTask   0x02030EAC  arm
 *   MCSS_Del   0x02015BA4  thumb
 *   MCSS_RestartAnime  0x02016374  thumb
 *   ARC_TOOL_CreateHandle         0x020490F4  arm
 *   ENV_SetResourceSet_2  0x02049238  arm
 *   MCSS_FreeResource  0x02016BA0  thumb
 *   NNS_G3dGeFlushBuffer    0x0206DB80  arm
 *   MTX_Inverse43    0x0207B67C  arm
 *   MI_Copy36B       0x02082B60  arm
 *   MTX_Copy33To44_  0x0207ADE8  arm
 *   MTX_Copy43To44_  0x0207B5C0  arm
 *   MTX_Concat44     0x0207BE14  arm
 *   G3i_LookAt_      0x0207D7C4  arm
 *   G3_RotX          0x0207D810  arm
 *   G3_RotZ          0x0207D888  arm
 *   G3_MultMtx44     0x0207D8FC  arm
 *   FX_Div     0x0207C768  arm
 *   g_renderStateDrawParams       0x02148B98  data
 *   SCREENTEX_ProjectionMatrix       0x02148B54  data
 *   SCREENTEX_CameraPositionOut       0x02148D8C  data
 *   SCREENTEX_CameraTargetOut       0x02148D98  data
 *   SCREENTEX_CameraUpOut       0x02148DA4  data
 *   FX_SinCosTable_  0x020A1B38  data
 *   d_0209E090       0x0209E090  data
 *   d_0209E09C       0x0209E09C  data
 *   G3i_FrustumW_    0x0207D760  arm
 *   MCSS_DeleteTextureTask  0x02016C0C  thumb
 *   NNS_G2dSetCellAnimationParam  0x02063000  arm
 *   NNSi_G2dMCEnumAnimBank  0x02064D70  arm
 *   NNS_G2dGetAnimSequenceByIdx  0x020627D8  arm
 *   NNS_G2dSetAnimSequenceToMCAnimation  0x0206469C  arm
 *   PALANM_BlendColors  0x02021F64  thumb
 *   TCB_AddTask  0x02030DA8  arm
 *   MIi_CpuCopy16  0x02082A60  arm
 *   NNS_G2dRestartMCAnimation  0x02064CBC  arm
 *   NNSi_G2dLoadVramResourceSub  0x02063A54  arm
 *   NNSi_G2dLoadVramResourceBySel  0x02063E54  arm
 *   TCB_DeleteTask   0x02030EAC  arm
 *   _s32_to_double  0x0209B750  arm
 *   pow   0x0209AB80  arm
 *   _d2s            0x0209C508  arm
 *   POKEGRA_GetArcID  0x0202D060  thumb
 *   POKEGRA_GetCbrArcIndex  0x0202D09C  thumb
 *   POKEGRA_GetPalArcIndex  0x0202D0D4  thumb
 *   POKEGRA_GetCelArcIndex  0x0202D110  thumb
 *   POKEGRA_GetAnmArcIndex  0x0202D144  thumb
 *   POKEGRA_GetMCelArcIndex  0x0202D178  thumb
 *   POKEGRA_GetMAnmArcIndex  0x0202D1AC  thumb
 *   POKEGRA_GetNcecArcIndex  0x0202D1E0  thumb
 *   POKEGRA_GetTrainerArcID  0x0202D5CC  thumb
 *   POKEGRA_GetTrainerCbrArcIndex  0x0202D5F8  thumb
 *   POKEGRA_GetTrainerPalArcIndex  0x0202D61C  thumb
 *   POKEGRA_GetTrainerCelArcIndex  0x0202D640  thumb
 *   POKEGRA_GetTrainerAnmArcIndex  0x0202D664  thumb
 *   POKEGRA_GetTrainerMCelArcIndex  0x0202D688  thumb
 *   POKEGRA_GetTrainerMAnmArcIndex  0x0202D6AC  thumb
 *   POKEGRA_GetTrainerNcecArcIndex  0x0202D6D0  thumb
 *   sSpindaSpotCoords  0x020A72D4  data
 *   POKE_TOOL_IsBoxShiny  0x02017EB4  thumb
 *   POKE_TOOL_GetBoxParam  0x020185F4  thumb
 *   ARC_UTIL_LoadCellBankFromArchive  0x02049FBC  arm
 *   ARC_UTIL_LoadCellBankFromHandle  0x02049FFC  arm
 *   ARC_UTIL_LoadMultiCellBankFromArchive  0x0204A03C  arm
 *   ARC_UTIL_LoadMultiCellBankFromHandle  0x0204A07C  arm
 *   ARC_UTIL_LoadAnimBankFromArchive  0x0204A0BC  arm
 *   ARC_UTIL_LoadAnimBankFromHandle  0x0204A0FC  arm
 *   ARC_UTIL_LoadMultiAnimBankFromArchive  0x0204A13C  arm
 *   ARC_UTIL_LoadMultiAnimBankFromHandle  0x0204A17C  arm
 *   ARC_TOOL_LoadHandleMember  0x02049250  arm
 *   NNS_G2dInitMCAnimation  0x02064754  arm
 *   NNS_G2dGetMCWorkAreaSize  0x020648B4  arm
 *   NNS_G2dTickMCAnimation  0x020649D4  arm
 *   NNSi_G2dInitVramHandle  0x02063790  arm
 *   POKE_TOOL_GetPartyValue  0x02017E1C  thumb
 *   POKE_TOOL_GetBoxValue  0x02017E88  thumb
 *   ARC_UTIL_LoadBgCharDataFromArchive  0x02049DB4  arm
 *   ARC_UTIL_LoadBgCharDataFromHandle  0x02049DF4  arm
 *   ARC_UTIL_LoadPaletteBlockFromHandle  0x02049F78  arm
 */
#include "field_status_shared_types.h"
#include "zone_light_shared_types.h"

#define REG_MTX_MODE     (*(vu32 *)0x04000440)

#define REG_MTX_PUSH     (*(vu32 *)0x04000444)

#define REG_MTX_POP      (*(vu32 *)0x04000448)

#define REG_MTX_STORE    (*(vu32 *)0x0400044C)

#define REG_MTX_IDENTITY (*(vu32 *)0x04000454)

#define REG_MTX_SCALE    (*(vu32 *)0x0400046C)

#define REG_MTX_TRANS    (*(vu32 *)0x04000470)

#define REG_TEXIMAGE_PARAM (*(vu32 *)0x040004A8)

#define FX_F32_TO_FX32(x) ((fx32)(((x) > 0) ? \
                                  ((x) * (1 << 12) + 0.5f) : \
                                  ((x) * (1 << 12) - 0.5f)))

#define REG_MTX_RESTORE  (*(vu32 *)0x04000450)

#define REG_TEXCOORD     (*(vu32 *)0x04000488)

#define REG_VTX_16       (*(vu32 *)0x0400048C)

#define REG_POLYGON_ATTR (*(vu32 *)0x040004A4)

#define REG_TEXPLTT_BASE (*(vu32 *)0x040004AC)

#define REG_BEGIN_VTXS   (*(vu32 *)0x04000500)

#define REG_END_VTXS     (*(vu32 *)0x04000504)

typedef signed char   s8;

typedef signed long long s64;

typedef s32 fx32;

typedef s64 fx64;

typedef volatile u32 vu32;

typedef struct { fx32 x, y, z; } VecFx32;

typedef struct { fx32 m[4][3]; } MtxFx43;

typedef struct { fx32 m[3][3]; } MtxFx33;

typedef struct { fx32 m[4][4]; } MtxFx44;

typedef enum { GX_TEXFMT_NONE = 0, GX_TEXFMT_PLTT4 = 2 } GXTexFmt;

typedef enum { GX_TEXGEN_NONE = 0, GX_TEXGEN_TEXCOORD = 1 } GXTexGen;

typedef enum { GX_TEXSIZE_S8 = 0 } GXTexSizeS;

typedef enum { GX_TEXSIZE_T8 = 0 } GXTexSizeT;

typedef enum { GX_TEXREPEAT_NONE = 0, GX_TEXREPEAT_ST = 3 } GXTexRepeat;

typedef enum { GX_TEXFLIP_NONE = 0, GX_TEXFLIP_ST = 3 } GXTexFlip;

typedef enum { GX_TEXPLTTCOLOR0_USE = 0, GX_TEXPLTTCOLOR0_TRNS = 1 } GXTexPlttColor0;

struct McssSys;

struct McssWork;

struct McssTransTask;

struct AnimBank;

/*
 * What to load for one sprite: the archive and the member ids of its
 * resources.  Built by the MCSS_TOOL_MakeAddWork functions, stored in the
 * work at +0x150 so the resources can be reloaded.  heapMode 1 puts the
 * resources into the 0x8000 heap bank.
 */
typedef struct McssAddWork {
    u32 arcId;                          /* 0x00 */
    u32 textureMember;                  /* 0x04 */
    u32 paletteMember;                  /* 0x08 */
    u32 cellMember;                     /* 0x0C */
    u32 cellAnimMember;                 /* 0x10 */
    u32 multiCellMember;                /* 0x14 */
    u32 multiCellAnimMember;            /* 0x18 */
    u32 cellHeaderMember;               /* 0x1C */
    u32 heapMode;                       /* 0x20 */
} McssAddWork;

/* Called after a sprite's resources are loaded; returns 1 to unhook itself. */
typedef u32 (*McssLoadHook)(const McssAddWork *addWork, struct McssTransTask *task, u32 hookWork);

/* One pose of a sprite part: the kind of the animation decides which fields the data holds. */
typedef struct McssPose {
    u16  index;                         /* cell frame or cell index */
    u16  rot;
    fx32 sx;
    fx32 sy;
    s16  ofsX;
    s16  ofsY;
} McssPose;

/* Pose data of kind 2: index and offset only. */
typedef struct McssPoseOfs {
    u16 index;
    u16 pad;
    s16 ofsX;
    s16 ofsY;
} McssPoseOfs;

typedef struct McssPoseFrame {
    void *content;
    u16   duration;
    u16   pad;
} McssPoseFrame;

typedef struct McssPoseSeq {
    u16 numFrames;
    u16 loopStart;
    u32 kind;                           /* 0: index, 1: full pose, 2: index and offset */
} McssPoseSeq;

/* Animation playback state, 0x34 bytes (McssWork +0x34 and the start of each node). */
typedef struct McssAnimCtrl {
    McssPoseFrame *cur;
    u8             state[0x1C - 0x04];
    McssPoseSeq   *seq;
    u8             tail[0x34 - 0x20];
} McssAnimCtrl;

/* One part of a multi cell sprite; the cell animation owns an array of them. */
typedef struct McssCellNode {
    McssAnimCtrl ctrl;
    u8           tail[0x5C - 0x34];
} McssCellNode;

typedef struct McssAnimCell {
    s16 cellId;
    s16 ofsX;
    s16 ofsY;
    u16 nodeInfo;                       /* high byte: index into the node array */
} McssAnimCell;

typedef struct McssCellFrame {
    u16           count;
    u16           pad;
    McssAnimCell *cells;
} McssCellFrame;

typedef struct McssCellAnim {
    u32            numFrames;
    McssCellFrame *frames;
} McssCellAnim;

/* The state of the cell animation at McssWork +0x68, 0x30 bytes. */
typedef struct McssCellCtrl {
    u8             head[0x0C];
    McssCellNode  *nodes;               /* 0x0C */
    McssCellAnim  *anim;                /* 0x10 */
    u8             tail[0x30 - 0x14];
} McssCellCtrl;

/* One textured rectangle: position, size and texture origin, all in fx32. */
typedef struct McssQuad {
    fx32 x, y, w, h, s, t;
} McssQuad;

/* One cell record: the body quad and the eye (mepachi) quad. */
typedef struct McssCellRec {
    McssQuad body;
    McssQuad eye;
} McssCellRec;

/* The header the cell data starts with (McssWork +0x2C). */
typedef struct McssCellHeader {
    u32 cellCount;
    u16 sizeX;
    u16 sizeY;
    s16 ofsX;
    s16 ofsY;
    McssCellRec cells[1];
} McssCellHeader;

/* Texture image proxy: VRAM addresses (3D, main, sub; -1 is unset) and the texture parameters. */
typedef struct McssTexImage {
    u32 vramAddr[3];                    /* 0x00 */
    u32 sizeS;                          /* 0x0C */
    u32 sizeT;                          /* 0x10 */
    u32 fmt;                            /* 0x14 */
    u32 byteSize;                       /* 0x18 */
    u32 pltt0;                          /* 0x1C */
} McssTexImage;

/* Palette image proxy, 0x14 bytes: format, size and the three VRAM addresses. */
typedef struct McssPlttProxy {
    s32 fmt;                            /* 0x00 */
    u32 byteSize;                       /* 0x04 */
    u32 vramAddr[3];                    /* 0x08 */
} McssPlttProxy;

/* A loaded palette. */
typedef struct McssPlttData {
    u32   fmt;                          /* 0x00 */
    u32   extended;                     /* 0x04 */
    u32   byteSize;                     /* 0x08 */
    void *data;                         /* 0x0C */
} McssPlttData;

/* A loaded texture; only the raw pixel pointer is read here. */
typedef struct McssTexData {
    u8  header[0x14];
    u8 *rawData;                        /* 0x14 */
} McssTexData;

/*
 * Work block of a texture or palette transfer task, 0x2C bytes.  Without a
 * task system the task only runs while the scanline is in 0xC0..0xC8.
 */
typedef struct McssTransTask {
    McssTexData   *texData;             /* 0x00 */
    McssPlttData  *plttData;            /* 0x04 */
    McssTexImage  *texImageOut;         /* 0x08 */
    McssPlttProxy *plttProxyOut;        /* 0x0C */
    void          *texBuf;              /* 0x10 */
    void          *plttBuf;             /* 0x14 */
    u32            texDest;             /* 0x18 */
    u32            plttDest;            /* 0x1C */
    struct McssSys *sys;                /* 0x20 */
    struct McssWork *work;              /* 0x24 */
    u32            hasTaskSys;          /* 0x28 */
} McssTransTask;

/*
 * The MCSS system: one per scene, owns the work slots and the shared
 * shadow palette.  Size 0x4C (MCSS_Init allocates it).
 */
typedef struct McssSys {
    void *arcHandle;                    /* 0x00 */
    u32 arcId;                          /* 0x04 */
    void *taskSys;                      /* 0x08 */
    void *shadowPlttTask;               /* 0x0C */
    s32 maxCount;                       /* 0x10 */
    struct McssWork **works;            /* 0x14 */
    McssPlttProxy shadowPltt;           /* 0x18 */
    union {                             /* 0x2C */
        u32 raw;
        struct {
            u32 orthoMode : 1;
            u32 nearDepthRange : 1;     /* far plane 512 and depth step 0x100 */
        } bits;
    } flags;
    u32 texTransAdrs;                   /* 0x30 */
    u32 plttTransAdrs;                  /* 0x34 */
    McssLoadHook loadHook;              /* 0x38 */
    u32 loadHookWork;                   /* 0x3C */
    u32 heapId;                         /* 0x40 */
    fx32 globalScale;                   /* 0x44 */
    s32 depthStep;                      /* 0x48 */
} McssSys;

/* The flag word at McssWork +0x140. */
typedef union McssFlags {
    u32 raw;
    struct {
        u32 alpha : 8;                  /* 0x1F = opaque */
        u32 mepachiFlag : 1;
        u32 anmStopFlag : 2;            /* bit 0 stop, bit 1 stop always */
        u32 vanishFlag : 1;
        u32 paletteFadeFlag : 1;
        u32 loaded : 1;
        u32 shadowAlpha : 9;
        u32 shadowVanishFlag : 1;
        u32 mosaic : 4;
        u32 plttCurrentValid : 1;       /* plttCurrent holds the last blended palette */
        u32 orthoBillboardFlag : 1;
        u32 mepachiDrawLast : 1;
        u32 shadowForceDraw : 1;
    } bits;
} McssFlags;

typedef union McssRequestFlags {
    u32 raw;
    struct {
        u32 stopAtStart : 1;
    } bits;
} McssRequestFlags;

/* One MCSS object (a multi-cell sprite).  Size 0x188. */
typedef struct McssWork {
    void *textureTask;                  /* 0x000 */
    void *fadeTask;                     /* 0x004 */
    void *paletteTask;                  /* 0x008 */
    void *cellFile;                     /* 0x00C */
    void *cellBank;                     /* 0x010 */
    void *multiCellFile;                /* 0x014 */
    void *multiCellBank;                /* 0x018 */
    void *cellAnimFile;                 /* 0x01C */
    void *cellAnimBank;                 /* 0x020 */
    void *multiCellAnimFile;            /* 0x024 */
    struct AnimBank *multiCellAnimBank; /* 0x028 */
    McssCellHeader *cellHeader;         /* 0x02C */
    u8 *stopCellTable;                  /* 0x030 */
    McssAnimCtrl animCtrl;              /* 0x034 */
    McssCellCtrl cellCtrl;              /* 0x068 */
    void *animWork;                     /* 0x098 */
    McssTexImage texImage;              /* 0x09C */
    u32 texImageExtra;                  /* 0x0BC */
    McssPlttProxy plttProxy;            /* 0x0C0 */
    void *plttOriginal;                 /* 0x0D4 */
    void *plttCurrent;                  /* 0x0D8 */
    u32 plttByteSize;                   /* 0x0DC */
    VecFx32 position;                   /* 0x0E0 */
    VecFx32 scale;                      /* 0x0EC */
    VecFx32 rotate;                     /* 0x0F8 */
    VecFx32 ofsScale;                   /* 0x104 */
    VecFx32 drawScale;                  /* 0x110 */
    VecFx32 ofsPosition;                /* 0x11C */
    VecFx32 shadowScale;                /* 0x128 */
    s8 fadeStart;                       /* 0x134 */
    s8 fadeEnd;                         /* 0x135 */
    s8 fadeWait;                        /* 0x136 */
    s8 fadeWaitSet;                     /* 0x137 */
    s32 fadeStep;                       /* 0x138 */
    u32 fadeColor;                      /* 0x13C */
    McssFlags flags;                    /* 0x140 */
    McssRequestFlags requestFlags;      /* 0x144 bit 0: stop the anime at its start */
    u32 index;                          /* 0x148 */
    u32 heapId;                         /* 0x14C */
    McssAddWork addWork;                /* 0x150 */
    fx32 animeSpeed;                    /* 0x174 */
    u16 shadowRotX;                     /* 0x178 */
    u16 shadowRotZ;                     /* 0x17A */
    VecFx32 shadowOffset;               /* 0x17C */
} McssWork;

extern u32 GFL_HEAP_Free(void *p);

extern void *ARC_TOOL_LoadMember(u32 archive, u32 member, u32 heap);

extern void *GFL_HEAP_Alloc(u32 heapId, u32 size, int clear, const char *site, u16 tag);

extern void NNSi_G2dInitVramHandleEx(u32 *proxy);

extern void *ARC_UTIL_LoadPaletteBlockFromArchive(u32 arcId, u32 member, McssPlttData **out, u32 heap);

extern void *GFL_USE_AddMainTask(void *fn, void *work, u32 priority);

extern void MCSS_CloseHandle(McssSys *sys);

extern void *TCBL_GetTaskUserData(void *task);

extern u32 GFL_HEAP_Free(void *p);

extern void TCB_DeleteTask(void *task);

extern void MCSS_Del(McssSys *sys, McssWork *work);

extern void NNS_G2dTickMCAnimation(McssAnimCtrl *ctrl, fx32 speed);

extern void MCSS_RestartAnime(McssWork *work);

extern void *ARC_TOOL_CreateHandle(u32 id, u32 heap);

extern void  ENV_SetResourceSet_2(void *arcHandle);

extern void MCSS_FreeResource(McssWork *work);

extern void NNS_G3dGeFlushBuffer(void);

extern int  MTX_Inverse43(const MtxFx43 *src, MtxFx43 *dst);

extern void MI_Copy36B(const void *src, void *dst);

extern void MTX_Copy33To44_(const MtxFx33 *src, MtxFx44 *dst);

extern void MTX_Copy43To44_(const MtxFx43 *src, MtxFx44 *dst);

extern void MTX_Concat44(const MtxFx44 *a, const MtxFx44 *b, MtxFx44 *ab);

extern void G3i_LookAt_(const VecFx32 *camPos, const VecFx32 *camUp,
                        const VecFx32 *target, int draw, MtxFx43 *mtx);

extern void G3_RotX(fx32 s, fx32 c);

extern void G3_RotZ(fx32 s, fx32 c);

extern void G3_MultMtx44(const MtxFx44 *m);

extern u32 FX_Div(u32 value, u32 divisor);

extern void G3i_FrustumW_(fx32 t, fx32 b, fx32 l, fx32 r, fx32 n, fx32 f,
                          fx32 scaleW, int draw, void *mtx);

extern void MCSS_DeleteTextureTask(void *taskHandle);

extern void NNS_G2dSetCellAnimationParam(int anim, int type, int param, int func);

extern void NNSi_G2dMCEnumAnimBank(void *, void *, unsigned);

extern void *NNS_G2dGetAnimSequenceByIdx(struct AnimBank *bank, u32 idx);

extern void NNS_G2dSetAnimSequenceToMCAnimation(McssAnimCtrl *ctrl, void *seq);

extern void *TCB_AddTask(void *taskSys, void *callback, void *work, int priority);

extern void  PALANM_BlendColors(void *src, void *dst, u16 count, int fadeLevel, u16 fadeColor);

extern void  MIi_CpuCopy16(const void *src, void *dst, u32 size);

extern void NNS_G2dRestartMCAnimation(McssAnimCtrl *ctrl);

extern void *ARC_UTIL_LoadCellBankFromArchive(u32 arcId, u32 member, u32 flag, void *out, u32 heap);

extern void *ARC_UTIL_LoadMultiCellBankFromArchive(u32 arcId, u32 member, u32 flag, void *out, u32 heap);

extern void *ARC_UTIL_LoadAnimBankFromArchive(u32 arcId, u32 member, u32 flag, void *out, u32 heap);

extern void *ARC_UTIL_LoadMultiAnimBankFromArchive(u32 arcId, u32 member, u32 flag, void *out, u32 heap);

extern void *ARC_UTIL_LoadBgCharDataFromArchive(u32 arcId, u32 member, u32 flag, McssTransTask *out, u16 heap);

extern void NNSi_G2dInitVramHandle(u32 *vramAddr);

extern void *ARC_UTIL_LoadCellBankFromHandle(void *arcHandle, u32 member, u32 flag, void *out, u16 heap);

extern void *ARC_UTIL_LoadMultiCellBankFromHandle(void *arcHandle, u32 member, u32 flag, void *out, u16 heap);

extern void *ARC_UTIL_LoadAnimBankFromHandle(void *arcHandle, u32 member, u32 flag, void *out, u16 heap);

extern void *ARC_UTIL_LoadMultiAnimBankFromHandle(void *arcHandle, u32 member, u32 flag, void *out, u16 heap);

extern void *ARC_TOOL_LoadHandleMember(void *arcHandle, u32 member, u32 heap);

extern void *ARC_UTIL_LoadBgCharDataFromHandle(void *arcHandle, u32 member, u32 flag, McssTransTask *out, u16 heap);

extern void *ARC_UTIL_LoadPaletteBlockFromHandle(void *arcHandle, u32 member, McssPlttData **out, u32 heap);

extern void NNSi_G2dLoadVramResourceSub(McssTexData *tex, u32 dst, int mode, McssTexImage *out);

extern void NNSi_G2dLoadVramResourceBySel(McssPlttData *pltt, u32 dst, int mode, McssPlttProxy *out);

extern int NNS_G2dGetMCWorkAreaSize(void *multiCellBank, int kind);

extern void NNS_G2dInitMCAnimation(McssAnimCtrl *ctrl, void *animWork, void *cellAnimBank, void *cellBank, void *multiCellBank, int kind);

extern double _s32_to_double(s32 v);

extern double pow(double base, double exponent);

extern s32 _d2s(double d);

extern int POKEGRA_GetArcID(void);

extern s32 POKEGRA_GetCbrArcIndex(u32 arcId, u32 species, u32 form, u32 gender, u32 isShiny, u32 direction, u32 isEgg);

extern s32 POKEGRA_GetPalArcIndex(u32 arcId, u32 species, u32 form, u32 gender, u32 isShiny, u32 direction, u32 isEgg);

extern s32 POKEGRA_GetCelArcIndex(u32 arcId, u32 species, u32 form, u32 gender, u32 isShiny, u32 direction, u32 isEgg);

extern s32 POKEGRA_GetAnmArcIndex(u32 arcId, u32 species, u32 form, u32 gender, u32 isShiny, u32 direction, u32 isEgg);

extern s32 POKEGRA_GetMCelArcIndex(u32 arcId, u32 species, u32 form, u32 gender, u32 isShiny, u32 direction, u32 isEgg);

extern s32 POKEGRA_GetMAnmArcIndex(u32 arcId, u32 species, u32 form, u32 gender, u32 isShiny, u32 direction, u32 isEgg);

extern s32 POKEGRA_GetNcecArcIndex(u32 arcId, u32 species, u32 form, u32 gender, u32 isShiny, u32 direction, u32 isEgg);

extern u32 POKEGRA_GetTrainerArcID(u32 a);

extern u32 POKEGRA_GetTrainerCbrArcIndex(u32 id, u32 flags);

extern u32 POKEGRA_GetTrainerPalArcIndex(u32 id, u32 flags);

extern u32 POKEGRA_GetTrainerCelArcIndex(u32 id, u32 flags);

extern u32 POKEGRA_GetTrainerAnmArcIndex(u32 id, u32 flags);

extern u32 POKEGRA_GetTrainerMCelArcIndex(u32 id, u32 flags);

extern u32 POKEGRA_GetTrainerMAnmArcIndex(u32 id, u32 flags);

extern u32 POKEGRA_GetTrainerNcecArcIndex(u32 id, u32 flags);

McssSys *MCSS_Init(u32 maxCount, u32 heapId);

void MCSS_Exit(McssSys *sys);

void MCSS_Main(McssSys *sys);

void MCSS_OpenHandle(McssSys *sys, u32 arcId);

void MCSS_SetTaskSystem(McssSys *sys, void *taskSys);

void MCSS_SetLoadHook(McssSys *sys, McssLoadHook hook, u32 hookWork);

void MCSS_ReloadResource(McssSys *sys, McssWork *work, const McssAddWork *addWork);

void MCSS_Draw(McssSys *sys);

void MCSS_DrawShadow(McssSys *sys, McssWork *work, fx32 x, fx32 y, fx32 width, fx32 height, fx32 s, fx32 t, McssPose *pose, u16 *frameIndex, McssPlttProxy *shadowPltt, int cellId, int ortho, u32 *depth, u8 flip);

McssWork *MCSS_Add(McssSys *sys, fx32 x, fx32 y, fx32 z, const McssAddWork *addWork);

void MCSS_SetOrthoMode(McssSys *sys);

void MCSS_ResetOrthoMode(McssSys *sys);

void MCSS_SetOrthoBillboardFlag(McssWork *work);

void MCSS_ResetOrthoBillboardFlag(McssWork *work);

void MCSS_GetPosition(McssWork *work, u32 *out);

void MCSS_SetPosition(McssWork *work, u32 *src);

void MCSS_GetOfsPosition(McssWork *work, u32 *out);

void MCSS_SetOfsPosition(McssWork *work, u32 *src);

void MCSS_GetScale(McssWork *work, u32 *out);

void MCSS_SetScale(McssWork *work, u32 *src);

void MCSS_GetShadowScale(McssWork *work, u32 *out);

void MCSS_SetShadowScale(McssWork *work, u32 *src);

void MCSS_GetRotate(McssWork *work, u32 *out);

void MCSS_SetRotate(McssWork *work, u32 *src);

void MCSS_SetOfsScale(McssWork *work, u32 *src);

void MCSS_GetDrawScale(McssWork *work, u32 *out);

void MCSS_SetDrawScale(McssWork *work, u32 *src);

void MCSS_SetShadowRotateX(McssWork *work, u16 rotX);

void MCSS_SetShadowRotateZ(McssWork *work, u16 rotZ);

void MCSS_SetShadowOffset(McssWork *work, int *src);

void MCSS_SetMepachiFlag(McssWork *work);

void MCSS_ResetMepachiFlag(McssWork *work);

void MCSS_FlipMepachiFlag(McssWork *work);

int MCSS_GetAnmStopFlag(McssWork *work);

void MCSS_SetAnmStopFlag(McssWork *work);

void MCSS_SetAnmStopFlagAlways(McssWork *work);

void MCSS_ResetAnmStopFlag(McssWork *work);

void MCSS_ResetAnmStopFlagAlways(McssWork *work);

int MCSS_GetVanishFlag(McssWork *work);

void MCSS_SetVanishFlag(McssWork *work);

void MCSS_ResetVanishFlag(McssWork *work);

void MCSS_FlipVanishFlag(McssWork *work);

void *MCSS_GetAnimCtrl(McssWork *work);

u16 MCSS_GetAnimSeqNum(McssWork *work);

u8 MCSS_GetStopCellNum(McssWork *work);

u8 MCSS_GetStopCellIndex(McssWork *work, u8 i);

u16 MCSS_GetSizeX(McssWork *work);

u16 MCSS_GetSizeY(McssWork *work);

s16 MCSS_GetOfsX(McssWork *work);

s16 MCSS_GetOfsY(McssWork *work);

u8 MCSS_GetStopCellFlags(McssWork *work);

int MCSS_SetAnimCallback(McssWork *work, u32 callback, u32 callbackWork, u32 unusedArg);

void MCSS_SetCellCallback(McssWork *work, unsigned flags, void *callback);

void MCSS_SetPaletteFade(McssWork *work, u32 start, u32 end, s32 wait, u32 color);

u8 MCSS_GetAlpha(McssWork *work);

void MCSS_SetAlpha(McssWork *work, int alpha);

void MCSS_SetShadowAlpha(McssWork *work, int alpha);

void MCSS_SetShadowVanishFlag(McssWork *work, int flag);

int MCSS_CheckPaletteFade(McssWork *work);

void MCSS_SetTextureTransAdrs(McssSys *sys, u32 adrs);

void MCSS_SetPaletteTransAdrs(McssSys *sys, unsigned int adrs);

void MCSS_SetAnimeIndex(McssWork *work, u32 animeIndex);

u8 MCSS_GetMosaic(McssWork *work);

void MCSS_SetMosaic(McssSys *sys, McssWork *work, int mosaic);

void MCSS_SetGlobalScale(McssSys *sys, unsigned int scale);

void MCSS_SetAnimeSpeed(McssWork *work, int speed);

u16 MCSS_GetAnimSeqNumEx(McssWork *work);

void MCSS_CreatePaletteTransTask(McssSys *sys, McssWork *work, u16 fadeLevel, int fadeColor);

void MCSS_CreatePaletteCopyTask(McssSys *sys, McssWork *work);

void MCSS_RequestAnimeStopAtStart(McssWork *work);

void MCSS_SetWorkFlag(McssWork *work, int flag);

void MCSS_SetSysParam(McssSys *sys, int depthStep);

void MCSS_SetSysFlag(McssSys *sys, int flag);

void MCSS_LoadResource(McssSys *sys, u32 index, const McssAddWork *addWork);

void MCSS_LoadResourceShared(McssSys *sys, u32 index, const McssAddWork *addWork);

void MCSS_TransTextureTask(void *taskHandle, McssTransTask *task);

void MCSS_TransPaletteTask(void *taskHandle, McssTransTask *task);

void MCSS_InitAnimCtrl(McssWork *work, int kind);

void MCSS_InitEdgeColor(void);

void MCSS_UpdatePaletteFade(McssSys *sys, McssWork *work);

void MCSS_DeletePaletteTask(void *taskHandle);

void MCSS_ApplyMosaic(McssWork *work, McssTransTask *task);

void MCSS_MulVecMtx44(const VecFx32 *v, const MtxFx44 *mtx, VecFx32 *dst, s32 *w);

void MCSS_TOOL_MakeAddWorkFromPP(void *pp, McssAddWork *out, u32 direction);

void MCSS_TOOL_MakeAddWorkFromPPP(void *pokemon, McssAddWork *out, u32 direction);

void MCSS_TOOL_MakeAddWorkFromParam(u32 species, u32 form, u32 gender, u32 isShiny, u32 isEgg, McssAddWork *out, u32 direction);

void MCSS_TOOL_MakeAddWorkFromTrainer(void *trainerClass, McssAddWork *out, void *trainerGender);

McssWork *MCSS_TOOL_AddPokeMcss(McssSys *sys, void *pp, u32 direction, fx32 x, fx32 y, fx32 z);

void MCSS_TOOL_SetSpindaSpotHook(McssSys *sys, u32 personality);

u32 MCSS_TOOL_SpindaSpotHook(const McssAddWork *addWork, McssTransTask *task, u32 personality);

void MCSS_TOOL_DrawSpindaSpots(u8 *pixels, u32 personality);

int MCSS_TOOL_SetAnimeStopCallback(McssWork *work);

void MCSS_TOOL_AnimeStopCallback(McssWork *work);

u32 POKE_TOOL_GetPartyValue(void *p, u32 id, u32 v);

u32 POKE_TOOL_GetBoxValue(void *p, u32 id, u32 v);

u32 POKE_TOOL_IsBoxShiny(void *p);

void *POKE_TOOL_GetBoxParam(void *p);

extern const char sFileMcss[];

extern MtxFx43 g_renderStateDrawParams;

extern MtxFx44 SCREENTEX_ProjectionMatrix;

extern VecFx32 SCREENTEX_CameraPositionOut;

extern VecFx32 SCREENTEX_CameraTargetOut;

extern VecFx32 SCREENTEX_CameraUpOut;

extern s16 FX_SinCosTable_[];

extern const VecFx32 d_0209E090;

extern const VecFx32 d_0209E09C;

extern const u8 *sSpindaSpotCoords[4];

McssSys *MCSS_Init(u32 maxCount, u32 heapId)
{
    McssSys *sys;
    McssTransTask *task;
    u32 subHeapId;

    sys = GFL_HEAP_Alloc(heapId, 0x4c, 1, sFileMcss, 0x78);
    sys->maxCount = maxCount;
    sys->heapId = heapId;
    sys->globalScale = 0x1000;
    sys->works = GFL_HEAP_Alloc(heapId, maxCount * 4, 1, sFileMcss, 0x7f);
    sys->texTransAdrs = 9 << 14;
    sys->plttTransAdrs = 0x1000;
    NNSi_G2dInitVramHandleEx((u32 *)&sys->shadowPltt);
    subHeapId = (heapId & 0x7fff) | 0x8000;
    task = GFL_HEAP_Alloc((u32)((void *)(u16)subHeapId), 0x2c, 1, sFileMcss, 0x8e);
    task->sys = sys;
    task->plttProxyOut = &sys->shadowPltt;
    task->plttDest = 0x1100;
    task->plttBuf = ARC_UTIL_LoadPaletteBlockFromArchive(0xb, 0x58, &task->plttData, (u16)subHeapId);
    sys->shadowPlttTask = GFL_USE_AddMainTask((void *)MCSS_TransTextureTask, task, 0);
    return sys;
}

/*
 * Tear-down of a "list of arrays" record: close the open sub-object at +0xC
 * (three frees through the handle returned by TCBL_GetTaskUserData, then the handle
 * itself), then walk the +0x14 array of +0x10 entries and release each live
 * one through MCSS_Del, finally the array and the record itself.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/MCSS_Exit.c \
 *       --func MCSS_Exit --addr 0x02014BA8 --cc 1.1p1 --thumb
 */
void MCSS_Exit(McssSys *sys)
{
    int i;

    MCSS_CloseHandle(sys);
    if (sys->shadowPlttTask != 0) {
        McssTransTask *task = TCBL_GetTaskUserData(sys->shadowPlttTask);

        GFL_HEAP_Free(task->plttData->data);
        GFL_HEAP_Free(task->plttData);
        GFL_HEAP_Free(task);
        TCB_DeleteTask(sys->shadowPlttTask);
        sys->shadowPlttTask = 0;
    }
    for (i = 0; i < sys->maxCount; i++) {
        McssWork **works = sys->works;
        McssWork *work = works[i];

        if (work != 0) {
            MCSS_Del(sys, work);
        }
    }
    GFL_HEAP_Free(sys->works);
    GFL_HEAP_Free(sys);
}

/*
 * Closed in the second pass (2026-09-22) from the 7-byte near miss in
 * docs/notes/pkt_02014C08.c.txt.  That note, and the two full permuter
 * runs made on it today (tools/permuter.py --mode hill, 171 single
 * mutations; --mode anneal, 2000 compiles) could not move the residue by
 * a single byte, which is the tell the brief names: a residue nothing in
 * the body reaches lives in the DECLARATIONS.
 *
 * THE LEVER IS MCSS_RestartAnime's ARITY.  The original leaves the slot
 * pointer live in r0 through the third bit test:
 *
 *     02014C7C  ldr r0, [r5, #0x14]     ; the slot array
 *     02014C7E  ldr r1, [sp, #4]        ; the offset constant 0x144
 *     02014C80  ldr r0, [r0, r4]        ; the slot -- STAYS in r0
 *     02014C82  ldr r1, [r0, r1]        ; the flag word into r1
 *     ...
 *     02014C8C  bl  #0x2016374          ; called with r0 already set
 *
 * Declared `void MCSS_RestartAnime(void)` the compiler has no reason to keep
 * the slot in r0, puts the flag word there instead and the six
 * instructions at +0x0076..+0x0080 come out with r0 and r1 swapped, the
 * whole 7-byte residue.  Declared `MCSS_RestartAnime(char *w)` and CALLED
 * with the slot, the allocation the image shows is the only legal one and
 * every byte closes.  This confirms the prototype
 * docs/families/mcss.h already carried (`void MCSS_RestartAnime(struct
 * McssWork *work)`), which the note had not applied at the call site.
 *
 * The 0x020169E8 site resolves through sole-ref/code (and, since
 * src/matched/MCSS_UpdatePaletteFade.c was filed in the same pass, through
 * `matched` as well).
 *
 * Verified with:
 *   python3 tools/match.py one --src src/matched/MCSS_Main.c \
 *       --func MCSS_Main --addr 0x02014C08 --cc 1.1p1 --thumb
 */
void MCSS_Main(McssSys *sys)
{
    int i;

    for (i = 0; i < sys->maxCount; i++) {
        if (sys->works[i] == 0)
            continue;
        if (sys->works[i]->flags.bits.anmStopFlag == 0)
            NNS_G2dTickMCAnimation(&sys->works[i]->animCtrl, sys->works[i]->animeSpeed);
        if (sys->works[i]->flags.bits.paletteFadeFlag != 0)
            MCSS_UpdatePaletteFade(sys, sys->works[i]);
        if (sys->works[i]->requestFlags.bits.stopAtStart == 1) {
            MCSS_RestartAnime(sys->works[i]);
            NNS_G2dTickMCAnimation(&sys->works[i]->animCtrl, 0);
            sys->works[i]->requestFlags.raw &= ~1u;
        }
    }
}

/*
 * A whole translation unit, matched as one byte range.
 *
 * alias: an acquire/release pair on the same object. MCSS_OpenHandle only
 * acts the first time (its own field at +0 is the guard); it records the
 * argument at +4 and installs whatever ARC_TOOL_CreateHandle returns at +0.
 * MCSS_CloseHandle is the release: if +0 is set it tears it down and clears
 * both fields.
 *
 * ENV_SetResourceSet_2 is not the same call site as
 * src/matched/unit_02014444.c's ENV_SetResourceSet: `layout/symbols_sdk.txt`
 * recovers three separate addresses for that SDK name (0x020307B0,
 * 0x02049238, 0x0204B084), one per statically linked object that pulled the
 * small library routine in, and this file only ever reaches the second one.
 * The two extern declarations therefore differ (three registers forwarded
 * there, one used here), which is a property of each call site, not a
 * disagreement about the routine.
 *
 * The one detail that pinned the source: the field at +0x40 is read with a
 * plain `ldr` (word reach, +124) and truncated to u16 afterwards rather than
 * loaded with `ldrh` (reach +62) directly, which only happens when the field
 * itself is declared u32 and truncated at the call, matching
 * docs/idioms/thumb-immediate-reach-costs-an-adds.md's family of reach-driven
 * tells. Declaring it u16 outright produces an extra `adds` to reach the
 * offset and is 4 bytes wrong.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02014CB8.c \
 *       --addr 0x02014CB8 --thumb
 */
void MCSS_OpenHandle(McssSys *sys, u32 arcId)
{
    if (sys->arcHandle == 0) {
        sys->arcId = arcId;
        sys->arcHandle = ARC_TOOL_CreateHandle(arcId, (u16)sys->heapId);
    }
}

void MCSS_CloseHandle(McssSys *sys)
{
    if (sys->arcHandle != 0) {
        ENV_SetResourceSet_2(sys->arcHandle);
        sys->arcId = 0;
        sys->arcHandle = 0;
    }
}

void MCSS_SetTaskSystem(McssSys *sys, void *taskSys)
{
    sys->taskSys = taskSys;
}

/*
 * Two consecutive word stores through the object pointer - a plain field
 * pair setter with no prologue, so no label, attested by the pool word
 * 0x02014CF1.  The stores are in source order.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/MCSS_SetLoadHook.c \
 *       --func MCSS_SetLoadHook --addr 0x02014CF0 --cc 1.1p1 --thumb
 */
void MCSS_SetLoadHook(McssSys *sys, McssLoadHook hook, u32 hookWork)
{
    sys->loadHook = hook;
    sys->loadHookWork = hookWork;
}

/*
 * Prepares b (a validation call, MCSS_FreeResource), copies a 0x24-byte record
 * from c into b's field at +0x150 (the inlined ldm/stm loop plus one trailing
 * word is docs/idioms/aggregate-assignment-is-ldm-stm.md), then forwards a,
 * a pointer field of b at +0x148, and the original record pointer c to
 * MCSS_LoadResource.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/MCSS_ReloadResource.c \
 *       --func MCSS_ReloadResource --addr 0x02014CF8 --thumb --cc 1.1p1
 */
void MCSS_ReloadResource(McssSys *sys, McssWork *work, const McssAddWork *addWork)
{
    MCSS_FreeResource(work);
    work->addWork = *addWork;
    MCSS_LoadResource(sys, work->index, addWork);
}

static inline fx32 FX_MUL(fx32 v1, fx32 v2)
{
    return (fx32)(((fx64)v1 * v2 + 0x800LL) >> 12);
}

static inline void G3_Translate(fx32 x, fx32 y, fx32 z)
{
    REG_MTX_TRANS = (u32)x;
    REG_MTX_TRANS = (u32)y;
    REG_MTX_TRANS = (u32)z;
}

static inline void G3_Scale(fx32 x, fx32 y, fx32 z)
{
    REG_MTX_SCALE = (u32)x;
    REG_MTX_SCALE = (u32)y;
    REG_MTX_SCALE = (u32)z;
}

static inline void G3_LookAt(const VecFx32 *camPos, const VecFx32 *camUp,
                             const VecFx32 *target, MtxFx43 *mtx)
{
    G3i_LookAt_(camPos, camUp, target, 1, mtx);
}

static inline void G3_TexImageParam(GXTexFmt texFmt, GXTexGen texGen, GXTexSizeS s, GXTexSizeT t, GXTexRepeat repeat, GXTexFlip flip, GXTexPlttColor0 pltt0, u32 addr)
{
    REG_TEXIMAGE_PARAM = (u32)((addr >> 3) | (texFmt << 26) | (texGen << 30) | (s << 20) |
                                  (t << 23) | (repeat << 16) | (flip << 18) | (pltt0 << 29));
}

static inline void G3_StoreMtx(int num) { REG_MTX_STORE = (u32)num; }

/* MCSS_Draw is one function over 0x02014D2C..0x020155A0.  The listing's
 * labels at 0x02014D90 and 0x02015590 are not
 * function starts: they are the targets of two long-branch bl pairs inside
 * it (the shared epilogue and the outer loop head). */
/*
 * Verified with:
 *   python tools/match.py tu --src src/matched/MCSS_Draw.c \
 *       --addr 0x02014D2C --thumb
 *
 * The mcss.c frame walker, ONE function over 0x02014D2C..0x020155A0
 * (2164 bytes).  0x02014D90 and 0x02015590 are not function starts: they
 * are the targets of two bl instructions the compiler emits as long
 * branches (0x02014D74 to the shared epilogue, 0x0201558C back to the
 * outer loop head), both beyond Thumb b reach.  They are not listed on the
 * function line (alternate labels of MCSS_Draw, no start of their own).
 *
 * The lever that closed it (wave 15, from 43 bytes out): the texture
 * parameter write is the SDK inline G3_TexImageParam with the SDK's ENUM
 * parameter types (GXTexFmt, GXTexGen, GXTexSizeS/T, GXTexRepeat,
 * GXTexFlip, GXTexPlttColor0).  With int parameters the inline is 2168
 * bytes (540 out); with a hand-written or-chain 43 out (the STORE constant
 * 0x1e CSE'd with 0x1e << 15).  Enum parameters are materialised as
 * temporaries before the body, which is what keeps 0x1e rematerialised.
 * See docs/idioms/an-enum-type-keeps-values-out-of-constant-folding.md.
 * History: docs/notes/pkt_02014D2C_boundary.c.txt.
 */
void MCSS_Draw(McssSys *sys)
{
    McssPose pose;
    McssPose part;
    VecFx32 pos;
    MtxFx44 billboardMtx;
    MtxFx43 invView;
    MtxFx33 invViewRot;
    u32 depth;
    s32 projW;
    McssWork *work;
    McssAnimCtrl *animCtrl;
    int cellIdx;
    int sinIdx;
    u16 angle;
    fx32 transX, transY;
    fx32 scaleX, scaleY;
    McssTexImage *texImage;
    int workIdx;
    McssCellNode **nodes;
    u8 flip;
    fx32 cosRot;
    fx32 sinRot;
    int billboard;

    NNS_G3dGeFlushBuffer();
    REG_MTX_PUSH = 0;
    REG_MTX_MODE = 0;
    REG_MTX_STORE = 0;
    REG_MTX_MODE = 3;
    REG_MTX_IDENTITY = 0;
    REG_MTX_MODE = 2;
    MTX_Inverse43(&g_renderStateDrawParams, &invView);
    MI_Copy36B(&invView, &invViewRot);
    MTX_Copy33To44_(&invViewRot, &billboardMtx);

    workIdx = 0;
    if (sys->maxCount > 0) {
    do {
        if (sys->works[workIdx] == 0 || sys->works[workIdx]->flags.bits.vanishFlag != 0 || sys->works[workIdx]->flags.bits.loaded != 1) {
            continue;
        }
        billboard = 0;
        depth = 0;
        if (sys->flags.bits.orthoMode) {
            billboard = sys->works[workIdx]->flags.bits.orthoBillboardFlag;
        }
        work = sys->works[workIdx];
        texImage = &work->texImage;
        if (billboard == 0) {
            G3_LookAt(&SCREENTEX_CameraPositionOut, &SCREENTEX_CameraTargetOut, &SCREENTEX_CameraUpOut, 0);
        } else {
            VecFx32 camPos = { 0, 0, 0 };
            VecFx32 camUp = d_0209E090;
            VecFx32 camTgt = d_0209E09C;
            G3_LookAt(&camPos, &camUp, &camTgt, 0);
        }
        animCtrl = &work->animCtrl;
        nodes = &work->cellCtrl.nodes;
        switch ((u16)animCtrl->seq->kind) {
        case 0:
            pose.index = *(u16 *)animCtrl->cur->content;
            pose.rot = 0;
            pose.sx = 0x1000;
            pose.sy = 0x1000;
            pose.ofsX = 0;
            pose.ofsY = 0;
            break;
        case 1:
            pose = *(McssPose *)animCtrl->cur->content;
            break;
        case 2: {
            McssPoseOfs *poseOfs = (McssPoseOfs *)animCtrl->cur->content;
            pose.index = poseOfs->index;
            pose.rot = 0;
            pose.sx = 0x1000;
            pose.sy = 0x1000;
            pose.ofsX = poseOfs->ofsX;
            pose.ofsY = poseOfs->ofsY;
            break;
        }
        }
        pos.x = work->position.x + work->ofsPosition.x;
        pos.y = work->position.y + work->ofsPosition.y;
        pos.z = work->position.z + work->ofsPosition.z;
        if (billboard == 0) {
            transX = FX_MUL(pose.ofsX << 8, sys->globalScale);
            transY = FX_MUL(-pose.ofsY << 8, sys->globalScale);
        } else {
            MtxFx44 viewMtx;
            scaleX = FX_MUL(work->scale.x, work->shadowScale.x);
            scaleY = FX_MUL(work->scale.y, work->shadowScale.y);
            MTX_Copy43To44_(&g_renderStateDrawParams, &viewMtx);
            MTX_Concat44(&viewMtx, &SCREENTEX_ProjectionMatrix, &viewMtx);
            MCSS_MulVecMtx44(&pos, &viewMtx, &pos, &projW);
            pos.x = FX_MUL(FX_Div(pos.x, projW), 0x80000);
            pos.y = FX_MUL(FX_Div(pos.y, projW), 0x60000);
            pos.z = -pos.z;
            transX = FX_F32_TO_FX32(pose.ofsX);
            transY = FX_F32_TO_FX32(-pose.ofsY);
            transX = FX_MUL(transX, scaleX / 16);
            transY = FX_MUL(transY, scaleY / 16);
        }
        G3_Translate(pos.x, pos.y, pos.z);
        if (billboard == 0) {
            G3_MultMtx44(&billboardMtx);
        }
        angle = pose.rot + (work->rotate.z >> 12);
        G3_Translate(transX, transY, 0);
        flip = 0;
        sinIdx = angle >> 4;
        cosRot = FX_SinCosTable_[sinIdx * 2 + 1];
        sinRot = -FX_SinCosTable_[sinIdx * 2];
        G3_RotZ(sinRot, cosRot);
        G3_Scale(FX_MUL(FX_MUL(pose.sx, work->scale.x), work->shadowScale.x),
                 FX_MUL(FX_MUL(pose.sy, work->scale.y), work->shadowScale.y), 0x1000);
        if (work->scale.x < 0) {
            flip++;
        }
        G3_StoreMtx(29);
        G3_LookAt(&SCREENTEX_CameraPositionOut, &SCREENTEX_CameraTargetOut, &SCREENTEX_CameraUpOut, 0);
        G3_Translate(work->position.x + work->ofsPosition.x + work->shadowOffset.x, work->position.y + work->shadowOffset.y,
                     work->position.z + work->ofsPosition.z + work->shadowOffset.z);
        sinIdx = work->shadowRotX >> 4;
        G3_RotX(FX_SinCosTable_[sinIdx * 2], FX_SinCosTable_[sinIdx * 2 + 1]);
        G3_Translate(FX_MUL(FX_MUL(pose.ofsX << 8, sys->globalScale), work->ofsScale.x),
                     FX_MUL(FX_MUL(-pose.ofsY << 8, sys->globalScale), work->ofsScale.y), 0);
        sinIdx = work->shadowRotZ >> 4;
        G3_RotZ(-FX_SinCosTable_[sinIdx * 2], FX_SinCosTable_[sinIdx * 2 + 1]);
        G3_RotZ(sinRot, cosRot);
        G3_Scale(FX_MUL(FX_MUL(FX_MUL(pose.sx, work->ofsScale.x), work->drawScale.x), work->shadowScale.x),
                 FX_MUL(FX_MUL(FX_MUL(pose.sy, work->ofsScale.y), work->drawScale.y), work->shadowScale.y),
                 0x1000);
        G3_StoreMtx(30);
        MCSS_InitEdgeColor();
        G3_TexImageParam(texImage->fmt, GX_TEXGEN_TEXCOORD, texImage->sizeS, texImage->sizeT, GX_TEXREPEAT_ST, GX_TEXFLIP_ST, texImage->pltt0, texImage->vramAddr[0]);
        for (cellIdx = 0; cellIdx < work->cellCtrl.anim->frames[pose.index].count; cellIdx++) {
            McssCellNode *node;
            McssCellRec *rec;
            int cellId;
            if (work->flags.bits.alpha != 0x1f || work->flags.bits.mepachiDrawLast) {
                cellId = work->cellCtrl.anim->frames[pose.index].count - 1 - cellIdx;
            } else {
                cellId = cellIdx;
            }
            node = &(*nodes)[(work->cellCtrl.anim->frames[pose.index].cells[cellId].nodeInfo & 0xff00) >> 8];
            switch ((u16)node->ctrl.seq->kind) {
            case 0:
                part.index = *(u16 *)node->ctrl.cur->content;
                part.rot = 0;
                part.sx = 0x1000;
                part.sy = 0x1000;
                part.ofsX = 0;
                part.ofsY = 0;
                break;
            case 1:
                part = *(McssPose *)node->ctrl.cur->content;
                break;
            case 2: {
                McssPoseOfs *poseOfs = (McssPoseOfs *)node->ctrl.cur->content;
                part.index = poseOfs->index;
                part.rot = 0;
                part.sx = 0x1000;
                part.sy = 0x1000;
                part.ofsX = poseOfs->ofsX;
                part.ofsY = poseOfs->ofsY;
                break;
            }
            }
            rec = &work->cellHeader->cells[part.index];
            if (rec->eye.w != 0 && work->flags.bits.mepachiDrawLast == 0) {
                if (work->flags.bits.mepachiFlag) {
                    MCSS_DrawShadow(sys, work, rec->eye.x, rec->eye.y, rec->eye.w, rec->eye.h, rec->eye.s, rec->eye.t + rec->eye.h, &part, &pose.index, &sys->shadowPltt, cellId, billboard, &depth, flip);
                } else {
                    MCSS_DrawShadow(sys, work, rec->eye.x, rec->eye.y, rec->eye.w, rec->eye.h, rec->eye.s, rec->eye.t, &part, &pose.index, &sys->shadowPltt, cellId, billboard, &depth, flip);
                }
            }
            MCSS_DrawShadow(sys, work, rec->body.x, rec->body.y, rec->body.w, rec->body.h, rec->body.s, rec->body.t, &part, &pose.index, &sys->shadowPltt, cellId, billboard, &depth, flip);
            if (rec->eye.w != 0 && work->flags.bits.mepachiDrawLast == 1) {
                if (work->flags.bits.mepachiFlag) {
                    MCSS_DrawShadow(sys, work, rec->eye.x, rec->eye.y, rec->eye.w, rec->eye.h, rec->eye.s, rec->eye.t + rec->eye.h, &part, &pose.index, &sys->shadowPltt, cellId, billboard, &depth, flip);
                } else {
                    MCSS_DrawShadow(sys, work, rec->eye.x, rec->eye.y, rec->eye.w, rec->eye.h, rec->eye.s, rec->eye.t, &part, &pose.index, &sys->shadowPltt, cellId, billboard, &depth, flip);
                }
            }
        }
    } while (++workIdx < sys->maxCount);
    }
    REG_MTX_POP = 1;
}

/* fx32 texture coordinate to the 12.4 halfword TEXCOORD wants */
#define ST(x) ((u32)(u16)(s16)((x) >> 8))

/*
 * mcss.c's per-cell quad drawer (wave 11, third lane on the family).  Its
 * three callers are the 0x02014D2C..0x020155A0 frame walker (0x020154D0,
 * 0x02015506, 0x02015562), which pass a cell record's six words as
 * x, y, width, height, s, t and a stack record as `pose`.  The body is a
 * straight run of G3 register writes: optional projection, texture palette
 * base, polygon attributes, translate / rotate / scale, one textured quad,
 * then (when the slot is not hidden and alpha is non-zero) the same quad
 * again with polygon id 1, and finally a depth step on *z.
 *
 * FOUR THINGS THE BYTES SETTLED, in the order they were found:
 *  1. FX_SinCosTable_ is declared WITHOUT const.  The second G3_RotZ
 *     re-reads pose->rot and both table entries after the call; const lets
 *     mwcc keep sin/cos across the call in two extra frame slots (0x58
 *     frame against the original's 0x50).  The index is recomputed too.
 *  2. G3_Translate / G3_Scale are the SDK inline functions, not three
 *     plain stores: the original loads pose->sx AND pose->sy (and *z)
 *     before the first register store, which only argument evaluation
 *     produces (58 -> 31 bytes).
 *  3. The second G3_TexPlttBase is written as the SDK's inline expression
 *     `addr >> (4 - (fmt == GX_TEXFMT_PLTT4))`; its 0/1 is a compiler
 *     temporary homed at sp+0x20, the LOWEST slot, which is how the slot
 *     order told a temporary from a declared local.  The alpha value goes
 *     through a block-local `a`, and polyId is declared last: slot order
 *     here follows creation order, not declaration order alone.
 *  4. The depth pointer is `u32 *`, not `fx32 *`.  With a signed pointee
 *     the two +-0x100 tails pick the other register for the 0x140 field
 *     offset the original re-uses to build 0x100 (`subs r0, #0x40`); 22
 *     bytes over four tails that 547 hill and 2000 anneal permuter compiles
 *     could not move, closed by the declaration alone (wave-10 lesson).
 */
void MCSS_DrawShadow(McssSys *sys, McssWork *work, fx32 x, fx32 y,
                   fx32 width, fx32 height, fx32 s, fx32 t,
                   McssPose *pose, u16 *frameIndex, McssPlttProxy *shadowPltt, int cellId,
                   int ortho, u32 *depth, u8 flip)
{
    u32 alpha;
    fx32 transX, transY;
    u32 texCoord0, texCoord1, texCoord2, texCoord3;
    u32 sLeft, tTop, sRight, tBottom;
    int sinIdx;
    int polyId;

    {
        u32 shadowAlpha = work->flags.bits.shadowAlpha;
        if (shadowAlpha == 0x20) {
            shadowAlpha = work->flags.bits.alpha >> 1;
        }
        alpha = (u8)shadowAlpha;
    }
    if (work->flags.bits.alpha == 0x1f || work->flags.bits.shadowForceDraw) {
        polyId = 0;
    } else {
        polyId = cellId;
        if (polyId > 0x3f) {
            polyId = 0x3f;
        }
    }

    if (ortho != 0) {
        G3i_FrustumW_(6 << 16, -6 << 16, -8 << 16, 8 << 16, 0x1000,
                      (sys->flags.bits.nearDepthRange ? 0x200 : 0x400) << 12, 0x1000, 1, 0);
        REG_MTX_MODE = 2;
    }
    REG_MTX_RESTORE = 0x1d;

    REG_TEXPLTT_BASE = work->plttProxy.vramAddr[0] >> (4 - (work->plttProxy.fmt == 2));
    REG_POLYGON_ATTR = (work->flags.bits.alpha << 16) | (0xc0 | (polyId << 24));

    transX = (work->cellCtrl.anim->frames[*frameIndex].cells[cellId].ofsX + pose->ofsX) << 8;
    transY = -(work->cellCtrl.anim->frames[*frameIndex].cells[cellId].ofsY + pose->ofsY) << 8;
    G3_Translate(transX, transY, *depth);
    sinIdx = pose->rot >> 4;
    G3_RotZ(-FX_SinCosTable_[sinIdx * 2], FX_SinCosTable_[sinIdx * 2 + 1]);

    if (flip == 0) {
        G3_Scale(pose->sx, pose->sy, 0x1000);
        G3_Translate(x, y, 0);
        G3_Scale(width, height, 0x1000);
    } else if (flip & 1) {
        G3_Scale(-pose->sx, pose->sy, 0x1000);
        G3_Translate(-x, y, 0);
        G3_Scale(width, height, 0x1000);
        G3_Translate(-0x100, 0, 0);
        s = 0x200000 - s - width;
    }

    REG_BEGIN_VTXS = 1;
    tTop = ST(t) << 16;
    sLeft = ST(s);
    texCoord0 = sLeft | tTop;
    REG_TEXCOORD = texCoord0;
    REG_VTX_16 = 0;
    REG_VTX_16 = 0;
    tBottom = ST(t + height) << 16;
    texCoord1 = sLeft | tBottom;
    REG_TEXCOORD = texCoord1;
    REG_VTX_16 = 0xFF000000;
    REG_VTX_16 = 0;
    sRight = ST(s + width);
    texCoord2 = tBottom | sRight;
    REG_TEXCOORD = texCoord2;
    REG_VTX_16 = 0xFF000100;
    REG_VTX_16 = 0;
    texCoord3 = sRight | tTop;
    REG_TEXCOORD = texCoord3;
    REG_VTX_16 = 0x100;
    REG_VTX_16 = 0;
    REG_END_VTXS = 0;

    REG_MTX_MODE = 0;
    REG_MTX_RESTORE = 0;
    REG_MTX_MODE = 2;
    REG_MTX_RESTORE = 0x1e;

    if (!work->flags.bits.shadowVanishFlag && alpha != 0) {
        REG_TEXPLTT_BASE = shadowPltt->vramAddr[0] >> (4 - (shadowPltt->fmt == 2));
        REG_POLYGON_ATTR = (alpha << 16) | 0x010000C0;
        G3_Translate(transX, transY, 0);
        sinIdx = pose->rot >> 4;
        G3_RotZ(-FX_SinCosTable_[sinIdx * 2], FX_SinCosTable_[sinIdx * 2 + 1]);
        G3_Scale(pose->sx, pose->sy, 0x1000);
        G3_Translate(x, y, 0);
        G3_Scale(width, height, 0x1000);
        REG_BEGIN_VTXS = 1;
        REG_TEXCOORD = texCoord0;
        REG_VTX_16 = 0;
        REG_VTX_16 = 0;
        REG_TEXCOORD = texCoord1;
        REG_VTX_16 = 0xFF000000;
        REG_VTX_16 = 0;
        REG_TEXCOORD = texCoord2;
        REG_VTX_16 = 0xFF000100;
        REG_VTX_16 = 0;
        REG_TEXCOORD = texCoord3;
        REG_VTX_16 = 0x100;
        REG_VTX_16 = 0;
        REG_END_VTXS = 0;
    }

    if (ortho == 0) {
        if (sys->depthStep == 0) {
            *depth -= ((work->flags.bits.alpha != 0x1f) | work->flags.bits.mepachiDrawLast) ? -0x100 : 0x100;
        } else {
            *depth -= ((work->flags.bits.alpha != 0x1f) | work->flags.bits.mepachiDrawLast) ? -sys->depthStep : sys->depthStep;
        }
    } else if (sys->flags.bits.nearDepthRange) {
        *depth -= ((work->flags.bits.alpha != 0x1f) | work->flags.bits.mepachiDrawLast) ? -0x100 : 0x100;
    } else {
        *depth -= ((work->flags.bits.alpha != 0x1f) | work->flags.bits.mepachiDrawLast) ? -0x400 : 0x400;
    }
}

/*
 * 476 bytes, one function, 29 field stores and no branches but the loop.
 *
 * "Take the first free slot of the module's array, allocate a 0x188 byte
 * record into it, fill it in and hand it back."  The loop walks
 * sys->works[0 .. sys->maxCount) looking for a NULL entry, and on the first one
 * it allocates, initialises and breaks; the return is sys->works[i] either way,
 * so a full array returns the one-past-the-end element, which is the game's
 * behaviour and not a transcription error.
 *
 * ---------------------------------------------------------------------------
 * THE FILE NAME, AND WHAT IT SETTLES
 * ---------------------------------------------------------------------------
 * The allocator call passes 0x020A72CC and 906, which are __FILE__ and
 * __LINE__.  The bytes at 0x020A72CC spell **mcss.c**, so this function and
 * its neighbours in pkt_02014D90 are that original source file, at line 906.
 * The string is attested the ordinary way, seven literal-pool witnesses
 * elsewhere in the image, so it needed no widening of the `string` class; see
 * docs/idioms/file-string-is-an-abs32-into-the-string-area.md for why it is
 * declared as an extern array rather than written `__FILE__`.  The strings on
 * either side of it in the packed area are "field_status.c" and a run of four
 * pointer words, which is the shape
 * docs/idioms/a-string-after-a-data-table-has-no-witness.md warns about for
 * the *next* file name in that area rather than for this one.
 *
 * ---------------------------------------------------------------------------
 * WHAT COST THE TIME
 * ---------------------------------------------------------------------------
 * **The loop bound is the field, not a local.**  `n = sys->maxCount;` before the
 * loop and `i < n` inside it compiles to the same 476 bytes with `n` in r1
 * instead of r2, which spills the second parameter one instruction later and
 * leaves nine bytes wrong in the prologue and one at the loop's `cmp`.
 * Written `for (i = 0; i < sys->maxCount; i++)` the compiler hoists the load
 * itself, into r2, and the whole function is EXACT.  Nothing in the body reads
 * the field, and the only call inside the loop is on the path that breaks out
 * of it, so the hoist is legal and the original took it.
 *
 * **sizeof is in the source, and it is what pays for the field offsets.**
 * The allocation size arrives as `movs r7, #0x62` / `lsls r7, r7, #2`, which is
 * 0x188, and r7 then stays live for the whole body: every field past the Thumb
 * immediate reach is addressed as `adds r0, r7, #0` / `subs r0, #k` with k the
 * distance back from the end of the record, and the halfword 0xC400 stored at
 * +0x178 is `lsls r2, r7, #7` off the same register.  That only happens if the
 * size the source passes to the allocator is literally `sizeof(McssWork)`
 * and the struct is exactly 0x188 bytes, which makes the declaration
 * self-checking: a struct one word too long or too short changes the constant
 * and every offset derived from it.  The same front end goes on to reuse the
 * constant 0x1F (a bitfield value, parked in `ip`) as the base for the offsets
 * 0x110, 0x114 and 0x118, which is the extreme end of the same behaviour.
 *
 * **Every store reloads the array and the element.**  `sys->works[i]->field = v`
 * appears 29 times and the original reloads `sys->works` and then
 * `sys->works[i]` before each one, because the store it just made could alias
 * either.  Writing the element pointer into a local once, which is what a
 * person would do, removes 28 pairs of loads and is a different function.  The
 * counterpart is docs/idioms/const-pointer-lets-a-field-load-survive-a-store.md:
 * there the qualifier removes the reloads, here its absence is the match.
 *
 * **The 36 byte record at +0x150 is one struct assignment.**  It compiles to a
 * counted `ldm`/`stm` loop of four iterations plus a trailing word, which is
 * docs/idioms/big-struct-assignment-is-an-ldm-stm-loop.md; declaring it as a
 * byte array instead gives a `ldrb`/`strb` loop of 36 iterations, so the
 * source's type has at least four byte alignment and `u32 w[9]` is what
 * reproduces it.
 *
 * The word at +0x140 is a bitfield container: the three writes are the low
 * eight bits set to 0x1F, the nine bits at 14 set to 0x20 and bit 11 cleared,
 * and then bit 29 set after the struct copy.  Written as masks and shifts over
 * a plain `u32` the compiler materialises each mask from a literal pool; as
 * bitfields it emits the original's `bics`/`orrs` against the small constants
 * and only the two nine-bit masks reach the pool.
 *
 * Nothing here is version specific: every constant is a structure offset, a
 * fixed-point 1.0 (0x1000), a bitfield value or the source line number.
 *
 * Verified with
 *   python tools/match.py one --src src/matched/MCSS_Add.c  *       --func MCSS_Add --addr 0x020159C8 --cc 1.1p1
 */
McssWork *MCSS_Add(McssSys *sys, fx32 x, fx32 y, fx32 z, const McssAddWork *addWork)
{
    s32 i;

    for (i = 0; i < sys->maxCount; i++) {
        if (sys->works[i] == 0) {
            sys->works[i] = GFL_HEAP_Alloc((u16)sys->heapId, sizeof(McssWork), 1,
                                          sFileMcss,
                                          906);
            sys->works[i]->index = i;
            sys->works[i]->heapId = sys->heapId;
            sys->works[i]->position.x = x;
            sys->works[i]->position.y = y;
            sys->works[i]->position.z = z;
            sys->works[i]->scale.x = 0x1000;
            sys->works[i]->scale.y = 0x1000;
            sys->works[i]->scale.z = 0x1000;
            sys->works[i]->ofsPosition.x = 0;
            sys->works[i]->ofsPosition.y = 0;
            sys->works[i]->ofsPosition.z = 0;
            sys->works[i]->shadowScale.x = 0x1000;
            sys->works[i]->shadowScale.y = 0x1000;
            sys->works[i]->shadowScale.z = 0x1000;
            sys->works[i]->flags.bits.alpha = 0x1F;
            sys->works[i]->flags.bits.shadowAlpha = 0x20;
            sys->works[i]->flags.bits.vanishFlag = 0;
            sys->works[i]->shadowRotX = 0xC400;
            sys->works[i]->shadowRotZ = 0;
            sys->works[i]->shadowOffset.x = 0;
            sys->works[i]->shadowOffset.y = 0;
            sys->works[i]->shadowOffset.z = 0xFFFFF000;
            sys->works[i]->drawScale.x = 0x1000;
            sys->works[i]->drawScale.y = 0x1000;
            sys->works[i]->drawScale.z = 0x1000;
            sys->works[i]->addWork = *addWork;
            sys->works[i]->animeSpeed = 0x1000;
            sys->works[i]->flags.bits.orthoBillboardFlag = 1;
            MCSS_LoadResource(sys, i, addWork);
            break;
        }
    }
    return sys->works[i];
}

/*
 * A whole translation unit, matched as one byte range.
 *
 *           MCSS_ResetOrthoBillboardFlag
 *
 * alias: MCSS_Del tears down an object: it calls MCSS_FreeResource(obj), then
 * for each of the three word fields at +0, +4 and +8 that is non-zero it
 * passes that field's *value* (not the object) to a cleanup call
 * (MCSS_DeleteTextureTask for +0, MCSS_DeletePaletteTask for +4 and +8) and zeroes the field;
 * it then clears a slot this object owns in an array reached through
 * sys->+0x14, indexed by the object's own field at +0x148, and finally
 * hands the object to GFL_HEAP_Free through an interworking blx.
 *
 * The four followers are unlabelled leaf accessors on the same class of
 * object, found in the .word run disasm.py left undecoded immediately
 * after MCSS_Del (its prologue has no register-saving push that a
 * two-word bit-flag accessor shares); see
 * docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md. Two work a
 * flag at +0x2c: MCSS_SetOrthoMode clears then re-sets bit 0 (a clear/set pair
 * rather than a plain |=, which is what tells apart the extra bics), and
 * MCSS_ResetOrthoMode only clears it. The other two work a flag at +0x140, too far
 * from the object base for an immediate str, which is why the compiler
 * computes the offset into a register instead of folding it into the
 * instruction: MCSS_SetOrthoBillboardFlag sets bit 0x1D (0x20000000) and MCSS_ResetOrthoBillboardFlag
 * clears it via the pool word 0xDFFFFFFF immediately after it.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02015BA4.c \
 *       --addr 0x02015BA4 --thumb
 */
void MCSS_Del(McssSys *sys, McssWork *work)
{
    u32 index;
    McssWork **works;
    MCSS_FreeResource(work);
    if (work->textureTask != 0) {
        MCSS_DeleteTextureTask(work->textureTask);
        work->textureTask = 0;
    }
    if (work->fadeTask != 0) {
        MCSS_DeletePaletteTask(work->fadeTask);
        work->fadeTask = 0;
    }
    if (work->paletteTask != 0) {
        MCSS_DeletePaletteTask(work->paletteTask);
        work->paletteTask = 0;
    }
    index = work->index;
    works = sys->works;
    works[index] = 0;
    GFL_HEAP_Free(work);
}

void MCSS_SetOrthoMode(McssSys *sys)
{
    sys->flags.raw &= ~1;
    sys->flags.raw |= 1;
}

void MCSS_ResetOrthoMode(McssSys *sys)
{
    sys->flags.raw &= ~1;
}

void MCSS_SetOrthoBillboardFlag(McssWork *work)
{
    work->flags.raw |= 0x20000000;
}

void MCSS_ResetOrthoBillboardFlag(McssWork *work)
{
    work->flags.raw &= ~0x20000000;
}

/*
 * Unlabelled Thumb leaf in the ARM9 module (saves nothing, so disasm.py emits
 * it as a run of .word). Copies three words out of the structure at +0xE0.
 * The inverse of MCSS_SetPosition; in the ov118 event state machine
 * (0x021D7130) it is the out-direction marshaller.
 *
 * Addresses are Black-image addresses.
 */
void MCSS_GetPosition(McssWork *work, u32 *out)
{
    out[0] = work->position.x;
    out[1] = work->position.y;
    out[2] = work->position.z;
}

/*
 * Unlabelled Thumb leaf in the ARM9 module. Copies three words into the
 * structure at +0xE0. The inverse of MCSS_GetPosition; in the ov118 event state
 * machine (POKETRADE_DEMO_MIDDLE_UpdateScene) and POKETRADE_DEMO_MIDDLE_ResetMonSlide it is the in-direction marshaller.
 *
 * Addresses are Black-image addresses.
 */
void MCSS_SetPosition(McssWork *work, u32 *src)
{
    work->position.x = src[0];
    work->position.y = src[1];
    work->position.z = src[2];
}

/*
 * Unlabelled Thumb leaf in the ARM9 module. Copies three words out of +0x11C. Twin of MCSS_SetOfsPosition.
 * Filed as the witness for an ov094 caller.
 *
 * Addresses are Black-image addresses.
 */
void MCSS_GetOfsPosition(McssWork *work, u32 *out)
{
    out[0] = work->ofsPosition.x;
    out[1] = work->ofsPosition.y;
    out[2] = work->ofsPosition.z;
}

/*
 * Unlabelled Thumb leaf in the ARM9 module (mcss.c). Copies three words
 * into the structure at +0x11C; same shape as MCSS_SetPosition further
 * back.
 *
 * Addresses are Black-image addresses.
 */
void MCSS_SetOfsPosition(McssWork *work, u32 *src)
{
    work->ofsPosition.x = src[0];
    work->ofsPosition.y = src[1];
    work->ofsPosition.z = src[2];
}

/*
 * Unlabelled Thumb leaf in the ARM9 module. Copies three words out of the
 * structure at +0xEC. The inverse of MCSS_SetScale; same shape as
 * MCSS_GetPosition one word-group further along.
 *
 * Addresses are Black-image addresses.
 */
void MCSS_GetScale(McssWork *work, u32 *out)
{
    out[0] = work->scale.x;
    out[1] = work->scale.y;
    out[2] = work->scale.z;
}

/*
 * Unlabelled Thumb leaf in the ARM9 module. Copies three words into the
 * structure at +0xEC. The inverse of MCSS_GetScale.
 *
 * Addresses are Black-image addresses.
 */
void MCSS_SetScale(McssWork *work, u32 *src)
{
    work->scale.x = src[0];
    work->scale.y = src[1];
    work->scale.z = src[2];
}

/*
 * Unlabelled Thumb leaf in the ARM9 module. Copies three words out of +0x128.
 * Filed as the witness for an ov094 caller.
 *
 * Addresses are Black-image addresses.
 */
void MCSS_GetShadowScale(McssWork *work, u32 *out)
{
    out[0] = work->shadowScale.x;
    out[1] = work->shadowScale.y;
    out[2] = work->shadowScale.z;
}

/*
 * Unlabelled Thumb leaf in the ARM9 module. Copies three words into +0x128. Inverse of MCSS_GetShadowScale.
 * Filed as the witness for an ov094 caller.
 *
 * Addresses are Black-image addresses.
 */
void MCSS_SetShadowScale(McssWork *work, u32 *src)
{
    work->shadowScale.x = src[0];
    work->shadowScale.y = src[1];
    work->shadowScale.z = src[2];
}

/*
 * Unlabelled Thumb leaf in the ARM9 module. Copies three words out of +0xF8.
 * Filed as the witness for an ov094 caller.
 *
 * Addresses are Black-image addresses.
 */
void MCSS_GetRotate(McssWork *work, u32 *out)
{
    out[0] = work->rotate.x;
    out[1] = work->rotate.y;
    out[2] = work->rotate.z;
}

/*
 * Unlabelled Thumb leaf in the ARM9 module. Copies three words into +0xF8. Inverse of MCSS_GetRotate.
 * Filed as the witness for an ov094 caller.
 *
 * Addresses are Black-image addresses.
 */
void MCSS_SetRotate(McssWork *work, u32 *src)
{
    work->rotate.x = src[0];
    work->rotate.y = src[1];
    work->rotate.z = src[2];
}

/*
 * Unlabelled Thumb leaf in the ARM9 module. Copies three words into +0x104.
 * Filed as the witness for an ov094 caller.
 *
 * Addresses are Black-image addresses.
 */
void MCSS_SetOfsScale(McssWork *work, u32 *src)
{
    work->ofsScale.x = src[0];
    work->ofsScale.y = src[1];
    work->ofsScale.z = src[2];
}

/*
 * Unlabelled Thumb leaf in the ARM9 module. Copies three words out of +0x110.
 * Filed as the witness for an ov094 caller.
 *
 * Addresses are Black-image addresses.
 */
void MCSS_GetDrawScale(McssWork *work, u32 *out)
{
    out[0] = work->drawScale.x;
    out[1] = work->drawScale.y;
    out[2] = work->drawScale.z;
}

/*
 * Unlabelled Thumb leaf in the ARM9 module. Copies three words into +0x110. Inverse of MCSS_GetDrawScale.
 * Filed as the witness for an ov094 caller.
 *
 * Addresses are Black-image addresses.
 */
void MCSS_SetDrawScale(McssWork *work, u32 *src)
{
    work->drawScale.x = src[0];
    work->drawScale.y = src[1];
    work->drawScale.z = src[2];
}

/*
 * note: halfword setter at +0x178; called from ov131 P_STA_SUB_CreateMcss (bl at
 *   +0x78 and +0xB6) with the pooled full-width value 0xD555.
 */
void MCSS_SetShadowRotateX(McssWork *work, u16 rotX)
{
    work->shadowRotX = rotX;
}

/*
 * Unlabelled Thumb leaf in the ARM9 module. Stores a halfword at +0x17A.
 * Filed as the witness for an ov094 caller.
 *
 * Addresses are Black-image addresses.
 */
void MCSS_SetShadowRotateZ(McssWork *work, u16 rotZ)
{
    work->shadowRotZ = rotZ;
}

/*
 * Unlabelled Thumb leaf in the ARM9 module. Copies three words into +0x17C.
 * Filed as the witness for an ov094 caller.
 *
 * Addresses are Black-image addresses.
 */
void MCSS_SetShadowOffset(McssWork *work, int *src)
{
    work->shadowOffset.x = src[0];
    work->shadowOffset.y = src[1];
    work->shadowOffset.z = src[2];
}

/*
 * Unlabelled Thumb leaf in the ARM9 module. Sets bit 8 of the control word at +0x140.
 * Filed as the witness for an ov094 caller.
 *
 * Addresses are Black-image addresses.
 */
void MCSS_SetMepachiFlag(McssWork *work)
{
    work->flags.raw |= 0x100u;
}

/*
 * Unlabelled Thumb leaf in the ARM9 module. Clears bit 8 of the control word at +0x140.
 * Filed as the witness for an ov094 caller.
 *
 * Addresses are Black-image addresses.
 */
void MCSS_ResetMepachiFlag(McssWork *work)
{
    work->flags.raw &= ~0x100u;
}

/*
 * Unlabelled Thumb leaf in the ARM9 module. Toggles bit 8 of the control word at +0x140.
 * Filed as the witness for an ov094 caller.
 *
 * Addresses are Black-image addresses.
 */
void MCSS_FlipMepachiFlag(McssWork *work)
{
    work->flags.bits.mepachiFlag ^= 1;
}

/*
 * Unlabelled Thumb leaf in the ARM9 module. Reads the two-bit field at bits 9..10 of the control word at +0x140.
 * Filed as the witness for an ov094 caller.
 *
 * Addresses are Black-image addresses.
 */
int MCSS_GetAnmStopFlag(McssWork *work)
{
    return work->flags.bits.anmStopFlag;
}

/*
 * Unlabelled Thumb leaf in the ARM9 module. Compound-OR of the 2-bit
 * bitfield at bits 9..10 of the register at +0x140 with 1. The access is
 * non-volatile in the original: mwcc reads the word once and reinserts the
 * field without a reload (a `volatile` spelling forces a second `ldr` and
 * diverges). Pairs with MCSS_ResetAnmStopFlag, which clears bit 9.
 *
 * Addresses are Black-image addresses.
 */
void MCSS_SetAnmStopFlag(McssWork *work)
{
    work->flags.bits.anmStopFlag |= 1;
}

/*
 * Unlabelled Thumb leaf in the ARM9 module. Sets bit 10 of the control word at +0x140.
 * Filed as the witness for an ov094 caller.
 *
 * Addresses are Black-image addresses.
 */
void MCSS_SetAnmStopFlagAlways(McssWork *work)
{
    work->flags.bits.anmStopFlag |= 2;
}

/*
 * Unlabelled Thumb leaf in the ARM9 module. Compound-AND of the 2-bit
 * bitfield at bits 9..10 of the register at +0x140 with ~1 (clears bit 9).
 * Same non-volatile codegen lever as MCSS_SetAnmStopFlag.
 *
 * Addresses are Black-image addresses.
 */
void MCSS_ResetAnmStopFlag(McssWork *work)
{
    work->flags.bits.anmStopFlag &= ~1u;
}

/*
 * Unlabelled Thumb leaf in the ARM9 module. Clears bit 10 of the control word at +0x140.
 * Filed as the witness for an ov094 caller.
 *
 * Addresses are Black-image addresses.
 */
void MCSS_ResetAnmStopFlagAlways(McssWork *work)
{
    work->flags.bits.anmStopFlag &= ~2u;
}

/*
 * Unlabelled Thumb leaf in the ARM9 module. Reads bit 11 of the control word at +0x140.
 * Filed as the witness for an ov094 caller.
 *
 * Addresses are Black-image addresses.
 */
int MCSS_GetVanishFlag(McssWork *work)
{
    return work->flags.bits.vanishFlag;
}

/*
 * Unlabelled Thumb leaf in the ARM9 module. Sets bit 11 (0x800) of the
 * 32-bit register at +0x140. Pairs with MCSS_ResetVanishFlag, which clears it.
 *
 * Addresses are Black-image addresses.
 */
void MCSS_SetVanishFlag(McssWork *work)
{
    /* stand-in: volatile keeps the word read-modify-write of the original */
    *(volatile u32 *)&work->flags.raw |= 0x800u;
}

/*
 * Unlabelled Thumb leaf in the ARM9 module (saves nothing, so disasm.py emits
 * it as a run of .word; the live bytes decode as Thumb). Clears bit 11
 * (0x800) of the 32-bit field at +0x140. This is one of the pair
 * MCSS_SetVanishFlag/MCSS_ResetVanishFlag that set and clear the same bit; it is called
 * from the ov118 event state machine POKETRADE_DEMO_MIDDLE_UpdateScene and from
 * POKETRADE_DEMO_MIDDLE_ResetMonSlide, and is an image-wide-only reference target (no listing label),
 * so matching it supplies the `matched` witness those callers lack.
 *
 * Addresses are Black-image addresses.
 */
void MCSS_ResetVanishFlag(McssWork *work)
{
    /* stand-in: volatile keeps the word read-modify-write of the original */
    *(volatile u32 *)&work->flags.raw &= 0xFFFFF7FFu;
}

/*
 * Unlabelled Thumb leaf in the ARM9 module. Toggles bit 11 of the control word at +0x140.
 * Filed as the witness for an ov094 caller.
 *
 * Addresses are Black-image addresses.
 */
void MCSS_FlipVanishFlag(McssWork *work)
{
    work->flags.bits.vanishFlag = work->flags.bits.vanishFlag ^ 1;
}

/*
 * Unlabelled Thumb leaf in the ARM9 module (mcss.c). Returns the address
 * of the embedded renderer sub-object at +0x34.
 *
 * Addresses are Black-image addresses.
 */
void *MCSS_GetAnimCtrl(McssWork *work)
{
    return &work->animCtrl;
}

u16 MCSS_GetAnimSeqNum(McssWork *work)
{
    return *(u16 *)work->multiCellAnimBank;
}

u8 MCSS_GetStopCellNum(McssWork *work)
{
    return work->stopCellTable[0];
}

u8 MCSS_GetStopCellIndex(McssWork *work, u8 i)
{
    return (work->stopCellTable + i)[2];
}

/*
 * Unlabelled Thumb leaf in the ARM9 module (mcss.c). Reads the u16 at
 * +4 of the table the word at +0x2C points to (`ldrh` proves unsigned).
 * Witness for the call from ov119 POKETRADE_3D_SetMcssOffsetForSpecies at 0x021E3520.
 */
u16 MCSS_GetSizeX(McssWork *work)
{
    return work->cellHeader->sizeX;
}

/*
 * Unlabelled Thumb leaf in the ARM9 module (mcss.c). Reads the u16 at
 * +6 of the table the word at +0x2C points to (`ldrh` proves unsigned).
 *
 * Addresses are Black-image addresses.
 */
u16 MCSS_GetSizeY(McssWork *work)
{
    return work->cellHeader->sizeY;
}

/*
 * Unlabelled Thumb leaf in the ARM9 module (mcss.c). Reads the s16 at
 * +8 of the table the word at +0x2C points to (`ldrsh` with a register
 * offset proves signed).
 *
 * Addresses are Black-image addresses.
 */
s16 MCSS_GetOfsX(McssWork *work)
{
    return work->cellHeader->ofsX;
}

/*
 * Unlabelled Thumb leaf in the ARM9 module (mcss.c). Reads the s16 at
 * +0xA of the table the word at +0x2C points to; sibling of
 * MCSS_GetOfsX.
 *
 * Addresses are Black-image addresses.
 */
s16 MCSS_GetOfsY(McssWork *work)
{
    return work->cellHeader->ofsY;
}

/*
 * Unlabelled Thumb leaf in the ARM9 module. Reads byte 1 of the record behind the pointer at +0x30.
 * Filed as the witness for an ov094 caller.
 *
 * Addresses are Black-image addresses.
 */
u8 MCSS_GetStopCellFlags(McssWork *work)
{
    return work->stopCellTable[1];
}

/*
 * A pure forwarder: tail-calls NNS_G2dSetCellAnimationParam on a member 0x34 bytes into
 * the object, with a fixed 1 as the second argument.
 *
 * EXACT* because the 18 compiled bytes fall far short of the disasm.py
 * extent (252 bytes): the packet's next several functions carry no
 * register-saving prologue and disasm.py's extent runs to the following
 * labelled function; they are not matched here.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/MCSS_SetAnimCallback.c \
 *       --func MCSS_SetAnimCallback --addr 0x02015F2C --cc 1.1p1
 */
int MCSS_SetAnimCallback(McssWork *work, u32 callback, u32 callbackWork, u32 unusedArg)
{
    NNS_G2dSetCellAnimationParam((int)&work->animCtrl, 1, callback, callbackWork);
}

void MCSS_SetCellCallback(McssWork *work, unsigned flags, void *callback)
{
    NNSi_G2dMCEnumAnimBank(&work->cellCtrl, callback, flags);
}

/*
 * Unlabelled Thumb function in the ARM9 module (mcss.c). Starts the
 * +0x134 fade: sets bit 12 of the +0x140 flag word, stores the current
 * and target bytes (+0x134, +0x135), the fifth argument at +0x13C, clears
 * +0x136, splits the signed step into +0x137 and the s32 step at +0x138
 * (1 - step when negative), and negates the step when the current value
 * is above the target (`cmp r1, r2 / bls`, so both are unsigned bytes).
 *
 * The step is stored as a field in each arm and the negation re-reads the
 * field (the original reloads +0x138 with a fresh `0x4e << 2` base).
 * Written through raw char offsets with the step in a local, mwcc forwards
 * the stored value into the `muls` and colours the 0x140 base into r5;
 * the struct spelling below is byte-exact. `* 0xFFFFFFFF` rather than
 * `-x` is what emits the `mvns`/`muls` pair.
 *
 * Addresses are Black-image addresses.
 */
void MCSS_SetPaletteFade(McssWork *work, u32 start, u32 end, s32 wait, u32 color)
{
    work->flags.raw |= 0x1000;
    work->fadeStart = start;
    work->fadeEnd = end;
    work->fadeColor = color;
    work->fadeWait = 0;
    if (wait < 0) {
        work->fadeWaitSet = 0;
        work->fadeStep = -(wait - 1);
    } else {
        work->fadeWaitSet = wait;
        work->fadeStep = 1;
    }
    if (start > end) {
        work->fadeStep *= 0xFFFFFFFF;
    }
}

/*
 * Unlabelled Thumb leaf in the ARM9 module. Reads the low byte of the control word at +0x140.
 * Filed as the witness for an ov094 caller.
 *
 * Addresses are Black-image addresses.
 */
u8 MCSS_GetAlpha(McssWork *work)
{
    return work->flags.bits.alpha;
}

/*
 * Unlabelled leaf accessor matched to give overlay call sites a `matched`
 * witness (ov117 POKETRADE_IRCDEMO_SetMonSlide): the low byte of the word at +0x140.
 * Addresses are Black-image addresses.
 */
void MCSS_SetAlpha(McssWork *work, int alpha)
{
    work->flags.raw = (work->flags.raw & ~0xFF) | (unsigned char)alpha;
}

/*
 * Unlabelled leaf accessor, the follower of MCSS_SetAlpha: a 9-bit field at
 * bit 14 of the word at +0x140. Labelled so that MCSS_SetAlpha's extent ends
 * at its own bx lr. Addresses are Black-image addresses.
 */
void MCSS_SetShadowAlpha(McssWork *work, int alpha)
{
    work->flags.raw = (work->flags.raw & 0xFF803FFF) | ((alpha & 0x1FF) << 14);
}

/*
 * Unlabelled leaf accessor matched to give overlay call sites a `matched`
 * witness.  Addresses are Black-image addresses.
 */
void MCSS_SetShadowVanishFlag(McssWork *work, int flag)
{
    work->flags.raw = (work->flags.raw & 0xFF7FFFFF) | ((flag & 1) << 23);
}

/*
 * Unlabelled Thumb leaf in the ARM9 module (mcss.c). Tests bit 12 of the
 * flag word at +0x140 (the bit MCSS_SetPaletteFade sets). A one-bit bitfield
 * keeps the original's lsls/lsrs pair; a mask would fold to `ands`.
 *
 * Addresses are Black-image addresses.
 */
int MCSS_CheckPaletteFade(McssWork *work)
{
    if (work->flags.bits.paletteFadeFlag) {
        return 1;
    }
    return 0;
}

/*
 * Unlabelled Thumb leaf in the ARM9 module (mcss.c). Stores its second
 * argument into the word at +0x30. Seeded from overlay call sites.
 *
 * Addresses are Black-image addresses.
 */
void MCSS_SetTextureTransAdrs(McssSys *sys, u32 adrs)
{
    sys->texTransAdrs = adrs;
}

void MCSS_SetPaletteTransAdrs(McssSys *sys, unsigned int adrs)
{
    sys->plttTransAdrs = adrs;
}

/*
 * promoted: from src/pending on 2026-09-19, no C change: its blocker is filed,
 *           every relocation site resolves and match.py one reports EXACT*.
 *
 * Reconfigures the object: derives a value from NNS_G2dGetAnimSequenceByIdx on field
 * +0x28 and a caller-supplied flag truncated to 16 bits (the explicit
 * lsls/lsrs #0x10 pair in the original is exactly that narrowing cast in
 * the callee, not something the caller is trusted to have done), releases
 * the handle at +0x98 through GFL_HEAP_Free if one is set, calls
 * MCSS_InitAnimCtrl(a, 1), passes the derived value into NNS_G2dSetAnimSequenceToMCAnimation on the
 * member at +0x34, then clears bit 0 of the word at +0x144.
 *
 * Every concrete byte matches; MCSS_InitAnimCtrl (0x02016984, later in this
 * same packet, not yet matched) is called from exactly this one site in
 * the whole ROM, so that relocation stays unresolved under the honesty
 * rule.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/MCSS_SetAnimeIndex.c \
 *       --func MCSS_SetAnimeIndex --addr 0x02016028 --cc 1.1p1
 *
 * The `matched` class does not reach it: MCSS_InitAnimCtrl is not matched, so
 * no EXACT entry covers that address. Closes to EXACT the day it is
 * matched, or gets a second caller elsewhere in the image.
 */
void MCSS_SetAnimeIndex(McssWork *work, u32 animeIndex)
{
    void *seq = NNS_G2dGetAnimSequenceByIdx(work->multiCellAnimBank, (u16)animeIndex);

    if (work->animWork != 0) {
        GFL_HEAP_Free(work->animWork);
    }

    MCSS_InitAnimCtrl(work, 1);
    NNS_G2dSetAnimSequenceToMCAnimation(&work->animCtrl, seq);
    work->requestFlags.raw &= ~1u;
}

/*
 * Unlabelled Thumb leaf in the ARM9 module. Reads bits 24..27 of the control word at +0x140.
 * Filed as the witness for an ov094 caller.
 *
 * Addresses are Black-image addresses.
 */
u8 MCSS_GetMosaic(McssWork *work)
{
    return work->flags.bits.mosaic;
}

/*
 * Updates a packed 4-bit mode field at b+0x140 (bits 24-27 of that word;
 * see docs/idioms/shift-pair-with-no-matching-type-is-a-bitfield.md) if
 * the caller's requested mode (clamped to 15) differs from the current
 * one, then reinitialises through MCSS_FreeResource and forwards a nested
 * word and struct pointer into MCSS_LoadResource. The bitfield pointer is
 * recomputed fresh for the store rather than kept in a local across the
 * clamp branch: the original re-issues the same "5 << 6" multiply instead
 * of reusing the register from the read, the same shape as
 * docs/idioms/keeping-a-cursor-in-a-named-local-costs-a-callee-saved-register.md.
 *
 * EXACT* because the 72 compiled bytes fall short of the disasm.py extent
 * (92 bytes): the extent runs into the next function's own literal pool,
 * not a byte difference.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/MCSS_SetMosaic.c \
 *       --func MCSS_SetMosaic --addr 0x02016078 --cc 1.1p1
 */
void MCSS_SetMosaic(McssSys *sys, McssWork *work, int mosaic)
{
    if (work->flags.bits.mosaic != (u32)mosaic) {
        if (mosaic > 15) {
            mosaic = 15;
        }
        work->flags.bits.mosaic = mosaic;
        MCSS_FreeResource(work);
        MCSS_LoadResource(sys, work->index, &work->addWork);
    }
}

void MCSS_SetGlobalScale(McssSys *sys, unsigned int scale)
{
    sys->globalScale = scale;
}

void MCSS_SetAnimeSpeed(McssWork *work, int speed)
{
    work->animeSpeed = speed;
}

/*
 * Unlabelled Thumb leaf in the ARM9 module. Reads the halfword behind the pointer at +0x28.
 * Filed as the witness for an ov094 caller.
 *
 * Addresses are Black-image addresses.
 */
u16 MCSS_GetAnimSeqNumEx(McssWork *work)
{
    return *(u16 *)work->multiCellAnimBank;
}

/*
 * mcss.c: builds the per-scene fade/transition context.  Three debug
 * allocations out of the heap named by the u16 at +0x14c (masked to
 * 0x7fff and forced into the 0x8000 bank), then a palette blend and a
 * copy, and finally either a task registration (MCSS_TransPaletteTask as the
 * callback, through the owner-aware path or the plain one) or, if the
 * caller has already set the "skip" bit at +0x140, an immediate teardown
 * of everything just allocated.  Either way the done bit 0x10000000 is
 * latched into the same word at +0x140.
 *
 * The three heap ids are recomputed rather than cached: each is a fresh
 * `ldr`+lsls/lsrs of the int field at +0x14c, so the field is an `int`
 * truncated at the call, not a u16 member (see MCSS_InitAnimCtrl in this
 * same file).  The two __LINE__ pool words 0x761 and 0x769 are the
 * consecutive-line idiom: 0x76e is derived from 0x769 with `adds #5`.
 *
 * Closed in the second pass (2026-09-22) from the 12-byte prologue-spill
 * near miss in docs/notes/MCSS_CreatePaletteTransTask.c.txt.  The lever is the THIRD
 * PARAMETER'S TYPE: `u16 a2`, not `int a2`.
 *
 * That note's own list had tried `u16` on a3 (which made it worse, 168
 * bytes) and `u32` on a2, but never `u16` on a2.  tools/permuter.py
 * found it as `type:p(a2:int->u16)` on the 306th compile of a
 * `--mode hill --budget 800 --types` run, taking 12 concrete bytes to 0
 * in one mutation.  A 16-bit parameter arrives already narrowed, so the
 * front end spills it BEFORE it touches the literal pool -- which is
 * exactly the `str r2,[sp,#4]` / `ldr r0,[pc,#0x158]` / `str r3,[sp,#8]`
 * order the note recorded and could not reach.  The note's "untried
 * lever" guess (make a2 reach a call earlier) was not needed.
 *
 * This is also a data point for the family: the value at +0x13C that
 * MCSS_UpdatePaletteFade hands to PALANM_BlendColors as `(u16)` is 16-bit AT THE
 * PARAMETER here, not only at the call.
 *
 * Verified with:
 *   python3 tools/match.py one --src src/matched/MCSS_CreatePaletteTransTask.c \
 *       --func MCSS_CreatePaletteTransTask --addr 0x020160D4 --cc 1.1p1 --thumb
 */
void MCSS_CreatePaletteTransTask(McssSys *sys, McssWork *work, u16 fadeLevel, int fadeColor)
{
    McssTransTask *task;

    task = GFL_HEAP_Alloc(
            (u16)(((u16)work->heapId & 0x7fff) | 0x8000),
            0x2c, 1, sFileMcss, 0x761);

    task->sys = sys;
    task->hasTaskSys = (sys->taskSys != 0);
    task->work = work;
    task->plttProxyOut = &work->plttProxy;
    task->plttDest = sys->plttTransAdrs + (work->index << 5);

    task->plttData = GFL_HEAP_Alloc(
            (u16)(((u16)work->heapId & 0x7fff) | 0x8000),
            0x10, 0, sFileMcss, 0x769);

    task->plttData->fmt = work->plttProxy.fmt;
    task->plttData->extended = 0;
    task->plttData->byteSize = work->plttByteSize;
    task->plttData->data = GFL_HEAP_Alloc(
            (u16)(((u16)work->heapId & 0x7fff) | 0x8000),
            work->plttByteSize, 0, sFileMcss, 0x76e);

    PALANM_BlendColors(work->plttOriginal,
                  task->plttData->data,
                  (u16)((s32)work->plttByteSize / 2),
                  fadeLevel, (u16)fadeColor);
    MIi_CpuCopy16(task->plttData->data,
                  work->plttCurrent, work->plttByteSize);

    if (work->paletteTask != 0) {
        MCSS_DeletePaletteTask(work->paletteTask);
        work->paletteTask = 0;
    }

    if (work->flags.bits.paletteFadeFlag == 0) {
        if (sys->taskSys != 0) {
            work->paletteTask = TCB_AddTask(sys->taskSys,
                                             MCSS_TransPaletteTask, task, 0);
        } else {
            work->paletteTask = GFL_USE_AddMainTask(MCSS_TransPaletteTask, task, 0);
        }
    } else {
        GFL_HEAP_Free(task->plttData->data);
        GFL_HEAP_Free(task->plttData);
        GFL_HEAP_Free(task);
    }

    work->flags.raw |= 0x10000000;
}

void MCSS_CreatePaletteCopyTask(McssSys *sys, McssWork *work)
{
    McssTransTask *task;
    u32 hasTaskSys;
    void *handle;

    hasTaskSys = 1;
    task = GFL_HEAP_Alloc((u16)(((u16)work->heapId & 0x7FFF) | 0x8000), 0x2C, 1, sFileMcss, 1942);
    task->sys = sys;
    if (sys->taskSys == 0) {
        hasTaskSys = 0;
    }
    task->hasTaskSys = hasTaskSys;
    task->work = work;
    task->plttProxyOut = &work->plttProxy;
    task->plttDest = sys->plttTransAdrs + (work->index << 5);

    hasTaskSys = 0;
    task->plttData = GFL_HEAP_Alloc((u16)(((u16)work->heapId & 0x7FFF) | 0x8000), 0x10, 0, sFileMcss, 1950);
    task->plttData->fmt = work->plttProxy.fmt;
    task->plttData->extended = hasTaskSys;
    task->plttData->byteSize = work->plttByteSize;

    task->plttData->data = GFL_HEAP_Alloc((u16)(((u16)work->heapId & 0x7FFF) | 0x8000), work->plttByteSize, 0, sFileMcss, 1950 + 5);
    MIi_CpuCopy16(work->plttOriginal, task->plttData->data, work->plttByteSize);

    if (work->paletteTask != 0) {
        MCSS_DeletePaletteTask(work->paletteTask);
        work->paletteTask = (void *)hasTaskSys;
    }

    if (sys->taskSys != 0) {
        handle = TCB_AddTask(sys->taskSys, MCSS_TransPaletteTask, task, 0);
    } else {
        handle = GFL_USE_AddMainTask(MCSS_TransPaletteTask, task, 0);
    }
    work->paletteTask = handle;

    work->flags.raw &= 0xEFFFFFFF;
}

/*
 * A single matched function.
 *
 * alias: an argument-adjusting tail call: it shifts the object pointer to
 * a member 0x34 bytes in and hands off to NNS_G2dRestartMCAnimation. See
 * docs/idioms/tail-call-is-a-pool-word-and-bx.md.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/unit_02016374.c \
 *       --func MCSS_RestartAnime --addr 0x02016374 --cc 1.1p1 --thumb
 */
void MCSS_RestartAnime(McssWork *work)
{
    NNS_G2dRestartMCAnimation(&work->animCtrl);
}

/*
 * Set bit 0 of the word at +0x144: read, clear, set, write back.  The two
 * `movs r1, #1` are the two separate constants of the `& ~1` / `| 1` pair
 * (Thumb has no ORR immediate, so both go through r1).  Entry attested by
 * the pool word 0x02016381 in MCSS_TOOL_AnimeStopCallback's own pool.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/MCSS_RequestAnimeStopAtStart.c \
 *       --func MCSS_RequestAnimeStopAtStart --addr 0x02016380 --cc 1.1p1 --thumb
 */
void MCSS_RequestAnimeStopAtStart(McssWork *work)
{
    u32 flags = work->requestFlags.raw;
    flags = flags & ~1u;
    flags = flags | 1u;
    work->requestFlags.raw = flags;
}

/*
 * Unlabelled Thumb leaf in the ARM9 module. Sets bit 30 of the control word at +0x140.
 * Filed as the witness for an ov094 caller.
 *
 * Addresses are Black-image addresses.
 */
void MCSS_SetWorkFlag(McssWork *work, int flag)
{
    work->flags.bits.mepachiDrawLast = flag;
}

/*
 * Unlabelled Thumb leaf in the ARM9 module. Stores a word at +0x48.
 * Filed as the witness for an ov094 caller.
 *
 * Addresses are Black-image addresses.
 */
void MCSS_SetSysParam(McssSys *sys, int depthStep)
{
    sys->depthStep = depthStep;
}

/*
 * Unlabelled Thumb leaf in the ARM9 module. Sets bit 1 of the flag word at +0x2C.
 * Filed as the witness for an ov094 caller.
 *
 * Addresses are Black-image addresses.
 */
void MCSS_SetSysFlag(McssSys *sys, int flag)
{
    sys->flags.bits.nearDepthRange = flag;
}

/*
 * The mcss.c bind-slot routine (line 0x840).  Closed in wave 15 from 16
 * bytes out by one declaration: the descriptor parameter is
 * const McssAddWork *.  Without const, the four constructor call sites
 * load a2 for the first argument before the second; with it the image's
 * order (second-argument base first, then the first, then the out
 * pointer copy) comes out.  History: docs/notes/MCSS_LoadResource.c.txt.
 */
void MCSS_LoadResource(McssSys *sys, u32 index, const McssAddWork *addWork)
{
    McssWork *work = sys->works[index];
    McssTransTask *task;
    u32 heap;
    u32 flag;
    McssCellHeader *cellHeader;

    {
        u32 t;
        if (addWork->heapMode == 1) {
            t = (u16)(((u16)work->heapId & 0x7FFF) | 0x8000);
        } else {
            t = work->heapId;
        }
        heap = (u16)t;
    }

    if (sys->arcHandle != 0 && sys->arcId == addWork->arcId) {
        MCSS_LoadResourceShared(sys, index, addWork);
        return;
    }

    work->flags.raw &= 0xFFFFDFFF;
    NNSi_G2dInitVramHandle((u32 *)&work->texImage);
    NNSi_G2dInitVramHandleEx((u32 *)&work->plttProxy);

    work->cellFile = ARC_UTIL_LoadCellBankFromArchive(addWork->arcId, addWork->cellMember, 0, &work->cellBank, heap);
    work->cellAnimFile = ARC_UTIL_LoadMultiCellBankFromArchive(addWork->arcId, addWork->cellAnimMember, 1, &work->cellAnimBank, heap);
    flag = 1;
    work->multiCellFile = ARC_UTIL_LoadAnimBankFromArchive(addWork->arcId, addWork->multiCellMember, 0, &work->multiCellBank, heap);
    work->multiCellAnimFile = ARC_UTIL_LoadMultiAnimBankFromArchive(addWork->arcId, addWork->multiCellAnimMember, 0, &work->multiCellAnimBank, heap);
    MCSS_SetAnimeIndex(work, 0);

    cellHeader = ARC_TOOL_LoadMember(addWork->arcId, addWork->cellHeaderMember, heap);
    work->cellHeader = cellHeader;
    work->stopCellTable = (u8 *)cellHeader + ((0x30 * cellHeader->cellCount + 0xC) & ~3u);

    task = GFL_HEAP_Alloc((u16)(((u16)work->heapId & (0xFFFFDFFFu >> 0x11)) | (flag << 0xF)),
                         0x2C, 1, sFileMcss, 0x840);
    task->sys = sys;
    if (sys->taskSys == 0) {
        flag = 0;
    }
    task->hasTaskSys = flag;
    task->texImageOut = &work->texImage;
    task->plttProxyOut = &work->plttProxy;
    task->texDest = sys->texTransAdrs + (index << 0xE);
    task->plttDest = sys->plttTransAdrs + (index << 5);
    task->work = work;

    task->texBuf = ARC_UTIL_LoadBgCharDataFromArchive(addWork->arcId, addWork->textureMember, 1, task,
                                 (u16)(((u16)work->heapId & 0x7FFF) | 0x8000));
    task->plttBuf = ARC_UTIL_LoadPaletteBlockFromArchive(addWork->arcId, addWork->paletteMember, &task->plttData,
                                  (u16)(((u16)work->heapId & 0x7FFF) | 0x8000));

    work->plttOriginal = GFL_HEAP_Alloc(heap,
                                       task->plttData->byteSize, 0,
                                       sFileMcss, 0x858);
    work->plttCurrent = GFL_HEAP_Alloc(heap,
                                      task->plttData->byteSize, 0,
                                      sFileMcss, 0x858 + 1);
    work->plttByteSize = task->plttData->byteSize;
    MIi_CpuCopy16(task->plttData->data, work->plttOriginal,
                  task->plttData->byteSize);

    if (sys->loadHook != 0) {
        if (sys->loadHook(addWork, task, sys->loadHookWork) == 1) {
            sys->loadHook = 0;
            sys->loadHookWork = 0;
        }
    }
    if (work->flags.bits.mosaic != 0) {
        MCSS_ApplyMosaic(work, task);
    }
    if (sys->taskSys != 0) {
        work->textureTask = TCB_AddTask(sys->taskSys, MCSS_TransTextureTask, task, 0);
    } else {
        work->textureTask = GFL_USE_AddMainTask(MCSS_TransTextureTask, task, 0);
    }
}

/*
 * The mcss.c rebind routine (line 0x8AB), twin of MCSS_LoadResource.  Closed
 * in wave 15 from 21 bytes out by the same declaration: the descriptor
 * parameter is const McssAddWork *, which fixes the argument load order
 * at every constructor call site.  History:
 * docs/notes/MCSS_LoadResourceShared.c.txt.
 */
void MCSS_LoadResourceShared(McssSys *sys, u32 index, const McssAddWork *addWork)
{
    McssWork *work = sys->works[index];
    void *arcHandle;
    McssTransTask *task;
    u32 flag;
    McssCellHeader *cellHeader;

    arcHandle = sys->arcHandle;
    work->flags.raw &= 0xFFFFDFFF;
    NNSi_G2dInitVramHandle((u32 *)&work->texImage);
    NNSi_G2dInitVramHandleEx((u32 *)&work->plttProxy);

    work->cellFile = ARC_UTIL_LoadCellBankFromHandle(arcHandle, addWork->cellMember, 0,
                                   &work->cellBank,
                                   (u16)work->heapId);
    work->cellAnimFile = ARC_UTIL_LoadMultiCellBankFromHandle(arcHandle, addWork->cellAnimMember, 1, &work->cellAnimBank,
                                       (u16)work->heapId);
    flag = 1;
    work->multiCellFile = ARC_UTIL_LoadAnimBankFromHandle(arcHandle, addWork->multiCellMember, 0, &work->multiCellBank,
                                        (u16)work->heapId);
    work->multiCellAnimFile = ARC_UTIL_LoadMultiAnimBankFromHandle(arcHandle, addWork->multiCellAnimMember, 0, &work->multiCellAnimBank,
                                            (u16)work->heapId);
    MCSS_SetAnimeIndex(work, 0);

    cellHeader = ARC_TOOL_LoadHandleMember(arcHandle, addWork->cellHeaderMember, (u16)work->heapId);
    work->cellHeader = cellHeader;
    work->stopCellTable = (u8 *)cellHeader + ((0x30 * cellHeader->cellCount + 0xC) & ~3u);

    task = GFL_HEAP_Alloc((u16)(((u16)work->heapId & (0xFFFFDFFFu >> 0x11)) | (flag << 0xF)),
                         0x2C, 1, sFileMcss, 0x8AB);
    task->sys = sys;
    if (sys->taskSys == 0) {
        flag = 0;
    }
    task->hasTaskSys = flag;
    task->texImageOut = &work->texImage;
    task->plttProxyOut = &work->plttProxy;
    task->texDest = sys->texTransAdrs + (index << 0xE);
    task->plttDest = sys->plttTransAdrs + (index << 5);
    task->work = work;

    task->texBuf = ARC_UTIL_LoadBgCharDataFromHandle(arcHandle, addWork->textureMember, 1, task,
                                 (u16)(((u16)work->heapId & 0x7FFF) | 0x8000));
    task->plttBuf = ARC_UTIL_LoadPaletteBlockFromHandle(arcHandle, addWork->paletteMember, &task->plttData,
                                  (u16)(((u16)work->heapId & 0x7FFF) | 0x8000));

    work->plttOriginal = GFL_HEAP_Alloc((u16)work->heapId,
                                       task->plttData->byteSize, 0,
                                       sFileMcss, 0x8C3);
    work->plttCurrent = GFL_HEAP_Alloc((u16)work->heapId,
                                      task->plttData->byteSize, 0,
                                      sFileMcss, 0x8C3 + 1);
    work->plttByteSize = task->plttData->byteSize;
    MIi_CpuCopy16(task->plttData->data, work->plttOriginal,
                  task->plttData->byteSize);

    if (sys->loadHook != 0) {
        if (sys->loadHook(addWork, task, sys->loadHookWork) == 1) {
            sys->loadHook = 0;
            sys->loadHookWork = 0;
        }
    }
    if (work->flags.bits.mosaic != 0) {
        MCSS_ApplyMosaic(work, task);
    }
    if (sys->taskSys != 0) {
        work->textureTask = TCB_AddTask(sys->taskSys, MCSS_TransTextureTask, task, 0);
    } else {
        work->textureTask = GFL_USE_AddMainTask(MCSS_TransTextureTask, task, 0);
    }
}

void MCSS_TransTextureTask(void *taskHandle, McssTransTask *task)
{
    if (task->hasTaskSys == 0) {
        u32 scanline = *(volatile u16 *)0x04000006;

        if (scanline < 0xc0 || scanline > 0xc8)
            return;
    }
    if (task->texBuf != 0) {
        NNSi_G2dLoadVramResourceSub(task->texData, task->texDest, 0, task->texImageOut);
        GFL_HEAP_Free(task->texBuf);
        if (task->work->flags.bits.mosaic == 0) {
            task->texBuf = 0;
            return;
        }
    }
    if (task->work != 0)
        task->work->flags.raw |= 0x2000;
    if (task->plttBuf != 0) {
        NNSi_G2dLoadVramResourceBySel(task->plttData, task->plttDest, 0, task->plttProxyOut);
        GFL_HEAP_Free(task->plttBuf);
    }
    if (task->work != 0)
        task->work->textureTask = 0;
    if (task->sys != 0 && task->sys->shadowPlttTask != 0)
        task->sys->shadowPlttTask = 0;
    GFL_HEAP_Free(task);
    TCB_DeleteTask(taskHandle);
}

void MCSS_TransPaletteTask(void *taskHandle, McssTransTask *task)
{
    if (task->hasTaskSys == 0) {
        u32 scanline = *(volatile u16 *)0x04000006;

        if (scanline < 0xc0 || scanline > 0xc8)
            return;
    }
    NNSi_G2dInitVramHandleEx((u32 *)task->plttProxyOut);
    NNSi_G2dLoadVramResourceBySel(task->plttData, task->plttDest, 0, task->plttProxyOut);
    if (task->work != 0) {
        if (task->work->fadeTask == taskHandle)
            task->work->fadeTask = 0;
        if (task->work->paletteTask == taskHandle)
            task->work->paletteTask = 0;
    }
    GFL_HEAP_Free(task->plttData->data);
    GFL_HEAP_Free(task->plttData);
    GFL_HEAP_Free(task);
    TCB_DeleteTask(taskHandle);
}

/*
 * A two-call registrar.  The first call is five arguments wide: the value
 * loaded from +0x14c is an `int` truncated to `u16` at the call (the listing
 * shows `ldr` + the lsls/lsrs 0x10 pair, not a `ldrh` - declaring the field
 * itself `u16` is what produces a `ldrh` and loses four bytes), and 0x970 is
 * the fifth argument on the stack.  The result is stored back into +0x98,
 * which the second call reads as its own second argument, so the field is a
 * genuine `int`.
 *
 * The pool word at 0x020169D0 is 0x020A72CC; that same word sits in eight
 * other functions' pools in this image (0x02014B9C, 0x02015B94, 0x02016240,
 * 0x02016360, 0x02016624, 0x02016870, 0x02016B84, ...), all outside the
 * compared range, which is what attests the site through the `literal` class.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/MCSS_InitAnimCtrl.c \
 *       --func MCSS_InitAnimCtrl --addr 0x02016984 --cc 1.1p1 --thumb
 */
void MCSS_InitAnimCtrl(McssWork *work, int kind)
{
    work->animWork = GFL_HEAP_Alloc((unsigned short)work->heapId,
                                   NNS_G2dGetMCWorkAreaSize(work->multiCellBank, kind),
                                   0, sFileMcss, 0x970);
    NNS_G2dInitMCAnimation(&work->animCtrl, work->animWork, work->cellAnimBank,
                  work->cellBank, work->multiCellBank, kind);
}

/*
 * A single matched function.
 *
 * alias: a direct write of a fixed 32-bit value to a hardware register pair
 * at 0x040004C0: the low word gets the full constant, the high word (at
 * +4) gets its upper halfword. This is a raw I/O register store, not an
 * SDK call, which is why it is game code sitting on hardware address space.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/unit_020169D4.c \
 *       --func MCSS_InitEdgeColor --addr 0x020169D4 --cc 1.1p1 --thumb
 */
void MCSS_InitEdgeColor(void)
{
    u32 v = 0x4210FFFF;
    *(volatile u32 *)0x040004C0 = v;
    *(volatile u32 *)0x040004C4 = v >> 16;
}

/*
 * Closed in the second pass (2026-09-22) from the 4-byte near miss in
 * docs/notes/MCSS_UpdatePaletteFade.c.txt.  The residue was NOT the pool-word
 * shape that note predicted; it was two misreadings of the image:
 *
 *   1. the flag mask is 0xFFFFEFFF (bit 12), not 0xEFFFFFFF (bit 28).
 *      The pool word at 0x02016B94 is `ff ef ff ff`.  Fixing it alone
 *      took the diff from 4 concrete bytes to 2.
 *   2. the second clamp reads +0x135 / +0x134, not +0x137 / +0x136.
 *      The `ldr r0,[pc,#0x3c]` at 0x02016B58 resolves to 0x02016B98,
 *      the SECOND pool word (0x135), while the `ldr r0,[pc,#0x30]` at
 *      0x02016B6A resolves to 0x02016B9C, the THIRD (0x137).  Reading
 *      both as 0x137 is what made the 0x135 pool word disappear and the
 *      function come out 436 bytes instead of 440.  The missing pool
 *      word was a symptom, not the cause.
 *
 * Verified with:
 *   python3 tools/match.py one --src src/matched/MCSS_UpdatePaletteFade.c \
 *       --func MCSS_UpdatePaletteFade --addr 0x020169E8 --cc 1.1p1 --thumb
 */
void MCSS_UpdatePaletteFade(McssSys *sys, McssWork *work)
{
    McssTransTask *task;
    u32 flag;
    void *handle;
    s32 step;
    s8 cur;
    s8 target;

    if (work->fadeWait != 0) {
        goto dec;
    }

    flag = 1;
    task = GFL_HEAP_Alloc((u16)(((u16)work->heapId & 0x7FFF) | 0x8000), 0x2C, 1, sFileMcss, 0x9A1);
    task->sys = sys;
    if (sys->taskSys == 0) {
        flag = 0;
    }
    task->hasTaskSys = flag;
    task->work = work;
    task->plttProxyOut = &work->plttProxy;
    task->plttDest = sys->plttTransAdrs + (work->index << 5);

    flag = 0;
    task->plttData = GFL_HEAP_Alloc((u16)(((u16)work->heapId & 0x7FFF) | 0x8000), 0x10, 0, sFileMcss, 0x9A9);
    task->plttData->fmt = work->plttProxy.fmt;
    task->plttData->extended = flag;
    task->plttData->byteSize = work->plttByteSize;
    task->plttData->data = GFL_HEAP_Alloc((u16)(((u16)work->heapId & 0x7FFF) | 0x8000), work->plttByteSize, 0, sFileMcss, 0x9A9 + 5);

    if (work->flags.bits.plttCurrentValid) {
        PALANM_BlendColors(work->plttCurrent, task->plttData->data, ((s32)work->plttByteSize / 2), *(u8 *)&work->fadeStart, (u16)work->fadeColor);
    } else {
        PALANM_BlendColors(work->plttOriginal, task->plttData->data, ((s32)work->plttByteSize / 2), *(u8 *)&work->fadeStart, (u16)work->fadeColor);
    }

    if (work->fadeTask != 0) {
        MCSS_DeletePaletteTask(work->fadeTask);
        work->fadeTask = 0;
    }

    if (sys->taskSys != 0) {
        handle = TCB_AddTask(sys->taskSys, MCSS_TransPaletteTask, task, 0);
    } else {
        handle = GFL_USE_AddMainTask(MCSS_TransPaletteTask, task, 0);
    }
    work->fadeTask = handle;

    cur = work->fadeStart;
    target = work->fadeEnd;
    if (cur == target) {
        work->flags.raw &= 0xFFFFEFFF;
    } else {
        step = work->fadeStep;
        work->fadeStart = (s8)(cur + (s8)step);
        if (step < 0 || work->fadeStart < target) {
            if (step < 0) {
                target = work->fadeEnd;
                if (work->fadeStart > target) {
                    goto done;
                }
            } else {
                goto done;
            }
        }
        work->fadeStart = target;
    }
done:
    work->fadeWait = work->fadeWaitSet;
    return;
dec:
    work->fadeWait = work->fadeWait - 1;
}

/*
 * A whole translation unit, matched as one byte range.
 *
 * alias: a teardown chain on the same object class as unit_02015BA4.c.
 * MCSS_FreeResource releases eight pointer fields of the object through
 * GFL_HEAP_Free (a generic release call reached by blx, so it is ARM),
 * zeroes three of them (+0x98, +0xd4, +0xd8, all past the immediate str
 * reach so the compiler adds the offset into a register first), then
 * zeroes the other four (+0xc, +0x1c, +0x14, +0x24, +0x2c) and, if the
 * object's own field at +0 is non-zero, recurses into MCSS_DeleteTextureTask with
 * that field's value before zeroing it too. MCSS_DeleteTextureTask turns an id into
 * an object through TCBL_GetTaskUserData, releases one or two of the object's own
 * pointer fields the same way, releases the object itself, and finally
 * releases the id through TCB_DeleteTask.
 *
 * The immediate follower, MCSS_DeletePaletteTask (38 bytes, same shape over a third
 * field, one level of extra indirection), is a documented near miss: this
 * front end assigns it only two callee-saved registers (padding a filler
 * into r3) where the original spends three (r4, r5, r6), so the second
 * fetch of the inner pointer is a register move here and a reload from
 * memory in every source shape tried. Left out rather than forced.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02016BA0.c \
 *       --addr 0x02016BA0 --thumb
 */
void MCSS_FreeResource(McssWork *work)
{
    GFL_HEAP_Free(work->cellFile);
    GFL_HEAP_Free(work->cellAnimFile);
    GFL_HEAP_Free(work->multiCellFile);
    GFL_HEAP_Free(work->multiCellAnimFile);
    GFL_HEAP_Free(work->animWork);
    GFL_HEAP_Free(work->cellHeader);
    GFL_HEAP_Free(work->plttOriginal);
    GFL_HEAP_Free(work->plttCurrent);

    work->animWork = 0;
    work->plttOriginal = 0;
    work->plttCurrent = 0;

    {
        void *task = work->textureTask;
        work->cellFile = 0;
        work->cellAnimFile = 0;
        work->multiCellFile = 0;
        work->multiCellAnimFile = 0;
        work->cellHeader = 0;
        if (task != 0) {
            MCSS_DeleteTextureTask(task);
            work->textureTask = 0;
        }
    }
}

void MCSS_DeleteTextureTask(void *taskHandle)
{
    McssTransTask *task = TCBL_GetTaskUserData(taskHandle);

    if (task->texBuf != 0) {
        GFL_HEAP_Free(task->texBuf);
    }
    if (task->plttBuf != 0) {
        GFL_HEAP_Free(task->plttBuf);
    }
    GFL_HEAP_Free(task);
    TCB_DeleteTask(taskHandle);
}

void MCSS_DeletePaletteTask(void *taskHandle)
{
    McssTransTask *task = TCBL_GetTaskUserData(taskHandle);
    GFL_HEAP_Free(task->plttData->data);
    GFL_HEAP_Free(task->plttData);
    GFL_HEAP_Free(task);
    TCB_DeleteTask(taskHandle);
}

/*
 * mcss.c, the two-pass nibble fill over the 0x30-byte cell records of work->cellHeader.
 * EXACT* (870 bytes; the 872-byte listing extent carries 2 pad bytes).
 * Closed in wave 21 (lane B2) from 16 bytes out.  The lever is eyeW: it is
 * read raw into the guard (`eyeW = rec->eye.w; if (eyeW != 0)`) and shifted
 * later (`eyeW >>= 12;`), and the pass-2 header follows pass 1's order,
 * eyeS, eyeT, eyeW, eyeH, then `eyeBlockRow = 0; blockY = 0;`.  The raw eyeW web spans the
 * eyeS/eyeT reads and is coloured before the record pointer, which puts
 * the pointer in r1 and both zeros in r0, as the image has them.
 * History: docs/notes/pkt_02016C60.c.txt.
 */
void MCSS_ApplyMosaic(McssWork *work, McssTransTask *task)
{
  s32 rowBytes;
  u8 *pixels;
  s32 cellIdx;
  s32 bodyS;
  s32 bodyT;
  s32 bodyW;
  s32 bodyH;
  s32 blockSize;
  s32 fillLow;
  s32 colorIdx;
  s32 blockX;
  s32 blockY;
  s32 blockRow;
  s32 blockCol;
  s32 eyeS;
  s32 eyeT;
  s32 eyeW;
  s32 eyeH;
  s32 eyeBlockRow;
  s32 eyeBlockCol;
  s32 blockW;
  s32 blockH;
  s32 row;
  s32 col;
  s32 byteOfs;
  s32 texX;
  s32 texel;
  s32 fillY;
  s32 eyeFillY;
  s32 searchY;
  s32 fillYBase;
  s32 eyeFillYBase;
  s32 eyeSearchY;
  s32 fillXBase;
  if (work->texImage.fmt != 3)
  {
    return;
  }
  rowBytes = _d2s(pow(2.0, _s32_to_double(work->texImage.sizeS + 2)));
  pixels = task->texData->rawData;
  cellIdx = 0;
  while (((u32) cellIdx) < work->cellHeader->cellCount)
  {
    bodyS = work->cellHeader->cells[cellIdx].body.s >> 12;
    bodyT = work->cellHeader->cells[cellIdx].body.t >> 12;
    bodyW = work->cellHeader->cells[cellIdx].body.w >> 12;
    bodyH = work->cellHeader->cells[cellIdx].body.h >> 12;
    blockSize = ((s32) work->flags.bits.mosaic) + 1;
    blockRow = 0;
    blockY = 0;
    if (bodyH > 0)
    {
      do
      {
        for (blockCol = 0, blockX = 0; blockX < bodyW; blockCol++, blockX += blockSize)
        {
          {
            s32 fillHigh;
            if ((blockX + blockSize) > bodyW)
            {
              blockW = bodyW - (blockSize * blockCol);
            }
            else
            {
              blockW = blockSize;
            }
            if ((blockY + blockSize) > bodyH)
            {
              blockH = bodyH - (blockSize * blockRow);
            }
            else
            {
              blockH = blockSize;
            }
            colorIdx = 0;
            for (row = 0; row < blockH; row++)
            {
              for (col = 0; col < blockW; col++)
              {
                texX = (bodyS + blockX) + col;
                searchY = (bodyT + blockY) + row;
                byteOfs = (texX / 2) + (searchY * rowBytes);
                if (col & 1)
                {
                  texel = (pixels[byteOfs] & 0xf0) >> 4;
                }
                else
                {
                  texel = pixels[byteOfs] & 0x0f;
                }
                if (texel != 0)
                {
                  colorIdx = texel;
                  break;
                }
              }

              if (colorIdx != 0)
              {
                break;
              }
            }

            fillLow = (u8) colorIdx;
            fillHigh = fillLow << 4;
            for (row = 0; row < blockH; row++)
            {
              for (col = 0; col < blockW; col++)
              {
                fillXBase = bodyS + blockX;
                texX = fillXBase + col;
                fillYBase = bodyT + blockY;
                fillY = fillYBase + row;
                byteOfs = (texX / 2) + (fillY * rowBytes);
                if (byteOfs < (1 << 14))
                {
                  if (texX & 1)
                  {
                    pixels[byteOfs] = (pixels[byteOfs] & 0x0f) | fillHigh;
                  }
                  else
                  {
                    pixels[byteOfs] = (pixels[byteOfs] & 0xf0) | fillLow;
                  }
                }
              }

            }

          }
        }

        blockRow++;
        blockY += blockSize;
      }
      while (blockY < bodyH);
    }
    eyeW = work->cellHeader->cells[cellIdx].eye.w;
    if (eyeW != 0)
    {
      eyeS = work->cellHeader->cells[cellIdx].eye.s >> 12;
      eyeT = work->cellHeader->cells[cellIdx].eye.t >> 12;
      eyeW >>= 12;
      eyeH = (work->cellHeader->cells[cellIdx].eye.h >> 12) << 1;
      eyeBlockRow = 0;
      blockY = 0;
      if (eyeH > 0)
      {
        do
        {
          for (eyeBlockCol = 0, blockX = 0; blockX < eyeW; eyeBlockCol++, blockX += blockSize)
          {
            {
              s32 eyeFillHigh;
              if ((blockX + blockSize) > eyeW)
              {
                blockW = eyeW - (blockSize * eyeBlockCol);
              }
              else
              {
                blockW = blockSize;
              }
              if ((blockY + blockSize) > eyeH)
              {
                blockH = eyeH - (blockSize * eyeBlockRow);
              }
              else
              {
                blockH = blockSize;
              }
              colorIdx = 0;
              for (row = 0; row < blockH; row++)
              {
                for (col = 0; col < blockW; col++)
                {
                  texX = (eyeS + blockX) + col;
                  eyeSearchY = (eyeT + blockY) + row;
                  byteOfs = (texX / 2) + (eyeSearchY * rowBytes);
                  if (col & 1)
                  {
                    texel = (pixels[byteOfs] & 0xf0) >> 4;
                  }
                  else
                  {
                    texel = pixels[byteOfs] & 0x0f;
                  }
                  if (texel != 0)
                  {
                    colorIdx = texel;
                    break;
                  }
                }

                if (colorIdx != 0)
                {
                  break;
                }
              }

              fillLow = (u8) colorIdx;
              eyeFillHigh = fillLow << 4;
              for (row = 0; row < blockH; row++)
              {
                for (col = 0; col < blockW; col++)
                {
                  texX = eyeS + blockX;
                  texX = texX + col;
                  eyeFillYBase = eyeT + blockY;
                  eyeFillY = eyeFillYBase + row;
                  byteOfs = (texX / 2) + (eyeFillY * rowBytes);
                  if (byteOfs < (1 << 14))
                  {
                    if (texX & 1)
                    {
                      pixels[byteOfs] = (pixels[byteOfs] & 0x0f) | eyeFillHigh;
                    }
                    else
                    {
                      pixels[byteOfs] = (pixels[byteOfs] & 0xf0) | fillLow;
                    }
                  }
                }

              }

            }
          }

          eyeBlockRow++;
          blockY += blockSize;
        }
        while (blockY < eyeH);
      }
    }
    cellIdx++;
  }

}

/*
 * 310 bytes, one function, and two bytes of linker fill after it before the
 * next function at 0x02017100; the range this entry owns is 0x02016FC8 plus
 * 310, which is why it is written as a unit rather than as a single function
 * entry (`match.py one` measures the extent to the next label, sees 312 and
 * reports EXACT* over two bytes the compiler never emitted).
 *
 * The 4x4 fixed-point transform of a three-component vector: the ordinary
 * Nitro row-vector convention, out = v * M with the translation row added
 * afterwards, computed in 64 bit and shifted back down by the 12 fractional
 * bits at the end of each component.  The fourth component does not go into
 * the destination vector; it is written through a separate `s32 *`, which is
 * what makes this the projection form rather than MTX_MultVec: the caller
 * gets x, y, z and w separately and divides by w itself.
 *
 *   dst->x = (s32)((vx * m[0][0] + vy * m[1][0] + vz * m[2][0]) >> 12)
 *            + m[3][0];        and the same for columns 1, 2 and 3
 *
 * Every product is a call to the compiler's 64 bit multiply helper at
 * 0x0209C054, twelve of them, and the `asrs rN, rM, #0x1f` in front of each
 * operand is the sign extension an `s32` costs on the way to `long long`; see
 * docs/idioms/consecutive-ll-udiv-calls-are-one-chained-64-bit-expression.md
 * for the same family of helpers seen from the division side.  The name the
 * relocation carries is `_ll_mul`, not `_ull_mul`: both spellings name the
 * same routine at 0x0209C054 (`umull` plus two `mla` is correct for either
 * signedness), and which one mwccarm emits follows the signedness of the
 * operands, so `src/matched/unit_020056A0.c` pins the same address under the
 * other name.  The helper's contract is r0:r1 and r2:r3 in, r0:r1 out.
 *
 * The 64 bit shift is not a call.  `lsls r0, rHi, #0x14` / `lsrs r1, rLo, #0xc`
 * / `orrs r1, r0` is the low word of a `>> 12` on a 64 bit value with the high
 * word dead, which is what the cast back to `s32` makes of it; the shift of
 * the low half is `lsrs` and not `asrs` whatever the sign of the value,
 * because it is a bit-field splice and not an arithmetic shift.
 *
 * ---------------------------------------------------------------------------
 * WHAT COST THE TIME
 * ---------------------------------------------------------------------------
 * **The shifted product needs a named local, or the translation row is loaded
 * ten bytes too early.**  Written as one expression,
 *
 *     dst->x = (s32)((...) >> 12) + mtx->m[3][0];
 *
 * the compiler loads `mtx->m[3][0]` before the last two adds of the 64 bit
 * accumulation, which then needs two register copies to get the helper's
 * result out of r0:r1; the function grows twelve bytes and 248 concrete bytes
 * differ, all of them scheduling.  Splitting the statement,
 *
 *     r = (s32)((...) >> 12);
 *     dst->x = r + mtx->m[3][0];
 *
 * is EXACT.  Holding the 64 bit sum in an `s64` local instead and casting at
 * the store is byte-identical, so the image does not say which of the two the
 * source wrote, only that it was not one expression.
 *
 * **The three vector components are read into locals, and the sign extension
 * is what they are read for.**  `v` is `const` and `dst` is not, so a store
 * through `dst` may alias `v`; written as `v->x` inside all twelve products
 * the compiler reloads and re-extends each component for every output and
 * comes out four bytes short with the whole body rescheduled.  Three `s32`
 * locals assigned at the top make the six words of sign-extended vector one
 * CSE that lives on the stack at sp+4 through sp+0x18 for the whole function,
 * which is the original's frame.  The same three values held as `s64` locals
 * are twelve bytes longer, so the source's locals are 32 bit and the cast is
 * at the multiply.
 *
 * Nothing here is version specific: every constant is a matrix offset or the
 * fixed-point shift.
 *
 * Verified with
 *   python tools/match.py tu --src src/matched/unit_02016FC8.c  *       --addr 0x02016FC8 --thumb
 */
void MCSS_MulVecMtx44(const VecFx32 *v, const MtxFx44 *mtx,
                   VecFx32 *dst, s32 *w)
{
    s32 vx;
    s32 vy;
    s32 vz;
    s32 r;

    vx = v->x;
    vy = v->y;
    vz = v->z;

    r = (s32)(((s64)vx * mtx->m[0][0] + (s64)vy * mtx->m[1][0]
                    + (s64)vz * mtx->m[2][0]) >> 12);
    dst->x = r + mtx->m[3][0];
    r = (s32)(((s64)vx * mtx->m[0][1] + (s64)vy * mtx->m[1][1]
                    + (s64)vz * mtx->m[2][1]) >> 12);
    dst->y = r + mtx->m[3][1];
    r = (s32)(((s64)vx * mtx->m[0][2] + (s64)vy * mtx->m[1][2]
                    + (s64)vz * mtx->m[2][2]) >> 12);
    dst->z = r + mtx->m[3][2];
    r = (s32)(((s64)vx * mtx->m[0][3] + (s64)vy * mtx->m[1][3]
                    + (s64)vz * mtx->m[2][3]) >> 12);
    *w = r + mtx->m[3][3];
}

/*
 * The first of two parallel fillers of the same nine word record.
 * MCSS_TOOL_MakeAddWorkFromParam builds it from the five values MCSS_TOOL_MakeAddWorkFromPPP reads out of the
 * save block and writes 0 into the last word; its twin at 0x02017214 builds
 * the same record from a pair of pointers and writes 1, so that word is the
 * tag saying which of the two produced it.  The twin is parked in
 * src/pending/unit_02017214.c: it is the only caller of six of its eight
 * callees.
 *
 * MCSS_TOOL_MakeAddWorkFromPP passes its first argument through POKE_TOOL_GetBoxParam rather than
 * holding it in a callee-saved register, which is only possible because that
 * function returns its argument: it is the two byte `bx lr` at 0x020185F4 that
 * src/matched/unit_020185F0.c matches as an empty hook.  Written as a void
 * call followed by MCSS_TOOL_MakeAddWorkFromPPP(p, ...) the first argument would have to be
 * saved across it and the function grows a register.
 */
void MCSS_TOOL_MakeAddWorkFromPP(void *pp, McssAddWork *out, u32 direction)
{
    MCSS_TOOL_MakeAddWorkFromPPP(POKE_TOOL_GetBoxParam(pp), out, direction);
}

void MCSS_TOOL_MakeAddWorkFromPPP(void *pokemon, McssAddWork *out, u32 direction)
{
    u32 species = POKE_TOOL_GetBoxValue(pokemon, 5, 0);
    u32 form = POKE_TOOL_GetBoxValue(pokemon, 0x6F, 0);
    u32 gender = POKE_TOOL_GetBoxValue(pokemon, 0x6E, 0);
    u32 isShiny = POKE_TOOL_IsBoxShiny(pokemon);
    u32 isEgg = POKE_TOOL_GetBoxValue(pokemon, 0x4C, 0);

    MCSS_TOOL_MakeAddWorkFromParam(species, form, gender, isShiny, isEgg, out, direction);
}

void MCSS_TOOL_MakeAddWorkFromParam(u32 species, u32 form, u32 gender, u32 isShiny, u32 isEgg, McssAddWork *out,
                   u32 direction)
{
    out->arcId = POKEGRA_GetArcID();
    out->textureMember = POKEGRA_GetCbrArcIndex(out->arcId, species, form, gender, isShiny, direction, isEgg);
    out->paletteMember = POKEGRA_GetPalArcIndex(out->arcId, species, form, gender, isShiny, direction, isEgg);
    out->cellMember = POKEGRA_GetCelArcIndex(out->arcId, species, form, gender, isShiny, direction, isEgg);
    out->cellAnimMember = POKEGRA_GetAnmArcIndex(out->arcId, species, form, gender, isShiny, direction, isEgg);
    out->multiCellMember = POKEGRA_GetMCelArcIndex(out->arcId, species, form, gender, isShiny, direction, isEgg);
    out->multiCellAnimMember = POKEGRA_GetMAnmArcIndex(out->arcId, species, form, gender, isShiny, direction, isEgg);
    out->cellHeaderMember = POKEGRA_GetNcecArcIndex(out->arcId, species, form, gender, isShiny, direction, isEgg);
    out->heapMode = 0;
}

/*
 * Promoted from src/pending/ during a shard verify sweep: all six of its
 * previously witness-less callees (POKEGRA_GetTrainerCbrArcIndex, POKEGRA_GetTrainerCelArcIndex,
 * POKEGRA_GetTrainerAnmArcIndex, POKEGRA_GetTrainerMCelArcIndex, POKEGRA_GetTrainerMAnmArcIndex, POKEGRA_GetTrainerNcecArcIndex) are now
 * EXACT matched entries elsewhere in the tree, so the `matched` class
 * resolves every site that was stuck wildcarded and this closes to
 * EXACT with no change to the C.
 *
 * This is the twin of MCSS_TOOL_MakeAddWorkFromParam in src/matched/unit_02017100.c: the
 * same nine word record, built from a pair of pointers instead of from
 * five save block fields, with 1 in the last word where the other
 * writes 0.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02017214.c \
 *       --addr 0x02017214 --thumb
 */
void MCSS_TOOL_MakeAddWorkFromTrainer(void *trainerClass, McssAddWork *out, void *trainerGender)
{
    out->arcId = POKEGRA_GetTrainerArcID((u32)trainerGender);
    out->textureMember = POKEGRA_GetTrainerCbrArcIndex((u32)trainerClass, (u32)trainerGender);
    out->paletteMember = POKEGRA_GetTrainerPalArcIndex((u32)trainerClass, (u32)trainerGender);
    out->cellMember = POKEGRA_GetTrainerCelArcIndex((u32)trainerClass, (u32)trainerGender);
    out->cellAnimMember = POKEGRA_GetTrainerAnmArcIndex((u32)trainerClass, (u32)trainerGender);
    out->multiCellMember = POKEGRA_GetTrainerMCelArcIndex((u32)trainerClass, (u32)trainerGender);
    out->multiCellAnimMember = POKEGRA_GetTrainerMAnmArcIndex((u32)trainerClass, (u32)trainerGender);
    out->cellHeaderMember = POKEGRA_GetTrainerNcecArcIndex((u32)trainerClass, (u32)trainerGender);
    out->heapMode = 1;
}

/*
 * Verified with:
 *   python tools/match.py one --src src/matched/MCSS_TOOL_AddPokeMcss.c \
 *       --func MCSS_TOOL_AddPokeMcss --addr 0x02017270 --cc 1.1p1 --thumb
 */
McssWork *MCSS_TOOL_AddPokeMcss(McssSys *sys, void *pp, u32 direction, fx32 x, fx32 y, fx32 z)
{
    McssAddWork addWork;

    MCSS_TOOL_SetSpindaSpotHook(sys, POKE_TOOL_GetPartyValue(pp, 0, 0));
    MCSS_TOOL_MakeAddWorkFromPP(pp, &addWork, direction);
    return MCSS_Add(sys, x, y, z, &addWork);
}

/*
 * A four-instruction tail call: the second argument is replaced by a function
 * pointer (the pool word 0x020172BD, the Thumb bit set), the first and third
 * pass through, and the target is loaded from the pool and branched to with
 * `bx r3`.  The callee is the label-less Thumb leaf src/matched/MCSS_SetLoadHook.c.
 *
 * The `symbols:` line is load-bearing.  Without it the name `MCSS_SetLoadHook`
 * carries the address but the naming convention can only guess the ISA, and
 * an address no `func_` label was traced at is guessed ARM -- so the site
 * was reported as "02014CF0 (arm, from name) has no witness" and the file sat
 * at MATCH, because MCSS_SetLoadHook is a Thumb manifest entry and the `matched`
 * class refuses an ISA that does not agree with it.  Declaring the ISA
 * explicitly (origin "header") resolves the word to 0x02014CF1, which is what
 * the image holds.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/MCSS_TOOL_SetSpindaSpotHook.c \
 *       --func MCSS_TOOL_SetSpindaSpotHook --addr 0x020172AC --cc 1.1p1 --thumb
 */
void MCSS_TOOL_SetSpindaSpotHook(McssSys *sys, u32 personality)
{
    MCSS_SetLoadHook(sys, MCSS_TOOL_SpindaSpotHook, personality);
}

/*
 * Verified with:
 *   python tools/match.py one --src src/matched/MCSS_TOOL_SpindaSpotHook.c \
 *       --func MCSS_TOOL_SpindaSpotHook --addr 0x020172BC --cc 1.1p1 --thumb
 */
u32 MCSS_TOOL_SpindaSpotHook(const McssAddWork *addWork, McssTransTask *task, u32 personality)
{
    if (addWork->cellHeaderMember == 0x1994) {
        MCSS_TOOL_DrawSpindaSpots(task->texData->rawData, personality);
    }
    return 1;
}

/*
 * mcss.c.  Walks four (x, y) offset lists and bumps the matching nibble of
 * two bytes per point.  Lever (wave 16): the read-modify-write of a0[p] is a
 * compound assignment `a0[p] += 0x50` / `a0[p] += 5`; the spelled-out
 * `a0[p] = (u8)(val + 0x50)` left a three-register rotation (a0/k/b0, 47
 * bytes out) that no declaration order, scope, type or permuter run moved.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/MCSS_TOOL_DrawSpindaSpots.c \
 *       --func MCSS_TOOL_DrawSpindaSpots --addr 0x020172D8 --cc 1.1p1 --thumb
 */
void MCSS_TOOL_DrawSpindaSpots(u8 *pixels, u32 personality)
{
    const u8 *spotTable;
    s32 spotSet;
    s32 spotIdx;
    s32 spotOfs[2];

    for (spotSet = 0; spotSet < 4; spotSet++) {
        spotTable = sSpindaSpotCoords[spotSet];
        spotIdx = 0;
        if (spotTable[0] != 0xff) {
            spotOfs[1] = (personality & 0xf) - 8;
            spotOfs[0] = ((personality & 0xf0) >> 4) - 8;
            do {
                u8 spotX = (u8)(spotOfs[1] + spotTable[spotIdx * 2]);
                u32 spotY = (u8)(spotOfs[0] + spotTable[spotIdx * 2 + 1]);
                u32 pixelIdx[2];
                s32 half;
                pixelIdx[0] = ((u32)spotX >> 1) + (spotY << 7);
                pixelIdx[1] = ((u32)spotX >> 1) + ((spotY + 0x28) << 7);
                for (half = 0; half < 2; half++) {
                    if ((spotX & 1) != 0) {
                        u32 pixelOfs = pixelIdx[half];
                        u8 pixel = pixels[pixelOfs];
                        s32 nibble = pixel & 0xf0;
                        if (nibble >= 0x10 && nibble <= 0x30) {
                            pixels[pixelOfs] += 0x50;
                        }
                    } else {
                        u32 pixelOfs = pixelIdx[half];
                        u8 pixel = pixels[pixelOfs];
                        s32 nibble = 0xf & pixel;
                        if (nibble >= 1 && nibble <= 3) {
                            pixels[pixelOfs] += 5;
                        }
                    }
                }
                spotIdx = (u8)(spotIdx + 1);
            } while (spotTable[spotIdx * 2] != 0xff);
        }
        personality = personality >> 8;
    }
}

int MCSS_TOOL_SetAnimeStopCallback(McssWork *work){ int ret = MCSS_SetAnimCallback(work, (u32)(work + 0), (u32)0x20173C9, (u32)1); return ret; }

/*
 * A four-byte tail call: the pool word 0x02016381 (Thumb) is loaded and
 * `bx r3` jumps with the incoming r0 untouched, i.e. MCSS_RequestAnimeStopAtStart itself.
 * Its witness is the EXACT entry for 0x02016380 in this same shard - the
 * `matched` class - which is what makes the pool word resolve.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/MCSS_TOOL_AnimeStopCallback.c \
 *       --func MCSS_TOOL_AnimeStopCallback --addr 0x020173C8 --cc 1.1p1 --thumb
 */
void MCSS_TOOL_AnimeStopCallback(McssWork *work)
{
    MCSS_RequestAnimeStopAtStart(work);
}
