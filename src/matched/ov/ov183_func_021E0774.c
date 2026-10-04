/*
 * function: func_021E0774
 * address: 0x021E0774
 * packet: pkt_ov183_021E0774
 * region: ov183
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: final two bytes are alignment padding.
 * symbols:
 *   func_02030EAC 0x02030EAC arm
 *   func_021E08E4 0x021E08E4 thumb ov183
 *   func_02049238 0x02049238 arm
 *   func_02051C6C 0x02051C6C arm
 *   func_020307B0 0x020307B0 arm
 */
#include "../include/Obj10751.h"
struct Node;
extern void func_02030EAC(struct Node *n);
extern void func_021E08E4(char *);
extern void func_02049238(void *);
extern void func_02051C6C(void *);
extern void func_020307B0(void *);
void func_021E0774(char *p){func_02030EAC(((struct Obj10751 *)p)->f314);func_021E08E4(p);func_02049238(((struct Obj10751 *)p)->f258);func_02051C6C(((struct Obj10751 *)p)->f294);func_020307B0(p);}
