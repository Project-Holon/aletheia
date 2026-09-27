/*
 * function: FSi_HasEnoughSpaceToCreateUserFile
 * address:  0x0208F370
 * packet:   pkt_0208F370
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT *
 * symbols:
 *   func_0208F398 0x0208F398 arm
 */

extern void func_0208F398(void);
asm void FSi_HasEnoughSpaceToCreateUserFile(void)
{
    ldr ip, =func_0208F398
    mov r3, #0
    bx ip
}
