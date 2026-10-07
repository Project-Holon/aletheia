/*
 * file:     unit_021B95A0_p04.c
 * unit:     yes
 * function: func_021BA000, func_021BA028, func_021BA0AC, func_021BA128, func_021BA2A8, func_021BA2AC, func_021BA2D8
 * address:  0x021BA000
 * region:   ov181
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   _u32_div_f 0x0209C2B0 arm
 *   func_02048AE8 0x02048AE8 arm
 *   func_02048B30 0x02048B30 arm
 *   func_02048AFC 0x02048AFC arm
 *   func_02048B44 0x02048B44 arm
 *   func_02048AD0 0x02048AD0 arm
 *   func_0202208C 0x0202208C thumb
 *   func_0207D658 0x0207D658 arm
 */
#include "../../matched/include/Obj08304.h"
#include "../../matched/include/Obj14411.h"
#include "../../matched/include/Obj24507.h"
#include "../../matched/include/Obj24508.h"
#include "../../matched/include/Obj03877.h"

struct Light;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef struct { int x, y, z; } Vec;

extern void func_02048AE8(struct Light *, Vec *);
extern void func_02048B30(struct Light *, Vec *);
extern void func_02048AFC(struct Light *, const Vec *);
extern void func_02048B44(struct Light *, const Vec *);
extern void func_02048AD0(struct Light *);
extern void func_0202208C(void *,u32,u32,u32,u32,u32,u32);
extern void func_0207D658(unsigned, int, int);
void func_021BA000(u8 *p);
void func_021BA028(Vec *out, const Vec *base, const Vec *target, unsigned duration);
void func_021BA0AC(Vec *out, const Vec *base, const Vec *velocity, unsigned step);
void func_021BA128(char *p);
void func_021BA2A8(u8 *p,u32 a);
int func_021BA2AC(u8 *p, int a);
void func_021BA2D8(char *p);

void func_021BA000(u8 *p){u32 i;for(i=0;i<15;i++){u8 *q=p+i*4;((struct Obj08304 *)q)->f34=((struct Obj08304 *)q)->f38;((struct Obj08304 *)q)->f36=((struct Obj08304 *)q)->f3A;}((struct Obj14411 *)p)->f70=65535;((struct Obj14411 *)p)->f72=0;}

void func_021BA028(Vec *out, const Vec *base, const Vec *target, unsigned duration)
{
    Vec v;
    int b, a, diff;
    b = target->x;
    a = base->x;
    diff = a - b;
    if (diff < 0) diff = -diff;
    v.x = ((unsigned)diff << 8) / duration;
    if (a > b) v.x *= -1;
    b = target->y;
    a = base->y;
    diff = a - b;
    if (diff < 0) diff = -diff;
    v.y = ((unsigned)diff << 8) / duration;
    if (a > b) v.y *= -1;
    b = target->z;
    a = base->z;
    diff = a - b;
    if (diff < 0) diff = -diff;
    v.z = ((unsigned)diff << 8) / duration;
    if (a > b) v.z *= -1;
    *out = v;
}

void func_021BA0AC(Vec *out, const Vec *base, const Vec *velocity, unsigned step)
{
    Vec v = *base;
    unsigned n;
    n = ((unsigned)(velocity->x < 0 ? -velocity->x : velocity->x) * step) >> 8;
    if (velocity->x > 0) v.x += n; else v.x -= n;
    n = ((unsigned)(velocity->y < 0 ? -velocity->y : velocity->y) * step) >> 8;
    if (velocity->y > 0) v.y += n; else v.y -= n;
    n = ((unsigned)(velocity->z < 0 ? -velocity->z : velocity->z) * step) >> 8;
    if (velocity->z > 0) v.z += n; else v.z -= n;
    *out = v;
}

void func_021BA128(char *p)
{
    Vec a, b, c, d, e;
    char *q;
    q = p + 0x28;
    if (*(int *)(q + 0x7c) == 0) return;
    if (*(u16 *)(q + 0x78) == 0) {
        *(u16 *)(q + 0x7a) = *(u16 *)(q + 0x36);
        func_02048AE8(*(struct Light **)(p + 0xc), &a);
        func_021BA028(&b, &a, (Vec *)(*(unsigned *)q + *(u16 *)(q + 0x34) * 24), *(u16 *)(q + 0x7a));
        *(Vec *)(q + 0x1c) = b;
        func_02048B30(*(struct Light **)(p + 0xc), &a);
        func_021BA028(&c, &a, (Vec *)(*(unsigned *)q + *(u16 *)(q + 0x34) * 24 + 12), *(u16 *)(q + 0x7a));
        *(Vec *)(q + 0x28) = c;
    }
    if (*(u16 *)(q + 0x78) >= *(u16 *)(q + 0x7a)) {
        *(Vec *)(q + 4) = *(Vec *)(*(unsigned *)q + *(u16 *)(q + 0x34) * 24);
        *(Vec *)(q + 0x10) = *(Vec *)(*(unsigned *)q + *(u16 *)(q + 0x34) * 24 + 12);
        *(u16 *)(q + 0x76) = *(u16 *)(q + 0x34);
        *(u16 *)(q + 0x78) = 0;
        func_021BA000((u8 *)q);
        if (*(u16 *)(q + 0x34) == 0xffff) func_021BA2A8((u8 *)q, 0);
    } else {
        func_021BA0AC(&d, (Vec *)(*(unsigned *)q + *(u16 *)(q + 0x76) * 24), (Vec *)(q + 0x1c), *(u16 *)(q + 0x78));
        *(Vec *)(q + 4) = d;
        func_021BA0AC(&e, (Vec *)(*(unsigned *)q + *(u16 *)(q + 0x76) * 24 + 12), (Vec *)(q + 0x28), *(u16 *)(q + 0x78));
        *(Vec *)(q + 0x10) = e;
        if (*(unsigned char *)(p + 0x2d2) == 1) *(u16 *)(q + 0x78) += 4;
        else ++*(u16 *)(q + 0x78);
    }
    func_02048AFC(*(struct Light **)(p + 0xc), (Vec *)(q + 4));
    func_02048B44(*(struct Light **)(p + 0xc), (Vec *)(q + 0x10));
    func_02048AD0(*(struct Light **)(p + 0xc));
}

void func_021BA2A8(u8 *p,u32 a){((struct Obj24507 *)p)->f7C=a;}

int func_021BA2AC(u8 *p, int a){func_0202208C(0,0,0,0,6,1,142);((struct Obj24508 *)p)->f2F0=a;return 1;}

void func_021BA2D8(char *p)
{
    int v = ((struct Obj03877 *)p)->f1C;
    if (v <= 0x10000) {
        ((struct Obj03877 *)p)->f1C = v + (((struct Obj03877 *)p)->f2D2 == 1 ? 0x400 : 0x100);
        func_0207D658(0x04000050, 1, *(volatile int *)&((struct Obj03877 *)p)->f1C / 0x1000 - 0x10);
    }
}
