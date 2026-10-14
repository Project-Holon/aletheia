/*
 * function: BTLV_INPUT_StartScreenTransition
 * address:  0x02204B0C
 * packet:   pkt_ov094_02204B0C
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   d_0220AEB0     0x0220AEB0  data   ov094  a1
 *   d_0220A38C     0x0220A38C  data   ov094  a1
 *   d_0220A3E4     0x0220A3E4  data   ov094  a4
 *   func_02030734  0x02030734  arm
 *   func_02030DA8  0x02030DA8  arm
 *   BTLV_INPUT_ScreenResetTask  0x022042E4  thumb  ov094
 *   BTLV_INPUT_TaskEndClearBusyBit  0x022043AC  thumb  ov094
 *   BTLV_INPUT_RegisterTask  0x0220684C  thumb  ov094
 *   BTLV_EFFECT_ResetIntroState  0x021F8AC0  thumb  ov094
 *   BTLV_EFFECT_StartEffect  0x021F7998  thumb  ov094
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct Main {
    void *owner;
    unsigned char pad04[0x68 - 4];
    u32 b0 : 1;
    u32 lo : 18;
    u32 mode : 2;
    u32 hi : 11;
    unsigned char pad6c[0x240 - 0x6c];
    u16 h240;
} Main;

typedef struct Obj {
    Main *main;
} Obj;

extern const char d_0220AEB0[];
extern const u8 d_0220A38C[][2];
extern const int d_0220A3E4[][2];
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void *func_02030DA8(void *owner, void (*fn)(void *, void *), void *p, u32 a3);
extern void BTLV_INPUT_ScreenResetTask(void *a, void *b);
extern void BTLV_INPUT_TaskEndClearBusyBit(void *h);
extern void BTLV_INPUT_RegisterTask(char *p, int a, int b);
extern void BTLV_EFFECT_ResetIntroState(int a);
extern void BTLV_EFFECT_StartEffect(u32 a);

void BTLV_INPUT_StartScreenTransition(Main *m, int c)
{
    Obj *o;
    int k;

    o = func_02030734((u16)((m->h240 & 0x7fff) | 0x8000), 0x24, 1, d_0220AEB0, 0xd8c);
    k = m->mode;
    m->mode = d_0220A38C[k][c - 5];
    m->b0 = 1;
    o->main = m;
    BTLV_INPUT_RegisterTask((char *)m, (int)func_02030DA8(m->owner, BTLV_INPUT_ScreenResetTask, o, 1), (int)((void *)BTLV_INPUT_TaskEndClearBusyBit));
    BTLV_EFFECT_ResetIntroState(2);
    BTLV_EFFECT_StartEffect(d_0220A3E4[k][c - 5]);
}
