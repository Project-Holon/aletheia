/*
 * function: func_021C4274
 * address: 0x021C4274
 * packet: pkt_ov127_021C4274
 * region: ov127
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0204B908 0x0204B908 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
/* Callee and its forwarding target read only r0/r1; legacy r2/r3 inputs are unused. */
extern void func_0204B908(u32,u32);
void func_021C4274(char *p,u32 a) { func_0204B908(*(u32 *)(p+4),a); }
