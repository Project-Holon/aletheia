/*
 * function: OS_TryLockCard
 * address:  0x02084E38
 * packet:   pkt_02084E38
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   OS_TryLockByWord 0x02084D68 arm
 *   OSi_AllocateCardBus 0x02084E54 arm
 */
typedef signed int     s32;
typedef unsigned short u16;
struct OSLockWord;
extern s32 OS_TryLockByWord(u16 lockID, struct OSLockWord *lockp, void (*ctrlFuncp)(void));
extern void OSi_AllocateCardBus(void);

s32 OS_TryLockCard(u16 lockID)
{
    return OS_TryLockByWord(lockID, (struct OSLockWord *)0x02FFFFE0, OSi_AllocateCardBus);
}
