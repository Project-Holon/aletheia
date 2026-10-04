/*
 * function: func_021BA2B4
 * address:  0x021BA2B4
 * packet:   pkt_ov021_021BA2B4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 * symbols:
 *   func_021B8220  0x021B8220  thumb  ov021
 *   func_021B830C  0x021B830C  thumb  ov021
 *   func_021B79D4  0x021B79D4  thumb  ov021
 *   func_021B821C  0x021B821C  thumb  ov021
 *   func_0218E124  0x0218E124  thumb  ov021
 *   func_0218EC60  0x0218EC60  thumb  ov021
 *   func_0218ED48  0x0218ED48  thumb  ov021
 *   func_0218ED34  0x0218ED34  thumb  ov021
 *   func_0218ED58  0x0218ED58  thumb  ov021
 * Addresses are Black-image addresses.
 */
#include "../include/Obj09635.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct { int x, y, z; } V;

u32 func_021B8220(u8 *p);
u8 *func_021B830C(void);
void func_021B79D4(u8 *p, V *v);
u32 func_021B821C(u8 *p);
void func_0218E124(u8 *a, u32 s);
u32 func_0218EC60(u32 a);
void func_0218ED48(u8 *p, u16 v);
void func_0218ED34(u8 *p, u16 v);
void func_0218ED58(u8 *p, u32 v);

void func_021BA2B4(u8 *p)
{
    V v;
    u8 *q;
    u32 o;
    u16 x, y;
    u32 z;

    o = func_021B821C(p);
    func_021B8220(p);
    q = func_021B830C();
    func_0218E124((u8 *)o, 0);
    func_0218EC60(func_021B821C(p));
    func_021B79D4(p, &v);
    x = ((struct Obj09635 *)q)->f4;
    y = ((struct Obj09635 *)q)->f8;
    z = ((struct Obj09635 *)q)->fC;
    func_0218ED48((u8 *)o, y);
    func_0218ED34((u8 *)o, x);
    func_0218ED58((u8 *)o, z);
}
