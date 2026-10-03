/*
 * function: func_021FC53C
 * address: 0x021FC53C
 * packet: pkt_ov132_021FC53C
 * region: ov132
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0201134C 0x0201134C thumb
 *   func_021F93D8 0x021F93D8 thumb ov132
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Cursor; struct Comm;
extern u32 func_0201134C(struct Cursor *);
extern void func_021F93D8(u8 *,u16,u32);
int func_021FC53C(int unused,char *p) { char *o; u32 a,b; o=*(char **)p; a=func_0201134C(*(struct Cursor **)(p+4)); b=func_0201134C(*(struct Cursor **)(p+4)); func_021F93D8(*(u8 **)(o+0x34),a,b); return 0; }
