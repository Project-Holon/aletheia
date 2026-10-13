/*
 * file:     field_effect.c
 * unit:     yes
 * function: func_021ABD50, func_021ABDE8, func_021ABE04, func_021ABE0C, func_021ABE14, func_021ABE18, func_021ABE24, func_021ABE28, func_021ABE2C, func_021ABE30, func_021ABE64, func_021ABE8C, func_021ABEA0, func_021ABEAC, func_021ABEE8, func_021ABF2C, func_021ABF48, func_021ABF68, func_021ABFA8, func_021ABFC0, func_021ABFDC, func_021ABFEC, func_021ABFFC, func_021AC03C, func_021AC074, func_021AC0A0, func_021AC134, func_021AC140, func_021AC154, func_021AC178, func_021AC18C, func_021AC1A0, func_021AC1AC, func_021AC1B8, func_021AC1CC, func_021AC1E0, func_021AC1EC, func_021AC1F0
 * address:  0x021ABD50
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 * Split from field_effect.c at 0x021ABD50: __FILE__ field_effect.c on 0x021ABD50 (create, first
 * function), 0x021ABEAC, 0x021ABF68, 0x021ABFFC.
 *
 * symbols:
 *   func_020490F4  0x020490F4  arm
 *   func_02049238  0x02049238  arm
 *   func_020307B0  0x020307B0  arm
 *   func_02082BCC  0x02082BCC  arm
 *   func_02030734  0x02030734  arm
 *   func_02188C80  0x02188C80  thumb  ov021
 *   func_02188C9C  0x02188C9C  thumb  ov021
 *   func_02013B38  0x02013B38  thumb
 *   func_0202E83C  0x0202E83C  thumb
 *   func_02188D58  0x02188D58  thumb  ov021
 *   func_020140D8  0x020140D8  thumb
 *   func_02188C88  0x02188C88  thumb  ov021
 *   func_02050080  0x02050080  arm
 *   func_0204EDBC  0x0204EDBC  arm
 *   func_0204ED70  0x0204ED70  arm
 *   func_0204EDB0  0x0204EDB0  arm
 *   d_021DE018     0x021DE018  data  a1
 *   d_021D8F04     0x021D8F04  data  a4
 *   func_02188CD8  0x02188CD8  thumb  ov021
 *   d_021D8F60  0x021D8F60  data  a4
 *   func_02030CB0  0x02030CB0  arm
 *   func_02030CBC  0x02030CBC  arm
 *   func_02030DA4  0x02030DA4  arm
 *   func_02030D28  0x02030D28  arm
 *   func_02022040  0x02022040  thumb
 */
#include "field_effect_types.h"

typedef struct PaletteResource {
    u8 pad00[0x30];
    u16 palSize;
    u16 pad32;
    u32 pad34;
    u32 palOffset;
} PaletteResource;

extern void *func_020490F4(u32 id, u32 heap);
extern void func_02049238(void *h);
extern u32 func_020307B0(void *p);
extern u32 func_02082BCC(void *p, int v, int n);
extern void *func_02188C80(void *p);
extern void *func_02030734(u32 a, u32 b, int c, const char *d, u16 e);
extern u16 func_02188C9C(u8 *p);
extern u32 func_02013B38(u32 id);
extern int func_0202E83C(void *a0);
extern u32 func_02188D58(u8 *p);
extern u8 func_020140D8(void *p);
extern u32 func_02188C88(u8 *p);
extern u32 func_02050080(u32 *p);
extern void func_0204EDBC(u8 *dst, u8 val);
extern void func_0204ED70(u8 *dst, VecFx32 *src);
extern void func_0204EDB0(u8 *dst, u8 *src);
extern u32 func_02188CD8(u8 *p);
extern u32 func_02030CB0(u32 idx);
extern int func_02030CBC(u32 capacity, void *buffer);
extern void func_02030DA4(int a);
extern void func_02030D28(int taskSys);
extern void *func_02030DA8(u32 taskSys, void (*cb)(void), void *arg, u32 pri);
extern void func_02030EAC(void *tcb);
extern void *func_02046F48(void *p);
extern unsigned char *func_0206E964(unsigned char *p);
extern void func_02022040(u16 *pal, int n, const u8 *table);

FieldEffectSys *func_021ABD50(void *fieldmap, int resourceCount, u16 heapId);
int func_021ABDE8(FieldEffectSys *sys, u32 unused0, u32 unused1, u32 unused2);
void func_021ABE04(FieldEffectSys *sys);
void func_021ABE0C(FieldEffectSys *sys);
u32 func_021ABE14(FieldEffectSys *sys);
u32 func_021ABE18(FieldEffectSys *sys);
u32 func_021ABE24(FieldEffectSys *sys);
u8 func_021ABE28(FieldEffectSys *sys);
u8 func_021ABE2C(FieldEffectSys *sys);
void func_021ABE30(FieldEffectSys *sys, int *ids, int count);
void func_021ABE64(FieldEffectSys *sys, int id);
int func_021ABE8C(FieldEffectSys *sys, int id);
int func_021ABEA0(FieldEffectSys *sys, int id);
void func_021ABEAC(FieldEffectSys *sys);
void func_021ABEE8(FieldEffectSys *sys);
FieldEffectResource *func_021ABF2C(FieldEffectSys *sys, int id);
FieldEffectResourceDef *func_021ABF48(int id);
void func_021ABF68(FieldEffectSys *sys, int objectCount);
void func_021ABFA8(FieldEffectSys *sys, const FieldEffectObjFuncs *funcs, const VecFx32 *pos, u32 mode, void *param, u32 priority);
void func_021ABFC0(FieldEffectSys *sys);
void func_021ABFDC(FieldEffectSys *sys);
void func_021ABFEC(FieldEffectSys *sys);
FieldEffectObjMgr *func_021ABFFC(u16 heapId, int taskSys, int objectCount);
void func_021AC03C(FieldEffectObjMgr *mgr);
void func_021AC074(FieldEffectObjMgr *mgr);
FieldEffectObj *func_021AC0A0(FieldEffectObjMgr *mgr, const FieldEffectObjFuncs *funcs, const VecFx32 *pos, u32 mode, void *param, u32 priority);
void func_021AC134(u32 task, FieldEffectObj *obj);
void func_021AC140(FieldEffectObj *obj);
void func_021AC154(FieldEffectObj *obj);
void func_021AC178(FieldEffectObj *obj);
void func_021AC18C(FieldEffectObj *obj);
int func_021AC1A0(FieldEffectObj *obj);
void *func_021AC1AC(FieldEffectObj *obj);
void func_021AC1B8(FieldEffectObj *obj, VecFx32 *out);
void func_021AC1CC(FieldEffectObj *obj, const VecFx32 *pos);
void *func_021AC1E0(FieldEffectObj *obj);
void func_021AC1EC(FieldEffectSys *sys, u32 paletteTable);
void func_021AC1F0(FieldEffectSys *sys, void *model);
extern char d_021DE018[];
extern VecFx32 d_021D8F04;
extern FieldEffectResourceDef d_021D8F60[];

FieldEffectSys *func_021ABD50(void *fieldmap, int resourceCount, u16 heapId)
{
    FieldEffectSys *sys;
    int billboard;
    VecFx32 vec;
    u8 zero;

    sys = func_02030734(heapId, 0x28, 1, d_021DE018, 0x7e);
    sys->resourceCount = resourceCount;
    sys->heapId = heapId;
    sys->fieldmap = fieldmap;
    sys->arcHandle = (int)func_020490F4(0x4b, heapId);
    func_02013B38(func_02188C9C((u8 *)fieldmap));
    sys->modelBaseOffset = func_0202E83C(func_02188C80(fieldmap));
    sys->modelBaseOffsetAlt = func_020140D8((void *)func_02188D58((u8 *)fieldmap));
    func_021ABEAC(sys);
    billboard = func_02050080((u32 *)func_02188C88((u8 *)sys->fieldmap));
    func_0204EDBC((u8 *)billboard, 0);
    vec = d_021D8F04;
    func_0204ED70((u8 *)billboard, &vec);
    zero = 0;
    func_0204EDB0((u8 *)billboard, &zero);
    return sys;
}

int func_021ABDE8(FieldEffectSys *sys, u32 unused0, u32 unused1, u32 unused2)
{
    func_021ABFC0(sys);
    func_021ABEE8(sys);
    func_02049238((void *)sys->arcHandle);
    return func_020307B0(sys);
}

void func_021ABE04(FieldEffectSys *sys)
{
    func_021ABFDC(sys);
}

void func_021ABE0C(FieldEffectSys *sys)
{
    func_021ABFEC(sys);
}

u32 func_021ABE14(FieldEffectSys *sys)
{
    return (u32)sys->fieldmap;
}

u32 func_021ABE18(FieldEffectSys *sys)
{
    return func_02188CD8((u8 *)sys->fieldmap);
}

u32 func_021ABE24(FieldEffectSys *sys)
{
    return sys->arcHandle;
}

u8 func_021ABE28(FieldEffectSys *sys)
{
    return sys->modelBaseOffset;
}

u8 func_021ABE2C(FieldEffectSys *sys)
{
    return sys->modelBaseOffsetAlt;
}

void func_021ABE30(FieldEffectSys *sys, int *ids, int count)
{
    FieldEffectResource *slot;
    FieldEffectResourceDef *def;

    for (; count != 0; count--) {
        slot = func_021ABF2C(sys, 0x18);
        def = func_021ABF48(*ids);
        slot->id = *ids;
        slot->handle = def->load(sys, sys->heapId);
        ids++;
    }
}

void func_021ABE64(FieldEffectSys *sys, int id)
{
    FieldEffectResource *slot = func_021ABF2C(sys, id);
    FieldEffectResourceDef *def;

    if (slot != 0) {
        def = func_021ABF48(id);
        def->unload(sys, slot->handle);
        slot->id = 0x18;
        slot->handle = 0;
    }
}

int func_021ABE8C(FieldEffectSys *sys, int id)
{
    if (func_021ABF2C(sys, id) != 0) {
        return 1;
    }
    return 0;
}

int func_021ABEA0(FieldEffectSys *sys, int id)
{
    return func_021ABF2C(sys, id)->handle;
}

void func_021ABEAC(FieldEffectSys *sys)
{
    FieldEffectResource *slot;
    int i;

    slot = sys->resources = func_02030734(sys->heapId, sys->resourceCount * 8, 1, d_021DE018, 0x174);
    i = 0;
    if (sys->resourceCount > 0) {
        for (; i < sys->resourceCount; i++) {
            slot->id = 0x18;
            slot++;
        }
    }
}

void func_021ABEE8(FieldEffectSys *sys)
{
    int i;
    FieldEffectResource *slot;

    i = 0;
    slot = sys->resources;
    if (i < sys->resourceCount) {
        for (; i < sys->resourceCount; i++, slot++) {
            if (slot->id != 0x18) {
                func_021ABF48(slot->id)->unload(sys, slot->handle);
                slot->id = 0x18;
                slot->handle = 0;
            }
        }
    }
    func_020307B0(sys->resources);
    sys->resources = 0;
}

FieldEffectResource *func_021ABF2C(FieldEffectSys *sys, int id)
{
    int n = sys->resourceCount;
    FieldEffectResource *slot = sys->resources;

    while (n != 0) {
        if (slot->id == id) {
            return slot;
        }
        n--;
        slot++;
    }
    return 0;
}

FieldEffectResourceDef *func_021ABF48(int id)
{
    int i;
    FieldEffectResourceDef *def = d_021D8F60;

    for (i = 0; i < 0x18; i++) {
        if (def->id == id) {
            return def;
        }
        def++;
    }
    return def;
}

void func_021ABF68(FieldEffectSys *sys, int objectCount)
{
    sys->objectCount = objectCount;
    sys->taskBuffer = func_02030734(sys->heapId, func_02030CB0(objectCount), 0, d_021DE018, 0x1db);
    sys->taskSys = func_02030CBC(objectCount, sys->taskBuffer);
    sys->objMgr = func_021ABFFC(sys->heapId, sys->taskSys, objectCount);
}

void func_021ABFA8(FieldEffectSys *sys, const FieldEffectObjFuncs *funcs, const VecFx32 *pos, u32 mode, void *param, u32 priority)
{
    func_021AC0A0(sys->objMgr, funcs, pos, mode, param, priority);
}

void func_021ABFC0(FieldEffectSys *sys)
{
    if (sys->objMgr != 0) {
        func_021AC03C(sys->objMgr);
        func_02030DA4(sys->taskSys);
        func_020307B0(sys->taskBuffer);
    }
}

void func_021ABFDC(FieldEffectSys *sys)
{
    if (sys->taskSys != 0) {
        func_02030D28(sys->taskSys);
    }
}

void func_021ABFEC(FieldEffectSys *sys)
{
    if (sys->objMgr != 0) {
        func_021AC074(sys->objMgr);
    }
}

FieldEffectObjMgr *func_021ABFFC(u16 heapId, int taskSys, int objectCount)
{
    FieldEffectObjMgr *mgr;

    mgr = func_02030734(heapId, 0x10, 1, d_021DE018, 0x23a);
    mgr->count = objectCount;
    mgr->heapId = heapId;
    mgr->objs = func_02030734(heapId, objectCount * 0xd4, 1, d_021DE018, 0x23e);
    mgr->taskSys = taskSys;
    return mgr;
}

void func_021AC03C(FieldEffectObjMgr *mgr)
{
    u32 i;

    for (i = 0; i < mgr->count; i++) {
        if (mgr->objs[i].active != 0) {
            func_021AC154(&mgr->objs[i]);
        }
    }
    func_020307B0(mgr->objs);
    func_020307B0(mgr);
}

void func_021AC074(FieldEffectObjMgr *mgr)
{
    u32 i;

    for (i = 0; i < mgr->count; i++) {
        if (mgr->objs[i].active != 0)
            func_021AC18C(&mgr->objs[i]);
    }
}

FieldEffectObj *func_021AC0A0(FieldEffectObjMgr *mgr, const FieldEffectObjFuncs *funcs, const VecFx32 *pos, u32 mode, void *param, u32 priority)
{
    u32 i = 0;
    FieldEffectObj *obj = mgr->objs;

    do {
        if (obj->active == 0) {
            func_02082BCC(obj, 0, sizeof(FieldEffectObj));
            obj->active = 1;
            obj->funcs = *funcs;
            obj->mode = mode;
            obj->param = param;
            if (pos != 0)
                obj->pos = *pos;
            obj->mgr = mgr;
            obj->task = func_02030DA8(mgr->taskSys, (void (*)(void))func_021AC134, obj, priority);
            break;
        }
        i++;
        obj++;
    } while (i < mgr->count);
    if (i < mgr->count) {
        func_021AC140(obj);
        return obj;
    }
    return 0;
}

void func_021AC134(u32 task, FieldEffectObj *obj)
{
    func_021AC178(obj);
}

void func_021AC140(FieldEffectObj *obj)
{
    if (obj != 0)
        obj->funcs.init(obj, obj->work);
}

void func_021AC154(FieldEffectObj *obj)
{
    if (obj != 0) {
        obj->funcs.exit(obj, obj->work);
        func_02030EAC(obj->task);
        obj->active = 0;
    }
}

void func_021AC178(FieldEffectObj *obj)
{
    if (obj != 0)
        obj->funcs.update(obj, obj->work);
}

void func_021AC18C(FieldEffectObj *obj)
{
    if (obj != 0)
        obj->funcs.draw(obj, obj->work);
}

int func_021AC1A0(FieldEffectObj *obj)
{
    if (obj != 0) {
        return obj->mode;
    }
    return 0;
}

void *func_021AC1AC(FieldEffectObj *obj)
{
    if (obj != 0) {
        return obj->param;
    }
    return 0;
}

void func_021AC1B8(FieldEffectObj *obj, VecFx32 *out)
{
    if (obj != 0)
        *out = obj->pos;
}

void func_021AC1CC(FieldEffectObj *obj, const VecFx32 *pos)
{
    if (obj != 0)
        obj->pos = *pos;
}

void *func_021AC1E0(FieldEffectObj *obj)
{
    if (obj != 0) {
        return obj->work;
    }
    return 0;
}

void func_021AC1EC(FieldEffectSys *sys, u32 paletteTable)
{
    sys->paletteTable = paletteTable;
}

void func_021AC1F0(FieldEffectSys *sys, void *model)
{
    PaletteResource *res;

    if (sys->paletteTable != 0) {
        res = (PaletteResource *)func_0206E964(func_02046F48(model));
        func_02022040((u16 *)((u8 *)res + res->palOffset), res->palSize * 8u / 2, (const u8 *)sys->paletteTable);
    }
}
