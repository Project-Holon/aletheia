/*
 * function: RESEARCH_TOP_CreateListObject
 * address:  0x021B9AD0
 * packet:   pkt_ov217_021B9AD0
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   RESEARCH_COMMON_GetHeapId  0x021C09AC  thumb  ov217
 *   RESEARCH_TOP_AllocListObject  0x021BA4E0  thumb  ov217
 *   RESEARCH_TOP_InitFields  0x021BA504  thumb  ov217
 *   RESEARCH_TOP_SetHeapId  0x021BA4D0  thumb  ov217
 *   RESEARCH_TOP_SetOwner  0x021BA4CC  thumb  ov217
 */

typedef unsigned short u16;
typedef unsigned int u32;

extern u32 RESEARCH_COMMON_GetHeapId(void *);
extern u32 RESEARCH_TOP_AllocListObject(u32);
extern void RESEARCH_TOP_InitFields(char *p);
extern void RESEARCH_TOP_SetHeapId(void *p, u32 v);
extern void RESEARCH_TOP_SetOwner(void *p, u32 v);

u32 RESEARCH_TOP_CreateListObject(void *self)
{
    u32 v = RESEARCH_COMMON_GetHeapId(self);
    u32 o = RESEARCH_TOP_AllocListObject(v);
    RESEARCH_TOP_InitFields((char *)o);
    RESEARCH_TOP_SetHeapId((void *)o, v);
    RESEARCH_TOP_SetOwner((void *)o, (u32)self);
    return o;
}
