/*
 * function: BTLV_INPUT_StartPaletteFlashTask
 * address:  0x02204838
 * packet:   pkt_ov094_02204838
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
 *   func_02030DA8  0x02030DA8  arm
 *   BTLV_INPUT_PaletteFlashTaskMain  0x022048A4  thumb  ov094
 *   BTLV_INPUT_PaletteFlashTaskEnd  0x02204940  thumb  ov094
 *   BTLV_INPUT_RegisterTask  0x0220684C  thumb  ov094
 */
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct Main {
    void *f0;
    unsigned char pad04[0x68 - 4];
    unsigned int f0b : 1;
    unsigned int st : 3;
    unsigned int hi : 28;
    unsigned char pad6C[0x240 - 0x6C];
    u16 h240;
} Main;

typedef struct Obj {
    Main *main;
    int f4;
} Obj;

extern const char d_0220AEB0[];
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void *func_02030DA8(void *a0, void *callback, void *ctx, int a3);
struct Ctx;
extern void BTLV_INPUT_PaletteFlashTaskMain(int a0, struct Ctx *c);
extern void BTLV_INPUT_PaletteFlashTaskEnd(void *h);
extern void BTLV_INPUT_RegisterTask(char *p, int a, int b);

void BTLV_INPUT_StartPaletteFlashTask(Main *m, int a1)
{
    Obj *o;

    o = func_02030734((u16)((m->h240 & 0x7fff) | 0x8000), 8, 0, d_0220AEB0, 0xcc9);
    o->main = m;
    o->f4 = a1;
    BTLV_INPUT_RegisterTask((char *)m, (int)func_02030DA8(m->f0, (void *)BTLV_INPUT_PaletteFlashTaskMain, o, 0), (int)BTLV_INPUT_PaletteFlashTaskEnd);
    m->st = m->st + 1;
}
