/*
 * function: func_01FF8460
 * address:  0x01FF8460
 * packet:   pkt_01FF8460
 * region:   arm9_autoload0_ITCM
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * symbols:
 *   func_01FF852C    0x01FF852C  arm
 */

typedef unsigned int u32;

#define HW_REG_BASE                  0x04000000
#define REG_IME_OFFSET               0x208

#define OSi_HW_DTCM                  0x02FE0000
#define HW_DTCM_SYSRV_OFS_INTR_VECTOR 0x3c

#define REG_SUBPINTF_ADDR             0x04000180

#define HW_EXCP_VECTOR_MAIN           0x02FFFD9C
#define HW_BIOS_EXCP_STACK_MAIN       0x02FFFD80
#define HW_PXI_SIGNAL_PARAM_ARM9      0x02FFFF80
#define HW_WM_RSSI_POOL               0x02FFFF98
#define HW_COMPONENT_PARAM            0x02FFFF9C
#define HW_ROM_HEADER_BUF             0x02FFFE00

extern void func_01FF852C(u32 data, void *destp, u32 size);

asm void func_01FF8460(void)
{
    mov     r12, #HW_REG_BASE
    str     r12, [r12, #REG_IME_OFFSET]

    ldr     r1, =OSi_HW_DTCM
    add     r1, r1, #0x3fc0
    add     r1, r1, #HW_DTCM_SYSRV_OFS_INTR_VECTOR
    mov     r0, #0
    str     r0, [r1]

    ldr     r1, =REG_SUBPINTF_ADDR
@1:
    ldrh    r0, [r1]
    and     r0, r0, #0x000f
    cmp     r0, #0x0001
    bne     @1
    mov     r0, #0x0100
    strh    r0, [r1]

    mov     r0, #0
    ldr     r3, =HW_EXCP_VECTOR_MAIN
    ldr     r4, [r3]

    ldr     r1, =HW_BIOS_EXCP_STACK_MAIN
    mov     r2, #0x80
    bl      func_01FF852C

    str     r4, [r3]

    ldr     r1, =HW_PXI_SIGNAL_PARAM_ARM9
    mov     r2, #0x18
    bl      func_01FF852C

    ldr     r1, =HW_WM_RSSI_POOL
    strh    r0, [r1]

    ldr     r1, =HW_COMPONENT_PARAM
    mov     r2, #0x64
    bl      func_01FF852C

    ldr     r1, =REG_SUBPINTF_ADDR
@2:
    ldrh    r0, [r1]
    and     r0, r0, #0x000f
    cmp     r0, #0x0001
    beq     @2
    mov     r0, #0
    strh    r0, [r1]

    ldr     r3, =HW_ROM_HEADER_BUF
    ldr     r12, [r3, #0x24]
    mov     lr, r12

    ldr     r11, =HW_PXI_SIGNAL_PARAM_ARM9
    ldmia   r11, {r0-r10}
    mov     r11, #0

    bx      r12
}
