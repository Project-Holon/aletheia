/*
 * function: func_021D70BC
 * address: 0x021D70BC
 * packet: pkt_ov123_021D70BC
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   d_021DA844 0x021DA844 data a4
 *   func_021D584C 0x021D584C thumb ov123
 *   func_021D5950 0x021D5950 thumb ov123
 *   func_021D5960 0x021D5960 thumb ov123
 *   func_021D6EE0 0x021D6EE0 thumb ov123
 *   func_021D7088 0x021D7088 thumb ov123
 *   func_021D706C 0x021D706C thumb ov123
 */
#include "../include/Obj06463.h"
typedef struct { int x[8]; } Table;
extern const Table d_021DA844;
extern void func_021D584C(char *);
typedef unsigned int   u32;
typedef unsigned char  u8;
extern int func_021D5950(u8 *p, int x);
extern void func_021D5960(char *,int,int);
extern void func_021D6EE0(u8 *p, u32 v, int unused);
extern void func_021D7088(char *);
extern void func_021D706C(char *);
void func_021D70BC(char *p)
{
    Table t=d_021DA844;
    if (((struct Obj06463 *)p)->fA8) {
        func_021D584C(*(char * *)&((struct Obj06463 *)p)->f18);
        func_021D5950((u8 *)(*(char * *)&((struct Obj06463 *)p)->f18),t.x[((struct Obj06463 *)p)->fA8]);
        func_021D5960(*(char * *)&((struct Obj06463 *)p)->f18,1,8);
        func_021D6EE0((u8 *)p,(int)func_021D7088,0x1f0);
    } else {
        func_021D6EE0((u8 *)p,(int)func_021D706C,0x1f3);
    }
}
