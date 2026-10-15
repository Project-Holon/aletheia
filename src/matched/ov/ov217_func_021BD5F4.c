/*
 * function: RESEARCH_GRAPH_Create
 * address:  0x021BD5F4
 * packet:   pkt_ov217_021BD5F4
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   RESEARCH_COMMON_GetHeapId  0x021C09AC  thumb  ov217
 *   RESEARCH_GRAPH_Alloc  0x021BFA14  thumb  ov217
 *   RESEARCH_GRAPH_InitFields  0x021BFA30  thumb  ov217
 *   RESEARCH_GRAPH_SetHeapId  0x021BF74C  thumb  ov217
 *   RESEARCH_GRAPH_SetOwner  0x021BF754  thumb  ov217
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned int   u32;
extern u32 RESEARCH_COMMON_GetHeapId(void *p);
extern u32 RESEARCH_GRAPH_Alloc(u32 a0);
extern void RESEARCH_GRAPH_InitFields(char *p);
extern void RESEARCH_GRAPH_SetHeapId(void *a, void *b);
extern void RESEARCH_GRAPH_SetOwner(void *p, u32 v);

void *RESEARCH_GRAPH_Create(void *p)
{
    void *r;
    void *a;
    a = (void *)RESEARCH_COMMON_GetHeapId(p);
    r = (void *)RESEARCH_GRAPH_Alloc((u32)a);
    RESEARCH_GRAPH_InitFields(r);
    RESEARCH_GRAPH_SetHeapId(r, a);
    RESEARCH_GRAPH_SetOwner(r, (u32)p);
    return r;
}
