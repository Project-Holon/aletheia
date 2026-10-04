/*
 * function: func_021D5980
 * address: 0x021D5980
 * packet: pkt_ov120_021D5980
 * region: ov120
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021D596C 0x021D596C thumb ov120
 *   func_021D69F4 0x021D69F4 thumb ov120
 *   func_021D7D3C 0x021D7D3C thumb ov120
 *   func_02041B6C 0x02041B6C arm
 *   func_021D4244 0x021D4244 thumb ov120
 *   func_021D4EC0 0x021D4EC0 thumb ov120
 *   func_021D57B0 0x021D57B0 thumb ov120
 */
#include "../include/Obj05346.h"
typedef unsigned char u8;
extern int func_021D596C(u8 *, int);
typedef unsigned int   u32;
extern void func_021D69F4(u8 *p, void *q, u32 n);
extern void func_021D7D3C(char *);
extern void func_02041B6C(u32 bit);
extern void func_021D4244(int, int, int);
extern void func_021D4EC0(u8 *p);
extern void func_021D57B0(u8 *p);
void func_021D5980(u8 *p)
{
    int state = func_021D596C(p, ((struct Obj05346 *)p)->f15C);
    if (state == 0) {
        func_021D69F4(((struct Obj05346 *)p)->f3C, ((struct Obj05346 *)p)->f34, 9);
        func_021D7D3C(*(char * *)&((struct Obj05346 *)p)->f40);
        func_02041B6C(6);
        func_021D4244((int)p, (int)func_021D4EC0, 0x8a3);
        return;
    }
    if (state == 1) {
        func_021D69F4(((struct Obj05346 *)p)->f3C, ((struct Obj05346 *)p)->f34, 9);
        func_021D4244((int)p, (int)func_021D57B0, 0x8a7);
    }
}
