#ifndef FIELD_FLASH_SHARED_TYPES_H
#define FIELD_FLASH_SHARED_TYPES_H

#include "../types.h"

#include "../sdk_fx.h"

typedef struct FieldMap FieldMap;

typedef struct FieldCamera FieldCamera;

typedef struct FieldPlayer FieldPlayer;

typedef struct Mmdl Mmdl;

/* FIELD_FLASH: the cave flash light. A tween drives the size and alpha of the mask model. */
typedef struct FlashTween {
    fx32 size;
    u8 alpha;
    u8 pad5;
    u16 frame;
    u16 frames;
    u8 padA[2];
    fx32 sizeStart;
    fx32 sizeDelta;
    s16 alphaStart;
    s16 alphaDelta;
} FlashTween;

typedef struct FldWipe3dObj FldWipe3dObj;

typedef struct FieldFlash {
    FldWipe3dObj *model;
    FlashTween tween;
    u16 state;
    u16 pendingCommand;
} FieldFlash;

enum FlashCommand {
    FLASH_CMD_INIT = 0,
    FLASH_CMD_EXPAND = 1,
    FLASH_CMD_SHOW_EXPANDED = 2,
    FLASH_CMD_HIDE = 3,
    FLASH_CMD_NONE = 4
};

/* FLD_WIPE_3DOBJ: resource archive and object of the flash mask model. */
struct FldWipe3dObj {
    void *resArc;
    void *object;
};

#endif
