/*
 * function: func_0205F35C
 * address:  0x0205F35C
 * packet:   pkt_0205DC74
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * SDK symbol: ConnectTestEnd (test.o, libdwcac.TWL.HYB.a)
 *
 * symbols:
 *   DWCi_AC_SetApType      0x0205C31C  arm
 *   DWCi_AC_CopyExSetting  0x0205C3B0  arm
 */

struct tagACWORK {
    char pad[0x14BD];
    unsigned char f;
};

extern void DWCi_AC_SetApType(unsigned char type);
extern void DWCi_AC_CopyExSetting(unsigned char type);

unsigned char func_0205F35C(struct tagACWORK *wk)
{
    DWCi_AC_SetApType(wk->f);
    DWCi_AC_CopyExSetting(wk->f);
    return 0x10;
}
