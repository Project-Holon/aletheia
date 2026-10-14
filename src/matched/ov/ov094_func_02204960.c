/*
 * function: BTLV_INPUT_StartBgScrollOffsetTask
 * address:  0x02204960
 * packet:   pkt_ov094_02204960
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   d_0220AEB0     0x0220AEB0  data   ov094  a1
 *   func_02030734  0x02030734  arm
 *   func_020056A0  0x020056A0  thumb
 *   BTLV_INPUT_BgScrollOffsetTaskMain  0x022049C8  thumb  ov094
 *   BTLV_INPUT_RegisterTask  0x0220684C  thumb  ov094
 */
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct Main {
    unsigned char pad00[0x240];
    u16 h240;
} Main;

typedef struct Obj {
    Main *main;
    int f4;
    int f8;
    int fc;
    int f10;
    int f14;
    int f18;
    int f1c;
} Obj;

extern const char d_0220AEB0[];
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void *func_020056A0(void *cb, void *ctx, int a);
struct Ctx;
extern void BTLV_INPUT_BgScrollOffsetTaskMain(int a0, struct Ctx *c);
extern void BTLV_INPUT_RegisterTask(char *p, int a, int b);

void BTLV_INPUT_StartBgScrollOffsetTask(Main *m, int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    Obj *o;

    o = func_02030734((u16)((m->h240 & 0x7fff) | 0x8000), 0x20, 0, d_0220AEB0, 0xd1d);
    o->main = m;
    o->f4 = a1;
    o->f8 = a2;
    o->fc = a3;
    o->f10 = a4;
    o->f14 = a5;
    o->f18 = a6;
    o->f1c = a7;
    BTLV_INPUT_RegisterTask((char *)m, (int)func_020056A0((void *)BTLV_INPUT_BgScrollOffsetTaskMain, o, 0), 0);
}
