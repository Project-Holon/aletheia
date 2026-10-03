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

struct _FSFreeAreaSize;
extern int func_02084CEC(struct _FSFreeAreaSize *freesize, char *path, unsigned long size);
extern void func_02084E98(void);

asm void func_02084E10(void)
{
    ldr r1, =0x02FFFFE0
    ldr r2, =func_02084E98
    ldr ip, =func_02084CEC
    bx	ip
}
