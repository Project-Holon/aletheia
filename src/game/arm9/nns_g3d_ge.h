#ifndef GAME_ARM9_NNS_G3D_GE_H
#define GAME_ARM9_NNS_G3D_GE_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of nns_g3d_ge.c, prototypes copied from their definitions. */

#include "../types.h"

int NNS_G3dGeIsBufferExist(void);
void NNS_G3dGeSetBuffer(u32 *cmdBuffer);
void *NNS_G3dGeReleaseBuffer(void);
void NNS_G3dGeFlushBuffer(void);
void NNS_G3dGeWaitSendDL(void);
void NNSi_G3dGeSendDLDone(void *arg);
void NNS_G3dGeSendDL(const u32 *src, u32 sz);
void NNS_G3dGeBufferOP_N(u32 cmd, const void *params, u32 n);
void NNS_G3dGeResetGX(void *clipMtxOut, void *vectorMtxOut);
/* END mkheaders: generated region */

#endif
