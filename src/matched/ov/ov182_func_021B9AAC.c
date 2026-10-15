/*
 * function: THE_END_GRAPHIC_RefreshDisplay
 * address: 0x021B9AAC
 * packet: pkt_ov182_021B9AAC
 * region: ov182
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BG_SYS_Update 0x020419E4 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long long u64;
extern void BG_SYS_Update(void);
void THE_END_GRAPHIC_RefreshDisplay(void *a0) { BG_SYS_Update(); }
