/*
 * function: BEACON_VIEW_SetupMessageText
 * address: 0x021F0A98
 * packet: pkt_ov032_021F0A98
 * region: ov032
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   MSGDATA_ReadString 0x02045CAC arm
 *   WORDSET_CopyTaggedText 0x0201F250 thumb
 */
#include "../include/Obj00007.h"
typedef unsigned int   u32;
struct MsgBank;
struct WordSet;
extern void MSGDATA_ReadString(struct MsgBank *bank, u32 index, void *dest);
extern void WORDSET_CopyTaggedText(struct WordSet *ws, void *dst, void *src);
void BEACON_VIEW_SetupMessageText(char *p,unsigned a) { MSGDATA_ReadString(((struct Obj00007 *)p)->f114,a,((struct Obj00007 *)p)->f118); WORDSET_CopyTaggedText(((struct Obj00007 *)p)->f110,((struct Obj00007 *)p)->f11C,((struct Obj00007 *)p)->f118); }
