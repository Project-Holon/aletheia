/*
 * function: BTLV_SCU_PrepareNamePlate
 * address:  0x021EDC28
 * packet:   pkt_ov093_021EDC28
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 * note:     a1 is a narrow (u8/u16, both give EXACT*) parameter: it pins the
 *           spill store to the front of the prologue; flag is int, cast (u8)
 *           at the bitfield store.
 *
 * symbols:
 *   BTL_SIDE_GetPokeAtPos  0x021B98AC  thumb  ov093
 *   BTL_POKEPARAM_GetValue  0x021D59B4  thumb  ov093
 *   BTL_POKEPARAM_GetPokeId  0x021D5440  thumb  ov093
 *   BTLV_SCU_HideNamePlate  0x021EDF4C  thumb  ov093
 *   BTLV_SCU_DrawNamePlate  0x021EDE54  thumb  ov093
 *   BTLV_EFFECT_SetPokeEffectValue  0x021F8AE8  thumb  ov094
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct W {
    char *f00;
    u8 pad04[4];
    u16 f08;
    u8 pad0a[2];
    u8 f0c;
    u8 f0d;
    u8 pad0e[0x14];
    u8 f22_0 : 1;
    u8 f22_1 : 1;
};

extern u8 *BTL_SIDE_GetPokeAtPos(char *const *q, u8 b);
extern int BTL_POKEPARAM_GetValue(u8 *p, int k);
extern u8 BTL_POKEPARAM_GetPokeId(u8 *p);
extern void BTLV_SCU_HideNamePlate(struct W *w);
extern void BTLV_SCU_DrawNamePlate(u8 *p);
extern void BTLV_EFFECT_SetPokeEffectValue(int a, u32 b);

void BTLV_SCU_PrepareNamePlate(struct W *w, u8 a1, int flag)
{
    u8 *t;
    u16 h;
    u8 k;

    t = BTL_SIDE_GetPokeAtPos(*(char *const **)(w->f00 + 0x138), a1);
    h = BTL_POKEPARAM_GetValue(t, 0x10);
    k = BTL_POKEPARAM_GetPokeId(t);
    if (w->f22_0) {
        if (k == w->f0c) {
            return;
        }
        BTLV_SCU_HideNamePlate(w);
    }
    if (h != w->f08 || k != w->f0c) {
        w->f08 = h;
        w->f0c = k;
        BTLV_SCU_DrawNamePlate((u8 *)w);
    }
    w->f22_1 = (u8)flag;
    w->f0d = 0;
    BTLV_EFFECT_SetPokeEffectValue(a1, h);
}
