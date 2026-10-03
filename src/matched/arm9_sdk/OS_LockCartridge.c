/*
 * function: OS_LockCartridge
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
 *   func_02084CFC 0x02084CFC arm
 *   func_02084DC4 0x02084DC4 arm
 */

typedef signed int     s32;
typedef unsigned short u16;
struct OSLockWord;
extern s32 func_02084CFC(u16 lockID, struct OSLockWord *lockp, void (*ctrlFuncp)(void), int disableFIQ);
extern void func_02084DC4(void);

asm void OS_LockCartridge(void)
{
    ldr r1, =0x02FFFFE8
    ldr r2, =func_02084DC4
    ldr ip, =func_02084CFC
    mov	r3, #1
    bx	ip
}
