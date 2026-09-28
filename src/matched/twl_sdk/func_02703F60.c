/*
 * function: func_02703F60
 * address:  0x02703F60
 * packet:   twl
 * region:   twl
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_02085DBC  0x02085DBC  arm
 */

extern void func_02085DBC(void);

asm void func_02703F60(void) {
    mov r2, r0
    mov r0, r1
    mov r1, r2
    ldr ip, =func_02085DBC
    mov r2, #0
    bx ip
}
