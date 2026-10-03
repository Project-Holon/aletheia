/*
 * function: func_021B6250
 * address: 0x021B6250
 * packet: pkt_ov173_021B6250
 * region: ov173
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021B6460 0x021B6460 thumb ov173
 *   func_02031140 0x02031140 arm
 *   func_0201D83C 0x0201D83C thumb
 *   func_020315D4 0x020315D4 arm
 *   func_020306F0 0x020306F0 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void func_021B6460(char *);
extern void func_02031140(void *);
extern void func_0201D83C(void *);
extern void func_020315D4(void *);
extern void func_020306F0(void *);
int func_021B6250(void *p,u32 a,u32 b,char *ctx) { func_021B6460(ctx); func_02031140(*(void **)(ctx+0x64)); func_0201D83C(*(void **)(ctx+0x60)); func_020315D4(p); func_020306F0((void *)79); return 1; }
