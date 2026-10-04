/*
 * function: func_021840AC
 * address:  0x021840AC
 * packet:   pkt_ov022_021840AC
 * region:   ov022
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020399A8  0x020399A8  arm
 *   func_0203D1A4  0x0203D1A4  arm
 * Addresses are Black-image addresses.
 */

typedef unsigned char u8;
typedef unsigned int u32;

struct Entry;
extern struct Entry *func_020399A8(void);
struct Link;
extern u32 func_0203D1A4(struct Link *p);

void func_021840AC(u8 *s)
{
    s[1] = s[1] | (u8)(1 << func_0203D1A4((struct Link *)((u32)func_020399A8())));
}
