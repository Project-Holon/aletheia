/*
 * function: func_021D4280
 * address: 0x021D4280
 * packet: pkt_ov124_021D4280
 * region: ov124
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_02030EAC 0x02030EAC arm
 *   func_021D485C 0x021D485C thumb ov124
 *   func_021D4698 0x021D4698 thumb ov124
 *   func_021D4504 0x021D4504 thumb ov124
 */
#include "../include/Obj00991.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Node;
extern void func_02030EAC(struct Node *);
extern void func_021D485C(char *);
extern void func_021D4698(char *);
extern void func_021D4504(char *);
void func_021D4280(char *p) {func_02030EAC(*(struct Node * *)&((struct Obj00991 *)p)->f14);func_021D485C(p);func_021D4698(p);func_021D4504(p);}
