/*
 * function: func_021B70A8
 * address: 0x021B70A8
 * packet: pkt_ov172_021B70A8
 * region: ov172
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0207C778 0x0207C778 arm
 *   func_0207D59C 0x0207D59C arm
 *   func_020307B0 0x020307B0 arm
 *   func_021BE100 0x021BE100 thumb ov172
 *   func_021B63B8 0x021B63B8 thumb ov172
 *   func_020306F0 0x020306F0 arm
 */
#include "../include/Obj04550.h"
extern int func_0207C778(int);
extern void func_0207D59C(void *, int *, int, int, int, int);
extern void func_020307B0(void *);
extern int func_021BE100(void);
extern void func_021B63B8(char *p);
extern void func_020306F0(unsigned int);
void func_021B70A8(int unused, char *q)
{
    int matrix[4];
    matrix[0] = func_0207C778(4096);
    matrix[3] = func_0207C778(4096);
    matrix[1] = 0;
    matrix[2] = 0;
    func_0207D59C((void *)0x04000030, matrix, 0, 0, 0, 0);
    func_020307B0(((struct Obj04550 *)q)->f4);
    func_020307B0(((struct Obj04550 *)q)->fC);
    func_020307B0(((struct Obj04550 *)q)->f8);
    if (func_021BE100() == 1) {
        func_020307B0(((struct Obj04550 *)q)->fB0);
        func_020307B0(((struct Obj04550 *)q)->fA8);
        func_020307B0(((struct Obj04550 *)q)->fAC);
        func_021B63B8(((struct Obj04550 *)q)->fA4);
        func_020306F0(110);
    }
    func_020307B0(q);
}
