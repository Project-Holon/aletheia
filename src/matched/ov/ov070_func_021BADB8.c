/*
 * function: ITEMMENU_ShowItemUseMessage
 * address: 0x021BADB8
 * packet: pkt_ov070_021BADB8
 * region: ov070
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   MSGDATA_ReadString 0x02045CAC arm
 *   ITEMMENU_RegisterItemName 0x021B61F4 thumb ov070
 *   WORDSET_CopyTaggedText 0x0201F250 thumb
 */
#include "../include/Obj06177.h"
typedef unsigned int   u32;
struct MsgBank;
extern void MSGDATA_ReadString(struct MsgBank *bank, u32 index, void *dest);
typedef unsigned char  u8;
extern void ITEMMENU_RegisterItemName(u8 *p, int a, unsigned int b);
struct WordSet;
extern void WORDSET_CopyTaggedText(struct WordSet *ws, void *dst, void *src);
void ITEMMENU_ShowItemUseMessage(char *p, unsigned v) { MSGDATA_ReadString((struct MsgBank *)(((struct Obj06177 *)p)->f51C), 0x2B, (void *)(*(int *)&((struct Obj06177 *)p)->f524)); ITEMMENU_RegisterItemName((u8 *)p, 0, v); WORDSET_CopyTaggedText(((struct Obj06177 *)p)->f520, ((struct Obj06177 *)p)->f528, ((struct Obj06177 *)p)->f524); }
