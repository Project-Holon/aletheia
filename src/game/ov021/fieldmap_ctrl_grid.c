/*
 * file:     fieldmap_ctrl_grid.c
 * unit:     yes
 * function: func_021A2D88, func_021A2DE4, func_021A2DF0, func_021A2E34, func_021A2E44
 * address:  0x021A2D88
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 * Split from weather_task.c (lane L141): __FILE__ anchor 021A2DE0 (d_021DDE90 "fieldmap_ctrl_grid.c"); 021A2D88 allocates the 0x10 holder, 021A2D30 before it is called from weather_task code.
 *
 * symbols:
 *   func_020307B0  0x020307B0  arm
 *   func_02030734  0x02030734  arm
 *   func_02188C84  0x02188C84  thumb  ov021
 *   func_02188CB4  0x02188CB4  thumb  ov021
 *   func_0216D5E0  0x0216D5E0  thumb  ov010
 *   func_0216D888  0x0216D888  thumb  ov010
 *   func_02188D40  0x02188D40  thumb  ov021
 *   func_02188CAC  0x02188CAC  thumb  ov021
 *   d_021DDE90     0x021DDE90  data  a4
 *   func_02188CA4  0x02188CA4  thumb  ov021
 *   func_020362DC  0x020362DC  arm
 *   func_0203630C  0x0203630C  arm
 *   func_021A3074  0x021A3074  thumb  ov021
 *   func_021A35BC  0x021A35BC  thumb  ov021
 *   func_021A35E0  0x021A35E0  thumb  ov021
 *   func_021A35F0  0x021A35F0  thumb  ov021
 */
#include "fieldmap_types.h"

typedef unsigned short u16;
typedef unsigned int u32;

struct FieldPlayer;
struct Mmdl;

/* The grid map control work (0x10 bytes), kept in FieldMap.ctrlWork. */
typedef struct FieldMapCtrlGridWork {
    u16 heapId;             /* 0x00 */
    u16 heapIdPad;          /* 0x02: alignment, never read */
    FieldMap *fieldMap;     /* 0x04 */
    u32 reserved;           /* 0x08: cleared by the allocation, never used */
    u32 busy;               /* 0x0C: set from outside (union room) to stop the player update */
} FieldMapCtrlGridWork;

extern u32 func_020307B0(void *memory);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *fileName, u16 line);
extern u32 func_020362DC(void);
extern unsigned int func_0203630C(void);
extern u16 func_02188C84(FieldMap *fieldMap);
extern struct FieldPlayer *func_02188CB4(FieldMap *fieldMap);
extern void func_02188CAC(FieldMap *fieldMap, void *ctrlWork);
extern void *func_02188CA4(FieldMap *fieldMap);
extern void func_02188D40(FieldMap *fieldMap, VecFx32 *targetPos);
extern void func_0216D5E0(struct Mmdl *mmdl, int dir);
extern VecFx32 *func_0216D888(struct Mmdl *mmdl);
extern struct Mmdl *func_021A3074(struct FieldPlayer *player);
extern int func_021A35BC(struct FieldPlayer *player);
extern void func_021A35E0(struct FieldPlayer *player, u32 heapId);
extern void func_021A35F0(struct FieldPlayer *player, u32 keyTrg, u32 keyCont, u32 flags);
extern int d_021DDE90;

void func_021A2D88(FieldMap *fieldMap, VecFx32 *pos, int dir);
void func_021A2DE4(FieldMap *fieldMap);
void func_021A2DF0(FieldMap *fieldMap, VecFx32 *pos);
VecFx32 *func_021A2E34(FieldMap *fieldMap);
void func_021A2E44(FieldMap *fieldMap, u32 busy);

/* Creates the grid control: the player walks on the grid and the camera targets its position. */
void func_021A2D88(FieldMap *fieldMap, VecFx32 *pos, int dir)
{
    int heapId;
    struct FieldPlayer *player;
    struct Mmdl *mmdl;
    FieldMapCtrlGridWork *work;

    heapId = func_02188C84(fieldMap);
    work = func_02030734(heapId, sizeof(FieldMapCtrlGridWork), 1, (const char *)&d_021DDE90, 0x68);
    work->heapId = heapId;
    work->fieldMap = fieldMap;
    player = func_02188CB4(fieldMap);
    mmdl = func_021A3074(player);
    func_0216D5E0(mmdl, dir);
    func_021A35E0(player, heapId);
    func_02188D40(fieldMap, func_0216D888(mmdl));
    func_02188CAC(fieldMap, work);
}

/* Destroy slot: frees the work. */
void func_021A2DE4(FieldMap *fieldMap)
{
    func_020307B0(func_02188CA4(fieldMap));
}

/* Main slot: moves the player with this frame's keys unless the work is busy. */
void func_021A2DF0(FieldMap *fieldMap, VecFx32 *pos)
{
    FieldMapCtrlGridWork *work = func_02188CA4(fieldMap);
    struct FieldPlayer *player = func_02188CB4(fieldMap);

    if (work->busy == 0) {
        u32 keyTrg = func_020362DC();
        u32 keyCont = func_0203630C();
        u32 flags = 0;

        if (func_021A35BC(player) == 1)
            flags |= 1;
        func_021A35F0(player, keyTrg, keyCont, flags);
    }
}

/* Position of the player's model, the point the camera follows. */
VecFx32 *func_021A2E34(FieldMap *fieldMap)
{
    return func_0216D888(func_021A3074(func_02188CB4(fieldMap)));
}

void func_021A2E44(FieldMap *fieldMap, u32 busy)
{
    ((FieldMapCtrlGridWork *)func_02188CA4(fieldMap))->busy = busy;
}
