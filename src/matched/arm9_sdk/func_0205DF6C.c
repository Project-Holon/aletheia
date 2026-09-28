/*
 * function: func_0205DF6C
 * address:  0x0205DF6C
 * packet:   pkt_0205DC74
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * SDK symbol: DWCi_AC_SetStealthChannel (search.o, libdwcac.TWL.HYB.a)
 *
 * symbols:
 *   DWCi_AC_GetMemPtr   0x0205C214  arm
 */

struct tagACWORK {
    char pad[0x14C6];
    unsigned short f14C6;
    char pad2[6];
    unsigned short f14CE;
};

extern void *DWCi_AC_GetMemPtr(unsigned long name);

void func_0205DF6C(unsigned short channel)
{
    struct tagACWORK *wk = DWCi_AC_GetMemPtr(0x10);

    if (channel > wk->f14CE)
        channel = wk->f14CE;
    wk->f14C6 = wk->f14C6 | (1 << (channel - 1));
}
