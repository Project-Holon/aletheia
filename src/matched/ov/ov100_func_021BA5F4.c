/*
 * function: func_021BA5F4
 * address: 0x021BA5F4
 * packet: pkt_ov100_021BA5F4
 * region: ov100
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_020452E8 0x020452E8 arm
 */
struct Descriptor;
extern void func_020452E8(struct Descriptor *);
void func_021BA5F4(unsigned a)
{
 if(*(unsigned *)(a+0x27c)!=0) func_020452E8(*(struct Descriptor **)(a+0x27c));
 if(*(unsigned *)(a+0x280)!=0) func_020452E8(*(struct Descriptor **)(a+0x280));
 *(unsigned *)(a+0x27c)=0;
 *(unsigned *)(a+0x280)=0;
}
