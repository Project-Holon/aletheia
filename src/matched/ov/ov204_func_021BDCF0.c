/*
 * function: func_021BDCF0
 * address: 0x021BDCF0
 * packet: pkt_ov204_021BDCF0
 * region: ov204
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * volatile: 021BDD1E and 021BDD28 read hardware DISPCNT for masked updates.
 * symbols:
 *   func_02030EAC 0x02030EAC arm
 *   func_021BE0D4 0x021BE0D4 thumb ov204
 *   func_021BDF74 0x021BDF74 thumb ov204
 *   func_021BDDF8 0x021BDDF8 thumb ov204
 *   func_0201DD68 0x0201DD68 thumb
 *   MI_CpuFill8 0x02082BCC arm
 *   func_020307B0 0x020307B0 arm
 */
#include "../include/Obj25334.h"
struct Node;
extern void func_02030EAC(struct Node *);
extern void func_021BE0D4(unsigned char *);
extern void func_021BDF74(unsigned char *);
extern void func_021BDDF8(unsigned char *);
extern void func_0201DD68(void);
extern void MI_CpuFill8(void *, unsigned, unsigned);
typedef unsigned int   u32;
extern u32 func_020307B0(void *p);
void func_021BDCF0(unsigned char *p)
{
    func_02030EAC(*(struct Node * *)&((struct Obj25334 *)p)->f10);
    func_021BE0D4(p + 8);
    func_021BDF74(p + 4);
    func_021BDDF8(p);
    func_0201DD68();
    *(volatile unsigned short *)0x04000050 = 0;
    *(volatile unsigned short *)0x04001050 = 0;
    *(volatile unsigned *)0x04000000 &= 0xFFFF1FFF;
    *(volatile unsigned *)0x04001000 &= 0xFFFF1FFF;
    MI_CpuFill8(p, 0, 0x14);
    func_020307B0(p);
}
