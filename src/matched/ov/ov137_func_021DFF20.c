/*
 * unit: no
 * function: GURU2_MAIN_BlendPalette
 * address: 0x021DFF20
 * packet: pkt_ov137_021DFF20
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   PALANM_BlendChannelMask 0x02022004 thumb
 */
#include "../include/Obj23771.h"
typedef unsigned char u8;typedef unsigned short u16;typedef unsigned int u32;
struct Descriptor;struct Cfg;struct CharBuf;struct Bank;struct Util;struct Setup;struct Ctx;
extern void PALANM_BlendChannelMask(u32,u32,u16,u32,u32);
void GURU2_MAIN_BlendPalette(u8 *p,int a){PALANM_BlendChannelMask(((struct Obj23771 *)p)->fD78,1,65535,(u8)a,0);}
