/*
 * file:     field_nogrid_mapper.c
 * unit:     yes
 * function: func_021BB1F4, func_021BB240, func_021BB260, func_021BB278, func_021BB2F8, func_021BB348, func_021BB36C, func_021BB388, func_021BB394, func_021BB3A0, func_021BB3AC, func_021BB3B8, func_021BB3C4, func_021BB3D0, func_021BB3DC, func_021BB3E8, func_021BB480
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
 *   func_020307B0  0x020307B0  arm
 *   func_02030734  0x02030734  arm
 *   func_021B7884  0x021B7884  thumb  ov021
 *   func_0219EF44  0x0219EF44  thumb  ov021
 *   d_021DE2D0     0x021DE2D0  data  a4
 *   func_021B791C  0x021B791C  thumb  ov021
 *   func_0219EF6C  0x0219EF6C  thumb  ov021
 *   func_021AB75C  0x021AB75C  thumb  ov021
 *   func_02049030  0x02049030  arm
 *   func_0219EF7C  0x0219EF7C  thumb  ov021
 *   func_0219F018  0x0219F018  thumb  ov021
 *   func_021B7934  0x021B7934  thumb  ov021
 *   func_021AB840  0x021AB840  thumb  ov021
 *   func_021AB880  0x021AB880  thumb  ov021
 *   func_021AB884  0x021AB884  thumb  ov021
 *   func_021AB888  0x021AB888  thumb  ov021
 *   func_021AB634  0x021AB634  thumb  ov021
 *   func_020490A8  0x020490A8  arm
 *   func_02048F4C  0x02048F4C  arm
 *   func_021AB650  0x021AB650  thumb  ov021
 *   func_021B7954  0x021B7954  thumb  ov021
 *   func_0219EFFC  0x0219EFFC  thumb  ov021
 *   func_021AB868  0x021AB868  thumb  ov021
 *   func_021B79E4  0x021B79E4  thumb  ov021
 *   func_021B79F0  0x021B79F0  thumb  ov021
 *   func_021B7970  0x021B7970  thumb
 *   func_021B79AC  0x021B79AC  thumb
 *   func_021B79C4  0x021B79C4  thumb  ov021
 *   func_021B79CC  0x021B79CC  thumb  ov021
 *   func_021B7D68  0x021B7D68  thumb ov021
 *   func_021B7C04  0x021B7C04  thumb  ov021
 *   func_02013C9C  0x02013C9C  thumb
 *   func_021B7C58  0x021B7C58  thumb  ov021
 *   func_021BB088  0x021BB088  thumb  ov021
 *   func_021BB0A4  0x021BB0A4  thumb  ov021
 *   func_021BB0B4  0x021BB0B4  thumb  ov021
 *   func_021BB11C  0x021BB11C  thumb  ov021
 *   func_021BB13C  0x021BB13C  thumb  ov021
 */
#include "fldmmdl_rail_types.h"

typedef unsigned int u32;

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

extern void *func_02030734(unsigned int heapId, unsigned int size, int clear, const char *file, u16 line);
extern u32 func_020307B0(void *p);
extern RailManager *func_021B7884(u16 heapId, u32 workMax, int fieldCamera);
extern FieldRailLoader *func_0219EF44(u32 heapId);
extern RailAttr *func_021BB088(int heapId);
extern void func_021BB0A4(RailAttr *attr);
extern void func_021B791C(RailManager *railMan);
extern void func_0219EF6C(FieldRailLoader *loader);
extern void func_021AB75C(FldSceneArea *sceneArea, u32 active);
extern u32 func_02049030(u32 arcId);
extern void func_0219EF7C(FieldRailLoader *loader, u32 dataId, u32 heapId);
extern FieldRailSetting *func_0219F018(FieldRailLoader *loader);
extern int func_021B7934(RailManager *railMan, FieldRailSetting *setting);
extern void func_021BB0B4(RailAttr *attr, u32 dataId, u32 heapId);
extern void func_021AB840(FldSceneAreaLoader *loader, int arcIndex, u32 dataId, u16 heapId);
extern u32 func_021AB880(FldSceneAreaLoader *loader);
extern u32 func_021AB884(FldSceneAreaLoader *loader);
extern u32 func_021AB888(FldSceneAreaLoader *loader);
extern void func_021AB634(FldSceneArea *sceneArea, u32 data, u32 count, u32 funcTable);
extern u32 func_020490A8(u32 arcId, u32 dataId);
extern void func_02048F4C(void *dst, u32 arcId, u32 dataId);
extern void func_021AB650(FldSceneArea *sceneArea);
extern u32 func_021B7954(RailManager *railMan);
extern int func_0219EFFC(FieldRailLoader *loader);
extern u32 func_021AB868(FldSceneAreaLoader *loader);
extern void func_021BB11C(RailAttr *attr);
extern void func_021B79E4(RailManager *railMan);
extern int func_021B79F0(RailManager *railMan, int force);
extern void func_021B7970(RailManager *railMan);
extern void func_021B79AC(RailManager *railMan, RailWork *work);
extern void func_021B79C4(RailManager *railMan, RailWork *work);
extern void func_021B79CC(RailManager *railMan);
extern u32 func_021BB13C(RailAttr *attr, const RailLocation *location);
extern void func_021B7D68(RailManager *railMan, const RailLocation *location);
extern void func_021B7C04(RailManager *railMan, int lineIndex, int enable);
extern int func_02013C9C(u16 zoneId);
extern void func_021B7C58(RailManager *railMan, FieldRailSetting *setting, u32 railIndex, u32 lineGrid, u32 widthPos, RailLocation *outLocation);

FieldNogridMapper *func_021BB1F4(u32 heapId, u32 fieldCamera, FldSceneArea *sceneArea, FldSceneAreaLoader *sceneAreaLoader);
int func_021BB240(FieldNogridMapper *mapper);
void func_021BB260(FieldNogridMapper *mapper, int active);
void func_021BB278(FieldNogridMapper *mapper, const FieldNogridMapperRes *res, u32 heapId);
void func_021BB2F8(FieldNogridMapper *mapper, u32 resId, u32 heapId);
void func_021BB348(FieldNogridMapper *mapper);
void func_021BB36C(FieldNogridMapper *mapper);
int func_021BB388(FieldNogridMapper *mapper);
void func_021BB394(FieldNogridMapper *mapper);
void func_021BB3A0(FieldNogridMapper *mapper, RailWork *work);
void func_021BB3AC(FieldNogridMapper *mapper, RailWork *work);
void func_021BB3B8(FieldNogridMapper *mapper);
u32 func_021BB3C4(FieldNogridMapper *mapper, const RailLocation *location);
void func_021BB3D0(FieldNogridMapper *mapper, const RailLocation *location);
void func_021BB3DC(FieldNogridMapper *mapper, int lineIndex, int enable);
void func_021BB3E8(FieldNogridMapper *mapper, u32 zoneId, u16 railIndex, u16 lineGrid, u16 widthPos, RailLocation *outLocation, u16 heapId);
RailManager *func_021BB480(FieldNogridMapper *mapper);

extern int d_021DE2D0;

FieldNogridMapper *func_021BB1F4(u32 heapId, u32 fieldCamera, FldSceneArea *sceneArea, FldSceneAreaLoader *sceneAreaLoader)
{
    FieldNogridMapper *mapper = func_02030734((u16)heapId, sizeof(FieldNogridMapper), 1, (const char *)&d_021DE2D0, 0x47);

    mapper->railMan = func_021B7884(heapId, RAIL_WORK_MAX, fieldCamera);
    mapper->railLoader = func_0219EF44(heapId);
    mapper->sceneArea = sceneArea;
    mapper->sceneAreaLoader = sceneAreaLoader;
    mapper->railAttr = func_021BB088(heapId);
    return mapper;
}

int func_021BB240(FieldNogridMapper *mapper)
{
    func_021BB0A4(mapper->railAttr);
    func_021B791C(mapper->railMan);
    func_0219EF6C(mapper->railLoader);
    return func_020307B0(mapper);
}

void func_021BB260(FieldNogridMapper *mapper, int active)
{
    if (active != 0) {
        mapper->inactive = 0;
    } else {
        mapper->inactive = 1;
    }
    func_021AB75C(mapper->sceneArea, active);
}

void func_021BB278(FieldNogridMapper *mapper, const FieldNogridMapperRes *res, u32 heapId)
{
    func_021BB348(mapper);
    if (res->railDataId != NOGRID_MAPPER_RES_NONE) {
        u32 railFileCount = func_02049030(RAIL_ARC_ID);
        func_0219EF7C(mapper->railLoader, res->railDataId, heapId);
        func_021B7934(mapper->railMan, func_0219F018(mapper->railLoader));
        func_021BB0B4(mapper->railAttr, res->railDataId + (railFileCount >> 1), heapId);
    }
    if (res->sceneAreaDataId != NOGRID_MAPPER_RES_NONE) {
        u32 data, count, funcTable;
        func_021AB840(mapper->sceneAreaLoader, 0, res->sceneAreaDataId, heapId);
        data = func_021AB880(mapper->sceneAreaLoader);
        count = func_021AB884(mapper->sceneAreaLoader);
        funcTable = func_021AB888(mapper->sceneAreaLoader);
        func_021AB634(mapper->sceneArea, data, count, funcTable);
    }
}

void func_021BB2F8(FieldNogridMapper *mapper, u32 resId, u32 heapId)
{
    int size = func_020490A8(NOGRID_MAPPER_RES_ARC_ID, resId);
    FieldNogridMapperRes *res = func_02030734((u16)(((u16)heapId & 0x7FFF) | 0x8000), size, 1, (const char *)&d_021DE2D0, 0xdd);
    func_02048F4C(res, NOGRID_MAPPER_RES_ARC_ID, resId);
    func_021BB278(mapper, res, heapId);
    func_020307B0(res);
}

void func_021BB348(FieldNogridMapper *mapper)
{
    func_021AB650(mapper->sceneArea);
    func_021B7954(mapper->railMan);
    func_0219EFFC(mapper->railLoader);
    func_021AB868(mapper->sceneAreaLoader);
    func_021BB11C(mapper->railAttr);
}

void func_021BB36C(FieldNogridMapper *mapper)
{
    func_021B79E4(mapper->railMan);
    if (mapper->inactive == 0) {
        func_021B79F0(mapper->railMan, 0);
    }
}

int func_021BB388(FieldNogridMapper *mapper) { return func_021B79F0(mapper->railMan, 1); }

void func_021BB394(FieldNogridMapper *mapper)
{
    func_021B7970(mapper->railMan);
}

void func_021BB3A0(FieldNogridMapper *mapper, RailWork *work)
{
    func_021B79AC(mapper->railMan, work);
}

void func_021BB3AC(FieldNogridMapper *mapper, RailWork *work)
{
    func_021B79C4(mapper->railMan, work);
}

void func_021BB3B8(FieldNogridMapper *mapper)
{
    func_021B79CC(mapper->railMan);
}

u32 func_021BB3C4(FieldNogridMapper *mapper, const RailLocation *location)
{
    return func_021BB13C(mapper->railAttr, location);
}

void func_021BB3D0(FieldNogridMapper *mapper, const RailLocation *location) { func_021B7D68(mapper->railMan, location); }

void func_021BB3DC(FieldNogridMapper *mapper, int lineIndex, int enable)
{
    func_021B7C04(mapper->railMan, lineIndex, enable);
}

void func_021BB3E8(FieldNogridMapper *mapper, u32 zoneId, u16 railIndex, u16 lineGrid, u16 widthPos, RailLocation *outLocation, u16 heapId)
{
    u16 tempHeapId;
    FieldNogridMapperRes *res;
    FieldRailLoader *loader;
    tempHeapId = (heapId & 0x7FFF) | 0x8000;
    res = func_02030734(tempHeapId, func_020490A8(NOGRID_MAPPER_RES_ARC_ID, func_02013C9C(zoneId)), 1, (const char *)&d_021DE2D0, 0x1c9);
    func_02048F4C(res, NOGRID_MAPPER_RES_ARC_ID, func_02013C9C(zoneId));
    loader = func_0219EF44(tempHeapId);
    func_0219EF7C(loader, res->railDataId, tempHeapId);
    func_021B7C58(mapper->railMan, func_0219F018(loader), railIndex, lineGrid, widthPos, outLocation);
    func_0219EF6C(loader);
    func_020307B0(res);
}

RailManager *func_021BB480(FieldNogridMapper *mapper)
{
    return mapper->railMan;
}
