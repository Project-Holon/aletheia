#ifndef GAME_OV021_FLDMMDL_G3DOBJ_H
#define GAME_OV021_FLDMMDL_G3DOBJ_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of fldmmdl_g3dobj.c, prototypes copied from their definitions. */

struct MmdlSys;
struct Mmdl;

#include "../types.h"

void FLDMMDL_G3DOBJ_Create(int mmdlSys, int objCtrl);
void FLDMMDL_G3DOBJ_Delete(struct MmdlSys *mmdlSys);
u32 FLDMMDL_G3DOBJ_GetObjCtrl(u32 mmdl);
u32 FLDMMDL_G3DOBJ_AddObj(struct Mmdl *mmdl);
void FLDMMDL_G3DOBJ_DelObj(struct Mmdl *mmdl, u32 objIdx);
/* END mkheaders: generated region */

#endif
