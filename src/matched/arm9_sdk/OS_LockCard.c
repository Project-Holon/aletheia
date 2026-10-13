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
 *   func_02084D68 0x02084D68 arm
 *   func_02084E54 0x02084E54 arm
 */
typedef signed int     s32;
typedef unsigned short u16;
struct OSLockWord;
extern s32 func_02084D68(u16 lockID, struct OSLockWord *lockp, void (*ctrlFuncp)(void));
extern void func_02084E54(void);

s32 OS_TryLockCard(u16 lockID)
{
    return func_02084D68(lockID, (struct OSLockWord *)0x02FFFFE0, func_02084E54);
}
