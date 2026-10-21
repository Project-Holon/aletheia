#ifndef GAME_OV021_FLDMMDL_G3DOBJ_H
#define GAME_OV021_FLDMMDL_G3DOBJ_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of fldmmdl_g3dobj.c, prototypes copied from their definitions. */

struct MmdlSys;
struct FieldG3dObjCtrl;
struct Mmdl;

#include "../ov010/fldmmdl_types.h"
#include "../types.h"

void FLDMMDL_G3DOBJ_Create(struct MmdlSys *mmdlSys, struct FieldG3dObjCtrl *objCtrl);
void FLDMMDL_G3DOBJ_Delete(struct MmdlSys *mmdlSys);
struct FieldG3dObjCtrl *FLDMMDL_G3DOBJ_GetObjCtrl(Mmdl *mmdl);
u32 FLDMMDL_G3DOBJ_AddObj(struct Mmdl *mmdl);
void FLDMMDL_G3DOBJ_DelObj(struct Mmdl *mmdl, u32 objIdx);
/* END mkheaders: generated region */

#endif
