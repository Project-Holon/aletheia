/*
 * file:     unit_02731718_p04.c
 * unit:     yes
 * function: func_02732648, func_02732874, func_02732944, func_02732A64, func_02732A70
 * address:  0x02732648
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
 *   func_021657C8  0x021657C8  arm  ov009
 *   func_027028B0  0x027028B0  arm  twl
 *   func_02165A4C  0x02165A4C  arm  ov009
 *   func_02731F14  0x02731F14  arm  twl
 *   func_021659B4  0x021659B4  arm  ov009
 *   func_020862B8  0x020862B8  arm  twl
 *   func_02166804  0x02166804  arm  ov009
 *   func_02166358  0x02166358  arm  ov009
 *   func_027032E0  0x027032E0  arm  twl
 */
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;

typedef struct NetWork {
    u8 pad0[0x12da];
    u16 phase;
    u8 pad1[2];
    u8 state;
    u8 pad2[0x12e0 - 0x12df];
    u8 buf[0x130c - 0x12e0];
    u16 flags;
} NetWork;

typedef struct Pkt {
    u16 pad0;
    u16 kind;
    u16 pad1;
    short level;
    u32 len;
    u8 *data;
} Pkt;

extern NetWork *func_021657C8(void);
extern u32 func_027028B0(void);
extern void func_02165A4C(unsigned char phase);
extern void func_02731F14(void);
extern void func_021659B4(u32 a, void *b, u32 c, u32 d);
extern void func_020862B8(void *buf, u32 len);
extern void func_02166804(u8 v);
extern void func_02166358(u8 *a, u8 *b, u8 *c, u32 len);
extern int func_027032E0(void *cb, u8 flag, void *buf);
asm void func_02732648(void *arg);
asm void func_02732874(void *arg);
void func_02732944(Pkt *p);
asm void func_02732A64(void);
asm void func_02732A70(void);




asm void func_02732648(void *arg)
{
    stmdb   sp!, {r4, r5, r6, lr}
    mov     r6, r0
    mov     r4, #0
    bl      func_021657C8
    mov     r5, r0
    bl      func_027028B0
    ldrh    r1, [r6, #2]
    cmp     r1, #5
    addls   pc, pc, r1, lsl #2
    b       @loc_02732840

    b       @loc_02732688
    b       @loc_02732704
    b       @loc_02732840
    b       @loc_02732840
    b       @loc_02732840
    b       @loc_02732830

@loc_02732688:
    cmp     r0, #4
    bne     @loc_027326E0
    add     r0, r5, #0x1000
    ldrb    r0, [r0, #0x2de]
    cmp     r0, #0xc
    bne     @loc_027326B0
    mov     r0, #8
    bl      func_02165A4C
    bl      func_02731F14
    ldmfd   sp!, {r4, r5, r6, pc}

@loc_027326B0:
    ldrh    r2, [r6, #0xe]
    add     r1, r5, #0x4300
    mov     r0, #9
    strh    r2, [r1, #0xe4]
    bl      func_02165A4C
    add     r1, r5, #0x2e0
    mov     r0, r4
    ldr     r3, =0x436
    mov     r2, r0
    add     r1, r1, #0x1000
    bl      func_021659B4
    ldmfd   sp!, {r4, r5, r6, pc}

@loc_027326E0:
    mov     r0, #0xb
    bl      func_02165A4C
    add     r0, r5, #0x2e0
    add     r1, r0, #0x1000
    ldr     r3, =0x43C
    mov     r0, #7
    mov     r2, r4
    bl      func_021659B4
    ldmfd   sp!, {r4, r5, r6, pc}

@loc_02732704:
    ldrh    r0, [r6, #0x10]
    cmp     r0, #0xd
    addls   pc, pc, r0, lsl #2
    b       @loc_0273280C

    b       @loc_0273280C
    b       @loc_0273274C
    b       @loc_0273274C
    b       @loc_027327EC
    b       @loc_0273274C
    b       @loc_0273274C
    b       @loc_0273274C
    b       @loc_0273274C
    b       @loc_0273274C
    b       @loc_0273274C
    b       @loc_0273274C
    b       @loc_0273274C
    b       @loc_0273274C
    b       @loc_0273274C

@loc_0273274C:
    add     r0, r5, #0x1000
    ldrb    r0, [r0, #0x2de]
    sub     r0, r0, #8
    cmp     r0, #4
    addls   pc, pc, r0, lsl #2
    ldmfd   sp!, {r4, r5, r6, pc}

    b       @loc_02732784
    b       @loc_02732778
    b       @loc_02732778
    ldmfd   sp!, {r4, r5, r6, pc}
    b       @loc_027327E4

@loc_02732778:
    add     r0, r5, #0x1200
    mov     r1, #6
    strh    r1, [r0, #0xda]

@loc_02732784:
    add     r0, r5, #0x4300
    strh    r4, [r0, #0xe4]
    ldrh    r1, [r6, #0x10]
    cmp     r1, #0xb
    addls   pc, pc, r1, lsl #2
    b       @loc_027327E4

    b       @loc_027327E4
    b       @loc_027327E4
    b       @loc_027327E4
    b       @loc_027327E4
    b       @loc_027327E4
    b       @loc_027327CC
    b       @loc_027327E4
    b       @loc_027327DC
    b       @loc_027327E4
    b       @loc_027327E4
    b       @loc_027327D4
    b       @loc_027327D4

@loc_027327CC:
    mov     r1, #0xd
    b       @loc_027327E0

@loc_027327D4:
    mov     r1, #0xf
    b       @loc_027327E0

@loc_027327DC:
    mov     r1, #0x11

@loc_027327E0:
    strh    r1, [r0, #0xe6]

@loc_027327E4:
    bl      func_02731F14
    ldmfd   sp!, {r4, r5, r6, pc}

@loc_027327EC:
    add     r0, r5, #0x1000
    ldrb    r0, [r0, #0x2de]
    cmp     r0, #8
    ldmnefd sp!, {r4, r5, r6, pc}
    add     r0, r5, #0x4300
    strh    r4, [r0, #0xe4]
    bl      func_02731F14
    ldmfd   sp!, {r4, r5, r6, pc}

@loc_0273280C:
    mov     r0, #0xb
    bl      func_02165A4C
    add     r0, r5, #0x2e0
    add     r1, r0, #0x1000
    ldrh    r2, [r6, #0x10]
    ldr     r3, =0x481
    mov     r0, #7
    bl      func_021659B4
    ldmfd   sp!, {r4, r5, r6, pc}

@loc_02732830:
    mov     r0, #8
    bl      func_02165A4C
    bl      func_02731F14
    ldmfd   sp!, {r4, r5, r6, pc}

@loc_02732840:
    mov     r4, #0xb
    mov     r0, r4
    bl      func_02165A4C
    add     r0, r5, #0x2e0
    add     r1, r0, #0x1000
    rsb     r3, r4, #0x4a0
    mov     r0, #7
    mov     r2, #0
    bl      func_021659B4
    ldmfd   sp!, {r4, r5, r6, pc}
}




asm void func_02732874(void *arg)
{
    stmdb   sp!, {r4, r5, r6, lr}
    mov     r4, r0
    bl      func_021657C8
    ldrh    r1, [r4, #2]
    mov     r4, r0
    cmp     r1, #4
    addls   pc, pc, r1, lsl #2
    b       @loc_0273291C

    b       @loc_027328A8
    b       @loc_0273290C
    b       @loc_0273291C
    b       @loc_0273290C
    b       @loc_0273291C

@loc_027328A8:
    add     r0, r4, #0x1000
    ldrb    r0, [r0, #0x2de]
    cmp     r0, #0xc
    bne     @loc_027328C8
    mov     r0, #0xa
    bl      func_02165A4C
    bl      func_02731F14
    ldmfd   sp!, {r4, r5, r6, pc}

@loc_027328C8:
    cmp     r0, #0xd
    bne     @loc_027328D8
    bl      func_02731F14
    ldmfd   sp!, {r4, r5, r6, pc}

@loc_027328D8:
    mov     r5, #3
    mov     r0, r5
    add     r1, r4, #0x4300
    mov     r6, #0
    strh    r6, [r1, #0xe4]
    bl      func_02165A4C
    add     r1, r4, #0x2e0
    mov     r0, r6
    mov     r2, r6
    add     r1, r1, #0x1000
    rsb     r3, r5, #0x4c0
    bl      func_021659B4
    ldmfd   sp!, {r4, r5, r6, pc}

@loc_0273290C:
    mov     r0, #0xa
    bl      func_02165A4C
    bl      func_02731F14
    ldmfd   sp!, {r4, r5, r6, pc}

@loc_0273291C:
    mov     r0, #0xb
    bl      func_02165A4C
    add     r0, r4, #0x2e0
    ldr     r3, =0x4CF
    add     r1, r0, #0x1000
    mov     r0, #7
    mov     r2, #0
    bl      func_021659B4
    ldmfd   sp!, {r4, r5, r6, pc}
}



void func_02732944(Pkt *p)
{
    NetWork *w = func_021657C8();
    int lv;

    switch (p->kind) {
    case 0:
        if (w->state == 12) {
            func_02165A4C(8);
            func_02731F14();
            return;
        }
        switch (func_027032E0(func_02732648, (w->flags & 2) ? 1 : 0, w->buf)) {
        case 2:
            return;
        case 6:
            func_02165A4C(12);
            func_021659B4(1, w->buf, 0, 1286);
            return;
        case 3:
        default:
            func_02165A4C(11);
            func_021659B4(7, w->buf, 0, 1295);
            return;
        }
    case 11:
        func_020862B8(p->data, 0x620);
        lv = p->level;
        if (lv < 0) {
            lv = 0;
        }
        if (lv > 0x100) {
            lv = 0xff;
        }
        func_02166804(lv);
        func_02166358(p->data + 6, p->data, p->data + 14, p->len - 14);
        return;
    }
}


asm void func_02732A64(void)
{
}

asm void func_02732A70(void)
{
}
