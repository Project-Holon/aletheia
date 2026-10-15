/*
 * function: POKETRADE_DEMO_MIDDLE_ResetMonSlide
 * address:  0x021D6E04
 * packet:   pkt_ov118_021D6E04
 * region:   ov118
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   MCSS_ResetVanishFlag  0x02015EB0  thumb
 *   MCSS_SetPosition  0x02015C48  thumb
 *   MCSS_SetAnmStopFlag  0x02015E04  thumb
 *   MCSS_GetScale  0x02015C94  thumb
 *   MCSS_SetScale  0x02015CAC  thumb
 *
 * The five ARM9 helpers it marshals through are unlabelled Thumb leaves;
 * they were promoted to src/matched (pkt_02015Exx) and now witness this
 * file's calls. Codegen lever: caching the base pointer in a local costs a
 * callee-saved register and diverges; the indexed field must be reloaded
 * inline at every use.
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned int u32;
typedef int s32;

extern void MCSS_ResetVanishFlag(void *p);
extern void MCSS_SetPosition(void *p, u32 *src);
extern void MCSS_SetAnmStopFlag(void *p);
extern void MCSS_GetScale(void *p, u32 *out);
extern void MCSS_SetScale(void *p, u32 *src);

void POKETRADE_DEMO_MIDDLE_ResetMonSlide(void *p, int idx)
{
    u32 vec[3];
    MCSS_ResetVanishFlag((void *)(((u32 *)((char *)p + 0x844))[idx]));
    vec[0] = 0;
    vec[1] = 0xFFFE9000;
    vec[2] = 0xA000;
    MCSS_SetPosition((void *)(((u32 *)((char *)p + 0x844))[idx]), vec);
    MCSS_SetAnmStopFlag((void *)(((u32 *)((char *)p + 0x844))[idx]));
    MCSS_GetScale((void *)(((u32 *)((char *)p + 0x844))[idx]), vec);
    vec[0] = ((s32)vec[0] < 0) ? 0xFFFF0000 : 0x10000;
    vec[1] = 0x10000;
    vec[2] = 0x1000;
    MCSS_SetScale((void *)(((u32 *)((char *)p + 0x844))[idx]), vec);
}
