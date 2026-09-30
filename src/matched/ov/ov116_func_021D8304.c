/*
 * function: func_021D8304
 * address: 0x021D8304
 * packet: pkt_ov116_021D8304
 * region: ov116
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02082BCC 0x02082BCC arm
 *   func_0203F8F4 0x0203F8F4 arm
 *   func_02045088 0x02045088 arm
 *   func_0203FC28 0x0203FC28 arm
 *   func_0203FCA0 0x0203FCA0 arm
 *   func_020414AC 0x020414AC arm
 *   func_02040588 0x02040588 arm
 *   d_021D83B0 0x021D83B0 data a4
 *   d_021D83F0 0x021D83F0 data a4
 */
typedef unsigned char u8;
extern void func_02082BCC(void *,int,int);
extern void func_0203F8F4(unsigned);
extern void func_02045088(unsigned);
extern void func_0203FC28(void *);
extern void func_0203FCA0(u8,void *,u8);
extern void func_020414AC(u8);
extern void func_02040588(u8,u8);
extern char d_021D83B0[],d_021D83F0[];
void func_021D8304(void *p,unsigned heap) {
 unsigned i; char *q; unsigned n;
 func_02082BCC(p,0,4);
 func_0203F8F4(heap); func_02045088(heap); func_0203FC28(d_021D83B0);
 for(i=0;i<8;i++) {
 q=d_021D83F0+i*44; n=*(unsigned *)q;
 func_0203FCA0(n,q+4,*(unsigned *)(q+36));
 func_020414AC(n); func_02040588(n,*(unsigned *)(q+40));
 }
}
