/*
 * function: FS_CloseFile
 * address:  0x02078A80
 * packet:   pkt_02078A80
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_02077D80 0x02077D80 arm
 */

extern void func_02077D80(void);

asm void FS_CloseFile(void)
{
    ldr ip, =func_02077D80
    mov	r1, #8
    mov	r2, #1
    bx	ip
}
