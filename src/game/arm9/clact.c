/*
 * file:     clact.c
 * unit:     yes
 * function: CLACT_InitSystem, CLACT_ExitSystem, CLACT_DrawSystem, CLACT_VBlankSystem, CLACT_FlushOamIfPending, CLACT_RegisterCharacter, CLACT_RegisterEmptyCharacter, CLACT_ReleaseCharacter, CLACT_TransferCharacter, CLACT_TransferCharacterPart, CLACT_GetCharacterProxy, CLACT_GetCharacterVramAddress, CLACT_RegisterPalette, CLACT_RegisterPaletteEx, CLACT_RegisterPaletteCompressed, CLACT_ReleasePalette, CLACT_TransferPalette, CLACT_GetPaletteProxy, CLACT_GetPaletteVramAddress, CLACT_RegisterCellAnim, CLACT_ReleaseCellAnim, CLACT_CreateRenderer, CLACT_DeleteRenderer, CLACT_SetSurfacePos, CLACT_GetSurfacePos, CLACT_SetRendererCulling, CLACT_CreateUnit, CLACT_DeleteUnit, CLACT_SetUnitDrawEnable, CLACT_GetUnitDrawEnable, CLACT_SetUnitRenderer, CLACT_SetUnitDefaultRenderer, CLACT_CreateActor, CLACT_CreateAffineActor, CLACT_DeleteActor, CLACT_SetActorDrawEnable, CLACT_GetActorDrawEnable, CLACT_AddActorSurfacePos, CLACT_GetActorSurfacePos, CLACT_SetActorSurfacePosAxis, CLACT_GetActorSurfacePosAxis, CLACT_SetActorPos, CLACT_GetActorPos, CLACT_SetActorPosAxis, CLACT_GetActorPosAxis, CLACT_SetActorAffineMode, CLACT_SetActorAffineOrigin, CLACT_SetActorAffineOriginAxis, CLACT_SetActorScale, CLACT_GetActorScale, CLACT_SetActorScaleAxis, CLACT_GetActorScaleAxis, CLACT_SetActorRotation, CLACT_GetActorRotation, CLACT_SetActorFlip, CLACT_GetActorFlip, CLACT_SetActorObjMode, CLACT_GetActorObjMode, CLACT_SetActorPaletteOffset, CLACT_GetActorPaletteOffset, CLACT_SetActorPaletteProxy, CLACT_GetActorPaletteProxy, CLACT_SetActorImageProxy, CLACT_GetActorImageProxy, CLACT_GetActorCharacterIndex, CLACT_GetActorPaletteIndex, CLACT_SetActorDrawPriority, CLACT_GetActorDrawPriority, CLACT_SetActorBgPriority, CLACT_GetActorBgPriority, CLACT_SetActorAnimSeq, CLACT_GetActorAnimSeq, CLACT_ChangeActorAnimSeq, CLACT_SetActorAnimFrame, CLACT_AddActorAnimFrame, CLACT_GetActorAnimFrame, CLACT_SetActorAnimIndex, CLACT_GetActorAnimSeqCount, CLACT_SetActorAutoAnim, CLACT_GetActorAutoAnim, CLACT_SetActorAutoAnimSpeed, CLACT_StartActorAnim, CLACT_StopActorAnim, CLACT_IsActorAnimActive, CLACT_RestartActorAnim, CLACT_SetActorAnimLoopCount, CLACT_ApplyActorAnimCommand, CLACT_ResetActorAnimCommand, CLACT_SetActorVisible, CLACT_InitDefaultRenderer, CLACT_SetPaletteBaseOffsets, CLACT_SetSystemActive, CLACT_IsSystemActive, CLACT_SetOamPending, CLACT_IsOamPending, CLACT_ResetOamIfPending, CLACT_DrawAllUnits, CLACT_LinkUnit, CLACT_UnlinkUnit, CLACT_InitOamManagers, CLACT_ExitOamManagers, CLACT_ApplyOamManagers, CLACT_ResetOamManagers, CLACT_InitOamManager, CLACT_ApplyOamManager, CLACT_ResetOamManager, CLACT_InitRenderer, CLACT_ExitRenderer, CLACT_SetSurfaceCulling, CLACT_InitSurface, CLACT_SetSurfaceType, CLACT_EntryOam, CLACT_EntryOamMain, CLACT_EntryOamSub, CLACT_EntryAffineMain, CLACT_EntryAffineSub, CLACT_IsAffineCellInView, CLACT_IsCellInView, CLACT_CullOam, CLACT_IsRectInView, CLACT_InitTransferPool, CLACT_ExitTransferPool, CLACT_AllocTransferEntries, CLACT_FreeTransferEntries, CLACT_ExecuteTransfers, CLACT_GetFreeTransferEntry, CLACT_RequestTransfer, CLACT_SetTransferEntry, CLACT_ExecuteTransfer, CLACT_GetFreeActor, CLACT_DrawUnit, CLACT_LinkActor, CLACT_UnlinkActor, CLACT_FindActorBefore, CLACT_FindActorAfter, CLACT_ClearActor, CLACT_DrawActor, CLACT_SetupActorDraw, CLACT_ApplyActorTransform, CLACT_UpdateActorAutoAnim, CLACT_ApplyActorInit, CLACT_ApplyActorResources, CLACT_GetSurfaceOrigin, CLACT_InitActorRequest, CLACT_CreateActorCore, CLACT_CreateActorFull, CLACT_InitAnimCtl, CLACT_ExitAnimCtl, CLACT_GetAnimCtlKind, CLACT_InitCellAnimCtl, CLACT_InitMultiCellAnimCtl, CLACT_InitVramAnimCtl, CLACT_ExitCellAnimCtl, CLACT_ExitMultiCellAnimCtl, CLACT_ExitVramAnimCtl, CLACT_SetAnimSeq, CLACT_SetCellAnimSeq, CLACT_SetMultiCellAnimSeq, CLACT_SetVramAnimSeq, CLACT_SetAnimFrame, CLACT_AddAnimFrame, CLACT_AddCellAnimFrame, CLACT_AddMultiCellAnimFrame, CLACT_AddVramAnimFrame, CLACT_GetAnimCtrl, CLACT_GetCellAnimCtrl, CLACT_GetMultiCellAnimCtrl, CLACT_GetVramAnimCtrl, CLACT_GetAnimObject, CLACT_GetCellAnimObject, CLACT_GetMultiCellAnimObject, CLACT_GetVramAnimObject, CLACT_SetAnimIndex, CLACT_SetVramAnimIndex, CLACT_SetAnimSpeed, CLACT_SetVramAnimSpeed, CLACT_SetCellAnimIndex, CLACT_SetMultiCellAnimIndex, CLACT_SetCellAnimSpeed, CLACT_SetMultiCellAnimSpeed, CLACT_ResetAnim, CLACT_ResetCellAnim, CLACT_ResetMultiCellAnim, CLACT_ResetVramAnim, CLACT_GetCellUserAttr, CLACT_GetMultiCellUserAttr, CLACT_GetVramCellUserAttr, CLACT_GetCellUserAttrTable, CLACT_GetMultiCellUserAttrTable, CLACT_GetVramCellUserAttrTable, CLACT_GetCellBankCount, CLACT_GetMultiCellBankCount, CLACT_GetVramCellBankCount, CLACT_ApplyAnimCommand, CLACT_ResetAnimCommand, CLACT_InitResources, CLACT_ExitResources, CLACT_IsVramTypeCompatible, CLACT_LoadArchiveData, CLACT_AllocCharacterTable, CLACT_SetupCharacterVram, CLACT_FreeCharacterTable, CLACT_UpdateObjMapping, CLACT_AllocPaletteTable, CLACT_TransferPaletteData, CLACT_TransferPaletteDataEx, CLACT_FreePaletteTable, CLACT_AllocCellAnimTable, CLACT_LoadCellAnimBanks, CLACT_FreeCellAnimTable, CLACT_SetupCharacter
 * address:  0x0204A48C
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   g_ClactSystem     0x02146A74  data
 *   s_clact_c      0x020A7F74  data
 *   GFL_HEAP_Alloc   0x02030734  arm
 *   GFL_HEAP_Free   0x020307B0  arm
 *   NNS_G2dUpdateCellTransferStateManager 0x02066998 arm
 *   g_ClactEmptyCharTemplate     0x020A1430  data
 *   VMAN_IsHandleInvalid  0x02034640  arm
 *   VMAN_Free  0x020346B8  arm
 *   NNSi_G2dIsVramHandleSet   0x020637BC  arm
 *   NNSi_G2dGetVramHandleValue   0x020637B4  arm
 *   GX_LoadOBJ   0x0207E780  arm
 *   GXS_LoadOBJ   0x0207E804  arm
 *   ARC_TOOL_LoadHandleMember  0x02049250  arm
 *   NNSi_G2dIsVramHandleSetEx  0x0206380C  arm
 *   NNSi_G2dGetVramHandleEx  0x02063800  arm
 *   GX_LoadOBJPltt  0x0207E51C  arm
 *   GXS_LoadOBJPltt  0x0207E5D0  arm
 *   NNSi_G2dGetCellAnimFrameIdx   0x02062F1C  arm
 *   gClactTables     0x020A7F3C  data
 *   NNS_G2dInitOamManagerModule  0x02063078  arm
 *   NNS_G2dApplyOamManagerToHW  0x0206343C  arm
 *   NNS_G2dResetOamManagerBuffer  0x02063640  arm
 *   NNS_G2dInitRenderer   0x02065AA8  arm
 *   NNS_G2dSetRendererTargetSurface   0x02065B64  arm
 *   NNS_G2dInitRenderSurface  0x02065B74  arm
 *   g_ClactSurfaceFuncTable     0x020A1418  data
 *   g_ClactSurfaceModeTable     0x020A13F4  data
 *   g_ClactSurfaceTypeTable     0x020A1388  data
 *   MI_CpuCopy8    0x02082D44  arm
 *   NNSi_G2dEntryOamManagerOam  0x02063294  arm
 *   NNS_G2dEntryOamManagerAffine  0x02063378  arm
 *   NNSi_objSizeHTbl   0x020A17D8  data
 *   NNSi_objSizeWTbl   0x020A17F0  data
 *   NNS_G2dInitCellTransferStateManager  0x02066934  arm
 *   MI_CpuFill8    0x02082BCC  arm
 *   g_ClactTransferFuncs     0x020A138C  data
 *   DC_FlushRange  0x020862F0  arm
 *   GF_PANIC_Fail  0x02034714  arm
 *   s_clact_assert_expr 0x020A7F7C data
 *   NNS_G2dSetRndCoreAffineOverwriteMode  0x02067AB8  arm
 *   NNS_G2dSetRndCoreFlipMode  0x02067B78  arm
 *   NNS_G2dTranslate  0x020663D0  arm
 *   NNS_G2dScale  0x020664CC  arm
 *   NNS_G2dRotZ  0x02066620  arm
 *   FX_SinCosTable_     0x020A1B38  data
 *   _fflt          0x0209BDBC  arm
 *   _ffix          0x0209C494  arm
 *   _fadd          0x0209C95C  arm
 *   _fsub          0x0209CB8C  arm
 *   g_ClactAnimFuncTable  0x020A1394  data
 *   NNS_G2dGetAnimSequenceByIdx  0x020627D8  arm
 *   NNS_G2dInitCellAnimation  0x0206428C  arm
 *   NNSi_G2dGetCellTransferStateIndex  0x02066AE0  arm
 *   NNS_G2dInitCellAnimationVramTransfered  0x020642C8  arm
 *   NNS_G2dGetMCWorkAreaSize  0x020648B4  arm
 *   NNS_G2dInitMCAnimation  0x02064754  arm
 *   NNSi_G2dResetCellTransferState  0x02066B38  arm
 *   NNS_G2dSetCellAnimationSequence  0x0206434C  arm
 *   NNS_G2dSetAnimSequenceToMCAnimation  0x0206469C  arm
 *   NNS_G2dTickCellAnimation   0x02064364  arm
 *   NNS_G2dTickMCAnimation   0x020649D4  arm
 *   NNS_G2dSetCellAnimationCurrentFrame  0x02064384  arm
 *   NNS_G2dSetMCAnimationCurrentFrame  0x02064AB4  arm
 *   NNS_G2dSetCellAnimationSpeed   0x020643C4  arm
 *   NNS_G2dSetMCAnimationSpeed  0x02064B68  arm
 *   g_ClactAnimResetFuncs  0x020A7F48  data
 *   NNS_G2dRestartCellAnimation  0x020643A4  arm
 *   NNS_G2dSetCellAnimationParam  0x02063000  arm
 *   NNS_G2dSetCellAnimationParamTagged  0x02063018  arm
 *   VMAN_Create  0x02034558  arm
 *   VMAN_Delete  0x020345DC  arm
 *   MI_UncompressLZ8  0x020834C0  arm
 *   VMAN_InvalidateHandle  0x02034630  arm
 *   NNSi_G2dInitVramHandle    0x02063790  arm
 *   VMAN_Alloc    0x02034660  arm
 *   VMAN_GetOffset    0x020346D8  arm
 *   NNSi_G2dLoadVramResourceMain    0x02063828  arm
 *   NNSi_G2dLoadVramResourceSub    0x02063A54  arm
 *   NNSi_G2dSetupVramResource    0x02063C80  arm
 *   NNS_G2dGetUnpackedPaletteCompressInfo  0x02062AD4  arm
 *   NNS_G2dGetUnpackedPaletteData  0x02062A98  arm
 *   NNSi_G2dInitVramHandleEx  0x020637D4  arm
 *   NNSi_G2dLoadVramResourceList  0x02063F4C  arm
 *   GX_GetBankForOBJExtPltt  0x02080C34  arm
 *   GX_GetBankForSubOBJExtPltt  0x02080C74  arm
 *   GX_SetBankForLCDC  0x0208068C  arm
 *   GX_SetBankForOBJExtPltt  0x020801F8  arm
 *   GX_SetBankForSubOBJExtPltt  0x0208083C  arm
 *   NNS_G2dGetUnpackedCellBank  0x02062820  arm
 *   NNS_G2dGetUnpackedAnimBankEx  0x02062670  arm
 *   NNS_G2dGetUnpackedCharacterData  0x02062A00  arm
 *   SYSTEMFONT_Load  0x020461F4  arm
 *   NNSi_G2dSetMCInstanceCurrentFrameZero  0x02064C10  arm
 *   NNS_G2dBeginRendering  0x02065BD0  arm
 *   NNS_G2dEndRendering  0x02065C78  arm
 *   NNSi_G2dRendererDrawCellZOffset  0x02065CE4  arm
 *   NNSi_G2dRendererDrawCellTransformedZOffset  0x02065D4C  arm
 *   NNSi_G2dRendererDrawMultiCellTransformed  0x02066080  arm
 *   NNSi_G2dReserveOamManagerSpan  0x02063138  arm
 *   NNSi_G2dLoadVramResourceBySel  0x02063E54  arm
 *   NNSi_G2dSetRndCoreImageProxyVeneer  0x02066748  arm
 */

#define CONV(d, v) do { s32 _t = (s16)(v); if (_t > 0) { (d) = (f32)(_t << 12) + 0.5f; } else { (d) = (f32)(_t << 12) - 0.5f; } } while (0)
struct Unit;
struct Renderer;
struct ClactRes;
struct ClactActor;
struct ArcFile;
struct NitroFileHeader;
struct VmanBank;
struct PaletteCompInfo;
struct CellAnim;
struct MultiCellAnim;
struct CellXferState;
struct AnimSequence;
#include "../types.h"
#include "../sdk_ioreg.h"
#include "clact.h"
#include "nns_g2d_cell_transfer.h"
#include "nns_g2d_oam_manager_types.h"
#include "nns_g2d_load.h"
#include "nns_g2d_renderer.h"
#include "nns_g2d_renderer_types.h"
#include "../sdk_gx.h"
#include "nns_g2d_res_types.h"
#include "nns_g2d_anim_types.h"

/* NNSG2dImageProxy (0x24) */
struct ImageProxy {
    u32 raw[9];
};

/* NNSG2dImagePaletteProxy (0x14) */
struct PaletteProxy {
    u32 raw[5];
};

/* One block taken from a VramAllocator. */
struct VramBlock {
    u32 lo;
    u32 hi;
};


/* NNSG2dPaletteData (0x10) */
struct PaletteData {
    u32 format;        /* 0x00 */
    u32 extended;      /* 0x04 */
    u32 size;          /* 0x08 */
    u32 raw;           /* 0x0c */
};

/* Transfer info whose word at +0x0c points at the VRAM size to reserve. */
struct CharXferInfo {
    u8   pad_00[0xc];
    u32 *size;         /* 0x0c */
};

/* Registered character (image) resource, 0x40. */
struct CharSlot {
    struct ImageProxy proxy;          /* 0x00 */
    void             *data;           /* 0x24 */
    u32               xfer_src;       /* 0x28 */
    struct VramBlock  main_block;     /* 0x2c */
    struct VramBlock  sub_block;      /* 0x34 */
    u32               data_shared : 1; /* 0x3c */
    u32               vram_size   : 30;
    u32               free        : 1;
};

/* Registered palette resource, 0x18. */
struct PlttSlot {
    struct PaletteProxy proxy;        /* 0x00 */
    union {
        struct {
            u32 size : 31;            /* 0x14 */
            u32 free : 1;
        };
        u32 bits;
    };
};

/* User extended attribute table inside a G2d data bank. */
typedef struct {
    u16 count;
    u16 pad_02;
    u8 *items;
} UserAttrTable;

typedef struct {
    u32           tag;
    u32           size;
    UserAttrTable tbl;
} UserExtBlock;

/* Registered cell and animation bank pair, 0x14. */
struct CellSlot {
    void               *cell_file;    /* 0x00 */
    void               *anim_file;    /* 0x04 */
    struct CellDataBank *cell_bank;    /* 0x08 */
    struct AnimBank *anim_bank;    /* 0x0c */
    u32                 free;         /* 0x10 */
};

/* Per-actor animation controller, 0x7c. */
struct AnimCtl {
    u32                 kind;         /* 0x00 */
    struct CellDataBank *cell_bank;    /* 0x04 */
    struct AnimBank *anim_bank;    /* 0x08 */
    u8                  anim[0x30];   /* 0x0c */
    u32                 cur_cell;     /* 0x3c */
    u8                  xfer_state[0x24]; /* 0x40 */
    u32                 xfer_handle;  /* 0x64 */
    u8                  pad_68[8];
    struct MultiCellBank *mc_bank;      /* 0x70 */
    struct AnimBank *mc_anim_bank; /* 0x74 */
    void               *mc_work;      /* 0x78 */
};


struct ActorReq {
    u16                 char_idx;     /* 0x00 */
    u16                 pltt_idx;     /* 0x02 */
    struct CharSlot    *char_slot;    /* 0x04 */
    struct PlttSlot    *pltt_slot;    /* 0x08 */
    struct CellDataBank *cell_bank;    /* 0x0c */
    struct AnimBank *anim_bank;    /* 0x10 */
    struct MultiCellBank *mc_bank;      /* 0x14 */
    struct AnimBank *mc_anim_bank; /* 0x18 */
    const NNSG2dCharacterData *xfer_chars; /* 0x1c */
};

struct Pair32 {
    u32 x;
    u32 y;
};

struct ClactActor {
    struct ClactActor       *next;         /* 0x00 */
    struct ClactActor       *prev;         /* 0x04 */
    struct Unit        *owner;        /* 0x08 */
    struct Pt16         pos;          /* 0x0c */
    struct Pt16         origin;       /* 0x10 */
    struct Pair32       scale;        /* 0x14 */
    struct ImageProxy   image;        /* 0x1c */
    struct PaletteProxy palette;      /* 0x40 */
    u32                 auto_anim_speed; /* 0x54 */
    u16                 angle;        /* 0x58 */
    u16                 anim_seq;     /* 0x5a */
    u16                 char_idx;     /* 0x5c */
    u16                 pltt_idx;     /* 0x5e */
    u32                 draw_priority : 8; /* 0x60 */
    u32                 mode          : 4;
    u32                 pltt_offset   : 4;
    u32                 bg_priority   : 2;
    u32                 affine_mode   : 2;
    u32                 flip          : 2;
    u32                 obj_mode      : 2;
    u32                 mosaic        : 1;
    u32                 auto_anim     : 1;
    u32                 enabled       : 1;
    u32                 loop_limit    : 4;
    u32                 pltt_op       : 1;
    u32                 hidden        : 1; /* 0x64 */
    u32                 pad_64        : 31;
    struct AnimCtl      ctl;          /* 0x68 */
};

struct Unit {
    struct ClactActor    *actors;          /* 0x00 */
    struct ClactActor    *head;            /* 0x04 */
    struct Renderer *renderer;        /* 0x08 */
    u16              count;           /* 0x0c */
    u8               source      : 4; /* 0x0e */
    u8               draw_enable : 4;
    u8               priority;        /* 0x0f */
    struct Unit     *next;            /* 0x10 */
    struct Unit     *prev;            /* 0x14 */
};

struct ClactRes {
    struct VmanBank *vram_main;  /* 0x00 */
    struct VmanBank *vram_sub;   /* 0x04 */
    struct CharSlot      *chars;      /* 0x08 */
    struct PlttSlot      *pltts;      /* 0x0c */
    struct CellSlot      *cells;      /* 0x10 */
    /*
     * stand-in: volatile keeps the per-iteration re-read of the loop bound in
     * the five registry scans (CLACT_RegisterCharacter, ..EmptyCharacter,
     * ..PaletteEx, ..PaletteCompressed, ..CellAnim).  Without it dsi/1.1p1
     * hoists the load (5 functions DIFF); ../2.0/sp2 and ../1.2/sp3 do not
     * fit these functions with or without it (115 to 185 bytes off).
     */
    volatile u16   n_chars;           /* 0x14 */
    volatile u16   n_pltts;           /* 0x16 */
    volatile u16   n_cells;           /* 0x18 */
    u16            n_spare;           /* 0x1a */
    u16            n_main_blocks;     /* 0x1c */
    u16            n_sub_blocks;      /* 0x1e */
};

/* One queued VRAM transfer, 0x10. */
struct TransferEntry {
    void *src;         /* 0x00 */
    u32   dest;        /* 0x04 */
    u32   size;        /* 0x08 */
    u32   kind;        /* 0x0c */
};

struct TransferPool {
    CellTransferState *tasks;       /* 0x00 */
    struct TransferEntry    *entries; /* 0x04 */
    u32                      count;   /* 0x08 */
    u32                      ready;   /* 0x0c */
};


typedef union {
    u32 attr01;
    struct {
        u32 y : 8;
        u32 rsMode : 2;
        u32 objMode : 2;
        u32 mosaic : 1;
        u32 colorMode : 1;
        u32 shape : 2;
        u32 x : 9;
        u32 rsParam : 5;
        u32 size : 2;
    };
} OamAttr;

struct Surface;
struct ViewRect;
struct Affine2D;
typedef void (*OamCullFn)(struct Surface *surface, struct ViewRect *view, s32 unused_x, s32 unused_y, struct Affine2D *mtx);

/* NNSG2dRenderSurface view, 0x48. */
struct Surface {
    s32       x;                  /* 0x00 */
    s32       y;                  /* 0x04 */
    s32       width;              /* 0x08 */
    s32       height;             /* 0x0c */
    u8        pad_10[4];
    u32       type;               /* 0x14 */
    u8        pad_18[0x10];
    s32       oam_func;           /* 0x28 */
    s32       affine_func;        /* 0x2c */
    u32       visible;            /* 0x30 */
    s32       extra_func;         /* 0x34 */
    OamAttr   oam;                /* 0x38 */
    u8        pad_3c[4];
    OamCullFn cull;               /* 0x40 */
    u8        pad_44[4];
};

/* Renderer with its surfaces, 0xa0. */
struct Renderer {
    u8              pad_00[0x30];
    u32             cull_reset;   /* 0x30 */
    u8              pad_34[0x4c];
    u32             active;       /* 0x80 */
    u32             flags;        /* 0x84 */
    u16             bg_priority;  /* 0x88 */
    u8              pad_8a[2];
    u32             obj_mode;     /* 0x8c */
    u32             mosaic;       /* 0x90 */
    u8              pad_94[4];
    struct Surface *surfaces;     /* 0x98 */
    u32             n_surfaces;   /* 0x9c */
};

struct OamManager {               /* 0x20 */
    NNSG2dOamManagerInstance inst;
    u32 bound;
};

struct OamManagers {
    struct OamManager mgr[2];
};

struct SurfaceInit {
    s16 x;
    s16 y;
    s16 w;
    s16 h;
    u32 type;
    u32 extra_func_sel;
};


/* NNSG2dCellData head with its bounding rectangle. */
struct CellData {
    u16 num_oams; u16 attr; u16 oams_lo; u16 oams_hi;
    s16 max_x; s16 max_y; s16 min_x; s16 min_y;
};

/* MtxFx32 2x3 */
struct Affine2D { s32 m00; s32 m01; s32 m10; s32 m11; s32 tx; s32 ty; };

struct ViewRect { s32 x; s32 y; s32 width; s32 height; };

struct Sys {
    struct OamManagers   oam_mgrs;    /* 0x000 */
    struct Renderer      renderer;    /* 0x040 */
    struct TransferPool  transfer;    /* 0x0e0 */
    u16                  pltt_base[2]; /* 0x0f0 */
    u32                  pltt_op;     /* 0x0f4 */
    u32                  active;      /* 0x0f8 */
    u32                  oam_pending; /* 0x0fc */
    struct Unit         *units;       /* 0x100 */
    struct ClactRes           res;         /* 0x104 */
};


/*
 * The file's static tables at 0x020A7F3C, one object: the per-kind animation
 * update and reset handlers, then the two default surface rectangles that
 * CLACT_InitDefaultRenderer fills in.  The handler tables are also reached
 * through their own symbols (g_ClactAnimUpdateFuncs, g_ClactAnimResetFuncs):
 * the dispatchers load those addresses from the pool, and addressing the
 * rectangles through a separate symbol moves the pool base (measured DIFF).
 */
struct ClactTables {
    void (*anim_update[3])(struct AnimCtl *ctl, u32 frames); /* 0x00 */
    void (*anim_reset[3])(struct AnimCtl *ctl);             /* 0x0c */
    struct SurfaceInit default_surfaces[2];                 /* 0x18 */
};

typedef struct { u32 oam_func, affine_func, extra_func; } SurfaceFuncs;


typedef void (*AnimUpdateFn)(struct AnimCtl *ctl, u32 frames);

typedef void (*AnimResetFn)(struct AnimCtl *ctl);


struct Caps {
    u16 n_chars;        /* 0x00 */
    u16 n_pltts;        /* 0x02 */
    u16 n_cells;        /* 0x04 */
    u16 n_spare;        /* 0x06 */
    u16 n_main_blocks;  /* 0x08 */
    u16 n_sub_blocks;   /* 0x0a */
};

struct DispVramCfg {
    u8  pad_00[0x10];
    u32 main_obj_bank;     /* 0x10 */
    u8  pad_14[4];
    u32 sub_obj_bank;      /* 0x18 */
    u8  pad_1c[0x0c];
    u32 main_obj_mapping;  /* 0x28 */
    u32 sub_obj_mapping;   /* 0x2c */
};

struct CompHeader {
    u32 header;
};

#include "gfl_heap_wrap.h"
#include "mi_memory.h"
#include "nns_g2d_cell_transfer.h"
struct VmanHandle;
struct VmanBank;
/* Kept local: clact.c passes the heap id as a full word (vman.h takes u16). */
/* Original DS prototype: the caller passes the arguments at the wider width; the host build uses the header. */
#ifdef __MWERKS__
#define VMAN_Create VMAN_Create_header
#endif
#include "vman.h"
#ifdef __MWERKS__
#undef VMAN_Create
extern struct VmanBank *VMAN_Create(u32 heapId, u32 kind, u32 flags, u32 base, u32 b);
#endif
#include "os_cache.h"
#include "gx_load2d.h"
#include "arc_tool.h"
struct Node;
struct NNSG2dOamManagerInstance;
struct NNSG2dRendererInstance;
struct NNSG2dRenderSurface;
#include "gf_panic.h"
/* Original DS prototypes: the caller takes the affine entry as returning nothing and passes the first OAM index as an int; the host build uses the header. */
#ifdef __MWERKS__
#define NNS_G2dEntryOamManagerAffine NNS_G2dEntryOamManagerAffine_header
#define NNSi_G2dReserveOamManagerSpan NNSi_G2dReserveOamManagerSpan_header
#endif
#include "nns_g2d_oam_manager.h"
#ifdef __MWERKS__
#undef NNS_G2dEntryOamManagerAffine
#undef NNSi_G2dReserveOamManagerSpan
extern u32 NNSi_G2dReserveOamManagerSpan(NNSG2dOamManagerInstance *s, int first, int count, int which);
extern void NNS_G2dEntryOamManagerAffine(NNSG2dOamManagerInstance *pMan, const MtxFx22 *mtx);
#endif

struct NNSG2dRndCoreInstance;
#include "nns_g2d_renderer_core.h"
struct MultiCellDrawCmd;
struct AnimBank;
struct AnimSequenceData;
struct CellDataBank;
#include "nns_g2d_multi_cell_animation.h"
struct MCInstance;
#include "nns_g2d_cell_animation.h"
#include "nns_g2d_anim_bank.h"
#include "mi_uncompress.h"
struct VramHandle;
struct VramResource;
struct VramHandleSel;
struct VramResourceSel;
#include "gx_vramcnt.h"
struct VramHandleList;
struct VramResourceIndices;
struct VramResourceList;
#include "systemfont.h"
void CLACT_InitSystem(const struct ClactSysInit *cfg, const struct DispVramCfg *res_cfg, u32 heapId);
void CLACT_ExitSystem(void);
void CLACT_DrawSystem(void);
void CLACT_VBlankSystem(void);
void CLACT_FlushOamIfPending(void);
s32 CLACT_RegisterCharacter(void *archive, u32 file_idx, u32 compressed, u32 vram_mode, u16 heap_id);
s32 CLACT_RegisterEmptyCharacter(u32 size, u32 vram_mode, u16 heapId);
void CLACT_ReleaseCharacter(u32 idx);
void CLACT_TransferCharacter(int idx, NNSG2dCharacterData *char_data);
void CLACT_TransferCharacterPart(int idx, void *src, u32 size, int offset, int target);
void CLACT_GetCharacterProxy(u32 idx, struct ImageProxy *out);
int CLACT_GetCharacterVramAddress(u32 idx, u32 flag);
s32 CLACT_RegisterPalette(void *archive, u32 file_idx, u32 vram_mode, u32 vram_offset, u16 heap_id);
s32 CLACT_RegisterPaletteEx(void *archive, u32 file_idx, u32 vram_mode, u32 vram_offset, u16 first_color, u16 color_count, u16 heap_id);
int CLACT_RegisterPaletteCompressed(void *archive, u32 file_idx, u32 vram_mode, u32 vram_offset, u16 heap_id);
void CLACT_ReleasePalette(u32 idx);
void CLACT_TransferPalette(u32 idx, struct PaletteData *dest, u32 count);
void CLACT_GetPaletteProxy(u32 idx, struct PaletteProxy *dest);
int CLACT_GetPaletteVramAddress(u32 idx, u32 alternate);
s32 CLACT_RegisterCellAnim(void *archive, u32 cell_file_idx, u32 anim_file_idx, u32 heap_id);
void CLACT_ReleaseCellAnim(u32 idx);
struct Renderer *CLACT_CreateRenderer(const struct SurfaceInit *inits, u32 count, u32 heap_id);
void CLACT_DeleteRenderer(struct Renderer *renderer);
void CLACT_SetSurfacePos(struct Renderer *renderer, int idx, struct ClactVec2 *pos);
void CLACT_GetSurfacePos(struct Renderer *renderer, u32 surface_idx, struct ClactVec2 *out);
void CLACT_SetRendererCulling(struct Renderer *renderer, int enable);
struct Unit *CLACT_CreateUnit(int count, u8 priority, u32 heapId);
u32 CLACT_DeleteUnit(struct Unit *unit);
void CLACT_SetUnitDrawEnable(struct Unit *unit, u32 enable);
u32 CLACT_GetUnitDrawEnable(struct Unit *unit);
void CLACT_SetUnitRenderer(struct Unit *unit, void *renderer);
void CLACT_SetUnitDefaultRenderer(struct Unit *unit);
struct ClactActor *CLACT_CreateActor(struct Unit *unit, u32 char_idx, u32 pltt_idx, u32 cell_idx, const struct ActorInitParam *init, u16 space, u16 heap_id);
struct ClactActor *CLACT_CreateAffineActor(struct Unit *unit, u32 char_idx, u32 pltt_idx, u32 cell_idx, const struct ActorInit *init, u16 space, u16 heap_id);
void CLACT_DeleteActor(struct ClactActor *actor);
void CLACT_SetActorDrawEnable(struct ClactActor *actor, u32 value);
u32 CLACT_GetActorDrawEnable(struct ClactActor *actor);
void CLACT_AddActorSurfacePos(struct ClactActor *actor, const struct ClactVec2 *delta, u32 which);
void CLACT_GetActorSurfacePos(struct ClactActor *actor, struct ClactVec2 *out, u16 space);
void CLACT_SetActorSurfacePosAxis(struct ClactActor *actor, s16 value, u32 space, u32 axis);
s16 CLACT_GetActorSurfacePosAxis(struct ClactActor *actor, u32 space, u32 axis);
void CLACT_SetActorPos(struct ClactActor *actor, const struct Pt16 *pos);
void CLACT_GetActorPos(const struct ClactActor *actor, struct Pt16 *out);
void CLACT_SetActorPosAxis(struct ClactActor *actor, signed short value, u32 axis);
s16 CLACT_GetActorPosAxis(const struct ClactActor *actor, u32 axis);
void CLACT_SetActorAffineMode(struct ClactActor *actor, u32 value);
void CLACT_SetActorAffineOrigin(struct ClactActor *actor, const struct Pt16 *origin);
void CLACT_SetActorAffineOriginAxis(struct ClactActor *actor, signed short value, u32 axis);
void CLACT_SetActorScale(struct ClactActor *actor, struct Pair32 *src);
void CLACT_GetActorScale(const struct ClactActor *actor, struct Pair32 *out_scale);
void CLACT_SetActorScaleAxis(struct ClactActor *actor, u32 value, u32 which);
u32 CLACT_GetActorScaleAxis(const struct ClactActor *actor, u32 which);
void CLACT_SetActorRotation(struct ClactActor *actor, u16 value);
u16 CLACT_GetActorRotation(const struct ClactActor *actor);
void CLACT_SetActorFlip(struct ClactActor *actor, u32 which, u32 set);
u32 CLACT_GetActorFlip(const struct ClactActor *actor, u32 which);
void CLACT_SetActorObjMode(struct ClactActor *actor, u32 value);
u32 CLACT_GetActorObjMode(const struct ClactActor *actor);
void CLACT_SetActorPaletteOffset(struct ClactActor *actor, u32 offset, u32 pltt_op);
u32 CLACT_GetActorPaletteOffset(struct ClactActor *actor);
void CLACT_SetActorPaletteProxy(struct ClactActor *actor, const struct PaletteProxy *proxy);
void CLACT_GetActorPaletteProxy(const char *actor_base, struct PaletteProxy *dst);
void CLACT_SetActorImageProxy(char *actor_base, const struct ImageProxy *proxy);
void CLACT_GetActorImageProxy(const char *actor_base, struct ImageProxy *dst);
u16 CLACT_GetActorCharacterIndex(struct ClactActor *actor);
u16 CLACT_GetActorPaletteIndex(struct ClactActor *actor);
void CLACT_SetActorDrawPriority(struct ClactActor *actor, u32 priority);
int CLACT_GetActorDrawPriority(struct ClactActor *actor);
void CLACT_SetActorBgPriority(struct ClactActor *actor, unsigned int priority);
u32 CLACT_GetActorBgPriority(struct ClactActor *actor);
void CLACT_SetActorAnimSeq(struct ClactActor *actor, u16 value);
u16 CLACT_GetActorAnimSeq(struct ClactActor *actor);
void CLACT_ChangeActorAnimSeq(struct ClactActor *actor, u16 anim_seq);
void CLACT_SetActorAnimFrame(struct ClactActor *actor, u32 frame);
void CLACT_AddActorAnimFrame(struct ClactActor *actor, u32 frames);
u32 CLACT_GetActorAnimFrame(struct ClactActor *actor);
void CLACT_SetActorAnimIndex(struct ClactActor *actor, u32 anim_idx);
u16 CLACT_GetActorAnimSeqCount(struct ClactActor *actor);
void CLACT_SetActorAutoAnim(struct ClactActor *actor, u32 enable);
u32 CLACT_GetActorAutoAnim(struct ClactActor *actor);
void CLACT_SetActorAutoAnimSpeed(struct ClactActor *actor, u32 speed);
void CLACT_StartActorAnim(struct ClactActor *actor);
void CLACT_StopActorAnim(struct ClactActor *actor);
u32 CLACT_IsActorAnimActive(struct ClactActor *actor);
void CLACT_RestartActorAnim(struct ClactActor *actor);
void CLACT_SetActorAnimLoopCount(struct ClactActor *actor, u32 loop_limit);
void CLACT_ApplyActorAnimCommand(struct ClactActor *actor, const struct ClactAnimCommand *cmd);
void CLACT_ResetActorAnimCommand(struct ClactActor *actor);
void CLACT_SetActorVisible(struct ClactActor *actor, u32 visible);
void CLACT_InitDefaultRenderer(struct Renderer *renderer, const s16 *src, u32 heap_id);
void CLACT_SetPaletteBaseOffsets(u32 pltt_proxy, u16 base_offset, u32 pltt_op);
void CLACT_SetSystemActive(u32 active);
u32 CLACT_IsSystemActive(void);
void CLACT_SetOamPending(u32 pending);
u32 CLACT_IsOamPending(void);
void CLACT_ResetOamIfPending(void);
void CLACT_DrawAllUnits(void);
void CLACT_LinkUnit(struct Unit *unit);
void CLACT_UnlinkUnit(struct Unit *unit);
void CLACT_InitOamManagers(struct OamManagers *oam_managers, u32 main_base, u32 main_count, u32 sub_base, u8 sub_count);
void CLACT_ExitOamManagers(struct OamManagers *oam_managers);
void CLACT_ApplyOamManagers(struct OamManagers *oam_managers);
void CLACT_ResetOamManagers(struct OamManagers *oam_managers);
void CLACT_InitOamManager(struct OamManager *oam_manager, int base, int count, int screen);
void CLACT_ApplyOamManager(struct OamManager *oam_manager);
void CLACT_ResetOamManager(struct OamManager *oam_manager);
void CLACT_InitRenderer(struct Renderer *renderer, const struct SurfaceInit *inits, int count, u32 heap_id);
void CLACT_ExitRenderer(struct Renderer *renderer);
void CLACT_SetSurfaceCulling(struct Renderer *renderer, int enable);
void CLACT_InitSurface(struct Surface *surface, const struct SurfaceInit *init);
void CLACT_SetSurfaceType(struct Surface *surface, u32 idx);
void CLACT_EntryOam(struct OamManager *oam_manager, GXOamAttr *src_entry, u32 mode, u32 pltt_offset, u32 pltt_op);
void CLACT_EntryOamMain(GXOamAttr *entry, u32 mode);
void CLACT_EntryOamSub(GXOamAttr *entry, u32 mode);
void CLACT_EntryAffineMain(const MtxFx22 *value);
void CLACT_EntryAffineSub(const MtxFx22 *value);
int CLACT_IsAffineCellInView(struct CellData *cell, struct Affine2D *affine, struct ViewRect *view);
int CLACT_IsCellInView(struct CellData *cell, struct Affine2D *affine, struct ViewRect *view);
void CLACT_CullOam(struct Surface *surface, struct ViewRect *view, s32 unused_arg2, s32 unused_arg3, struct Affine2D *affine);
int CLACT_IsRectInView(s32 dx, s32 dy, s32 x0, s32 x1, s32 y0, s32 y1, const struct Affine2D *affine, const struct ViewRect *view);
void CLACT_InitTransferPool(struct TransferPool *pool, u8 count, u32 heapId);
void CLACT_ExitTransferPool(struct TransferPool *pool);
void CLACT_AllocTransferEntries(struct TransferPool *pool, u32 count, u32 heapId);
void CLACT_FreeTransferEntries(struct TransferPool *pool);
void CLACT_ExecuteTransfers(struct TransferPool *pool);
struct TransferEntry *CLACT_GetFreeTransferEntry(struct TransferPool *pool);
BOOL CLACT_RequestTransfer(s32 kind, u32 dest, void *src, u32 size);
void CLACT_SetTransferEntry(struct TransferEntry *entry, u32 entry_kind, u32 dest, void *src, u32 size);
void CLACT_ExecuteTransfer(struct TransferEntry *entry);
struct ClactActor *CLACT_GetFreeActor(struct Unit *unit);
void CLACT_DrawUnit(struct Unit *unit);
void CLACT_LinkActor(struct Unit *unit, struct ClactActor *actor);
void CLACT_UnlinkActor(struct Unit *unit, struct ClactActor *actor);
void *CLACT_FindActorBefore(struct ClactActor *head, u32 priority);
struct ClactActor *CLACT_FindActorAfter(struct ClactActor *head, u32 priority);
void CLACT_ClearActor(struct ClactActor *actor);
void CLACT_DrawActor(struct ClactActor *actor, struct Renderer *renderer);
void CLACT_SetupActorDraw(struct ClactActor *actor, struct Renderer *renderer);
void CLACT_ApplyActorTransform(struct ClactActor *actor);
void CLACT_UpdateActorAutoAnim(struct ClactActor *actor);
void CLACT_ApplyActorInit(struct ClactActor *actor, const struct ActorInitParam *init, u32 space);
void CLACT_ApplyActorResources(struct ClactActor *actor, const struct ActorReq *req);
void CLACT_GetSurfaceOrigin(struct ClactActor *actor, u32 surface_idx, u16 *out);
void CLACT_InitActorRequest(struct ActorReq *req, u16 char_idx, u16 pltt_idx, struct CharSlot *char_slot, struct PlttSlot *pltt_slot, struct CellDataBank *cell_bank, struct AnimBank *anim_bank);
struct ClactActor *CLACT_CreateActorCore(struct Unit *unit, const struct ActorInitParam *init, struct ActorReq *req, u32 space, u16 heap_id);
struct ClactActor *CLACT_CreateActorFull(struct Unit *unit, const struct ActorInit *init, struct ActorReq *req, u32 space, u16 heap_id);
void CLACT_InitAnimCtl(struct AnimCtl *anim_ctl, void *req, u32 heap_id);
void CLACT_ExitAnimCtl(struct AnimCtl *anim_ctl);
s32 CLACT_GetAnimCtlKind(const struct ActorReq *req);
void CLACT_InitCellAnimCtl(struct AnimCtl *anim_ctl, const struct ActorReq *req);
void CLACT_InitMultiCellAnimCtl(struct AnimCtl *anim_ctl, const struct ActorReq *req);
void CLACT_InitVramAnimCtl(struct AnimCtl *anim_ctl, const struct ActorReq *req, u32 heap_id);
void CLACT_ExitCellAnimCtl(void *anim);
void CLACT_ExitMultiCellAnimCtl(struct AnimCtl *anim_ctl);
void CLACT_ExitVramAnimCtl(struct AnimCtl *anim_ctl);
void CLACT_SetAnimSeq(struct AnimCtl *anim_ctl, u32 anim_seq);
void CLACT_SetCellAnimSeq(struct AnimCtl *anim_ctl, u32 idx);
void CLACT_SetMultiCellAnimSeq(struct AnimCtl *anim_ctl, u32 idx);
void CLACT_SetVramAnimSeq(struct AnimCtl *anim_ctl, u32 idx);
void CLACT_SetAnimFrame(struct AnimCtl *anim_ctl, u32 value);
void *CLACT_AddAnimFrame(struct AnimCtl *anim_ctl, u32 speed);
void CLACT_AddCellAnimFrame(struct AnimCtl *anim_ctl, s32 frames);
void CLACT_AddMultiCellAnimFrame(struct AnimCtl *anim_ctl, s32 frames);
void CLACT_AddVramAnimFrame(struct AnimCtl *anim_ctl, s32 frames);
AnimCtrl *CLACT_GetAnimCtrl(struct AnimCtl *anim_ctl);
void *CLACT_GetCellAnimCtrl(struct AnimCtl *anim_ctl);
void *CLACT_GetMultiCellAnimCtrl(struct AnimCtl *anim_ctl);
void *CLACT_GetVramAnimCtrl(struct AnimCtl *anim_ctl);
AnimCtrl *CLACT_GetAnimObject(struct AnimCtl *anim_ctl);
void *CLACT_GetCellAnimObject(struct AnimCtl *anim_ctl);
void *CLACT_GetMultiCellAnimObject(struct AnimCtl *anim_ctl);
void *CLACT_GetVramAnimObject(struct AnimCtl *anim_ctl);
void *CLACT_SetAnimIndex(struct AnimCtl *anim_ctl, u32 anim_idx);
void CLACT_SetCellAnimIndex(u8 *anim_base, u32 frame);
void CLACT_SetMultiCellAnimIndex(u8 *anim_base, u32 frame);
void CLACT_SetVramAnimIndex(struct AnimCtl *anim_ctl, u32 frame);
void CLACT_SetAnimSpeed(struct AnimCtl *anim_ctl, u32 frames);
void CLACT_SetCellAnimSpeed(struct AnimCtl *anim_ctl, u32 value);
void CLACT_SetMultiCellAnimSpeed(struct AnimCtl *anim_ctl, u32 value);
void CLACT_SetVramAnimSpeed(struct AnimCtl *anim_ctl, u32 target);
void CLACT_ResetAnim(struct AnimCtl *anim_ctl);
void CLACT_ResetCellAnim(void *anim_base);
void CLACT_ResetMultiCellAnim(u8 *anim_base);
void CLACT_ResetVramAnim(void *anim_base);
void *CLACT_GetCellUserAttr(struct AnimCtl *anim_ctl, u32 idx);
void *CLACT_GetMultiCellUserAttr(struct AnimCtl *anim_ctl, u32 idx);
void *CLACT_GetVramCellUserAttr(struct AnimCtl *anim_ctl, u32 idx);
UserAttrTable *CLACT_GetCellUserAttrTable(struct AnimCtl *anim_ctl);
UserAttrTable *CLACT_GetMultiCellUserAttrTable(struct AnimCtl *anim_ctl);
UserAttrTable *CLACT_GetVramCellUserAttrTable(struct AnimCtl *anim_ctl);
u16 CLACT_GetCellBankCount(struct AnimCtl *anim_ctl);
u16 CLACT_GetMultiCellBankCount(struct AnimCtl *anim_ctl);
u16 CLACT_GetVramCellBankCount(struct AnimCtl *anim_ctl);
void CLACT_ApplyAnimCommand(struct AnimCtl *anim_ctl, const struct ClactAnimCommand *cmd);
void CLACT_ResetAnimCommand(struct AnimCtl *anim_ctl);
void CLACT_InitResources(struct ClactRes *res, u32 heapId, const struct DispVramCfg *cfg, const struct Caps *caps);
void CLACT_ExitResources(struct ClactRes *res);
u32 CLACT_IsVramTypeCompatible(u32 mode, u32 bank_idx);
void *CLACT_LoadArchiveData(void *archive, u32 file_idx, u32 compressed, u32 heapId);
void *CLACT_AllocCharacterTable(u32 heapId, u32 count);
void CLACT_SetupCharacterVram(struct ClactRes *res, u32 idx, NNSG2dCharacterData *char_data, struct CharXferInfo *xfer_override, u32 vram_mode);
void CLACT_FreeCharacterTable(void *chars);
void CLACT_UpdateObjMapping(NNSG2dCharacterData *char_data, int screen);
void *CLACT_AllocPaletteTable(u32 heapId, u32 count);
void CLACT_TransferPaletteData(struct ClactRes *res, int idx, void *file, void *vram_mode, u32 vram_offset, u16 first_color, u16 color_count);
void CLACT_TransferPaletteDataEx(struct ClactRes *res, int idx, void *file, void *vram_mode, u32 vram_offset);
void CLACT_FreePaletteTable(void *pltts);
struct CellSlot *CLACT_AllocCellAnimTable(u32 heap_id, u32 count);
s32 CLACT_LoadCellAnimBanks(struct ClactRes *res, s32 idx, void *cell_file, void *anim_file);
void CLACT_FreeCellAnimTable(void *cells);
void CLACT_SetupCharacter(struct ClactRes *res, s32 idx, u32 handle, u32 vram_mode, u32 xfer_info);
extern struct Sys *g_ClactSystem;
extern const char s_clact_c[];
extern const NNSG2dCharacterData g_ClactEmptyCharTemplate;
extern struct ClactTables gClactTables;
extern SurfaceFuncs  g_ClactSurfaceFuncTable[];
extern u32  g_ClactSurfaceModeTable[];
extern u16 g_ClactSurfaceTypeTable[];
extern const u16 NNSi_objSizeHTbl[4][4];
extern const u16 NNSi_objSizeWTbl[4][4];
extern const char s_clact_assert_expr[];
extern s16 FX_SinCosTable_[];
extern AnimResetFn g_ClactAnimResetFuncs[];

/*
 * Blocked at MATCH: all 288 concrete bytes are correct and seven of the ten
 * relocation sites now resolve.  CLACT_InitDefaultRenderer (+0x00C0) was closed by wave
 * 20C (src/matched/CLACT_InitDefaultRenderer.c).  The other three are each byte-correct
 * in src/pending/ but capped at MATCH by a fan-in-1 extern of their own, so
 * this file needs three `matched` entries that do not exist yet:
 *   CLACT_InitResources (+0x0090) waits on 0x02034558, 0x0204DA5C and 0x0204DCA8
 *   CLACT_InitOamManagers (+0x00AC) waits on CLACT_InitOamManager, which waits on 0x02063138
 *   CLACT_InitTransferPool (+0x00D8) waits on 0x02066934
 * All four of those addresses sit outside clact.c.
 *
 * Bring up the single global cell-actor system behind 0x02146A74, the exact
 * inverse of src/pending/CLACT_ExitSystem.c: one 0x124-byte allocation, zeroed,
 * then each of the four embedded sub-objects at +0x00, +0x40, +0x0e0 and
 * +0x104 initialised from the caller's config record, the two-entry u16 table
 * at +0xf0 cleared, and the system enabled.  The __FILE__ pointer is the same
 * s_clact_c the rest of clact.c uses.
 *
 * The six halfwords at +0x10..+0x1a of the config are copied into a stack
 * array one field at a time rather than as an aggregate: a twelve-byte struct
 * assignment would be an inlined `ldm`/`stm` pair
 * (docs/idioms/aggregate-assignment-is-ldm-stm.md), and the original spells out
 * six `ldrh`/`strh`.
 *
 * The zero that clears the +0xf0 table is the loop counter's own initial
 * value, hoisted out of the loop, and is the same register as the allocator's
 * `clear` argument and the fill byte
 * (docs/idioms/a-small-constant-is-rematerialised-off-a-zero-register-unless-an-argument-shares-it.md),
 * so `i` has to be a function-scope local.  The trailing 1 is shared by the
 * last two calls the same way.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/CLACT_InitSystem.c \
 *       --func CLACT_InitSystem --addr 0x0204A48C --cc 1.1p1 --arm
 */
void CLACT_InitSystem(const struct ClactSysInit *cfg, const struct DispVramCfg *res_cfg, u32 heapId)
{
    u16 dims[6];
    int i;

    g_ClactSystem = GFL_HEAP_Alloc(heapId, sizeof(struct Sys), 0, s_clact_c, 0x28f);
    MI_CpuFill8(g_ClactSystem, 0, sizeof(struct Sys));

    dims[0] = cfg->n_chars;
    dims[1] = cfg->n_pltts;
    dims[2] = cfg->n_cells;
    dims[3] = cfg->n_spare;
    dims[4] = cfg->n_main_blocks;
    dims[5] = cfg->n_sub_blocks;

    CLACT_InitResources(&g_ClactSystem->res, heapId, res_cfg, (const struct Caps *)dims);
    CLACT_InitOamManagers(&g_ClactSystem->oam_mgrs, cfg->oam_main_base, cfg->oam_main_count, cfg->oam_sub_base,
                  cfg->oam_sub_count);
    CLACT_InitDefaultRenderer(&g_ClactSystem->renderer, cfg->surface_pos, heapId);
    CLACT_InitTransferPool(&g_ClactSystem->transfer, cfg->n_transfers, heapId);

    for (i = 0; i < 2; i++) {
        g_ClactSystem->pltt_base[i] = 0;
    }

    CLACT_SetSystemActive(1);
    CLACT_SetOamPending(1);
}

/*
 * Was blocked at MATCH pending CLACT_ExitResources (+0x003C), which was itself
 * capped at MATCH behind VMAN_Delete.  Both are now `matched`
 * (src/matched/CLACT_ExitResources.c, src/matched/VMAN_Delete.c), closing the
 * cell-actor system destructor.
 *
 * Tear down the single global cell-actor system behind 0x02146A74.  The block
 * is one allocation with four embedded sub-objects at +0x00, +0x40, +0x0e0 and
 * +0x104, each released by its own finaliser, after which the block is freed
 * and the global cleared.  src/matched/CLACT_SetUnitDefaultRenderer.c points a unit at
 * +0x40 of the same block, so that sub-object is the shared default.
 *
 * The global is re-read from the pool word before every call because each
 * callee could store to it; that is not a `volatile` (see
 * docs/idioms/a-global-reread-across-a-call-to-a-visible-static-needs-volatile.md,
 * which is about the opposite case), it is just an extern the compiler cannot
 * see through.
 *
 * The zero passed to CLACT_SetSystemActive and the null stored back at the end are the
 * same register: the constant is materialised once into r5 and the argument
 * copied off it
 * (docs/idioms/a-small-constant-is-rematerialised-off-a-zero-register-unless-an-argument-shares-it.md).
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/CLACT_ExitSystem.c \
 *       --func CLACT_ExitSystem --addr 0x0204A5AC --cc 1.1p1 --arm
 */
void CLACT_ExitSystem(void)
{
    CLACT_SetSystemActive(0);
    CLACT_ExitOamManagers(&g_ClactSystem->oam_mgrs);
    CLACT_ExitRenderer(&g_ClactSystem->renderer);
    CLACT_ExitTransferPool(&g_ClactSystem->transfer);
    CLACT_ExitResources((struct ClactRes *)((u8 *)g_ClactSystem + 0x104));
    GFL_HEAP_Free(g_ClactSystem);
    g_ClactSystem = 0;
}

/*
 * note:     re-verified 2026-09-20: MATCH; see verify output
 */
void CLACT_DrawSystem(void)
{
    struct Sys *sys = g_ClactSystem;

    if (sys == 0) {
        return;
    }

    CLACT_SetSystemActive(0);
    CLACT_ResetOamIfPending();
    CLACT_DrawAllUnits();

    sys = g_ClactSystem;
    if (sys->transfer.ready != 0) {
        NNS_G2dUpdateCellTransferStateManager();
    }

    CLACT_SetSystemActive(1);
}

/*
 * The cell-actor manager's teardown pass, and the exact inverse of
 * src/pending/CLACT_DrawSystem.c: each guard re-reads the context pointer from
 * its slot (the two `popeq` exits are the short-circuit returns, which is why
 * neither guard is predicated), the +0xEC latch decides whether the +0xE0
 * sub-object is released, and the flag goes back to 1.
 *
 * The 0x0204BCF4 call site resolves off the `label` class (its own
 * src/pending/CLACT_ApplyOamManagers.c is capped, but the branch has witnesses outside
 * this range), so this file is EXACT.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/CLACT_VBlankSystem.c \
 *       --func CLACT_VBlankSystem --addr 0x0204A648 --cc 1.1p1 --arm
 */
void CLACT_VBlankSystem(void)
{
    if (g_ClactSystem == 0)
        return;
    if (CLACT_IsSystemActive() == 0)
        return;

    CLACT_ApplyOamManagers(&g_ClactSystem->oam_mgrs);

    if (g_ClactSystem->transfer.ready != 0)
        CLACT_ExecuteTransfers(&g_ClactSystem->transfer);

    CLACT_SetOamPending(1);
}

/*
 * Cell-actor latch-only tick: latch off, flush the actor unit list, latch
 * back on.  No render update compared with CLACT_DrawSystem.
 */
void CLACT_FlushOamIfPending(void)
{
    if (g_ClactSystem == 0) {
        return;
    }
    CLACT_SetSystemActive(0);
    CLACT_ResetOamIfPending();
    CLACT_SetSystemActive(1);
}

/*
 * Claims the first entry of the display-object table (0x40-byte slots at
 * +0x08 of the owner block, 0x104 into the object at 0x02146A74) whose
 * pending bit (bit 31 of +0x3c) is set, loads the object for it through
 * CLACT_LoadArchiveData, publishes it with CLACT_SetupCharacter, frees the handle, then
 * clears +0x24 and bit 0 of +0x3c.  Returns the slot index, or -1 when
 * nothing was waiting.  Sibling of CLACT_RegisterEmptyCharacter.
 *
 * Shape notes (docs/notes/CLACT_RegisterCharacter.c.txt has the full history):
 *  - `count` is volatile (reread every iteration), `sys` is kept live for
 *    the slot address, and the not-found exit falls out of the loop past a
 *    goto.
 *  - The body sits inside `if (i != (u32)-1) { ... return i; }` with a
 *    trailing `return -1;`.  The early-return spelling
 *    `if (i == (u32)-1) return -1;` gets every byte right except the order
 *    of `mov r8, r0` (the handle) and `mov r7, #0` (the shared zero) after
 *    the load call (4 out, flat over five waves).  See
 *    docs/idioms/an-inverted-guard-returns-the-compare-constant-register.md.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/CLACT_RegisterCharacter.c  *       --func CLACT_RegisterCharacter --addr 0x0204A6C8 --cc 1.1p1 --arm
 */
s32 CLACT_RegisterCharacter(void *archive, u32 file_idx, u32 compressed, u32 vram_mode, u16 heap_id)
{
    struct Sys   *sys;
    struct ClactRes *res;
    struct CharSlot  *slot;
    u32 i;
    uptr file;

    sys   = g_ClactSystem;
    res = &sys->res;

    for (i = 0; i < res->n_chars; i++) {
        if (res->chars[i].free != 0) {
            goto found;
        }
    }
    i = (u32)-1;

found:
    if (i != (u32)-1) {
        slot   = &sys->res.chars[i];
        file = (uptr)CLACT_LoadArchiveData(archive, file_idx, compressed, (u16)((heap_id & 0x7fff) | 0x8000));

        CLACT_SetupCharacter(&g_ClactSystem->res, i, file, vram_mode, 0);
        GFL_HEAP_Free((void *)file);

        slot->data = 0;
        slot->data_shared = 0;
        return i;
    }
    return -1;
}

/*
 * Claims the first busy cell (bit 31 of +0x3c) of the singleton's table at
 * +0x104, like its sibling CLACT_RegisterCharacter, but builds a fresh character
 * record: the 0x18-byte template at 0x020A1430 is copied to the stack, the
 * DISPCNT OBJ-mapping bits and the size patched in, and the sixth word
 * holds a scratch block from GFL_HEAP_Alloc (clact.c, line 0x3c8) that is
 * registered through CLACT_SetupCharacterVram and freed at the end.  Returns the cell
 * index, or -1 when none is found.
 *
 * Shape notes:
 *  - `struct CharSlot *slot` is declared before `u32 i` (wave 18): that order
 *    gives the image's whole allocation (size r8, vram_mode r7, heapId lr, the -1
 *    in sb, i r6, slot r5, &t r4).
 *  - The body sits inside `if (i != (u32)-1) { ... return i; }` with a
 *    trailing `return -1;`.  The image returns the compare's -1 register
 *    (`moveq r0, sb`).  An early `if (i == -1) return i;` returns r6
 *    (1 out); an early `return -1;` recolours the function (47).  With the
 *    guard inverted the -1 is returned from the same register the compare
 *    used and the colouring is kept.  See
 *    docs/idioms/an-inverted-guard-returns-the-compare-constant-register.md.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/CLACT_RegisterEmptyCharacter.c  *       --func CLACT_RegisterEmptyCharacter --addr 0x0204A7A0 --cc 1.1p1 --arm
 */
s32 CLACT_RegisterEmptyCharacter(u32 size, u32 vram_mode, u16 heapId)
{
    struct Sys   *sys;
    struct ClactRes *res;
    struct CharSlot  *slot;
    u32 i;
    NNSG2dCharacterData char_data;

    sys   = g_ClactSystem;
    res = &sys->res;

    for (i = 0; i < res->n_chars; i++) {
        if (res->chars[i].free != 0) {
            goto found;
        }
    }
    i = (u32)-1;

found:
    if (i != (u32)-1) {
        slot = &sys->res.chars[i];
        char_data = g_ClactEmptyCharTemplate;
        char_data.mapingType = *(volatile u32 *)REG_DISPCNT_ADDR & 0x00300010;
        char_data.szByte = size;
        char_data.pRawData = GFL_HEAP_Alloc((u16)((heapId & 0x7fff) | 0x8000), size, 1, s_clact_c, 0x3c8);

        CLACT_SetupCharacterVram((struct ClactRes *)(&g_ClactSystem->res), i, (NNSG2dCharacterData *)(&char_data), 0, vram_mode);

        slot->free = 0;
        slot->data = 0;
        slot->data_shared = 0;
        GFL_HEAP_Free(char_data.pRawData);
        return i;
    }
    return -1;
}

/*
 * Retire one slot of the 0x40-byte table at +0x10c of the singleton behind
 * 0x02146A74.  The two eight-byte sub-objects at +0x2c and +0x34 are returned
 * to their owners (+0x104 and +0x108) unless VMAN_IsHandleInvalid says they are
 * already detached, the payload at +0x24 is released, and the flag word at
 * +0x3c ends as "top bit set, everything else clear".
 *
 * Nothing is cached: every one of the eleven accesses reloads g_ClactSystem and
 * re-indexes, because each intervening store may alias the global pointer
 * (docs/idioms/const-pointer-lets-a-field-load-survive-a-store.md read from
 * the other side, the same shape as src/matched/CLACT_ReleasePalette.c).  The payload
 * pointer is the one exception: it is bound to a local, which is why the `bl`
 * to GFL_HEAP_Free needs no load in front of it.
 *
 * +0x3c is a bitfield word, not a mask word.  The evidence is the guard:
 * `lsl #31` / `lsrs #31` to read bit 0, where a plain `x & 1` compiles to
 * `ands` (docs/idioms/shift-pair-with-no-matching-type-is-a-bitfield.md).
 * The other two writes confirm the partition: `bic`+`orr` with 0x80000000 is
 * an assignment to the one-bit field at bit 31, and `and #0x80000001` is an
 * assignment of zero to the thirty-bit field between them.  Field order is
 * LSB first, as in CLACT_ReleasePalette.c.
 *
 * The release is the fall-through and the flag clear is the `else`, so the
 * guard is spelled `== 0` and the short arm is left to be if-converted into
 * `bicne`/`strne` (docs/idioms/the-fall-through-arm-is-the-source-order.md).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/CLACT_ReleaseCharacter.c \
 *       --func CLACT_ReleaseCharacter --addr 0x0204A8D4 --cc 1.1p1 --arm
 */
void CLACT_ReleaseCharacter(u32 idx)
{
    void *payload;

    if (VMAN_IsHandleInvalid((struct VmanHandle *)(&g_ClactSystem->res.chars[idx].main_block)) == 0) {
        VMAN_Free((struct VmanBank *)g_ClactSystem->res.vram_main, (struct VmanHandle *)(&g_ClactSystem->res.chars[idx].main_block));
    }

    if (VMAN_IsHandleInvalid((struct VmanHandle *)(&g_ClactSystem->res.chars[idx].sub_block)) == 0) {
        VMAN_Free((struct VmanBank *)g_ClactSystem->res.vram_sub, (struct VmanHandle *)(&g_ClactSystem->res.chars[idx].sub_block));
    }

    payload = g_ClactSystem->res.chars[idx].data;
    if (payload != 0) {
        if (g_ClactSystem->res.chars[idx].data_shared == 0) {
            GFL_HEAP_Free(payload);
        } else {
            g_ClactSystem->res.chars[idx].data_shared = 0;
        }
        g_ClactSystem->res.chars[idx].data = 0;
    }

    g_ClactSystem->res.chars[idx].free = 1;
    g_ClactSystem->res.chars[idx].vram_size = 0;
}

void CLACT_TransferCharacter(int idx, NNSG2dCharacterData *char_data)
{
    if (NNSi_G2dIsVramHandleSet((const u32 *)((uptr)g_ClactSystem->res.chars + (idx << 6)), 1) != 0) {
        void *vram_addr = (void *)NNSi_G2dGetVramHandleValue((int *)((uptr)g_ClactSystem->res.chars + (idx << 6)), 1);
        DC_FlushRange((void *)char_data->pRawData, char_data->szByte);
        GX_LoadOBJ((void *)char_data->pRawData, (uptr)vram_addr, char_data->szByte);
    }
    if (NNSi_G2dIsVramHandleSet((const u32 *)((uptr)g_ClactSystem->res.chars + (idx << 6)), 2) == 0)
        return;
    {
        void *vram_addr = (void *)NNSi_G2dGetVramHandleValue((int *)((uptr)g_ClactSystem->res.chars + (idx << 6)), 2);
        DC_FlushRange((void *)char_data->pRawData, char_data->szByte);
        GXS_LoadOBJ((void *)char_data->pRawData, (uptr)vram_addr, char_data->szByte);
    }
}

void CLACT_TransferCharacterPart(int idx, void *src, u32 size, int offset, int target)
{
    if (target == 0 || target == 2) {
        if (NNSi_G2dIsVramHandleSet((const u32 *)((uptr)g_ClactSystem->res.chars + (idx << 6)), 1) != 0) {
            void *vram_addr = (void *)NNSi_G2dGetVramHandleValue((int *)((uptr)g_ClactSystem->res.chars + (idx << 6)), 1);
            DC_FlushRange(src, size);
            GX_LoadOBJ(src, (uptr)vram_addr + offset, size);
        }
    }
    if (target == 1 || target == 2) {
        if (NNSi_G2dIsVramHandleSet((const u32 *)((uptr)g_ClactSystem->res.chars + (idx << 6)), 2) == 0)
            return;
        {
            void *vram_addr = (void *)NNSi_G2dGetVramHandleValue((int *)((uptr)g_ClactSystem->res.chars + (idx << 6)), 2);
            DC_FlushRange(src, size);
            GXS_LoadOBJ(src, (uptr)vram_addr + offset, size);
        }
    }
}

/*
 * Copy the 36-byte header of a 64-byte-stride record out of the actor
 * table hung off the manager's pointer member at +0x10c into the caller's
 * buffer.  The whole copy is one aggregate assignment: two ldm/stm pairs
 * of four registers and a trailing word.
 */
void CLACT_GetCharacterProxy(u32 idx, struct ImageProxy *out)
{
    struct ImageProxy *slot_proxy = (struct ImageProxy *)((u8 *)g_ClactSystem->res.chars + idx * 64);

    *out = *slot_proxy;
}

/*
 * Snapshot one actor record into a local 36-byte buffer and hand it to
 * NNSi_G2dGetVramHandleValue with mode 1, or mode 2 when the second argument is set.
 */
int CLACT_GetCharacterVramAddress(u32 idx, u32 flag)
{
    struct ImageProxy buf;
    u32 mode = 1;

    if (flag != 0) {
        mode = 2;
    }
    CLACT_GetCharacterProxy(idx, &buf);
    return NNSi_G2dGetVramHandleValue((int *)(&buf), mode);
}

/*
 * The short-form entry point of CLACT_RegisterPaletteEx: same call with the two
 * optional halfword parameters defaulted to zero.
 *
 * All the frame does is rebuild the stack half of the argument list.  The
 * four register arguments pass through untouched, so nothing in the body
 * mentions them; `sub sp, sp, #0xc` is the callee's three stack words, the
 * two zeros go in the first two, and the caller's own single stack argument
 * is copied from +0x10 (four bytes of saved lr plus the twelve just
 * reserved) into the third.  It is read with `ldrh`, which is what fixes
 * that parameter as a halfword rather than a word.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/CLACT_RegisterPalette.c \
 *       --func CLACT_RegisterPalette --addr 0x0204ABF0 --cc 1.1p1 --arm
 */
s32 CLACT_RegisterPalette(void *archive, u32 file_idx, u32 vram_mode, u32 vram_offset, u16 heap_id)
{
    return CLACT_RegisterPaletteEx(archive, file_idx, vram_mode, vram_offset, 0, 0, heap_id);
}

/*
 *           the call inside this function, so `label` has no outside witness
 *           and no manifest entry covers it yet.  File 0x0204DD08 first and
 *           this graduates with no change to its C.
 */
s32 CLACT_RegisterPaletteEx(void *archive, u32 file_idx, u32 vram_mode, u32 vram_offset, u16 first_color, u16 color_count, u16 heap_id)
{
    struct ClactRes *res;
    u32 i;
    uptr file;

    res = &g_ClactSystem->res;

    for (i = 0; i < res->n_pltts; i++) {
        if (res->pltts[i].free != 0) {
            goto found;
        }
    }
    i = (u32)-1;

found:
    if (i == (u32)-1) {
        return i;
    }

    file = (uptr)ARC_TOOL_LoadHandleMember(archive, file_idx, (u16)((heap_id & 0x7fff) | 0x8000));

    CLACT_TransferPaletteData((struct ClactRes *)(&g_ClactSystem->res), i, (void *)file, (void *)vram_mode, vram_offset, first_color, color_count);
    GFL_HEAP_Free((void *)file);

    return i;
}

/*
 * The clact.c record-claim scan: walk the ClRes cell table for a free slot
 * (bit 31 of the element's +0x14 word), load the archive member into it and
 * return the index, or -1.
 *
 * TWO LEVERS, and it is their COMBINATION that closes it.  docs/notes/
 * pkt_0204ACEC.c.txt had each of them separately and measured each as a loss:
 *
 *  1. A named `Inner0204ACEC *in` local for the +0x104 sub-object.  Without it
 *     mwcc 1.1p1 splits the 0x11a count offset as base 0x100 + 0x1a (the ldrh
 *     8-bit immediate reaches 0x1a from 0x100) and reaches `arr` straight off
 *     the global at +0x110 (inside the ldr 12-bit immediate), so the two
 *     fields never share a base.  The image materialises `g + 0x104` once and
 *     reads both through it: `add r7, r2, #0x104` / `ldrh r2, [r7, #0x16]` /
 *     `ldr ip, [r7, #0xc]`.  Nested sub-structs and casts all fold back to the
 *     0x100 base; only a live local pointer emits the 0x104 add.  The note
 *     measured this alone at 109-138 bytes out, because it also hoists the
 *     loop bound and drops the image's back-edge count re-read.
 *  2. `volatile u16 count`, which restores that back-edge re-read
 *     (`ldrh r3, [r7, #0x16]` at +0x40).  The note measured THIS alone at
 *     188 bytes against 184 -- four bytes long -- because with the 0x100 base
 *     the volatile load costs an extra instruction it does not pay for.
 *
 * Together they are exact: the local pointer removes the base split, and the
 * volatile puts back the one load the local pointer's hoist removed.  Each
 * lever alone is a regression; the pair is EXACT.  tools/permuter.py could not
 * move the 17-byte no-local baseline at all (169 single mutations), which is
 * the declarations-not-allocation signature.
 *
 * Verified with:
 *   python3 tools/match.py one --src src/matched/CLACT_RegisterPaletteCompressed.c \
 *       --func CLACT_RegisterPaletteCompressed --addr 0x0204ACEC --cc 1.1p1 --arm
 */
int CLACT_RegisterPaletteCompressed(void *archive, u32 file_idx, u32 vram_mode, u32 vram_offset, u16 heap_id)
{
    struct ClactRes *res = &g_ClactSystem->res;
    u32 i;
    void *file;
    struct PlttSlot *slots;

    for (i = 0; i < res->n_pltts; i++) {
        slots = (struct PlttSlot *)res->pltts;
        if (slots[i].free != 0)
            goto found;
    }
    i = -1;
found:
    if (i == (u32)-1)
        return (int)i;
    file = ARC_TOOL_LoadHandleMember(archive, file_idx, (u16)((heap_id & 0x7fff) | 0x8000));
    CLACT_TransferPaletteDataEx((struct ClactRes *)(&g_ClactSystem->res), i, file, (void *)vram_mode, vram_offset);
    GFL_HEAP_Free(file);
    return (int)i;
}

/*
 * Reset one entry of the 0x18-byte table hanging off +0x110 of the
 * singleton at 0x02146A74: set the top bit of the word at +0x14 and clear
 * the other 31 bits under it.
 *
 * The two statements do not share one address computation, even though
 * there is no call between them: the `str` of the first statement may
 * alias the global pointer itself, so the compiler has to reload
 * g_ClactSystem and re-index before the second
 * (docs/idioms/const-pointer-lets-a-field-load-survive-a-store.md, read
 * from the other side).  The index multiply is a real `mul` by a
 * register-held 0x18, not a shift pair, because 24 is not a power of two.
 *
 * `bic` immediately followed by `orr` with the same constant is the
 * bitfield-assignment shape, not a redundant pair: the field is cleared
 * and then the value inserted, and the value happening to be the constant
 * 1 does not collapse the two.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/CLACT_ReleasePalette.c \
 *       --func CLACT_ReleasePalette --addr 0x0204ADA4 --cc 1.1p1 --arm
 */
void CLACT_ReleasePalette(u32 idx)
{
    g_ClactSystem->res.pltts[idx].free = 1;
    g_ClactSystem->res.pltts[idx].size = 0;
}

/*
 * Flush both halves of one slot of the 0x18-byte-stride table at +0x110 of
 * the singleton behind 0x02146A74 into the destination the caller supplies.
 * Each half is guarded by NNSi_G2dIsVramHandleSetEx, fetched with NNSi_G2dGetVramHandleEx and
 * written through GX_LoadOBJPltt (selector 1) or GXS_LoadOBJPltt (selector 2),
 * with DC_FlushRange invalidating the destination first.
 *
 * `count` is in 32-byte units; zero means "use the length the destination
 * already records at +8" instead.  The shift happens unconditionally and is
 * overwritten by the predicated `ldreq`, so the guard has to be written as
 * a plain `if` after the shift, not as a ternary around it.
 *
 * The slot offset `idx * 0x18` is a named local `off`, declared before
 * `size` and assigned after the guard, and added to the table base as an
 * integer.  Written as `&pltts[idx]`, the offset becomes a CSE temporary,
 * which mwcc numbers before every named local: `size` then takes r4 and the
 * offset r5, the original's assignment swapped.  The named `off` keeps its
 * own register (declared first, it is coloured first and takes r4), and the
 * integer add keeps expression propagation from folding it back into each
 * use.  All seven callers pass three arguments.
 */
void CLACT_TransferPalette(u32 idx, struct PaletteData *dest, u32 count)
{
    u32 off;
    u32 size;

    size = count << 5;

    if (count == 0) {
        size = dest->size;
    }
    off = idx * sizeof(struct PlttSlot);

    if (NNSi_G2dIsVramHandleSetEx((char *)((uptr)g_ClactSystem->res.pltts + off), 1) != 0) {
        void *src = (void *)NNSi_G2dGetVramHandleEx((char *)((uptr)g_ClactSystem->res.pltts + off), 1);

        DC_FlushRange((void *)dest->raw, size);
        GX_LoadOBJPltt((void *)dest->raw, (uptr)src, size);
    }

    if (NNSi_G2dIsVramHandleSetEx((char *)((uptr)g_ClactSystem->res.pltts + off), 2) != 0) {
        void *src = (void *)NNSi_G2dGetVramHandleEx((char *)((uptr)g_ClactSystem->res.pltts + off), 2);

        DC_FlushRange((void *)dest->raw, size);
        GXS_LoadOBJPltt((void *)dest->raw, (uptr)src, size);
    }
}

/*
 * A getter and its one caller.  CLACT_GetPaletteProxy copies the 0x14-byte record
 * out of slot `idx` of the 0x18-byte-stride table at +0x110 of the
 * singleton behind 0x02146A74; the copy is an inlined `ldm`/`stm` pair plus
 * a trailing word, which is what a whole-struct assignment of this size
 * compiles to (docs/idioms/aggregate-assignment-is-ldm-stm.md).
 * CLACT_GetPaletteVramAddress takes that copy on its own stack and submits it to
 * NNSi_G2dGetVramHandleEx under selector 1 or 2.
 *
 * Kept as one unit so the `bl` at CLACT_GetPaletteVramAddress+0x1c is `local`:
 * CLACT_GetPaletteVramAddress is CLACT_GetPaletteProxy's only caller image-wide, so split into two
 * files the site would have no witness of any class.
 */
void CLACT_GetPaletteProxy(u32 idx, struct PaletteProxy *dest)
{
    *dest = g_ClactSystem->res.pltts[idx].proxy;
}

int CLACT_GetPaletteVramAddress(u32 idx, u32 alternate)
{
    struct PaletteProxy record;
    u32 selector;

    selector = 1;
    if (alternate != 0) {
        selector = 2;
    }

    CLACT_GetPaletteProxy(idx, &record);
    return NNSi_G2dGetVramHandleEx((char *)(&record), selector);
}

/*
 * Claim the first live slot of the 0x14-byte entry pool that lives at
 * +0x104 of the singleton behind 0x02146A74, build its two handles through
 * ARC_TOOL_LoadHandleMember (same owner and same mode for both, second argument
 * differing), publish the pair with CLACT_LoadCellAnimBanks and hand the slot index
 * back.
 *
 * The scan is an inlined helper, which is what puts the "not found" answer
 * on its own block: the `bne` out of the loop is the `return i` and the
 * `mvn sl, #0` it jumps over is the `return -1`.  Note that -1 is not
 * checked before it is used as a subscript, so a pool with no live entry
 * writes one stride below the array; that is the original's behaviour, not
 * a transcription slip.
 *
 * `count` is spelled `volatile` purely as a codegen device, not as a claim
 * about the hardware: without it the compiler proves the entry loads cannot
 * touch the halfword, CSEs the guard's read with the latch's, and the
 * resulting one-instruction-shorter loop shifts the whole tail by four
 * bytes.  The original reloads +0x18 on every iteration while keeping the
 * entries base cached, which is what the volatile reproduces.  The loop
 * must also be the guard-plus-do-while form: a plain `for` hoists the
 * entries load above the guard.
 *
 * Previously capped at MATCH: the PC24 at +0xa0 (CLACT_LoadCellAnimBanks) had no
 * witness outside 0204AF28..0204AFD8, this function being 0x0204E074's only
 * caller image-wide.  src/matched/CLACT_LoadCellAnimBanks.c now reproduces that range
 * EXACT, so the site resolves in the `matched` class and the file is EXACT.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/CLACT_RegisterCellAnim.c \
 *       --func CLACT_RegisterCellAnim --addr 0x0204AF28 --cc 1.1p1 --arm
 */
s32 CLACT_RegisterCellAnim(void *archive, u32 cell_file_idx, u32 anim_file_idx, u32 heap_id)
{
    struct ClactRes *res = &g_ClactSystem->res;
    struct CellSlot *slot;
    s32 idx;

    struct CellSlot *slots;

    idx = 0;
    if ((u32)idx < res->n_cells) {
        slots = res->cells;
        do {
            if (slots[idx].free != 0) {
                goto found;
            }
            idx++;
        } while ((u32)idx < res->n_cells);
    }
    idx = -1;
found:
    slot = &g_ClactSystem->res.cells[idx];

    slot->cell_file = ARC_TOOL_LoadHandleMember(archive, cell_file_idx, heap_id);
    slot->anim_file = ARC_TOOL_LoadHandleMember(archive, anim_file_idx, heap_id);

    CLACT_LoadCellAnimBanks(&g_ClactSystem->res, idx, slot->cell_file, slot->anim_file);

    return idx;
}

/*
 * Tear down one entry of the 0x14-byte table hanging off +0x114 of the
 * singleton at 0x02146A74: free the two payload pointers at +0 and +4 if
 * they are set, NULL them, and mark the slot free with 1 at +0x10.
 *
 * The entry address is bound to a named local (r4) and survives both
 * calls, so neither the global nor the index multiply is recomputed after
 * the first store, unlike CLACT_ReleasePalette next door
 * (docs/idioms/keeping-a-cursor-in-a-named-local-costs-a-callee-saved-register.md).
 * The first load reads through the register-offset form `ldr r0,[r2,r1]`
 * before the `add` that materialises the cursor; that is scheduling, not
 * a second addressing mode in the source.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/CLACT_ReleaseCellAnim.c \
 *       --func CLACT_ReleaseCellAnim --addr 0x0204AFD8 --cc 1.1p1 --arm
 */
void CLACT_ReleaseCellAnim(u32 idx)
{
    struct CellSlot *slot = &g_ClactSystem->res.cells[idx];

    if (slot->cell_file != 0) {
        GFL_HEAP_Free(slot->cell_file);
        slot->cell_file = 0;
    }
    if (slot->anim_file != 0) {
        GFL_HEAP_Free(slot->anim_file);
        slot->anim_file = 0;
    }
    slot->free = 1;
}

/*
 * clact.c's 0xA0-byte cell-actor allocation helper: carve the record with the
 * three-argument allocator, hand it and the caller's three values to the
 * record initialiser, and return the record.  The third parameter is the heap
 * id and reaches the allocator as its first argument, so the two call sites
 * do not share an argument order.
 *
 * The file string at 0x020A7F74 is "clact.c" and the stacked fifth argument
 * is __LINE__ = 0x633; declared as an extern array pinned by address, never
 * as a literal __FILE__.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/CLACT_CreateRenderer.c \
 *       --func CLACT_CreateRenderer --addr 0x0204B034 --cc 1.1p1 --arm
 */
struct Renderer *CLACT_CreateRenderer(const struct SurfaceInit *inits, u32 count, u32 heap_id)
{
    struct Renderer *renderer = GFL_HEAP_Alloc(heap_id, sizeof(struct Renderer), 0, s_clact_c, 0x633);

    CLACT_InitRenderer(renderer, inits, count, heap_id);
    return renderer;
}

void CLACT_DeleteRenderer(struct Renderer *renderer)
{
    CLACT_ExitRenderer(renderer);
    GFL_HEAP_Free(renderer);
}

/*
 * Unlabelled arm9 leaf (the label at 0x0204B09C also spans the next leaf at
 * 0x0204B0C8); witness for ov021 FIELD_MENU_UpdateActorsForScroll. Writes a 16-bit x/y pair,
 * scaled to fx32, into entry idx (0x48 bytes each) of the table at +0x98.
 */
void CLACT_SetSurfacePos(struct Renderer *renderer, int idx, struct ClactVec2 *pos)
{
    int x = pos->x;
    int y = pos->y;
    struct Surface *surface = &renderer->surfaces[idx];
    surface->x = x << 12;
    surface->y = y << 12;
}

/*
 * EXACT*, not EXACT: the listing extent runs 12 bytes long because what
 * follows at 0x0204B0F4 is not code from this file at all, it is a linker
 * veneer, `ldr ip, [pc]; bx ip; .word 0x0204BE38`
 * (docs/idioms/a-four-byte-arm-function-in-a-thumb-packet-is-a-long-branch-veneer.md
 * describes the Thumb-side form of the same stub).  0x0204B0F4 is a seed for
 * layout/function_starts.txt, and no `tu` range may span it.
 *
 * Read back one cell actor's position: the 0x48-byte records hang off +0x98 of
 * the owner, their first two words are the x and y coordinates in 20.12 fixed
 * point, and the caller gets them as a pair of whole-pixel s16 values.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/CLACT_GetSurfacePos.c \
 *       --func CLACT_GetSurfacePos --addr 0x0204B0C8 --cc 1.1p1 --arm
 */
void CLACT_GetSurfacePos(struct Renderer *renderer, u32 surface_idx, struct ClactVec2 *out)
{
    struct Surface *surface = &renderer->surfaces[surface_idx];

    out->x = surface->x >> 12;
    out->y = surface->y >> 12;
}

void CLACT_SetRendererCulling(struct Renderer *renderer, int enable)
{
    CLACT_SetSurfaceCulling(renderer, enable);
}

/*
 * The cell-actor unit constructor.  The __FILE__ pointer is the same
 * s_clact_c 0x020A7F74 that src/matched/CLACT_LoadArchiveData.c pins, so this whole
 * 0x0204Bxxx run is clact.c.
 *
 * Allocate the 0x18-byte unit header, zero it, allocate `count` 0xE4-byte
 * actor records behind it, record the count at +0x0c and the caller's flag at
 * +0x0f, run each record through CLACT_ClearActor, then the three unit-wide
 * initialisers.  src/matched/CLACT_DeleteUnit.c is the exact inverse.
 *
 * The two allocation sites are one pool word apart in the source's line
 * numbering: 0x6eb is materialised from the literal pool and 0x6ef is derived
 * with `add r0, r5, #4`
 * (docs/idioms/consecutive-line-numbers-are-one-pool-word-and-adds.md), so
 * the second call has to be written with the literal 0x6ef, not with a second
 * pooled constant.
 *
 * The zero shared by the two `clear` arguments, the fill byte and the loop
 * counter all live in r7 for the whole function; `i` therefore has to be a
 * function-scope local, not declared inside the `for`.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/CLACT_CreateUnit.c \
 *       --func CLACT_CreateUnit --addr 0x0204B100 --cc 1.1p1 --arm
 */
struct Unit *CLACT_CreateUnit(int count, u8 priority, u32 heapId)
{
    struct Unit *unit;
    int          i;

    unit = GFL_HEAP_Alloc(heapId, sizeof(struct Unit), 0, s_clact_c, 0x6eb);
    MI_CpuFill8(unit, 0, sizeof(struct Unit));

    unit->actors = GFL_HEAP_Alloc(heapId, count * sizeof(struct ClactActor), 0,
                                s_clact_c, 0x6ef);
    unit->count = count;
    unit->priority = priority;

    for (i = 0; i < count; i++) {
        CLACT_ClearActor(&unit->actors[i]);
    }

    CLACT_SetUnitDefaultRenderer(unit);
    CLACT_SetUnitDrawEnable(unit, 1);
    CLACT_LinkUnit(unit);

    return unit;
}

/*
 * The inverse of src/matched/CLACT_CreateUnit.c: quiesce the cell-actor unit,
 * tear down every live actor record, then free the record array and the unit
 * header.  An actor counts as live when its first word (the resource handle
 * src/matched/CLACT_DeleteActor.c hands back) is non-null.
 *
 * `unit->count` is re-read on every iteration because CLACT_DeleteActor is opaque
 * to the compiler, so the bound has to stay the field access in the `for`
 * condition rather than a local; the entry test at the top is the compiler's
 * own loop rotation of that same read, not a separate guard.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/CLACT_DeleteUnit.c \
 *       --func CLACT_DeleteUnit --addr 0x0204B1CC --cc 1.1p1 --arm
 */
u32 CLACT_DeleteUnit(struct Unit *unit)
{
    int i;

    CLACT_UnlinkUnit(unit);

    for (i = 0; i < unit->count; i++) {
        if (unit->actors[i].next != 0) {
            CLACT_DeleteActor(&unit->actors[i]);
        }
    }

    GFL_HEAP_Free(unit->actors);
    return GFL_HEAP_Free(unit);
}

/*
 * Three leaf accessors of clact.c's unit header, packed end to end with no
 * literal pool between them.  Only the first has a `func_` label in the
 * listing, because none of the three saves lr
 * (docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md); 0x0204B248 and
 * 0x0204B258 are unlabelled followers and are seeds for
 * layout/function_starts.txt.
 *
 * The byte at +0x0e is two 4-bit unsigned bitfields.  The low nibble is a
 * source selector paired with the pointer at +0x08: CLACT_SetUnitDefaultRenderer sets it to 0
 * for the shared default at g_ClactSystem + 0x40, and 0x0204B258 sets it to 1
 * for a caller-supplied pointer.  The high nibble is written by 0x0204B22C
 * and read back by 0x0204B248, and never appears next to the pointer, so it
 * is an independent mode.
 *
 * The nibble accesses are the giveaway: a plain u8 field masked and shifted
 * would fold to `ands`, while the write here is `bic` plus a shifted `orr`
 * and the read is the unequal `lsl #24` / `lsr #28` pair, which is a bitfield
 * extraction (docs/idioms/shift-pair-with-no-matching-type-is-a-bitfield.md).
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0204B22C.c \
 *       --addr 0x0204B22C --cc 1.1p1 --arm
 */
void CLACT_SetUnitDrawEnable(struct Unit *unit, u32 enable)
{
    unit->draw_enable = enable;
}

u32 CLACT_GetUnitDrawEnable(struct Unit *unit)
{
    return unit->draw_enable;
}

void CLACT_SetUnitRenderer(struct Unit *unit, void *renderer)
{
    unit->renderer = renderer;
    unit->source = 1;
}

/*
 * The companion of CLACT_SetUnitRenderer in src/matched/unit_0204B22C.c: point the
 * unit at the shared default block 0x40 bytes into whatever 0x02146A74 holds
 * and clear the low nibble of the flag byte at +0x0e back to source 0, where
 * CLACT_SetUnitRenderer sets it to 1 for a caller-supplied pointer.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/CLACT_SetUnitDefaultRenderer.c \
 *       --func CLACT_SetUnitDefaultRenderer --addr 0x0204B270 --cc 1.1p1 --arm
 */
void CLACT_SetUnitDefaultRenderer(struct Unit *unit)
{
    unit->renderer = &g_ClactSystem->renderer;
    unit->source = 0;
}

/*
 * Build a 0x20-byte request on the stack out of three of the singleton's
 * parallel tables, then dispatch it.  The singleton at 0x02146A74 carries
 * three table pointers in a row: 0x40-byte records at +0x10c, 0x18-byte
 * records at +0x110 and 0x14-byte records at +0x114.
 *
 * The global is read once and every index is computed off that one load,
 * because nothing between them can store to it; the two index multiplies
 * are real `mla`s against a register-held 0x18 and 0x14, since neither
 * size is a power of two, while the 0x40-byte stride folds into the
 * addressing as `add r3, r3, ip, lsl #6`.
 *
 * The `lsl #16` / `lsr #16` pairs on the two index arguments are the
 * narrowing casts CLACT_InitActorRequest's u16 parameters force at the call site,
 * not evidence that this function's own parameters are u16: the same
 * values are used untruncated as table indices a few instructions
 * earlier.  Reading them the other way (declaring the parameters u16)
 * would have to truncate before the multiplies too.
 *
 * The last two arguments come back off the caller's own stack with
 * `ldrh`, which is what names those two u16.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/CLACT_CreateActor.c \
 *       --func CLACT_CreateActor --addr 0x0204B294 --cc 1.1p1 --arm
 */
struct ClactActor *CLACT_CreateActor(struct Unit *unit, u32 char_idx, u32 pltt_idx, u32 cell_idx,
                        const struct ActorInitParam *init, u16 space, u16 heap_id)
{
    struct ActorReq req;

    CLACT_InitActorRequest(&req, char_idx, pltt_idx, &g_ClactSystem->res.chars[char_idx], &g_ClactSystem->res.pltts[pltt_idx],
                 g_ClactSystem->res.cells[cell_idx].cell_bank, g_ClactSystem->res.cells[cell_idx].anim_bank);
    return CLACT_CreateActorCore(unit, init, &req, space, heap_id);
}

/*
 * Same request-builder shape as CLACT_CreateActor: a 0x20-byte request is staged
 * on the stack from three of the singleton's parallel tables (0x40-byte
 * records at +0x10c, 0x18-byte records at +0x110, 0x14-byte records at
 * +0x114), then dispatched by CLACT_CreateActorFull, which is CLACT_CreateActorCore's
 * five-argument sibling.
 *
 * The last two arguments come back off the caller's own stack with `ldrh`,
 * which is what names those two u16; the fifth arrives with a plain `ldr`.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/CLACT_CreateAffineActor.c \
 *       --func CLACT_CreateAffineActor --addr 0x0204B324 --cc 1.1p1 --arm
 */
struct ClactActor *CLACT_CreateAffineActor(struct Unit *unit, u32 char_idx, u32 pltt_idx, u32 cell_idx, const struct ActorInit *init, u16 space, u16 heap_id)
{
    struct ActorReq req;

    CLACT_InitActorRequest((&req), char_idx, pltt_idx, (&g_ClactSystem->res.chars[char_idx]), (&g_ClactSystem->res.pltts[pltt_idx]),
                 g_ClactSystem->res.cells[cell_idx].cell_bank, g_ClactSystem->res.cells[cell_idx].anim_bank);
    return CLACT_CreateActorFull(unit, init, &req, space, heap_id);
}

/*
 * Tear-down for the 0x0204Bxxx object: hand the handle at +8 and the owner
 * to CLACT_UnlinkActor, run the embedded sub-object at +0x68 through
 * CLACT_ExitAnimCtl, then CLACT_ClearActor on the owner.
 *
 * This file was parked at MATCH on the PC24 site at +0x18: this is
 * 0x0204D104's only caller image-wide, and 0x0204D104 was itself stuck
 * because its handler table 0x020A13D0 appears in no other literal pool.
 * 0x020A13D0 is row 5 of the one array based at 0x020A1394, which is pooled
 * at 0x0204D490; src/matched/CLACT_ExitAnimCtl.c is now EXACT and attests this
 * site `matched`.  The C here is unchanged.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/CLACT_DeleteActor.c  *       --func CLACT_DeleteActor --addr 0x0204B3B4 --cc 1.1p1 --arm
 */
void CLACT_DeleteActor(struct ClactActor *actor)
{
    CLACT_UnlinkActor(actor->owner, actor);
    CLACT_ExitAnimCtl((&actor->ctl));
    CLACT_ClearActor(actor);
}

/*
 * A whole translation unit, matched as one byte range.
 *
 * Three consecutive members of one object's interface.  The object carries a
 * handle at +8, a packed flag word at +0x60 and an embedded sub-object at
 * +0x68 that the 0x0204Cxxx/0x0204Dxxx layer operates on.
 *
 *   CLACT_SetActorDrawEnable  set bit 26 of the flag word at +0x60.
 *   CLACT_GetActorDrawEnable  read it back.  Saves no lr, so disasm.py never labels it.
 *   CLACT_AddActorSurfacePos  move by a delta: ask CLACT_GetSurfaceOrigin for the current
 *                 position into a scratch pair, add the caller's s16 x/y
 *                 pair to it in a second scratch pair, and hand that to
 *                 CLACT_SetActorPos.
 *
 * The two 4-byte scratch pairs sit at sp+0 and sp+4; the later declaration
 * takes the lower stack address, so `pos` is declared before `dest`.
 *
 * The range deliberately starts at 0x0204B3DC rather than at this file's
 * real first function, CLACT_DeleteActor: that one's call to CLACT_ExitAnimCtl has
 * no witness anywhere in the image, so including it caps the whole unit at
 * MATCH.  --suggest-split names this exact cut; CLACT_DeleteActor is parked in
 * src/pending/CLACT_DeleteActor.c.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0204B3DC.c \
 *       --addr 0x0204B3DC --arm
 */
void CLACT_SetActorDrawEnable(struct ClactActor *actor, u32 value)
{
    actor->enabled = value;
}

u32 CLACT_GetActorDrawEnable(struct ClactActor *actor)
{
    return actor->enabled;
}

void CLACT_AddActorSurfacePos(struct ClactActor *actor, const struct ClactVec2 *delta, u32 which)
{
    struct ClactVec2 pos;
    struct ClactVec2 dest;

    CLACT_GetSurfaceOrigin(actor, which, (u16 *)(&pos));
    dest.x = delta->x + pos.x;
    dest.y = delta->y + pos.y;
    CLACT_SetActorPos(actor, (const struct Pt16 *)(&dest));
}

/*
 * Read the actor's screen position back in the coordinate space named by
 * `space`: CLACT_GetSurfaceOrigin fills in that space's origin, src/matched/CLACT_GetActorPos.c
 * fills in the absolute position, and the difference is written back over the
 * caller's buffer in place.
 *
 * The scratch pair is the `r3` slot of the prologue push rather than an
 * explicit `sub sp`, which is what a single four-byte local costs here.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/CLACT_GetActorSurfacePos.c \
 *       --func CLACT_GetActorSurfacePos --addr 0x0204B454 --cc 1.1p1 --arm
 */
void CLACT_GetActorSurfacePos(struct ClactActor *actor, struct ClactVec2 *out, u16 space)
{
    struct ClactVec2 origin;

    CLACT_GetSurfaceOrigin(actor, space, (u16 *)&origin);
    CLACT_GetActorPos(actor, (struct Pt16 *)out);

    out->x = out->x - origin.x;
    out->y = out->y - origin.y;
}

/*
 * The write side of src/matched/CLACT_GetActorSurfacePosAxis.c: set one axis of the actor's
 * position, given in the coordinate space named by `space`.
 *
 * THE LEVER (wave 18, lane ties_b; it was DIFF 76/80 for four waves,
 * docs/notes/CLACT_SetActorSurfacePosAxis.c.txt): the origin is added to the s16 parameter
 * by COMPOUND assignment in each arm, `value += origin.x;`. The image keeps
 * the narrowed sum in the parameter's home register r6 and copies it into r1
 * for the call; `value = value + origin.x` (or a fresh local, or one
 * expression) lets 1.1p1 narrow straight into r1 and elide the copy, four
 * bytes short.
 */
void CLACT_SetActorSurfacePosAxis(struct ClactActor *actor, s16 value, u32 space, u32 axis)
{
    struct ClactVec2 origin;

    CLACT_GetSurfaceOrigin(actor, space, (unsigned short *)&origin);

    if (axis == 0) {
        value += origin.x;
    } else {
        value += origin.y;
    }

    CLACT_SetActorPosAxis(actor, value, axis);
}

/*
 * The read side of src/matched/CLACT_SetActorSurfacePosAxis.c: one axis of the actor's
 * position, expressed in the coordinate space named by `space`.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/CLACT_GetActorSurfacePosAxis.c \
 *       --func CLACT_GetActorSurfacePosAxis --addr 0x0204B4EC --cc 1.1p1 --arm
 */
s16 CLACT_GetActorSurfacePosAxis(struct ClactActor *actor, u32 space, u32 axis)
{
    struct ClactVec2 origin;
    s16        pos_value;
    s16        origin_value;

    CLACT_GetSurfaceOrigin(actor, space, (unsigned short *)&origin);
    pos_value = CLACT_GetActorPosAxis(actor, axis);

    if (axis == 0) {
        origin_value = origin.x;
    } else {
        origin_value = origin.y;
    }

    return pos_value - origin_value;
}

/*
 * Store the actor's screen position pair at +0x0c/+0x0e.  Copied field by
 * field rather than as a four-byte aggregate: a struct assignment of this
 * size would be one `ldr`/`str` pair
 * (docs/idioms/aggregate-assignment-is-ldm-stm.md), and the original spells
 * out two halfword moves instead.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/CLACT_SetActorPos.c \
 *       --func CLACT_SetActorPos --addr 0x0204B528 --cc 1.1p1 --arm
 */
void CLACT_SetActorPos(struct ClactActor *actor, const struct Pt16 *pos)
{
    actor->pos.x = pos->x;
    actor->pos.y = pos->y;
}

/*
 * The read side of src/matched/CLACT_SetActorPos.c: copy the actor's screen
 * position pair out of +0x0c/+0x0e, field by field.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/CLACT_GetActorPos.c \
 *       --func CLACT_GetActorPos --addr 0x0204B53C --cc 1.1p1 --arm
 */
void CLACT_GetActorPos(const struct ClactActor *actor, struct Pt16 *out)
{
    out->x = actor->pos.x;
    out->y = actor->pos.y;
}

/*
 * Write one axis of the actor's screen position: axis 0 is x at +0x0c, any
 * other value is y at +0x0e.  Both arms are a single store, so the compiler
 * if-converts the whole body to `strheq`/`strhne` and the function has no
 * branch at all.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/CLACT_SetActorPosAxis.c \
 *       --func CLACT_SetActorPosAxis --addr 0x0204B550 --cc 1.1p1 --arm
 */
void CLACT_SetActorPosAxis(struct ClactActor *actor, signed short value, u32 axis)
{
    if (axis == 0) {
        actor->pos.x = value;
    } else {
        actor->pos.y = value;
    }
}

/*
 * The read side of src/matched/CLACT_SetActorPosAxis.c: one axis of the actor's screen
 * position, axis 0 being x at +0x0c.  Both arms are a single load, so the body
 * if-converts to `ldrsheq`/`ldrshne`.
 *
 * The `ldrsh` is the signedness tell
 * (docs/idioms/ldrsh-register-offset-is-signedness.md, here in its
 * immediate-offset form): the stored field itself is u16, since
 * src/matched/CLACT_GetActorPos.c reads the same two halfwords with plain `ldrh`,
 * so the sign extension belongs to this function's s16 return type and not to
 * the struct.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/CLACT_GetActorPosAxis.c \
 *       --func CLACT_GetActorPosAxis --addr 0x0204B560 --cc 1.1p1 --arm
 */
s16 CLACT_GetActorPosAxis(const struct ClactActor *actor, u32 axis)
{
    if (axis == 0) {
        return actor->pos.x;
    } else {
        return actor->pos.y;
    }
}

/*
 * Two more leaf accessors of the 0xE4-byte cell actor.  0x0204B588 saves no
 * lr and so carries no label in the listing
 * (docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md); it is a seed
 * for layout/function_starts.txt.
 *
 * CLACT_SetActorAffineMode writes a two-bit field at bits 18..19 of the u32 flag word at
 * +0x60.  The base type has to be u32, not u8 as in
 * src/matched/unit_0204B22C.c: a u8-based bitfield would truncate the
 * incoming value with an `and r1, r1, #0xff` first, and there is no such
 * instruction here.
 *
 * 0x0204B588 is the +0x10 twin of src/matched/CLACT_SetActorPos.c, so the actor
 * carries two halfword pairs, the screen position at +0x0c and this second
 * pair at +0x10.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0204B570.c \
 *       --addr 0x0204B570 --cc 1.1p1 --arm
 */
void CLACT_SetActorAffineMode(struct ClactActor *actor, u32 value)
{
    actor->affine_mode = value;
}

void CLACT_SetActorAffineOrigin(struct ClactActor *actor, const struct Pt16 *origin)
{
    actor->origin.x = origin->x;
    actor->origin.y = origin->y;
}

/*
 * Three leaf accessors on the display object, 56 bytes end to end with no
 * padding.  Only the first carries a label in the listing: the other two
 * save nothing and so are invisible to disasm.py's prologue rule
 * (docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md).  They are
 * folded into one unit here rather than three files, which also makes the
 * range self-contained: the unit has no relocation sites at all.
 *
 * CLACT_SetActorAffineOriginAxis selects between the +0x10 and +0x12 halfwords on a flag; the
 * front end if-converts it to a `strheq`/`strhne` pair with no branch, and
 * the `eq` arm being first is the source order of the `if`
 * (docs/idioms/the-fall-through-arm-is-the-source-order.md).
 *
 * CLACT_SetActorScale and CLACT_GetActorScale are the setter and getter for the 8-byte
 * pair at +0x14.  Both words are loaded before either is stored, which is
 * what two independent field assignments give when neither store can be
 * proved to feed the following load; writing them as one 8-byte struct
 * assignment is the same code.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0204B59C.c \
 *       --addr 0x0204B59C --arm
 */
void CLACT_SetActorAffineOriginAxis(struct ClactActor *actor, signed short value, u32 axis)
{
    if (axis == 0) {
        actor->origin.x = value;
    } else {
        actor->origin.y = value;
    }
}

/*
 * Unlabelled ARM leaf: copy two words from src into the pair at +0x14/+0x18
 * of dst.  `ldr r2,[r1]; ldr r1,[r1,#4]; str r2,[r0,#0x14]; str r1,[r0,#0x18]`.
 */
void CLACT_SetActorScale(struct ClactActor *actor, struct Pair32 *src)
{
    struct Pair32 scale_copy = *src;

    actor->scale = scale_copy;
}

void CLACT_GetActorScale(const struct ClactActor *actor, struct Pair32 *out_scale)
{
    out_scale->x = actor->scale.x;
    out_scale->y = actor->scale.y;
}

/*
 * Write and read one of the two u32 slots at +0x14 and +0x18 of the cell
 * actor, selected by the last argument.  0x0204B5E4 is an unlabelled leaf and
 * is a seed for layout/function_starts.txt.
 *
 * Both bodies if-convert to a single predicated memory access, the same shape
 * as src/matched/CLACT_SetActorPosAxis.c and src/matched/CLACT_GetActorPosAxis.c have for the
 * halfword pair at +0x0c.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0204B5D4.c \
 *       --addr 0x0204B5D4 --cc 1.1p1 --arm
 */
void CLACT_SetActorScaleAxis(struct ClactActor *actor, u32 value, u32 which)
{
    if (which == 0) {
        actor->scale.x = value;
    } else {
        actor->scale.y = value;
    }
}

u32 CLACT_GetActorScaleAxis(const struct ClactActor *actor, u32 which)
{
    if (which == 0) {
        return actor->scale.x;
    } else {
        return actor->scale.y;
    }
}

/*
 * The write and read of the u16 at +0x58 of the cell actor.  Neither saves lr,
 * so only the first carries a label in the listing
 * (docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md); 0x0204B5FC is
 * a seed for layout/function_starts.txt.
 *
 * The unit deliberately stops here rather than running on to the end of the
 * listing extent at 0x0204B658.  The next leaf, 0x0204B604, is a closed near
 * miss recorded in docs/notes/CLACT_SetActorFlip.c.txt, and folding it in would put
 * this range back to DIFF.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0204B5F4.c \
 *       --addr 0x0204B5F4 --cc 1.1p1 --arm
 */
void CLACT_SetActorRotation(struct ClactActor *actor, u16 value)
{
    actor->angle = value;
}

u16 CLACT_GetActorRotation(const struct ClactActor *actor)
{
    return actor->angle;
}

/*
 * The setter side of CLACT_GetActorFlip (src/matched/CLACT_GetActorFlip.c): sets or
 * clears bit `which` of the two-bit field `flip` at bits 20..21 of the flag
 * word at +0x60.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/CLACT_SetActorFlip.c \
 *       --func CLACT_SetActorFlip --addr 0x0204B604 --cc 1.1p1 --arm
 */
void CLACT_SetActorFlip(struct ClactActor *actor, u32 which, u32 set)
{
    u32 mask = (which == 0) ? 1 : 2;

    if (set == 0) {
        actor->flip &= ~mask;
        return;
    }

    actor->flip |= mask;
}

/*
 * The test side of CLACT_SetActorFlip in src/matched/unit_0204B5F4.c: is bit
 * `which` of the two-bit field at bits 20..21 of the flag word at +0x60 set.
 *
 * The mask is not built into a register here the way the setter builds it.
 * Each arm carries its own constant `tst`, and the `movne r1, #1` that both
 * arms reach is the shared exit
 * (docs/idioms/a-shared-exit-block-is-written-out-in-each-arm.md), so the
 * result has to be a named local initialised to zero before the branch and
 * assigned in both arms, not a returned expression.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/CLACT_GetActorFlip.c \
 *       --func CLACT_GetActorFlip --addr 0x0204B658 --cc 1.1p1 --arm
 */
u32 CLACT_GetActorFlip(const struct ClactActor *actor, u32 which)
{
    u32 result = 0;

    if (which == 0) {
        if ((actor->flip & 1) != 0) {
            result = 1;
        }
    } else {
        if ((actor->flip & 2) != 0) {
            result = 1;
        }
    }

    return result;
}

/*
 * Two accessors of the cell actor's u32 flag word at +0x60.  0x0204B6E4 saves
 * no lr and so carries no label in the listing
 * (docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md); it is a seed
 * for layout/function_starts.txt.
 *
 * The flag word is a dense pile of bitfields.  This pair owns the two-bit
 * field at bits 22..23, and writing it also maintains bit 3 of the four-bit
 * field at bits 8..11: setting a non-zero value sets that bit, setting zero
 * clears it.
 *
 * The clear is spelled `^= 8` under a `& 8` guard, not `&= ~8`.  That is
 * visible in the bytes: `&= ~8` on a four-bit field folds to a single
 * `bic r1, r1, #8`, while the original keeps the guard's `tst r1, #8` and then
 * an `eor r1, r1, #8`, which only a real exclusive or produces.
 *
 * Both arms re-read the field out of the value they just stored, so the write
 * of bits 22..23 has to come first as its own statement; the compiler forwards
 * the store and never reloads from +0x60.
 *
 * The polarity matters: the zero case is the source's then-arm
 * (docs/idioms/the-fall-through-arm-is-the-source-order.md), and inside it the
 * `& 8` test is an early `return`, which is what the original's `bxeq lr` is.
 * Written the other way round the compiler predicates the whole clear
 * sequence, which is four bytes short and moves every instruction.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0204B688.c \
 *       --addr 0x0204B688 --cc 1.1p1 --arm
 */
void CLACT_SetActorObjMode(struct ClactActor *actor, u32 value)
{
    actor->obj_mode = value;

    if (value == 0) {
        if ((actor->mode & 8) == 0) {
            return;
        }
        actor->mode = actor->mode ^ 8;
    } else {
        actor->mode = actor->mode | 8;
    }
}

u32 CLACT_GetActorObjMode(const struct ClactActor *actor)
{
    return actor->obj_mode;
}

/*
 * A whole translation unit, matched as one byte range.
 *
 * A packed bitfield word at +0x60 of the 0x0204Bxxx object: a 12-bit field
 * at bits 0-11 (untouched here), a 4-bit field at bits 12-15, 15 pad bits,
 * and a 1-bit flag at bit 31.
 *
 *   CLACT_SetActorPaletteOffset  set the 4-bit field and the top flag bit together (one
 *                 read-modify-write of the whole word).
 *   CLACT_GetActorPaletteOffset  read the 4-bit field back out.
 *
 * The setter's double shift (`lsl r1,r1,#28` then `orr r1,r3,r1,lsr#16`) is
 * the compiler's general bitfield-store formula, value << (32-width) then
 * >> (32-width-offset); the getter's `lsl #16`/`lsr #28` is the matching
 * read formula, << (32-width-offset) then >> (32-width).  The flag bit
 * collapses to a single `lsl #31` because its offset+width is 32.
 *
 * The getter's redundant `and r0, r0, #0xff` (the field is already 0-15) is
 * only there because the source narrows the result to `unsigned char`
 * before returning it; reading the bitfield straight through as `u32` loses
 * those four bytes.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0204B6F4.c \
 *       --addr 0x0204B6F4 --arm
 */
void CLACT_SetActorPaletteOffset(struct ClactActor *actor, u32 offset, u32 pltt_op)
{
    actor->pltt_offset = offset;
    actor->pltt_op = pltt_op;
}

u32 CLACT_GetActorPaletteOffset(struct ClactActor *actor)
{
    return (unsigned char)actor->pltt_offset;
}

/*
 * Install a transform into the object at +0x40: query the two axis slots
 * through the predicate at 0x0206380C, then copy all five words in.
 *
 * 0x0206380C is a pure reader (`return m->mgr[axis + 2] != -1;`, 28 bytes,
 * no store), so the source pointer is genuinely `const` here.  Both call
 * results are discarded, which is what an assertion-shaped call looks like
 * once the check itself is compiled out.
 *
 * The `const` is load-bearing for codegen, not decoration: with a plain
 * `struct PaletteProxy *` source this front end emits the destination address
 * (`add ip, r5, #0x40`) before the source block load, and with `const` it
 * emits the `ldm r4!, {r0, r1, r2, r3}` first, which is the original's
 * order.  That is the whole content of the DIFF recorded in
 * docs/notes/CLACT_SetActorPaletteProxy.c.txt, and the reason nine non-const spellings
 * there all failed identically.  See
 * docs/idioms/const-source-pointer-schedules-the-block-load-first.md.
 *
 * The copy is twenty bytes, under the unroll threshold, so it inlines to a
 * writeback `ldm`/`stm` pair plus a trailing word for the odd fifth
 * (docs/idioms/aggregate-assignment-is-ldm-stm.md).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/CLACT_SetActorPaletteProxy.c \
 *       --func CLACT_SetActorPaletteProxy --addr 0x0204B728 --cc 1.1p1 --arm
 */
void CLACT_SetActorPaletteProxy(struct ClactActor *actor, const struct PaletteProxy *proxy)
{
    NNSi_G2dIsVramHandleSetEx((char *)proxy, 1);
    NNSi_G2dIsVramHandleSetEx((char *)proxy, 2);
    actor->palette = *proxy;
}

static inline void copy_inline1(const struct ImageProxy *src, struct ImageProxy *dst) {
    *dst = *src;
}

static inline void copy_inline2(struct ImageProxy *dst, const struct ImageProxy *src) {
    *dst = *src;
}

/*
 * A whole translation unit, matched as one byte range.
 *
 * Three aggregate struct copies out of a cell actor, laid out as one unit so
 * the whole 140-byte range (padding included) is the evidence.
 *
 * docs/notes/pkt_0204B764.c.txt records these as a two-instruction scheduling
 * residue; that note is SUPERSEDED for all three.  The spelling that closes it
 * is in the body below: the unit's middle function binds the copy to a named
 * struct local (`struct ImageProxy s; ... s = *src; *(struct ImageProxy *)(dst + 0x1c) = s;`),
 * which is what puts the source address ahead of the destination move, and the
 * two wrappers cast the base once and assign through it.  `tu` reports EXACT,
 * 3 code sections, 140 bytes, 2 of 2 relocation sites resolved.
 *
 * The previous header carried one per-function block per function rather than
 * one `unit: yes` block, so `manifest --verify` recorded only the LAST of the
 * three and 0x0204B764 / 0x0204B784 stayed open in the worklist although the
 * bytes had been reproduced.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0204B764.c \
 *       --addr 0x0204B764 --arm
 */
void CLACT_GetActorPaletteProxy(const char *actor_base, struct PaletteProxy *dst)
{
    const struct PaletteProxy *proxy = (const struct PaletteProxy *)(actor_base + 0x40);
    *dst = *proxy;
}

void CLACT_SetActorImageProxy(char *actor_base, const struct ImageProxy *proxy)
{
    struct ImageProxy copy;
    NNSi_G2dIsVramHandleSet((void *)proxy, 1);
    NNSi_G2dIsVramHandleSet((void *)proxy, 2);
    copy = *proxy;
    *(struct ImageProxy *)(actor_base + 0x1c) = copy;
}

void CLACT_GetActorImageProxy(const char *actor_base, struct ImageProxy *dst)
{
    const struct ImageProxy *proxy = (const struct ImageProxy *)(actor_base + 0x1c);
    *dst = *proxy;
}

/*
 * u16 field read at +0x5c.  Unlabelled in the current listings: the prologue
 * saves nothing, so disasm.py never auto-labelled it (see
 * docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md).  It sits
 * between the literal pool of CLACT_GetActorImageProxy and CLACT_SetActorDrawPriority.
 */
u16 CLACT_GetActorCharacterIndex(struct ClactActor *actor)
{
    return actor->char_idx;
}

/*
 * Same as CLACT_GetActorCharacterIndex one field up, at +0x5e.  Unlabelled leaf for the
 * same reason.
 */
u16 CLACT_GetActorPaletteIndex(struct ClactActor *actor)
{
    return actor->pltt_idx;
}

/*
 * Field at +0x60 is an 8-bit bitfield in a whole word: the original is a
 * word load, and/bic/orr, word store, never a ldrb/strb.
 */
void CLACT_SetActorDrawPriority(struct ClactActor *actor, u32 priority)
{
    actor->draw_priority = priority;
    CLACT_UnlinkActor(actor->owner, actor);
    CLACT_LinkActor(actor->owner, actor);
}

int CLACT_GetActorDrawPriority(struct ClactActor *actor)
{
    return (u8)actor->draw_priority & 0xff;
}

void CLACT_SetActorBgPriority(struct ClactActor *actor, unsigned int priority)
{
    actor->bg_priority = priority;
}

u32 CLACT_GetActorBgPriority(struct ClactActor *actor)
{
    return (u8)actor->bg_priority;
}

/*
 * Stores a 16-bit value at +0x5a of the object, then runs the sub-object at
 * +0x68 through CLACT_SetAnimSeq and re-runs the owner through CLACT_StartActorAnim.
 * The same +0x68 sub-object is the one CLACT_DeleteActor hands to CLACT_ExitAnimCtl.
 *
 * This file was parked at MATCH: CLACT_SetActorAnimSeq is 0x0204D324's only caller
 * image-wide, so the PC24 site at +0x10 could only ever be attested by an
 * EXACT entry for 0x0204D324 itself, and that function looked unattestable
 * in turn because its handler-table pool word 0x020A13B8 appears in no
 * other literal pool.  It is not a table address: it is row 3 of the one
 * eight-by-three array based at 0x020A1394, which is pooled at 0x0204D490
 * as well.  src/matched/CLACT_SetAnimSeq.c carries the reasoning; with that
 * entry EXACT this site resolves `matched` and nothing here changed.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/CLACT_SetActorAnimSeq.c  *       --func CLACT_SetActorAnimSeq --addr 0x0204B878 --cc 1.1p1 --arm
 */
void CLACT_SetActorAnimSeq(struct ClactActor *actor, u16 value)
{
    actor->anim_seq = value;
    CLACT_SetAnimSeq((&actor->ctl), value);
    CLACT_StartActorAnim(actor);
}

/*
 * A whole translation unit range, matched as one byte range.
 *
 * Two members of the interface of the object whose flag word sits at
 * +0x60 (see src/matched/unit_0204B3DC.c and unit_0204B92C.c).  The state
 * this corner of the file owns is the u16 at +0x5a:
 *
 *   CLACT_GetActorAnimSeq  read it.  Saves no lr, so disasm.py never labels it.
 *   CLACT_ChangeActorAnimSeq  the guarded write: do nothing when the value is
 *                 unchanged, otherwise hand it to CLACT_SetActorAnimSeq (which
 *                 stores it and pushes it down into the 0x0204Dxxx layer)
 *                 and re-run CLACT_StartActorAnim on top.
 *
 * The `cmp r1, r2` operand order is the tell that the incoming value is
 * the left operand of the comparison and the field the right one
 * (docs/idioms/cmp-operand-order-names-the-temporary.md), so the guard is
 * written `anim_seq == actor->anim_seq`, not the other way round.
 *
 * This is a cut out of a larger file: the neighbouring functions
 * 0x0204B8C4, 0x0204B8D4, 0x0204B908 and 0x0204B918 are all byte-correct
 * but each calls a 0x0204Dxxx (or, for 0x0204B918, an 0x02062F1C) entry
 * point that has no caller anywhere else in the image, so they are capped
 * at MATCH and parked in src/pending/, next to the 0x0204B878 that an
 * earlier wave parked there for the same reason.  0x0204B8F4,
 * the other clean one, is in src/matched/CLACT_GetActorAnimFrame.c; it is not
 * contiguous with this pair.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0204B898.c \
 *       --addr 0x0204B898 --arm
 */
u16 CLACT_GetActorAnimSeq(struct ClactActor *actor)
{
    return actor->anim_seq;
}

void CLACT_ChangeActorAnimSeq(struct ClactActor *actor, u16 anim_seq)
{
    if (anim_seq == actor->anim_seq) {
        return;
    }
    CLACT_SetActorAnimSeq(actor, anim_seq);
    CLACT_StartActorAnim(actor);
}

/*
 * Forward the sub-object embedded at +0x68 of the 0x0204Bxxx object to
 * CLACT_SetAnimFrame.  A pool word and a `bx ip`, never a displacement branch,
 * because each function is its own section
 * (docs/idioms/tail-call-is-a-pool-word-and-bx.md).
 *
 * Byte-correct, capped at MATCH: 0x0204D3A0 has zero branch witnesses
 * anywhere in the image outside this ABS32 pool word, so the tail-call
 * target cannot be attested.  It unsticks when 0x0204D3A0 is itself
 * decompiled to EXACT.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/CLACT_SetActorAnimFrame.c  *       --func CLACT_SetActorAnimFrame --addr 0x0204B8C4 --cc 1.1p1 --arm
 */
void CLACT_SetActorAnimFrame(struct ClactActor *actor, u32 frame)
{
    CLACT_SetAnimFrame((&actor->ctl), frame);
}

/*
 * Run CLACT_SetAnimSpeed over the sub-object embedded at +0x68 of the
 * 0x0204Bxxx object, then CLACT_AddAnimFrame on it with 0x1000.  The address
 * is recomputed with a second `add r0, r4, #0x68` rather than kept in a
 * register across the call
 * (docs/idioms/keeping-a-cursor-in-a-named-local-costs-a-callee-saved-register.md).
 *
 * Was capped at MATCH: CLACT_SetAnimSpeed is called from this one site and
 * nowhere else in the image, so its PC24 had no outside witness, and
 * CLACT_AddAnimFrame resolved fine (label).  0x0204D4C4 is now the lead function
 * of src/matched/unit_0204D4C4.c and this site resolves `matched` against
 * it.  The C in this file is unchanged.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/CLACT_AddActorAnimFrame.c  *       --func CLACT_AddActorAnimFrame --addr 0x0204B8D4 --cc 1.1p1 --arm
 */
void CLACT_AddActorAnimFrame(struct ClactActor *actor, u32 frames)
{
    CLACT_SetAnimSpeed((&actor->ctl), frames);
    CLACT_AddAnimFrame((&actor->ctl), 0x1000);
}

/*
 * Read +0x10 of the record CLACT_GetAnimObject hands back for the sub-object
 * embedded at +0x68 of the 0x0204Bxxx object (see
 * src/matched/unit_0204B898.c for the family).  The call result is
 * dereferenced in place, so no register is spent copying it
 * (docs/idioms/a-forwarding-call-passes-one-argument-and-the-rest-are-leftovers.md).
 *
 * EXACT*: the byte comparison passes, but the follower at 0x0204B908
 * saves no lr, so disasm.py never labelled it and the inferred extent
 * runs past the end of this function.  0x0204B908 wants seeding into
 * layout/function_starts.txt.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/CLACT_GetActorAnimFrame.c \
 *       --func CLACT_GetActorAnimFrame --addr 0x0204B8F4 --cc 1.1p1 --arm
 */
u32 CLACT_GetActorAnimFrame(struct ClactActor *actor)
{
    return CLACT_GetAnimObject(&actor->ctl)->currentTime;
}

void CLACT_SetActorAnimIndex(struct ClactActor *actor, u32 anim_idx)
{
    CLACT_SetAnimIndex(&actor->ctl, anim_idx);
}

/*
 * Hand the record CLACT_GetAnimObject returns for the sub-object at +0x68
 * straight to NNSi_G2dGetCellAnimFrameIdx: a plain forwarding call whose argument is
 * already in r0
 * (docs/idioms/a-forwarding-call-passes-one-argument-and-the-rest-are-leftovers.md).
 * NNSi_G2dGetCellAnimFrameIdx is the one call this family makes outside the 0x0204Cxxx
 * / 0x0204Dxxx layer.
 *
 * Byte-correct, capped at MATCH: 0x02062F1C is called from this one site
 * and nowhere else in the image.  CLACT_GetAnimObject resolves fine (label).
 * It unsticks when 0x02062F1C is itself decompiled to EXACT.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/CLACT_GetActorAnimSeqCount.c  *       --func CLACT_GetActorAnimSeqCount --addr 0x0204B918 --cc 1.1p1 --arm
 */
u16 CLACT_GetActorAnimSeqCount(struct ClactActor *actor)
{
    return NNSi_G2dGetCellAnimFrameIdx(CLACT_GetAnimObject(&actor->ctl));
}

/*
 * A whole translation unit, matched as one byte range.
 *
 * A setter/getter pair for one bit of the flag word at +0x60 of a widely
 * passed object (bit 25).  The unlabelled getter at 0x0204B944 saves no lr,
 * so disasm.py never labels it; it is only visible by sweeping addresses.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0204B92C.c \
 *       --addr 0x0204B92C --arm
 */
void CLACT_SetActorAutoAnim(struct ClactActor *actor, u32 enable)
{
    actor->auto_anim = enable;
}

u32 CLACT_GetActorAutoAnim(struct ClactActor *actor)
{
    return actor->auto_anim;
}

/*
 * A leaf setter for the word at +0x54 of the cell-actor record: two
 * instructions, no frame, no relocation.  It saves no lr, so `disasm.py`
 * would not have labelled it on its own; it is only visible because the
 * worklist walks the packet by address
 * (docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/CLACT_SetActorAutoAnimSpeed.c \
 *       --func CLACT_SetActorAutoAnimSpeed --addr 0x0204B954 --cc 1.1p1 --arm
 */
void CLACT_SetActorAutoAnimSpeed(struct ClactActor *actor, u32 speed)
{
    actor->auto_anim_speed = speed;
}

/*
 * Set the flag at +0x0c of the animation record CLACT_GetAnimCtrl selects out of
 * the cell actor's +0x68 sub-object.  CLACT_StopActorAnim next door is the same
 * function storing 0 instead of 1.
 *
 * The store goes through the callee's return value, not through the actor, so
 * the actor pointer is dead after the call and nothing is saved across it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/CLACT_StartActorAnim.c \
 *       --func CLACT_StartActorAnim --addr 0x0204B95C --cc 1.1p1 --arm
 */
void CLACT_StartActorAnim(struct ClactActor *actor)
{
    CLACT_GetAnimCtrl(&actor->ctl)->bActive = 1;
}

/*
 * Set the flag at +0x0c of the animation record CLACT_GetAnimCtrl selects out of
 * the cell actor's +0x68 sub-object.  CLACT_StartActorAnim next door is the same
 * function storing 1 instead of 0.
 *
 * The store goes through the callee's return value, not through the actor, so
 * the actor pointer is dead after the call and nothing is saved across it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/CLACT_StopActorAnim.c \
 *       --func CLACT_StopActorAnim --addr 0x0204B974 --cc 1.1p1 --arm
 */
void CLACT_StopActorAnim(struct ClactActor *actor)
{
    CLACT_GetAnimCtrl(&actor->ctl)->bActive = 0;
}

/*
 * Read the u32 at +0x0c of the record CLACT_GetAnimObject selects out of the cell
 * actor's +0x68 sub-object.  The pair CLACT_StartActorAnim / CLACT_StopActorAnim writes the
 * same field through CLACT_GetAnimCtrl's record instead.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/CLACT_IsActorAnimActive.c \
 *       --func CLACT_IsActorAnimActive --addr 0x0204B98C --cc 1.1p1 --arm
 */
u32 CLACT_IsActorAnimActive(struct ClactActor *actor)
{
    return CLACT_GetAnimObject(&actor->ctl)->bActive;
}

/*
 * Blocked at MATCH: all 36 concrete bytes are correct, but the PC24 at +0x001C
 * (the call to CLACT_ResetAnim) has no witness of any class.  0x0204D510 has
 * exactly one branch reference image wide and it is that call, so no cut frees
 * it; the only unblock is a `matched` entry at 0x0204D510, which sits in
 * pkt_0204D4B0, outside this packet.
 *
 * CLACT_StartActorAnim followed by a restart of the animation.  The actor pointer
 * has to survive the first call, so unlike CLACT_StartActorAnim this one spends r4
 * and re-materialises `&actor->ctl` for the second call.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/CLACT_RestartActorAnim.c \
 *       --func CLACT_RestartActorAnim --addr 0x0204B9A0 --cc 1.1p1 --arm
 */
void CLACT_RestartActorAnim(struct ClactActor *actor)
{
    CLACT_GetAnimCtrl(&actor->ctl)->bActive = 1;
    CLACT_ResetAnim(&actor->ctl);
}

/*
 * Three functions, 0x0204B9C4 / 0x0204BA00 / 0x0204BA10.  Only the first is
 * labelled: the other two save no lr, so `disasm.py` never named them and the
 * extent walk from 0x0204B9C4 runs straight through both
 * (docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md).  They are
 * folded into this unit because that is the only way they get a manifest
 * entry at all; neither can ever be attested by the `label` class.
 *
 * CLACT_SetActorAnimLoopCount stores a 4-bit field into the actor's +0x60 word and then
 * pushes the same value into the animation record.  The field is a bitfield,
 * not a mask-and-shift: `lsl #0x1c` followed by `orr ..., lsr #1` is the
 * compiler's insert sequence for width 4 at bit offset 27, where an explicit
 * `(v & 0xf) << 27` would have produced an `and` and a single shift
 * (docs/idioms/unequal-shift-pair-is-a-narrowing-cast-folded-with-a-shift.md).
 *
 * The zero arm clears two fields and the non-zero arm writes one, which is
 * what makes the compiler predicate all three stores off the single `cmp r4,
 * #0` instead of branching.
 *
 * CLACT_ApplyActorAnimCommand and CLACT_ResetActorAnimCommand are tail-call thunks that only re-base the
 * actor pointer onto its +0x68 sub-object.  Each is a pool word and a `bx`,
 * never a displacement branch, because every function gets its own section
 * (docs/idioms/tail-call-is-a-pool-word-and-bx.md).
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0204B9C4.c \
 *       --addr 0x0204B9C4 --cc 1.1p1 --arm
 */
void CLACT_SetActorAnimLoopCount(struct ClactActor *actor, u32 loop_limit)
{
    AnimCtrl *anim_ctrl;

    actor->loop_limit = loop_limit;

    anim_ctrl = CLACT_GetAnimCtrl(&actor->ctl);
    if (loop_limit == 0) {
        anim_ctrl->bReverse = 0;
        anim_ctrl->overriddenPlayMode = 0;
    } else {
        anim_ctrl->overriddenPlayMode = loop_limit;
    }
}

void CLACT_ApplyActorAnimCommand(struct ClactActor *actor, const struct ClactAnimCommand *cmd)
{
    CLACT_ApplyAnimCommand(&actor->ctl, cmd);
}

void CLACT_ResetActorAnimCommand(struct ClactActor *actor)
{
    CLACT_ResetAnimCommand(&actor->ctl);
}

/*
 * Store the logical negation of the argument into bit 0 of the cell actor's
 * +0x64 flag word.  A leaf: no lr saved, no relocation.
 *
 * The bit has to be written as an `if`/`else` with a literal in each arm.
 * The assignment form `actor->hidden = (visible == 0)` materialises the boolean first
 * (`moveq r1, #1` / `movne r1, #0` / `and r1, r1, #1`) and then inserts it,
 * twelve bytes longer; only the two-arm form lets the compiler clear the bit
 * once with `bic` and predicate the set back onto the entry compare.  See
 * docs/idioms/a-one-bit-bitfield-wants-two-arms-not-a-boolean.md.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/CLACT_SetActorVisible.c \
 *       --func CLACT_SetActorVisible --addr 0x0204BA20 --cc 1.1p1 --arm
 */
void CLACT_SetActorVisible(struct ClactActor *actor, u32 visible)
{
    if (visible == 0) {
        actor->hidden = 1;
    } else {
        actor->hidden = 0;
    }
}

/*
 * Copy two signed halfword pairs from the caller's array into clact.c's
 * static two-record scratch block and hand the block to CLACT_InitRenderer.
 *
 * The two pool words 0x020A7F3C and 0x020A7F54 are one symbol, not two: the
 * stores reach the record array as +0x18/+0x1a/+0x28/+0x2a off the base, so
 * the scratch block is the tail of the same static object whose first 0x18
 * bytes are the six function pointers CLACT_SetCellAnimSpeed..CLACT_ResetVramAnim that
 * 0x0204D4DC also loads
 * (docs/idioms/pool-base-for-a-far-field-is-the-symbol-offset-masked-by-the-load-reach.md).
 * Reading them as two objects splits the symbol and loses the relocation.
 *
 * `ldrsh` with an immediate offset is what names the source elements s16
 * (docs/idioms/ldrsh-register-offset-is-signedness.md covers the register
 * form of the same tell).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/CLACT_InitDefaultRenderer.c \
 *       --func CLACT_InitDefaultRenderer --addr 0x0204BA38 --cc 1.1p1 --arm
 */
void CLACT_InitDefaultRenderer(struct Renderer *renderer, const s16 *src, u32 heap_id)
{
    gClactTables.default_surfaces[0].x = src[0];
    gClactTables.default_surfaces[0].y = src[1];
    gClactTables.default_surfaces[1].x = src[2];
    gClactTables.default_surfaces[1].y = src[3];

    CLACT_InitRenderer(renderer, gClactTables.default_surfaces, 2, heap_id);
}

/*
 * Record the two VRAM base offsets of a cell-actor resource set in the
 * singleton: NNSi_G2dGetVramHandleEx returns a byte address per bank selector, the
 * halfword fields at +0xf0 and +0xf2 hold it in 32-byte units, and the
 * caller's bias is then folded into both.
 *
 * The bias is folded with `+=`, not by adding it into the expression above:
 * the compound form re-reads the halfword it just stored
 * (docs/idioms/compound-assignment-rereads-the-field-plain-assignment-reuses-the-cached-load.md),
 * which is what produces the four extra `ldr r1, [r6]` / `ldrh` / `strh`
 * groups instead of one `add` before each store.
 *
 * Only the address of the global is worth keeping in r6: the pointer itself
 * is re-read before every store because each call and each store may alias
 * it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/CLACT_SetPaletteBaseOffsets.c \
 *       --func CLACT_SetPaletteBaseOffsets --addr 0x0204BA7C --cc 1.1p1 --arm
 */
void CLACT_SetPaletteBaseOffsets(u32 pltt_proxy, u16 base_offset, u32 pltt_op)
{
    g_ClactSystem->pltt_base[0] = (u32)NNSi_G2dGetVramHandleEx((char *)pltt_proxy, (u32)1) >> 5;
    g_ClactSystem->pltt_base[1] = (u32)NNSi_G2dGetVramHandleEx((char *)pltt_proxy, (u32)2) >> 5;

    g_ClactSystem->pltt_base[0] += base_offset;
    g_ClactSystem->pltt_base[1] += base_offset;

    g_ClactSystem->pltt_op = pltt_op;
}

/*
 * Store a word at +0xf8 of the cell-actor singleton, silently doing nothing
 * before the system is constructed.  A leaf: the guarded store predicates to
 * `strne` and no lr is saved.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/CLACT_SetSystemActive.c \
 *       --func CLACT_SetSystemActive --addr 0x0204BAEC --cc 1.1p1 --arm
 */
void CLACT_SetSystemActive(u32 active)
{
    if (g_ClactSystem != 0) {
        g_ClactSystem->active = active;
    }
}

/*
 * The reader for the word CLACT_SetSystemActive writes, returning 0 before the system
 * is constructed.  Both arms are predicated off the null test (`ldrne` and
 * `moveq` into the same register), which is why this has to be written as one
 * `if`/`else` over two returns rather than an early return followed by the
 * load.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/CLACT_IsSystemActive.c \
 *       --func CLACT_IsSystemActive --addr 0x0204BB04 --cc 1.1p1 --arm
 */
u32 CLACT_IsSystemActive(void)
{
    if (g_ClactSystem != 0) {
        return g_ClactSystem->active;
    } else {
        return 0;
    }
}

/*
 * Store a word at +0xfc of the cell-actor singleton, silently doing nothing
 * before the system is constructed.  A leaf: the guarded store predicates to
 * `strne` and no lr is saved.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/CLACT_SetOamPending.c \
 *       --func CLACT_SetOamPending --addr 0x0204BB20 --cc 1.1p1 --arm
 */
void CLACT_SetOamPending(u32 pending)
{
    if (g_ClactSystem != 0) {
        g_ClactSystem->oam_pending = pending;
    }
}

/*
 * The reader for the word CLACT_SetOamPending writes, returning 0 before the system
 * is constructed.  Both arms are predicated off the null test (`ldrne` and
 * `moveq` into the same register), which is why this has to be written as one
 * `if`/`else` over two returns rather than an early return followed by the
 * load.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/CLACT_IsOamPending.c \
 *       --func CLACT_IsOamPending --addr 0x0204BB38 --cc 1.1p1 --arm
 */
u32 CLACT_IsOamPending(void)
{
    if (g_ClactSystem != 0) {
        return g_ClactSystem->oam_pending;
    } else {
        return 0;
    }
}

/*
 * Drop the singleton's +0xfc latch: if it is set, release the two OAM
 * sub-records hanging off the singleton itself and clear the latch.
 *
 * Two early returns, each predicated into its own `popeq`, so they are two
 * separate `if`s rather than one `&&`
 * (docs/idioms/guard-chain-sharing-one-exit-block-is-a-single-conjunction.md
 * is the opposite shape: one shared exit block).  The address of the global
 * is held in r4 across both calls, but the pointer itself is re-read for the
 * third call because CLACT_IsOamPending may have stored to it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/CLACT_ResetOamIfPending.c \
 *       --func CLACT_ResetOamIfPending --addr 0x0204BB54 --cc 1.1p1 --arm
 */
void CLACT_ResetOamIfPending(void)
{
    if (g_ClactSystem == 0) {
        return;
    }
    if (CLACT_IsOamPending() == 0) {
        return;
    }

    CLACT_ResetOamManagers(&g_ClactSystem->oam_mgrs);
    CLACT_SetOamPending(0);
}

/*
 * Blocked at MATCH: all 60 concrete bytes are correct, but the PC24 at +0x001C
 * (the call to CLACT_DrawUnit) has no witness of any class.  0x0204C944 has
 * exactly one branch reference image wide and it is that call, so no cut frees
 * it; the only unblock is a `matched` entry at 0x0204C944, which sits in the
 * packet after pkt_0204BD64.
 *
 * Walk the singleton's unit ring at +0x100 and run CLACT_DrawUnit over every
 * member.  The ring is the one src/matched/CLACT_LinkUnit.c builds, so the
 * walk is a do/while around the head test rather than a null-terminated
 * list.
 *
 * Unlike CLACT_LinkUnit's insertion walk, this one needs no `goto`: the call
 * in the body is an optimisation barrier, so the compiler neither rotates the
 * loop nor hoists the `->head` reload, and the structured form already
 * reproduces the re-read at +0x20.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/CLACT_DrawAllUnits.c \
 *       --func CLACT_DrawAllUnits --addr 0x0204BB8C --cc 1.1p1 --arm
 */
void CLACT_DrawAllUnits(void)
{
    struct Unit *unit;

    unit = g_ClactSystem->units;
    if (unit == 0) {
        return;
    }

    do {
        CLACT_DrawUnit(unit);
        unit = unit->next;
    } while (unit != g_ClactSystem->units);
}

/*
 * Link a cell-actor unit into the singleton's priority-ordered ring at
 * +0x100.  The ring is circular and doubly linked through +0x10 (next) and
 * +0x14 (prev); the sort key is the u8 at +0x0f that
 * src/matched/CLACT_CreateUnit.c stores from its caller's flag.
 *
 * Empty ring: the unit becomes the head and both of its own links point at
 * itself.  The three stores are written through the global each time, which
 * is why the global is reloaded twice after the first store: a store through
 * a Bank pointer may alias the pointer variable itself, so the compiler
 * cannot keep the initial load live across it.  The walk in the other arm
 * performs no store and keeps the cached copy in ip throughout.
 *
 * The walk has to be written with explicit labels and `goto`.  Every
 * structured spelling (`while`, `do`/`while`, `for(;;)` with two breaks) is
 * rotated: the compiler peels the first priority test, and once the loop has
 * a single back edge it also hoists the `->head` reload out of it, which
 * costs twelve bytes and loses the `ldr r1, [ip, #0x100]` at +0x48.  See
 * docs/idioms/a-reloaded-loop-invariant-means-the-loop-was-not-rotated.md.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/CLACT_LinkUnit.c \
 *       --func CLACT_LinkUnit --addr 0x0204BBC8 --cc 1.1p1 --arm
 */
void CLACT_LinkUnit(struct Unit *unit)
{
    struct Unit *cursor;
    struct Unit *prev_unit;

    if (g_ClactSystem->units == 0) {
        g_ClactSystem->units = unit;
        g_ClactSystem->units->next = unit;
        g_ClactSystem->units->prev = unit;
        return;
    }

    cursor = g_ClactSystem->units;
loop:
    if (cursor->priority > unit->priority) {
        goto found;
    }
    cursor = cursor->next;
    if (cursor != g_ClactSystem->units) {
        goto loop;
    }
found:

    prev_unit = cursor->prev;
    unit->prev = prev_unit;
    unit->next = prev_unit->next;
    prev_unit->next->prev = unit;
    prev_unit->next = unit;
}

/*
 * The inverse of src/matched/CLACT_LinkUnit.c: unlink a cell-actor unit from
 * the singleton's ring at +0x100 and NULL both of its own links.  When the
 * unit being removed is the head, the head moves to its successor, or to
 * NULL when the unit was the only member.
 *
 * The head update is one `if`/`else` whose two arms the compiler predicates
 * into `streq`/`strne` off a shared `moveq r1, #0`
 * (docs/idioms/a-factored-tail-lets-the-compiler-predicate-the-arms.md);
 * writing it as a conditional expression on the stored value instead loses
 * the paired store.
 *
 * Both link fields are re-read between the two ring stores because a store
 * through one Unit pointer may alias the other, so `unit->next` is loaded
 * twice and `unit->prev` twice.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/CLACT_UnlinkUnit.c \
 *       --func CLACT_UnlinkUnit --addr 0x0204BC40 --cc 1.1p1 --arm
 */
void CLACT_UnlinkUnit(struct Unit *unit)
{
    if (g_ClactSystem->units == unit) {
        if (unit->next == unit) {
            g_ClactSystem->units = 0;
        } else {
            g_ClactSystem->units = unit->next;
        }
    }

    unit->next->prev = unit->prev;
    unit->prev->next = unit->next;
    unit->next = 0;
    unit->prev = 0;
}

/*
 * Blocked at MATCH: all 68 concrete bytes are correct and the call to
 * NNS_G2dInitOamManagerModule resolves off the second call site in
 * src/matched/CLACT_ExitOamManagers.c, but the two PC24 sites at +0x0028 and +0x003C
 * (the calls to CLACT_InitOamManager) have no witness outside this range: those two
 * calls are the only branch references to 0x0204BD3C image wide.  No cut frees
 * them, and src/pending/CLACT_InitOamManager.c cannot supply a `matched` entry
 * because it is itself capped at MATCH by NNSi_G2dReserveOamManagerSpan, a fan-in-1 extern.
 *
 * Bind both of a cell actor's 0x20-byte OAM sub-records to their hardware
 * spans: flush first, then the low record with span (base, count) and
 * selector 0, then the high record with (base2, count2) and selector 1.
 *
 * The fifth parameter is a u8: it arrives on the caller's stack and is read
 * back with `ldrb r2, [sp, #0x18]` past the six-register push, while the
 * third parameter reaches the same argument slot as a plain `mov`.  Widening
 * it to u32 would drop the `ldrb` to an `ldr`.
 *
 * The second sub-record is reached with `add r0, r7, #0x20`, the constant
 * subscript &oam_managers->mgr[1], not a running cursor.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/CLACT_InitOamManagers.c \
 *       --func CLACT_InitOamManagers --addr 0x0204BC94 --cc 1.1p1 --arm
 */
void CLACT_InitOamManagers(struct OamManagers *oam_managers, u32 main_base, u32 main_count, u32 sub_base, u8 sub_count)
{
    NNS_G2dInitOamManagerModule();
    CLACT_InitOamManager(&oam_managers->mgr[0], main_base, main_count, 0);
    CLACT_InitOamManager(&oam_managers->mgr[1], sub_base, sub_count, 1);
}

/*
 * Release both of a cell actor's 0x20-byte OAM sub-records and then flush the
 * hardware tables.  The pair-wise loops live in CLACT_ResetOamManagers and
 * CLACT_ApplyOamManagers; this is only the ordering.
 *
 * The actor pointer is saved in r4 across the first call and restored for the
 * second; the third call takes no argument at all, so r0 still carries
 * CLACT_ApplyOamManagers's return value when it is made.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/CLACT_ExitOamManagers.c \
 *       --func CLACT_ExitOamManagers --addr 0x0204BCD8 --cc 1.1p1 --arm
 */
void CLACT_ExitOamManagers(struct OamManagers *oam_managers)
{
    CLACT_ResetOamManagers(oam_managers);
    CLACT_ApplyOamManagers(oam_managers);
    NNS_G2dInitOamManagerModule();
}

/*
 * Blocked at MATCH: all 36 concrete bytes are correct, but the PC24 at
 * +0x0010 (the call to CLACT_ApplyOamManager) has no witness of any class.  Its only
 * caller image wide is that call, so no cut frees it; the unblock is a
 * `matched` entry at 0x0204BD64, and that file is itself capped on 0x0206343C
 * (508 bytes, pkt_02063078, claimed by lane-C).  Chain capped for this pass.
 *
 * Run CLACT_ApplyOamManager over both of a cell actor's 0x20-byte OAM sub-records.
 * CLACT_ResetOamManagers next door is the same loop against CLACT_ResetOamManager.
 */
void CLACT_ApplyOamManagers(struct OamManagers *oam_managers)
{
    int i;

    for (i = 0; i < 2; i++) {
        CLACT_ApplyOamManager(&oam_managers->mgr[i]);
    }
}

/*
 * Blocked at MATCH: all 36 concrete bytes are correct, but the PC24 at
 * +0x0010 (the call to CLACT_ResetOamManager) has no witness of any class.  Its only
 * caller image wide is that call, and that file is itself capped on 0x02063640
 * (316 bytes, pkt_02063640, claimed by lane-C).  Chain capped for this pass.
 *
 * Run CLACT_ResetOamManager over both of a cell actor's 0x20-byte OAM sub-records.
 */
void CLACT_ResetOamManagers(struct OamManagers *oam_managers)
{
    int i;

    for (i = 0; i < 2; i++) {
        CLACT_ResetOamManager(&oam_managers->mgr[i]);
    }
}

void CLACT_InitOamManager(struct OamManager *oam_manager, int base, int count, int screen)
{
    if (count == 0) {
        oam_manager->bound = 0;
        return;
    }
    NNSi_G2dReserveOamManagerSpan(&oam_manager->inst, base, count, screen);
    oam_manager->bound = 1;
}

/*
 * Blocked at MATCH: all 24 concrete bytes are correct, but the PC24 at +0x0010
 * (the call to NNS_G2dApplyOamManagerToHW) has no witness of any class.  0x0206343C has
 * exactly one branch reference image wide and it is that call, so no cut frees
 * it; the only unblock is a `matched` entry at 0x0206343C, a 508-byte function
 * in pkt_02063078, claimed by lane-C and far outside this lane.
 *
 * Release one bound 0x20-byte OAM sub-record of a cell actor.  The "bound"
 * flag at +0x1c is the same one CLACT_InitOamManager sets, and an unbound record is
 * an early return predicated onto the compare (`popeq`).
 */
void CLACT_ApplyOamManager(struct OamManager *oam_manager)
{
    if (oam_manager->bound == 0) {
        return;
    }

    NNS_G2dApplyOamManagerToHW((struct NNSG2dOamManagerInstance *)oam_manager, oam_manager->bound);
}

/*
 * Blocked at MATCH: all 24 concrete bytes are correct, but the PC24 at +0x0010
 * (the call to NNS_G2dResetOamManagerBuffer) has no witness of any class.  0x02063640 has
 * exactly one branch reference image wide and it is that call; the only unblock
 * is a `matched` entry at 0x02063640, a 316-byte function in pkt_02063640,
 * claimed by lane-C.
 *
 * Release one bound 0x20-byte OAM sub-record of a cell actor.  The "bound"
 * flag at +0x1c is the same one CLACT_InitOamManager sets, and an unbound record is
 * an early return predicated onto the compare (`popeq`).  The r1 read at the
 * call is a leftover, not an argument: 0x02063640 overwrites r1 at +0x1C with
 * `ldrh r1, [r5, #8]` before any use (docs/notes/NNS_G2dResetOamManagerBuffer.c.txt).
 */
void CLACT_ResetOamManager(struct OamManager *oam_manager)
{
    if (oam_manager->bound == 0) {
        return;
    }

    NNS_G2dResetOamManagerBuffer((struct NNSG2dOamManagerInstance *)oam_manager);
}

/*
 *           this body (the tool prints "no witness outside 0204BD94..0204BE2C");
 *           CLACT_InitSurface lives in pkt_0204BE84, which is not this lane's.
 *
 * Byte-identical at 148 bytes; only the two PC24 call fields at +0x14 and
 * +0x68 stay wildcarded.  The 0x020A7F74 pool word is ABS32 into the string
 * area and resolves `literal`, and NNS_G2dSetRendererTargetSurface resolves `matched`.
 *
 * Spellings that mattered: `for (i = 0; i < count; i++)` with an unsigned `i`
 * and a signed `count` is what gives the single `popls` loop guard and the
 * `blo` back-edge.  Adding an explicit `if (count <= 0) return;` in front of
 * the loop emits BOTH `pople` and `popls` and costs four bytes of layout.
 */
void CLACT_InitRenderer(struct Renderer *renderer, const struct SurfaceInit *inits, int count, u32 heap_id)
{
    u32 i;

    NNS_G2dInitRenderer((struct NNSG2dRendererInstance *)renderer);
    renderer->active = 1;
    renderer->surfaces = GFL_HEAP_Alloc(heap_id, count * sizeof(struct Surface), 0, s_clact_c, 0xfc7);
    renderer->n_surfaces = count;
    for (i = 0; i < count; i++) {
        CLACT_InitSurface(&renderer->surfaces[i], &inits[i]);
        NNS_G2dSetRendererTargetSurface((struct NNSG2dRendererInstance *)renderer, (struct NNSG2dRenderSurface *)(&renderer->surfaces[i]));
    }
}

void CLACT_ExitRenderer(struct Renderer *renderer){ GFL_HEAP_Free(renderer->surfaces); }

#define fxmul(a, b) ((s32)((((s64)(a) * (s64)(b)) + 0x800) >> 12))

/*
 * Culling on/off for a 0x48-stride element array (the same surfaces/n_surfaces pair
 * CLACT_InitRenderer allocates): enable != 0 installs CLACT_CullOam as each element's
 * +0x40 callback, enable == 0 sets renderer->cull_reset = 1 and clears the callbacks.  Reached
 * only through a pool word at 0x0204B0FC; the pool word 0x0204C2C8 resolves
 * sole-ref/code.
 *
 * Two levers, both needed: the non-zero arm first (`if (enable != 0)`), and `i`
 * declared before `fn` (found by trying both orders).
 */
void CLACT_SetSurfaceCulling(struct Renderer *renderer, int enable)
{
    u32 i;
    OamCullFn cull_fn;

    if (enable != 0) {
        cull_fn = CLACT_CullOam;
    } else {
        renderer->cull_reset = 1;
        cull_fn = 0;
    }
    for (i = 0; i < renderer->n_surfaces; i++) {
        renderer->surfaces[i].cull = cull_fn;
    }
}

/*
 * Wave 15 (register-tie lane).  Three facts closed the 104-byte residue of
 * docs/notes/pkt_0204BE84.c.txt:
 *  - CLACT_SetSurfaceType takes TWO arguments (surface, init->type): its body is
 *    `surface->type = tbl_020A1388[idx]`, and the image's `ldr r1, [r4, #8]`
 *    inside the store block is that argument, not an early load of the
 *    table index.  The "missing mov r0, r5" of the older note follows.
 *  - `const T *init` (the source record is read-only); the volatile +0x04
 *    device of the older note is no longer needed.
 *  - the y and h halfwords bound to s16 locals at the image's load points
 *    (found by permuter anneal, then reduced by hand): that fixes the
 *    f0, f2, f6, f4 load order and the r2/r3 pair.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/CLACT_InitSurface.c \
 *       --func CLACT_InitSurface --addr 0x0204BE84 --cc 1.1p1 --arm
 */
void CLACT_InitSurface(struct Surface *surface, const struct SurfaceInit *init)
{
    SurfaceFuncs funcs;
    s16 init_h;
    s16 init_y;

    NNS_G2dInitRenderSurface((NNSG2dRenderSurface *)surface);
    init_y = init->y;
    surface->x = (int)init->x << 12;
    init_h = init->h;
    surface->y = (int)init_y << 12;
    surface->width = (int)init->w << 12;
    surface->height = (int)init_h << 12;
    CLACT_SetSurfaceType(surface, init->type);
    funcs = g_ClactSurfaceFuncTable[init->type];
    funcs.extra_func = g_ClactSurfaceModeTable[init->extra_func_sel];
    surface->oam_func = (int)funcs.oam_func;
    surface->affine_func = (int)funcs.affine_func;
    surface->extra_func = (int)funcs.extra_func;
}

/*
 * Blocked at MATCH: all 24 concrete bytes are correct (20 code + the pool
 * word), but the ABS32 at +0x0014 has no witness of any class.  0x020A1388
 * is plain data, so only the `literal` class could attest it, and the pool
 * word inside this function is that address's only occurrence image wide.
 * The escape that unblocked 0x0204C83C in this same region (decompile the
 * target to EXACT and cite it as a `matched` witness) does not exist here:
 * nothing compiles a data table.  Same wall as src/matched/CLACT_ExecuteTransfer.c
 * and docs/notes/clact_c_fan_in_1_blockers.c.txt describe for 0x020A138C.
 *
 * Store the u16 entry `idx` of the table at 0x020A1388 into the caller's
 * word at +0x14, zero-extended.
 */
void CLACT_SetSurfaceType(struct Surface *surface, u32 idx)
{
    surface->type = g_ClactSurfaceTypeTable[idx];
}

/*
 * Push one OAM entry through the window at `oam_manager`, rewriting its palette field
 * on the way.  The caller's 8-byte entry is copied onto the stack first
 * (MI_CpuCopy8, not a struct assignment: the source is only 2-aligned), then
 * the 4-bit palette in bits 12..15 of the attribute halfword at +4 is either
 * BIASED by `pal` (mode 0) or REPLACED with it (mode 1); any other mode leaves
 * the entry alone.  The rewritten copy, not the caller's, is what reaches
 * NNSi_G2dEntryOamManagerOam.
 *
 * The bias arm is written as a store through a pointer to the halfword's word
 * (`add r2, sp, #4` then `ldr`/`str` through r2), which is what makes the
 * image reload the base instead of re-using sp; the replace arm is small
 * enough that 1.1p1 predicates it whole
 * (`ldreq`/`lsleq`/`biceq`/`orreq`/`streq`) and needs no such pointer.
 *
 * Signature pinned from src/matched/CLACT_EntryOamMain.c, the one filed caller.
 *
 * BYTE-CORRECT, PARKED, NOT FILED.  132 bytes, 0 concrete mismatches; the sole
 * unresolved site is the PC24 to NNSi_G2dEntryOamManagerOam at +0x78.  Blocking evidence
 * class: `label` -- 0x02063294 has no branch anywhere in the image outside
 * 0x0204BF40..0x0204BFC4, and there is no `matched` entry for it
 * (docs/notes/pkt_02063078.c.txt records it as a DIFF, 228 bytes).  Filing
 * NNSi_G2dEntryOamManagerOam unblocks this file with no change to the C_0204BE38.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/CLACT_EntryOam.c \
 *       --func CLACT_EntryOam --addr 0x0204BF40 --cc 1.1p1 --arm
 */
void CLACT_EntryOam(struct OamManager *oam_manager, GXOamAttr *src_entry, u32 mode, u32 pltt_offset,
                   u32 pltt_op)
{
    GXOamAttr entry_copy;
    u32 *attr2;

    MI_CpuCopy8(src_entry, &entry_copy, sizeof(entry_copy));

    if (pltt_op == 0) {
        attr2 = &entry_copy.attr23;
        *attr2 = (*attr2 & ~0xf000) |
                 ((((u32)(u16)*attr2 >> 12) + pltt_offset) << 28 >> 16);
    } else if (pltt_op == 1) {
        entry_copy.attr23 = (entry_copy.attr23 & ~0xf000) |
                               (pltt_offset << 28 >> 16);
    }

    NNSi_G2dEntryOamManagerOam(&oam_manager->inst, &entry_copy, mode);
}

/*
 * Forward one command at the manager itself: the manager is the command
 * block, its u16 at +0xf0 is the id and the word at +0xf4 the payload.
 */
void CLACT_EntryOamMain(GXOamAttr *entry, u32 mode)
{
    CLACT_EntryOam(&g_ClactSystem->oam_mgrs.mgr[0], entry, mode, g_ClactSystem->pltt_base[0], g_ClactSystem->pltt_op);
}

/*
 * Same forward as CLACT_EntryOamMain, but aimed at the sub-command block at
 * +0x20 of the manager, whose id and payload sit at +0xf2 / +0xf4.
 */
void CLACT_EntryOamSub(GXOamAttr *entry, u32 mode)
{
    CLACT_EntryOam(&g_ClactSystem->oam_mgrs.mgr[1], entry, mode,
                  g_ClactSystem->pltt_base[1], g_ClactSystem->pltt_op);
}

/*
 * Tail call through the singleton pointer: the pool word for the global is
 * loaded, its value passed as the first argument, and the callee reached with
 * the compiler's usual `ldr ip, [pc, #4]` / `bx ip` plus a second pool word.
 */
void CLACT_EntryAffineMain(const MtxFx22 *value)
{
    NNS_G2dEntryOamManagerAffine(&g_ClactSystem->oam_mgrs.mgr[0].inst, value);
}

/*
 * Same forward as CLACT_EntryAffineMain but aimed at the sub-block at +0x20.
 *
 * Unlabelled in the current listings: the prologue saves nothing, so
 * disasm.py never auto-labelled it (see
 * docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md).  The
 * function starts at the computed address and its body ends at 0x0204C060.
 */
void CLACT_EntryAffineSub(const MtxFx22 *value)
{
    NNS_G2dEntryOamManagerAffine(&g_ClactSystem->oam_mgrs.mgr[1].inst, value);
}

/*
 * The 2x2-matrix sibling of CLACT_IsCellInView (see docs/notes/pkt_0204C060.c.txt):
 * transform the sprite's four half-extents through the caller's 2x2 matrix in
 * 20.12 fixed point, translate by the camera delta, take the min/max of each
 * axis and cull against the viewport.
 *
 * Three levers, all measured, that this note's sibling row asked for:
 *  - The fall-through arm is the `flag == 1` field arm and the synthetic arm
 *    is the predicated one (`rsbne`/`lslne`/`movne` + `bne` over the fields),
 *    which only happens when the 6-bit extraction is hoisted ABOVE the `if`.
 *  - `dx` must be computed beside `dy`, before the `if`, not after it: with
 *    `dx` after the branch the whole 64-bit block reallocates (295 bytes out).
 *  - The extraction must go through an explicit u8 narrowing of the MASK,
 *    `(s32)(u8)(f & 0x3f)` then `(m6 << 2) & 0xff`. Every spelling that masks
 *    first and narrows the SHIFTED value -- `((f & 0x3f) << 2) & 0xff`,
 *    `(u8)((f & 0x3f) << 2)`, the u32 and the `* 4` forms -- lets 1.1p1 prove
 *    the field contiguous and fuse it into `lsl #26` + `lsr #24`, where the
 *    image keeps `and #0x3f` + `lsl #2` + `and #0xff`.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/CLACT_IsAffineCellInView.c \
 *       --func CLACT_IsAffineCellInView --addr 0x0204C060 --cc 1.1p1 --arm
 */
int CLACT_IsAffineCellInView(struct CellData *cell, struct Affine2D *affine, struct ViewRect *view)
{
    u16 attr = cell->attr;
    s32 size_bits = (s32)(u8)(attr & 0x3f);
    s32 half_extent = (size_bits << 2) & 0xff;
    s32 dy = affine->tx - view->x;
    s32 dx = affine->ty - view->y;
    s32 y_lo, y_hi, x_lo, x_hi;
    s32 m01, m11, m10, m00;
    s32 min_x, corner_x1, min_y, max_y;
    s32 max_x;

    if (((attr >> 11) & 1) == 1) {
        y_lo = cell->min_y << 12;
        y_hi = cell->max_y << 12;
        x_lo = cell->min_x << 12;
        x_hi = cell->max_x << 12;
    } else {
        y_hi = half_extent << 12;
        y_lo = (-half_extent) << 12;
        x_lo = y_lo;
        x_hi = y_hi;
    }
    m01 = affine->m01;
    m11 = affine->m11;
    m10 = affine->m10;
    m00 = affine->m00;

    min_x = dx + (fxmul(y_lo, m01) + fxmul(y_lo, m11));
    corner_x1 = dx + (fxmul(y_hi, m01) + fxmul(y_hi, m11));
    min_y = dy + (fxmul(x_lo, m00) + fxmul(x_lo, m10));
    max_y = dy + (fxmul(x_hi, m00) + fxmul(x_hi, m10));

    max_x = corner_x1;
    if (corner_x1 < min_x) {
        max_x = min_x;
        min_x = corner_x1;
    }
    if (max_y < min_y) {
        s32 swap = max_y;
        max_y = min_y;
        min_y = swap;
    }
    if (max_x > 0 && min_x < view->height && max_y > 0 && min_y < view->width)
        return 1;
    return 0;
}

/*
 * The axis-aligned sibling of CLACT_IsAffineCellInView (clact.c): take the sprite's four
 * half-extents in 20.12 fixed point, translate by the camera delta and cull
 * against the viewport.  Where CLACT_IsAffineCellInView runs the extents through a 2x2
 * matrix, this one adds the deltas straight to them.  No relocations.
 *
 * Four levers, all measured against the image (docs/notes/pkt_0204C060.c.txt
 * had this row at 37-148 bytes out before the second pass):
 *  - The fall-through arm is the `flag == 1` field arm and the synthetic arm
 *    is the predicated one (`rsbne`/`lslne`/`movne` + `bne` over the fields).
 *    That only happens when the 6-bit extraction is hoisted ABOVE the `if`.
 *  - `dy` is declared before `dx` (the image's first `sub` is
 *    `affine->tx - view->x`); swapping them costs 8 bytes.
 *  - The four sums must be computed as named locals in the order
 *    ay, ax, bx, by BEFORE the `&&` chain; computing them inside the chain
 *    makes the compiler interleave the adds with the branches (115 out).
 *  - The extraction must go through an explicit u8 narrowing of the MASK,
 *    `(s32)(u8)(w & 0x3f)` then `(m6 << 2) & 0xff`, exactly as
 *    CLACT_IsAffineCellInView documents.  Every spelling that masks first and narrows
 *    the SHIFTED value -- `(u8)((w & 0x3f) << 2)`, `((w & 0x3f) << 2) & 0xff`,
 *    the u32 and the `* 4` forms -- lets 1.1p1 prove the field contiguous and
 *    fuse it into `lsl #26` + `lsr #24`, where the image keeps
 *    `and #0x3f` + `lsl #2` + `and #0xff`.  This was the final 6-byte residue;
 *    tools/permuter.py exhausted 261 single mutations on it without moving it,
 *    which is the "residue is in the reading, not the allocation" signature.
 *
 * Verified with:
 *   python3 tools/match.py one --src src/matched/CLACT_IsCellInView.c \
 *       --func CLACT_IsCellInView --addr 0x0204C214 --cc 1.1p1 --arm
 */
int CLACT_IsCellInView(struct CellData *cell, struct Affine2D *affine, struct ViewRect *view)
{
    u16 attr = cell->attr;
    s32 size_bits = (s32)(u8)(attr & 0x3f);
    s32 half_extent = (size_bits << 2) & 0xff;
    s32 dy = affine->tx - view->x;
    s32 dx = affine->ty - view->y;
    s32 x0, y0, x1, y1;
    s32 ax, ay, bx, by;

    if (((attr >> 11) & 1) == 1) {
        x0 = cell->min_y << 12;
        y0 = cell->max_y << 12;
        x1 = cell->min_x << 12;
        y1 = cell->max_x << 12;
    } else {
        x0 = -half_extent << 12;
        y0 = half_extent << 12;
        x1 = -half_extent << 12;
        y1 = half_extent << 12;
    }
    ay = y0 + dx;
    ax = x0 + dx;
    bx = x1 + dy;
    by = y1 + dy;
    return ay > 0 && ax < view->height && by > 0 && bx < view->width;
}

static inline s32 RepeatX(s16 x)
{
    if (x > 0xff)
        x |= ~0xff;
    return x;
}

static inline s32 RepeatY(s16 y)
{
    if (y > 0x7f)
        y |= ~0xff;
    return y;
}

static inline u16 SizeX(s32 shape)
{
    return NNSi_objSizeWTbl[(shape & 0xc000) >> 14][(shape & 0xc0000000) >> 30];
}

static inline u16 SizeY(s32 shape)
{
    return NNSi_objSizeHTbl[(shape & 0xc000) >> 14][(shape & 0xc0000000) >> 30];
}

/*
 * The OAM cull callback CLACT_SetSurfaceCulling installs at element +0x40: read the
 * element's GXOamAttr attr01 word (+0x38), wrap x (9 bits) and y (8 bits),
 * size the object from the OBJ width/height tables indexed [shape][size],
 * and store CLACT_IsRectInView's verdict into the element's visible flag (+0x30).
 * affine is the 2x2 matrix plus translation (tx/ty), view the viewport.
 *
 * Lever (wave 16, declaration facts): the two OBJ size tables are
 * read-only data and are declared `const`.  Without const every register
 * name of the second half shuffled (58 bytes, flat under 120 declaration
 * orders, 80 index casts and two anneals); with it, EXACT.  const on the
 * p parameter is wrong (264 bytes); const on box and on the callee's
 * pointer parameters is neutral.
 */
void CLACT_CullOam(struct Surface *surface, struct ViewRect *view, s32 unused_arg2, s32 unused_arg3, struct Affine2D *affine)
{
    s32 shape = surface->oam.attr01 & 0xC000C000;
    s32 x0 = RepeatX(surface->oam.x) << 12;
    s32 x1 = (RepeatX(surface->oam.x) + SizeX(shape)) << 12;
    s32 y0 = RepeatY(surface->oam.y) << 12;
    s32 y1 = (RepeatY(surface->oam.y) + SizeY(shape)) << 12;

    surface->visible = CLACT_IsRectInView(affine->tx - view->x, affine->ty - view->y,
                               x0, x1, y0, y1, affine, view) != 0;
}

#undef fxmul

#undef fxmul

#undef fxmul

#undef fxmul

#undef fxmul

#define fxmul(a, b) ((s32)((((s64)(a) * (s64)(b)) + 0x800) >> 12))

/*
 * The 2x2-matrix cull test behind CLACT_CullOam (its only caller): transform
 * the four corners (x0,y0) (x0,y1) (x1,y0) (x1,y1) of an OAM rectangle through
 * the matrix affine (20.12, rounded +0x800), take min/max per axis, translate by the
 * camera delta (dx, dy) and test against the viewport view->width / view->height.  Eight
 * arguments: dx, dy, x0, x1 in r0-r3; y0, y1, affine, view on the stack.
 *
 * Levers, all measured (wave 10):
 *  - the four translated bounds are added EAGERLY as statements
 *    (`minx += dx; maxx += dx; miny += dy; maxy += dy;`) before the `&&`
 *    chain, same lever as CLACT_IsCellInView; inline in the chain: 41-66 out.
 *  - declaration order `maxx, minx, maxy, miny` and the seed order
 *    `min = p; max = p;` put the minimum in p's register and the maximum in
 *    the copy (r4/lr, sb/r7), as the image has it; any other order swaps the
 *    pair (25-37 out).  Found by tools/permuter.py (decl-order + reorder),
 *    then closed by sweeping all 240 decl/seed orders.
 *  - the umull/mla (not smull) products from the second use of each
 *    coordinate on are the CSE'd `(s64)` sign halves, not a different macro.
 */
int CLACT_IsRectInView(s32 dx, s32 dy, s32 x0, s32 x1, s32 y0, s32 y1,
                  const struct Affine2D *affine, const struct ViewRect *view)
{
    s32 maxx, minx, maxy, miny;
    s32 proj;

    proj = fxmul(x0, affine->m00) + fxmul(y0, affine->m10);
    minx = proj;
    maxx = proj;
    proj = fxmul(x0, affine->m00) + fxmul(y1, affine->m10);
    if (proj < minx) minx = proj; else if (proj > maxx) maxx = proj;
    proj = fxmul(x1, affine->m00) + fxmul(y0, affine->m10);
    if (proj < minx) minx = proj; else if (proj > maxx) maxx = proj;
    proj = fxmul(x1, affine->m00) + fxmul(y1, affine->m10);
    if (proj < minx) minx = proj; else if (proj > maxx) maxx = proj;

    proj = fxmul(x0, affine->m01) + fxmul(y0, affine->m11);
    miny = proj;
    maxy = proj;
    proj = fxmul(x0, affine->m01) + fxmul(y1, affine->m11);
    if (proj < miny) miny = proj; else if (proj > maxy) maxy = proj;
    proj = fxmul(x1, affine->m01) + fxmul(y0, affine->m11);
    if (proj < miny) miny = proj; else if (proj > maxy) maxy = proj;
    proj = fxmul(x1, affine->m01) + fxmul(y1, affine->m11);
    if (proj < miny) miny = proj; else if (proj > maxy) maxy = proj;

    minx += dx; maxx += dx; miny += dy; maxy += dy;
    if (maxy > 0 && miny < view->height && maxx > 0 && minx < view->width)
        return 1;
    return 0;
}

/*
 * promoted: from src/pending 2026-09-19, no C change: blocker 0x02066934 is filed in layout/matched/arm9/pkt_02066890.json and every site resolves (gate: manifest --verify --shard layout/matched/arm9/pkt_0204C060.json, then 0 rewritten).
 *
 * Blocked at MATCH: all 132 concrete bytes are correct and four of the five
 * relocation sites resolve, but the PC24 at +0x0054 (the call to
 * NNS_G2dInitCellTransferStateManager) has no witness of any class.  0x02066934 has exactly one
 * branch reference image wide and it is that call, so no cut frees it; the
 * only unblock is a `matched` entry at 0x02066934, far outside clact.c.
 *
 * Construct a pool of `count` 0x30-byte records: allocate the array, hand it to
 * NNS_G2dInitCellTransferStateManager with CLACT_RequestTransfer as the per-record callback, build the
 * parallel 0x10-byte entry array through CLACT_AllocTransferEntries, and mark the object
 * constructed.  A zero capacity leaves the object unconstructed and is the
 * predicated early return off the `movs` that loads the count.
 *
 * The record size 0x30 is a real `mul` against a register, not a shift pair:
 * mwccarm only strength-reduces the multiply when the constant is a power of
 * two, and 0x30 is not.
 *
 * The allocation result is bound to a local, stored, and then passed on: the
 * call to NNS_G2dInitCellTransferStateManager reuses the value in r0 instead of reloading +0x00,
 * which is what the named temporary produces
 * (docs/idioms/a-store-that-lands-after-the-next-call-names-a-local-temporary.md).
 *
 * CLACT_RequestTransfer is passed as data, so the relocation is an ABS32 into the
 * code section; it is an ordinary extern declared at its own address, not a
 * veneer.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/CLACT_InitTransferPool.c \
 *       --func CLACT_InitTransferPool --addr 0x0204C660 --cc 1.1p1 --arm
 */
void CLACT_InitTransferPool(struct TransferPool *pool, u8 count, u32 heapId)
{
    CellTransferState *tasks;

    if (count == 0) {
        pool->ready = 0;
        return;
    }

    pool->count = count;
    tasks = GFL_HEAP_Alloc(heapId, count * sizeof(CellTransferState), 0, s_clact_c, 0x1337);
    pool->tasks = tasks;

    NNS_G2dInitCellTransferStateManager(tasks, count, CLACT_RequestTransfer);
    CLACT_AllocTransferEntries((struct TransferPool *)pool, count, heapId);

    pool->ready = 1;
}

/*
 * The inverse of src/matched/CLACT_InitTransferPool.c: release the 0x30-byte record
 * array, drop the free-list built over it, and clear the constructed flag at
 * +0x0c.  An unconstructed object is an early return predicated onto the
 * entry compare.
 *
 * The zero is materialised once into a callee-saved register and used for
 * both stores, because the second store lands after the call to
 * CLACT_FreeTransferEntries; that is also what forces the store to +0x00 to be written
 * before the call rather than after
 * (docs/idioms/a-store-that-lands-after-the-next-call-names-a-local-temporary.md).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/CLACT_ExitTransferPool.c \
 *       --func CLACT_ExitTransferPool --addr 0x0204C6E4 --cc 1.1p1 --arm
 */
void CLACT_ExitTransferPool(struct TransferPool *pool)
{
    if (pool->ready == 0) {
        return;
    }

    GFL_HEAP_Free(pool->tasks);
    pool->tasks = 0;
    CLACT_FreeTransferEntries((struct TransferPool *)pool);
    pool->ready = 0;
}

/*
 * Allocate the pool's parallel array of 0x10-byte entries and zero each one.
 * The __FILE__ pointer is the same s_clact_c the rest of clact.c uses; the
 * line number 0x137b is a plain pooled constant here, not derived from a
 * neighbouring one, because this is the only allocation in the function.
 *
 * The entry count for the loop is read back out of the object at +0x08 rather
 * than reused from the `count` that sized the allocation: the load right after the
 * call is the loop's rotated entry test, and the same field is re-read at the
 * bottom of every iteration because MI_CpuFill8 may alias it.
 *
 * The clear is a per-element call, not one call over the whole array, so the
 * zero and the 0x10 are hoisted into callee-saved registers for the loop.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/CLACT_AllocTransferEntries.c \
 *       --func CLACT_AllocTransferEntries --addr 0x0204C718 --cc 1.1p1 --arm
 */
void CLACT_AllocTransferEntries(struct TransferPool *pool, u32 count, u32 heapId)
{
    u32 i;

    pool->entries = GFL_HEAP_Alloc(heapId, count * sizeof(struct TransferEntry), 0, s_clact_c,
                           0x137b);

    for (i = 0; i < pool->count; i++) {
        MI_CpuFill8(&pool->entries[i], 0, sizeof(struct TransferEntry));
    }
}

/*
 * Release the 0x10-byte entry array CLACT_AllocTransferEntries allocates at +0x04 and NULL
 * the pointer.  The pointer has to survive the free call, so the object is
 * kept in r4 and the store is written after it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/CLACT_FreeTransferEntries.c \
 *       --func CLACT_FreeTransferEntries --addr 0x0204C788 --cc 1.1p1 --arm
 */
void CLACT_FreeTransferEntries(struct TransferPool *pool)
{
    GFL_HEAP_Free(pool->entries);
    pool->entries = 0;
}

/*
 * Blocked at MATCH: all 96 concrete bytes are correct, but the PC24 at
 * +0x0034 (the call to CLACT_ExecuteTransfer) has no witness of any class.
 * 0x0204C8B8 has exactly one branch reference image wide and it is that
 * call, so no cut frees it; the unblock is a `matched` entry at 0x0204C8B8,
 * which src/pending/CLACT_ExecuteTransfer.c cannot supply, being itself byte-correct
 * but capped at MATCH by the handler table at 0x020A138C having no second
 * pool word anywhere in the image.
 *
 * Tear down every live entry of a 16-byte-record table: the record count is
 * at +0x08 and the array base at +0x04, and a record is live when its first
 * word is non-null.  Each live record is handed to CLACT_ExecuteTransfer and then
 * zeroed.
 *
 * The array base is re-read from +0x04 on both sides of the CLACT_ExecuteTransfer
 * call, which is what fixes it as a field load rather than a cached local:
 * the callee may move the table.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/CLACT_ExecuteTransfers.c \
 *       --func CLACT_ExecuteTransfers --addr 0x0204C7A4 --cc 1.1p1 --arm
 */
void CLACT_ExecuteTransfers(struct TransferPool *pool)
{
    u32 i;

    for (i = 0; i < pool->count; i++) {
        if (pool->entries[i].src != 0) {
            CLACT_ExecuteTransfer((struct TransferEntry *)(&pool->entries[i]));
            MI_CpuFill8(&pool->entries[i], 0, sizeof(struct TransferEntry));
        }
    }
}

/*
 * Find the first free 0x10-byte entry of a pool, free meaning a zero word at
 * +0x00.  Returns NULL when the pool is full.  A leaf: nothing here calls
 * anything, so both the entry array and the count are hoisted out of the loop
 * and the element address is only materialised on the arm that returns it
 * (`addeq r0, r2, r1, lsl #4`).
 *
 * The scaled register offset `ldr r0, [r2, r1, lsl #4]` is the subscript form
 * `pool->entries[i].src`; a walking cursor would have produced a post-indexed
 * load and an extra add
 * (docs/idioms/keeping-a-cursor-in-a-named-local-costs-a-callee-saved-register.md).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/CLACT_GetFreeTransferEntry.c \
 *       --func CLACT_GetFreeTransferEntry --addr 0x0204C804 --cc 1.1p1 --arm
 */
struct TransferEntry *CLACT_GetFreeTransferEntry(struct TransferPool *pool)
{
    u32 i;

    for (i = 0; i < pool->count; i++) {
        if (pool->entries[i].src == 0) {
            return &pool->entries[i];
        }
    }

    return 0;
}

/*
 * The per-record callback src/matched/CLACT_InitTransferPool.c hands to NNS_G2dInitCellTransferStateManager,
 * which is why its address only ever appears as a pool word and never as a
 * branch target.
 *
 * The selector local really is uninitialised on the path where the first
 * argument is neither 0x13 nor 0x23: r4 is written only inside the two
 * predicated arms and is read again at the call below, with no `mov r4, ...`
 * on the fall-through.  Giving it a default value in the C adds that `mov`
 * and four bytes, so the original's C had an `if`/`else if` with no `else`.
 *
 * The handle passed to CLACT_SetTransferEntry is CLACT_GetFreeTransferEntry's return value left in
 * r0, not a reload; the selector chain in between touches only r4 and the
 * flags.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/CLACT_RequestTransfer.c \
 *       --func CLACT_RequestTransfer --addr 0x0204C83C --cc 1.1p1 --arm
 */
BOOL CLACT_RequestTransfer(s32 kind, u32 dest, void *src, u32 size)
{
    void *entry;
    u32   entry_kind;

    entry = CLACT_GetFreeTransferEntry(&g_ClactSystem->transfer);

    if (kind == 0x13) {
        entry_kind = 0;
    } else if (kind == 0x23) {
        entry_kind = 1;
    }

    if (size != 0) {
        CLACT_SetTransferEntry(entry, entry_kind, dest, src, size);
    }

    return 1;
}

/*
 * Fill one 0x10-byte pool entry.  A leaf with five arguments, so the last one
 * is read straight back off the caller's stack with no frame at all.
 *
 * The store order in the source is +0x0c, +0x00, +0x04, +0x08: only the last
 * two are adjacent in both address and source order, which is what lets the
 * compiler fuse them into `stmib r0, {r2, ip}`.  Writing the four fields in
 * address order would fuse three of them instead and change the encoding.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/CLACT_SetTransferEntry.c \
 *       --func CLACT_SetTransferEntry --addr 0x0204C8A4 --cc 1.1p1 --arm
 */
void CLACT_SetTransferEntry(struct TransferEntry *entry, u32 entry_kind, u32 dest, void *src, u32 size)
{
    entry->kind = entry_kind;
    entry->src = src;
    entry->dest = dest;
    entry->size = size;
}

extern void (*g_ClactTransferFuncs[])(void *src, u32 arg, u32 size);

/*
 * Blocked at MATCH: all 44 concrete bytes are correct, but the ABS32 at
 * +0x0028 (the handler table at 0x020A138C) has no witness.  The table is
 * plain data, so only the `literal` class could attest it, and the pool word
 * inside this function is the address's only occurrence image wide; there is
 * no second site.  The same wall docs/notes/clact_c_fan_in_1_blockers.c.txt
 * describes for 0x0204C83C, but without its escape: there the address was a
 * function that could be decompiled to EXACT and become a `matched` witness,
 * here it is a table and nothing compiles it.
 *
 * Run one 16-byte transfer record: flush the source range out of the data
 * cache, then dispatch on the record's fourth word through the handler table
 * at 0x020A138C, passing the other three words.
 *
 * The four words are read back with a single `ldm r4, {r0, r1, r2, ip}`,
 * which is the compiler combining four consecutive field loads, not a struct
 * copy: the first and third are loaded a second time here because
 * DC_FlushRange may have written them.
 *
 * This function is the sole blocker for src/pending/CLACT_ExecuteTransfers.c, whose
 * only call to it is the one branch reference it has image wide.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/CLACT_ExecuteTransfer.c \
 *       --func CLACT_ExecuteTransfer --addr 0x0204C8B8 --cc 1.1p1 --arm
 */
void CLACT_ExecuteTransfer(struct TransferEntry *entry)
{
    DC_FlushRange(entry->src, entry->size);
    g_ClactTransferFuncs[entry->kind](entry->src, entry->dest, entry->size);
}

/*
 * The slot allocator for the 0xe4-byte display object: walk the owner's
 * array of `count` records and return the first whose word 0 is zero, or
 * fail the GF_ASSERT(0) at calct.c:5204 and return NULL.
 *
 * 0xe4 is not a power of two, so the index is a real `mul` against a
 * materialised element size rather than a shift; the size constant lands in
 * r0 on top of the owner pointer because the count and the array base are
 * both hoisted out of the loop before the first iteration and the owner is
 * dead from there on.  The `ble` guard is signed, which is what a plain
 * `int i` compared against a `u16` field gives: the field zero-extends into
 * an int and the comparison stays signed.
 *
 * The two `__FILE__`/expression strings are one object here, not two.  The
 * file-name string 0x020A7F74 has 92 pool witnesses image-wide, but the
 * expression string "0" at 0x020A7F7C is pooled only by this function, and
 * it is one character long, below the string class's minimum run, so
 * `string` cannot fix it from the preceding terminator either (which is
 * what docs/idioms/a-string-after-a-data-table-has-no-witness.md describes
 * from the other side).  Declaring this translation unit's string area as
 * a single object whose second member starts at +8, the length of
 * "calct.c" including its terminator, puts both relocations on the attested
 * base and takes the +8 from the C.  Same bytes, same two pool words.  See
 * docs/idioms/an-assert-expression-string-rides-the-file-name-symbol.md.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/CLACT_GetFreeActor.c \
 *       --func CLACT_GetFreeActor --addr 0x0204C8E4 --cc 1.1p1 --arm
 */
struct ClactActor *CLACT_GetFreeActor(struct Unit *unit)
{
    int i;

    for (i = 0; i < unit->count; i++) {
        if (unit->actors[i].next == 0) {
            return &unit->actors[i];
        }
    }

    GF_PANIC_Fail(s_clact_c, 5204, s_clact_assert_expr);
    return 0;
}

/*
 * Blocked at MATCH: all 72 concrete bytes are correct and CLACT_UpdateActorAutoAnim
 * resolves `matched`, but the call to CLACT_DrawActor (+0x0028) has no
 * witness: 0204CB44 has exactly one branch reference image wide, this
 * call, so no cut frees it. CLACT_DrawUnit itself was the blocker named in
 * docs/notes/clact_c_fan_in_1_blockers.c.txt for CLACT_DrawAllUnits; closing it
 * only traded one fan-in-1 blocker for another one level down
 * (CLACT_DrawActor, 108 bytes, not otherwise investigated here).
 *
 * Guarded by the top nibble of the byte at +0xe (the low nibble is never
 * tested here, hence the `lsl #0x18; lsrs #0x1c` rather than a plain
 * `ldrb`/`ands`) and by the ring head at +0x04 being non-null. Then walk
 * that ring (the node's own +0x00 is its `next`, same shape as
 * CLACT_DrawAllUnits's unit ring) running CLACT_DrawActor and CLACT_UpdateActorAutoAnim (the
 * latter already matched, src/matched/CLACT_UpdateActorAutoAnim.c) over every member.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/CLACT_DrawUnit.c \
 *       --func CLACT_DrawUnit --addr 0x0204C944 --cc 1.1p1 --arm
 */
void CLACT_DrawUnit(struct Unit *unit)
{
    struct ClactActor *actor;

    if (unit->draw_enable == 0) {
        return;
    }

    actor = unit->head;
    if (actor == 0) {
        return;
    }

    do {
        CLACT_DrawActor(actor, unit->renderer);
        CLACT_UpdateActorAutoAnim(actor);
        actor = actor->next;
    } while (actor != unit->head);
}

/*
 * Sorted insert into a circular doubly-linked list whose head pointer sits
 * at unit+4 and whose links are {next @0, prev @4}.  The empty list seeds a
 * self-loop; a first key below the head's key goes in front of the tail;
 * otherwise the average of the head and tail keys picks the half to search
 * and CLACT_FindActorBefore/CLACT_FindActorAfter return the node to insert after.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/CLACT_LinkActor.c \
 *       --func CLACT_LinkActor --addr 0x0204C98C --cc 1.1p1
 */
void CLACT_LinkActor(struct Unit *unit, struct ClactActor *actor)
{
    struct ClactActor *insert_after;

    if (unit->head == 0) {
        unit->head = actor;
        actor->next = actor;
        unit->head->prev = actor;
        return;
    }
    {
        u32 priority = CLACT_GetActorDrawPriority(actor);
        u32 head_priority = CLACT_GetActorDrawPriority(unit->head);
        u32 tail_priority;
        u8  mid_priority;

        if (priority < head_priority) {
            insert_after = unit->head->prev;
            unit->head = actor;
        } else {
            tail_priority = CLACT_GetActorDrawPriority(unit->head->prev);
            mid_priority = (u8)((int)(head_priority + tail_priority) / 2);
            if (mid_priority >= priority) {
                insert_after = CLACT_FindActorBefore(unit->head, priority);
            } else {
                insert_after = CLACT_FindActorAfter(unit->head->prev, priority);
            }
        }
    }
    actor->prev = insert_after;
    actor->next = insert_after->next;
    insert_after->next->prev = actor;
    insert_after->next = actor;
}

/*
 * Unlink a node from a doubly linked list whose head pointer lives at +4 of
 * the manager.  A node whose own forward pointer is itself is the only
 * entry, so the manager's head is cleared instead of taking the link.  Both
 * arms of that inner if write the head, which is why the store is a
 * conditional pair rather than one unconditional store.
 */
void CLACT_UnlinkActor(struct Unit *unit, struct ClactActor *actor)
{
    if (unit->head == actor) {
        if (actor->next == actor) {
            unit->head = 0;
        } else {
            unit->head = actor->next;
        }
    }
    actor->next->prev = actor->prev;
    actor->prev->next = actor->next;
    actor->next = 0;
    actor->prev = 0;
}

/*
 * Walk the circular list backwards from `head` and return the payload of
 * the first node whose key sorts strictly above `key`; if the walk comes
 * all the way round, the head's own payload is the answer.
 *
 * The list is circular, so the test is at the bottom and the loop is a
 * `do`/`while`: a `while` would have added an entry test the original does
 * not have.  `hi` rather than `gt` fixes the comparison as unsigned.  The
 * hit arm is two predicated instructions, `ldrhi` and `pophi`, so it never
 * reaches the shared tail.
 *
 * Its mirror image CLACT_FindActorAfter walks the same list forwards, returns the
 * node instead of the payload and inverts the condition.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/CLACT_FindActorBefore.c \
 *       --func CLACT_FindActorBefore --addr 0x0204CA74 --cc 1.1p1 --arm
 */
void *CLACT_FindActorBefore(struct ClactActor *head, u32 priority)
{
    struct ClactActor *cur = head;

    do {
        if (CLACT_GetActorDrawPriority(cur) > priority) {
            return cur->prev;
        }
        cur = cur->next;
    } while (cur != head);

    return head->prev;
}

/*
 * The forward half of the pair that opens this packet: walk the circular
 * list through its `next` links and return the first node whose key does
 * not sort above `key`, falling back on the head's `prev` when the walk
 * comes all the way round.
 *
 * Where CLACT_FindActorBefore returns a payload, this one returns the node itself,
 * which is the whole difference between `ldrhi r0, [r4, #4]` there and
 * `movls r0, r4` here.  The polarity is the other way round too: `ls`, the
 * complement of the sibling's `hi`.
 *
 * The two are separate translation units in the image, not one: each gets
 * its own `bl 0x204b838` and its own copy of the loop.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/CLACT_FindActorAfter.c \
 *       --func CLACT_FindActorAfter --addr 0x0204CAAC --cc 1.1p1 --arm
 */
struct ClactActor *CLACT_FindActorAfter(struct ClactActor *head, u32 priority)
{
    struct ClactActor *cur = head;

    do {
        if (CLACT_GetActorDrawPriority(cur) <= priority) {
            return cur;
        }
        cur = cur->prev;
    } while (cur != head);

    return head->next;
}

/*
 * The constructor for the 0xe4-byte object this packet operates on: wipe
 * it, initialise the two embedded sub-objects at +0x1c and +0x40, set the
 * three 0x1000 scale fields, and fix up the flag word at +0x60.
 *
 * The flag word is one load and one store for three separate bitfield
 * assignments, which is the whole reason this function is worth reading:
 * the 4-bit field at bit 8 is a read-modify-write (`lsl #20; lsr #28; orr
 * #1; lsl #28; ... lsr #20` around a `bic #0xf00`), while the two fields
 * being set to zero collapse into plain `bic`s of their masks.  Only the
 * field whose new value depends on its old one pays for the extract and
 * reinsert.
 *
 * 0x1000 is materialised once into r4 and reused for all three stores; the
 * compiler spreads those stores across the two calls rather than keeping
 * them together, so their position in the listing is not their position in
 * the source.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/CLACT_ClearActor.c \
 *       --func CLACT_ClearActor --addr 0x0204CAE4 --cc 1.1p1 --arm
 */
void CLACT_ClearActor(struct ClactActor *actor)
{
    MI_CpuFill8(actor, 0, 0xe4);
    actor->auto_anim_speed = 0x1000;
    NNSi_G2dInitVramHandle(actor->image.raw);
    NNSi_G2dInitVramHandleEx(actor->palette.raw);
    actor->scale.x = 0x1000;
    actor->scale.y = 0x1000;
    actor->mode |= 1;
    actor->pltt_op = 0;
    actor->affine_mode = 0;
}

/*
 * Blocked at MATCH on the `label`/`matched` classes: all 108 concrete bytes
 * are right, but every one of the six callees has exactly one branch
 * reference image-wide and it is the call in this function, so none of the
 * six can be witnessed and no cut frees any of them.  Four of the six are
 * now closed and the file is at 4 of 6 relocation sites resolved:
 *
 *   NNSi_G2dSetRndCoreImageProxyVeneer  0x02066748   12 bytes  -- veneer, resolves `veneer`
 *   NNS_G2dBeginRendering  0x02065BD0  168 bytes  -- OPEN, docs/notes/NNS_G2dBeginRendering.c.txt
 *   CLACT_SetupActorDraw  0x0204CBB0  188 bytes  -- closed, resolves `matched`
 *   CLACT_SetPaletteBaseOffsets  0x0204BA7C  112 bytes  -- closed, resolves `matched`
 *   CLACT_ApplyActorTransform  0x0204CC6C  584 bytes  -- OPEN, soft-float, multi-function
 *   NNS_G2dEndRendering  0x02065C78  108 bytes  -- closed, resolves `matched`
 *
 * NNSi_G2dSetRndCoreImageProxyVeneer is not decompilable and never will be.  It is a twelve-byte
 * ARM linker veneer, `ldr ip, [pc]; bx ip; .word 0x02067AA0`, and the
 * `veneer` attestation class used to refuse it because 0x02067AA0 was an
 * unlabelled three-instruction leaf (`str r1, [r0, #8]; str r2, [r0, #0xc];
 * bx lr`) that `disasm.py` never labels, so `names_known_code()` failed.  The
 * integrator seeded 0x02067AA0 into layout/function_starts.txt before wave
 * 25 and the site now resolves `veneer` with no change to any source file,
 * exactly as
 * docs/idioms/a-veneer-attests-nothing-while-its-target-is-an-unlabelled-leaf.md
 * predicted.
 *
 * What remains is NNS_G2dBeginRendering, a 24-byte codegen near miss over one
 * zero-register allocation (the note names every spelling tried), and
 * CLACT_ApplyActorTransform, 584 bytes of soft-float record publishing that nobody has
 * attempted yet.  This function is itself the sole blocker for
 * src/pending/CLACT_DrawUnit.c, which is the sole blocker named in
 * docs/notes/clact_c_fan_in_1_blockers.c.txt for src/pending/CLACT_DrawAllUnits.c,
 * which is one of the two blockers of src/pending/CLACT_DrawSystem.c (the other
 * is 0x02066998).
 *
 * Per-element teardown.  Guarded by bit 26 of the flag word at +0x60; the
 * two values handed to CLACT_SetPaletteBaseOffsets are bits 12-15 (narrowed to u8, which
 * is what the otherwise redundant `and r1, r1, #0xff` after the shift pair
 * records) and bit 31 of the same word, read through one load.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/CLACT_DrawActor.c \
 *       --func CLACT_DrawActor --addr 0x0204CB44 --cc 1.1p1 --arm
 */
void CLACT_DrawActor(struct ClactActor *actor, struct Renderer *renderer)
{
    if (actor->enabled == 0)
        return;

    NNSi_G2dSetRndCoreImageProxyVeneer((int *)renderer, (sptr)&actor->image, (sptr)&actor->palette);
    NNS_G2dBeginRendering((struct NNSG2dRendererInstance *)renderer);
    CLACT_SetupActorDraw(actor, renderer);
    CLACT_SetPaletteBaseOffsets((uptr)&actor->palette, (u8)actor->pltt_offset, actor->pltt_op);
    CLACT_ApplyActorTransform(actor);
    NNS_G2dEndRendering();
}

/*
 * Publishes five bitfields of the element's flag word at +0x60 into the
 * render record: the two-bit mode at bits 18-19 through NNS_G2dSetRndCoreAffineOverwriteMode, the
 * two corner values through NNS_G2dSetRndCoreFlipMode when that mode is zero, then the
 * four-bit value at bits 8-11 into +0x84, bit 24 into +0x90, bits 22-23 into
 * +0x8c and bits 16-17 into +0x88.
 *
 * The +0x84 store is three instructions of arithmetic that computes nothing:
 * `(flags | mode_bits) & ~(~mode_bits)` is `mode_bits`, and mwccarm folds every direct spelling of it
 * away.  The cast between the two complements, and the statement boundaries
 * that put the first `mvn` ahead of the `orr`, are what keep all five
 * instructions:
 * docs/idioms/a-cast-between-two-complements-is-what-keeps-both-mvns.md.
 *
 * Decompiled so that it becomes a `matched` witness for the call at
 * 0x0204CB44+0x3c (src/pending/CLACT_DrawActor.c).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/CLACT_SetupActorDraw.c \
 *       --func CLACT_SetupActorDraw --addr 0x0204CBB0 --cc 1.1p1 --arm
 */
void CLACT_SetupActorDraw(struct ClactActor *actor, struct Renderer *renderer)
{
    u32 flip_x, flip_y, flags;
    int inv_mask;
    u8  mode_bits;

    NNS_G2dSetRndCoreAffineOverwriteMode((struct NNSG2dRndCoreInstance *)renderer, actor->affine_mode);

    if (actor->affine_mode == 0) {
        flip_x = CLACT_GetActorFlip(actor, 0);
        flip_y = CLACT_GetActorFlip(actor, 1);
        NNS_G2dSetRndCoreFlipMode((struct NNSG2dRndCoreInstance *)renderer, flip_y, flip_x);
    }

    mode_bits = actor->mode;
    inv_mask = ~mode_bits;
    flags = renderer->flags | mode_bits;
    renderer->flags = flags & ~(u32)inv_mask;
    renderer->mosaic = actor->mosaic;
    renderer->obj_mode = actor->obj_mode;
    renderer->bg_priority = (u8)actor->bg_priority;
}

/*
 * Byte-correct, MATCH-capped.  NOT in the manifest; see src/pending/README.md.
 *
 * All 584 concrete bytes are right; 36 of 40 relocation sites resolve.  The
 * four that do not are the three fan-in-1 callees of the trailing switch:
 *
 *   NNSi_G2dRendererDrawCellZOffset  0x02065CE4  104 bytes  -- OPEN (pkt_02065CE4), 4 bytes
 *                                            from EXACT, see
 *                                            docs/notes/NNSi_G2dRendererDrawCellZOffset.c.txt
 *   NNSi_G2dRendererDrawCellTransformedZOffset  0x02065D4C  104 bytes  -- OPEN (pkt_02065D4C), twin of
 *                                            the above, same near miss
 *   NNSi_G2dRendererDrawMultiCellTransformed  0x02066080  220 bytes  -- OPEN (pkt_02065D4C), unattempted
 *
 * Each has exactly one branch reference image-wide and it is the call in this
 * function, so `label` cannot see them and a single function cannot be split.
 * Closing all three turns this file EXACT and makes it the `matched` witness
 * that src/pending/CLACT_DrawActor.c's last open site needs.
 *
 * What it does.  Publishes the cell actor's two coordinate pairs into the
 * render state.  Each s16 field is converted with the same inlined helper:
 * the fixed-point value `v << 12` is turned into a float and rounded half
 * away from zero, `(f32)(v << 12) + 0.5f` for a positive v and
 * `(f32)(v << 12) - 0.5f` otherwise, then truncated back to s32 by the
 * soft-float runtime.  The
 * second pair is published only when the 2-bit field at 0x60 bits 18-19 is
 * set, is followed by a scale (NNS_G2dScale, 0x1000 == FX32_ONE) and a
 * rotation read as a pair of s16 from the table at 0x020A1B38 indexed by
 * `actor->angle >> 4`, and is then undone by publishing the negated pair.  The
 * trailing switch on +0x68 picks the draw path; case 0 splits again on bit 0
 * of +0x64.
 *
 * The add in the first arm is the expression form: mwccarm canonicalises the
 * commutative add so the constant becomes the first operand and the call is
 * `_fadd(0.5f, t)`, which is what the image has.  See
 * docs/idioms/a-soft-float-add-puts-the-constant-first-unless-it-is-a-compound-assignment.md
 * (this file was matched earlier as `0.5f - t' / `t += 0.5f' against swapped
 * _fsub/_fadd addresses; 0x0209C95C is the add, 0x0209CB8C the subtract).
 */
void CLACT_ApplyActorTransform(struct ClactActor *actor)
{
    f32 y_f, x_f;
    s32 trig_idx;

    CONV(y_f, actor->pos.y);
    CONV(x_f, actor->pos.x);
    NNS_G2dTranslate((s32)x_f, (s32)y_f, 0);

    if (actor->affine_mode != 0) {
        CONV(y_f, actor->origin.y);
        CONV(x_f, actor->origin.x);
        NNS_G2dTranslate((s32)x_f, (s32)y_f, 0);

        NNS_G2dScale(actor->scale.x, actor->scale.y, 0x1000);

        trig_idx = actor->angle >> 4;
        NNS_G2dRotZ(FX_SinCosTable_[trig_idx * 2], FX_SinCosTable_[trig_idx * 2 + 1]);

        CONV(y_f, actor->origin.y);
        CONV(x_f, actor->origin.x);
        NNS_G2dTranslate(-(s32)x_f, -(s32)y_f, 0);
    }

    switch (actor->ctl.kind) {
    case 0:
        if (actor->hidden == 1) {
            NNSi_G2dRendererDrawCellZOffset((void *)actor->ctl.cur_cell);
        } else {
            NNSi_G2dRendererDrawCellTransformedZOffset(actor->ctl.anim);
        }
        break;
    case 1:
        NNSi_G2dRendererDrawCellTransformedZOffset(actor->ctl.anim);
        break;
    case 2:
        NNSi_G2dRendererDrawMultiCellTransformed((struct MultiCellDrawCmd *)actor->ctl.anim);
        break;
    }
}

/*
 * Verified with:
 *   python tools/match.py one --src src/pending/CLACT_ApplyActorTransform.c \
 *       --func CLACT_ApplyActorTransform --addr 0x0204CC6C --cc 1.1p1 --arm
 */

/*
 * Run the object through CLACT_AddActorAnimFrame, but only when the flag word at +0x60
 * has its seventh bit set.
 *
 * `lsl #6; lsr #31` with nothing that could be a type conversion is a
 * one-bit unsigned bitfield
 * (docs/idioms/shift-pair-with-no-matching-type-is-a-bitfield.md).  The
 * pair names the bit from the top: `lsl #6` says six bits sit above it, so
 * it is bit 25 counting from the least significant end, and this front end
 * allocates bitfields from the least significant end upward, which means
 * twenty-five bits of padding must be declared before it.  Declaring the
 * six-bit pad first instead gives `lsl #25` and is the whole difference
 * between the two spellings.  The guard is `== 1`, not a plain truth test, which
 * is why the comparison survives as an explicit `cmp r1, #1` instead of
 * folding into the shift's flags.
 *
 * CLACT_AddActorAnimFrame takes one argument; the `ldr r1, [r0, #0x54]` that precedes
 * the call is a second, forwarded value this function reads but that callee
 * ignores (src/pending/CLACT_AddActorAnimFrame.c).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/CLACT_UpdateActorAutoAnim.c \
 *       --func CLACT_UpdateActorAutoAnim --addr 0x0204CEB4 --cc 1.1p1 --arm
 */
void CLACT_UpdateActorAutoAnim(struct ClactActor *actor)
{
    if (actor->auto_anim == 1) {
        CLACT_AddActorAnimFrame(actor, actor->auto_anim_speed);
    }
}

/*
 * Apply the seven-field request to the object: the two signed halfwords at
 * +0 and +2 are the two axes of the same setter, selected by a trailing
 * 0/1; the byte at +6 replaces the low eight bits of the flag word at
 * +0x60; the byte at +7 and the halfword at +4 go to their own setters, and
 * CLACT_StartActorAnim commits the result.
 *
 * `ldrsh` with no immediate offset form is the only evidence that the first
 * two fields are `s16` rather than `u16`
 * (docs/idioms/ldrsh-register-offset-is-signedness.md); the third is
 * `ldrh`, so the request really does mix the two.
 *
 * The flag-word update is a plain `bic #0xff` / `orr`, with no shift on
 * either side, which places the field at bit 0 and fixes its width at
 * eight: the value comes from an `ldrb`, so nothing has to mask it first.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/CLACT_ApplyActorInit.c \
 *       --func CLACT_ApplyActorInit --addr 0x0204CED8 --cc 1.1p1 --arm
 */
void CLACT_ApplyActorInit(struct ClactActor *actor, const struct ActorInitParam *init, u32 space)
{
    CLACT_SetActorSurfacePosAxis(actor, init->x, space, 0);
    CLACT_SetActorSurfacePosAxis(actor, init->y, space, 1);
    actor->draw_priority = init->draw_priority;
    CLACT_SetActorBgPriority(actor, init->bg_priority);
    CLACT_SetActorAnimSeq(actor, init->anim_seq);
    CLACT_StartActorAnim(actor);
}

/*
 * Apply a four-field request to the object: the two words at +4 and +8 go
 * through the setters at 0x0204B784 and 0x0204B728, the two halfwords at +0
 * and +2 are copied straight into the object's +0x5c/+0x5e pair.
 *
 * Both halfwords are loaded before either is stored, which is the ordinary
 * effect of the two loads having no dependence on the stores: reading them
 * one at a time would have interleaved `ldrh`/`strh`.
 *
 * Was capped at MATCH: the PC24 site at +0x1c names 0x0204B728 and this is
 * that address's only branch site anywhere in the image, so `label` has
 * nothing outside the compared range to point at, and the two functions are
 * not contiguous, so no unit can make the site `local` either.  0x0204B728
 * is now EXACT in src/matched/CLACT_SetActorPaletteProxy.c (the blocker there was one
 * `const` on the source pointer of its closing struct assignment, see
 * docs/idioms/const-source-pointer-schedules-the-block-load-first.md), and
 * the site resolves `matched` against it.  The C in this file is unchanged.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/CLACT_ApplyActorResources.c \
 *       --func CLACT_ApplyActorResources --addr 0x0204CF40 --cc 1.1p1 --arm
 */
void CLACT_ApplyActorResources(struct ClactActor *actor, const struct ActorReq *req)
{
    CLACT_SetActorImageProxy((char *)actor, (const struct ImageProxy *)req->char_slot);
    CLACT_SetActorPaletteProxy(actor, (const struct PaletteProxy *)req->pltt_slot);
    actor->char_idx = req->char_idx;
    actor->pltt_idx = req->pltt_idx;
}

/*
 * Measure entry `id`, writing the two halfwords of the answer through
 * `out`.  The sentinel id 0xFFFF means "nothing", and zeroes both.
 *
 * 0xFFFF costs a pool word because it is not an ARM rotated immediate
 * (docs/idioms/out-of-range-immediate-subtract-costs-a-pool-word.md is the
 * same constraint on the other side of the comparison).  The whole early
 * return is predicated: one `moveq` feeding two `strheq` and a `popeq`,
 * with no branch anywhere.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/CLACT_GetSurfaceOrigin.c \
 *       --func CLACT_GetSurfaceOrigin --addr 0x0204CF74 --cc 1.1p1 --arm
 */
void CLACT_GetSurfaceOrigin(struct ClactActor *actor, u32 surface_idx, u16 *out)
{
    if (surface_idx == 0xFFFF) {
        out[0] = 0;
        out[1] = 0;
        return;
    }
    CLACT_GetSurfacePos(actor->owner->renderer, surface_idx, (struct ClactVec2 *)out);
}

/*
 * The seven-argument initialiser for the 0x20-byte request record: four
 * arguments arrive in registers, three more off the caller's stack, and the
 * last three words of the record are cleared.
 *
 * The four-register push is not about callee-saved state, it is the cost of
 * having three stack arguments to stage; [sp, #0x10] is the first of them,
 * sixteen bytes past the pushed frame.  `stmib r0, {r3, r5}` is the
 * compiler folding the +4 and +8 stores once both values happen to sit in
 * ascending registers, not a struct copy
 * (docs/idioms/aggregate-assignment-is-ldm-stm.md describes the other case).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/CLACT_InitActorRequest.c \
 *       --func CLACT_InitActorRequest --addr 0x0204CFA4 --cc 1.1p1 --arm
 */
void CLACT_InitActorRequest(struct ActorReq *req, u16 char_idx, u16 pltt_idx, struct CharSlot *char_slot, struct PlttSlot *pltt_slot, struct CellDataBank *cell_bank, struct AnimBank *anim_bank)
{
    req->char_idx = char_idx;
    req->pltt_idx = pltt_idx;
    req->char_slot = char_slot;
    req->pltt_slot = pltt_slot;
    req->cell_bank = cell_bank;
    req->anim_bank = anim_bank;
    req->mc_bank = 0;
    req->mc_anim_bank = 0;
    req->xfer_chars = 0;
}

/*
 * Allocate one object out of the owner's pool, back-link it, initialise its
 * embedded sub-object at +0x68 from the request, apply the two field
 * groups, register it with the owner and enable it.
 *
 * Five of the six callees want the object pointer and two want the owner,
 * so both are pinned for the whole body; that is what forces the
 * five-callee-saved push.  The fifth argument is only read once, straight
 * out of this function's own stack slot at [sp, #0x18] (five pushed
 * registers plus lr above it), and never spilled.
 *
 * Was parked at MATCH.  Three of the six sites name functions whose only
 * branch site image-wide is the one here, so each needed its own EXACT
 * entry to act as a `matched` witness; all three now have one and the C in
 * this file is unchanged.
 *
 *   0x0204C8E4, the allocator, is src/matched/CLACT_GetFreeActor.c.  Its own
 *     blocker was the GF_ASSERT expression string, folded onto the
 *     file-name symbol
 *     (docs/idioms/an-assert-expression-string-rides-the-file-name-symbol.md).
 *   0x0204D0C4, the sub-object initialiser, is src/matched/CLACT_InitAnimCtl.c.
 *     Its handler table 0x020A13DC is row 6 of the array based at
 *     0x020A1394, not a symbol of its own.
 *   0x0204CF40 is src/matched/CLACT_ApplyActorResources.c, which unstuck once
 *     0x0204B728 landed (one `const` on a struct assignment's source).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/CLACT_CreateActorCore.c \
 *       --func CLACT_CreateActorCore --addr 0x0204CFDC --cc 1.1p1 --arm
 */
struct ClactActor *CLACT_CreateActorCore(struct Unit *unit, const struct ActorInitParam *init, struct ActorReq *req, u32 space, u16 heap_id)
{
    struct ClactActor *actor = CLACT_GetFreeActor(unit);

    actor->owner = unit;
    CLACT_InitAnimCtl(&actor->ctl, req, heap_id);
    CLACT_ApplyActorInit(actor, init, space);
    CLACT_ApplyActorResources(actor, req);
    CLACT_LinkActor(unit, actor);
    CLACT_SetActorDrawEnable(actor, 1);
    return actor;
}

/*
 * Build the object with CLACT_CreateActorCore, then apply the six remaining fields
 * of the request to it: two axes share CLACT_SetActorAffineOriginAxis and two more share
 * CLACT_SetActorScaleAxis, selected by a trailing 0/1 argument, and the last two are
 * plain halfwords.
 *
 * The fifth argument is forwarded untouched: `ldrh r4, [sp, #0x18]` reads
 * this function's own stack argument (six pushed registers above it) and
 * `str r4, [sp]` writes it straight back out as CLACT_CreateActorCore's, with r0-r3
 * never disturbed in between.
 *
 * The literals 0 and 1 are each materialised once, into r5 and r4, and
 * reused across four call sites rather than rematerialised per call
 * (docs/idioms/a-small-constant-is-rematerialised-off-a-zero-register-unless-an-argument-shares-it.md,
 * the "an argument shares it" case).  The `s16` field at +8 is loaded twice
 * with `ldrsh`, once per call, because the intervening call could have
 * written it.
 *
 * Was parked at MATCH.  0x0204B59C is reached from exactly two `bl` sites
 * image-wide, 0x0204D06C and 0x0204D080, and both of them are the two call
 * sites above, so no outside `label` witness exists and no cut can create
 * one: a split that removed this function would remove both sites at once.
 * The route taken instead was to decompile 0x0204B59C itself, which is the
 * first of three unlabelled leaf accessors now covered by
 * src/matched/unit_0204B59C.c; both sites here resolve `matched` against
 * that entry.  The C in this file is unchanged.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/CLACT_CreateActorFull.c \
 *       --func CLACT_CreateActorFull --addr 0x0204D048 --cc 1.1p1 --arm
 */
struct ClactActor *CLACT_CreateActorFull(struct Unit *unit, const struct ActorInit *init, struct ActorReq *req, u32 space, u16 heap_id)
{
    struct ClactActor *actor = CLACT_CreateActorCore(unit, &init->param, req, space, heap_id);

    CLACT_SetActorAffineOriginAxis(actor, init->origin_x, 0);
    CLACT_SetActorAffineOriginAxis(actor, init->origin_x, 1);
    CLACT_SetActorScaleAxis(actor, init->scale_x, 0);
    CLACT_SetActorScaleAxis(actor, init->scale_y, 1);
    CLACT_SetActorRotation(actor, init->rotation);
    CLACT_SetActorAffineMode(actor, init->affine_mode);
    return actor;
}

extern void *(*const g_ClactAnimFuncTable[][3])();

/*
 * Constructor for the 0x7c-byte sub-object embedded at +0x68 of the
 * 0x0204Bxxx owner, and the counterpart of the destructor at 0x0204D104:
 * derive the kind tag from the request with CLACT_GetAnimCtlKind, stamp it into
 * word 0, then run row 6 of the handler table at 0x020A1394 with the object
 * and the two forwarded arguments.
 *
 * The kind stays in ip across the table load and is stored only just before
 * the `blx`, which is the ordinary effect of the store having no consumer:
 * the index is needed for the table load either way, so the store sinks to
 * the last position that still precedes the call.
 *
 * The table is row 6 of the one eight-by-three array based at 0x020A1394;
 * see src/matched/CLACT_SetAnimSeq.c for the row map and why the base rather
 * than the row is the relocation's symbol.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/CLACT_InitAnimCtl.c \
 *       --func CLACT_InitAnimCtl --addr 0x0204D0C4 --cc 1.1p1 --arm
 */
void CLACT_InitAnimCtl(struct AnimCtl *anim_ctl, void *req, u32 heap_id)
{
    u32 kind = CLACT_GetAnimCtlKind(req);

    anim_ctl->kind = kind;
    g_ClactAnimFuncTable[6][kind](anim_ctl, req, heap_id);
}

void CLACT_ExitAnimCtl(struct AnimCtl *anim_ctl)
{
    g_ClactAnimFuncTable[5][anim_ctl->kind](anim_ctl);
    MI_CpuFill8(anim_ctl, 0, 0x7c);
}

/*
 * Classify a request into the small index the sibling CLACT_InitAnimCtl uses to
 * pick a handler out of its table: 1 if the pointer at +0x1c is set, else 2
 * if the one at +0x14 is, else 0.  A leaf with no prologue at all, so
 * disasm.py never labelled it.
 *
 * The first arm gets its own `bxne lr` while the last two share one exit as
 * a `movne`/`moveq` pair: that is what an early `return` followed by a
 * two-way tail looks like once the compiler has run out of conditional
 * slots to fold the first test into
 * (docs/idioms/initialise-the-result-before-the-input-or-every-arm-duplicates-the-return.md
 * read in reverse, the result here is not initialised first).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/CLACT_GetAnimCtlKind.c \
 *       --func CLACT_GetAnimCtlKind --addr 0x0204D134 --cc 1.1p1 --arm
 */
s32 CLACT_GetAnimCtlKind(const struct ActorReq *req)
{
    if (req->xfer_chars != 0) {
        return 1;
    }
    if (req->mc_bank != 0) {
        return 2;
    }
    return 0;
}

/*
 * Copy the source's two handles into the object's +4/+8 pair, then bind the
 * record at +0xc to them.
 *
 * The +4 field is read back from memory for NNS_G2dInitCellAnimation's third argument
 * rather than reused out of r2: the intervening call to NNS_G2dGetAnimSequenceByIdx could
 * alias it, so the cached load does not survive
 * (docs/idioms/const-pointer-lets-a-field-load-survive-a-store.md, the case
 * without the `const`).
 *
 * NNS_G2dGetAnimSequenceByIdx is called here with an explicit zero in r1, where
 * src/matched/CLACT_SetCellAnimSeq.c leaves r1 untouched: the two call sites
 * disagree about the arity, and the zero is written out only because this
 * one needs it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/CLACT_InitCellAnimCtl.c \
 *       --func CLACT_InitCellAnimCtl --addr 0x0204D158 --cc 1.1p1 --arm
 */
void CLACT_InitCellAnimCtl(struct AnimCtl *anim_ctl, const struct ActorReq *req)
{
    anim_ctl->cell_bank = req->cell_bank;
    anim_ctl->anim_bank = req->anim_bank;
    NNS_G2dInitCellAnimation((struct CellAnim *)anim_ctl->anim, NNS_G2dGetAnimSequenceByIdx(anim_ctl->anim_bank, 0), anim_ctl->cell_bank);
}

/*
 * Record builder in clact.c.  Wave 15 (register-tie lane): the last 10
 * bytes (the image sinks `mov sb, r0` above the two req->cell_bank/req->anim_bank loads)
 * close with `const struct ActorReq *req`.  The read-only source pointer lets the
 * parameter copy of anim_ctl be scheduled before the loads, freeing r0 for the
 * stmib pair {r0, r1}.  The rest is the 2026-09-22 source from
 * docs/notes/pkt_0204D18C.CLACT_InitVramAnimCtl.c.txt: the nested t1/t0 block
 * (descending loads) for the stmib, and `two - 3` for the -1 argument.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/CLACT_InitMultiCellAnimCtl.c \
 *       --func CLACT_InitMultiCellAnimCtl --addr 0x0204D18C --cc 1.1p1 --arm
 */
void CLACT_InitMultiCellAnimCtl(struct AnimCtl *anim_ctl, const struct ActorReq *req)
{
    u32 zero = 0;
    u32 two;
    uptr anim_data; u32 main_vram_addr, sub_vram_addr;
    const NNSG2dCharacterData *chars;

    {
        struct AnimBank *anim_bank = req->anim_bank;
        struct CellDataBank *cell_bank = req->cell_bank;
        anim_ctl->cell_bank = cell_bank;
        anim_ctl->anim_bank = anim_bank;
    }
    anim_ctl->xfer_handle = NNSi_G2dGetCellTransferStateIndex();
    chars = req->xfer_chars;
    anim_data = (uptr)NNS_G2dGetAnimSequenceByIdx(anim_ctl->anim_bank, zero);
    main_vram_addr = NNSi_G2dGetVramHandleValue((int *)req->char_slot, 1);
    two = 2;
    sub_vram_addr = NNSi_G2dGetVramHandleValue((int *)req->char_slot, two);
    NNS_G2dInitCellAnimationVramTransfered((struct CellAnim *)anim_ctl->anim, (struct AnimSequenceData *)anim_data, anim_ctl->cell_bank, anim_ctl->xfer_handle,
                  two - 3, main_vram_addr, sub_vram_addr, (sptr)chars->pRawData, zero, chars->szByte);
}

/*
 * Record constructor in clact.c.  Wave 15 (register-tie lane): EXACT* (the
 * listing extent runs over the unlabelled fill leaf 0x0204D2C8, filed as
 * src/matched/CLACT_ExitCellAnimCtl.c).  Two facts closed it:
 *  - the older 2-byte "best source" in
 *    docs/notes/pkt_0204D18C.CLACT_InitVramAnimCtl.c.txt stored req->mc_bank into +0x04
 *    and req->cell_bank into +0x70, which is NOT what the image does (image: +0x04
 *    gets cell_bank, +0x70 gets mc_bank).  The honest residue with the image's
 *    pairing was 9 bytes.
 *  - `const struct ActorReq *req` with the four stores written straight from req and
 *    NNS_G2dGetMCWorkAreaSize fed a fresh req->mc_bank: the const source lets mwcc keep all
 *    four loads above the stores in field order and CSE the mc_bank re-read.
 *    The `volatile` device on +0x04 is no longer needed.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/CLACT_InitVramAnimCtl.c \
 *       --func CLACT_InitVramAnimCtl --addr 0x0204D224 --cc 1.1p1 --arm
 */
void CLACT_InitVramAnimCtl(struct AnimCtl *anim_ctl, const struct ActorReq *req, u32 heap_id)
{
    anim_ctl->cell_bank = req->cell_bank;
    anim_ctl->anim_bank = req->anim_bank;
    anim_ctl->mc_bank = req->mc_bank;
    anim_ctl->mc_anim_bank = req->mc_anim_bank;

    anim_ctl->mc_work = GFL_HEAP_Alloc(heap_id, NNS_G2dGetMCWorkAreaSize(req->mc_bank, 1), 0, s_clact_c, 0x171d);
    NNS_G2dInitMCAnimation((struct MultiCellAnim *)anim_ctl->anim, anim_ctl->mc_work, anim_ctl->anim_bank, anim_ctl->cell_bank, anim_ctl->mc_bank, 1);
    NNS_G2dSetAnimSequenceToMCAnimation((struct MultiCellAnim *)anim_ctl->anim, NNS_G2dGetAnimSequenceByIdx(anim_ctl->mc_anim_bank, 0));
}

/*
 * Unlabelled leaf after CLACT_InitVramAnimCtl in clact.c: clears the 0x7c-byte
 * animation sub-object (the same fill CLACT_ExitMultiCellAnimCtl ends with), as a tail
 * call.  Filed as the witness that turns CLACT_InitVramAnimCtl's EXACT* into EXACT
 * once 0x0204D2C8 is seeded.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/CLACT_ExitCellAnimCtl.c \
 *       --func CLACT_ExitCellAnimCtl --addr 0x0204D2C8 --cc 1.1p1 --arm
 */
void CLACT_ExitCellAnimCtl(void *anim)
{
    MI_CpuFill8(anim, 0, 0x7c);
}

/*
 * Destructor for one variant of the 0x7c-byte 0x0204Cxxx/0x0204Dxxx
 * object: release the sub-resource whose handle lives at +0x64, then wipe
 * the whole record.  0x02082BCC is the SDK's byte fill (dest, value,
 * length); the 0x7c length is the object's own size, which the sibling
 * CLACT_ExitVramAnimCtl repeats verbatim for the +0x78 variant.
 *
 * Was capped at MATCH: the PC24 site at +0x0c names 0x02066B38 and this is
 * that address's only branch site anywhere in the image, so `label` has
 * nothing to point at and no split can create one from a single function.
 * 0x02066B38 is now EXACT in src/matched/NNSi_G2dResetCellTransferState.c and the site
 * resolves `matched` against it.  The C in this file is unchanged.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/CLACT_ExitMultiCellAnimCtl.c \
 *       --func CLACT_ExitMultiCellAnimCtl --addr 0x0204D2DC --cc 1.1p1 --arm
 */
void CLACT_ExitMultiCellAnimCtl(struct AnimCtl *anim_ctl)
{
    NNSi_G2dResetCellTransferState((u32)anim_ctl->xfer_handle);
    MI_CpuFill8(anim_ctl, 0, 0x7c);
}

/*
 * The sibling of CLACT_ExitMultiCellAnimCtl: same destructor shape for the variant whose
 * owned resource hangs off +0x78 and is freed through the heap entry point
 * at 0x020307B0 rather than 0x02066B38.  The trailing wipe is the same
 * 0x7c-byte object fill.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/CLACT_ExitVramAnimCtl.c \
 *       --func CLACT_ExitVramAnimCtl --addr 0x0204D300 --cc 1.1p1 --arm
 */
void CLACT_ExitVramAnimCtl(struct AnimCtl *anim_ctl)
{
    GFL_HEAP_Free(anim_ctl->mc_work);
    MI_CpuFill8(anim_ctl, 0, 0x7c);
}

/*
 * Dispatch on the object's kind word, passing the object and one forwarded
 * argument.
 *
 * The second parameter is real, not a leftover: the original steps over r1
 * entirely (kind in r3, table base in r2) where the one-parameter spelling
 * uses r2 and r1.  A register that the body never touches and never
 * reallocates is a live argument being forwarded.
 *
 * This file was previously parked at MATCH on the theory that the pool word
 * 0x020A13B8 named a table object of its own, which left the ABS32 site
 * with no witness: 0x020A13B8 appears in exactly one pool image-wide, this
 * function's own, and self-reference is refused.  It is not a table of its
 * own.  The words from 0x020A1394 onward are one two-dimensional array of
 * at least eleven rows of three handlers, indexed [operation][kind], and
 * the functions of this family each pin a different row:
 *
 *   row 0  0x020A1394   pooled at 0x0204D490
 *   row 1  0x020A13A0   pooled at 0x0204D45C
 *   row 3  0x020A13B8   pooled here
 *   row 5  0x020A13D0   pooled at 0x0204D130  (CLACT_ExitAnimCtl)
 *   row 6  0x020A13DC   pooled at 0x0204D100
 *   row 7  0x020A13E8   pooled at 0x0204D428  (CLACT_GetAnimCtrl)
 *   row 10 0x020A140C   pooled at 0x0204D3C4  (unit_0204D3C4.c)
 *
 * Declared that way the relocation names the array's base, 0x020A1394, and
 * the +0x24 is the row index coming from the C rather than from the bytes
 * under test; the base is attested `literal` by the pool word at 0x0204D490,
 * well outside this range.  Same bytes, same pool word, an honest witness.
 * See docs/idioms/pool-base-for-a-far-field-is-the-symbol-offset-masked-by-the-load-reach.md.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/CLACT_SetAnimSeq.c \
 *       --func CLACT_SetAnimSeq --addr 0x0204D324 --cc 1.1p1 --arm
 */
void CLACT_SetAnimSeq(struct AnimCtl *anim_ctl, u32 anim_seq)
{
    g_ClactAnimFuncTable[3][anim_ctl->kind](anim_ctl, anim_seq);
}

/*
 * One of this family's per-slot "apply" hooks: take the handle at +8,
 * resolve it through NNS_G2dGetAnimSequenceByIdx, and feed the result to NNS_G2dSetCellAnimationSequence
 * together with the embedded record at +0xc.  CLACT_SetMultiCellAnimSeq is a
 * byte-for-byte duplicate of this function at a different address (the two
 * differ only in their PC24 displacements), which is what a pair of
 * distinct table slots sharing one body looks like when neither was folded.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/CLACT_SetCellAnimSeq.c \
 *       --func CLACT_SetCellAnimSeq --addr 0x0204D340 --cc 1.1p1 --arm
 */
void CLACT_SetCellAnimSeq(struct AnimCtl *anim_ctl, u32 idx)
{
    NNS_G2dSetCellAnimationSequence((struct CellAnim *)anim_ctl->anim, NNS_G2dGetAnimSequenceByIdx(anim_ctl->anim_bank, idx));
}

/*
 * The second copy of CLACT_SetCellAnimSeq: same body, same two callees, emitted
 * again thirty-two bytes later.  Two adjacent dispatch-table slots each got
 * their own definition and nothing folded them, so the only difference
 * between the two functions in the image is the PC24 displacement.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/CLACT_SetMultiCellAnimSeq.c \
 *       --func CLACT_SetMultiCellAnimSeq --addr 0x0204D360 --cc 1.1p1 --arm
 */
void CLACT_SetMultiCellAnimSeq(struct AnimCtl *anim_ctl, u32 idx)
{
    NNS_G2dSetCellAnimationSequence((struct CellAnim *)anim_ctl->anim, NNS_G2dGetAnimSequenceByIdx(anim_ctl->anim_bank, idx));
}

/*
 * The third member of the CLACT_SetCellAnimSeq / CLACT_SetMultiCellAnimSeq trio, reading the
 * handle from +0x74 instead of +8 and finishing in NNS_G2dSetAnimSequenceToMCAnimation instead of
 * NNS_G2dSetCellAnimationSequence.  The shared middle step, NNS_G2dGetAnimSequenceByIdx on the handle, is
 * what says these three are the same operation over different slots.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/CLACT_SetVramAnimSeq.c \
 *       --func CLACT_SetVramAnimSeq --addr 0x0204D380 --cc 1.1p1 --arm
 */
void CLACT_SetVramAnimSeq(struct AnimCtl *anim_ctl, u32 idx)
{
    NNS_G2dSetAnimSequenceToMCAnimation((struct MultiCellAnim *)anim_ctl->anim, NNS_G2dGetAnimSequenceByIdx(anim_ctl->mc_anim_bank, idx));
}

/*
 * Set the +0x10 field of the record CLACT_GetAnimCtrl resolves for this object,
 * then re-run the object through the CLACT_AddAnimFrame dispatcher with a zero
 * second argument.  Both callees are themselves index-dispatch thunks
 * (`ldr r3,[r0]; ldr r2,[table, r3 lsl 2]; blx r2`), so this function is
 * the C-visible half of a virtual pair.
 *
 * The object pointer is kept in r5 across the first call rather than
 * recomputed, which is what forces the four-register push: r4 holds the
 * incoming second argument over the same call.
 *
 * This is the missing witness for src/pending/CLACT_SetActorAnimFrame.c, whose only
 * unresolved site is the ABS32 pool word naming 0x0204D3A0.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/CLACT_SetAnimFrame.c \
 *       --func CLACT_SetAnimFrame --addr 0x0204D3A0 --cc 1.1p1 --arm
 */
void CLACT_SetAnimFrame(struct AnimCtl *anim_ctl, u32 value)
{
    CLACT_GetAnimCtrl(anim_ctl)->currentTime = value;
    CLACT_AddAnimFrame(anim_ctl, 0);
}

void *CLACT_AddAnimFrame(struct AnimCtl *anim_ctl, u32 speed)
{
    return g_ClactAnimFuncTable[10][anim_ctl->kind](anim_ctl, speed);
}

void CLACT_AddCellAnimFrame(struct AnimCtl *anim_ctl, s32 frames)
{
    NNS_G2dTickCellAnimation((struct CellAnim *)(anim_ctl->anim), frames);
}

void CLACT_AddMultiCellAnimFrame(struct AnimCtl *anim_ctl, s32 frames)
{
    NNS_G2dTickCellAnimation((struct CellAnim *)(anim_ctl->anim), frames);
}

void CLACT_AddVramAnimFrame(struct AnimCtl *anim_ctl, s32 frames)
{
    NNS_G2dTickMCAnimation((struct MultiCellAnim *)anim_ctl->anim, frames);
}

/*
 * One index-dispatch thunk plus the three handlers it dispatches to, 52
 * bytes end to end with no padding.  The object's first word is a small
 * kind index, and row 7 of the handler table at 0x020A1394 holds the three
 * implementations, which are all the same pointer adjustment to +0xc.
 * They save nothing, so disasm.py gives them no labels and they used to be
 * this function's `EXACT*` tail; as a unit they are four real entries.
 *
 * The register pair the load uses names the arity: this one allocates r2
 * then r1, leaving r1 free, so the thunk forwards only r0
 * (docs/idioms/a-forwarding-call-passes-one-argument-and-the-rest-are-leftovers.md).
 * `blx` plus `push {r3, lr}` rather than a tail `bx` is the ordinary
 * non-tail form: the result is returned unchanged, which is what lets
 * CLACT_SetAnimFrame write through it directly.
 *
 * This file was parked at MATCH* while 0x020A13E8 was read as a table
 * object of its own, which left the ABS32 without a witness.  It is row 7
 * of the one eight-by-three array based at 0x020A1394; see
 * src/matched/CLACT_SetAnimSeq.c for the row map and the reasoning.  The base
 * is attested `literal` by the pool word at 0x0204D490, outside this range.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0204D410.c \
 *       --addr 0x0204D410 --arm
 */
AnimCtrl *CLACT_GetAnimCtrl(struct AnimCtl *anim_ctl)
{
    return g_ClactAnimFuncTable[7][anim_ctl->kind](anim_ctl);
}

void *CLACT_GetCellAnimCtrl(struct AnimCtl *anim_ctl)
{
    return anim_ctl->anim;
}

void *CLACT_GetMultiCellAnimCtrl(struct AnimCtl *anim_ctl)
{
    return anim_ctl->anim;
}

void *CLACT_GetVramAnimCtrl(struct AnimCtl *anim_ctl)
{
    return anim_ctl->anim;
}

/*
 * The same shape as src/matched/unit_0204D410.c one row over: the thunk
 * dispatches on the object's kind through row 1 of the handler table at
 * 0x020A1394, and the three row-1 handlers are again the +0xc pointer
 * adjustment.  Three unlabelled leaves folded into the unit with the thunk.
 *
 * The base is attested `literal` by the pool word at 0x0204D490, outside
 * this range; see src/matched/CLACT_SetAnimSeq.c for the row map.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0204D444.c \
 *       --addr 0x0204D444 --arm
 */
AnimCtrl *CLACT_GetAnimObject(struct AnimCtl *anim_ctl)
{
    return g_ClactAnimFuncTable[1][anim_ctl->kind](anim_ctl);
}

void *CLACT_GetCellAnimObject(struct AnimCtl *anim_ctl)
{
    return anim_ctl->anim;
}

void *CLACT_GetMultiCellAnimObject(struct AnimCtl *anim_ctl)
{
    return anim_ctl->anim;
}

void *CLACT_GetVramAnimObject(struct AnimCtl *anim_ctl)
{
    return anim_ctl->anim;
}

/*
 * Row 0 of the eight-by-three handler table at 0x020A1394, the same shape as
 * src/matched/unit_0204D410.c (row 7), src/matched/unit_0204D444.c (row 1)
 * and src/matched/CLACT_SetAnimSeq.c (row 3, and the row map).  Every concrete
 * byte is reproduced; the single unresolved site is the ABS32 in the pool.
 *
 * Blocked on: evidence class `literal`, and it can never be satisfied.  For
 * rows 1, 3, 5, 6 and 7 the pool word is base+0x0c..base+0x54, so some other
 * row's thunk holds a different word and the base is witnessed from outside.
 * Row 0's pool word *is* the array base, 0x020A1394, and `--suggest-split`
 * reports exactly one witness image-wide: this function's own relocation site
 * at 0x0204D490.  Self-reference is refused, so no cut can free it.  It would
 * become EXACT only if some future matched entry defines the table data at
 * 0x020A1394, or if a caller elsewhere is found that pools the bare base.
 *
 * The arity comes from the register pair, not from the call: the original
 * takes the kind in r3 and the table base in r2, which is the two-parameter
 * allocation (compare src/matched/CLACT_SetAnimSeq.c).  The one-parameter
 * spelling allocates r2 then r1 and is a four-instruction diff.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/CLACT_SetAnimIndex.c \
 *       --func CLACT_SetAnimIndex --addr 0x0204D478 --cc 1.1p1 --arm
 */
void *CLACT_SetAnimIndex(struct AnimCtl *anim_ctl, u32 anim_idx)
{
    return g_ClactAnimFuncTable[0][anim_ctl->kind](anim_ctl, anim_idx);
}

/*
 * Two identical tail calls to the same callee with the argument biased by
 * 0xc.  Unlabelled leaves; the range 0x0204D494..0x0204D4B4 is contiguous.
 */
void CLACT_SetCellAnimIndex(u8 *anim_base, u32 frame)
{
    NNS_G2dSetCellAnimationCurrentFrame((struct CellAnim *)(anim_base + 0xc), frame);
}

void CLACT_SetMultiCellAnimIndex(u8 *anim_base, u32 frame)
{
    NNS_G2dSetCellAnimationCurrentFrame((struct CellAnim *)(anim_base + 0xc), frame);
}

/*
 * note:     promoted 2026-09-21: the blocker named below, 0x02064AB4, was
 *           filed EXACT as src/matched/NNS_G2dSetMCAnimationCurrentFrame.c (pin ../2.0/sp2) by the
 *           pkt_02064934 lane, so the sole ABS32 site now resolves `matched`.
 *
 * The third row-0 handler of the table at 0x020A1394 (row map in
 * src/matched/CLACT_SetAnimSeq.c).  Same shape as the two in
 * src/matched/unit_0204D494.c, tail calling the +0xc subobject through a pool
 * word, but to a different target.  It saves nothing, so disasm.py gives it
 * no label.
 *
 * Was blocked on: no evidence class at all.  `--suggest-split` reported zero
 * witnesses image-wide for 0x02064AB4: nothing branches to it (so no `label`),
 * no other pool holds the word (so no `literal`), and it is inside the G2D
 * block that has no matched entry yet.  The address is reachable only through
 * this table row, which is why it never appears as a branch target.  It will
 * resolve as `matched` once the G2D function at 0x02064AB4 is decompiled, or
 * as `label` if an overlay turns out to call it directly.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/CLACT_SetVramAnimIndex.c \
 *       --func CLACT_SetVramAnimIndex --addr 0x0204D4B4 --cc 1.1p1 --arm
 */
void CLACT_SetVramAnimIndex(struct AnimCtl *anim_ctl, u32 frame)
{
    NNS_G2dSetMCAnimationCurrentFrame((struct MultiCellAnim *)anim_ctl->anim, frame);
}

/*
 * A dispatch thunk and the first two of the three handlers its table row
 * names, 60 bytes end to end.  Each handler steps the pointer past the
 * object's 0xc-byte header and tail-calls into the G2D layer; a tail call
 * is always a pool word and a `bx`, never a displacement branch, because
 * every function is its own section
 * (docs/idioms/tail-call-is-a-pool-word-and-bx.md).  The handlers save
 * nothing, so disasm.py gives them no labels; they are folded in here
 * rather than left as this thunk's `EXACT*` tail.
 *
 * The thunk forwards two arguments, not one: it allocates r3 then r2 for
 * the table load, leaving r1 alone, where the one-argument form in
 * src/matched/unit_0204D410.c allocates r2 then r1
 * (docs/idioms/a-forwarding-call-passes-one-argument-and-the-rest-are-leftovers.md).
 *
 * The third handler, CLACT_SetVramAnimSpeed at 0x0204D500, is deliberately left out
 * of the range: its tail-call target 0x02064B68 is named only by its own
 * pool word, so including it caps the whole unit at MATCH.  It is parked
 * byte-correct in src/pending/CLACT_SetVramAnimSpeed.c, and it graduates when
 * 0x02064B68 does (docs/notes/NNS_G2dSetMCAnimationSpeed.c.txt).
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0204D4C4.c \
 *       --addr 0x0204D4C4 --arm
 */
void CLACT_SetAnimSpeed(struct AnimCtl *anim_ctl, u32 frames)
{
    gClactTables.anim_update[anim_ctl->kind](anim_ctl, frames);
}

void CLACT_SetCellAnimSpeed(struct AnimCtl *anim_ctl, u32 value)
{
    NNS_G2dSetCellAnimationSpeed((struct CellAnim *)(anim_ctl->anim), value);
}

void CLACT_SetMultiCellAnimSpeed(struct AnimCtl *anim_ctl, u32 value)
{
    NNS_G2dSetCellAnimationSpeed((struct CellAnim *)(anim_ctl->anim), value);
}

/*
 * The third handler of the row that src/matched/unit_0204D4C4.c dispatches
 * through: step the pointer past the object's 0xc-byte header and tail-call
 * into the G2D layer, forwarding the second argument untouched.
 *
 * Byte-correct, capped at MATCH.  The tail call is a pool word and a `bx`
 * (docs/idioms/tail-call-is-a-pool-word-and-bx.md), so the site is an ABS32
 * naming 0x02064B68, and that address is named by no other pool word and by
 * no branch anywhere in the image: `label`, `literal` and `veneer` all have
 * nothing outside this range.  The one route left is an EXACT entry for
 * 0x02064B68 itself acting as a `matched` witness; that function is a
 * 168-byte two-armed cell/node walk which is four transposed instructions
 * away from matching, recorded in docs/notes/NNS_G2dSetMCAnimationSpeed.c.txt.
 *
 * Kept out of unit_0204D4C4.c for exactly this reason: folding it back in
 * would cap that whole range at MATCH for one unattestable word.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/CLACT_SetVramAnimSpeed.c \
 *       --func CLACT_SetVramAnimSpeed --addr 0x0204D500 --cc 1.1p1 --arm
 */
void CLACT_SetVramAnimSpeed(struct AnimCtl *anim_ctl, u32 target)
{
    NNS_G2dSetMCAnimationSpeed((struct MultiCellAnim *)((anim_ctl->anim)), (int)target);
}

/*
 * Closes the clact.c fan-in-1 blocker documented in
 * docs/notes/clact_c_fan_in_1_blockers.c.txt: CLACT_RestartActorAnim (its only
 * caller image wide) forwards its argument unchanged.
 *
 * Dispatch through a function-pointer table indexed by the mode word at
 * +0x00 of the argument; the call itself is an indirect `blx` (no PC24
 * relocation to attest), but the table base at 0x020A7F48 is an ABS32
 * literal with no second reference anywhere in the ARM9 image, so this
 * stays MATCH regardless of the C.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/CLACT_ResetAnim.c \
 *       --func CLACT_ResetAnim --addr 0x0204D510 --cc 1.1p1 --arm
 */
void CLACT_ResetAnim(struct AnimCtl *anim_ctl)
{
    g_ClactAnimResetFuncs[anim_ctl->kind](anim_ctl);
}

void CLACT_ResetCellAnim(void *anim_base){ NNS_G2dRestartCellAnimation((struct CellAnim *)((char *)anim_base + 0xc)); }

/*
 * The same 0xc-biased tail call to the other callee of the pair.
 */
void CLACT_ResetMultiCellAnim(u8 *anim_base)
{
    NNS_G2dRestartCellAnimation((struct CellAnim *)(anim_base + 0xc));
}

/*
 * Tear the actor down and release the sub-object at +0x40: CLACT_ResetCellAnim on
 * the actor itself, then NNSi_G2dSetMCInstanceCurrentFrameZero on the tail.
 *
 * Both call sites resolve from `matched` witnesses, which is what this file
 * waited for while it sat parked in src/pending/ with both PC24s wildcarded.
 * The trailing star is the listing extent only: the next func_ label after
 * 0x0204D54C is 540 bytes away, so the harness compares the 32 bytes this
 * body compiles to and reports the disagreement rather than a concrete diff.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/CLACT_ResetVramAnim.c \
 *       --func CLACT_ResetVramAnim --addr 0x0204D54C --cc 1.1p1 --arm
 */
void CLACT_ResetVramAnim(void *anim_base)
{
    CLACT_ResetCellAnim(anim_base);
    NNSi_G2dSetMCInstanceCurrentFrameZero((struct MCInstance *)((u8 *)anim_base + 0x40));
}

void *CLACT_GetCellUserAttr(struct AnimCtl *anim_ctl, u32 idx)
{
    UserExtBlock *block = (UserExtBlock *)anim_ctl->anim_bank->pSubBank;
    UserAttrTable *table;
    if (block == 0 || block->tag != 0x55414154) {
        block = 0;
    }
    table = block != 0 ? &block->tbl : 0;
    if (table != 0) {
        if ((u16)idx < table->count) {
            return table->items + (u16)idx * 12;
        }
        return 0;
    }
    return 0;
}

void *CLACT_GetMultiCellUserAttr(struct AnimCtl *anim_ctl, u32 idx)
{
    UserExtBlock *block = (UserExtBlock *)anim_ctl->anim_bank->pSubBank;
    UserAttrTable *table;
    if (block == 0 || block->tag != 0x55414154) {
        block = 0;
    }
    table = block != 0 ? &block->tbl : 0;
    if (table != 0) {
        if ((u16)idx < table->count) {
            return table->items + (u16)idx * 12;
        }
        return 0;
    }
    return 0;
}

void *CLACT_GetVramCellUserAttr(struct AnimCtl *anim_ctl, u32 idx)
{
    UserExtBlock *block = (UserExtBlock *)anim_ctl->mc_anim_bank->pSubBank;
    UserAttrTable *table;
    if (block == 0 || block->tag != 0x55414154) {
        block = 0;
    }
    table = block != 0 ? &block->tbl : 0;
    if (table != 0) {
        if ((u16)idx < table->count) {
            return table->items + (u16)idx * 12;
        }
        return 0;
    }
    return 0;
}

UserAttrTable *CLACT_GetCellUserAttrTable(struct AnimCtl *anim_ctl)
{
    UserExtBlock *block = (UserExtBlock *)anim_ctl->cell_bank->pUserExt;
    if (block == 0 || block->tag != 0x55434154) {
        block = 0;
    }
    return block != 0 ? &block->tbl : 0;
}

UserAttrTable *CLACT_GetMultiCellUserAttrTable(struct AnimCtl *anim_ctl)
{
    UserExtBlock *block = (UserExtBlock *)anim_ctl->cell_bank->pUserExt;
    if (block == 0 || block->tag != 0x55434154) {
        block = 0;
    }
    return block != 0 ? &block->tbl : 0;
}

UserAttrTable *CLACT_GetVramCellUserAttrTable(struct AnimCtl *anim_ctl)
{
    UserExtBlock *block = (UserExtBlock *)anim_ctl->mc_bank->pAnimBank;
    if (block == 0 || block->tag != 0x55434154) {
        block = 0;
    }
    return block != 0 ? &block->tbl : 0;
}

u16 CLACT_GetCellBankCount(struct AnimCtl *anim_ctl)
{
    return *(u16 *)anim_ctl->anim_bank;
}

u16 CLACT_GetMultiCellBankCount(struct AnimCtl *anim_ctl)
{
    return *(u16 *)anim_ctl->anim_bank;
}

u16 CLACT_GetVramCellBankCount(struct AnimCtl *anim_ctl)
{
    return *(u16 *)anim_ctl->mc_anim_bank;
}

/*
 * Apply one animation command record to the handle behind the cell actor's
 * +0x68 sub-object.  The opcode is the u16 at +0 of the record; 0 and 2 both
 * call NNS_G2dSetCellAnimationParam with a different mode, 1 calls NNS_G2dSetCellAnimationParamTagged with the
 * record's own u16 at +2 as its last argument.
 *
 * Three cases dense from zero, yet no halfword table: the compiler emits a
 * compare chain because the arms are all tail calls with no shared code, so
 * the table would cost more than the three compares
 * (docs/idioms/dense-switch-is-a-pc-relative-halfword-table.md is the case
 * where it does build one).  The compare chain runs 0, 1, 2 in case-label
 * order whatever the source does, but the arm *blocks* are laid out in source
 * order, so the cases have to be written 0, 2, 1 to put case 1's block last.
 * That is the only thing separating this from the image: with the arms in
 * numeric order the two `beq` displacements swap and fourteen bytes differ.
 *
 * `ldmib r4, {r2, r3}` is not a struct copy, it is the compiler merging the
 * two consecutive word loads at +4 and +8 that feed argument registers three
 * and four.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/CLACT_ApplyAnimCommand.c \
 *       --func CLACT_ApplyAnimCommand --addr 0x0204D768 --cc 1.1p1 --arm
 */
void CLACT_ApplyAnimCommand(struct AnimCtl *anim_ctl, const struct ClactAnimCommand *cmd)
{
    void *anim_ctrl = CLACT_GetAnimCtrl(anim_ctl);

    switch (cmd->op) {
    case 0:
        NNS_G2dSetCellAnimationParam(anim_ctrl, 1, cmd->param, cmd->func);
        break;
    case 2:
        NNS_G2dSetCellAnimationParam(anim_ctrl, 3, cmd->param, cmd->func);
        break;
    case 1:
        NNS_G2dSetCellAnimationParamTagged(anim_ctrl, cmd->param, cmd->func, cmd->tag);
        break;
    }
}

/*
 * Reset the animation handle behind the cell actor's +0x68 sub-object: the
 * all-zero form of the case-0 arm of CLACT_ApplyAnimCommand next door.
 *
 * The three zero arguments are one `mov r1, #0` and two register copies, not
 * three `mov`s of an immediate
 * (docs/idioms/a-small-constant-is-rematerialised-off-a-zero-register-unless-an-argument-shares-it.md).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/CLACT_ResetAnimCommand.c \
 *       --func CLACT_ResetAnimCommand --addr 0x0204D7C4 --cc 1.1p1 --arm
 */
void CLACT_ResetAnimCommand(struct AnimCtl *anim_ctl)
{
    NNS_G2dSetCellAnimationParam((struct CellAnim *)(CLACT_GetAnimCtrl(anim_ctl)), 0, 0, 0);
}

/*
 * Blocked at MATCH: all 204 concrete bytes are correct; CLACT_AllocCharacterTable,
 * CLACT_AllocPaletteTable and CLACT_AllocCellAnimTable all now resolve `matched` off their own
 * manifest entries (src/matched/CLACT_AllocCharacterTable.c, CLACT_AllocPaletteTable.c). Only
 * VMAN_Create (+0x0038 and +0x005C) is left, and it cannot reach EXACT
 * from here: see docs/notes/VMAN_Create.c.txt. Its only two branch
 * references image wide are the two calls in this function, so no cut
 * frees it, and decompiling it does not help either, since it is itself
 * blocked by VMAN_GetBankSetSize's unwitnessed g_FlagTable literal, one level
 * further down.
 *
 * Build the cell-actor system's five resource managers out of the caller's
 * config and capacity records, then keep a copy of the six capacities in the
 * output block at +0x14..+0x1e.
 *
 * The first two managers are the same VMAN_Create with a different pair of
 * config words; its fifth argument goes through the four-byte stack slot the
 * prologue reserves, which is the whole reason for the `sub sp, sp, #4`.  The
 * shared constant 1 is hoisted into r8 rather than re-materialised at each
 * call, because both calls want it in r1 and nothing in between clobbers it.
 *
 * The two capacities that reach VMAN_Create are scaled by 32 with a plain
 * `lsl` on the zero-extended halfword; the six stores at the end are six
 * separate `strh`, not an aggregate copy, so they are written as six field
 * assignments (docs/idioms/aggregate-assignment-is-ldm-stm.md is the shape
 * that would have collapsed them).
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/CLACT_InitResources.c \
 *       --func CLACT_InitResources --addr 0x0204D7E0 --cc 1.1p1 --arm
 */
void CLACT_InitResources(struct ClactRes *res, u32 heapId, const struct DispVramCfg *cfg,
                   const struct Caps *caps)
{
    res->vram_main    = VMAN_Create(heapId, 1, cfg->main_obj_bank, caps->n_main_blocks << 5,
                                  cfg->main_obj_mapping);
    res->vram_sub = VMAN_Create(heapId, 1, cfg->sub_obj_bank, caps->n_sub_blocks << 5,
                                  cfg->sub_obj_mapping);
    res->chars     = CLACT_AllocCharacterTable(heapId, caps->n_chars);
    res->pltts     = CLACT_AllocPaletteTable(heapId, caps->n_pltts);
    res->cells  = CLACT_AllocCellAnimTable(heapId, caps->n_cells);

    res->n_chars     = caps->n_chars;
    res->n_pltts     = caps->n_pltts;
    res->n_cells  = caps->n_cells;
    res->n_spare   = caps->n_spare;
    res->n_main_blocks    = caps->n_main_blocks;
    res->n_sub_blocks = caps->n_sub_blocks;
}

/*
 * Was blocked at MATCH: all 264 concrete bytes were correct and the two PC24
 * sites at +0x00E0 and +0x00E8, both calls to VMAN_Delete, had no witness
 * of any class (those two calls were its only branch references image
 * wide).  Unblocked by src/matched/VMAN_Delete.c, now a `matched` witness.
 *
 * The inverse of src/pending/CLACT_InitResources.c: release every live entry of the
 * three parallel tables, then the tables themselves and the two heaps, and
 * NULL all five pointers.  This block is the tail of the singleton, at
 * +0x104, which is why the three per-entry finalisers take a bare index and
 * find the table through the global themselves (src/matched/CLACT_ReleaseCharacter.c,
 * CLACT_ReleasePalette.c and CLACT_ReleaseCellAnim.c).
 *
 * The liveness tests are the same three fields those finalisers write: the
 * one-bit field at bit 31 of +0x3c of the 0x40-byte record, the whole word at
 * +0x10 of the 0x14-byte record, and the one-bit field at bit 31 of +0x14 of
 * the 0x18-byte record.  Bit 31 reads as a bare `lsrs #0x1f` with no mask,
 * which is the bitfield tell
 * (docs/idioms/shift-pair-with-no-matching-type-is-a-bitfield.md).
 *
 * Every loop re-reads both its bound and its table base, because the
 * finaliser it calls is opaque and may store to the singleton.  The two
 * non-power-of-two strides become `mla` against a register-held 0x14 and
 * 0x18; only the 0x40 stride folds into `add r0, r0, r4, lsl #6`.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/CLACT_ExitResources.c \
 *       --func CLACT_ExitResources --addr 0x0204D8AC --cc 1.1p1 --arm
 */
void CLACT_ExitResources(struct ClactRes *res)
{
    u32 i;

    for (i = 0; i < res->n_chars; i++) {
        if (res->chars[i].free == 0) {
            CLACT_ReleaseCharacter(i);
        }
    }

    for (i = 0; i < res->n_cells; i++) {
        if (res->cells[i].free == 0) {
            CLACT_ReleaseCellAnim(i);
        }
    }

    for (i = 0; i < res->n_pltts; i++) {
        if (res->pltts[i].free == 0) {
            CLACT_ReleasePalette(i);
        }
    }

    CLACT_FreeCharacterTable(res->chars);
    CLACT_FreePaletteTable(res->pltts);
    CLACT_FreeCellAnimTable(res->cells);
    VMAN_Delete((struct VmanBank *)res->vram_sub);
    VMAN_Delete((struct VmanBank *)res->vram_main);

    res->vram_main    = 0;
    res->vram_sub = 0;
    res->chars     = 0;
    res->pltts     = 0;
    res->cells  = 0;
}

/*
 * Two-value compatibility test: value 2 is the wildcard, otherwise the two
 * have to be equal.  A leaf, no relocation.
 *
 * The disjunction has to be one expression so that both halves share the
 * `moveq r0, #1` / `bxeq lr` exit
 * (docs/idioms/disjunction-must-be-one-expression-to-share-its-exit.md); the
 * second test is the predicated `cmpne r1, #2`, which is what a `||` looks
 * like once it is short enough not to branch.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/CLACT_IsVramTypeCompatible.c \
 *       --func CLACT_IsVramTypeCompatible --addr 0x0204D9B4 --cc 1.1p1 --arm
 */
u32 CLACT_IsVramTypeCompatible(u32 mode, u32 bank_idx)
{
    if (mode == 2 || bank_idx == 2) {
        return 1;
    }
    return mode == bank_idx;
}

/*
 * Load an archive member, optionally decompressing it.  Both arms read the
 * member with ARC_TOOL_LoadHandleMember into a scratch block taken from the far end of
 * the caller's heap, (heapId & 0x7fff) | 0x8000, the same "allocate high"
 * form src/matched/unit_02045C44.c uses.  When the third argument is set the
 * block is treated as a compressed image: its first word carries the
 * uncompressed size in the top 24 bits, a normal-end block of that size is
 * allocated, MI_UncompressLZ8 expands into it and the scratch is released.
 *
 * The heap id is computed once above the branch, which is why the `lsl #16`
 * sits before the `beq` and only the matching `lsr #16` is duplicated into
 * each arm: the compiler hoists the common subexpression and cross-jumps what
 * is left.  Spelling the cast per arm instead moves the whole pair down twice.
 *
 * The decompressing arm is the fall-through, so the guard is written `!= 0`
 * (docs/idioms/the-fall-through-arm-is-the-source-order.md).
 *
 * MI_UncompressLZ8 takes source first and destination second here, and only two
 * arguments: r2 still holds the allocator's clobbered register at the call and
 * the original never reloads it.  Other files in the tree declare a
 * three-argument (dest, src, size) form of the same address; the declarations
 * live in different translation units and never meet, and this one is what the
 * bytes at this call site say.
 *
 * The fourth argument doubles as the heap id for both allocations, so it is
 * held in a callee-saved register across the whole function rather than
 * recomputed.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/CLACT_LoadArchiveData.c \
 *       --func CLACT_LoadArchiveData --addr 0x0204D9D4 --cc 1.1p1 --arm
 */
void *CLACT_LoadArchiveData(void *archive, u32 file_idx, u32 compressed, u32 heapId)
{
    void *out;
    struct CompHeader *packed;

    if (compressed != 0) {
        packed = (struct CompHeader *)ARC_TOOL_LoadHandleMember(archive, file_idx,
                  (u16)((heapId & 0x7fff) | 0x8000));
        out = GFL_HEAP_Alloc(heapId, packed->header >> 8, 0, s_clact_c, 0x1ba5);
        MI_UncompressLZ8(packed, out);
        GFL_HEAP_Free(packed);
    } else {
        out = ARC_TOOL_LoadHandleMember(archive, file_idx,
                  (u16)((heapId & 0x7fff) | 0x8000));
    }
    return out;
}

/*
 * Closes one of the two clact.c fan-in-1 blockers of CLACT_InitResources
 * documented in docs/notes/clact_c_fan_in_1_blockers.c.txt (the other is
 * CLACT_AllocPaletteTable, the packet's next function).
 *
 * Allocate `count` 0x40-byte records and initialise each: set bit 31 of
 * the word at +0x3c (a one-bit bitfield, unconditional `bic`/`orr` of the
 * same immediate is the bitfield-store tell), then hand the two
 * two-word sentinel pairs at +0x2c and +0x34 to VMAN_InvalidateHandle (already
 * matched, src/matched/unit_02034630.c).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/CLACT_AllocCharacterTable.c \
 *       --func CLACT_AllocCharacterTable --addr 0x0204DA5C --cc 1.1p1 --arm
 */
void *CLACT_AllocCharacterTable(u32 heapId, u32 count)
{
    u32 i;
    struct CharSlot *slots;

    slots = GFL_HEAP_Alloc(heapId, count << 6, 0, s_clact_c, 0x1bbe);

    for (i = 0; i < count; i++) {
        struct CharSlot *slot = &slots[i];
        slot->free = 1;
        VMAN_InvalidateHandle((struct VmanHandle *)(&slot->main_block));
        VMAN_InvalidateHandle((struct VmanHandle *)(&slot->sub_block));
    }

    return slots;
}

/*
 * Upload one 0x40-byte cell's two graphics halves to VRAM. The optional
 * fourth argument supplies an override key: when it is null the key comes
 * from the sink's +0x10 field and the "overridden" flag stays clear;
 * otherwise it is the first word of the override's +0x0C block, with the
 * flag set. NNSi_G2dInitVramHandle resets the cell's three-word handle triple, then
 * each half (the +0x2C descriptor against bank +0x00 and kind 1, the +0x34
 * descriptor against bank +0x04 and kind 2) is uploaded only when
 * CLACT_IsVramTypeCompatible admits the mode pair and VMAN_Alloc finds the resource:
 * VMAN_GetOffset turns the descriptor into a byte offset, CLACT_UpdateObjMapping
 * selects the VRAM window, and one of the three upload entries is chosen by
 * the override flag and, failing that, by the sink's own +0x08 selector.
 * Finally the sink pointer is published at +0x28 (null when not overridden)
 * and the key is packed into the low 31 bits of the word at +0x3C.
 */
void CLACT_SetupCharacterVram(struct ClactRes *res, u32 idx, NNSG2dCharacterData *char_data, struct CharXferInfo *xfer_override,
                   u32 vram_mode)
{
    struct CharSlot *slot;
    u32 has_override;
    u32 vram_size;
    u32 vram_kind;
    u32 vram_offset;

    slot = &res->chars[idx];

    if (xfer_override == 0) {
        vram_size = char_data->szByte;
        has_override = 0;
    } else {
        has_override = (xfer_override->size != 0);
        if (has_override) vram_size = *xfer_override->size;
        else vram_size = 0;
        has_override = 1;
    }

    NNSi_G2dInitVramHandle((u32 *)slot);

    if (CLACT_IsVramTypeCompatible(vram_mode, 0) != 0) {
        if (VMAN_Alloc((struct VmanBank *)res->vram_main, vram_size, (struct VmanHandle *)&slot->main_block) != 0) {
            vram_offset = VMAN_GetOffset((struct VmanBank *)res->vram_main, (u32 *)&slot->main_block);
            vram_kind = 1;
            CLACT_UpdateObjMapping((NNSG2dCharacterData *)char_data, (int)vram_kind);
            if (has_override != 0) {
                NNSi_G2dSetupVramResource((struct VramResource *)char_data, vram_offset, (int)vram_kind, (struct VramHandle *)slot);
            } else if (char_data->mapingType != 0) {
                NNSi_G2dLoadVramResourceMain((struct VramResource *)char_data, vram_offset, (int)vram_kind, (struct VramHandle *)slot);
            } else {
                NNSi_G2dLoadVramResourceSub((struct VramResource *)char_data, vram_offset, (int)vram_kind, (struct VramHandle *)slot);
            }
        }
    }

    if (CLACT_IsVramTypeCompatible(vram_mode, 1) != 0) {
        if (VMAN_Alloc((struct VmanBank *)res->vram_sub, vram_size, (struct VmanHandle *)&slot->sub_block) != 0) {
            vram_offset = VMAN_GetOffset((struct VmanBank *)res->vram_sub, (u32 *)&slot->sub_block);
            vram_kind = 2;
            CLACT_UpdateObjMapping((NNSG2dCharacterData *)char_data, (int)vram_kind);
            if (has_override != 0) {
                NNSi_G2dSetupVramResource((struct VramResource *)char_data, vram_offset, (int)vram_kind, (struct VramHandle *)slot);
            } else if (char_data->mapingType != 0) {
                NNSi_G2dLoadVramResourceMain((struct VramResource *)char_data, vram_offset, (int)vram_kind, (struct VramHandle *)slot);
            } else {
                NNSi_G2dLoadVramResourceSub((struct VramResource *)char_data, vram_offset, (int)vram_kind, (struct VramHandle *)slot);
            }
        }
    }

    if (has_override == 0) char_data = 0;
    slot->xfer_src = (uptr)char_data;
    slot->vram_size = vram_size;
}

void CLACT_FreeCharacterTable(void *chars)
{
    GFL_HEAP_Free(chars);
}

void CLACT_UpdateObjMapping(NNSG2dCharacterData *char_data, int screen)
{
    u32 mapping_bits = (screen == 1) ? (*(vu32 *)REG_DISPCNT_ADDR & 0x00300010) : (*(vu32 *)REG_DB_DISPCNT_ADDR & 0x00300010);
    if (char_data->mapingType != mapping_bits) {
        char_data->mapingType = mapping_bits;
    }
}

/*
 * Closes the other of the two clact.c fan-in-1 blockers of CLACT_InitResources
 * documented in docs/notes/clact_c_fan_in_1_blockers.c.txt (the other is
 * CLACT_AllocCharacterTable, this packet's previous function).
 *
 * Allocate `count` 0x18-byte records and set bit 31 of the word at +0x14
 * of each (a one-bit bitfield; the unconditional `bic`/`orr` pair of the
 * same immediate is the bitfield-store tell, same shape as
 * CLACT_AllocCharacterTable's +0x3c field).
 *
 * The record size 0x18 is a real `mul` against a register, not a shift
 * pair, because 0x18 is not a power of two; the per-record address inside
 * the loop is then one `mla`.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/CLACT_AllocPaletteTable.c \
 *       --func CLACT_AllocPaletteTable --addr 0x0204DCA8 --cc 1.1p1 --arm
 */
void *CLACT_AllocPaletteTable(u32 heapId, u32 count)
{
    u32 i;
    struct PlttSlot *slots;

    slots = GFL_HEAP_Alloc(heapId, count * sizeof(struct PlttSlot), 0, s_clact_c, 0x1c58);

    for (i = 0; i < count; i++) {
        slots[i].free = 1;
    }

    return slots;
}

/*
 * Reconfigure one 0x18-byte entry of the holder's table: trim the surface
 * (the +0x08 byte count / +0x0c data word pair, a palette-shaped record) by
 * `head` 32-byte blocks from the front and to `tail` blocks, clamp it to the
 * layer limit, re-upload for one or both engines, then store the surviving
 * byte count into the entry's bits 0..30.  Sole caller: CLACT_RegisterPaletteEx.
 *
 * The C body is docs/notes/CLACT_TransferPaletteData.c.txt's (476 against 480 there),
 * closed in wave 10 by two levers:
 *  - THE MATERIALISED `lsl r0, r3, #5`.  The head block's offset is a named
 *    64-BIT local, `unsigned long long ofs = head * 32;`, used by the add and
 *    the sub, while the compare keeps the plain `head * 32` (which is why the
 *    image re-folds `cmp r1, r3, lsl #5` beside the live r0).  A 32-bit local
 *    of any type (u32, int, long, pointer, enum) is copy-propagated and folded
 *    into both consumers (476 bytes); a u16/s16 local materialises the value
 *    but narrows it (`lsl #21` + `lsr #16` shifter operands, 5 out).  Only
 *    the u64 local keeps the plain shift as a register temporary: its low
 *    word is what the u32 add and sub consume.  The
 *    materialising temp is `first_color * 32` as u16; the width was a
 *    hand sweep.
 *  - THE TAIL MASK ORDER.  The entry's bit-31 half is read into its own
 *    local before the OR (`u32 free_bit = slot->bits & 0x80000000;`), which is what
 *    loads +0x14 before pltt_data->size.
 */
void CLACT_TransferPaletteData(struct ClactRes *res, int idx, void *file, void *vram_mode,
                  u32 vram_offset, u16 first_color, u16 color_count)
{
    struct PaletteData *pltt_data;
    void *pltt_hdr;
    u32 slot_off;
    u8 *slots;
    int max_colors;
    int byte_limit;
    int extended;
    u32 saved_state;

    slot_off  = idx * sizeof(struct PlttSlot);
    slots = (u8 *)res->pltts;
    if (vram_offset >= 0x200) {
        vram_offset  = (u16)(vram_offset - 0x200);
        extended  = 1;
        max_colors   = 0x100;
        byte_limit = 0x2000;
    } else {
        extended  = 0;
        max_colors   = 0x10;
        byte_limit = 0x200;
    }

    NNS_G2dGetUnpackedPaletteCompressInfo(file, &pltt_hdr);
    if (!NNS_G2dGetUnpackedPaletteData(file, (void **)(&pltt_data))) {
        return;
    }
    NNSi_G2dInitVramHandleEx((u32 *)(slots + slot_off));

    if (first_color != 0) {
        unsigned long long skip_bytes = first_color * 32;
        if (pltt_data->size > first_color * 32) {
            pltt_data->raw += skip_bytes;
            pltt_data->size -= skip_bytes;
        }
    }
    if (color_count != 0) {
        if (first_color + color_count <= max_colors) {
            if (pltt_data->size > color_count * 32) {
                pltt_data->size = color_count * 32;
            }
        }
    }
    if (vram_offset != 0) {
        if (pltt_data->size + vram_offset > byte_limit) {
            pltt_data->size = byte_limit - vram_offset;
        }
    }

    if (CLACT_IsVramTypeCompatible((uptr)vram_mode, 0)) {
        saved_state = GX_GetBankForOBJExtPltt();
        if (extended) GX_SetBankForLCDC(saved_state);
        NNSi_G2dLoadVramResourceBySel((struct VramResourceSel *)pltt_data, vram_offset, 1, (struct VramHandleSel *)(slots + slot_off));
        if (extended) GX_SetBankForOBJExtPltt(saved_state);
    }
    if (CLACT_IsVramTypeCompatible((uptr)vram_mode, 1)) {
        saved_state = GX_GetBankForSubOBJExtPltt();
        if (extended) GX_SetBankForLCDC(saved_state);
        NNSi_G2dLoadVramResourceBySel((struct VramResourceSel *)pltt_data, vram_offset, 2, (struct VramHandleSel *)(slots + slot_off));
        if (extended) GX_SetBankForSubOBJExtPltt(saved_state);
    }

    ((struct PlttSlot *)((u8 *)res->pltts + slot_off))->bits &= ~0x80000000;
    {
        u32 free_bit = ((struct PlttSlot *)((u8 *)res->pltts + slot_off))->bits & 0x80000000;
        ((struct PlttSlot *)((u8 *)res->pltts + slot_off))->bits = free_bit | (pltt_data->size & ~0x80000000);
    }
}

/*
 * The one-surface sibling of CLACT_TransferPaletteData (same entry table, same 0x200
 * large-layer split, same bracketed double upload through CLACT_IsVramTypeCompatible's
 * engine select), uploading through NNSi_G2dLoadVramResourceList instead of NNSi_G2dLoadVramResourceBySel.
 * Returns nothing: the trailing read-modify-write leaves r0 as garbage.
 *
 * Levers, all measured (wave 10): the two out-locals are declared `pltt_data` then
 * `pltt_hdr` (NNS_G2dGetUnpackedPaletteData's out first), which puts `pltt_hdr` at sp+4 as the image has
 * it; and the 0x200 test is written small-arm-first
 * (`if (size < 0x200) flag = 0; else {...}`), which is what orders the
 * predicated `movlo sl,#0` before `movhs sl,#1`.  Either alone leaves 4-6
 * bytes out.  `off = idx * sizeof(struct PlttSlot)` as a byte-offset local and
 * the entry re-derived from res->pltts at the end are CLACT_TransferPaletteData's pins.
 */
void CLACT_TransferPaletteDataEx(struct ClactRes *res, int idx, void *file, void *vram_mode, u32 vram_offset)
{
    void *pltt_data;
    void *pltt_hdr;
    u32 slot_off;
    struct PlttSlot *slot;
    int extended;
    u32 saved_state;

    slot_off = idx * sizeof(struct PlttSlot);
    slot = (struct PlttSlot *)((u8 *)res->pltts + slot_off);
    if (vram_offset < 0x200) {
        extended = 0;
    } else {
        vram_offset = (u16)(vram_offset - 0x200);
        extended = 1;
    }

    NNS_G2dGetUnpackedPaletteCompressInfo(file, &pltt_hdr);
    if (!NNS_G2dGetUnpackedPaletteData(file, &pltt_data)) {
        return;
    }
    NNSi_G2dInitVramHandleEx((u32 *)slot);

    if (CLACT_IsVramTypeCompatible((uptr)vram_mode, 0)) {
        saved_state = GX_GetBankForOBJExtPltt();
        if (extended) GX_SetBankForLCDC(saved_state);
        NNSi_G2dLoadVramResourceList(pltt_data, pltt_hdr, vram_offset, 1, (struct VramHandleList *)slot);
        if (extended) GX_SetBankForOBJExtPltt(saved_state);
    }
    if (CLACT_IsVramTypeCompatible((uptr)vram_mode, 1)) {
        saved_state = GX_GetBankForSubOBJExtPltt();
        if (extended) GX_SetBankForLCDC(saved_state);
        NNSi_G2dLoadVramResourceList(pltt_data, pltt_hdr, vram_offset, 2, (struct VramHandleList *)slot);
        if (extended) GX_SetBankForSubOBJExtPltt(saved_state);
    }

    ((struct PlttSlot *)((u8 *)res->pltts + slot_off))->bits &= ~0x80000000;
}

void CLACT_FreePaletteTable(void *pltts)
{
    GFL_HEAP_Free(pltts);
}

/*
 * Allocate the 0x14-byte entry pool and mark every entry free.  The
 * allocation size is `count * sizeof(struct TransferEntry)`, and the `mvn`-free
 * `mov r2, r4` is the alignment argument sharing the zero the loop counter
 * was just materialised into, so `i` must be spelled before the call, not
 * only in the `for` header.
 *
 * The file string at 0x020A7F74 is "clact.c" and the stacked fifth argument
 * is __LINE__ = 7494; it is declared as an extern array pinned by address,
 * never as a literal __FILE__.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/CLACT_AllocCellAnimTable.c \
 *       --func CLACT_AllocCellAnimTable --addr 0x0204E01C --cc 1.1p1 --arm
 */
struct CellSlot *CLACT_AllocCellAnimTable(u32 heap_id, u32 count)
{
    struct CellSlot *slots;
    u32 i;

    i = 0;
    slots = (struct CellSlot *)GFL_HEAP_Alloc(heap_id,
                                            count * sizeof(struct CellSlot), i,
                                            s_clact_c, 7494);

    for (; i < count; i++) {
        slots[i].free = 1;
    }

    return slots;
}

/*
 * Publish the two handles of one 0x14-byte pool entry.  The entry is
 * addressed as `res->cells[idx]` (the `mla` by 0x14 is the subscript,
 * not a byte offset), each handle is registered through its own registrar,
 * and only when both succeed is the entry's +0x10 slot cleared and 1
 * returned.  Either failure leaves the entry alone and returns 0.
 *
 * The two guards must be written nested (`if (ok1) { if (ok2) { ...; return
 * 1; } } return 0;`), not as two early-`return 0` guards and not as one
 * `||`.  Only the nested form leaves the success path as the fall-through
 * of the second `cmp`, which is what lets the store, the constant and the
 * return if-convert into `movne`/`strne`/`movne`/`popne` above a single
 * shared `mov r0, #0` tail.  Two early returns give an if-converted first
 * guard and no shared tail (76 bytes); `||` emits the failure block first
 * and duplicates the return (84 bytes).  Both arguments must be read
 * into locals before the first call: the `mov r5, r3` ahead of the `bl` is
 * the fourth argument being parked in a callee-saved register, which only
 * happens when it is live across the call as a plain value.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/CLACT_LoadCellAnimBanks.c \
 *       --func CLACT_LoadCellAnimBanks --addr 0x0204E074 --cc 1.1p1 --arm
 */
s32 CLACT_LoadCellAnimBanks(struct ClactRes *res, s32 idx, void *cell_file, void *anim_file)
{
    struct CellSlot *slot = &res->cells[idx];

    if (NNS_G2dGetUnpackedCellBank(cell_file, &slot->cell_bank) != 0) {
        if (NNS_G2dGetUnpackedAnimBankEx(anim_file, &slot->anim_bank) != 0) {
            slot->free = 0;
            return 1;
        }
    }
    return 0;
}

void CLACT_FreeCellAnimTable(void *cells)
{
    GFL_HEAP_Free(cells);
}

/*
 * Resolve a handle through NNS_G2dGetUnpackedCharacterData into a stack temporary and, only
 * on success, hand it to CLACT_SetupCharacterVram together with the two stacked
 * arguments, then clear bit 31 of +0x3c in the 0x40-byte slot `idx` of the
 * table at `res->chars`.
 *
 * The temporary must be a plain local whose address is taken: the `add r1,
 * sp, #4` before the first call and the `ldr r2, [sp, #4]` after it are the
 * out-parameter, and the `ldr r3, [sp, #0x18]` is the caller's fifth
 * argument being reloaded from the incoming stack area, which fixes the
 * arity at five.  Argument four reaches CLACT_SetupCharacterVram's own stack slot and
 * argument five reaches its r3, so the two are swapped relative to this
 * function's own signature; that is the original's order, not a slip.
 *
 * The final read-modify-write must go through a named `struct CharSlot *`.
 * Written inline as `res->chars[idx].free = 0`, the compiler
 * folds the constant 0x3c into the base and leaves the scaled index in both
 * the load and the store (`[r1, r5, lsl #6]`), three instructions wrong;
 * binding the element address to a local first forces `add r1, r0, r5, lsl
 * #6` once with an immediate-offset load and store.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/CLACT_SetupCharacter.c \
 *       --func CLACT_SetupCharacter --addr 0x0204E0D0 --cc 1.1p1 --arm
 */
void CLACT_SetupCharacter(struct ClactRes *res, s32 idx, u32 handle, u32 vram_mode, u32 xfer_info)
{
    uptr char_data_addr;
    struct CharSlot *slot;

    if (NNS_G2dGetUnpackedCharacterData((struct NitroFileHeader *)handle, (void **)(&char_data_addr)) != 0) {
        CLACT_SetupCharacterVram((struct ClactRes *)res, idx, (NNSG2dCharacterData *)char_data_addr, (struct CharXferInfo *)xfer_info, vram_mode);
        slot = &res->chars[idx];
        slot->free = 0;
    }
}
