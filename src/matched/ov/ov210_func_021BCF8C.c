/*
 * function: func_021BCF8C
 * address:  0x021BCF8C
 * packet:   pkt_ov210_021BCF8C
 * region:   ov210
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02034AC4  0x02034AC4  arm
 *   ov067_id  0x00000043  data
 *   BG_SYS_SetMainVisiblePlanes  0x02043534  arm
 *   BG_SYS_SetSubVisiblePlanes  0x020435F4  arm
 *   BG_SYS_SetLcdSwap  0x0204363C  arm
 *   func_0207D534  0x0207D534  arm
 *   ZUKAN_SAVE_GetViewMode  0x0200CA70  thumb
 *   GFL_NET_RestartWithDefaultTimeout  0x0203D34C  arm
 *   func_021BC3D4  0x021BC3D4  thumb  ov210
 *   func_021BC3F0  0x021BC3F0  thumb  ov210
 *   func_021BC5DC  0x021BC5DC  thumb  ov210
 *   func_021BC940  0x021BC940  thumb  ov210
 *   func_021BE368  0x021BE368  thumb  ov210
 *   func_021BED2C  0x021BED2C  thumb  ov210
 *   func_021BC9D0  0x021BC9D0  thumb  ov210
 *   func_021BCA20  0x021BCA20  thumb  ov210
 *   func_021BCDA4  0x021BCDA4  thumb  ov210
 *   func_021BC790  0x021BC790  thumb  ov210
 *   func_021BC82C  0x021BC82C  thumb  ov210
 *   func_021BCBB8  0x021BCBB8  thumb  ov210
 *   func_021BC8EC  0x021BC8EC  thumb  ov210
 *   func_021BC294  0x021BC294  thumb  ov210
 *   func_021BC318  0x021BC318  thumb  ov210
 *   func_021BCF0C  0x021BCF0C  thumb  ov210
 * Addresses are Black-image addresses.
 */
#include "../include/Obj05546.h"
#include "../include/Obj25595.h"
#include "../include/Obj25596.h"
#include "../include/Obj25597.h"
#include "../include/Obj25598.h"
#include "../include/Obj25599.h"
#include "../include/Obj25600.h"
#include "../include/Obj25601.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
typedef signed int     s32;
extern u8 ov067_id[];
extern int func_02034AC4(s32 handle);
extern void BG_SYS_SetMainVisiblePlanes(u32 a);
extern void BG_SYS_SetSubVisiblePlanes(u32 a);
extern void BG_SYS_SetLcdSwap(u32 a);
struct Blk37;
extern void func_0207D534(volatile u16 *reg, int brightness);
extern u32 ZUKAN_SAVE_GetViewMode(struct Blk37 *p);
extern void GFL_NET_RestartWithDefaultTimeout(u32 a, u32 b);
extern void func_021BC3D4(void);
extern void func_021BC3F0(void);
extern void func_021BC5DC(void);
extern void func_021BC940(char *p);
extern void func_021BE368(u8 *p);
extern void func_021BED2C(int p);
extern void func_021BC9D0(int p);
extern void func_021BCA20(char *p);
extern void func_021BCDA4(char *p);
extern void func_021BC790(char *p);
extern void func_021BC82C(char *p, u8 b, u8 c);
extern void func_021BCBB8(char *p);
extern void func_021BC8EC(void);
extern void func_021BC294(u8 *p);
extern void func_021BC318(u8 *p);
extern void func_021BCF0C(u8 *p);

u32 func_021BCF8C(u8 *p)
{
    u32 z;
    u32 ra = 0x04000050;
    u32 rb = 0x04001050;
    int m;

    func_02034AC4((u32)ov067_id);
    z = 0;
    BG_SYS_SetMainVisiblePlanes(0);
    BG_SYS_SetSubVisiblePlanes(0);
    *(volatile u16 *)&((struct Obj25595 *)ra)->f0 = z;
    *(volatile u16 *)&((struct Obj25596 *)rb)->f0 = z;
    BG_SYS_SetLcdSwap(0);
    m = -16;
    func_0207D534((volatile u16 *)(ra + 0x1c), m);
    func_0207D534((volatile u16 *)(rb + 0x1c), m);
    if (ZUKAN_SAVE_GetViewMode((struct Blk37 *)(((struct Obj25597 *)(*(u8 * *)&((struct Obj05546 *)p)->f0))->f4)) == 1) {
        ((struct Obj25599 *)(*(u8 * *)&((struct Obj25598 *)(*(u8 * *)&((struct Obj05546 *)p)->f0))->f8))->f0 = z;
    } else {
        ((struct Obj25601 *)(*(u8 * *)&((struct Obj25600 *)(*(u8 * *)&((struct Obj05546 *)p)->f0))->f8))->f0 = 1;
    }
    func_021BC3D4();
    func_021BC3F0();
    func_021BC5DC();
    func_021BC940((char *)p);
    func_021BE368(p);
    func_021BED2C((int)p);
    func_021BC9D0((int)p);
    GFL_NET_RestartWithDefaultTimeout(1, 0x7b);
    func_021BCA20((char *)p);
    func_021BCDA4((char *)p);
    func_021BC790((char *)p);
    func_021BC82C((char *)p, 16, 16);
    func_021BCBB8((char *)p);
    func_021BC8EC();
    func_021BC294(p);
    func_021BC318(p);
    p[0x2b9] = 0xff;
    func_021BCF0C(p);
    return 3;
}
