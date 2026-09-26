/*
 * function: func_02701A60
 * address:  0x02701A60
 * packet:   twl_sys
 * region:   twl
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   DIFF
 *
 * notes:
 *   CW inline assembler does not support the blt mnemonic (parser conflict with bl).
 *   C decompilation produces reordered ldrb r1, [r0]; ldrb r2, [r0, #1] byte reads.
 *
 * symbols:
 *   func_02088610  0x02088610  code twl a2
 */

typedef unsigned int u32;
typedef unsigned char u8;
typedef signed int s32;

extern s32 func_02088610(u32, u32, u32);

void func_02701A60(const u8 *ptr) {
    u32 r1, r2, r3, r0, r6, r5, r4;
    r1 = ptr[1];
    r2 = ptr[0];
    r3 = ptr[2];
    r0 = r1 << 8;
    r0 |= r2 << 16;
    r6 = r3 | r0;
    r5 = 0x15;
    r4 = 0;
    while (func_02088610(r5, r6, r4) < 0) {
        (void)0;
    }
}
