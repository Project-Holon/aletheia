/*
 * function: func_021FC22C
 * address: 0x021FC22C
 * packet: pkt_ov132_021FC22C
 * region: ov132
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0201134C 0x0201134C thumb
 *   func_021F9DD4 0x021F9DD4 thumb ov132
 *   func_021F9DDC 0x021F9DDC thumb ov132
 *   func_021F6EE4 0x021F6EE4 thumb ov112
 *   func_021F9DE8 0x021F9DE8 thumb ov132
 *   func_021F95E8 0x021F95E8 thumb ov132
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Cursor; struct Comm;
extern u32 func_0201134C(struct Cursor *);
extern void *func_021F9DD4(void *);
extern void *func_021F9DDC(void *,u8);
extern void func_021F6EE4(void *,u8 *);
extern void func_021F9DE8(void *,void *,u8);
extern void func_021F95E8(char *p);
int func_021FC22C(int unused,char *p) { char *o; u32 a; void *ctx; o=*(char **)p; a=func_0201134C(*(struct Cursor **)(p+4)); ctx=func_021F9DD4(*(void **)(o+0x34)); func_021F6EE4(ctx,func_021F9DDC(*(void **)(o+0x34),a)); func_021F9DE8(*(void **)(o+0x34),0,a); func_021F95E8(*(void **)(o+0x34)); return 0; }
