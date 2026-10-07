/*
 * function: func_02702070
 * address:  0x02702070
 * packet:   twl_sys
 * region:   twl
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_02700DB8  0x02700DB8  arm twl
 */

typedef unsigned int   u32;
extern u32 func_02700DB8(u32 a0);

asm void func_02702070(void) {
    ldr ip, =func_02700DB8
    mov r0, #0
    bx ip
}
