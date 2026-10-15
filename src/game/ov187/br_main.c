/*
 * file:     br_main.c
 * unit:     yes
 * function: BR_MAIN_Init, BR_MAIN_Exit, BR_MAIN_Main, BR_MAIN_InitSceneManager, BR_MAIN_RunSceneStep, BR_MAIN_FreeSceneManager, BR_MAIN_SetDesiredScene, BR_MAIN_CreateListScene, BR_MAIN_DeleteListScene, BR_MAIN_CreateReplayScene, BR_MAIN_DeleteReplayScene, BR_MAIN_SanitizeBgmIds
 * address:  0x0220AF40
 * region:   ov187
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from br_main.c, ov187_func_0220B240.c by tools/splitfile.py.
 *
 * symbols:
 *   GFL_HEAP_CreateChildHeap 0x0203064C arm
 *   PROCSYS_AllocProcWork 0x0203159C arm
 *   MI_CpuFill8 0x02082BCC arm
 *   BATTLE_REC_AllocWork 0x0200B400 thumb
 *   d_0220B2A0 0x0220B2A0 data a4
 *   STRBUF_Delete   0x02045808  arm
 *   func_020315D4   0x020315D4  arm
 *   func_020306F0   0x020306F0  arm
 *   BATTLE_REC_FreeWork   0x0200B424  thumb
 *   PROCSYS_Create  0x02031324  arm
 *   PROCSYS_Push 0x02031348 arm
 *   PROCSYS_Main 0x02031330 arm
 *   func_02034714  0x02034714  arm
 *   func_0203133C  0x0203133C  arm
 *   func_02030734 0x02030734 arm
 *   d_0220B2E4 0x0220B2E4 data a1
 *   func_020307B0  0x020307B0  arm
 *   BTL_SETUP_InitWithSlots 0x020138C4 thumb
 *   BATTLE_REC_LoadToolOverlay 0x0200BA58 thumb
 *   BATTLE_REC_UnloadToolOverlay 0x0200BA68 thumb
 *   BATTLE_REC_TOOL_UnpackSetup 0x021EEEA8 thumb ov188
 *   GFL_USE_SetBgmPlayerParam 0x02005DE4 thumb
 *   GFL_USE_PushBgm 0x02005E64 thumb
 *   BR_MAIN_SanitizeBgmIds 0x0220B240 thumb ov187
 *   GFL_USE_CancelChangeAndPlayBgm 0x02005D90 thumb
 *   GAME_DATA_GetBgmInfo 0x02012A30 thumb
 *   GFL_USE_PopBgm 0x02005E9C thumb
 *   GFL_USE_FadeInBgmFull 0x02005DF8 thumb
 *   func_02028A58 0x02028A58 thumb
 *   BTL_SETUP_ClearWithSlots 0x02013930 thumb
 */
#include "../arm9/btl_setup_types.h"

struct GameData;
struct SoundSys;
struct StrBuf;

typedef unsigned int   u32;

typedef unsigned char  u8;

typedef unsigned short u16;

/* One screen of the recorder: how to build its work block, which proc to push, how to free it. */
typedef struct BrSceneEntry {
    int procId;
    const void *procDescriptor;
    void *(*create)(unsigned short heapId, void *owner, unsigned previousScene);
    void (*destroy)(void *sceneWork, void *owner);
} BrSceneEntry;

/* Scene manager, 0x28 bytes at the start of the recorder work block. */
typedef struct BrSceneManager {
    void *procSys;
    unsigned step;
    void *sceneWork;
    unsigned unused0C;      /* never read or written */
    unsigned short heapId;
    unsigned short unused12;
    void *owner;
    const BrSceneEntry *scenes;
    unsigned previousScene;
    unsigned desiredScene;
    unsigned currentScene;
} BrSceneManager;

/* Parameter block the caller passes in as the proc's argument. */
typedef struct BrLaunchParam {
    u32 kind;
    struct GameData *gameData;
} BrLaunchParam;

/* Work block of the recorder proc, 0x17F4 bytes. */
typedef struct BrMainWork {
    BrSceneManager sceneManager;        /* 0x0000 */
    u8 sceneData[0x1758];               /* 0x0028 */
    struct StrBuf *slotNames[4];        /* 0x1780 */
    u8 unknown1790[0x34];               /* 0x1790 */
    u32 hasRecords;                     /* 0x17C4 */
    u8 unknown17C8[0x1C];               /* 0x17C8 */
    u32 hidePlayerNames;                /* 0x17E4 */
    u8 unknown17E8[8];                  /* 0x17E8 */
    BrLaunchParam *launch;              /* 0x17F0 */
} BrMainWork;

/* Work block of the list scene, 16 bytes. */
typedef struct BrListSceneWork {
    int launchKind;
    int mode;
    void *data;
    BrLaunchParam *launch;
} BrListSceneWork;

extern void GFL_HEAP_CreateChildHeap(unsigned, unsigned, unsigned);

extern void *PROCSYS_AllocProcWork(void *proc, unsigned int size, unsigned int heap);

extern void *MI_CpuFill8(void *, int, unsigned);

extern void BATTLE_REC_AllocWork(unsigned);

extern void STRBUF_Delete(struct StrBuf *vec);

extern void func_020315D4(void *p);

extern void func_020306F0(unsigned int heap);

extern void BATTLE_REC_FreeWork(void);

extern void *PROCSYS_Create(int heapId);

extern void PROCSYS_Push(void *, int, const void *, void *);

extern unsigned int PROCSYS_Main(void *p);

extern void func_02034714(const char *expr, u32 line, const char *file);

extern void func_0203133C(void *procSys);

extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);

extern u32 func_020307B0(void *p);

extern void BTL_SETUP_InitWithSlots(struct BattleSetupParam *, struct GameData *, u32 heapId);

extern void BATTLE_REC_LoadToolOverlay(void);

extern void BATTLE_REC_UnloadToolOverlay(void);

extern void BATTLE_REC_TOOL_UnpackSetup(struct BattleSetupParam *, u32);

extern void GFL_USE_SetBgmPlayerParam(void *p);

extern int GFL_USE_PushBgm(void);

extern void BR_MAIN_SanitizeBgmIds(u16 *,u16 *);

extern void GFL_USE_CancelChangeAndPlayBgm(u32,u32);

extern unsigned int GAME_DATA_GetBgmInfo(const struct GameData *);

extern int GFL_USE_PopBgm(void);

extern void GFL_USE_FadeInBgmFull(u32);

extern void func_02028A58(struct SoundSys *sys, u8 level, u16 frames);

extern void BTL_SETUP_ClearWithSlots(struct BattleSetupParam *p);

int BR_MAIN_Init(void *proc, unsigned unused, BrLaunchParam *launch);

int BR_MAIN_Exit(int a, int b, int c, BrMainWork *work);

int BR_MAIN_Main(void *a, int *state, int b, BrMainWork *work);

void BR_MAIN_InitSceneManager(BrSceneManager *mgr, const BrSceneEntry *scenes, void *owner, u32 heapId);

int BR_MAIN_RunSceneStep(BrSceneManager *mgr);

void BR_MAIN_FreeSceneManager(BrSceneManager *mgr);

void BR_MAIN_SetDesiredScene(BrMainWork *work, u32 scene);

BrListSceneWork *BR_MAIN_CreateListScene(unsigned short heapId, BrMainWork *work, int mode);

void BR_MAIN_DeleteListScene(BrListSceneWork *listWork, BrMainWork *work);

void *BR_MAIN_CreateReplayScene(u32 heapId, BrMainWork *work);

void BR_MAIN_DeleteReplayScene(struct BattleSetupParam *setup, BrMainWork *work);

extern const BrSceneEntry d_0220B2A0[];

extern const char d_0220B2E4[];

int BR_MAIN_Init(void *proc, unsigned unused, BrLaunchParam *launch)
{
    BrMainWork *work;
    GFL_HEAP_CreateChildHeap(1, 0x59, 0x12000);
    work = PROCSYS_AllocProcWork(proc, sizeof(BrMainWork), 0x59);
    MI_CpuFill8(work, 0, sizeof(BrMainWork));
    work->launch = launch;
    BATTLE_REC_AllocWork(0x59);
    BR_MAIN_InitSceneManager(&work->sceneManager, d_0220B2A0, work, 0x59);
    BR_MAIN_SetDesiredScene(work, 0);
    return 1;
}

/* Free the saved-record name strings when records exist, then the scene manager and the work. */
int BR_MAIN_Exit(int a, int b, int c, BrMainWork *work)
{
    int i;
    if (work->hasRecords != 0) {
        for (i = 0; i < 4; i++) {
            struct StrBuf *name = work->slotNames[i];
            if (name != 0)
                STRBUF_Delete(name);
        }
    }
    BR_MAIN_FreeSceneManager(&work->sceneManager);
    BATTLE_REC_FreeWork();
    func_020315D4((void *)a);
    func_020306F0(0x59);
    return 1;
}

int BR_MAIN_Main(void *a, int *state, int b, BrMainWork *work)
{
    switch (*state) {
    case 0:
        *state = 1;
        break;
    case 1:
        if (BR_MAIN_RunSceneStep(&work->sceneManager))
            *state = 2;
        break;
    case 2:
        return 1;
    }
    return 0;
}

void BR_MAIN_InitSceneManager(BrSceneManager *mgr, const BrSceneEntry *scenes, void *owner, u32 heapId)
{
    MI_CpuFill8(mgr, 0, sizeof(BrSceneManager));
    mgr->procSys = PROCSYS_Create(heapId);
    mgr->owner = owner;
    mgr->scenes = scenes;
    mgr->heapId = heapId;
}

/* Scene state machine: 0 select next scene, 1 create its work and push its proc, 2 run, 3 destroy, 4 done. */
int BR_MAIN_RunSceneStep(BrSceneManager *mgr)
{
    switch (mgr->step) {
    case 0:
        mgr->previousScene = mgr->currentScene;
        mgr->currentScene = mgr->desiredScene;
        mgr->step = 1;
        break;
    case 1:
        if (mgr->scenes[mgr->currentScene].create) mgr->sceneWork = mgr->scenes[mgr->currentScene].create(mgr->heapId, mgr->owner, mgr->previousScene);
        else mgr->sceneWork = 0;
        PROCSYS_Push(mgr->procSys, mgr->scenes[mgr->currentScene].procId, mgr->scenes[mgr->currentScene].procDescriptor, mgr->sceneWork);
        mgr->step = 2;
        break;
    case 2:
        if (!PROCSYS_Main(mgr->procSys)) mgr->step = 3;
        break;
    case 3:
        if (mgr->scenes[mgr->currentScene].destroy) {
            mgr->scenes[mgr->currentScene].destroy(mgr->sceneWork, mgr->owner);
            mgr->sceneWork = 0;
        }
        if (mgr->currentScene != mgr->desiredScene) mgr->step = 0;
        else mgr->step = 4;
        break;
    case 4: return 1;
    }
    return 0;
}

void BR_MAIN_FreeSceneManager(BrSceneManager *mgr)
{
    if (mgr->sceneWork != 0)
        func_02034714((void *)0x0220b2e0, 0, (void *)0x0220b2e0);
    func_0203133C(mgr->procSys);
    MI_CpuFill8(mgr, 0, sizeof(BrSceneManager));
}

void BR_MAIN_SetDesiredScene(BrMainWork *work, u32 scene) { work->sceneManager.desiredScene = scene; }

BrListSceneWork *BR_MAIN_CreateListScene(unsigned short heapId, BrMainWork *work, int mode)
{
    BrListSceneWork *list;
    list = func_02030734(heapId, sizeof(BrListSceneWork), 0, d_0220B2E4, 0x1e7);
    MI_CpuFill8(list, 0, sizeof(BrListSceneWork));
    list->launch = work->launch;
    list->data = work->sceneData;
    if (mode == 1) list->mode = 1;
    else list->mode = 0;
    return list;
}

void BR_MAIN_DeleteListScene(BrListSceneWork *listWork, BrMainWork *work)
{
    switch (listWork->launchKind) {
    case 0:
        break;
    case 1:
        BR_MAIN_SetDesiredScene(work, 1);
        break;
    }
    func_020307B0(listWork);
}

void *BR_MAIN_CreateReplayScene(u32 heapId, BrMainWork *work)
{
    struct BattleSetupParam *setup = func_02030734(heapId, sizeof(struct BattleSetupParam), 0, d_0220B2E4, 542);
    MI_CpuFill8(setup, 0, sizeof(struct BattleSetupParam));
    BTL_SETUP_InitWithSlots(setup, work->launch->gameData, heapId);
    BATTLE_REC_LoadToolOverlay();
    BATTLE_REC_TOOL_UnpackSetup(setup, heapId);
    BATTLE_REC_UnloadToolOverlay();
    GFL_USE_SetBgmPlayerParam((void *)1);
    GFL_USE_PushBgm();
    BR_MAIN_SanitizeBgmIds(&setup->bgmBattle, &setup->bgmWin);
    GFL_USE_CancelChangeAndPlayBgm(setup->bgmBattle, 65535);
    return setup;
}

void BR_MAIN_DeleteReplayScene(struct BattleSetupParam *setup, BrMainWork *work)
{
    void *soundSys = (void *)GAME_DATA_GetBgmInfo(work->launch->gameData);
    GFL_USE_PopBgm();
    GFL_USE_SetBgmPlayerParam(0);
    GFL_USE_FadeInBgmFull(30);
    if (work->launch->kind == 0) func_02028A58(soundSys, 64, 0);
    work->hidePlayerNames = setup->bits.recordComplete;
    func_020307B0(setup->playerStatus[0]);
    BTL_SETUP_ClearWithSlots(setup);
    func_020307B0(setup);
    BR_MAIN_SetDesiredScene(work, 0);
}

/* Force the battle BGM to a known id and the win BGM to 0x47D or 0x480. */
void BR_MAIN_SanitizeBgmIds(u16 *battleBgm, u16 *winBgm)
{
    u16 x = *battleBgm;
    u16 y = *winBgm;
    switch (x) {
    case 0x46B: case 0x470: case 0x48D: case 0x490: break;
    case 0x48B: case 0x48C: case 0x48E: case 0x48F: default: *battleBgm = 0x490; break;
    }
    if (y != 0x47D && y != 0x480) *winBgm = 0x47D;
}
