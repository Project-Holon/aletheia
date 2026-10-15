/*
 * file:     zukan_detail_main.c
 * unit:     yes
 * function: ZUKAN_DETAIL_MAIN_Init, ZUKAN_DETAIL_MAIN_Exit, ZUKAN_DETAIL_MAIN_Main, ZUKAN_DETAIL_MAIN_NoOp, ZUKAN_DETAIL_MAIN_SwitchScreen
 * address:  0x021BCA68
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from zukan_detail_common.c, zukan_detail_graphic.c by tools/splitfile.py.
 *
 * symbols:
 *   func_02030734 0x02030734 arm
 *   func_020307B0 0x020307B0  arm
 *   ZUKAN_SAVE_GetFromGameData 0x0200CA1C thumb
 *   GFL_HEAP_CreateChildHeap 0x0203064C arm
 *   PROCSYS_AllocProcWork 0x0203159C arm
 *   MI_CpuFill8 0x02082BCC arm
 *   ZUKAN_DETAIL_GRAPHIC_InitBgGraphics 0x021BCE10 thumb
 *   ZUKAN_DETAIL_GRAPHIC_ExitBgGraphics 0x021BCEC0 thumb
 *   GF_FONT_Create 0x0201D7EC thumb
 *   PRINTSYS_QUE_Create 0x0201C440 thumb
 *   func_020056A0 0x020056A0 thumb
 *   ZUKAN_SAVE_GetDexObtained 0x0200CA54 thumb
 *   ZUKAN_DETAIL_TOUCHBAR_Create 0x021BD8C0 thumb
 *   ZUKAN_DETAIL_HEADBAR_Create 0x021BE710 thumb
 *   FADE_Start 0x0204E720 arm
 *   GFL_NET_RestartWithDefaultTimeout 0x0203D34C arm
 *   ZUKAN_DETAIL_HEADBAR_Delete 0x021BE778 thumb ov208
 *   ZUKAN_DETAIL_TOUCHBAR_Delete 0x021BD954 thumb ov208
 *   func_02030EAC 0x02030EAC arm
 *   PRINTSYS_QUE_Clear 0x0201C6EC thumb
 *   PRINTSYS_QUE_Delete 0x0201C4C0 thumb
 *   GF_FONT_Delete 0x0201D83C thumb
 *   func_020315D4 0x020315D4 arm
 *   func_020306F0 0x020306F0 arm
 *   ZUKAN_DETAIL_TOUCHBAR_GetPressedButtonId 0x021BDB08 thumb
 *   ZUKAN_DETAIL_TOUCHBAR_GetHeldButtonId 0x021BDB54 thumb
 *   ZUKAN_DETAIL_TOUCHBAR_Update 0x021BD974 thumb
 *   ZUKAN_DETAIL_HEADBAR_Update 0x021BE7A4 thumb
 *   PRINTSYS_QUE_Main 0x0201C4E4 thumb
 *   ZUKAN_DETAIL_GRAPHIC_DrawFrame 0x021BCF18 thumb
 *   ZUKAN_DETAIL_GRAPHIC_ApplyCamera 0x021BCF2C thumb
 *   ZUKAN_DETAIL_GRAPHIC_EndDraw3d 0x021BCF3C thumb
 *   func_021BEA00 0x021BEA00 thumb
 *   ZUKAN_DETAIL_AREA_SetHeapId 0x021BF784 thumb ov208
 *   ZUKAN_DETAIL_VOICE_SetHeapId 0x021C255C thumb
 *   ZUKAN_DETAIL_FORM_SetHeapId 0x021C3B68 thumb
 *   d_021C8DB0 0x021C8DB0 data a1
 *   d_021C8508 0x021C8508 data a4
 *   d_021C8590 0x021C8590 data a4
 *   d_021C86F0 0x021C86F0 data a4
 *   d_021C881C 0x021C881C data a4
 *   ZUKAN_DETAIL_PROCSYS_AllocNode 0x021BC240 thumb ov208
 *   ZUKAN_DETAIL_PROCSYS_FreeNode 0x021BC26C thumb ov208
 *   ZUKAN_DETAIL_PROCSYS_RunStateCallbacks 0x021BC274 thumb ov208
 *   ZUKAN_DETAIL_PROCSYS_CallOwnerUpdate 0x021BC2F0 thumb ov208
 *   ZUKAN_DETAIL_PROCSYS_CallOwnerHook 0x021BC310 thumb ov208
 *   ZUKAN_DETAIL_COMMON_CreateContext 0x021BC35C thumb ov208
 *   ZUKAN_DETAIL_COMMON_DeleteContext 0x021BC39C thumb ov208
 */
#include "zukan_detail_shared_types.h"

struct Obj0203159C;

struct Ov208Mgr;

struct S020315D4;

struct Ov208Fade;

/*
 * Arguments of one zukan detail session, owned by the caller that opens the
 * screen. src is the save-data blob, mode selects the screen (1 info, 2 area,
 * 3 voice, 4 form). extra/formNo/shiny are handed to the context constructor
 * and speciesStep is written back when the left/right buttons are pressed.
 */
struct Ov208Args {
    void *src;
    int mode;
    int extra;
    u16 formNo;
    u16 shiny;
    int speciesStep;
};

/*
 * Work object of the whole zukan detail screen, allocated with size 0x2c by
 * ZUKAN_DETAIL_MAIN_Init. node is the procsys state node of the active screen
 * and context the shared context built by ZUKAN_DETAIL_COMMON_CreateContext.
 */
struct Ov208Main {
    u16 heap;
    u16 pad;
    void *display;
    void *font;
    void *printer;
    void *task;
    void *touchbar;
    void *headbar;
    void *context;
    void *node;
    void *mem;
    int pendingMode;
};

extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);

extern u32 func_020307B0(void *p);

extern void *ZUKAN_SAVE_GetFromGameData(void *a);

extern void GFL_HEAP_CreateChildHeap(u32 src, u32 heap, u32 size);

extern void *PROCSYS_AllocProcWork(struct Obj0203159C *obj, u32 size, u32 heap);

extern void MI_CpuFill8(void *p, int v, int n);

extern char *ZUKAN_DETAIL_GRAPHIC_InitBgGraphics(u32 display, u32 heap, int threeD);

extern void ZUKAN_DETAIL_GRAPHIC_ExitBgGraphics(char *p);

extern struct GfFont *GF_FONT_Create(int a0, int a1, int a2, int a3, u32 heapId);

extern u32 PRINTSYS_QUE_Create(void *p);

extern int func_020056A0(void (*fn)(void), void *arg, int n);

extern u32 ZUKAN_SAVE_GetDexObtained(struct Blk37 *p);

extern char *ZUKAN_DETAIL_TOUCHBAR_Create(u16 heap, unsigned arg);

extern struct Ov208Icon *ZUKAN_DETAIL_HEADBAR_Create(u16 heap, unsigned arg);

extern void FADE_Start(u32 a, s32 b, s32 c, s32 d);

extern void GFL_NET_RestartWithDefaultTimeout(u32 a, u32 b);

extern void ZUKAN_DETAIL_HEADBAR_Delete(struct Ov208Mgr *m);

extern void ZUKAN_DETAIL_TOUCHBAR_Delete(struct Ov208Mgr *m);

extern void func_02030EAC(struct Node *n);

extern void PRINTSYS_QUE_Clear(struct PrintSys *p);

extern void PRINTSYS_QUE_Delete(struct PrintSys *p);

extern u32 GF_FONT_Delete(void *ptr);

extern void func_020315D4(struct S020315D4 *p);

extern void func_020306F0(unsigned int heap);

extern unsigned ZUKAN_DETAIL_TOUCHBAR_GetPressedButtonId(const struct Ov208Fsm *p);

extern unsigned ZUKAN_DETAIL_TOUCHBAR_GetHeldButtonId(const struct Ov208Fsm *p);

extern void ZUKAN_DETAIL_TOUCHBAR_Update(struct Ov208Fade *m);

extern void ZUKAN_DETAIL_HEADBAR_Update(struct Ov208Icon *p);

extern u32 PRINTSYS_QUE_Main(struct PrintSys *ps);

extern void ZUKAN_DETAIL_GRAPHIC_DrawFrame(char *p);

extern void ZUKAN_DETAIL_GRAPHIC_ApplyCamera(char *p);

extern void ZUKAN_DETAIL_GRAPHIC_EndDraw3d(char *p);

extern void func_021BEA00(void *mem, u32 heap);

extern void ZUKAN_DETAIL_AREA_SetHeapId(u16 *p, u16 v);

extern void ZUKAN_DETAIL_VOICE_SetHeapId(u16 *dst, u16 value);

extern void ZUKAN_DETAIL_FORM_SetHeapId(u16 *p, u32 value);

struct Ov208Fsm *ZUKAN_DETAIL_PROCSYS_AllocNode(void *owner, int val, u32 heap);

void ZUKAN_DETAIL_PROCSYS_FreeNode(void *p);

int ZUKAN_DETAIL_PROCSYS_RunStateCallbacks(struct Ov208Fsm *p,int arg);

void ZUKAN_DETAIL_PROCSYS_CallOwnerUpdate(char *p, int a, int b);

void ZUKAN_DETAIL_PROCSYS_CallOwnerHook(char *p, int v);

void *ZUKAN_DETAIL_COMMON_CreateContext(u32 a, void *b, void *c, void *d, void *e, void *f, void *g, int h, unsigned short i, void *j);

void ZUKAN_DETAIL_COMMON_DeleteContext(void *a0);

int ZUKAN_DETAIL_MAIN_Init(void *owner, int unused, struct Ov208Args *args);

int ZUKAN_DETAIL_MAIN_Exit(void *a,int b,int c,char *p);

int ZUKAN_DETAIL_MAIN_Main(void *unused, int *cnt, struct Ov208Args *a, struct Ov208Main *m);

void ZUKAN_DETAIL_MAIN_NoOp(void);

void ZUKAN_DETAIL_MAIN_SwitchScreen(struct Ov208Args *m, struct Ov208Main *s);

extern const char d_021C8DB0[];

extern void *d_021C8508[];

extern void *d_021C8590[];

extern void *d_021C86F0[];

extern void *d_021C881C[];

/*
 * 2026-10-02: only ZUKAN_DETAIL_MAIN_NoOp (unlabelled bx lr stub, filed as ov208_func_021BCC80.c) lacks a witness; bytes match.
 * Callee ZUKAN_DETAIL_COMMON_CreateContext is declared void in its matched file but returns the new object (caller stores r0).
 */
int ZUKAN_DETAIL_MAIN_Init(void *owner, int unused, struct Ov208Args *args)
{
    struct Ov208Main *p;
    GFL_HEAP_CreateChildHeap(1, 0x95, 0x90000);
    p = PROCSYS_AllocProcWork(owner, 0x2c, 0x95);
    MI_CpuFill8(p, 0, 0x2c);
    p->heap = 0x95;
    args->speciesStep = 0;
    p->display = ZUKAN_DETAIL_GRAPHIC_InitBgGraphics(0, p->heap, 1);
    ZUKAN_DETAIL_GRAPHIC_ExitBgGraphics(p->display);
    p->display = ZUKAN_DETAIL_GRAPHIC_InitBgGraphics(0, p->heap, 0);
    p->font = GF_FONT_Create(0x17, 0, 0, 0, p->heap);
    p->printer = (void *)PRINTSYS_QUE_Create((void *)p->heap);
    p->task = (void *)func_020056A0(ZUKAN_DETAIL_MAIN_NoOp, p, 1);

    p->touchbar = ZUKAN_DETAIL_TOUCHBAR_Create(p->heap, ZUKAN_SAVE_GetDexObtained(ZUKAN_SAVE_GetFromGameData(args->src)));
    p->headbar = ZUKAN_DETAIL_HEADBAR_Create(p->heap, (unsigned int)p->font);
    p->context = ZUKAN_DETAIL_COMMON_CreateContext(p->heap, args->src, p->display, p->font, p->printer, p->touchbar, p->headbar, args->extra, args->formNo, &args->shiny);
    p->node = 0;
    p->mem = 0;
    ZUKAN_DETAIL_MAIN_SwitchScreen(args, p);
    p->pendingMode = 0;
    FADE_Start(3, 0, 0, 0);
    GFL_NET_RestartWithDefaultTimeout(1, p->heap);
    return 1;
}

/*
 * extent: 102 code bytes, then two zero alignment bytes at 021BCBB2.
 */
int ZUKAN_DETAIL_MAIN_Exit(void *a,int b,int c,char *p)
{
    FADE_Start(3,16,16,0);
    if(((struct Ov208Main *)p)->node)ZUKAN_DETAIL_PROCSYS_FreeNode(((struct Ov208Main *)p)->node);
    if(((struct Ov208Main *)p)->mem)func_020307B0((void *)(((struct Ov208Main *)p)->mem));
    ZUKAN_DETAIL_COMMON_DeleteContext(((struct Ov208Main *)p)->context);
    ZUKAN_DETAIL_HEADBAR_Delete(((struct Ov208Main *)p)->headbar);
    ZUKAN_DETAIL_TOUCHBAR_Delete(((struct Ov208Main *)p)->touchbar);
    func_02030EAC(((struct Ov208Main *)p)->task);
    PRINTSYS_QUE_Clear((struct PrintSys *)(*(unsigned *)&((struct Ov208Main *)p)->printer));
    PRINTSYS_QUE_Delete(((struct Ov208Main *)p)->printer);
    GF_FONT_Delete(((struct Ov208Main *)p)->font);
    ZUKAN_DETAIL_GRAPHIC_ExitBgGraphics(*(char * *)&((struct Ov208Main *)p)->display);
    func_020315D4(a);
    func_020306F0(149);
    return 1;
}

int ZUKAN_DETAIL_MAIN_Main(void *unused, int *cnt, struct Ov208Args *a, struct Ov208Main *m)
{
    int done = 0;
    u32 v;
    if (*cnt <= 8)
        *cnt = *cnt + 1;
    if (ZUKAN_DETAIL_PROCSYS_RunStateCallbacks(m->node, (int)m->context) != 0) {
        if (m->pendingMode != 0) {
            a->mode = m->pendingMode;
            ZUKAN_DETAIL_MAIN_SwitchScreen(a, m);
            m->pendingMode = 0;
            done = 1;
        } else {
            return 1;
        }
    }
    if (done == 0) {
        v = ZUKAN_DETAIL_TOUCHBAR_GetPressedButtonId(m->touchbar);
        if (v == 0)
            v = ZUKAN_DETAIL_TOUCHBAR_GetHeldButtonId(m->touchbar);
        ZUKAN_DETAIL_PROCSYS_CallOwnerUpdate(m->node, (int)m->context, v);
        switch (v) {
        case 1: a->speciesStep = 0; break;
        case 2: a->speciesStep = 1; break;
        case 6: m->pendingMode = 1; break;
        case 7: m->pendingMode = 2; break;
        case 8: m->pendingMode = 3; break;
        case 9: m->pendingMode = 4; break;
        }
    }
    ZUKAN_DETAIL_TOUCHBAR_Update(m->touchbar);
    ZUKAN_DETAIL_HEADBAR_Update(m->headbar);
    PRINTSYS_QUE_Main(m->printer);
    ZUKAN_DETAIL_GRAPHIC_DrawFrame(m->display);
    ZUKAN_DETAIL_GRAPHIC_ApplyCamera(m->display);
    if (done == 0)
        ZUKAN_DETAIL_PROCSYS_CallOwnerHook(m->node, (int)m->context);
    ZUKAN_DETAIL_GRAPHIC_EndDraw3d(m->display);
    return 0;
}

void ZUKAN_DETAIL_MAIN_NoOp(void)
{
}

/*
 * 2026-10-04 (D2-16): callee ZUKAN_DETAIL_AREA_SetHeapId filed EXACT as src/matched/ov/ov208_func_021BF784.c (strh leaf). Still MATCH only because no
 * shard witnesses it yet; the integrator manifest run should make this EXACT. Symbols line now carries the ov208 hint.
 * 2026-10-02: only ZUKAN_DETAIL_AREA_SetHeapId (init for mode 2, another lane) has no witness yet; bytes match.
 */
void ZUKAN_DETAIL_MAIN_SwitchScreen(struct Ov208Args *m, struct Ov208Main *s)
{
    void **tbl;
    void *mem;
    if (s->node != 0)
        ZUKAN_DETAIL_PROCSYS_FreeNode(s->node);
    if (s->mem != 0)
        func_020307B0(s->mem);
    switch (m->mode) {
    case 1:
        mem = func_02030734(s->heap, 2, 1, d_021C8DB0, 0x1c3);
        func_021BEA00(mem, s->heap);
        s->mem = mem;
        tbl = d_021C8508;
        break;
    case 2:
        mem = func_02030734(s->heap, 2, 1, d_021C8DB0, 0x1cb);
        ZUKAN_DETAIL_AREA_SetHeapId(mem, s->heap);
        s->mem = mem;
        tbl = d_021C8590;
        break;
    case 3:
        mem = func_02030734(s->heap, 2, 1, d_021C8DB0, 0x1d3);
        ZUKAN_DETAIL_VOICE_SetHeapId(mem, s->heap);
        s->mem = mem;
        tbl = d_021C86F0;
        break;
    case 4:
        mem = func_02030734(s->heap, 2, 1, d_021C8DB0, 0x1db);
        ZUKAN_DETAIL_FORM_SetHeapId(mem, s->heap);
        s->mem = mem;
        tbl = d_021C881C;
        break;
    }
    s->node = ZUKAN_DETAIL_PROCSYS_AllocNode(tbl, (int)s->mem, s->heap);
}
