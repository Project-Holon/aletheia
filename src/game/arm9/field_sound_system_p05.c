/*
 * file:     field_sound_system_p05.c
 * unit:     yes
 * function: func_02028FD0, func_02028FE0, func_02029040, func_020290F0
 * address:  0x02028FD0
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   g_flagTable_0209FE1C  0x0209FE1C  data
 */
#include "../../matched/include/Obj00354.h"
#include "../../matched/include/Obj00354.h"
#include "../../matched/include/Obj16754.h"

struct SoundParam;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

struct SoundParam {
    u8 pad00[4];
    u32 group;    /* +0x04 */
};

struct T_02028FE0 {
    u32 pad00[7];
    u32 f1c;
};

struct T_02029040 {
    u32 f00;
    u32 f04;
    u32 f08;
    u32 f0c;
    u32 f10;
    u32 f14;
    u32 f18;
    u32 f1c;
};

extern void func_02029344(void *obj, u32 value);
extern void func_02029364(u8 *p);
extern void func_02029374(u8 *p);
extern void func_020293D8(struct T_02028FE0 *p);
extern void func_0202945C(u8 *p);
extern int func_02029354(int a0);
extern void func_0202938C(u8 *p);
u32 func_02028FD0(struct SoundParam *obj, u32 kind);
void func_02028FE0(struct T_02028FE0 *p);
void func_02029040(struct T_02029040 *p);
void func_020290F0(u8 *p);
extern const u8 g_flagTable_0209FE1C[];


/*
 * Blocked: g_flagTable_0209FE1C is named by this function's one pool word
 * (0x02028FDC), which lies inside the compared range, so the `literal`
 * class discards it; the object is not a string and not a pointer table
 * (no outside witness for the `string` or `data_table` class either).
 * Every concrete byte reproduces.
 * 2026-09-21, FAMILY wave.  Re-verified in a fresh process: still MATCH,
 * every concrete byte identical.  Evidence worked to exhaustion:
 *   - `--suggest-split` reports "witnesses image wide: 1, of them inside
 *     this range: 1"; a single-function file has nothing to cut against.
 *   - No sibling in field_sound_system.c (0x02028844..0x02029EB4) references
 *     the object: the only other listing hits are the rodata DEFINITION in
 *     asm/arm9/src/030_*.s, which is a referent, not a referrer.
 *   - sole-ref/data was probed directly.  in_data_section = True and the
 *     layout/data_objects.txt row IS an object start when the range is
 *     ignored, but `_map_attests(addr, lo, hi)` = False once the range is
 *     applied, because that row's sole referrer is this function's own pool
 *     word.  This is the documented "a lone reference never contributes its
 *     own start" rule firing correctly, not a tooling gap.
 * Declarations cross-checked against docs/families/field_sound_system.h.
 */
u32 func_02028FD0(struct SoundParam *obj, u32 kind)
{
    const u8 *p = g_flagTable_0209FE1C + obj->group * 8;
    return p[kind];
}


void func_02028FE0(struct T_02028FE0 *p)
{
    switch (p->f1c) {
    case 0:
    case 1:
    case 2:
    case 3:
        break;
    case 4:
        func_020293D8(p);
        func_02029374((u8 *)p);
        func_02029344(p, 7);
        break;
    case 5:
        func_02029344(p, 8);
        break;
    case 6:
        func_02029344(p, 0xd);
        break;
    case 7:
        func_0202945C((u8 *)p);
        func_02029344(p, 1);
        func_02029364((u8 *)p);
        break;
    }
}


/*
 * A Thumb `add pc, r0` switch on p->f1c with eight arms, the twin of
 * func_02028FE0 in the same packet.  Every callee takes the object pointer,
 * which is why the switch index lives in r1 and r0 keeps holding p.
 */
void func_02029040(struct T_02029040 *p)
{
    switch (p->f1c) {
    case 0:
        break;
    case 1:
        func_02029354((int)p);
        break;
    case 2:
        func_0202938C((u8 *)p);
        func_02029344(p, 3);
        break;
    case 3:
        func_0202938C((u8 *)p);
        func_02029344(p, 5);
        break;
    case 4:
        func_0202938C((u8 *)p);
        func_02029344(p, 6);
        break;
    case 5:
        if (p->f0c == p->f08) {
            func_02029354((int)p);
        } else {
            func_0202938C((u8 *)p);
            func_02029344(p, 8);
        }
        break;
    case 6:
        if (p->f0c == p->f08) {
            func_02029354((int)p);
        } else {
            func_0202938C((u8 *)p);
            func_02029344(p, 0xd);
        }
        break;
    case 7:
        if (p->f0c == p->f08) {
            func_02029354((int)p);
        } else {
            func_0202945C((u8 *)p);
            func_02029344(p, 1);
            func_02029364((u8 *)p);
        }
        break;
    }
}


void func_020290F0(u8 *p)
{
    switch (((struct Obj16754 *)p)->f1C) {
    case 0:
        break;
    case 1:
        func_02029374(p);
        func_02029344(p, 4);
        break;
    case 7:
        func_0202945C(p);
        func_02029344(p, 1);
        func_02029364(p);
        break;
    }
}
