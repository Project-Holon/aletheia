/*
 * function: DWC_AC_GetSecuritySetting
 * address:  0x0205BE58
 * packet:   pkt_02040000
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * TwlDWC libdwcac dwc_ac.o.
 */
extern void *DWCi_AC_GetMemPtr(unsigned long name);

unsigned int DWC_AC_GetSecuritySetting(void)
{
    unsigned char *hd = (unsigned char *)DWCi_AC_GetMemPtr(1);
    return hd[35];
}
