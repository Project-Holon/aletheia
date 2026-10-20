#ifndef GAME_OV021_MAP_ATTR_H
#define GAME_OV021_MAP_ATTR_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of map_attr.c, prototypes copied from their definitions. */

struct FieldG3dMapper;
struct VecFx32;

#include "../types.h"

int MAP_ATTR_GetAt(struct FieldG3dMapper *g3dMapper, const struct VecFx32 *pos);
u16 MAP_ATTR_GetTerrainId(u32 attr);
u16 MAP_ATTR_GetFlags(u32 attr);
BOOL MAP_ATTR_IsPresent(u32 attr);
BOOL MAP_ATTR_IsBlocked(u32 attr);
int MAP_ATTR_IsTallGrass(int terrainId);
BOOL MAP_ATTR_IsLedgeNorth(u16 terrainId);
BOOL MAP_ATTR_IsLedgeSouth(u16 terrainId);
BOOL MAP_ATTR_IsLedgeWest(u16 terrainId);
BOOL MAP_ATTR_IsLedgeEast(u16 terrainId);
BOOL MAP_ATTR_IsNoInteract(u16 terrainId);
BOOL MAP_ATTR_IsCameraStep(u16 terrainId);
int MAP_ATTR_IsGimmickD6(int terrainId);
BOOL MAP_ATTR_IsGimmickD7(u16 terrainId);
BOOL MAP_ATTR_IsGimmickD8(u16 terrainId);
BOOL MAP_ATTR_IsGimmickE2(u16 terrainId);
BOOL MAP_ATTR_IsGimmickD9(u16 terrainId);
BOOL MAP_ATTR_IsGimmickDA(u16 terrainId);
BOOL MAP_ATTR_IsGimmickDB(u16 terrainId);
BOOL MAP_ATTR_IsGimmickDC(u16 terrainId);
BOOL MAP_ATTR_IsGimmickDD(u16 terrainId);
BOOL MAP_ATTR_IsGimmickDE(u16 terrainId);
BOOL MAP_ATTR_IsGimmickDF(u16 terrainId);
BOOL MAP_ATTR_IsGimmickE0(u16 terrainId);
BOOL MAP_ATTR_IsGimmickE1(u16 terrainId);
BOOL MAP_ATTR_IsGrassSingle(u16 terrainId);
BOOL MAP_ATTR_IsGrassDouble(u16 terrainId);
BOOL MAP_ATTR_IsTallGrassSingle(u16 terrainId);
BOOL MAP_ATTR_IsTallGrassDouble(u16 terrainId);
BOOL MAP_ATTR_IsAnySingleGrass(u16 terrainId);
BOOL MAP_ATTR_IsAnyDoubleGrass(u16 terrainId);
BOOL MAP_ATTR_IsAnyGrass(u16 terrainId);
BOOL MAP_ATTR_IsHole(u16 terrainId);
BOOL MAP_ATTR_IsLongHopEdge(int terrainId);
int MAP_ATTR_IsRippleWater(int terrainId);
BOOL MAP_ATTR_IsSplashWater(u16 terrainId);
BOOL MAP_ATTR_IsWaterfall(u16 terrainId);
BOOL MAP_ATTR_IsSnow(u16 terrainId);
BOOL MAP_ATTR_IsDeepSnow(int terrainId);
BOOL MAP_ATTR_IsSnowTile(u16 terrainId);
BOOL MAP_ATTR_IsForcedSlide(u32 terrainId);
int MAP_ATTR_IsIce(int terrainId);
BOOL MAP_ATTR_IsSplashWaterB(u16 terrainId);
BOOL MAP_ATTR_IsSandD(u16 terrainId);
BOOL MAP_ATTR_IsSandVariant(u32 terrainId);
BOOL MAP_ATTR_IsAnySand(u16 terrainId);
BOOL MAP_ATTR_IsFishableWater(u16 terrainId);
int MAP_ATTR_IsPuddle(int terrainId);
BOOL MAP_ATTR_IsMud(u16 terrainId);
BOOL MAP_ATTR_IsElectricFloor(u16 terrainId);
BOOL MAP_ATTR_IsElectricPanel(u16 terrainId);
int MAP_ATTR_IsDeepSand(int terrainId);
int MAP_ATTR_IsDeepSandB(int terrainId);
BOOL MAP_ATTR_IsSand(u16 terrainId);
BOOL MAP_ATTR_IsGrassSingleB(u16 terrainId);
BOOL MAP_ATTR_IsGrassDoubleB(u16 terrainId);
BOOL MAP_ATTR_IsMirrorFloor(u16 terrainId);
BOOL MAP_ATTR_IsNoDash(u16 terrainId);
int MAP_ATTR_IsSlopeYA(int terrainId);
int MAP_ATTR_IsSlopeYB(int terrainId);
int MAP_ATTR_IsSlopeXB(int terrainId);
int MAP_ATTR_IsSlopeXA(int terrainId);
int MAP_ATTR_IsRoughGround(int terrainId);
BOOL MAP_ATTR_IsGrassSingleC(u16 terrainId);
BOOL MAP_ATTR_IsGrassDoubleC(u16 terrainId);
int MAP_ATTR_GetEncounterEffectKind(u32 attr);
u8 MAP_ATTR_GetBattleBackground(u16 terrainId);
int MAP_ATTR_IsHopTransition(unsigned long fromAttr, unsigned long toAttr);
/* END mkheaders: generated region */

#endif
