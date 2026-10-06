/*
 * function: func_021B9FB8
 * address: 0x021B9FB8
 * region: ov222
 * isa: thumb
 * packet: pkt_ov222_021B9FB8
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * status: EXACT
 * volatile: BLDCNT stores 021B9FDE/021B9FE4; DISPCNT accesses 021B9FE6..021B9FF4
 * symbols:
 *   func_02030EAC 0x02030EAC arm
 *   func_021BA1C8 0x021BA1C8 thumb ov222
 *   func_021BA12C 0x021BA12C thumb ov222
 *   func_021BA0A8 0x021BA0A8 thumb ov222
 *   func_0201DD68 0x0201DD68 thumb
 *   func_02082BCC 0x02082BCC arm
 *   func_020307B0 0x020307B0 arm
 * 1DD68 ignores incoming arguments and tails with fixed 1,2,0.
 */
#include "../include/Obj26084.h"
typedef unsigned int u32;
typedef unsigned short u16;
struct Node;
extern void func_02030EAC(struct Node *n);
extern void func_021BA1C8(u32 *);
extern void func_021BA12C(char *);
extern void func_021BA0A8(void *);
extern void func_0201DD68(void);
extern void func_02082BCC(void *,u32,u32);
extern u32 func_020307B0(void *p);
void func_021B9FB8(char *p)
{
    func_02030EAC((struct Node *)(((struct Obj26084 *)p)->fC));
    func_021BA1C8((u32 *)(p+8));
    func_021BA12C(p+4);
    func_021BA0A8(p);
    func_0201DD68();
    *(volatile u16 *)0x04000050=0;
    *(volatile u16 *)0x04001050=0;
    *(volatile u32 *)0x04000000 &= 0xFFFF1FFF;
    *(volatile u32 *)0x04001000 &= 0xFFFF1FFF;
    func_02082BCC(p,0,16);
    func_020307B0(p);
}
