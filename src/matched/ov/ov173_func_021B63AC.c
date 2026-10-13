/*
 * function: func_021B63AC
 * address:  0x021B63AC
 * packet:   pkt_021B63AC
 * region:   ov173
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BG_SYS_ClearMainPlanes  0x020434CC  arm
 *   BG_SYS_ClearSubPlanes  0x02043588  arm
 *   func_020490F4  0x020490F4  arm
 *   WIPE_SYS_Start  0x0202208C  thumb
 *   BG_SYS_SetLcdSwap  0x0204363C  arm
 *   func_020056A0  0x020056A0  thumb
 *   ARC_TOOL_DeleteHandle  0x02049238  arm
 *   func_021B64C0  0x021B64C0  thumb  ov173
 *   func_021B64D0  0x021B64D0  thumb  ov173
 *   func_021B66BC  0x021B66BC  thumb  ov173
 *   func_021B7A00  0x021B7A00  thumb  ov173
 *   func_021B6850  0x021B6850  thumb  ov173
 *   func_021B67A4  0x021B67A4  thumb  ov173
 *   func_021B7128  0x021B7128  thumb  ov173
 *   func_021B6BCC  0x021B6BCC  thumb  ov173
 *   func_021B6CC0  0x021B6CC0  thumb  ov173
 *   func_021B7C44  0x021B7C44  thumb  ov173
 *   func_021B8040  0x021B8040  thumb  ov173
 *   func_021B6278  0x021B6278  thumb  ov173
 *   func_021B6498  0x021B6498  thumb  ov173
 */
#include "../include/Obj00180.h"
typedef unsigned char u8;
typedef unsigned int u32;

typedef unsigned short u16;

extern void BG_SYS_ClearMainPlanes(void);
extern void BG_SYS_ClearSubPlanes(void);
extern void *func_020490F4(u32 id, u32 heap);
extern void WIPE_SYS_Start(void *p1, u32 p2, u32 p3, u32 p4, u32 p5, u32 p6, u32 p7);
extern void BG_SYS_SetLcdSwap(u32 swap);
extern u32 func_020056A0(void (*cb)(void), void *p, int n);
extern void ARC_TOOL_DeleteHandle(u32 a);
extern void func_021B64C0(void);
extern void func_021B64D0(void);
extern void func_021B66BC(u8 *p, u8 *q);
extern void func_021B7A00(char *p, void *arg);
extern void func_021B6850(char *p);
extern void func_021B67A4(u8 *p);
extern void func_021B7128(char *p);
extern void func_021B6BCC(char *p);
extern void func_021B6CC0(char *p);
extern void func_021B7C44(u8 *p);
extern void func_021B8040(u8 *p);
extern void func_021B6278(u8 *p);
extern void func_021B6498(void *unused, char *p);

void func_021B63AC(u8 *p)
{
    u8 *q;

    BG_SYS_ClearMainPlanes();
    BG_SYS_ClearSubPlanes();
    *(volatile u32 *)0x04000000 &= 0xffffe0ff;
    *(volatile u32 *)0x04001000 &= 0xffffe0ff;
    q = func_020490F4(0x7c, 0x4f);
    func_021B64C0();
    func_021B64D0();
    func_021B66BC(p, q);
    func_021B7A00((char *)p, q);
    func_021B6850((char *)p);
    func_021B67A4(p);
    func_021B7128((char *)p);
    func_021B6BCC((char *)p);
    func_021B6CC0((char *)p);
    func_021B7C44(p);
    func_021B8040(p);
    WIPE_SYS_Start(0, 1, 1, 0, 6, 1, 0x4f);
    BG_SYS_SetLcdSwap(1);
    ((struct Obj00180 *)p)->f68 = (u32)func_020056A0((void (*)(void))func_021B6498, p, 0x10);
    ARC_TOOL_DeleteHandle((u32)q);
    func_021B6278(p);
}



