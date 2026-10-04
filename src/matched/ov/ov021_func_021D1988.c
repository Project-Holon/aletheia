/*
 * function: func_021D1988
 * address:  0x021D1988
 * packet:   pkt_ov021_021D1988
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02011610  0x02011610  thumb
 *   func_02011638  0x02011638  thumb
 *   func_0207C9D0  0x0207C9D0  arm
 *   func_0216D89C  0x0216D89C  thumb  ov010
 *   func_0216D60C  0x0216D60C  thumb  ov010
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef int            s32;

typedef struct Vec3 { s32 x, y, z; } Vec3;

struct IcaAnime;
struct Rec12;
extern u32 func_02011610(struct IcaAnime *a, struct Rec12 *out);
extern u32 func_02011638(struct IcaAnime *a, struct Rec12 *out);
extern void func_0207C9D0(Vec3 *a, Vec3 *b, Vec3 *c);
extern void func_0216D89C(u32 a, Vec3 *v);
extern int func_0216D60C(int a0, int a1);

void func_021D1988(u32 a, u32 b, Vec3 *c)
{
    Vec3 v1;
    Vec3 v0;

    func_02011610((struct IcaAnime *)a, (struct Rec12 *)&v1);
    func_02011638((struct IcaAnime *)a, (struct Rec12 *)&v0);
    func_0207C9D0(&v1, c, &v1);
    func_0216D89C(b, &v1);
    if (v0.y == 0) {
        func_0216D60C(b, 1);
    } else if (v0.y == 0x5A000) {
        func_0216D60C(b, 3);
    } else if (v0.y == 0xB4000) {
        func_0216D60C(b, 0);
    } else if (v0.y == 0x10E000) {
        func_0216D60C(b, 2);
    }
}
