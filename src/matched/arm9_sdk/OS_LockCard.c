/*
 * function: OS_LockCard
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

struct _FSFreeAreaSize;
extern int func_02084D68(struct _FSFreeAreaSize *freesize, char *path, unsigned long size);
extern void func_02084E54(void);

asm void OS_LockCard(void)
{
    ldr r1, =0x02FFFFE0
    ldr r2, =func_02084E54
    ldr ip, =func_02084D68
    bx	ip
}
