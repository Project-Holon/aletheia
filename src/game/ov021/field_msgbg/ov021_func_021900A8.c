/*
 * function: func_021900A8
 * address:  0x021900A8
 * packet:   pkt_ov021_021900A8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0218F18C  0x0218F18C  thumb
 *   func_0218EC90  0x0218EC90  thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

typedef struct { u32 a, b, c; } Vec3;

extern void func_0218F18C(void *a, Vec3 *out);
extern void func_0218EC90(void *a, const Vec3 *p);

void func_021900A8(void *a)
{
    Vec3 t;
    func_0218F18C(a, &t);
    func_0218EC90(a, &t);
}
