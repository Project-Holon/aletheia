/*
 * file:     fld3d_ci_p07.c
 * unit:     yes
 * function: func_021C2764, func_021C2784, func_021C27A4, func_021C27C0, func_021C27CC, func_021C27E8, func_021C27F4, func_021C2854, func_021C2918, func_021C2B1C
 * address:  0x021C2764
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
 *   func_02043658  0x02043658  arm
 *   func_02043534  0x02043534  arm
 *   func_020124F0  0x020124F0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   func_020124E4  0x020124E4  thumb
 *   func_0201210C  0x0201210C  thumb
 *   func_020437AC  0x020437AC  arm
 *   func_020307B0  0x020307B0  arm
 *   func_02006CAC  0x02006CAC  thumb
 *   func_02006984  0x02006984  thumb
 *   func_02006650  0x02006650  thumb
 *   func_02006B20  0x02006B20  thumb
 *   func_02006A8C  0x02006A8C  thumb
 *   func_020065D8  0x020065D8  thumb
 *   func_02043678  0x02043678  arm
 *   func_02048A0C  0x02048A0C  arm
 *   func_02047388  0x02047388  arm
 *   func_020473B8  0x020473B8  arm
 *   func_0202D060  0x0202D060  thumb
 *   func_0202D064  0x0202D064  thumb
 *   func_0202D0D4  0x0202D0D4  thumb
 *   func_02049E34  0x02049E34  arm
 *   func_02049F34  0x02049F34  arm
 *   func_020437D4  0x020437D4  arm
 *   func_02082A7C  0x02082A7C  arm
 *   func_02082A90  0x02082A90  arm
 *   func_02044F64  0x02044F64  arm
 *   func_02061CA4  0x02061CA4  arm
 *   func_02030830  0x02030830  arm
 *   func_0204E720  0x0204E720  arm
 *   func_0204E804  0x0204E804  arm
 */
#include "../../matched/include/Obj20169.h"
#include "../../matched/include/Obj20172.h"
#include "../../matched/include/Obj20174.h"
#include "../../matched/include/Obj01215.h"
#include "../../matched/include/Obj01214.h"
#include "../../matched/include/Obj09680.h"

struct Node;
struct Obj;
struct Obj020437AC;
struct Ctx;
struct Bmp;
struct Layer;
typedef unsigned char u8;

typedef unsigned int u32;

typedef unsigned short u16;

typedef signed char    s8;

typedef struct CharData {
    u8 pad00[0x14];
    u8 *raw;
} CharData;

typedef struct PlttData {
    u8 pad00[0xc];
    void *raw;
} PlttData;

typedef struct Obj {
    u8 pad00[0x10];
    u16 heap;
    u16 pad12;
    void *f14;
    u8 pad18[0x88 - 0x18];
    CharData *chr;
    PlttData *pltt;
    void *canvas;
    void *chrRes;
    void *plttRes;
    u32 args[5];
} Obj;

typedef signed int     s32;

extern void func_0208068C(u32 a);
extern void *func_020056A0(void *callback, void *ctx, int a2);
extern void func_02030EAC(struct Node *n);
extern u8 func_020416D4(u32 layer);
u32 func_02043658(void);
extern void func_0204047C(int idx, unsigned short val);
extern void func_02043534(u32 a);
void *func_020124F0(struct Obj *p);
void *func_020124E8(struct Obj *p);
void *func_020124E4(struct Obj *p);
void *func_0201210C(const struct Ctx *p);
void func_020437AC(struct Obj020437AC *p);
u32 func_020307B0(void *p);
void func_02006CAC(void **out);
unsigned int func_02006984(unsigned int a0, unsigned int a1, unsigned int a2, unsigned int a3, unsigned int a4, unsigned int a5, unsigned int a6, unsigned int a7);
int func_02006650(void);
s8 func_02006B20(u32 i);
void func_02006A8C(u32 idx, int delta);
void func_020065D8(void);
extern struct Bmp *func_02043678(u32 width, u32 height, u32 depth, u16 heap);
extern u32 func_02048A0C(u8 *a0, int i);
extern u32 func_02047388(struct Layer *layer);
extern u32 func_020473B8(struct Layer *layer);
extern int func_0202D060(void);
extern s32 func_0202D064(u32 a0, u32 a1, u32 a2, u32 a3, u32 s5, u32 s6, u32 s7);
extern s32 func_0202D0D4(u32 a0, u32 a1, u32 a2, u32 a3, u32 s5, u32 s6, u32 s7);
extern void *func_02049E34(u32 a0, u32 a1, u32 a2, u32 a3, u16 a4);
extern void *func_02049F34(u32 a0, u32 a1, u32 a2, u32 a3);
extern void *func_020437D4(const struct Bmp *bmp);
extern void func_02082A7C(u32 fill, void *dst, u32 size);
extern void func_02082A90(const void *src, void *dst, u32 size);
extern struct Bmp *func_02044F64(struct Bmp *src, u32 keep, u16 heap);
extern s32 func_02061CA4(void *p, u32 a, u32 b, s32 size);
extern void *func_02030830(u32 heapId);
void func_0204E720(u32 a, s32 b, s32 c, s32 d);
int func_0204E804(void);
void func_021C2764(u8 *p);
void func_021C2784(void *p, u32 *done);
void func_021C27A4(u8 *p);
void func_021C27C0(char *p);
void func_021C27CC(u8 *p);
void func_021C27E8(u8 *p);
int func_021C27F4(int a, int *b);
int func_021C2854(int a, char *b);
void func_021C2918(Obj *p);
int func_021C2B1C(int a, int *b);


/*
 * Clears the task slot and starts the func_021C2784 task.
 */
void func_021C2764(u8 *p)
{
    ((struct Obj20169 *)p)->f70 = 0;
    func_0208068C(8);
    func_020056A0(func_021C2784, p + 0x70, 0);
}


/*
 * VBlank task: arms display capture, ends itself, flags completion.
 */
void func_021C2784(void *p, u32 *done)
{
    *(volatile u32 *)0x04000064 = 0x81330010;
    func_02030EAC(p);
    if (done != 0)
        *done = 1;
}


/*
 * Saves the four layer priorities into p[0x6C..0x6F].
 */
void func_021C27A4(u8 *p)
{
    int i;

    for (i = 0; i < 4; i++)
        p[0x6C + i] = func_020416D4((u8)i);
}


void func_021C27C0(char *p)
{
    ((struct Obj20172 *)p)->f68 = func_02043658();
}


/*
 * Restores the four saved layer priorities (EXACT*: unlabelled follower).
 */
void func_021C27CC(u8 *p)
{
    int i;

    for (i = 0; i < 4; i++)
        func_0204047C((u8)i, p[0x6C + i]);
}


void func_021C27E8(u8 *p)
{
    func_02043534(((struct Obj20174 *)p)->f68);
}


int func_021C27F4(int a, int *b)
{
    char *p;

    p = *(char **)func_020124E8(func_020124F0((struct Obj *)a));
    func_0201210C(func_020124E4((struct Obj *)a));
    switch (*b) {
    case 0:
        func_021C2918((struct Obj *)((int)p));
        (*b)++;
        break;
    case 1:
        func_020437AC((struct Obj020437AC *)(*(int *)&((struct Obj01215 *)p)->f90));
        func_020307B0((void *)(*(int *)&((struct Obj01215 *)p)->f94));
        func_020307B0((void *)(*(int *)&((struct Obj01215 *)p)->f98));
        (*b)++;
        break;
    case 2:
        return 1;
    }
    return 0;
}


int func_021C2854(int a, char *b)
{
    int r;
    char *q;
    char buf[4];

    q = b + 0x9c;
    if (((struct Obj01214 *)q)->f14 != 0 && ((struct Obj01214 *)q)->f18 != 0) {
        (((struct Obj01214 *)q)->f18)--;
        if (((struct Obj01214 *)q)->f18 == 0) {
            if (((struct Obj01214 *)q)->f0 == 0x1b9) {
                func_02006CAC((void **)buf);
                ((struct Obj01214 *)q)->f1C = func_02006984(((struct Obj01214 *)q)->f0, ((struct Obj01214 *)q)->f4, 0x40, 0, 0, 0, 0, (unsigned int)buf);
            } else {
                ((struct Obj01214 *)q)->f1C = func_02006984(((struct Obj01214 *)q)->f0, ((struct Obj01214 *)q)->f4, 0x40, 0, 0, 0, 0, 0);
            }
        }
        ((struct Obj01214 *)q)->f1A = 0x1e;
        return 0;
    }
    r = 0;
    if (((struct Obj01214 *)q)->f18 == 0) {
        if (func_02006650() == 0) {
            r = 1;
        } else if (((struct Obj01214 *)q)->f1A != 0) {
            (((struct Obj01214 *)q)->f1A)--;
        } else if (func_02006B20(((struct Obj01214 *)q)->f1C) > 0) {
            func_02006A8C(((struct Obj01214 *)q)->f1C, r - 16);
        } else {
            func_020065D8();
            r = 1;
        }
    }
    if (((struct Obj09680 *)b)->f11C != 0 && ((struct Obj09680 *)b)->f120 != 0 && ((struct Obj09680 *)b)->f124 != 0 && r != 0)
        return 1;
    return 0;
}


/*
 * Twin of ov195 func_0220685C (same tile-copy body). The far argument block
 * at +0x9C needs a local pointer (`a = p->args`), and the two size calls
 * must land in int locals before the (u16) << 3 conversions.
 */
void func_021C2918(Obj *p)
{
    u16 heap;
    u8 *buf;
    int j;
    u32 tex;
    u32 pltt;
    u8 *src;
    u32 chrFile;
    u32 plttFile;
    void *h;
    u32 *a;
    int t1;
    int t2;
    int i;
    int k;

    heap = p->heap;
    p->canvas = func_02043678(16, 16, 32, heap);
    k = 0;
    h = (void *)func_02048A0C(p->f14, 0);
    t1 = func_02047388(h);
    t2 = func_020473B8(h);
    tex = (u16)t1 << 3;
    pltt = (u16)t2 << 3;
    a = p->args;
    chrFile = func_0202D064(func_0202D060(), a[0], a[1], a[2], a[3], 0, a[4]);
    plttFile = func_0202D0D4(func_0202D060(), a[0], a[1], a[2], a[3], 0, a[4]);
    p->chr = 0;
    p->pltt = 0;
    p->chrRes = func_02049E34(func_0202D060(), chrFile, 1, (u32)(&p->chr), heap);
    p->plttRes = func_02049F34(func_0202D060(), plttFile, (u32)(&p->pltt), heap);
    src = p->chr->raw;
    buf = func_020437D4(p->canvas);
    func_02082A7C(0, buf, 0x2000);
    for (j = 0; j < 8; j++) {
        for (i = 0; i < 8; i++) {
            func_02082A90(src + k * 32, buf + 0x440 + (i + j * 16) * 32, 32);
            k++;
        }
    }
    for (j = 0; j < 8; j++) {
        for (i = 8; i < 12; i++) {
            func_02082A90(src + k * 32, buf + 0x440 + (i + j * 16) * 32, 32);
            k++;
        }
    }
    for (j = 8; j < 12; j++) {
        for (i = 0; i < 8; i++) {
            func_02082A90(src + k * 32, buf + 0x440 + (i + j * 16) * 32, 32);
            k++;
        }
    }
    for (j = 8; j < 12; j++) {
        for (i = 8; i < 12; i++) {
            func_02082A90(src + k * 32, buf + 0x440 + (i + j * 16) * 32, 32);
            k++;
        }
    }
    func_02044F64(p->canvas, 0, heap);
    func_02061CA4(0, tex, (u32)func_020437D4(p->canvas), 0x2000);
    func_02061CA4((void *)1, pltt, (u32)p->pltt->raw, 0x20);
    func_02030830(p->heap);
}


int func_021C2B1C(int a, int *b)
{
    func_0201210C(func_020124E4((struct Obj *)a));
    switch (*b) {
    case 0:
        func_0204E720(4, 0, 0x10, -1);
        (*b)++;
        break;
    case 1:
        if (func_0204E804() == 0)
            return 1;
        break;
    }
    return 0;
}
