/*
 * function: func_021D6CDC
 * address: 0x021D6CDC
 * packet: pkt_ov131_021D6CDC
 * region: ov131
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_0201ACDC 0x0201ACDC thumb
 *   func_020452E8 0x020452E8 arm
 */
typedef unsigned char u8;
extern void func_0201ACDC(void *,u8,void *);
struct Descriptor;
extern void func_020452E8(struct Descriptor *d);
void func_021D6CDC(unsigned char *a,unsigned char *b) {
 unsigned char *q=*(unsigned char **)(a+8);
 if(q[12]==1) func_0201ACDC(*(void **)q,a[0x1a],*(void **)(b+12));
 func_020452E8(*(void **)(b+0x1c));
 func_020452E8(*(void **)(b+0x18));
}
