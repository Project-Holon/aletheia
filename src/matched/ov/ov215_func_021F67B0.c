/*
 * function: func_021F67B0
 * address: 0x021F67B0
 * packet: pkt_ov215_021F67B0
 * region: ov215
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * trailing: zero halfword at 021F67DE is alignment padding.
 * symbols:
 *   func_021F7028 0x021F7028 thumb ov215
 *   func_021F6F18 0x021F6F18 thumb ov215
 *   func_021F6E4C 0x021F6E4C thumb ov215
 *   func_021F6CAC 0x021F6CAC thumb ov215
 *   func_021F6AE0 0x021F6AE0 thumb ov215
 *   sub_02030EAC 0x02030EAC arm
 *   func_020307B0 0x020307B0 arm
 */
#include "../include/Obj04636.h"
struct Node;
extern void func_021F7028(char *);
extern void func_021F6F18(char *);
extern void func_021F6E4C(char *);
extern void func_021F6CAC(char *);
extern void func_021F6AE0(char *);
extern void sub_02030EAC(struct Node *);
extern void func_020307B0(void *);
void func_021F67B0(char *p){func_021F7028(p);func_021F6F18(p);func_021F6E4C(*(char * *)&((struct Obj04636 *)p)->f44);func_021F6CAC(p);func_021F6AE0(p);sub_02030EAC(*(struct Node * *)&((struct Obj04636 *)p)->f2C);func_020307B0(p);}
