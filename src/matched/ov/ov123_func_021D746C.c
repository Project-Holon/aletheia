/*
 * function: func_021D746C
 * address: 0x021D746C
 * packet: pkt_ov123_021D746C
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020092D0 0x020092D0 thumb
 *   func_021D7224 0x021D7224 thumb ov123
 *   func_021D6EBC 0x021D6EBC thumb ov123
 *   func_021D7CB4 0x021D7CB4 thumb ov123
 *   func_021D7DE8 0x021D7DE8 thumb ov123
 *   func_021D7C54 0x021D7C54 thumb ov123
 *   func_021D7D18 0x021D7D18 thumb ov123
 *   func_021D6EE0 0x021D6EE0 thumb ov123
 *   func_021D7430 0x021D7430 thumb ov123
 */
#include "../include/Obj03269.h"
#include "../include/Obj06465.h"
typedef unsigned char u8;
typedef unsigned short u16;
struct Sub02009210Obj;
struct Sub02009448Obj;
extern struct Sub02009448Obj *func_02009448(void *sys);
extern void func_021D7224(char *p);
extern int func_021D6EBC(u8 *p);
extern int func_021D7CB4(int a, u8 *p);
extern void func_021D7DE8(u8 *p, int a, u8 *records);
extern void func_021D7C54(void *p, char *q);
extern void func_020092D0(struct Sub02009210Obj *obj, u8 value);
typedef unsigned int   u32;
extern u32 func_020056EC(u32 range);
extern void func_021D7D18(u8 *p, int unused, int species, int gender, int form, int n, int value);
extern void func_02009348(struct Sub02009210Obj *obj, int i, u16 a, u8 b);
extern int func_02012DAC(int a0);
extern void func_021D6EE0(u8 *p, u32 v, int unused);
extern void func_021D7430(u8 *p);
void func_021D746C(int a)
{
    int b;
    int i;
    u8 *p;
    b=(int)func_02009448((void *)(((struct Obj03269 *)a)->f28));
    ((struct Obj03269 *)a)->fAB=1;
    func_021D7224((char *)a);
    if(func_021D6EBC((u8 *)a)==0) {
        func_021D7CB4(b,(u8 *)(((struct Obj03269 *)a)->f38));
        func_021D7DE8((u8 *)a,b,(u8 *)(((struct Obj03269 *)a)->f38));
        func_021D7C54((void *)b,(char *)(((struct Obj03269 *)a)->f38));
        func_020092D0((struct Sub02009210Obj *)b,*(u8 *)(((struct Obj03269 *)a)->f38+0x5a));
    } else {
        p=*(u8 * *)&((struct Obj03269 *)a)->f20+0xc;
        func_021D7D18((u8 *)a,b,((struct Obj06465 *)p)->f2,p[7],p[6],((struct Obj06465 *)p)->f4,func_020056EC(8));
        for(i=0;i<20;i++) func_02009348((struct Sub02009210Obj *)b,i,*(u16 *)(p+8+i*2),p[0x30+i]);
    }
    ((struct Obj03269 *)a)->fAD=1;
    func_02012DAC(((struct Obj03269 *)a)->f2C);
    func_021D6EE0((u8 *)a,(int)func_021D7430,0x311);
}
