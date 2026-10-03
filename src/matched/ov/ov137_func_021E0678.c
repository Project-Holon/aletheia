/*
 * function: func_021E0678
 * address: 0x021E0678
 * packet: pkt_ov137_021E0678
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * note: original narrows the second call argument with lsls/lsrs #16 at 021E0682/021E0686, so this caller's extern uses u16.
 * symbols:
 *   func_020480E4 0x020480E4 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Ctx;
extern void func_020480E4(struct Ctx *,u16);
void func_021E0678(char *p) { func_020480E4(*(struct Ctx **)(p+0xaf4),*(u32 *)(p+0xda4)); }
