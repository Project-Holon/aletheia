/*
 * function: func_021BA9AC
 * address: 0x021BA9AC
 * packet: pkt_ov213_021BA9AC
 * region: ov213
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020480E4 0x020480E4 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
struct Ctx;
extern void func_020480E4(struct Ctx *,u32);
void func_021BA9AC(char *p) { func_020480E4(*(struct Ctx **)(p+8),*(u16 *)(p+12)); *(u8 *)(p+15)=0; *(u8 *)(p+14)=0; }
