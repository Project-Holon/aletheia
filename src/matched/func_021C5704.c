/*
 * function: func_021C5704
 * address:  0x021C5704
 * packet:   pkt_021C5704
 * region:   ov127
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021C41BC  0x021C41BC  thumb
 *   func_02082BCC  0x02082BCC  arm
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

extern void func_021C41BC(void *);
extern void func_02082BCC(void *, int, int);

void func_021C5704(u8 *p)
{
    func_021C41BC(*(void **)(p + 4));
    func_02082BCC(p, 0, 0x14);
}
