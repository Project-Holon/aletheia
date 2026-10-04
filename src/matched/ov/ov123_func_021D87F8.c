/*
 * function: func_021D87F8
 * address: 0x021D87F8
 * packet: pkt_ov123_021D87F8
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021D57B8 0x021D57B8 thumb ov123
 *   func_021D5A7C 0x021D5A7C thumb ov123
 *   func_021D6EE0 0x021D6EE0 thumb ov123
 *   func_021D8790 0x021D8790 thumb ov123
 *   func_021B95D4 0x021B95D4 thumb ov114
 *   func_021B9748 0x021B9748 thumb ov114
 *   func_0203CD98 0x0203CD98 arm
 *   func_020362DC 0x020362DC arm
 *   func_02035C60 0x02035C60 arm
 */
#include "../include/Obj08113.h"

typedef unsigned int u32;
extern void func_021D57B8(char *,int);
extern void func_021D5A7C(char *);
extern void func_021D6EE0(char *,int,int);
typedef unsigned char  u8;
extern void func_021D8790(char *p);
extern int func_021B95D4(int index, u8 *p);
extern int func_021B9748(u8 *p);
extern int func_0203CD98(void);
extern u32 func_020362DC(void);
extern int func_02035C60(void);
void func_021D87F8(char *p)
{
    func_021D57B8(*(char * *)&((struct Obj08113 *)p)->f18,13);
    func_021D5A7C(*(char * *)&((struct Obj08113 *)p)->f18);
    if (func_0203CD98()) {
        if (func_021B95D4(0,((struct Obj08113 *)p)->f10)) {
            if (!func_021B9748(((struct Obj08113 *)p)->f10))
                func_021D6EE0(p,(int)func_021D8790,0x7ea);
        }
    } else {
        if (func_020362DC() || func_02035C60())
            func_021D6EE0(p,(int)func_021D8790,0x7f1);
    }
}
