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
 *   func_021B8308  0x021B8308  thumb  ov071
 *   func_021B8350  0x021B8350  thumb  ov071
 *   func_021B81A0  0x021B81A0  thumb  ov071
 *   func_021B82E4  0x021B82E4  thumb  ov071
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
struct Obj0203159C;
int MONOLITH_TOOL_MENU_Create(struct Obj0203159C *a, int unused, C *c)
{
    extern void *ICA_ANIME_GetField1C(const struct Ctx *p);
    extern void *PROCSYS_AllocProcWork(struct Obj0203159C *obj, u32 size, u32 heap);
    extern void MI_CpuFill8(void *, int, int);
    extern u32 GAME_DATA_GetEventWork(const struct BigObj *p);
    extern u32 ZONEDATA_CheckEventFlag(void *bitmap, s32 id);
    extern void func_021B8308(void);
    extern void func_021B8350(W *, int *);
    extern void func_021B81A0(int *a, u8 *p);
    extern void func_021B82E4(void *, int);
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
    func_021B8308();
    func_021B8350(w, c->f4);
    func_021B81A0((int *)c, (u8 *)w);
    func_021B82E4(c, (int)w);
    BG_SYS_SetSubPlaneVisible(0x10, 1);
    return 1;
}
