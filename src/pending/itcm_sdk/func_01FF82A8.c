/*
 * function: func_01FF82A8
 * address:  0x01FF82A8
 * packet:   itcm
 * region:   arm9_autoload0_ITCM
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */

typedef unsigned char u8;
typedef unsigned int u32;
typedef int BOOL;

asm BOOL func_01FF82A8(const u8 *src, u32 len, const void *digest)
{
    PUSH    {R3, R4, R5, R6, R7, LR}
    SUB     SP, #0xB8
    MOV     R4, R1
    MOV     R5, R0
    MOV     R7, R2
    ADD     R0, SP, #0x54
    MOV     R3, #0x60
    ADD     R3, R0
    MOV     R2, #0
    STR     R2, [R3]
    SWI     0x24
    LDR     R0, =0x01FF8328
    ADD     R1, SP, #0x14
    MOV     R2, #0x0
    MOV     R3, #0x36
@0:
    LDRB    R6, [R0, R2]
    EOR     R6, R3
    STRB    R6, [R1, R2]
    ADD     R2, R2, #0x1
    CMP     R2, #0x40
    BLT     @0
    ADD     R0, SP, #0x54
    SWI     0x25
    ADD     R0, SP, #0x54
    MOV     R1, R5
    MOV     R2, R4
    SWI     0x25
    ADD     R0, SP, #0x0
    ADD     R1, SP, #0x54
    SWI     0x26
    ADD     R0, SP, #0x54
    MOV     R3, #0x60
    ADD     R3, R0
    MOV     R2, #0
    STR     R2, [R3]
    SWI     0x24
    LDR     R0, =0x01FF8328
    ADD     R1, SP, #0x14
    MOV     R2, #0x0
    MOV     R3, #0x5C
@1:
    LDRB    R6, [R0, R2]
    EOR     R6, R3
    STRB    R6, [R1, R2]
    ADD     R2, R2, #0x1
    CMP     R2, #0x40
    BLT     @1
    ADD     R0, SP, #0x54
    SWI     0x25
    ADD     R0, SP, #0x54
    ADD     R1, SP, #0x0
    MOV     R2, #0x14
    SWI     0x25
    ADD     R0, SP, #0x0
    ADD     R1, SP, #0x54
    SWI     0x26
    ADD     R0, SP, #0x0
    MOV     R1, R7
    SWI     0x28
    CMP     R0, #0x0
    BEQ     @2
    MOV     R0, #0x1
@2:
    ADD     SP, #0xB8
    POP     {R3, R4, R5, R6, R7, PC}
    NOP
    dcd 0xDEC00621
    dcd 0x3FCE98BA
    dcd 0x9DE392A6
    dcd 0x01EDF246
    dcd 0x08CCE376
    dcd 0xFA632356
    dcd 0xDFECD4CA
    dcd 0x3478629A
    dcd 0x3C636D8F
    dcd 0x92CA22FE
    dcd 0x23978820
    dcd 0xC2AECFD2
    dcd 0xFE8D6732
    dcd 0x986483CA
    dcd 0x373EFDAC
    dcd 0x24584687
}
