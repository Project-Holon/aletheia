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

typedef unsigned short u16;
typedef unsigned int   u32;
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern const char d_021F140C[];

void func_021EA808(char *p)
{
    unsigned short *q = func_02030734(0x804C, 4, 0, d_021F140C, 0x2305);
    q[0] = 0;
    q[1] = 0;
    *(unsigned short **)(*(char **)(p + 0x2C) + 0xA190) = q;
}
