/*
 * function: BTLV_MCSS_Update
 * address: 0x021FEBAC
 * packet: pkt_ov094_021FEBAC
 * region: ov094
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * lever: enum loop counter keeps both entry guards; a separate local k for the
 *   first loop index puts idx at sp+8 and flag at sp+4 (one shared idx swapped them).
 * symbols:
 *   BTLV_MCSS_IsSpriteLoaded 0x021FFD9C thumb ov094
 *   BTLV_MCSS_FindSpriteIndex 0x022019F4 thumb ov094
 *   MCSS_RestartAnime 0x02016374 thumb
 *   MCSS_Main 0x02014C08 thumb
 *   func_0203F0A8 0x0203F0A8 arm
 *   _ull_mul 0x0209C054 arm
 *   BTLV_EFFECT_GetBitMask 0x021F935C thumb ov094
 *   BTLV_MCSS_IsAnimStopped 0x021FF2D8 thumb ov094
 *   BTLV_MCSS_StartBlinkTask 0x021FF870 thumb ov094
 *   BTLV_EFFECT_IsBusy 0x021F7EB4 thumb ov094
 *   BTLV_MCSS_GetSpriteAttrFlags 0x021FFF38 thumb ov094
 *   BTLV_EFFECT_GaugeGetSlotHealthInfo 0x021F821C thumb ov094
 *   BTLV_MCSS_StartPaletteCopy 0x021FFE24 thumb ov094
 *   BTLV_MCSS_SetBlinkMode 0x021FF260 thumb ov094
 *   BTLV_MCSS_SetAnimStopMode 0x021FF304 thumb ov094
 *   BTLV_MCSS_SetAnimSpeed 0x021FF498 thumb ov094
 *   BTLV_MCSS_StartPaletteTrans 0x021FFDF8 thumb ov094
 */
typedef unsigned char u8;
typedef unsigned int u32;
typedef unsigned long long u64;
typedef enum { KEY_0 } Key;

typedef struct {
    void *h;                /* 0x00 */
    char pad04[0x48];
    unsigned int f0 : 1;    /* 0x4c */
    unsigned int f1 : 1;
    unsigned int f2 : 5;
    unsigned int f7 : 1;
    unsigned int f8 : 1;
    unsigned int f9 : 2;
    unsigned int f11 : 1;
    int f50;                /* 0x50 */
    int f54;                /* 0x54 */
    int f58;                /* 0x58 */
} Entry;

typedef struct {
    int pad00;              /* 0x000 */
    void *obj;              /* 0x004 */
    Entry e[14];            /* 0x008 */
    unsigned int pad510 : 2;    /* 0x510 */
    unsigned int f510 : 1;
    int m514;
    int m518;
    int m51c;
    int m520;
    int m524;
    int m528;               /* 0x528 */
} Work;

extern int BTLV_MCSS_IsSpriteLoaded(char *p, int key);
extern int BTLV_MCSS_FindSpriteIndex(char *p, int key);
extern void MCSS_RestartAnime(void *h);
extern void MCSS_Main(char *self);
extern u32 func_0203F0A8(void);
extern int BTLV_EFFECT_GetBitMask(int x);
extern int BTLV_MCSS_IsAnimStopped(Work *w, int key);
extern void BTLV_MCSS_StartBlinkTask(Work *w, int key, int kind, int a, int b);
extern int BTLV_EFFECT_IsBusy(void);
extern int BTLV_MCSS_GetSpriteAttrFlags(char *p, int key);
extern int BTLV_EFFECT_GaugeGetSlotHealthInfo(int key, int *a, int *b);
extern void BTLV_MCSS_StartPaletteCopy(Work *w, int key);
extern void BTLV_MCSS_SetBlinkMode(Work *w, int key, int mode);
extern void BTLV_MCSS_SetAnimStopMode(Work *w, int key, int mode);
extern void BTLV_MCSS_SetAnimSpeed(char *p, int key, void *v);
extern void BTLV_MCSS_StartPaletteTrans(Work *w, int key, int a, int b);

void BTLV_MCSS_Update(Work *w)
{
    Key i;
    int k;
    int idx;
    int flag;
    int a;
    int b;

    for (i = 0; i < 8; i++) {
        if (BTLV_MCSS_IsSpriteLoaded((char *)w, i)) {
            k = BTLV_MCSS_FindSpriteIndex((char *)w, i);
            if (w->e[k].f11) {
                w->e[k].f11 = 0;
                MCSS_RestartAnime(w->e[k].h);
            }
        }
    }
    MCSS_Main(w->obj);
    if (w->f510 == 0) {
        for (i = 0; i < 8; i++) {
            if (BTLV_MCSS_IsSpriteLoaded((char *)w, i)
                && (u32)(((u64)func_0203F0A8() * 100) >> 32) == 0
                && (BTLV_EFFECT_GetBitMask(i) & w->m528) == 0
                && BTLV_MCSS_IsAnimStopped(w, i) == 0)
                BTLV_MCSS_StartBlinkTask(w, i, 2, 4, 1);
            if (BTLV_MCSS_IsSpriteLoaded((char *)w, i) == 0)
                continue;
            idx = BTLV_MCSS_FindSpriteIndex((char *)w, i);
            flag = 0;
            if (BTLV_EFFECT_IsBusy() && w->e[idx].f8) {
                w->e[idx].f8 = 0;
                w->e[idx].f7 = 1;
            }
            if (BTLV_EFFECT_IsBusy() && w->e[idx].f7)
                continue;
            w->e[idx].f7 = 0;
            if (BTLV_MCSS_GetSpriteAttrFlags((char *)w, i) & 4)
                continue;
            if (BTLV_EFFECT_GaugeGetSlotHealthInfo(i, &a, &b) == 0)
                continue;
            if (w->e[idx].f1 == 1) {
                if (w->e[idx].f54 == 0)
                    w->e[idx].f54 = 1;
                if (w->e[idx].f58++ > 0x18) {
                    flag = 1;
                    w->e[idx].f58 = 0;
                    w->e[idx].f50 += w->e[idx].f54;
                    if (w->e[idx].f50 == 0 || w->e[idx].f50 == 12)
                        w->e[idx].f54 *= -1;
                }
            }
            switch (b) {
            case 3:
                BTLV_MCSS_StartPaletteCopy(w, i);
                BTLV_MCSS_SetBlinkMode(w, i, 3);
                BTLV_MCSS_SetAnimStopMode(w, i, 3);
                BTLV_MCSS_SetAnimSpeed((char *)w, i, (void *)0x555);
                w->e[idx].f1 = 1;
                break;
            case 1:
                if (flag == 1)
                    BTLV_MCSS_StartPaletteTrans(w, i, (u8)w->e[idx].f50, 0x1ef);
                BTLV_MCSS_SetBlinkMode(w, i, 4);
                BTLV_MCSS_SetAnimStopMode(w, i, 3);
                w->e[idx].f1 = 1;
                break;
            case 2:
                if (flag == 1)
                    BTLV_MCSS_StartPaletteTrans(w, i, 8, 0x7def);
                BTLV_MCSS_SetBlinkMode(w, i, 4);
                BTLV_MCSS_SetAnimStopMode(w, i, 2);
                w->e[idx].f1 = 1;
                break;
            case 5:
                if (flag == 1)
                    BTLV_MCSS_StartPaletteTrans(w, i, (u8)w->e[idx].f50, 0xf);
                BTLV_MCSS_SetBlinkMode(w, i, 4);
                BTLV_MCSS_SetAnimStopMode(w, i, 3);
                w->e[idx].f1 = 1;
                break;
            case 4:
            case 7:
                if (flag == 1)
                    BTLV_MCSS_StartPaletteTrans(w, i, (u8)w->e[idx].f50, 0x3c0f);
                BTLV_MCSS_SetBlinkMode(w, i, 4);
                BTLV_MCSS_SetAnimStopMode(w, i, 3);
                w->e[idx].f1 = 1;
                break;
            case 8:
            default:
                if (w->e[idx].f1 == 1) {
                    BTLV_MCSS_StartPaletteCopy(w, i);
                    BTLV_MCSS_SetBlinkMode(w, i, 4);
                    BTLV_MCSS_SetAnimStopMode(w, i, 3);
                    BTLV_MCSS_SetAnimSpeed((char *)w, i, (void *)0x1000);
                    w->e[idx].f1 = 0;
                    w->e[idx].f54 = 0;
                    w->e[idx].f50 = 0;
                    w->e[idx].f58 = 0;
                }
                break;
            }
            if (b == 8) {
                if ((u32)(a - 2) <= 1)
                    BTLV_MCSS_SetAnimSpeed((char *)w, i, (void *)0x555);
                else
                    BTLV_MCSS_SetAnimSpeed((char *)w, i, (void *)0x1000);
            }
        }
    }
}
