/*
 * function: OPTION_MENU_Init
 * address:  0x021B95A0
 * packet:   pkt_ov068_021B95A0
 * region:   ov068
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * The `adds r1, r7, #0` before the zero store to args->x0 is the store
 * written through the field just set (w->args->x0 = 0): the forwarded value
 * gets its own register. args->x0 = 0, *(int *)args = 0 and an inline
 * setter all store through r7 directly (452 B).
 *
 * symbols:
 *   func_02034AC4  0x02034AC4  arm
 *   GFL_HEAP_CreateChildHeap  0x0203064C  arm
 *   PROCSYS_AllocProcWork  0x0203159C  arm
 *   MI_CpuFill8  0x02082BCC  arm
 *   OPTION_MENU_InitScreen  0x021B9850  thumb  ov068
 *   GF_FONT_Create  0x0201D7EC  thumb
 *   PRINTSYS_QUE_Create  0x0201C440  thumb
 *   APP_TASKMENU_RES_Create  0x02027F60  thumb
 *   func_02045B38  0x02045B38  arm
 *   TCBL_Create  0x0203101C  arm
 *   func_020120F4  0x020120F4  thumb
 *   GAME_DATA_GetSaveControl  0x02012EBC  thumb
 *   func_0200873C  0x0200873C  thumb
 *   OPTION_MENU_InitSettings  0x021BAF5C  thumb  ov068
 *   OPTION_MENU_InitRunner  0x021BB0F8  thumb  ov068
 *   OPTION_MENU_StateFadeIn  0x021BB148  thumb  ov068
 *   func_021B9950  0x021B9950  thumb  ov068
 *   OPTION_MENU_InitButtons  0x021BA37C  thumb  ov068
 *   OPTION_MENU_InitList  0x021BA734  thumb  ov068
 *   OPTION_MENU_InitInput  0x021BA024  thumb  ov068
 *   func_021B995C  0x021B995C  thumb  ov068
 *   OPTION_MENU_InitTextBox  0x021BA1C4  thumb  ov068
 *   OPTION_MENU_InitMessageBox  0x021BAD60  thumb  ov068
 *   ov067_id       0x00000043  data
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct {
    u32 x0;
    u32 x4;
} Args;

typedef struct {
    u8 pad0[0xd4];
    u8 xD4[0x10];
    u8 xE4[0x20];
    u8 x104[0x44];
    u8 x148[0x58];
    u8 x1A0[0x38];
    u8 x1D8[0x70];
    u8 x248[0xc];
    u32 font;
    u32 x258;
    u32 msg;
    u32 x260;
    u32 x264;
    u32 x268;
    Args *args;
} Work;

extern u8 ov067_id[];

typedef signed int     s32;
extern int func_02034AC4(s32 handle);
extern void  GFL_HEAP_CreateChildHeap(u32 a, u32 b, u32 c);
struct Obj0203159C;
extern void *PROCSYS_AllocProcWork(struct Obj0203159C *obj, u32 size, u32 heap);
extern void  MI_CpuFill8(void *p, u32 v, u32 n);
extern void OPTION_MENU_InitScreen(u8 *p, u32 a);
struct Big;
struct Ctx;
struct GfFont;
struct MsgBank;
struct R;
struct Sub02008700Obj;
struct Tcbl;
extern struct GfFont *GF_FONT_Create(int a0, int a1, int a2, int a3, u32 heapId);
extern u32 PRINTSYS_QUE_Create(void *p);
extern struct R *APP_TASKMENU_RES_Create(u16 a0, u16 a1, u32 a2, u32 a3, u16 heap);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern struct Tcbl *TCBL_Create(u16 heap, u16 tag, u32 count, u32 workSize);
extern void *func_020120F4(const struct Ctx *p);
extern void *GAME_DATA_GetSaveControl(struct Big *p);
extern struct Sub02008700Obj *func_0200873C(void *sys);
extern void OPTION_MENU_InitSettings(u8 *p, short unsigned int *a);
extern void  OPTION_MENU_StateFadeIn(void *unused, u32 *p);
extern void OPTION_MENU_InitRunner(u8 *p, int value, int callback);
extern int func_021B9950(void *p);
extern void  OPTION_MENU_InitButtons(u8 *p, u32 a1, u32 a2, u32 a3, u32 s0, u32 s1, u32 s2, u16 s3);
extern void  OPTION_MENU_InitList(u8 *p, u16 a1, u16 a2, Work *a3, u8 *src, u32 heap);
extern void OPTION_MENU_InitInput(void *p, int heap);
extern int func_021B995C(int *p, int i);
extern void  OPTION_MENU_InitTextBox(u8 *p, u32 a1, u32 a2, u32 a3, u32 s0, u32 s1, u16 s2);
extern void OPTION_MENU_InitMessageBox(u8 *p, u32 a, u32 b, void *c, u32 s0, u32 s1, u32 s2, u16 s3);

int OPTION_MENU_Init(void *proc, int *seq, Args *args)
{
    Work *w;
    u32 t;

    func_02034AC4((u32)ov067_id);
    GFL_HEAP_CreateChildHeap(1, 0x1c, 0x21000);
    w = PROCSYS_AllocProcWork(proc, sizeof(Work), 0x1c);
    MI_CpuFill8(w, 0, sizeof(Work));
    w->args = args;
    w->args->x0 = 0;
    OPTION_MENU_InitScreen((u8 *)w, 0x1c);
    w->font = (u32)GF_FONT_Create(0x17, 0, 0, 0, 0x1c);
    w->x258 = PRINTSYS_QUE_Create((void *)0x1c);
    w->x260 = (u32)APP_TASKMENU_RES_Create(0, 0xd, w->font, w->x258, 0x1c);
    w->x264 = (u32)APP_TASKMENU_RES_Create(3, 9, w->font, w->x258, 0x1c);
    w->msg = (u32)func_02045B38(0, 2, 0x1d, 0x1c);
    w->x268 = (u32)TCBL_Create(0x1c, 0x1c, 0x20, 0x20);
    OPTION_MENU_InitSettings(w->x248, (short unsigned int *)func_0200873C(GAME_DATA_GetSaveControl(func_020120F4((const struct Ctx *)w->args->x4))));
    OPTION_MENU_InitRunner(w->xD4, (int)w, (int)OPTION_MENU_StateFadeIn);
    t = (u32)func_020120F4((const struct Ctx *)w->args->x4);
    OPTION_MENU_InitButtons(w->x104, func_021B9950(w), w->font, w->x258, w->msg, w->x260, t, 0x1c);
    OPTION_MENU_InitList(w->x148, 1, 2, w, w->x248, 0x1c);
    OPTION_MENU_InitInput(w->xE4, 0x1c);
    OPTION_MENU_InitTextBox(w->x1A0, func_021B995C((int *)w, 0x11), w->font, w->msg, w->x268, w->x258, 0x1c);
    OPTION_MENU_InitMessageBox(w->x1D8, func_021B995C((int *)w, 0x12), w->font, (void *)w->msg, w->x268, w->x264, w->x258, 0x1c);
    return 1;
}
