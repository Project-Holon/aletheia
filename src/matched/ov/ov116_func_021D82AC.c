/*
 * unit: yes
 * function: func_021D82AC, func_021D82F8
 * address: 0x021D82AC
 * packet: pkt_ov116_021D82AC
 * region: ov116
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02030EAC 0x02030EAC arm
 *   func_021D8364 0x021D8364 thumb ov116
 *   func_0201DD68 0x0201DD68 thumb
 *   func_02082BCC 0x02082BCC arm
 *   func_020307B0 0x020307B0 arm
 *   func_021D839C 0x021D839C thumb ov116
 * volatile: hardware registers 0x04000050, 0x04001050, 0x04000000, 0x04001000 are read/written at 021D8244..021D8258 or 021D82C4..021D82DA.
 */
#include "../include/Obj22633.h"
struct Node;
extern void func_02030EAC(struct Node *n);
extern void func_021D8364(void *);
extern void func_0201DD68(void);
extern void func_02082BCC(void *,int,int);
typedef unsigned int   u32;
extern u32 func_020307B0(void *p);
extern void func_021D839C(void *);
void func_021D82AC(void *p) {
 func_02030EAC(((struct Obj22633 *)p)->fC); func_021D8364(p); func_0201DD68();
 *(volatile unsigned short *)0x04000050=0;
 *(volatile unsigned short *)0x04001050=0;
 *(volatile unsigned *)0x04000000 &= 0xffff1fff;
 *(volatile unsigned *)0x04001000 &= 0xffff1fff;

 func_02082BCC(p,0,16); func_020307B0(p);
}
void func_021D82F8(void *a,void *b) {func_021D839C(b);}
