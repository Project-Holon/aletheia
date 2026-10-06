/*
 * function: func_021BBA78
 * address: 0x021BBA78
 * packet: pkt_ov223_021BBA78
 * region: ov223
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02040EBC 0x02040EBC arm
 *   func_021B9854 0x021B9854 thumb ov223
 *   func_021BAB78 0x021BAB78 thumb ov223
 *   func_021BAC0C 0x021BAC0C thumb ov223
 *   func_021BB2A4 0x021BB2A4 thumb ov223
 *   func_0207D63C 0x0207D63C arm
 */
#include "../include/Obj06729.h"
extern void func_02040EBC(unsigned, unsigned);
typedef unsigned short u16;
typedef unsigned char  u8;
extern void func_021B9854(u8 *p);
extern void func_021BAB78(u16 *p);
extern void func_021BAC0C(unsigned short *);
extern void func_021BB2A4(char *p);
extern void func_0207D63C(void *, unsigned, unsigned, unsigned, unsigned);
int func_021BBA78(char *p)
{
    func_02040EBC(0, 0x2F3B);
    func_02040EBC(4, 0x2F3B);
    func_021B9854((u8 *)p);
    func_021BAB78((u16 *)p);
    func_021BAC0C((unsigned short *)p);
    func_021BB2A4(p);
    ((struct Obj06729 *)p)->f24 |= 2;
    ((struct Obj06729 *)p)->f268 = 0;
    func_0207D63C((void *)0x04000050, 5, 63,
                 ((struct Obj06729 *)p)->f268, 16 - ((struct Obj06729 *)p)->f268);
    ((struct Obj06729 *)p)->f10 = 0;
    return 3;
}
