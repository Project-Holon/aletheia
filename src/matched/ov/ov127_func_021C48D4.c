/*
 * function: func_021C48D4
 * address:  0x021C48D4
 * packet:   pkt_021C48D4
 * region:   ov127
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021C4954  0x021C4954  thumb
 *   func_021C4C88  0x021C4C88  thumb
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

extern char *func_021C4954(unsigned *p, unsigned id);
extern void func_021C4C88(char *p, char *q);

void func_021C48D4(void *a, u8 *q)
{
    func_021C4C88(func_021C4954(a, q[7]), (char *)q);
}
