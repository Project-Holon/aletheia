/*
 * function: func_021EBAF8
 * address:  0x021EBAF8
 * packet:   pkt_ov170_021EBAF8
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0201EF40 0x0201EF40 thumb
 *   func_021EBA84 0x021EBA84 thumb
 *
 * Puts item v into word slot 0 and prints message 0x15 into window i.
 */

typedef unsigned int u32;

extern void func_0201EF40(void *ws, u32 i, u32 v);
extern void func_021EBA84(unsigned char *p, int msg, int i);

#define WORK(p) (*(char **)((p) + 0x2C))

void func_021EBAF8(unsigned char *p, u32 v, int i)
{
    func_0201EF40(*(void **)(WORK(p) + 0x84), 0, v);
    func_021EBA84(p, 0x15, i);
}
