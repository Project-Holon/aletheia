/*
 * function: RESEARCH_GRAPH_StepEntry
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
 *   RESEARCH_GRAPH_GetLeftCircle 0x021BF76C thumb ov217
 *   RESEARCH_GRAPH_GetGroupKey 0x021BF7CC thumb ov217
 *   RESEARCH_GRAPH_GetGroupCount 0x021BF7E0 thumb ov217
 *   RESEARCH_GRAPH_GetEntryKey 0x021BF7F4 thumb ov217
 *   CircleGraph_FindSliceIndex 0x021C11C8 thumb ov217
 *   CircleGraph_GetSliceKey 0x021C11D0 thumb ov217
 *   GRAPHTABLE_FindEntry 0x021C26AC thumb ov217
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern u8 *RESEARCH_GRAPH_GetLeftCircle(void *p);
extern u32 RESEARCH_GRAPH_GetGroupKey(void *);
extern u32 RESEARCH_GRAPH_GetGroupCount(void *);
extern u32 RESEARCH_GRAPH_GetEntryKey(void *);
extern u8 CircleGraph_FindSliceIndex(u8 *p, u8 key);
extern u8 CircleGraph_GetSliceKey(u8 *p, u8 n);
extern u32 GRAPHTABLE_FindEntry(const u8 *p, u8 unused, u8 key);
void RESEARCH_GRAPH_StepEntry(u8 *p, int step)
{
    u8 *object;
    int kind;
    int count;
    int index;
    object = RESEARCH_GRAPH_GetLeftCircle(p);
    kind = RESEARCH_GRAPH_GetGroupKey(p);
    count = RESEARCH_GRAPH_GetGroupCount(p);
    index = RESEARCH_GRAPH_GetEntryKey(p);
    index = CircleGraph_FindSliceIndex(object, index);

    index = (count + (index + step)) % count;
    index = CircleGraph_GetSliceKey(object, index);
    p[697] = GRAPHTABLE_FindEntry(p + 56, kind, index);
}
