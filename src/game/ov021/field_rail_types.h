#ifndef GAME_OV021_FIELD_RAIL_TYPES_H
#define GAME_OV021_FIELD_RAIL_TYPES_H

#include "fldmmdl_rail_types.h"

/*
 * Field rail system (field_rail.c). The rails are a graph: points (nodes),
 * lines between two points, and per-line shape entries. A rail manager owns an
 * array of rail works. Each work stands on one point or one line and moves
 * along the lines in steps of one grid cell (16 units). The data comes from a
 * rail file (field_rail_loader.c) that the manager copies as its setting.
 */

typedef unsigned int  u32;
typedef signed char   s8;
typedef signed int    s32;
typedef long long     s64;
typedef int           fx32;
typedef long long     fx64;

typedef struct { fx32 x, y, z; } VecFx32;

#define RAIL_NONE_INDEX 0xFFFF      /* unused point, line, camera or shape slot */

struct RailWork;
struct RailManager;
struct FieldCamera;

/* Called with the manager when the focused work stands on a point or line that
 * has a camera entry (FIELD_RAIL_UpdateCamera, FIELD_RAIL_UpdateCameraAtLocation). */
typedef void (*RailCameraFunc)(struct RailManager *manager);

/* Position of a work on a line that has a shape entry (FIELD_RAIL_WORK_GetSpotPos). */
typedef void (*RailLinePosFunc)(struct RailWork *work, VecFx32 *outPos);

/* Hit test of a segment against one line: fills the location and the position
 * of the hit, returns 1 on a hit (FIELD_RAIL_FindSegmentLocation). */
typedef int (*RailLineFunc)(int lineIndex, struct RailManager *manager, const VecFx32 *segmentHit,
                            RailLocation *outLocation, VecFx32 *outPos);

/* A node of the rail graph (0x70 bytes). */
typedef struct RailPoint {
    u32 lineIndex[4];       /* 0x00 lines that leave this point, RAIL_NONE_INDEX if unused */
    u32 lineKey[4];         /* 0x10 move key to take for each of those lines */
    s32 lineWidth[4];       /* 0x20 width of the line at this point */
    VecFx32 pos;            /* 0x30 */
    u32 cameraIndex;        /* 0x3C entry of the camera table, RAIL_NONE_INDEX for none */
    u8 reserved40[0x30];    /* 0x40 not read by the code of field_rail.c */
} RailPoint;

/* An edge between two points (0x48 bytes). */
typedef struct RailLine {
    u32 startPoint;         /* 0x00 */
    u32 endPoint;           /* 0x04 */
    u32 key;                /* 0x08 move key from the start to the end point */
    u32 linePosIndex;       /* 0x0C entry of the line position table (the line shape) */
    u32 cameraIndex;        /* 0x10 entry of the camera table, RAIL_NONE_INDEX for none */
    u32 length;             /* 0x14 length in grid cells */
    u8 reserved18[0x30];    /* 0x18 not read by the code of field_rail.c */
} RailLine;

/* A work stands on a point or a line, by its mode. */
typedef union RailSpot {
    RailPoint point;
    RailLine line;
} RailSpot;

/* Camera table entry (0x24 bytes): picks the camera function. */
typedef struct RailCamera {
    u32 funcIndex;          /* 0x00 index into the camera function table */
    s32 param[8];           /* 0x04 camera function parameters (angle, distance, position) */
} RailCamera;

/* Line position table entry (0x24 bytes): picks the shape functions of a line. */
typedef struct RailLinePos {
    u32 funcIndex;          /* 0x00 index into the line position and line function tables */
    VecFx32 pos;            /* 0x04 anchor of the shape (centre of an arc) */
    u8 reserved10[0x14];    /* 0x10 */
} RailLinePos;

/* The loaded rail data: counts, tables and function tables (0x30 bytes). It is
 * the manager's copy of the setting the loader filled in. */
typedef struct FieldRailSetting {
    u16 pointCount;                 /* 0x00 */
    volatile u16 lineCount;         /* 0x02 volatile: the original re-reads it on every loop pass */
    u16 cameraCount;                /* 0x04 */
    u16 linePosCount;               /* 0x06 */
    u16 cameraFuncCount;            /* 0x08 */
    u16 linePosFuncCount;           /* 0x0A */
    u16 lineFuncCount;              /* 0x0C */
    u16 reserved0E;                 /* 0x0E */
    RailPoint *points;              /* 0x10 */
    RailLine *lines;                /* 0x14 */
    RailCamera *cameras;            /* 0x18 */
    RailLinePos *linePoses;         /* 0x1C */
    RailCameraFunc *cameraFuncs;    /* 0x20 */
    RailLinePosFunc *linePosFuncs;  /* 0x24 */
    RailLineFunc *lineFuncs;        /* 0x28 */
    int unitScale;                  /* 0x2C word the data header points at (entryInfo of the loader) */
} FieldRailSetting;

/* Lines that are switched off (closed), by index. */
typedef struct RailClosedLines {
    u16 lineIndex[0x12];            /* RAIL_NONE_INDEX for a free slot */
} RailClosedLines;

typedef enum RailWorkMode {
    RAIL_WORK_ON_POINT = 0,
    RAIL_WORK_ON_LINE = 1,
    RAIL_WORK_UNSET = 2
} RailWorkMode;

/* One walker on the rails (0x7C bytes): the player, a field model or the probe. */
typedef struct RailWork {
    u16 mode;                       /* 0x00 RailWorkMode */
    u16 inUse;                      /* 0x02 slot taken */
    RailSpot *spot;                 /* 0x04 point or line the work stands on */
    u16 located;                    /* 0x08 a location was set */
    u16 reserved0A;                 /* 0x0A */
    int lineOffset;                 /* 0x0C position along the line, 16 per grid cell */
    int lineEnd;                    /* 0x10 end of the line section */
    int widthOffset;                /* 0x14 position across the line, 0 at the centre */
    int widthLimit;                 /* 0x18 how far the work may stand off the centre */
    int unitScale;                  /* 0x1C copy of FieldRailSetting.unitScale */
    int moveKey;                    /* 0x20 key of the line the work follows */
    FieldRailSetting *setting;      /* 0x24 */
    RailClosedLines *closedLines;   /* 0x28 */
    u8 moving;                      /* 0x2C a step is in progress */
    s8 stepProgress;                /* 0x2D units done of the 16 of a step */
    u16 stepKey;                    /* 0x2E key of the step in progress */
    u16 speedIndex;                 /* 0x30 index into the step size table */
    u8 lastKey;                     /* 0x32 key the last step took */
    u8 lastSpeedIndex;              /* 0x33 */
    u8 stepped;                     /* 0x34 the last update moved the work */
    u8 reserved35[3];               /* 0x35 */
    VecFx32 pos;                    /* 0x38 world position */
    VecFx32 prevPos;                /* 0x44 position at the start of the step */
    VecFx32 queryPos;               /* 0x50 position of the cached query */
    RailLocation location;          /* 0x5C */
    RailLocation prevLocation;      /* 0x64 */
    RailLocation queryLocation;     /* 0x6C location of the cached query */
    u8 queryValid;                  /* 0x74 */
    u8 queryResult;                 /* 0x75 */
    u8 queryKey;                    /* 0x76 */
    u8 reserved77;                  /* 0x77 */
    struct RailManager *manager;    /* 0x78 */
} RailWork;

/* The rail manager (0x74 bytes). */
typedef struct RailManager {
    u16 heapId;                     /* 0x00 */
    u16 dataLoaded;                 /* 0x02 a setting is in place */
    u16 running;                    /* 0x04 */
    u8 reserved06[2];               /* 0x06 */
    RailWork *works;                /* 0x08 */
    int workCount;                  /* 0x0C */
    struct FieldCamera *fieldCamera; /* 0x10 the field camera the rail camera functions drive */
    RailWork *focusWork;            /* 0x14 the work the rail camera follows */
    u32 forceCamera;                /* 0x18 run the camera function even if the work did not move */
    RailWork *probeWork;            /* 0x1C spare work for location queries */
    FieldRailSetting setting;       /* 0x20 */
    RailClosedLines closedLines;    /* 0x50 */
} RailManager;

/* Default entries the table lookups return for an index past the end. */
extern RailCamera gRailDefaultCamera;
extern RailLinePos gRailDefaultLinePos;

#endif
