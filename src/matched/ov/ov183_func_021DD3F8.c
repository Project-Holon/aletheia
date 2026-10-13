/*
 * function: func_021DD3F8
 * address: 0x021DD3F8
 * packet: pkt_ov183_021DD3F8
 * region: ov183
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021DDF5C 0x021DDF5C thumb ov183
 *   func_021DDDE8 0x021DDDE8 thumb ov183
 *   func_020409B4 0x020409B4 arm
 *   func_021FC0C8 0x021FC0C8 thumb ov186
 *   func_021FD820 0x021FD820 thumb ov186
 *   func_0201C4C0 0x0201C4C0 thumb
 *   BMP_OAM_DeleteSys 0x02025588 thumb
 *   func_020315D4 0x020315D4 arm
 */
#include "../include/Obj06603.h"
#include "../include/Obj10732.h"
extern void func_021DDF5C(char *, char *);
extern void func_021DDDE8(char *, char *);
extern void func_020409B4(unsigned int);
extern void func_021FC0C8(char *p, unsigned i);
extern void func_021FD820(char *);
struct PrintSys;
extern void func_0201C4C0(struct PrintSys *p);
extern void BMP_OAM_DeleteSys(void *);
struct S020315D4;
extern void func_020315D4(struct S020315D4 *);
int func_021DD3F8(struct S020315D4 *a, int unused, char *q, char *p)
{
    func_021DDF5C(p, q);
    func_021DDDE8(p, q);
    func_020409B4(4);
    func_020409B4(1);
    func_021FC0C8((char *)(((struct Obj06603 *)q)->f8), 13);
    func_021FD820(*(char * *)&((struct Obj10732 *)p)->f74);
    func_0201C4C0(((struct Obj10732 *)p)->f4);
    BMP_OAM_DeleteSys(((struct Obj10732 *)p)->f0);
    func_020315D4(a);
    return 1;
}
