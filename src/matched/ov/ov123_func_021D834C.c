/*
 * function: func_021D834C
 * address: 0x021D834C
 * packet: pkt_ov123_021D834C
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021D584C 0x021D584C thumb ov123
 *   func_021D62B4 0x021D62B4 thumb ov123
 *   func_021D57B8 0x021D57B8 thumb ov123
 *   func_021D6EE0 0x021D6EE0 thumb ov123
 *   func_021D8304 0x021D8304 thumb ov123
 */
#include "../include/Obj03797.h"
extern void func_021D584C(char *);
typedef unsigned int   u32;
typedef unsigned char  u8;
struct Sub02009210Obj;
extern void func_021D62B4(u8 *p, unsigned int i);
struct Sub02009448Obj;
extern struct Sub02009448Obj *func_02009448(void *sys);
extern u32 func_02009370(const struct Sub02009210Obj *obj);
extern void func_021D57B8(char *, int);
extern void func_021D6EE0(u8 *p, u32 v, int unused);
extern void func_021D8304(char *p);
void func_021D834C(char *p)
{
    func_021D584C(*(char * *)&((struct Obj03797 *)p)->f18);
    func_021D62B4((u8 *)(*(char * *)&((struct Obj03797 *)p)->f14), 0);
    func_021D62B4((u8 *)(*(char * *)&((struct Obj03797 *)p)->f14), 12);
    func_021D62B4((u8 *)(*(char * *)&((struct Obj03797 *)p)->f14), 6);
    func_021D62B4((u8 *)(*(char * *)&((struct Obj03797 *)p)->f14), 8);
    if (func_02009370((const struct Sub02009210Obj *)func_02009448(((struct Obj03797 *)p)->f28)))
        func_021D57B8(*(char * *)&((struct Obj03797 *)p)->f18, 21);
    else
        func_021D57B8(*(char * *)&((struct Obj03797 *)p)->f18, 10);
    func_021D6EE0((u8 *)p, (int)func_021D8304, 0x64c);
}
