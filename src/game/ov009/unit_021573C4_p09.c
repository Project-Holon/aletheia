/*
 * file:     unit_021573C4_p09.c
 * unit:     yes
 * function: func_02157F60
 * address:  0x02157F60
 * packet:   pkt_ov009_02157F60
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      arprequest (libcps.TWL.HYB.a(network.o))
 *
 * symbols:
 *   func_02157E54  0x02157E54  arm  ov009
 *   func_02085A38  0x02085A38  arm
 *   func_02157D8C  0x02157D8C  arm  ov009
 *   g_021A1CA8  0x021A1CA8  data
 *   g_021A826C  0x021A826C  data
 */

extern unsigned long g_021A1CA8[];
extern char g_021A826C[];
extern void func_02157E54(unsigned long ip);
extern void func_02085A38(unsigned long msec);
extern unsigned char *func_02157D8C(unsigned long ip);

unsigned long func_02157F60(unsigned long ip)
{
    unsigned long retry1;
    unsigned long retry2;
    unsigned long r;

    for (retry1 = 0; retry1 < 6; retry1++) {
        func_02157E54(ip);
        for (retry2 = 0; retry2 < g_021A1CA8[retry1] / 100; retry2++) {
            if (*(unsigned long *)(g_021A826C + 0x50) == 0)
                return 0;
            func_02085A38(100);
            r = (long unsigned int)func_02157D8C(ip);
            if (r != 0)
                return r;
        }
    }
    return 0;
}
