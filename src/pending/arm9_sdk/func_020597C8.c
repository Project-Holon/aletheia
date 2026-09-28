/*
 * function: func_020597C8
 * address:  0x020597C8
 * packet:   pkt_020597C8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   pending
 *
 * SDK symbol: DWC_CheckHasProfile (libdwcaccount.TWL.HYB.a(dwc_account.o))
 * DWARF dwc_account.c:1136, formal userdata, no locals.
 */

extern int func_020596B0(void *);
extern int func_020590AC(void *);

int func_020597C8(void *userdata)
{
    return func_020596B0((char *)userdata + 0x10) != 0 &&
           *(int *)((char *)userdata + 0x1c) > 0;
}
