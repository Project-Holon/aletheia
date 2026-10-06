/*
 * function: func_021E1098
 * address: 0x021E1098
 * packet: pkt_ov119_021E1098
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0202F038 0x0202F038 thumb
 *   func_020456F8 0x020456F8 arm
 *   func_02041B6C 0x02041B6C arm
 *   func_0201F7A8 0x0201F7A8 thumb
 *   func_020452E8 0x020452E8 arm
 */
#include "../include/Obj00001.h"
typedef unsigned char  u8;
struct Descriptor;
extern void func_0202F038(u8 *p);
extern void func_020456F8(struct Descriptor *d);
typedef unsigned int   u32;
extern void func_02041B6C(u32 bit);
extern void func_0201F7A8(void *desc, u32 kind);
extern u32 func_020452E8(struct Descriptor *d);
void func_021E1098(char *p) { if(*(int *)&((struct Obj00001 *)p)->f5F0) {func_0202F038((u8 *)(*(int *)&((struct Obj00001 *)p)->f5F0));*(int *)&((struct Obj00001 *)p)->f5F0=0;} if(*(int *)&((struct Obj00001 *)p)->f71C) {func_020456F8((struct Descriptor *)(*(int *)&((struct Obj00001 *)p)->f71C));func_02041B6C(6);func_0201F7A8((void *)(*(int *)&((struct Obj00001 *)p)->f71C),2);func_020452E8((struct Descriptor *)(*(int *)&((struct Obj00001 *)p)->f71C));*(int *)&((struct Obj00001 *)p)->f71C=0;} }
