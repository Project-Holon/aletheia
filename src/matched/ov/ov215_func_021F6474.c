/*
 * function: func_021F6474
 * address: 0x021F6474
 * packet: pkt_ov215_021F6474
 * region: ov215
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * volatile: hardware reads/stores 021F649A,64A0,64A2,64AA,64AC,64B0.
 * symbols:
 *   func_02030EAC 0x02030EAC arm
 *   func_021F669C 0x021F669C thumb ov215
 *   func_021F6600 0x021F6600 thumb ov215
 *   func_021F657C 0x021F657C thumb ov215
 *   func_0201DD68 0x0201DD68 thumb
 *   func_02082BCC 0x02082BCC arm
 *   func_020307B0 0x020307B0 arm
 */
#include "../include/Obj25750.h"
typedef unsigned short u16;
struct Node;
extern void func_02030EAC(struct Node *n);
extern void func_021F669C(int *p);
extern void func_021F6600(char *p);
extern void func_021F657C(void *);
extern void func_0201DD68(void);
extern void func_02082BCC(void *,int,int);
extern void func_020307B0(void *);
void func_021F6474(char *p)
{
    func_02030EAC(((struct Obj25750 *)p)->fC);
    func_021F669C((int *)(p+8));
    func_021F6600(p+4);
    func_021F657C(p);
    func_0201DD68();
    *(volatile u16 *)0x04000050=0;
    *(volatile u16 *)0x04001050=0;
    *(volatile unsigned *)0x04000000 &= 0xFFFF1FFF;
    *(volatile unsigned *)0x04001000 &= 0xFFFF1FFF;
    func_02082BCC(p,0,16);
    func_020307B0(p);
}
