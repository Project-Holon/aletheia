#ifndef ALETHEIA_OV021_FIELDMAP_TYPES_H
#define ALETHEIA_OV021_FIELDMAP_TYPES_H

/*
 * The field map work (0x154 bytes, fieldmap.c FIELDMAP_Create). Every
 * pointer field is named after the call that creates it in fieldmap.c
 * (FIELDMAP_SeqInitSystem, FIELDMAP_SeqCreateSubsystems,
 * FIELDMAP_CreateG3dResources).
 */

struct GameSystem;
struct GameData;
struct AreaData;
struct FieldCamera;
struct FieldLight;
struct FieldFog;
struct FieldZoneFog;
struct WeatherSys;
struct FieldSubscreen;
struct FieldMsgBg;
struct FieldMsgWin;
struct FieldPlaceName;
struct FldExpObjCnt;
struct MmdlSys;
struct FieldNogridMapper;
struct FldSceneArea;
struct FldSceneAreaLoader;
struct FieldG3dMapper;
struct FieldPlayer;
struct FieldEncount;
struct FieldEffectSys;
struct UnionEff;
struct FieldPalaceSys;
struct FieldSkillMapEff;
struct G3dCamera;
struct LightSlot;
struct TcbTask;
struct BbActSys;
struct FieldmapFunc;
struct TcbSystem;
struct FldParticle;
struct Fld3dCi;
struct SodateyaWork;
struct FieldG3dObjCtrl;
struct FieldTaskManager;
struct EncEffWork;
struct FldVReq;
struct FieldMap;

/* A fixed point 3D vector (x, y, z in fx32). */
#include "../sdk_fx.h"

/* A warp destination (0x1C bytes; same layout as arm9 zonedata.c Location). */
typedef struct FieldMapLocation {
    unsigned int type;          /* 0x00: 0 exit, 1 direct */
    unsigned short zoneId;      /* 0x04 */
    short exitId;               /* 0x06 */
    unsigned short dir;         /* 0x08 */
    unsigned short exitOffset;  /* 0x0A */
    unsigned int posType;       /* 0x0C: 0 vector, 1 rail */
    VecFx32 pos;                /* 0x10 */
} FieldMapLocation;

/*
 * Map mapper parameters (0x3C bytes at FieldMap+0x50), filled by
 * FIELDMAP_SetupMapperParam: words 0x00..0x38 come from the per map type
 * table sMapTypeTable, then the matrix and area values overwrite part of them.
 */
typedef struct FieldMapMapperParam {
    unsigned int typeParam[5];          /* 0x00: from the map type table */
    unsigned short matrixWidth;         /* 0x14 */
    unsigned short matrixHeight;        /* 0x16 */
    unsigned int matrixCount;           /* 0x18 */
    void *matrixGrid;                   /* 0x1C */
    unsigned int enabled;               /* 0x20: always 1 */
    unsigned int blockLoadMax;          /* 0x24: always 0xE */
    unsigned int texSetId;              /* 0x28 */
    unsigned int itaAnimeId;            /* 0x2C */
    unsigned int itpAnimeId;            /* 0x30 */
    unsigned int typeParamTail[2];      /* 0x34: from the map type table */
} FieldMapMapperParam;

struct FieldMapCtrlFuncs;

/* One entry of the map type table sMapTypeTable (0x48 bytes). */
typedef struct FieldMapTypeEntry {
    FieldMapMapperParam param;                  /* 0x00 */
    const struct FieldMapCtrlFuncs *ctrlFuncs;  /* 0x3C */
    unsigned int useMatrix;                     /* 0x40 */
    unsigned int extra;                         /* 0x44: not read in fieldmap.c */
} FieldMapTypeEntry;

/*
 * The same table seen from its ctrlFuncs word: gMapTypeCtrlTable is sMapTypeTable +
 * 0x3C, and FIELDMAP_GetCtrlFuncs (and field_event_check.c) load the
 * ctrlFuncs through this second symbol, so the bytes need both names.
 */
typedef struct FieldMapTypeEntryTail {
    const struct FieldMapCtrlFuncs *ctrlFuncs;  /* 0x00 (entry 0x3C) */
    unsigned int useMatrix;                     /* 0x04 (entry 0x40) */
    unsigned int extra;                         /* 0x08 (entry 0x44) */
    FieldMapMapperParam nextParam;              /* 0x0C: next entry's param */
} FieldMapTypeEntryTail;

/* Map control function table (gMapTypeCtrlTable entries point to one). */
typedef struct FieldMapCtrlFuncs {
    unsigned int ctrlType;                                       /* 0x00 */
    void (*create)(struct FieldMap *fieldMap, VecFx32 *pos, int dir); /* 0x04 */
    void (*main)(struct FieldMap *fieldMap, VecFx32 *pos);       /* 0x08 */
    void (*destroy)(struct FieldMap *fieldMap);                  /* 0x0C */
} FieldMapCtrlFuncs;

/* One work buffer that another module can borrow by id (-1 = free). */
typedef struct FieldMapCommonWork {
    int id;                 /* 0x00 */
    void *buf;              /* 0x04 */
} FieldMapCommonWork;

typedef struct FieldMap {
    unsigned short heapId;                  /* 0x000 */
    unsigned short heapIdPad;               /* 0x002: alignment, never read */
    struct GameSystem *gameSystem;          /* 0x004 */
    struct GameData *gameData;              /* 0x008 */
    struct AreaData *areaData;              /* 0x00C ZONEDATA_CreateAreaData */
    struct FieldCamera *camera;             /* 0x010 FIELD_CAMERA_Create */
    struct FieldLight *light;               /* 0x014 FIELD_LIGHT_Create */
    struct FieldFog *fog;                   /* 0x018 FIELD_FOG_Create */
    struct FieldZoneFog *zoneFog;           /* 0x01C FIELD_ZONEFOG_Create */
    struct WeatherSys *weather;             /* 0x020 WEATHER_Create */
    struct FieldSubscreen *subscreen;       /* 0x024 FIELD_SUBSCREEN_Create */
    struct FieldMsgBg *msgBg;               /* 0x028 FIELD_MSGBG_Create */
    struct FieldMsgWin *infoWindow;         /* 0x02C window made by script commands */
    struct FieldPlaceName *placeName;       /* 0x030 */
    struct FldExpObjCnt *expObj;            /* 0x034 FLD_EXP_OBJ_Create */
    struct MmdlSys *mmdlSys;                /* 0x038 GAME_DATA_GetOccupyInfo, FLDMMDL_SetupSysProc */
    struct FieldNogridMapper *nogridMapper; /* 0x03C FIELD_NOGRID_MAPPER_Create */
    struct FldSceneArea *sceneArea;         /* 0x040 FLD_SCENEAREA_Create */
    struct FldSceneAreaLoader *sceneAreaLoader; /* 0x044 FLD_SCENEAREA_LOADER_Create */
    struct FieldG3dMapper *g3dMapper;       /* 0x048 FIELD_G3D_MAPPER_Create */
    unsigned int g3dMapperReserved;         /* 0x04C: not read in fieldmap.c */
    FieldMapMapperParam mapperParam;        /* 0x050 */
    struct FieldPlayer *player;             /* 0x08C FIELD_PLAYER_Create */
    struct FieldEncount *encount;           /* 0x090 FIELD_ENCOUNT_Create */
    struct FieldEffectSys *effect;         /* 0x094 FIELD_EFFECT_Create */
    struct UnionEff *unionEff;              /* 0x098 UNION_EFF_Create (union room only) */
    struct FieldPalaceSys *palaceSys;       /* 0x09C FIELD_PALACE_SYS_Create */
    struct FieldSkillMapEff *mapEff;        /* 0x0A0 FIELDSKILL_MAPEFF_Create */
    struct G3dCamera *g3dCamera;            /* 0x0A4 G3D_CAMERA_Create */
    struct LightSlot *g3dLight;             /* 0x0A8 G3D_LIGHT_CreateSlots */
    struct TcbTask *vblankTcb;              /* 0x0AC FIELDMAP_VBlankTask */
    struct BbActSys *mmdlBbdAct;            /* 0x0B0 billboards of the move models */
    struct BbActSys *effectBbdAct;          /* 0x0B4 shadows and effects (half depth offset) */
    struct BbActSys *groundBbdAct;          /* 0x0B8 grass, ripple, splash */
    struct FieldmapFunc *mapFunc;           /* 0x0BC FIELDMAP_FUNC_Create */
    int mainState;                          /* 0x0C0: 0 starting, 1 running, 2 closing */
    int seqNo;                              /* 0x0C4: row of the sequence table */
    unsigned char subSeq;                   /* 0x0C8 */
    unsigned char halfFrame;                /* 0x0C9: column of the sequence table */
    unsigned char subSeqPad[2];             /* 0x0CA: alignment, never read */
    unsigned int frameCount;                /* 0x0CC */
    unsigned short zoneId;                  /* 0x0D0: zone the map was built for */
    unsigned short zoneIdPad;               /* 0x0D2: alignment, never read */
    FieldMapLocation location;            /* 0x0D4: location.zoneId is the current zone */
    const VecFx32 *targetPos;               /* 0x0F0: position the camera follows */
    VecFx32 nowPos;                         /* 0x0F4 */
    int cameraPitchScale;                   /* 0x100 FIELDMAP_CalcCameraPitchScale */
    int projDepthOffset;                    /* 0x104 FIELDMAP_GetProjDepthOffset */
    const FieldMapCtrlFuncs *ctrlFuncs;     /* 0x108 FIELDMAP_GetCtrlFuncs */
    void *ctrlWork;                         /* 0x10C */
    struct TcbSystem *tcblSys;                /* 0x110 */
    void *tcblWork;                         /* 0x114 */
    FieldMapCommonWork commonWork;          /* 0x118 */
    struct FldParticle *particle;           /* 0x120 FLD_PARTICLE_Create */
    struct Fld3dCi *fld3dCi;                /* 0x124 FLD3D_CI_Create */
    struct SodateyaWork *sodateya;              /* 0x128 SODATEYA_Create */
    int drawMode;                           /* 0x12C: index into the draw tables */
    struct FieldG3dObjCtrl *g3dObjCtrl;     /* 0x130 FIELD_G3DOBJ_Create */
    struct FieldTaskManager *taskManager;   /* 0x134 FIELD_TASK_MANAGER_Create */
    int scriptEffectBusy;                   /* 0x138 */
    struct EncEffWork *encEff;                  /* 0x13C ENCEFF_Create */
    int updateStopped;                      /* 0x140 */
    int subscreenBusy;                      /* 0x144 */
    void *faceUpWork;                       /* 0x148 fld_faceup.c */
    struct FldVReq *vreq;                   /* 0x14C FLD_VREQ_Create */
    void *zoneEffectWork;                   /* 0x150 ov055 */
} FieldMap;

/* The field map proc work (FIELDMAP_ProcInit). */
typedef struct FieldMapProcWork {
    FieldMap *fieldMap;     /* 0x00 */
} FieldMapProcWork;

#endif
