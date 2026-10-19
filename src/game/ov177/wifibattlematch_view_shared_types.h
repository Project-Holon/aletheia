#ifndef WIFIBATTLEMATCH_VIEW_SHARED_TYPES_H
#define WIFIBATTLEMATCH_VIEW_SHARED_TYPES_H

#include "wifibattlematch_graphic_shared_types.h"

struct MsgBank;

struct U16Vec;

struct Descriptor;

struct PrintSys;

struct Obj;

struct CharBuf;

struct Slot;

#include "../types.h"

typedef struct { void *win; u8 shown; u8 pad[3]; } Slot;

#endif
