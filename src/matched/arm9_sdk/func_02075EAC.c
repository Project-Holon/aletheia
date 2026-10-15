/*
 * function: CARD_UnlockBackup
 * address:  0x02075EAC
 * packet:   pkt_02075EAC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      CARD_UnlockBackup (libcard.TWL.HYB.a card_api.o)
 *
 * symbols:
 *   CARD_TryWaitBackupAsync  0x02076B8C  arm
 *   CARD_WaitBackupAsync  0x02076B80  arm
 *   CARDi_UnlockResource  0x02075F4C  arm
 */

typedef unsigned short u16;
typedef long s32;
typedef int BOOL;

extern BOOL CARD_TryWaitBackupAsync(void);
extern BOOL CARD_WaitBackupAsync(void);
extern void CARDi_UnlockResource(s32 owner, int target);

void CARD_UnlockBackup(u16 lock_id)
{
    if (!CARD_TryWaitBackupAsync())
    {
        (void)CARD_WaitBackupAsync();
    }
    CARDi_UnlockResource(lock_id, 2);
}
