/*
 * file:     unit_02701940_p02.c
 * unit:     yes
 * function: func_02701FE8, func_02702028
 * address:  0x02701FE8
 * region:   twl
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   data_02732FC8  0x02732FC8  data twl a2
 *   data_04000208  0x04000208  data twl a2
 *   func_020879E0  0x020879E0  code twl a2
 *   func_02088688  0x02088688  code twl a2
 */
typedef unsigned int u32;

typedef unsigned short u16;

extern u32 func_020879E0(void);
extern void func_02088688(void);
asm void func_02701FE8(void);
void func_02702028(void);
extern u32 data_02732FC8[];
extern u16 data_04000208;


asm void func_02701FE8(void) {
    stmdb sp!, {r3, lr}
    ldr r1, =data_02732FC8
    ldr r2, [r1]
    cmp r2, #0
    movne r2, #0
    strne r2, [r1]
    ldr r1, =data_02732FC8
    ldr r3, [r1, #4]
    cmp r3, #0
    ldmeqfd sp!, {r3, pc}
    mov r2, #0
    str r2, [r1, #4]
    ldr r1, [r1, #0xC]
    blx r3
    ldmfd sp!, {r3, pc}
}


void func_02702028(void) {
    if (data_02732FC8[0] == 0) {
        return;
    }
    do {
        u32 mode = func_020879E0();
        if (mode == 0x80 || data_04000208 == 0) {
            func_02088688();
        }
    } while (data_02732FC8[0] != 0);
}
