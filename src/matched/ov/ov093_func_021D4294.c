/*
 * function: func_021D4294
 * address:  0x021D4294
 * packet:   pkt_ov093_021D4294
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   d_021F3B88     0x021F3B88  data  ov093
 *   func_0203D3A8  0x0203D3A8  arm
 */

typedef unsigned char u8; typedef unsigned short u16;
struct S { void *link; u8 pad[0x3b1c - 4]; u16 buf[2]; };
extern struct S *d_021F3B88;
extern int func_0203D3A8(unsigned,unsigned,unsigned,void *);
void func_021D4294(u16 v)
{
    u16 *b = d_021F3B88->buf;
    b[0] = 0x64;
    b[1] = v;
    func_0203D3A8((unsigned)d_021F3B88->link, 0x100, 4, b);
}
