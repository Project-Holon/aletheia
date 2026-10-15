/*
 * function: MB_COMM_SYS_FreeGameStrings
 * address: 0x021EF74C
 * packet: pkt_ov107_021EF74C
 * region: ov107
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   ov014_id 0x0000000E data
 *   func_02034A5C 0x02034A5C arm
 *   CARD_SetPulledOutCallback 0x020774A0 arm
 *   func_020307B0 0x020307B0 arm
 *   func_02040588 0x02040588 arm
 */
#include "../include/Obj10258.h"
extern void func_02034A5C(int);
extern unsigned char ov014_id[];
extern void CARD_SetPulledOutCallback(int (*callback)(void));
typedef unsigned int   u32;
extern u32 func_020307B0(void *p);
extern void func_02040588(unsigned char which, unsigned char enable);
void MB_COMM_SYS_FreeGameStrings(unsigned char *p) {
 func_02034A5C((int)ov014_id);CARD_SetPulledOutCallback(0);
 func_020307B0(((struct Obj10258 *)p)->f50);func_020307B0(((struct Obj10258 *)p)->f54);
 if(!p[40]) {func_02040588(2,0);func_02040588(0,0);}
 else {func_02040588(5,0);func_02040588(4,0);}
}
