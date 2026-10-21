#ifndef GAME_OV021_FLDMMDL_G3DOBJ_H
#define GAME_OV021_FLDMMDL_G3DOBJ_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of fldmmdl_g3dobj.c, prototypes copied from their definitions. */

struct MmdlSys;
struct MmdlG3dObjCont;
struct Mmdl;
typedef struct MmdlG3dObjCont MmdlG3dObjCont;

#include "../types.h"

void FLDMMDL_G3DOBJ_Create(int mmdlSys, int objCtrl);
void FLDMMDL_G3DOBJ_Delete(struct MmdlSys *mmdlSys);
u32 FLDMMDL_G3DOBJ_GetObjCtrl(u32 mmdl);
void FLDMMDL_G3DOBJ_InitResTable(MmdlG3dObjCont *cont, int heapId);
void FLDMMDL_G3DOBJ_DeleteResTable(MmdlG3dObjCont *cont);
u16 FLDMMDL_G3DOBJ_AddResEntry(MmdlG3dObjCont *cont, u32 code, u32 resIdx);
u16 FLDMMDL_G3DOBJ_FindResIdx(MmdlG3dObjCont *cont, u16 code);
u32 FLDMMDL_G3DOBJ_LoadRes(u32 mmdlSys, MmdlG3dObjCont *cont, u32 code, u16 *resParam);
void FLDMMDL_G3DOBJ_DeleteResByCode(MmdlG3dObjCont *cont, u16 code);
u32 FLDMMDL_G3DOBJ_AddObj(struct Mmdl *mmdl);
void FLDMMDL_G3DOBJ_DelObj(struct Mmdl *mmdl, u32 objIdx);
/* END mkheaders: generated region */

#endif
