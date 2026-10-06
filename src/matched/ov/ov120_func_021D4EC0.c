/*
 * function: func_021D4EC0
 * address: 0x021D4EC0
 * packet: pkt_ov120_021D4EC0
 * region: ov120
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021D6988 0x021D6988 thumb ov120
 *   func_021B64D0 0x021B64D0 thumb ov067
 *   func_021D7D3C 0x021D7D3C thumb ov120
 *   func_021D6814 0x021D6814 thumb ov120
 *   func_021D444C 0x021D444C thumb ov120
 *   func_021D7DC8 0x021D7DC8 thumb ov120
 *   func_021D4C98 0x021D4C98 thumb ov120
 *   func_021D79F4 0x021D79F4 thumb ov120
 *   func_021D7ECC 0x021D7ECC thumb ov120
 *   func_020355C4 0x020355C4 arm
 *   func_021D69F4 0x021D69F4 thumb ov120
 *   func_02041B6C 0x02041B6C arm
 *   func_021D4244 0x021D4244 thumb ov120
 *   func_021D4D28 0x021D4D28 thumb ov120
 */
#include "../include/Obj01253.h"
typedef unsigned char u8;
typedef unsigned int u32;
extern u32 func_021D6988(u8 *p);
extern void func_021B64D0(u8 *, u32);
typedef unsigned short u16;
struct Obj;
extern void func_021D7D3C(char *p);
extern void func_021D6814(u8 *p);
extern int func_021D444C(int n, char *p);
extern void func_021D4C98(void *p, int n, u8 *s);
extern void func_021D7DC8(char *p, int a, int b, int c, int d, int e);
extern void func_021D79F4(u8 *p, u16 n);
extern void *func_021D7ECC(char *p, u16 n);
extern u8 func_020355C4(void);
extern void func_021D69F4(u8 *p, void *q, u32 n);
extern void func_02028218(struct Obj *obj, u32 a);
extern void func_02041B6C(u32 bit);
extern void func_021D4244(int *p, int v, int a2);
extern void func_021D4D28(u8 *p);
void func_021D4EC0(u8 *p)
{
    ((struct Obj01253 *)p)->f138 = 0;
    func_021B64D0((u8 *)func_021D6988(((struct Obj01253 *)p)->f3C), 1);
    func_021D7D3C(((struct Obj01253 *)p)->f40);
    func_021D6814(((struct Obj01253 *)p)->f3C);
    *(void (**)(int))(p + 4) = (void (*)(int))func_021D444C;
    func_021D7DC8(((struct Obj01253 *)p)->f40, (int)func_021D4C98, (int)p, ((struct Obj01253 *)p)->f144, ((struct Obj01253 *)p)->f13C, ((struct Obj01253 *)p)->f140);
    func_021D79F4(((struct Obj01253 *)p)->f40, 20);
    ((struct Obj01253 *)p)->f34 = func_021D7ECC(((struct Obj01253 *)p)->f40, 18);
    if (func_020355C4() == 0) {
        func_021D69F4(((struct Obj01253 *)p)->f3C, 0, ((struct Obj01253 *)p)->f160);
        if (((struct Obj01253 *)p)->f160 == 5)
            func_02028218(((struct Obj01253 *)p)->f34, 1);
    } else {
        func_021D69F4(((struct Obj01253 *)p)->f3C, 0, 9);
    }
    func_02041B6C(6);
    func_021D4244((int *)p, (int)((void (*)(int))func_021D4D28), 0x537);
}
