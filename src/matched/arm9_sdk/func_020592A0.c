/*
 * function: func_020592A0
 * address:  0x020592A0
 * packet:   pkt_020592A0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_SetSentBuddyReqFlag (libdwcaccount.TWL.HYB.a(dwc_account.o))
 *
 * symbols:
 *   DWCi_Acc_GetFlags                0x02059108 arm
 *   DWCi_Acc_SetFlags                0x020591d8 arm
 */

extern unsigned long DWCi_Acc_GetFlags(void *userdata);
extern void DWCi_Acc_SetFlags(void *userdata, unsigned long flags);

void func_020592A0(void *frienddata, int setflag)
{
    unsigned long tempflags;

    if (setflag) {
        tempflags = DWCi_Acc_GetFlags(frienddata) | 0x20;
    } else {
        tempflags = DWCi_Acc_GetFlags(frienddata) & ~0x20;
    }
    DWCi_Acc_SetFlags(frienddata, tempflags);
}
