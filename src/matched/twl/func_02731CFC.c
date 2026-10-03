/*
 * function: func_02731CFC
 * address:  0x02731CFC
 * packet:   twl_sys
 * region:   twl
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_021657C8  0x021657C8  arm  ov009
 *   func_02703854  0x02703854  arm  twl
 *   func_02165A4C  0x02165A4C  arm  ov009
 *   func_02732A64  0x02732A64  arm  twl
 */

typedef unsigned int u32;

extern int func_021657C8(void);
extern u32 func_02703854(u32 a0, u32 a1);
extern void func_02165A4C(unsigned char phase);
extern void func_02732A64(void);

asm u32 func_02731CFC(void)
{
    stmdb   sp!, {r4, lr}
    bl      func_021657C8
    mov     r4, r0
    ldr     r0, =func_02732A64
    mov     r1, #0
    bl      func_02703854
    cmp     r0, #2
    beq     @loc_02731D30
    cmp     r0, #3
    beq     @loc_02731D50
    cmp     r0, #6
    beq     @loc_02731D48
    b       @loc_02731D50

@loc_02731D30:
    mov     r0, #0xa
    bl      func_02165A4C
    add     r0, r4, #0x1200
    mov     r1, #6
    strh    r1, [r0, #0xda]
    b       @loc_02731D60

@loc_02731D48:
    mov     r0, #4
    ldmfd   sp!, {r4, pc}

@loc_02731D50:
    mov     r0, #0xb
    bl      func_02165A4C
    mov     r0, #7
    ldmfd   sp!, {r4, pc}

@loc_02731D60:
    mov     r0, #3
    ldmfd   sp!, {r4, pc}
}
