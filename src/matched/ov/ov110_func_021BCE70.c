/*
 * function: func_021BCE70
 * address: 0x021BCE70
 * packet: pkt_ov110_021BCE70
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * Extent ends in two-byte alignment padding at 0x021BCE9E.
 * symbols:
 *   func_021BF6DC 0x021BF6DC thumb ov110
 *   func_021BCFF0 0x021BCFF0 thumb ov110
 *   func_020282A4 0x020282A4 thumb
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u8 func_021BF6DC(u8 *);
extern u32 func_021BCFF0(char *,u32);
struct Obj;
extern void func_020282A4(struct Obj *obj);
int func_021BCE70(char *p) { int result; if (func_021BF6DC(*(u8 **)(p+4))==1) { result=1; if (func_021BCFF0(p,1)) { func_020282A4(*(void **)(p+0x68)); return result; } } else { return 1; } return 0; }
