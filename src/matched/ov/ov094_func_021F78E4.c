/*
 * function: BTLV_EFFECT_Main
 * address:  0x021F78E4
 * packet:   pkt_ov094_021F78E4
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * volatile: 0x021F7980 0x021F7986 (0x04000604 read twice, results unused)
 *
 * symbols:
 *   TCB_Main  0x02030D28  arm
 *   G3D_SYSTEM_DrawStart  0x02047964  arm
 *   G3D_SYSTEM_ApplyLookAt  0x020479D8  arm
 *   PARTICLE_Main  0x02050BE8  arm
 *   G3D_SYSTEM_DrawEnd  0x02047970  arm
 *   gBtlvEff     0x0220AF20  data   ov094
 *   BTLV_EFFVM_Main  0x021F9478  thumb  ov094
 *   BTLV_EFFECT_UpdateIntroInput  0x021F903C  thumb  ov094
 *   BTLV_MCSS_Update  0x021FEBAC  thumb  ov094
 *   BTLV_STAGE_UpdateLayerAnims  0x021F6934  thumb  ov094
 *   BTLV_FIELD_UpdateAnims  0x021F6D5C  thumb  ov094
 *   BTLV_CAMERA_UpdateMove  0x021F6ED4  thumb  ov094
 *   BTLV_GAUGE_FlashTaskMain  0x02206EB4  thumb  ov094
 *   BTLV_CLACT_Draw  0x02201AF0  thumb  ov094
 *   BTLV_STAGE_DrawLayers  0x021F69B0  thumb  ov094
 *   BTLV_FIELD_Draw  0x021F6DD4  thumb  ov094
 *   BTLV_MCSS_Draw  0x021FEE9C  thumb  ov094
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    void *owner;            /* 0x000 */
    char pad04[0x188 - 4];
    void *h188;             /* 0x188 */
    void *h18c;
    void *h190;             /* 0x190 */
    void *h194;
    void *h198;
    void *h19c;
    void *h1a0;
    void *h1a4;
    char pad1a8[0x1e8 - 0x1a8];
    int f1e8;               /* 0x1e8 */
} Work;

extern Work *gBtlvEff;

struct Ctx;
struct W;
extern void TCB_Main(struct Ctx *c);
extern void G3D_SYSTEM_DrawStart(void);
extern void G3D_SYSTEM_ApplyLookAt(void);
extern void PARTICLE_Main(void);
extern void G3D_SYSTEM_DrawEnd(void);
extern int BTLV_EFFVM_Main(void *);
extern void BTLV_EFFECT_UpdateIntroInput(void);
extern void BTLV_MCSS_Update(void *);
extern void BTLV_STAGE_UpdateLayerAnims(void *);
extern void BTLV_FIELD_UpdateAnims(void *);
extern void BTLV_CAMERA_UpdateMove(int *p);
extern void BTLV_GAUGE_FlashTaskMain(struct W *p);
extern void BTLV_CLACT_Draw(void *);
extern void BTLV_STAGE_DrawLayers(void *);
extern void BTLV_FIELD_Draw(void *);
extern void BTLV_MCSS_Draw(int *p);

#define REG_04000604 (*(volatile u16 *)0x04000604)

void BTLV_EFFECT_Main(void)
{
    if (gBtlvEff != 0) {
        gBtlvEff->f1e8 = BTLV_EFFVM_Main(gBtlvEff->h188);
        BTLV_EFFECT_UpdateIntroInput();
        TCB_Main(gBtlvEff->owner);
        BTLV_MCSS_Update(gBtlvEff->h190);
        BTLV_STAGE_UpdateLayerAnims(gBtlvEff->h194);
        BTLV_FIELD_UpdateAnims(gBtlvEff->h198);
        BTLV_CAMERA_UpdateMove(gBtlvEff->h19c);
        BTLV_GAUGE_FlashTaskMain(gBtlvEff->h1a4);
        BTLV_CLACT_Draw(gBtlvEff->h1a0);
        G3D_SYSTEM_DrawStart();
        G3D_SYSTEM_ApplyLookAt();
        BTLV_STAGE_DrawLayers(gBtlvEff->h194);
        BTLV_FIELD_Draw(gBtlvEff->h198);
        BTLV_MCSS_Draw(gBtlvEff->h190);
        REG_04000604;
        PARTICLE_Main();
        REG_04000604;
        G3D_SYSTEM_DrawEnd();
    }
}
