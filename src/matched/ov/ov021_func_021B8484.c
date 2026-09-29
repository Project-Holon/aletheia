/*
 * function: func_021B8484
 * address:  0x021B8484
 * packet:   pkt_ov021_021B8484
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_021B7DC0  0x021B7DC0  thumb  ov021
 *   func_021B7EE4  0x021B7EE4  thumb  ov021
 *   func_021B91F8  0x021B91F8  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct { u16 a, b, c, d; } Q;
typedef struct { int x, y, z; } V;

void func_021B7DC0(u8 *p, Q *q);
void func_021B7EE4(u8 *p, Q *q);
void func_021B91F8(u8 *p, V *v);

void func_021B8484(u8 *p, u32 a, u32 b, int c)
{
    Q q;

    func_021B7DC0(p, &q);
    q.a = a;
    q.c = 0;
    q.d = b;
    func_021B7EE4(p, &q);
    q.c = c - *(int *)(p + 0x18) / 16;
    func_021B91F8(p, (V *)(p + 0x38));
    *(u16 *)(p + 0x5c) = q.a;
    *(u16 *)(p + 0x5e) = q.b;
    *(u16 *)(p + 0x60) = q.c;
    *(u16 *)(p + 0x62) = q.d;
    *(u16 *)(p + 0x64) = q.a;
    *(u16 *)(p + 0x66) = q.b;
    *(u16 *)(p + 0x68) = q.c;
    *(u16 *)(p + 0x6a) = q.d;
    *(V *)(p + 0x44) = *(V *)(p + 0x38);
}
