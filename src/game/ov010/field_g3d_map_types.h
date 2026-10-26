#ifndef ALETHEIA_OV010_FIELD_G3D_MAP_TYPES_H
#define ALETHEIA_OV010_FIELD_G3D_MAP_TYPES_H

/*
 * Field 3D map block object (field_g3d_map.c). One object is one loaded map
 * block: it streams a model file from an archive member into its own buffer,
 * turns it into a render object, draws it, and keeps two small tables of
 * placed models (position and angle per entry). The 0xDC-byte object is
 * built by FIELD_G3D_MAP_Create and handled by the field_g3d_mapper in ov021.
 */

struct FieldG3dMap;
typedef struct ArcFile ArcFile;

#include "../sdk_fx.h"

/* 4x3 matrix of the pipeline load and multiply commands: rotation, then translation. */
typedef struct FieldG3dMapMtx43 {
    int rot[9];
    VecFx32 trans;
} FieldG3dMapMtx43;

/* Result record of the query callbacks: five words per hit. */
typedef struct FieldG3dMapHit {
    unsigned short kind;
    unsigned short index;
    unsigned short flags;
    int attr;
    int height;
} FieldG3dMapHit;

typedef struct FieldG3dMapHitList {
    FieldG3dMapHit hits[16];
    unsigned int count;
} FieldG3dMapHitList;

/* Callback of a block type, called with the loaded data, a position, the grid size and its height. */
typedef void (*FieldG3dMapQueryFunc)(void *out, void *data, VecFx32 *localPos, unsigned int gridSize, unsigned int height);

/* Callback of a block type, called once per update with the user parameter of the config. */
typedef void (*FieldG3dMapUpdateFunc)(struct FieldG3dMap *map, void *userParam);

/*
 * Block type table entry (0x10 bytes). The table ends with key -1; the key is
 * the first halfword of the archive member.
 */
typedef struct FieldG3dMapType {
    int key;                              /* 0x00 */
    FieldG3dMapUpdateFunc update;         /* 0x04 */
    FieldG3dMapQueryFunc queryHits;       /* 0x08 */
    FieldG3dMapQueryFunc queryPlane;      /* 0x0C */
} FieldG3dMapType;

/* Model resource info as read by the box test (fields from offset 0x18 of the info block). */
typedef struct FieldG3dMapModelInfo {
    unsigned char head[0x18];
    short boxX;                           /* 0x18 */
    short boxY;                           /* 0x1A */
    short boxZ;                           /* 0x1C */
    short boxW;                           /* 0x1E */
    short boxH;                           /* 0x20 */
    short boxD;                           /* 0x22 */
    unsigned int boxPosScale;             /* 0x24 */
} FieldG3dMapModelInfo;

/* Model resource: the info block starts at 0x14. */
typedef struct FieldG3dMapModel {
    unsigned char head[0x14];
    FieldG3dMapModelInfo info;
} FieldG3dMapModel;

/* Render object (0x54 bytes): the model is the second word. */
typedef struct FieldG3dMapRenderObj {
    unsigned int flag;                    /* 0x00 */
    FieldG3dMapModel *model;              /* 0x04 */
    unsigned char body[0x4C];             /* 0x08 */
} FieldG3dMapRenderObj;

/* Placed model entry (0x14 bytes); index -1 marks an unused entry. */
typedef struct FieldG3dMapPlacement {
    int modelIndex;                       /* 0x00 */
    VecFx32 pos;                   /* 0x04 */
    unsigned short angle;                 /* 0x10 */
    unsigned short pad12;                 /* 0x12 */
} FieldG3dMapPlacement;

/* Model resources of the placed models: one pair of resource pointers per model index. */
typedef struct FieldG3dMapModelRes {
    void *modelData;                      /* 0x00 */
    void *textureData;                    /* 0x04 */
} FieldG3dMapModelRes;

typedef struct FieldG3dMapModelSet {
    FieldG3dMapModelRes *res;             /* 0x00 */
    unsigned int count;                   /* 0x04 */
} FieldG3dMapModelSet;

/* Creation parameters. */
typedef struct FieldG3dMapConfig {
    unsigned int bufferSize;              /* 0x00 */
    unsigned int texVramSize;             /* 0x04 */
    const FieldG3dMapType *typeTable;     /* 0x08 */
    void *userParam;                      /* 0x0C */
    unsigned int chunkSize;               /* 0x10, 0 selects 0x800 */
    unsigned short placementCountA;       /* 0x14 */
    unsigned short placementCountB;       /* 0x16 */
    unsigned int extraParam0;             /* 0x18 */
    unsigned int extraParam1;             /* 0x1C */
} FieldG3dMapConfig;

typedef struct FieldG3dMap {
    unsigned short visible;               /* 0x00 */
    unsigned short loadSync;              /* 0x02, 1 while a load must finish in one step */
    VecFx32 pos;                   /* 0x04 */
    ArcFile *archive;                     /* 0x10 */
    unsigned int memberIndex;             /* 0x14 */
    unsigned int typeIndex;               /* 0x18, index into typeTable */
    unsigned int bufferSize;              /* 0x1C */
    unsigned int texVramSize;             /* 0x20 */
    unsigned int chunkSize;               /* 0x24 */
    const FieldG3dMapType *typeTable;     /* 0x28 */
    FieldG3dMapRenderObj *renderObjRef;   /* 0x2C, points at renderObj */
    FieldG3dMapRenderObj renderObj;       /* 0x30 */
    void *modelRes;                       /* 0x84, resource record, mode 1 */
    void *textureRes;                     /* 0x88, resource record, mode 2 */
    unsigned int texKey;                  /* 0x8C */
    unsigned int plttKey;                 /* 0x90 */
    void *altTextureRes;                  /* 0x94, used when textureRes holds nothing */
    FieldG3dMapModelSet *placedModels;    /* 0x98 */
    FieldG3dMapPlacement *placementsA;    /* 0x9C */
    FieldG3dMapPlacement *placementsB;    /* 0xA0 */
    unsigned short placementCountA;       /* 0xA4 */
    unsigned short placementCountB;       /* 0xA6 */
    unsigned int extraParam0;             /* 0xA8 */
    unsigned int extraParam1;             /* 0xAC */
    unsigned short active;                /* 0xB0, nonzero from load start until reset */
    unsigned short padB2;                 /* 0xB2 */
    unsigned int bufferOffset;            /* 0xB4, bytes of the buffer already filled */
    unsigned int loadedBytes;             /* 0xB8 */
    unsigned int totalBytes;              /* 0xBC, size of the archive member */
    unsigned int resetFlag;               /* 0xC0, cleared with the load state */
    unsigned int spareWord;               /* 0xC4, not read here */
    unsigned int readFinished;            /* 0xC8, set when the member has been read */
    unsigned int buildStarted;            /* 0xCC, set when the build step begins */
    unsigned int dataReady;               /* 0xD0 */
    unsigned char *buffer;                /* 0xD4 */
    void *userParam;                      /* 0xD8 */
} FieldG3dMap;

#endif
