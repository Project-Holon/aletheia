/*
 * file:     worldtrade_enter_p01.c
 * unit:     yes
 * function: func_021F88B0, func_021F88D8, func_021F8908, func_021F8950, func_021F8990, func_021F89A8, func_021F89B4, func_021F89F0, func_021F8A18, func_021F8A3C, func_021F8A40
 * address:  0x021F88B0
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   d_022030E8 0x022030E8 data a2
 *   tbl_02202F0C  0x02202F0C  data
 *   func_0201F81C 0x0201F81C thumb
 *   func_0201F878 0x0201F878 thumb
 *   tbl_022030E8 0x022030E8 data a2
 *   func_021F50EC 0x021F50EC thumb ov135
 *   d_02203C1C 0x02203C1C data a4
 *   func_021F5074  0x021F5074  thumb  ov135
 *   func_021F4EC8  0x021F4EC8  thumb  ov135
 */
#include "../../matched/include/Obj02204.h"
#include "../../matched/include/Obj12203.h"
#include "../../matched/include/Obj12204.h"
#include "../../matched/include/Obj05413.h"
#include "../../matched/include/Obj08184.h"
#include "../../matched/include/Obj00287.h"

struct Slot;
struct Obj;
typedef unsigned char u8;

typedef signed char s8;

typedef unsigned short u16;

typedef signed short s16;

typedef unsigned int u32;

typedef signed int s32;

typedef struct {
    u8 start;
    u8 id;
} Range;

extern void *func_0201F81C(u32 n, u32 heap);
extern void func_0201F878(struct Slot *table, u32 a, u32 b, u32 tag, u32 heap);
extern s32 func_020200CC(struct Obj *o);
extern void func_020202EC(struct Obj *obj, u16 *out);
extern void func_020061E4(u32 id);
extern void func_021F50EC(u8 *);
extern void func_021F5074(u8 *p);
extern void func_021F4EC8(u8 *p);
void func_021F88B0(u8 *p,u32 n);
int func_021F88D8(u32 id, u32 *start);
int func_021F8908(void **menu, void *msg, int id);
int func_021F8950(void *p, u16 *old);
void func_021F8990(u8 *p);
void func_021F89A8(u8 *p, int i, u16 a, u16 b);
int func_021F89B4(u8 *p);
int func_021F89F0(u8 *p);
u32 func_021F8A18(u8 *p);
void func_021F8A3C(void *a0);
void func_021F8A40(void);
extern const u16 d_022030E8[];
extern const Range tbl_02202F0C[];
extern u16 tbl_022030E8[];

void func_021F88B0(u8 *p,u32 n) { if(n==0){((struct Obj02204 *)p)->fF84=0;return;}n--;if(n<130)((struct Obj02204 *)p)->fF84=d_022030E8[n]; }


int func_021F88D8(u32 id, u32 *start)
{
    int i;

    for (i = 0; i < 28; i++) {
        if (id == tbl_02202F0C[i].id) {
            *start = tbl_02202F0C[i].start;
            return tbl_02202F0C[i + 1].start - tbl_02202F0C[i].start;
        }
    }
    return 0;
}

#pragma opt_common_subs off

/*
 * Builds a message menu: reads the entry range for an id, allocates the table
 * and fills one slot per entry. The slot call takes five arguments (heap id
 * 0x48 on the stack), as in the other matched callers of func_0201F878 (the
 * arm9 definition lists four parameters; the fifth is passed but not read).
 * Closed with opt_common_subs off: the original does not share start + i
 * between the table index and the tag. 2026-10-05 (P21): plain form 16 bytes
 * off, only that pragma closes it. Table extern is not const (const gave 18).
 */
int func_021F8908(void **menu, void *msg, int id)
{
    int i;
    int count;
    u32 start;
    count = func_021F88D8(id, &start);
    *menu = func_0201F81C(count, 0x48);
    for (i = 0; (i < count) ? 1 : 0; i++) {
        func_0201F878(*menu, (u32)msg, tbl_022030E8[start + i], start + i + 1, 0x48);
    }
    return count;
}

#pragma opt_common_subs reset

int func_021F8950(void *p, u16 *old)
{
    u16 current;
    int result;
    result = func_020200CC(p);
    func_020202EC(p, &current);
    if (*old != current) {
        if (*old != 0xFFFF) func_020061E4(0x548);
        *old = current;
    }
    return result;
}

/*
 * Clear the two ten-entry u16 tables at +4 and +0x18 and the two header words.
 */
void func_021F8990(u8 *p)
{
    int i;
    u16 z = 0;

    for (i = 0; i < 10; i++) {
        *(u16 *)(p + i * 2 + 4) = z;
        *(u16 *)(p + i * 2 + 0x18) = z;
    }
    ((struct Obj12203 *)p)->f0 = z;
    ((struct Obj12203 *)p)->f2 = z;
}

/*
 * Store a pair of u16 values at +4 and +0x18 of record i.
 */
void func_021F89A8(u8 *p, int i, u16 a, u16 b)
{
    u8 *q = p + i * 2;

    ((struct Obj12204 *)q)->f4 = a;
    ((struct Obj12204 *)q)->f18 = b;
}

/*
 * volatile: hardware read-modify-write at 021F89C6/021F89CA, 0x04000304.
 */
int func_021F89B4(u8 *p) {func_021F50EC(p);func_021F8A3C(p);*(volatile u16 *)0x04000304 = (u16)(*(volatile u16 *)0x04000304 & ~0x8000);switch(((struct Obj05413 *)p)->f20){case 19:case 21:((struct Obj05413 *)p)->f28=2;break;case 20:((struct Obj05413 *)p)->f28=4;break;}return 1;}

extern int (*const d_02203C1C[])(void *);

int func_021F89F0(u8 *p) { int state,r;state=((struct Obj08184 *)p)->f28;r=d_02203C1C[state](p);if(state!=((struct Obj08184 *)p)->f28){((struct Obj08184 *)p)->fF88=0;((struct Obj08184 *)p)->fF8A=0;}return r; }


/*
 * Run the three teardown steps, then report 4 while the +0x10 handle is gone.
 */
u32 func_021F8A18(u8 *p)
{
    func_021F8A40();
    func_021F5074(p);
    func_021F4EC8(p);
    if (((struct Obj00287 *)p)->f10 == 0) {
        return 4;
    }
    return 0;
}

/*
 * Empty stub.
 */
void func_021F8A3C(void *a0)
{
}

void func_021F8A40(void)
{
}
