/*
 * file:     field_nogrid_mapper.c
 * unit:     yes
 * function: FIELD_NOGRID_MAPPER_Create, FIELD_NOGRID_MAPPER_Delete, FIELD_NOGRID_MAPPER_SetActive, FIELD_NOGRID_MAPPER_LoadData, FIELD_NOGRID_MAPPER_LoadDataFromArc, FIELD_NOGRID_MAPPER_ReleaseData, FIELD_NOGRID_MAPPER_Main, FIELD_NOGRID_MAPPER_UpdateCameraForced, FIELD_NOGRID_MAPPER_CreateRailWork, FIELD_NOGRID_MAPPER_DeleteRailWork, FIELD_NOGRID_MAPPER_BindCameraWork, FIELD_NOGRID_MAPPER_UnbindCameraWork, FIELD_NOGRID_MAPPER_GetAttribute, FIELD_NOGRID_MAPPER_SetCameraLocation, FIELD_NOGRID_MAPPER_SetLineEnable, FIELD_NOGRID_MAPPER_CalcZoneRailLocation, FIELD_NOGRID_MAPPER_GetRailMan
 * address:  0x021BB1F4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   GFL_HEAP_Free  0x020307B0  arm
 *   GFL_HEAP_Alloc  0x02030734  arm
 *   FIELD_RAIL_Create  0x021B7884  thumb  ov021
 *   FIELD_RAIL_LOADER_Create  0x0219EF44  thumb  ov021
 *   d_021DE2D0     0x021DE2D0  data  a4
 *   FIELD_RAIL_Delete  0x021B791C  thumb  ov021
 *   FIELD_RAIL_LOADER_Delete  0x0219EF6C  thumb  ov021
 *   FLD_SCENEAREA_SetEnabled  0x021AB75C  thumb  ov021
 *   ARC_TOOL_GetArchiveFileCount  0x02049030  arm
 *   FIELD_RAIL_LOADER_Load  0x0219EF7C  thumb  ov021
 *   FIELD_RAIL_LOADER_GetSetting  0x0219F018  thumb  ov021
 *   FIELD_RAIL_SetSetting  0x021B7934  thumb  ov021
 *   FLD_SCENEAREA_LOADER_Load  0x021AB840  thumb  ov021
 *   FLD_SCENEAREA_LOADER_GetRecs  0x021AB880  thumb  ov021
 *   FLD_SCENEAREA_LOADER_GetRecCount  0x021AB884  thumb  ov021
 *   FLD_SCENEAREA_LOADER_GetCallbacks  0x021AB888  thumb  ov021
 *   FLD_SCENEAREA_SetData  0x021AB634  thumb  ov021
 *   ARC_TOOL_GetMemberSize  0x020490A8  arm
 *   ARC_TOOL_ReadMember  0x02048F4C  arm
 *   FLD_SCENEAREA_ClearData  0x021AB650  thumb  ov021
 *   FIELD_RAIL_ClearSetting  0x021B7954  thumb  ov021
 *   FIELD_RAIL_LOADER_Unload  0x0219EFFC  thumb  ov021
 *   FLD_SCENEAREA_LOADER_Unload  0x021AB868  thumb  ov021
 *   FIELD_RAIL_Update  0x021B79E4  thumb  ov021
 *   FIELD_RAIL_UpdateCamera  0x021B79F0  thumb  ov021
 *   FIELD_RAIL_ActivateFreeWork  0x021B7970  thumb
 *   FIELD_RAIL_ReleaseWork  0x021B79AC  thumb
 *   FIELD_RAIL_SetFocusWork  0x021B79C4  thumb  ov021
 *   FIELD_RAIL_ClearFocusWork  0x021B79CC  thumb  ov021
 *   FIELD_RAIL_UpdateCameraAtLocation  0x021B7D68  thumb ov021
 *   FIELD_RAIL_SetLineEnable  0x021B7C04  thumb  ov021
 *   ZONEDATA_GetSpecialKind  0x02013C9C  thumb
 *   FIELD_RAIL_MakeLineLocation  0x021B7C58  thumb  ov021
 *   RAIL_ATTR_Create  0x021BB088  thumb  ov021
 *   RAIL_ATTR_Delete  0x021BB0A4  thumb  ov021
 *   RAIL_ATTR_Load  0x021BB0B4  thumb  ov021
 *   RAIL_ATTR_Release  0x021BB11C  thumb  ov021
 *   RAIL_ATTR_GetAttribute  0x021BB13C  thumb  ov021
 */
#include "fldmmdl_rail_types.h"

#include "../types.h"

#define RAIL_ARC_ID 0x4f            /* rail data, then rail attribute data (second half) */
#define NOGRID_MAPPER_RES_ARC_ID 0x6d
#define NOGRID_MAPPER_RES_NONE 0xFFFF
#define RAIL_WORK_MAX 0x30

typedef struct RailManager RailManager;          /* field_rail.c */
typedef struct FieldRailLoader FieldRailLoader;  /* field_rail_loader.c */
typedef struct FieldRailSetting FieldRailSetting;
typedef struct RailAttr RailAttr;                /* rail_attr.c */
typedef struct RailWork RailWork;
typedef struct FldSceneArea FldSceneArea;        /* fld_scenearea.c */
typedef struct FldSceneAreaLoader FldSceneAreaLoader;

/* Rail (no-grid) map handler of the field map (0x18 bytes, line 0x47
 * allocation): the rail manager, its loader, the rail attributes and the
 * camera scene areas. */
typedef struct FieldNogridMapper {
    RailManager *railMan;                /* 0x00 */
    FieldRailLoader *railLoader;         /* 0x04 */
    RailAttr *railAttr;                  /* 0x08 */
    FldSceneArea *sceneArea;             /* 0x0C */
    FldSceneAreaLoader *sceneAreaLoader; /* 0x10 */
    int inactive;                        /* 0x14: nonzero stops the rail camera update */
} FieldNogridMapper;

/* One record of archive NOGRID_MAPPER_RES_ARC_ID (4 bytes). */
typedef struct FieldNogridMapperRes {
    u16 railDataId;        /* rail data and rail attribute file, or NOGRID_MAPPER_RES_NONE */
    u16 sceneAreaDataId;   /* scene area file, or NOGRID_MAPPER_RES_NONE */
} FieldNogridMapperRes;

extern void *GFL_HEAP_Alloc(unsigned int heapId, unsigned int size, int clear, const char *file, u16 line);
extern u32 GFL_HEAP_Free(void *p);
struct FieldCamera;
extern RailManager *FIELD_RAIL_Create(u16 heapId, u32 workMax, struct FieldCamera *fieldCamera);
extern FieldRailLoader *FIELD_RAIL_LOADER_Create(u32 heapId);
extern RailAttr *RAIL_ATTR_Create(int heapId);
extern void RAIL_ATTR_Delete(RailAttr *attr);
extern void FIELD_RAIL_Delete(RailManager *railMan);
extern void FIELD_RAIL_LOADER_Delete(FieldRailLoader *loader);
extern void FLD_SCENEAREA_SetEnabled(FldSceneArea *sceneArea, u32 active);
extern u32 ARC_TOOL_GetArchiveFileCount(u32 arcId);
extern void FIELD_RAIL_LOADER_Load(FieldRailLoader *loader, u32 dataId, u32 heapId);
extern FieldRailSetting *FIELD_RAIL_LOADER_GetSetting(FieldRailLoader *loader);
extern void FIELD_RAIL_SetSetting(RailManager *railMan, FieldRailSetting *setting);
extern void RAIL_ATTR_Load(RailAttr *attr, u32 dataId, u32 heapId);
extern void FLD_SCENEAREA_LOADER_Load(FldSceneAreaLoader *loader, int arcIndex, u32 dataId, u16 heapId);
extern u32 FLD_SCENEAREA_LOADER_GetRecs(FldSceneAreaLoader *loader);
extern u32 FLD_SCENEAREA_LOADER_GetRecCount(FldSceneAreaLoader *loader);
extern u32 FLD_SCENEAREA_LOADER_GetCallbacks(FldSceneAreaLoader *loader);
extern void FLD_SCENEAREA_SetData(FldSceneArea *sceneArea, u32 data, u32 count, u32 funcTable);
extern u32 ARC_TOOL_GetMemberSize(u32 arcId, u32 dataId);
extern void ARC_TOOL_ReadMember(void *dst, u32 arcId, u32 dataId);
extern void FLD_SCENEAREA_ClearData(FldSceneArea *sceneArea);
extern u32 FIELD_RAIL_ClearSetting(RailManager *railMan);
extern void FIELD_RAIL_LOADER_Unload(FieldRailLoader *loader);
extern void FLD_SCENEAREA_LOADER_Unload(FldSceneAreaLoader *loader);
extern void RAIL_ATTR_Release(RailAttr *attr);
extern void FIELD_RAIL_Update(RailManager *railMan);
extern int FIELD_RAIL_UpdateCamera(RailManager *railMan, int force);
extern void FIELD_RAIL_ActivateFreeWork(RailManager *railMan);
extern int FIELD_RAIL_ReleaseWork(RailManager *railMan, RailWork *work);
extern void FIELD_RAIL_SetFocusWork(RailManager *railMan, RailWork *work);
extern void FIELD_RAIL_ClearFocusWork(RailManager *railMan);
extern int RAIL_ATTR_GetAttribute(RailAttr *attr, const RailLocation *location);
extern void FIELD_RAIL_UpdateCameraAtLocation(RailManager *railMan, const RailLocation *location);
extern void FIELD_RAIL_SetLineEnable(RailManager *railMan, int lineIndex, int enable);
extern int ZONEDATA_GetSpecialKind(u16 zoneId);
extern void FIELD_RAIL_MakeLineLocation(struct RailManager *manager, FieldRailSetting *setting, u16 railIndex, u16 lineGrid, u16 widthPos, RailLocation *outLocation);

FieldNogridMapper *FIELD_NOGRID_MAPPER_Create(u32 heapId, u32 fieldCamera, FldSceneArea *sceneArea, FldSceneAreaLoader *sceneAreaLoader);
int FIELD_NOGRID_MAPPER_Delete(FieldNogridMapper *mapper);
void FIELD_NOGRID_MAPPER_SetActive(FieldNogridMapper *mapper, int active);
void FIELD_NOGRID_MAPPER_LoadData(FieldNogridMapper *mapper, const FieldNogridMapperRes *res, u32 heapId);
void FIELD_NOGRID_MAPPER_LoadDataFromArc(FieldNogridMapper *mapper, u32 resId, u32 heapId);
void FIELD_NOGRID_MAPPER_ReleaseData(FieldNogridMapper *mapper);
void FIELD_NOGRID_MAPPER_Main(FieldNogridMapper *mapper);
int FIELD_NOGRID_MAPPER_UpdateCameraForced(FieldNogridMapper *mapper);
void FIELD_NOGRID_MAPPER_CreateRailWork(FieldNogridMapper *mapper);
void FIELD_NOGRID_MAPPER_DeleteRailWork(FieldNogridMapper *mapper, RailWork *work);
void FIELD_NOGRID_MAPPER_BindCameraWork(FieldNogridMapper *mapper, RailWork *work);
void FIELD_NOGRID_MAPPER_UnbindCameraWork(FieldNogridMapper *mapper);
u32 FIELD_NOGRID_MAPPER_GetAttribute(FieldNogridMapper *mapper, const RailLocation *location);
void FIELD_NOGRID_MAPPER_SetCameraLocation(FieldNogridMapper *mapper, const RailLocation *location);
void FIELD_NOGRID_MAPPER_SetLineEnable(FieldNogridMapper *mapper, int lineIndex, int enable);
void FIELD_NOGRID_MAPPER_CalcZoneRailLocation(FieldNogridMapper *mapper, u32 zoneId, u16 railIndex, u16 lineGrid, u16 widthPos, RailLocation *outLocation, u16 heapId);
RailManager *FIELD_NOGRID_MAPPER_GetRailMan(FieldNogridMapper *mapper);

extern int d_021DE2D0;

FieldNogridMapper *FIELD_NOGRID_MAPPER_Create(u32 heapId, u32 fieldCamera, FldSceneArea *sceneArea, FldSceneAreaLoader *sceneAreaLoader)
{
    FieldNogridMapper *mapper = GFL_HEAP_Alloc((u16)heapId, sizeof(FieldNogridMapper), 1, (const char *)&d_021DE2D0, 0x47);

    mapper->railMan = FIELD_RAIL_Create(heapId, RAIL_WORK_MAX, (struct FieldCamera *)fieldCamera);
    mapper->railLoader = FIELD_RAIL_LOADER_Create(heapId);
    mapper->sceneArea = sceneArea;
    mapper->sceneAreaLoader = sceneAreaLoader;
    mapper->railAttr = RAIL_ATTR_Create(heapId);
    return mapper;
}

int FIELD_NOGRID_MAPPER_Delete(FieldNogridMapper *mapper)
{
    RAIL_ATTR_Delete(mapper->railAttr);
    FIELD_RAIL_Delete(mapper->railMan);
    FIELD_RAIL_LOADER_Delete(mapper->railLoader);
    return GFL_HEAP_Free(mapper);
}

void FIELD_NOGRID_MAPPER_SetActive(FieldNogridMapper *mapper, int active)
{
    if (active != 0) {
        mapper->inactive = 0;
    } else {
        mapper->inactive = 1;
    }
    FLD_SCENEAREA_SetEnabled(mapper->sceneArea, active);
}

void FIELD_NOGRID_MAPPER_LoadData(FieldNogridMapper *mapper, const FieldNogridMapperRes *res, u32 heapId)
{
    FIELD_NOGRID_MAPPER_ReleaseData(mapper);
    if (res->railDataId != NOGRID_MAPPER_RES_NONE) {
        u32 railFileCount = ARC_TOOL_GetArchiveFileCount(RAIL_ARC_ID);
        FIELD_RAIL_LOADER_Load(mapper->railLoader, res->railDataId, heapId);
        FIELD_RAIL_SetSetting(mapper->railMan, FIELD_RAIL_LOADER_GetSetting(mapper->railLoader));
        RAIL_ATTR_Load(mapper->railAttr, res->railDataId + (railFileCount >> 1), heapId);
    }
    if (res->sceneAreaDataId != NOGRID_MAPPER_RES_NONE) {
        u32 data, count, funcTable;
        FLD_SCENEAREA_LOADER_Load(mapper->sceneAreaLoader, 0, res->sceneAreaDataId, heapId);
        data = FLD_SCENEAREA_LOADER_GetRecs(mapper->sceneAreaLoader);
        count = FLD_SCENEAREA_LOADER_GetRecCount(mapper->sceneAreaLoader);
        funcTable = FLD_SCENEAREA_LOADER_GetCallbacks(mapper->sceneAreaLoader);
        FLD_SCENEAREA_SetData(mapper->sceneArea, data, count, funcTable);
    }
}

void FIELD_NOGRID_MAPPER_LoadDataFromArc(FieldNogridMapper *mapper, u32 resId, u32 heapId)
{
    int size = ARC_TOOL_GetMemberSize(NOGRID_MAPPER_RES_ARC_ID, resId);
    FieldNogridMapperRes *res = GFL_HEAP_Alloc((u16)(((u16)heapId & 0x7FFF) | 0x8000), size, 1, (const char *)&d_021DE2D0, 0xdd);
    ARC_TOOL_ReadMember(res, NOGRID_MAPPER_RES_ARC_ID, resId);
    FIELD_NOGRID_MAPPER_LoadData(mapper, res, heapId);
    GFL_HEAP_Free(res);
}

void FIELD_NOGRID_MAPPER_ReleaseData(FieldNogridMapper *mapper)
{
    FLD_SCENEAREA_ClearData(mapper->sceneArea);
    FIELD_RAIL_ClearSetting(mapper->railMan);
    FIELD_RAIL_LOADER_Unload(mapper->railLoader);
    FLD_SCENEAREA_LOADER_Unload(mapper->sceneAreaLoader);
    RAIL_ATTR_Release(mapper->railAttr);
}

void FIELD_NOGRID_MAPPER_Main(FieldNogridMapper *mapper)
{
    FIELD_RAIL_Update(mapper->railMan);
    if (mapper->inactive == 0) {
        FIELD_RAIL_UpdateCamera(mapper->railMan, 0);
    }
}

int FIELD_NOGRID_MAPPER_UpdateCameraForced(FieldNogridMapper *mapper) { return FIELD_RAIL_UpdateCamera(mapper->railMan, 1); }

void FIELD_NOGRID_MAPPER_CreateRailWork(FieldNogridMapper *mapper)
{
    FIELD_RAIL_ActivateFreeWork(mapper->railMan);
}

void FIELD_NOGRID_MAPPER_DeleteRailWork(FieldNogridMapper *mapper, RailWork *work)
{
    FIELD_RAIL_ReleaseWork(mapper->railMan, work);
}

void FIELD_NOGRID_MAPPER_BindCameraWork(FieldNogridMapper *mapper, RailWork *work)
{
    FIELD_RAIL_SetFocusWork(mapper->railMan, work);
}

void FIELD_NOGRID_MAPPER_UnbindCameraWork(FieldNogridMapper *mapper)
{
    FIELD_RAIL_ClearFocusWork(mapper->railMan);
}

u32 FIELD_NOGRID_MAPPER_GetAttribute(FieldNogridMapper *mapper, const RailLocation *location)
{
    return RAIL_ATTR_GetAttribute(mapper->railAttr, location);
}

void FIELD_NOGRID_MAPPER_SetCameraLocation(FieldNogridMapper *mapper, const RailLocation *location) { FIELD_RAIL_UpdateCameraAtLocation(mapper->railMan, location); }

void FIELD_NOGRID_MAPPER_SetLineEnable(FieldNogridMapper *mapper, int lineIndex, int enable)
{
    FIELD_RAIL_SetLineEnable(mapper->railMan, lineIndex, enable);
}

void FIELD_NOGRID_MAPPER_CalcZoneRailLocation(FieldNogridMapper *mapper, u32 zoneId, u16 railIndex, u16 lineGrid, u16 widthPos, RailLocation *outLocation, u16 heapId)
{
    u16 tempHeapId;
    FieldNogridMapperRes *res;
    FieldRailLoader *loader;
    tempHeapId = (heapId & 0x7FFF) | 0x8000;
    res = GFL_HEAP_Alloc(tempHeapId, ARC_TOOL_GetMemberSize(NOGRID_MAPPER_RES_ARC_ID, ZONEDATA_GetSpecialKind(zoneId)), 1, (const char *)&d_021DE2D0, 0x1c9);
    ARC_TOOL_ReadMember(res, NOGRID_MAPPER_RES_ARC_ID, ZONEDATA_GetSpecialKind(zoneId));
    loader = FIELD_RAIL_LOADER_Create(tempHeapId);
    FIELD_RAIL_LOADER_Load(loader, res->railDataId, tempHeapId);
    FIELD_RAIL_MakeLineLocation(mapper->railMan, FIELD_RAIL_LOADER_GetSetting(loader), railIndex, lineGrid, widthPos, outLocation);
    FIELD_RAIL_LOADER_Delete(loader);
    GFL_HEAP_Free(res);
}

RailManager *FIELD_NOGRID_MAPPER_GetRailMan(FieldNogridMapper *mapper)
{
    return mapper->railMan;
}
