/*
 * function: func_0220D464
 * address: 0x0220D464
 * packet: pkt_ov197_0220D464
 * region: ov197
 * compiler: 1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02209C2C 0x02209C2C thumb
 *   func_0220D89C 0x0220D89C thumb ov197
 *   func_0220BF20 0x0220BF20 thumb ov197
 *   func_0220D234 0x0220D234 thumb ov197
 *   func_0220D254 0x0220D254 thumb ov197
 *   func_0220BB98 0x0220BB98 thumb ov197
 *   func_0220D11C 0x0220D11C thumb ov197
 */
#include "../include/Obj00688.h"
#include "../include/Obj25098.h"
#include "../include/Obj25099.h"
#include "../include/Obj25100.h"
typedef unsigned char u8;
typedef unsigned short u16;
extern int func_02209C2C(void *);
extern void func_0220D89C(char **, int);
extern void func_0220BF20(char *, int);
extern int func_0220D234(char *);
extern int func_0220D254(char *);
extern unsigned func_0220BB98(const char *, int);
extern int func_0220D11C(char *);
int func_0220D464(char *p)
{
    switch (((struct Obj00688 *)p)->f53D) {
    case 0:
        if (func_02209C2C(((struct Obj00688 *)p)->f14C) == 1) {
            func_0220D89C((char **)p, 0x54d);
            ((struct Obj00688 *)p)->f533 = 2;
            ((struct Obj00688 *)p)->f531 = 0x11;
            func_0220BF20(p, 2);
            ++((struct Obj00688 *)p)->f53D;
            return 0x10;
        }
        break;
    case 1:
        if (func_02209C2C(((struct Obj00688 *)p)->f14C) == 0) {
            func_0220D234(p);
            ++((struct Obj00688 *)p)->f53D;
            ((struct Obj00688 *)p)->f531 = 0x11;
            return 0xa;
        }
        break;
    case 2:
        if (func_02209C2C(((struct Obj00688 *)p)->f14C) == 1) {
            func_0220D89C((char **)p, 0x54d);
            *(u16 *)(*(char * *)&((struct Obj00688 *)p)->f0 + ((struct Obj00688 *)p)->f533 * 2 + 0x30) = 0;
            ((struct Obj00688 *)p)->f531 = 0x11;
            func_0220BF20(p, 4);
            ++((struct Obj00688 *)p)->f53D;
            return 0x10;
        }
        break;
    case 3:
        if (func_02209C2C(((struct Obj00688 *)p)->f14C) == 0) {
            func_0220D254(p);
            ++((struct Obj00688 *)p)->f53D;
            ((struct Obj00688 *)p)->f531 = 0x11;
            return 0xa;
        }
        break;
    case 4:
        if (func_02209C2C(((struct Obj00688 *)p)->f14C) == 1) {
            func_0220D89C((char **)p, 0x54d);
            ((struct Obj25098 *)(*(char * *)&((struct Obj00688 *)p)->f0))->f16 = func_0220BB98(p, *(short *)(*(char * *)&((struct Obj00688 *)p)->f0 + ((struct Obj00688 *)p)->f533 * 2 + 0x30));
            ((struct Obj25099 *)(*(char * *)&((struct Obj00688 *)p)->f0))->f2A = ((struct Obj00688 *)p)->f533;
            ((struct Obj25100 *)(*(char * *)&((struct Obj00688 *)p)->f0))->f18 = 0;
            func_0220BF20(p, 0xd);
            ++((struct Obj00688 *)p)->f53D;
        }
        break;
    case 5:
        if (func_02209C2C(((struct Obj00688 *)p)->f14C) == 0) return func_0220D11C(p);
        break;
    }
    return 0x11;
}
