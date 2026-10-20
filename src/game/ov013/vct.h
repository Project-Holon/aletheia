#ifndef GAME_OV013_VCT_H
#define GAME_OV013_VCT_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of vct.c, prototypes copied from their definitions. */

#include "../ov013/vct_types.h"

int VCT_Init(VctInitParams *params);
void VCT_Exit(void);
void VCT_Update(void);
int VCT_ReceiveFrame(int senderId, VctFrameHeader *frame, int length);
int VCT_ParseFrame(int senderId, VctFrameHeader *header, int length, VctEvent *eventOut);
/* END mkheaders: generated region */

#endif
