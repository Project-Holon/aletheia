/*
 * function: func_021F38F0
 * address:  0x021F38F0
 * packet:   pkt_ov052_021F38F0
 * region:   ov052
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02188C98  0x02188C98  thumb  ov021
 *   func_0218DC4C  0x0218DC4C  thumb  ov021
 *   d_021F39CC     0x021F39CC  data  a4
 */
#include "../include/Obj01038.h"
#include "../include/Obj20568.h"

typedef struct { int v[4]; } T4;
typedef struct { int x, y, z; } V3;

extern T4 d_021F39CC;
typedef unsigned int   u32;
typedef unsigned char  u8;
extern u32 func_02188C98(u8 *p);
extern void func_0218DC4C(int, V3 *);

void func_021F38F0(char *a, int b)
{
    V3 v = {0, 0, 0};
    T4 t = d_021F39CC;
    unsigned char *p = *(unsigned char * *)&((struct Obj20568 *)a)->f24;
    int r = func_02188C98((u8 *)b);

    switch (p[1]) {
    case 0:
        if (p[0] == 1)
            return;
        ((struct Obj01038 *)p)->f4 = t.v[p[2]];
        p[2]++;
        p[2] &= 3;
        p[1]++;
    case 1:
        if (--((struct Obj01038 *)p)->f4 <= 0) {
            ((struct Obj01038 *)p)->f8 = 1;
            p[1]++;
        }
        break;
    case 2:
        v.y = ((struct Obj01038 *)p)->f8 << 12;
        func_0218DC4C(r, &v);
        if (((struct Obj01038 *)p)->f8 == 0)
            p[1] = 0;
        if (((struct Obj01038 *)p)->f8 < 0) {
            ((struct Obj01038 *)p)->f8 += 2;
            if (((struct Obj01038 *)p)->f8 > 0)
                ((struct Obj01038 *)p)->f8 = 0;
        }
        ((struct Obj01038 *)p)->f8 = -((struct Obj01038 *)p)->f8;
        break;
    }
}
