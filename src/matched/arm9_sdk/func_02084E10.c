/*
 * function: OS_UnlockCard
 * address:  0x02084E10
 * packet:   pkt_02084E10
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   OS_UnlockByWord 0x02084CEC arm
 *   OSi_FreeCardBus 0x02084E98 arm
 */
typedef signed int     s32;
typedef unsigned short u16;
struct OSLockWord;
extern s32 OS_UnlockByWord(u16 lockID, struct OSLockWord *lockp, void (*ctrlFuncp)(void));
extern void OSi_FreeCardBus(void);

s32 OS_UnlockCard(u16 lockID)
{
    return OS_UnlockByWord(lockID, (struct OSLockWord *)0x02FFFFE0, OSi_FreeCardBus);
}
