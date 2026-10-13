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
 *   func_020307B0  0x020307B0  arm
 *   FLDMMDL_GetMmdlSys  0x0216D67C  thumb  ov010
 *   FLDMMDL_GetObjCodeParam  0x0216E3C4  thumb  ov010
 *   FLDMMDL_CheckSameObjCodeOther  0x0216DFC4  thumb  ov010
 *   FLDMMDL_GetObjCode  0x0216D598  thumb  ov010
 *   func_02030734  0x02030734  arm
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
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
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
extern u32 FLDMMDL_SysGetHeapId(u8 *p);
extern u32 func_020307B0(void *p);
extern void *FLDMMDL_GetMmdlSys(void *a0);
extern void *FLDMMDL_GetObjCodeParam(void *p);
extern int FLDMMDL_CheckSameObjCodeOther(void *a, u32 id);
extern u16 FLDMMDL_GetObjCode(void *p);
extern void *func_02030734(unsigned int heapId, unsigned int size, int clear, const char *site, unsigned short tag);
extern u32 FLDMMDL_SysGetResArcHandle(u8 *p);
extern u16 FLDMMDL_SysGetMmdlMax(void *p);
extern void FLDMMDL_SysSetG3dObjCont(void *p, void *v);
extern u32 FLDMMDL_SysGetG3dObjCont(u8 *p);
extern void FIELD_G3DOBJ_DeleteResource(u8 *p, int i);
extern void FIELD_G3DOBJ_InitResDesc(u32 a);
extern void FIELD_G3DOBJ_SetResDescModel(u32 *, u32, u16);
extern void FIELD_G3DOBJ_SetResDescAnimeArc(u32 *p, u32 v);
extern void FIELD_G3DOBJ_AddResDescAnimeFile(u32 *, u16);
extern u32 FIELD_G3DOBJ_AddResourceDefaultPal(u32, u32 *, u32);
extern u8 *FLDMMDL_GetObjCodeParamMdlRes(u8 *p);
extern u32 FIELD_G3DOBJ_AddObject(u32, u32, u32, u32);
extern void FIELD_G3DOBJ_DeleteObject(u32, u32);
void FLDMMDL_G3DOBJ_Create(int a, int b);
void FLDMMDL_G3DOBJ_Delete(u32 a);
u32 FLDMMDL_G3DOBJ_GetObjCtrl(u32 a);
void FLDMMDL_G3DOBJ_InitResTable(MmdlG3dObjCont *cont, int heapId);
void FLDMMDL_G3DOBJ_DeleteResTable(MmdlG3dObjCont *cont);
u16 FLDMMDL_G3DOBJ_AddResEntry(MmdlG3dObjCont *cont, u32 code, u32 resIdx);
u16 FLDMMDL_G3DOBJ_FindResIdx(MmdlG3dObjCont *cont, u16 code);
u32 FLDMMDL_G3DOBJ_LoadRes(u32 mmdlSys, MmdlG3dObjCont *cont, u32 code, u16 *resParam);
void FLDMMDL_G3DOBJ_DeleteResByCode(MmdlG3dObjCont *cont, u16 code);
u32 FLDMMDL_G3DOBJ_AddObj(u32 a);
void FLDMMDL_G3DOBJ_DelObj(u32 a, u32 b);
extern unsigned char d_021DDD80[];



















void FLDMMDL_G3DOBJ_Create(int mmdlSys, int objCtrl)
{
    int heapId;
    MmdlG3dObjCont *cont;
    heapId = FLDMMDL_SysGetHeapId((u8 *)mmdlSys);
    cont = (MmdlG3dObjCont *)func_02030734(heapId, sizeof(MmdlG3dObjCont), 1, (const char *)d_021DDD80, 0x48);
    cont->mmdlSys = mmdlSys;
    cont->objCtrl = objCtrl;
    cont->resMax = FLDMMDL_SysGetMmdlMax((void *)mmdlSys);
    FLDMMDL_G3DOBJ_InitResTable(cont, heapId);
    FLDMMDL_SysSetG3dObjCont((void *)mmdlSys, cont);
}
void FLDMMDL_G3DOBJ_Delete(u32 mmdlSys)
{
    MmdlG3dObjCont *cont = (MmdlG3dObjCont *)FLDMMDL_SysGetG3dObjCont((u8 *)mmdlSys);
    FLDMMDL_G3DOBJ_DeleteResTable(cont);
    func_020307B0(cont);
}
u32 FLDMMDL_G3DOBJ_GetObjCtrl(u32 mmdl)
{
    return ((MmdlG3dObjCont *)FLDMMDL_SysGetG3dObjCont((u8 *)((u32)FLDMMDL_GetMmdlSys((void *)mmdl))))->objCtrl;
}
/* Allocates resMax entries and marks every entry free (code 0xFFFF). */
void FLDMMDL_G3DOBJ_InitResTable(MmdlG3dObjCont *cont, int heapId)
{
    int i;
    cont->resTable = (MmdlG3dObjRes *)func_02030734(heapId, cont->resMax * 4, 1, (const char *)d_021DDD80, 0x7f);
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
                FIELD_G3DOBJ_DeleteResource((u8 *)cont->objCtrl, res->resIdx);
            }
        }
    }
    func_020307B0(cont->resTable);
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
    heapId = FLDMMDL_SysGetResArcHandle((u8 *)mmdlSys);
    FIELD_G3DOBJ_InitResDesc((u32)resDesc);
    if (resParam[0] != 0xFFFF) {
        FIELD_G3DOBJ_SetResDescModel(resDesc, heapId, resParam[0]);
    }
    if (resParam[1] != 0xFFFF) {
        FIELD_G3DOBJ_SetResDescModel(resDesc, heapId, resParam[1]);
    }
    FIELD_G3DOBJ_SetResDescAnimeArc((u32 *)resDesc, heapId);
    for (i = 0; i < 3; i++) {
        if (resParam[i + 2] != 0xFFFF) {
            FIELD_G3DOBJ_AddResDescAnimeFile(resDesc, resParam[i + 2]);
        }
    }
    resIdx = FIELD_G3DOBJ_AddResourceDefaultPal(cont->objCtrl, resDesc, 0);
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
            FIELD_G3DOBJ_DeleteResource((u8 *)cont->objCtrl, res->resIdx);
            res->code = 0xFFFF;
            return;
        }
    }
}
u32 FLDMMDL_G3DOBJ_AddObj(u32 mmdl)
{
    u16 *objCode;
    u32 mmdlSys;
    MmdlG3dObjCont *cont;
    u32 resIdx;
    objCode = FLDMMDL_GetObjCodeParam((void *)mmdl);
    mmdlSys = (u32)FLDMMDL_GetMmdlSys((void *)mmdl);
    cont = (MmdlG3dObjCont *)FLDMMDL_SysGetG3dObjCont((u8 *)mmdlSys);
    resIdx = FLDMMDL_G3DOBJ_FindResIdx(cont, *objCode);
    if (resIdx == 0xFFFF) {
        resIdx = FLDMMDL_G3DOBJ_LoadRes(mmdlSys, cont, *objCode, (u16 *)FLDMMDL_GetObjCodeParamMdlRes((u8 *)objCode));
    }
    return FIELD_G3DOBJ_AddObject(cont->objCtrl, resIdx, 0, 0);
}
void FLDMMDL_G3DOBJ_DelObj(u32 mmdl, u32 objIdx)
{
    MmdlG3dObjCont *cont = (MmdlG3dObjCont *)FLDMMDL_SysGetG3dObjCont(FLDMMDL_GetMmdlSys((void *)mmdl));
    u16 code = FLDMMDL_GetObjCode((void *)mmdl);
    FIELD_G3DOBJ_DeleteObject(cont->objCtrl, objIdx);
    if (FLDMMDL_CheckSameObjCodeOther((void *)mmdl, code) == 0) {
        FLDMMDL_G3DOBJ_DeleteResByCode(cont, code);
    }
}
