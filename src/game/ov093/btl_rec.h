#ifndef GAME_OV093_BTL_REC_H
#define GAME_OV093_BTL_REC_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of btl_rec.c, prototypes copied from their definitions. */

#include "../ov093/btl_rec_types.h"
#include "../types.h"

BtlRecBuffer *BTL_REC_CreateBuffer(u32 heapId);
void BTL_REC_DeleteBuffer(BtlRecBuffer *buffer);
void BTL_REC_AppendPacket(BtlRecBuffer *buffer, const u8 *src, int size);
u8 BTL_REC_GetPacketId(u8 *src);
u8 *BTL_REC_ReadEntry(BtlRecBuffer *buffer, u32 *outSize);
void BTL_REC_InitReader(BtlRecReader *reader, u8 *bytes, u32 size);
void BTL_REC_ResetReader(BtlRecReader *reader);
int BTL_REC_ReadSkipFlag(BtlRecReader *reader, int channel);
u32 *BTL_REC_ReadRecord(BtlRecReader *reader, u32 channel, u8 *outSize, u8 *outFlag);
int BTL_REC_CountFlaggedRecords(BtlRecReader *reader);
int BTL_REC_IsChannelDone(BtlRecReader *reader, int channel);
void BTL_REC_InitPacket(BtlRecPacket *packet, int flag);
u8 *BTL_REC_MakeSkipPacket(BtlRecPacket *packet, u32 *outSize, int flag);
void BTL_REC_AddRecord(BtlRecPacket *packet, u8 channel, const void *words, u32 count);
u8 *BTL_REC_FinishPacket(BtlRecPacket *packet, u8 id, u32 *outSize);
u8 *BTL_REC_MakeResetPacket(BtlRecPacket *packet, u32 *outSize);
void BTL_REC_LoadPacket(BtlRecPacket *packet, const void *src, int size);
int BTL_REC_NextRecord(BtlRecPacket *packet, u32 *pos, u8 *outChannel, u8 *outWords, u32 *dst);
/* END mkheaders: generated region */

#endif
