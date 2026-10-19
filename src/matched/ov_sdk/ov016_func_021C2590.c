/*
 * function: initGraphics
 * address:  0x021C2590
 * packet:   pkt_021C2590
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * symbols:
 *   DWCi_CMNlLoadResource  0x021BD1D4  arm
 */

typedef unsigned short u16;

typedef struct {
    u16 priority : 2;
    u16 rest : 14;
} BgCnt;

void DWCi_CMNlLoadResource(char *file, void (*func)(void *, unsigned long, unsigned long));

void initGraphics(void)
{
    DWCi_CMNlLoadResource((void *)0x021DB2DC, (void *)0x0207EB78);
    ((BgCnt *)0x04001008)->priority = 3;
    ((BgCnt *)0x0400100A)->priority = 3;
    ((BgCnt *)0x04000008)->priority = 3;
    ((BgCnt *)0x0400000A)->priority = 3;
    ((BgCnt *)0x0400000C)->priority = 3;
}
