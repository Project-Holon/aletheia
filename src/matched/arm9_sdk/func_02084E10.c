/*
 * function: func_02084E10
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
 *   func_02084CEC 0x02084CEC arm
 *   func_02084E98 0x02084E98 arm
 */
typedef signed int     s32;
typedef unsigned short u16;
struct OSLockWord;
extern s32 func_02084CEC(u16 lockID, struct OSLockWord *lockp, void (*ctrlFuncp)(void));
extern void func_02084E98(void);

s32 func_02084E10(u16 lockID)
{
    return func_02084CEC(lockID, (struct OSLockWord *)0x02FFFFE0, func_02084E98);
}
