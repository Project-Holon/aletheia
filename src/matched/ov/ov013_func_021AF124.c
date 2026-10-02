/*
 * function: func_021AF124
 * address: 0x021AF124
 * packet: pkt_ov013_021AF124
 * region: ov013
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   d_021B3C80 0x021B3C80 data ov013 a4
 *   func_02073A60 0x02073A60 arm
 */
typedef unsigned char u8;
extern u8 *d_021B3C80;
struct A;
extern void func_02073A60(struct A *);
void func_021AF124(void) { func_02073A60((struct A *)(d_021B3C80 + 0x19B8)); }
