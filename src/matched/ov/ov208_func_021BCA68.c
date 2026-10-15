/*
 * function: ZUKAN_DETAIL_MAIN_Init
 * address: 0x021BCA68
 * packet: pkt_ov208_021BCA68
 * region: ov208
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GFL_HEAP_CreateChildHeap 0x0203064C arm
 *   PROCSYS_AllocProcWork 0x0203159C arm
 *   MI_CpuFill8 0x02082BCC arm
 *   ZUKAN_DETAIL_GRAPHIC_InitBgGraphics 0x021BCE10 thumb
 *   ZUKAN_DETAIL_GRAPHIC_ExitBgGraphics 0x021BCEC0 thumb
 *   GF_FONT_Create 0x0201D7EC thumb
 *   PRINTSYS_QUE_Create 0x0201C440 thumb
 *   func_020056A0 0x020056A0 thumb
 *   ZUKAN_DETAIL_MAIN_NoOp 0x021BCC80 thumb
 *   ZUKAN_SAVE_GetFromGameData 0x0200CA1C thumb
 *   ZUKAN_SAVE_GetDexObtained 0x0200CA54 thumb
 *   ZUKAN_DETAIL_TOUCHBAR_Create 0x021BD8C0 thumb
 *   ZUKAN_DETAIL_HEADBAR_Create 0x021BE710 thumb
 *   ZUKAN_DETAIL_COMMON_CreateContext 0x021BC35C thumb
 *   ZUKAN_DETAIL_MAIN_SwitchScreen 0x021BCC84 thumb
 *   FADE_Start 0x0204E720 arm
 *   GFL_NET_RestartWithDefaultTimeout 0x0203D34C arm
 * 2026-10-02: only ZUKAN_DETAIL_MAIN_NoOp (unlabelled bx lr stub, filed as ov208_func_021BCC80.c) lacks a witness; bytes match.
 * Callee ZUKAN_DETAIL_COMMON_CreateContext is declared void in its matched file but returns the new object (caller stores r0).
 */
typedef unsigned short u16;
typedef unsigned int u32;
struct Ov208Args { void *src; int f4; int f8; u16 fc; u16 fe; int f10; };
struct Ov208Main {
    u16 heap; u16 pad;
    void *disp; void *font; void *gfx; int task;
    void *f14; void *f18; void *fsm;
    int f20; int f24; int f28;
};
extern void GFL_HEAP_CreateChildHeap(u32 src, u32 heap, u32 size);
struct Proc;
extern void *PROCSYS_AllocProcWork(struct Proc *obj, u32 size, u32 heap);
extern void MI_CpuFill8(void *p, int v, int n);
extern char *ZUKAN_DETAIL_GRAPHIC_InitBgGraphics(u32 display, u32 heap, int threeD);
extern void ZUKAN_DETAIL_GRAPHIC_ExitBgGraphics(char *p);
typedef signed int     s32;
struct Blk37;
struct GfFont;
extern struct GfFont *GF_FONT_Create(int a0, int a1, int a2, int a3, u32 heapId);
struct Ov208Icon;
extern u32 PRINTSYS_QUE_Create(void *p);
extern int func_020056A0(void (*fn)(void), void *arg, int n);
extern void ZUKAN_DETAIL_MAIN_NoOp(void);
extern void *ZUKAN_SAVE_GetFromGameData(void *a);
extern u32 ZUKAN_SAVE_GetDexObtained(struct Blk37 *p);
extern char *ZUKAN_DETAIL_TOUCHBAR_Create(u16 heap, unsigned arg);
extern struct Ov208Icon *ZUKAN_DETAIL_HEADBAR_Create(u16 heap, unsigned arg);
extern void *ZUKAN_DETAIL_COMMON_CreateContext(u32 heap, void *a, void *b, void *c, void *d, void *e, void *f, int g, u16 h, void *i);
struct Ov208Mode;
struct Ov208Slot;
extern void ZUKAN_DETAIL_MAIN_SwitchScreen(struct Ov208Mode *m, struct Ov208Slot *s);
extern void FADE_Start(u32 a, s32 b, s32 c, s32 d);
extern void GFL_NET_RestartWithDefaultTimeout(u32 a, u32 b);
int ZUKAN_DETAIL_MAIN_Init(void *owner, int unused, struct Ov208Args *args)
{
    struct Ov208Main *p;
    GFL_HEAP_CreateChildHeap(1, 0x95, 0x90000);
    p = PROCSYS_AllocProcWork(owner, 0x2c, 0x95);
    MI_CpuFill8(p, 0, 0x2c);
    p->heap = 0x95;
    args->f10 = 0;
    p->disp = ZUKAN_DETAIL_GRAPHIC_InitBgGraphics(0, p->heap, 1);
    ZUKAN_DETAIL_GRAPHIC_ExitBgGraphics(p->disp);
    p->disp = ZUKAN_DETAIL_GRAPHIC_InitBgGraphics(0, p->heap, 0);
    p->font = GF_FONT_Create(0x17, 0, 0, 0, p->heap);
    p->gfx = (void *)PRINTSYS_QUE_Create((void *)p->heap);
    p->task = func_020056A0(ZUKAN_DETAIL_MAIN_NoOp, p, 1);

    p->f14 = ZUKAN_DETAIL_TOUCHBAR_Create(p->heap, ZUKAN_SAVE_GetDexObtained(ZUKAN_SAVE_GetFromGameData(args->src)));
    p->f18 = ZUKAN_DETAIL_HEADBAR_Create(p->heap, (unsigned int)p->font);
    p->fsm = ZUKAN_DETAIL_COMMON_CreateContext(p->heap, args->src, p->disp, p->font, p->gfx, p->f14, p->f18, args->f8, args->fc, &args->fe);
    p->f20 = 0;
    p->f24 = 0;
    ZUKAN_DETAIL_MAIN_SwitchScreen((struct Ov208Mode *)args, (struct Ov208Slot *)p);
    p->f28 = 0;
    FADE_Start(3, 0, 0, 0);
    GFL_NET_RestartWithDefaultTimeout(1, p->heap);
    return 1;
}
