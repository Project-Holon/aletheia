#ifndef GAME_ARM9_CLACT_H
#define GAME_ARM9_CLACT_H

struct AnimCtrl;

/* Setup record of CLACT_InitSystem (0x1C bytes). */
struct ClactSysInit {
    s16 surface_pos[4];  /* 0x00 */
    u8  oam_main_base;   /* 0x08 */
    u8  oam_main_count;  /* 0x09 */
    u8  oam_sub_base;    /* 0x0a */
    u8  oam_sub_count;   /* 0x0b */
    u32 n_transfers;     /* 0x0c */
    u16 n_chars;         /* 0x10 */
    u16 n_pltts;         /* 0x12 */
    u16 n_cells;         /* 0x14 */
    u16 n_spare;         /* 0x16 */
    u16 n_main_blocks;   /* 0x18 */
    u16 n_sub_blocks;    /* 0x1a */
};

/* Initial placement of a plain actor (CLACT_CreateActor), the first 8 bytes of ActorInit. */
struct ActorInitParam {
    s16 x;             /* 0x00 */
    s16 y;             /* 0x02 */
    u16 anim_seq;      /* 0x04 */
    u8  draw_priority; /* 0x06 */
    u8  bg_priority;   /* 0x07 */
};

/* Initial placement of an affine actor (CLACT_CreateAffineActor). */
struct ActorInit {
    struct ActorInitParam param;   /* 0x00 */
    s16 origin_x;      /* 0x08 */
    s16 origin_y;      /* 0x0a */
    u32 scale_x;       /* 0x0c */
    u32 scale_y;       /* 0x10 */
    u16 rotation;      /* 0x14 */
    u16 affine_mode;   /* 0x16 */
};

/* Screen position or offset of an actor. */
struct ClactVec2 {
    s16 x;
    s16 y;
};

/* One animation command (CLACT_ApplyActorAnimCommand). */
struct ClactAnimCommand {
    u16 op;     /* 0x00 */
    u16 tag;    /* 0x02 */
    u32 param;  /* 0x04 */
    u32 func;   /* 0x08 */
};

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of clact.c, prototypes copied from their definitions. */

struct ClactSysInit;
struct DispVramCfg;
struct ImageProxy;
struct PaletteData;
struct PaletteProxy;
struct Renderer;
struct SurfaceInit;
struct ClactVec2;
struct Unit;
struct ClactActor;
struct ActorInitParam;
struct ActorInit;
struct Pt16 {
    u16 x;
    u16 y;
};
struct Pair32;
struct ClactAnimCommand;
union GXOamAttr;
struct OamManagers;
struct OamManager;
struct Surface;
#include "../sdk_fx.h"
struct CellData;
struct Affine2D;
struct ViewRect;
struct TransferPool;
struct TransferEntry;
struct ActorReq;
struct CharSlot;
struct PlttSlot;
struct CellDataBank;
struct AnimBank;
struct AnimCtl;
struct ClactRes;
struct Caps;
struct CharXferInfo;
struct CellSlot;

#include "../types.h"
#include "../arm9/nns_g2d_res_types.h"
#include "../arm9/nns_g2d_anim_types.h"

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
void CLACT_SetPaletteBaseOffsets(char *pltt_proxy, u16 base_offset, u32 pltt_op);
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
void CLACT_EntryOam(struct OamManager *oam_manager, union GXOamAttr *src_entry, u32 mode, u32 pltt_offset, u32 pltt_op);
void CLACT_EntryOamMain(union GXOamAttr *entry, u32 mode);
void CLACT_EntryOamSub(union GXOamAttr *entry, u32 mode);
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
void CLACT_TransferPaletteData(struct ClactRes *res, int idx, void *file, u32 vram_mode, u32 vram_offset, u16 first_color, u16 color_count);
void CLACT_TransferPaletteDataEx(struct ClactRes *res, int idx, void *file, u32 vram_mode, u32 vram_offset);
void CLACT_FreePaletteTable(void *pltts);
struct CellSlot *CLACT_AllocCellAnimTable(u32 heap_id, u32 count);
s32 CLACT_LoadCellAnimBanks(struct ClactRes *res, s32 idx, void *cell_file, void *anim_file);
void CLACT_FreeCellAnimTable(void *cells);
void CLACT_SetupCharacter(struct ClactRes *res, s32 idx, void *handle, u32 vram_mode, struct CharXferInfo *xfer_info);
/* END mkheaders: generated region */

#endif
