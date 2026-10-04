/*
 * function: func_021F0A98
 * address: 0x021F0A98
 * packet: pkt_ov032_021F0A98
 * region: ov032
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_02045CAC 0x02045CAC arm
 *   func_0201F250 0x0201F250 thumb
 */
#include "../include/Obj00007.h"
typedef unsigned int   u32;
struct MsgBank;
struct WordSet;
extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
void func_021F0A98(char *p,unsigned a) { func_02045CAC(((struct Obj00007 *)p)->f114,a,((struct Obj00007 *)p)->f118); func_0201F250(((struct Obj00007 *)p)->f110,((struct Obj00007 *)p)->f11C,((struct Obj00007 *)p)->f118); }
