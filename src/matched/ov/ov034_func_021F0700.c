/*
 * function: func_021F0700
 * address: 0x021F0700
 * packet: pkt_ov034_021F0700
 * region: ov034
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0201D83C 0x0201D83C thumb
 *   func_020452E8 0x020452E8 arm
 *   func_0201C4C0 0x0201C4C0 thumb
 */
#include "../include/Obj13077.h"
extern void func_0201D83C(void *);
struct Descriptor;
struct PrintSys;
extern void func_020452E8(struct Descriptor *d);
extern void func_0201C4C0(struct PrintSys *p);
void func_021F0700(char *p) { unsigned i; func_0201D83C(((struct Obj13077 *)p)->f4C); for(i=0;i<8;i++) func_020452E8(*(void **)(p+i*8+0xc)); func_0201C4C0(((struct Obj13077 *)p)->f8); }
