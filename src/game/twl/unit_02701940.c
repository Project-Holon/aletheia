/*
 * file:     unit_02701940.c
 * unit:     yes
 * function: func_02701940, func_027019B4, func_02701A60, func_02701AA0, func_02701FD8, func_02701FE8, func_02702028, func_02702070
 * address:  0x02701940
 * region:   twl
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT*
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   data_02732FC8  0x02732FC8  data twl a2
 *   data_02733FC8  0x02733FC8  data twl a2
 *   data_04000208  0x04000208  data twl a2
 *   func_020879E0 0x020879E0 arm twl a2
 *   func_02087988 0x02087988 arm twl a2
 *   func_0208799C 0x0208799C arm twl a2
 *   func_02087A04 0x02087A04 arm twl a2
 *   func_02088610 0x02088610 arm twl a2
 *   func_02088688 0x02088688 arm twl a2
 *   func_02700DB8  0x02700DB8  arm twl
 *   func_027001F0 0x027001F0 arm twl a2
 */
typedef unsigned int u32;
typedef signed int s32;
typedef unsigned short u16;
typedef unsigned char u8;

#define reg_04004004 (*(volatile u16 *)0x04004004)

typedef struct CamPxiCmd {
    u32 busy;
    u32 callback;
    u32 f08;
    u32 arg;
    s32 command;
    s32 type;
    u8 index;
    u8 total;
    u8 pad[2];
    u8 *buf;
    u32 len;
    u32 pend0;
    u32 pend1;
    u32 pend2;
} CamPxiCmd;

typedef struct CamPxiState {
    u8 pad0[0x128];
    s32 f128, f12c, f130, f134, f138, f13c, f140, f144;
    s32 f148, f14c, f150, f154, f158, f15c, f160, f164;
    s32 f168, f16c, f170, f174, f178, f17c, f180, f184;
    s32 f188, f18c, f190, f194, f198, f19c;
    u32 flagsA;
    u32 flagsB;
    s32 value;
} CamPxiState;

extern u32 func_02087988(void);
extern void func_0208799C(u32);
extern void func_02087A04(u32);
extern int func_02088610(u32, u32, u32);
extern u32 func_020879E0(void);
extern void func_02088688(void);
extern u32 func_02700DB8(u32 a0);
extern void func_027001F0(void);
asm void func_02701940(void);
asm void func_027019B4(u32 a0, u32 a1, u32 a2);
asm void func_02701A60(const u8 *ptr);
void func_02701AA0(int tag, u32 data, int err);
asm void func_02701FD8(void);
asm void func_02701FE8(u32 result);
void func_02702028(void);
asm void func_02702070(void);
extern CamPxiCmd data_02732FC8;
extern CamPxiState data_02733FC8;
extern u16 data_04000208;


asm void func_02701940(void) {
    stmdb sp!, {r4, r5, r6, r7, r8, lr}
    mov r8, r0
    mov r7, r1
    mov r6, r2
    bl func_02087988
    ldr r4, =data_02732FC8
    ldr r1, [r4]
    cmp r1, #0
    beq @lbl_02701970
    bl func_0208799C
    mov r0, #2
    ldmfd sp!, {r4, r5, r6, r7, r8, pc}
@lbl_02701970:
    mov r5, #1
    str r5, [r4]
    bl func_0208799C
    str r7, [r4, #4]
    ldr r3, =data_02733FC8
    str r6, [r4, #0xc]
    mov r1, r5
    and r2, r8, #0xff
    mov r0, #0x40
    str r8, [r3, #0x1a8]
    bl func_027019B4
    cmp r0, #0
    movne r0, #0
    moveq r0, #4
    ldmfd sp!, {r4, r5, r6, r7, r8, pc}
}



asm void func_027019B4(u32 a0, u32 a1, u32 a2) {
    stmdb sp!, {r4, r5, r6, lr}
    mov r0, r0, lsl #8
    and r3, r0, #0x7f00
    mov r0, r1, lsl #0x10
    orr r1, r3, #0x2000000
    and r0, r0, #0xff0000
    and r2, r2, #0xff
    orr r0, r1, r0
    orr r5, r2, r0
    bl func_02087988
    ldr r2, [pc, #0x74]
    ldrh r4, [r2]
    orr r1, r4, #0x100
    strh r1, [r2]
    bl func_0208799C
    ands r6, r4, #0x100
    bne @lbl_02701A00
    mov r0, #0x14
    bl func_02087A04
@lbl_02701A00:
    ldr r4, =data_02732FC8
    mov r3, r6, asr #8
    mov r1, r5
    mov r0, #0x15
    mov r2, #0
    str r3, [r4, #0x24]
    bl func_02088610
    cmp r0, #0
    bge @lbl_02701A50
    ldr r0, [r4, #0x24]
    cmp r0, #0
    bne @lbl_02701A48
    bl func_02087988
    ldr r2, [pc, #0x1c]
    ldrh r1, [r2]
    bic r1, r1, #0x100
    strh r1, [r2]
    bl func_0208799C
@lbl_02701A48:
    mov r0, #0
    ldmfd sp!, {r4, r5, r6, pc}
@lbl_02701A50:
    mov r0, #1
    ldmfd sp!, {r4, r5, r6, pc}
    streq r4, [r0], #-4
}



asm void func_02701A60(const u8 *ptr)
{
    stmdb   sp!, {r4, r5, r6, lr}
    ldrb    r1, [r0, #1]
    ldrb    r2, [r0, #0]
    ldrb    r3, [r0, #2]
    mov     r0, r1, lsl #8
    orr     r0, r0, r2, lsl #16
    orr     r6, r3, r0
    mov     r5, #0x15
    mov     r4, #0
loop:
    mov     r0, r5
    mov     r1, r6
    mov     r2, r4
    bl      func_02088610
    cmp     r0, #0
    blt     loop
    ldmfd   sp!, {r4, r5, r6, pc}
}


void func_02701AA0(int tag, u32 data, int err)
{
    u32 result;
    u8 *buf;

    if (err) {
        func_02701FE8(7);
        return;
    }
    if (data & 0x2000000) {
        data_02732FC8.total = (data & 0xff0000) >> 16;
        data_02732FC8.index = 0;
        data_02732FC8.command = (data & 0x7f00) >> 8;
        data_02732FC8.type = data & 0xff;
    } else {
        buf = data_02732FC8.buf;
        if (buf == 0) {
            func_02701FE8(7);
            return;
        }
        if (data_02732FC8.index < data_02732FC8.len) {
            buf[data_02732FC8.index++] = (data & 0xff0000) >> 16;
        }
        if (data_02732FC8.index < data_02732FC8.len) {
            data_02732FC8.buf[data_02732FC8.index++] = (data & 0xff00) >> 8;
        }
        if (data_02732FC8.index < data_02732FC8.len) {
            data_02732FC8.buf[data_02732FC8.index++] = data;
        }
    }
    if (data_02732FC8.index < data_02732FC8.total - 1) {
        return;
    }
    if (data_02732FC8.pend2 != 0 || (data_02732FC8.pend1 == 0 && data_02732FC8.pend0 == 0)) {
        u32 irq = func_02087988();
        reg_04004004 = reg_04004004 & ~0x100;
        func_0208799C(irq);
    }
    result = 0;
    data_02732FC8.pend1 = result;
    data_02732FC8.pend2 = result;
    switch (data_02732FC8.type) {
    case 0:
        switch (data_02732FC8.command) {
        case 0x10:
            data_02733FC8.f19c = data_02733FC8.value;
            break;
        case 0x12:
            if (data_02733FC8.flagsA & 1) data_02733FC8.f15c = data_02733FC8.value;
            if (data_02733FC8.flagsA & 2) data_02733FC8.f198 = data_02733FC8.value;
            break;
        case 0x30:
            if (data_02733FC8.flagsA & 1) {
                if (data_02733FC8.flagsB & 1) data_02733FC8.f128 = data_02733FC8.value;
            }
            if (data_02733FC8.flagsB & 2) data_02733FC8.f12c = data_02733FC8.value;
            if (data_02733FC8.flagsA & 2) {
                if (data_02733FC8.flagsB & 1) data_02733FC8.f164 = data_02733FC8.value;
            }
            if (data_02733FC8.flagsB & 2) data_02733FC8.f168 = data_02733FC8.value;
            break;
        case 0x31:
            if (data_02733FC8.flagsA & 1) data_02733FC8.f148 = data_02733FC8.value;
            if (data_02733FC8.flagsA & 2) data_02733FC8.f184 = data_02733FC8.value;
            break;
        case 0x32:
            if (data_02733FC8.flagsA & 1) {
                if (data_02733FC8.flagsB & 1) data_02733FC8.f130 = data_02733FC8.value;
            }
            if (data_02733FC8.flagsB & 2) data_02733FC8.f134 = data_02733FC8.value;
            if (data_02733FC8.flagsA & 2) {
                if (data_02733FC8.flagsB & 1) data_02733FC8.f16c = data_02733FC8.value;
            }
            if (data_02733FC8.flagsB & 2) data_02733FC8.f170 = data_02733FC8.value;
            break;
        case 0x33:
            if (data_02733FC8.flagsA & 1) {
                if (data_02733FC8.flagsB & 1) data_02733FC8.f138 = data_02733FC8.value;
            }
            if (data_02733FC8.flagsB & 2) data_02733FC8.f13c = data_02733FC8.value;
            if (data_02733FC8.flagsA & 2) {
                if (data_02733FC8.flagsB & 1) data_02733FC8.f174 = data_02733FC8.value;
            }
            if (data_02733FC8.flagsB & 2) data_02733FC8.f178 = data_02733FC8.value;
            break;
        case 0x34:
            if (data_02733FC8.flagsA & 1) {
                data_02733FC8.f140 = data_02733FC8.value;
                switch (data_02733FC8.value) {
                case 0:
                    data_02733FC8.f150 = 0;
                    data_02733FC8.f14c = 0;
                    data_02733FC8.f144 = 0;
                    break;
                case 1:
                    data_02733FC8.f150 = -2;
                    data_02733FC8.f14c = 0;
                    data_02733FC8.f144 = 0;
                    break;
                case 2:
                    data_02733FC8.f150 = 1;
                    data_02733FC8.f14c = 0;
                    data_02733FC8.f144 = 3;
                    break;
                case 3:
                    data_02733FC8.f150 = -1;
                    data_02733FC8.f14c = 2;
                    data_02733FC8.f144 = 0;
                    break;
                case 4:
                    data_02733FC8.f150 = 2;
                    data_02733FC8.f14c = 2;
                    data_02733FC8.f144 = 0;
                    break;
                }
            }
            if (data_02733FC8.flagsA & 2) {
                data_02733FC8.f17c = data_02733FC8.value;
                switch (data_02733FC8.value) {
                case 0:
                    data_02733FC8.f18c = 0;
                    data_02733FC8.f188 = 0;
                    data_02733FC8.f180 = 0;
                    break;
                case 1:
                    data_02733FC8.f18c = -2;
                    data_02733FC8.f188 = 0;
                    data_02733FC8.f180 = 0;
                    break;
                case 2:
                    data_02733FC8.f18c = 1;
                    data_02733FC8.f188 = 0;
                    data_02733FC8.f180 = 3;
                    break;
                case 3:
                    data_02733FC8.f18c = -1;
                    data_02733FC8.f188 = 2;
                    data_02733FC8.f180 = 0;
                    break;
                case 4:
                    data_02733FC8.f18c = 2;
                    data_02733FC8.f188 = 2;
                    data_02733FC8.f180 = 0;
                    break;
                }
            }
            break;
        case 0x35:
            if (data_02733FC8.flagsA & 1) {
                data_02733FC8.f144 = data_02733FC8.value;
                data_02733FC8.f158 = 1;
            }
            if (data_02733FC8.flagsA & 2) {
                data_02733FC8.f180 = data_02733FC8.value;
                data_02733FC8.f194 = 1;
            }
            break;
        case 0x36:
            if (data_02733FC8.flagsA & 1) data_02733FC8.f14c = data_02733FC8.value;
            if (data_02733FC8.flagsA & 2) data_02733FC8.f188 = data_02733FC8.value;
            break;
        case 0x37:
            if (data_02733FC8.flagsA & 1) data_02733FC8.f150 = data_02733FC8.value;
            if (data_02733FC8.flagsA & 2) data_02733FC8.f18c = data_02733FC8.value;
            break;
        case 0x39:
            if (data_02733FC8.flagsA & 1) data_02733FC8.f154 = data_02733FC8.value;
            if (data_02733FC8.flagsA & 2) data_02733FC8.f190 = data_02733FC8.value;
            break;
        case 0x3a:
            if (data_02733FC8.flagsA & 1) data_02733FC8.f158 = data_02733FC8.value;
            if (data_02733FC8.flagsA & 2) data_02733FC8.f194 = data_02733FC8.value;
            break;
        case 0x40:
            data_02733FC8.f19c = data_02733FC8.value;
            break;
        }
        break;
    case 1:
        result = 1;
        break;
    case 4:
        result = 6;
        break;
    case 2:
    case 3:
    case 5:
    default:
        result = 7;
        break;
    }
    func_02701FE8(result);
    if (result == 6) {
        func_027001F0();
    }
}


asm void func_02701FD8(void) {
    ldr r1, =data_02732FC8
    str r0, [r1, #8]
    bx lr
}




asm void func_02701FE8(u32 result) {
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
    if (data_02732FC8.busy == 0) {
        return;
    }
    do {
        u32 mode = func_020879E0();
        if (mode == 0x80 || data_04000208 == 0) {
            func_02088688();
        }
    } while (data_02732FC8.busy != 0);
}


asm void func_02702070(void) {
    ldr ip, =func_02700DB8
    mov r0, #0
    bx ip
}
