/*
 * function: func_021BF6E0
 * address: 0x021BF6E0
 * packet: pkt_ov210_021BF6E0
 * region: ov210
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021BEE58 0x021BEE58 thumb ov210
 *   func_021BEE38 0x021BEE38 thumb ov210
 *   func_021B8AE4 0x021B8AE4 thumb ov067
 */
#include "../include/Obj25629.h"
struct S;
extern void func_021BEE58(char *, int, short *, short *, unsigned short);
extern void func_021BEE38(char *, int, unsigned short, short, unsigned short);
extern int func_021B8AE4(struct S *, unsigned int);
void func_021BF6E0(char *p)
{
    short pos[2];
    unsigned int y;
    func_021BEE58(p, 0, &pos[1], &pos[0], 0);
    y = func_021B8AE4(*(struct S * *)&((struct Obj25629 *)p)->f1E0, pos[0]);
    if (y < 12) y = 12;
    else if (y > 156) y = 156;
    func_021BEE38(p, 0, 0xfc, y, 0);
}
