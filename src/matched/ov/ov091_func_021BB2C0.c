/*
 * function: func_021BB2C0
 * address: 0x021BB2C0
 * packet: pkt_ov091_021BB2C0
 * region: ov091
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_021BAAE4 0x021BAAE4 thumb ov091
 */
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;
struct Descriptor;
extern void *func_02045770(struct Descriptor *p);
struct CharBuf;
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_021BAAE4(u8 *,u8 *,int);
void func_021BB2C0(u8 *a,u8 *s) {func_02043B5C((struct CharBuf *)((u32)func_02045770((struct Descriptor *)*(u32 *)(s+32))),0);func_021BAAE4(a,s,0);}
