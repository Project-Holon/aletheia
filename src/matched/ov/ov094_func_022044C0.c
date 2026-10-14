/*
 * function: BTLV_INPUT_StartBgWipeTask
 * address:  0x022044C0
 * packet:   pkt_ov094_022044C0
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   d_0220AEB0     0x0220AEB0  data   ov094  a1
 *   func_02030734  0x02030734  arm
 *   func_020056A0  0x020056A0  thumb
 *   BTLV_INPUT_BgWipeTaskMain  0x0220453C  thumb  ov094
 *   BTLV_INPUT_BgWipeTaskEnd  0x02204588  thumb  ov094
 *   BTLV_INPUT_RegisterTask  0x0220684C  thumb  ov094
 */
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct Main {
    unsigned char pad00[0x68];
    unsigned int f0 : 1;
    unsigned int st : 3;
    unsigned int hi : 28;
    unsigned char pad6C[0x240 - 0x6C];
    u16 h240;
} Main;

typedef struct Obj {
    Main *main;
    int f4;
    int f8;
    int fc;
    int f10;
    int f14;
} Obj;

extern const char d_0220AEB0[];
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void *func_020056A0(void *cb, void *ctx, int a);
struct Ctx;
extern void BTLV_INPUT_BgWipeTaskMain(int a0, struct Ctx *c);
extern void BTLV_INPUT_BgWipeTaskEnd(void *h);
extern void BTLV_INPUT_RegisterTask(char *p, int a, int b);

void BTLV_INPUT_StartBgWipeTask(Main *m, int a1, int a2, int a3, int a4)
{
    Obj *o;

    o = func_02030734((u16)((m->h240 & 0x7fff) | 0x8000), 0x18, 0, d_0220AEB0, 0xbd5);
    o->main = m;
    o->f4 = 0;
    o->f8 = a1;
    o->fc = a2;
    o->f10 = a3;
    o->f14 = a4;
    BTLV_INPUT_RegisterTask((char *)m, (int)func_020056A0((void *)BTLV_INPUT_BgWipeTaskMain, o, 0), (int)BTLV_INPUT_BgWipeTaskEnd);
    m->st = m->st + 1;
}
