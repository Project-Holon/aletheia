/*
 * unit: no
 * function: func_0220D6AC
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
 *   func_0201F250 0x0201F250 thumb
 *   STRBUF_Delete 0x02045808 arm
 *   func_0220E13C 0x0220E13C thumb ov198
 */
#include "../include/Obj02247.h"
typedef unsigned char u8;typedef unsigned short u16;typedef unsigned int u32;
struct MsgBank;struct WordSet;struct U16Vec;extern void *func_02045EC0(struct MsgBank *,u32);extern void func_0201F250(struct WordSet *,void *,void *);extern void STRBUF_Delete(struct U16Vec *);extern void func_0220E13C(u8 *);
void func_0220D6AC(u8 *p){void *s=func_02045EC0(*(struct MsgBank * *)&((struct Obj02247 *)p)->f1EA0,70);func_0201F250(*(struct WordSet * *)&((struct Obj02247 *)p)->f1EA4,((struct Obj02247 *)p)->f1EA8,s);STRBUF_Delete(s);func_0220E13C(p);}
