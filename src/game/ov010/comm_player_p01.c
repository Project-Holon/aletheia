/*
 * file:     comm_player_p01.c
 * unit:     yes
 * function: func_02167380, func_02167394, func_021673A8, func_021673C4, func_021673E0, func_0216742C, func_02167444, func_0216745C, func_0216747C, func_0216749C, func_02167518, func_0216754C
 * address:  0x02167380
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   d_02171F5F  0x02171F5F  data  a1
 *   d_02171F3C 0x02171F3C data a1
 *   func_0200E06C  0x0200E06C  thumb
 *   func_0200E024  0x0200E024  thumb
 *   MI_CpuFill8    0x02082BCC  arm
 *   MI_CpuCopy8    0x02082D44  arm
 *   func_02030734 0x02030734 arm
 *   d_02172A18 0x02172A18 data a1
 *   func_02167658  0x02167658  thumb  ov010
 *   func_02012114  0x02012114  thumb
 *   func_021942C8  0x021942C8  thumb  ov021
 *   func_02034714  0x02034714  arm
 *   func_020307B0  0x020307B0  arm
 *   d_02172A28  0x02172A28  data  ov010  a4
 */
#include "../../matched/include/Obj17732.h"
#include "../../matched/include/Obj17733.h"
#include "../../matched/include/Obj07311.h"

struct Entry32;
struct Ctx;
typedef unsigned char u8;

typedef unsigned int u32;

typedef unsigned short u16;

typedef struct Entry32 {
    u32 id : 11;
    u32 rest : 21;
} Entry32;

struct O {
    int f0;
    int f4;
};

extern void func_0200E06C(char *p);
extern void func_0200E024(void *p);
extern void MI_CpuFill8(void *dst, u8 val, u32 size);
extern void MI_CpuCopy8(const void *src, void *dst, u32 size);
extern void *func_02030734(u32, u32, int, const char *, u16);
extern void func_02167658(struct O *o, int i);
extern unsigned int func_02012114(const struct Ctx *a);
extern void func_021942C8(int a);
extern void func_02034714(const char *expr, u32 line, const char *file);
extern u32 func_020307B0(void *p);
u8 func_02167380(u32 id);
u8 func_02167394(u32 i);
u8 func_021673A8(u8 *p);
u8 func_021673C4(u8 *p);
u8 func_021673E0(Entry32 *list, Entry32 *out, u32 cap, u32 start, int count);
u16 func_0216742C(int a0, int a1, int a2, int a3);
int func_02167444(int a0, int a1, int a2, int a3);
u16 func_0216745C(Entry32 *list, Entry32 *out, u32 cap, u32 page, u8 *n);
u16 func_0216747C(Entry32 *list, Entry32 *out, u32 cap, u32 page, u8 *n);
u16 func_0216749C(Entry32 *list, Entry32 *out, u32 cap, int page, u8 *n);
void *func_02167518(int a, void *b, u16 heap, int c);
void func_0216754C(int a, struct O *o);
extern u8 d_02171F5F[];
extern const u8 d_02171F3C[];
extern const char d_02172A18[];
extern const char d_02172A28[];

/*
 * Record-field accessor (third of the four-leaf run 0x02167358..0x021673A8):
 * returns byte 3 of the 4-byte record for id, 0 when id > 0x1d.  The record
 * table starts at 0x02171F5C; the pool word names the field address itself.
 * Unlabelled in the listing (no lr-saving prologue, callers all in arm9).
 */
u8 func_02167380(u32 id)
{
    if (id > 0x1d)
        return 0;
    return d_02171F5F[id * 4];
}

u8 func_02167394(u32 i) { if (i > 29) return 0; return d_02171F3C[i]; }


/*
 * Reads the byte at +0x848 of the shared state under its lock
 * (func_0200E06C / func_0200E024).
 */
u8 func_021673A8(u8 *p)
{
    u8 v;

    func_0200E06C((char *)p);
    v = p[0x848];
    func_0200E024(p);
    return v;
}


/*
 * Reads the byte at +0x849 of the shared state under its lock
 * (func_0200E06C / func_0200E024).
 */
u8 func_021673C4(u8 *p)
{
    u8 v;

    func_0200E06C((char *)p);
    v = p[0x849];
    func_0200E024(p);
    return v;
}


/*
 * Copies `count` 4-byte entries starting at index `start` out of the
 * shared list under its lock into a cleared buffer of `cap` entries, and
 * answers how many leading entries are in use (non-zero 11-bit id).
 */
u8 func_021673E0(Entry32 *list, Entry32 *out, u32 cap, u32 start, int count)
{
    int i;

    i = 0;
    MI_CpuFill8(out, 0, cap * 4);
    func_0200E06C((char *)list);
    MI_CpuCopy8(&list[start], out, count * 4);
    func_0200E024(list);
    for (i = 0; i < count; i++) {
        if (out[i].id == 0)
            break;
    }
    return i;
}


u16 func_0216742C(int a0, int a1, int a2, int a3)
{
    unsigned char fr[4];
    int t4;
    int o4;
t4 = a3 + 0;
a3 = 0xa;
    o4 = a3;
a3 = 0;
    a0 = func_021673E0((struct Entry32 *)a0, (struct Entry32 *)a1, a2, a3, o4);
loc_0216743C:
((struct Obj17732 *)((char *)t4))->f0 = a0;
a0 = 0;
    return a0;
}


int func_02167444(int a0, int a1, int a2, int a3)
{
    unsigned char fr[4];
    int t4;
    int o4;
t4 = a3 + 0;
a3 = 0xa;
    o4 = a3;
a3 = 0xa;
    a0 = func_021673E0((struct Entry32 *)a0, (struct Entry32 *)a1, a2, a3, o4);
loc_02167454:
((struct Obj17733 *)((char *)t4))->f0 = a0;
a0 = 0xa;
    return a0;
}


/*
 * One of the three 10-entry pages from index 20.
 */
u16 func_0216745C(Entry32 *list, Entry32 *out, u32 cap, u32 page, u8 *n)
{
    u16 start;

    start = page * 10 + 20;
    *n = func_021673E0(list, out, cap, start, 10);
    return start;
}


/*
 * One of the 20-entry pages from index 50.
 */
u16 func_0216747C(Entry32 *list, Entry32 *out, u32 cap, u32 page, u8 *n)
{
    u16 start;

    start = page * 20 + 50;
    *n = func_021673E0(list, out, cap, start, 20);
    return start;
}


/*
 * Fetches list page `page` (0: the first twenty entries, 1..3: ten-entry
 * pages, 4 and up: twenty-entry pages); answers its start index and the
 * number of used entries in *n.
 */
u16 func_0216749C(Entry32 *list, Entry32 *out, u32 cap, int page, u8 *n)
{
    u8 more;
    u16 start;

    more = 0;
    MI_CpuFill8(out, 0, cap * 4);
    if (page == 0) {
        start = func_0216742C((int)list, (int)out, cap, (int)n);
        out += 10;
        cap -= 10;
        func_02167444((int)list, (int)out, cap, (int)(&more));
        *n += more;
    } else if (page >= 1 && page < 4) {
        start = func_0216745C(list, out, cap, page - 1, n);
    } else {
        start = func_0216747C(list, out, cap, page - 4, n);
    }
    return start;
}

void *func_02167518(int a, void *b, u16 heap, int c) {
    u8 *p;
    p = func_02030734(heap, 148, 1, d_02172A18, 97);
    p[142] = a;
    ((struct Obj07311 *)p)->f0 = b;
    ((struct Obj07311 *)p)->f8C = heap;
    p[144] = c;
    return p;
}


void func_0216754C(int a, struct O *o)
{
    int i;
    if (o->f4 != 0) {
        for (i = 0; i < 4; i++)
            func_02167658(o, i);
        if (func_02012114((const struct Ctx *)a) == 1)
            func_021942C8(o->f4);
        else
            func_02034714(d_02172A28, 0, d_02172A28);
    }
    func_020307B0(o);
}
