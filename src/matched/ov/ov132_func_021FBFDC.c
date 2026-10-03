/*
 * function: func_021FBFDC
 * address: 0x021FBFDC
 * packet: pkt_ov132_021FBFDC
 * region: ov132
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_0201134C 0x0201134C thumb
 *   func_021F9DC0 0x021F9DC0 thumb ov132
 *   func_021F9DC4 0x021F9DC4 thumb ov132
 *   func_021F9F58 0x021F9F58 thumb ov132
 *   func_021F9DCC 0x021F9DCC thumb ov132
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Cursor; struct Comm;
extern u32 func_0201134C(struct Cursor *);
extern void *func_021F9DC0(void *);
extern void *func_021F9DC4(void *,u8);
extern void func_021F9F58(u8 *,u8 *);
extern void func_021F9DCC(void *p, void *v, u32 i);
int func_021FBFDC(int unused,char *p) { char *o; u32 a; void *ctx; o=*(char **)p; a=func_0201134C(*(struct Cursor **)(p+4)); ctx=func_021F9DC0(*(void **)(o+0x34)); func_021F9F58(ctx,func_021F9DC4(*(void **)(o+0x34),a)); func_021F9DCC(*(void **)(o+0x34),0,(u8)a); return 0; }
