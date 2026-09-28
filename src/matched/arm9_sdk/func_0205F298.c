/*
 * function: func_0205F298
 * address:  0x0205F298
 * packet:   pkt_0205DC74
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      ConnectTestCreate (test.o)
 *
 * symbols:
 *   DWCi_AC_GetMemPtr                0x0205c214 arm
 *   DWC_Netcheck_Create              0x0217a880 arm
 *   DWCi_AC_SetError                 0x0205c2e4 arm
 */

typedef struct DWCNetcheckParam DWCNetcheckParam;

extern void *func_0205C214(unsigned long name);
extern int DWC_Netcheck_Create(DWCNetcheckParam *param);
extern void func_0205C2E4(int error);

static unsigned char func_0205F298(void)
{
    DWCNetcheckParam *nc = (DWCNetcheckParam *)func_0205C214(8);

    if (DWC_Netcheck_Create(nc) == 0) {
        return 0xE;
    }
    func_0205C2E4(3);
    return 0x11;
}
