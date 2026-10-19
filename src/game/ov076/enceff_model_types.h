#ifndef ALETHEIA_OV076_ENCEFF_MODEL_TYPES_H
#define ALETHEIA_OV076_ENCEFF_MODEL_TYPES_H

/*
 * Encounter effect with a 3D model (overlay 0x4C): two flashes, then a
 * model with an animation plays over a capture of the field screen, and the
 * screen fades out when the animation nears its end. One builder per effect
 * kind of the effect table in enceff.c (kinds 0, 1, 5, 6, 31, 35).
 */

#include "../types.h"

struct GameSystem;
struct GameEvent;
struct FieldMap;
struct EncEffWork;

/* Work of the model effect, 0x44 bytes, owned by the EncEffWork of the field map. */
typedef struct EncEffModelScene {
    int flashCount;            /* 0x00 flashes done, two are played */
    struct FieldMap *fieldMap; /* 0x04 */
    u32 texBankMask;           /* 0x08 texture VRAM banks in use, with the bank this effect adds */
    int texBankAdded;          /* 0x0C 1 when this effect added its bank and must remove it */
    u32 savedDrawMode;         /* 0x10 draw mode of the field map, restored at the end */
    void *modelResource;       /* 0x14 */
    void *screenTex;           /* 0x18 capture of the field screen */
    void *animeResource;       /* 0x1C */
    void *renderObj;           /* 0x20 */
    void *animeObj;            /* 0x24 */
    void *object;              /* 0x28 render object with its animation */
    u32 modelIndex;            /* 0x2C member of the model archive */
    u32 animeIndex;            /* 0x30 member of the model archive */
    int fadeScreens;           /* 0x34 screens of the closing fade (0xC or 3) */
    int fadeStarted;           /* 0x38 */
    s32 fadeStartFrame;        /* 0x3C animation frame that starts the closing fade */
    int soundId;               /* 0x40 sound played with the model, or -1 */
} EncEffModelScene;

extern struct FieldMap *GAMESYSTEM_GetFieldMap(struct GameSystem *gameSystem);
extern struct EncEffWork *FIELDMAP_GetEncEff(struct FieldMap *fieldMap);
extern void *ENCEFF_AllocWork(struct EncEffWork *eff, u32 size, u32 heapId);
extern EncEffModelScene *ENCEFF_GetWork(struct EncEffWork *eff);

#endif
