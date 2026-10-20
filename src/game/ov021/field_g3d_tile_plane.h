#ifndef GAME_OV021_FIELD_G3D_TILE_PLANE_H
#define GAME_OV021_FIELD_G3D_TILE_PLANE_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of field_g3d_tile_plane.c, prototypes copied from their definitions. */

struct TileSurface;
struct PackedTileMap;
typedef struct TileSurface TileSurface;
typedef struct PackedTileMap PackedTileMap;

#include "../sdk_fx.h"
#include "../types.h"

void FIELD_G3D_MAPPER_GetTilePlane(TileSurface *out, int idx, PackedTileMap *map, VecFx32 *pos, fx32 size, fx32 base);
/* END mkheaders: generated region */

#endif
