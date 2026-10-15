/*
 * unit: no
 * function: B_PLIST_DRAW_PrintWordAndRefresh
 * address: 0x0220D6AC
 * packet: pkt_ov198_0220D6AC
 * region: ov198
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02045EC0 0x02045EC0 arm
 *   WORDSET_CopyTaggedText 0x0201F250 thumb
 *   STRBUF_Delete 0x02045808 arm
 *   B_PLIST_DRAW_ClearAndPrintStream 0x0220E13C thumb ov198
 */
#include "../include/Obj02247.h"
typedef unsigned char u8;typedef unsigned short u16;typedef unsigned int u32;
struct MsgBank;struct WordSet;struct U16Vec;extern void *func_02045EC0(struct MsgBank *,u32);extern void WORDSET_CopyTaggedText(struct WordSet *,void *,void *);extern void STRBUF_Delete(struct U16Vec *);extern void B_PLIST_DRAW_ClearAndPrintStream(u8 *);
void B_PLIST_DRAW_PrintWordAndRefresh(u8 *p){void *s=func_02045EC0(*(struct MsgBank * *)&((struct Obj02247 *)p)->f1EA0,70);WORDSET_CopyTaggedText(*(struct WordSet * *)&((struct Obj02247 *)p)->f1EA4,((struct Obj02247 *)p)->f1EA8,s);STRBUF_Delete(s);B_PLIST_DRAW_ClearAndPrintStream(p);}
