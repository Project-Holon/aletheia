/*
 * function: func_021B23E0
 * address:  0x021B23E0
 * packet:   pkt_ov013_021B23E0
 * region:   ov013
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   d_021B60D8  0x021B60D8  data  ov013  a4
 *   d_021B4BD0  0x021B4BD0  data  ov013  a4
 *   d_021B3C48  0x021B3C48  data  ov013  a4
 *   d_021B4BE0  0x021B4BE0  data  a4
 *   d_021B4C0C  0x021B4C0C  data  ov013  a4
 *   func_020870D0  0x020870D0  arm
 *   func_021B26DC  0x021B26DC  arm  ov013
 */

#include "../../../matched/include/G_Pool.h"

typedef unsigned long long u64;

typedef struct Ctx {
    int f0;
    int (*cb)(int, int, int, int);
    int arg;
    int fC;
    int state;
} Ctx;

typedef struct Stat {
    int f0;
    int f4;
    u64 t;
} Stat;

extern Ctx d_021B60D8;
extern Stat d_021B4BD0;
extern u64 d_021B3C48;
extern struct Pool d_021B4BE0;
extern char d_021B4C0C;
extern u64 func_020870D0(void);
extern void func_021B26DC(int);

void func_021B23E0(void)
{
    u64 now;

    now = func_020870D0();
    if (d_021B60D8.state != 2)
        return;
    if (d_021B60D8.fC == 0)
        return;
    if (d_021B4BD0.t == 0)
        return;
    if (now - d_021B4BD0.t <= d_021B3C48)
        return;
    d_021B4BD0.t = 0;
    d_021B4BE0.active_state = 0;
    d_021B4BE0.active_fc = 0;
    func_021B26DC(0);
    d_021B60D8.cb(*((unsigned char *)&d_021B4BE0 + 0x30), 9, (int)&d_021B4C0C, d_021B60D8.arg);
}
