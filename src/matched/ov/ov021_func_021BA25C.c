/*
 * function: func_021BA25C
 * address:  0x021BA25C
 * packet:   pkt_ov021_021BA25C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_021B8220  0x021B8220  thumb  ov021
 *   func_021B830C  0x021B830C  thumb  ov021
 *   func_021B79D4  0x021B79D4  thumb  ov021
 *   func_021B821C  0x021B821C  thumb  ov021
 *   func_0218E124  0x0218E124  thumb  ov021
 *   func_0218ECF4  0x0218ECF4  thumb  ov021
 *   func_0218EC60  0x0218EC60  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct { int x, y, z; } V;

u32 func_021B8220(u8 *p);
u8 *func_021B830C(void);
void func_021B79D4(u8 *p, V *v);
u32 func_021B821C(u8 *p);
void func_0218E124(u8 *a, u32 s);
void func_0218ECF4(u32 a, V *v);
u32 func_0218EC60(u32 a);

void func_021BA25C(u8 *p)
{
    V v;
    u8 *q;

    func_021B8220(p);
    q = func_021B830C();
    func_021B79D4(p, &v);
    func_0218E124((u8 *)func_021B821C(p), 2);
    v.x += *(int *)(q + 4);
    v.y += *(int *)(q + 8);
    v.z += *(int *)(q + 12);
    func_0218ECF4(func_021B821C(p), &v);
    func_0218EC60(func_021B821C(p));
}
