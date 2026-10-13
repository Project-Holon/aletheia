/*
 * function: func_021FFDA8
 * address: 0x021FFDA8
 * packet: pkt_ov135_021FFDA8
 * region: ov135
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * volatile: hardware display control 0x04000304 read and written at 0x021FFDB6..0x021FFDBA.
 * symbols:
 *   WIPE_SYS_Start 0x0202208C thumb
 *   func_0220040C 0x0220040C thumb ov135
 *   func_021FFF10 0x021FFF10 thumb ov135
 *   func_0220015C 0x0220015C thumb ov135
 *   func_022002A0 0x022002A0 thumb ov135
 *   func_021FFFE8 0x021FFFE8 thumb ov135
 *   func_02200AB4 0x02200AB4 thumb ov135
 *   func_02200B34 0x02200B34 thumb ov135
 *   func_02200BAC 0x02200BAC thumb ov135
 *   func_022001F4 0x022001F4 thumb ov135
 *   func_021F9254 0x021F9254 thumb ov135
 *   func_0220093C 0x0220093C thumb ov135
 *   func_02200130 0x02200130 thumb ov135
 *   func_021FF8B0 0x021FF8B0 thumb ov135
 *   func_021FFD44 0x021FFD44 thumb ov135
 *   func_021FFBC8 0x021FFBC8 thumb ov135
 *   func_02040588 0x02040588 arm
 *   func_0207D55C 0x0207D55C arm
 */
#include "../include/Obj00137.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void func_0220040C(u8 *);
extern void func_021FFF10(void);
extern void func_0220015C(u8 *);
extern void func_022002A0(u8 *);
extern void func_021FFFE8(u8 *,u32,u32);
extern void func_02200AB4(u8 *);
extern void func_02200B34(u8 *);
extern void func_02040588(unsigned char which, unsigned char enable);
extern void func_02200BAC(u8 *,u32);
extern void func_022001F4(u8 *);
extern void func_021F9254(u8 *);
extern void func_0220093C(u8 *);
extern void func_02200130(char *p);
extern void WIPE_SYS_Start(void *,u32,u32,u32,u32,u32,u32);
extern void func_021FF8B0(u8 *);
extern int func_0207D55C(volatile u16 *reg);
extern void func_021FFD44(char *p);
extern void func_021FFBC8(u8 *);
int func_021FFDA8(u8 *p)
{
    u32 control;
    func_0220040C(p);
    control=*(volatile u16 *)0x04000304;
    control &= ~0x8000;
    *(volatile u16 *)0x04000304=control;
    func_021FFF10();
    func_0220015C(p);
    func_022002A0(p);
    func_021FFFE8(p,0,0);
    func_02200AB4(p);
    if(((struct Obj00137 *)p)->f30==0) func_02040588(4,0);
    else {func_02200B34(p);func_02040588(4,1);}
    func_02200BAC(p,0);
    ((struct Obj00137 *)p)->f12E4=0;
    func_022001F4(p);
    func_021F9254(p);
    func_0220093C(p);
    if(((struct Obj00137 *)p)->f30==0) {
        func_02200130((char *)p);
        WIPE_SYS_Start(0,1,1,0,6,1,0x48);
        ((struct Obj00137 *)p)->f28=0;
        ((struct Obj00137 *)p)->f30=1;
        func_021FF8B0(p);
    } else {
        if(((struct Obj00137 *)p)->fEB4==1 && func_0207D55C((u16 *)0x0400106C)!=0) {
            func_021FFD44((char *)p);
            WIPE_SYS_Start(0,1,1,0,6,1,0x48);
        } else WIPE_SYS_Start((void *)3,1,1,0,6,1,0x48);
        ((struct Obj00137 *)p)->f28=5;
    }
    ((struct Obj00137 *)p)->fEB4=0;
    func_021FFBC8(p);
    return 1;
}
