/*
 * function: func_021E1F90
 * address:  0x021E1F90
 * packet:   pkt_021E1F90
 * region:   ov170
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021DC964  0x021DC964  thumb  ov170
 *   func_021DCF30  0x021DCF30  thumb  ov170
 *   func_021EE3CC  0x021EE3CC  thumb  ov170
 *   func_021EF310  0x021EF310  thumb  ov170
 *   func_021EBDD8  0x021EBDD8  thumb  ov170
 *   func_021EAAC4  0x021EAAC4  thumb  ov170
 *   func_021DD8F8  0x021DD8F8  thumb  ov170
 *   func_021DCE80  0x021DCE80  thumb  ov170
 *   func_021DCDD8  0x021DCDD8  thumb  ov170
 *   func_021DCB48  0x021DCB48  thumb  ov170
 *   KEY_SetRepeatSpeed  0x02036270  arm
 *   ARC_TOOL_DeleteHandle  0x02049238  arm
 *   func_020307B0  0x020307B0  arm
 *   func_020306F0  0x020306F0  arm
 *   BG_SYS_SetMainVisiblePlanes  0x02043534  arm
 *   BG_SYS_SetSubVisiblePlanes  0x020435F4  arm
 *   func_02034A5C  0x02034A5C  arm
 *   ov067_id       0x00000043  data
 */
#include "../include/Obj00000.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void func_021DC964(char *p);
extern void func_021DCF30(char *p);
extern void func_021EE3CC(int *p);
extern void func_021EF310(char *p);
extern void func_021EBDD8(char *p);
extern void func_021EAAC4(char *p);
extern void func_021DD8F8(char *p);
extern void func_021DCE80(char *p);
extern void func_021DCDD8(int *p);
extern void func_021DCB48(void *p);
extern int KEY_SetRepeatSpeed(int a0, int a1);
extern void ARC_TOOL_DeleteHandle(u32 a);
extern u32 func_020307B0(void *p);
extern void func_020306F0(unsigned int a);
extern void BG_SYS_SetMainVisiblePlanes(u32 planes);
extern void BG_SYS_SetSubVisiblePlanes(u32 planes);
extern void func_02034A5C(int a);
extern u8 ov067_id[];

int func_021E1F90(u8 *p)
{
    func_021DC964((char *)p);
    func_021DCF30((char *)p);
    func_021EE3CC((int *)p);
    func_021EF310(((struct Obj00000 *)p)->f2C);
    func_021EBDD8(((struct Obj00000 *)p)->f2C);
    func_021EAAC4((char *)p);
    func_021DD8F8((char *)p);
    func_021DCE80((char *)p);
    func_021DCDD8((int *)p);
    func_021DCB48(p);
    KEY_SetRepeatSpeed(*(u32 *)(*(u32 *)&((struct Obj00000 *)p)->f2C + 0x4c), *(u32 *)(*(u32 *)&((struct Obj00000 *)p)->f2C + 0x50));
    ARC_TOOL_DeleteHandle(*(u32 *)(*(u32 *)&((struct Obj00000 *)p)->f2C + 0x1b0));
    func_020307B0(((struct Obj00000 *)p)->f2C);
    func_020306F0(0x4c);
    *(u32 *)&((struct Obj00000 *)p)->f2C = 0;
    *(volatile u16 *)0x04000050 = 0;
    *(volatile u16 *)0x04001050 = 0;
    BG_SYS_SetMainVisiblePlanes(0);
    BG_SYS_SetSubVisiblePlanes(0);
    func_02034A5C((int)ov067_id);
    return *(u32 *)&((struct Obj00000 *)p)->f28;
}
