/*
 * function: func_021FC5E8
 * address: 0x021FC5E8
 * packet: pkt_ov132_021FC5E8
 * region: ov132
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0201134C 0x0201134C thumb
 *   func_021F969C 0x021F969C thumb ov132
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Cursor; struct Comm;
extern u32 func_0201134C(struct Cursor *);
extern int func_021F969C(char *,u16,u16,u16);
int func_021FC5E8(int unused,char *p) { char *o; u32 a,b,c; o=*(char **)p; a=func_0201134C(*(struct Cursor **)(p+4)); b=func_0201134C(*(struct Cursor **)(p+4)); c=func_0201134C(*(struct Cursor **)(p+4)); func_021F969C(*(char **)(o+0x34),a,b,c); return 0; }
