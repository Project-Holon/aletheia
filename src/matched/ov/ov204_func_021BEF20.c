/*
 * function: func_021BEF20
 * address: 0x021BEF20
 * packet: pkt_ov204_021BEF20
 * region: ov204
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02030734 0x02030734 arm
 *   func_021BF0A0 0x021BF0A0 thumb ov204
 *   d_021C0AAC 0x021C0AAC data a1
 */
extern void *func_02030734(unsigned short, unsigned, int, const char *, unsigned short);
extern void *func_021BF0A0(unsigned short);
extern const char d_021C0AAC[];
char *func_021BEF20(void *a, unsigned b, unsigned c, char *d, unsigned e, unsigned short heap)
{
    char *p = func_02030734(heap, 0x10d8, 1, d_021C0AAC, 0x6f2);
    *(unsigned short *)p = heap;
    *(char **)(p + 4) = d;
    *(unsigned *)(p + 8) = c;
    *(void **)(p + 0xc) = a;
    *(unsigned *)(p + 0x10) = b;
    *(unsigned *)(p + 0x14) = e;
    *(unsigned *)(p + 0xa4) = *(unsigned *)(d + 0xc);
    *(void **)(p + 0x18) = func_021BF0A0(heap);
    return p;
}
