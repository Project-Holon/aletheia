/*
 * function: FIELD_WFBC_DATA_LOCAL_LoadMmdlPositionTable
 * address:  0x02186830
 * packet:   pkt_02186830
 * region:   ov020
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   ARC_TOOL_LoadHandleMember  0x02049250  arm
 */

struct ArcFile;

extern void *ARC_TOOL_LoadHandleMember(struct ArcFile *arc, unsigned int member,
                           unsigned int heap);

void *FIELD_WFBC_DATA_LOCAL_LoadMmdlPositionTable(struct ArcFile **p, int b, unsigned int heap)
{
    return ARC_TOOL_LoadHandleMember(*p, b + 0x22, heap);
}
