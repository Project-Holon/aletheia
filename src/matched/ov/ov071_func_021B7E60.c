/*
 * function: MONOLITH_TOOL_MENU_Create
 * address:  0x021B7E60
 * packet:   pkt_ov071_021B7E60
 * region:   ov071
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   ICA_ANIME_GetField1C  0x020120F4  thumb
 *   PROCSYS_AllocProcWork  0x0203159C  arm
 *   MI_CpuFill8  0x02082BCC  arm
 *   GAME_DATA_GetEventWork  0x0201296C  thumb
 *   ZONEDATA_CheckEventFlag  0x020142E8  thumb
 *   MONOLITH_TOOL_MENU_InitBackgrounds  0x021B8308  thumb  ov071
 *   MONOLITH_TOOL_MENU_CreateWindow  0x021B8350  thumb  ov071
 *   MONOLITH_TOOL_MENU_CreateButtons  0x021B81A0  thumb  ov071
 *   MONOLITH_TOOL_MENU_CreateCursor  0x021B82E4  thumb  ov071
 *   BG_SYS_SetSubPlaneVisible  0x02043598  arm
 */

typedef struct {
    char pad[0x32];
    unsigned char f32;
} W;

typedef struct {
    char pad[0x3d];
    unsigned char f3d;
} Q;

typedef struct {
    Q *q;
    int *f4;
} C;

typedef signed int     s32;
typedef unsigned int   u32;
struct Ctx;
struct BigObj;
typedef unsigned char  u8;
struct Proc;
int MONOLITH_TOOL_MENU_Create(struct Proc *a, int unused, C *c)
{
    extern void *ICA_ANIME_GetField1C(const struct Ctx *p);
    extern void *PROCSYS_AllocProcWork(struct Proc *obj, u32 size, u32 heap);
    extern void MI_CpuFill8(void *, int, int);
    extern u32 GAME_DATA_GetEventWork(const struct BigObj *p);
    extern u32 ZONEDATA_CheckEventFlag(void *bitmap, s32 id);
    extern void MONOLITH_TOOL_MENU_InitBackgrounds(void);
    extern void MONOLITH_TOOL_MENU_CreateWindow(W *, int *);
    extern void MONOLITH_TOOL_MENU_CreateButtons(int *a, u8 *p);
    extern void MONOLITH_TOOL_MENU_CreateCursor(void *, int);
    extern void BG_SYS_SetSubPlaneVisible(u32 mask, u32 enable);
    void *h = ICA_ANIME_GetField1C(*(void **)c->q);
    W *w = PROCSYS_AllocProcWork(a, 0x48, 0x61);

    MI_CpuFill8(w, 0, 0x48);
    if (ZONEDATA_CheckEventFlag((void *)GAME_DATA_GetEventWork(h), 0x980) == 0) {
        w->f32 = 2;
    } else if (c->q->f3d == 1) {
        w->f32 = 1;
    } else {
        w->f32 = 0;
    }
    MONOLITH_TOOL_MENU_InitBackgrounds();
    MONOLITH_TOOL_MENU_CreateWindow(w, c->f4);
    MONOLITH_TOOL_MENU_CreateButtons((int *)c, (u8 *)w);
    MONOLITH_TOOL_MENU_CreateCursor(c, (int)w);
    BG_SYS_SetSubPlaneVisible(0x10, 1);
    return 1;
}
