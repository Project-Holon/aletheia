/*
 * function: BTLV_MCSS_StartRotation
 * address:  0x02200344
 * packet:   pkt_ov094_02200344
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
 *   BTLV_EFFECT_RegisterTask  0x021F896C  thumb  ov094
 *   BTLV_MCSS_RotationTaskMain  0x02201408  thumb  ov094
 *   BTLV_MCSS_RotationTaskEnd  0x02201700  thumb  ov094
 *   gBtlvMcssSourceFileName     0x0220AE7C  data   ov094  a1
 */
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    void *owner;            /* 0x000 */
    char pad004[0x510 - 4];
    u32 flags;              /* 0x510 */
    char pad514[0x540 - 0x514];
    u16 heap;               /* 0x540 */
} Work;

typedef struct {
    Work *w;                /* 0x00 */
    u32 a : 31;             /* 0x04 */
    u32 flag : 1;
    int f8;                 /* 0x08 */
    int fc;                 /* 0x0c */
} Obj;

extern const char gBtlvMcssSourceFileName[];
extern void *GFL_HEAP_Alloc(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void *func_02030DA8(void *owner, void *fn, void *p, u32 a3);
extern void BTLV_EFFECT_RegisterTask(void *h, void (*cb)(void *), int arg);
extern void BTLV_MCSS_RotationTaskMain(void *h);
extern void BTLV_MCSS_RotationTaskEnd(void *h);

void BTLV_MCSS_StartRotation(Work *w, int a, int b, int flag)
{
    Obj *o = GFL_HEAP_Alloc((u16)((w->heap & 0x7fff) | 0x8000), 0x24, 0, gBtlvMcssSourceFileName, 0x8f2);

    o->w = w;
    o->a = 0;
    o->flag = flag;
    o->f8 = a;
    o->fc = b;
    w->flags |= 4;
    BTLV_EFFECT_RegisterTask(func_02030DA8(w->owner, BTLV_MCSS_RotationTaskMain, o, 0), BTLV_MCSS_RotationTaskEnd, 2);
}
