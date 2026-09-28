/*
 * function: func_021C3194
 * address:  0x021C3194
 * packet:   pkt_021C3194
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * symbols:
 *   func_021BD1D4  0x021BD1D4  arm
 */

typedef unsigned short u16;

typedef struct {
    u16 priority : 2;
    u16 rest : 14;
} BgCnt;

void func_021BD1D4(void *a, void *b);

void func_021C3194(void)
{
    func_021BD1D4((void *)0x021DB368, (void *)0x0207EB78);
    ((BgCnt *)0x04001008)->priority = 3;
    ((BgCnt *)0x0400100A)->priority = 3;
    ((BgCnt *)0x04000008)->priority = 3;
    ((BgCnt *)0x0400000A)->priority = 3;
    ((BgCnt *)0x0400000C)->priority = 3;
}
