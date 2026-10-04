/*
 * function: func_021E9984
 * address: 0x021E9984
 * packet: pkt_ov093_021E9984
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021D3D70 0x021D3D70 thumb ov093
 *   func_021B8F5C 0x021B8F5C thumb ov093
 *   func_021B8F38 0x021B8F38 thumb ov093
 *   func_021B8F7C 0x021B8F7C thumb ov093
 *   func_021B8FC0 0x021B8FC0 thumb ov093
 *   func_021B8588 0x021B8588 thumb ov093
 *   func_021B99B8 0x021B99B8 thumb ov093
 *   func_021E9A68 0x021E9A68 thumb ov093
 *   func_021F86D4 0x021F86D4 thumb ov094
 *   func_021F86E0 0x021F86E0 thumb ov094
 *   func_021B8748 0x021B8748 thumb ov093
 *   func_021B86B8 0x021B86B8 thumb ov093
 */
#include "../include/Obj00056.h"
#include "../include/Obj00714.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u8 func_021D3D70(u8 *p);
extern int func_021B8F5C(u8 *, u32);
extern int func_021B8F38(unsigned char *p);
extern int func_021B8F7C(u8 *, u32);
extern unsigned char func_021B8FC0(unsigned char *p, unsigned int k);
extern u32 func_021B8588(void **p);
extern int func_021B99B8(void *pp, unsigned int b);
extern int func_021E9A68(void *);
extern void *func_021F86D4(void);
extern int func_021F86E0(void);
extern u32 func_021B8748(void **p);
extern void *func_021B86B8(void ***);

void func_021E9984(u8 *p, u8 *q, int mode, u8 x, int y)
{
    u32 k;
    int zero;
    int active;
    k = func_021D3D70(((struct Obj00056 *)p)->f4);
    ((struct Obj00714 *)q)->f4 = func_021B8F5C(*(u8 * *)&((struct Obj00056 *)p)->f0, k);
    if (mode != 3) active = func_021B8F38(((struct Obj00056 *)p)->f0);
    else active = 0;
    ((struct Obj00714 *)q)->f18 = active;
    if (active) {
        ((struct Obj00714 *)q)->f8 = func_021B8F7C(*(u8 * *)&((struct Obj00056 *)p)->f0, k);
        q[0x1c] = func_021B8FC0(((struct Obj00056 *)p)->f0, k);
    } else {
        ((struct Obj00714 *)q)->f8 = 0;
        q[0x1c] = 0;
    }
    q[0x1f] = mode;
    if (func_021B8588(((struct Obj00056 *)p)->f0) != 3) q[0x22] = func_021B99B8(((struct Obj00056 *)p)->f0, k);
    else q[0x22] = 3;
    switch (mode) {
    case 4:
    case 5: active = x; break;
    default: active = 0; break;
    }
    q[0x20] = active;
    q[0x21] = x;
    ((struct Obj00714 *)q)->f26 = y;
    q[0x4b] = 0;
    ((struct Obj00714 *)q)->f10 = ((struct Obj00056 *)p)->f184;
    ((struct Obj00714 *)q)->fC = ((struct Obj00056 *)p)->fB0;
    ((struct Obj00714 *)q)->f14 = func_021B8588(((struct Obj00056 *)p)->f0);
    ((struct Obj00714 *)q)->f44 = func_021E9A68(((struct Obj00056 *)p)->f180);
    ((struct Obj00714 *)q)->f28 = func_021F86D4();
    ((struct Obj00714 *)q)->f2C = (void *)func_021F86E0();
    ((struct Obj00714 *)q)->f0 = (void *)func_021B8748(((struct Obj00056 *)p)->f0);
    ((struct Obj00714 *)q)->f30 = 0;
    zero = 0;
    if ((int)func_021B86B8(*(void *** *)&((struct Obj00056 *)p)->f0) != 3) zero = 1;
    ((struct Obj00714 *)q)->f40 = zero;
    ((struct Obj00714 *)q)->f34 = 0;
    q[0x4c] = 0;
}
