/*
 * function: BTLV_EFFECT_Init
 * address:  0x021F7544
 * packet:   pkt_ov094_021F7544
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * note:     the two BTLV_FIELD_Create calls and the two f244 stores are written per arm;
 *           the compiler tail-merges them, which is what keeps the 0x194-based
 *           offsets and the reload of &gBtlvEff seen in the listing.
 *
 * symbols:
 *   sub_02030734   0x02030734  arm
 *   func_02030CB0  0x02030CB0  arm
 *   func_02030CBC  0x02030CBC  arm
 *   func_020307B0  0x020307B0  arm
 *   gBtlvEff     0x0220AF20  data   a4
 *   gBtlvEffectFileName     0x0220AC90  data   a1
 *   BTLV_EFFVM_Create  0x021F93F4  thumb  ov094
 *   PALANM_Create  0x02021518  thumb
 *   PALANM_SetAutoTransfer  0x02021EE4  thumb
 *   PALANM_AllocSlotBuffers  0x0202155C  thumb
 *   BTLV_MCSS_Create  0x021FEAC0  thumb  ov094
 *   ARC_TOOL_LoadMember  0x02048F60  arm
 *   BTLV_STAGE_Create  0x021F6560  thumb  ov094
 *   BTL_MAIN_CheckSetupStatusFlag  0x021BA1A8  thumb  ov093
 *   BTLV_FIELD_Create  0x021F6B04  thumb  ov094
 *   func_0201493C  0x0201493C  thumb
 *   G3D_SYSTEM_SetLight  0x02046A94  arm
 *   BTLV_CAMERA_Create  0x021F6E3C  thumb  ov094
 *   BTLV_CLACT_Create  0x02201A8C  thumb  ov094
 *   BTLV_GAUGE_Create  0x02206BC8  thumb  ov094
 *   BTLV_TIMER_Create  0x02209224  thumb  ov094
 *   BTLV_BG_Create  0x0220975C  thumb  ov094
 *   BTLV_MCSS_EnableOrthoMode  0x021FF16C  thumb  ov094
 *   PARTICLE_InitManager  0x02050B80  arm
 *   func_020056A0  0x020056A0  thumb
 *   PM_VOICE_AllocBuffers  0x02006674  thumb
 *   BTLV_EFFECT_VBlankTask  0x021F8B90  thumb  ov094
 */

#include "../include/G_0220AF20.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;

typedef struct {
    int f0;          /* 0x00 */
    int f4;          /* 0x04 */
    int f8;          /* 0x08 */
    int fc;          /* 0x0c */
    u8 f10;          /* 0x10 */
    u8 f11;          /* 0x11 */
    u16 f12;         /* 0x12 */
    u8 f14;          /* 0x14 */
    u8 f15;          /* 0x15 */
    char pad16[0x28 - 0x16];
    void *battle;    /* 0x28 */
} Param;

typedef struct {
    void *owner;     /* 0x000 */
    void *buf;       /* 0x004 */
    char pad08[0x188 - 8];
    void *h188;      /* 0x188 */
    int h18c;        /* 0x18c */
    void *h190;      /* 0x190 */
    void *h194;      /* 0x194 */
    void *h198;      /* 0x198 */
    void *h19c;      /* 0x19c */
    void *h1a0;      /* 0x1a0 */
    void *h1a4;      /* 0x1a4 */
    char pad1a8[8];
    void *h1b0;      /* 0x1b0 */
    void *h1b4;      /* 0x1b4 */
    void *h1b8;      /* 0x1b8 */
    Param param;     /* 0x1bc */
    int f1e8;        /* 0x1e8 */
    char pad1ec[4];
    u16 heap;        /* 0x1f0 */
    char pad1f2[6];
    int slots[8];    /* 0x1f8 */
    char pad218[0x244 - 0x218];
    int f244;        /* 0x244 */
    int f248;        /* 0x248 */
} Work;

typedef struct {
    u8 f0;
    u8 f1;
    u8 a2[0x13 - 2];
    u8 a13[0x24 - 0x13];
} Entry;

typedef struct {
    s16 x;
    s16 y;
    s16 z;
    u16 w;
} Rect;

extern struct G_0220AF20 *gBtlvEff;
extern const char gBtlvEffectFileName[];

extern void *sub_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern unsigned func_02030CB0(unsigned);
struct Ctx;
struct Res;
extern struct Ctx *func_02030CBC(u32 capacity, struct Ctx *c);
extern u32 func_020307B0(void *p);
extern void *BTLV_EFFVM_Create(void *a, u32 b);
struct Obj02021EE4;
struct PalAnmSlot;
extern void *PALANM_Create(u32 heap);
extern void PALANM_SetAutoTransfer(struct Obj02021EE4 *o, int v);
extern void PALANM_AllocSlotBuffers(struct PalAnmSlot *slots, u32 idx, u32 size, u32 heap);
extern void *BTLV_MCSS_Create(int mode, void *a1, u16 a2);
extern void *ARC_TOOL_LoadMember(u32 archive_id, u32 member, u32 heap);
extern void *BTLV_STAGE_Create(int, u8, u8, u16);
extern int BTL_MAIN_CheckSetupStatusFlag(char **p, int m);
extern void *BTLV_FIELD_Create(int unused, int group, u8 variant, u16 heap);
extern void func_0201493C(u32 id, u32 a1, u32 a2, u32 a3, u32 b0, u16 *b1, u16 heap);
extern void G3D_SYSTEM_SetLight(u32 idx, const u16 *src);
extern void *BTLV_CAMERA_Create(void *a, u16 b);
extern struct Res *BTLV_CLACT_Create(void *owner, u16 heap);
extern void *BTLV_GAUGE_Create(int, u16);
extern void *BTLV_TIMER_Create(u16 heap);
extern void *BTLV_BG_Create(void *a, u16 heap);
extern void BTLV_MCSS_EnableOrthoMode(void *);
extern void PARTICLE_InitManager(u32);
extern void *func_020056A0(void (*cb)(void), void *ctx, int pri);
extern void PM_VOICE_AllocBuffers(int n, u32 heap);
extern void BTLV_EFFECT_VBlankTask(void);

void BTLV_EFFECT_Init(Param *p, int arg, u16 heap)
{
    Work *w;
    Entry *tbl;
    u8 v;
    int i;
    Rect r;
    u16 out[10];

    w = sub_02030734(heap, sizeof(Work), 1, gBtlvEffectFileName, 0x116);
    gBtlvEff = (struct G_0220AF20 *)(w);
    w->param = *p;
    w->heap = heap;
    gBtlvEff->buf = sub_02030734(heap, func_02030CB0(0x20), 1, gBtlvEffectFileName, 0x11c);
    gBtlvEff->owner = func_02030CBC(0x20, gBtlvEff->buf);
    gBtlvEff->h188 = BTLV_EFFVM_Create(gBtlvEff->owner, heap);
    gBtlvEff->h18c = (int)PALANM_Create(heap);
    PALANM_SetAutoTransfer((struct Obj02021EE4 *)gBtlvEff->h18c, 1);
    PALANM_AllocSlotBuffers((struct PalAnmSlot *)gBtlvEff->h18c, 0, 0x200, heap);
    PALANM_AllocSlotBuffers((struct PalAnmSlot *)gBtlvEff->h18c, 1, 0x1e0, heap);
    PALANM_AllocSlotBuffers((struct PalAnmSlot *)gBtlvEff->h18c, 2, 0x200, heap);
    PALANM_AllocSlotBuffers((struct PalAnmSlot *)gBtlvEff->h18c, 3, 0x1e0, heap);
    v = 0;
    gBtlvEff->h190 = BTLV_MCSS_Create(p->f0, gBtlvEff->owner, heap);
    tbl = ARC_TOOL_LoadMember(0x98, 0, (u16)((gBtlvEff->heap & 0x7fff) | 0x8000));
    if (tbl[p->f8].f1 != 0) {
        v = p->f11;
    }
    gBtlvEff->h194 = BTLV_STAGE_Create(p->f0, tbl[p->f8].a13[p->fc], v, heap);
    if (gBtlvEff->param_battle != 0) {
        gBtlvEff->h198 = BTLV_FIELD_Create(BTL_MAIN_CheckSetupStatusFlag(gBtlvEff->param_battle, 0x400), tbl[p->f8].a2[p->fc], v, heap);
    } else {
        gBtlvEff->h198 = BTLV_FIELD_Create(0, tbl[p->f8].a2[p->fc], v, heap);
    }
    if (tbl[p->f8].f0 != 0) {
        func_0201493C(p->f12, p->f14, p->f15, p->f10, p->f11, out, gBtlvEff->heap);
        r.w = out[0];
        r.x = 0;
        r.y = -0x1000;
        r.z = 0;
        G3D_SYSTEM_SetLight(0, (const u16 *)(&r));
    }
    func_020307B0(tbl);
    gBtlvEff->h19c = BTLV_CAMERA_Create(gBtlvEff->owner, heap);
    gBtlvEff->h1a0 = BTLV_CLACT_Create(gBtlvEff->owner, heap);
    gBtlvEff->h1a4 = BTLV_GAUGE_Create(arg, heap);
    gBtlvEff->h1b0 = BTLV_TIMER_Create(heap);
    gBtlvEff->h1b4 = BTLV_BG_Create(gBtlvEff->owner, heap);
    BTLV_MCSS_EnableOrthoMode(gBtlvEff->h190);
    PARTICLE_InitManager(heap);
    for (i = 0; i < 8; i++) {
        gBtlvEff->slots[i] = -1;
    }
    if (gBtlvEff->param_battle != 0) {
        if (BTL_MAIN_CheckSetupStatusFlag(gBtlvEff->param_battle, 0x800)) {
            gBtlvEff->f244 = 300;
        } else {
            gBtlvEff->f244 = 900;
        }
    }
    gBtlvEff->h1b8 = func_020056A0(BTLV_EFFECT_VBlankTask, 0, 1);
    PM_VOICE_AllocBuffers(2, gBtlvEff->heap);
}
