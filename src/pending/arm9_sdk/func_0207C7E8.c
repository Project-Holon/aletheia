/*
 * function: func_0207C7E8
 * address:  0x0207C7E8
 * packet:   pkt_0207C7E8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   CCERR
 *
 * symbols:
 *   FX_InvAsync            0x0207C8A0  arm
 *   FX_SqrtAsync           0x0207C8D0  arm
 *   FX_GetDivResultFx64c   0x0207C848  arm
 *
 * TwlSDK libfx fx_cp.o. Hand-written assembly (DWARF has no locals).
 * 1/sqrt(x) via the divider and square-root unit running together; 0 for
 * non-positive x.
 */

extern void FX_InvAsync(long denom);
extern void FX_SqrtAsync(long x);
extern long long FX_GetDivResultFx64c(long denom);

asm void func_0207C7E8(void)
{
    stmfd sp!, {r4, lr}
    mov   r4, r0
    cmp   r4, #0
    ble   L_zero

    bl    FX_InvAsync
    mov   r0, r4
    bl    FX_SqrtAsync
    bl    FX_GetDivResultFx64c

    ldr   r3, =0x040002B0
L_wait:
    ldrh  r2, [r3]
    tst   r2, #0x8000
    bne   L_wait

    ldr   r2, =0x040002B4
    ldr   r2, [r2]
    umull r12, r3, r0, r2
    mla   r3, r1, r2, r3
    adds  r0, r12, #0
    adc   r0, r3, #512
    asr   r0, r0, #10

    ldmfd sp!, {r4, pc}

L_zero:
    mov   r0, #0
    ldmfd sp!, {r4, pc}
}
