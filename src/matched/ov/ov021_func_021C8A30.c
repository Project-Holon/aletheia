/*
 * function: FIELD_TILE_MOVE_StartSpinTask
 * address:  0x021C8A30
 * packet:   pkt_ov021_021C8A30
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Creates task FIELD_TILE_MOVE_SpinTaskMain with a 0x1C byte work area and fills it from the
 * owner object.
 *
 * symbols:
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   FIELDMAP_GetFieldPlayer  0x02188CB4  thumb
 *   FIELD_PLAYER_GetMmdl  0x021A3074  thumb
 *   FLDMMDL_GetDirDisp  0x0216D5F8  thumb  ov010
 *   FIELD_TILE_MOVE_SpinTaskMain  0x021C89BC  thumb
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;

struct Work8A30 {
    void *sys;
    u8 *owner;
    u8 *f8;
    void *fC;
    u32 f10;
    u16 f14;
    u16 pad16;
    u32 f18;
};

typedef int (*TaskFn)(void *task, int *state, void *work);

struct Desc;
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
struct Obj;
extern void *func_020124E8(struct Obj *p);
struct Obj00020;
extern void *FIELDMAP_GetFieldPlayer(struct Obj00020 *p);
extern void *FIELD_PLAYER_GetMmdl(unsigned char *p);
extern u16 FLDMMDL_GetDirDisp(void *p);
extern int FIELD_TILE_MOVE_SpinTaskMain(int a, int *st, int *p);

void *FIELD_TILE_MOVE_StartSpinTask(u32 prio, void *sys, struct Obj00020 *owner)
{
    void *task = func_020122C0(sys, (void *)prio, (TaskFn)FIELD_TILE_MOVE_SpinTaskMain, 0x1C);
    struct Work8A30 *w = func_020124E8(task);

    w->sys = sys;
    w->owner = (u8 *)owner;
    w->f8 = FIELDMAP_GetFieldPlayer(owner);
    w->fC = FIELD_PLAYER_GetMmdl(w->f8);
    w->f10 = 0;
    w->f14 = FLDMMDL_GetDirDisp(w->fC);
    w->f18 = 0;
    return task;
}
