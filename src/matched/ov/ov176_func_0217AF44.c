/*
 * function: BATTLE_CHAMPIONSHIP_FLOW_DeleteView
 * address: 0x0217AF44
 * packet: pkt_ov176_0217AF44
 * region: ov176
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   WIFIBATTLEMATCH_VIEW_Delete 0x021E5868 thumb ov177
 */
#include "../include/Obj03869.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void WIFIBATTLEMATCH_VIEW_Delete(void *);
void BATTLE_CHAMPIONSHIP_FLOW_DeleteView(int *p) {WIFIBATTLEMATCH_VIEW_Delete(((struct Obj03869 *)p)->f20);}
