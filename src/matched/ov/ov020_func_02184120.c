/*
 * function: func_02184120
 * address:  0x02184120
 * packet:   pkt_ov020_02184120
 * region:   ov020
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021BE89C  0x021BE89C  thumb  ov021
 *   func_021BE8B8  0x021BE8B8  thumb  ov021
 *   sub_0202E8A4   0x0202E8A4  thumb
 *   func_02012844  0x02012844  thumb
 *   func_021625CC  0x021625CC  thumb  ov010
 *   func_021626E8  0x021626E8  thumb  ov010
 */
#include "../include/Obj00082.h"
#include "../include/Obj02069.h"

typedef unsigned char  u8;
typedef unsigned short u16;

typedef struct { int w[7]; } Blk28;

extern int func_021BE89C(int a, int b);
extern int func_021BE8B8(int a, int b);
extern u8 sub_0202E8A4(u8 a);
typedef unsigned int   u32;
struct BigObj;
extern u32 func_02012844(const struct BigObj *p);
extern void *func_021625CC(char *p, unsigned i);
extern u8 func_021626E8(u8 *p);

void func_02184120(u8 *p, int arg)
{
    u8 *q = p + 0x4c;

    ((struct Obj02069 *)q)->f4 = *(int *)&((struct Obj00082 *)p)->f0;
    ((struct Obj02069 *)q)->f8 = ((struct Obj00082 *)p)->f4;
    ((struct Obj02069 *)q)->fC = *(int *)&((struct Obj00082 *)p)->f8;
    ((struct Obj02069 *)q)->f10 = ((struct Obj00082 *)p)->f2C;
    ((struct Obj00082 *)p)->f4C = arg;
    ((struct Obj02069 *)q)->f18 = ((struct Obj00082 *)p)->fC;
    *(Blk28 *)(q + 0x1c) = *(Blk28 *)(p + 0x10);
    ((struct Obj02069 *)q)->f38 = func_021BE89C(((struct Obj00082 *)p)->fC, ((struct Obj00082 *)p)->f14);
    ((struct Obj02069 *)q)->f3C = func_021BE8B8(((struct Obj00082 *)p)->fC, ((struct Obj00082 *)p)->f14);
    ((struct Obj02069 *)q)->f40 = (((struct Obj00082 *)p)->f40 != 0 && ((struct Obj00082 *)p)->f44 != 0) ? 1 : 0;
    ((struct Obj02069 *)q)->f44 = sub_0202E8A4(((struct Obj00082 *)p)->f48);
    ((struct Obj02069 *)q)->f45 = ((struct Obj00082 *)p)->f4A;
    if (((struct Obj00082 *)p)->f10 == 1) {
        ((struct Obj02069 *)q)->f14 = 0;
        return;
    }
    ((struct Obj02069 *)q)->f14 = func_021626E8(func_021625CC((char *)func_02012844((const struct BigObj *)(((struct Obj00082 *)p)->f4)), ((struct Obj00082 *)p)->f16));
}
