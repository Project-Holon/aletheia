/*
 * function: func_021D6214
 * address: 0x021D6214
 * packet: pkt_ov131_021D6214
 * region: ov131
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_02045770 0x02045770 arm
 *   func_021D61B8 0x021D61B8 thumb ov131
 */
extern unsigned int func_02045770(unsigned int);
extern void func_021D61B8(unsigned char *,int,void *,int,unsigned short,unsigned short,unsigned short);
void func_021D6214(unsigned char *p,unsigned int a,void *b,int c,unsigned short d,unsigned short e,unsigned short f) {
 func_021D61B8(p,(int)func_02045770(a),b,c,d,e,f);
}
