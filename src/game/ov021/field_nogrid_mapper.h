#ifndef GAME_OV021_FIELD_NOGRID_MAPPER_H
#define GAME_OV021_FIELD_NOGRID_MAPPER_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of field_nogrid_mapper.c, prototypes copied from their definitions. */

struct FieldNogridMapper;
struct FieldNogridMapperRes;
typedef struct FieldNogridMapper FieldNogridMapper;
typedef struct FieldNogridMapperRes FieldNogridMapperRes;

#include "../types.h"
#include "../ov021/fld_scenearea_types.h"
#include "../ov021/fld_scenearea_types.h"
#include "../ov021/field_rail_types.h"
#include "../arm9/zonedata_types.h"

FieldNogridMapper *FIELD_NOGRID_MAPPER_Create(u32 heapId, u32 fieldCamera, FldSceneArea *sceneArea, FldSceneAreaLoader *sceneAreaLoader);
int FIELD_NOGRID_MAPPER_Delete(FieldNogridMapper *mapper);
void FIELD_NOGRID_MAPPER_SetActive(FieldNogridMapper *mapper, int active);
void FIELD_NOGRID_MAPPER_LoadData(FieldNogridMapper *mapper, const FieldNogridMapperRes *res, u32 heapId);
void FIELD_NOGRID_MAPPER_LoadDataFromArc(FieldNogridMapper *mapper, u32 resId, u32 heapId);
void FIELD_NOGRID_MAPPER_ReleaseData(FieldNogridMapper *mapper);
void FIELD_NOGRID_MAPPER_Main(FieldNogridMapper *mapper);
int FIELD_NOGRID_MAPPER_UpdateCameraForced(FieldNogridMapper *mapper);
RailWork *FIELD_NOGRID_MAPPER_CreateRailWork(FieldNogridMapper *mapper);
void FIELD_NOGRID_MAPPER_DeleteRailWork(FieldNogridMapper *mapper, RailWork *work);
void FIELD_NOGRID_MAPPER_BindCameraWork(FieldNogridMapper *mapper, RailWork *work);
void FIELD_NOGRID_MAPPER_UnbindCameraWork(FieldNogridMapper *mapper);
u32 FIELD_NOGRID_MAPPER_GetAttribute(FieldNogridMapper *mapper, const RailLocation *location);
void FIELD_NOGRID_MAPPER_SetCameraLocation(FieldNogridMapper *mapper, const RailLocation *location);
void FIELD_NOGRID_MAPPER_SetLineEnable(FieldNogridMapper *mapper, int lineIndex, int enable);
void FIELD_NOGRID_MAPPER_CalcZoneRailLocation(FieldNogridMapper *mapper, u32 zoneId, u16 railIndex, u16 lineGrid, u16 widthPos, RailLocation *outLocation, u16 heapId);
RailManager *FIELD_NOGRID_MAPPER_GetRailMan(FieldNogridMapper *mapper);
/* END mkheaders: generated region */

#endif
