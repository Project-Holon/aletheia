/*
 * function: func_021EBDF4
 * address: 0x021EBDF4
 * packet: pkt_ov170_021EBDF4
 * region: ov170
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021DC9D8 0x021DC9D8 thumb ov170
 *   func_0204A48C 0x0204A48C arm
 *   d_021EFD64 0x021EFD64 data a4
 */
typedef struct {unsigned a,b,c,d,e,f,g;} Template; extern const Template d_021EFD64;extern unsigned func_021DC9D8(void);extern void func_0204A48C(Template *,unsigned,unsigned);
void func_021EBDF4(void){Template t=d_021EFD64;unsigned n=func_021DC9D8();func_0204A48C(&t,n,76);}
