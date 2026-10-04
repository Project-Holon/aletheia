/*
 * function: func_021D7390
 * address: 0x021D7390
 * packet: pkt_ov123_021D7390
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021B99DC 0x021B99DC thumb ov114
 *   func_021B9790 0x021B9790 thumb ov114
 *   func_021B97F4 0x021B97F4 thumb ov114
 *   func_021D6E08 0x021D6E08 thumb ov123
 *   func_021D6EE0 0x021D6EE0 thumb ov123
 *   func_021D72D8 0x021D72D8 thumb ov123
 */
#include "../include/Obj06464.h"
typedef unsigned char  u8;
struct Sub02009448Obj;
extern int func_021B99DC(u8 *p);
extern int func_021B9790(u8 *p);
extern u8 *func_021B97F4(u8 *p);
extern int func_021D6E08(char *,int);
extern struct Sub02009448Obj *func_02009448(void *sys);
extern void func_021D6EE0(char *,int,int);
extern void func_021D72D8(char *);
void func_021D7390(char *p)
{
    if (func_021D6E08(p,func_021B99DC(((struct Obj06464 *)p)->f10))==0) {
        if (func_021B9790(((struct Obj06464 *)p)->f10)==0) {
            func_021B97F4(((struct Obj06464 *)p)->f10);
            func_02009448(((struct Obj06464 *)p)->f28);
            ((struct Obj06464 *)p)->fAE=1;
            func_021D6EE0(p,(int)func_021D72D8,0x2ae);
        }
    }
}
