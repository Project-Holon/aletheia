/*
 * function: func_021BB220
 * address: 0x021BB220
 * packet: pkt_ov214_021BB220
 * region: ov214
 * compiler: 1.1p1
 * flags: -O4,p
 * isa: thumb
 * lang: c99
 * status: EXACT
 * volatile: BLDCNT stores 021BB246/021BB24C; DISPCNT reads/stores 021BB24E..021BB25C
 * symbols:
 *   func_02030EAC 0x02030EAC arm
 *   func_021BB448 0x021BB448 thumb ov214
 *   func_021BB3AC 0x021BB3AC thumb ov214
 *   func_021BB328 0x021BB328 thumb ov214
 *   func_0201DD68 0x0201DD68 thumb
 *   MI_CpuFill8 0x02082BCC arm
 *   func_020307B0 0x020307B0 arm
 * 1DD68 full body ignores incoming arguments and tails with fixed 1,2,0.
 */
#include "../include/Obj25731.h"
typedef unsigned int u32;
typedef unsigned short u16;
struct Node;
extern void func_02030EAC(struct Node *n);
extern void func_021BB448(int *);
extern void func_021BB3AC(void *);
extern void func_021BB328(void *);
extern void func_0201DD68(void);
extern void MI_CpuFill8(void *,u32,u32);
extern u32 func_020307B0(void *p);
void func_021BB220(char *p)
{
    func_02030EAC((struct Node *)(((struct Obj25731 *)p)->fC));
    func_021BB448((int *)(p+8));
    func_021BB3AC(p+4);
    func_021BB328(p);
    func_0201DD68();
    *(volatile u16 *)0x04000050=0;
    *(volatile u16 *)0x04001050=0;
    *(volatile u32 *)0x04000000 &= 0xFFFF1FFF;
    *(volatile u32 *)0x04001000 &= 0xFFFF1FFF;
    MI_CpuFill8(p,0,16);
    func_020307B0(p);
}
