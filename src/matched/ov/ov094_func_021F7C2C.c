/*
 * function: BTLV_EFFECT_StartDamageTintTask
 * address:  0x021F7C2C
 * packet:   pkt_ov094_021F7C2C
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * witness: arm9 WAZA_TOOL_GetDamageType filed as src/matched/arm9/WAZA_TOOL_GetDamageType.c.
 *
 * symbols:
 *   GFL_HEAP_Alloc   0x02030734  arm
 *   func_02030DA8  0x02030DA8  arm
 *   WAZA_TOOL_GetDamageType  0x0201C1E8  thumb
 *   gBtlvEff     0x0220AF20  data   ov094
 *   gBtlvEffectFileName     0x0220AC90  data   ov094  a1
 *   BTLV_MCSS_IsVanished  0x021FF348  thumb  ov094
 *   BTLV_EFFECT_GetBitMask  0x021F935C  thumb  ov094
 *   BTLV_EFFECT_RegisterTask  0x021F896C  thumb  ov094
 *   BTLV_EFFECT_DamageTintTaskMain  0x021F8BAC  thumb  ov094
 *   BTLV_EFFECT_ClearTaskMaskM0  0x021F8C78  thumb  ov094
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    void *owner;            /* 0x000 */
    char pad04[0x190 - 4];
    void *h190;             /* 0x190 */
    char pad194[0x1ec - 0x194];
    u32 m : 8;              /* 0x1ec */
    u32 mrest : 24;
    u16 heap;               /* 0x1f0 */
} Work;

typedef struct {
    int f0;
    int f4;
    int f8;
    int fc;
    int f10;
    int f14;
} Job;

extern Work *gBtlvEff;
extern const char gBtlvEffectFileName[];

extern void *GFL_HEAP_Alloc(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void *func_02030DA8(void *owner, void (*fn)(void *, void *), void *p, u32 a3);
extern int WAZA_TOOL_GetDamageType(int);
extern int BTLV_MCSS_IsVanished(void *h, int a);
extern int BTLV_EFFECT_GetBitMask(int a);
extern void BTLV_EFFECT_RegisterTask(void *h, void (*cb)(void *), int arg);
extern void BTLV_EFFECT_DamageTintTaskMain(void *h, int *p);
extern void BTLV_EFFECT_ClearTaskMaskM0(void *);

void BTLV_EFFECT_StartDamageTintTask(int a, int b)
{
    Job *o;

    o = GFL_HEAP_Alloc((u16)((gBtlvEff->heap & 0x7fff) | 0x8000), 0x18, 0, gBtlvEffectFileName, 0x29b);
    o->f4 = 0;
    o->f0 = a;
    o->f8 = 3;
    o->fc = 0;
    o->f14 = BTLV_MCSS_IsVanished(gBtlvEff->h190, a);
    if (WAZA_TOOL_GetDamageType(b) == 1)
        o->f10 = 0x842;
    else
        o->f10 = 0x6318;
    gBtlvEff->m |= BTLV_EFFECT_GetBitMask(a);
    BTLV_EFFECT_RegisterTask(func_02030DA8(gBtlvEff->owner, (void (*)(void *, void *))BTLV_EFFECT_DamageTintTaskMain, o, 0), BTLV_EFFECT_ClearTaskMaskM0, 0);
}
