#ifndef GAME_OV021_UNION_CHAT_LOG_H
#define GAME_OV021_UNION_CHAT_LOG_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of union_chat.c, prototypes copied from their definitions. */

struct UnionChatLine;
struct UnionChatRing;
typedef struct UnionChatLine UnionChatLine;
typedef struct UnionChatRing UnionChatRing;

#include "../ov012/union_comm_types.h"
#include "../ov012/union_comm_types.h"
#include "../types.h"

void UNION_CHAT_LOG_Add(UnionRoomWork *work, UnionBeaconPc *beaconPc, u16 *chatPms, u8 chatType);
UnionChatLine *UNION_CHAT_LOG_TakeSlot(UnionChatRing *ring);
UnionChatLine *UNION_CHAT_LOG_GetLine(UnionChatRing *ring, u32 index);
int UNION_CHAT_LOG_IsNew(UnionChatRing *ring, const void *mac, u16 chatCount);
/* END mkheaders: generated region */

#endif
