/*
 * function: BTLV_EFFECT_StartEffectWithRequest
 * address:  0x021F7B2C
 * packet:   pkt_ov094_021F7B2C
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GFL_HEAP_Alloc   0x02030734  arm
 *   func_02030DA8  0x02030DA8  arm
 *   gBtlvEff     0x0220AF20  data   ov094
 *   gBtlvEffectFileName     0x0220AC90  data   ov094  a1
 *   BTLV_EFFECT_IsBusy  0x021F7EB4  thumb  ov094
 *   BTLV_EFFVM_InitParams  0x021F9844  thumb  ov094
 *   BTLV_EFFVM_StartScript  0x021F94F8  thumb  ov094
 *   BTLV_EFFECT_RegisterTask  0x021F896C  thumb  ov094
 *   BTLV_EFFECT_DelayedStartEffectTaskMain  0x021F8FE8  thumb  ov094
 *   BTLV_EFFECT_FreeTaskArg  0x021F9028  thumb  ov094
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    void *owner;            /* 0x000 */
    char pad04[0x188 - 4];
    void *h188;             /* 0x188 */
    char pad18c[0x1e8 - 0x18c];
    int f1e8;               /* 0x1e8 */
    char pad1ec[4];
    u16 heap;               /* 0x1f0 */
} Work;

typedef struct {
    u8 b0, b1, b2, b3;
    int f4;
    int f8;
    u16 fc;
} Arg;

typedef struct {
    u8 b0, b1, b2;
} Small;

typedef struct {
    int f0;
    int f4;
    int f8;
    int fc;
    Small *s;           /* 0x10 */
} Job;

typedef struct {
    u16 h0;
    int f4;
    int f8;
    u8 c;               /* 0x0c */
    u8 d;               /* 0x0d */
    int f10;
} Req;

extern Work *gBtlvEff;
extern const char gBtlvEffectFileName[];

extern void *GFL_HEAP_Alloc(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void *func_02030DA8(void *owner, void (*fn)(void *, void *), void *p, u32 a3);
extern int BTLV_EFFECT_IsBusy(void);
extern void BTLV_EFFVM_InitParams(Arg *a);
extern void BTLV_EFFVM_StartScript(void *h, int a, u32 b, u16 c, Arg *d);
extern void BTLV_EFFECT_RegisterTask(void *h, void (*cb)(void *), int arg);
extern void BTLV_EFFECT_DelayedStartEffectTaskMain(void *, void *);
extern void BTLV_EFFECT_FreeTaskArg(void *);

void BTLV_EFFECT_StartEffectWithRequest(const Req *r)
{
    Job *o;
    Arg l;

    if (BTLV_EFFECT_IsBusy() == 0) {
        BTLV_EFFVM_InitParams(&l);
        l.b0 = r->f10;
        l.b1 = r->c;
        l.b2 = r->d;
        BTLV_EFFVM_StartScript(gBtlvEff->h188, r->f4, r->f8, r->h0, &l);
        gBtlvEff->f1e8 = 1;
        return;
    }
    o = GFL_HEAP_Alloc(gBtlvEff->heap, 0x14, 1, gBtlvEffectFileName, 0x26b);
    o->s = GFL_HEAP_Alloc(gBtlvEff->heap, 0x10, 1, gBtlvEffectFileName, 0x26c);
    o->f4 = r->f4;
    o->f8 = r->f8;
    o->fc = r->h0;
    o->s->b0 = r->f10;
    o->s->b1 = r->c;
    o->s->b2 = r->d;
    BTLV_EFFECT_RegisterTask(func_02030DA8(gBtlvEff->owner, BTLV_EFFECT_DelayedStartEffectTaskMain, o, 0), BTLV_EFFECT_FreeTaskArg, 0);
}
