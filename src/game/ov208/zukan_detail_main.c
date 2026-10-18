/*
 * file:     zukan_detail_main.c
 * unit:     yes
 * function: ZUKAN_DETAIL_MAIN_Init, ZUKAN_DETAIL_MAIN_Exit, ZUKAN_DETAIL_MAIN_Main, ZUKAN_DETAIL_MAIN_NoOp
 * address:  0x021BCA68
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Wave 13: ZUKAN_DETAIL_MAIN_SwitchScreen moved out to zukan_detail.c by
 * tools/splitfile.py. SwitchScreen is the only function of this unit whose own
 * __FILE__ pool anchor names a file (zukan_detail.c, string 0x021C8DB0); the
 * four functions kept here have no __FILE__ anchor.
 *
 * symbols:
 *   GFL_HEAP_Free 0x020307B0  arm
 *   ZUKAN_SAVE_GetFromGameData 0x0200CA1C thumb
 *   GFL_HEAP_CreateChildHeap 0x0203064C arm
 *   PROCSYS_AllocProcWork 0x0203159C arm
 *   MI_CpuFill8 0x02082BCC arm
 *   ZUKAN_DETAIL_GRAPHIC_InitBgGraphics 0x021BCE10 thumb
 *   ZUKAN_DETAIL_GRAPHIC_ExitBgGraphics 0x021BCEC0 thumb
 *   GF_FONT_Create 0x0201D7EC thumb
 *   PRINTSYS_QUE_Create 0x0201C440 thumb
 *   GFL_USE_AddMainTask 0x020056A0 thumb
 *   ZUKAN_SAVE_GetDexObtained 0x0200CA54 thumb
 *   ZUKAN_DETAIL_TOUCHBAR_Create 0x021BD8C0 thumb
 *   ZUKAN_DETAIL_HEADBAR_Create 0x021BE710 thumb
 *   FADE_Start 0x0204E720 arm
 *   GFL_NET_RestartWithDefaultTimeout 0x0203D34C arm
 *   ZUKAN_DETAIL_HEADBAR_Delete 0x021BE778 thumb ov208
 *   ZUKAN_DETAIL_TOUCHBAR_Delete 0x021BD954 thumb ov208
 *   TCB_DeleteTask 0x02030EAC arm
 *   PRINTSYS_QUE_Clear 0x0201C6EC thumb
 *   PRINTSYS_QUE_Delete 0x0201C4C0 thumb
 *   GF_FONT_Delete 0x0201D83C thumb
 *   PROCSYS_FreeProcWork 0x020315D4 arm
 *   GFL_HEAP_DeleteChecked 0x020306F0 arm
 *   ZUKAN_DETAIL_TOUCHBAR_GetPressedButtonId 0x021BDB08 thumb
 *   ZUKAN_DETAIL_TOUCHBAR_GetHeldButtonId 0x021BDB54 thumb
 *   ZUKAN_DETAIL_TOUCHBAR_Update 0x021BD974 thumb
 *   ZUKAN_DETAIL_HEADBAR_Update 0x021BE7A4 thumb
 *   PRINTSYS_QUE_Main 0x0201C4E4 thumb
 *   ZUKAN_DETAIL_GRAPHIC_DrawFrame 0x021BCF18 thumb
 *   ZUKAN_DETAIL_GRAPHIC_ApplyCamera 0x021BCF2C thumb
 *   ZUKAN_DETAIL_GRAPHIC_EndDraw3d 0x021BCF3C thumb
 *   ZUKAN_DETAIL_PROCSYS_FreeNode 0x021BC26C thumb ov208
 *   ZUKAN_DETAIL_PROCSYS_RunStateCallbacks 0x021BC274 thumb ov208
 *   ZUKAN_DETAIL_PROCSYS_CallOwnerUpdate 0x021BC2F0 thumb ov208
 *   ZUKAN_DETAIL_PROCSYS_CallOwnerHook 0x021BC310 thumb ov208
 *   ZUKAN_DETAIL_COMMON_CreateContext 0x021BC35C thumb ov208
 *   ZUKAN_DETAIL_COMMON_DeleteContext 0x021BC39C thumb ov208
 *   ZUKAN_DETAIL_MAIN_SwitchScreen 0x021BCC84 thumb ov208
 */
#include "zukan_detail_shared_types.h"
#include "zukan_detail_main_shared_types.h"

struct Proc;

struct Ov208Mgr;

struct Proc;

struct Ov208Fade;

extern u32 GFL_HEAP_Free(void *p);

extern void *ZUKAN_SAVE_GetFromGameData(void *a);

extern void GFL_HEAP_CreateChildHeap(u32 src, u32 heap, u32 size);

extern void *PROCSYS_AllocProcWork(struct Proc *obj, u32 size, u32 heap);

extern void MI_CpuFill8(void *p, int v, int n);

extern char *ZUKAN_DETAIL_GRAPHIC_InitBgGraphics(u32 display, u32 heap, int threeD);

extern void ZUKAN_DETAIL_GRAPHIC_ExitBgGraphics(char *p);

extern struct GfFont *GF_FONT_Create(int a0, int a1, int a2, int a3, u32 heapId);

extern u32 PRINTSYS_QUE_Create(void *p);

extern int GFL_USE_AddMainTask(void (*fn)(void), void *arg, int n);

extern u32 ZUKAN_SAVE_GetDexObtained(struct Blk37 *p);

extern char *ZUKAN_DETAIL_TOUCHBAR_Create(u16 heap, unsigned arg);

extern struct Ov208Icon *ZUKAN_DETAIL_HEADBAR_Create(u16 heap, unsigned arg);

extern void FADE_Start(u32 a, s32 b, s32 c, s32 d);

extern void GFL_NET_RestartWithDefaultTimeout(u32 a, u32 b);

extern void ZUKAN_DETAIL_HEADBAR_Delete(struct Ov208Mgr *m);

extern void ZUKAN_DETAIL_TOUCHBAR_Delete(struct Ov208Mgr *m);

extern void TCB_DeleteTask(struct Node *n);

extern void PRINTSYS_QUE_Clear(struct PrintSys *p);

extern void PRINTSYS_QUE_Delete(struct PrintSys *p);

extern u32 GF_FONT_Delete(void *ptr);

extern void PROCSYS_FreeProcWork(struct Proc *p);

extern void GFL_HEAP_DeleteChecked(unsigned int heap);

extern unsigned ZUKAN_DETAIL_TOUCHBAR_GetPressedButtonId(const struct Ov208Fsm *p);

extern unsigned ZUKAN_DETAIL_TOUCHBAR_GetHeldButtonId(const struct Ov208Fsm *p);

extern void ZUKAN_DETAIL_TOUCHBAR_Update(struct Ov208Fade *m);

extern void ZUKAN_DETAIL_HEADBAR_Update(struct Ov208Icon *p);

extern u32 PRINTSYS_QUE_Main(struct PrintSys *ps);

extern void ZUKAN_DETAIL_GRAPHIC_DrawFrame(char *p);

extern void ZUKAN_DETAIL_GRAPHIC_ApplyCamera(char *p);

extern void ZUKAN_DETAIL_GRAPHIC_EndDraw3d(char *p);

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

/*
 * 2026-10-02: only ZUKAN_DETAIL_MAIN_NoOp (unlabelled bx lr stub, filed as ZUKAN_DETAIL_MAIN_NoOp.c) lacks a witness; bytes match.
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
    p->task = (void *)GFL_USE_AddMainTask(ZUKAN_DETAIL_MAIN_NoOp, p, 1);

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
    if(((struct Ov208Main *)p)->mem)GFL_HEAP_Free((void *)(((struct Ov208Main *)p)->mem));
    ZUKAN_DETAIL_COMMON_DeleteContext(((struct Ov208Main *)p)->context);
    ZUKAN_DETAIL_HEADBAR_Delete(((struct Ov208Main *)p)->headbar);
    ZUKAN_DETAIL_TOUCHBAR_Delete(((struct Ov208Main *)p)->touchbar);
    TCB_DeleteTask(((struct Ov208Main *)p)->task);
    PRINTSYS_QUE_Clear((struct PrintSys *)(*(unsigned *)&((struct Ov208Main *)p)->printer));
    PRINTSYS_QUE_Delete(((struct Ov208Main *)p)->printer);
    GF_FONT_Delete(((struct Ov208Main *)p)->font);
    ZUKAN_DETAIL_GRAPHIC_ExitBgGraphics(*(char * *)&((struct Ov208Main *)p)->display);
    PROCSYS_FreeProcWork(a);
    GFL_HEAP_DeleteChecked(149);
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
