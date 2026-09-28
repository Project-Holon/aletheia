/*
 * function: func_0205C018
 * address:  0x0205C018
 * packet:   pkt_0205C018
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_AC_InvalidatePriorityWPA (dwc_ac.o)
 *
 * symbols:
 *   DWCi_AC_GetMemPtr                0x0205c214 arm
 */

typedef struct tagACWORK {
    unsigned char before[0x14BC];
    unsigned char connectType : 4;
    unsigned char skipNetCheck : 1;
    unsigned char useDSWireless : 1;
    unsigned char duplicateFlag : 1;
    unsigned char wpaSetting : 1;
} tagACWORK;

extern void *func_0205C214(unsigned long name);

void func_0205C018(void)
{
    tagACWORK *wk = (tagACWORK *)func_0205C214(0x10);

    wk->wpaSetting = 0;
}
