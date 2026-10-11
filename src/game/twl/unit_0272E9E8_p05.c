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
 *   data_02732F3C 0x02732F3C data twl
 *   func_02730090 0x02730090 arm twl
 *   func_0272F9C4 0x0272F9C4 arm twl
 *   func_0272FCB0 0x0272FCB0 arm twl
 *   func_02084998 0x02084998 arm
 *   func_020849C8 0x020849C8 arm
 *   func_02084818 0x02084818 arm
 *   func_02084774 0x02084774 arm
 *   func_02084968 0x02084968 arm
 */
#include "../../matched/include/G_twl_data_02732EFC.h"

struct Entry {
    int unk0;
    int unk4;
    int unk8;
    int unkC;
};

int func_0272FC90(int);
unsigned int func_02087988(void);
void func_0208799C(unsigned int);
void func_0272FCB0(int);
void func_0272F9C4(int mode, int ch, unsigned int src, unsigned int dst, unsigned int fill, unsigned int size, void (*cb)(), unsigned int arg, void *cfg, int words, unsigned int flags);
void func_02730090(void);
void func_02084998(unsigned int);
void func_020849C8(unsigned int);
unsigned int func_02084818(unsigned int);
void func_02084774(unsigned int, void (*)(void));
void func_02084968(unsigned int);
void func_0272FD40(int a0);
void func_0272FD5C(unsigned int a0, unsigned int a1);
void func_0272FD7C(void);
asm void func_0272FDC0(int a0, const void *src);
asm void func_0272FDDC(int ch, const void *src, void *dst);
asm void func_0272FE48(void);
void func_0272FE54(unsigned int a0, unsigned int a1, unsigned int a2, unsigned int a3, int s0, void (*s1)(), unsigned int s2);
void func_0272FEF4(unsigned int a0, unsigned int a1, unsigned int a2, void (*cb)(unsigned int), unsigned int arg);
void func_0272FFC8(void);
extern struct G_twl_data_02732EFC data_02732EFC[];

struct St {
    unsigned int f0;
    unsigned int f4;
    unsigned int f8;
    unsigned int fc;
    void (*f10)(unsigned int);
    unsigned int f14;
    unsigned int f18;
    unsigned int f1c;
};
extern struct St data_02732F3C;


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

void func_0272FE54(unsigned int a0, unsigned int a1, unsigned int a2, unsigned int a3, int s0, void (*s1)(), unsigned int s2)
{
    unsigned int buf[4];
    unsigned int n = 10;
    if (s0 == 0) {
        n = 3;
    }
    func_0272FDC0(a0, buf);
    buf[0] = 2;
    buf[1] = 0;
    buf[2] = 0x40000;
    buf[3] = a2;
    func_0272F9C4(n, a0, 0x04004204, a1, 0, a3, s1, s2, buf, 0x0b000000, 0x80000000);
}

void func_0272FEF4(unsigned int a0, unsigned int a1, unsigned int a2, void (*cb)(unsigned int), unsigned int arg)
{
    unsigned int irq;
    struct St *s;
    if (a2 == 0) {
        if (cb != 0) {
            cb(arg);
        }
        return;
    }
    while (((volatile struct St *)&data_02732F3C)->f0 != 0) {
    }
    while ((((*(volatile unsigned int *)0x04000600) & 0x7000000) >> 24 & 2) == 0) {
    }
    s = &data_02732F3C;
    s->f0 = 1;
    s->f4 = a0;
    s->f8 = a1;
    s->fc = a2;
    s->f10 = cb;
    s->f14 = arg;
    func_0272FCB0(a0);
    irq = func_02087988();
    s->f18 = (*(volatile unsigned int *)0x04000600 & 0xc0000000) >> 0x1e;
    s->f1c = func_02084818(0x200000);
    *(volatile unsigned int *)0x04000600 = (*(volatile unsigned int *)0x04000600 & ~0xc0000000) | 0x40000000;
    func_02084774(0x200000, func_0272FFC8);
    func_02084968(0x200000);
    func_0272FFC8();
    func_0208799C(irq);
}

void func_0272FFC8(void)
{
    unsigned int pos;
    unsigned int n = data_02732F3C.fc;
    void (*cb)();
    unsigned int rem;
    unsigned int idx;
    if (n == 0) {
        return;
    }
    if (n >= 0x1d8) {
        n = 0x1d8;
    }
    pos = data_02732F3C.f8;
    data_02732F3C.fc -= n;
    data_02732F3C.f8 = pos + n;
    if (data_02732F3C.fc == 0) {
        func_02084998(0x200000);
    }
    func_020849C8(0x200000);
    rem = data_02732F3C.fc;
    cb = func_02730090;
    if (rem != 0) {
        cb = 0;
    }
    idx = data_02732F3C.f4;
    func_0272F9C4(rem == 0 ? 9 : 8, idx, pos, 0x04000400, 0, n, cb, 0,
                  (void *)((char *)data_02732EFC + (idx << 4)), -1, 0x80000000);
}
