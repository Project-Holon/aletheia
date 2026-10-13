/*
 * function: func_021F5154
 * address: 0x021F5154
 * packet: pkt_ov135_021F5154
 * region: ov135
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * volatile: hardware halfword 04000304 read at 021F5162 before masked write.
 * symbols:
 *   func_021F5980 0x021F5980 thumb ov135
 *   func_021F5250 0x021F5250 thumb ov135
 *   func_021FFFE8 0x021FFFE8 thumb ov135
 *   func_021F5374 0x021F5374 thumb ov135
 *   func_021F57EC 0x021F57EC thumb ov135
 *   func_021F5420 0x021F5420 thumb ov135
 *   func_021FFD44 0x021FFD44 thumb ov135
 *   func_0207D55C 0x0207D55C arm
 *   func_021F68A4 0x021F68A4 thumb ov135
 *   func_021F9254 0x021F9254 thumb ov135
 *   WIPE_SYS_Start  0x0202208C  thumb  arm9
 */
#include "../include/Obj10575.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void func_021F5980(u8 *);
extern void func_021F5250(void);
extern void func_021FFFE8(u8 *, u32, u32);
extern void func_021F5374(u8 *);
extern void func_021F57EC(u8 *);
extern void func_021F5420(u8 *);
extern void func_021FFD44(char *p);
extern int func_0207D55C(volatile u16 *reg);
extern void WIPE_SYS_Start(void *, u32, u32, u32, u32, u32, u32);
extern void func_021F68A4(u8 *, int);
extern void func_021F9254(u8 *);
int func_021F5154(u8 *p)
{
    func_021F5980(p);
    *(volatile u16 *)0x04000304 = (u16)(*(volatile u16 *)0x04000304 & ~0x8000);
    func_021F5250();
    func_021FFFE8(p, 0, 0);
    func_021F5374(p);
    func_021F57EC(p);
    func_021F5420(p);
    func_021FFD44((char *)p);
    if (func_0207D55C((u16 *)0x0400106c) == 0) {
        WIPE_SYS_Start((void *)3, 1, 1, 0, 6, 1, 0x48);
    } else {
        WIPE_SYS_Start(0, 1, 1, 0, 6, 1, 0x48);
    }
    func_021F68A4(p, ((struct Obj10575 *)p)->fC4);
    func_021F9254(p);
    ((struct Obj10575 *)p)->f28 = 0;
    ((struct Obj10575 *)p)->f12E4 = 0;
    return 1;
}
