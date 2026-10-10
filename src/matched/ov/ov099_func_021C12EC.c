/*
 * function: func_021C12EC
 * address: 0x021C12EC
 * packet: pkt_ov099_021C12EC
 * region: ov099
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 *
 * Function with no listing label, matched inside src/game/ov099/unit_021BF050.c and filed here.
 */

typedef unsigned char  u8;
typedef unsigned int u32;
u32 func_021C12EC(int i, u8 *p);

u32 func_021C12EC(int i, u8 *p) { u8 *q = *(u8 **)(p + 0x248); return *(u32 *)(q + i * 4 + 0x14); }
