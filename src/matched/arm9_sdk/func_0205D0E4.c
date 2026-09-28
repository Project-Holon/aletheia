/*
 * function: func_0205D0E4
 * address:  0x0205D0E4
 * packet:   pkt_0205D0E4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_AC_Error (error.o)
 */

typedef unsigned char u8;

typedef struct {
    u8 pad[0xa];
    u8 phase;
} ACHOLD;

extern ACHOLD *DWCi_AC_GetMemPtr(int name);
extern int DWCi_AC_CloseNetwork(u8 *phase);

u8 func_0205D0E4(void)
{
    ACHOLD *hd = DWCi_AC_GetMemPtr(1);

    if (DWCi_AC_CloseNetwork(&hd->phase) == 1) {
        return 0x12;
    }
    return 0x11;
}
