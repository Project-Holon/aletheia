/*
 * function: PLIST_MESSAGE_CreateWordSet
 * address: 0x021BB97C
 * packet: pkt_ov091_021BB97C
 * region: ov091
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_0201EC64 0x0201EC64 thumb
 */
#include "../include/Obj20889.h"
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;
struct WordSet;
extern struct WordSet *func_0201EC64(u32 heap);
void PLIST_MESSAGE_CreateWordSet(u16 *p,u32 s) { ((struct Obj20889 *)s)->f2C=(u32)func_0201EC64(*p); }
