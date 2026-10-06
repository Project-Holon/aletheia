/*
 * function: func_021D96C4
 * address: 0x021D96C4
 * packet: pkt_ov121_021D96C4
 * region: ov121
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * volatile: hardware reads at 021D96EA and 021D96F4
 * symbols:
 *   func_0201DD68 0x0201DD68 thumb
 *   func_02030EAC 0x02030EAC arm
 *   func_020307B0 0x020307B0 arm
 *   func_02082BCC 0x02082BCC arm
 *   func_021D98C0 0x021D98C0 thumb ov121
 *   func_021D9828 0x021D9828 thumb ov121
 */
#include "../include/Obj22873.h"
typedef unsigned char u8;
struct Node;
extern void func_02030EAC(struct Node *n);
extern void func_021D98C0(u8 *p);
extern void func_021D9828(void *);
extern void func_0201DD68(void);
extern void func_02082BCC(void *,int,int);
typedef unsigned int   u32;
extern u32 func_020307B0(void *p);
void func_021D96C4(u8 *p)
{
    func_02030EAC(((struct Obj22873 *)p)->f14);
    func_021D98C0(p+4);
    func_021D9828(p);
    func_0201DD68();
    *(volatile unsigned short *)0x04000050=0;
    *(volatile unsigned short *)0x04001050=0;
    *(volatile unsigned *)0x04000000 &= 0xFFFF1FFF;
    *(volatile unsigned *)0x04001000 &= 0xFFFF1FFF;
    func_02082BCC(p,0,28);
    func_020307B0(p);
}
