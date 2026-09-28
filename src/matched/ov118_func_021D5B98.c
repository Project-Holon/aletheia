/*
 * function: func_021D5B98
 * address:  0x021D5B98
 * packet:   pkt_ov118_021D5B98
 * region:   ov118
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021D8E84  0x021D8E84  thumb  ov119
 *   func_021DFA60  0x021DFA60  thumb  ov119
 *   func_021D5BB8  0x021D5BB8  thumb  ov118
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned int u32;
typedef unsigned char u8;
typedef int s32;

extern void func_021D8E84(void *p, int next);
extern void func_021DFA60(s32);
extern void func_021D5BB8(u8 *p);

void func_021D5B98(u8 *p)
{
    func_021DFA60(*(s32 *)(p + 0xF2C));
    func_021D8E84(p, (int)func_021D5BB8);
}
