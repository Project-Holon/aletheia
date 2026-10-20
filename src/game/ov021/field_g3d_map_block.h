#ifndef GAME_OV021_FIELD_G3D_MAP_BLOCK_H
#define GAME_OV021_FIELD_G3D_MAP_BLOCK_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of field_g3d_map_block.c, prototypes copied from their definitions. */

struct FieldG3dMapper;
struct FieldG3dMapBlockHeader;
struct CollisionPlane;
typedef struct FieldG3dMapBlockHeader FieldG3dMapBlockHeader;
typedef struct CollisionPlane CollisionPlane;

#include "../ov010/field_g3d_map_types.h"
#include "../sdk_fx.h"
#include "../types.h"

int FIELD_G3D_MAP_BLOCK_UpdateOnePlane(FieldG3dMap *map, struct FieldG3dMapper *mapper);
void FIELD_G3D_MAP_BLOCK_QueryOnePlane(FieldG3dMapHitList *hitList, const FieldG3dMapBlockHeader *header, VecFx32 *localPos, int gridSize, int height);
int FIELD_G3D_MAP_BLOCK_UpdateTwoPlane(FieldG3dMap *map, struct FieldG3dMapper *mapper);
void FIELD_G3D_MAP_BLOCK_QueryTwoPlane(FieldG3dMapHitList *hitList, const FieldG3dMapBlockHeader *header, VecFx32 *localPos, int gridSize, int height);
void FIELD_G3D_MAP_BLOCK_QueryOnePlaneBuffered(FieldG3dMapHitList *hitList, const FieldG3dMapBlockHeader *header, VecFx32 *localPos, int gridSize, int height);
int FIELD_G3D_MAP_BLOCK_UpdateNoPlane(FieldG3dMap *map, struct FieldG3dMapper *mapper);
void FIELD_G3D_MAP_BLOCK_QueryClear(FieldG3dMapHitList *hitList);
int FIELD_G3D_MAP_BLOCK_UpdateWfbc(FieldG3dMap *map, struct FieldG3dMapper *mapper);
void FIELD_G3D_MAP_BLOCK_GetCollisionPlane(CollisionPlane *out, const int *mapData, VecFx32 *pos, fx32 mapSize, fx32 baseHeight);
/* END mkheaders: generated region */

#endif
