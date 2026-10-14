/*
 * function: BTLV_INPUT_ProcessKeyInput
 * address:  0x022030F0
 * packet:   pkt_ov094_022030F0
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   sec_0220A380   0x0220A380  data
 *   d_0220A380     0x0220A380  data
 *   d_0220AE98     0x0220AE98  data
 *   d_0220AEA4     0x0220AEA4  data
 *   PALANM_GetFadeRequestBits  0x02021ED8  thumb
 *   KEY_GetTrg  0x020362DC  arm
 *   BTLV_EFFECT_GaugeRequestStop  0x021F8168  thumb  ov094
 *   PALANM_RequestFadeOverwrite  0x02021848  thumb
 *   BTLV_INPUT_PlayPageSe  0x02206B74  thumb  ov094
 *   BTLV_INPUT_StartScreenTransition  0x02204B0C  thumb  ov094
 *   TOUCHPANEL_HitTrg  0x02035C08  arm
 *   BTL_POKEPARAM_IsTransformed  0x021D6D54  thumb  ov093
 *   BTLV_INPUT_ProcessButtonSelection  0x02206140  thumb  ov094
 *   KEY_GetCont  0x0203630C  arm
 *   BTLV_INPUT_PlayBackSe  0x02206BAC  thumb  ov094
 *   BTLV_INPUT_IsWazaSelectable  0x02206908  thumb  ov094
 *   BTLV_INPUT_PlayOpenSe  0x02206B90  thumb  ov094
 *   BTLV_INPUT_PlayCursorSe  0x02206B58  thumb  ov094
 *   BTLV_INPUT_SetSelection  0x02206578  thumb  ov094
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct Main {
    void *owner;
    unsigned char pad04[0x58 - 4];
    int f58;
    unsigned char pad5c[0x64 - 0x5c];
    int f64;
    u32 b0 : 1;
    u32 lo : 4;
    u32 f5 : 4;
    u32 mid : 10;
    u32 mode : 2;
    u32 hi : 10;
    u32 b31 : 1;
    u32 f6c;
    int f70;
    unsigned char pad74[0x220 - 0x74];
    int f220;
    unsigned char pad224[0x242 - 0x224];
    u8 tbl[3][8];
    u8 b25a[8];
    u8 b262[4];
    unsigned char pad266[0x27c - 0x266];
    int f27c;
    unsigned char pad280[0x2a4 - 0x280];
    void *f2a4[3];
} Main;

typedef struct Desc {
    void *a;
    void *b;
    const int *c;
} Desc;

/* The rodata objects at 0x0220A380..0x0220A3B4 are one section to the compiler: loads go
 * through the section base (sec_0220A380 + field) and addresses taken get their own words;
 * the 3-byte object at the section start is a second name at the same address. */
typedef struct Sec {
    u8 b0[3];
    u8 key[3];
    u8 pal[3][2];
    u8 mode[3][2];
    u16 h[5];
    Desc da;
    Desc db;
} Sec;

extern const Sec sec_0220A380;
extern const u8 d_0220A380[3];
extern void *const d_0220AE98[];
extern void *const d_0220AEA4[];

extern u32 PALANM_GetFadeRequestBits(const char *ptr);
extern u32 KEY_GetTrg(void);
extern void BTLV_EFFECT_GaugeRequestStop(void);
extern void PALANM_RequestFadeOverwrite(int a, int b, u16 c, int d, int e, int f, int g, void *h);
extern void BTLV_INPUT_PlayPageSe(char *p);
extern void BTLV_INPUT_StartScreenTransition(Main *m, int c);
extern int TOUCHPANEL_HitTrg(const void *p);
struct R5;
extern int BTL_POKEPARAM_IsTransformed(struct R5 *p);
extern int BTLV_INPUT_ProcessButtonSelection(Main *m, const Desc *d, void *t, const u8 *k, int a, int b);
extern unsigned int KEY_GetCont(void);
extern void BTLV_INPUT_PlayBackSe(char *p);
extern int BTLV_INPUT_IsWazaSelectable(char *p, char *q, int i);
extern void BTLV_INPUT_PlayOpenSe(char *p);
extern void BTLV_INPUT_PlayCursorSe(char *p);
extern int BTLV_INPUT_SetSelection(char *s, int a, int b);

int BTLV_INPUT_ProcessKeyInput(Main *m, u8 *key, int *out)
{
    int i;
    int a;
    u32 held;
    int r;

    if (m->b0 || PALANM_GetFadeRequestBits((const char *)m->f64) != 0 || m->b31)
        return 0;
    if (KEY_GetTrg() & 8)
        BTLV_EFFECT_GaugeRequestStop();
    if (m->f70 != -1) {
        i = m->f70 & 0xFFFF7FFF;
        if (i < 5) {
            if (i < 4 && m->f220 == 1)
                m->f70 = 7;
            *out = m->f70;
            *key = sec_0220A380.key[m->mode];
            m->f70 = -1;
            m->f6c &= ~2;
            PALANM_RequestFadeOverwrite(m->f64, 2, 0x3e00, 0, 0, 0, 0, m->owner);
            PALANM_RequestFadeOverwrite(m->f64, 8, 0x700, 0, 0, 0, 0, m->owner);
            return 1;
        }
        m->f5 = 0;
        m->tbl[m->f27c][m->f58] = 0;
        m->f6c &= ~2;
        BTLV_INPUT_PlayPageSe((char *)m);
        BTLV_INPUT_StartScreenTransition(m, i);
        m->f70 = -1;
        return 0;
    }
    if (m->f220 == 1) {
        a = TOUCHPANEL_HitTrg(sec_0220A380.db.a);
        i = BTLV_INPUT_ProcessButtonSelection(m, &sec_0220A380.db, d_0220AE98[m->mode], 0, a, BTL_POKEPARAM_IsTransformed(m->f2a4[m->mode]));
    } else {
        a = TOUCHPANEL_HitTrg(sec_0220A380.da.a);
        i = BTLV_INPUT_ProcessButtonSelection(m, &sec_0220A380.da, d_0220AEA4[m->mode], d_0220A380, a, BTL_POKEPARAM_IsTransformed(m->f2a4[m->mode]));
    }
    if (i != -1) {
        held = KEY_GetCont();
        if (m->b25a[i] == 0 && !(held & 0x200)) {
            if (m->b262[i] != 0)
                BTLV_INPUT_PlayBackSe((char *)m);
            i = -1;
        } else if (i > 4 && m->b25a[i] == 0) {
            i = -1;
        } else if (i < 4 && (held & 0x200) && (BTL_POKEPARAM_IsTransformed(m->f2a4[m->mode]) == 1 || m->f220 == 1)) {
            i = -1;
        } else if (i < 4 && (held & 0x200) && m->b262[i] == 0) {
            i = -1;
        }
    }
    if (i != -1) {
        if (m->f220 == 1) {
            r = BTLV_INPUT_IsWazaSelectable((char *)m, (char *)(&sec_0220A380.db), i);
            if (r == 0 && !(m->f6c << 30 >> 31)) {
                m->tbl[m->f27c][m->f58] = i;
                BTLV_INPUT_PlayOpenSe((char *)m);
            } else if (r == 1 && !(m->f6c << 30 >> 31)) {
                BTLV_INPUT_PlayCursorSe((char *)m);
            }
            i = BTLV_INPUT_SetSelection((char *)m, i, sec_0220A380.db.c[i]);
        } else {
            r = BTLV_INPUT_IsWazaSelectable((char *)m, (char *)(&sec_0220A380.da), i);
            if (r == 0 && !(m->f6c << 30 >> 31)) {
                m->tbl[m->f27c][m->f58] = i;
                BTLV_INPUT_PlayOpenSe((char *)m);
            } else if (r == 1 && !(m->f6c << 30 >> 31)) {
                BTLV_INPUT_PlayCursorSe((char *)m);
            }
            i = BTLV_INPUT_SetSelection((char *)m, i, sec_0220A380.da.c[i]);
        }
    }
    if (i != -1)
        return 1;
    return 0;
}
