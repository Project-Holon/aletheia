/*
 * function: func_021C0A04
 * address:  0x021C0A04
 * packet:   pkt_ov217_021C0A04
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02082BCC  0x02082BCC  arm
 *   func_021C0AF8  0x021C0AF8  thumb  ov217
 *   func_021C0B8C  0x021C0B8C  thumb  ov217
 *   func_021C0BB4  0x021C0BB4  thumb  ov217
 *   func_021C0C38  0x021C0C38  thumb  ov217
 *   func_021C0CF0  0x021C0CF0  thumb  ov217
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char u8;
typedef unsigned int u32;

extern void func_02082BCC(void *dst, int val, u32 n);
extern void func_021C0AF8(void *p);
extern void func_021C0B8C(void *p);
extern void func_021C0BB4(void *p);
extern void func_021C0C38(void *p);
extern void func_021C0CF0(void *p);

void func_021C0A04(u8 *p)
{
    func_02082BCC(p, 0, 0x40);
    *(int *)(p + 0x30) = 0;
    *(int *)(p + 0x34) = 0;
    func_021C0AF8(p);
    func_021C0B8C(p);
    func_021C0BB4(p);
    func_021C0C38(p);
    func_021C0CF0(p);
}
