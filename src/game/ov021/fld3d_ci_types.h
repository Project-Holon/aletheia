#ifndef ALETHEIA_OV021_FLD3D_CI_TYPES_H
#define ALETHEIA_OV021_FLD3D_CI_TYPES_H

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;
typedef int fx32;

typedef struct { fx32 x, y, z; } VecFx32;
typedef struct { fx32 m[3][3]; } MtxFx33;
typedef struct NNSFndAllocator { u32 w[4]; } NNSFndAllocator;
typedef struct NNSG3dRenderObj NNSG3dRenderObj;
typedef struct NNSG3dAnmObj NNSG3dAnmObj;

#include "../arm9/g3d_system_types.h"

struct Fld3dCi;

/* Particle system of the field map (FLD_PARTICLE_Create). */
typedef struct FldParticle {
    u32 reserved;
    u16 heapId;
    u16 pad06;
    void *workBuffer;      /* 0x4800-byte particle work area */
    void *effect;          /* effect instance, 0 when none */
} FldParticle;

/* One resource of a cut-in sequence: kind 0x73 is a particle resource. */
typedef struct Fld3dCiResource {
    u32 kind;
    u16 id;
    u32 value;
} Fld3dCiResource;

typedef struct Fld3dCiAnimRef {
    u16 index;
    u16 zero;
} Fld3dCiAnimRef;

typedef struct Fld3dCiAnimTrack {
    u16 index;
    u16 zero;
    u16 trackIndex;
    Fld3dCiAnimRef *refs;
    u16 refCount;
} Fld3dCiAnimTrack;

/* Cut-in sequence data in archive 0x75, one record per sequence id. */
typedef struct Fld3dCiSeqFile {
    u32 effectResId;
    u16 startDelay[2];
    u16 trackA[2];
    u16 waitDelay[2];
    u16 trackB[4];
    u16 trackC[4];
    u32 darkenScreen;
} Fld3dCiSeqFile;

/* Sequence data built from a Fld3dCiSeqFile (FLD3D_CI_LoadSequence). */
typedef struct Fld3dCiSeq {
    Fld3dCiResource *resources;     /* total entries */
    Fld3dCiAnimTrack *tracks;       /* trackACount entries */
    Fld3dCiAnimRef *refsB;          /* trackBCount entries */
    Fld3dCiAnimRef *refsC;          /* trackCCount entries */
    Fld3dCiResource *resourceTable;
    u16 resourceCount;
    Fld3dCiAnimTrack *trackTable;
    u16 trackTableCount;
    u16 pad1E;
    u16 startDelay[2];
    u16 waitDelay[2];
    u32 effectResId;
    u8 total;
    u8 trackACount;
    u8 trackBCount;
    u8 trackCCount;
    u32 darkenScreen;
} Fld3dCiSeq;

/* Pokemon description of a pokemon cut-in, plus its cry state. */
typedef struct Fld3dCiPokemon {
    int species;
    int form;
    int attr6E;
    int personality;
    int attr4C;
    int cryPending;
    u16 cryDelay;
    u16 cryFadeWait;
    int cryHandle;
} Fld3dCiPokemon;

/* Name icon arguments of a trainer or item cut-in. */
typedef struct Fld3dCiIcon {
    int nameMsgId;
    int chrFile;
    int plttFile;
    int hasSecondName;
    int secondNameCentered;
} Fld3dCiIcon;

typedef struct Fld3dCiCharData {
    u8 pad00[0x14];
    u8 *raw;
} Fld3dCiCharData;

typedef struct Fld3dCiPlttData {
    u8 pad00[0xC];
    u16 *raw;
} Fld3dCiPlttData;

typedef int (*Fld3dCiEventStepFunc)(void *event, int *state);
typedef int (*Fld3dCiFinishFunc)(void *event, struct Fld3dCi *ci);

/* The cut-in work (0x138 bytes), FieldMap.fld3dCi. */
typedef struct Fld3dCi {
    FldParticle *particle;
    void *cameraPersp;
    void *cameraOrtho;
    u32 cameraSelect;           /* 0 draws with cameraPersp, else cameraOrtho */
    u16 heapId;
    u16 pad12;
    void *gfxUnits;
    int effectUnit;             /* -1 when none */
    G3dObjectStatus status;     /* drawn with G3D_SYSTEM_DrawObject */
    void *effect;
    u16 startDelay[2];
    u16 waitDelay[2];
    u16 started;
    u16 sequenceId;
    u32 savedVisiblePlanes;
    u8 savedLayerPriority[4];
    u32 captureDone;
    u32 displayRestoreDone;
    u32 trackStarted[2];
    u32 trackWatched[2];
    Fld3dCiCharData *chr;
    Fld3dCiPlttData *pltt;
    void *canvas;
    void *chrRes;
    void *plttRes;
    union {
        Fld3dCiPokemon pokemon;
        Fld3dCiIcon icon;
        u32 args[5];
    } arg;
    u8 pad_BC[0x11C - 0xBC];
    int startDone;
    int trackADone;
    int trackBDone;
    Fld3dCiEventStepFunc extraTask;
    Fld3dCiFinishFunc finishStep;
    u32 finishState;
    u16 frame;
    u16 cueIndex;
} Fld3dCi;

/* Work of the cut-in game event (0x40 bytes). */
typedef struct Fld3dCiEventWork {
    Fld3dCi *ci;
    Fld3dCiSeq seq;
    u32 hideFieldObjects;
    u32 fadeVariant;
} Fld3dCiEventWork;

/* Textures and palettes of a model resource block. */
typedef struct Fld3dCiTexBlock {
    u8 pad00[8];
    u32 texDataWord;
    u8 pad0C[0x20];
    u32 plttDataWord;
    u8 pad30[4];
    u16 plttDictOffset;
} Fld3dCiTexBlock;

typedef struct Fld3dCiTexDictEntry {
    u32 dataWord;
} Fld3dCiTexDictEntry;

typedef struct Fld3dCiPlttDictEntry {
    u16 dataWord;
} Fld3dCiPlttDictEntry;

typedef struct Fld3dCiFollowTarget {
    int pad;
    VecFx32 pos;
} Fld3dCiFollowTarget;

/* Follow-the-target animation callback argument. */
typedef struct Fld3dCiFollow {
    u8 pad00[0x20];
    Fld3dCiFollowTarget **target;
    int pad24;
    VecFx32 pos;
} Fld3dCiFollow;

/* Sound cue: play soundId when the sequence reaches frame. */
typedef struct Fld3dCiCue {
    int soundId;
    u32 frame;
} Fld3dCiCue;

typedef struct Fld3dCiNameKey { u32 v[4]; } Fld3dCiNameKey;
typedef struct Fld3dCiDispSetup { u32 v[4]; } Fld3dCiDispSetup;
typedef struct Fld3dCiBgMode { int a, b, c, d; } Fld3dCiBgMode;

#endif
