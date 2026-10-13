/*
 * function: IRC_RANKING_DataDelete
 * address: 0x021B8D5C
 * packet: pkt_ov106_021B8D5C
 * region: ov106
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * trailing: two-byte alignment padding, no follower.
 * symbols:
 *   STRBUF_Delete 0x02045808 arm
 *   func_020307B0 0x020307B0 arm
 */
#include "../include/Obj13760.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct U16Vec;
extern void STRBUF_Delete(struct U16Vec *);
extern u32 func_020307B0(void *p);
void IRC_RANKING_DataDelete(u8 *p) { u32 i; if (((struct Obj13760 *)p)->f0 != 0) { for(i=0;i<((struct Obj13760 *)p)->f0;i++) { struct U16Vec *v; v=*(struct U16Vec **)(p+4+i*16); if(v) STRBUF_Delete(v); } } func_020307B0(p); }
