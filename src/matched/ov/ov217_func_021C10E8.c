/*
 * function: CircleGraph_SetSlices
 * address:  0x021C10E8
 * packet:   pkt_ov217_021C10E8
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   CircleGraph_ClearSlices  0x021C1704  thumb  ov217
 *   CircleGraph_AddSlice  0x021C1720  thumb  ov217
 *   CircleGraph_SortSlices  0x021C17C4  thumb  ov217
 *   CircleGraph_ComputePercents  0x021C1850  thumb  ov217
 *   CircleGraph_ComputePointRanges  0x021C18C4  thumb  ov217
 *   CircleGraph_BuildVertices  0x021C18F8  thumb  ov217
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char u8;

typedef unsigned int   u32;
extern u32 CircleGraph_ClearSlices(void *a0);
extern void CircleGraph_AddSlice(u8 *p, u8 *e);
extern void CircleGraph_SortSlices(u8 *p);
extern void CircleGraph_ComputePercents(u8 *p);
extern void CircleGraph_ComputePointRanges(u8 *p);
extern void CircleGraph_BuildVertices(u8 *p);

void CircleGraph_SetSlices(u8 *p, u8 *tab, int n)
{
    int i;
    CircleGraph_ClearSlices((void *)p);
    for (i = 0; i < n; i++)
        CircleGraph_AddSlice(p, tab + i * 16);
    CircleGraph_SortSlices(p);
    CircleGraph_ComputePercents(p);
    CircleGraph_ComputePointRanges(p);
    CircleGraph_BuildVertices(p);
}
