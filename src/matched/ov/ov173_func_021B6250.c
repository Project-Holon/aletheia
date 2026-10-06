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
#include "../include/Obj00362.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void func_021B6460(char *);
struct S02031140;
struct S020315D4;
extern void func_02031140(struct S02031140 *p);
extern u32 func_0201D83C(void *ptr);
extern void func_020315D4(struct S020315D4 *p);
extern void func_020306F0(unsigned int heap);
int func_021B6250(void *p,u32 a,u32 b,char *ctx) { func_021B6460(ctx); func_02031140(((struct Obj00362 *)ctx)->f64); func_0201D83C(((struct Obj00362 *)ctx)->f60); func_020315D4(p); func_020306F0(79); return 1; }
