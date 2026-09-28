/*
 * function: func_02059270
 * address:  0x02059270
 * packet:   pkt_02059270
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   pending
 *
 * SDK symbol: DWCi_SetExpIsBuddyFriendFlag (libdwcaccount.TWL.HYB.a(dwc_account.o))
 * DWARF dwc_account.c:524-530, formals frienddata/setflag, local tempflags.
 */

extern unsigned long DWCi_Acc_GetFlags(void *frienddata);
extern void DWCi_Acc_SetFlags(void *frienddata, unsigned long flags);

void func_02059270(void *frienddata, int setflag)
{
    unsigned long tempflags;

    if (setflag)
        tempflags = DWCi_Acc_GetFlags(frienddata) | 16;
    else
        tempflags = DWCi_Acc_GetFlags(frienddata) & ~16;
    DWCi_Acc_SetFlags(frienddata, tempflags);
}
