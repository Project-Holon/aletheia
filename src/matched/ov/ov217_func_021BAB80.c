/*
 * function: RESEARCH_LIST_Create
 * address:  0x021BAB80
 * packet:   pkt_021B9850
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Reconstructed from the listing (.inst decoded).
 *
 * symbols:
 *   RESEARCH_LIST_SetHeapId  0x021BC634  thumb  ov217
 *   RESEARCH_LIST_SetOwner  0x021BC638  thumb  ov217
 *   RESEARCH_LIST_SetListView  0x021BC640  thumb  ov217
 *   RESEARCH_LIST_Alloc  0x021BC758  thumb  ov217
 *   RESEARCH_LIST_InitFields  0x021BC774  thumb  ov217
 *   RESEARCH_COMMON_GetHeapId  0x021C09AC  thumb  ov217
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

extern u32 RESEARCH_LIST_SetHeapId();
extern void RESEARCH_LIST_SetOwner(void *p, u32 v);
extern void RESEARCH_LIST_SetListView(void *p, u32 v);
extern u32 RESEARCH_LIST_Alloc(u32 a0);
extern void RESEARCH_LIST_InitFields(u8 *p);
extern u32 RESEARCH_COMMON_GetHeapId(void *p);
u32 RESEARCH_LIST_Create(u32 a0, u32 a1)
{
    u32 v1 = RESEARCH_COMMON_GetHeapId((void *)a0);
    u32 v2 = RESEARCH_LIST_Alloc(v1);
    RESEARCH_LIST_InitFields((u8 *)v2);
    RESEARCH_LIST_SetHeapId(v2, v1);
    RESEARCH_LIST_SetOwner((void *)v2, a0);
    RESEARCH_LIST_SetListView((void *)v2, a1);
    return v2;
}

