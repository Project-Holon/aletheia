/*
 * function: BTL_REC_SEL_GRAPHIC_Delete
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
 *   BTL_REC_SEL_GRAPHIC_DeleteG3d 0x021BB448 thumb ov214
 *   BTL_REC_SEL_GRAPHIC_DeleteClact 0x021BB3AC thumb ov214
 *   BTL_REC_SEL_GRAPHIC_DeleteBg 0x021BB328 thumb ov214
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
extern void BTL_REC_SEL_GRAPHIC_DeleteG3d(int *);
extern void BTL_REC_SEL_GRAPHIC_DeleteClact(void *);
extern void BTL_REC_SEL_GRAPHIC_DeleteBg(void *);
extern void func_0201DD68(void);
extern void MI_CpuFill8(void *,u32,u32);
extern u32 func_020307B0(void *p);
void BTL_REC_SEL_GRAPHIC_Delete(char *p)
{
    func_02030EAC((struct Node *)(((struct Obj25731 *)p)->fC));
    BTL_REC_SEL_GRAPHIC_DeleteG3d((int *)(p+8));
    BTL_REC_SEL_GRAPHIC_DeleteClact(p+4);
    BTL_REC_SEL_GRAPHIC_DeleteBg(p);
    func_0201DD68();
    *(volatile u16 *)0x04000050=0;
    *(volatile u16 *)0x04001050=0;
    *(volatile u32 *)0x04000000 &= 0xFFFF1FFF;
    *(volatile u32 *)0x04001000 &= 0xFFFF1FFF;
    MI_CpuFill8(p,0,16);
    func_020307B0(p);
}
