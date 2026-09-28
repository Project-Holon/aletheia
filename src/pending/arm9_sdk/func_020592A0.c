/*
 * function: func_020592A0
 * address:  0x020592A0
 * packet:   pkt_020592A0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   pending
 *
 * SDK symbol: DWCi_SetSentBuddyReqFlag (libdwcaccount.TWL.HYB.a(dwc_account.o))
 * DWARF dwc_account.c:555-561, formals frienddata/setflag, local tempflags.
 */

extern unsigned long DWCi_Acc_GetFlags(void *frienddata);
extern void DWCi_Acc_SetFlags(void *frienddata, unsigned long flags);

void func_020592A0(void *frienddata, int setflag)
{
    unsigned long tempflags;

    if (setflag)
        tempflags = DWCi_Acc_GetFlags(frienddata) | 32;
    else
        tempflags = DWCi_Acc_GetFlags(frienddata) & ~32;
    DWCi_Acc_SetFlags(frienddata, tempflags);
}
