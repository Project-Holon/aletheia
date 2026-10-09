/*
 * file:     comm_player_p01.c
 * unit:     yes
 * function: func_02167380, func_02167394, func_021673A8, func_021673C4, func_021673E0, func_0216742C, func_02167444, func_0216745C, func_0216747C, func_0216749C, func_02167518, func_0216754C, func_02167590, func_021675D0, func_02167658, func_02167688, func_021676E4, func_02167794, func_021677E4, func_02167810, func_02167848, func_0216786C, func_021679A4, func_021679C4, func_02167A14, func_02167A54, func_02167A74, func_02167AB0, func_02167AC4, func_02167B00, func_02167B18, func_02167B24, func_02167B34, func_02167B44, func_02167B9C, func_02167BB4, func_02167BCC, func_02167BD8, func_02167BE4, func_02167BF0
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
 *   func_02012114  0x02012114  thumb
 *   func_021942C8  0x021942C8  thumb  ov021
 *   func_02034714  0x02034714  arm
 *   func_020307B0  0x020307B0  arm
 *   d_02172A28  0x02172A28  data  ov010  a4
 *   func_021BB5C8  0x021BB5C8  thumb
 *   func_02194300  0x02194300  thumb  ov021
 *   func_02194354 0x02194354 thumb ov021
 *   func_0201210C  0x0201210C  thumb
 *   func_02188C7C  0x02188C7C  thumb  ov021
 *   func_02194284  0x02194284  thumb  ov021
 *   func_02082BCC  0x02082BCC  arm
 *   func_020120F4  0x020120F4  thumb
 *   func_020127A4  0x020127A4  thumb
 *   func_02012B28  0x02012B28  thumb
 *   func_02012B38  0x02012B38  thumb
 *   func_02014484  0x02014484  thumb
 *   func_02188BE8  0x02188BE8  thumb  ov021
 *   func_02188CB4  0x02188CB4  thumb  ov021
 *   func_021A3074  0x021A3074  thumb  ov021
 *   func_021A34EC  0x021A34EC  thumb  ov021
 *   func_021A3038  0x021A3038  thumb  ov021
 *   func_02197CCC  0x02197CCC  thumb  ov021
 *   func_021A3050  0x021A3050  thumb  ov021
 *   func_02012AA0  0x02012AA0  thumb
 *   func_02012AE4  0x02012AE4  thumb
 *   func_0203EFC8  0x0203EFC8  arm
 *   func_02194384   0x02194384  thumb
 *   func_02188CD0  0x02188CD0  thumb  ov021
 *   func_021943EC  0x021943EC  thumb  ov021
 *   func_021BB578  0x021BB578  thumb
 *   func_0203CBAC  0x0203CBAC  arm
 *   d_02172014  0x02172014  data  ov010
 *   func_02012944 0x02012944 thumb
 *   func_02008494 0x02008494 thumb
 *   func_02087C6C 0x02087C6C arm
 *   func_0203A574 0x0203A574 arm
 *   d_02171FD4 0x02171FD4 data ov010 a4
 *   func_0203A5E4  0x0203A5E4  arm
 *   func_020399A8  0x020399A8  arm
 *   func_0203D594  0x0203D594  arm
 *   func_0203D5A0  0x0203D5A0  arm
 *   func_021CA210  0x021CA210  thumb  ov021
 *   func_02008550  0x02008550  thumb
 *   func_0201AB28  0x0201AB28  thumb
 *   func_02017E1C  0x02017E1C  thumb
 *   func_021CA234  0x021CA234  thumb  ov021
 *   func_021CA2CC  0x021CA2CC  thumb  ov021
 *   func_02082D44  0x02082D44  arm
 */
#include "../../matched/include/Obj17732.h"
#include "../../matched/include/Obj17733.h"
#include "../../matched/include/Obj07311.h"
#include "../../matched/include/Obj12372.h"
#include "../../matched/include/Obj12373.h"
#include "../../matched/include/Obj17734.h"
#include "../../matched/include/Obj00020.h"
#include "../../matched/include/Obj19012.h"
#include "../../matched/include/Obj19013.h"

struct Entry32;
struct Ctx;
struct BigObj;
struct Rec44;
struct SaveBlock;
struct Sub02014444Obj;
struct Obj00020;
struct Tbl;
struct Req;
struct Entry;
struct Sub0200852CObj;
typedef unsigned char u8;

typedef unsigned int u32;

typedef unsigned short u16;

typedef struct Entry32 {
    u32 id : 11;
    u32 rest : 21;
} Entry32;

typedef struct { void *sys; void *obj; } Work_02167658;

typedef struct Ent_02167590 {
    u8 pad00[0x14];
    u8 used : 1;
    u8 pend : 1;
    u8 dir : 4;
    u8 f15[3];
    u32 f18;
} Ent_02167590;

typedef struct Work_02167590 {
    void *sys;
    void *obj;
    Ent_02167590 e[4];
} Work_02167590;

typedef unsigned long long u64;

typedef struct Blk12 {
    u64 lo;
    u32 hi;
} Blk12;

typedef struct Ent_021675D0 {
    Blk12 pos;
    u32 f0c;
    u16 f10;
    u16 f12;
    u8 used : 1;
    u8 pend : 1;
    u8 dir : 4;
    u8 f15[3];
    u32 f18;
} Ent_021675D0;

typedef struct Work_021675D0 {
    void *sys;
    void *obj;
    Ent_021675D0 e[4];
    u8 pad78[0x8C - 0x78];
    u16 f8c;
    u8 f8e;
    u8 pad8f;
    u8 f90;
} Work_021675D0;

typedef struct Src_02167380 {
    u32 f0;
    Blk12 pos;
    u16 f10;
} Src_02167380;

typedef struct { u8 used:1; u8 rest:7; u8 pad[3]; u32 f04; u8 tail[20]; } Slot_02167380;

typedef struct { u8 pad[28]; Slot_02167380 slot; } Row_02167380;

typedef struct Slot_02167688 {
    u8 used : 1;
    u8 pend : 1;
    u8 dir : 4;
    u8 pad[0x1B];
} Slot_02167688;

typedef struct Vec3 {
    u32 x;
    u32 y;
    u32 z;
} Vec3;

typedef struct Src_02167688 {
    u32 f0;
    Vec3 pos;
    u16 f10;
    u8 dir;
} Src_02167688;

typedef struct { u8 used:1; u8 rest:7; u8 pad[27]; } Slot;

typedef struct { u8 pad[28]; Slot slot; } Row_021677E4;

typedef struct Blk12_02167810 {
    u64 lo;
    u32 hi;
} Blk12_02167810;

typedef struct Ent_021677E4 {
    Blk12_02167810 pos;
    u32 f0c;
    u16 f10;
    u16 f12;
    u8 used : 1;
    u8 pend : 1;
    u8 dir : 4;
    u8 f15[3];
    u32 f18;
} Ent_021677E4;

typedef struct Work_02167810 {
    void *sys;
    void *obj;
    Ent_021677E4 e[4];
} Work_02167810;

typedef struct {
    u64 lo;
    u32 hi;
} Blk12_02167848;

typedef int s32;

typedef s32 fx32;

typedef struct VecFx32 {
    fx32 x;
    fx32 y;
    fx32 z;
} VecFx32;

typedef struct Where {
    VecFx32 pos;        /* 0x00 */
    u16 zone;           /* 0x0C */
    u8 dir : 4;         /* 0x0E */
    u8 flag : 1;
} Where;

typedef struct Report {
    u32 flag;           /* 0x00 */
    VecFx32 pos;        /* 0x04 */
    u16 zone;           /* 0x10 */
    u8 dir;             /* 0x12 */
} Report;

typedef struct Work_0216786C {
    void *sys;          /* 0x00 */
    u8 pad04[0x78 - 0x04];
    Where last;         /* 0x78 */
    u8 pad88[0x8F - 0x88];
    u8 f8f;             /* 0x8F */
} Work_0216786C;

typedef struct Blk12_021679C4 {
    u64 lo;
    u32 hi;
} Blk12_021679C4;

typedef struct Work_021679C4 {
    void *sys;
    void *obj;
    Ent_021677E4 e[4];
} Work_021679C4;

typedef struct Ent_02167A14 {
    Blk12 pos;
    u32 f0c;
    u16 f10;
    u16 f12;
    u8 used : 1;
    u8 pend : 1;
    u8 dir : 4;
    u8 f15[3];
    u32 f18;
} Ent_02167A14;

typedef struct Work {
    void *sys;
    void *obj;
    Ent_02167A14 e[4];
} Work;

typedef struct {
    unsigned char b0 : 1;
} Flag;

typedef struct Obj_02167B44 {
    u8 pad00[0x1E];
    u8 b1e[2];
    u8 pad20[0x668 - 0x20];
    u16 h668;
    u16 h66a[2];
    u16 h66e;
} Obj_02167B44;

typedef struct Obj_02167B9C {
    u8 pad00[0x32];
    u8 b32[0x668 - 0x32];
    u8 b668[0x1C];
} Obj_02167B9C;

typedef struct Obj_02167BB4 {
    u8 pad00[0x0C];
    u16 h0c_b0 : 3;
    u16 b3 : 1;
    u16 h0c_rest : 12;
    u8 pad0e[0x668 - 0x0E];
    u16 h668;
} Obj_02167BB4;

typedef struct Obj_02167BCC {
    u8 pad00[9];
    u8 b09;
    u8 pad0a[0x668 - 0x0A];
    u32 w668;
} Obj_02167BCC;

typedef struct Obj_02167BD8 {
    u8 pad00[0x668];
    u32 w668;
} Obj_02167BD8;

typedef struct Obj_02167BE4 {
    u8 pad00[0x668];
    u32 w668;
} Obj_02167BE4;

typedef struct Obj {
    u8 pad00[0x668];
    u32 w668;
} Obj;

extern void func_0200E06C(char *p);
extern void func_0200E024(void *p);
extern void MI_CpuFill8(void *dst, u8 val, u32 size);
extern void MI_CpuCopy8(const void *src, void *dst, u32 size);
extern void *func_02030734(u32, u32, int, const char *, u16);
extern unsigned int func_02012114(const struct Ctx *a);
extern void func_021942C8(void *obj);
extern void func_02034714(const char *expr, u32 line, const char *file);
extern u32 func_020307B0(void *p);
extern int func_021BB5C8(u32 v);
extern void func_02194300(u16 *a, int b, int c, u16 *d, int e, int f);
extern void func_02194354(void *, u32);
extern void *func_0201210C(const struct Ctx *p);
extern void *func_02188C7C(u8 *p);
extern void *func_02194284(int a, void *b, int heap, int c);
extern void func_02082BCC(void *p, int v, int n);
extern void *func_020120F4(const struct Ctx *p);
extern void *func_020127A4(struct SaveBlock *p);
extern u32 func_02012B28(const struct Rec44 *p);
extern void *func_02012B38(const struct BigObj *p);
extern u8 func_02014484(struct Sub02014444Obj *o);
extern int func_02188BE8(void *proc);
extern void *func_02188CB4(struct Obj00020 *p);
extern void *func_021A3074(u8 *p);
extern int func_021A34EC(u8 *p);
extern void func_021A3038(unsigned char *p, struct VecFx32 *out);
extern void func_02197CCC(u8 *p, s32 *out);
extern u16 func_021A3050(u8 *p);
extern VecFx32 *func_02012AA0(void *pl);
extern u16 func_02012AE4(void *pl);
extern s32 func_0203EFC8(const u8 *a, const u8 *b, u32 n);
extern int func_02194384(int, int, int, int, int, int);
extern u32 func_02188CD0(u8 *p);
extern u32 func_021943EC(struct Tbl *t, u32 key);
extern u32 func_021BB578(void *a, void *b, int c, int d);
extern void func_0203CBAC(struct Req *req, u32 a2, u32 a3);
extern u8 *func_02012944(void *p);
extern void func_02008494(void *, void *);
extern void func_02087C6C(void *);
extern void func_0203A574(u32, u32, u32, u32);
void func_0203A5E4(u32 key);
extern struct Entry *func_020399A8(void);
extern int func_0203D594();
extern int func_0203D5A0();
extern void *func_021CA210(u8 *p);
extern u8 func_02008550(const struct Sub0200852CObj *obj);
extern void *func_0201AB28(void *p, u32 idx);
extern u32 func_02017E1C(void *p, u32 id, u32 v);
extern u16 func_021CA234(u8 *p);
extern u16 func_021CA2CC(u16 v);
extern void func_02082D44(void *dst, void *src, int n);
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
void func_0216754C(int a, Work_02167658 *o);
void func_02167590(void *a, Work_02167590 *w);
void func_021675D0(Work_021675D0 *w, int idx, int a2, Src_02167380 *src);
void func_02167658(Work_02167658 *p, int i);
void func_02167688(Work_021675D0 *w);
void func_021676E4(Work_021675D0 *w);
void func_02167794(Work_02167658 *w);
int func_021677E4(void *p, int i);
u16 func_02167810(Work_02167810 *w, int i);
void func_02167848(char *a0, int a1, char *a2);
int func_0216786C(Work_0216786C *w, Report *out);
int func_021679A4(void *a0, int a1, int a2, int a3, int a4, int a5);
int func_021679C4(Work_021679C4 *w, int i);
u32 func_02167A14(Work *w, int i);
int func_02167A54(int *p, int i);
void func_02167A74(int a0, int a1);
void func_02167AB0(void *p);
void *func_02167AC4(u8 *p);
int func_02167AF0(void);
int func_02167AF4(int a, int b);
void func_02167B00(u32 a);
void func_02167B18(void *p);
int func_02167B24(int a0);
int func_02167B34(int a0);
void func_02167B44(Obj_02167B44 *o, void *a1);
void func_02167B9C(Obj_02167B9C *o);
void func_02167BB4(Obj_02167BB4 *o, u16 v);
void func_02167BCC(Obj_02167BCC *o);
void func_02167BD8(Obj_02167BD8 *o, u32 v);
void func_02167BE4(Obj_02167BE4 *o, u32 v);
void func_02167BF0(Obj *o, u32 v);
extern u8 d_02171F5F[];
extern const u8 d_02171F3C[];
extern const char d_02172A18[];
extern const char d_02172A28[];
extern u8 d_02172014[];
extern const u32 d_02171FD4[];




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





void func_0216754C(int a, Work_02167658 *o)
{
    int i;
    if (o->obj != 0) {
        for (i = 0; i < 4; i++)
            func_02167658(o, i);
        if (func_02012114((const struct Ctx *)a) == 1)
            func_021942C8(o->obj);
        else
            func_02034714(d_02172A28, 0, d_02172A28);
    }
    func_020307B0(o);
}





void func_02167590(void *a, Work_02167590 *w)
{
    int i;

    func_02167A74((int)a, (int)w);
    if (func_02012114(w->sys) == 1) {
        for (i = 0; i < 4; i++) {
            if (w->e[i].used == 1 && w->e[i].f18 != 0 && func_021BB5C8(w->e[i].f18) == 1)
                w->e[i].f18 = 0;
        }
    }
}





static inline void cpy(Blk12 *d, Blk12 *s)
{
    *d = *s;
}





void func_021675D0(Work_021675D0 *w, int idx, int a2, Src_02167380 *src)
{
    if (w->obj != 0 && w->e[idx].used != 1) {
        cpy(&w->e[idx].pos, &src->pos);
        *(u16 *)((char *)w + idx * 0x1C + 0x18) = src->f10;
        *(u32 *)((char *)w + idx * 0x1C + 0x14) = src->f0;
        w->e[idx].f12 = a2;
        w->e[idx].pend = 0;
        w->e[idx].used = 1;
        w->e[idx].f18 = 0;
        func_02194300(w->obj, idx, a2, &w->e[idx].f10, (int)(&w->e[idx]), (int)(&w->e[idx].f0c));
    }
}




/*
 * lever: test the one-bit field directly; == 1 inserts an extra cmp.
 * domain: no index bound assumed; flag base and unsigned scaled offset use modulo-32 address arithmetic, with no fixed-array subscript.
 * address lever: separate flags base and off locals preserve the original base/offset registers; a combined raw address folds i+1, while Row_02167380 accesses share the scaled pointer.
 */
void func_02167658(Work_02167658 *p, int i) {
    Slot_02167380 *flags;
    u32 off;
    flags = (Slot_02167380 *)((u32)p + 28u);
    off = (u32)i * 28u;
    if (((Slot_02167380 *)((u32)flags + off))->used && p->obj != 0) {
        *(u32 *)((u32)p + off + 32u) = 0;
        func_02194354(p->obj, i);
        ((Slot_02167380 *)((u32)flags + off))->used = 0;
    }
}




void func_02167688(Work_021675D0 *w)
{
    Slot_02167688 *s;
    int i;

    if (func_02012114(w->sys) != 1)
        func_02034714((const char *)d_02172A28, 0, (const char *)d_02172A28);
    if (w->obj != 0) {
        i = 0;
        s = (Slot_02167688 *)((char *)w + 0x1C);
        for (; i < 4; i++) {
            if (s[i].used == 1) {
                func_02167658((Work_02167658 *)w, i);
                *(u8 *)&s[i] |= 2;
            }
        }
        func_021942C8(w->obj);
        w->obj = 0;
    }
}




void func_021676E4(Work_021675D0 *w)
{
    Src_02167688 t;
    Slot_02167688 *s;
    int i;

    if (func_02012114(w->sys) != 1)
        func_02034714((const char *)d_02172A28, 0, (const char *)d_02172A28);
    if (w->obj != 0)
        func_02034714((const char *)d_02172A28, 0, (const char *)d_02172A28);
    w->obj = func_02194284(w->f8e, func_02188C7C(func_0201210C(w->sys)), w->f8c, w->f90);
    func_02082BCC(&t, 0, 0x14);
    s = (Slot_02167688 *)w;
    s = (Slot_02167688 *)((char *)s + 0x1C);
    for (i = 0; i < 4; i++) {
        if (s[i].pend == 1) {
            t.pos = *(Vec3 *)&w->e[i].pos;
            t.f10 = w->e[i].f10;
            t.f0 = 0;
            t.dir = s[i].dir;
            func_021675D0(w, i, w->e[i].f12, (Src_02167380 *)&t);
        }
    }
}




void func_02167794(Work_02167658 *w)
{
    Slot_02167688 *s;
    int i;

    if (func_02012114(w->sys) != 1)
        func_02034714((const char *)d_02172A28, 0, (const char *)d_02172A28);
    if (w->obj != 0)
        func_02034714((const char *)d_02172A28, 0, (const char *)d_02172A28);
    i = 0;
    s = (Slot_02167688 *)((char *)w + 0x1C);
    for (; i < 4; i++) {
        if (s[i].pend == 1)
            s[i].pend = 0;
    }
}





/*
 * domain: the signed i>=4 guard admits negative indices; raw unsigned scaling preserves the original modulo-32 address arithmetic without a fixed-array bound.
 * address lever: Row_021677E4 supplies the +28 load offset after unsigned scaling; combining +28 with the scaled index folds i+1 and changes the instructions.
 */
int func_021677E4(void *p, int i) {
    if (p == 0 || i >= 4) func_02034714(d_02172A28, 0, d_02172A28);
    return ((Row_021677E4 *)((u32)p + (u32)i * 28u))->slot.used;
}






u16 func_02167810(Work_02167810 *w, int i)
{
    if (w == 0 || i >= 4 || w->e[i].used != 1)
        func_02034714((const char *)d_02172A28, 0, (const char *)d_02172A28);
    return w->e[i].f12;
}






/*
 * Recursive MATCH unblocker: callee of func_0217FF78 (ov019) +005C.  An
 * unlabelled Thumb leaf inside ov010: `disasm.py` emitted its body as the
 * `pool_02167844` word run because its `push {r4, r5}` prologue saves no `lr`
 * (docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md).  ov009 holds
 * ARM data at the address, ov011/ov018/ov019 only call it, so ov010 is the
 * region it lives in.
 *
 * The byte shape turns on the 12-byte aggregate copy: writing the +8 block as
 * one `struct { u64; u32; }` assignment is what makes mwcc evaluate the
 * destination address first (dst in r3, a2 kept in r2) and emit the exact
 * `ldm r5!`/`stm r4!` run.  Splitting it into a `u64` store plus a `u32` store
 * (or an explicit `dst` local, u32 index, Src/Dst structs) makes the allocator
 * compute the source address first and move a2 into r4, losing the whole range.
 * See docs/notes/recursive-match-unblocker-ov010-0215.c.txt and
 * docs/idioms/a-twelve-byte-aggregate-copy-pins-the-destination-first.md.
 */
void func_02167848(char *a0, int a1, char *a2)
{
    char *d = a0 + a1 * 0x1C;

    *(Blk12_02167848 *)(d + 8) = *(Blk12_02167848 *)(a2 + 4);
    ((struct Obj12373 *)d)->f18 = ((struct Obj12372 *)a2)->f10;
    ((struct Obj12373 *)d)->f14 = ((struct Obj12372 *)a2)->f0;
}






/*
 * Report the player's position, zone and facing (from the saved copy
 * while flying, from the ov021 rail object, or from the player object),
 * returning 1 only when it differs from the last report. One lever: the
 * change test written positively so the update block comes before the
 * `return 0`.
 */
int func_0216786C(Work_0216786C *w, Report *out)
{
    VecFx32 pos;
    void *a;
    void *pl;
    void *ctx;
    Where *last;
    void *q;
    u32 flag;
    u32 dir;
    u16 zone;

    ctx = func_020120F4(w->sys);
    last = &w->last;
    flag = 0;
    if (w->f8f == 1)
        return 0;
    pl = func_020127A4(ctx);
    dir = func_02012B28(pl);
    if (func_02014484(func_02012B38(ctx)) == 2) {
        zone = last->zone;
        pos = last->pos;
        flag = 1;
        dir = last->dir;
    } else if (func_02012114(w->sys) == 1 && func_02188BE8(func_0201210C(w->sys)) == 1) {
        q = func_02188CB4(func_0201210C(w->sys));
        a = func_021A3074(q);
        if (func_021A34EC(q) == 4)
            func_021A3038(q, &pos);
        else
            func_02197CCC(a, (s32 *)(&pos));
        zone = func_021A3050(q);
    } else {
        pos = *func_02012AA0(pl);
        zone = func_02012AE4(pl);
    }
    out->zone = zone;
    out->pos = pos;
    out->flag = flag;
    out->dir = dir;
    if (zone != last->zone || dir != last->dir || flag != last->flag
        || func_0203EFC8((const u8 *)(&pos), (const u8 *)last, sizeof(VecFx32)) != 0) {
        last->zone = zone;
        last->pos = pos;
        last->dir = dir;
        last->flag = flag;
        return 1;
    }
    return 0;
}






/*
 * The record's second word is the first argument of the six-argument
 * overlay call, with a zero bail.
 */
int func_021679A4(void *a0, int a1, int a2, int a3, int a4, int a5)
{
    int v = ((struct Obj17734 *)a0)->f4;

    if (v == 0)
        return 0;

    return func_02194384(v, a1, a2, a3, a4, a5);
}






int func_021679C4(Work_021679C4 *w, int i)
{
    Ent_021677E4 *e;
    void *a;

    e = &w->e[i];
    if (w->obj == 0 || e->used == 0 || e->f18 != 0)
        return 0;
    a = (void *)func_02188CD0(func_0201210C(w->sys));
    e->f18 = func_021BB578(a, (void *)func_021943EC(w->obj, i), 0, 0);
    return 1;
}






u32 func_02167A14(Work *w, int i)
{
    if (w->obj == 0)
        func_02034714((const char *)d_02172A28, 0, (const char *)d_02172A28);
    if (w->e[i].used != 1)
        func_02034714((const char *)d_02172A28, 0, (const char *)d_02172A28);
    return func_021943EC(w->obj, i);
}






/*
 * Unlabelled leaf (sole blocker of ov018 func_0217FCAC).
 */
int func_02167A54(int *p, int i)
{
    if (p == 0 || p[1] == 0 || !((Flag *)((char *)p + i * 0x1c + 0x1c))->b0) {
        return 0;
    }
    return 1;
}






void func_02167A74(int a0, int a1)
{
    int a2;
    int a3;
    int t4;
    void *res;
    void *v0;
    void *v1;

t4 = a1 + 0;
a1 = *(int *)&((struct Obj00020 *)t4)->f4;
    if (a1 != 0) goto loc_02167AAE;
loc_02167A7E:
    v0 = func_0201210C((void *)a0);
loc_02167A82:
    if (v0 == 0) goto loc_02167AAE;
loc_02167A86:
    a0 = func_02188BE8(v0);
loc_02167A8A:
    if (a0 == 0) goto loc_02167AAE;
loc_02167A8E:
    v1 = func_02188C7C(v0);
loc_02167A94:
a0 = t4 + 0;
a2 = t4 + 0;
a3 = t4 + 0;
a0 = a0 + 0x8e;
a2 = a2 + 0x8c;
a3 = a3 + 0x90;
a0 = *(u8 *)&((struct Obj00020 *)((char *)a0))->f0;
a2 = *(u16 *)&((struct Obj00020 *)((char *)a2))->f0;
a3 = *(u8 *)&((struct Obj00020 *)((char *)a3))->f0;
    res = func_02194284(a0, v1, a2, a3);
loc_02167AAC:
((struct Obj00020 *)t4)->f4 = res;
loc_02167AAE:
    return;}






/*
 * Tail call to ARM func_0203CBAC with (&d_02172014, 0, arg). No lr-saving
 * prologue; bl from ov021 func_021CA5C4 at 0x021CB4F4.
 */
void func_02167AB0(void *p)
{
    func_0203CBAC((struct Req *)d_02172014, 0, (u32)p);
}





/*
 * Trailing unlabelled constant getter and equality predicate are included.
 */
void *func_02167AC4(u8 *p)
{
    u8 *q;
    q = p + 0x6f4;
    func_02008494(func_02012944(((struct Obj19012 *)p)->f6C), q);
    func_02087C6C(q + 0x20);
    ((struct Obj19013 *)q)->f26 = 0x3a0b;
    return q;
}





int func_02167AF0(void)
{
    return 0x28;
}





int func_02167AF4(int a, int b)
{
    if (a == b) return 1;
    return 0;
}





/*
 * Trailing extent is already matched func_02167B18.
 */
void func_02167B00(u32 a)
{
    func_0203A574(0x2c00, (u32)d_02171FD4, 0x2c08, a);
}






/*
 * Unlabelled leaf, blocker of ov021 func_021CB8AC: tail call of func_0203A5E4(0x2C00); the argument is ignored.
 * Overlay choice, ov009 and ov010 share this window; ov009 holds ARM code here,
 * ov010 holds this Thumb routine, and the ov021 callers already name ov010
 * (ov010 is the overlay resident with ov021).
 *
 * Addresses are Black-image addresses.
 */
void func_02167B18(void *p)
{
    func_0203A5E4(0x2c00);
}






int func_02167B24(int a0)
{
    int a1;
    int t4;
    struct Entry *e;

t4 = a0 + 0;
    e = func_020399A8();
loc_02167B2C:
a1 = t4 + 0;
    a0 = func_0203D594(e, a1);
loc_02167B32:
    return a0;}






int func_02167B34(int a0)
{
    int a1;
    int t4;
    struct Entry *e;

t4 = a0 + 0;
    e = func_020399A8();
loc_02167B3C:
a1 = t4 + 0;
    a0 = func_0203D5A0(e, a1);
loc_02167B42:
    return a0;}






void func_02167B44(Obj_02167B44 *o, void *a1)
{
    void *t;
    void *list;
    int i;

    t = func_02012944(a1);
    list = func_021CA210((u8 *)o);
    o->h668 = func_02008550(t);
    for (i = 0; i < 2; i++)
        o->h66a[i] = func_02017E1C(func_0201AB28(list, o->b1e[i]), 5, 0);
    o->h66e = func_021CA2CC(func_021CA234((u8 *)o));
}






/*
 * Unlabelled Thumb leaf hidden in a word run (no lr saved); callee of ov010 func_02167BFC.
 */
void func_02167B9C(Obj_02167B9C *o)
{
    func_02082D44(o->b32, o->b668, 0x1C);
}






void func_02167BB4(Obj_02167BB4 *o, u16 v)
{
    o->b3 = v;
    o->h668 = v;
}





void func_02167BCC(Obj_02167BCC *o)
{
    o->w668 = o->b09;
}





void func_02167BD8(Obj_02167BD8 *o, u32 v)
{
    o->w668 = v;
}





void func_02167BE4(Obj_02167BE4 *o, u32 v)
{
    o->w668 = v;
}



void func_02167BF0(Obj *o, u32 v)
{
    o->w668 = v;
}
