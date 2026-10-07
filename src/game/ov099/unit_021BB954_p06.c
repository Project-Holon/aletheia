/*
 * file:     unit_021BB954_p06.c
 * unit:     yes
 * function: func_021BC14C, func_021BC1C4
 * address:  0x021BC14C
 * region:   ov099
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_020399A8  0x020399A8  arm
 *   func_0203D1E8  0x0203D1E8  arm
 *   func_0203D378  0x0203D378  arm
 *   func_02039C68  0x02039C68  arm
 *   func_021BA874  0x021BA874  thumb  ov099
 *   func_021BAAB8  0x021BAAB8  thumb  ov099
 *   func_021BC090  0x021BC090  thumb  ov099
 *   func_021BA928  0x021BA928  thumb  ov099
 *   func_021BA828  0x021BA828  thumb  ov099
 */
#include "../../matched/include/Obj00008.h"

struct Link;
struct Entry;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32_021BC14C;

typedef unsigned long  u32_021BC1C4;

typedef signed char    s8;

typedef signed short   s16;

typedef signed long    s32;

typedef int BOOL;

extern struct Entry *func_020399A8(void);
extern void func_0203D1E8(u32_021BC14C unused, void *arg);
extern u32_021BC14C func_0203D378(void);
extern void func_02039C68(struct Link *p, u32_021BC14C lo, u32_021BC14C hi);
extern void func_021BA874(char *p, int id);
extern void func_021BAAB8(char *p, int a, int b);
extern void func_021BC090(char *p);
extern int func_021BA928(void *p, int v);
extern void func_021BA828(char *p);
int func_021BC14C(char *p, int v);
int func_021BC1C4(char *p, int v);


/*
 * 2026-10-05 (wD5 lane01): EXACT. Each arm ends with `off -= 0x76; p[off] = 0x42 / 0x49;`; tail
 *   merging builds the shared join. The value local r merged at the join swapped p and off.
 *   Older notes below.
 *
 * note (2026-10-04): DIFF, 124 vs 120 bytes. Original pushes r3-r7 (v in r6, zero local in r7), loads the 0x242 pool offset into r5 inside each arm and reuses it at the join as subs r5,#0x76 for the 0x1CC store; ours reads 0x242 into r1 (dies at the ldrh), builds 0x1CC separately, and uses only r4-r6. Semantics are right; the open question is what keeps the 0x242 constant live to the join.
 *
 * note (2026-10-04, lane17): lane17 wave D2: re-read, no new change. Same residue as the note above (0x242 pool offset kept in r5 to the join; pushes r3-r7).
 *
 * note: 2026-10-05 (wD4 lane20): constant-in-a-local lever applied: int off = 0x242 assigned in each arm, join is off -= 0x76; p[off] = r. Down from 50 to 14 differing bytes, same size, r4-r7 push set now matches, offset kept live to the join. Residue: p/off colour swap only (image p r4, off r5; ours p r5, off r4). Tried declaration orders of z/r/off, off initialised at the top (loses the r7 zero), off -= inside the index expression.
 */
int func_021BC14C(char *p, int v)
{
    int z;
    int off;
    func_0203D1E8((u32_021BC14C)func_020399A8(), 0);
    z = 0;
    if (func_0203D378() == 0) {
        *(int *)(p + 0x135C) = 3;
        off = 0x242;
        func_021BA874(p, *(u16 *)(p + off) - 1);
        func_021BAAB8(p, 0x5F, z);
        off -= 0x76;
        *(int *)(p + off) = 0x42;
    } else {
        *(int *)(p + 0x135C) = 4;
        off = 0x242;
        func_021BA874(p, *(u16 *)(p + off) - 1);
        func_021BAAB8(p, 0x7E, z);
        func_021BC090(p);
        func_02039C68((struct Link *)func_020399A8(), 0x1B, 0xA);
        off -= 0x76;
        *(int *)(p + off) = 0x49;
    }
    return v;
}


/*
 * Early-returns the selector when the guard is false, else runs the setup and stamps 0x43.
 */
int func_021BC1C4(char *p, int v)
{
    if (func_021BA928(p, v) == 0) {
        return v;
    }

    func_021BA828(p);
    *(u32_021BC1C4 *)&((struct Obj00008 *)p)->f1CC = 0x43;
    return v;
}
