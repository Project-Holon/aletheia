/*
 * function: func_02210BFC
 * address: 0x02210BFC
 * packet: pkt_ov198_02210BFC
 * region: ov198
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * Lever: the seven-bit unsigned byte field emits shifts and an unsigned
 * comparison while retaining the original entry-pointer scheduling.
 * symbols:
 *   func_022110D4 0x022110D4 thumb ov198
 *   func_0202D01C 0x0202D01C thumb
 *   func_02041300 0x02041300 arm
 *   func_02041B6C 0x02041B6C arm
 */
#include "../include/Obj08363.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct Level { u8 pad[22]; u8 level:7; u8 flag:1; } Level;
extern int func_022110D4(u8 *,int);
extern u8 func_0202D01C(u32,u32,u32);
extern void func_02041300(u32,u16,u8,int,u8,u8,u8);
extern void func_02041B6C(u32);
void func_02210BFC(u8 *p,int mode)
{
    u8 *q;
    u32 numerator,denominator;
    u8 amount,i;
    u16 tile;
    if(mode!=2) return;
    q=p+4+76*func_022110D4(p,(*(u8 **)p)[32]);
    if(((Level *)q)->level<100U) {
        denominator=((struct Obj08363 *)q)->f24-((struct Obj08363 *)q)->f20;
        numerator=((struct Obj08363 *)q)->f1C-((struct Obj08363 *)q)->f20;
    } else { denominator=0; numerator=0; }
    amount=func_0202D01C(numerator,denominator,64);
    for(i=0;i<8;i++) {
        if(amount>=8) tile=30; else tile=amount+22;
        func_02041300(7,tile,i+10,8,1,1,16);
        if(amount<8) amount=0; else amount-=8;
    }
    func_02041B6C(7);
}
