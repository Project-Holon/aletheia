/*
 * function: BTLV_GAUGE_UpdateLowHpBgm
 * address: 0x022089D4
 * packet: pkt_ov094_022089D4
 * region: ov094
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GFL_USE_IsBgmFading 0x02005E50 thumb
 *   GFL_USE_PopBgm 0x02005E9C thumb
 *   BTLV_EFFECT_IsBgmSaved 0x021F882C thumb ov094
 *   GFL_USE_CancelChangeAndPlayBgm 0x02005D90 thumb
 *   BTLV_GAUGE_SetBgmPlayerParam 0x02208D24 thumb ov094
 *   GFL_USE_FadeInBgmFull 0x02005DF8 thumb
 *   GFL_USE_PushBgm 0x02005E64 thumb
 *   func_0202D034 0x0202D034 thumb
 *   GFL_USE_GetBgmNo 0x02005C44 thumb
 *   GFL_USE_FadeOutBgm 0x02005E30 thumb
 */
typedef unsigned int u32;
typedef struct { char p0[0x40]; int f40, f44, f48, f4c; char p50[0x20]; u32 b0:1, b1:1, b2:1, b3:1, hi:28; char p74[12]; } E;
typedef struct { char p0[0x40]; E e[8]; u32 b0:1, b1:1, b2:1, b3:1, hi:28; int f444; } O;
extern int GFL_USE_IsBgmFading(void);
extern int GFL_USE_PopBgm(void);
extern int BTLV_EFFECT_IsBgmSaved(void);
extern void GFL_USE_CancelChangeAndPlayBgm(u32, u32);
extern void BTLV_GAUGE_SetBgmPlayerParam(int);
extern void GFL_USE_FadeInBgmFull(u32);
extern int GFL_USE_PushBgm(void);
typedef unsigned short u16;
extern int func_0202D034(u32 a, u32 b);
extern u16 GFL_USE_GetBgmNo(void);
extern void GFL_USE_FadeOutBgm(u32);
void BTLV_GAUGE_UpdateLowHpBgm(O *o)
{
    int busy, found, i;
    if (o->b1) {
        if (GFL_USE_IsBgmFading() != 0) return;
        o->b1 = 0;
        if (o->b2) {
            GFL_USE_PopBgm();
            if (!o->b3 && BTLV_EFFECT_IsBgmSaved() != 0) {
                GFL_USE_CancelChangeAndPlayBgm(o->f444, 0xffff);
                o->b3 = 1;
            } else {
                BTLV_GAUGE_SetBgmPlayerParam(0);
            }
            GFL_USE_FadeInBgmFull(24);
        } else {
            BTLV_GAUGE_SetBgmPlayerParam(1);
            GFL_USE_PushBgm();
            GFL_USE_CancelChangeAndPlayBgm(0x47a, 0xffff);
        }
        o->b2 ^= 1;
        return;
    }
    busy = 0;
    found = 0;
    for (i = 0; i < 8; i++) {
        if (o->e[i].b0 || o->e[i].b1 || o->e[i].b2) {
            busy = 1;
        } else if (o->e[i].f44 == 0 && o->e[i].b3 && o->e[i].f40 != 4) {
            if (func_0202D034(o->e[i].f48, o->e[i].f4c) == 2) found = 1;
        }
    }
    if (!o->b2 && o->f444 != GFL_USE_GetBgmNo()) return;
    if (busy != 0) return;
    if ((o->b2 && found == 0) || (!o->b2 && found == 1)) {
        o->b1 = 1;
        GFL_USE_FadeOutBgm(8);
    }
}
