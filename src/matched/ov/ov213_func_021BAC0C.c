/*
 * function: func_021BAC0C
 * address: 0x021BAC0C
 * packet: pkt_ov213_021BAC0C
 * region: ov213
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * volatile: 021BAC3A and 021BAC44 read hardware DISPCNT for masked updates.
 * symbols:
 *   func_02030EAC 0x02030EAC arm
 *   func_021BAE40 0x021BAE40 thumb ov213
 *   func_021BAD98 0x021BAD98 thumb ov213
 *   func_021BAD14 0x021BAD14 thumb ov213
 *   func_0201DD68 0x0201DD68 thumb
 *   func_02082BCC 0x02082BCC arm
 *   func_020307B0 0x020307B0 arm
 */
#include "../include/Obj25715.h"
struct Node;
extern void func_02030EAC(struct Node *);
extern void func_021BAE40(int *);
extern void func_021BAD98(void *p);
extern void func_021BAD14(void *p);
extern void func_0201DD68(void);
extern void func_02082BCC(void *, unsigned, unsigned);
extern void func_020307B0(void *);
void func_021BAC0C(unsigned char *p)
{
    func_02030EAC(*(struct Node * *)&((struct Obj25715 *)p)->fC);
    func_021BAE40((int *)(p + 8));
    func_021BAD98(p + 4);
    func_021BAD14(p);
    func_0201DD68();
    *(volatile unsigned short *)0x04000050 = 0;
    *(volatile unsigned short *)0x04001050 = 0;
    *(volatile unsigned *)0x04000000 &= 0xFFFF1FFF;
    *(volatile unsigned *)0x04001000 &= 0xFFFF1FFF;
    func_02082BCC(p, 0, 0x10);
    func_020307B0(p);
}
