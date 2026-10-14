/*
 * function: BTLV_MCSS_SetSubstituteSprite
 * address:  0x021FFFD8
 * packet:   pkt_ov094_021FFFD8
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   BTLV_MCSS_FindSpriteIndex 0x022019F4 thumb ov094
 *   MCSS_TOOL_SetSpindaSpotHook 0x020172AC thumb
 *   MCSS_ReloadResource 0x02014CF8 thumb
 *   MCSS_SetAnimCallback 0x02015F2C thumb
 *   BTLV_MCSS_IdleAnimCallback 0x02201718 thumb ov094
 *   POKEGRA_GetArcID 0x0202D060 thumb
 *   BTLV_MCSS_StartPaletteCopy 0x021FFE24 thumb ov094
 */
#include "../include/Obj01047.h"
typedef unsigned int u32;
typedef struct { u32 v[9]; } Rec;
extern int BTLV_MCSS_FindSpriteIndex(char *, int);
extern void MCSS_TOOL_SetSpindaSpotHook(int a0, int a1);
struct Sub02014CF8Ctx;
struct Sub02014CF8Rec;
extern void MCSS_ReloadResource(void *a, struct Sub02014CF8Ctx *b, const struct Sub02014CF8Rec *c);
extern void MCSS_SetAnimCallback(void *, int, void (*)(int), int);
extern void BTLV_MCSS_IdleAnimCallback(int);
extern int POKEGRA_GetArcID(void);
extern void BTLV_MCSS_StartPaletteCopy(char *, int);

void BTLV_MCSS_SetSubstituteSprite(char *w, int key, int flag, int clear)
{
    int idx = BTLV_MCSS_FindSpriteIndex(w, key);
    char *e;
    int off;
    Rec r;
    int odd;

    if (idx == -1)
        return;
    e = w;
    e += 8;
    off = idx * 0x5c;
    if (*(void **)(e + off) == 0)
        return;
    if (flag == 0) {
        MCSS_TOOL_SetSpindaSpotHook((int)(((struct Obj01047 *)w)->f4), *(u32 *)(w + off + 0x3c));
        MCSS_ReloadResource(((struct Obj01047 *)w)->f4, *(void **)(w + 8 + off), (const struct Sub02014CF8Rec *)(w + 0xc + off));
        MCSS_SetAnimCallback(*(void **)(w + 8 + off), idx, BTLV_MCSS_IdleAnimCallback, 1);
        if (clear)
            *(u32 *)(w + 0x48 + off) &= ~1u;
        *(u32 *)(w + 0x48 + off) &= ~4u;
    } else {
        r.v[0] = POKEGRA_GetArcID();
        odd = key & 1;
        r.v[1] = odd ? 0x37a0 : 0x37a6;
        r.v[2] = 0x37ac;
        r.v[3] = odd ? 0x37a1 : 0x37a7;
        r.v[4] = odd ? 0x37a2 : 0x37a8;
        r.v[5] = odd ? 0x37a3 : 0x37a9;
        r.v[6] = odd ? 0x37a4 : 0x37aa;
        r.v[7] = odd ? 0x37a5 : 0x37ab;
        r.v[8] = 0;
        MCSS_ReloadResource(((struct Obj01047 *)w)->f4, *(void **)(e + off), (const struct Sub02014CF8Rec *)(&r));
        BTLV_MCSS_StartPaletteCopy(w, key);
        if (clear)
            *(u32 *)(w + 0x48 + off) |= 1;
        *(u32 *)(w + 0x48 + off) |= 4;
    }
}
