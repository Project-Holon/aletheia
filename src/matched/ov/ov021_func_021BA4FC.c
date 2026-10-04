/*
 * function: func_021BA4FC
 * address:  0x021BA4FC
 * packet:   pkt_ov021_021BA4FC
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
 *   func_0218E124  0x0218E124  thumb  ov021
 *   func_0218EC54  0x0218EC54  thumb  ov021
 *   func_0218ECF4  0x0218ECF4  thumb  ov021
 *   func_0218EC90  0x0218EC90  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct { int x, y, z; } V;

u32 func_021B8220(u8 *p);
u8 *func_021B830C(void);
u32 func_021B821C(u8 *p);
void func_0218E124(u8 *a, u32 s);
void func_0218EC54(u8 *p);
void func_0218ECF4(u32 a, V *v);
void func_0218EC90(u32 a, V *v);

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
    a.x = *(int *)(q + 4);
    a.y = *(int *)(q + 8);
    a.z = *(int *)(q + 12);
    b.x = *(int *)(q + 0x10);
    b.y = *(int *)(q + 0x14);
    b.z = *(int *)(q + 0x18);
    func_0218ECF4(o, &a);
    func_0218EC90(o, &b);
}
