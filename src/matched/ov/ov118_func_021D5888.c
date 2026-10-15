/*
 * function: POKETRADE_DEMO_UP_ResetMonSlide
 * address:  0x021D5888
 * packet:   pkt_ov118_021D5888
 * region:   ov118
 * compiler: dsi/1.1p1
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
 * Addresses are Black-image addresses.
 */

typedef unsigned int u32;
typedef unsigned char u8;
typedef int s32;

typedef struct {
    s32 x, y, z;
} Vec;

extern void MCSS_ResetVanishFlag(void *p);
extern void MCSS_SetPosition(void *p, u32 *src);
extern void MCSS_SetAnmStopFlag(void *p);
extern void MCSS_GetScale(void *p, u32 *out);
extern void MCSS_SetScale(void *p, u32 *src);

void POKETRADE_DEMO_UP_ResetMonSlide(u8 *p, int idx)
{
    u32 *obj = (u32 *)(p + 0x844);
    Vec v;

    MCSS_ResetVanishFlag((void *)obj[idx]);
    v.x = 0;
    v.y = -0x17000;
    v.z = 0xA000;
    MCSS_SetPosition((void *)obj[idx], (u32 *)(&v));
    MCSS_SetAnmStopFlag((void *)obj[idx]);
    MCSS_GetScale((void *)obj[idx], (u32 *)(&v));
    if (v.x < 0) {
        v.x = -0x10000;
    } else {
        v.x = 0x10000;
    }
    v.y = 0x10000;
    v.z = 0x1000;
    MCSS_SetScale((void *)obj[idx], (u32 *)(&v));
}
