/*
 * file:     unit_02731718_p03.c
 * unit:     yes
 * function: func_02731774, func_0273184C, func_02731868, func_02731920, func_0273199C, func_02731A84, func_02731AF0, func_02731BF8, func_02731CFC, func_02731D6C, func_02731E50, func_02731F00, func_02731F14, func_027320D0, func_027323A8
 * address:  0x02731774
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
 *   func_020862B8  0x020862B8  arm  twl
 *   func_02703088  0x02703088  arm  twl
 *   func_02732B70  0x02732B70  arm  twl
 *   func_02731770  0x02731770  thumb
 *   func_02731754  0x02731754  thumb
 *   func_02731760  0x02731760  thumb
 *   MI_CpuCopy8    0x02082D44  arm
 *   func_02731764  0x02731764  thumb
 *   func_021657C8  0x021657C8  arm  ov009
 *   func_02702434  0x02702434  arm  twl
 *   func_02165A4C  0x02165A4C  arm  ov009
 *   func_02702B08  0x02702B08  arm  twl
 *   func_02702FE8  0x02702FE8  arm  twl
 *   func_027034C0  0x027034C0  arm  twl
 *   func_02703960  0x02703960  arm  twl
 *   func_02703854  0x02703854  arm  twl
 *   func_02732A64  0x02732A64  arm  twl
 *   func_027028B0  0x027028B0  arm  twl
 *   func_02702A98  0x02702A98  arm  twl
 *   func_02702BFC  0x02702BFC  arm  twl
 *   func_02703424  0x02703424  arm  twl
 *   func_02732874  0x02732874  arm  twl
 *   func_02166378   0x02166378  arm  ov009
 *   func_027036A0   0x027036A0  arm  twl
 *   OS_SleepThread  0x020857B0  arm
 *   func_02732CAC   0x02732CAC  arm  twl
 *   func_02732CEC   0x02732CEC  arm  twl
 *   func_02702980  0x02702980  arm  twl
 *   func_021659B4  0x021659B4  arm  ov009
 *   func_02702F38     0x02702F38  arm  twl
 *   OS_GetMacAddress  0x02087C6C  arm
 *   func_021665CC     0x021665CC  arm  ov009
 *   func_027035F4     0x027035F4  arm  twl
 *   func_0270379C     0x0270379C  arm  twl
 *   func_02732944     0x02732944  arm  twl
 */
typedef unsigned int u32;

typedef unsigned short u16;

typedef unsigned char u8;

typedef struct NetWork {
    u8 pad0[0x12da];
    u16 phase;
    u8 pad1[2];
    u8 state;
    u8 pad2[0x43a0 - 0x12df];
    u32 sendBuf;
    u16 sendLen;
    u8 pad3[0x43e0 - 0x43a6];
    u32 sendCount;
} NetWork;

extern void func_02731770(void);
extern void func_02731754(void);
extern void func_02731760(void *a, void *b, void *c);
extern void MI_CpuCopy8(const void *src, void *dst, u32 size);
extern void func_02731764(void);
extern NetWork *func_021657C8(void);
extern void func_020862B8(u32 buf, u32 len);
extern int func_02703088(void *cb, void *buf);
extern void func_02732B70(u32 a, u32 b, u32 c);
extern u32 func_02702434(u32 a0, u32 a1, u32 a2);
extern void func_02165A4C(unsigned char phase);
extern u32 func_02702B08(void *arg);
extern u32 func_02702FE8(void *arg);
extern u32 func_027034C0(void *a, u32 b, u32 c, void *d);
extern u32 func_02703960(void *a, void *b);
extern u32 func_02703854(u32 a0, u32 a1);
extern void func_02732A64(void);
extern u32 func_027028B0(void);
extern u32 func_02702A98(void);
extern u32 func_02702BFC(void *arg);
extern u32 func_02703424(void *arg);
extern void func_02732874(void);
extern void *func_02166378(void);
extern u32 func_027036A0(void *cb, u32 a, u32 b, u32 c);
extern void OS_SleepThread(void *queue);
extern void func_02732CAC(void);
extern void func_02732CEC(void);
extern u32 func_02702980(void);
extern void func_021659B4(u32 a, void *b, u32 c, u32 d);
extern u32 func_02702F38(void *arg);
extern void OS_GetMacAddress(void *mac);
extern void func_021665CC(void *mac);
extern u32 func_027035F4(void *arg, u32 b);
extern u32 func_0270379C(void *arg, void *b, u32 c, u32 d);
extern void func_02732944(void);
asm void func_02731774(void *ctx, const void *key, u32 key_len);
void func_0273184C(void *a, void *b, void *c);
asm void func_02731868(void *ctx, void *digest);
asm void func_02731920(void *digest, const void *data, u32 data_len, const void *key, u32 key_len);
asm u32 func_0273199C(void);
asm u32 func_02731A84(void);
int func_02731AF0(u32 a, u32 b, u32 c);
asm u32 func_02731BF8(void);
asm u32 func_02731CFC(void);
asm u32 func_02731D6C(void);
asm u32 func_02731E50(u32 a, u32 b, u32 c, u32 d);
u32 func_02731F00(void);
asm void func_02731F14(void);
asm void func_027320D0(void *arg);
asm void func_027323A8(void);



#pragma thumb on


#pragma thumb reset



asm void func_02731774(void *ctx, const void *key, u32 key_len)
{
    stmdb   sp!, {r3, r4, r5, lr}
    sub     sp, sp, #0x40
    movs    r4, r0
    mov     r5, r2
    addeq   sp, sp, #0x40
    ldmeqfd sp!, {r3, r4, r5, pc}
    cmp     r5, #0
    beq     @loc_027317A0
    cmp     r1, #0
    addeq   sp, sp, #0x40
    ldmeqfd sp!, {r3, r4, r5, pc}

@loc_027317A0:
    cmp     r5, #0x40
    bls     @loc_027317C0
    mov     r2, r5
    add     r0, r4, #0x64
    bl      func_02731770
    mov     r0, #0x14
    str     r0, [r4, #0xa4]
    b       @loc_027317D4

@loc_027317C0:
    mov     r0, r1
    mov     r2, r5
    add     r1, r4, #0x64
    bl      MI_CpuCopy8
    str     r5, [r4, #0xa4]

@loc_027317D4:
    ldr     r0, [r4, #0xa4]
    mov     r1, #0
    cmp     r0, #0
    bls     @loc_02731808
    add     r2, sp, #0

@loop_ipad:
    add     r0, r4, r1
    ldrb    r0, [r0, #0x64]
    add     r1, r1, #1
    eor     r0, r0, #0x36
    strb    r0, [r2], #1
    ldr     r0, [r4, #0xa4]
    cmp     r1, r0
    blo     @loop_ipad

@loc_02731808:
    cmp     r1, #0x40
    bge     @loc_0273182C
    add     r0, sp, #0
    add     r2, r0, r1
    mov     r0, #0x36

@loop_pad:
    add     r1, r1, #1
    cmp     r1, #0x40
    strb    r0, [r2], #1
    blt     @loop_pad

@loc_0273182C:
    mov     r0, r4
    bl      func_02731754
    add     r1, sp, #0
    mov     r0, r4
    mov     r2, #0x40
    bl      func_02731760
    add     sp, sp, #0x40
    ldmfd   sp!, {r3, r4, r5, pc}
}





#pragma thumb on





#pragma thumb reset






void func_0273184C(void *a, void *b, void *c)
{
    if (a != 0 && c != 0 && b != 0) {
        func_02731760(a, b, c);
    }
}





#pragma thumb on





#pragma thumb reset






asm void func_02731868(void *ctx, void *digest)
{
    stmdb   sp!, {r4, r5, lr}
    sub     sp, sp, #0x54
    mov     r4, r1
    movs    r5, r0
    cmpne   r4, #0
    addeq   sp, sp, #0x54
    ldmeqfd sp!, {r4, r5, pc}
    add     r1, sp, #0
    bl      func_02731764
    ldr     r0, [r5, #0xa4]
    mov     r1, #0
    cmp     r0, #0
    bls     @loc_027318C0
    add     r2, sp, #0x14

@loc_027318A0:
    add     r0, r5, r1
    ldrb    r0, [r0, #0x64]
    add     r1, r1, #1
    eor     r0, r0, #0x5c
    strb    r0, [r2], #1
    ldr     r0, [r5, #0xa4]
    cmp     r1, r0
    blo     @loc_027318A0

@loc_027318C0:
    cmp     r1, #0x40
    bge     @loc_027318E4
    add     r0, sp, #0x14
    add     r2, r0, r1
    mov     r0, #0x5c

@loc_027318D4:
    add     r1, r1, #1
    cmp     r1, #0x40
    strb    r0, [r2], #1
    blt     @loc_027318D4

@loc_027318E4:
    mov     r0, r5
    bl      func_02731754
    add     r1, sp, #0x14
    mov     r0, r5
    mov     r2, #0x40
    bl      func_02731760
    add     r1, sp, #0
    mov     r0, r5
    mov     r2, #0x14
    bl      func_02731760
    mov     r0, r5
    mov     r1, r4
    bl      func_02731764
    add     sp, sp, #0x54
    ldmfd   sp!, {r4, r5, pc}
}






asm void func_02731920(void *digest, const void *data, u32 data_len, const void *key, u32 key_len)
{
    stmdb   sp!, {r4, r5, r6, lr}
    sub     sp, sp, #0xa8
    movs    r6, r0
    mov     r5, r1
    mov     r4, r2
    addeq   sp, sp, #0xa8
    ldmeqfd sp!, {r4, r5, r6, pc}
    cmp     r4, #0
    beq     @loc_02731950
    cmp     r5, #0
    addeq   sp, sp, #0xa8
    ldmeqfd sp!, {r4, r5, r6, pc}

@loc_02731950:
    ldr     r0, [sp, #0xb8]
    cmp     r0, #0
    beq     @loc_02731968
    cmp     r3, #0
    addeq   sp, sp, #0xa8
    ldmeqfd sp!, {r4, r5, r6, pc}

@loc_02731968:
    ldr     r2, [sp, #0xb8]
    add     r0, sp, #0
    mov     r1, r3
    bl      func_02731774
    add     r0, sp, #0
    mov     r1, r5
    mov     r2, r4
    bl      func_0273184C
    add     r0, sp, #0
    mov     r1, r6
    bl      func_02731868
    add     sp, sp, #0xa8
    ldmfd   sp!, {r4, r5, r6, pc}
}






asm u32 func_0273199C(void)
{
    stmdb   sp!, {r4, lr}
    bl      func_021657C8
    mov     r4, r0
    add     r0, r4, #0x1000
    ldr     r1, [r0, #0x2c0]
    add     r0, r4, #0x3a0
    and     r2, r1, #0xff
    add     r0, r0, #0x1000
    mov     r1, #0x3000
    bl      func_02702434
    cmp     r0, #5
    addls   pc, pc, r0, lsl #2
    b       @loc_02731A00

    b       @loc_02731A10
    b       @loc_02731A00
    b       @loc_02731A00
    b       @loc_027319E8
    b       @loc_027319F8
    b       @loc_02731A00

@loc_027319E8:
    mov     r0, #0xb
    bl      func_02165A4C
    mov     r0, #7
    ldmfd   sp!, {r4, pc}

@loc_027319F8:
    mov     r0, #5
    ldmfd   sp!, {r4, pc}

@loc_02731A00:
    mov     r0, #0xb
    bl      func_02165A4C
    mov     r0, #7
    ldmfd   sp!, {r4, pc}

@loc_02731A10:
    ldr     r0, =func_027320D0
    add     r1, r4, #0x4300
    mov     r2, #0
    strh    r2, [r1, #0xe6]
    bl      func_02702B08
    cmp     r0, #2
    beq     @loc_02731A40
    cmp     r0, #3
    beq     @loc_02731A68
    cmp     r0, #6
    beq     @loc_02731A58
    b       @loc_02731A68

@loc_02731A40:
    mov     r0, #2
    bl      func_02165A4C
    add     r0, r4, #0x1200
    mov     r1, #1
    strh    r1, [r0, #0xda]
    b       @loc_02731A78

@loc_02731A58:
    mov     r0, #0xc
    bl      func_02165A4C
    mov     r0, #1
    ldmfd   sp!, {r4, pc}

@loc_02731A68:
    mov     r0, #0xb
    bl      func_02165A4C
    mov     r0, #7
    ldmfd   sp!, {r4, pc}

@loc_02731A78:
    mov     r0, #3
    ldmfd   sp!, {r4, pc}
}






asm u32 func_02731A84(void)
{
    stmdb   sp!, {r4, lr}
    bl      func_021657C8
    mov     r4, r0
    ldr     r0, =func_027320D0
    bl      func_02702FE8
    cmp     r0, #2
    beq     @loc_02731AB4
    cmp     r0, #3
    beq     @loc_02731AD4
    cmp     r0, #6
    beq     @loc_02731ACC
    b       @loc_02731AD4

@loc_02731AB4:
    mov     r0, #4
    bl      func_02165A4C
    add     r0, r4, #0x1200
    mov     r1, #2
    strh    r1, [r0, #0xda]
    b       @loc_02731AE4

@loc_02731ACC:
    mov     r0, #4
    ldmfd   sp!, {r4, pc}

@loc_02731AD4:
    mov     r0, #0xb
    bl      func_02165A4C
    mov     r0, #7
    ldmfd   sp!, {r4, pc}

@loc_02731AE4:
    mov     r0, #3
    ldmfd   sp!, {r4, pc}
}



int func_02731AF0(u32 a, u32 b, u32 c)
{
    NetWork *w = func_021657C8();

    switch (w->state) {
    case 5:
        func_02732B70(a, b, c);
        return 2;
    case 6:
        func_02732B70(a, b, c);
        return 0;
    default:
        return 1;
    case 3:
        func_02732B70(a, b, c);
        func_020862B8(w->sendBuf, w->sendLen);
        w->sendCount++;
        switch (func_02703088(func_027323A8, &w->sendBuf)) {
        case 2:
            func_02165A4C(5);
            w->phase = 3;
            return 3;
        case 6:
            return 4;
        case 3:
        default:
            func_02165A4C(11);
            return 7;
        }
    }
}




asm u32 func_02731BF8(void)
{
    stmdb   sp!, {r3, r4, r5, lr}
    sub     sp, sp, #0x28
    bl      func_021657C8
    mov     r4, r0
    add     r0, r4, #0x1000
    ldrb    r1, [r0, #0x290]
    cmp     r1, #7
    addls   pc, pc, r1, lsl #2
    b       @loc_02731C98

    b       @loc_02731C3C
    b       @loc_02731C3C
    b       @loc_02731C3C
    b       @loc_02731C3C
    b       @loc_02731C6C
    b       @loc_02731C6C
    b       @loc_02731C6C
    b       @loc_02731C6C

@loc_02731C3C:
    ldr     r0, [r0, #0x2d4]
    mov     r2, #0
    and     r0, r0, #0xc0000
    cmp     r0, #0xc0000
    moveq   r2, #1
    add     r0, r4, #0x1000
    str     r2, [sp, #0]
    ldrb    r2, [r0, #0x291]
    ldr     r0, =func_027320D0
    add     r3, r4, #0x1240
    bl      func_027034C0
    b       @loc_02731C94

@loc_02731C6C:
    add     r1, sp, #6
    add     r0, r4, #0x1240
    mov     r2, #0x20
    bl      MI_CpuCopy8
    add     r0, r4, #0x1000
    ldrb    r2, [r0, #0x290]
    ldr     r0, =func_027320D0
    add     r1, sp, #4
    strh    r2, [sp, #4]
    bl      func_02703960

@loc_02731C94:
    mov     r5, r0

@loc_02731C98:
    cmp     r5, #2
    beq     @loc_02731CB4
    cmp     r5, #3
    beq     @loc_02731CD8
    cmp     r5, #6
    beq     @loc_02731CCC
    b       @loc_02731CD8

@loc_02731CB4:
    mov     r0, #8
    bl      func_02165A4C
    add     r0, r4, #0x1200
    mov     r1, #5
    strh    r1, [r0, #0xda]
    b       @loc_02731CEC

@loc_02731CCC:
    add     sp, sp, #0x28
    mov     r0, #4
    ldmfd   sp!, {r3, r4, r5, pc}

@loc_02731CD8:
    mov     r0, #0xb
    bl      func_02165A4C
    add     sp, sp, #0x28
    mov     r0, #7
    ldmfd   sp!, {r3, r4, r5, pc}

@loc_02731CEC:
    mov     r0, #3
    add     sp, sp, #0x28
    ldmfd   sp!, {r3, r4, r5, pc}
}





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





asm u32 func_02731D6C(void)
{
    stmdb   sp!, {r4, lr}
    bl      func_021657C8
    mov     r4, r0
    bl      func_027028B0
    cmp     r0, #4
    addls   pc, pc, r0, lsl #2
    b       @loc_02731DE4

    b       @loc_02731DE4
    b       @loc_02731D9C
    b       @loc_02731DC0
    b       @loc_02731DCC
    b       @loc_02731DD8

@loc_02731D9C:
    bl      func_02702A98
    cmp     r0, #0
    bne     @loc_02731DF4
    mov     r0, #1
    bl      func_02165A4C
    add     r1, r4, #0x1200
    mov     r0, #0
    strh    r0, [r1, #0xda]
    ldmfd   sp!, {r4, pc}

@loc_02731DC0:
    ldr     r0, =func_027320D0
    bl      func_02702BFC
    b       @loc_02731DF4

@loc_02731DCC:
    ldr     r0, =func_027320D0
    bl      func_02702FE8
    b       @loc_02731DF4

@loc_02731DD8:
    ldr     r0, =func_02732874
    bl      func_02703424
    b       @loc_02731DF4

@loc_02731DE4:
    add     r0, r4, #0x1000
    mov     r1, #1
    strb    r1, [r0, #0x2dd]
    mov     r0, #4

@loc_02731DF4:
    cmp     r0, #2
    beq     @loc_02731E10
    cmp     r0, #3
    beq     @loc_02731E30
    cmp     r0, #6
    beq     @loc_02731E28
    b       @loc_02731E30

@loc_02731E10:
    mov     r0, #0xd
    bl      func_02165A4C
    add     r0, r4, #0x1200
    mov     r1, #9
    strh    r1, [r0, #0xda]
    b       @loc_02731E40

@loc_02731E28:
    mov     r0, #4
    ldmfd   sp!, {r4, pc}

@loc_02731E30:
    mov     r0, #0xb
    bl      func_02165A4C
    mov     r0, #7
    ldmfd   sp!, {r4, pc}

@loc_02731E40:
    mov     r0, #3
    ldmfd   sp!, {r4, pc}
}





asm u32 func_02731E50(u32 a, u32 b, u32 c, u32 d)
{
    stmdb   sp!, {r4, r5, r6, r7, r8, lr}
    mov     r5, r3
    mov     r8, r0
    mov     r7, r1
    mov     r6, r2
    bl      func_02166378
    mov     r4, r0
    cmp     r5, #0
    bne     @loc_02731E88
    ldr     r0, =func_02732CAC
    mov     r1, r8
    mov     r2, r7
    mov     r3, r6
    b       @loc_02731E9C

@loc_02731E88:
    ldr     r0, =func_02732CEC
    mov     r1, r8
    mov     r2, r7
    mov     r3, r6
    str     r5, [r4, #0x2c]

@loc_02731E9C:
    bl      func_027036A0
    cmp     r0, #6
    addls   pc, pc, r0, lsl #2
    b       @loc_02731EC8

    b       @loc_02731EC8
    b       @loc_02731EC8
    b       @loc_02731ED0
    b       @loc_02731EC8
    b       @loc_02731EC8
    b       @loc_02731EC8
    b       @loc_02731EC8

@loc_02731EC8:
    mvn     r0, #4
    ldmfd   sp!, {r4, r5, r6, r7, r8, pc}

@loc_02731ED0:
    cmp     r5, #0
    bne     @loc_02731EF0
    add     r0, r4, #4
    bl      OS_SleepThread
    ldrh    r0, [r4, #0x24]
    cmp     r0, #0
    mvnne   r0, #4
    ldmnefd sp!, {r4, r5, r6, r7, r8, pc}

@loc_02731EF0:
    mov     r0, r6
    ldmfd   sp!, {r4, r5, r6, r7, r8, pc}
}





u32 func_02731F00(void)
{
    return (func_02702980() << 15) >> 16;
}





asm void func_02731F14(void)
{
    stmdb   sp!, {r4, r5, r6, r7, r8, lr}
    mov     r4, #3
    bl      func_021657C8
    mov     r7, r0
    add     r0, r7, #0x1000
    ldrb    r1, [r0, #0x2dd]
    cmp     r1, #0
    ldmnefd sp!, {r4, r5, r6, r7, r8, pc}
    mov     r5, #0
    strb    r5, [r0, #0x2dd]
    add     r1, r7, #0x4300
    strh    r5, [r1, #0xe4]
    ldrb    r0, [r0, #0x2de]
    mov     r6, #1
    cmp     r0, #0xd
    addls   pc, pc, r0, lsl #2
    b       @loc_027320A4

    b       @loc_027320A4
    b       @loc_027320A4
    b       @loc_027320A4
    b       @loc_027320A4
    b       @loc_027320A4
    b       @loc_02731F90
    b       @loc_02731F90
    b       @loc_02731FB0
    b       @loc_02731FD0
    b       @loc_02731FFC
    b       @loc_02732020
    b       @loc_027320A4
    b       @loc_02731FFC
    b       @loc_02732044

@loc_02731F90:
    mov     r0, r4
    bl      func_02165A4C
    mov     r0, r6
    mov     r1, r5
    mov     r2, r5
    add     r3, r4, #0x298
    bl      func_021659B4
    ldmfd   sp!, {r4, r5, r6, r7, r8, pc}

@loc_02731FB0:
    mov     r0, r4
    bl      func_02165A4C
    mov     r0, r5
    mov     r1, r5
    mov     r2, r5
    rsb     r3, r4, #0x2a4
    bl      func_021659B4
    ldmfd   sp!, {r4, r5, r6, r7, r8, pc}

@loc_02731FD0:
    ldrh    r8, [r1, #0xe6]
    mov     r0, r4
    strh    r5, [r1, #0xe6]
    bl      func_02165A4C
    add     r1, r7, #0x2e0
    mov     r0, r6
    mov     r2, r8
    add     r1, r1, #0x1000
    add     r3, r4, #0x2a8
    bl      func_021659B4
    ldmfd   sp!, {r4, r5, r6, r7, r8, pc}

@loc_02731FFC:
    mov     r0, r4
    bl      func_02165A4C
    add     r1, r7, #0x2e0
    mov     r0, r5
    mov     r2, r6
    add     r1, r1, #0x1000
    add     r3, r4, #0x2b0
    bl      func_021659B4
    ldmfd   sp!, {r4, r5, r6, r7, r8, pc}

@loc_02732020:
    mov     r0, r4
    bl      func_02165A4C
    add     r1, r7, #0x2e0
    ldr     r3, =0x2BA
    mov     r0, r5
    mov     r2, r5
    add     r1, r1, #0x1000
    bl      func_021659B4
    ldmfd   sp!, {r4, r5, r6, r7, r8, pc}

@loc_02732044:
    ldr     r0, =func_027320D0
    bl      func_02702FE8
    cmp     r0, #2
    ldmeqfd sp!, {r4, r5, r6, r7, r8, pc}
    cmp     r0, #3
    beq     @loc_02732084
    cmp     r0, #6
    bne     @loc_02732084
    mov     r0, #0xc
    bl      func_02165A4C
    mov     r0, r6
    mov     r1, r5
    mov     r2, r5
    mov     r3, #0x2c8
    bl      func_021659B4
    ldmfd   sp!, {r4, r5, r6, r7, r8, pc}

@loc_02732084:
    mov     r0, #0xb
    bl      func_02165A4C
    mov     r0, #7
    mov     r1, #0
    mov     r2, r1
    rsb     r3, r0, #0x2d8
    bl      func_021659B4
    ldmfd   sp!, {r4, r5, r6, r7, r8, pc}

@loc_027320A4:
    mov     r0, #0xb
    bl      func_02165A4C
    add     r1, r7, #0x1000
    mov     r0, #7
    ldrb    r2, [r1, #0x2de]
    add     r3, r0, #0x2d0
    mov     r1, #0
    bl      func_021659B4
    ldmfd   sp!, {r4, r5, r6, r7, r8, pc}
}





asm void func_027320D0(void *arg)
{
    stmdb   sp!, {r4, r5, r6, lr}
    sub     sp, sp, #8
    mov     r6, r0
    mov     r5, #0xd
    bl      func_021657C8
    ldrh    r1, [r6, #2]
    mov     r4, r0
    cmp     r1, #0xa
    addls   pc, pc, r1, lsl #2
    b       @loc_0273235C

    b       @loc_02732124
    b       @loc_027322EC
    b       @loc_0273235C
    b       @loc_0273235C
    b       @loc_0273235C
    b       @loc_0273235C
    b       @loc_0273235C
    b       @loc_0273235C
    b       @loc_0273235C
    b       @loc_0273235C
    b       @loc_02732324

@loc_02732124:
    ldrh    r0, [r6, #0]
    cmp     r0, #0x12
    addls   pc, pc, r0, lsl #2
    b       @loc_02732260

    b       @loc_02732260
    b       @loc_02732260
    b       @loc_02732260
    b       @loc_02732180
    b       @loc_0273218C
    b       @loc_027321E0
    b       @loc_02732218
    b       @loc_02732260
    b       @loc_02732260
    b       @loc_02732260
    b       @loc_02732260
    b       @loc_02732260
    b       @loc_02732260
    b       @loc_02732224
    b       @loc_02732248
    b       @loc_02732260
    b       @loc_02732260
    b       @loc_02732260
    b       @loc_02732224

@loc_02732180:
    ldr     r0, =func_027320D0
    bl      func_02702F38
    b       @loc_0273225C

@loc_0273218C:
    bl      func_02702A98
    cmp     r0, #0
    bne     @loc_027321BC
    mov     r0, #1
    bl      func_02165A4C
    mov     r0, #0
    mov     r1, r0
    mov     r2, r0
    mov     r3, #0x300
    bl      func_021659B4
    add     sp, sp, #8
    ldmfd   sp!, {r4, r5, r6, pc}

@loc_027321BC:
    mov     r0, #0xb
    bl      func_02165A4C
    mov     r0, #7
    mov     r1, #0
    mov     r2, r1
    rsb     r3, r0, #0x310
    bl      func_021659B4
    add     sp, sp, #8
    ldmfd   sp!, {r4, r5, r6, pc}

@loc_027321E0:
    add     r4, sp, #0
    mov     r0, r4
    bl      OS_GetMacAddress
    mov     r0, r4
    bl      func_021665CC
    mov     r0, #3
    bl      func_02165A4C
    mov     r0, #0
    ldr     r3, =0x316
    mov     r1, r0
    mov     r2, r0
    bl      func_021659B4
    add     sp, sp, #8
    ldmfd   sp!, {r4, r5, r6, pc}

@loc_02732218:
    ldr     r0, =func_027320D0
    bl      func_02702BFC
    b       @loc_0273225C

@loc_02732224:
    add     r0, r4, #0x1000
    ldr     r0, [r0, #0x2d4]
    mov     r1, #0
    and     r0, r0, #0x30000
    cmp     r0, #0x30000
    ldr     r0, =func_027320D0
    movne   r1, #1
    bl      func_027035F4
    b       @loc_0273225C

@loc_02732248:
    ldr     r0, =func_02732944
    add     r1, r4, #0x600
    mov     r2, #0xc40
    mov     r3, #0
    bl      func_0270379C

@loc_0273225C:
    mov     r5, r0

@loc_02732260:
    cmp     r5, #2
    addeq   sp, sp, #8
    ldmeqfd sp!, {r4, r5, r6, pc}
    cmp     r5, #3
    beq     @loc_027322B4
    cmp     r5, #6
    bne     @loc_027322B4
    mov     r0, #0xc
    bl      func_02165A4C
    add     r0, r4, #0x1200
    ldrsh   r0, [r0, #0xda]
    ldr     r3, =0x34A
    mov     r2, #0
    cmp     r0, #5
    addeq   r0, r4, #0x2e0
    addeq   r1, r0, #0x1000
    movne   r1, #0
    mov     r0, #1
    bl      func_021659B4
    add     sp, sp, #8
    ldmfd   sp!, {r4, r5, r6, pc}

@loc_027322B4:
    mov     r0, #0xb
    bl      func_02165A4C
    add     r0, r4, #0x1200
    ldrsh   r0, [r0, #0xda]
    mov     r2, #0
    cmp     r0, #5
    addeq   r0, r4, #0x2e0
    addeq   r1, r0, #0x1000
    mov     r0, #7
    movne   r1, #0
    add     r3, r0, #0x34c
    bl      func_021659B4
    add     sp, sp, #8
    ldmfd   sp!, {r4, r5, r6, pc}

@loc_027322EC:
    mov     r0, #0xc
    bl      func_02165A4C
    add     r0, r4, #0x1200
    ldrsh   r0, [r0, #0xda]
    ldr     r3, =0x372
    mov     r2, #0
    cmp     r0, #5
    addeq   r0, r4, #0x2e0
    addeq   r1, r0, #0x1000
    movne   r1, #0
    mov     r0, #1
    bl      func_021659B4
    add     sp, sp, #8
    ldmfd   sp!, {r4, r5, r6, pc}

@loc_02732324:
    mov     r0, #0xb
    bl      func_02165A4C
    add     r0, r4, #0x1200
    ldrsh   r0, [r0, #0xda]
    mov     r2, #0
    mov     r3, #0x378
    cmp     r0, #5
    addeq   r0, r4, #0x2e0
    addeq   r1, r0, #0x1000
    movne   r1, #0
    mov     r0, #7
    bl      func_021659B4
    add     sp, sp, #8
    ldmfd   sp!, {r4, r5, r6, pc}

@loc_0273235C:
    mov     r0, #0xb
    bl      func_02165A4C
    add     r0, r4, #0x1200
    ldrsh   r0, [r0, #0xda]
    mov     r2, #0
    cmp     r0, #5
    addeq   r0, r4, #0x2e0
    addeq   r1, r0, #0x1000
    mov     r0, #7
    movne   r1, #0
    rsb     r3, r0, #0x38c
    bl      func_021659B4
    add     sp, sp, #8
    ldmfd   sp!, {r4, r5, r6, pc}
}


asm void func_027323A8(void)
{
}
