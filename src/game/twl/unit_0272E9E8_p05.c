/*
 * file:     unit_0272E9E8_p05.c
 * unit:     yes
 * function: func_0272FD40, func_0272FD5C, func_0272FD7C, func_0272FDC0, func_0272FDDC, func_0272FE48, func_0272FE54, func_0272FEF4, func_0272FFC8
 * address:  0x0272FD40
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
 *   func_0272FC90 0x0272FC90 arm twl
 *   data_02732EFC 0x02732EFC data twl
 *   func_02082A90 0x02082A90 arm
 *   func_02087988 0x02087988 arm
 *   func_0208799C 0x0208799C arm
 */
#include "../../matched/include/G_twl_data_02732EFC.h"

struct Entry {
    int unk0;
    int unk4;
    int unk8;
    int unkC;
};

int func_0272FC90(int);
void func_02087988(void);
void func_0208799C(void);
void func_0272FD40(int a0);
void func_0272FD5C(unsigned int a0, unsigned int a1);
void func_0272FD7C(void);
asm void func_0272FDC0(int a0, const void *src);
asm void func_0272FDDC(int ch, const void *src, void *dst);
asm void func_0272FE48(void);
asm void func_0272FE54(void);
asm void func_0272FEF4(void);
asm void func_0272FFC8(void);
extern struct G_twl_data_02732EFC data_02732EFC[];


void func_0272FD40(int a0) {
    do {
    } while (func_0272FC90(a0) == 1);
}

void func_0272FD5C(unsigned int a0, unsigned int a1) {
    if (a0 == 0x80000000) {
        *(volatile unsigned int *)0x04004100 = a1 | 0x80000000;
    } else {
        *(volatile unsigned int *)0x04004100 = 0;
    }
}


void func_0272FD7C(void) {
    register struct Entry *e = ((struct Entry *)data_02732EFC);
    register int i = 0;
    do {
        e->unk0 = 1;
        e->unk4 = 0;
        e->unk8 = 0x40000;
        i++;
        e->unkC = -1;
        e++;
    } while (i <= 3);
}

asm void func_0272FDC0(int a0, const void *src)
{
    ldr r3, [pc, #0xc]
    ldr ip, [pc, #0xc]
    mov r2, #0x10
    add r0, r3, r0, lsl #4
    bx ip
    dcd 0x02732EFC
    dcd 0x02082A90
}


asm void func_0272FDDC(int ch, const void *src, void *dst)
{
    stmdb   sp!, {r3, r4, r5, r6, r7, lr}
    mov     r7, r0
    mov     r6, r1
    mov     r5, r2
    bl      func_02087988
    mov     r4, r0
    mov     r0, r7
    bl      func_0272FD40
    mov     r0, #0x1c
    mul     r0, r7, r0
    add     r0, r0, #0x4000000
    add     r1, r0, #0x4000
    str     r6, [r1, #0x104]
    ldr     r0, [pc, #0x2c]
    str     r5, [r1, #0x108]
    mov     r2, #1
    str     r2, [r1, #0x10c]
    str     r2, [r1, #0x110]
    add     r0, r0, r7, lsl #4
    ldr     r2, [r0, #8]
    mov     r0, r4
    orr     r2, r2, #0x4000
    orr     r2, r2, #0xa4000000
    str     r2, [r1, #0x11c]
    bl      func_0208799C
    ldmia   sp!, {r3, r4, r5, r6, r7, pc}
    DCD     data_02732EFC
}

asm void func_0272FE48(void)
{
    ldr     r12, [pc, #0]
    bx      r12
    dcd     0x0272FDDC
}

asm void func_0272FE54(void)
{
}

asm void func_0272FEF4(void)
{
}

asm void func_0272FFC8(void)
{
}
