/*
 * file:     unit_02066B84_p01.c
 * unit:     yes
 * function: CARD_SetPulledOutCallback, func_02066DFC, func_02066E10, func_02066E20
 * address:  0x02066DEC
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   g_02148B2C 0x02148B2C data
 *   g_020A8218 0x020A8218 data
 */
extern void g_02148B2C(void);
extern void g_020A8218(void);
asm void CARD_SetPulledOutCallback(void);
asm void CTRDGi_CallbackForSetPhi(void);
asm void func_02066E10(void);
int func_02066E20(void);

asm void CARD_SetPulledOutCallback(void)
{
    ldr r1, =g_02148B2C
    str r0, [r1, #8]
    bx lr
}



asm void CTRDGi_CallbackForSetPhi(void)
{
    ldr r0, =g_02148B2C
    mov	r1, #0
    str	r1, [r0, #4]
    bx	lr
}


asm void func_02066E10(void)
{
    ldr r1, =g_020A8218
    str r0, [r1]
    bx lr
}


int func_02066E20(void){ return *(int *)(0x20A8218); }
