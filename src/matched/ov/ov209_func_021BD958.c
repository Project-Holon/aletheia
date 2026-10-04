/*
 * function: func_021BD958
 * address: 0x021BD958
 * packet: pkt_ov209_021BD958
 * region: ov209
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * prototype: outgoing space argument is loaded by ldrh at 021BD966; callee extern uses u16 for the observed bits.
 * symbols:
 *   func_0204B454 0x0204B454 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed short s16;struct Actor;typedef struct PtS {s16 x,y;} PtS;extern void func_0204B454(struct Actor *,PtS *,unsigned int);
void func_021BD958(char *p,u32 idx,s16 *x,s16 *y,u16 space) {PtS point;func_0204B454(*(struct Actor **)(p+idx*4+0xa74),&point,space);*x=point.x;*y=point.y;}
