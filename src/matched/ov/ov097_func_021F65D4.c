/*
 * function: func_021F65D4
 * address:  0x021F65D4
 * packet:   pkt_ov097_021F65D4
 * region:   ov097
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BG_SYS_SetMainVisiblePlanes  0x02043534  arm
 *   BG_SYS_SetSubVisiblePlanes  0x020435F4  arm
 *   BG_SYS_SetLcdSwap  0x0204363C  arm
 *   GFL_NET_RestartWithDefaultTimeout  0x0203D34C  arm
 *   BG_SYS_SetMainPlaneVisible  0x020434DC  arm
 *   func_021F6A28  0x021F6A28  thumb  ov097
 *   func_021F682C  0x021F682C  thumb  ov097
 *   func_021F683C  0x021F683C  thumb  ov097
 *   func_021F68FC  0x021F68FC  thumb  ov097
 *   func_021F6970  0x021F6970  thumb  ov097
 *   func_021F6A98  0x021F6A98  thumb  ov097
 *   func_021F6F24  0x021F6F24  thumb  ov097
 *   func_021F734C  0x021F734C  thumb  ov097
 *   func_021F69E4  0x021F69E4  thumb  ov097
 *   func_021F681C  0x021F681C  thumb  ov097
 *   func_021F67C8  0x021F67C8  thumb  ov097
 */

typedef unsigned short u16;

typedef unsigned int   u32;
extern void BG_SYS_SetMainVisiblePlanes(u32 planes);
extern void BG_SYS_SetSubVisiblePlanes(u32 planes);
extern void BG_SYS_SetLcdSwap(u32 swap);
extern void GFL_NET_RestartWithDefaultTimeout(u32 a, u32 b);
extern void BG_SYS_SetMainPlaneVisible(u32 mask, u32 enable);
typedef unsigned char  u8;
struct P;
extern void func_021F6A28(int *p);
extern void func_021F682C(void);
extern void func_021F683C(void);
extern void func_021F68FC(int);
extern void func_021F6970(u8 *p);
extern void func_021F6A98(int);
extern void func_021F6F24(struct P *p);
extern void func_021F734C(struct P *p);
extern void func_021F69E4(u8 *p);
extern int func_021F681C(u8 *p, int count, int result);
extern int func_021F67C8(u8 *p, int value);

void func_021F65D4(int a)
{
    BG_SYS_SetMainVisiblePlanes(0);
    BG_SYS_SetSubVisiblePlanes(0);
    *(volatile u16 *)0x04000050 = 0;
    *(volatile u16 *)0x04001050 = 0;
    BG_SYS_SetLcdSwap(1);
    func_021F6A28((int *)a);
    func_021F682C();
    func_021F683C();
    func_021F68FC(a);
    func_021F6970((u8 *)a);
    func_021F6A98(a);
    func_021F6F24((struct P *)a);
    func_021F734C((struct P *)a);
    GFL_NET_RestartWithDefaultTimeout(1, 0x71);
    BG_SYS_SetMainPlaneVisible(0x17, 1);
    func_021F69E4((u8 *)a);
    func_021F67C8((u8 *)a, func_021F681C((u8 *)a, 0x80, 4));
}
