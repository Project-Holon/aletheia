/*
 * file:     unit_02073EE4.c
 * function: func_02073EE4
 * address:  0x02073EE4
 * packet:   pkt_02073BF0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * symbols:
 *   g_0214E9FC  0x0214E9FC  data
 */

typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;


struct G { u32 f0; u8 p4[0x24 - 4]; u32 f24; u32 f28; u32 f2c; };
extern struct G g_0214E9FC;
extern void func_020894DC(u32, u32, u32, u32);
extern u32 func_02089D40(void);
extern void func_02089B38(u32);
extern void func_02089CD4(u32);
void func_02073EE4(void) {
    struct G *g = &g_0214E9FC;
    u32 m;
    u32 r;
    if (g->f0 == 0) return;
    if ((int)g->f2c >= 0) m = 1u << g->f2c;
    else m = 0;
    func_020894DC(g->f24, g->f28, m, 0);
    r = func_02089D40();
    func_02089B38(1);
    func_02089CD4(r);
}
