#ifndef SHINKA_DEMO_GRAPHIC_SHARED_TYPES_H
#define SHINKA_DEMO_GRAPHIC_SHARED_TYPES_H

struct ShinkaDemoGraphicNode;

struct Light;

#include "../types.h"

typedef struct ShinkaDemoGraphicNode {
    u16 id;
    u16 pad02;
    fx32 tx, ty, tz;
    fx32 sx, sy, sz;
    u8 mtx[0x24];
    u8 pad40[4];
} ShinkaDemoGraphicNode;

struct Unit;
struct G3dCamera;
struct TcbTask;

/* The actor system handle of the evolution screen (one CLACT unit). */
typedef struct ShinkaClact {
    struct Unit *unit;
} ShinkaClact;

/* The 3D system handle of the evolution screen (one camera). */
typedef struct ShinkaG3d {
    struct G3dCamera *camera;
} ShinkaG3d;

/* The graphic system of the evolution screen, 16 bytes. */
typedef struct ShinkaGraphic {
    u32 mainBg;
    ShinkaClact clact;
    ShinkaG3d g3d;
    struct TcbTask *vblank;
} ShinkaGraphic;

#endif
