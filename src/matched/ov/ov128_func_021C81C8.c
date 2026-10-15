/*
 * function: Wf2dmapFriend_ItemInput
 * address: 0x021C81C8
 * packet: pkt_ov128_021C81C8
 * region: ov128
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   Wf2dmapFriend_ItemTouchInput 0x021C8100 thumb ov128
 *   func_020355D8 0x020355D8 arm
 *   Wf2dmapFriend_ItemKeyInput 0x021C7F14 thumb ov128
 */
#include "../include/Obj03810.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
extern int Wf2dmapFriend_ItemTouchInput(s16 *,void *,void *,int *);
extern void func_020355D8(u8);
extern int Wf2dmapFriend_ItemKeyInput(s16 *,u8 *,u8 *);
int Wf2dmapFriend_ItemInput(s16 *p,u8 *q,u8 *r) {int changed=0;int ret=Wf2dmapFriend_ItemTouchInput(p,q,r,&changed);if(changed) {func_020355D8(1);((struct Obj03810 *)q)->f0=1;return ret;}return Wf2dmapFriend_ItemKeyInput(p,q,r);}
