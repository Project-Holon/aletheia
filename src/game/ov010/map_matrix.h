#ifndef GAME_OV010_MAP_MATRIX_H
#define GAME_OV010_MAP_MATRIX_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of map_matrix.c, prototypes copied from their definitions. */

struct MapMatrix;
struct MapReplace;
struct GameSystem;
struct MatrixFile;

#include "../types.h"

struct MapMatrix *MAP_MATRIX_Create(int heapId);
int MAP_MATRIX_Load(struct MapMatrix *matrix, int matrixId, u16 zoneId, int heapId);
void MAP_MATRIX_Delete(struct MapMatrix *matrix);
u16 MAP_MATRIX_GetZoneId(const struct MapMatrix *matrix, u32 x, u32 z);
int MAP_MATRIX_GetZoneIdByPos(const struct MapMatrix *matrix, int posX, int posZ);
unsigned short MAP_MATRIX_GetWidth(const struct MapMatrix *matrix);
unsigned short MAP_MATRIX_GetHeight(const struct MapMatrix *matrix);
int MAP_MATRIX_GetCount(const struct MapMatrix *matrix);
void MAP_MATRIX_SetSize(struct MapMatrix *matrix, u32 width, u32 height);
u32 *MAP_MATRIX_GetMapGrid(struct MapMatrix *matrix);
int MAP_MATRIX_IsInRange(const struct MapMatrix *matrix, int x, int z);
int MAP_MATRIX_IsInRangeByPos(const struct MapMatrix *matrix, int posX, int posZ);
void MAP_MATRIX_ApplyReplaceRecord(struct MapMatrix *matrix, struct MapReplace *replace, int heapId);
void MAP_MATRIX_ApplyReplace(struct MapMatrix *matrix, struct GameSystem *gameSystem, int heapId);
void MAP_MATRIX_SetupFromFile(struct MapMatrix *matrix, const struct MatrixFile *file, u32 matrixId, u16 zoneId);
int MAP_MATRIX_PosToBlock(int pos);
/* END mkheaders: generated region */

#endif
