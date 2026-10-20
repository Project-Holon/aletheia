#ifndef GAME_OV203_DEMO3D_CMDSYS_H
#define GAME_OV203_DEMO3D_CMDSYS_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of demo3d_cmdsys.c, prototypes copied from their definitions. */

#include "../ov203/demo3d_data_shared_types.h"

Demo3dCmdContext *DEMO3D_CMDSYS_Create(char *owner,unsigned heap);
void DEMO3D_CMDSYS_Delete(char *p);
void DEMO3D_CMDSYS_Update(Demo3dCmdContext *p,int time,int flag);
void DEMO3D_CMDSYS_Init(char *p);
void DEMO3D_CMDSYS_Release(char *p);
int DEMO3D_CMDSYS_Seek(char *p,char *owner,int *index);
/* END mkheaders: generated region */

#endif
