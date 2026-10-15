/*
 * function: PLIST_MESSAGE_DestroyWordSet
 * address: 0x021BB98C
 * packet: pkt_ov091_021BB98C
 * region: ov091
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   WORDSET_DeleteStrbufED04 0x0201ED04 thumb
 */
#include "../include/Obj13253.h"
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;
struct WordSet;
extern u32 WORDSET_DeleteStrbufED04(struct WordSet *p);
void PLIST_MESSAGE_DestroyWordSet(void *p,u32 s) { WORDSET_DeleteStrbufED04((struct WordSet *)(((struct Obj13253 *)s)->f2C)); ((struct Obj13253 *)s)->f2C=0; }
