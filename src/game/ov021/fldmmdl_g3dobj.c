/*
 * file:     fldmmdl_g3dobj.c
 * unit:     yes
 * function: FLDMMDL_G3DOBJ_Create, FLDMMDL_G3DOBJ_Delete, FLDMMDL_G3DOBJ_GetObjCtrl, FLDMMDL_G3DOBJ_InitResTable, FLDMMDL_G3DOBJ_DeleteResTable, FLDMMDL_G3DOBJ_AddResEntry, FLDMMDL_G3DOBJ_FindResIdx, FLDMMDL_G3DOBJ_LoadRes, FLDMMDL_G3DOBJ_DeleteResByCode, FLDMMDL_G3DOBJ_AddObj, FLDMMDL_G3DOBJ_DelObj
 * address:  0x0219D448
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 * Split from fldmmdl_blact.c at 0x0219D448 (__FILE__ anchor boundary, certain cut).
 *
 * symbols:
 *   FLDMMDL_SysGetHeapId  0x0216D4F8  thumb  ov010
 *   GFL_HEAP_Free  0x020307B0  arm
 *   FLDMMDL_GetMmdlSys  0x0216D67C  thumb  ov010
 *   FLDMMDL_GetObjCodeParam  0x0216E3C4  thumb  ov010
 *   FLDMMDL_CheckSameObjCodeOther  0x0216DFC4  thumb  ov010
 *   FLDMMDL_GetObjCode  0x0216D598  thumb  ov010
 *   GFL_HEAP_Alloc  0x02030734  arm
 *   FLDMMDL_SysGetResArcHandle  0x0216D518  thumb  ov010
 *   FLDMMDL_SysGetMmdlMax  0x0216D4F0  thumb  ov010
 *   FLDMMDL_SysSetG3dObjCont  0x0216D524  thumb  ov010
 *   d_021DDD80     0x021DDD80  data ov021 a4
 *   FLDMMDL_SysGetG3dObjCont  0x0216D528  thumb  ov010
 *   FIELD_G3DOBJ_DeleteResource  0x021C6580  thumb  ov021
 *   FIELD_G3DOBJ_InitResDesc  0x021C6AE0  thumb  ov021
 *   FIELD_G3DOBJ_SetResDescModel  0x021C6AF0  thumb  ov021
 *   FIELD_G3DOBJ_SetResDescAnimeArc  0x021C6AF8  thumb  ov021
 *   FIELD_G3DOBJ_AddResDescAnimeFile  0x021C6AFC  thumb  ov021
 *   FIELD_G3DOBJ_AddResourceDefaultPal  0x021C6574  thumb  ov021
 *   FLDMMDL_GetObjCodeParamMdlRes  0x0216E3CC  thumb  ov010
 *   FIELD_G3DOBJ_AddObject  0x021C6590  thumb  ov021
 *   FIELD_G3DOBJ_DeleteObject  0x021C6628  thumb  ov021
 */
#include "../types.h"
/* One loaded model resource of the field model 3D object container. */
typedef struct {
    u16 resIdx; /* resource index in the field 3D object control */
    u16 code;   /* object code, 0xFFFF = free entry */
} MmdlG3dObjRes;
/* Links the field model system to the field 3D object control (0x10). */
typedef struct {
    u32 mmdlSys;
    u32 objCtrl;
    u16 resMax;
    MmdlG3dObjRes *resTable;
} MmdlG3dObjCont;
struct MmdlSys;
#include "../ov010/fldmmdl.h"
#include "../arm9/gfl_heap_wrap.h"
struct Mmdl;
struct FieldG3dObjCtrl;
/* DS-original prototypes: the DS code was built against narrower or wider integer parameters than the header; the host build uses the header. */
#ifdef __MWERKS__
#define FIELD_G3DOBJ_AddObject FIELD_G3DOBJ_AddObject_header
#endif
#include "field_g3dobj.h"
#ifdef __MWERKS__
#undef FIELD_G3DOBJ_AddObject
extern u16 FIELD_G3DOBJ_AddObject(FieldG3dObjCtrl *, u32, u32, VecFx32 *);
#endif
struct FieldG3dObjResDesc;
void FLDMMDL_G3DOBJ_Create(int a, int b);
void FLDMMDL_G3DOBJ_Delete(struct MmdlSys *a);
u32 FLDMMDL_G3DOBJ_GetObjCtrl(u32 a);
void FLDMMDL_G3DOBJ_InitResTable(MmdlG3dObjCont *cont, int heapId);
void FLDMMDL_G3DOBJ_DeleteResTable(MmdlG3dObjCont *cont);
u16 FLDMMDL_G3DOBJ_AddResEntry(MmdlG3dObjCont *cont, u32 code, u32 resIdx);
u16 FLDMMDL_G3DOBJ_FindResIdx(MmdlG3dObjCont *cont, u16 code);
u32 FLDMMDL_G3DOBJ_LoadRes(u32 mmdlSys, MmdlG3dObjCont *cont, u32 code, u16 *resParam);
void FLDMMDL_G3DOBJ_DeleteResByCode(MmdlG3dObjCont *cont, u16 code);
u32 FLDMMDL_G3DOBJ_AddObj(struct Mmdl *a);
void FLDMMDL_G3DOBJ_DelObj(struct Mmdl *mmdl, u32 objIdx);
extern unsigned char d_021DDD80[];

void FLDMMDL_G3DOBJ_Create(int mmdlSys, int objCtrl)
{
    int heapId;
    MmdlG3dObjCont *cont;
    heapId = FLDMMDL_SysGetHeapId((struct MmdlSys *)mmdlSys);
    cont = (MmdlG3dObjCont *)GFL_HEAP_Alloc(heapId, sizeof(MmdlG3dObjCont), 1, (const char *)d_021DDD80, 0x48);
    cont->mmdlSys = mmdlSys;
    cont->objCtrl = objCtrl;
    cont->resMax = FLDMMDL_SysGetMmdlMax((void *)mmdlSys);
    FLDMMDL_G3DOBJ_InitResTable(cont, heapId);
    FLDMMDL_SysSetG3dObjCont((void *)mmdlSys, cont);
}
void FLDMMDL_G3DOBJ_Delete(struct MmdlSys *mmdlSys)
{
    MmdlG3dObjCont *cont = (MmdlG3dObjCont *)FLDMMDL_SysGetG3dObjCont((struct MmdlSys *)mmdlSys);
    FLDMMDL_G3DOBJ_DeleteResTable(cont);
    GFL_HEAP_Free(cont);
}
u32 FLDMMDL_G3DOBJ_GetObjCtrl(u32 mmdl)
{
    return ((MmdlG3dObjCont *)FLDMMDL_SysGetG3dObjCont((struct MmdlSys *)((uptr)FLDMMDL_GetMmdlSys((void *)mmdl))))->objCtrl;
}
/* Allocates resMax entries and marks every entry free (code 0xFFFF). */
void FLDMMDL_G3DOBJ_InitResTable(MmdlG3dObjCont *cont, int heapId)
{
    int i;
    cont->resTable = (MmdlG3dObjRes *)GFL_HEAP_Alloc(heapId, cont->resMax * 4, 1, (const char *)d_021DDD80, 0x7f);
    for (i = 0; i < (int)cont->resMax; i++) {
        cont->resTable[i].code = 0xFFFF;
    }
}
void FLDMMDL_G3DOBJ_DeleteResTable(MmdlG3dObjCont *cont)
{
    int i = 0;
    MmdlG3dObjRes *res = cont->resTable;
    if (i < cont->resMax) {
        for (; i < cont->resMax; i++, res++) {
            if (res->code != 0xFFFF) {
                FIELD_G3DOBJ_DeleteResource((struct FieldG3dObjCtrl *)cont->objCtrl, res->resIdx);
            }
        }
    }
    GFL_HEAP_Free(cont->resTable);
}
u16 FLDMMDL_G3DOBJ_AddResEntry(MmdlG3dObjCont *cont, u32 code, u32 resIdx)
{
    int i;
    MmdlG3dObjRes *res = cont->resTable;
    int max = cont->resMax;
    for (i = 0; i < max; i++, res++) {
        if (res->code == 0xFFFF) {
            res->code = code;
            res->resIdx = resIdx;
            return i;
        }
    }
    return 0;
}
u16 FLDMMDL_G3DOBJ_FindResIdx(MmdlG3dObjCont *cont, u16 code)
{
    int i;
    MmdlG3dObjRes *res = cont->resTable;
    int max = cont->resMax;
    for (i = 0; i < max; i++, res++) {
        if (res->code == code) {
            return res->resIdx;
        }
    }
    return 0xFFFF;
}
/*
 * resParam: two model ids, then three animation ids (0xFFFF = none).
 */
u32 FLDMMDL_G3DOBJ_LoadRes(u32 mmdlSys, MmdlG3dObjCont *cont, u32 code, u16 *resParam)
{
    u32 resDesc[9];
    u32 heapId;
    u32 resIdx;
    int i;
    heapId = (uptr)FLDMMDL_SysGetResArcHandle((struct MmdlSys *)mmdlSys);
    FIELD_G3DOBJ_InitResDesc((struct FieldG3dObjResDesc *)resDesc);
    if (resParam[0] != 0xFFFF) {
        FIELD_G3DOBJ_SetResDescModel((struct FieldG3dObjResDesc *)resDesc, heapId, resParam[0]);
    }
    if (resParam[1] != 0xFFFF) {
        FIELD_G3DOBJ_SetResDescModel((struct FieldG3dObjResDesc *)resDesc, heapId, resParam[1]);
    }
    FIELD_G3DOBJ_SetResDescAnimeArc((struct FieldG3dObjResDesc *)resDesc, heapId);
    for (i = 0; i < 3; i++) {
        if (resParam[i + 2] != 0xFFFF) {
            FIELD_G3DOBJ_AddResDescAnimeFile((struct FieldG3dObjResDesc *)resDesc, resParam[i + 2]);
        }
    }
    resIdx = FIELD_G3DOBJ_AddResourceDefaultPal((struct FieldG3dObjCtrl *)cont->objCtrl, (struct FieldG3dObjResDesc *)resDesc, 0);
    FLDMMDL_G3DOBJ_AddResEntry(cont, code, resIdx);
    return resIdx;
}
void FLDMMDL_G3DOBJ_DeleteResByCode(MmdlG3dObjCont *cont, u16 code)
{
    int i;
    int max = cont->resMax;
    MmdlG3dObjRes *res = cont->resTable;
    for (i = 0; i < max; i++, res++) {
        if (res->code == code) {
            FIELD_G3DOBJ_DeleteResource((struct FieldG3dObjCtrl *)cont->objCtrl, res->resIdx);
            res->code = 0xFFFF;
            return;
        }
    }
}
u32 FLDMMDL_G3DOBJ_AddObj(struct Mmdl *mmdl)
{
    MmdlObjCodeParam *objCode;
    uptr mmdlSys;
    MmdlG3dObjCont *cont;
    u32 resIdx;
    objCode = FLDMMDL_GetObjCodeParam(mmdl);
    mmdlSys = (uptr)FLDMMDL_GetMmdlSys((void *)mmdl);
    cont = (MmdlG3dObjCont *)FLDMMDL_SysGetG3dObjCont((struct MmdlSys *)mmdlSys);
    resIdx = FLDMMDL_G3DOBJ_FindResIdx(cont, objCode->code);
    if (resIdx == 0xFFFF) {
        resIdx = FLDMMDL_G3DOBJ_LoadRes(mmdlSys, cont, objCode->code, FLDMMDL_GetObjCodeParamMdlRes(objCode));
    }
    return FIELD_G3DOBJ_AddObject((struct FieldG3dObjCtrl *)cont->objCtrl, resIdx, 0, 0);
}
void FLDMMDL_G3DOBJ_DelObj(struct Mmdl *mmdl, u32 objIdx)
{
    MmdlG3dObjCont *cont = (MmdlG3dObjCont *)FLDMMDL_SysGetG3dObjCont((struct MmdlSys *)FLDMMDL_GetMmdlSys(mmdl));
    u16 code = FLDMMDL_GetObjCode(mmdl);
    FIELD_G3DOBJ_DeleteObject((struct FieldG3dObjCtrl *)cont->objCtrl, objIdx);
    if (FLDMMDL_CheckSameObjCodeOther(mmdl, code) == 0) {
        FLDMMDL_G3DOBJ_DeleteResByCode(cont, code);
    }
}
