/*
 * function: func_021BCA68
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
 *   func_02082BCC 0x02082BCC arm
 *   func_021BCE10 0x021BCE10 thumb
 *   func_021BCEC0 0x021BCEC0 thumb
 *   GF_FONT_Create 0x0201D7EC thumb
 *   func_0201C440 0x0201C440 thumb
 *   func_020056A0 0x020056A0 thumb
 *   func_021BCC80 0x021BCC80 thumb
 *   func_0200CA1C 0x0200CA1C thumb
 *   func_0200CA54 0x0200CA54 thumb
 *   func_021BD8C0 0x021BD8C0 thumb
 *   func_021BE710 0x021BE710 thumb
 *   func_021BC35C 0x021BC35C thumb
 *   func_021BCC84 0x021BCC84 thumb
 *   FADE_Start 0x0204E720 arm
 *   GFL_NET_RestartWithDefaultTimeout 0x0203D34C arm
 * 2026-10-02: only func_021BCC80 (unlabelled bx lr stub, filed as ov208_func_021BCC80.c) lacks a witness; bytes match.
 * Callee func_021BC35C is declared void in its matched file but returns the new object (caller stores r0).
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
struct Obj0203159C;
extern void *PROCSYS_AllocProcWork(struct Obj0203159C *obj, u32 size, u32 heap);
extern void func_02082BCC(void *p, int v, int n);
extern char *func_021BCE10(u32 display, u32 heap, int threeD);
extern void func_021BCEC0(char *p);
typedef signed int     s32;
struct Blk37;
struct GfFont;
extern struct GfFont *GF_FONT_Create(int a0, int a1, int a2, int a3, u32 heapId);
struct Ov208Icon;
extern u32 func_0201C440(void *p);
extern int func_020056A0(void (*fn)(void), void *arg, int n);
extern void func_021BCC80(void);
extern void *func_0200CA1C(void *a);
extern u32 func_0200CA54(struct Blk37 *p);
extern char *func_021BD8C0(u16 heap, unsigned arg);
extern struct Ov208Icon *func_021BE710(u16 heap, unsigned arg);
extern void *func_021BC35C(u32 heap, void *a, void *b, void *c, void *d, void *e, void *f, int g, u16 h, void *i);
struct Ov208Mode;
struct Ov208Slot;
extern void func_021BCC84(struct Ov208Mode *m, struct Ov208Slot *s);
extern void FADE_Start(u32 a, s32 b, s32 c, s32 d);
extern void GFL_NET_RestartWithDefaultTimeout(u32 a, u32 b);
int func_021BCA68(void *owner, int unused, struct Ov208Args *args)
{
    struct Ov208Main *p;
    GFL_HEAP_CreateChildHeap(1, 0x95, 0x90000);
    p = PROCSYS_AllocProcWork(owner, 0x2c, 0x95);
    func_02082BCC(p, 0, 0x2c);
    p->heap = 0x95;
    args->f10 = 0;
    p->disp = func_021BCE10(0, p->heap, 1);
    func_021BCEC0(p->disp);
    p->disp = func_021BCE10(0, p->heap, 0);
    p->font = GF_FONT_Create(0x17, 0, 0, 0, p->heap);
    p->gfx = (void *)func_0201C440((void *)p->heap);
    p->task = func_020056A0(func_021BCC80, p, 1);

    p->f14 = func_021BD8C0(p->heap, func_0200CA54(func_0200CA1C(args->src)));
    p->f18 = func_021BE710(p->heap, (unsigned int)p->font);
    p->fsm = func_021BC35C(p->heap, args->src, p->disp, p->font, p->gfx, p->f14, p->f18, args->f8, args->fc, &args->fe);
    p->f20 = 0;
    p->f24 = 0;
    func_021BCC84((struct Ov208Mode *)args, (struct Ov208Slot *)p);
    p->f28 = 0;
    FADE_Start(3, 0, 0, 0);
    GFL_NET_RestartWithDefaultTimeout(1, p->heap);
    return 1;
}
