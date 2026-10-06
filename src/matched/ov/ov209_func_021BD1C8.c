/*
 * function: func_021BD1C8
 * address: 0x021BD1C8
 * packet: pkt_ov209_021BD1C8
 * region: ov209
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * note: repeated decrement in each arm cross-jumps through branch stubs; explicit shared goto costs DIFF81/156.
 * symbols:
 *   func_021B93B0 0x021B93B0 thumb ov067
 *   func_021B9280 0x021B9280 thumb ov067
 *   func_02041B6C 0x02041B6C arm
 */
#include "../include/Obj01435.h"
typedef unsigned char u8;
extern int func_021B93B0(char *);
typedef unsigned int   u32;
extern void func_021B9280(u8 *p, int a, u32 b);
extern void func_02041B6C(unsigned);
int func_021BD1C8(char *p)
{
    switch (((struct Obj01435 *)p)->fC26) {
    case 0:
    case 2:
        if (((struct Obj01435 *)p)->fC27 == 0) {
            func_021B9280((u8 *)(*(char * *)&((struct Obj01435 *)p)->fC2C), (unsigned short)func_021B93B0(*(char * *)&((struct Obj01435 *)p)->fC2C), 1);
            ((struct Obj01435 *)p)->fC27 = 4;
            (((struct Obj01435 *)p)->fC26)++;
        } else (((struct Obj01435 *)p)->fC27)--;
        break;
    case 1:
    case 3:
        if (((struct Obj01435 *)p)->fC27 == 0) {
            func_021B9280((u8 *)(*(char * *)&((struct Obj01435 *)p)->fC2C), (unsigned short)func_021B93B0(*(char * *)&((struct Obj01435 *)p)->fC2C), 2);
            func_02041B6C(2);
            ((struct Obj01435 *)p)->fC27 = 4;
            (((struct Obj01435 *)p)->fC26)++;
        } else (((struct Obj01435 *)p)->fC27)--;
        break;
    case 4:
        if (((struct Obj01435 *)p)->fC27 == 0) {
            ((struct Obj01435 *)p)->fC26 = 0;
            return 8;
        }
        (((struct Obj01435 *)p)->fC27)--;
        break;
    }
    return 7;
}
