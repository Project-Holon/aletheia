/*
 * function: func_02037B08
 * address:  0x02037B08
 * packet:   pkt_02037A6C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_0203D788   0x0203D788  arm
 *   func_0203D798   0x0203D798  arm
 *   func_020307B0   0x020307B0  arm
 *   func_02036B88   0x02036B88  arm
 *   g_021469D0      0x021469D0  data
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02037B08.c \
 *       --func func_02037B08 --addr 0x02037B08 --cc 1.1p1 --arm
 */

#include "../include/G_LinkState.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void *func_0203D788(void);
extern void *func_0203D798(void);
extern u32 func_020307B0(void *p);
extern void  func_02036B88(void *p);

extern struct LinkState *g_021469D0;

void func_02037B08(void)
{
    func_0203D788();
    func_0203D798();

    if (g_021469D0 == 0) {
        return;
    }

    func_020307B0(g_021469D0->f14);
    func_020307B0(g_021469D0->f18);
    func_020307B0(g_021469D0->f10);

    func_02036B88(&g_021469D0->obj_F4);
    func_02036B88(&g_021469D0->obj_CC);

    func_020307B0(g_021469D0->f0);
    func_020307B0(g_021469D0->f04);
    func_020307B0(g_021469D0->f08);
    func_020307B0(g_021469D0->f0C);

    func_020307B0(g_021469D0);

    g_021469D0 = 0;
}
