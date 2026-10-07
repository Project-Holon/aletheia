/*
 * file:     field_nogrid_mapper_p09.c
 * unit:     yes
 * function: func_021BA4C4, func_021BA4FC
 * address:  0x021BA4C4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021B8220  0x021B8220  thumb  ov021
 *   func_021B821C  0x021B821C  thumb  ov021
 *   func_021BA348  0x021BA348  thumb  ov021
 *   func_0218EC54  0x0218EC54  thumb  ov021
 *   func_021B8314  0x021B8314  thumb  ov021
 *   func_0218EC90  0x0218EC90  thumb  ov021
 *   func_021B830C  0x021B830C  thumb  ov021
 *   func_0218E124  0x0218E124  thumb  ov021
 *   func_0218ECF4  0x0218ECF4  thumb  ov021
 */
#include "../../matched/include/Obj05053.h"

typedef unsigned char  u8;

typedef unsigned int   u32;

typedef struct { int x, y, z; } V;

typedef unsigned short u16;

u32 func_021B8220(u8 *p);
u32 func_021B821C(u8 *p);
void func_021BA348(u32 p);
void func_0218EC54(u8 *p);
void func_021B8314(u32 a, V *v);
void func_0218EC90(u32 a, V *v);
u8 *func_021B830C(void);
void func_0218E124(u8 *a, u32 s);
void func_0218ECF4(u32 a, V *v);
void func_021BA4C4(u8 *p);
void func_021BA4FC(u8 *p);


/*
 * Addresses are Black-image addresses.
 */
void func_021BA4C4(u8 *p)
{
    V v;
    u32 q;
    u32 o;

    q = func_021B8220(p);
    o = func_021B821C(p);
    func_021BA348((u32)p);
    func_0218EC54((u8 *)o);
    func_021B8314(q, &v);
    func_0218EC90(o, &v);
}


void func_021BA4FC(u8 *p)
{
    V a;
    V b;
    u8 *q;
    u32 o;

    func_021B8220(p);
    q = func_021B830C();
    o = func_021B821C(p);
    func_0218E124((u8 *)o, 2);
    func_0218EC54((u8 *)func_021B821C(p));
    a.x = ((struct Obj05053 *)q)->f4;
    a.y = ((struct Obj05053 *)q)->f8;
    a.z = ((struct Obj05053 *)q)->fC;
    b.x = ((struct Obj05053 *)q)->f10;
    b.y = ((struct Obj05053 *)q)->f14;
    b.z = ((struct Obj05053 *)q)->f18;
    func_0218ECF4(o, &a);
    func_0218EC90(o, &b);
}
