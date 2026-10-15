/*
 * unit: yes
 * function: RESEARCH_TOP_OpenSubState, RESEARCH_TOP_StateIdle
 * address: 0x021B9774
 * packet: pkt_ov217_021B9774
 * region: ov217
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   RESEARCH_TOP_CreateListObject 0x021B9AD0 thumb ov217
 *   RESEARCH_LIST_Create 0x021BAB80 thumb ov217
 *   RESEARCH_GRAPH_Create 0x021BD5F4 thumb ov217
 */
typedef unsigned int u32;
extern u32 RESEARCH_TOP_CreateListObject(void *self);
extern u32 RESEARCH_LIST_Create(u32, u32);
extern void *RESEARCH_GRAPH_Create(void *p);
void RESEARCH_TOP_OpenSubState(u32 *p, u32 *state, u32 kind)
{
    switch (kind) {
    case 0:
    case 4:
        break;
    case 1:
        p[4] = RESEARCH_TOP_CreateListObject((void *)p[3]);
        break;
    case 2:
        p[5] = RESEARCH_LIST_Create(p[3], p[7]);
        break;
    case 3:
        p[6] = (u32)RESEARCH_GRAPH_Create((void *)p[3]);
        break;
    }
    *state = kind;
}
int RESEARCH_TOP_StateIdle(void *a0)
{
    return 1;
}
