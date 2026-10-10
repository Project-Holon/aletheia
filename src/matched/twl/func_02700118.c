/*
 * function: func_02700118
 * address: 0x02700118
 * packet: pkt_twl_02700118
 * region: twl
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: arm
 * status: EXACT*
 *
 * Function with no listing label, matched inside src/game/twl/unit_02700078.c and filed here.
 *
 * symbols:
 *   data_02732FC8 0x02732FC8 data twl a2
 */

typedef unsigned int u32;
asm void func_02700118(u32 a0);
extern u32 data_02732FC8[];

asm void func_02700118(u32 a0) {
    ldr r1, =data_02732FC8
    str r0, [r1, #0x60]
    bx lr
}
