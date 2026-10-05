/*
 * function: func_021E0000
 * address:  0x021E0000
 * packet:   pkt_ov175_021E0000
 * region:   ov175
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * SDK provenance: sciReportBeginNewPlayer (TwlDWC/libdwcgssc.TWL.HYB.a,
 * scireport.o), ov175.  Close the previous player block and start a new one
 * at +0x120, byte-swapping the zeroed two-byte player id.
 *
 * symbols:
 *   func_021E0504  0x021E0504  arm  ov175
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern u8 *func_021E0504(u8 *dst, u32 v);

int func_021E0000(u8 *p)
{
    u32 a = *(u32 *)(p + 0x120);
    u8 *q = *(u8 **)(p + 0x124);

    *(u16 *)(p + 8) = 0;
    *(u32 *)(p + 4) = a;
    *(u32 *)(p + 0x120) = a + 2;
    func_021E0504(q + a, 0);
    *(u32 *)(q + 0x3c) += 2;
    return 0;
}
