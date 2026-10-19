/*
 * function: ConnectTestEnd
 * address:  0x0205F35C
 * packet:   pkt_0205DC74
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      ConnectTestEnd (test.o)
 *
 * symbols:
 *   DWCi_AC_SetApType                0x0205c31c arm
 *   DWCi_AC_CopyExSetting            0x0205c3b0 arm
 */

typedef struct tagACWORK {
    unsigned char before[0x14BD];
    unsigned char connectApType;
} tagACWORK;

extern void DWCi_AC_SetApType(unsigned char type);
extern void DWCi_AC_CopyExSetting(unsigned char type);

static unsigned char ConnectTestEnd(tagACWORK *wk)
{
    DWCi_AC_SetApType(wk->connectApType);
    DWCi_AC_CopyExSetting(wk->connectApType);
    return 0x10;
}
