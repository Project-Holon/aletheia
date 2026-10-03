/*
 * unit: no
 * function: func_021BA558
 * address: 0x021BA558
 * packet: pkt_ov181_021BA558
 * region: ov181
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02045770 0x02045770 arm
 *   func_021BA4AC 0x021BA4AC thumb ov181
 */
typedef unsigned char u8;typedef unsigned short u16;typedef unsigned int u32;
struct Descriptor;
extern void *func_02045770(struct Descriptor *);
extern void func_021BA4AC(char *,u8 *,void *,int);
void func_021BA558(char *p,u8 *q){if(q[9]==0)func_021BA4AC(p,q,func_02045770(*(struct Descriptor **)(p+0x2c4)),192);else func_021BA4AC(p,q,func_02045770(*(struct Descriptor **)(p+0x2c4)),194);}
