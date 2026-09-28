/*
 * function: func_02059240
 * address:  0x02059240
 * packet:   pkt_02059240
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   pending
 *
 * SDK symbol: DWCi_SetReverseBuddyFlag (libdwcaccount.TWL.HYB.a(dwc_account.o))
 * DWARF dwc_account.c:494-499, formals frienddata/setflag, local tempflags.
 */

extern unsigned long DWCi_Acc_GetFlags(void *frienddata);
extern void DWCi_Acc_SetFlags(void *frienddata, unsigned long flags);

void func_02059240(void *frienddata, int setflag)
{
    unsigned long tempflags;

    if (setflag)
        tempflags = DWCi_Acc_GetFlags(frienddata) | 8;
    else
        tempflags = DWCi_Acc_GetFlags(frienddata) & ~8;
    DWCi_Acc_SetFlags(frienddata, tempflags);
}
