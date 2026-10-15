/*
 * function: POKETRADE_IRCDEMO_SetMonSlide
 * address:  0x021D49F4
 * packet:   pkt_ov117_021D49F4
 * region:   ov117
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   MCSS_SetAlpha  0x02015FBC  thumb
 *   MCSS_ResetVanishFlag  0x02015EB0  thumb
 *   MCSS_SetPosition  0x02015C48  thumb
 *   MCSS_SetAnmStopFlag  0x02015E04  thumb
 *   MCSS_SetScale  0x02015CAC  thumb
 *   MCSS_SetPaletteFade  0x02015F50  thumb
 *
 * The call to 0x02015FBC (arm9 byte insert at +0x140) attests through
 * src/matched/MCSS_SetAlpha.c, seeded in layout/function_starts.txt.
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj22645.h"

typedef unsigned int u32;
typedef unsigned char u8;
typedef int s32;

typedef struct {
    s32 x, y, z;
} Vec;

struct McssFade;
extern void MCSS_SetAlpha(char *p, int v);
extern void MCSS_ResetVanishFlag(void *);
extern void MCSS_SetPosition(void *p, u32 *src);
extern void MCSS_SetAnmStopFlag(void *);
extern void MCSS_SetScale(void *p, u32 *src);
extern void MCSS_SetPaletteFade(struct McssFade *w, u32 cur, u32 target, s32 step, u32 e);

void POKETRADE_IRCDEMO_SetMonSlide(void *obj, void *p)
{
    Vec v;
    MCSS_SetAlpha(obj, 0x1f);
    MCSS_ResetVanishFlag(obj);
    v.x = 0;
    v.y = -0x17000;
    v.z = 0xa000;
    MCSS_SetPosition(obj, (u32 *)(&v));
    MCSS_SetAnmStopFlag(obj);
    MCSS_SetScale(obj, (u32 *)((char *)((struct Obj22645 *)p)->fC + 0x48));
    MCSS_SetPaletteFade(obj, 0x10, 0x10, 0, 0x7fff);
}
