/*
 * file:     unit_021F5260.c
 * unit:     yes
 * function: func_021F5260, func_021F526C, func_021F5278, func_021F5284, func_021F5290, func_021F529C, func_021F52A8, func_021F52B4, func_021F52C0, func_021F52CC, func_021F52D8, func_021F52E4, func_021F52F0, func_021F52FC, func_021F5308, func_021F5314, func_021F5320, func_021F532C, func_021F5338, func_021F5344, func_021F5350, func_021F535C, func_021F5368, func_021F5374, func_021F5380, func_021F538C, func_021F5398, func_021F53C8
 * address:  0x021F5260
 * region:   ov073
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0201210C 0x0201210C thumb
 *   func_02189A08 0x02189A08 thumb ov021
 *   func_021CF52C 0x021CF52C thumb ov021
 *   func_020122C0 0x020122C0 thumb
 *   func_020124E4  0x020124E4  thumb
 *   func_021CF560  0x021CF560  thumb  ov021
 *   func_02189A00  0x02189A00  thumb  ov021
 *   func_021C1DCC  0x021C1DCC  thumb  ov021
 *   func_02012374  0x02012374  thumb
 *   func_0204E720  0x0204E720  arm
 *   func_0204E804  0x0204E804  arm
 *   func_021F5488  0x021F5488  thumb  ov073
 */
#include "../ov021/fieldmap_types.h"

typedef unsigned char u8;
typedef unsigned int u32;
typedef signed int s32;

struct GameSystem;
struct GameEvent;
struct EncEff;

/*
 * Overlay 73 holds 26 encounter effect builders. Each one is the build
 * function of one row of the effect table in enceff.c (rows 3, 4, 10 to 30,
 * 32 to 34) and starts the same name cut-in event with its own row of the
 * cut-in table (overlay 74). The event flashes the screen twice, then runs
 * the cut-in of fld3d_ci.c.
 */

/* Memory of the cut-in event, allocated in the ENCEFF effect work. */
typedef struct EncEffNameCutInWork {
    int flashCount;     /* 0x00: white flashes done */
    int tableIndex;     /* 0x04: row of the cut-in table */
    int fadeVariant;    /* 0x08: build argument of the effect table row */
} EncEffNameCutInWork;

typedef int (*GameEventMainFunc)(struct GameEvent *event, int *state);

extern struct GameSystem *func_020124E4(struct GameEvent *event);
extern struct FieldMap *func_0201210C(const struct GameSystem *gameSystem);
extern struct EncEff *func_02189A08(struct FieldMap *fieldMap);
extern struct Fld3dCi *func_02189A00(struct FieldMap *fieldMap);
extern void *func_021CF52C(struct EncEff *eff, u32 size, u32 heapId);
extern EncEffNameCutInWork *func_021CF560(struct EncEff *eff);
extern struct GameEvent *func_020122C0(void *owner, void *arg, GameEventMainFunc main, u32 workSize);
extern void func_02012374(struct GameEvent *parent, struct GameEvent *child);
extern struct GameEvent *func_021C1DCC(struct GameSystem *gameSystem, struct Fld3dCi *ci, int tableIndex, int fadeVariant);
extern void func_0204E720(u32 flags, s32 start, s32 end, s32 step);
extern int func_0204E804(void);
extern int func_021F5488(struct GameEvent *event, int *state);

struct GameEvent *func_021F5260(struct GameSystem *gameSystem, struct FieldMap *fieldMap, int fadeVariant);
struct GameEvent *func_021F526C(struct GameSystem *gameSystem, struct FieldMap *fieldMap, int fadeVariant);
struct GameEvent *func_021F5278(struct GameSystem *gameSystem, struct FieldMap *fieldMap, int fadeVariant);
struct GameEvent *func_021F5284(struct GameSystem *gameSystem, struct FieldMap *fieldMap, int fadeVariant);
struct GameEvent *func_021F5290(struct GameSystem *gameSystem, struct FieldMap *fieldMap, int fadeVariant);
struct GameEvent *func_021F529C(struct GameSystem *gameSystem, struct FieldMap *fieldMap, int fadeVariant);
struct GameEvent *func_021F52A8(struct GameSystem *gameSystem, struct FieldMap *fieldMap, int fadeVariant);
struct GameEvent *func_021F52B4(struct GameSystem *gameSystem, struct FieldMap *fieldMap, int fadeVariant);
struct GameEvent *func_021F52C0(struct GameSystem *gameSystem, struct FieldMap *fieldMap, int fadeVariant);
struct GameEvent *func_021F52CC(struct GameSystem *gameSystem, struct FieldMap *fieldMap, int fadeVariant);
struct GameEvent *func_021F52D8(struct GameSystem *gameSystem, struct FieldMap *fieldMap, int fadeVariant);
struct GameEvent *func_021F52E4(struct GameSystem *gameSystem, struct FieldMap *fieldMap, int fadeVariant);
struct GameEvent *func_021F52F0(struct GameSystem *gameSystem, struct FieldMap *fieldMap, int fadeVariant);
struct GameEvent *func_021F52FC(struct GameSystem *gameSystem, struct FieldMap *fieldMap, int fadeVariant);
struct GameEvent *func_021F5308(struct GameSystem *gameSystem, struct FieldMap *fieldMap, int fadeVariant);
struct GameEvent *func_021F5314(struct GameSystem *gameSystem, struct FieldMap *fieldMap, int fadeVariant);
struct GameEvent *func_021F5320(struct GameSystem *gameSystem, struct FieldMap *fieldMap, int fadeVariant);
struct GameEvent *func_021F532C(struct GameSystem *gameSystem, struct FieldMap *fieldMap, int fadeVariant);
struct GameEvent *func_021F5338(struct GameSystem *gameSystem, struct FieldMap *fieldMap, int fadeVariant);
struct GameEvent *func_021F5344(struct GameSystem *gameSystem, struct FieldMap *fieldMap, int fadeVariant);
struct GameEvent *func_021F5350(struct GameSystem *gameSystem, struct FieldMap *fieldMap, int fadeVariant);
struct GameEvent *func_021F535C(struct GameSystem *gameSystem, struct FieldMap *fieldMap, int fadeVariant);
struct GameEvent *func_021F5368(struct GameSystem *gameSystem, struct FieldMap *fieldMap, int fadeVariant);
struct GameEvent *func_021F5374(struct GameSystem *gameSystem, struct FieldMap *fieldMap, int fadeVariant);
struct GameEvent *func_021F5380(struct GameSystem *gameSystem, struct FieldMap *fieldMap, int fadeVariant);
struct GameEvent *func_021F538C(struct GameSystem *gameSystem, struct FieldMap *fieldMap, int fadeVariant);
struct GameEvent *func_021F5398(struct GameSystem *gameSystem, struct FieldMap *unusedFieldMap, int tableIndex, int fadeVariant);
int func_021F53C8(struct GameEvent *event, int *state);


/* Build function of effect table row 10 (cut-in table row 0). */
struct GameEvent *func_021F5260(struct GameSystem *gameSystem, struct FieldMap *fieldMap, int fadeVariant)
{
    return func_021F5398(gameSystem, fieldMap, 0, fadeVariant);
}


/* Build function of effect table row 11 (cut-in table row 1). */
struct GameEvent *func_021F526C(struct GameSystem *gameSystem, struct FieldMap *fieldMap, int fadeVariant)
{
    return func_021F5398(gameSystem, fieldMap, 1, fadeVariant);
}


/* Build function of effect table row 12 (cut-in table row 2). */
struct GameEvent *func_021F5278(struct GameSystem *gameSystem, struct FieldMap *fieldMap, int fadeVariant)
{
    return func_021F5398(gameSystem, fieldMap, 2, fadeVariant);
}


/* Build function of effect table row 13 (cut-in table row 3). */
struct GameEvent *func_021F5284(struct GameSystem *gameSystem, struct FieldMap *fieldMap, int fadeVariant)
{
    return func_021F5398(gameSystem, fieldMap, 3, fadeVariant);
}


/* Build function of effect table row 14 (cut-in table row 4). */
struct GameEvent *func_021F5290(struct GameSystem *gameSystem, struct FieldMap *fieldMap, int fadeVariant)
{
    return func_021F5398(gameSystem, fieldMap, 4, fadeVariant);
}


/* Build function of effect table row 15 (cut-in table row 5). */
struct GameEvent *func_021F529C(struct GameSystem *gameSystem, struct FieldMap *fieldMap, int fadeVariant)
{
    return func_021F5398(gameSystem, fieldMap, 5, fadeVariant);
}


/* Build function of effect table row 16 (cut-in table row 6). */
struct GameEvent *func_021F52A8(struct GameSystem *gameSystem, struct FieldMap *fieldMap, int fadeVariant)
{
    return func_021F5398(gameSystem, fieldMap, 6, fadeVariant);
}


/* Build function of effect table row 17 (cut-in table row 7). */
struct GameEvent *func_021F52B4(struct GameSystem *gameSystem, struct FieldMap *fieldMap, int fadeVariant)
{
    return func_021F5398(gameSystem, fieldMap, 7, fadeVariant);
}


/* Build function of effect table row 18 (cut-in table row 8). */
struct GameEvent *func_021F52C0(struct GameSystem *gameSystem, struct FieldMap *fieldMap, int fadeVariant)
{
    return func_021F5398(gameSystem, fieldMap, 8, fadeVariant);
}


/* Build function of effect table row 19 (cut-in table row 9). */
struct GameEvent *func_021F52CC(struct GameSystem *gameSystem, struct FieldMap *fieldMap, int fadeVariant)
{
    return func_021F5398(gameSystem, fieldMap, 9, fadeVariant);
}


/* Build function of effect table row 20 (cut-in table row 10). */
struct GameEvent *func_021F52D8(struct GameSystem *gameSystem, struct FieldMap *fieldMap, int fadeVariant)
{
    return func_021F5398(gameSystem, fieldMap, 10, fadeVariant);
}


/* Build function of effect table row 21 (cut-in table row 11). */
struct GameEvent *func_021F52E4(struct GameSystem *gameSystem, struct FieldMap *fieldMap, int fadeVariant)
{
    return func_021F5398(gameSystem, fieldMap, 11, fadeVariant);
}


/* Build function of effect table row 22 (cut-in table row 12). */
struct GameEvent *func_021F52F0(struct GameSystem *gameSystem, struct FieldMap *fieldMap, int fadeVariant)
{
    return func_021F5398(gameSystem, fieldMap, 12, fadeVariant);
}


/* Build function of effect table row 23 (cut-in table row 13). */
struct GameEvent *func_021F52FC(struct GameSystem *gameSystem, struct FieldMap *fieldMap, int fadeVariant)
{
    return func_021F5398(gameSystem, fieldMap, 13, fadeVariant);
}


/* Build function of effect table row 24 (cut-in table row 14). */
struct GameEvent *func_021F5308(struct GameSystem *gameSystem, struct FieldMap *fieldMap, int fadeVariant)
{
    return func_021F5398(gameSystem, fieldMap, 14, fadeVariant);
}


/* Build function of effect table row 25 (cut-in table row 15). */
struct GameEvent *func_021F5314(struct GameSystem *gameSystem, struct FieldMap *fieldMap, int fadeVariant)
{
    return func_021F5398(gameSystem, fieldMap, 15, fadeVariant);
}


/* Build function of effect table row 26 (cut-in table row 16). */
struct GameEvent *func_021F5320(struct GameSystem *gameSystem, struct FieldMap *fieldMap, int fadeVariant)
{
    return func_021F5398(gameSystem, fieldMap, 16, fadeVariant);
}


/* Build function of effect table row 27 (cut-in table row 17). */
struct GameEvent *func_021F532C(struct GameSystem *gameSystem, struct FieldMap *fieldMap, int fadeVariant)
{
    return func_021F5398(gameSystem, fieldMap, 17, fadeVariant);
}


/* Build function of effect table row 28 (cut-in table row 18). */
struct GameEvent *func_021F5338(struct GameSystem *gameSystem, struct FieldMap *fieldMap, int fadeVariant)
{
    return func_021F5398(gameSystem, fieldMap, 18, fadeVariant);
}


/* Build function of effect table row 29 (cut-in table row 19). */
struct GameEvent *func_021F5344(struct GameSystem *gameSystem, struct FieldMap *fieldMap, int fadeVariant)
{
    return func_021F5398(gameSystem, fieldMap, 19, fadeVariant);
}


/* Build function of effect table row 30 (cut-in table row 20). */
struct GameEvent *func_021F5350(struct GameSystem *gameSystem, struct FieldMap *fieldMap, int fadeVariant)
{
    return func_021F5398(gameSystem, fieldMap, 20, fadeVariant);
}


/* Build function of effect table row 32 (cut-in table row 21). */
struct GameEvent *func_021F535C(struct GameSystem *gameSystem, struct FieldMap *fieldMap, int fadeVariant)
{
    return func_021F5398(gameSystem, fieldMap, 21, fadeVariant);
}


/* Build function of effect table row 33 (cut-in table row 22). */
struct GameEvent *func_021F5368(struct GameSystem *gameSystem, struct FieldMap *fieldMap, int fadeVariant)
{
    return func_021F5398(gameSystem, fieldMap, 22, fadeVariant);
}


/* Build function of effect table row 34 (cut-in table row 23). */
struct GameEvent *func_021F5374(struct GameSystem *gameSystem, struct FieldMap *fieldMap, int fadeVariant)
{
    return func_021F5398(gameSystem, fieldMap, 23, fadeVariant);
}


/* Build function of effect table row 3 (cut-in table row 24). */
struct GameEvent *func_021F5380(struct GameSystem *gameSystem, struct FieldMap *fieldMap, int fadeVariant)
{
    return func_021F5398(gameSystem, fieldMap, 24, fadeVariant);
}


/* Build function of effect table row 4 (cut-in table row 25). */
struct GameEvent *func_021F538C(struct GameSystem *gameSystem, struct FieldMap *fieldMap, int fadeVariant)
{
    return func_021F5398(gameSystem, fieldMap, 25, fadeVariant);
}

/* Starts the name cut-in event for one row of the cut-in table. */
struct GameEvent *func_021F5398(struct GameSystem *gameSystem, struct FieldMap *unusedFieldMap, int tableIndex, int fadeVariant)
{
    EncEffNameCutInWork *work;

    work = func_021CF52C(func_02189A08(func_0201210C(gameSystem)), 12, 0x50);
    work->flashCount = 0;
    work->tableIndex = tableIndex;
    work->fadeVariant = fadeVariant;
    return func_020122C0(gameSystem, 0, func_021F53C8, 0);
}

/*
 * Main step of the name cut-in event. States 0 to 2 flash the screen white
 * (fade out then in, twice); state 2 then starts the cut-in, or a plain fade
 * out when the cut-in cannot start; state 3 ends the event.
 */
int func_021F53C8(struct GameEvent *event, int *state)
{
    struct GameSystem *gameSystem;
    struct FieldMap *fieldMap;
    EncEffNameCutInWork *work;
    struct GameEvent *child;

    gameSystem = func_020124E4(event);
    fieldMap = func_0201210C(gameSystem);
    work = func_021CF560(func_02189A08(fieldMap));
    switch (*state) {
    case 0:
        func_0204E720(4, 0, 0x10, 0);
        *state = *state + 1;
    case 1:
        if (func_0204E804() == 0) {
            func_0204E720(4, 0x10, 0, 0);
            *state = *state + 1;
        }
        break;
    case 2:
        if (func_0204E804() == 0) {
            work->flashCount = work->flashCount + 1;
            if (work->flashCount < 2) {
                func_0204E720(4, 0, 0x10, 0);
                *state = 1;
            } else {
                child = func_021C1DCC(gameSystem, func_02189A00(fieldMap), work->tableIndex, work->fadeVariant);
                if (child != 0) {
                    func_02012374(event, child);
                } else {
                    child = func_020122C0(gameSystem, event, func_021F5488, 0);
                    func_02012374(event, child);
                }
                *state = *state + 1;
            }
        }
        break;
    case 3:
        return 1;
    }
    return 0;
}
