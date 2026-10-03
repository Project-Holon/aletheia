/*
 * function: func_021D7C10
 * address: 0x021D7C10
 * packet: pkt_ov120_021D7C10
 * region: ov120
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02051C88 0x02051C88 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int     s32;
struct Ctx;
extern s32 func_02051C88(struct Ctx *c);
int func_021D7C10(char *p) { return func_02051C88(*(void **)(p+8)); }
