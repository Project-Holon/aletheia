/*
 * unit: no
 * function: GURU2_MAIN_DeleteNameWindows
 * address: 0x021E03A0
 * packet: pkt_ov137_021E03A0
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   BMP_WIN_ClearScreen 0x020456F8 arm
 *   BMP_WIN_GetBgLayer 0x02045730 arm
 *   func_020409B4 0x020409B4 arm
 *   BMP_WIN_Delete 0x020452E8 arm
 */
#include "../include/Obj14230.h"
#include "../include/Obj23774.h"
typedef unsigned char u8;typedef unsigned short u16;typedef unsigned int u32;
struct Descriptor;struct Cfg;struct CharBuf;struct Bank;struct Util;struct Setup;struct Ctx;
extern void BMP_WIN_ClearScreen(struct Descriptor *);
extern u8 BMP_WIN_GetBgLayer(struct Descriptor *);
extern void func_020409B4(u32);
extern u32 BMP_WIN_Delete(struct Descriptor *d);
void GURU2_MAIN_DeleteNameWindows(u8 *p){int i;u8 *s=p+0xce0;for(i=0;i<((struct Obj23774 *)s)->f0;i++){u8 *q=s+(u32)i*4;struct Descriptor *w=*(struct Descriptor * *)&((struct Obj14230 *)q)->f14;BMP_WIN_ClearScreen(w);func_020409B4(BMP_WIN_GetBgLayer(w));BMP_WIN_Delete(*(struct Descriptor * *)&((struct Obj14230 *)q)->f14);}}
