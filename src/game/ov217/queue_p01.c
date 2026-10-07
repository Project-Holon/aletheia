/*
 * file:     queue_p01.c
 * unit:     yes
 * function: func_021C05B0, func_021C06AC, func_021C06C8, func_021C06E0, func_021C06F0, func_021C0794, func_021C07B0, func_021C07BC, func_021C0800, func_021C0820, func_021C083C, func_021C085C, func_021C0878, func_021C08A8, func_021C08C4, func_021C08D4, func_021C08F0, func_021C0900, func_021C0918, func_021C093C, func_021C0968, func_021C097C, func_021C099C
 * address:  0x021C05B0
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   d_021C3C54  0x021C3C54  data  a4
 *   d_021C37D0  0x021C37D0  data  a4
 *   func_0204384C  0x0204384C  arm
 *   func_020439A0  0x020439A0  arm
 *   func_020437AC  0x020437AC  arm
 *   func_02045EC0  0x02045EC0  arm
 *   func_0201C7D0  0x0201C7D0  thumb
 *   func_020307B0  0x020307B0  arm
 *   _u32_div_f  0x0209C0A4  arm
 *   func_02025538  0x02025538  thumb  ov217
 *   func_02025588  0x02025588  thumb
 *   d_021C377C 0x021C377C data a4
 *   func_021BF9F0 0x021BF9F0 thumb ov217
 *   func_020255A0 0x020255A0 thumb
 *   func_02025774 0x02025774 thumb
 *   func_020257D0 0x020257D0 thumb
 *   func_0202570C  0x0202570C  thumb
 *   func_02021518 0x02021518 thumb
 *   func_0202155C 0x0202155C thumb
 *   func_020216D4 0x020216D4 thumb
 *   func_02021540  0x02021540  thumb
 *   func_021C29C8  0x021C29C8  thumb  ov217
 *   func_021C29D8  0x021C29D8  thumb  ov217
 *   d_021C3A28  0x021C3A28  data  a4
 *   func_021C29E8  0x021C29E8  thumb  ov217
 *   func_021C2A08  0x021C2A08  thumb  ov217
 *   func_020056A0  0x020056A0  thumb
 *   func_021BF6BC  0x021BF6BC  thumb  ov217
 *   func_02030EAC  0x02030EAC  arm
 *   func_02012138  0x02012138  thumb
 *   func_02026400  0x02026400  thumb
 *   func_02026454  0x02026454  thumb
 *   func_02026498  0x02026498  thumb
 *   func_021BF734  0x021BF734  thumb  ov217
 *   func_020121CC  0x020121CC  thumb
 *   func_021C0A38  0x021C0A38  thumb  ov217
 *   func_021C0A04  0x021C0A04  thumb  ov217
 *   func_021C0A5C  0x021C0A5C  thumb  ov217
 *   func_021C0A54  0x021C0A54  thumb  ov217
 *   func_021C0AA4  0x021C0AA4  thumb  ov217
 */
#include "../../matched/include/Obj10961.h"
#include "../../matched/include/Obj25966.h"
#include "../../matched/include/Obj25967.h"
#include "../../matched/include/Obj25969.h"
#include "../../matched/include/Obj03953.h"
#include "../../matched/include/Obj10962.h"
#include "../../matched/include/Obj25970.h"
#include "../../matched/include/Obj25973.h"
#include "../../matched/include/Obj25974.h"
#include "../../matched/include/Obj25975.h"

#define E ((const struct Entry_021C05B0 *)gb)
struct Bmp;
struct MsgBank;
struct Obj020437AC;
struct Sys;
struct Grid;
struct Obj;
struct PalAnmSlot;
struct Node;
struct Ctx;
struct Comm;
struct IcaAnime;
typedef unsigned char u8;

typedef unsigned short u16;

typedef signed short s16;

typedef unsigned int u32;

struct Entry_021C05B0 {
    int x, y, pad, bank, index, px, py;
    u8 r, g, b, pad2;
    u32 arc, member, enabled;
};

struct Row {
    u32 w[20];
};

struct Tab {
    struct Row r[3];
};

typedef signed int     s32;

struct Param { void *bmp; s16 x,y; u32 f8,fc; u8 f10,f11; u16 f12; u32 f14; };

struct Entry_021C06F0 { s16 x,y; u32 f8,fc; u8 f10,f11; u16 f12; u32 f14; };

typedef signed char    s8;

struct Ent {
    u32 a;
    u32 b;
    u8 c;
    u8 pad[11];
};

extern struct Bmp *func_0204384C(u32, u32, u32, u32);
extern void func_020439A0(struct Bmp *, struct Bmp *, u32, u32, int, int, u32, u32, u32);
extern void *func_02045EC0(struct MsgBank *, u32);
extern void func_0201C7D0(void *, s16, s16, void *, void *, u16);
extern u32 func_020307B0(void *p);
extern void func_020437AC(struct Obj020437AC *);
extern int func_02025538(u16 heap, int a);
extern void func_02025588(void *p);
extern u32 func_021BF9F0(void *,u32);
extern struct Grid *func_020255A0(struct Sys *,const struct Param *);
extern void func_02025774(u8 *,u32);
extern void func_020257D0(struct Obj *);
extern void func_0202570C(struct Grid *g);
extern void *func_02021518(u32);
extern void func_0202155C(struct PalAnmSlot *, u32, u32, u32);
extern void func_020216D4(struct PalAnmSlot *, u32, u32, u32);
extern u32 func_02021540(void *a0);
extern void func_020215A0(struct PalAnmSlot *slots, u32 idx);
extern u32 func_021C29C8(u32 a0);
extern u32 func_021C29D8(void *a0);
extern void func_021C29E8(void *p, u32 b, u32 c, u32 d);
extern int func_021C2A08(char *p);
extern void func_0203D34C(u32 a, u32 b);
extern int func_020056A0(void (*)(void), void *, int);
extern u32 func_021BF6BC(u32 a0, u32 a1);
extern void func_02030EAC(struct Node *n);
extern u32 func_02012138(const struct Ctx *);
extern void func_02026400(struct Comm *p);
extern u32 func_02026454(void *obj);
extern void func_02026498(void *obj, u32 flag);
extern u32 func_021BF734(u8 *);
extern u32 func_020121CC(struct IcaAnime *p);
extern u32 func_021C0A38(u32 a0);
extern void func_021C0A04(u8 *p);
extern void func_021C0A5C(u8 *p, const struct Ctx *ctx, u32 heap);
extern u32 func_021C0A54(void *a0);
extern u32 func_021C0AA4(u32);
void func_021C05B0(u8 *p);
void func_021C06AC(int *p);
void func_021C06C8(u8 *p);
void func_021C06E0(u8 *a0);
void func_021C06F0(u8 *p);
void func_021C0794(int *p);
void func_021C07B0(void *p);
void func_021C07BC(u8 *p);
u32 func_021C0800(u32 a0);
void func_021C0820(void *p);
void func_021C083C(u8 *p);
void func_021C085C(int *p);
void func_021C0878(u8 *p);
void func_021C08A8(int *p);
void func_021C08C4(u32 a0);
void func_021C08D4(char *p);
void func_021C08F0(u8 *a0);
u32 func_021C0900(s32 v);
void func_021C0918(u8 *a0);
int func_021C093C(u8 *a0);
void func_021C0968(unsigned char *a0);
int func_021C097C(int a0, int a1);
u32 func_021C099C(void *a0);
extern const struct Tab d_021C3C54;
extern const struct Entry_021C05B0 d_021C37D0;
extern const struct Entry_021C06F0 d_021C377C[];
extern const struct Ent d_021C3A28[];

void func_021C05B0(u8 *p)
{
    struct Tab tab = d_021C3C54;
    int i;
    int j;
    struct Bmp *bmp;
    void *text;
    u16 color;
    u32 gb = (u32)&d_021C37D0;
    bmp = func_0204384C(E->arc, E->member, 0, *(u16 *)(p + 4));
    for (i = 0; i < 3; i++) {
        int y = i * 8;
        for (j = 0; j < 20; j++) {
            func_020439A0(bmp, *(struct Bmp **)(p + 0x3B4), (tab.r[i].w[j] % 3) * 8, (tab.r[i].w[j] / 3) * 8, j * 8, y, 8, 8, 0);
        }
    }
    func_020437AC((struct Obj020437AC *)bmp);
    color = ((E->r & 31) << 10) | ((E->g & 31) << 5) | (E->b & 31);
    text = func_02045EC0(*(struct MsgBank **)(p + 12 + E->bank * 4), E->index);
    func_0201C7D0(*(void **)(p + 0x3B4), E->px, E->py, text, *(void **)(p + 8), color);
    func_020307B0(text);
}


void func_021C06AC(int *p)
{
    int i;
    for (i = 0; i < 2; i++)
        func_020437AC((struct Obj020437AC *)p[i + 0xEC]);
}


void func_021C06C8(u8 *p)
{
    ((struct Obj10961 *)p)->f3A4 = func_02025538(((struct Obj10961 *)p)->f4, ((struct Obj10961 *)p)->f38C);
}


void func_021C06E0(u8 *a0)
{
    func_02025588((void *)((u32)(((struct Obj25966 *)a0)->f3A4)));
}

/*
 * note 2026-10-05 (wave D9r lane 131): removed the 4 dead first assignments
 * (`sysOff=0x3B0;` before `sysOff=0x3A4;`; `outOff=0x3B0;` before
 * `outOff=0x3A8;` and 2 more). Game code has no line table, so these were
 * stand-ins. The plain single assignment gives EXACT in --lang c99 and
 * --lang c: the output bytes do not change. Older text in this header that
 * asks for the double assignment is superseded.
 */
void func_021C06F0(u8 *p)
{
    int sysOff,outOff,callOff,uploadOff;
    struct Param param;
    int i;
    const struct Entry_021C06F0 *q;
    u8 *dest;
    sysOff=0x3A4;
    outOff=0x3A8;
    callOff=0x3A8;
    uploadOff=0x3A8;
    for(i=0;i<2;i++) {
        dest=p+i*4;
        param.bmp=((struct Obj25967 *)dest)->f3B0;
        q=&d_021C377C[i];
        param.x=q->x; param.y=q->y;
        param.f8=func_021BF9F0(p,q->f8);
        param.fc=q->fc;
        param.f10=q->f10; param.f11=q->f11;
        param.f12=q->f12; param.f14=q->f14;
        *(struct Grid **)(dest+outOff)=func_020255A0(*(struct Sys **)(p+sysOff),&param);
        func_02025774(*(u8 **)(dest+callOff),0);
        func_020257D0(*(struct Obj **)(dest+uploadOff));
    }
}


/*
 * Addresses are Black-image addresses.
 */
void func_021C0794(int *p)
{
    int i;
    for (i = 0; i < 2; i++)
        func_0202570C((struct Grid *)p[i + 0xEA]);
}


/*
 * Clear the u32 at +0x3b8.
 *
 * Addresses are Black-image addresses.
 */
void func_021C07B0(void *p)
{
    ((struct Obj25969 *)p)->f3B8 = 0;
}

void func_021C07BC(u8 *p)
{
    ((struct Obj03953 *)p)->f3B8 = func_02021518(((struct Obj03953 *)p)->f4);
    func_0202155C(((struct Obj03953 *)p)->f3B8, 0, 512, ((struct Obj03953 *)p)->f4);
    func_0202155C(((struct Obj03953 *)p)->f3B8, 2, 512, ((struct Obj03953 *)p)->f4);
    func_020216D4(((struct Obj03953 *)p)->f3B8, 0, 0, 512);
    func_020216D4(((struct Obj03953 *)p)->f3B8, 2, 0, 512);
}

/*
 * Reconstructed from the listing (.inst decoded).
 *
 * BLOCKED at MATCH: the relocation site(s) below have no independent witness.
 *   +001A THM_CALL func_02021540       -> unresolved: 02021540 (arm, from name) has no witness outside 021C0800..021C0820
 * Promote automatically when the target is matched.
 *
 * Addresses are Black-image addresses.
 */
u32 func_021C0800(u32 a0)
{
    func_020215A0((struct PalAnmSlot *)(((struct Obj10962 *)(((u8*)a0)))->f3B8), 0);
    func_020215A0((struct PalAnmSlot *)(((struct Obj10962 *)(((u8*)a0)))->f3B8), 2);
    return func_02021540((void *)(((struct Obj10962 *)(((u8*)a0)))->f3B8));
}


void func_021C0820(void *p)
{
    int i;
    for (i = 0; i < 8; i++)
        *(u32 *)((char *)p + i * 4 + 0x324) = 0;
}


void func_021C083C(u8 *p)
{
    int i;
    for (i = 0; i < 8; i++)
        *(int *)(p + i * 4 + 0x324) = func_021C29C8(((struct Obj25970 *)p)->f4);
}


void func_021C085C(int *p)
{
    int i;
    for (i = 0; i < 8; i++)
        func_021C29D8((void *)p[i + 0xC9]);
}


void func_021C0878(u8 *p)
{
    int i;
    for (i = 0; i < 8; i++)
        func_021C29E8((void *)(*(int *)(p + i * 4 + 0x324)), d_021C3A28[i].a, d_021C3A28[i].b, d_021C3A28[i].c);
}


void func_021C08A8(int *p)
{
    int i;
    for (i = 0; i < 8; i++)
        func_021C2A08((char *)p[i + 0xC9]);
}

/*
 * Reconstructed from the listing.
 *
 * Addresses are Black-image addresses.
 */
void func_021C08C4(u32 a0)
{
    func_0203D34C(1, ((struct Obj25973 *)(((u8*)a0 + 0)))->f4);
}


void func_021C08D4(char *p)
{
    ((struct Obj25974 *)p)->f3C0 = func_020056A0((void (*)(void))func_021BF6BC, p, 0);
}


/*
 * Tail-call veneer: forwards arg(s) (u32)(*(u32*)(a0 + 960)), 960 to func_02030EAC.
 *
 * Addresses are Black-image addresses.
 */
void func_021C08F0(u8 *a0)
{
    func_02030EAC((struct Node *)((u32)(((struct Obj25975 *)a0)->f3C0)));
}


u32 func_021C0900(s32 v)
{
    if (v < 0)
        return 0;
    if (v > 0xff)
        return 0xff;
    return (u8)v;
}

/*
 * Opens the +0x10 record (func_02012138 on the result of func_021BF734),
 * tags it with 1, and releases it when func_02026454 reports state 2.
 * Closed by the generator's duplicate guard statement (O89).
 *
 * Addresses are Black-image addresses.
 */
void func_021C0918(u8 *a0)
{
    u32 v1 = func_02012138((const struct Ctx *)func_021BF734(a0));
    func_02026498((void *)v1, 1);
    if (func_02026454((void *)v1) == 2) {
    func_02026400((struct Comm *)v1);
    }
}


int func_021C093C(u8 *a0)
{
    u32 r;
    r = func_021BF734(a0);
    switch (func_02026454((void *)func_02012138((const struct Ctx *)r))) {
    case 0:
        func_020121CC((struct IcaAnime *)r);
        return 1;
    default:
        return 1;
    case 2:
        return 0;
    }
}


void func_021C0968(unsigned char *a0)
{
    func_02026498((void *)func_02012138((const struct Ctx *)func_021BF734(a0)), 0);
}


int func_021C097C(int a0, int a1)
{
    int r;
    r = func_021C0A38(a0);
    func_021C0A04((u8 *)r);
    func_021C0A5C((u8 *)r, (const struct Ctx *)a1, a0);
    return r;
}

/*
 * Reconstructed from the listing (.inst decoded).
 *
 * Addresses are Black-image addresses.
 */
u32 func_021C099C(void *a0)
{
    func_021C0AA4((u32)a0);
    return func_021C0A54(a0);
}
