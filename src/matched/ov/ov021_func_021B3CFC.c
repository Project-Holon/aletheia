/*
 * function: func_021B3CFC
 * address:  0x021B3CFC
 * packet:   pkt_ov021_021B3CFC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02020E60 0x02020E60 thumb
 *   func_0204AC18 0x0204AC18 arm
 *   func_0204A6C8 0x0204A6C8 arm
 *   func_0204AF28 0x0204AF28 arm
 */

extern unsigned func_02020E60(unsigned a, unsigned b);
extern void *func_0204AC18(void *a, unsigned b, unsigned c, unsigned d, unsigned e, unsigned f, unsigned g);
extern void *func_0204A6C8(void *a, unsigned b, unsigned c, unsigned d, unsigned e);
extern void *func_0204AF28(void *a, unsigned b, unsigned c, unsigned d);

void func_021B3CFC(char *w)
{
    *(void **)(w + 0x1EC) = func_0204AC18(*(void **)(w + 0x1F8), func_02020E60(1, 2), 0, 0x20, 0, 1, *(unsigned short *)(w + 4));
    *(void **)(w + 0x1F0) = func_0204A6C8(*(void **)(w + 0x1F8), func_02020E60(1, 1), 0, 0, *(unsigned short *)(w + 4));
    *(void **)(w + 0x1F4) = func_0204AF28(*(void **)(w + 0x1F8), 1, 0, *(unsigned short *)(w + 4));
}
