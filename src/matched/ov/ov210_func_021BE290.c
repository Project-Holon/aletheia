/*
 * function: func_021BE290
 * address: 0x021BE290
 * packet: pkt_ov210_021BE290
 * region: ov210
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * ABI: 93D4 receives full entry index in r1 without caller-side truncation;
 *      widen its legacy s16 declaration. FA7C explicitly narrows r1 to u16.
 * symbols:
 *   func_021B93B8 0x021B93B8 thumb ov067
 *   func_021B93D4 0x021B93D4 thumb ov067
 *   func_021BFA7C 0x021BFA7C thumb ov210
 *   func_021BF618 0x021BF618 thumb ov210
 */
#include "../include/Obj10919.h"
#include "../include/Obj25612.h"
typedef unsigned char u8;
typedef unsigned short u16;
struct S;
extern int func_021B93B8(char *);
extern void func_021B93D4(struct S *, int);
extern void func_021BFA7C(char *, u16, int);
extern void func_021BF618(u8 *);
void func_021BE290(u8 *p, int index)
{
    int sum = index + func_021B93B8(*(char * *)&((struct Obj10919 *)p)->f1E0);
    u8 *data = *(u8 * *)&((struct Obj25612 *)(*(u8 * *)&((struct Obj10919 *)p)->f0))->f8;
    if (data[6] == sum) {
        data[6] = 255;
        func_021BFA7C((char *)p, index, 0);
    } else {
        data[6] = sum;
        func_021BFA7C((char *)p, index, 1);
    }
    func_021B93D4(*(struct S * *)&((struct Obj10919 *)p)->f1E0, index);
    func_021BF618(p);
}
