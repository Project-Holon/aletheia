/*
 * function: WORLDTRADE_BOX_DeleteStrings
 * address: 0x021F59E8
 * packet: pkt_ov135_021F59E8
 * region: ov135
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020307B0 0x020307B0 arm
 *   STRBUF_Delete 0x02045808 arm
 */
#include "../include/Obj00287.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u32 func_020307B0(void *p);
struct U16Vec;
extern void STRBUF_Delete(struct U16Vec *vec);
void WORLDTRADE_BOX_DeleteStrings(char *p) { func_020307B0(((struct Obj00287 *)p)->fEAC); STRBUF_Delete(((struct Obj00287 *)p)->fB80); STRBUF_Delete(((struct Obj00287 *)p)->fB88); STRBUF_Delete(((struct Obj00287 *)p)->fB84); }
