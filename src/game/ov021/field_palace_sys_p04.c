/*
 * file:     field_palace_sys_p04.c
 * unit:     yes
 * function: func_021D1988, func_021D1A04
 * address:  0x021D1988
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
 *   func_02011610  0x02011610  thumb
 *   func_02011638  0x02011638  thumb
 *   func_0207C9D0  0x0207C9D0  arm
 *   func_0216D89C  0x0216D89C  thumb  ov010
 *   func_0216D60C  0x0216D60C  thumb  ov010
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_02158F58  0x02158F58  thumb  ov010
 *   func_02188C84  0x02188C84  thumb  ov021
 *   func_02159B10  0x02159B10  thumb  ov010
 *   func_02188CB4  0x02188CB4  thumb  ov021
 *   func_021A3038  0x021A3038  thumb  ov021
 *   func_021D182C  0x021D182C  thumb  ov021
 *   func_02159104  0x02159104  thumb  ov010
 */
struct IcaAnime;
struct Rec12;
struct Obj00020;
struct VecFx32;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef int            s32;

typedef struct Vec3 { s32 x, y, z; } Vec3;

extern u32 func_02011610(struct IcaAnime *a, struct Rec12 *out);
extern u32 func_02011638(struct IcaAnime *a, struct Rec12 *out);
extern void func_0207C9D0(Vec3 *a, Vec3 *b, Vec3 *c);
extern void func_0216D89C(u32 a, Vec3 *v);
extern int func_0216D60C(int a0, int a1);
extern void *func_0215A5F4(void *p);
extern int func_02158F58(int a0);
extern u16 func_02188C84(u8 *p);
extern unsigned int func_02159B10(void *a, void *b);
extern void *func_02188CB4(struct Obj00020 *p);
extern void func_021A3038(unsigned char *p, struct VecFx32 *out);
extern u8 *func_021D182C(u32 a, u32 b, u32 *c, u32 d);
extern void func_02159104(u8 *p, u32 v);
void func_021D1988(u32 a, u32 b, Vec3 *c);
int func_021D1A04(u32 a, u32 b);


/*
 * Addresses are Black-image addresses.
 */
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


int func_021D1A04(u32 a, u32 b)
{
    u32 buf[3];
    void *s = func_0215A5F4((void *)b);
    u32 *q = (u32 *)func_02158F58((int)s);
    u32 t = func_02188C84((u8 *)q[1]);
    u32 k = func_02159B10((void *)a, (void *)b);
    u8 *r;

    func_021A3038(func_02188CB4((struct Obj00020 *)q[1]), (struct VecFx32 *)buf);
    r = func_021D182C(q[1], k, buf, t);
    func_02159104(s, (u32)r);
    return 0;
}
