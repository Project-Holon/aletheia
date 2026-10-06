/*
 * function: func_021B7658
 * address: 0x021B7658
 * packet: pkt_ov173_021B7658
 * region: ov173
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0204A48C 0x0204A48C arm
 *   func_0204B100 0x0204B100 arm
 *   func_0204B270 0x0204B270 arm
 *   func_020434DC 0x020434DC arm
 *   func_02043598 0x02043598 arm
 *   d_021B820C 0x021B820C data a4
 *   d_021B8250 0x021B8250 data a4
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Cfg;struct Bank;
extern const struct Cfg d_021B820C;
extern u8 d_021B8250[];
extern void func_0204A48C(const struct Cfg *,u32,u32);
extern struct Bank *func_0204B100(int,u8,u32);
extern void func_0204B270(struct Bank *);
extern void func_020434DC(u32,u32);
extern void func_02043598(u32,u32);
typedef enum { OFFSET=14 } Offset;
void func_021B7658(u8 *p, void *a1) {Offset off;struct Bank *b;func_0204A48C(&d_021B820C,(u32)d_021B8250,79);off=OFFSET;b=func_0204B100(14,0,79);off+=242;*(struct Bank **)(p+off)=b;func_0204B270(b);func_020434DC(16,1);func_02043598(16,1);}
