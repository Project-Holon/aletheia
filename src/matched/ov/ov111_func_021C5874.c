/*
 * function: VIEWER_MAIN_InitLcdBrightness
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
 *   FX_Inv  0x0207C778  arm
 *   OS_WaitVBlankIntr  0x02087AE4  arm
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

extern fx32 FX_Inv(fx32 v);
extern void OS_WaitVBlankIntr(void);
extern void func_0207D59C(void *reg, struct Mtx *m, u32 a, u32 b, u32 x, u32 y);

void VIEWER_MAIN_InitLcdBrightness(void)
{
    struct Mtx m;
    fx32 a, d;

    a = FX_Inv(0x1000);
    d = FX_Inv(0x1000);
    m._00 = a;
    m._01 = 0;
    m._10 = 0;
    m._11 = d;
    OS_WaitVBlankIntr();
    func_0207D59C((void *)0x04001020, &m, 0x80, 0x60, 0, 0);
    func_0207D59C((void *)0x04001030, &m, 0x80, 0x60, 0, 0);
    OS_WaitVBlankIntr();
    func_0207D59C((void *)0x04000030, &m, 0x80, 0, 0, 0);
}
