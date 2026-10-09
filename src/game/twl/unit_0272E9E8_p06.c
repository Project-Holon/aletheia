/*
 * file:     unit_0272E9E8_p06.c
 * unit:     yes
 * function: func_0272FB10, func_0272FB28, func_0272FB78, func_0272FBD0, func_0272FC2C, func_0272FC90, func_0272FCB0, func_0272FCE0, func_0272FD18
 * address:  0x0272FB10
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
 *   func_0272FD5C 0x0272FD5C arm twl
 *   func_0272FD7C 0x0272FD7C arm twl
 *   data_02732EFC 0x02732EFC data twl
 *   func_0272F8A8 0x0272F8A8 arm twl
 *   func_0272F9C4 0x0272F9C4 arm twl
 *   func_02087988 0x02087988 arm
 *   func_0208799C 0x0208799C arm
 */
#include "../../matched/include/G_twl_data_02732EFC.h"

void func_0272FD5C(unsigned int, unsigned int);
void func_0272FD7C(void);
void func_0272F8A8(int a0, int a1, int a2, int a3, int a4, int a5, void *a6, int a7, unsigned int a8);
void func_0272F9C4(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, void *a8, int a9, unsigned int a10);
int func_02087988(void);
void func_0208799C(int);
void func_0272FB10(void);
void func_0272FB28(int a0, int a1, int a2, int a3);
void func_0272FB78(int a0, int a1, int a2, int a3);
void func_0272FBD0(int a0, int a1, int a2, int a3, int a4, int a5);
void func_0272FC2C(int a0, int a1, int a2, int a3, int a4, int a5);
asm unsigned int func_0272FC90(int ch);
void func_0272FCB0(int ch);
void func_0272FCE0(int ch);
void func_0272FD18(void);
extern struct G_twl_data_02732EFC data_02732EFC;


void func_0272FB10(void) {
    func_0272FD5C(0x80000000, 0x60000);
    func_0272FD7C();
}



void func_0272FB28(int a0, int a1, int a2, int a3)
{
    func_0272F8A8(0, a0, 0, a1, a2, a3, (void *)(((char *)&data_02732EFC) + (a0 << 4)), -1, 0x80000000);
}



void func_0272FB78(int a0, int a1, int a2, int a3)
{
    func_0272F8A8(1, a0, a1, a2, 0, a3, (void *)(((char *)&data_02732EFC) + (a0 << 4)), -1, 0x80000000);
}



void func_0272FBD0(int a0, int a1, int a2, int a3, int a4, int a5)
{
    func_0272F9C4(0, a0, 0, a1, a2, a3, a4, a5, (void *)(((char *)&data_02732EFC) + (a0 << 4)), -1, 0x80000000);
}



void func_0272FC2C(int a0, int a1, int a2, int a3, int a4, int a5)
{
    func_0272F9C4(1, a0, a1, a2, 0, a3, a4, a5, (void *)(((char *)&data_02732EFC) + (a0 << 4)), -1, 0x80000000);
}


asm unsigned int func_0272FC90(int ch)
{
    mov r1, #0x1c
    mul r1, r0, r1
    add r0, r1, #0x4000000
    add r0, r0, #0x4000
    ldr r0, [r0, #0x11c]
    and r0, r0, #0x80000000
    mov r0, r0, lsr #0x1f
    bx lr
}



void func_0272FCB0(int ch)
{
    int irq = func_02087988();
    volatile unsigned int *reg = (volatile unsigned int *)(0x0400411C + ch * 0x1C);
    while (*reg & 0x80000000) {
    }
    func_0208799C(irq);
}



void func_0272FCE0(int ch)
{
    int irq = func_02087988();
    volatile unsigned int *reg = (volatile unsigned int *)(0x04004000 + 0x11C + ch * 0x1C);
    *reg &= ~0x80000000;
    (void)*reg;
    (void)*reg;
    func_0208799C(irq);
}



void func_0272FD18(void) {
    func_0272FCE0(0);
    func_0272FCE0(1);
    func_0272FCE0(2);
    func_0272FCE0(3);
}
