/*
 * function: func_021B9A84
 * address: 0x021B9A84
 * packet: pkt_ov213_021B9A84
 * region: ov213
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021BA38C 0x021BA38C thumb ov213
 *   func_021B9E50 0x021B9E50 thumb ov213
 *   func_021BAA8C 0x021BAA8C thumb ov213
 *   func_021BA5A0 0x021BA5A0 thumb ov213
 */
#include "../include/Obj02260.h"
typedef unsigned short u16;
extern void func_021BA38C(char *);
extern int func_021B9E50(unsigned),func_021BAA8C(char *);
extern void func_021BA5A0(char *,void *,void *,u16,u16,unsigned char);
int func_021B9A84(int unused,char *p)
{
    u16 a,b;
    func_021BA38C(p);
    if(func_021B9E50(((struct Obj02260 *)p)->f49C8)) {
        a=func_021BAA8C(*(char * *)&((struct Obj02260 *)p)->f4);
        b=func_021BAA8C(*(char * *)&((struct Obj02260 *)p)->f4+16);
    } else {
        a=func_021BAA8C(*(char * *)&((struct Obj02260 *)p)->f4);
        a+=func_021BAA8C(*(char * *)&((struct Obj02260 *)p)->f4+16);
        b=func_021BAA8C(*(char * *)&((struct Obj02260 *)p)->f4+32);
        b+=func_021BAA8C(*(char * *)&((struct Obj02260 *)p)->f4+48);
    }
    func_021BA5A0(p+0x498C,p+0xC,p+0x24,a,b,((struct Obj02260 *)p)->f49C8);
    return 1;
}
