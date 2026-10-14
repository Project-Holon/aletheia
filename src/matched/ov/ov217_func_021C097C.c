/*
 * function: RESEARCH_COMMON_Create
 * address:  0x021C097C
 * packet:   pkt_ov217_021C097C
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   RESEARCH_COMMON_Alloc  0x021C0A38  thumb  ov217
 *   RESEARCH_COMMON_ClearFields  0x021C0A04  thumb  ov217
 *   RESEARCH_COMMON_Init  0x021C0A5C  thumb  ov217
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned int u32;

extern u32 RESEARCH_COMMON_Alloc(u32 a0);
typedef unsigned char  u8;
struct Ctx;
extern void RESEARCH_COMMON_ClearFields(u8 *p);
extern void RESEARCH_COMMON_Init(u8 *p, const struct Ctx *ctx, u32 heap);

int RESEARCH_COMMON_Create(int a0, int a1)
{
    int r;
    r = RESEARCH_COMMON_Alloc(a0);
    RESEARCH_COMMON_ClearFields((u8 *)r);
    RESEARCH_COMMON_Init((u8 *)r, (const struct Ctx *)a1, a0);
    return r;
}
