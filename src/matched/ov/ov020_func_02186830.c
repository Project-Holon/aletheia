/*
 * function: func_02186830
 * address:  0x02186830
 * packet:   pkt_02186830
 * region:   ov020
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_02049250  0x02049250  arm
 */

struct ArcFile;

extern void *func_02049250(struct ArcFile *arc, unsigned int member,
                           unsigned int heap);

void *func_02186830(struct ArcFile **p, int b, unsigned int heap)
{
    return func_02049250(*p, b + 0x22, heap);
}
