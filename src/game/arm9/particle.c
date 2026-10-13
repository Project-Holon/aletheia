/*
 * file:     particle.c
 * unit:     yes
 * function: BILLBOARD_ACT_Create, BILLBOARD_ACT_Delete, BILLBOARD_ACT_GetBoard, func_02050084, BILLBOARD_ACT_InitSlot, BILLBOARD_ACT_ResetPlayback, BILLBOARD_ACT_InitEntry, BILLBOARD_ACT_CreateSlots, BILLBOARD_ACT_AddSlot, BILLBOARD_ACT_DeleteSlots, BILLBOARD_ACT_DeleteSlot, BILLBOARD_ACT_GetSlotBoardId, BILLBOARD_ACT_CreateEntries, BILLBOARD_ACT_DeleteEntries, BILLBOARD_ACT_UpdateEntries, BILLBOARD_ACT_UpdateEntry, BILLBOARD_ACT_UploadSlotFrame, BILLBOARD_ACT_UploadSlotPalette, func_02050790, BILLBOARD_ACT_SetEntryFlags, BILLBOARD_ACT_GetEntryFlags, BILLBOARD_ACT_SetEntryEnabled, BILLBOARD_ACT_SetEntryCommands, BILLBOARD_ACT_SetEntryList, BILLBOARD_ACT_GetEntryList, BILLBOARD_ACT_SetEntryCursor, BILLBOARD_ACT_GetEntryCursor, BILLBOARD_ACT_SetEntryPaletteFromSlot, BILLBOARD_ACT_GetEntryElemId, BILLBOARD_ACT_GetEntrySlotIndex, BILLBOARD_ACT_GetEntryLastCommand, BILLBOARD_ACT_IsControlCommand, BILLBOARD_ACT_RunControlCommand, BILLBOARD_ACT_GetControlHandler, BILLBOARD_ACT_CmdEnd, BILLBOARD_ACT_CmdSetList, BILLBOARD_ACT_CmdLoop, BILLBOARD_ACT_CmdJump, func_02050A70, func_02050B14, PARTICLE_InitManager, PARTICLE_Main, PARTICLE_CreateSystemDefault, PARTICLE_CreateSystem, PARTICLE_DeleteSystem, PARTICLE_ExitManager, PARTICLE_AllocWorkSlot0, PARTICLE_AllocWorkSlot1, PARTICLE_AllocWorkSlot2, PARTICLE_AllocWorkSlot3, PARTICLE_AllocWorkSlot4, PARTICLE_AllocWorkSlot5, PARTICLE_AllocWorkSlot6, PARTICLE_AllocWorkSlot7, PARTICLE_AllocWorkSlot8, PARTICLE_AllocWorkSlot9, PARTICLE_AllocWorkSlot10, PARTICLE_AllocWorkSlot11, PARTICLE_AllocWorkSlot12, PARTICLE_AllocWorkSlot13, PARTICLE_AllocWorkSlot14, PARTICLE_AllocWorkSlot15, PARTICLE_LoadArchiveMember, PARTICLE_SetupSystem, PARTICLE_SetupSystemBorrowed, PARTICLE_SetupSystemNoHandlers, PARTICLE_ApplyLoadHandlers, PARTICLE_ApplyLoadHandlersTask, PARTICLE_DrawSystem, PARTICLE_UpdateSystem, PARTICLE_CountSystems, PARTICLE_DrawAllSystems, PARTICLE_UpdateAllSystems, PARTICLE_StartEffect, PARTICLE_StartEffectWithCallback, PARTICLE_GetEffectCount, PARTICLE_KillAllEffects, PARTICLE_KillEffect, PARTICLE_GetWorkBase, PARTICLE_InitCamera, PARTICLE_ReleaseCamera
 * address:  0x0204FE94
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
 *   func_02030734     0x02030734  arm
 *   func_0204EBD4     0x0204EBD4  arm
 *   func_02033C00     0x02033C00  arm
 *   sBillboardAct     0x020A7FB0  data
 *   gBillboardActTpl  0x020A155C  data  a4
 *   BILLBOARD_FreeElem  0x0204F5A8  arm
 *   func_0204ED24  0x0204ED24  arm
 *   AREAMAN_Delete  0x02033C9C  arm
 *   func_020307B0  0x020307B0  arm
 *   AREAMAN_Alloc  0x02033CA8  arm
 *   BILLBOARD_AddImage  0x0204EF58  arm
 *   BILLBOARD_TrimImageResource  0x0204F10C  arm
 *   BILLBOARD_DeleteImage  0x0204F150  arm
 *   func_02046EFC  0x02046EFC  arm
 *   AREAMAN_Free  0x0203422C  arm
 *   BILLBOARD_AddElem  0x0204F428  arm
 *   BILLBOARD_SetElemVisible  0x0204F720  arm
 *   BILLBOARD_SetElemCell  0x0204F66C  arm
 *   BILLBOARD_SetElemFlipS  0x0204F764  arm
 *   BILLBOARD_SetElemFlipT  0x0204F794  arm
 *   G3D_SYSTEM_GetTexDataAddr  0x020473D8  arm
 *   BILLBOARD_GetImageVramAddr  0x0204F2B4  arm
 *   BILLBOARD_CalcImageFrameRange  0x0204F344  arm
 *   G3D_SYSTEM_GetPlttDataAddr   0x020473EC  arm
 *   func_0204F2CC   0x0204F2CC  arm
 *   DWCi_LSTlErase 0x0204F7DC arm
 *   g_pDmaChannels     0x02146A84  data
 *   OS_DisableInterrupts  0x02087988  arm
 *   OS_RestoreInterrupts  0x0208799C  arm
 *   g_pParticleMan      0x02146A88  data
 *   sParticleFile     0x020A7FC0  data
 *   sDefaultCameraPos     0x020A1590  data
 *   sDefaultCameraTarget     0x020A1584  data
 *   sDefaultCameraUp     0x020A1578  data
 *   sSystemEngineIds     0x020A15A8  data
 *   func_02052DC8  0x02052DC8  arm
 *   MI_CpuFill8    0x02082BCC  arm
 *   PARTICLE_KillAllEffects  0x02051620  arm
 *   func_0206168C  0x0206168C  arm
 *   func_020621FC  0x020621FC  arm
 *   func_02061824  0x02061824  arm
 *   func_02062594  0x02062594  arm
 *   G3D_CAMERA_Delete  0x02048AC4  arm
 *   ARC_TOOL_LoadMember  0x02048F60  arm
 *   G3D_SYSTEM_GetTexManagerMode  0x02046BFC  arm
 *   G3D_SYSTEM_GetPlttManagerMode  0x02046C10  arm
 *   func_0206164C  0x0206164C  arm
 *   func_02061808  0x02061808  arm
 *   func_02052A50  0x02052A50  arm
 *   func_02030DA8  0x02030DA8  arm
 *   BUTTON_MAN_Func1A3C  0x02051A3C  arm
 *   BUTTON_MAN_AppendList0  0x02051A54  arm
 *   BUTTON_MAN_Func1AA0  0x02051AA0  arm
 *   BUTTON_MAN_AppendList1  0x02051AB8  arm
 *   func_020528A8  0x020528A8  arm
 *   func_020528BC  0x020528BC  arm
 *   func_020528D0  0x020528D0  arm
 *   func_02052984  0x02052984  arm
 *   sDefaultViewVec      0x020A159C  data
 *   g_renderState      0x02148B4C  data
 *   g_renderStateDrawParams      0x02148B98  data
 *   g_renderStateIdentityMtx      0x02148C08  data
 *   G3D_SYSTEM_GetProjection   0x020467EC  arm
 *   G3D_SYSTEM_SetProjection   0x02046858  arm
 *   G3D_SYSTEM_GetLookAt   0x02046AFC  arm
 *   G3D_SYSTEM_SetLookAt   0x02046B40  arm
 *   G3D_SYSTEM_ApplyLookAt   0x020479D8  arm
 *   func_02048AD0   0x02048AD0  arm
 *   func_020526A8   0x020526A8  arm
 *   NNS_G3dGlbBaseTrans   0x0206A9DC  arm
 *   NNS_G3dGlbBaseScale   0x0206AA0C  arm
 *   func_0206DB80   0x0206DB80  arm
 *   MI_Copy36B      0x02082B60  arm
 *   MTX_Identity33_ 0x0207ADC4  arm
 *   func_020524C8 0x020524C8 arm
 *   func_0205250C  0x0205250C  arm
 *   G3D_CAMERA_Create  0x02048A24  arm
 *   BILLBOARD_GetElemVisible  0x0204F704  arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed int     s32;

typedef struct Vec3 {
    s32 x, y, z;
} Vec3;

typedef struct Mtx33 {
    s32 m[9];
} Mtx33;

/* Saved 3D engine state (32 bytes) that DrawSystem restores after drawing. */
typedef struct SavedGxState {
    u32 w[8];
} SavedGxState;

struct AreaMan;          /* index range pool (docs/families/areaman.h) */
struct BbBoard;          /* billboard board object, opaque in this file */
struct PayloadBlock;     /* reference-counted payload of a slot, opaque */
struct ParticleCamera;   /* camera object made by G3D_CAMERA_Create, opaque */
struct TaskNode;         /* one-shot task node, opaque */
struct BbActSys;
struct BbActEntry;
struct ParticleSys;

/* ---- billboard_act ---- */

/*
 * Called by the board to move sprite data to VRAM: kind 0 is one texture
 * frame, kind 1 is the 0x20-byte palette.
 */
typedef u32 (*BbActUploadFn)(u32 kind, u32 dst, u32 src, u32 size);
typedef void (*BbActEntryHook)(struct BbActSys *sys, int entryIndex, u32 arg);

/* 28-byte board setup block: the two counts, then fixed data from rodata. */
struct BbActBoardInit {
    u16 slotCount;
    u16 entryCount;
    u32 rest[6];
};

/* One image slot: the board image id and the loaded payload behind it. */
struct BbActSlot {
    u16 boardId;             /* 0xFFFF: unused */
    u16 pad02;
    u32 payload;             /* struct PayloadBlock *, 0 when none */
};

/* Request record for BILLBOARD_ACT_CreateSlots (create slots). */
struct BbActRec {
    u32 resource;
    u8  format;
    u8  sizeS;
    u8  sizeT;
    u8  paletteId;
    u32 kind;                /* 0: board image, 1: board image plus commit, 2: external payload */
};

/* Animation command: a frame index, two flip flags and one argument. */
struct BbActCmd {
    u16 frame : 14;          /* values 0x3FFC..0x3FFF are control commands */
    u16 flipX : 1;
    u16 flipY : 1;
    u16 arg;                 /* duration in frames; control commands use it as operand */
};

enum {
    BBACT_CMD_JUMP     = 0x3FFC,   /* cursor = arg */
    BBACT_CMD_LOOP     = 0x3FFD,   /* arg high byte: repeat count, low byte: target cursor */
    BBACT_CMD_SET_LIST = 0x3FFE,   /* listIndex = arg, restart */
    BBACT_CMD_END      = 0x3FFF    /* stop advancing */
};

/* One billboard instance (0x28 bytes) with its animation playback state. */
struct BbActEntry {
    u32 elemId;                    /* 0x00: board element id, 0xFFFF: free */
    u16 slotIndex;                 /* 0x04 */
    u16 pad06;
    struct BbActCmd **cmdLists;    /* 0x08: array of command lists */
    u16 listCount;                 /* 0x0C */
    u16 listIndex;                 /* 0x0E: list being played */
    u16 cursor;                    /* 0x10: next command in the list */
    u16 waitFrames;                /* 0x12 */
    u16 loopCount;                 /* 0x14 */
    u16 pad16;
    u32 enabled;                   /* 0x18: playback runs only when nonzero */
    u16 lastCommand;               /* 0x1C: frame field of the last command read */
    u16 pad1E;
    BbActEntryHook hook;           /* 0x20: called every update when set */
    u32 hookArg;                   /* 0x24 */
};

/* Creation record for one entry (0x24 bytes). */
struct BbActDesc {
    u16 slot;                /* 0x00: slot index, relative to the base slot */
    s16 width;               /* 0x02 */
    s16 height;              /* 0x04 */
    u8  layer;               /* 0x06 */
    u8  pad07;
    u32 flags;               /* 0x08 */
    u32 color;               /* 0x0C */
    Vec3 pos;                /* 0x10 */
    BbActEntryHook hook;     /* 0x1C */
    u32 hookArg;             /* 0x20 */
};

/* The billboard_act system object (0x24 bytes). */
struct BbActSys {
    u16 heapId;                    /* 0x00 */
    u16 pad02;
    struct BbBoard *board;         /* 0x04 */
    BbActUploadFn uploadFn;        /* 0x08 */
    struct BbActSlot *slots;       /* 0x0C */
    u16 slotCount;                 /* 0x10 */
    u16 pad12;
    struct AreaMan *slotPool;      /* 0x14 */
    struct BbActEntry *entries;    /* 0x18 */
    u16 entryCount;                /* 0x1C */
    u16 pad1E;
    struct AreaMan *entryPool;     /* 0x20 */
};

typedef int (*BbActControlFn)(struct BbActEntry *entry, struct BbActCmd *cmd);

/* ---- DMA channel bank (not billboard code, see misplaced.tsv) ---- */

/* Software copy of one DMA channel (16 bytes); the bank has four. */
typedef struct DmaChannel {
    u32 srcAddr;
    u32 dstAddr;
    u32 control;                /* packed: bit 1 irq, bit 5 width, 7-8 src, 9-10 dst, 11.. count */
    u32 dirty       : 1;        /* bit 0 of +0x0C */
    u32 programmed  : 1;        /* bit 1 */
    u32 reprogram   : 1;        /* bit 2 */
    u32             : 29;
} DmaChannel;

#define REG_DMA_CNT(ch) (*(volatile u32 *)(0x040000B8 + (ch) * 12))

/* ---- DWC list wrapper (not billboard code, see misplaced.tsv) ---- */

typedef struct tagLISTCB {
    void *head;
    void *tail;
} LISTCB;

/* ---- particle ---- */

typedef u32 (*ParticleLoadFn)(u32 id, u32 arg);

/* Particle engine instance made by func_02052DC8; only the count is read here. */
struct ParticleEngine {
    u32 engineId;
    u32 effectLimit;
    int effectCount;
};

/* Projection setup for the system camera. */
struct ParticleCameraParams {
    u32 projType;
    u32 fovSin;
    u32 fovCos;
    u32 aspect;
    u32 orthoExtent;
    u32 nearZ;
    u32 farZ;
    u32 projScale;
};

#define PARTICLE_LOAD_TEX_BULK    1   /* texture handles managed as one table */
#define PARTICLE_LOAD_TEX_ENTRY   2   /* texture handles loaded one by one */
#define PARTICLE_LOAD_PAL_BULK    4
#define PARTICLE_LOAD_PAL_ENTRY   8

/* One particle system (0x260 bytes allocated, 0x25C used). */
struct ParticleSys {
    struct ParticleEngine *engine;      /* 0x00 */
    void *resourceBlock;                /* 0x04: freed on delete unless flags bit 0 */
    int activeEffect;                   /* 0x08: handle of the last effect started */
    u32 workBase;                       /* 0x0C: caller's work buffer */
    u32 workCursor;                     /* 0x10: bump allocator position */
    u32 workEnd;                        /* 0x14 */
    ParticleLoadFn texLoadFn;           /* 0x18 */
    ParticleLoadFn palLoadFn;           /* 0x1C */
    struct ParticleCamera *camera;      /* 0x20 */
    u32 cameraShiftX;                   /* 0x24 */
    u32 cameraShiftY;                   /* 0x28 */
    u32 cameraShiftZ;                   /* 0x2C */
    u16 cameraAngle;                    /* 0x30 */
    u16 flags;                          /* 0x32: bit 0: resourceBlock is not owned */
    Vec3 cameraPos;                     /* 0x34 */
    Vec3 cameraTarget;                  /* 0x40 */
    Vec3 cameraUp;                      /* 0x4C */
    u32 texHandles[0x40];               /* 0x58 */
    u32 palHandles[0x40];               /* 0x158 */
    u8  loadMode;                       /* 0x258: PARTICLE_LOAD_* */
    u8  pad259;
    u8  slotIndex;                      /* 0x25A: index in ParticleMan.systems */
    u8  projType;                       /* 0x25B */
    u16 texCount;                       /* 0x25C */
    u16 palCount;                       /* 0x25E */
};

/* The particle singleton (0x48 bytes). */
struct ParticleMan {
    struct ParticleSys *systems[16];    /* 0x00 */
    int callbackArg;                    /* 0x40: user value while an effect starts */
    struct ParticleSys *current;        /* 0x44: system whose handlers run */
};

extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 line);
extern struct BbBoard *func_0204EBD4(const struct BbActBoardInit *init, u32 heapId);
extern struct AreaMan *func_02033C00(u32 size, u32 heapId);
extern void BILLBOARD_FreeElem(struct BbBoard *board, u32 elemId);
extern void func_0204ED24(struct BbBoard *board);
extern u32 AREAMAN_Delete(struct AreaMan *pool);
extern u32 func_020307B0(void *p);
extern s32 AREAMAN_Alloc(struct AreaMan *pool, u32 count);
extern u16  BILLBOARD_AddImage(struct BbBoard *board, u32 resource, u32 format, u32 sizeS, u8 sizeT, u8 paletteId);
extern void BILLBOARD_TrimImageResource(struct BbBoard *board, u32 boardId);
extern void BILLBOARD_DeleteImage(struct BbBoard *board, int boardId);
extern void func_02046EFC(struct PayloadBlock *payload);
extern int AREAMAN_Free(struct AreaMan *pool, u32 start, s32 count);
extern s32  BILLBOARD_AddElem(struct BbBoard *board, u32 boardId, s16 width, s16 height, const Vec3 *pos, u8 layer, u32 color, u32 mode);
extern int BILLBOARD_SetElemVisible(struct BbBoard *board, u32 elemId, const u32 *flags);
extern void BILLBOARD_SetElemCell(struct BbBoard *board, u32 elemId, u16 *frame);
extern void BILLBOARD_SetElemFlipS(struct BbBoard *board, u32 elemId, u32 *flipX);
extern void BILLBOARD_SetElemFlipT(struct BbBoard *board, u32 elemId, u32 *flipY);
extern int G3D_SYSTEM_GetTexDataAddr(u32 payload);
extern void BILLBOARD_GetImageVramAddr(struct BbBoard *board, u32 boardId, u32 *texDst);
extern void BILLBOARD_CalcImageFrameRange(struct BbBoard *board, u32 boardId, int frame, u32 *offset, u32 *size, u8 flag);
extern int G3D_SYSTEM_GetPlttDataAddr(u32 payload);
extern u32 func_0204F2CC(struct BbBoard *board, u16 boardId, u32 *palDst);
extern void DWCi_LSTlErase(void *ob);
extern u32 BILLBOARD_GetElemVisible(struct BbBoard *board, u32 elemId);
extern u32  OS_DisableInterrupts(void);
extern void OS_RestoreInterrupts(u32 state);
extern struct ParticleEngine *func_02052DC8(u32 engineId, u32 effectLimit, u32 particleLimit, u32 limitA, u32 limitB, u32 maxResIndex);
extern void  MI_CpuFill8(void *dst, u32 value, u32 size);
extern void func_0206168C(u32 *table);
extern u32 func_020621FC(u32 handle);
extern void func_02061824(u32 *table);
extern int func_02062594(u32 handle);
extern u32 G3D_CAMERA_Delete(struct ParticleCamera *camera);
extern struct ParticleCamera *ARC_TOOL_LoadMember(u32 archiveId, u32 member, u32 heapId);
extern int G3D_SYSTEM_GetTexManagerMode(void);
extern int G3D_SYSTEM_GetPlttManagerMode(void);
extern void func_0206164C(u32 *table);
extern void func_02061808(u32 *table);
extern void func_02052A50(struct ParticleEngine *engine, void *block);
extern void func_02030DA8(u32 taskMgr, void (*proc)(struct TaskNode *task, struct ParticleSys *sys), struct ParticleSys *work, u32 priority);
extern u32 BUTTON_MAN_Func1A3C(u32 id, u32 arg);
extern u32 BUTTON_MAN_AppendList0(u32 id, u32 arg);
extern u32 BUTTON_MAN_Func1AA0(u32 id, u32 arg);
extern u32 BUTTON_MAN_AppendList1(u32 id, u32 arg);
extern void func_020528A8(struct ParticleEngine *engine);
extern void func_020528BC(struct ParticleEngine *engine);
extern int  func_020528D0(struct ParticleEngine *engine, ParticleLoadFn fn);
extern int  func_02052984(struct ParticleEngine *engine, ParticleLoadFn fn);
extern void func_02030EAC(struct TaskNode *task);
extern void G3D_SYSTEM_GetProjection(SavedGxState *dst);
extern void G3D_SYSTEM_SetProjection(const SavedGxState *src);
extern void G3D_SYSTEM_GetLookAt(Mtx33 *dst);
extern void G3D_SYSTEM_SetLookAt(Mtx33 *src);
extern void G3D_SYSTEM_ApplyLookAt(void);
extern void func_02048AD0(struct ParticleCamera *camera);
extern void func_020526A8(struct ParticleEngine *engine, const u32 *drawParams);
extern void NNS_G3dGlbBaseTrans(Vec3 *p);
extern void NNS_G3dGlbBaseScale(Vec3 *p);
extern void func_0206DB80(void);
extern void MI_Copy36B(const void *src, void *dst);
extern void MTX_Identity33_(Mtx33 *p);
extern int func_02052770(struct ParticleEngine *engine);
extern int func_02052634(struct ParticleEngine *engine, int resId, int arg);
extern int func_020525A0(struct ParticleEngine *engine, int resId, void (*callback)(void *));
extern void func_020524C8(struct ParticleEngine *engine);
extern void func_0205250C(struct ParticleEngine *engine, void *effect);
extern struct ParticleCamera *G3D_CAMERA_Create(u32 projType, u32 fovSin, u32 fovCos, u32 aspect,
                                            u32 orthoExtent, u32 nearZ, u32 farZ, u32 projScale,
                                            Vec3 *pos, Vec3 *target, Vec3 *up, int heapId);

struct BbActSys *BILLBOARD_ACT_Create(u16 slotCount, u16 entryCount, BbActUploadFn uploadFn, int heapId);
void BILLBOARD_ACT_Delete(struct BbActSys *sys);
struct BbBoard *BILLBOARD_ACT_GetBoard(struct BbActSys *sys);
void BILLBOARD_ACT_InitSlot(struct BbActSlot *slot);
void BILLBOARD_ACT_ResetPlayback(struct BbActEntry *entry);
void BILLBOARD_ACT_InitEntry(struct BbActEntry *entry);
u16 BILLBOARD_ACT_CreateSlots(struct BbActSys *sys, const struct BbActRec *recs, u32 count);
u32 BILLBOARD_ACT_AddSlot(struct BbActSys *sys, u32 boardId, u32 payload);
void BILLBOARD_ACT_DeleteSlots(struct BbActSys *sys, u32 first, u32 count);
int BILLBOARD_ACT_DeleteSlot(struct BbActSys *sys, u32 slot);
u16 BILLBOARD_ACT_GetSlotBoardId(struct BbActSys *sys, int slotIndex);
u16 BILLBOARD_ACT_CreateEntries(struct BbActSys *sys, u16 baseSlot, const struct BbActDesc *descs, u32 count, u32 mode);
void BILLBOARD_ACT_DeleteEntries(struct BbActSys *sys, u16 first, u32 count);
void BILLBOARD_ACT_UpdateEntries(struct BbActSys *sys);
void BILLBOARD_ACT_UpdateEntry(struct BbActSys *sys, struct BbActEntry *entry);
void BILLBOARD_ACT_UploadSlotFrame(struct BbActSys *sys, struct BbActSlot *slot, u32 frame);
u32 BILLBOARD_ACT_UploadSlotPalette(struct BbActSys *sys, struct BbActSlot *slot);
void func_02050790(LISTCB *list, int unused1, int unused2);
int BILLBOARD_ACT_SetEntryFlags(struct BbActSys *sys, int entryIndex, u32 flags);
int BILLBOARD_ACT_GetEntryFlags(struct BbActSys *sys, int entryIndex);
void BILLBOARD_ACT_SetEntryEnabled(struct BbActSys *sys, int entryIndex, u32 enabled);
void BILLBOARD_ACT_SetEntryCommands(struct BbActSys *sys, int entryIndex, struct BbActCmd **cmdLists, u16 listCount);
void BILLBOARD_ACT_SetEntryList(struct BbActSys *sys, int entryIndex, u32 listIndex);
u16 BILLBOARD_ACT_GetEntryList(struct BbActSys *sys, int entryIndex);
void BILLBOARD_ACT_SetEntryCursor(struct BbActSys *sys, int entryIndex, u32 cursor);
u16 BILLBOARD_ACT_GetEntryCursor(struct BbActSys *sys, int entryIndex);
int BILLBOARD_ACT_SetEntryPaletteFromSlot(struct BbActSys *sys, int entryIndex, int srcSlot);
int BILLBOARD_ACT_GetEntryElemId(struct BbActSys *sys, int entryIndex);
u32 BILLBOARD_ACT_GetEntrySlotIndex(struct BbActSys *sys, u32 entryIndex);
u32 BILLBOARD_ACT_GetEntryLastCommand(struct BbActSys *sys, int entryIndex, u16 *lastCommand);
int BILLBOARD_ACT_IsControlCommand(struct BbActCmd *cmd);
int BILLBOARD_ACT_RunControlCommand(struct BbActEntry *entry, struct BbActCmd *cmd);
BbActControlFn BILLBOARD_ACT_GetControlHandler(u32 id);
int BILLBOARD_ACT_CmdEnd(struct BbActEntry *entry, struct BbActCmd *cmd);
int BILLBOARD_ACT_CmdSetList(struct BbActEntry *entry, struct BbActCmd *cmd);
int BILLBOARD_ACT_CmdLoop(struct BbActEntry *entry, struct BbActCmd *cmd);
int BILLBOARD_ACT_CmdJump(struct BbActEntry *entry, struct BbActCmd *cmd);
void func_02050A70(void);
void func_02050B14(u32 channel);
void PARTICLE_InitManager(u32 heapId);
void PARTICLE_Main(void);
struct ParticleSys *PARTICLE_CreateSystemDefault(u32 workBuf, u32 workSize, u32 withCamera, u32 heapId);
struct ParticleSys *PARTICLE_CreateSystem(u32 workBuf, u32 workSize, u32 withCamera, u32 limitA, u32 limitB, u32 maxResIndex, u32 heapId);
void PARTICLE_DeleteSystem(struct ParticleSys *sys);
void PARTICLE_ExitManager(void);
void *PARTICLE_AllocWorkSlot0(u32 size);
void *PARTICLE_AllocWorkSlot1(u32 size);
void *PARTICLE_AllocWorkSlot2(u32 size);
void *PARTICLE_AllocWorkSlot3(u32 size);
void *PARTICLE_AllocWorkSlot4(u32 size);
void *PARTICLE_AllocWorkSlot5(u32 size);
void *PARTICLE_AllocWorkSlot6(u32 size);
void *PARTICLE_AllocWorkSlot7(u32 size);
void *PARTICLE_AllocWorkSlot8(u32 size);
void *PARTICLE_AllocWorkSlot9(u32 size);
void *PARTICLE_AllocWorkSlot10(u32 size);
void *PARTICLE_AllocWorkSlot11(u32 size);
void *PARTICLE_AllocWorkSlot12(u32 size);
void *PARTICLE_AllocWorkSlot13(u32 size);
void *PARTICLE_AllocWorkSlot14(u32 size);
void *PARTICLE_AllocWorkSlot15(u32 size);
void *PARTICLE_LoadArchiveMember(u32 archiveId, u32 member, u32 heapId);
void PARTICLE_SetupSystem(struct ParticleSys *sys, void *block, u32 applyNow, u32 taskMgr);
void PARTICLE_SetupSystemBorrowed(struct ParticleSys *sys, void *block, u32 applyNow, u32 taskMgr);
void PARTICLE_SetupSystemNoHandlers(struct ParticleSys *sys, void *block);
void PARTICLE_ApplyLoadHandlers(struct ParticleSys *sys);
void PARTICLE_ApplyLoadHandlersTask(struct TaskNode *task, struct ParticleSys *sys);
void PARTICLE_DrawSystem(struct ParticleSys *sys);
int PARTICLE_UpdateSystem(struct ParticleSys *sys);
int PARTICLE_CountSystems(void);
int PARTICLE_DrawAllSystems(void);
int PARTICLE_UpdateAllSystems(void);
int PARTICLE_StartEffect(struct ParticleSys *sys, int resId, int arg);
int PARTICLE_StartEffectWithCallback(struct ParticleSys *sys, int resId, void (*callback)(void *), int userArg);
int PARTICLE_GetEffectCount(struct ParticleSys *sys);
void PARTICLE_KillAllEffects(struct ParticleSys *sys);
void PARTICLE_KillEffect(struct ParticleSys *sys, void *effect);
void *PARTICLE_GetWorkBase(struct ParticleSys *sys);
void PARTICLE_InitCamera(struct ParticleSys *sys, struct ParticleCameraParams *params, u16 angle,
                   Vec3 *pos, Vec3 *target, Vec3 *up, u32 heapId);
int PARTICLE_ReleaseCamera(struct ParticleSys *sys);
extern const char sBillboardAct[];
extern const struct BbActBoardInit gBillboardActTpl;
extern DmaChannel *g_pDmaChannels;
extern struct ParticleMan *g_pParticleMan;
extern const char sParticleFile[];
extern Vec3 sDefaultCameraPos;
extern Vec3 sDefaultCameraTarget;
extern Vec3 sDefaultCameraUp;
extern const u32 sSystemEngineIds[];
extern Vec3 sDefaultViewVec;
extern u32      g_renderState[];
extern u32      g_renderStateDrawParams[];
extern u32      g_renderStateIdentityMtx[];



/*
 * The billboard_act.c system constructor, and the function that NAMES the
 * family: its __FILE__ word at 0x0204FFF4 is 0x020A7FB0, and
 * layout/file_anchors.txt fixes the string there as "billboard_act.c" (the NUL
 * of "billboard.c" at 0x020A7FAF is what pins its start).  Three allocations,
 * at source lines 94, 119 and 123, monotone in address -- the second,
 * independent check that this is one original translation unit.
 *
 * Allocate the 0x24-byte system object, stamp in the caller's heap id, the
 * two counts and the upload callback, build the sub-board by copying a 28-byte
 * template out of rodata onto the stack and overwriting its first two
 * halfwords with the two counts, then allocate the two parallel arrays (the
 * slotCount * 8 slot array and the entryCount * 0x28 entry array) with their two
 * index pools, and finally run the per-element initialisers over both.
 *
 * Three shapes are load-bearing:
 *
 *   - The 28-byte template is ONE aggregate assignment from a rodata object
 *     into a `struct BbActBoardInit` LOCAL, which mwcc expands to a 16-byte ldm/stm
 *     pair with write-back plus a 12-byte pair without, reusing the bases the
 *     write-back left in sl and sb (the same expansion as the sibling
 *     constructor func_0204EBD4, src/matched/func_0204EBD4.c).  A byte array
 *     or a memcpy compiles to a copy loop instead.
 *   - The two counts are patched into the first two fields of the local,
 *     re-reading sys->slotCount and sys->entryCount rather than reusing the
 *     incoming parameters: the image issues `ldrh r2, [r6, #0x10]` and
 *     `ldrh r2, [r6, #0x1c]` between the stm and the call, which the
 *     parameters would not produce.
 *   - Both element loops use SEPARATE counters (`i` and `j`) and re-read
 *     their bound from the object at the bottom of the loop; the compare is
 *     signed (`blt`) on the promoted u16, so the counters are plain `int`.
 *
 * The template at 0x020A155C is attested `sole-ref` (its only referrer image
 * wide is this function's own pool word at 0x0204FFF8); the file string is
 * attested `string`.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/BILLBOARD_ACT_Create.c \
 *       --func BILLBOARD_ACT_Create --addr 0x0204FE94 --cc 1.1p1 --arm
 *   EXACT, 360 bytes, 10 relocation sites, all resolved.
 */
struct BbActSys *BILLBOARD_ACT_Create(u16 slotCount, u16 entryCount, BbActUploadFn uploadFn, int heapId)
{
    const char *file = sBillboardAct;
    struct BbActSys *sys;
    struct BbActBoardInit init;
    int i;
    int j;

    sys = func_02030734(heapId, 0x24, 1, file, 94);
    sys->heapId = (u16)heapId;
    sys->uploadFn = uploadFn;
    sys->slotCount = slotCount;
    sys->entryCount = entryCount;

    init = gBillboardActTpl;
    init.slotCount = sys->slotCount;
    init.entryCount = sys->entryCount;
    sys->board = func_0204EBD4(&init, heapId);

    sys->slots = func_02030734(heapId, sys->slotCount * 8, 1, file, 119);
    sys->slotPool = func_02033C00(sys->slotCount, heapId);
    sys->entries = func_02030734(heapId, sys->entryCount * 0x28, 1, file, 123);
    sys->entryPool = func_02033C00(sys->entryCount, heapId);

    for (i = 0; i < sys->slotCount; i++) {
        BILLBOARD_ACT_InitSlot(&sys->slots[i]);
    }
    for (j = 0; j < sys->entryCount; j++) {
        BILLBOARD_ACT_InitEntry(&sys->entries[j]);
    }
    return sys;
}






/*
 * billboard_act.c teardown.  The two-byte residue of the earlier notes
 * (the loaded entry word landing in r0 instead of r1) was the callee's
 * arity: BILLBOARD_FreeElem takes TWO arguments, and the second is the entry's
 * first word, which the image loads straight into r1 for the compare and
 * then passes on.  EXACT* because the unlabelled 8-byte getter at
 * 0x02050080 (`ldr r0,[r0,#4]; bx lr`, blx'd from ov021) follows the pool.
 */
void BILLBOARD_ACT_Delete(struct BbActSys *sys)
{
    int i;

    for (i = 0; i < sys->entryCount; i++) {
        if (sys->entries[i].elemId != 0xFFFF) {
            BILLBOARD_FreeElem(sys->board, sys->entries[i].elemId);
        }
    }
    AREAMAN_Delete(sys->entryPool);
    func_020307B0(sys->entries);
    AREAMAN_Delete(sys->slotPool);
    func_020307B0(sys->slots);
    func_0204ED24(sys->board);
    func_020307B0(sys);
}





/*
 * func_02050084 (`bx lr`) is the return instruction of this getter: the layout has a function entry
 * there, but the bytes are the ones this function emits, so it has no separate definition.
 */
struct BbBoard *BILLBOARD_ACT_GetBoard(struct BbActSys *sys)
{
    return sys->board;
}















void BILLBOARD_ACT_InitSlot(struct BbActSlot *slot)
{
    slot->boardId = 0xFFFF;
    slot->payload = 0;
}









void BILLBOARD_ACT_ResetPlayback(struct BbActEntry *entry)
{
    entry->cursor = 0;
    entry->waitFrames = 0;
    entry->loopCount = 0;
    entry->lastCommand = 0;
}









/*
 * Second of the three 0x0204F6xx-series object initialisers; the eight bytes
 * of literal pool at 0x020500EC (0x0000FFFF) are this function's own.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/BILLBOARD_ACT_InitEntry.c \
 *       --func BILLBOARD_ACT_InitEntry --addr 0x020500B8 --cc 1.1p1 --arm
 */
void BILLBOARD_ACT_InitEntry(struct BbActEntry *entry)
{
    entry->elemId = 0xFFFF;
    entry->cmdLists = 0;
    entry->listCount = 0;
    entry->listIndex = 0;
    BILLBOARD_ACT_ResetPlayback(entry);
    entry->enabled = 0;
    entry->hook = 0;
    entry->hookArg = 0;
}









/*
 * billboard_act.c: take n slot indices from the pool at +0x14 and fill one
 * slot record per request (0: board slot, 1: board slot plus BILLBOARD_TrimImageResource,
 * 2: an external payload word with the 0xFFFF sentinel id).  The 28-byte
 * scheduling wall of the earlier notes was the missing `const` on the
 * request array (its byte loads then batch ahead of the outgoing-argument
 * stores, and case 2's payload load hoists above the sentinel store); with
 * it the plain subscript sys->slots[base + i] and literal zeros are exact.
 */
u16 BILLBOARD_ACT_CreateSlots(struct BbActSys *sys, const struct BbActRec *recs, u32 count)
{
    int base;
    u32 i;

    base = AREAMAN_Alloc(sys->slotPool, count);
    for (i = 0; i < count; i++) {
        const struct BbActRec *rec = &recs[i];
        u16 id;
        switch (rec->kind) {
        case 0:
            sys->slots[base + i].boardId = BILLBOARD_AddImage(sys->board, rec->resource, rec->format, rec->sizeS, rec->sizeT, rec->paletteId);
            sys->slots[base + i].payload = 0;
            break;
        case 1:
            id = BILLBOARD_AddImage(sys->board, rec->resource, rec->format, rec->sizeS, rec->sizeT, rec->paletteId);
            BILLBOARD_TrimImageResource(sys->board, id);
            sys->slots[base + i].boardId = id;
            sys->slots[base + i].payload = 0;
            break;
        case 2:
            sys->slots[base + i].boardId = 0xFFFF;
            sys->slots[base + i].payload = rec->resource;
            break;
        }
    }
    return base;
}








/*
 * Appends one {u16, u32} record (8 bytes, id in the low half) to the array
 * the caller's object keeps at +12, at the slot AREAMAN_Alloc hands back for
 * the pool at +20; the return is the slot narrowed to u16.
 *
 * The four bytes that cost three attempts are the first store's register
 * pairing: the pointer form `*(u16 *)(*(u32 *)((char *)p + 12) + idx * 8)`
 * compiles the same two instructions as the original but allocates them the
 * other way round (`ldr r1,[r6,#12]; lsl r2,r0,#3; strh r5,[r1,r2]` against
 * the original's r2/r1), a whole-function DIFF at +001C.  Written as an
 * array subscript on an 8-byte struct element,
 * `((struct S8 *)*(u32 *)((char *)p + 12))[idx].h`, it comes out EXACT.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/BILLBOARD_ACT_AddSlot.c \
 *       --func BILLBOARD_ACT_AddSlot --addr 0x02050238 --cc 1.1p1 --arm
 *   EXACT, 64 bytes, 1 relocation site, resolved [label].
 */
u32 BILLBOARD_ACT_AddSlot(struct BbActSys *sys, u32 boardId, u32 payload)
{
    int index = AREAMAN_Alloc(sys->slotPool, 1);

    sys->slots[index].boardId = boardId;
    sys->slots[index].payload = payload;
    return (u16)index;
}








/*
 * billboard_act.c: release `count` slot records from `first`: the board
 * record through BILLBOARD_DeleteImage(board, id) when the id is live, the payload
 * through func_02046EFC when nonzero, then reset the record and return the
 * index range to the pool.  BILLBOARD_DeleteImage takes TWO arguments (the loaded
 * id is the r1 the image compares); the rest is plain subscripts.
 */
void BILLBOARD_ACT_DeleteSlots(struct BbActSys *sys, u32 first, u32 count)
{
    u32 i;

    for (i = 0; i < count; i++) {
        if (sys->slots[first + i].boardId != 0xFFFF) {
            BILLBOARD_DeleteImage(sys->board, sys->slots[first + i].boardId);
        }
        if (sys->slots[first + i].payload != 0) {
            func_02046EFC((struct PayloadBlock *)sys->slots[first + i].payload);
        }
        BILLBOARD_ACT_InitSlot(&sys->slots[first + i]);
    }
    AREAMAN_Free(sys->slotPool, first, count);
}






int BILLBOARD_ACT_DeleteSlot(struct BbActSys *sys, u32 slot)
{
    BILLBOARD_ACT_InitSlot(&sys->slots[slot]);
    return AREAMAN_Free(sys->slotPool, slot, 1);
}







u16 BILLBOARD_ACT_GetSlotBoardId(struct BbActSys *sys, int slotIndex)
{
    return sys->slots[slotIndex].boardId;
}






/*
 * billboard_act.c: take `count` consecutive entry indices from the pool at
 * +0x20 and build one board element per 0x24-byte descriptor through
 * BILLBOARD_AddElem, returning the first index (0xFFFF when the pool is full).
 * Levers, all measured: the descriptor array is `const` (its field loads
 * then move above the entry stores, 62 -> 15 bytes); the element id is a
 * named local passed on to BILLBOARD_SetElemVisible rather than re-read; the caller's
 * view of BILLBOARD_AddElem takes s16 v12/v14 (ldrsh, no narrowing); all five
 * locals at function scope in the order p, e, idx, i, r (loop-scoped e/p
 * swap the i and p registers).
 */
u16 BILLBOARD_ACT_CreateEntries(struct BbActSys *sys, u16 baseSlot, const struct BbActDesc *descs, u32 count, u32 mode)
{
    const struct BbActDesc *desc;
    struct BbActEntry *entry;
    int first;
    u32 i;
    s32 elemId;

    first = AREAMAN_Alloc(sys->entryPool, count);
    if (first == -1) {
        return 0xFFFF;
    }
    for (i = 0; i < count; i++) {
        entry = &sys->entries[first + i];
        desc = &descs[i];

        BILLBOARD_ACT_InitEntry(entry);
        entry->slotIndex = baseSlot + desc->slot;
        elemId = BILLBOARD_AddElem(sys->board, sys->slots[entry->slotIndex].boardId, desc->width, desc->height, &desc->pos, desc->layer, desc->color, mode);
        entry->elemId = elemId;
        entry->hook = desc->hook;
        entry->hookArg = desc->hookArg;
        BILLBOARD_SetElemVisible(sys->board, elemId, &desc->flags);
        entry->lastCommand = 0x3FFF;
    }
    return first;
}






/*
 * billboard_act.c: release `count` entries from `first` and give the index
 * range back to the pool.  The earlier 2-byte floor (add operand order) and
 * the hand-copied stride came from writing the address arithmetic by hand;
 * the source is plain subscripts, sys->entries[first + i], in a for loop.
 */
void BILLBOARD_ACT_DeleteEntries(struct BbActSys *sys, u16 first, u32 count)
{
    u32 i;

    for (i = 0; i < count; i++) {
        BILLBOARD_FreeElem(sys->board, sys->entries[first + i].elemId);
        BILLBOARD_ACT_InitEntry(&sys->entries[first + i]);
    }
    AREAMAN_Free(sys->entryPool, first, count);
}






/*
 * Tick every live entry of sys->entries (0x28 bytes each): for each index
 * below the live count sys->entryCount, skip the entry whose first word is the
 * sentinel 0xFFFF, otherwise call its per-entry hook (a function pointer at
 * +0x20, taking the owner, the index and the entry's +0x24 word) when one is
 * installed, then hand the entry to BILLBOARD_ACT_UpdateEntry.
 *
 * Two shapes are load-bearing:
 *
 *   - The live count is re-read from sys->entryCount at the BOTTOM of the loop
 *     (`ldrh r0, [r5, #0x1c]` at +0x60) as well as at the top, because the
 *     hook and BILLBOARD_ACT_UpdateEntry may both change it.  Caching it in a local gives
 *     one load and a different loop shape.
 *   - The count is a u16 but the comparison is SIGNED (`blt`, and `pople` on
 *     the entry guard), so the index is a plain `int` and the count is
 *     promoted, not an unsigned compare.
 *
 * The 0xFFFF sentinel lives in the pool at 0x0205054C rather than as an
 * immediate, which is why r7 is loaded once before the loop.
 *
 * UNBLOCKED 2026-09-21: BILLBOARD_ACT_UpdateEntry was filed EXACT
 * (src/matched/BILLBOARD_ACT_UpdateEntry.c, shard arm9/pkt_02050340.json), so the single
 * relocation site, the `bl` at +0x5C, is now attested `matched` and this file
 * verifies EXACT unchanged.  No C was altered to promote it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/BILLBOARD_ACT_UpdateEntries.c \
 *       --func BILLBOARD_ACT_UpdateEntries --addr 0x020504D8 --cc 1.1p1 --arm
 *
 * Addresses are Black-image addresses.
 */
void BILLBOARD_ACT_UpdateEntries(struct BbActSys *sys)
{
    int i = 0;
    int n = sys->entryCount;

    if (n <= 0) {
        return;
    }
    do {
            struct BbActEntry *entry = &sys->entries[i];

            if (entry->elemId != 0xFFFF) {
                if (entry->hook != 0) {
                    entry->hook(sys, i, entry->hookArg);
                }
                BILLBOARD_ACT_UpdateEntry(sys, entry);
            }
        i++;
    } while (i < sys->entryCount);
}






void BILLBOARD_ACT_UpdateEntry(struct BbActSys *sys, struct BbActEntry *entry)
{
    struct BbActCmd *cmd;
    u32  flipXValue;
    u32  flipYValue;
    u16  frame;
    u16  duration;
    struct BbActSlot *slot;

    if (entry->cmdLists == 0 || entry->enabled == 0) {
        return;
    }
    if (entry->waitFrames != 0) {
        entry->waitFrames = entry->waitFrames - 1;
        return;
    }

    cmd = &entry->cmdLists[entry->listIndex][entry->cursor];
    while (BILLBOARD_ACT_IsControlCommand(cmd)) {
        if (BILLBOARD_ACT_RunControlCommand(entry, cmd)) {
            return;
        }
        cmd = &entry->cmdLists[entry->listIndex][entry->cursor];
    }

    entry->cursor = entry->cursor + 1;
    frame = cmd->frame;
    duration = cmd->arg;

    slot = (struct BbActSlot *)((u8 *)(entry->slotIndex * 8) + (u32)sys->slots);
    if (slot->payload != 0) {
        BILLBOARD_ACT_UploadSlotFrame(sys, slot, frame);
    } else {
        BILLBOARD_SetElemCell(sys->board, entry->elemId, &frame);
    }

    if (cmd->flipX) {
        flipXValue = 1;
    } else {
        flipXValue = 0;
    }
    if (cmd->flipY) {
        flipYValue = 1;
    } else {
        flipYValue = 0;
    }

    BILLBOARD_SetElemFlipS(sys->board, entry->elemId, &flipXValue);
    BILLBOARD_SetElemFlipT(sys->board, entry->elemId, &flipYValue);

    if (duration != 0) {
        duration = duration - 1;
    }
    entry->waitFrames = duration;
}






void BILLBOARD_ACT_UploadSlotFrame(struct BbActSys *sys, struct BbActSlot *slot, u32 frame)
{
    u32 texDst;
    u32 frameOffset;
    u32 frameSize;
    u32 payloadBase;
    u32 zero;

    payloadBase = G3D_SYSTEM_GetTexDataAddr(slot->payload);
    BILLBOARD_GetImageVramAddr(sys->board, slot->boardId, &texDst);
    zero = 0;
    BILLBOARD_CalcImageFrameRange(sys->board, slot->boardId, frame, &frameOffset, &frameSize, zero);
    if (sys->uploadFn != 0) {
        sys->uploadFn(zero, texDst, payloadBase + frameOffset, frameSize);
    }
}






/*
 * An 88-byte ARM function in the 0x02050000 block.  It reads a record index
 * out of the object at +4, resolves it through G3D_SYSTEM_GetPlttDataAddr, then calls
 * func_0204F2CC with the object's word at +4, the halfword at q[0] and a
 * stack scratch slot; when the hook pointer at p+8 is non-null it calls the
 * hook with the scratch value and the resolved record.  The null case returns
 * the func_0204F2CC result, which is why the `cmp ip, #0` sits after the
 * second call with r0 still live.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/BILLBOARD_ACT_UploadSlotPalette.c \
 *       --func BILLBOARD_ACT_UploadSlotPalette --addr 0x02050738 --cc 1.1p1 --arm
 */
u32 BILLBOARD_ACT_UploadSlotPalette(struct BbActSys *sys, struct BbActSlot *slot)
{
    u32 paletteSrc = G3D_SYSTEM_GetPlttDataAddr(slot->payload);
    u32 paletteDst;
    u32 result = func_0204F2CC(sys->board, slot->boardId, &paletteDst);
    BbActUploadFn uploadFn = sys->uploadFn;

    if (uploadFn == 0)
        return result;
    return uploadFn(1, paletteDst, paletteSrc, 0x20);
}






/*
 * sdk:      DWCi_LSTlPopFront (libdwcutil.TWL.HYB.a list.o)
 */
void func_02050790(LISTCB *list, int unused1, int unused2)
{
    DWCi_LSTlErase(list->tail);
}






/*
 * The listing labels this function at 0x020507A4, not 0x020507A0: disasm.py
 * only auto-labels a prologue that saves lr, so the four bytes at 0x020507A0
 * that home the four argument registers (`push {r0,r1,r2,r3}`, the tell for
 * an address-taken register parameter,
 * docs/idioms/address-of-a-register-parameter-is-a-push-of-all-four.md) are
 * printed as a stray `.word` and the label lands on the `push {r3, lr}` four
 * bytes later.  The real entry is 0x020507A0 and the function is 48 bytes,
 * not the worklist's 44; verified from 0x020507A0, where the extent runs to
 * the next label at 0x020507D0.
 *
 * The third parameter is not a pointer but a scalar whose address is taken
 * (`&x`, compiled as the home slot).  Written as `u8 *buf` it compiles to 32
 * bytes; as `u8 buf[16]`, 32; only `&x` on a scalar reproduces the home push.
 *
 * Reads element `idx` of a 40-byte record array hanging off p+24 and hands it,
 * together with p's own word at +4 and the caller's buffer address, to
 * BILLBOARD_SetElemVisible.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/BILLBOARD_ACT_SetEntryFlags.c \
 *       --func BILLBOARD_ACT_SetEntryFlags --addr 0x020507A0 --cc 1.1p1 --arm
 */
int BILLBOARD_ACT_SetEntryFlags(struct BbActSys *sys, int entryIndex, u32 flags)
{
    return BILLBOARD_SetElemVisible(sys->board,
                         sys->entries[entryIndex].elemId,
                         &flags);
}






/*
 * Leaf witness for ov021 0x021BBF10 / 0x021BC138 (lane wA1-12).
 */
int BILLBOARD_ACT_GetEntryFlags(struct BbActSys *sys, int entryIndex)
{
    return BILLBOARD_GetElemVisible(sys->board, sys->entries[entryIndex].elemId);
}






void BILLBOARD_ACT_SetEntryEnabled(struct BbActSys *sys, int entryIndex, u32 enabled)
{
    struct BbActEntry *entry = &sys->entries[entryIndex];
    entry->enabled = enabled;
}






/*
 * Verified with:
 *   python tools/match.py one --src src/matched/BILLBOARD_ACT_SetEntryCommands.c \
 *       --func BILLBOARD_ACT_SetEntryCommands --addr 0x02050804 --cc 1.1p1 --arm
 */
void BILLBOARD_ACT_SetEntryCommands(struct BbActSys *sys, int entryIndex, struct BbActCmd **cmdLists, u16 listCount)
{
    struct BbActEntry *entry = &sys->entries[entryIndex];

    entry->cmdLists = cmdLists;
    entry->listCount = listCount;
    entry->listIndex = 0;
    BILLBOARD_ACT_ResetPlayback(entry);
}






void BILLBOARD_ACT_SetEntryList(struct BbActSys *sys, int entryIndex, u32 listIndex)
{
    struct BbActEntry *entry = &sys->entries[entryIndex];
    entry->listIndex = listIndex;
    BILLBOARD_ACT_ResetPlayback(entry);
}






/*
 * Leaf witness for ov021 0x0219F058 and siblings (lane wA1-06).
 */
u16 BILLBOARD_ACT_GetEntryList(struct BbActSys *sys, int entryIndex)
{
    return sys->entries[entryIndex].listIndex;
}






/*
 * Verified with:
 *   python tools/match.py one --src src/matched/BILLBOARD_ACT_SetEntryCursor.c \
 *       --func BILLBOARD_ACT_SetEntryCursor --addr 0x0205085C --cc 1.1p1 --arm
 */
void BILLBOARD_ACT_SetEntryCursor(struct BbActSys *sys, int entryIndex, u32 cursor)
{
    struct BbActEntry *entry = &sys->entries[entryIndex];

    BILLBOARD_ACT_ResetPlayback(entry);
    entry->cursor = cursor;
}






u16 BILLBOARD_ACT_GetEntryCursor(struct BbActSys *sys, int entryIndex)
{
    return sys->entries[entryIndex].cursor;
}






/*
 * PROMOTED from src/pending/BILLBOARD_ACT_SetEntryPaletteFromSlot.c: it was parked at MATCH because
 * the only branch in the image to 0x02050738 is the one inside this function.
 * 0x02050738 (88 bytes, pkt_02050340) is now matched, so the site resolves by
 * the `matched` class with no change to the C.  The file's packet id is
 * corrected from pkt_02050340 to pkt_02050894, which is the packet the
 * worklist gives 0x02050894.
 *
 * Moves one word between two parallel record arrays of the object: the index
 * is read out of the 40-byte record table at p+24, the value out of the
 * 8-byte-pair array at p+12, the value is stored back into the record the
 * index names, and the record is handed to BILLBOARD_ACT_UploadSlotPalette.
 *
 * The listing's extent runs 140 bytes because the follower at 0x020508C4 is an
 * unlabelled leaf accessor (no prologue that saves lr).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/BILLBOARD_ACT_SetEntryPaletteFromSlot.c \
 *       --func BILLBOARD_ACT_SetEntryPaletteFromSlot --addr 0x02050894 --cc 1.1p1 --arm
 */
int BILLBOARD_ACT_SetEntryPaletteFromSlot(struct BbActSys *sys, int entryIndex, int srcSlot)
{
    struct BbActSlot *slots = sys->slots;
    struct BbActEntry *entries = sys->entries;
    u16 dstSlot = entries[entryIndex].slotIndex;
    u32 payload = slots[srcSlot].payload;

    slots[dstSlot].payload = payload;
    return BILLBOARD_ACT_UploadSlotPalette(sys, &slots[dstSlot]);
}






int BILLBOARD_ACT_GetEntryElemId(struct BbActSys *sys, int entryIndex)
{
    return sys->entries[entryIndex].elemId;
}






u32 BILLBOARD_ACT_GetEntrySlotIndex(struct BbActSys *sys, u32 entryIndex)
{
    return sys->entries[entryIndex].slotIndex;
}






u32 BILLBOARD_ACT_GetEntryLastCommand(struct BbActSys *sys, int entryIndex, u16 *lastCommand)
{
    u16 value = sys->entries[entryIndex].lastCommand;
    *lastCommand = value;
    /* true for BBACT_CMD_JUMP..BBACT_CMD_END; the range test must stay in this form */
    return (u16)(value + 4 + 0xC000) <= 3;
}






/*
 * Verified with:
 *   python tools/match.py one --src src/matched/BILLBOARD_ACT_IsControlCommand.c \
 *       --func BILLBOARD_ACT_IsControlCommand --addr 0x02050920 --cc 1.1p1 --arm
 */
int BILLBOARD_ACT_IsControlCommand(struct BbActCmd *cmd)
{
    return BILLBOARD_ACT_GetControlHandler(cmd->frame) != 0;
}






/*
 * Verified with:
 *   python tools/match.py one --src src/matched/BILLBOARD_ACT_RunControlCommand.c \
 *       --func BILLBOARD_ACT_RunControlCommand --addr 0x02050944 --cc 1.1p1 --arm
 */
int BILLBOARD_ACT_RunControlCommand(struct BbActEntry *entry, struct BbActCmd *cmd)
{
    BbActControlFn handler;

    handler = BILLBOARD_ACT_GetControlHandler(cmd->frame);
    entry->lastCommand = cmd->frame;
    return handler(entry, cmd);
}






/*
 * PROMOTED from src/pending/BILLBOARD_ACT_GetControlHandler.c 2026-09-21 (wave 4, billboard_act).
 * The C is UNCHANGED: it was parked at MATCH* because three of its four ABS32
 * pool words -- 0x020509E0, 0x02050A00 and 0x02050A58 -- each had exactly one
 * mention image wide, the pool word inside this very function, so neither
 * `label` nor `literal` reached them.  All three handlers are now filed EXACT
 * (src/matched/BILLBOARD_ACT_CmdEnd.c, BILLBOARD_ACT_CmdLoop.c, BILLBOARD_ACT_CmdJump.c, shard
 * arm9/pkt_02050984.json), so every site resolves by the `matched` class and
 * this file verifies EXACT* with no edit to the body.
 *
 * EXACT*, not EXACT: the listing's extent runs 100 bytes because the follower
 * at 0x020509E0 is reached only through this function's own pool word and has
 * no prologue that saves lr, so disasm.py does not label it.  Report
 * 0x020509E0 as a seed for layout/function_starts.txt; it is never a byte
 * difference.
 *
 * The switch normalises the id with two subtracts and no `mov` of the base,
 * which is the whole reason the case labels read 0x3FFC..0x3FFF: the image
 * subtracts 0x3FC and then 0x3C00, i.e. 0x3FFC, and spelling the cases
 * 0x43FC..0x43FF makes the second subtract `#0x4000` and the four case arms
 * come out in the wrong order.  Writing the cases in DESCENDING source order
 * is what reproduces the image's arm order (case 0x3FFF's arm nearest the
 * table); ascending order puts case 0x3FFC's arm there and differs in four
 * branch instructions.
 *
 * `return <function address>;` is the shape: each arm is `ldr r0, [pc, #n];
 * bx lr` and the fall-through is `mov r0, #0; bx lr`.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/BILLBOARD_ACT_GetControlHandler.c \
 *       --func BILLBOARD_ACT_GetControlHandler --addr 0x02050984 --cc 1.1p1 --arm
 */
BbActControlFn BILLBOARD_ACT_GetControlHandler(u32 id)
{
    switch (id) {
    case BBACT_CMD_END:      return BILLBOARD_ACT_CmdEnd;
    case BBACT_CMD_SET_LIST: return BILLBOARD_ACT_CmdSetList;
    case BBACT_CMD_LOOP:     return BILLBOARD_ACT_CmdLoop;
    case BBACT_CMD_JUMP:     return BILLBOARD_ACT_CmdJump;
    }
    return 0;
}





/*
 * The second arm of the four-entry handler table BILLBOARD_ACT_GetControlHandler dispatches
 * through (its pool word at 0x020509D0).  Eight bytes, a leaf that returns the
 * nonzero constant the dispatch caller tests, and one of the pool words that
 * keeps src/pending/BILLBOARD_ACT_GetControlHandler.c wildcarded until it has an EXACT entry.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/BILLBOARD_ACT_CmdEnd.c \
 *       --func BILLBOARD_ACT_CmdEnd --addr 0x020509E0 --cc 1.1p1 --arm
 */
int BILLBOARD_ACT_CmdEnd(struct BbActEntry *entry, struct BbActCmd *cmd)
{
    return 1;
}






/*
 * Verified with:
 *   python tools/match.py one --src src/matched/BILLBOARD_ACT_CmdSetList.c \
 *       --func BILLBOARD_ACT_CmdSetList --addr 0x020509E8 --cc 1.1p1 --arm
 */
int BILLBOARD_ACT_CmdSetList(struct BbActEntry *entry, struct BbActCmd *cmd)
{
    entry->listIndex = cmd->arg;
    BILLBOARD_ACT_ResetPlayback(entry);
    return 0;
}






/*
 * The third arm of the handler table BILLBOARD_ACT_GetControlHandler dispatches through (see
 * src/pending/BILLBOARD_ACT_GetControlHandler.c).  88 bytes, a leaf: the command halfword at
 * cmd->arg packs two bytes, a repeat count in the high half and a value in the
 * low half.  While the entry's repeat counter at +0x14 is below the count,
 * store the value at +0x10 and bump the counter; once it reaches the count,
 * reset the counter and advance +0x10 by one instead.  +0x12 is zeroed on
 * both paths.  Returns 0 (the "command consumed, keep going" verdict the
 * dispatcher in BILLBOARD_ACT_RunControlCommand tests).
 *
 * The comparison is SIGNED (`bge`), so both sides are promoted `int`s and the
 * counter is compared as an int, not as an unsigned halfword.
 *
 * Two shapes are load-bearing, both worth 8 bytes each:
 *
 *   - The high byte must land in a `u8` LOCAL, not be written inline in the
 *     comparison.  `if (n < ((v & 0xff00) >> 8 & 0xff))` lets mwcc fold the
 *     shift into the compare's shifter operand (`cmp r2, r1, asr #8`) and drop
 *     the redundant `and #0xff` entirely, losing the original's separate
 *     `asr r1,r1,#8` / `and r1,r1,#0xff` pair (80 bytes, 56 out).
 *   - The LOW byte must be extracted into its own local BEFORE the `if`, not
 *     spelled `v & 0xff` at its single use inside the taken arm.  The original
 *     issues `and r3, r3, #0xff` above the `bge`; written at the use it lands
 *     after it, which is the last 8 bytes (88 bytes, 8 out).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/BILLBOARD_ACT_CmdLoop.c \
 *       --func BILLBOARD_ACT_CmdLoop --addr 0x02050A00 --cc 1.1p1 --arm
 */
int BILLBOARD_ACT_CmdLoop(struct BbActEntry *entry, struct BbActCmd *cmd)
{
    int operand = cmd->arg;
    int count = entry->loopCount;
    unsigned char repeats = (unsigned char)((operand & 0xff00) >> 8);
    unsigned char target = (unsigned char)operand;

    if (count < repeats) {
        entry->cursor = target;
        entry->waitFrames = 0;
        entry->loopCount = (u16)(count + 1);
    } else {
        int cursor = entry->cursor;
        entry->loopCount = 0;
        entry->waitFrames = 0;
        entry->cursor = (u16)(cursor + 1);
    }
    return 0;
}





/*
 * The fourth arm of the handler table BILLBOARD_ACT_GetControlHandler dispatches through (its
 * pool word at 0x02050980-ish; see src/pending/BILLBOARD_ACT_GetControlHandler.c).  Twenty
 * bytes, a leaf: it loads the command's second halfword (`cmd->arg`), zeroes the
 * entry's +0x12 counter, stores the halfword at +0x10 and returns 0.
 *
 * The zero is materialised once and reused for both the +0x12 store and the
 * return (`mov r1,#0 ... mov r0,r1`), which is what a single `0` constant
 * shared between the store and the `return 0;` produces.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/BILLBOARD_ACT_CmdJump.c \
 *       --func BILLBOARD_ACT_CmdJump --addr 0x02050A58 --cc 1.1p1 --arm
 */
int BILLBOARD_ACT_CmdJump(struct BbActEntry *entry, struct BbActCmd *cmd)
{
    u16 target = cmd->arg;

    entry->waitFrames = 0;
    entry->cursor = target;
    return 0;
}





/*
 *           02050A70..02050B14 - BOTH unresolved sites are the `bl` to it,
 *           and this function holds the only two branches to 0x02050B14 in
 *           the whole image, so `label` has nothing to point at and no cut
 *           frees it.  It closes only when 0x02050B14 itself has a shard
 *           entry, and that body is the one-register allocator residue
 *           written up in docs/notes/pkt_02050A70.c.txt (44 differing bytes,
 *           no source reaches it).  Chain row.
 *
 *           All 164 concrete bytes reproduce, including the third site
 *           (g_pDmaChannels, literal x5).  The counter is `int`, not `u32`: the
 *           loop's back edge is `blt`.
 *
 * Sweep the four 16-byte slots of the global bank at 0x02146A84 and retire
 * the ones whose state bits say so: a slot whose bit 0 of +0x0C is set has it
 * cleared, and if it is still busy (bits 11.. of +0x08) its teardown routine
 * runs and the "torn down" bit (bit 1) is set; a slot whose bit 2 is set has
 * it cleared and the teardown routine runs.  The bank pointer is re-read
 * after every store (`ldr r0, [r5]`), which is what the repeated reads say:
 * the store can alias the global itself.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/func_02050A70.c \
 *       --func func_02050A70 --addr 0x02050A70 --cc 1.1p1 --arm
 */
void func_02050A70(void)
{
    int i;

    if (g_pDmaChannels == 0)
        return;

    for (i = 0; i < 4; i++) {
        if (g_pDmaChannels[i].dirty) {
            g_pDmaChannels[i].dirty = 0;
            if (g_pDmaChannels[i].control >> 11) {
                func_02050B14(i);
                g_pDmaChannels[i].programmed = 1;
            }
        }
        if (g_pDmaChannels[i].reprogram) {
            g_pDmaChannels[i].reprogram = 0;
            func_02050B14(i);
        }
    }
}





/*
 * CLOSES the two-wave wall written up at the top of docs/notes/pkt_02050A70.c.txt
 * (44 differing bytes, diagnosed there as a one-register allocator shift with
 * "no source shape that reaches it").  The diagnosis was wrong: the residue was
 * a WRONG RECORD STRIDE, not an allocation tie.  The note's reconstruction read
 * the field as `g_pDmaChannels[idx].unk_08` over 16-byte records but spelled the
 * index arithmetic so that the compiler emitted a multiply; the image emits
 * `add r1, r3, r4, lsl #4` -- a shift, because 16 is a power of two -- and
 * `mul r2, r4, r1` ONLY for the SECOND, independent 12-byte stride of the I/O
 * register address (0x040000B8 + idx * 12).  Declaring the record struct as
 * four plain u32 words (16 bytes) and subscripting it normally gives the shift,
 * and every register then falls out identical: the whole 44-byte residue was
 * downstream of that one address computation.
 *
 * Read the 3D engine's per-engine configuration word out of the slot bank and
 * repack it into the display register at 0x040000B8 + idx*12: dest bit 30 from
 * source bit 1, dest bit 26 from source bit 5, dest 23:24 from source 7:8,
 * dest 21:22 from source 9:10 and dest 0:20 from source 11:31, under an
 * interrupt-disabled critical section.
 *
 * The OR-chain ORDER is load-bearing and is the note's one surviving finding:
 * the bit-30 term is written FIRST and the bit-26 term SECOND, because the
 * compiler fully materialises the second operand of a commutative chain
 * (docs/idioms/the-accumulator-of-a-commutative-chain-is-its-second-operand.md)
 * and the image materialises the bit-26 term (`lsl #0x1a; lsr #0x1f; lsl #0x1a`)
 * while folding the other three placements into the ORs' shifter operands.
 * Written in descending destination order the four extracts come out mirrored.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02050B14.c \
 *       --func func_02050B14 --addr 0x02050B14 --cc 1.1p1 --arm
 *   EXACT, 108 bytes, 3 relocation sites, all resolved.
 */
void func_02050B14(u32 channel)
{
    u32 state = OS_DisableInterrupts();
    u32 v = g_pDmaChannels[channel].control;

    REG_DMA_CNT(channel) =
        ((v << 30) >> 31) << 30 |
        ((v << 26) >> 31) << 26 |
        ((v << 23) >> 30) << 23 |
        ((v << 21) >> 30) << 21 |
        (v >> 11);

    OS_RestoreInterrupts(state);
}






/*
 * Allocate the 0x48-byte singleton on the caller's heap and publish it at
 * 0x02146A88, zero its first sixteen words, then clear the two trailing word
 * fields at +0x40 and +0x44.
 *
 * The heap id is the incoming r0, untouched: the allocator's first argument is
 * the parameter, and its third (the clear flag, 0) is CSE'd off the loop
 * counter's own zero, which is why no `mov r0` appears and r4 is zeroed before
 * the call.
 *
 * The global is a pointer VARIABLE, and both the zero loop and the two field
 * stores re-dereference it: a store through the pointer could overwrite the
 * pointer itself, so only `systems[i] = 0` inside the loop and `callbackArg`/`current`
 * afterwards reproduce the four separate loads of the global.
 */
void PARTICLE_InitManager(u32 heapId)
{
    int i = 0;

    g_pParticleMan = func_02030734(heapId, 0x48, i, sParticleFile, 190);

    for (i = 0; i < 16; i++) {
        g_pParticleMan->systems[i] = 0;
    }

    g_pParticleMan->callbackArg = 0;
    g_pParticleMan->current = 0;
}






/*
 * Verified with:
 *   python tools/match.py one --src src/matched/PARTICLE_Main.c \
 *       --func PARTICLE_Main --addr 0x02050BE8 --cc 1.1p1 --arm
 */
void PARTICLE_Main(void)
{
    if (PARTICLE_CountSystems() == 0)
        return;
    PARTICLE_DrawAllSystems();
    PARTICLE_UpdateAllSystems();
}





/*
 * Verified with:
 *   python tools/match.py one --src src/matched/PARTICLE_CreateSystemDefault.c \
 *       --func PARTICLE_CreateSystemDefault --addr 0x02050C04 --cc 1.1p1 --arm
 */
struct ParticleSys *PARTICLE_CreateSystemDefault(u32 workBuf, u32 workSize, u32 withCamera, u32 heapId)
{
    return PARTICLE_CreateSystem(workBuf, workSize, withCamera, 5, 6, 63, heapId);
}





/*
 * particle.c, the emitter constructor (wave 13): find a free slot among the
 * sixteen in the 0x02146A88 table, allocate a 0x260-byte emitter (particle.c
 * line 285), clear it, copy the three default vectors in as struct
 * assignments, clear flag bit 0, wire the work-buffer span fields from (workBuf, workSize), publish
 * the emitter in its slot, optionally build the 3D block (a2 == 1), and store
 * func_02052DC8's handle at +0.
 *
 * WHAT CLOSED IT (docs/notes/pkt_02050C30.c.txt: size-exact at 392 with 37
 * bytes out inside the final argument setup, permuter exhausted): the
 * per-slot table 0x020A15A8 is CONST, `extern const u32 sSystemEngineIds[];`.
 * Without const the element load may not move above the two argument stores
 * to the outgoing area (they could alias it), so the compiler schedules the
 * truncations and stores first; const lets it issue the table base load
 * first and the element load in the middle, as the image does.  The same
 * mechanism as docs/idioms/const-pointer-lets-a-field-load-survive-a-store.md,
 * applied to a global array.  The note's argument order (a3, a4, a5 each
 * truncated with a (u16) cast at the use) and its three other decisions all
 * stand.
 */
struct ParticleSys *PARTICLE_CreateSystem(u32 workBuf, u32 workSize, u32 withCamera, u32 limitA, u32 limitB, u32 maxResIndex, u32 heapId)
{
    struct ParticleSys *sys;
    struct ParticleSys **table;
    int i = 0;

    table = g_pParticleMan->systems;
    do {
        if (table[i] == 0)
            break;
        i++;
    } while (i < 16);
    if (i >= 16)
        return 0;

    sys = func_02030734((u16)heapId, 0x260, 0, sParticleFile, 285);
    MI_CpuFill8(sys, 0, 0x260);
    sys->cameraPos = sDefaultCameraPos;
    sys->cameraTarget = sDefaultCameraTarget;
    sys->cameraUp = sDefaultCameraUp;
    sys->flags = sys->flags & ~1u;
    MI_CpuFill8((void *)workBuf, 0, workSize);
    sys->workBase = workBuf;
    sys->workCursor = workBuf;
    sys->workEnd = workBuf + workSize;
    sys->slotIndex = (u8)i;
    g_pParticleMan->systems[i] = sys;

    if (withCamera == 1)
        PARTICLE_InitCamera(sys, 0, 0x2000, 0, 0, 0, heapId);

    sys->engine = func_02052DC8(sSystemEngineIds[i], 0x18, 0xc8, (u16)limitA, (u16)limitB, (u16)maxResIndex);
    return sys;
}





/*
 * Emitter teardown: release the two 0x40-entry resource tables (either as a
 * whole through func_0206168C / func_02061824, or entry by entry through
 * func_020621FC / func_02062594 depending on the flag byte at +0x258), drop
 * the block at +4 unless the +0x32 bit-0 bitfield says otherwise, unpublish
 * the emitter from the singleton's sixteen-slot table, release the 3D block
 * at +0x20 and free the record.
 *
 * CLOSES both residues of docs/notes/PARTICLE_DeleteSystem.c.txt.
 *
 * 1. The note's HARD BLOCKER is gone without filing anything: 0x0206168C
 *    (and 0x02061824) had no branch outside this range, but both are traced
 *    `func_` labels, so the sole-ref/code sub-kind added 2026-09-21 attests
 *    them.  All nine sites resolve, none wildcarded.
 *
 * 2. The note's 20-byte register swap in the sixteen-entry search loop is
 *    closed by writing that loop WITHOUT a cursor local: `g_pParticleMan->systems[j]`
 *    drawn fresh at both the read and the store, not `a = g_pParticleMan; a[j]`.
 *    Found with tools/permuter.py (hill, budget 500, mutation `expand(a x2)`).
 *    The note ruled out declaration order, a separate index, hoisting the
 *    counter and the pointer-walk form, but never tried expanding the cursor
 *    away; with the cursor gone the array pointer lands in r2 and the index
 *    in r1, which is the image's assignment.  The note's other finding for
 *    this loop still holds and is still needed: the element goes into a named
 *    local `t` before the compare, or the compare comes out `cmp r5, r0`.
 *
 * Two more spelling tells found on the way to size-exact, neither in the note:
 *   * the two 0x40-entry loops read texHandles[i] / palHandles[i] and store
 *     the zero through the same subscript; the typed array form recomputes the
 *     address at each use, as the image does (the raw-offset spelling needed
 *     two different spellings of one address to avoid a CSE).
 *   * the +0x32 guard is `((u32)(f << 31) >> 31) == 0`: the cast to u32 is
 *     what makes the second shift `lsrs` rather than `asrs` (the u16 field
 *     promotes to int, and a plain `>> 31` on an int is arithmetic).  A
 *     `& 1` mask folds to a single `tst` and is four bytes short, per the
 *     note.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/PARTICLE_DeleteSystem.c \
 *       --func PARTICLE_DeleteSystem --addr 0x02050DB8 --cc 1.1p1 --arm
 *   EXACT, 284 bytes, 9 relocation sites, all resolved.
 */
void PARTICLE_DeleteSystem(struct ParticleSys *sys)
{
    int i;
    u32 z = 0;

    PARTICLE_KillAllEffects(sys);

    if (sys->loadMode & PARTICLE_LOAD_TEX_BULK) {
        func_0206168C(sys->texHandles);
    } else if (sys->loadMode & PARTICLE_LOAD_TEX_ENTRY) {
        for (i = 0; i < 0x40; i++) {
            if (sys->texHandles[i] != 0) {
                func_020621FC(sys->texHandles[i]);
                sys->texHandles[i] = z;
            }
        }
    }

    if (sys->loadMode & PARTICLE_LOAD_PAL_BULK) {
        func_02061824(sys->palHandles);
    } else if (sys->loadMode & PARTICLE_LOAD_PAL_ENTRY) {
        for (i = 0; i < 0x40; i++) {
            if (sys->palHandles[i] != 0) {
                func_02062594(sys->palHandles[i]);
                sys->palHandles[i] = z;
            }
        }
    }

    {
        void *block = sys->resourceBlock;
        sys->loadMode = (u8)z;
        sys->activeEffect = z;
        if (block != 0) {
            if (((u32)(sys->flags << 31) >> 31) == 0) {
                func_020307B0(block);
                sys->resourceBlock = (void *)z;
            }
        }
    }

    {
        int j = 0;
        for (;;) {
            struct ParticleSys *t = g_pParticleMan->systems[j];
            if (t == sys) {
                g_pParticleMan->systems[j] = (struct ParticleSys *)z;
                break;
            }
            j++;
            if (j >= 0x10)
                break;
        }
    }

    if (sys->camera != 0)
        G3D_CAMERA_Delete(sys->camera);

    func_020307B0(sys);
}





/*
 * Teardown of a sixteen-entry table of pointers: every non-null entry is
 * released through PARTICLE_DeleteSystem, then the table pointer itself is handed to
 * func_020307B0 and cleared.  The global is re-read from its own slot before
 * every use, which is what the loop's `ldr r0, [r4]` at the top is; the two
 * pool words are the same address, so both `ldr r4, [pc, ...]` load one word.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/PARTICLE_ExitManager.c \
 *       --func PARTICLE_ExitManager --addr 0x02050ED4 --cc 1.1p1 --arm
 */
void PARTICLE_ExitManager(void)
{
    int i;

    for (i = 0; i < 16; i++) {
        struct ParticleSys *sys = g_pParticleMan->systems[i];

        if (sys != 0)
            PARTICLE_DeleteSystem(sys);
    }
    func_020307B0(g_pParticleMan);
    g_pParticleMan = 0;
}



void *PARTICLE_AllocWorkSlot0(u32 size)
{
    struct ParticleSys *sys = g_pParticleMan->systems[0];
    u32 next = sys->workCursor + size;
    u32 start = sys->workCursor;
    if (next & 3) {
        next += 4 - (next & 3);
    }
    sys->workCursor = next;
    return (void *)start;
}



void *PARTICLE_AllocWorkSlot1(u32 size)
{
    struct ParticleSys *sys = g_pParticleMan->systems[1];
    u32 next = sys->workCursor + size;
    u32 start = sys->workCursor;
    if (next & 3) {
        next += 4 - (next & 3);
    }
    sys->workCursor = next;
    return (void *)start;
}



void *PARTICLE_AllocWorkSlot2(u32 size)
{
    struct ParticleSys *sys = g_pParticleMan->systems[2];
    u32 next = sys->workCursor + size;
    u32 start = sys->workCursor;
    if (next & 3) {
        next += 4 - (next & 3);
    }
    sys->workCursor = next;
    return (void *)start;
}



void *PARTICLE_AllocWorkSlot3(u32 size)
{
    struct ParticleSys *sys = g_pParticleMan->systems[3];
    u32 next = sys->workCursor + size;
    u32 start = sys->workCursor;
    if (next & 3) {
        next += 4 - (next & 3);
    }
    sys->workCursor = next;
    return (void *)start;
}



void *PARTICLE_AllocWorkSlot4(u32 size)
{
    struct ParticleSys *sys = g_pParticleMan->systems[4];
    u32 next = sys->workCursor + size;
    u32 start = sys->workCursor;
    if (next & 3) {
        next += 4 - (next & 3);
    }
    sys->workCursor = next;
    return (void *)start;
}



void *PARTICLE_AllocWorkSlot5(u32 size)
{
    struct ParticleSys *sys = g_pParticleMan->systems[5];
    u32 next = sys->workCursor + size;
    u32 start = sys->workCursor;
    if (next & 3) {
        next += 4 - (next & 3);
    }
    sys->workCursor = next;
    return (void *)start;
}



void *PARTICLE_AllocWorkSlot6(u32 size)
{
    struct ParticleSys *sys = g_pParticleMan->systems[6];
    u32 next = sys->workCursor + size;
    u32 start = sys->workCursor;
    if (next & 3) {
        next += 4 - (next & 3);
    }
    sys->workCursor = next;
    return (void *)start;
}



void *PARTICLE_AllocWorkSlot7(u32 size)
{
    struct ParticleSys *sys = g_pParticleMan->systems[7];
    u32 next = sys->workCursor + size;
    u32 start = sys->workCursor;
    if (next & 3) {
        next += 4 - (next & 3);
    }
    sys->workCursor = next;
    return (void *)start;
}



void *PARTICLE_AllocWorkSlot8(u32 size)
{
    struct ParticleSys *sys = g_pParticleMan->systems[8];
    u32 next = sys->workCursor + size;
    u32 start = sys->workCursor;
    if (next & 3) {
        next += 4 - (next & 3);
    }
    sys->workCursor = next;
    return (void *)start;
}



void *PARTICLE_AllocWorkSlot9(u32 size)
{
    struct ParticleSys *sys = g_pParticleMan->systems[9];
    u32 next = sys->workCursor + size;
    u32 start = sys->workCursor;
    if (next & 3) {
        next += 4 - (next & 3);
    }
    sys->workCursor = next;
    return (void *)start;
}



void *PARTICLE_AllocWorkSlot10(u32 size)
{
    struct ParticleSys *sys = g_pParticleMan->systems[10];
    u32 next = sys->workCursor + size;
    u32 start = sys->workCursor;
    if (next & 3) {
        next += 4 - (next & 3);
    }
    sys->workCursor = next;
    return (void *)start;
}



void *PARTICLE_AllocWorkSlot11(u32 size)
{
    struct ParticleSys *sys = g_pParticleMan->systems[11];
    u32 next = sys->workCursor + size;
    u32 start = sys->workCursor;
    if (next & 3) {
        next += 4 - (next & 3);
    }
    sys->workCursor = next;
    return (void *)start;
}



void *PARTICLE_AllocWorkSlot12(u32 size)
{
    struct ParticleSys *sys = g_pParticleMan->systems[12];
    u32 next = sys->workCursor + size;
    u32 start = sys->workCursor;
    if (next & 3) {
        next += 4 - (next & 3);
    }
    sys->workCursor = next;
    return (void *)start;
}



void *PARTICLE_AllocWorkSlot13(u32 size)
{
    struct ParticleSys *sys = g_pParticleMan->systems[13];
    u32 next = sys->workCursor + size;
    u32 start = sys->workCursor;
    if (next & 3) {
        next += 4 - (next & 3);
    }
    sys->workCursor = next;
    return (void *)start;
}



void *PARTICLE_AllocWorkSlot14(u32 size)
{
    struct ParticleSys *sys = g_pParticleMan->systems[14];
    u32 next = sys->workCursor + size;
    u32 start = sys->workCursor;
    if (next & 3) {
        next += 4 - (next & 3);
    }
    sys->workCursor = next;
    return (void *)start;
}



void *PARTICLE_AllocWorkSlot15(u32 size)
{
    struct ParticleSys *sys = g_pParticleMan->systems[15];
    u32 next = sys->workCursor + size;
    u32 start = sys->workCursor;
    if (next & 3) {
        next += 4 - (next & 3);
    }
    sys->workCursor = next;
    return (void *)start;
}






/*
 * Truncating forwarding wrapper: zero-extend the third argument to u16 and
 * tail-call ARC_TOOL_LoadMember.  The ARM9 listing emits it as a .word run (no
 * func_ label), so a `matched` entry is the only witness its callers can
 * use.
 */
void *PARTICLE_LoadArchiveMember(u32 archiveId, u32 member, u32 heapId)
{
    return ARC_TOOL_LoadMember(archiveId, member, (unsigned short)heapId);
}






/*
 * note:     re-verified 2026-09-20: MATCH; see verify output
 */
void PARTICLE_SetupSystem(struct ParticleSys *sys, void *block, u32 applyNow, u32 taskMgr)
{
    u32 mode;
    u32 palMode;
    u32 z;
    s32 i;
    struct ParticleEngine *engine;

    z = 0;
    mode = (G3D_SYSTEM_GetTexManagerMode() == 1) ? 1 : 2;
    palMode = G3D_SYSTEM_GetPlttManagerMode();
    if (palMode == 1)
        palMode = 4;
    else
        palMode = 8;
    mode |= palMode;
    sys->loadMode = (u8)mode;
    if (mode & PARTICLE_LOAD_TEX_BULK) {
        func_0206164C(sys->texHandles);
        sys->texLoadFn = BUTTON_MAN_Func1A3C;
    } else if (mode & PARTICLE_LOAD_TEX_ENTRY) {
        for (i = 0; i < 0x40; i++)
            sys->texHandles[i] = z;
        sys->texLoadFn = BUTTON_MAN_AppendList0;
        sys->texCount = z;
    }
    if (mode & PARTICLE_LOAD_PAL_BULK) {
        func_02061808(sys->palHandles);
        sys->palLoadFn = BUTTON_MAN_Func1AA0;
    } else if (mode & PARTICLE_LOAD_PAL_ENTRY) {
        for (i = 0; i < 0x40; i++)
            sys->palHandles[i] = z;
        sys->palLoadFn = BUTTON_MAN_AppendList1;
        sys->palCount = z;
    }
    engine = sys->engine;
    sys->resourceBlock = block;
    func_02052A50(engine, block);
    if (applyNow == 1) {
        PARTICLE_ApplyLoadHandlers(sys);
        return;
    }
    if (taskMgr == 0)
        return;
    func_02030DA8(taskMgr, PARTICLE_ApplyLoadHandlersTask, sys, 0);
}





/*
 * Verified with:
 *   python tools/match.py one --src src/matched/PARTICLE_SetupSystemBorrowed.c \
 *       --func PARTICLE_SetupSystemBorrowed --addr 0x02051360 --cc 1.1p1 --arm
 */
void PARTICLE_SetupSystemBorrowed(struct ParticleSys *sys, void *block, u32 applyNow, u32 taskMgr)
{
    PARTICLE_SetupSystem(sys, block, applyNow, taskMgr);
    sys->flags = (u16)((sys->flags & ~1) | 1);
}







/*
 * Tail call with two zero arguments. Filed as the witness for ov094 func_021FA12C.
 */
void PARTICLE_SetupSystemNoHandlers(struct ParticleSys *sys, void *block)
{
    PARTICLE_SetupSystem(sys, block, 0, 0);
}








/*
 * Publishes the emitter into the singleton's current-emitter slot (+0x44 of
 * the 0x02146A88 pointee, i.e. word index 0x11), routes each of the emitter's
 * two handler words at +0x18 and +0x1C to one of two handlers on null, then
 * clears the slot again.
 *
 * CLOSES the wall recorded in docs/notes/pkt_02051394.c.txt, which was not a
 * codegen residue at all: the note's two unresolved sites 0x020528A8 and
 * 0x020528BC are now EXACT entries of shard pkt_020526A8, so both attest
 * through `sole-ref/code` and the file needed only its remaining 10-byte
 * codegen gap closed.
 *
 * That gap was statement form.  The condition field and the call's argument
 * must both be read into NAMED LOCALS, and by plain ASSIGNMENT STATEMENTS
 * placed after the publish store, not by initialisers at the declarations:
 *   - inline (`if (p[6] == 0) func_020528BC(p[0]);`) the compiler folds the
 *     condition into r0 and issues `cmp` before the argument load, so the
 *     image's `ldr r1, [r4, #0x18]` / `ldr r0, [r4]` / `cmp r1, #0` triple
 *     comes out in the wrong order in BOTH blocks (10 bytes out);
 *   - as initialisers at the top of the body the two loads hoist ABOVE the
 *     `str r4, [r0, #0x44]` publish and the first block loses six more bytes
 *     (14 out).
 * Assignment statements after the store reproduce all 25 instructions.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/PARTICLE_ApplyLoadHandlers.c \
 *       --func PARTICLE_ApplyLoadHandlers --addr 0x02051394 --cc 1.1p1 --arm
 */
void PARTICLE_ApplyLoadHandlers(struct ParticleSys *sys)
{
    ParticleLoadFn fn;
    struct ParticleEngine *engine;

    g_pParticleMan->current = sys;

    fn = sys->texLoadFn;
    engine = sys->engine;
    if (fn == 0)
        func_020528BC(engine);
    else
        func_02052984(engine, fn);

    fn = sys->palLoadFn;
    engine = sys->engine;
    if (fn == 0)
        func_020528A8(engine);
    else
        func_020528D0(engine, fn);

    g_pParticleMan->current = 0;
}








/*
 * Verified with:
 *   python tools/match.py one --src src/matched/PARTICLE_ApplyLoadHandlersTask.c \
 *       --func PARTICLE_ApplyLoadHandlersTask --addr 0x020513F8 --cc 1.1p1 --arm
 */
void PARTICLE_ApplyLoadHandlersTask(struct TaskNode *task, struct ParticleSys *sys)
{
    PARTICLE_ApplyLoadHandlers(sys);
    func_02030EAC(task);
}







/*
 * particle.c, the 3D setup half of a two-phase emitter pass (wave 13).  When
 * the private block at +0x20 exists: bring up the two frame objects (0x20 and
 * 0x24 bytes), copy the model vector 0x020A159C into a local, build an
 * identity 3x3, zero a vector for NNS_G3dGlbBaseTrans, copy the 3x3 to the
 * 0x02148C08 scratch, clear bits 0xa4 of word 63 of 0x02148B4C and hand the
 * model vector to NNS_G3dGlbBaseScale; then the shared call func_020526A8 and, when
 * the block is still there, the teardown.
 *
 * WHAT CLOSED IT (docs/notes/pkt_02051414.c.txt had it at 152 bytes out,
 * 220 against 224): the three setup-only locals are declared in a NESTED
 * BLOCK with INITIALISERS -- `VecFx32 v = sDefaultViewVec; MtxFx33 m;
 * VecFx32 z = {0, 0, 0};`.  The aggregate initialiser `{0, 0, 0}` is what
 * keeps &z in a callee-saved register (r6) and stores the zero through it,
 * which costs the image's extra r7 (&v) and the push of r3/r7.  Assigning the
 * three fields, a pointer local, an inline VEC_Set, a compound literal and
 * the same locals in the if-block without initialisers all stay at 152 out.
 *
 * sDefaultViewVec resolves through sole-ref/self (its only pool word is inside
 * this function; the ROM word equals the relocation), func_020526A8 through
 * sole-ref/code.
 */
void PARTICLE_DrawSystem(struct ParticleSys *sys)
{
    SavedGxState savedState;
    Mtx33    savedMtx;

    if (sys->camera != 0) {
        G3D_SYSTEM_GetProjection(&savedState);
        G3D_SYSTEM_GetLookAt(&savedMtx);
        {
            Vec3  viewVec = sDefaultViewVec;
            Mtx33 identity;
            Vec3  zeroVec = {0, 0, 0};
            MTX_Identity33_(&identity);
            NNS_G3dGlbBaseTrans(&zeroVec);
            MI_Copy36B(&identity, g_renderStateIdentityMtx);
            g_renderState[63] = g_renderState[63] & ~0xa4u;
            NNS_G3dGlbBaseScale(&viewVec);
        }
        func_02048AD0(sys->camera);
        G3D_SYSTEM_ApplyLookAt();
        func_0206DB80();
    }
    func_020526A8(sys->engine, g_renderStateDrawParams);
    if (sys->camera == 0)
        return;
    G3D_SYSTEM_SetProjection(&savedState);
    G3D_SYSTEM_SetLookAt(&savedMtx);
    G3D_SYSTEM_ApplyLookAt();
    func_0206DB80();
}







/*
 * NOTE ON PACKET: this 16-byte leaf sits at 0x020514F4..0x02051504, in the
 * four-byte gap between packet pkt_02051230 (ends 0x020514F4) and packet
 * pkt_02051504 (starts 0x02051504) - the last instruction word of the
 * 0x02051414 dump plus a pool word.  The listing does label it
 * (`PARTICLE_UpdateSystem` at asm/arm9/src/019_0204D434.s:5680), but its only caller
 * in the whole image is the `bl` at 0x02051594 inside PARTICLE_UpdateAllSystems, which is
 * itself inside pkt_02051504's range, so the `label` class cannot attest it for
 * that caller.  Filing it here as its own entry makes it a `matched` witness
 * for PARTICLE_UpdateAllSystems instead, which is the only reason it is in this shard.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/PARTICLE_UpdateSystem.c \
 *       --func PARTICLE_UpdateSystem --addr 0x020514F4 --cc 1.1p1 --arm
 */
int PARTICLE_UpdateSystem(struct ParticleSys *sys)
{
    return func_02052770(sys->engine);
}







/*
 * Counts the non-NULL entries of the 16-slot pointer table g_pParticleMan.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/PARTICLE_CountSystems.c \
 *       --func PARTICLE_CountSystems --addr 0x02051504 --cc 1.1p1 --arm
 */
int PARTICLE_CountSystems(void)
{
    int n = 0;
    int i;

    for (i = 0; i < 16; i++) {
        if (g_pParticleMan->systems[i] != 0)
            n++;
    }
    return n;
}







/*
 * For every live slot of g_pParticleMan, calls PARTICLE_DrawSystem with the slot value;
 * returns how many slots were live (not what the callee returned).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/PARTICLE_DrawAllSystems.c \
 *       --func PARTICLE_DrawAllSystems --addr 0x02051534 --cc 1.1p1 --arm
 */
int PARTICLE_DrawAllSystems(void)
{
    int i;
    int n = 0;

    for (i = 0; i < 16; i++) {
        if (g_pParticleMan->systems[i] != 0) {
            PARTICLE_DrawSystem(g_pParticleMan->systems[i]);
            n++;
        }
    }
    return n;
}






/*
 * Same walk as PARTICLE_DrawAllSystems, but each live slot goes to PARTICLE_UpdateSystem -
 * the pair is a start/stop pass over the same 16-entry table.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/PARTICLE_UpdateAllSystems.c \
 *       --func PARTICLE_UpdateAllSystems --addr 0x02051574 --cc 1.1p1 --arm
 */
int PARTICLE_UpdateAllSystems(void)
{
    int i;
    int n = 0;

    for (i = 0; i < 16; i++) {
        if (g_pParticleMan->systems[i] != 0) {
            PARTICLE_UpdateSystem(g_pParticleMan->systems[i]);
            n++;
        }
    }
    return n;
}






/*
 * Promoted by parks lane 2: the callee 0x02052634 was filed first as an
 * EXACT entry (src/matched/func_02052634.c, shard pkt_0205250C) and this
 * file's call site now resolves through the `matched` class.  No change to
 * the C was needed.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/PARTICLE_StartEffect.c \
 *       --func PARTICLE_StartEffect --addr 0x020515B4 --cc 1.1p1 --arm
 */
int PARTICLE_StartEffect(struct ParticleSys *sys, int resId, int arg)
{
    int effect = func_02052634(sys->engine, resId, arg);
    sys->activeEffect = effect;
    return effect;
}





/*
 * Promoted by parks lane 2: the callee 0x020525A0 was filed first as an
 * EXACT entry (src/matched/func_020525A0.c, shard pkt_0205250C) and this
 * file's call site now resolves through the `matched` class.  No change to
 * the C was needed.
 *
 * EXACT: every byte is identical and the listing extent is now 72 bytes
 * (it once ran on to 0x02051620 for want of a label at 0x02051610).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/PARTICLE_StartEffectWithCallback.c \
 *       --func PARTICLE_StartEffectWithCallback --addr 0x020515CC --cc 1.1p1 --arm
 */
int PARTICLE_StartEffectWithCallback(struct ParticleSys *sys, int resId, void (*callback)(void *), int userArg)
{
    int effect;
    if (sys->engine->effectCount >= 0x18)
        return -1;
    g_pParticleMan->callbackArg = userArg;
    effect = func_020525A0(sys->engine, resId, callback);
    g_pParticleMan->callbackArg = 0;
    sys->activeEffect = effect;
    return effect;
}





/*
 * Returns word 2 of the object at *p. Filed as the witness for ov094 func_021FC744.
 */
int PARTICLE_GetEffectCount(struct ParticleSys *sys)
{
    return sys->engine->effectCount;
}





void PARTICLE_KillAllEffects(struct ParticleSys *sys)
{
    func_020524C8(sys->engine);
}






/*
 * Dereference the first argument and tail-call func_0205250C with the loaded
 * pointer.  Unlabelled ARM leaf in the ARM9 listing; matched so its overlay
 * callers get a `matched` witness.
 */
void PARTICLE_KillEffect(struct ParticleSys *sys, void *effect)
{
    func_0205250C(sys->engine, effect);
}






/*
 * Unlabelled ARM leaf in the ARM9 module. Reads the word at +0xC.
 * Filed as the witness for an ov094 caller.
 *
 * Addresses are Black-image addresses.
 */
void *PARTICLE_GetWorkBase(struct ParticleSys *sys)
{
    return (void *)sys->workBase;
}






/*
 * Constructor for the 0x25c-byte emitter record: defaults the three pointer
 * arguments, zeroes three words, stores the id halfword, stamps the 0x25b
 * byte from the source record or from zero, then hands twelve arguments to
 * G3D_CAMERA_Create and stores its return at +0x20.
 *
 * CLOSES the 268/272 near miss written up in docs/notes/PARTICLE_InitCamera.c.txt,
 * whose whole residue was one missing `mov r0, #0`: the compiler kept the
 * prologue's live zero across the branch and reused it for the null arm's
 * first two statements, where the image re-materialises it.
 *
 * The lever is STATEMENT ORDER, found by tools/permuter.py (hill, budget 300,
 * mutation `reorder(+3)`): the three zero stores are written BETWEEN the a4
 * and a5 defaults, not after all three.  Interleaving them that way puts the
 * `ldreq ip, [pc, ...]` for a5 after the three `str r0` of the prologue zero,
 * which is what kills that zero's live range before the branch and forces the
 * null arm to build its own.  Written with all three defaults first the zero
 * survives and the arm is four bytes short; that is the note's residue.  The
 * reorder is value-preserving: the defaults and the stores touch disjoint
 * objects (three parameters versus three fields of `this`).
 *
 * The note's other findings are all still load-bearing and unchanged:
 *   * `src != 0` is the FALL-THROUGH arm; the null arm is the `beq`.
 *   * the three pointer defaults are evaluated unconditionally before the
 *     branch and the compiler predicates each (`ldreq r3, [pc, ...]`).
 *   * `sys->projType = (u8)params->projType` casts the WORD field: the image is
 *     `ldr r2, [lr]` then `strb`, not `ldrb`.
 *   * a6 is truncated at the USE with `(u16)`, not declared `u16`; declared
 *     u16 the compiler emits a single `ldrh` and the file is 2 bytes short
 *     (docs/families/particle.h records this tell for the whole family).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/PARTICLE_InitCamera.c \
 *       --func PARTICLE_InitCamera --addr 0x02051648 --cc 1.1p1 --arm
 *   EXACT, 272 bytes, 5 relocation sites, all resolved (label x2, literal x3).
 */
void PARTICLE_InitCamera(struct ParticleSys *sys, struct ParticleCameraParams *params, u16 angle,
                   Vec3 *pos, Vec3 *target, Vec3 *up, u32 heapId)
{
    if (pos == 0) pos = &sDefaultCameraPos;
    if (target == 0) target = &sDefaultCameraTarget;

    sys->cameraShiftX = 0;
    sys->cameraShiftY = 0;
    sys->cameraShiftZ = 0;

    if (up == 0) up = &sDefaultCameraUp;

    sys->cameraAngle = angle;

    if (params != 0) {
        sys->projType = (u8)params->projType;
        sys->camera = G3D_CAMERA_Create(params->projType, params->fovSin, params->fovCos, params->aspect,
                                    params->orthoExtent, params->nearZ, params->farZ, params->projScale,
                                    pos, target, up, (u16)heapId);
    } else {
        sys->projType = 0;
        sys->camera = G3D_CAMERA_Create(0, 0xb50, 0xb50, 0x1555,
                                    0, 0x1000, 0x384000, 0,
                                    pos, target, up, (u16)heapId);
    }
}





int PARTICLE_ReleaseCamera(struct ParticleSys *sys)
{
    G3D_CAMERA_Delete(sys->camera);
    sys->camera = 0;
    return 0;
}
