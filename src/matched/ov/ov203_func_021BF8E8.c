/*
 * function: func_021BF8E8
 * address: 0x021BF8E8
 * packet: pkt_ov203_021BF8E8
 * region: ov203
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   TCBL_Create 0x0203101C arm
 *   GF_FONT_Create 0x0201D7EC thumb
 *   func_020490F4 0x020490F4 arm
 *   func_02012FFC 0x02012FFC thumb
 */
#include "../include/Obj01776.h"
struct Tcbl;struct GfFont;
typedef unsigned short u16;
extern struct Tcbl *TCBL_Create(u16 heap, u16 tag, unsigned int count, unsigned int workSize);
extern struct GfFont *GF_FONT_Create(int,int,int,int,unsigned);
typedef unsigned int   u32;
extern void *func_020490F4(u32 id, u32 heap);
extern signed char func_02012FFC(void);
void func_021BF8E8(char *p){*(struct Tcbl * *)&((struct Obj01776 *)p)->f20=TCBL_Create(((struct Obj01776 *)p)->f0,((struct Obj01776 *)p)->f0,16,128);*(struct GfFont * *)&((struct Obj01776 *)p)->f24=GF_FONT_Create(23,0,0,0,((struct Obj01776 *)p)->f0);((struct Obj01776 *)p)->f28=func_020490F4(161,((struct Obj01776 *)p)->f0);p[0x18]=func_02012FFC();}
