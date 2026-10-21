/*
 * file:     particle.c
 * unit:     yes
 * function: PARTICLE_InitManager, PARTICLE_Main, PARTICLE_CreateSystemDefault, PARTICLE_CreateSystem, PARTICLE_DeleteSystem, PARTICLE_ExitManager, PARTICLE_AllocWorkSlot0, PARTICLE_AllocWorkSlot1, PARTICLE_AllocWorkSlot2, PARTICLE_AllocWorkSlot3, PARTICLE_AllocWorkSlot4, PARTICLE_AllocWorkSlot5, PARTICLE_AllocWorkSlot6, PARTICLE_AllocWorkSlot7, PARTICLE_AllocWorkSlot8, PARTICLE_AllocWorkSlot9, PARTICLE_AllocWorkSlot10, PARTICLE_AllocWorkSlot11, PARTICLE_AllocWorkSlot12, PARTICLE_AllocWorkSlot13, PARTICLE_AllocWorkSlot14, PARTICLE_AllocWorkSlot15, PARTICLE_LoadArchiveMember, PARTICLE_SetupSystem, PARTICLE_SetupSystemBorrowed, PARTICLE_SetupSystemNoHandlers, PARTICLE_ApplyLoadHandlers, PARTICLE_ApplyLoadHandlersTask, PARTICLE_DrawSystem, PARTICLE_UpdateSystem, PARTICLE_CountSystems, PARTICLE_DrawAllSystems, PARTICLE_UpdateAllSystems, PARTICLE_StartEffect, PARTICLE_StartEffectWithCallback, PARTICLE_GetEffectCount, PARTICLE_KillAllEffects, PARTICLE_KillEffect, PARTICLE_GetWorkBase, PARTICLE_InitCamera, PARTICLE_ReleaseCamera, PARTICLE_GetCallbackArg, PARTICLE_EMITTER_GetBlock, PARTICLE_EMITTER_GetPos, PARTICLE_EMITTER_SetPos, PARTICLE_EMITTER_GetRot, PARTICLE_EMITTER_GetScaleX, PARTICLE_EMITTER_SetScaleX, PARTICLE_EMITTER_GetScaleY, PARTICLE_EMITTER_SetScaleY, PARTICLE_EMITTER_GetOffsetX, PARTICLE_EMITTER_SetOffsetX, PARTICLE_EMITTER_GetOffsetY, PARTICLE_EMITTER_SetOffsetY, PARTICLE_EMITTER_GetAngle, PARTICLE_EMITTER_GetAlpha, PARTICLE_EMITTER_SetEmitPos, PARTICLE_EMITTER_SetRot, PARTICLE_EMITTER_SetAngle, PARTICLE_EMITTER_SetAlpha, PARTICLE_EMITTER_FindBehaviorData, PARTICLE_EMITTER_SetBehavior2Data, PARTICLE_EMITTER_SetBehavior3Half, PARTICLE_EMITTER_SetBehavior5Data, PARTICLE_EMITTER_SetCallback, PARTICLE_EMITTER_SetUserData, PARTICLE_EMITTER_GetUserData, PARTICLE_AllocTexVramOffset, PARTICLE_AllocTexVramTracked, PARTICLE_AllocVramOffset, PARTICLE_AllocPlttVramTracked, PARTICLE_RESOURCE_GetType, G2_GetBGCharPtrById
 * address:  0x02050B80
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Cut from particle.c by tools/splitfile.py.
 *
 * symbols:
 *   GFL_HEAP_Alloc     0x02030734  arm
 *   GFL_HEAP_Free  0x020307B0  arm
 *   g_pParticleMan      0x02146A88  data
 *   sParticleFile     0x020A7FC0  data
 *   sDefaultCameraPos     0x020A1590  data
 *   sDefaultCameraTarget     0x020A1584  data
 *   sDefaultCameraUp     0x020A1578  data
 *   sSystemEngineIds     0x020A15A8  data
 *   SPL_EMITTER_AllocNodeFromHeap  0x02052DC8  arm
 *   MI_CpuFill8    0x02082BCC  arm
 *   PARTICLE_KillAllEffects  0x02051620  arm
 *   NNS_GfdLoadVramManager  0x0206168C  arm
 *   NNS_GfdFreeTexVram  0x020621FC  arm
 *   NNSi_GfdSetVramManagerWork  0x02061824  arm
 *   NNS_GfdFreePlttVram  0x02062594  arm
 *   G3D_CAMERA_Delete  0x02048AC4  arm
 *   ARC_TOOL_LoadMember  0x02048F60  arm
 *   G3D_SYSTEM_GetTexManagerMode  0x02046BFC  arm
 *   G3D_SYSTEM_GetPlttManagerMode  0x02046C10  arm
 *   NNS_GfdSaveVramManager  0x0206164C  arm
 *   NNSi_GfdGetVramManagerWork  0x02061808  arm
 *   SPL_EMITTER_FreeNodeToHeap  0x02052A50  arm
 *   TCB_AddTask  0x02030DA8  arm
 *   PARTICLE_AllocTexVramOffset  0x02051A3C  arm
 *   PARTICLE_AllocTexVramTracked  0x02051A54  arm
 *   PARTICLE_AllocVramOffset  0x02051AA0  arm
 *   PARTICLE_AllocPlttVramTracked  0x02051AB8  arm
 *   SPL_EMITTER_AllocPlttVramDefault  0x020528A8  arm
 *   SPL_EMITTER_AllocTexVramDefault  0x020528BC  arm
 *   SPL_EMITTER_AllocPlttVramList  0x020528D0  arm
 *   SPL_EMITTER_AllocTexVramList  0x02052984  arm
 *   sDefaultViewVec      0x020A159C  data
 *   g_renderState      0x02148B4C  data
 *   g_renderStateDrawParams      0x02148B98  data
 *   g_renderStateIdentityMtx      0x02148C08  data
 *   G3D_SYSTEM_GetProjection   0x020467EC  arm
 *   G3D_SYSTEM_SetProjection   0x02046858  arm
 *   G3D_SYSTEM_GetLookAt   0x02046AFC  arm
 *   G3D_SYSTEM_SetLookAt   0x02046B40  arm
 *   G3D_SYSTEM_ApplyLookAt   0x020479D8  arm
 *   G3D_CAMERA_Reset   0x02048AD0  arm
 *   SPL_EMITTER_FreeNodeHeap   0x020526A8  arm
 *   NNS_G3dGlbBaseTrans   0x0206A9DC  arm
 *   NNS_G3dGlbBaseScale   0x0206AA0C  arm
 *   NNS_G3dGeFlushBuffer   0x0206DB80  arm
 *   MI_Copy36B      0x02082B60  arm
 *   MTX_Identity33_ 0x0207ADC4  arm
 *   SPL_EMITTER_FreeResourceList 0x020524C8 arm
 *   SPL_EMITTER_FreeResource  0x0205250C  arm
 *   G3D_CAMERA_Create  0x02048A24  arm
 *   SPL_EMITTER_AllocResourceEx  0x020525A0  arm
 *   SPL_EMITTER_AllocResource  0x02052634  arm
 *   SPL_EMITTER_FreeTexNode  0x02052770  arm
 *   d_02146A88  0x02146A88  data
 *   SPL_EMITTER_LerpVec  0x02057EF8  arm
 *   SPL_EMITTER_InterpTarget  0x02057F8C  arm
 *   SPL_EMITTER_BuildFrame  0x020580A8  arm
 *   SPL_EMITTER_AddScaledVec  0x02058180  arm
 *   SPL_EMITTER_UpdateNode  0x02058204  arm
 *   SPL_EMITTER_AddVec  0x020582CC  arm
 *   NNS_GfdDefaultFuncAllocTexVram   0x020A8140  data
 *   NNS_GfdDefaultFuncAllocPlttVram   0x020A8148  data
 *   G2_GetBG0CharPtr  0x0207E1F8  arm
 *   G2_GetBG1CharPtr  0x0207E24C  arm
 *   G2_GetBG2CharPtr  0x0207E2A0  arm
 *   G2_GetBG3CharPtr  0x0207E330  arm
 *   G2S_GetBG0CharPtr  0x0207E22C  arm
 *   G2S_GetBG1CharPtr  0x0207E280  arm
 *   G2S_GetBG2CharPtr  0x0207E2F0  arm
 *   G2S_GetBG3CharPtr  0x0207E388  arm
 *   NNSi_GfdDefaultAllocTexVram  0x020614D4  arm
 *   NNS_GfdAllocVram  0x020616CC  arm
 *   TCB_DeleteTask  0x02030EAC  arm
 */
#include "billboard_act_shared_types.h"

#include "../sdk_fx.h"

/* Saved 3D engine state (32 bytes) that DrawSystem restores after drawing. */
typedef struct SavedGxState {
    u32 w[8];
} SavedGxState;

struct ParticleCamera;   /* camera object made by G3D_CAMERA_Create, opaque */

struct TaskNode;         /* one-shot task node, opaque */

#ifdef __MWERKS__
#define SPL_EMITTER_FreeTexNode SPL_EMITTER_FreeTexNode_header
#endif
#include "spl_emitter.h"
#ifdef __MWERKS__
#undef SPL_EMITTER_FreeTexNode
extern int SPL_EMITTER_FreeTexNode(struct VramNodeHeap *engine); /* original prototype; the definition differs in pointer type, return type */
#endif
struct ParticleSys;

/* ---- particle ---- */
typedef u32 (*ParticleLoadFn)(u32 id, u32 arg);


#include "particle_types.h"
#include "particle.h"
#include "tcb_list.h"

#define PARTICLE_LOAD_TEX_BULK    1   /* texture handles managed as one table */

#define PARTICLE_LOAD_TEX_ENTRY   2   /* texture handles loaded one by one */

#define PARTICLE_LOAD_PAL_BULK    4

#define PARTICLE_LOAD_PAL_ENTRY   8

/* One particle system (0x260 bytes allocated, 0x25C used). */
struct ParticleSys {
    struct VramNodeHeap *engine;      /* 0x00 */
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

#include "gfl_heap_wrap.h"



#include "mi_memory.h"

#ifdef __MWERKS__
extern void NNS_GfdLoadVramManager(u32 *table);
#else
#include "nns_gfd_vram_manager.h"
#endif

#include "nns_gfd_lnk_vram_man.h"

#include "nns_gfd_vram_man.h"



#include "arc_tool.h"

#include "g3d_system.h"


struct Arena02146B74;

struct VramHeapHeader;
struct VramTexHeap;

#ifdef __MWERKS__
extern void SPL_EMITTER_FreeNodeToHeap(struct VramTexHeap *h, struct VramHeapHeader *d);
#else
#include "spl_emitter.h"
#endif
struct TcbSystem;
struct TcbTask;


unsigned int PARTICLE_AllocTexVramOffset(int szByte, int is4x4comp, int unused2, int unused3);

u32 PARTICLE_AllocTexVramTracked(u32 a, u32 b);

int PARTICLE_AllocVramOffset(int a, int b);

u32 PARTICLE_AllocPlttVramTracked(u32 a, u32 b);

struct RigObject;

extern int  SPL_EMITTER_AllocPlttVramList(struct RigObject *o, ParticleLoadFn fn);

extern int  SPL_EMITTER_AllocTexVramList(struct RigObject *o, ParticleLoadFn fn);
struct TcbTask;

struct G3dProjection;


struct G3dLookAt;

struct G3dLookAt;


struct G3dCamera;

struct VramHeapHead;


#include "nns_g3d_glb.h"


#include "nns_g3d_ge.h"


#include "fx_mtx33.h"


#include "g3d_camera.h"

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

extern struct ParticleMan *g_pParticleMan;

extern const char sParticleFile[];

extern Vec3 sDefaultCameraPos;

extern Vec3 sDefaultCameraTarget;

extern Vec3 sDefaultCameraUp;

extern void *(*const sSystemEngineIds[])(u32 size); /* per-slot allocator callbacks */

extern Vec3 sDefaultViewVec;

extern u32      g_renderState[];

extern u32      g_renderStateDrawParams[];

extern u32      g_renderStateIdentityMtx[];

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

    g_pParticleMan = GFL_HEAP_Alloc(heapId, 0x48, i, sParticleFile, 190);

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
 * SPL_EMITTER_AllocNodeFromHeap's handle at +0.
 *
 * WHAT CLOSED IT (docs/notes/pkt_02050C30.c.txt: size-exact at 392 with 37
 * bytes out inside the final argument setup, permuter exhausted): the
 * per-slot table 0x020A15A8 is CONST (a table of allocator function pointers).
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

    sys = GFL_HEAP_Alloc((u16)heapId, 0x260, 0, sParticleFile, 285);
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

    sys->engine = SPL_EMITTER_AllocNodeFromHeap(sSystemEngineIds[i], 0x18, 0xc8, (u16)limitA, (u16)limitB, (u16)maxResIndex);
    return sys;
}

/*
 * Emitter teardown: release the two 0x40-entry resource tables (either as a
 * whole through NNS_GfdLoadVramManager / NNSi_GfdSetVramManagerWork, or entry by entry through
 * NNS_GfdFreeTexVram / NNS_GfdFreePlttVram depending on the flag byte at +0x258), drop
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
    uptr z = 0;

    PARTICLE_KillAllEffects(sys);

    if (sys->loadMode & PARTICLE_LOAD_TEX_BULK) {
        NNS_GfdLoadVramManager(sys->texHandles);
    } else if (sys->loadMode & PARTICLE_LOAD_TEX_ENTRY) {
        for (i = 0; i < 0x40; i++) {
            if (sys->texHandles[i] != 0) {
                NNS_GfdFreeTexVram(sys->texHandles[i]);
                sys->texHandles[i] = z;
            }
        }
    }

    if (sys->loadMode & PARTICLE_LOAD_PAL_BULK) {
        NNSi_GfdSetVramManagerWork(sys->palHandles);
    } else if (sys->loadMode & PARTICLE_LOAD_PAL_ENTRY) {
        for (i = 0; i < 0x40; i++) {
            if (sys->palHandles[i] != 0) {
                NNS_GfdFreePlttVram(sys->palHandles[i]);
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
                GFL_HEAP_Free(block);
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

    GFL_HEAP_Free(sys);
}

/*
 * Teardown of a sixteen-entry table of pointers: every non-null entry is
 * released through PARTICLE_DeleteSystem, then the table pointer itself is handed to
 * GFL_HEAP_Free and cleared.  The global is re-read from its own slot before
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
    GFL_HEAP_Free(g_pParticleMan);
    g_pParticleMan = 0;
}

void *PARTICLE_AllocWorkSlot0(u32 size)
{
    struct ParticleSys *sys = g_pParticleMan->systems[0];
    u32 next = sys->workCursor + size;
    uptr start = sys->workCursor;
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
    uptr start = sys->workCursor;
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
    uptr start = sys->workCursor;
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
    uptr start = sys->workCursor;
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
    uptr start = sys->workCursor;
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
    uptr start = sys->workCursor;
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
    uptr start = sys->workCursor;
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
    uptr start = sys->workCursor;
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
    uptr start = sys->workCursor;
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
    uptr start = sys->workCursor;
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
    uptr start = sys->workCursor;
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
    uptr start = sys->workCursor;
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
    uptr start = sys->workCursor;
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
    uptr start = sys->workCursor;
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
    uptr start = sys->workCursor;
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
    uptr start = sys->workCursor;
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
    struct VramNodeHeap *engine;

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
        NNS_GfdSaveVramManager(sys->texHandles);
        sys->texLoadFn = (ParticleLoadFn)PARTICLE_AllocTexVramOffset;
    } else if (mode & PARTICLE_LOAD_TEX_ENTRY) {
        for (i = 0; i < 0x40; i++)
            sys->texHandles[i] = z;
        sys->texLoadFn = PARTICLE_AllocTexVramTracked;
        sys->texCount = z;
    }
    if (mode & PARTICLE_LOAD_PAL_BULK) {
        NNSi_GfdGetVramManagerWork((struct Arena02146B74 *)sys->palHandles);
        sys->palLoadFn = (ParticleLoadFn)PARTICLE_AllocVramOffset;
    } else if (mode & PARTICLE_LOAD_PAL_ENTRY) {
        for (i = 0; i < 0x40; i++)
            sys->palHandles[i] = z;
        sys->palLoadFn = PARTICLE_AllocPlttVramTracked;
        sys->palCount = z;
    }
    engine = sys->engine;
    sys->resourceBlock = block;
    SPL_EMITTER_FreeNodeToHeap((struct VramTexHeap *)engine, block);
    if (applyNow == 1) {
        PARTICLE_ApplyLoadHandlers(sys);
        return;
    }
    if (taskMgr == 0)
        return;
    TCB_AddTask((struct TcbSystem *)taskMgr, (TcbFunc)PARTICLE_ApplyLoadHandlersTask, sys, 0);
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
 * Tail call with two zero arguments. Filed as the witness for ov094 BTLV_EFFVM_CmdLoadParticleResource.
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
 *   - inline (`if (p[6] == 0) SPL_EMITTER_AllocTexVramDefault(p[0]);`) the compiler folds the
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
    struct VramNodeHeap *engine;

    g_pParticleMan->current = sys;

    fn = sys->texLoadFn;
    engine = sys->engine;
    if (fn == 0)
        SPL_EMITTER_AllocTexVramDefault((uptr)engine);
    else
        SPL_EMITTER_AllocTexVramList((struct RigObject *)engine, fn);

    fn = sys->palLoadFn;
    engine = sys->engine;
    if (fn == 0)
        SPL_EMITTER_AllocPlttVramDefault((uptr)engine);
    else
        SPL_EMITTER_AllocPlttVramList((struct RigObject *)engine, fn);

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
    TCB_DeleteTask((struct TcbTask *)task);
}

/*
 * particle.c, the 3D setup half of a two-phase emitter pass (wave 13).  When
 * the private block at +0x20 exists: bring up the two frame objects (0x20 and
 * 0x24 bytes), copy the model vector 0x020A159C into a local, build an
 * identity 3x3, zero a vector for NNS_G3dGlbBaseTrans, copy the 3x3 to the
 * 0x02148C08 scratch, clear bits 0xa4 of word 63 of 0x02148B4C and hand the
 * model vector to NNS_G3dGlbBaseScale; then the shared call SPL_EMITTER_FreeNodeHeap and, when
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
 * this function; the ROM word equals the relocation), SPL_EMITTER_FreeNodeHeap through
 * sole-ref/code.
 */
void PARTICLE_DrawSystem(struct ParticleSys *sys)
{
    SavedGxState savedState;
    MtxFx33    savedMtx;

    if (sys->camera != 0) {
        G3D_SYSTEM_GetProjection((struct G3dProjection *)(&savedState));
        G3D_SYSTEM_GetLookAt((struct G3dLookAt *)(&savedMtx));
        {
            Vec3  viewVec = sDefaultViewVec;
            MtxFx33 identity;
            Vec3  zeroVec = {0, 0, 0};
            MTX_Identity33_(&identity);
            NNS_G3dGlbBaseTrans(&zeroVec);
            MI_Copy36B(&identity, g_renderStateIdentityMtx);
            g_renderState[63] = g_renderState[63] & ~0xa4u;
            NNS_G3dGlbBaseScale(&viewVec);
        }
        G3D_CAMERA_Reset((struct G3dCamera *)sys->camera);
        G3D_SYSTEM_ApplyLookAt();
        NNS_G3dGeFlushBuffer();
    }
    SPL_EMITTER_FreeNodeHeap((struct VramHeapHead *)sys->engine, (uptr)g_renderStateDrawParams);
    if (sys->camera == 0)
        return;
    G3D_SYSTEM_SetProjection((struct G3dProjection *)(&savedState));
    G3D_SYSTEM_SetLookAt((struct G3dLookAt *)(&savedMtx));
    G3D_SYSTEM_ApplyLookAt();
    NNS_G3dGeFlushBuffer();
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
#ifdef __MWERKS__
    return SPL_EMITTER_FreeTexNode(sys->engine);
#else
    /* the definition returns void; the DS caller returns whatever r0 holds */
    SPL_EMITTER_FreeTexNode((struct VramFreeList *)sys->engine);
    return 0;
#endif
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
 * EXACT entry (src/matched/SPL_EMITTER_AllocResource.c, shard pkt_0205250C) and this
 * file's call site now resolves through the `matched` class.  No change to
 * the C was needed.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/PARTICLE_StartEffect.c \
 *       --func PARTICLE_StartEffect --addr 0x020515B4 --cc 1.1p1 --arm
 */
int PARTICLE_StartEffect(struct ParticleSys *sys, int resId, int arg)
{
    int effect = SPL_EMITTER_AllocResource((char *)sys->engine, resId, arg);
    sys->activeEffect = effect;
    return effect;
}

/*
 * Promoted by parks lane 2: the callee 0x020525A0 was filed first as an
 * EXACT entry (src/matched/SPL_EMITTER_AllocResourceEx.c, shard pkt_0205250C) and this
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
    effect = SPL_EMITTER_AllocResourceEx((char *)sys->engine, resId, callback);
    g_pParticleMan->callbackArg = 0;
    sys->activeEffect = effect;
    return effect;
}

/*
 * Returns word 2 of the object at *p. Filed as the witness for ov094 BTLV_EFFVM_IsAllIdle.
 */
int PARTICLE_GetEffectCount(struct ParticleSys *sys)
{
    return sys->engine->effectCount;
}

void PARTICLE_KillAllEffects(struct ParticleSys *sys)
{
    SPL_EMITTER_FreeResourceList(sys->engine);
}

/*
 * Dereference the first argument and tail-call SPL_EMITTER_FreeResource with the loaded
 * pointer.  Unlabelled ARM leaf in the ARM9 listing; matched so its overlay
 * callers get a `matched` witness.
 */
void PARTICLE_KillEffect(struct ParticleSys *sys, void *effect)
{
    SPL_EMITTER_FreeResource((char *)sys->engine, effect);
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
        sys->camera = (struct ParticleCamera *)G3D_CAMERA_Create(params->projType, params->fovSin, params->fovCos, params->aspect,
                                    params->orthoExtent, params->nearZ, params->farZ, params->projScale,
                                    pos, target, up, (u16)heapId);
    } else {
        sys->projType = 0;
        sys->camera = (struct ParticleCamera *)G3D_CAMERA_Create(0, 0xb50, 0xb50, 0x1555,
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

/* ---- ParticleMan/ParticleSys accessor head, moved from button_man.c
 * (0x02051774..0x02051B84).  Vec3 and MtxFx33 are already defined above; the
 * remaining object views and callees are declared here. ---- */

struct Ent {
    void *fn;
    void *data;
};

struct BlkInner {
    u8   pad00[0x04];
    Vec3 pos;               /* +0x04 */
};

struct Blk {
    struct BlkInner *inner; /* +0x00, re-read per statement */
    u8               pad04[0x14];
    struct Ent      *ents;  /* +0x18 */
    u16              count; /* +0x1C */
};

/* The 3D object the accessors at 0x02051788..0x02051B04 work on. */
struct Obj3D {
    u8      pad00[0x20];
    struct Blk *blk;        /* +0x20 */
    u8      pad24[0x04];
    Vec3    emitPos;        /* +0x28 */
    Vec3    pos;            /* +0x34 */
    u8      pad40[0x10];
    Vec3U16 rot;            /* +0x50 */
    u8      pad56[0x06];
    s32     scaleX;
    s32     scaleY;
    s32     offsetX;
    s32     offsetY;
    s32     angle;
    u16     alpha;
    u8      pad72[0x1E];
    s32     callback;
    s32     userData;
};

extern u32 d_02146A88;
struct LerpDest;
struct LerpSource;

#ifdef __MWERKS__
extern void SPL_EMITTER_LerpVec(struct LerpSource *a, struct LerpDest *b);
#endif
struct InterpState;
struct InterpTrack;
struct InterpTargetParam;

#ifdef __MWERKS__
extern void SPL_EMITTER_InterpTarget(struct InterpTargetParam *a, struct InterpTrack *s, s32 unused, struct InterpState *c);
#endif
struct AxisAngleKey;

#ifdef __MWERKS__
extern void SPL_EMITTER_BuildFrame(struct AxisAngleKey *o, u8 *dst);
#endif
struct RigOffsetPair;
struct ScaledVecSource;

struct RandomVecSource;
struct RandomVecRange;

#ifdef __MWERKS__
extern void SPL_EMITTER_UpdateNode(struct RandomVecRange *o, struct RandomVecSource *s, s32 *dst);
extern void SPL_EMITTER_AddVec(struct RandomVecRange *o, void *s, s32 *dst);
extern int NNSi_GfdDefaultAllocTexVram(int a, int b, int c); /* original prototype; the definition differs in argument count, return type */
#endif

#include "gx_bgcnt.h"








u32 PARTICLE_GetCallbackArg(void)
{
    return *(u32 *)(*(u32 *)&d_02146A88 + 0x40);
}

extern u32 (*NNS_GfdDefaultFuncAllocTexVram)(u32 a, u32 b, u32 c);

extern u32 (*NNS_GfdDefaultFuncAllocPlttVram)(u32 a, u32 b, u32 c);

/*
 * Returns the word at offset 0x20. Filed as the witness for ov094 BTLV_EFFVM_CmdStartParticleEffectTargeted.
 */
int PARTICLE_EMITTER_GetBlock(struct Obj3D *p)
{
    return (sptr)p->blk;
}

/*
 * Copies the vector at offset 0x34 out. Filed as the witness for ov094 BTLV_EFFVM_ParticleStartCallback.
 */
void PARTICLE_EMITTER_GetPos(struct Obj3D *p, Vec3 *out)
{
    *out = p->pos;
}

/*
 * Stores a vector at offset 0x34. Filed as the witness for ov094 BTLV_EFFVM_ParticleStartCallback.
 */
void PARTICLE_EMITTER_SetPos(struct Obj3D *p, const Vec3 *v)
{
    p->pos = *v;
}

/*
 * Copies the three halfwords at offset 0x50 out. Filed as the witness for ov094 BTLV_EFFVM_ParticleStartCallback.
 */
void PARTICLE_EMITTER_GetRot(struct Obj3D *p, Vec3U16 *out)
{
    *out = p->rot;
}

/*
 * Returns the word at offset 0x5c. Filed as the witness for ov094 BTLV_EFFVM_ParticleStartCallback.
 */
int PARTICLE_EMITTER_GetScaleX(struct Obj3D *p)
{
    return p->scaleX;
}

/*
 * Stores the word at offset 0x5c. Filed as the witness for ov094 BTLV_EFFVM_ParticleStartCallback.
 */
void PARTICLE_EMITTER_SetScaleX(struct Obj3D *p, int v)
{
    p->scaleX = v;
}

/*
 * Returns the word at offset 0x60. Filed as the witness for ov094 BTLV_EFFVM_ParticleStartCallback.
 */
int PARTICLE_EMITTER_GetScaleY(struct Obj3D *p)
{
    return p->scaleY;
}

/*
 * Stores the word at offset 0x60. Filed as the witness for ov094 BTLV_EFFVM_ParticleStartCallback.
 */
void PARTICLE_EMITTER_SetScaleY(struct Obj3D *p, int v)
{
    p->scaleY = v;
}

/*
 * Returns the word at offset 0x64 as a short. Filed as the witness for ov094 BTLV_EFFVM_ParticleStartCallback.
 */
short PARTICLE_EMITTER_GetOffsetX(struct Obj3D *p)
{
    return p->offsetX;
}

/*
 * Stores the word at offset 0x64. Filed as the witness for ov094 BTLV_EFFVM_ParticleStartCallback.
 */
void PARTICLE_EMITTER_SetOffsetX(struct Obj3D *p, int v)
{
    p->offsetX = v;
}

/*
 * Returns the word at offset 0x68 as a short. Filed as the witness for ov094 BTLV_EFFVM_ParticleStartCallback.
 */
short PARTICLE_EMITTER_GetOffsetY(struct Obj3D *p)
{
    return p->offsetY;
}

/*
 * Stores the word at offset 0x68. Filed as the witness for ov094 BTLV_EFFVM_ParticleStartCallback.
 */
void PARTICLE_EMITTER_SetOffsetY(struct Obj3D *p, int v)
{
    p->offsetY = v;
}

/*
 * Returns the word at offset 0x6c as a short. Filed as the witness for ov094 BTLV_EFFVM_ParticleStartCallback.
 */
short PARTICLE_EMITTER_GetAngle(struct Obj3D *p)
{
    return p->angle;
}

/*
 * Returns the halfword at offset 0x70. Filed as the witness for ov094 BTLV_EFFVM_ParticleStartCallback.
 */
unsigned short PARTICLE_EMITTER_GetAlpha(struct Obj3D *p)
{
    return p->alpha;
}

/*
 * particle.c (wave 13): the emitter's three-word position at +0x28..+0x30 is
 * the caller's vector plus the vector at +4 of the block the private 3D
 * block's first word names (+0x20 -> +0x00 -> +0x04/+0x08/+0x0C).
 *
 * WHAT CLOSED IT (docs/notes/pkt_02051838.c.txt: 72 against 72 with 10 bytes
 * out via a `volatile` parameter, permuter exhausted at 3000): the caller's
 * vector is a `const VecFx32 *`.  mwccarm lets a load through a const-
 * qualified pointer move above a store through a non-const one, so all three
 * q reads are hoisted to the top in the image's order (r4, r3, r2 -- a
 * descending run the peephole cannot merge into one ldm), while the block's
 * inner pointer is still re-read before each sum because the stores to the
 * emitter may alias it.  No named locals: each component is one statement.
 * The `volatile` spelling only imitated that hoisting and allocated
 * differently; plain non-const spellings keep the q reads in place and merge
 * two of them into an ldm (68 bytes).
 */
void PARTICLE_EMITTER_SetEmitPos(struct Obj3D *e, const Vec3 *q)
{
    e->emitPos.x = q->x + e->blk->inner->pos.x;
    e->emitPos.y = q->y + e->blk->inner->pos.y;
    e->emitPos.z = q->z + e->blk->inner->pos.z;
}

/*
 * Setter on the same object as its packet-mate src/matched/PARTICLE_EMITTER_FindBehaviorData.c:
 * copies a three-component 16-bit vector into the object's 0x50..0x54
 * triple.  The three loads come out ahead of the three stores, which is the
 * plain field-by-field spelling; a struct assignment would be ldm/stm.
 */
void PARTICLE_EMITTER_SetRot(struct Obj3D *o, const Vec3U16 *v)
{
    o->rot.x = v->x;
    o->rot.y = v->y;
    o->rot.z = v->z;
}

/*
 * Word setter on the same object as its packet-mate
 * src/matched/PARTICLE_EMITTER_FindBehaviorData.c: stores the argument into field 0x6c.
 */
void PARTICLE_EMITTER_SetAngle(struct Obj3D *o, u32 v)
{
    o->angle = v;
}

/*
 * Halfword setter on the same object as its packet-mate
 * src/matched/PARTICLE_EMITTER_FindBehaviorData.c: stores the argument into field 0x70.
 */
void PARTICLE_EMITTER_SetAlpha(struct Obj3D *o, u16 v)
{
    o->alpha = v;
}

/*
 * Linear search of the block at obj+0x20 for the first 8-byte entry whose
 * first word is the handler address selected by `kind`, returning that
 * entry's second word (or NULL).  The six handlers are the 3D-rig rows at
 * 0x02057EF8..0x020582CC, all pool words and all attested by the sibling
 * pool at 0x02052DB0.
 *
 * Two tells decide the shape.  Declaring the index BEFORE the count is what
 * puts the count in r4 and the index in lr (declaration-order-decides-which-
 * register-a-local-gets).  And the image's `adds ip, r5, lr, lsl #3` / `beq`
 * pair at +0040 is a redundant null test on the entry pointer: the `adds`
 * form only appears when the source writes `if (e == 0) continue;`, which
 * folds into the address computation.  Without it the switch is four bytes
 * shorter and every branch target shifts.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/PARTICLE_EMITTER_FindBehaviorData.c \
 *       --func PARTICLE_EMITTER_FindBehaviorData --addr 0x020518AC --cc 1.1p1 --arm
 */
void *PARTICLE_EMITTER_FindBehaviorData(struct Obj3D *obj, int kind)
{
    struct Blk *b = obj->blk;
    int i;
    int n = b->count;

    if (n == 0)
        return 0;

    for (i = 0; i < n; i++) {
        struct Ent *e = &b->ents[i];
        if (e == 0)
            continue;
        switch (kind) {
        case 0:
            if (e->fn == (void *)SPL_EMITTER_AddVec)
                return e->data;
            break;
        case 1:
            if (e->fn == (void *)SPL_EMITTER_UpdateNode)
                return e->data;
            break;
        case 2:
            if (e->fn == (void *)SPL_EMITTER_AddScaledVec)
                return e->data;
            break;
        case 3:
            if (e->fn == (void *)SPL_EMITTER_BuildFrame)
                return e->data;
            break;
        case 4:
            if (e->fn == (void *)SPL_EMITTER_InterpTarget)
                return e->data;
            break;
        case 5:
            if (e->fn == (void *)SPL_EMITTER_LerpVec)
                return e->data;
            break;
        default:
            return 0;
        }
    }
    return 0;
}

/*
 * Copies a 12-byte record into the slot PARTICLE_EMITTER_FindBehaviorData hands back for class 2.
 * Verified with:
 *   python tools/match.py one --src src/matched/PARTICLE_EMITTER_SetBehavior2Data.c \
 *       --func PARTICLE_EMITTER_SetBehavior2Data --addr 0x020519C4 --cc 1.1p1 --arm
 */
void PARTICLE_EMITTER_SetBehavior2Data(struct Obj3D *p, Vec3 *q)
{
    Vec3 *r = PARTICLE_EMITTER_FindBehaviorData(p, 2);

    if (r != 0)
        *r = *q;
}

/*
 * The class-3 slot carries only a halfword at +2.
 * Verified with:
 *   python tools/match.py one --src src/matched/PARTICLE_EMITTER_SetBehavior3Half.c \
 *       --func PARTICLE_EMITTER_SetBehavior3Half --addr 0x020519E4 --cc 1.1p1 --arm
 */
void PARTICLE_EMITTER_SetBehavior3Half(struct Obj3D *p, u16 *q)
{
    u16 *r = PARTICLE_EMITTER_FindBehaviorData(p, 3);

    if (r != 0)
        r[1] = *q;
}

/*
 * Same 12-byte copy as PARTICLE_EMITTER_SetBehavior2Data, out of the class-5 slot.
 * Verified with:
 *   python tools/match.py one --src src/matched/PARTICLE_EMITTER_SetBehavior5Data.c \
 *       --func PARTICLE_EMITTER_SetBehavior5Data --addr 0x02051A04 --cc 1.1p1 --arm
 */
void PARTICLE_EMITTER_SetBehavior5Data(struct Obj3D *p, Vec3 *q)
{
    Vec3 *r = PARTICLE_EMITTER_FindBehaviorData(p, 5);

    if (r != 0)
        *r = *q;
}

/*
 * Unlabelled ARM leaf in the ARM9 module: an 8-byte store helper,
 * `p[0x90/4] = v`. With PARTICLE_EMITTER_SetUserData (the +0x94 twin) it is the storage
 * setter pair the ov118 functions POKETRADE_DEMO_MIDDLE_SetupEmitterA/SetupEmitterB call.
 *
 * Addresses are Black-image addresses.
 */
void PARTICLE_EMITTER_SetCallback(struct Obj3D *p, int v)
{
    p->callback = v;
}

/*
 * Unlabelled ARM leaf in the ARM9 module: an 8-byte store helper,
 * `p[0x94/4] = v`. The +0x94 twin of PARTICLE_EMITTER_SetCallback.
 *
 * Addresses are Black-image addresses.
 */
void PARTICLE_EMITTER_SetUserData(struct Obj3D *p, int v)
{
    p->userData = v;
}

/*
 * Unlabelled ARM leaf in the ARM9 module: an 8-byte load helper,
 * `return p[0x94/4]`. The getter half of PARTICLE_EMITTER_SetUserData.
 *
 * Addresses are Black-image addresses.
 */
int PARTICLE_EMITTER_GetUserData(struct Obj3D *p)
{
    return p->userData;
}

/*
 * Calls NNSi_GfdDefaultAllocTexVram with a constant 0 as its third argument and returns the
 * low halfword of the result scaled by eight (unused2 and unused3 are unused).
 */
unsigned int PARTICLE_AllocTexVramOffset(int szByte, int is4x4comp, int unused2, int unused3)
{
#ifdef __MWERKS__
    int t0 = NNSi_GfdDefaultAllocTexVram(szByte, is4x4comp, 0);
#else
    int t0 = NNSi_GfdDefaultAllocTexVram(szByte, is4x4comp);
#endif

    return (unsigned int)(t0 << 16) >> 13;
}

/*
 * The caller's registered handler (the function pointer in the clact.c global
 * 0x020A8140) is invoked with the two incoming arguments and a literal 0 in
 * r2; r1 is never written, so the callee takes at least two arguments and the
 * third is a constant zero.
 *
 * The result is appended to the current context's u32 table: the count
 * halfword at base+0x25c is loaded once, incremented and stored back, and the
 * value is written to base+0x58+count*4 - the store uses the OLD count, so the
 * table is indexed before the increment.  The return value is the low
 * halfword of the result scaled by eight, which the compiler writes as the
 * fused unequal shift pair lsl #16 / lsr #13 (a u16 cast folded into the
 * multiply, see
 * docs/idioms/unequal-shift-pair-is-a-narrowing-cast-folded-with-a-shift.md).
 *
 * The twin at 0x02051AB8 is the same shape over the parallel table 0x100
 * higher (count at +0x25e, elements at +0x158).
 */
u32 PARTICLE_AllocTexVramTracked(u32 szByte, u32 is4x4comp)
{
    u32 v = NNS_GfdDefaultFuncAllocTexVram(szByte, is4x4comp, 0);
    struct ParticleSys *base = g_pParticleMan->current;
    u16 n = base->texCount;

    base->texCount = n + 1;
    base->texHandles[n] = v;

    return (u16)v * 8;
}

/*
 * Verified with:
 *   python tools/match.py one --src src/matched/PARTICLE_AllocVramOffset.c \
 *       --func PARTICLE_AllocVramOffset --addr 0x02051AA0 --cc 1.1p1 --arm
 */
int PARTICLE_AllocVramOffset(int a, int b)
{
    return (u16)NNS_GfdAllocVram(a, b, 1) << 3;
}

/*
 * Byte-for-byte the twin of PARTICLE_AllocTexVramTracked over the second table: same
 * indirect call through the handler at 0x020A8140 (two arguments forwarded,
 * a literal 0 in r2), same append-and-count shape, but the count halfword is
 * at base+0x25e and the elements at base+0x158, i.e. the parallel table 0x100
 * bytes higher with its own counter.
 */
u32 PARTICLE_AllocPlttVramTracked(u32 a, u32 b)
{
    u32 v = NNS_GfdDefaultFuncAllocPlttVram(a, b, 0);
    struct ParticleSys *base = g_pParticleMan->current;
    u16 n = base->palCount;

    base->palCount = n + 1;
    base->palHandles[n] = v;

    return (u16)v * 8;
}

/*
 * ARM leaf, seeded 2026-09-27 from the ov195 call site 0x02208954
 * (SHINKA_DEMO_EFFECT_CreateParticle). Returns the u16 at +8 of its argument.
 *
 * Addresses are Black-image addresses.
 */
u16 PARTICLE_RESOURCE_GetType(void *res)
{
    return ((u16 *)res)[4];
}

/*
 * Eight-way dispatch on a button-man handler id: each of the eight ids tail
 * calls its own handler and returns that handler's value, and any id above 7
 * falls out of the switch to `return 0;`.  That trailing `return 0;` is what
 * the image has at +0x7C (`mov r0, #0; pop {r3, pc}`) and it is also the
 * addls-skipped target at +0x0C, so the `switch` has no `default:` label at
 * all - writing the arms as bare calls (or with `break`) instead of
 * `return f();` loses those eight bytes and the arms' `pop {r3, pc}` with
 * them.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/G2_GetBGCharPtrById.c \
 *       --func G2_GetBGCharPtrById --addr 0x02051B0C --cc 1.1p1 --arm
 */
int G2_GetBGCharPtrById(int i)
{
    switch (i) {
    case 0: return (sptr)G2_GetBG0CharPtr();
    case 1: return (sptr)G2_GetBG1CharPtr();
    case 2: return (sptr)G2_GetBG2CharPtr();
    case 3: return (sptr)G2_GetBG3CharPtr();
    case 4: return G2S_GetBG0CharPtr();
    case 5: return G2S_GetBG1CharPtr();
    case 6: return (sptr)G2S_GetBG2CharPtr();
    case 7: return (sptr)G2S_GetBG3CharPtr();
    }
    return 0;
}
