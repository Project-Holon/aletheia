/*
 * function: func_021FC474
 * address: 0x021FC474
 * packet: pkt_ov186_021FC474
 * region: ov186
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * volatile: hardware BLDCNT 04000050/04001050 and DISPCNT 04000000/04001000, read-modify-write at 021FC49A..021FC4A8.
 * symbols:
 *   func_02030EAC 0x02030EAC arm
 *   func_021FC5E0 0x021FC5E0 thumb ov186
 *   func_021FC55C 0x021FC55C thumb ov186
 *   func_0201DD68 0x0201DD68 thumb
 *   func_02082BCC 0x02082BCC arm
 *   func_020307B0 0x020307B0 arm
 */
#include "../include/Obj24835.h"
struct Node;
extern void func_02030EAC(struct Node *n);
extern void func_021FC5E0(void *);
extern void func_021FC55C(void *);
extern void func_0201DD68(void);
extern void func_02082BCC(void *,int,int);
typedef unsigned int   u32;
extern u32 func_020307B0(void *p);
void func_021FC474(char *p)
{
    func_02030EAC(((struct Obj24835 *)p)->fC);
    func_021FC5E0(p+4);
    func_021FC55C(p);
    func_0201DD68();
    *(volatile unsigned short *)0x04000050=0;
    *(volatile unsigned short *)0x04001050=0;
    *(volatile unsigned *)0x04000000&=~0xe000;
    *(volatile unsigned *)0x04001000&=~0xe000;
    func_02082BCC(p,0,16);
    func_020307B0(p);
}
