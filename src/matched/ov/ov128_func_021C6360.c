/*
 * function: Wf2dmapFriend_Setup
 * address: 0x021C6360
 * packet: pkt_ov128_021C6360
 * region: ov128
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   Wf2dmapFriend_InitGfx 0x021C658C thumb ov128
 *   Wf2dmapFriend_Proc 0x021C6354 thumb ov128
 *   func_020056A0 0x020056A0 thumb
 */
#include "../include/Obj08125.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void Wf2dmapFriend_InitGfx(char *,void *,int);
extern void Wf2dmapFriend_Proc(void *,char *);
extern void *func_020056A0(void *,void *,int);
void Wf2dmapFriend_Setup(char *p,int heap) {Wf2dmapFriend_InitGfx(p+4,p+0x190,heap); if(!((struct Obj08125 *)p)->f5A8) ((struct Obj08125 *)p)->f5A8=func_020056A0(Wf2dmapFriend_Proc,p,16);}
