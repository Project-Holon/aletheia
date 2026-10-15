/*
 * function: BATTLE_CHAMPIONSHIP_FLOW_DeleteMenu
 * address: 0x0217B344
 * packet: pkt_ov176_0217B344
 * region: ov176
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   WIFIBATTLEMATCH_UTIL_DeleteCallback 0x021E8A78 thumb ov177
 *   MSGDATA_Delete 0x02045C04 arm
 *   func_020307B0 0x020307B0 arm
 */
#include "../include/Obj14356.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void WIFIBATTLEMATCH_UTIL_DeleteCallback(void *);
struct Rec;
extern u32 MSGDATA_Delete(struct Rec *rec);
extern u32 func_020307B0(void *p);
void BATTLE_CHAMPIONSHIP_FLOW_DeleteMenu(int *p) {WIFIBATTLEMATCH_UTIL_DeleteCallback(((struct Obj14356 *)p)->f0);MSGDATA_Delete(((struct Obj14356 *)p)->fC);func_020307B0(p);}
