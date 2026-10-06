/*
 * function: func_021B30C8
 * address:  0x021B30C8
 * packet:   pkt_ov021_021B30C8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0218F1B4  0x0218F1B4  thumb
 *   func_0218F1AC  0x0218F1AC  thumb
 *   func_0218F848  0x0218F848  thumb
 *   func_02188CB4  0x02188CB4  thumb
 *   func_021A3050  0x021A3050  thumb
 *   func_0218ECE4  0x0218ECE4  thumb
 *   func_0218ECB4  0x0218ECB4  thumb
 *   func_0218EC54  0x0218EC54  thumb
 *   func_0218F918  0x0218F918  thumb
 *   d_021D9708     0x021D9708  data
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

typedef struct { s32 x, y, z; } Vec3;

typedef struct {
    Vec3 a;
    Vec3 b;
    Vec3 c;
    Vec3 d;
    s32 e[5];
    s32 f;
} Param;

extern u8 func_0218F1B4(u8 *p);
extern void func_0218F1AC(u8 *p, u32 v);
extern void func_0218F848(u8 *a);
extern void *func_02188CB4(unsigned char *p);
extern u16 func_021A3050(u8 *p);
extern void func_0218ECE4(void *h, Vec3 *out);
extern void func_0218ECB4(void *h, Vec3 *out);
extern void func_0218EC54(u8 *p);
extern void func_0218F918(void *h, Param *p, int n);

extern Vec3 d_021D9708[];

void func_021B30C8(u32 *p, u32 b, void *h)
{
    Param s;
    int i;

    p[1] = func_0218F1B4(h);
    func_0218F1AC(h, 0);
    func_0218F848(h);
    i = func_021A3050(func_02188CB4((void *)b));
    func_0218ECE4(h, &s.a);
    func_0218ECB4(h, &s.b);
    func_0218EC54(h);
    s.b.x += d_021D9708[i].x;
    s.b.y += d_021D9708[i].y;
    s.b.z += d_021D9708[i].z;
    s.e[0] = 0;
    s.e[1] = 0;
    s.e[2] = 0;
    s.e[3] = 0;
    s.e[4] = 0;
    s.f = 1;
    func_0218F918(h, &s, 10);
}
