/*
 * function: BTLV_EFFECT_StartHitTask
 * address:  0x021F7D80
 * packet:   pkt_ov094_021F7D80
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   sub_02030734   0x02030734  arm
 *   func_02030DA8  0x02030DA8  arm
 *   gBtlvEff     0x0220AF20  data   ov094
 *   gBtlvEffectFileName     0x0220AC90  data   ov094  a1
 *   BTLV_MCSS_RefreshSpriteFromParty  0x021FFE48  thumb  ov094
 *   BTLV_MCSS_MakeAddWorkFromPoke  0x022003EC  thumb  ov094
 *   BTLV_EFFECT_GetBitMask  0x021F935C  thumb  ov094
 *   BTLV_EFFECT_RegisterTask  0x021F896C  thumb  ov094
 *   BTLV_EFFECT_SequenceTaskMain  0x021F8CB0  thumb  ov094
 *   BTLV_EFFECT_ClearTaskMaskM1  0x021F8EF8  thumb  ov094
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    void *owner;            /* 0x000 */
    char pad04[0x190 - 4];
    void *h190;             /* 0x190 */
    char pad194[0x1ec - 0x194];
    u32 m0 : 8;             /* 0x1ec */
    u32 m1 : 8;
    u32 mrest : 16;
    u16 heap;               /* 0x1f0 */
} Work;

typedef struct {
    int f0;
    int f4;
    int buf[9];         /* 0x08 */
} Job;

extern Work *gBtlvEff;
extern const char gBtlvEffectFileName[];

extern void *sub_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void *func_02030DA8(void *owner, void (*fn)(void *, void *), void *p, u32 a3);
extern void BTLV_MCSS_RefreshSpriteFromParty(void *h, int b, void *a);
extern void BTLV_MCSS_MakeAddWorkFromPoke(void *h, void *a, int *buf, int b);
extern int BTLV_EFFECT_GetBitMask(int a);
extern void BTLV_EFFECT_RegisterTask(void *h, void (*cb)(void *), int arg);
extern void BTLV_EFFECT_SequenceTaskMain(void *h, int *p);
extern void BTLV_EFFECT_ClearTaskMaskM1(void *);

void BTLV_EFFECT_StartHitTask(void *a, int b)
{
    Job *o;

    o = sub_02030734((u16)((gBtlvEff->heap & 0x7fff) | 0x8000), 0x2c, 0, gBtlvEffectFileName, 0x2f9);
    o->f4 = 0;
    o->f0 = b;
    BTLV_MCSS_RefreshSpriteFromParty(gBtlvEff->h190, b, a);
    BTLV_MCSS_MakeAddWorkFromPoke(gBtlvEff->h190, a, o->buf, b);
    gBtlvEff->m1 |= BTLV_EFFECT_GetBitMask(b);
    BTLV_EFFECT_RegisterTask(func_02030DA8(gBtlvEff->owner, (void (*)(void *, void *))BTLV_EFFECT_SequenceTaskMain, o, 0), BTLV_EFFECT_ClearTaskMaskM1, 0);
}
