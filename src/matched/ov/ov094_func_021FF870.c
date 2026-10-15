/*
 * function: BTLV_MCSS_StartBlinkTask
 * address:  0x021FF870
 * packet:   pkt_ov094_021FF870
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
 *   BTLV_EFFECT_GetBitMask  0x021F935C  thumb  ov094
 *   BTLV_MCSS_SetBlinkMode  0x021FF260  thumb  ov094
 *   BTLV_MCSS_BlinkTaskMain  0x02200CD0  thumb  ov094
 *   BTLV_MCSS_BlinkTaskEnd  0x02200D30  thumb  ov094
 *   gBtlvMcssSourceFileName     0x0220AE7C  data   ov094  a1
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    void *owner;            /* 0x000 */
    char pad04[0x520 - 4];
    int mask[4];            /* 0x520 */
    char pad530[0x540 - 0x530];
    u16 heap;               /* 0x540 */
    char pad542[0x588 - 0x542];
    u8 cnt[4][14];          /* 0x588 */
} Work;

typedef struct {
    Work *w;                /* 0x00 */
    int i;                  /* 0x04 */
    char pad08[0x0c];
    int kind;               /* 0x14 */
    char pad18[0x2c];
    int f44;                /* 0x44 */
    int f48;                /* 0x48 */
    int f4c;                /* 0x4c */
    int f50;                /* 0x50 */
} Obj;

extern const char gBtlvMcssSourceFileName[];
extern void *GFL_HEAP_Alloc(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void *func_02030DA8(void *owner, void *fn, void *p, u32 a3);
extern void BTLV_EFFECT_RegisterTask(void *h, void (*cb)(void *), int arg);
extern int BTLV_EFFECT_GetBitMask(int x);
extern void BTLV_MCSS_SetBlinkMode(Work *w, int key, int flag);
extern void BTLV_MCSS_BlinkTaskMain(void);
extern void BTLV_MCSS_BlinkTaskEnd(void *p);

void BTLV_MCSS_StartBlinkTask(Work *w, int key, int kind, int a, int b)
{
    Obj *o;

    switch (kind) {
    case 3:
        BTLV_MCSS_SetBlinkMode(w, key, 1);
        return;
    case 4:
        BTLV_MCSS_SetBlinkMode(w, key, 0);
        return;
    case 2:
        o = GFL_HEAP_Alloc((u16)((w->heap & 0x7fff) | 0x8000), 0x54, 0, gBtlvMcssSourceFileName, 0x5e5);
        o->w = w;
        o->i = key;
        o->kind = kind;
        o->f44 = 0;
        o->f48 = a;
        o->f4c = b * 2;
        w->cnt[0][key]++;
        o->f50 = w->cnt[0][key];
        BTLV_EFFECT_RegisterTask(func_02030DA8(w->owner, (void *)BTLV_MCSS_BlinkTaskMain, o, 0), BTLV_MCSS_BlinkTaskEnd, 2);
        w->mask[2] |= BTLV_EFFECT_GetBitMask(key);
        return;
    }
}
