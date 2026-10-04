/*
 * function: func_02210C88
 * address: 0x02210C88
 * packet: pkt_ov198_02210C88
 * region: ov198
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0201C6B4 0x0201C6B4 thumb
 *   func_0220BDD4 0x0220BDD4 thumb ov198
 *   func_0220BC70 0x0220BC70 thumb ov198
 *   func_0220BE2C 0x0220BE2C thumb ov198
 *   func_02210D4C 0x02210D4C thumb ov198
 *   func_02041570 0x02041570 arm
 *   func_0220E25C 0x0220E25C thumb ov198
 *   func_02210BFC 0x02210BFC thumb ov198
 *   func_0220EA68 0x0220EA68 thumb ov198
 *   func_02210FCC 0x02210FCC thumb ov198
 *   func_0220B848 0x0220B848 thumb ov198
 *   func_0220BB94 0x0220BB94 thumb ov198
 * FCC receives only two loaded arguments here; mode is in 0..8, so its
 * out-of-domain incoming-r2 fallback is unused. BB94 receives live mode.
 */
#include "../include/Obj03351.h"
typedef unsigned char u8;
typedef unsigned int u32;
typedef struct State { u8 pad[0x2177]; u8 step:4; u8 flags:4; } State;
typedef unsigned short u16;
struct PrintSys;
extern u32 func_0201C6B4(const struct PrintSys *p);
extern void func_0220BDD4(char *);
extern void func_0220BC70(u8 *,u32);
extern int func_0220BE2C(char *,int);
extern void func_02210D4C(u8 *,u32);
extern void func_02041570(int channel, u16 val);
extern void func_0220E25C(u8 *);
extern void func_02210BFC(u8 *,int);
extern void func_0220EA68(char *,unsigned);
extern void func_02210FCC(u8 *,u32);
extern void func_0220B848(u8 *,unsigned);
extern void func_0220BB94(u8 *,unsigned);
int func_02210C88(u8 *p,unsigned mode)
{
    switch(((State *)p)->step) {
    case 0:
        if(func_0201C6B4(((struct Obj03351 *)p)->f1EAC)==1) {
            func_0220BDD4((char *)p);
            func_0220BC70(p,mode);
            func_0220BE2C((char *)p,mode);
            ((State *)p)->step=(u8)(((State *)p)->step+1);
        }
        break;
    case 1:
        if(func_0201C6B4(((struct Obj03351 *)p)->f1EAC)==1) {
            func_02210D4C(p,mode);
            func_02041570(4,0);
            func_02041570(5,0);
            func_0220E25C(p);
            func_02210BFC(p,mode);
            func_0220EA68((char *)p,mode);
            func_02210FCC(p,mode);
            func_0220B848(p,mode);
            func_0220BB94(p,mode);
            p[0x2180]=mode;
            ((State *)p)->step=0;
            return 1;
        }
        break;
    }
    return 0;
}
