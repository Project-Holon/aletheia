/*
 * function: func_021FC734
 * address: 0x021FC734
 * packet: pkt_ov186_021FC734
 * region: ov186
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   BMP_WIN_ClearScreen 0x020456F8 arm
 *   BMP_WIN_Delete 0x020452E8 arm
 *   STRBUF_Delete 0x02045808 arm
 *   func_020307B0 0x020307B0 arm
 */
#include "../include/Obj10791.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Descriptor;
struct U16Vec;
extern void BMP_WIN_ClearScreen(struct Descriptor *d);
extern u32 BMP_WIN_Delete(struct Descriptor *d);
extern void STRBUF_Delete(struct U16Vec *vec);
extern u32 func_020307B0(void *p);
void func_021FC734(u8*p){BMP_WIN_ClearScreen(*(void* *)&((struct Obj10791 *)p)->fC);BMP_WIN_Delete(*(void* *)&((struct Obj10791 *)p)->fC);STRBUF_Delete(*(void* *)&((struct Obj10791 *)p)->f10);func_020307B0(p);}
