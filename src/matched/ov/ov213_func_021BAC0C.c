/*
 * function: COMM_BTL_DEMO_GRAPHIC_Delete
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
 *   COMM_BTL_DEMO_GRAPHIC_DeleteG3d 0x021BAE40 thumb ov213
 *   COMM_BTL_DEMO_GRAPHIC_DeleteClact 0x021BAD98 thumb ov213
 *   COMM_BTL_DEMO_GRAPHIC_DeleteBg 0x021BAD14 thumb ov213
 *   func_0201DD68 0x0201DD68 thumb
 *   MI_CpuFill8 0x02082BCC arm
 *   func_020307B0 0x020307B0 arm
 */
#include "../include/Obj25715.h"
struct Node;
extern void func_02030EAC(struct Node *);
extern void COMM_BTL_DEMO_GRAPHIC_DeleteG3d(int *);
extern void COMM_BTL_DEMO_GRAPHIC_DeleteClact(void *p);
extern void COMM_BTL_DEMO_GRAPHIC_DeleteBg(void *p);
extern void func_0201DD68(void);
extern void MI_CpuFill8(void *, unsigned, unsigned);
typedef unsigned int   u32;
extern u32 func_020307B0(void *p);
void COMM_BTL_DEMO_GRAPHIC_Delete(unsigned char *p)
{
    func_02030EAC(*(struct Node * *)&((struct Obj25715 *)p)->fC);
    COMM_BTL_DEMO_GRAPHIC_DeleteG3d((int *)(p + 8));
    COMM_BTL_DEMO_GRAPHIC_DeleteClact(p + 4);
    COMM_BTL_DEMO_GRAPHIC_DeleteBg(p);
    func_0201DD68();
    *(volatile unsigned short *)0x04000050 = 0;
    *(volatile unsigned short *)0x04001050 = 0;
    *(volatile unsigned *)0x04000000 &= 0xFFFF1FFF;
    *(volatile unsigned *)0x04001000 &= 0xFFFF1FFF;
    MI_CpuFill8(p, 0, 0x10);
    func_020307B0(p);
}
