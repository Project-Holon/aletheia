/*
 * function: func_021F5304
 * address: 0x021F5304
 * packet: pkt_ov194_021F5304
 * region: ov194
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * Match levers: u16 heap, counter declared first, zero set before size-base
 * assignment; the int heap and later zero caused the recorded diffs.
 * symbols:
 *   func_02030734 0x02030734 arm
 *   ARC_UTIL_LoadMemberWithSize 0x0204A298 arm
 *   func_0203F37C 0x0203F37C arm
 *   d_021F57B8 0x021F57B8 data a1
 */
typedef struct { unsigned data[7], size[7]; } Resources;
extern const char d_021F57B8[];
extern void *func_02030734(unsigned, unsigned, int, const char *, unsigned short);
extern int ARC_UTIL_LoadMemberWithSize(int, int, int, int, unsigned *);
extern void func_0203F37C(void *p, unsigned int size, unsigned int seed);
Resources *func_021F5304(unsigned short heap)
{
    int i;
    Resources *p;
    unsigned *sizes;
    p = func_02030734(heap, 0x38, 1, d_021F57B8, 0x38);
    sizes = (unsigned *)p;
    i = 0;
    sizes = p->size;
    for (; i < 7; i++) {
        p->data[i] = ARC_UTIL_LoadMemberWithSize(0xDD, i, 0, heap, &sizes[i]);
        func_0203F37C((void *)p->data[i], p->size[i], 0x72012891);
    }
    return p;
}
