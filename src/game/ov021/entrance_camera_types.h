#ifndef ALETHEIA_OV021_ENTRANCE_CAMERA_TYPES_H
#define ALETHEIA_OV021_ENTRANCE_CAMERA_TYPES_H

/*
 * Camera movement of the entrance (door, stairs, cave) events, entrance_camera.c.
 * The camera is moved by a field camera anime (FIELD_CAMERA_ANIME_*).
 */

#include "fieldmap_types.h"
#include "field_camera_types.h"

struct FieldCamera;
struct FieldCameraAnime;

/* Which side of the map change the camera serves. */
enum {
    ENTRANCE_CAMERA_PHASE_LEAVE,    /* the player walks into the entrance of the old map */
    ENTRANCE_CAMERA_PHASE_ARRIVE    /* the player comes out of the entrance of the new map */
};

/* Player facing values read by the default camera setups. */
enum {
    ENTRANCE_CAMERA_DIR_UP,
    ENTRANCE_CAMERA_DIR_DOWN,
    ENTRANCE_CAMERA_DIR_LEFT,
    ENTRANCE_CAMERA_DIR_RIGHT
};

/* The entrance types from this value on have a camera record in archive 0xB3. */
#define ENTRANCE_CAMERA_FIRST_RECORD_TYPE 7
#define ENTRANCE_CAMERA_RECORD_ARCHIVE 0xB3

/* What the caller asks of the camera (0x0C bytes). */
typedef struct EntranceCameraRequest {
    int entranceType;       /* 0x00: exit type of the entrance */
    int phase;              /* 0x04: ENTRANCE_CAMERA_PHASE_* */
    int usePlayerPos;       /* 0x08: 0 aims at the entrance position, else at the player */
} EntranceCameraRequest;

/*
 * One entry of archive 0xB3 (0x40 bytes), the camera setting of an entrance
 * type from ENTRANCE_CAMERA_FIRST_RECORD_TYPE on. Angles, distance and
 * vectors are whole numbers; the setups shift them left by 12 into fx32.
 */
typedef struct EntranceCameraRecord {
    int entranceType;       /* 0x00 */
    int pitch;              /* 0x04 */
    int yaw;                /* 0x08 */
    int distance;           /* 0x0C */
    int useFixedTarget;     /* 0x10: aim at target below, else at the entrance or player position */
    VecFx32 target;         /* 0x14 */
    VecFx32 shift;          /* 0x20 */
    int frames;             /* 0x2C */
    int leaveActive;        /* 0x30 */
    int arriveActive;       /* 0x34 */
    int detachTarget;       /* 0x38 */
    int stopTrace;          /* 0x3C */
} EntranceCameraRecord;

/* The entrance camera work (0x70 bytes, heap tag 0x12A). */
typedef struct EntranceCamera {
    FieldMap *fieldMap;                 /* 0x00 */
    struct FieldCamera *camera;         /* 0x04 */
    FieldCameraAnimeData animData;      /* 0x08: the move handed to the camera anime */
    struct FieldCameraAnime *anime;     /* 0x54 */
    EntranceCameraRequest request;      /* 0x58 */
    int isSetUp;                        /* 0x64 */
    int leaveActive;                    /* 0x68: the leave move runs */
    int arriveActive;                   /* 0x6C: the arrive move runs */
} EntranceCamera;

#endif
