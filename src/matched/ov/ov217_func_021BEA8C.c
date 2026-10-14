/*
 * function: func_021BEA8C
 * address: 0x021BEA8C
 * packet: pkt_ov217_021BEA8C
 * region: ov217
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * Prototypes: original loads r0/r1 and reads return at 021C11C8/11D0;
 * narrow argument truncations are explicit in the caller.
 * symbols:
 *   func_021BF76C 0x021BF76C thumb ov217
 *   func_021BF7CC 0x021BF7CC thumb ov217
 *   func_021BF7E0 0x021BF7E0 thumb ov217
 *   func_021BF7F4 0x021BF7F4 thumb ov217
 *   CircleGraph_FindSliceIndex 0x021C11C8 thumb ov217
 *   CircleGraph_GetSliceKey 0x021C11D0 thumb ov217
 *   GRAPHTABLE_FindEntry 0x021C26AC thumb ov217
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern u8 *func_021BF76C(void *p);
extern u32 func_021BF7CC(void *);
extern u32 func_021BF7E0(void *);
extern u32 func_021BF7F4(void *);
extern u8 CircleGraph_FindSliceIndex(u8 *p, u8 key);
extern u8 CircleGraph_GetSliceKey(u8 *p, u8 n);
extern u32 GRAPHTABLE_FindEntry(const u8 *p, u8 unused, u8 key);
void func_021BEA8C(u8 *p, int step)
{
    u8 *object;
    int kind;
    int count;
    int index;
    object = func_021BF76C(p);
    kind = func_021BF7CC(p);
    count = func_021BF7E0(p);
    index = func_021BF7F4(p);
    index = CircleGraph_FindSliceIndex(object, index);

    index = (count + (index + step)) % count;
    index = CircleGraph_GetSliceKey(object, index);
    p[697] = GRAPHTABLE_FindEntry(p + 56, kind, index);
}
