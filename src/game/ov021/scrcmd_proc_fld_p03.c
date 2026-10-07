/*
 * file:     scrcmd_proc_fld_p03.c
 * unit:     yes
 * function: func_021B385C, func_021B38E0, func_021B39C4, func_021B3A64, func_021B3B04, func_021B3B14, func_021B3B84, func_021B3BD8, func_021B3C58, func_021B3C78, func_021B3CFC
 * address:  0x021B385C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0201EFA4 0x0201EFA4 thumb
 *   func_020212B0 0x020212B0 thumb
 *   func_0201EF34 0x0201EF34 thumb
 *   func_0201F250 0x0201F250 thumb
 *   func_0201F898 0x0201F898 thumb
 *   func_0201F878 0x0201F878 thumb
 *   func_02045B38 0x02045B38 arm
 *   func_02021288 0x02021288 thumb
 *   func_0201F81C 0x0201F81C thumb
 *   func_02020FE4 0x02020FE4 thumb
 *   func_0201102C 0x0201102C thumb
 *   func_021B3834 0x021B3834 thumb ov021
 *   func_02045C04 0x02045C04 arm
 *   d_021D946C 0x021D946C data
 *   d_021D95DE 0x021D95DE data
 *   d_021DE1A8 0x021DE1A8 data
 *   d_021DE164     0x021DE164  data  a4
 *   d_021D9430     0x021D9430  data  a1
 *   func_02186670 0x02186670 thumb ov020
 *   func_0201F868  0x0201F868  thumb
 *   func_0201EC64 0x0201EC64 thumb
 *   func_020457B0 0x020457B0 arm
 *   func_0203101C 0x0203101C arm
 *   func_02045EC0 0x02045EC0 arm
 *   func_02031140 0x02031140 arm
 *   func_0201ED04 0x0201ED04 thumb
 *   func_02045808 0x02045808 arm
 *   func_020490F4 0x020490F4 arm
 *   func_02049B68 0x02049B68 arm
 *   func_02049658 0x02049658 arm
 *   func_02049990 0x02049990 arm
 *   func_02049238 0x02049238 arm
 *   func_0201F5BC 0x0201F5BC thumb
 *   func_020414EC 0x020414EC arm
 *   func_0204047C 0x0204047C arm
 *   func_02193060  0x02193060  thumb  ov021
 *   func_0204AC18 0x0204AC18 arm
 *   func_0204A6C8 0x0204A6C8 arm
 *   func_0204AF28 0x0204AF28 arm
 *   func_02020E60 0x02020E60 thumb
 */
#include "../../matched/include/Obj00037.h"
#include "../../matched/include/Obj12843.h"
#include "../../matched/include/Obj19996.h"
#include "../../matched/include/Obj03599.h"
#include "../../matched/include/Obj06037.h"
#include "../../matched/include/Obj02389.h"

struct WordSet;
struct Slot;
struct MsgBank;
struct Rec;
struct Tcbl;
struct U16Vec;
struct S02031140;
typedef unsigned short u16;

typedef unsigned int   u32;

typedef unsigned char u8;

typedef struct {
    u16 id;
    u16 pad;
    u32 val;
} Entry;

typedef struct {
    u8 _00[4];
    u16 heap;
    u8 _06[0x1a];
    Entry list[40];
    u16 count;
    u8 mode;
    u8 _163[0x1d];
    Entry *buf;
    u8 _184[4];
    u32 win;
} Obj;

typedef signed int     s32;

extern void func_0201EFA4(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);
extern u16 func_020212B0(u16 id);
extern void func_0201EF34(struct WordSet *p, u32 i, u32 v);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern void func_0201F898(struct Slot *table, u32 a, u32 b, u32 tag);
extern void func_0201F878(struct Slot *table, u32 a, u32 b, u32 tag, u32 heap);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern u32 func_02021288(u32 id);
extern void *func_0201F81C(int, int);
extern u32 func_02020FE4(void *a, u32 sel, u32 id);
extern u32 func_0201102C(u32 v);
extern u32 func_021B3834(u8 *p, int n);
extern u32 func_02045C04(struct Rec *rec);
extern void func_02186670(char *base, char *out, u16 *cnt, int n, u16 id);
extern u32 func_0201F868(void *p);
extern struct WordSet *func_0201EC64(u32 heap);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern struct Tcbl *func_0203101C(u16 heap, u16 tag, u32 count, u32 workSize);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void func_02031140(struct S02031140 *p);
extern u32 func_0201ED04(struct WordSet *p);
extern void func_02045808(struct U16Vec *vec);
extern void *func_020490F4(unsigned int id, unsigned int heap);
extern void func_02049B68(void *a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern u32 func_02049658(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern u32 func_02049990(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u16 a7);
extern void func_02049238(void *);
extern void func_0201F5BC(u32 a, u32 b, u32 c, u32 d, u16 e);
extern void func_020414EC(u32 i);
extern void func_0204047C(int idx, unsigned short val);
extern void func_02193060(u32);
extern s32 func_0204AC18(void *a, u32 b, u32 c, u32 d, u16 e, u16 f, u16 g);
extern s32 func_0204A6C8(void *a, u32 b, u32 c, u32 a3, u16 flags);
extern s32 func_0204AF28(void *owner, u32 first, u32 second, u32 mode);
extern unsigned func_02020E60(unsigned a, unsigned b);
void func_021B385C(char *p, int idx, int mode, int val, int arg);
void func_021B38E0(char *p, int a, int b, int c);
void func_021B39C4(Obj *p, int idx);
void func_021B3A64(char *p, int i);
void func_021B3B04(char *w);
int func_021B3B14(char *p, int a);
void func_021B3B84(char *p);
void func_021B3BD8(char *p);
void func_021B3C58(u8 *w);
void func_021B3C78(char *p);
void func_021B3CFC(char *w);
extern u8 d_021D946C[];
extern u8 d_021D95DE[];
extern u16 *d_021DE1A8[];
extern Entry *d_021DE164[];
extern u8 d_021D9430[];


void func_021B385C(char *p, int idx, int mode, int val, int arg)
{
    if (mode == 1) {
        func_0201EFA4(((struct Obj00037 *)p)->f190, 0, val - 327, 2, 2, 1);
        func_0201EF34(((struct Obj00037 *)p)->f190, 1, func_020212B0(val));
        func_0201F250(((struct Obj00037 *)p)->f190, ((struct Obj00037 *)p)->f198, ((struct Obj00037 *)p)->f19C);
        func_0201F898((struct Slot *)(*(char * *)&((struct Obj00037 *)p)->f180 + idx * 8), (u32)(((struct Obj00037 *)p)->f198), idx, ((struct Obj00037 *)p)->f4);
    } else {
        func_0201F878((struct Slot *)(*(char * *)&((struct Obj00037 *)p)->f180 + idx * 8), arg, val, idx, ((struct Obj00037 *)p)->f4);
    }
}


/*
 * Spill slots: the image puts the idx*4 offset at sp+4, q at sp+8, n at sp+0xc.
 * A single-def offset local is folded into a compiler temporary, and temps
 * take slots above every spilled local; the second (redundant) assignment in
 * the flag arm keeps off a real local, and declaration order (n, q, ..., off;
 * last declared lowest) gives the image layout.
 */
void func_021B38E0(char *p, int a, int b, int c)
{
    int n;
    void *q = func_02045B38(0, 2, 54, ((struct Obj00037 *)p)->f4);
    int idx;
    int k;
    int v;
    char *e;
    int off;

    if (a == 0xff) {
        idx = d_021D946C[c];
    } else {
        idx = b + 6;
    }
    off = idx * 4;
    if (func_02021288(**(u16 **)((char *)d_021DE1A8 + off))) {
        ((struct Obj00037 *)p)->f162 = 1;
        off = idx * 4;
    }
    n = d_021D95DE[idx];
    ((struct Obj00037 *)p)->f180 = func_0201F81C(n + 1, ((struct Obj00037 *)p)->f4);
    for (k = 0; k < n; k++) {
        v = (*(u16 **)((char *)d_021DE1A8 + off))[k];
        func_021B385C(p, k, ((struct Obj00037 *)p)->f162, v, (int)q);
        e = p + k * 8;
        ((struct Obj12843 *)e)->f20 = v;
        ((struct Obj12843 *)e)->f24 = func_0201102C(func_02020FE4((void *)v, 0, ((struct Obj00037 *)p)->f4));
    }
    ((struct Obj00037 *)p)->f160 = k;
    func_021B3834((u8 *)(p + 32), ((struct Obj00037 *)p)->f160);
    func_0201F878((struct Slot *)(*(char * *)&((struct Obj00037 *)p)->f180 + k * 8), (u32)(((struct Obj00037 *)p)->f188), 11, -2, ((struct Obj00037 *)p)->f4);
    func_02045C04(q);
}


/*
 * Addresses are Black-image addresses.
 */
void func_021B39C4(Obj *p, int idx)
{
    int i;
    Entry *tbl;
    u32 h;
    int n;

    i = 0;
    h = (u32)func_02045B38(0, 2, 0x36, p->heap);
    tbl = d_021DE164[idx];
    n = d_021D9430[idx];
    p->buf = func_0201F81C(n + 1, p->heap);
    for (; i < n; i++) {
        func_021B385C((char *)p, i, p->mode, tbl[i].id, h);
        p->list[i].id = tbl[i].id;
        p->list[i].val = tbl[i].val;
    }
    p->count = i;
    func_0201F878((struct Slot *)(p->buf + i), p->win, 0xb, -2, p->heap);
    func_02045C04((struct Rec *)h);
}


void func_021B3A64(char *p, int i)
{
    int k = 0;
    void *q = func_02045B38(0, 2, 54, ((struct Obj00037 *)p)->f4);

    func_02186670(((struct Obj00037 *)p)->f1C, p + 32, (u16 *)(p + 352), i - 247, ((struct Obj00037 *)p)->f4);
    ((struct Obj00037 *)p)->f180 = func_0201F81C(((struct Obj00037 *)p)->f160 + 1, ((struct Obj00037 *)p)->f4);
    for (; k < ((struct Obj00037 *)p)->f160; k++) {
        func_021B385C(p, k, ((struct Obj00037 *)p)->f162, *(u16 *)(p + 32 + k * 8), (int)q);
    }
    func_0201F878((struct Slot *)(*(char * *)&((struct Obj00037 *)p)->f180 + k * 8), (u32)(((struct Obj00037 *)p)->f188), 11, -2, ((struct Obj00037 *)p)->f4);
    func_02045C04(q);
}


/*
 * Unlabelled leaf (tail-call stub), called from func_021B35A4.
 *
 * Addresses are Black-image addresses.
 */
void func_021B3B04(char *w)
{
    func_0201F868(((struct Obj19996 *)w)->f180);
}


int func_021B3B14(char *p, int a)
{
    ((struct Obj00037 *)p)->f188 = func_02045B38(0, 3, 423, ((struct Obj00037 *)p)->f4);
    ((struct Obj00037 *)p)->f18C = func_02045B38(0, 2, 53, ((struct Obj00037 *)p)->f4);
    ((struct Obj00037 *)p)->f190 = func_0201EC64(((struct Obj00037 *)p)->f4);
    ((struct Obj00037 *)p)->f198 = func_020457B0(200, ((struct Obj00037 *)p)->f4);
    ((struct Obj00037 *)p)->f1B4 = func_0203101C(((struct Obj00037 *)p)->f4, ((struct Obj00037 *)p)->f4, 32, 32);
    ((struct Obj00037 *)p)->f19C = func_02045EC0(((struct Obj00037 *)p)->f188, 29);
    return a;
}


void func_021B3B84(char *p)
{
    func_02031140(((struct Obj03599 *)p)->f1B4);
    func_0201ED04(((struct Obj03599 *)p)->f190);
    func_02045808(((struct Obj03599 *)p)->f19C);
    func_02045808(((struct Obj03599 *)p)->f198);
    func_02045808(((struct Obj03599 *)p)->f1A0);
    func_02045808(((struct Obj03599 *)p)->f194);
    func_02045C04(((struct Obj03599 *)p)->f188);
    func_02045C04(((struct Obj03599 *)p)->f18C);
}


void func_021B3BD8(char *p)
{
    void *q;

    *(volatile u16 *)0x04000050 = 0;
    q = func_020490F4(54, ((struct Obj06037 *)p)->f4);
    func_02049B68(q, 1, 0, 0, 96, ((struct Obj06037 *)p)->f4);
    func_02049658(q, 0, 2, 100, 0, 0, ((struct Obj06037 *)p)->f4);
    func_02049990(q, 2, 2, 0, 100, 0, 0, ((struct Obj06037 *)p)->f4);
    func_02049238(q);
    func_0201F5BC(1, 228, 9, 0, ((struct Obj06037 *)p)->f4);
    func_020414EC(1);
    func_0204047C(2, 1);
}


void func_021B3C58(u8 *w)
{
    func_020414EC(1);
    func_020414EC(2);
    func_0204047C(2, 0);
    func_02193060(1);
}


void func_021B3C78(char *p)
{
    void *q = func_020490F4(54, ((struct Obj02389 *)p)->f4);

    ((struct Obj02389 *)p)->f1D4 = (void *)func_0204AC18(q, 10, 0, 0, 0, 1, ((struct Obj02389 *)p)->f4);
    ((struct Obj02389 *)p)->f1D8 = (void *)func_0204A6C8(q, 7, 0, 0, ((struct Obj02389 *)p)->f4);
    ((struct Obj02389 *)p)->f1E4 = (void *)func_0204A6C8(q, 4, 0, 0, ((struct Obj02389 *)p)->f4);
    ((struct Obj02389 *)p)->f1DC = (void *)func_0204AF28(q, 8, 9, ((struct Obj02389 *)p)->f4);
    ((struct Obj02389 *)p)->f1E8 = (void *)func_0204AF28(q, 5, 6, ((struct Obj02389 *)p)->f4);
    func_02049238(q);
}


void func_021B3CFC(char *w)
{
    ((struct Obj00037 *)w)->f1EC = (void *)func_0204AC18(((struct Obj00037 *)w)->f1F8, func_02020E60(1, 2), 0, 0x20, 0, 1, ((struct Obj00037 *)w)->f4);
    ((struct Obj00037 *)w)->f1F0 = (void *)func_0204A6C8(((struct Obj00037 *)w)->f1F8, func_02020E60(1, 1), 0, 0, ((struct Obj00037 *)w)->f4);
    ((struct Obj00037 *)w)->f1F4 = (void *)func_0204AF28(((struct Obj00037 *)w)->f1F8, 1, 0, ((struct Obj00037 *)w)->f4);
}
