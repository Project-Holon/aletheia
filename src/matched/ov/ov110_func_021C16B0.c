/*
 * function: func_021C16B0
 * address: 0x021C16B0
 * packet: pkt_ov110_021C16B0
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * volatile: hardware registers 0x04000050, 0x04001050, 0x04000000, 0x04001000 re-read at 021C16D6 and 021C16E0.
 * symbols:
 *   func_02030EAC 0x02030EAC arm
 *   func_021C181C 0x021C181C thumb ov110
 *   func_021C1798 0x021C1798 thumb ov110
 *   func_0201DD68 0x0201DD68 thumb
 *   func_02082BCC 0x02082BCC arm
 *   func_020307B0 0x020307B0 arm
 */
#include "../include/Obj22415.h"
typedef unsigned char u8;
typedef unsigned short u16;
struct Node;
extern void func_02030EAC(struct Node *n);
extern void func_021C181C(void **p);
extern void func_021C1798(void *);
extern void func_0201DD68(void);
extern void func_02082BCC(void *,int,unsigned);
typedef unsigned int   u32;
extern u32 func_020307B0(void *p);
void func_021C16B0(u8 *p) {
    func_02030EAC(((struct Obj22415 *)p)->fC);
    func_021C181C((void **)(p+4));
    func_021C1798(p);
    func_0201DD68();
    *(volatile u16 *)0x04000050=0;
    *(volatile u16 *)0x04001050=0;
    *(volatile unsigned *)0x04000000 &= ~0xe000;
    *(volatile unsigned *)0x04001000 &= ~0xe000;
    func_02082BCC(p,0,16);
    func_020307B0(p);
}
