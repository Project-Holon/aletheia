/*
 * function: func_021B6C84
 * address: 0x021B6C84
 * packet: pkt_ov173_021B6C84
 * region: ov173
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02045EC0 0x02045EC0 arm
 *   func_0201EFA4 0x0201EFA4 thumb
 *   func_0201F250 0x0201F250 thumb
 *   func_02045808 0x02045808 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct MsgBank;
struct U16Vec;
struct WordSet;
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void func_0201EFA4(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern void func_02045808(struct U16Vec *vec);
void func_021B6C84(char *p,u32 idx,u32 a,u32 b,u8 c) { void *s; s=func_02045EC0(*(void **)(p+0x44),idx); func_0201EFA4(*(void **)(p+0x48),0,a,b,c,1); func_0201F250(*(void **)(p+0x48),*(void **)(p+0x4c),s); func_02045808(s); }
