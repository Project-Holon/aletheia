/*
 * function: GIMMICK39_UnlockLane
 * address: 0x021F4184
 * packet: pkt_ov039_021F4184
 * region: ov039
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
void GIMMICK39_UnlockLane(u8 *p, u8 i) { int zero = 0; int valid = 0; if (i == 1) { valid = 1; i = zero; } else if (i == 2) { valid = 1; i = 1; } if (valid) *(u16 *)(p + i * 2 + 0x14) = 1; }
