/*
 * function: func_0218E018
 * address:  0x0218E018
 * packet:   pkt_ov021_0218E018
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02030734  0x02030734  arm
 *   d_021DDA28     0x021DDA28  data  ov021  a4
 *   func_02048B78  0x02048B78  arm
 *   func_02048B88  0x02048B88  arm
 *   func_0207D184  0x0207D184  arm
 *   func_020490F4  0x020490F4  arm
 *   func_0218E18C  0x0218E18C  thumb ov021
 *   func_0218EEFC  0x0218EEFC  thumb ov021
 */
#include "../include/Obj00519.h"

typedef unsigned char  u8;
typedef unsigned short u16;

extern void *func_02030734(u16, int, int, void *, int);
extern int d_021DDA28;
extern int func_02048B78(int a);
extern void func_02048B88(int a, int *out);
extern u16 func_0207D184(int a);
extern void *func_020490F4(unsigned int id, u16 heap);
extern void func_0218E18C(char *p, int a);
typedef unsigned int   u32;
extern void func_0218EEFC(int n, u32 x, u32 flags, u32 heap, void *a);

char *func_0218E018(int a0, int a1, int a2, int a3, u16 heap)
{
    int t;
    char *p = func_02030734(heap, 0x1b0, 1, &d_021DDA28, 0x80);
    ((struct Obj00519 *)p)->f10 = a0;
    ((struct Obj00519 *)p)->f14 = a1;
    ((struct Obj00519 *)p)->fC = a2;
    ((struct Obj00519 *)p)->f20 = 0;
    ((struct Obj00519 *)p)->f0 = heap;
    ((struct Obj00519 *)p)->f24 = 0;
    ((struct Obj00519 *)p)->f28 = 0;
    ((struct Obj00519 *)p)->f2C = 0;
    ((struct Obj00519 *)p)->f48 = 0;
    ((struct Obj00519 *)p)->f4C = 0;
    ((struct Obj00519 *)p)->f50 = 0;
    ((struct Obj00519 *)p)->f6C = 0;
    ((struct Obj00519 *)p)->f70 = 0;
    ((struct Obj00519 *)p)->f74 = 0;
    ((struct Obj00519 *)p)->f30 = 0;
    ((struct Obj00519 *)p)->f34 = 0;
    ((struct Obj00519 *)p)->f38 = 0;
    ((struct Obj00519 *)p)->f7A = 0;
    ((struct Obj00519 *)p)->f78 = 0;
    ((struct Obj00519 *)p)->f7C = 0x78;
    ((struct Obj00519 *)p)->fE9 = 1;
    if (func_02048B78(a2) == 0) {
        func_02048B88(a2, &t);
        ((struct Obj00519 *)p)->f80 = func_0207D184(t);
    }
    ((struct Obj00519 *)p)->f4 = func_020490F4(0x3c, ((struct Obj00519 *)p)->f0);
    ((struct Obj00519 *)p)->f8 = func_020490F4(0x6c, ((struct Obj00519 *)p)->f0);
    ((struct Obj00519 *)p)->fEA = 0xffff;
    func_0218E18C(p, a3);
    func_0218EEFC(7, 6, 2, heap, p);
    ((struct Obj00519 *)p)->f1AC = 0;
    return p;
}
