/*
 * function: func_021BB724
 * address:  0x021BB724
 * packet:   pkt_ov093_021BB724
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021EEAE8  0x021EEAE8  thumb  ov093
 *   func_021BB830  0x021BB830  thumb  ov093
 *   func_021EEB00  0x021EEB00  thumb  ov093
 *   func_021EEAFC  0x021EEAFC  thumb  ov093
 */

typedef unsigned char u8;
typedef unsigned int u32;

extern void func_021EEAE8(void);
extern int func_021BB830(u8 *);
extern void func_021EEB00(u32, int, int, int);
extern void func_021EEAFC(void);

void func_021BB724(u8 *p, int a, int b, int c)
{
    int i;
    u8 *q;

    func_021EEAE8();
    i = 0;
    q = p + 0x14;
    for (; i < 4; i++) {
        if (func_021BB830(q + i * 12) != 0)
            func_021EEB00(*(u32 *)(p + 0x14 + i * 12), a, b, c);
    }
    func_021EEAFC();
}
