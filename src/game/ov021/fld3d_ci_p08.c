/*
 * file:     fld3d_ci_p08.c
 * unit:     yes
 * function: func_021C2B5C, func_021C2B98, func_021C2BD4, func_021C2BE4
 * address:  0x021C2B5C
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
 *   func_020124E4  0x020124E4  thumb
 *   func_0201210C  0x0201210C  thumb
 *   func_0204E720  0x0204E720  arm
 *   func_0204E804  0x0204E804  arm
 *   func_02048A0C  0x02048A0C  arm
 *   func_02047388  0x02047388  arm
 *   func_020473B8  0x020473B8  arm
 *   func_02046F48  0x02046F48  arm
 *   func_0206E964  0x0206E964  arm
 *   func_021C2EDC  0x021C2EDC  thumb  ov021
 *   func_021C2F14  0x021C2F14  thumb  ov021
 *   func_02049DB4  0x02049DB4  arm
 *   func_02049F34  0x02049F34  arm
 *   func_020437D4  0x020437D4  arm
 *   func_02082A7C  0x02082A7C  arm
 *   func_02082A90  0x02082A90  arm
 *   func_02044F64  0x02044F64  arm
 *   func_02061CA4  0x02061CA4  arm
 *   func_02030830  0x02030830  arm
 */
struct Obj;
struct Ctx;
struct Bmp;
struct Layer;
struct Tagged;
typedef unsigned int u32;

typedef signed int     s32;

typedef unsigned short u16;

typedef unsigned char u8;

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
} Obj;

extern void *func_020124E4(struct Obj *p);
extern void *func_0201210C(const struct Ctx *p);
extern void func_0204E720(u32 a, s32 b, s32 c, s32 d);
extern int func_0204E804(void);
extern u32 func_02048A0C(u8 *a0, int i);
extern u32 func_02047388(struct Layer *layer);
extern u32 func_020473B8(struct Layer *layer);
extern void *func_02046F48(struct Tagged *p);
extern unsigned char *func_0206E964(unsigned char *p);
extern int func_021C2EDC(u8 *p, const char *name);
extern int func_021C2F14(u8 *p, const char *name);
extern void *func_02049DB4(u32 a0, u32 a1, u32 a2, u32 a3, u16 a4);
extern void *func_02049F34(u32 a0, u32 a1, u32 a2, u32 a3);
extern void *func_020437D4(const struct Bmp *bmp);
extern void func_02082A7C(u32 fill, void *dst, u32 size);
extern void func_02082A90(const void *src, void *dst, u32 size);
extern struct Bmp *func_02044F64(struct Bmp *src, u32 keep, u16 heap);
extern s32 func_02061CA4(void *p, u32 a, u32 b, s32 size);
extern void *func_02030830(u32 heapId);
int func_021C2B5C(void *t, int *st);
int func_021C2B98(void *a, u32 *p);
int func_021C2BD4(u16 id);
void func_021C2BE4(Obj *p, u32 a1, u32 a2, u32 chrFile, u32 plttFile);


/*
 * Fade-out state step: start the fade, then wait for it to finish.
 */
int func_021C2B5C(void *t, int *st)
{
    func_0201210C(func_020124E4(t));
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
    func_0201210C(func_020124E4(a));
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
