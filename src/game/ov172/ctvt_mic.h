#ifndef GAME_OV172_CTVT_MIC_H
#define GAME_OV172_CTVT_MIC_H

#include "../arm9/mic.h"

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of ctvt_mic.c, prototypes copied from their definitions. */

struct CtvtMic;

#include "../ov172/ctvt_types.h"
#include "../types.h"

CtvtMic *CTVT_MIC_Create(u16 heap);
void CTVT_MIC_Delete(CtvtMic *mic);
void CTVT_MIC_Update(CtvtMic *mic);
void CTVT_MIC_SetMode(struct CtvtMic *mode);
void CTVT_MIC_OnVBlank(void *unused0);
int CTVT_MIC_StartCapture(CtvtMic *mic);
void CTVT_MIC_OnCaptureComplete(MICResult result, void *arg);
int CTVT_MIC_StopCapture(CtvtMic *mic);
u32 CTVT_MIC_IsCapturing(CtvtMic *mic);
u32 CTVT_MIC_GetReadyBytes(CtvtMic *mic);
void *CTVT_MIC_GetBuffer(CtvtMic *mic);
int CTVT_MIC_EncodeAdpcm(struct CtvtMic *unused, void *a, void *buf, unsigned n);
int CTVT_MIC_DecodeAdpcm(void *unused, char *a, void *buf, unsigned n);
void CTVT_MIC_InitChannel(CtvtMic *mic, u32 heap);
void CTVT_MIC_FreeChannel(CtvtMic *mic);
void CTVT_MIC_PostUpdate(CtvtMic *mic);
int CTVT_MIC_PlayVoice(CtvtMic *mic, char *buf, unsigned n, int vol, int freq);
void CTVT_MIC_StopVoice(CtvtMic *mic);
u32 CTVT_MIC_GetPlayState(CtvtMic *mic);
int CTVT_MIC_GetLength(CtvtMic *mic);
int CTVT_MIC_GetPlayPos(CtvtMic *mic);
int CTVT_MIC_GetPlayRatio(CtvtMic *mic);
int CTVT_MIC_IsCaptureDone(CtvtMic *mic);
/* END mkheaders: generated region */

#endif
