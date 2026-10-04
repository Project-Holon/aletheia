/*
 * function: func_021BA9B4
 * address:  0x021BA9B4
 * packet:   pkt_ov021_021BA9B4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_021B8220  0x021B8220  thumb  ov021
 *   func_021B830C  0x021B830C  thumb  ov021
 *   func_021B821C  0x021B821C  thumb  ov021
 *   func_021B79D4  0x021B79D4  thumb  ov021
 *   func_0218E124  0x0218E124  thumb  ov021
 *   func_0218EC60  0x0218EC60  thumb  ov021
 *   func_0207CA00  0x0207CA00  arm
 *   func_0207CCA4  0x0207CCA4  arm
 *   func_0207CFB8  0x0207CFB8  arm
 *   func_0218ED34  0x0218ED34  thumb  ov021
 *   func_0218ED58  0x0218ED58  thumb  ov021
 *   func_0218ED48  0x0218ED48  thumb  ov021
 * Addresses are Black-image addresses.
 */
#include "../include/Obj07529.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct { int x, y, z; } V;

u32 func_021B8220(u8 *p);
u8 *func_021B830C(void);
u32 func_021B821C(u8 *p);
void func_021B79D4(u8 *p, V *v);
void func_0218E124(u8 *a, u32 s);
u32 func_0218EC60(u32 a);
void func_0207CA00(const V *a, const V *b, V *c);
void func_0207CCA4(const V *a, V *b);
int func_0207CFB8(int a, int b);
void func_0218ED34(u8 *p, u16 v);
void func_0218ED58(u8 *p, u32 v);
void func_0218ED48(u32 o, u32 v);

void func_021BA9B4(u8 *p)
{
    V w;
    V v;
    u8 *q;
    u32 o;
    int h;

    func_021B8220(p);
    q = func_021B830C();
    o = func_021B821C(p);
    func_0218E124((u8 *)o, 0);
    func_0218EC60(func_021B821C(p));
    func_021B79D4(p, &v);
    v.y = 0;
    w.x = ((struct Obj07529 *)q)->fC;
    w.y = 0;
    w.z = ((struct Obj07529 *)q)->f10;
    func_0207CA00(&v, &w, &v);
    func_0207CCA4(&v, &v);
    h = func_0207CFB8(v.x, v.z);
    func_0218ED34((u8 *)o, ((struct Obj07529 *)q)->f4);
    func_0218ED58((u8 *)o, ((struct Obj07529 *)q)->f8);
    func_0218ED48(o, h);
}
