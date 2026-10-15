/*
 * function: VIEWER_MAIN_Create
 * address:  0x021C3CC0
 * packet:   pkt_ov111_021C3CC0
 * region:   ov111
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BG_SYS_ClearMainPlanes  0x020434CC  arm
 *   BG_SYS_ClearSubPlanes  0x02043588  arm
 *   WIPE_SetBrightnessFadeOut  0x0202223C  thumb
 *   WIPE_ResetWndMask  0x02022224  thumb
 *   GFL_HEAP_CreateChildHeap  0x0203064C  arm
 *   PROCSYS_AllocProcWork  0x0203159C  arm
 *   MI_CpuFill8  0x02082BCC  arm
 *   func_020355C4  0x020355C4  arm
 *   MSG_SPEED_GetWait  0x02012FFC  thumb
 *   GFL_NET_GetNegotiationNum  0x0203D1B4  arm
 *   BG_SYS_Create  0x0203F8F4  arm
 *   BG_SYS_SetVramBanks  0x020433E0  arm
 *   PMS_DRAW_Create  0x0202DB0C  thumb
 *   func_020056A0  0x020056A0  thumb
 *   TCBL_Create  0x0203101C  arm
 *   GFL_NET_RestartWithDefaultTimeout  0x0203D34C  arm
 *   WIPE_SYS_Start  0x0202208C  thumb
 *   VIEWER_MAIN_LoadResources  0x021C41C4  thumb  ov111
 *   VIEWER_MAIN_InitBg  0x021C43E8  thumb  ov111
 *   VIEWER_MAIN_LoadBgResources  0x021C453C  thumb  ov111
 *   VIEWER_TEXT_InitActors  0x021C6D9C  thumb  ov111
 *   VIEWER_TEXT_SetScrollParam  0x021C6804  thumb  ov111
 *   VIEWER_TEXT_CreateActor  0x021C6E8C  thumb  ov111
 *   VIEWER_TEXT_Init  0x021C6000  thumb  ov111
 *   VIEWER_TEXT_NoOp  0x021C6D98  thumb  ov111
 *   VIEWER_MAIN_InitLcdBrightness  0x021C5874  thumb  ov111
 *   VIEWER_MAIN_Draw  0x021C47EC  thumb  ov111
 *   VIEWER_MAIN_VBlank  0x021C581C  thumb  ov111
 *   d_021C8564     0x021C8564  data  a4
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    u8 pad0[4];
    u8 f4_0 : 1;
    u8 f4_1 : 1;
    u8 f4_2 : 1;
    u8 f4_3 : 1;
    u8 f4_4 : 1;
    u8 pad5[3];
    u16 h8;
    u8 padA[0x33 - 0xA];
    u8 b33;
} Info;

typedef struct {
    Info *info;
    u8 pad4[0xC - 4];
    u32 fC;
    u8 pad10[4];
    u32 f14;
} Args;

typedef struct {
    u16 heap;
    u8 pad2[2];
    void *f4;
} Anim;

typedef struct {
    u16 heap;
    u8 pad2[2];
    void *bg[8];
    Args *args;
    Info *info;
    u8 pad2C[0x3034 - 0x2C];
    u32 f3034;
    u8 pad3038[0x304C - 0x3038];
    u32 f304C;
    u32 f3050;
    u32 f3054;
    u32 f3058;
    u8 pad305C[0x3060 - 0x305C];
    u32 f3060;
    u8 pad3064[0x3070 - 0x3064];
    Anim anim;
    u8 pad3078[0x31C4 - 0x3078];
    u32 f31C4;
    u8 pad31C8[0x31F4 - 0x31C8];
    void *f31F4;
    void *f31F8;
    void *f31FC;
    u8 pad3200[0x320C - 0x3200];
    void *f320C;
    u8 pad3210[0x32B0 - 0x3210];
    void *f32B0;
    u8 flags[16];
    u8 b32C4;
    u8 pad32C5[3];
    u8 b32C8;
    u8 pad32C9;
    u8 f32CA_0 : 1;
    u8 f32CA_1 : 1;
    u8 pad32CB;
    void *f32CC;
    u8 pad32D0[4];
    u8 b32D4;
    u8 b32D5;
    u8 pad32D6[0x3310 - 0x32D6];
} Work;

extern void BG_SYS_ClearMainPlanes(void);
extern void BG_SYS_ClearSubPlanes(void);
extern void WIPE_SetBrightnessFadeOut(u32 a, u32 b);
struct PmsDraw;
extern u32 WIPE_ResetWndMask(void *win);
extern void GFL_HEAP_CreateChildHeap(u32 a, u32 b, u32 c);
struct Obj0203159C;
extern void *PROCSYS_AllocProcWork(struct Obj0203159C *obj, u32 size, u32 heap);
extern void MI_CpuFill8(void *p, u32 v, u32 n);
struct Tcbl;
extern u8 func_020355C4(void);
extern signed char MSG_SPEED_GetWait(void);
extern int GFL_NET_GetNegotiationNum(void);
extern void BG_SYS_Create(u16 heap);
struct DispVram;
extern void BG_SYS_SetVramBanks(const struct DispVram *c);
extern struct PmsDraw *PMS_DRAW_Create(u32 a, u32 b, u32 c, u32 d, u8 e0, u8 e1, u16 heap);
extern void *func_020056A0(void (*cb)(void *, Work *), void *ctx, int pri);
extern struct Tcbl *TCBL_Create(u16 heap, u16 tag, u32 count, u32 workSize);
extern void GFL_NET_RestartWithDefaultTimeout(u32 a, u32 b);
extern void WIPE_SYS_Start(void *p1, u32 p2, u32 p3, u32 p4, u32 p5, u32 p6, u32 p7);
extern void VIEWER_MAIN_LoadResources(Work *p);
extern void VIEWER_MAIN_InitBg(void);
extern void VIEWER_MAIN_LoadBgResources(Work *p);
extern void VIEWER_TEXT_InitActors(Anim *a, const void *cfg);
extern void VIEWER_TEXT_SetScrollParam(Work *p, Info *info);
extern void VIEWER_TEXT_CreateActor(Anim *a);
extern void VIEWER_TEXT_Init(Work *p);
extern void VIEWER_TEXT_NoOp(Work *p, void *bg, u32 a, void *b);
extern void VIEWER_MAIN_InitLcdBrightness(void);
extern void VIEWER_MAIN_Draw(Work *p);
extern void VIEWER_MAIN_VBlank(void *task, Work *p);
extern const u8 d_021C8564[];

int VIEWER_MAIN_Create(void *man, int *state, Args *args)
{
    Work *p;
    int i;
    u16 mask;

    BG_SYS_ClearMainPlanes();
    BG_SYS_ClearSubPlanes();
    *(volatile u32 *)0x04000000 &= ~0x1F00;
    *(volatile u32 *)0x04001000 &= ~0x1F00;
    WIPE_SetBrightnessFadeOut(0, 0);
    WIPE_SetBrightnessFadeOut(1, 0);
    WIPE_ResetWndMask(0);
    WIPE_ResetWndMask((void *)1);
    GFL_HEAP_CreateChildHeap(1, 0x27, 0x50000);
    p = PROCSYS_AllocProcWork(man, sizeof(Work), 0x27);
    MI_CpuFill8(p, 0, sizeof(Work));
    p->heap = 0x27;
    p->anim.heap = 0x27;
    p->args = args;
    p->info = args->info;
    p->f3060 = func_020355C4();
    p->b32D5 = MSG_SPEED_GetWait();
    p->b32D4 = 0;
    if (p->info->b33) {
        p->f32CA_0 = 1;
    } else {
        p->f32CA_0 = 0;
    }
    mask = 1;
    for (i = 0; i < 16; i++) {
        if (p->info->h8 & mask) {
            p->flags[i] = 1;
        } else {
            p->flags[i] = 0;
        }
        mask <<= 1;
    }
    if (GFL_NET_GetNegotiationNum() > 0) {
        p->f32CA_1 = 1;
    }
    BG_SYS_Create(p->heap);
    VIEWER_MAIN_LoadResources(p);
    BG_SYS_SetVramBanks((const struct DispVram *)d_021C8564);
    VIEWER_MAIN_InitBg();
    VIEWER_MAIN_LoadBgResources(p);
    VIEWER_TEXT_InitActors(&p->anim, d_021C8564);
    VIEWER_TEXT_SetScrollParam(p, p->args->info);
    VIEWER_TEXT_CreateActor(&p->anim);
    VIEWER_TEXT_Init(p);
    p->f32B0 = PMS_DRAW_Create((u32)p->anim.f4, 1, (u32)p->f32CC, (u32)p->f31FC, 8, 1, 0x27);
    VIEWER_TEXT_NoOp(p, p->bg[4], 1, p->f320C);
    if (p->args->f14 == 2) {
        p->args->f14 = 0;
        p->f3034 = 1;
    } else {
        p->f3034 = 0;
    }
    p->args->fC = 0;
    p->b32C4 = 0;
    p->f31C4 = 0;
    if (p->info->f4_4) {
        p->b32C8 = 0;
    } else {
        p->b32C8 = 2;
    }
    p->f304C = 0x80;
    p->f3050 = 0x60;
    p->f3054 = 0;
    p->f3058 = 0;
    VIEWER_MAIN_InitLcdBrightness();
    VIEWER_MAIN_Draw(p);
    p->f31F4 = func_020056A0(VIEWER_MAIN_VBlank, p, 1);
    p->f31F8 = TCBL_Create(p->heap, p->heap, 3, 0);
    GFL_NET_RestartWithDefaultTimeout(1, p->heap);
    WIPE_SYS_Start((void *)1, 3, 3, 0, 6, 1, p->heap);
    return 1;
}
