/*
 * function: func_021AC3F8
 * address:  0x021AC3F8
 * packet:   pkt_ov021_021AC3F8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0216E3C4  0x0216E3C4  thumb  ov010
 *   func_0216D88C  0x0216D88C  thumb  ov010
 *   func_0216D92C  0x0216D92C  thumb  ov010
 *   func_0207C9D0  0x0207C9D0  arm
 *   func_0216D8B0  0x0216D8B0  thumb  ov010
 *   func_0204F720  0x0204F720  arm
 *   func_0204F638  0x0204F638  arm
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef int            s32;

typedef struct Vec3 { s32 x, y, z; } Vec3;

extern u8 *func_0216E3C4(u32 a);
extern void func_0216D88C(u32 a, Vec3 *v);
extern void func_0216D92C(u32 a, Vec3 *v);
extern void func_0207C9D0(Vec3 *a, Vec3 *b, Vec3 *c);
extern void func_0216D8B0(u32 a, Vec3 *v);
extern void func_0204F720(u32 a, u32 b, u32 *c);
extern void func_0204F638(u32 a, u32 b, Vec3 *c);

void func_021AC3F8(u32 unused, u32 *p)
{
    Vec3 v1;
    Vec3 v2;
    u32 one;
    u32 zero;
    u32 r4 = p[5];
    u8 *r6 = func_0216E3C4(p[2]);
    if (p[0] == 0) {
        one = 1;
        func_0216D88C(p[2], &v1);
        func_0216D92C(p[2], &v2);
        func_0207C9D0(&v1, &v2, &v1);
        if ((u8)(r6[3] + 246) <= 1) {
            func_0216D8B0(p[2], &v2);
            if (r6[7] == 0)
                v2.y = -0x800;
            func_0207C9D0(&v1, &v2, &v1);
        }
        func_0204F720(*(u32 *)(p[1] + 0x14), r4, &one);
        v1.y += 0x1000;
        func_0204F638(*(u32 *)(p[1] + 0x14), r4, &v1);
    } else {
        zero = 0;
        func_0204F720(*(u32 *)(p[1] + 0x14), r4, &zero);
    }
}
