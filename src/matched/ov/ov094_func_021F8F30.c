/*
 * function: BTLV_EFFECT_PokeSpriteTransitionTaskMain
 * address:  0x021F8F30
 * packet:   pkt_ov094_021F8F30
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   gBtlvEff     0x0220AF20  data   ov094
 *   BTLV_MCSS_StartRotation  0x02200344  thumb  ov094
 *   BTLV_STAGE_IsAnyLayerArmed  0x021F6AD0  thumb  ov094
 *   BTLV_MCSS_IsAnySpriteBusy  0x021FFD6C  thumb  ov094
 *   BTLV_EFFECT_DeleteTask  0x021F89BC  thumb  ov094
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;

typedef struct {
    char pad[0x190];
    void *obj;          /* 0x190 */
    void *obj2;         /* 0x194 */
    char pad2[0x50];
    u32 x;              /* 0x1E8 */
    u32 a : 8;          /* 0x1EC */
    u32 b : 8;
    u32 rest : 16;
} Work;

typedef struct {
    int state;          /* 0 */
    u8 b;               /* 4 */
    int c;              /* 8 */
    int d;              /* 0xC */
} St;

extern Work *gBtlvEff;

extern void BTLV_MCSS_StartRotation(void *o, int c, u32 b, int d);
extern int BTLV_STAGE_IsAnyLayerArmed(void *o);
extern int BTLV_MCSS_IsAnySpriteBusy(void *o);
extern void BTLV_EFFECT_DeleteTask(void *h);

void BTLV_EFFECT_PokeSpriteTransitionTaskMain(void *h, St *s)
{
    int st;
    u32 m;

    st = s->state;
    switch (st) {
    case 0:
        m = gBtlvEff->a | gBtlvEff->x | gBtlvEff->b;
        if (m)
            return;
        s->state = st + 1;
    case 1:
        BTLV_MCSS_StartRotation(gBtlvEff->obj, s->c, s->b, s->d);
        s->state = s->state + 1;
        return;
    case 2:
        if (BTLV_STAGE_IsAnyLayerArmed(gBtlvEff->obj2))
            return;
        if (BTLV_MCSS_IsAnySpriteBusy(gBtlvEff->obj))
            return;
        BTLV_EFFECT_DeleteTask(h);
        return;
    }
}
