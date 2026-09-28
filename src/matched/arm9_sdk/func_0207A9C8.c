/*
 * function: func_0207A9C8
 * address:  0x0207A9C8
 * packet:   pkt_0207A9C8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * SDK symbol: FSi_OnRomReadDone (TwlSDK libfs.TWL.HYB.a fs_proc_rom.o)
 *
 * symbols:
 *   CARD_IsPulledOut           0x020774B0  arm
 *   FS_NotifyArchiveAsyncEnd   0x02078734  arm
 */

typedef int BOOL;

extern BOOL CARD_IsPulledOut(void);
extern void FS_NotifyArchiveAsyncEnd(void *arc, int ret);

void func_0207A9C8(void *arg)
{
    FS_NotifyArchiveAsyncEnd(arg, CARD_IsPulledOut() ? 5 : 0);
}
