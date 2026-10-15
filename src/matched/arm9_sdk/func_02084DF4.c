/*
 * function: OS_LockCard
 * address:  0x02084DF4
 * packet:   pkt_02084DF4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * note:     os_spinLock.o OS_LockCard; HW_CARD_LOCK_BUF = 0x02FFFFE0.
 *
 * symbols:
 *   OS_LockByWord        0x02084C68  arm
 *   OSi_AllocateCardBus  0x02084E54  arm
 */

int OS_LockByWord(unsigned short lockID, void *lockBuf, void (*ctrlFuncp)(void));
void OSi_AllocateCardBus(void);

int OS_LockCard(unsigned short lockID)
{
    return OS_LockByWord(lockID, (void *)0x02FFFFE0, OSi_AllocateCardBus);
}
