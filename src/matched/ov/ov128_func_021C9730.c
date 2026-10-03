/*
 * function: func_021C9730
 * address: 0x021C9730
 * packet: pkt_ov128_021C9730
 * region: ov128
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: two-byte zero padding at 021C979E before next label 021C97A0.
 * symbols:
 *   func_021CA444 0x021CA444 thumb ov128
 *   func_021CA458 0x021CA458 thumb ov128
 *   func_021C9EFC 0x021C9EFC thumb ov128
 *   func_021C9EF0 0x021C9EF0 thumb ov128
 *   func_020452E8 0x020452E8 arm
 *   func_021C9EB4 0x021C9EB4 thumb ov128
 *   func_021C9E54 0x021C9E54 thumb ov128
 */
typedef unsigned char u8;
extern void func_021CA444(void *);
extern void func_021CA458(void *,void *);
extern void func_021C9EFC(void *,int);
extern void func_021C9EF0(void *);
struct Descriptor;
extern void func_020452E8(struct Descriptor *d);
extern void func_021C9EB4(u8 *,void *);
extern void func_021C9E54(u8 *);
void func_021C9730(u8 *p,void *unused,u8 *q)
{
    u8 *base;
    int j;
    int i;
    func_021CA444(q);
    func_021CA458(q,q+12);
    base=p+20;
    for(i=0;i<3;i++) {
        for(j=0;j<8;j++) func_021C9EFC(base+i*76,j);
        func_021C9EF0(base+i*76);
    }
    for(i=0;i<2;i++) func_020452E8(*(void **)(p+i*8+0x118));
    func_021C9EB4(p,q);
    p+=0xf8;
    func_021C9E54(p);
}
