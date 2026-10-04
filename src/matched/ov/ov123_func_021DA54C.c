/*
 * function: func_021DA54C
 * address: 0x021DA54C
 * packet: pkt_ov123_021DA54C
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021D9A14 0x021D9A14 thumb ov123
 *   func_021D9404 0x021D9404 thumb ov123
 *   func_021B9774 0x021B9774 thumb ov114
 *   func_02157170 0x02157170 thumb ov009
 */
#include "../include/Obj03276.h"
#include "../include/Obj22990.h"
typedef unsigned int   u32;
typedef unsigned char  u8;
extern u32 func_0200FB24(void);
extern void func_02027974(void *);
extern void func_021D9A14(int);
extern void func_021D9404(char *p);
extern u32 func_020221A4(void);
extern void func_021B9774(u8 *p);
extern void func_02012E08(char *p);
extern void func_0202223C(u32 a, u32 color);
extern void func_02157170(int,int);
int func_021DA54C(int a,int b,char *c,char *p)
{
    void (*f)(char *);
    int r;
    f = *(void (**)(char *))(p + 0x30);
    r = 1;
    if (f) {
        if (!func_0200FB24()) f(p);
        r = 0;
    }
    if (((struct Obj03276 *)p)->f14) func_02027974(((struct Obj03276 *)p)->f14);
    func_021D9A14(((struct Obj03276 *)p)->fC);
    func_021D9404(((struct Obj03276 *)p)->f10);
    if (func_020221A4()) {
        if (func_0200FB24()) {
            func_021B9774(((struct Obj03276 *)p)->f8);
            if (((struct Obj03276 *)p)->f6C) {
                func_02012E08(((struct Obj03276 *)p)->f20);
                ((struct Obj03276 *)p)->f6C = 0;
            }
            func_0202223C(0,0);
            func_0202223C(1,0);
            r = 1;
            func_02157170(1,0);
            ((struct Obj22990 *)c)->f10 = 1;
        }
    } else if (func_0200FB24()) r = 1;
    return r;
}
