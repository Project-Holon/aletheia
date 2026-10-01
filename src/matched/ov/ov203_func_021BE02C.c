/*
 * function: func_021BE02C
 * address: 0x021BE02C
 * packet: pkt_ov203_021BE02C
 * region: ov203
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02040DA8 0x02040DA8 arm
 *   func_02040588 0x02040588 arm
 *   func_020403F4 0x020403F4 arm
 *   func_020450C8 0x020450C8 arm
 *   func_0203F9B4 0x0203F9B4 arm
 *   func_02082BCC 0x02082BCC arm
 *   d_021BFC24 0x021BFC24 data a4
 */
extern const unsigned d_021BFC24[][11];
extern void func_02040DA8(unsigned, unsigned, unsigned);
extern void func_02040588(unsigned char, unsigned);
extern void func_020403F4(unsigned char);
extern void func_020450C8(void);
extern void func_0203F9B4(void);
extern void func_02082BCC(void *, int, unsigned);
void func_021BE02C(void *ctx)
{
    unsigned i = 0;
    unsigned layer;
    func_02040DA8(1, 1, 0);
    for (; i < 4; i++) {
        layer = d_021BFC24[i][0];
        func_02040588(layer, 0);
        func_020403F4(layer);
    }
    func_020450C8();
    func_0203F9B4();
    func_02082BCC(ctx, 0, 4);
}
