/*
 * function: Wf2dmapFriend_DeleteGfx
 * address: 0x021C6664
 * packet: pkt_ov128_021C6664
 * region: ov128
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   WF2DMAP_TOUCH_DeletePalAnims 0x021CA10C thumb ov128
 *   Wf2dmapFriend_DeleteListActors 0x021C6DAC thumb ov128
 *   Wf2dmapFriend_DeleteBmps 0x021C6AC0 thumb ov128
 *   Wf2dmapFriend_DeleteWindows 0x021C6A5C thumb ov128
 *   Wf2dmapFriend_DeleteFont 0x021C6980 thumb ov128
 *   Wf2dmapFriend_DeleteActors 0x021C68C4 thumb ov128
 *   Wf2dmapFriend_DeleteBg 0x021C6790 thumb ov128
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 */
#include "../include/Obj00725.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void WF2DMAP_TOUCH_DeletePalAnims(u8 *);
extern void Wf2dmapFriend_DeleteListActors(u8 *);
extern void Wf2dmapFriend_DeleteBmps(u8 *);
extern void Wf2dmapFriend_DeleteWindows(u8 *);
extern void Wf2dmapFriend_DeleteFont(u8 *);
extern void Wf2dmapFriend_DeleteActors(char *p);
extern void Wf2dmapFriend_DeleteBg(u8 *);
extern void ARC_TOOL_DeleteHandle(void *);
void Wf2dmapFriend_DeleteGfx(u8 *p) {WF2DMAP_TOUCH_DeletePalAnims(p);Wf2dmapFriend_DeleteListActors(p);Wf2dmapFriend_DeleteBmps(p);Wf2dmapFriend_DeleteWindows(p);Wf2dmapFriend_DeleteFont(p);Wf2dmapFriend_DeleteActors((char *)p);Wf2dmapFriend_DeleteBg(p);ARC_TOOL_DeleteHandle(((struct Obj00725 *)p)->f8);}
