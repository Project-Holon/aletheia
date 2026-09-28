/*
 * function: func_021C5874
 * address:  0x021C5874
 * packet:   pkt_ov111_021C5874
 * region:   ov111
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0207C778  0x0207C778  arm
 *   func_02087AE4  0x02087AE4  arm
 *   func_0207D59C  0x0207D59C  arm
 *
 * Addresses are Black-image addresses.
 */

typedef int fx32;
typedef unsigned int u32;

struct Mtx {
    fx32 _00;
    fx32 _01;
    fx32 _10;
    fx32 _11;
};

extern fx32 func_0207C778(fx32 v);
extern void func_02087AE4(void);
extern void func_0207D59C(void *reg, struct Mtx *m, u32 a, u32 b, u32 x, u32 y);

void func_021C5874(void)
{
    struct Mtx m;
    fx32 a, d;

    a = func_0207C778(0x1000);
    d = func_0207C778(0x1000);
    m._00 = a;
    m._01 = 0;
    m._10 = 0;
    m._11 = d;
    func_02087AE4();
    func_0207D59C((void *)0x04001020, &m, 0x80, 0x60, 0, 0);
    func_0207D59C((void *)0x04001030, &m, 0x80, 0x60, 0, 0);
    func_02087AE4();
    func_0207D59C((void *)0x04000030, &m, 0x80, 0, 0, 0);
}
