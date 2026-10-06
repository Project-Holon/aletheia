/*
 * function: func_02184360
 * address: 0x02184360
 * packet: pkt_ov168_02184360
 * region: ov168
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_020456F8 0x020456F8 arm
 *   func_020452E8 0x020452E8 arm
 *   func_02045C04 0x02045C04 arm
 *   func_0201D83C 0x0201D83C thumb
 */
#include "../include/Obj14260.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Bank; struct CharBuf; struct Descriptor; struct Rec; struct Node; struct Blk37;
extern void *func_02045770(struct Descriptor *p);
extern void func_02043B5C(struct CharBuf *,u8);
extern void func_020456F8(struct Descriptor *);
extern u32 func_020452E8(struct Descriptor *d);
extern u32 func_02045C04(struct Rec *rec);
extern u32 func_0201D83C(void *ptr);
void func_02184360(char *p) { int i; for(i=0;i<3;i++) {func_02043B5C(func_02045770(*(void **)(p+i*4)),0);func_020456F8(*(struct Descriptor **)(p+i*4));func_020452E8(*(struct Descriptor **)(p+i*4));} func_02045C04(*(struct Rec * *)&((struct Obj14260 *)p)->fC);func_0201D83C(((struct Obj14260 *)p)->f10); }
