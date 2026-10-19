#ifndef GAME_OV021_FLD_SCENEAREA_TYPES_H
#define GAME_OV021_FLD_SCENEAREA_TYPES_H

/*
 * Scene areas (fld_scenearea.c, fld_scenearea_loader.c). A scene area file is
 * an array of 0x48-byte records. Each record holds a region of the map (the
 * "check"), a camera setup (the "action") and the ids of the check and of the
 * actions to run when the player stays in, enters or leaves the region. The
 * loader (fld_scenearea_loader.c) reads the file and owns the check and
 * action tables; FldSceneArea (fld_scenearea.c) runs them every frame.
 */

#include "../types.h"

#include "../sdk_fx.h"

struct FldSceneArea;
struct FldSceneAreaRec;

/* Offset of FldSceneAreaRec.checkId (read by the update loop through the record base). */
#define FLD_SCENEAREA_REC_CHECK_ID_OFFSET 0x40

/* FldSceneArea.current when the player is in no area. */
#define FLD_SCENEAREA_NO_AREA (-1)

/* FldSceneArea.lastActionId before any action ran this frame. */
#define FLD_SCENEAREA_NO_ACTION 0xFFFF

/* Check ids (index into the check table gFldSceneAreaChecks). */
#define FLD_SCENEAREA_CHECK_SECTOR 0 /* ring sector around a center, FLD_SCENEAREA_LOADER_CheckSector */
#define FLD_SCENEAREA_CHECK_STRIP 1  /* tile strip, FLD_SCENEAREA_LOADER_CheckStrip */

/* Action ids (index into the action table gFldSceneAreaActions). */
#define FLD_SCENEAREA_ACTION_SECTOR_CAMERA 0     /* camera on a sector, ApplySectorCamera */
#define FLD_SCENEAREA_ACTION_FIXED_CAMERA 1      /* fixed target and eye, ApplyFixedCamera */
#define FLD_SCENEAREA_ACTION_STRIP_CAMERA 2      /* pitch, yaw, distance along the strip */
#define FLD_SCENEAREA_ACTION_STRIP_CAMERA_STOP 3 /* same, stops the camera delay first when delayFlag is set */
#define FLD_SCENEAREA_ACTION_STRIP_CAMERA_RESUME 4 /* same, restarts the camera delay afterwards */
#define FLD_SCENEAREA_ACTION_STRIP_FULL 5        /* strip camera, target shift and field of view */
#define FLD_SCENEAREA_ACTION_STRIP_FULL_STOP 6
#define FLD_SCENEAREA_ACTION_STRIP_FULL_RESUME 7

/* Check function: returns 1 when the position lies in the record's region. */
typedef int (*FldSceneAreaCheckFn)(struct FldSceneArea *sceneArea, const struct FldSceneAreaRec *rec, VecFx32 *pos);

/* Action function: applies the record's camera setup. */
typedef void (*FldSceneAreaActionFn)(struct FldSceneArea *sceneArea, const struct FldSceneAreaRec *rec, VecFx32 *pos);

/* Tables the update loop dispatches through (ROM object at 0x021D8EF4, 12 bytes). */
typedef struct FldSceneAreaCallbacks {
    const FldSceneAreaCheckFn *checks;
    const FldSceneAreaActionFn *actions;
    u16 checkCount;
    u16 actionCount;
} FldSceneAreaCallbacks;

/* Camera pitch, yaw and distance at one end of a strip. */
typedef struct FldSceneAreaCameraKey {
    u16 pitch;
    u16 yaw;
    s32 distance;
} FldSceneAreaCameraKey;

/* One scene area record (0x48 bytes). The layout of 0x00..0x3F depends on the check id. */
typedef struct FldSceneAreaRec {
    union {
        /* FLD_SCENEAREA_CHECK_SECTOR with the sector camera action */
        struct {
            u32 angleLo;     /* sector start angle, 16 bit angle units */
            u32 angleHi;     /* sector end angle; hi < lo wraps through 0 */
            s32 minDistance; /* inner radius */
            s32 maxDistance; /* outer radius */
            VecFx32 center;
            s32 angleIndex;  /* camera elevation as a table index, in steps of 16 */
            s32 distance;    /* camera distance from the center */
        } sector;
        /* FLD_SCENEAREA_CHECK_STRIP with the strip camera actions */
        struct {
            u16 tileX;       /* strip start, in tiles */
            u16 tileZ;
            u16 extentX;     /* 1: strip runs along x for length tiles with extentZ tiles in z; otherwise extentX wide along z */
            u16 extentZ;
            u16 length;
            u8 reserved0A[2];
            FldSceneAreaCameraKey from;
            FldSceneAreaCameraKey to;
            s32 delayFlag;   /* nonzero: stop or restart the camera delay around the move */
            VecFx32 targetFrom;
            VecFx32 targetTo;
            u16 fovFrom;
            u16 fovTo;
            u8 reserved3C[4];
        } strip;
        /* FLD_SCENEAREA_ACTION_FIXED_CAMERA */
        struct {
            u8 reserved00[0x24];
            VecFx32 target;
            VecFx32 eye;
            u8 reserved3C[4];
        } fixed;
    } shape;
    u16 checkId;
    u16 stayActionId;
    u16 enterActionId;
    u16 leaveActionId;
} FldSceneAreaRec;

/* Scene area work (0x20 bytes), created by FIELDMAP and held in FieldMap.sceneArea. */
typedef struct FldSceneArea {
    void *camera;
    void *fieldMap;
    FldSceneAreaRec *recs;
    const FldSceneAreaCallbacks *callbacks;
    u32 count;
    int current;       /* index of the area the player is in, or FLD_SCENEAREA_NO_AREA */
    int enabled;
    u32 lastActionId;  /* id of the action that ran last this frame, or FLD_SCENEAREA_NO_ACTION */
} FldSceneArea;

/* Scene area file loader (0x10 bytes), held in FieldMap.sceneAreaLoader. */
typedef struct FldSceneAreaLoader {
    FldSceneAreaRec *recs;
    u32 count;
    void *arcHandle[2];
} FldSceneAreaLoader;

#endif
