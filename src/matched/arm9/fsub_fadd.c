/*
 * unit:     yes
 * function: __fadd, __fsub
 * address:  0x0209C95C
 * packet:   pkt_0209C95C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT*
 *
 * Filed as manifest kind `runtime` (tools/match.py): each function is
 * compared at its layout/runtime_arm9.txt row, and worklist.py keeps the
 * rows out of the game figure.
 *
 * __fsub's third instruction is `bmi #0x209c968`, a backward displacement
 * branch into the interior of __fadd after flipping the sign bit of the
 * second operand -- the exact "branch into another entry's interior" shape
 * documented for this library, so the two are filed as one asm function;
 * __fsub is kept as a label inside it for documentation.  0x0209C95C is
 * the add (equal signs fall into `adds r0, r0, r1' at 0x0209C9B4) and
 * 0x0209CB8C the subtract (`subs r0, r0, r1' at 0x0209CBE8); the two names
 * were filed the other way round until 2026-09-28.
 *
 * Verified with:
 *   python tools/match.py one --src <this file> --func __fadd --addr
 *     0x0209C95C --cc 1.1p1 --arm
 */

asm void __fadd(void)
{
__fadd:
    eors r2, r0, r1
    eormi r1, r1, #0x80000000
    bmi L_0209CB98
L_0209C968:
    subs ip, r0, r1
    sublo r0, r0, ip
    addlo r1, r1, ip
    mov r2, #0x80000000
    mov r3, r0, lsr #0x17
    orr r0, r2, r0, lsl #8
    ands ip, r3, #0xff
    cmpne ip, #0xff
    beq L_0209C9FC
    mov ip, r1, lsr #0x17
    orr r1, r2, r1, lsl #8
    ands r2, ip, #0xff
    beq L_0209CA3C
L_0209C99C:
    subs ip, r3, ip
    beq L_0209C9B4
    rsb r2, ip, #0x20
    movs r2, r1, lsl r2
    mov r1, r1, lsr ip
    orrne r1, r1, #1
L_0209C9B4:
    adds r0, r0, r1
    blo L_0209C9D4
    and r1, r0, #1
    orr r0, r1, r0, rrx
    add r3, r3, #1
    and r2, r3, #0xff
    cmp r2, #0xff
    beq L_0209CB44
L_0209C9D4:
    ands r1, r0, #0xff
    add r0, r0, r0
    mov r0, r0, lsr #9
    orr r0, r0, r3, lsl #23
    tst r1, #0x80
    bxeq lr
    ands r1, r1, #0x7f
    andeqs r1, r0, #1
    addne r0, r0, #1
    bx lr
L_0209C9FC:
    cmp r3, #0x100
    movge r2, #0x80000000
    movlt r2, #0
    ands r3, r3, #0xff
    beq L_0209CA60
    movs r0, r0, lsl #1
    bne L_0209CB70
    mov ip, r1, lsr #0x17
    mov r1, r1, lsl #9
    ands ip, ip, #0xff
    beq L_0209CB64
    cmp ip, #0xff
    blt L_0209CB64
    cmp r1, #0
    beq L_0209CB64
    b L_0209CB70
L_0209CA3C:
    cmp r3, #0x100
    movge r2, #0x80000000
    movlt r2, #0
    and r3, r3, #0xff
    ands ip, ip, #0xff
    beq L_0209CABC
L_0209CA54:
    movs r1, r1, lsl #1
    bne L_0209CB70
    b L_0209CB64
L_0209CA60:
    movs r0, r0, lsl #1
    beq L_0209CA98
    mov r3, #1
    mov r0, r0, lsr #1
    mov ip, r1, lsr #0x17
    mov r1, r1, lsl #8
    ands ip, ip, #0xff
    beq L_0209CABC
    cmp ip, #0xff
    beq L_0209CA54
    orr r1, r1, #0x80000000
    orr r3, r3, r2, lsr #23
    orr ip, ip, r2, lsr #23
    b L_0209C99C
L_0209CA98:
    mov r3, r1, lsr #0x17
    mov r0, r1, lsl #9
    ands r3, r3, #0xff
    beq L_0209CB24
    cmp r3, #0xff
    blt L_0209CB24
    cmp r0, #0
    beq L_0209CB64
    b L_0209CB5C
L_0209CABC:
    movs r1, r1, lsl #1
    beq L_0209CB2C
    mov r1, r1, lsr #1
    mov ip, #1
    orr r3, r3, r2, lsr #23
    orr ip, ip, r2, lsr #23
    cmp r0, #0
    bmi L_0209C99C
    adds r0, r0, r1
    blo L_0209CAF0
    and r1, r0, #1
    orr r0, r1, r0, rrx
    add ip, ip, #1
L_0209CAF0:
    cmp r0, #0
    subge ip, ip, #1
    ands r1, r0, #0xff
    add r0, r0, r0
    mov r0, r0, lsr #9
    orr r0, r0, ip, lsl #23
    bxeq lr
    tst r1, #0x80
    bxeq lr
    ands r1, r1, #0x7f
    andeqs r1, r0, #1
    addne r0, r0, #1
    bx lr
L_0209CB24:
    mov r0, r1
    bx lr
L_0209CB2C:
    cmp r0, #0
    subges r3, r3, #1
    add r0, r0, r0
    orr r0, r2, r0, lsr #9
    orr r0, r0, r3, lsl #23
    bx lr
L_0209CB44:
    cmp r3, #0x100
    movge r2, #0x80000000
    movlt r2, #0
    mov r0, #0xff000000
    orr r0, r2, r0, lsr #1
    bx lr
L_0209CB5C:
    mvn r0, #0x80000000
    bx lr
L_0209CB64:
    mov r0, #0xff000000
    orr r0, r2, r0, lsr #1
    bx lr
L_0209CB70:
    mvn r0, #0x80000000
    bx lr
    mvn r0, #0x80000000
    bx lr
    eor r0, r0, r1
    eor r1, r0, r1
    eor r0, r0, r1
__fsub:
    eors r2, r0, r1
    eormi r1, r1, #0x80000000
    bmi L_0209C968
L_0209CB98:
    subs ip, r0, r1
    eorlo ip, ip, #0x80000000
    sublo r0, r0, ip
    addlo r1, r1, ip
    mov r2, #0x80000000
    mov r3, r0, lsr #0x17
    orr r0, r2, r0, lsl #8
    ands ip, r3, #0xff
    cmpne ip, #0xff
    beq L_0209CCB4
    mov ip, r1, lsr #0x17
    orr r1, r2, r1, lsl #8
    ands r2, ip, #0xff
    beq L_0209CCF4
L_0209CBD0:
    subs ip, r3, ip
    beq L_0209CC18
    rsb r2, ip, #0x20
    movs r2, r1, lsl r2
    mov r1, r1, lsr ip
    orrne r1, r1, #1
    subs r0, r0, r1
    bpl L_0209CC5C
    ands r1, r0, #0xff
    add r0, r0, r0
    mov r0, r0, lsr #9
    orr r0, r0, r3, lsl #23
    tst r1, #0x80
    bxeq lr
    ands r1, r1, #0x7f
    andeqs r1, r0, #1
    addne r0, r0, #1
    bx lr
L_0209CC18:
    subs r0, r0, r1
    beq L_0209CDC0
    mov r2, r3, lsl #0x17
    and r2, r2, #0x80000000
    bic r3, r3, #0x100
    clz ip, r0
    movs r0, r0, lsl ip
    sub r3, r3, ip
    cmp r3, #0
    bgt L_0209CC4C
    rsb r3, r3, #9
    orr r0, r2, r0, lsr r3
    bx lr
L_0209CC4C:
    add r0, r0, r0
    orr r0, r2, r0, lsr #9
    orr r0, r0, r3, lsl #23
    bx lr
L_0209CC5C:
    mov r2, r3, lsl #0x17
    and r2, r2, #0x80000000
    bic r3, r3, #0x100
    clz ip, r0
    movs r0, r0, lsl ip
    sub r3, r3, ip
    cmp r3, #0
    bgt L_0209CC88
    rsb r3, r3, #9
    orr r0, r2, r0, lsr r3
    bx lr
L_0209CC88:
    ands r1, r0, #0xff
    add r0, r0, r0
    orr r0, r2, r0, lsr #9
    orr r0, r0, r3, lsl #23
    bxeq lr
    tst r1, #0x80
    bxeq lr
    ands r1, r1, #0x7f
    andeqs r1, r0, #1
    addne r0, r0, #1
    bx lr
L_0209CCB4:
    cmp r3, #0x100
    movge r2, #0x80000000
    movlt r2, #0
    ands r3, r3, #0xff
    beq L_0209CD1C
    movs r0, r0, lsl #1
    bne L_0209CDF4
    mov ip, r1, lsr #0x17
    mov r1, r1, lsl #9
    ands ip, ip, #0xff
    beq L_0209CDE8
    cmp ip, #0xff
    blt L_0209CDE8
    cmp r1, #0
    beq L_0209CDFC
    b L_0209CDF4
L_0209CCF4:
    cmp ip, #0x100
    movge r2, #0x80000000
    movlt r2, #0
    and r3, r3, #0xff
    ands ip, ip, #0xff
    beq L_0209CD84
L_0209CD0C:
    eor r2, r2, #0x80000000
    movs r1, r1, lsl #1
    bne L_0209CDF4
    b L_0209CDE8
L_0209CD1C:
    movs r0, r0, lsl #1
    beq L_0209CD54
    mov r0, r0, lsr #1
    mov r3, #1
    mov ip, r1, lsr #0x17
    mov r1, r1, lsl #8
    ands ip, ip, #0xff
    beq L_0209CD84
    cmp ip, #0xff
    beq L_0209CD0C
    orr r1, r1, #0x80000000
    orr r3, r3, r2, lsr #23
    orr ip, ip, r2, lsr #23
    b L_0209CBD0
L_0209CD54:
    mov r3, r1, lsr #0x17
    mov r0, r1, lsl #9
    ands r2, r3, #0xff
    beq L_0209CD78
    cmp r2, #0xff
    blt L_0209CDA0
    cmp r0, #0
    bne L_0209CDE0
    b L_0209CDE8
L_0209CD78:
    cmp r0, #0
    beq L_0209CDC0
    b L_0209CDA0
L_0209CD84:
    movs r1, r1, lsl #1
    beq L_0209CDA8
    mov r1, r1, lsr #1
    mov ip, #1
    orr ip, ip, r2, lsr #23
    orr r3, r3, r2, lsr #23
    b L_0209CBD0
L_0209CDA0:
    mov r0, r1
    bx lr
L_0209CDA8:
    cmp r0, #0
    subges r3, r3, #1
    add r0, r0, r0
    orr r0, r2, r0, lsr #9
    orr r0, r0, r3, lsl #23
    bx lr
L_0209CDC0:
    mov r0, #0
    bx lr
    cmp r0, #0
    subges r3, r3, #1
    add r0, r0, r0
    mov r0, r0, lsr #9
    orr r0, r0, r3, lsl #23
    bx lr
L_0209CDE0:
    mvn r0, #0x80000000
    bx lr
L_0209CDE8:
    mov r0, #0xff000000
    orr r0, r2, r0, lsr #1
    bx lr
L_0209CDF4:
    mvn r0, #0x80000000
    bx lr
L_0209CDFC:
    mvn r0, #0x80000000
    bx lr
    eor r0, r0, r1
    eor r1, r0, r1
    eor r0, r0, r1
}
