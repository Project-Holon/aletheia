/*
 * function: DWCi_Acc_GetUserId
 * address:  0x02059084
 * packet:   pkt_02040000
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * TwlDWC libdwcaccount dwc_account.o.
 * Returns the 11-bit id as the high half and the raw word at +4 as the low half.
 */
typedef struct {
    unsigned int id;
    unsigned int low;
} DWCstAccLoginId;

unsigned long long DWCi_Acc_GetUserId(DWCstAccLoginId *userdata)
{
    return ((unsigned long long)(userdata->id & 0x7ff) << 32) | userdata->low;
}
