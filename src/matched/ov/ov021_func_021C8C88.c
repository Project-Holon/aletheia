/*
 * function: FIELD_TILE_MOVE_StartSlideTask
 * address:  0x021C8C88
 * packet:   pkt_ov021_021C8C88
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Creates task FIELD_TILE_MOVE_SlideTaskMain with a 0x28 byte work area, fills it from the
 * owner, and loads three resources (0x55E, 0x6E2, 0x769) through
 * GFL_USE_GetSeSlot.
 *
 * symbols:
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   FIELDMAP_GetFieldPlayer  0x02188CB4  thumb
 *   FIELD_PLAYER_GetMmdl  0x021A3074  thumb
 *   GFL_USE_GetSeSlot  0x02006148  thumb
 *   FIELD_TILE_MOVE_SlideTaskMain  0x021C8BFC  thumb
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;

struct Work8C88 {
    void *sys;
    u8 *owner;
    u8 *f8;
    void *fC;
    u32 f10;
    u32 f14;
    u32 f18;
    int f1C;
    int f20;
    int f24;
};

typedef int (*TaskFn)(void *task, int *state, void *work);

struct Desc;
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
struct Obj;
extern void *func_020124E8(struct Obj *p);
struct Obj00020;
extern void *FIELDMAP_GetFieldPlayer(struct Obj00020 *p);
extern void *FIELD_PLAYER_GetMmdl(unsigned char *p);
extern int GFL_USE_GetSeSlot(u32 a0);
extern int FIELD_TILE_MOVE_SlideTaskMain(int a, int *st, int *p);

void *FIELD_TILE_MOVE_StartSlideTask(u32 prio, void *sys, struct Obj00020 *owner)
{
    void *v = FIELDMAP_GetFieldPlayer(owner);
    void *task = func_020122C0(sys, (void *)prio, (TaskFn)FIELD_TILE_MOVE_SlideTaskMain, 0x28);
    struct Work8C88 *w = func_020124E8(task);

    w->sys = sys;
    w->owner = (u8 *)owner;
    w->f8 = (u8 *)v;
    w->fC = FIELD_PLAYER_GetMmdl(w->f8);
    w->f10 = 0;
    w->f14 = 0;
    w->f18 = 0;
    w->f1C = GFL_USE_GetSeSlot(0x55E);
    w->f20 = GFL_USE_GetSeSlot(0x6E2);
    w->f24 = GFL_USE_GetSeSlot(0x769);
    return task;
}
