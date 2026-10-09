/*
 * file:     field_effect_p17.c
 * unit:     yes
 * function: func_021ABF48, func_021ABF68, func_021ABFA8, func_021ABFC0, func_021ABFDC, func_021ABFEC, func_021ABFFC, func_021AC03C, func_021AC074, func_021AC0A0, func_021AC134, func_021AC140, func_021AC154, func_021AC178, func_021AC18C, func_021AC1A0, func_021AC1AC, func_021AC1B8, func_021AC1CC, func_021AC1E0, func_021AC1EC, func_021AC1F0, func_021AC218, func_021AC260, func_021AC274, func_021AC2AC, func_021AC2C0, func_021AC2F0, func_021AC384, func_021AC3A4, func_021AC3F8, func_021AC494, func_021AC4B8, func_021AC4CC, func_021AC514, func_021AC528, func_021AC578, func_021AC62C, func_021AC660, func_021AC66C, func_021AC688, func_021AC68C, func_021AC6C0, func_021AC6D4, func_021AC740, func_021AC760
 * address:  0x021ABF48
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
 *   func_021C6628  0x021C6628  thumb  ov021
 *   d_021D8F60  0x021D8F60  data  a4
 *   func_02030CB0  0x02030CB0  arm
 *   func_02030734  0x02030734  arm
 *   func_02030CBC  0x02030CBC  arm
 *   d_021DE018  0x021DE018  data  a4
 *   func_02030DA4  0x02030DA4  arm
 *   func_020307B0  0x020307B0  arm
 *   func_02030D28  0x02030D28  arm
 *   func_02022040  0x02022040  thumb
 *   func_021ABE14  0x021ABE14  thumb  ov021
 *   func_02188C88  0x02188C88  thumb  ov021
 *   func_02050080  0x02050080  arm
 *   d_021DE028     0x021DE028  data  a1
 *   d_021D908C     0x021D908C  data  a4
 *   ENV_SetResourceSet  0x020307B0  arm
 *   func_021ABE24  0x021ABE24  thumb  ov021
 *   func_02050278  0x02050278  arm
 *   d_021D9098  0x021D9098  data
 *   func_021ABEA0  0x021ABEA0  thumb  ov021
 *   func_0216E1A4  0x0216E1A4  thumb  ov010
 *   func_0216E1C4  0x0216E1C4  thumb  ov010
 *   func_0216D67C  0x0216D67C  thumb  ov010
 *   func_0216D98C  0x0216D98C  thumb  ov010
 *   func_0216DAB4  0x0216DAB4  thumb  ov010
 *   func_0216D57C  0x0216D57C  thumb  ov010
 *   func_0216E3C4  0x0216E3C4  thumb  ov010
 *   func_0216D88C  0x0216D88C  thumb  ov010
 *   func_0216D92C  0x0216D92C  thumb  ov010
 *   func_0207C9D0  0x0207C9D0  arm
 *   func_0216D8B0  0x0216D8B0  thumb  ov010
 *   func_0204F720  0x0204F720  arm
 *   func_0204F638  0x0204F638  arm
 *   d_021DE038  0x021DE038  data
 *   func_021ABE18  0x021ABE18  thumb  ov021
 *   func_021C6AE0  0x021C6AE0  thumb  ov021
 *   func_021C6AF0  0x021C6AF0  thumb  ov021
 *   func_021C6AF8  0x021C6AF8  thumb  ov021
 *   func_021C6AFC  0x021C6AFC  thumb  ov021
 *   func_021C6574  0x021C6574  thumb  ov021
 *   func_021C6580  0x021C6580  thumb  ov021
 *   d_021D90AC     0x021D90AC  data  a4
 *   func_0216D538  0x0216D538  thumb  ov010
 *   _ll_mul        0x0209C054  arm
 *   tbl_020A1B38   0x020A1B38  data  a2
 *   func_021C6590  0x021C6590  thumb  ov021
 *   func_021C6694  0x021C6694  thumb  ov021
 *   d_021DE070  0x021DE070  data
 *   func_02188C90  0x02188C90  thumb  ov021
 *   func_02188C80  0x02188C80  thumb  ov021
 *   func_021ABE28  0x021ABE28  thumb  ov021
 *   func_02046E24  0x02046E24  arm
 *   func_020500F0  0x020500F0  arm
 *   d_021D911C     0x021D911C  data  a2
 *   d_021D90EC  0x021D90EC  data
 *   func_02163E58  0x02163E58  thumb  ov010
 *   func_02164280  0x02164280  thumb  ov010
 *   func_0216D55C  0x0216D55C  thumb  ov010
 *   func_0216D588  0x0216D588  thumb  ov010
 *   func_0216D590  0x0216D590  thumb  ov010
 *   func_0216D83C  0x0216D83C  thumb  ov010
 *   func_0216D86C  0x0216D86C  thumb  ov010
 *   func_0216D8AC  0x0216D8AC  thumb  ov010
 */
#include "../../matched/include/Obj07511.h"
#include "../../matched/include/Obj18085.h"
#include "../../matched/include/Obj18086.h"
#include "../../matched/include/Obj04241.h"
#include "../../matched/include/Obj12095.h"
#include "../../matched/include/Obj07513.h"
#include "../../matched/include/Obj12096.h"
#include "../../matched/include/Obj05038.h"

struct Ctx;
struct Mgr;
struct Node;
struct Tagged;
struct Ctl;
struct BbActRec;
struct BbActSys;
struct BbActDesc;
struct Trip;
struct Actor;
struct VecFx32;
struct X;
typedef unsigned short u16;

typedef struct {
    int f0;
    int f4;
} E_021ABF48;

typedef struct T_021ABF48 T_021ABF48;

typedef struct {
    int id;
    int (*f4)(T_021ABF48 *t, u16 h);
    void (*f8)(T_021ABF48 *t, int v);
} D;

struct T_021ABF48 {
    int f0;
    u16 h4;
    u16 pad6;
    int pad8[2];
    E_021ABF48 *f10;
};

typedef struct {
    int f0;
    u16 h4;
    u16 pad6;
    int pad8[3];
    u16 h14;
    u16 pad16;
    void *f18;
    int f1c;
    int f20;
} T_021ABF68;

typedef unsigned int   u32;

typedef struct {
    int f0;
    u16 h4;
    u16 pad6;
    int pad8[3];
    u16 h14;
    u16 pad16;
    void *f18;
    int f1c;
    int f20;
} T_021ABFA8;

typedef struct {
    int f0;
    u16 h4;
    u16 pad6;
    int pad8[3];
    u16 h14;
    u16 pad16;
    void *f18;
    int f1c;
    int f20;
} T_021ABFC0;

typedef struct {
    int f0;
    u16 h4;
    u16 pad6;
    int pad8[3];
    u16 h14;
    u16 pad16;
    void *f18;
    int f1c;
    int f20;
} T;

typedef struct {
    int f0;
    char pad[0xd0];
} E_021ABFDC;

typedef struct {
    u32 f0;
    int f4;
    E_021ABFDC *f8;
} U;

typedef unsigned char  u8;

typedef signed short   s16;

typedef signed char    s8;

typedef struct V3 { int x, y, z; } V3;

typedef struct Obj_021AC074 Obj_021AC074;

typedef void (*ObjCb_021AC074)(Obj_021AC074 *o, void *work);

struct Obj_021AC074 {
    u32 active;
    u32 f4;
    u32 f8;
    V3 pos;
    u8 work[0xa4];
    ObjCb_021AC074 init;
    ObjCb_021AC074 exit;
    ObjCb_021AC074 f_c4;
    ObjCb_021AC074 f_c8;
    u32 fcc;
    void *fd0;
};

typedef struct Mgr_021AC074 { u32 count; u32 f4; Obj_021AC074 *objs; } Mgr_021AC074;

typedef struct Obj_021AC0A0 Obj_021AC0A0;

typedef struct Mgr_021AC0A0 Mgr_021AC0A0;

typedef struct ObjFuncs { ObjCb_021AC074 f0; ObjCb_021AC074 init; ObjCb_021AC074 exit; ObjCb_021AC074 f_c4; ObjCb_021AC074 f_c8; } ObjFuncs;

struct Obj_021AC0A0 {
    u32 active;
    u32 f4;
    u32 f8;
    V3 pos;
    u8 work[0xa0];
    ObjFuncs funcs;
    Mgr_021AC0A0 *mgr;
    void *fd0;
};

struct Mgr_021AC0A0 { u32 count; u32 f4; Obj_021AC0A0 *objs; u32 heap; };

typedef signed int     s32_021ABF48;

typedef void (*ObjCb_021AC134)(Obj_021AC074 *o, void *work);

typedef struct Obj_021AC154 Obj_021AC154;

typedef void (*ObjCb)(Obj_021AC154 *o, void *work);

struct Obj_021AC154 {
    u32 active;
    u32 f4;
    u32 f8;
    V3 pos;
    u8 work[0xa4];
    ObjCb init;
    ObjCb exit;
    ObjCb f_c4;
    ObjCb f_c8;
    u32 fcc;
    void *fd0;
};

typedef struct Res { u8 pad[0x30]; u16 h30; u16 pad32; u32 f34; u32 f38; } Res;

typedef struct X_021ABF48 { u8 pad[0x24]; u32 f24; } X_021ABF48;

typedef struct { int x; int y; int z; } V;

typedef struct Tmpl { u32 res; u8 b4, b5, b6, b7; u32 w8; } Tmpl;

typedef struct Ctl { u32 f0; u32 f4; u32 f8; u32 fc; u32 f10; u32 f14; u32 f18; } Ctl;

typedef struct Arg_021AC074 { u32 a; u32 b; } Arg_021AC074;

typedef struct Desc {
    u16 slot;
    u16 v12;
    u16 v14;
    u8 k;
    u8 pad;
    u32 flag;
    u32 w;
    V3 pos;
    void (*f1c)(void);
    u32 f20;
} Desc;

typedef struct Sys { u8 pad[0x10]; u32 f10; u32 f14; u32 f18; } Sys;

typedef struct Arg4 { u8 b0; } Arg4;

typedef struct P_021AC074 {
    u32 f0;
    Sys *sys;
    u32 f8;
    u16 fc[4];
    u32 f14;
} P_021AC074;

typedef struct H { u32 f0, f4, f8, fc, f10; } H;

typedef struct W { u32 f0; H *h; u32 f8, fc, f10; u32 f14; } W;

typedef int            s32_021AC3F8;

typedef struct Vec3_021ABF48 { s32_021AC3F8 x, y, z; } Vec3_021ABF48;

typedef struct P_021AC384 { u32 f0; u32 f4; } P_021AC384;

typedef signed int     s32_021AC4B8;

typedef int            s32_021AC528;

typedef struct Arg_021AC384 { u32 a; Vec3_021ABF48 v; } Arg_021AC384;

typedef int            s32_021AC578;

typedef struct Vec3_021AC578 { s32_021AC578 x, y, z; } Vec3_021AC578;

typedef struct Arg { u32 a; Vec3_021AC578 v; } Arg;

typedef struct HidObj_021AC660 {
    int f0;
    void *f4;
    u16 f8;
} HidObj_021AC660;

typedef struct X_021AC66C { u32 f0; u32 f4; u16 f8; } X_021AC66C;

typedef struct P { u32 f0; u32 f4; u32 w[4]; } P;

typedef signed int     s32;

typedef struct Arg_021AC6D4 { u32 a; u8 b4, b5, b6, b7; u32 c; } Arg_021AC6D4;

typedef struct X { u32 f0; u32 f4; u16 h[8]; } X;

typedef struct Arg_021AC760 {
    u32 f0;
    u32 f4;
    int f8;
    int fc;
    u16 h10;
    u16 h12;
    V3 pos;
    int f20;
} Arg_021AC760;

extern u32 func_02030CB0(u32 idx);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern struct Ctx *func_02030CBC(u32 capacity, struct Ctx *c);
extern void func_02030DA4(int a);
extern u32 func_020307B0(void *p);
extern void func_02030D28(struct Ctx *c);
extern u32 func_02082BCC(void *p, int v, int n);
extern void *func_02030DA8(u32 heap, void (*cb)(void), void *arg, u32 pri);
extern void func_02030EAC(struct Node *n);
extern void *func_02046F48(struct Tagged *p);
extern unsigned char *func_0206E964(unsigned char *p);
extern void func_02022040(u16 *pal, int n, const u8 *table);
extern u32 func_021ABE14(u8 *p);
extern u32 func_02188C88(u8 *p);
extern u32 func_02050080(u32 *p);
extern void ENV_SetResourceSet(void *p);
extern u32 func_021ABE24(u8 *p);
extern void *func_02046E24(u32 a0, u32 a1);
extern u16 func_020500F0(struct BbActSys *o, const struct BbActRec *recs, u32 n);
extern void func_02050278(struct BbActSys *o, u32 first, u32 count);
extern int func_021ABEA0(u32 a, u32 b);
extern int func_0216E1A4(int a0, int a1);
extern u16 func_02050340(struct BbActSys *o, u16 base, const struct BbActDesc *d, u32 count, u32 mode);
extern void func_0204F6DC(u8 *a0, int i, u8 *px);
extern void func_02050468(struct BbActSys *o, u16 first, u32 count);
extern int func_0216E1C4(int a0, int a1);
extern void *func_0216D67C(void *a0);
extern int func_0216D98C(int a0);
extern int func_0216DAB4(void *a0);
extern u32 func_0216D57C(void *p, u32 v);
extern void *func_0216E3C4(void *p);
extern void func_0216D88C(const struct Actor *a, struct VecFx32 *v);
extern void func_0216D92C(u8 *p, s32_021AC3F8 *q);
extern void func_0207C9D0(Vec3_021ABF48 *a, Vec3_021ABF48 *b, Vec3_021ABF48 *c);
extern void func_0216D8B0(u8 *p, u8 *q);
extern void func_0204F720(void *p, u32 idx, u32 *flag);
extern void func_0204F638(u8 *a0, int i, struct Trip *src);
extern u32 func_021ABE18(u8 *p);
extern void func_021C6AE0(u32 a);
extern int func_021C6AF0(u32 a, u32 b, u32 c);
extern void func_021C6AF8(u32 *p, u32 v);
extern void func_021C6AFC(u32 *a, u32 b);
extern int func_021C6574(u32 a, u32 b, u32 c);
extern u32 func_021C6580(u32, u32);
extern u32 func_0216D538(u8 *p);
extern u32 func_021C6590(u32 a, u32 b, u32 c, u32 *d);
void func_021C6628(u32 a, u32 b);
extern int func_021C6694(u32 *a, int idx, int v);
extern u32 func_02188C90(u8 *p);
extern void *func_02188C80(void *p);
extern u8 func_021ABE28(u8 *p);
extern u16 func_0216D588(void *p);
extern u16 func_0216D590(void *p);
extern int func_0216D83C(void *p);
extern int func_0216D86C(void *p);
extern void func_02164280(int x, int y, int *p);
extern u32 func_0216D8AC(void *p);
extern int func_0216D55C(int a0, int a1);
extern void func_02163E58(u32 a, V3 *v, int *out);
D *func_021ABF48(int id);
void func_021ABF68(T_021ABF68 *t, int n);
void func_021ABFA8(T_021ABFA8 *t, int b, int c, int d, int e, int f);
void func_021ABFC0(T_021ABFC0 *t);
void func_021ABFDC(T *t);
void func_021ABFEC(T *t);
char *func_021ABFFC(u16 heap, int b, int cnt);
void func_021AC03C(U *u);
void func_021AC074(Mgr_021AC074 *m);
Obj_021AC0A0 *func_021AC0A0(Mgr_021AC0A0 *m, const ObjFuncs *funcs, const V3 *pos, u32 f4, u32 f8, u32 pri);
void func_021AC134(u32 a, u32 b);
void func_021AC140(Obj_021AC074 *o);
void func_021AC154(Obj_021AC154 *o);
void func_021AC178(Obj_021AC154 *o);
void func_021AC18C(Obj_021AC154 *o);
int func_021AC1A0(u32 a);
int func_021AC1AC(u32 a);
void func_021AC1B8(Obj_021AC154 *o, V3 *out);
void func_021AC1CC(Obj_021AC154 *o, V3 *in);
int func_021AC1E0(u32 a);
void func_021AC1EC(u32 *p, u32 v);
void func_021AC1F0(X_021ABF48 *x, void *b);
char *func_021AC218(int a, int heap);
void func_021AC260(u32 a, u8 *p);
void func_021AC274(Ctl *p);
void func_021AC2AC(u8 *p);
void func_021AC2C0(u32 a, u32 b);
void func_021AC2F0(u32 a, P_021AC074 *p);
void func_021AC384(u32 a, W *w);
void func_021AC3A4(u32 a, u32 *b);
void func_021AC3F8(u32 unused, u32 *p);
P_021AC384 *func_021AC494(u32 a, int heap);
void func_021AC4B8(u32 a, u8 *p);
void func_021AC4CC(u32 *a);
int func_021AC514(u32 a);
void func_021AC528(u32 a, u32 b);
void func_021AC578(u32 a, u32 b);
void func_021AC62C(u32 a, u32 *b);
void func_021AC660(u32 a, HidObj_021AC660 *q);
void func_021AC66C(u32 a, X_021AC66C *x);
void func_021AC688(void);
P *func_021AC68C(int a, int heap);
void func_021AC6C0(u32 a, u8 *p);
void func_021AC6D4(u32 *p);
void func_021AC740(X *x);
void func_021AC760(u32 a, u32 b, u32 c, int d);
extern D d_021D8F60[];
extern char d_021DE018[];
extern char d_021DE028[];
extern V d_021D908C;
extern u8 d_021D9098[];
extern char d_021DE038[];
extern u8 d_021D90AC[];
extern s16 tbl_020A1B38[];
extern char d_021DE070[];
extern u16 d_021D911C[];
extern u8 d_021D90EC[];







D *func_021ABF48(int id)
{
    int i;
    D *d = d_021D8F60;
    for (i = 0; i < 0x18; i++) {
        if (d->id == id) {
            return d;
        }
        d++;
    }
    return d;
}







void func_021ABF68(T_021ABF68 *t, int n)
{
    t->h14 = n;
    t->f18 = func_02030734(t->h4, func_02030CB0(n), 0, d_021DE018, 0x1db);
    t->f1c = (int)func_02030CBC(n, t->f18);
    t->f20 = (int)func_021ABFFC(t->h4, t->f1c, n);
}







void func_021ABFA8(T_021ABFA8 *t, int b, int c, int d, int e, int f)
{
    func_021AC0A0((Mgr_021AC0A0 *)t->f20, (const ObjFuncs *)b, (const V3 *)c, d, e, f);
}







void func_021ABFC0(T_021ABFC0 *t)
{
    if (t->f20 != 0) {
        func_021AC03C((void *)t->f20);
        func_02030DA4(t->f1c);
        func_020307B0(t->f18);
    }
}







void func_021ABFDC(T *t)
{
    if (t->f1c != 0) {
        func_02030D28((struct Ctx *)t->f1c);
    }
}







void func_021ABFEC(T *t)
{
    if (t->f20 != 0) {
        func_021AC074((Mgr_021AC074 *)((struct Mgr *)t->f20));
    }
}







char *func_021ABFFC(u16 heap, int b, int cnt)
{
    char *p;

    p = (char *)func_02030734(heap, 0x10, 1, d_021DE018, 0x23a);
    ((struct Obj07511 *)p)->f0 = cnt;
    ((struct Obj07511 *)p)->f4 = heap;
    ((struct Obj07511 *)p)->f8 = func_02030734(heap, cnt * 0xd4, 1, d_021DE018, 0x23e);
    ((struct Obj07511 *)p)->fC = b;
    return p;
}







void func_021AC03C(U *u)
{
    u32 i;
    for (i = 0; i < u->f0; i++) {
        if (u->f8[i].f0 != 0) {
            func_021AC154((Obj_021AC154 *)(&u->f8[i]));
        }
    }
    func_020307B0(u->f8);
    func_020307B0(u);
}










void func_021AC074(Mgr_021AC074 *m)
{
    u32 i;

    for (i = 0; i < m->count; i++) {
        if (m->objs[i].active != 0)
            func_021AC18C((void *)&m->objs[i]);
    }
}










Obj_021AC0A0 *func_021AC0A0(Mgr_021AC0A0 *m, const ObjFuncs *funcs, const V3 *pos, u32 f4, u32 f8, u32 pri)
{
    u32 i = 0;
    Obj_021AC0A0 *o = m->objs;

    do {
        if (o->active == 0) {
            func_02082BCC(o, 0, sizeof(Obj_021AC0A0));
            o->active = 1;
            o->funcs = *funcs;
            o->f4 = f4;
            o->f8 = f8;
            if (pos != 0)
                o->pos = *pos;
            o->mgr = m;
            o->fd0 = func_02030DA8(m->heap, (void (*)(void))func_021AC134, o, pri);
            break;
        }
        i++;
        o++;
    } while (i < m->count);
    if (i < m->count) {
        func_021AC140((void *)o);
        return o;
    }
    return 0;
}










/*
 * Untraced thunk: forwards the second argument.
 *
 * Addresses are Black-image addresses.
 */
void func_021AC134(u32 a, u32 b)
{
    func_021AC178((void *)b);
}










void func_021AC140(Obj_021AC074 *o)
{
    if (o != 0)
        o->init(o, o->work);
}









void func_021AC154(Obj_021AC154 *o)
{
    if (o != 0) {
        o->exit(o, o->work);
        func_02030EAC(o->fd0);
        o->active = 0;
    }
}









void func_021AC178(Obj_021AC154 *o)
{
    if (o != 0)
        o->f_c4(o, o->work);
}









void func_021AC18C(Obj_021AC154 *o)
{
    if (o != 0)
        o->f_c8(o, o->work);
}









/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_021AC1A0(u32 a)
{
if (a != 0) {
    return ((struct Obj18085 *)((u8 *)(a)))->f4;
}
return 0;
}









int func_021AC1AC(u32 a)
{
if (a != 0) {
    return ((struct Obj18086 *)((u8 *)(a)))->f8;
}
return 0;
}









void func_021AC1B8(Obj_021AC154 *o, V3 *out)
{
    if (o != 0)
        *out = o->pos;
}









void func_021AC1CC(Obj_021AC154 *o, V3 *in)
{
    if (o != 0)
        o->pos = *in;
}









int func_021AC1E0(u32 a)
{
if (a != 0) {
    return (a + 24);
}
return 0;
}








/*
 * Setter: stores the second argument at +0x24.  Unlabelled in the listing;
 * called from func_021881D8.
 *
 * Addresses are Black-image addresses.
 */
void func_021AC1EC(u32 *p, u32 v)
{
    p[9] = v;
}








void func_021AC1F0(X_021ABF48 *x, void *b)
{
    Res *p;

    if (x->f24 != 0) {
        p = (Res *)func_0206E964(func_02046F48(b));
        func_02022040((u16 *)((u8 *)p + p->f38), p->h30 * 8u / 2, (const u8 *)x->f24);
    }
}








char *func_021AC218(int a, int heap)
{
    char *p;

    p = (char *)func_02030734(heap, 0x1c, 1, d_021DE028, 0x5c);
    *(int *)&((struct Obj04241 *)p)->f0 = a;
    *(V *)(p + 4) = d_021D908C;
    ((struct Obj04241 *)p)->f10 = func_02188C88((u8 *)func_021ABE14((u8 *)a));
    ((struct Obj04241 *)p)->f14 = func_02050080((u32 *)(((struct Obj04241 *)p)->f10));
    func_021AC274((struct Ctl *)p);
    return p;
}








/*
 * Pattern-generated from the ov021 family.
 *
 * Addresses are Black-image addresses.
 */
void func_021AC260(u32 a, u8 *p)
{
    func_021AC2AC(p);
    ENV_SetResourceSet(p);
}








void func_021AC274(Ctl *p)
{
    Tmpl t;

    t.res = (u32)func_02046E24(func_021ABE24((u8 *)p->f0), 0x2f);
    t.b4 = 2;
    t.b5 = 0x11;
    t.b6 = 0x10;
    t.b7 = 0x10;
    t.w8 = 1;
    p->f18 = func_020500F0((struct BbActSys *)p->f10, (const struct BbActRec *)(&t), 1);
}








/*
 * Tail call with two fields and a constant one.
 *
 * Addresses are Black-image addresses.
 */
void func_021AC2AC(u8 *p)
{
    func_02050278((struct BbActSys *)(((struct Obj12095 *)p)->f10), (u16)((struct Obj12095 *)p)->f18, 1);
}








void func_021AC2C0(u32 a, u32 b)
{
    Arg_021AC074 s;

    s.a = func_021ABEA0(b, 0);
    s.b = a;
    func_021ABFA8((T_021ABFA8 *)b, (int)d_021D9098, 0, 0, (int)&s, 0);
}








void func_021AC2F0(u32 a, P_021AC074 *p)
{
    u32 *q = (u32 *)func_021AC1AC(a);
    Arg4 t;
    Desc s;

    p->sys = (Sys *)q[0];
    p->f8 = q[1];
    func_0216E1A4(q[1], (int)p->fc);
    s.slot = 0;
    s.v12 = 0x1000;
    s.v14 = 0x1000;
    s.k = 0x13;
    s.flag = 1;
    s.w = 1;
    {
        V3 zero = {0, 0, 0};

        s.pos = zero;
    }
    s.f1c = 0;
    s.f20 = (u32)p;
    p->f14 = func_02050340((struct BbActSys *)p->sys->f10, (u16)p->sys->f18, (const struct BbActDesc *)(&s), 1, 3);
    if (p->f14 == 0xFFFF) {
        func_021AC154((void *)a);
        return;
    }
    t.b0 = 2;
    func_0204F6DC((u8 *)p->sys->f14, p->f14, (u8 *)(&t));
    func_021AC178((void *)a);
}







void func_021AC384(u32 a, W *w)
{
    if (w->f14 != 0xFFFF)
        func_02050468((struct BbActSys *)w->h->f10, (u16)w->f14, 1);
}







/*
 * Addresses are Black-image addresses.
 */
void func_021AC3A4(u32 a, u32 *b)
{
    if (func_0216E1C4(b[2], (int)(b + 3)) == 0) {
        func_021AC154((void *)a);
        return;
    }
    if (func_0216D98C((int)func_0216D67C((void *)b[2])) == 0) {
        func_021AC154((void *)a);
        return;
    }
    if (func_0216DAB4((void *)b[2]) == 1 || func_0216D57C((void *)b[2], 0x8000) != 0)
        b[0] = 1;
    else
        b[0] = 0;
}







void func_021AC3F8(u32 unused, u32 *p)
{
    Vec3_021ABF48 v1;
    Vec3_021ABF48 v2;
    u32 one;
    u32 zero;
    u32 r4 = p[5];
    u8 *r6 = func_0216E3C4((void *)p[2]);
    if (p[0] == 0) {
        one = 1;
        func_0216D88C((const struct Actor *)p[2], (struct VecFx32 *)&v1);
        func_0216D92C((u8 *)p[2], (s32_021AC3F8 *)(&v2));
        func_0207C9D0((Vec3_021ABF48 *)&v1, (Vec3_021ABF48 *)&v2, (Vec3_021ABF48 *)&v1);
        if ((u8)(r6[3] + 246) <= 1) {
            func_0216D8B0((u8 *)p[2], (u8 *)(&v2));
            if (r6[7] == 0)
                v2.y = -0x800;
            func_0207C9D0((Vec3_021ABF48 *)&v1, (Vec3_021ABF48 *)&v2, (Vec3_021ABF48 *)&v1);
        }
        func_0204F720((void *)(*(u32 *)(p[1] + 0x14)), r4, &one);
        v1.y += 0x1000;
        func_0204F638((u8 *)(*(u32 *)(p[1] + 0x14)), r4, (struct Trip *)(&v1));
    } else {
        zero = 0;
        func_0204F720((void *)(*(u32 *)(p[1] + 0x14)), r4, &zero);
    }
}







P_021AC384 *func_021AC494(u32 a, int heap)
{
    P_021AC384 *p;

    p = (P_021AC384 *)func_02030734(heap, 8, 1, d_021DE038, 0x52);
    p->f0 = a;
    func_021AC4CC((u32 *)p);
    return p;
}







void func_021AC4B8(u32 a, u8 *p)
{
    func_021AC514((u32)p);
    func_020307B0(p);
}







void func_021AC4CC(u32 *a)
{
    u32 buf[9];
    u32 r6 = func_021ABE18((u8 *)a[0]);
    u32 r4 = func_021ABE24((u8 *)a[0]);
    func_021C6AE0((u32)buf);
    func_021C6AF0((u32)buf, r4, 0x30);
    func_021C6AF8((u32 *)buf, r4);
    func_021C6AFC(buf, 0x60);
    ((struct Obj07513 *)a)->f4 = func_021C6574(r6, (u32)buf, 0);
}







int func_021AC514(u32 a)
{
    u32 b;
    u32 c;
    u32 d;
return func_021C6580(func_021ABE18((u8 *)(((struct Obj12096 *)((u8 *)(a)))->f0)), ((struct Obj12096 *)((u8 *)(a)))->f4);
}







void func_021AC528(u32 a, u32 b)
{
    Vec3_021ABF48 v;
    Arg_021AC384 s;
    func_0216D88C((const struct Actor *)a, (struct VecFx32 *)&v);
    v.y += 0x1000;
    v.z += 0x6000;
    s.a = func_021ABEA0(b, 1);
    s.v = v;
    func_021ABFA8((T_021ABFA8 *)b, (int)d_021D90AC, 0, 0, (int)((void *)&s), 0);
}





void func_021AC578(u32 a, u32 b)
{
    Vec3_021AC578 v;
    Arg s;
    int i;
    i = func_0216D538(func_0216D67C((void *)a));
    func_0216D88C((const struct Actor *)a, (struct VecFx32 *)&v);
    v.y += 0x1000;
    i = (i >> 4) * 2;
    v.z += (s32_021AC578)(((long long)tbl_020A1B38[i + 1] * 0x6000 + 0x800) >> 12);
    v.x += (s32_021AC578)(((long long)tbl_020A1B38[i] * 0x6000 + 0x800) >> 12);
    s.a = func_021ABEA0(b, 1);
    s.v = v;
    func_021ABFA8((T_021ABFA8 *)b, (int)d_021D90AC, 0, 0, (int)&s, 0);
}





void func_021AC62C(u32 a, u32 *b)
{
    u32 *p = (u32 *)func_021AC1AC(a);
    b[0] = p[0];
    b[1] = func_021ABE18((u8 *)(*(u32 *)b[0]));
    func_021AC1CC((Obj_021AC154 *)a, (V3 *)(p + 1));
    ((struct Obj05038 *)b)->f8 = func_021C6590(b[1], *(u16 *)(b[0] + 4), 0, p + 1);
}



void func_021AC660(u32 a, HidObj_021AC660 *q)
{
    func_021C6628((u32)q->f4, q->f8);
}



void func_021AC66C(u32 a, X_021AC66C *x)
{
    if (func_021C6694((u32 *)x->f4, x->f8, 0x1000) == 0)
        func_021AC154((Obj_021AC154 *)a);
}



void func_021AC688(void)
{
}



P *func_021AC68C(int a, int heap)
{
    P *p;

    p = (P *)func_02030734(heap, 0x18, 1, d_021DE070, 0x6c);
    p->f0 = a;
    p->f4 = func_02188C90((u8 *)func_021ABE14((u8 *)a));
    func_021AC6D4((u32 *)p);
    return p;
}




/*
 * Pattern-generated from the ov021 family.
 *
 * Addresses are Black-image addresses.
 */
void func_021AC6C0(u32 a, u8 *p)
{
    func_021AC740((struct X *)p);
    func_020307B0(p);
}




/*
 * Addresses are Black-image addresses.
 */
void func_021AC6D4(u32 *p)
{
    Arg_021AC6D4 s;
    int i;
    u32 r7 = func_021ABE24((u8 *)p[0]);
    u16 *t;
    u32 lv;
    func_02188C80((void *)func_021ABE14((u8 *)p[0]));
    lv = func_021ABE28((u8 *)p[0]);
    s.b4 = 0;
    s.b5 = 0x24;
    s.b6 = 0x20;
    s.b7 = 0x20;
    s.c = 1;
    t = d_021D911C + lv;
    for (i = 0; i < 8; i++) {
        s.a = (u32)func_02046E24(r7, t[i * 4]);
        func_021AC1F0((X_021ABF48 *)((struct X *)p[0]), (void *)s.a);
        ((u16 *)p)[4 + i] = func_020500F0((struct BbActSys *)p[1], (const struct BbActRec *)(&s), 1);
    }
}




void func_021AC740(X *x)
{
    int i;

    for (i = 0; i < 8; i++)
        func_02050278((struct BbActSys *)x->f4, x->h[i], 1);
}




/*
 * The v.z -= 0x2000 adjust is written in both arms of the if; the
 * compiler tail-merges the arms and keeps the 2 of 0x2000 in r6
 * (docs/idioms/a-constant-shifted-in-a-merged-tail-is-a-statement-repeated-in-each-arm.md).
 */
void func_021AC760(u32 a, u32 b, u32 c, int d)
{
    V3 v;
    Arg_021AC760 s;
    int tmp;

    if (d >= 8)
        return;
    s.f0 = func_021ABEA0(a, 2);
    s.f4 = b;
    s.f20 = d;
    s.h10 = func_0216D588((void *)b);
    s.h12 = func_0216D590((void *)b);
    s.f8 = func_0216D83C((void *)b);
    s.fc = func_0216D86C((void *)b);
    func_02164280((s16)s.f8, (s16)s.fc, (int *)(&v));
    v.y = func_0216D8AC((void *)b);
    if (func_0216D55C(b, 0x2000) != 0) {
        v.y += 7 * 0x1000;
        v.z -= 0x2000;
    } else {
        func_02163E58(b, &v, &tmp);
        v.y = tmp + 9 * 0x1000;
        v.z -= 0x2000;
    }
    s.pos = v;
    func_021ABFA8((T_021ABFA8 *)a, (int)d_021D90EC, 0, c, (int)&s, 0);
}
