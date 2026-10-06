/*
 * function: func_02190110
 * address:  0x02190110
 * packet:   pkt_ov021_02190110
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021901E8  0x021901E8  thumb
 *   func_0218ED34  0x0218ED34  thumb
 *   func_0218ED48  0x0218ED48  thumb
 *   func_0218ED58  0x0218ED58  thumb
 *   func_0218EC90  0x0218EC90  thumb
 *   func_0218ECD4  0x0218ECD4  thumb
 */
#include "../include/Obj19579.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

typedef struct { u32 a, b, c; } Vec3;

typedef struct {
    u16 h0;
    u16 h2;
    u32 w4;
    Vec3 v8;
    Vec3 v14;
} Params;

extern u32 func_021901E8(u8 *p);
extern void func_0218ED34(u8 *p, u16 v);
extern void func_0218ED48(u8 *p, u32 v);
extern void func_0218ED58(u8 *p, u32 v);
extern void func_0218EC90(void *a, const Vec3 *p);
extern void func_0218ECD4(void *a, const Vec3 *p);

void func_02190110(u8 *a)
{
    void *x = ((struct Obj19579 *)a)->f4;
    Params *p = (Params *)(func_021901E8(a) + 0x24);
    func_0218ED34(x, p->h0);
    func_0218ED48(x, p->h2);
    func_0218ED58(x, p->w4);
    func_0218EC90(x, &p->v8);
    func_0218ECD4(x, &p->v14);
}
