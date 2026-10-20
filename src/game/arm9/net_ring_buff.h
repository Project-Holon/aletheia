#ifndef GAME_ARM9_NET_RING_BUFF_H
#define GAME_ARM9_NET_RING_BUFF_H

/* Public functions of net_ring_buff.c, prototypes copied from their definitions. */

#include "../arm9/net_types.h"
#include "../types.h"

void GFL_NET_RING_BUFF_Init(NetRingBuff *ring, u8 *buf, int size);
void GFL_NET_RING_BUFF_Write(NetRingBuff *ring, const u8 *pDataArea, int size);
int GFL_NET_RING_BUFF_Read(NetRingBuff *ring, u8 *dst, u32 size, u32 max);
u32 GFL_NET_RING_BUFF_ReadByte(NetRingBuff *ring);
u32 GFL_NET_RING_BUFF_ReadU16(NetRingBuff *ring);
int GFL_NET_RING_BUFF_Peek(const NetRingBuff *ring, u8 *dst, int size, int max);
int GFL_NET_RING_BUFF_GetDataSize(NetRingBuff *ring);
int GFL_NET_RING_BUFF_GetFreeSize(NetRingBuff *ring);
int GFL_NET_RING_BUFF_WrapPos(const NetRingBuff *ring, int pos);
int GFL_NET_RING_BUFF_GetWritableSize(NetRingBuff *ring);
void GFL_NET_RING_BUFF_EndChange(NetRingBuff *ring);

#endif
