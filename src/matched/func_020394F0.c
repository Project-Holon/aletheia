/*
 * function: func_020394F0
 * address:  0x020394F0
 * packet:   pkt_020394F0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * symbols:
 *   g_021469D0     0x021469D0  data
 *   func_0203D798  0x0203D798  arm
 */

typedef unsigned int u32;
typedef unsigned char u8;

typedef struct {
    u8 pad_000[0x65];
    u8 f065;
} T_0203D798;

typedef struct {
    u8 pad_000[0x1ac];
    u32 f1ac;
    u32 f1b0;
    u32 f1b4;
    u32 f1b8;
} T_020394F0;

extern T_0203D798 *func_0203D798(void);
extern T_020394F0 *g_021469D0;

void func_020394F0(u32 a)
{
    u8 v = func_0203D798()->f065;

    if ((u8)(v + 0xff) > 1) {
        return;
    }
    g_021469D0->f1ac = a;
    if (a == 0) {
        return;
    }
    g_021469D0->f1b0 = 0;
    g_021469D0->f1b4 = 0;
    g_021469D0->f1b8 = 0;
}
