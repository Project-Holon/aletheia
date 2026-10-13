/*
 * file:     fieldmap_ctrl_nogrid_work.c
 * unit:     yes
 * function: func_021A6CB8, func_021A6D30, func_021A6D3C, func_021A6D48, func_021A6D58, func_021A6D9C, func_021A6DA4
 * address:  0x021A6CB8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 * Split from weather_task.c (lane L141): __FILE__ anchor 021A6D98 (d_021DDF1C "fieldmap_ctrl_nogrid_work.c"); 021A6CB8 creates the work via 021A6D58, same shape as fieldmap_ctrl_grid.c 021A2D88.
 *
 * symbols:
 *   func_020307B0  0x020307B0  arm
 *   func_02188C84  0x02188C84  thumb  ov021
 *   func_02188CB4  0x02188CB4  thumb  ov021
 *   func_0216D888  0x0216D888  thumb  ov010
 *   func_02188D40  0x02188D40  thumb  ov021
 *   func_02188CAC  0x02188CAC  thumb  ov021
 *   func_02188CA4  0x02188CA4  thumb  ov021
 *   func_02030734  0x02030734  arm
 *   d_021DDF1C     0x021DDF1C  data  a1
 *   func_020362DC  0x020362DC  arm
 *   func_0203630C  0x0203630C  arm
 *   func_02188C5C  0x02188C5C  thumb
 *   func_020120F4  0x020120F4  thumb
 *   func_02188C80  0x02188C80  thumb  ov021
 *   func_02188C58  0x02188C58  thumb  ov021
 *   func_020127A4  0x020127A4  thumb
 *   func_02012AB8  0x02012AB8  thumb
 *   func_021BB3AC  0x021BB3AC  thumb  ov021
 *   func_021A3044  0x021A3044  thumb  ov021
 *   func_021A305C  0x021A305C  thumb  ov021
 *   func_021A3074  0x021A3074  thumb  ov021
 *   func_021A3664  0x021A3664  thumb  ov021
 *   func_021A3674  0x021A3674  thumb  ov021
 *   func_021A36A4  0x021A36A4  thumb  ov021
 *   func_021A36B0  0x021A36B0  thumb  ov021
 *   func_021A36D4  0x021A36D4  thumb  ov021
 */
#include "fieldmap_types.h"
#include "fldmmdl_rail_types.h"

typedef unsigned int u32;

struct FieldPlayer;
struct FieldNogridMapper;
struct Mmdl;

/* The nogrid map control work (8 bytes), kept in FieldMap.ctrlWork. */
typedef struct FieldMapCtrlNogridWork {
    struct FieldPlayer *player;     /* 0x00 */
    u32 reserved;                   /* 0x04: cleared by the allocation, never used */
} FieldMapCtrlNogridWork;

extern u32 func_020307B0(void *memory);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *fileName, u16 line);
extern u32 func_020362DC(void);
extern unsigned int func_0203630C(void);
extern u16 func_02188C84(FieldMap *fieldMap);
extern struct FieldPlayer *func_02188CB4(FieldMap *fieldMap);
extern void func_02188CAC(FieldMap *fieldMap, void *ctrlWork);
extern void *func_02188CA4(FieldMap *fieldMap);
extern void func_02188D40(FieldMap *fieldMap, VecFx32 *targetPos);
extern void *func_02188C58(FieldMap *fieldMap);
extern struct FieldNogridMapper *func_02188C5C(FieldMap *fieldMap);
extern void *func_02188C80(FieldMap *fieldMap);
extern VecFx32 *func_0216D888(struct Mmdl *mmdl);
extern void *func_020120F4(void *gameSystem);
extern void *func_020127A4(void *gameData);
extern RailLocation *func_02012AB8(void *saveRecord);
extern void func_021BB3AC(struct FieldNogridMapper *mapper, u32 railWork);
extern struct Mmdl *func_021A3074(struct FieldPlayer *player);
extern void func_021A3044(struct FieldPlayer *player, VecFx32 *pos);
extern void func_021A305C(struct FieldPlayer *player, u32 dir);
extern void func_021A3664(struct FieldPlayer *player, u32 heapId);
extern void func_021A3674(struct FieldPlayer *player, u32 keyTrg, u32 keyCont);
extern u32 func_021A36A4(struct FieldPlayer *player);
extern void func_021A36B0(struct FieldPlayer *player, RailLocation *location);
extern void func_021A36D4(struct FieldPlayer *player, VecFx32 *pos);
extern const char d_021DDF1C[];

void func_021A6CB8(FieldMap *fieldMap, VecFx32 *pos, u32 dir);
void func_021A6D30(FieldMap *fieldMap);
void func_021A6D3C(FieldMap *fieldMap, VecFx32 *pos);
VecFx32 *func_021A6D48(FieldMap *fieldMap);
FieldMapCtrlNogridWork *func_021A6D58(FieldMap *fieldMap, u32 heapId);
void func_021A6D9C(void *work);
void func_021A6DA4(FieldMapCtrlNogridWork *work);

/*
 * Creates the nogrid control: the player stands on the rails at the location
 * stored in the save data. The first two getters have unused results.
 */
void func_021A6CB8(FieldMap *fieldMap, VecFx32 *pos, u32 dir)
{
    struct FieldPlayer *player;

    func_02188C58(fieldMap);
    func_02188C5C(fieldMap);
    player = func_02188CB4(fieldMap);
    func_02188CAC(fieldMap, func_021A6D58(fieldMap, func_02188C84(fieldMap)));
    func_02188D40(fieldMap, func_0216D888(func_021A3074(player)));
    func_021A36B0(player, func_02012AB8(func_020127A4(func_020120F4(func_02188C80(fieldMap)))));
    func_021A36D4(player, pos);
    func_021A3044(player, pos);
    func_021A305C(player, dir);
}

/* Destroy slot. */
void func_021A6D30(FieldMap *fieldMap)
{
    func_021A6D9C(func_02188CA4(fieldMap));
}

/* Main slot. */
void func_021A6D3C(FieldMap *fieldMap, VecFx32 *pos)
{
    func_021A6DA4(func_02188CA4(fieldMap));
}

/* Position of the player's model, the point the camera follows. */
VecFx32 *func_021A6D48(FieldMap *fieldMap)
{
    return func_0216D888(func_021A3074(func_02188CB4(fieldMap)));
}

/* Allocates the work and binds the nogrid mapper camera to the player's rail work. */
FieldMapCtrlNogridWork *func_021A6D58(FieldMap *fieldMap, u32 heapId)
{
    struct FieldNogridMapper *nogridMapper = func_02188C5C(fieldMap);
    FieldMapCtrlNogridWork *work = func_02030734(heapId, sizeof(FieldMapCtrlNogridWork), 1, d_021DDF1C, 0x3e);
    struct FieldPlayer *player = func_02188CB4(fieldMap);

    work->player = player;
    func_021A3664(player, heapId);
    func_021BB3AC(nogridMapper, func_021A36A4(player));
    return work;
}

/* Frees the work. */
void func_021A6D9C(void *work)
{
    func_020307B0(work);
}

/* Moves the player along the rails with this frame's keys. */
void func_021A6DA4(FieldMapCtrlNogridWork *work)
{
    u32 keyTrg = func_020362DC();
    u32 keyCont = func_0203630C();

    func_021A3674(work->player, keyTrg, keyCont);
}
