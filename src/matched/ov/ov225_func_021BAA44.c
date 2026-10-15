/*
 * function: MANUAL_COMMON_SetListWorkBgMode
 * address: 0x021BAA44
 * packet: pkt_ov225_021BAA44
 * region: ov225
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BG_SYS_SetFlagField06 0x02041B6C arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
extern void BG_SYS_SetFlagField06(u32);
struct Work;

void MANUAL_COMMON_SetListWorkBgMode(struct Work *a0) { BG_SYS_SetFlagField06(4); }
