#ifndef SCRCMD_NETWORK_SHARED_TYPES_H
#define SCRCMD_NETWORK_SHARED_TYPES_H

#include "../arm9/script_vm_types.h"

struct GameSystem;

struct GameData;

struct GameComm;

struct GameEvent;

struct FieldMap;

struct MyStatus;

#include "../types.h"

/* Event task callback: (event, sequence counter, work). */
typedef int (*EventTaskFn)(struct GameEvent *event, u32 *seq, void *work);

#endif
