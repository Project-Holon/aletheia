/*
 * function: BTLV_INPUT_ProcessTouchInput
 * address:  0x02202DC4
 * packet:   pkt_ov094_02202DC4
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   PALANM_GetFadeRequestBits  0x02021ED8  thumb
 *   KEY_GetTrg  0x020362DC  arm
 *   BTLV_EFFECT_GaugeRequestStop  0x021F8168  thumb  ov094
 *   TOUCHPANEL_HitTrg  0x02035C08  arm
 *   BTLV_INPUT_PlayCursorSe  0x02206B58  thumb  ov094
 *   BTLV_INPUT_PlaySelectSe  0x02206B30  thumb  ov094
 *   BTLV_INPUT_ProcessKeyRepeat  0x0220648C  thumb  ov094
 *   BTLV_INPUT_SetSelection  0x02206578  thumb  ov094
 *   BTLV_INPUT_ProcessButtonSelection  0x02206140  thumb  ov094
 *   KEY_GetCont  0x0203630C  arm
 *   BTLV_INPUT_PlayBackSe  0x02206BAC  thumb  ov094
 *   BTLV_INPUT_IsWazaSelectable  0x02206908  thumb  ov094
 *   d_0689E090     0x0689E090  data   ov095
 *   d_0689E0B0     0x0689E0B0  data   ov095
 *   gBtlvScdTargetRegionsSingleB     0x0689E560  data   ov095
 *   gBtlvScdTargetRegionsDoubleB     0x0689E704  data   ov095
 */
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned int u32;

typedef struct {
    char pad0[0xa];
    s8 id;              /* 0x0a */
    char padb;
} Ent;

typedef struct {
    void *key;          /* 0x00 */
    int f4;
    int *vals;          /* 0x08 */
} Cmd;

typedef struct {
    char pad0[0x50];
    int f50;            /* 0x50 */
    int f54;
    int mode;           /* 0x58 */
    char pad5c[0x64 - 0x5c];
    int f64;            /* 0x64 */
    u32 busy : 1;       /* 0x68 */
    u32 f68_1 : 30;
    u32 lock : 1;
    u32 f6c_0 : 1;      /* 0x6c */
    u32 flag : 1;
    u32 sel : 8;
    u32 f6c_10 : 22;
    int pending;        /* 0x70 */
    char pad74[0x242 - 0x74];
    u8 slot[3][8];      /* 0x242 */
    u8 en[8];           /* 0x25a */
    u8 en2[8];          /* 0x262 */
    char pad26a[0x27c - 0x26a];
    int cur;            /* 0x27c */
    int f280;           /* 0x280 */
} Obj;

extern u32 PALANM_GetFadeRequestBits(const char *ptr);
extern u32 KEY_GetTrg(void);
extern void BTLV_EFFECT_GaugeRequestStop(void);
extern int TOUCHPANEL_HitTrg(const void *p);
extern void BTLV_INPUT_PlayCursorSe(char *p);
extern void BTLV_INPUT_PlaySelectSe(char *p);
extern int BTLV_INPUT_ProcessKeyRepeat(char *p);
extern int BTLV_INPUT_SetSelection(char *s, int a, int b);
extern int BTLV_INPUT_ProcessButtonSelection(Obj *o, Cmd *c, int x, int y, int k, int z);
extern unsigned int KEY_GetCont(void);
extern void BTLV_INPUT_PlayBackSe(char *p);
extern int BTLV_INPUT_IsWazaSelectable(char *p, char *q, int i);

extern u8 d_0689E090[][15];
extern u8 d_0689E0B0[][15];
extern Ent *gBtlvScdTargetRegionsSingleB[][15];
extern Ent *gBtlvScdTargetRegionsDoubleB[][15];

int BTLV_INPUT_ProcessTouchInput(Obj *o, Cmd *c, int x)
{
    int r;
    int k;
    u32 keys;
    int ret;
    int i;
    int cnt;
    int idx;
    Ent *e;
    int mode;

    if (o->busy || PALANM_GetFadeRequestBits((const char *)o->f64) != 0 || o->lock)
        return -1;
    ret = o->pending;
    if (ret != -1) {
        o->flag = 0;
        o->pending = -1;
        return ret;
    }
    if (KEY_GetTrg() & 8) {
        if ((u32)(o->mode - 1) <= 2)
            BTLV_EFFECT_GaugeRequestStop();
    }
    if (o->mode == 6) {
        r = TOUCHPANEL_HitTrg(c->key);
        if (r != -1) {
            if (o->en[r] == 0)
                r = -1;
            else if (r == 2)
                BTLV_INPUT_PlayCursorSe((char *)o);
            else
                BTLV_INPUT_PlaySelectSe((char *)o);
        } else {
            r = BTLV_INPUT_ProcessKeyRepeat((char *)o);
        }
        if (r != -1)
            r = BTLV_INPUT_SetSelection((char *)o, r, c->vals[r]);
        return r;
    }

    k = TOUCHPANEL_HitTrg(c->key);
    r = BTLV_INPUT_ProcessButtonSelection(o, c, x, 0, k, o->f280);
    if (r != -1) {
        keys = KEY_GetCont();
        if (o->en[r] == 0 && (!(keys & 0x200) || o->mode != 2)) {
            if (o->en2[r] != 0 && o->mode == 2)
                BTLV_INPUT_PlayBackSe((char *)o);
            r = -1;
        } else if (r < 4 && (keys & 0x200) && o->mode == 2 && o->f280 == 1) {
            r = -1;
        } else if (r < 4 && (keys & 0x200) && o->mode == 2 && o->en2[r] == 0) {
            r = -1;
        } else if (k != -1) {
            if (BTLV_INPUT_IsWazaSelectable((char *)o, (char *)c, r) == 0 && !o->flag) {
                BTLV_INPUT_PlaySelectSe((char *)o);
                mode = o->mode;
                switch (mode) {
                case 1:
                case 2:
                case 5:
                    o->slot[o->cur][mode] = r;
                    break;
                case 3:
                    idx = 0;
                    if (o->f50 != 2)
                        cnt = d_0689E090[o->cur][o->sel];
                    else
                        cnt = d_0689E0B0[o->cur][o->sel];
                    if (o->f50 != 2)
                        e = gBtlvScdTargetRegionsSingleB[o->cur][o->sel];
                    else
                        e = gBtlvScdTargetRegionsDoubleB[o->cur][o->sel];
                    for (i = 0; i < cnt; i++) {
                        if (r == e[i].id) {
                            idx = i;
                            break;
                        }
                    }
                    o->slot[o->cur][mode] = (o->slot[o->cur][2] << 4) | idx;
                    break;
                }
            } else {
                BTLV_INPUT_PlayCursorSe((char *)o);
            }
        }
    }
    if (r != -1)
        r = BTLV_INPUT_SetSelection((char *)o, r, c->vals[r]);
    return r;
}
