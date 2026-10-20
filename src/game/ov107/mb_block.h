#ifndef GAME_OV107_MB_BLOCK_H
#define GAME_OV107_MB_BLOCK_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of mb_block.c, prototypes copied from their definitions. */

#include "../types.h"
#include "../ov107/mb_block_types.h"

void MBi_SetChildMPMaxSize(u16 childMaxSize);
void MBi_SetParentPieceBuffer(void *buf);
void MBi_ClearParentPieceBuffer(u16 child_aid);
u8 *MBi_MakeParentSendBuffer(const MBCommParentBlockHeader *hdr, u8 *sendbuf);
u8 *MBi_SetRecvBufferFromChild(u8 *recvbuf, MBCommChildBlockHeader *hdr, u16 child_id);
u8 *MBi_ReceiveRequestDataPiece(MBCommChildBlockHeader *hdr, u16 child);
int IsGetAllRequestData(int a);
/* END mkheaders: generated region */

#endif
