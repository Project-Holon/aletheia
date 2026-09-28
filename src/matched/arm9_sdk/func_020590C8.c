/*
 * function: DWCi_Acc_SetUserId
 * address:  0x020590C8
 * packet:   pkt_02040000
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * TwlDWC libdwcaccount dwc_account.o.
 * The two 32-bit halves arrive as separate arguments (high first), not as one u64.
 */
extern int DWCi_Acc_SetMaskBits(unsigned long *ptr, unsigned long data, unsigned long shift, unsigned long mask);

typedef struct { unsigned long id; unsigned long low; } DWCstAccLoginId;

void DWCi_Acc_SetUserId(DWCstAccLoginId *userdata, unsigned long high, unsigned long low)
{
    DWCi_Acc_SetMaskBits((unsigned long *)userdata, low, 0, 0x7ff);
    userdata->low = high;
}
