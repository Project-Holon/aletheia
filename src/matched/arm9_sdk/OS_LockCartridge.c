/*
 * function: OS_TryLockCartridge
 * address:  0x02084DA4
 * packet:   pkt_02084DA4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   OSi_DoTryLockByWord 0x02084CFC arm
 *   OSi_AllocateCartridgeBus 0x02084DC4 arm
 */
typedef signed int     s32;
typedef unsigned short u16;
struct OSLockWord;
extern s32 OSi_DoTryLockByWord(u16 lockID, struct OSLockWord *lockp, void (*ctrlFuncp)(void), int disableFIQ);
extern void OSi_AllocateCartridgeBus(void);

s32 OS_TryLockCartridge(u16 lockID)
{
    return OSi_DoTryLockByWord(lockID, (struct OSLockWord *)0x02FFFFE8, OSi_AllocateCartridgeBus, 1);
}
