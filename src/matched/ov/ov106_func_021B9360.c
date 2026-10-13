/*
 * function: func_021B9360
 * address: 0x021B9360
 * packet: pkt_ov106_021B9360
 * region: ov106
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   BMP_OAM_Delete 0x0202570C thumb
 *   BMP_Delete 0x020437AC arm
 *   STRBUF_Delete 0x02045808 arm
 *   func_020307B0 0x020307B0 arm
 */
#include "../include/Obj10256.h"
typedef unsigned char u8;typedef unsigned short u16;typedef unsigned int u32;
struct Grid;
struct Obj020437AC;
struct U16Vec;
extern void BMP_OAM_Delete(struct Grid *g);
extern void BMP_Delete(struct Obj020437AC *p);
extern void STRBUF_Delete(struct U16Vec *vec);
extern u32 func_020307B0(void *p);
void func_021B9360(u8 *p) { BMP_OAM_Delete(((struct Obj10256 *)p)->f1C); BMP_Delete(((struct Obj10256 *)p)->f0); STRBUF_Delete(((struct Obj10256 *)p)->f18); func_020307B0(p); }
