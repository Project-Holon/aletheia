/*
 * function: func_0220D024
 * address: 0x0220D024
 * packet: pkt_ov197_0220D024
 * region: ov197
 * compiler: 1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0220D884 0x0220D884 thumb ov197
 *   func_02025DE8 0x02025DE8 thumb
 *   func_0220D89C 0x0220D89C thumb ov197
 *   func_0220BB98 0x0220BB98 thumb ov197
 *   func_0220BBD8 0x0220BBD8 thumb ov197
 *   func_0220BF20 0x0220BF20 thumb ov197
 *   func_0220D11C 0x0220D11C thumb ov197
 */
#include "../include/Obj02245.h"
#include "../include/Obj25081.h"
#include "../include/Obj25082.h"
#include "../include/Obj25083.h"
#include "../include/Obj25084.h"
#include "../include/Obj25085.h"
#include "../include/Obj25086.h"
typedef unsigned char u8;
typedef unsigned short u16;
extern int func_0220D884(char **);
typedef unsigned int   u32;
struct Sound;
extern int func_02025DE8(struct Sound *obj);
extern void func_0220D89C(char **, int);
extern unsigned func_0220BB98(const char *, int);
extern u16 func_0220BBD8(u32 key);
extern void func_0220BF20(char *, int);
extern int func_0220D11C(char *);
int func_0220D024(char *p)
{
    if (func_0220D884((char **)p) == 1) return 0x12;
    switch ((unsigned)func_02025DE8(((struct Obj02245 *)p)->f144)) {
    case 0:
        func_0220D89C((char **)p, 0x54d);
        ((struct Obj25081 *)(*(char * *)&((struct Obj02245 *)p)->f0))->f16 = func_0220BB98(p, *(short *)(*(char * *)&((struct Obj02245 *)p)->f0 + ((struct Obj02245 *)p)->f533 * 2 + 0x30));
        ((struct Obj25082 *)(*(char * *)&((struct Obj02245 *)p)->f0))->f2A = ((struct Obj02245 *)p)->f533;
        if (((struct Obj25083 *)(*(char * *)&((struct Obj02245 *)p)->f0))->f8 == 1)
            ((struct Obj25085 *)(*(char * *)&((struct Obj02245 *)p)->f0))->f18 = func_0220BBD8(((struct Obj25084 *)(*(char * *)&((struct Obj02245 *)p)->f0))->f16);
        else
            ((struct Obj25086 *)(*(char * *)&((struct Obj02245 *)p)->f0))->f18 = 0;
        func_0220BF20(p, 0xd);
        return func_0220D11C(p);
    case 1:
        func_0220D89C((char **)p, 0x552);
        ((struct Obj02245 *)p)->f531 = 8;
        func_0220BF20(p, 0xa);
        return 0x10;
    case (unsigned)-2:
        func_0220D89C((char **)p, 0x552);
        ((struct Obj02245 *)p)->f531 = 8;
        func_0220BF20(p, 0xa);
        return 0x10;
    case (unsigned)-4:
    case (unsigned)-3:
        func_0220D89C((char **)p, 0x548);
        break;
    case (unsigned)-8:
    case (unsigned)-7:
    case (unsigned)-6:
    case (unsigned)-5:
    case (unsigned)-1:
        break;
    }
    return 6;
}
