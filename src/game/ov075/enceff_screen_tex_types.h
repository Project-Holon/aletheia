#ifndef ALETHEIA_OV075_ENCEFF_SCREEN_TEX_TYPES_H
#define ALETHEIA_OV075_ENCEFF_SCREEN_TEX_TYPES_H

#include "../sdk_fx.h"

/* Include ../ov021/fieldmap_types.h before this header (VecFx32). */

#include "../types.h"

struct GameSystem;
struct GameEvent;
struct EncEffWork;

/*
 * Overlay 75 is the common part of the encounter effects that capture the
 * field screen and draw it as a direct color texture on 3D polygons
 * (overlays 77 to 81 give the polygons).  The caller passes a camera
 * position, a start function (returns the event that animates the polygons)
 * and a draw function.
 */

typedef struct GameEvent *(*EncEffScreenTexStartFunc)(struct GameSystem *gameSystem);
typedef void (*EncEffScreenTexDrawFunc)(void *effectWork);

typedef struct EncEffScreenTexWork {
    int flashCount;                         /* 0x00: white flashes done */
    u32 texBanks;                           /* 0x04: texture VRAM banks in use */
    int addedTexBank;                       /* 0x08: 1 when bit 8 of texBanks was added here */
    u32 savedDrawMode;                      /* 0x0C: field map draw mode to restore */
    int captureDone;                        /* 0x10: set by the capture task */
    u32 texParam;                           /* 0x14: TEXIMAGE_PARAM of the captured screen */
    VecFx32 cameraPos;                      /* 0x18 */
    void *effectWork;                       /* 0x24: ENCEFF effect memory */
    EncEffScreenTexStartFunc start;         /* 0x28 */
    EncEffScreenTexDrawFunc draw;           /* 0x2C */
} EncEffScreenTexWork;

typedef int (*GameEventMainFunc)(struct GameEvent *event, int *state, void *work);

#endif
