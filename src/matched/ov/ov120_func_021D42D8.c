/*
 * function: func_021D42D8
 * address: 0x021D42D8
 * packet: pkt_ov120_021D42D8
 * region: ov120
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: existing matched followers 021D435C, 021D437C, 021D439C remain separate.
 * symbols:
 *   func_020355D8 0x020355D8 arm
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   func_021D69F4 0x021D69F4 thumb ov120
 *   func_021D593C 0x021D593C thumb ov120
 *   func_021D4244 0x021D4244 thumb ov120
 *   func_021D5980 0x021D5980 thumb ov120
 */
#include "../include/Obj02830.h"
typedef unsigned char u8;
typedef unsigned int u32;
extern void func_020355D8(u8 v);
extern void GFL_USE_PlaySeDefaultVolume(u32 a);
extern void func_021D69F4(u8 *, void *, u32);
extern int func_021D593C(u8 *, int);
extern void func_021D4244(int *p, int v, int a2);
extern void func_021D5980(u8 *);
int func_021D42D8(int n, u8 *p)
{
    ((struct Obj02830 *)p)->f138 = n;
    func_020355D8(1);
    if (((struct Obj02830 *)p)->f184 == 1) {
        GFL_USE_PlaySeDefaultVolume(0x551);
        return 1;
    }
    if (n == 0) {
        ((struct Obj02830 *)p)->f15C = 0;
        func_021D69F4(*(u8 * *)&((struct Obj02830 *)p)->f3C, ((struct Obj02830 *)p)->f34, 0);
        func_021D593C(p, ((struct Obj02830 *)p)->f15C);
        func_021D4244((int *)p, (int)func_021D5980, 0x177);
    } else {
        ((struct Obj02830 *)p)->f15C = 1;
        func_021D69F4(*(u8 * *)&((struct Obj02830 *)p)->f3C, ((struct Obj02830 *)p)->f34, 1);
        func_021D593C(p, ((struct Obj02830 *)p)->f15C);
        func_021D4244((int *)p, (int)func_021D5980, 0x17e);
    }
    return 1;
}
