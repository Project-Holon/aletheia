/*
 * function: BTLV_INPUT_StartBgScrollTask
 * address:  0x022043C0
 * packet:   pkt_ov094_022043C0
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
 *   BTLV_INPUT_BgScrollTaskMain  0x02204438  thumb  ov094
 *   BTLV_INPUT_BgScrollTaskEnd  0x022044A0  thumb  ov094
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
} Obj;

extern const char d_0220AEB0[];
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void *func_020056A0(void *cb, void *ctx, int a);
struct Ctx;
extern void BTLV_INPUT_BgScrollTaskMain(int a0, struct Ctx *c);
extern void BTLV_INPUT_BgScrollTaskEnd(void *h);
extern void BTLV_INPUT_RegisterTask(char *p, int a, int b);

void BTLV_INPUT_StartBgScrollTask(Main *m, int a1, int a2, int a3, int a4)
{
    Obj *o;

    o = func_02030734((u16)((m->h240 & 0x7fff) | 0x8000), 0x14, 0, d_0220AEB0, 0xb97);
    o->main = m;
    o->f4 = a1;
    o->f8 = a2;
    o->fc = a3;
    o->f10 = a4;
    BTLV_INPUT_RegisterTask((char *)m, (int)func_020056A0((void *)BTLV_INPUT_BgScrollTaskMain, o, 0), (int)BTLV_INPUT_BgScrollTaskEnd);
    m->st = m->st + 1;
}
