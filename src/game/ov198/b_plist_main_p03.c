/*
 * file:     b_plist_main_p03.c
 * unit:     yes
 * function: func_02210C88, func_02210D4C
 * address:  0x02210C88
 * region:   ov198
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0201C6B4 0x0201C6B4 thumb
 *   func_0220BDD4 0x0220BDD4 thumb ov198
 *   func_0220BC70 0x0220BC70 thumb ov198
 *   func_0220BE2C 0x0220BE2C thumb ov198
 *   func_02041570 0x02041570 arm
 *   func_0220E25C 0x0220E25C thumb ov198
 *   func_02210BFC 0x02210BFC thumb ov198
 *   func_0220EA68 0x0220EA68 thumb ov198
 *   func_02210FCC 0x02210FCC thumb ov198
 *   func_0220B848 0x0220B848 thumb ov198
 *   func_0220BB94 0x0220BB94 thumb ov198
 *   func_02049EB4 0x02049EB4 arm
 *   func_02041090 0x02041090 arm
 *   func_02041B6C 0x02041B6C arm
 *   func_020307B0 0x020307B0 arm
 *   d_022121D4 0x022121D4 data a4
 */
#include "../../matched/include/Obj03351.h"
#include "../../matched/include/Obj25267.h"
#include "../../matched/include/Obj25269.h"

struct PrintSys;
typedef unsigned char u8;

typedef unsigned int u32;

typedef struct State { u8 pad[0x2177]; u8 step:4; u8 flags:4; } State;

typedef unsigned short u16;

extern u32 func_0201C6B4(const struct PrintSys *p);
extern void func_0220BDD4(char *);
extern void func_0220BC70(u8 *,u32);
extern int func_0220BE2C(char *,int);
extern void func_02041570(int channel, u16 val);
extern void func_0220E25C(u8 *);
extern void func_02210BFC(u8 *,int);
extern void func_0220EA68(char *,unsigned);
extern void func_02210FCC(u8 *,u32);
extern void func_0220B848(u8 *,unsigned);
extern void func_0220BB94(u8 *,unsigned);
extern void *func_02049EB4(u32 a0, u32 a1, u32 a2, u32 a3, u16 a4);
extern void func_02041090(u32 index, u32 a1, u32 a2, u32 a3, u8 a4, u8 a5);
extern void func_02041B6C(u8);
extern u32 func_020307B0(void *p);
int func_02210C88(u8 *p,unsigned mode);
void func_02210D4C(u8 *p,u32 n);
extern const u32 d_022121D4[];

/*
 * FCC receives only two loaded arguments here; mode is in 0..8, so its
 * out-of-domain incoming-r2 fallback is unused. BB94 receives live mode.
 */
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

void func_02210D4C(u8 *p,u32 n)
{
    u32 i=0;
    const u32 *table=d_022121D4+n*2;
    u8 *out;
    void *buf;
    for(;i<2;i++) {
        buf=func_02049EB4(100,table[i],1,(u32)(&out),((struct Obj25269 *)(*(u8 * *)&((struct Obj25267 *)p)->f0))->f10);
        func_02041090((u8)(i+6),(u32)(out+12),0,0,32,24);
        func_02041B6C(i+6);
        func_020307B0(buf);
    }
}
