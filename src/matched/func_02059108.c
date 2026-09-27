/*
 * function: DWCi_Acc_GetFlags
 * address:  0x02059108
 * packet:   pkt_02040000
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * TwlDWC libdwcaccount dwc_account.o.
 * 21-bit field at bit 11.
 */
typedef struct {
    unsigned int raw;
} DWCstAccFlag;

unsigned long DWCi_Acc_GetFlags(DWCstAccFlag *userdata)
{
    return (userdata->raw >> 11) & 0x1fffff;
}
