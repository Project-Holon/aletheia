/*
 * function: func_021EA808
 * address:  0x021EA808
 * packet:   pkt_ov170_021EA808
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02030734 0x02030734 arm
 *   d_021F140C 0x021F140C data a1
 */

extern unsigned short *func_02030734(unsigned heap, unsigned size, unsigned clear, const char *file, unsigned line);
extern const char d_021F140C[];

void func_021EA808(char *p)
{
    unsigned short *q = func_02030734(0x804C, 4, 0, d_021F140C, 0x2305);
    q[0] = 0;
    q[1] = 0;
    *(unsigned short **)(*(char **)(p + 0x2C) + 0xA190) = q;
}
