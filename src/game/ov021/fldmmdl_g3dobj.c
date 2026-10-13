/*
 * file:     fldmmdl_g3dobj.c
 * unit:     yes
 * function: func_0219D448, func_0219D488, func_0219D49C, func_0219D4AC, func_0219D4EC, func_0219D524, func_0219D558, func_0219D584, func_0219D604, func_0219D634, func_0219D680
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
 *   func_0216D4F8  0x0216D4F8  thumb  ov010
 *   func_020307B0  0x020307B0  arm
 *   func_0216D67C  0x0216D67C  thumb  ov010
 *   func_0216E3C4  0x0216E3C4  thumb  ov010
 *   func_0216DFC4  0x0216DFC4  thumb  ov010
 *   func_0216D598  0x0216D598  thumb  ov010
 *   func_02030734  0x02030734  arm
 *   func_0216D518  0x0216D518  thumb  ov010
 *   func_0216D4F0  0x0216D4F0  thumb  ov010
 *   func_0216D524  0x0216D524  thumb  ov010
 *   d_021DDD80     0x021DDD80  data ov021 a4
 *   func_0216D528  0x0216D528  thumb  ov010
 *   func_021C6580  0x021C6580  thumb  ov021
 *   func_021C6AE0  0x021C6AE0  thumb  ov021
 *   func_021C6AF0  0x021C6AF0  thumb  ov021
 *   func_021C6AF8  0x021C6AF8  thumb  ov021
 *   func_021C6AFC  0x021C6AFC  thumb  ov021
 *   func_021C6574  0x021C6574  thumb  ov021
 *   func_0216E3CC  0x0216E3CC  thumb  ov010
 *   func_021C6590  0x021C6590  thumb  ov021
 *   func_021C6628  0x021C6628  thumb  ov021
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
extern u32 func_0216D4F8(u8 *p);
extern u32 func_020307B0(void *p);
extern void *func_0216D67C(void *a0);
extern void *func_0216E3C4(void *p);
extern int func_0216DFC4(void *a, u32 id);
extern u16 func_0216D598(void *p);
extern void *func_02030734(unsigned int heapId, unsigned int size, int clear, const char *site, unsigned short tag);
extern u32 func_0216D518(u8 *p);
extern u16 func_0216D4F0(void *p);
extern void func_0216D524(void *p, void *v);
extern u32 func_0216D528(u8 *p);
extern void func_021C6580(u8 *p, int i);
extern void func_021C6AE0(u32 a);
extern void func_021C6AF0(u32 *, u32, u16);
extern void func_021C6AF8(u32 *p, u32 v);
extern void func_021C6AFC(u32 *, u16);
extern u32 func_021C6574(u32, u32 *, u32);
extern u8 *func_0216E3CC(u8 *p);
extern u32 func_021C6590(u32, u32, u32, u32);
extern void func_021C6628(u32, u32);
void func_0219D448(int a, int b);
void func_0219D488(u32 a);
u32 func_0219D49C(u32 a);
void func_0219D4AC(MmdlG3dObjCont *cont, int heapId);
void func_0219D4EC(MmdlG3dObjCont *cont);
u16 func_0219D524(MmdlG3dObjCont *cont, u32 code, u32 resIdx);
u16 func_0219D558(MmdlG3dObjCont *cont, u16 code);
u32 func_0219D584(u32 mmdlSys, MmdlG3dObjCont *cont, u32 code, u16 *resParam);
void func_0219D604(MmdlG3dObjCont *cont, u16 code);
u32 func_0219D634(u32 a);
void func_0219D680(u32 a, u32 b);
extern unsigned char d_021DDD80[];



















void func_0219D448(int mmdlSys, int objCtrl)
{
    int heapId;
    MmdlG3dObjCont *cont;
    heapId = func_0216D4F8((u8 *)mmdlSys);
    cont = (MmdlG3dObjCont *)func_02030734(heapId, sizeof(MmdlG3dObjCont), 1, (const char *)d_021DDD80, 0x48);
    cont->mmdlSys = mmdlSys;
    cont->objCtrl = objCtrl;
    cont->resMax = func_0216D4F0((void *)mmdlSys);
    func_0219D4AC(cont, heapId);
    func_0216D524((void *)mmdlSys, cont);
}
void func_0219D488(u32 mmdlSys)
{
    MmdlG3dObjCont *cont = (MmdlG3dObjCont *)func_0216D528((u8 *)mmdlSys);
    func_0219D4EC(cont);
    func_020307B0(cont);
}
u32 func_0219D49C(u32 mmdl)
{
    return ((MmdlG3dObjCont *)func_0216D528((u8 *)((u32)func_0216D67C((void *)mmdl))))->objCtrl;
}
/* Allocates resMax entries and marks every entry free (code 0xFFFF). */
void func_0219D4AC(MmdlG3dObjCont *cont, int heapId)
{
    int i;
    cont->resTable = (MmdlG3dObjRes *)func_02030734(heapId, cont->resMax * 4, 1, (const char *)d_021DDD80, 0x7f);
    for (i = 0; i < (int)cont->resMax; i++) {
        cont->resTable[i].code = 0xFFFF;
    }
}
void func_0219D4EC(MmdlG3dObjCont *cont)
{
    int i = 0;
    MmdlG3dObjRes *res = cont->resTable;
    if (i < cont->resMax) {
        for (; i < cont->resMax; i++, res++) {
            if (res->code != 0xFFFF) {
                func_021C6580((u8 *)cont->objCtrl, res->resIdx);
            }
        }
    }
    func_020307B0(cont->resTable);
}
u16 func_0219D524(MmdlG3dObjCont *cont, u32 code, u32 resIdx)
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
u16 func_0219D558(MmdlG3dObjCont *cont, u16 code)
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
u32 func_0219D584(u32 mmdlSys, MmdlG3dObjCont *cont, u32 code, u16 *resParam)
{
    u32 resDesc[9];
    u32 heapId;
    u32 resIdx;
    int i;
    heapId = func_0216D518((u8 *)mmdlSys);
    func_021C6AE0((u32)resDesc);
    if (resParam[0] != 0xFFFF) {
        func_021C6AF0(resDesc, heapId, resParam[0]);
    }
    if (resParam[1] != 0xFFFF) {
        func_021C6AF0(resDesc, heapId, resParam[1]);
    }
    func_021C6AF8((u32 *)resDesc, heapId);
    for (i = 0; i < 3; i++) {
        if (resParam[i + 2] != 0xFFFF) {
            func_021C6AFC(resDesc, resParam[i + 2]);
        }
    }
    resIdx = func_021C6574(cont->objCtrl, resDesc, 0);
    func_0219D524(cont, code, resIdx);
    return resIdx;
}
void func_0219D604(MmdlG3dObjCont *cont, u16 code)
{
    int i;
    int max = cont->resMax;
    MmdlG3dObjRes *res = cont->resTable;
    for (i = 0; i < max; i++, res++) {
        if (res->code == code) {
            func_021C6580((u8 *)cont->objCtrl, res->resIdx);
            res->code = 0xFFFF;
            return;
        }
    }
}
u32 func_0219D634(u32 mmdl)
{
    u16 *objCode;
    u32 mmdlSys;
    MmdlG3dObjCont *cont;
    u32 resIdx;
    objCode = func_0216E3C4((void *)mmdl);
    mmdlSys = (u32)func_0216D67C((void *)mmdl);
    cont = (MmdlG3dObjCont *)func_0216D528((u8 *)mmdlSys);
    resIdx = func_0219D558(cont, *objCode);
    if (resIdx == 0xFFFF) {
        resIdx = func_0219D584(mmdlSys, cont, *objCode, (u16 *)func_0216E3CC((u8 *)objCode));
    }
    return func_021C6590(cont->objCtrl, resIdx, 0, 0);
}
void func_0219D680(u32 mmdl, u32 objIdx)
{
    MmdlG3dObjCont *cont = (MmdlG3dObjCont *)func_0216D528(func_0216D67C((void *)mmdl));
    u16 code = func_0216D598((void *)mmdl);
    func_021C6628(cont->objCtrl, objIdx);
    if (func_0216DFC4((void *)mmdl, code) == 0) {
        func_0219D604(cont, code);
    }
}
