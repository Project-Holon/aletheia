/*
 * function: WORLDTRADE_DEPOSIT_DeleteStrings
 * address: 0x021F79EC
 * packet: pkt_ov135_021F79EC
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
#include "../include/Obj23384.h"
#include "../include/Obj23385.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u32 func_020307B0(void *p);
struct U16Vec;
extern void STRBUF_Delete(struct U16Vec *vec);
void WORLDTRADE_DEPOSIT_DeleteStrings(char *p) { func_020307B0(((struct Obj23384 *)(*(char * *)&((struct Obj00287 *)p)->fE00))->f14); func_020307B0(((struct Obj23385 *)(*(char * *)&((struct Obj00287 *)p)->fE00))->f18); func_020307B0(((struct Obj00287 *)p)->fE00); STRBUF_Delete(((struct Obj00287 *)p)->fB88); }
