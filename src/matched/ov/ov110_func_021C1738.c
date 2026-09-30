/*
 * function: func_021C1738
 * address: 0x021C1738
 * packet: pkt_ov110_021C1738
 * region: ov110
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
 *   d_021C3A18 0x021C3A18 data a4
 *   d_021C3A74 0x021C3A74 data a4
 */
typedef unsigned char u8;
typedef unsigned short u16;
extern const unsigned d_021C3A18[];
extern const unsigned d_021C3A74[][11];
extern void func_02082BCC(void *, int, unsigned);
extern void func_0203F8F4(u16);
extern void func_02045088(unsigned);
extern void func_0203FC28(const void *);
extern void func_0203FCA0(u8,const void *,u8);
extern void func_020414AC(u8);
extern void func_02040588(u8,u8);
void func_021C1738(void *p, u16 heap) {
    unsigned i;
    const unsigned *q;
    unsigned id;
    func_02082BCC(p,0,4);
    func_0203F8F4(heap);
    func_02045088(heap);
    func_0203FC28(d_021C3A18);
    for (i=0; i<6; i++) {
        q=d_021C3A74[i];
        id=q[0];
        func_0203FCA0(id,q+1,q[9]);
        func_020414AC(id);
        func_02040588(id,q[10]);
    }
}
