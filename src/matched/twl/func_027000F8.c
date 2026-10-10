/*
 * function: func_027000F8
 * address: 0x027000F8
 * packet: pkt_twl_027000F8
 * region: twl
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: arm
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/twl/unit_02700078.c and filed here.
 *
 * symbols:
 *   data_02732FC8 0x02732FC8 data twl a2
 */

typedef unsigned int u32;
asm void func_027000F8(u32 a0);
extern u32 data_02732FC8[];

asm void func_027000F8(u32 a0) {
    ldr r1, =data_02732FC8
    str r0, [r1, #0x58]
    bx lr
}
