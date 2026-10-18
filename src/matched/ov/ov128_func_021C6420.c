/*
 * function: Wf2dmapFriend_DeleteText
 * address: 0x021C6420
 * packet: pkt_ov128_021C6420
 * region: ov128
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   UI_SetInputMode 0x020355D8 arm
 *   STRBUF_Delete 0x02045808 arm
 */
#include "../include/Obj10482.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void UI_SetInputMode(int);
struct U16Vec;
extern void STRBUF_Delete(struct U16Vec *vec);
void Wf2dmapFriend_DeleteText(u8 *p, void *a1) { UI_SetInputMode(((struct Obj10482 *)p)->f0); STRBUF_Delete(((struct Obj10482 *)p)->f58); STRBUF_Delete(((struct Obj10482 *)p)->f5C); }
