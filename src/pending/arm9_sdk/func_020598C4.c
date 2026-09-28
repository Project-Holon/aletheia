/*
 * function: func_020598C4
 * address:  0x020598C4
 * packet:   pkt_020598C4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   pending
 *
 * SDK symbol: DWC_GetFriendKey (libdwcaccount.TWL.HYB.a(dwc_account.o))
 * DWARF dwc_account.c:1301, formal frienddata, no locals.
 */

extern int func_0205911C(void *);
extern unsigned long long func_020590AC(void *);

unsigned long long func_020598C4(void *frienddata)
{
    if (func_0205911C(frienddata) != 2)
        return 0;
    return func_020590AC(frienddata);
}
