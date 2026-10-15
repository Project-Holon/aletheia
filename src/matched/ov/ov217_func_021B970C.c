/*
 * function: RESEARCH_TOP_CloseSubState
 * address: 0x021B970C
 * packet: pkt_ov217_021B970C
 * region: ov217
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * tail: zero halfword alignment at 021B9772.
 * symbols:
 *   RESEARCH_TOP_DestroyListObject 0x021B9AF8 thumb ov217
 *   RESEARCH_LIST_Destroy 0x021BABB4 thumb ov217
 *   RESEARCH_GRAPH_Destroy 0x021BD61C thumb ov217
 */
typedef unsigned int u32;
extern u32 RESEARCH_TOP_DestroyListObject(void *a0);
extern u32 RESEARCH_LIST_Destroy(void *a0);
extern u32 RESEARCH_GRAPH_Destroy(void *a0);
void RESEARCH_TOP_CloseSubState(u32 *p, u32 *state)
{
    switch (*state) {
    case 0: case 4: break;
    case 1: RESEARCH_TOP_DestroyListObject((void *)p[4]); break;
    case 2: RESEARCH_LIST_Destroy((void *)p[5]); break;
    case 3: RESEARCH_GRAPH_Destroy((void *)p[6]); break;
    }
    switch (*state) {
    case 0: case 4: break;
    case 1: p[4] = 0; break;
    case 2: p[5] = 0; break;
    case 3: p[6] = 0; break;
    }
}
