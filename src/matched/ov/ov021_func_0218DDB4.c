/*
 * function: func_0218DDB4
 * address:  0x0218DDB4
 * packet:   pkt_ov021_0218DDB4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   d_021D3DD4     0x021D3DD4  data a2
 *   func_021C0688  0x021C0688  thumb ov021
 *   func_021C068C  0x021C068C  thumb ov021
 *   func_021C06B4  0x021C06B4  thumb ov021
 *   func_021C06A8  0x021C06A8  thumb ov021
 */
#include "../include/Obj02370.h"
#include "../include/Obj03107.h"
#include "../include/Obj12588.h"

typedef unsigned char  u8;
typedef unsigned short u16;

typedef struct { u16 a; u16 b; u16 c; } S6;

extern S6 d_021D3DD4;
typedef unsigned int   u32;
extern u32 func_021C0688(u8 *p);
extern int func_021C068C(int x, int z, int o, u8 i);
extern int func_021C06B4(u8 i, int o);
extern int func_021C06A8(u8 i, int o);

void func_0218DDB4(const char *p, int *q, char *r)
{
    S6 tmp = d_021D3DD4;
    int cnt = 0;
    int base = ((struct Obj03107 *)r)->f100;
    int n = func_021C0688((u8 *)(((struct Obj02370 *)p)->f70));
    int z;
    int x;
    int i;

    x = q[0] / 0x10000;
    z = q[2] / 0x10000;
    for (i = 0; i < n; i++) {
        if (func_021C068C(x, z, ((struct Obj02370 *)p)->f70, i)) {
            int k = base + ++cnt - 1;
            char *e;
            if (k >= 0x10)
                break;
            e = r + k * 16;
            *(S6 *)e = tmp;
            ((struct Obj12588 *)e)->f8 = func_021C06B4(i, ((struct Obj02370 *)p)->f70);
            ((struct Obj12588 *)e)->fC = func_021C06A8(i, ((struct Obj02370 *)p)->f70);
        }
    }
    ((struct Obj03107 *)r)->f100 += (u16)cnt;
}
