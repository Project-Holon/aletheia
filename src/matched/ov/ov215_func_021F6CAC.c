/*
 * function: func_021F6CAC
 * address: 0x021F6CAC
 * packet: pkt_ov215_021F6CAC
 * region: ov215
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * trailing: existing follower 021F6CC0 in its own matched shard.
 * symbols:
 *   func_02015EA0 0x02015EA0 thumb
 *   sub_02015BA4 0x02015BA4 thumb
 */
#include "../include/Obj10941.h"

extern void func_02015EA0(void *);
extern void sub_02015BA4(void *,void *);
void func_021F6CAC(char *p){func_02015EA0(((struct Obj10941 *)p)->f34);sub_02015BA4(((struct Obj10941 *)p)->f30,((struct Obj10941 *)p)->f34);}
