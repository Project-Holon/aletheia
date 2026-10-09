/*
 * file:     fld3d_ci_p03.c
 * unit:     yes
 * function: func_021C21B4, func_021C223C, func_021C22AC, func_021C2320, func_021C2484, func_021C24A8, func_021C24BC, func_021C24F0, func_021C2734, func_021C2764, func_021C2784, func_021C27A4, func_021C27C0, func_021C27CC, func_021C27E8, func_021C27F4, func_021C2854, func_021C2918, func_021C2B1C, func_021C2B5C, func_021C2B98, func_021C2BD4, func_021C2BE4
 * address:  0x021C21B4
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
 *   func_021C1AB4  0x021C1AB4  thumb  ov021
 *   func_020489F4  0x020489F4  arm
 *   func_02048A18  0x02048A18  arm
 *   func_0204779C  0x0204779C  arm
 *   func_020478B8  0x020478B8  arm
 *   func_021C1A48  0x021C1A48  thumb  ov021
 *   func_021C1C24  0x021C1C24  thumb  ov021
 *   func_021C1A98  0x021C1A98  thumb  ov021
 *   func_021C1AA8  0x021C1AA8  thumb  ov021
 *   func_02048A00  0x02048A00  arm
 *   func_020477A4  0x020477A4  arm
 *   func_02051B04  0x02051B04  arm
 *   func_020124E4  0x020124E4  thumb
 *   func_020122C0  0x020122C0  thumb
 *   func_02012374  0x02012374  thumb
 *   func_020480E4  0x020480E4  arm
 *   func_021C1A84  0x021C1A84  thumb  ov021
 *   func_020515CC  0x020515CC  arm
 *   func_02048F4C  0x02048F4C  arm
 *   func_02030734  0x02030734  arm
 *   d_021DE3D8     0x021DE3D8  data  a4
 *   func_02043658  0x02043658  arm
 *   func_02043534  0x02043534  arm
 *   func_020124F0  0x020124F0  thumb
 *   func_020124E8  0x020124E8  thumb
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
 *   func_02046F48  0x02046F48  arm
 *   func_0206E964  0x0206E964  arm
 *   func_021C2EDC  0x021C2EDC  thumb  ov021
 *   func_021C2F14  0x021C2F14  thumb  ov021
 *   func_02049DB4  0x02049DB4  arm
 */
#include "../../matched/include/Obj01864.h"
#include "../../matched/include/Obj05076.h"
#include "../../matched/include/Obj05077.h"
#include "../../matched/include/Obj00456.h"
#include "../../matched/include/Obj00616.h"
#include "../../matched/include/Obj07228.h"
#include "../../matched/include/Obj20162.h"
#include "../../matched/include/Obj20169.h"
#include "../../matched/include/Obj20172.h"
#include "../../matched/include/Obj20174.h"
#include "../../matched/include/Obj01215.h"
#include "../../matched/include/Obj01214.h"
#include "../../matched/include/Obj09680.h"

struct Desc;
struct G3dSys;
struct Evt;
struct Obj;
struct Ctx;
struct Node;
struct Obj_021C2764;
struct Obj020437AC;
struct Bmp;
struct Layer;
struct Tagged;
typedef unsigned short u16;

typedef unsigned int   u32;

typedef unsigned char u8;

typedef signed short   s16;

typedef signed char    s8;

typedef struct {
    int x;
    int y;
    int z;
} Vec;

typedef struct {
    int f0;
    Vec v;
} Inner;

typedef struct {
    char pad0[0x20];
    Inner **f20;
    int f24;
    Vec f28;
} Obj_021C2484;

typedef struct {
    u32 w0;
    u16 h4;
    u16 h6;
    u16 a[2];
    u16 hc;
    u16 he;
    u16 b[4];
    u16 c[4];
    u32 w20;
} Src;

typedef struct {
    u32 kind;
    u16 id;
    u32 val;
} E0;

typedef struct {
    u16 idx;
    u16 zero;
} E2;

typedef struct {
    u16 idx;
    u16 zero;
    u16 idx2;
    E2 *list;
    u16 cnt;
} E1;

typedef struct {
    E0 *e0;
    E1 *e1;
    E2 *e2;
    E2 *e3;
    E0 *p10;
    u16 n10;
    E1 *p18;
    u16 n1c;
    u16 pad1e;
    u16 h20;
    u16 h22;
    u16 h24;
    u16 h26;
    u32 w28;
    u8 total;
    u8 na;
    u8 nb;
    u8 nc;
    u32 w30;
} Out;

typedef struct CharData {
    u8 pad00[0x14];
    u8 *raw;
} CharData;

typedef struct PlttData {
    u8 pad00[0xc];
    void *raw;
} PlttData;

typedef struct Obj_021C2764 {
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
} Obj_021C2764;

typedef signed int     s32;

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
} Obj;

int func_021C1AB4(u32 *p);
unsigned int func_020489F4(u8 *a0, int i);
u32 func_02048A18(u8 *a0, int i);
int func_0204779C(int *p);
int func_020478B8(void *a, int idx, int amount);
int func_021C1A48(int a);
int func_021C1C24(char *p, char *q);
void *func_021C1A98(u16 *p, int a, int b);
int func_021C1AA8(u32 a, u32 b, u32 c, u32 d);
u32 func_02048A00(u8 *a0, int i);
u32 func_020477A4(struct G3dSys *sys, u32 idx);
u16 func_02051B04(void *res);
void *func_020124E4(struct Obj *p);
struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
void func_02012374(struct Evt *evt, struct Evt **out);
extern void func_020480E4(struct Ctx *c, u32 i);
extern u32 func_021C1A84(u32);
int func_020515CC(int *p, int a, int b, int c);
extern void func_02048F4C(void *dst, u32 archive_id, u32 member);
extern void *func_02030734(u32, u32, int, const char *, u16);
extern u32 func_020307B0(void *p);
extern void func_0208068C(u32 a);
extern void *func_020056A0(void *callback, void *ctx, int a2);
extern void func_02030EAC(struct Node *n);
extern u8 func_020416D4(u32 layer);
u32 func_02043658(void);
extern void func_0204047C(int idx, unsigned short val);
extern void func_02043534(u32 a);
void *func_020124F0(struct Obj_021C2764 *p);
void *func_020124E8(struct Obj_021C2764 *p);
void *func_0201210C(const struct Ctx *p);
void func_020437AC(struct Obj020437AC *p);
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
extern void *func_02046F48(struct Tagged *p);
extern unsigned char *func_0206E964(unsigned char *p);
extern int func_021C2EDC(u8 *p, const char *name);
extern int func_021C2F14(u8 *p, const char *name);
extern void *func_02049DB4(u32 a0, u32 a1, u32 a2, u32 a3, u16 a4);
int func_021C21B4(char *p);
int func_021C223C(char *p);
int func_021C22AC(char *p);
void func_021C2320(void *a, char *p, char *q, int d);
int func_021C2484(u8 *a, u8 *b);
void func_021C24A8(char *p, int k);
void func_021C24BC(Obj_021C2484 *p);
void func_021C24F0(Out *out, u32 b, u32 heap);
void func_021C2734(void **p);
void func_021C2764(u8 *p);
void func_021C2784(void *p, u32 *done);
void func_021C27A4(u8 *p);
void func_021C27C0(char *p);
void func_021C27CC(u8 *p);
void func_021C27E8(u8 *p);
int func_021C27F4(int a, int *b);
int func_021C2854(int a, char *b);
void func_021C2918(Obj_021C2764 *p);
int func_021C2B1C(int a, int *b);
int func_021C2B5C(void *t, int *st);
int func_021C2B98(void *a, u32 *p);
int func_021C2BD4(u16 id);
void func_021C2BE4(Obj *p, u32 a1, u32 a2, u32 chrFile, u32 plttFile);
extern u8 d_021DE3D8;



int func_021C21B4(char *p)
{
    if (((struct Obj01864 *)p)->f64 == 0) {
        if (((struct Obj01864 *)p)->f78 == 0) {
            if (((struct Obj01864 *)p)->f5C != 0) {
                (((struct Obj01864 *)p)->f5C)--;
            } else {
                func_021C24A8(p, 0);
                ((struct Obj01864 *)p)->f78 = 1;
            }
        }
        if (((struct Obj01864 *)p)->f7C == 0) {
            if (((struct Obj01864 *)p)->f5E != 0) {
                (((struct Obj01864 *)p)->f5E)--;
            } else {
                func_021C24A8(p, 1);
                ((struct Obj01864 *)p)->f7C = 1;
            }
        }
        if (((struct Obj01864 *)p)->f78 != 0 && ((struct Obj01864 *)p)->f7C != 0)
            ((struct Obj01864 *)p)->f64 = 1;
    } else if (func_021C1AB4((u32 *)(((struct Obj01864 *)p)->f0)) != 0) {
        return 1;
    }
    return 0;
}



int func_021C223C(char *p)
{
    int a;
    u8 k;
    int r;
    int n;

    if (((struct Obj05076 *)p)->f80 == 0)
        return 1;
    if (((struct Obj05076 *)p)->f60 != 0) {
        (((struct Obj05076 *)p)->f60)--;
    } else {
        a = func_02048A18((u8 *)(((struct Obj05076 *)p)->f14), (int)func_020489F4((u8 *)(((struct Obj05076 *)p)->f14), (u16)(((struct Obj05076 *)p)->f18)));
        n = func_0204779C((int *)a);
        for (k = 0; k < n; k++)
            r = func_020478B8((void *)a, k, 0x1000);
        if (r == 0)
            return 1;
    }
    return 0;
}



int func_021C22AC(char *p)
{
    int a;
    u8 k;
    int r;
    int n;

    if (((struct Obj05077 *)p)->f84 == 0)
        return 1;
    if (((struct Obj05077 *)p)->f62 != 0) {
        (((struct Obj05077 *)p)->f62)--;
    } else {
        a = (int)func_02048A18((u8 *)(((struct Obj05077 *)p)->f14), (u16)((int)func_020489F4((u8 *)(((struct Obj05077 *)p)->f14), (u16)(((struct Obj05077 *)p)->f18)) + 1));
        n = func_0204779C((int *)a);
        for (k = 0; k < n; k++)
            r = func_020478B8((void *)a, k, 0x1000);
        if (r == 0)
            return 1;
    }
    return 0;
}



void func_021C2320(void *a, char *p, char *q, int d)
{
    int t;
    u8 i;
    int base;
    int cnt;
    u8 k;
    int h;
    int n;
    int r;

    ((struct Obj00616 *)p)->f58 = func_021C1A48(((struct Obj00616 *)p)->f0);
    func_021C24F0((Out *)q, d, ((struct Obj00616 *)p)->f10);
    func_021C1C24(p, q + 0x10);
    if (((struct Obj00456 *)q)->f28 != 0xFFFF) {
        t = (int)func_021C1A98((u16 *)(((struct Obj00616 *)p)->f0), 0x73, ((struct Obj00456 *)q)->f28);
        func_021C1AA8(((struct Obj00616 *)p)->f0, t, 1, 0);
    } else {
        t = 0;
    }
    base = (int)func_020489F4((u8 *)(((struct Obj00616 *)p)->f14), (u16)(((struct Obj00616 *)p)->f18));
    cnt = (int)func_02048A00((u8 *)(((struct Obj00616 *)p)->f14), (u16)(((struct Obj00616 *)p)->f18));
    for (i = 0; i < cnt; i++) {
        h = (int)func_02048A18((u8 *)(((struct Obj00616 *)p)->f14), (u16)(base + i));
        n = func_0204779C((int *)h);
        for (k = 0; k < n; k++)
            func_020477A4((struct G3dSys *)h, (u8)k);
    }
    ((struct Obj00616 *)p)->f5C = ((struct Obj00456 *)q)->f20;
    ((struct Obj00616 *)p)->f5E = ((struct Obj00456 *)q)->f22;
    ((struct Obj00616 *)p)->f60 = ((struct Obj00456 *)q)->f24;
    ((struct Obj00616 *)p)->f62 = ((struct Obj00456 *)q)->f26;
    if (t != 0)
        r = func_02051B04((void *)t);
    else
        r = 0;
    if (r == 2) {
        ((struct Obj00616 *)p)->f78 = 0;
        ((struct Obj00616 *)p)->f7C = 0;
    } else if (r == 1) {
        ((struct Obj00616 *)p)->f78 = 0;
        ((struct Obj00616 *)p)->f7C = 1;
    } else {
        ((struct Obj00616 *)p)->f78 = 1;
        ((struct Obj00616 *)p)->f7C = 1;
    }
    ((struct Obj00616 *)p)->f80 = 0;
    ((struct Obj00616 *)p)->f84 = 0;
    if (((struct Obj00456 *)q)->f2E != 0)
        ((struct Obj00616 *)p)->f80 = 1;
    if (((struct Obj00456 *)q)->f2F != 0)
        ((struct Obj00616 *)p)->f84 = 1;
    if (((struct Obj00616 *)p)->f128 != 0) {
        h = (int)func_020124E4((struct Obj *)a);
        func_02012374((struct Evt *)a, (struct Evt **)func_020122C0((void *)h, a, (void *)(((struct Obj00616 *)p)->f128), (int)0));
    }
}





/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_021C2484(u8 *a, u8 *b)
{
func_021C2734((void **)b);
func_020480E4((struct Ctx *)(((struct Obj07228 *)((u8 *)(a)))->f14), ((((struct Obj07228 *)((u8 *)(a)))->f18 << 16) >> 16));
((struct Obj07228 *)((u8 *)(a)))->f18 = (~0);
return func_021C1A84(((struct Obj07228 *)((u8 *)(a)))->f0);
}





/*
 * EXACT*: the 72-byte listing extent runs on into the unlabelled leaf
 * func_021C24BC (ov021_func_021C24BC.c), whose EXACT entry attests the
 * pool word 0x021C24BD as matched.
 */
void func_021C24A8(char *p, int k)
{
    func_020515CC((int *)(((struct Obj20162 *)p)->f58), k, (int)func_021C24BC, 0);
}





/*
 * Unlabelled thumb leaf (push {r4} only), reached through the pool word
 * 0x021C24BD in func_021C24A8. Char-pointer offsets give the same bytes
 * scheduled differently (34 differ); the struct-typed accesses keep the
 * zero-initialiser stores ahead of the loads, as in the original.
 * Addresses are Black-image addresses.
 */
void func_021C24BC(Obj_021C2484 *p)
{
    Vec o = { 0, 0, 0 };

    o.z = 0x40;
    p->f28.x = o.x + (*p->f20)->v.x;
    p->f28.y = o.y + (*p->f20)->v.y;
    p->f28.z = o.z + (*p->f20)->v.z;
}





void func_021C24F0(Out *out, u32 b, u32 heap)
{
    Src s;
    u16 ids[8];
    u8 na, nb, nc, total, baseb, basec;
    u8 i, j, n;

    func_02048F4C(&s, 0x75, b);
    na = 0;
    for (i = 0; i < 2; i++) {
        if (s.a[i] != 0xFFFF) {
            na++;
        }
    }
    nc = 0;
    nb = 0;
    for (i = 0; i < 4; i++) {
        if (s.b[i] != 0xFFFF) {
            nb++;
        }
    }
    for (i = 0; i < 4; i++) {
        if (s.c[i] != 0xFFFF) {
            nc++;
        }
    }
    baseb = 0 + na;
    basec = baseb + nb;
    total = na + nb + nc;
    if (total != 0) {
        out->e0 = func_02030734(heap, total * 12, 1, (const char *)&d_021DE3D8, 0x566);
    }
    if (na != 0) {
        out->e1 = func_02030734(heap, na * 16, 1, (const char *)&d_021DE3D8, 0x56a);
    }
    if (nb != 0) {
        out->e2 = func_02030734(heap, nb * 4, 1, (const char *)&d_021DE3D8, 0x56e);
    }
    if (nc != 0) {
        out->e3 = func_02030734(heap, nc * 4, 1, (const char *)&d_021DE3D8, 0x572);
    }
    out->total = total;
    out->na = na;
    out->nb = nb;
    out->nc = nc;
    out->h20 = s.h4;
    out->h22 = s.h6;
    out->h24 = s.hc;
    out->h26 = s.he;
    ids[0] = s.a[0];
    ids[1] = s.a[1];
    ids[2] = s.b[0];
    ids[3] = s.b[1];
    ids[4] = s.b[2];
    ids[5] = s.c[0];
    ids[6] = s.c[1];
    ids[7] = s.c[2];
    n = 0;
    for (j = 0; j < 8; j++) {
        if (ids[j] != 0xFFFF) {
            out->e0[n].kind = 0x73;
            out->e0[n].id = ids[j];
            out->e0[n].val = 0;
            n++;
        }
    }
    for (i = 0; i < nb; i++) {
        out->e2[i].idx = baseb + i;
        out->e2[i].zero = 0;
    }
    for (i = 0; i < nc; i++) {
        out->e3[i].idx = basec + i;
        out->e3[i].zero = 0;
    }
    for (i = 0; i < na; i++) {
        out->e1[i].idx = 0 + i;
        out->e1[i].zero = 0;
        out->e1[i].idx2 = 0 + i;
    }
    if (na >= 1) {
        out->e1[0].list = out->e2;
        out->e1[0].cnt = nb;
    }
    if (na >= 2) {
        out->e1[1].list = out->e3;
        out->e1[1].cnt = nc;
    }
    out->p10 = out->e0;
    out->n10 = total;
    out->n1c = na;
    out->p18 = out->e1;
    out->w28 = s.w0;
    out->w30 = s.w20;
}





/*
 * Frees the four optional buffers (EXACT*: trailing pad).
 */
void func_021C2734(void **p)
{
    if (p[2] != 0)
        func_020307B0(p[2]);
    if (p[3] != 0)
        func_020307B0(p[3]);
    if (p[1] != 0)
        func_020307B0(p[1]);
    if (p[0] != 0)
        func_020307B0(p[0]);
}





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

    p = *(char **)func_020124E8(func_020124F0((struct Obj_021C2764 *)a));
    func_0201210C(func_020124E4((struct Obj *)((struct Obj_021C2764 *)a)));
    switch (*b) {
    case 0:
        func_021C2918((struct Obj_021C2764 *)((int)p));
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
void func_021C2918(Obj_021C2764 *p)
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
    func_0201210C(func_020124E4((struct Obj *)((struct Obj_021C2764 *)a)));
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




/*
 * Fade-out state step: start the fade, then wait for it to finish.
 */
int func_021C2B5C(void *t, int *st)
{
    func_0201210C(func_020124E4((struct Obj *)t));
    switch (*st) {
    case 0:
        func_0204E720(4, 0x10, 0, -1);
        (*st)++;
        break;
    case 1:
        if (func_0204E804() == 0)
            return 1;
        break;
    }
    return 0;
}




/*
 * Addresses are Black-image addresses.
 */
int func_021C2B98(void *a, u32 *p)
{
    func_0201210C(func_020124E4((struct Obj *)a));
    switch (p[0]) {
    case 0:
        func_0204E720(3, 0x10, 0, 0);
        p[0]++;
        break;
    case 1:
        if (func_0204E804() == 0)
            return 1;
        break;
    }
    return 0;
}




/*
 * Unlabelled leaf: true for the two ids 0xC and 0x13.
 * Addresses are Black-image addresses.
 */
int func_021C2BD4(u16 id)
{
    if (id == 0xc || id == 0x13)
        return 1;
    return 0;
}




/*
 * Sibling of func_021C2918 (same object layout at +0x88..+0x98), 16x16
 * tile copy with archive 0xB4 and file ids passed in.
 */
void func_021C2BE4(Obj *p, u32 a1, u32 a2, u32 chrFile, u32 plttFile)
{
    u32 tex;
    u32 pltt;
    u16 heap;
    u8 *buf;
    int j;
    void *h;
    void *t;
    u8 *src;
    int i;
    int k;

    heap = p->heap;
    k = 0;
    h = (void *)func_02048A0C(p->f14, 0);
    func_02047388(h);
    func_020473B8(h);
    t = func_0206E964(func_02046F48(h));
    tex = func_021C2EDC(t, (const char *)a1);
    pltt = func_021C2F14(t, (const char *)a2);
    p->chr = 0;
    p->pltt = 0;
    p->chrRes = func_02049DB4(0xb4, chrFile, 1, (u32)(&p->chr), heap);
    p->plttRes = func_02049F34(0xb4, plttFile, (u32)(&p->pltt), heap);
    src = p->chr->raw;
    buf = func_020437D4(p->canvas);
    func_02082A7C(0, buf, 0x2000);
    for (j = 0; j < 16; j++) {
        for (i = 0; i < 16; i++) {
            func_02082A90(src + k * 32, buf + (i + j * 16) * 32, 32);
            k++;
        }
    }
    func_02044F64(p->canvas, 0, heap);
    func_02061CA4(0, tex, (u32)func_020437D4(p->canvas), 0x2000);
    func_02061CA4((void *)1, pltt, (u32)p->pltt->raw, 0x20);
    func_02030830(p->heap);
}
