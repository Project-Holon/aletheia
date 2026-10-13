#ifndef ALETHEIA_OV021_FIELD_CAMERA_TYPES_H
#define ALETHEIA_OV021_FIELD_CAMERA_TYPES_H

/*
 * The field camera (field_camera.c, FIELD_CAMERA_*) and the records that
 * field_camera_anime.c and entrance_camera.c pass to it.
 *
 * The camera keeps an eye point and a target point. In mode
 * FIELD_CAMERA_MODE_TRACK_TARGET the target follows a position the owner
 * supplies and the eye is derived from pitch, yaw and distance. In
 * FIELD_CAMERA_MODE_TRACK_EYE the eye follows and the target is derived. In
 * FIELD_CAMERA_MODE_FREE both follow their own sources. The "raw" points are
 * the wanted values; the plain eye and target are the raw ones after the
 * constraint areas have pushed them.
 */

#include "fieldmap_types.h"

struct ArcFile;
struct G3dCamera;
struct FieldCamera;

/* Camera modes (FieldCamera.mode). */
enum {
    FIELD_CAMERA_MODE_TRACK_TARGET,     /* target follows, eye is derived */
    FIELD_CAMERA_MODE_TRACK_EYE,        /* eye follows, target is derived */
    FIELD_CAMERA_MODE_FREE              /* eye and target both follow */
};

/* Constraint area shapes (FieldCameraArea.shape): index into the area function table. */
enum {
    FIELD_CAMERA_AREA_KEEP_IN_BOX,      /* clamp the point into a box */
    FIELD_CAMERA_AREA_KEEP_IN_RING,     /* clamp the point into a ring sector */
    FIELD_CAMERA_AREA_KEEP_OUT_BOX      /* push the point out of a box */
};

/* Which camera point a constraint area limits (FieldCameraArea.applyTo). */
enum {
    FIELD_CAMERA_AREA_ON_TARGET,
    FIELD_CAMERA_AREA_ON_EYE
};

/* One camera setting: angles and distance around the target, target and shift (0x20 bytes). */
typedef struct FieldCameraParam {
    unsigned short pitch;       /* 0x00 */
    unsigned short yaw;         /* 0x02 */
    int distance;               /* 0x04: fx32 */
    VecFx32 target;             /* 0x08 */
    VecFx32 shift;              /* 0x14 */
} FieldCameraParam;

/* Camera move request (0x4C bytes). */
typedef struct FieldCameraAnimeData {
    unsigned int frames;        /* 0x00: 0 sets the end setting at once */
    FieldCameraParam start;     /* 0x04 */
    FieldCameraParam end;       /* 0x24 */
    unsigned int detachTarget;  /* 0x44: unbind the camera from its target during the move */
    unsigned int stopTrace;     /* 0x48: stop the camera trace during the move */
} FieldCameraAnimeData;

/* One entry (0x2C bytes) of archive 0x3C: the camera setting of a camera type. */
typedef struct FieldCameraSetting {
    int distance;               /* 0x00: whole units, shifted left by 12 into fx32 */
    int pitch;                  /* 0x04 */
    int yaw;                    /* 0x08 */
    int pad0C;                  /* 0x0C */
    unsigned char pad10;        /* 0x10 */
    unsigned char projection;   /* 0x11: 0 or 1, passed to the G3D system */
    unsigned short fov;         /* 0x12: angle */
    int g3dScale;               /* 0x14: stored in the G3D camera scale */
    int g3dRoll;                /* 0x18: stored in the G3D camera roll */
    int hasTarget;              /* 0x1C: 0 means vec is the target, else vec is the shift */
    VecFx32 vec;                /* 0x20 */
} FieldCameraSetting;

/* A camera pose (0x30 bytes). */
typedef struct FieldCameraView {
    VecFx32 eye;                /* 0x00 */
    VecFx32 target;             /* 0x0C */
    VecFx32 shift;              /* 0x18 */
    unsigned short pitch;       /* 0x24 */
    unsigned short yaw;         /* 0x26 */
    int distance;               /* 0x28 */
    unsigned short fov;         /* 0x2C */
    unsigned short pad2E;       /* 0x2E */
} FieldCameraView;

/* Which parts of a pose a move interpolates (0x18 bytes); 0 leaves the part alone. */
typedef struct FieldCameraMoveChannels {
    unsigned int shift;         /* 0x00 */
    unsigned int pitch;         /* 0x04 */
    unsigned int yaw;           /* 0x08 */
    unsigned int distance;      /* 0x0C */
    unsigned int fov;           /* 0x10 */
    unsigned int target;        /* 0x14 */
} FieldCameraMoveChannels;

/* Move request of FIELD_CAMERA_StartMove (0x48 bytes). */
typedef struct FieldCameraMoveRequest {
    FieldCameraView goal;               /* 0x00 */
    FieldCameraMoveChannels channels;   /* 0x30 */
} FieldCameraMoveRequest;

/* A constraint area (0x18 bytes). */
typedef struct FieldCameraArea {
    unsigned int shape;         /* 0x00: FIELD_CAMERA_AREA_KEEP_* */
    unsigned int applyTo;       /* 0x04: FIELD_CAMERA_AREA_ON_* */
    union {
        struct {
            int minX;           /* 0x08: whole units */
            int maxX;           /* 0x0C */
            int minZ;           /* 0x10 */
            int maxZ;           /* 0x14 */
        } box;
        struct {
            int centerX;        /* 0x08: fx32 */
            int centerZ;        /* 0x0C */
            int maxRadius;      /* 0x10 */
            unsigned short maxAngle;    /* 0x14 */
            unsigned short minAngle;    /* 0x16 */
        } ring;
    } u;
} FieldCameraArea;

/* The area set of one area record: count, then the areas (archive 0x6C member). */
typedef struct FieldCameraAreaSet {
    int count;                  /* 0x00 */
    FieldCameraArea areas[4];   /* 0x04 */
} FieldCameraAreaSet;

typedef int (*FieldCameraAreaFunc)(const FieldCameraArea *area, VecFx32 *in, VecFx32 *out);

/* A short log that delays the target and eye the camera sends to the G3D camera (0x30 bytes). */
typedef struct FieldCameraDelay {
    int count;                  /* 0x00: entries per log */
    int readPos;                /* 0x04 */
    int writePos;               /* 0x08 */
    int delayFrames;            /* 0x0C */
    int filled;                 /* 0x10: the log has been filled up to the delay */
    int delayX;                 /* 0x14: nonzero delays the x component */
    int delayY;                 /* 0x18 */
    int delayZ;                 /* 0x1C */
    VecFx32 *targetLog;         /* 0x20 */
    VecFx32 *eyeLog;            /* 0x24 */
    int enabled;                /* 0x28 */
    int draining;               /* 0x2C: stop logging, play the log out */
} FieldCameraDelay;

/* The motion block of the camera: the saved pose and the running move (0xC0 bytes). */
typedef void (*FieldCameraUpdateFunc)(struct FieldCamera *camera, unsigned int arg);

typedef struct FieldCameraMotion {
    unsigned int savedMode;             /* 0x00 */
    FieldCameraView saved;              /* 0x04: pose kept by the push state call */
    FieldCameraView from;               /* 0x34 */
    FieldCameraView to;                 /* 0x64 */
    unsigned short frames;              /* 0x94: move length */
    unsigned short frame;               /* 0x96: frames played */
    unsigned int stateSaved;            /* 0x98: saved holds a pose */
    unsigned int moving;                /* 0x9C */
    FieldCameraMoveChannels channels;   /* 0xA0 */
    unsigned int callbackArg;           /* 0xB8 */
    FieldCameraUpdateFunc callback;     /* 0xBC: per frame, runs before the mode update; 0 none */
} FieldCameraMotion;

/* The field camera work (0x1B0 bytes, heap tag 0x80, func_0218E018). */
typedef struct FieldCamera {
    unsigned short heapId;      /* 0x00 */
    unsigned char pad02[2];     /* 0x02 */
    struct ArcFile *settingArc; /* 0x04: archive 0x3C, FieldCameraSetting entries */
    struct ArcFile *areaArc;    /* 0x08: archive 0x6C, FieldCameraAreaSet members */
    struct G3dCamera *g3dCamera;/* 0x0C */
    int settingId;              /* 0x10: index into settingArc */
    unsigned int mode;          /* 0x14: FIELD_CAMERA_MODE_* */
    const VecFx32 *boundTarget; /* 0x18: position the camera was bound to */
    const VecFx32 *traceTarget; /* 0x1C: target source in use; 0 stops the trace */
    const VecFx32 *traceEye;    /* 0x20: eye source in use */
    VecFx32 eyeRaw;             /* 0x24 */
    VecFx32 eyeShift;           /* 0x30 */
    VecFx32 eye;                /* 0x3C */
    VecFx32 targetRaw;          /* 0x48 */
    VecFx32 target;             /* 0x54 */
    VecFx32 targetShift;        /* 0x60 */
    VecFx32 lastSetTarget;      /* 0x6C */
    unsigned short pitch;       /* 0x78 */
    unsigned short yaw;         /* 0x7A */
    int distance;               /* 0x7C: fx32 */
    unsigned short fov;         /* 0x80: angle, 0x10000 = full turn */
    unsigned short viewYaw;     /* 0x82: yaw of the eye seen from the target */
    unsigned short viewPitch;   /* 0x84: angle between the eye direction and up */
    unsigned char pad86[2];     /* 0x86 */
    FieldCameraArea areas[4];   /* 0x88 */
    unsigned char areaCount;    /* 0xE8 */
    unsigned char areasEnabled; /* 0xE9 */
    unsigned short areaId;      /* 0xEA: loaded area record, 0xFFFF none */
    FieldCameraDelay *delay;    /* 0xEC */
    FieldCameraMotion motion;   /* 0xF0 */
} FieldCamera;

#endif
