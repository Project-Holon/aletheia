#ifndef ICA_ANIME_SHARED_TYPES_H
#define ICA_ANIME_SHARED_TYPES_H

#include "../arm9/btl_setup_types.h"
#include "../arm9/script_vm_types.h"
#include "../arm9/vm_shared_types.h"

struct MiscSave;

struct GameSystem;

struct BgmInfo;

struct GameComm;

struct GameEvent;

struct GameEvent;

typedef int (*GameEventFunc)(struct GameEvent *event, u32 *seq, void *work);

typedef struct GameEvent *(*GameEventCreatorFn)(struct GameSystem *gameSystem, void *arg);

/* Game system proc work (0x34 bytes, GAMESYSTEM_GetWorkSize). */
struct GameSystem {
    u16   heapId;
    u8    pad02[2];
    u32   initParam;
    struct ProcSys *procSys;
    u32   procStatus;
    GameEventCreatorFn eventCreator;
    void *eventCreatorArg;
    struct GameEvent *event;
    struct GameData *gameData;
    void *fieldMap;
    struct GameComm *gameComm;
    u32   reserved;
    void *issSystem;
    u8    fieldMapState;
    u8    eventActive;
    u8    commBlocked;
    u8    netOffBySleep : 1;
    u8    unusedBits : 7;
};

/* One running event of the game system (0x14 bytes, game_event.c). */
struct GameEvent {
    struct GameEvent *parent;
    GameEventFunc func;
    u32   seq;
    void *work;
    struct GameSystem *gameSystem;
};


#include "../sdk_fx.h"

#endif
