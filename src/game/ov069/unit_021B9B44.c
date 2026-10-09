/*
 * file:     unit_021B9B44.c
 * unit:     yes
 * function: func_021B9B44, func_021B9BF0, func_021B9C44, func_021B9CD8, func_021B9D08, func_021B9DE8, func_021B9DFC, func_021B9E44, func_021B9E5C, func_021B9E74, func_021B9EC0, func_021B9EDC, func_021B9F08, func_021B9F24, func_021B9F58, func_021B9F70, func_021B9F9C, func_021B9FC8, func_021B9FF0, func_021BA2A4, func_021BA2D8, func_021BA350, func_021BA384, func_021BA400, func_021BA438, func_021BA470, func_021BA480
 * address:  0x021B9B44
 * region:   ov069
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0204B294  0x0204B294  arm
 *   func_0204B92C  0x0204B92C  arm
 *   d_021BA6BC  0x021BA6BC  data  a4
 *   func_0204A8D4  0x0204A8D4  arm
 *   func_0204ADA4  0x0204ADA4  arm
 *   func_0204AFD8  0x0204AFD8  arm
 *   func_0204B1CC  0x0204B1CC  arm
 *   func_0204A5AC  0x0204A5AC  arm
 *   func_02045088  0x02045088  arm
 *   func_020450F0  0x020450F0  arm
 *   func_02045770  0x02045770  arm
 *   func_02043B5C  0x02043B5C  arm
 *   func_02045334  0x02045334  arm
 *   func_02045374  0x02045374  arm
 *   func_02045730  0x02045730  arm
 *   func_020409B4  0x020409B4  arm
 *   d_021BA874  0x021BA874  data  a4
 *   func_020452E8 0x020452E8 arm
 *   func_020450C8 0x020450C8 arm
 *   func_0201D7EC  0x0201D7EC  thumb
 *   func_0201C440  0x0201C440  thumb
 *   func_0201C724  0x0201C724  thumb
 *   func_0201C4C0 0x0201C4C0 thumb
 *   func_0201D83C 0x0201D83C thumb
 *   func_0201C4E4  0x0201C4E4  thumb
 *   func_0201C6C4  0x0201C6C4  thumb
 *   d_021BA860 0x021BA860 data a4
 *   func_020221A4 0x020221A4 thumb
 *   func_0201C6B4  0x0201C6B4  thumb
 *   func_02025D2C  0x02025D2C  thumb
 *   func_0204B98C 0x0204B98C arm
 *   func_0202208C 0x0202208C thumb
 *   func_02025CD0 0x02025CD0 thumb
 *   d_021BA71C 0x021BA71C data a4
 *   d_021BA5EC 0x021BA5EC data a4
 *   func_02025D14 0x02025D14 thumb
 *   func_020061E4 0x020061E4 thumb
 *   func_0202616C 0x0202616C thumb
 *   func_0204B404 0x0204B404 arm
 *   func_020457B0  0x020457B0  arm
 *   func_0201EFA4  0x0201EFA4  thumb
 *   func_0201F048  0x0201F048  thumb
 *   func_0201F094  0x0201F094  thumb
 *   func_0201F250  0x0201F250  thumb
 *   func_02045994  0x02045994  arm
 *   func_0202435C  0x0202435C  thumb
 *   func_02045808  0x02045808  arm
 *   func_02041B6C  0x02041B6C  arm
 *   func_02035C08 0x02035C08 arm
 *   func_020362DC 0x020362DC arm
 *   d_021BA5FC 0x021BA5FC data a4
 *   func_0204B878  0x0204B878  arm
 *   func_0204B3DC  0x0204B3DC  arm
 *   func_020260E0 0x020260E0 thumb
 *   func_021BA520  0x021BA520  thumb  ov069
 *   func_0202CC70  0x0202CC70  thumb
 */
#include "../../matched/include/Obj01132.h"
#include "../../matched/include/Obj01133.h"
#include "../../matched/include/Obj06172.h"
#include "../../matched/include/Obj20656.h"
#include "../../matched/include/Obj00432.h"
#include "../../matched/include/Obj13147.h"
#include "../../matched/include/Obj20657.h"
#include "../../matched/include/Obj20658.h"
#include "../../matched/include/Obj09876.h"
#include "../../matched/include/Obj13148.h"
#include "../../matched/include/Obj13149.h"
#include "../../matched/include/Obj06173.h"
#include "../../matched/include/Obj03659.h"

struct Obj_021B9B44;
struct Bank;
struct Descriptor;
struct Cfg;
struct CharBuf;
struct GfFont;
struct PrintSys;
struct Sound;
struct Actor;
struct Struct_02025CD0;
struct Rec;
struct Obj;
struct Vec2;
struct WordSet;
struct U16Vec;
struct Strbuf;
struct WinMgr;
typedef unsigned char u8;

typedef short s16;

typedef struct Ent_021B9B44 {
    int a, b, c;
    int d, e, f;
} Ent_021B9B44;

typedef struct SlotParam {
    s16 a, b, c;
    u8 d, e;
} SlotParam;

typedef struct WorkObj {
    unsigned char pad000[0x11C];
    int f11C;
    int f120;
    int slot[4];
    int arr[1];
} Obj_021B9B44;

typedef unsigned int   u32;

typedef unsigned short u16;

typedef struct Ent_021B9C44 {
    u32 f0;
    u8 f4, f5, f6, f7;
    u16 f8;
} Ent_021B9C44;

typedef struct Obj_021B9C44 {
    unsigned char pad000[0x10];
    int b[10];
    int a[8];
} Obj_021B9C44;

typedef int (*Callback)(u8 *);

typedef struct Point { u16 x, y; } Point;

struct Rec { u8 pad0[0x12]; u8 a; u8 b; u8 pad1[4]; u16 name[5]; };

typedef struct Ent {
    unsigned char pad[0x20];
    u8 f0 : 1;
    u8 f1 : 1;
} Ent;

typedef struct Obj {
    unsigned char pad000[4];
    struct WinMgr *f4;
    char *f8;
    unsigned char pad00C[0x160 - 0xC];
    u16 page;
    u16 f162;
    int f164;
} Obj;

extern struct Obj_021B9B44 *func_0204B294(void *owner, unsigned int i, unsigned int j, unsigned int k, const void *position, unsigned short space, unsigned short heap);
extern void func_0204B92C(struct Obj_021B9B44 *, unsigned int);
extern void func_0204A8D4(u32 i);
extern void func_0204ADA4(u32 i);
extern void func_0204AFD8(u32 i);
extern u32 func_0204B1CC(struct Bank *bank);
extern void func_0204A5AC(void);
extern void func_02045088(u16 heapId);
extern u32 func_020450F0(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
extern void *func_02045770(struct Descriptor *p);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_02045334(struct Descriptor *d);
extern void func_02045374(struct Cfg *cfg);
extern u8 func_02045730(struct Descriptor *p);
extern void func_020409B4(u32);
extern u32 func_020452E8(struct Descriptor *d);
extern void func_020450C8(void);
extern struct GfFont *func_0201D7EC(int a0, int a1, int a2, int a3, u32 heapId);
extern u32 func_0201C440(void *p);
extern void func_0201C724(void *owner, u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern void func_0201C4C0(struct PrintSys *p);
extern u32 func_0201D83C(void *ptr);
extern u32 func_0201C4E4(struct PrintSys *ps);
extern u32 func_0201C6C4(struct PrintSys *p, void *v);
extern u32 func_020221A4(void);
extern u32 func_0201C6B4(const struct PrintSys *p);
extern int func_02025D2C(struct Sound *obj);
extern u32 func_0204B98C(struct Actor *a);
extern void func_0202208C(void *,u32,u32,u32,u32,u32,u32);
extern struct Struct_02025CD0 *func_02025CD0(u32 a0, u32 a1, u32 a2, u32 a3, u8 a4, u16 heapId);
extern u32 func_02025D14(void *a0);
extern void func_020061E4(u32 a);
extern void *func_0202616C(void **obj, unsigned int idx);
extern void func_0204B404(struct Obj *p, const struct Vec2 *delta, u32 which);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern void func_0201EFA4(struct WordSet *, u32, u32, u32, u32, u32);
extern void func_0201F048(struct WordSet *p, u32 i, u32 n);
extern void func_0201F094(struct WordSet *p, u32 i, u32 a, u32 n);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern void func_02045994(struct Strbuf *o, const u16 *src, u32 len);
extern void *func_0202435C(void *slots, unsigned int heap);
extern void func_02045808(struct U16Vec *vec);
extern void func_02041B6C(u32);
extern int func_02035C08(const void *key);
extern unsigned func_020362DC(void);
extern void func_0204B878(struct Obj *p, u16 value);
extern void func_0204B3DC(struct Obj *p, unsigned int v);
extern u8 func_020260E0(struct Sound *obj);
extern void func_021BA520(u8 *a0, int a1, void *a2, int a3);
extern void func_0202CC70(struct WinMgr *mgr, u32 idx);
void func_021B9B44(Obj_021B9B44 *o);
void func_021B9BF0(char *p);
void func_021B9C44(Obj_021B9C44 *o);
void func_021B9CD8(u8 *p);
void func_021B9D08(u8 *p);
void func_021B9DE8(u8 *p);
void func_021B9DFC(unsigned char *p);
int func_021B9E44(u8 *p);
int func_021B9E5C(u8 *p);
int func_021B9E74(char *o);
int func_021B9EC0(u8 *p);
int func_021B9EDC(u8 *p);
int func_021B9F08(char *p);
void func_021B9F24(char *p);
int func_021B9F58(char *p);
void func_021B9F68(void);
void func_021B9F6C(void);
void func_021B9F70(char *p, int i);
void func_021B9F9C(char *p, int i);
void func_021B9FC8(char *p, int i);
void func_021B9FF0(char *p, struct Rec *tbl, int idx);
int func_021BA2A4(char *p);
void func_021BA2D8(char *o, int k);
void func_021BA350(char *p);
void func_021BA384(char *o, int i, int n);
int func_021BA400(char *p, int k);
void func_021BA438(char *p, int i);
int func_021BA470(int a, int b, int c);
void func_021BA480(Obj *o);
extern const Ent_021B9B44 d_021BA6BC[];
extern Ent_021B9C44 *d_021BA874[];
extern Callback d_021BA860[];
extern const char d_021BA71C[], d_021BA5EC[];
extern const char d_021BA5FC[];



/*
 * Creates four sprites from a const 6-word template table (x, y, z, then
 * three resource-slot indices).  The table must be `const`: a non-const
 * table lets the stores into the stack record alias it, and the index loads
 * are then scheduled after the stack-argument stores (42 bytes of DIFF).
 * Twin: ov111_func_021C75E4.
 */
void func_021B9B44(Obj_021B9B44 *o)
{
    int i;
    SlotParam r;

    for (i = 0; i < 4; i++) {
        r.a = d_021BA6BC[i].a;
        r.b = d_021BA6BC[i].b;
        r.c = d_021BA6BC[i].c;
        r.e = 0;
        r.d = 0;
        o->slot[i] = (int)func_0204B294((void *)o->f11C, o->arr[d_021BA6BC[i].d], o->arr[d_021BA6BC[i].e], o->arr[d_021BA6BC[i].f], &r, 0, 0x80);
        func_0204B92C((struct Obj_021B9B44 *)o->slot[i], 1);
    }
}



void func_021B9BF0(char *p)
{
    func_0204A8D4(((struct Obj01132 *)p)->f144);
    func_0204ADA4(((struct Obj01132 *)p)->f140);
    func_0204AFD8(((struct Obj01132 *)p)->f148);
    func_0204A8D4(((struct Obj01132 *)p)->f138);
    func_0204ADA4(((struct Obj01132 *)p)->f134);
    func_0204AFD8(((struct Obj01132 *)p)->f13C);
    func_0204B1CC((struct Bank *)(((struct Obj01132 *)p)->f120));
    func_0204B1CC((struct Bank *)(((struct Obj01132 *)p)->f11C));
    func_0204A5AC();
}



void func_021B9C44(Obj_021B9C44 *o)
{
    int i;
    int j;
    int h;
    Ent_021B9C44 *e;

    func_02045088(0x80);
    for (i = 0; i < 8; i++) {
        e = d_021BA874[i];
        o->a[i] = (int)func_020450F0((u8)e->f0, (int)e->f4, (int)e->f5, (int)e->f6, (int)e->f7, e->f8, (int)1);
        func_02043B5C((struct CharBuf *)((int)func_02045770((struct Descriptor *)o->a[i])), 0);
        h = o->a[i];
        func_02045334((struct Descriptor *)h);
        func_02045374((struct Cfg *)h);
        func_020409B4(func_02045730((struct Descriptor *)h));
    }
    for (j = 0; j < 10; j++) {
        o->b[j] = (int)func_020450F0((u8)1, (int)2, (int)1, (int)10, (int)2, 1, (int)1);
        func_02043B5C((struct CharBuf *)((int)func_02045770((struct Descriptor *)o->b[j])), 4);
    }
}


/*
 * extent: final two bytes are alignment padding before next labelled function.
 */
void func_021B9CD8(u8 *p) { int i; for(i=0;i<10;i++) func_020452E8(*(void **)(p+i*4+0x10)); for(i=0;i<8;i++) func_020452E8(*(void **)(p+i*4+0x38)); func_020450C8(); }



void func_021B9D08(u8 *p)
{
    int i;
    u32 h;

    ((struct Obj01133 *)p)->fC = func_0201D7EC(0x17, 0, 0, 0, 0x80);
    ((struct Obj01133 *)p)->fE8 = (void *)func_0201C440((void *)0x80);
    for (i = 0; i < 18; i++) {
        *(int *)(p + i * 8 + 0x58) = *(int *)(p + i * 4 + 0x10);
        p[i * 8 + 0x5C] = 0;
    }
    h = *(u32 *)&((struct Obj01133 *)p)->fE8;
    func_0201C724((void *)h, (int)func_02045770((struct Descriptor *)((struct Obj01133 *)p)->fA8), 0, 0,
                  ((struct Obj01133 *)p)->f100, *(u32 *)&((struct Obj01133 *)p)->fC, 0x3DC0);
    p[0xAC] = 1;
    h = *(u32 *)&((struct Obj01133 *)p)->fE8;
    func_0201C724((void *)h, (int)func_02045770((struct Descriptor *)((struct Obj01133 *)p)->fC8), 0, 0,
                  ((struct Obj01133 *)p)->f10C, *(u32 *)&((struct Obj01133 *)p)->fC, 0x3DC0);
    p[0xCC] = 1;
    h = *(u32 *)&((struct Obj01133 *)p)->fE8;
    func_0201C724((void *)h, (int)func_02045770((struct Descriptor *)((struct Obj01133 *)p)->fD8), 0, 0,
                  ((struct Obj01133 *)p)->f118, *(u32 *)&((struct Obj01133 *)p)->fC, 0x3DC0);
    p[0xDC] = 1;
}


void func_021B9DE8(u8 *p) { func_0201C4C0(((struct Obj01132 *)p)->fE8); func_0201D83C(((struct Obj01132 *)p)->fC); }



void func_021B9DFC(unsigned char *p)
{
    int i;
    int h;

    func_0201C4E4((struct PrintSys *)(((struct Obj06172 *)p)->fE8));
    for (i = 0; i < 18; i++) {
        h = ((struct Obj06172 *)p)->fE8;
        if (p[i * 8 + 0x5C] != 0) {
            if (func_0201C6C4((struct PrintSys *)h, (void *)((int)func_02045770((struct Descriptor *)*(int *)(p + i * 8 + 0x58)))) == 0) {
                func_02045334((struct Descriptor *)*(int *)(p + i * 8 + 0x58));
                p[i * 8 + 0x5C] = 0;
            }
        }
    }
}


int func_021B9E44(u8 *p) { return d_021BA860[*(int *)(p+0x158)](p); }


int func_021B9E5C(u8 *p) { if (func_020221A4()) ((struct Obj20656 *)p)->f158=1; return 1; }



int func_021B9E74(char *o)
{
    int v;

    if (func_0201C6B4((const struct PrintSys *)(((struct Obj00432 *)o)->fE8)) == 0)
        return 1;
    if (func_021BA2A4(o) == -1) {
        v = func_02025D2C((struct Sound *)(*(int *)&((struct Obj00432 *)o)->f14C));
        if (v == -6)
            func_021BA2D8(o, 0);
        else if (v == -5)
            func_021BA2D8(o, 1);
    }
    return 1;
}


int func_021B9EC0(u8 *p) { if (func_0204B98C(((struct Obj13147 *)p)->f128)==0) ((struct Obj13147 *)p)->f158=3; return 1; }


int func_021B9EDC(u8 *p) { func_0202208C(0,0,0,0,16,1,128); ((struct Obj20657 *)p)->f158=4; return 1; }


/*
 * extent: Two bytes of alignment padding follow.
 */
int func_021B9F08(char *p)
{
    if (func_020221A4()) {
        ((struct Obj20658 *)p)->f158 = 0;
        return 0;
    }
    return 1;
}


void func_021B9F24(char *p)
{
    ((struct Obj09876 *)p)->f14C = func_02025CD0((u32)d_021BA71C, (u32)d_021BA5EC, (u32)p, 1, 0, 0x80);
    func_021B9FC8(p, 0);
}


/*
 * evidence: 02025D14 forwards r0 to 02030164, whose body reads the pointer
 * and returns a predicate; its legacy void(void) declaration is incomplete.
 */
int func_021B9F58(char *p)
{
    return func_02025D14(((struct Obj01132 *)p)->f14C);
}


void func_021B9F68(void) {}


void func_021B9F6C(void) {}


void func_021B9F70(char *p, int i)
{
    func_021B9FF0(p, ((struct Obj13148 *)p)->f8, (int)((unsigned)i + (unsigned)((struct Obj13148 *)p)->f160 * 10u));
    func_021B9FC8(p, i);
    func_020061E4(0x548);
}


void func_021B9F9C(char *p, int i)
{
    func_021B9FF0(p, ((struct Obj13149 *)p)->f8, (int)((unsigned)i + (unsigned)((struct Obj13149 *)p)->f160 * 10u));
    func_021B9FC8(p, i);
    func_020061E4(0x548);
}


void func_021B9FC8(char *p, int i)
{
    Point pt;
    u8 *v;
    v = func_0202616C(((struct Obj09876 *)p)->f14C, i);
    pt.x = v[0];
    pt.y = v[1];
    func_0204B404(((struct Obj09876 *)p)->f124, (const struct Vec2 *)(&pt), 0);
}


void func_021B9FF0(char *p, struct Rec *tbl, int idx)
{
    u32 a;
    u32 b;
    struct Rec *rec;
    char *name;
    int off;
    struct U16Vec *vec;
    struct Descriptor *d;
    int n;
    off = idx * 0x22;
    rec = &tbl[idx];
    a = rec->a;
    b = rec->b;
    name = (char *)rec + 0x18;
    vec = func_020457B0(0x10, 0x80);
    func_0201EFA4(*(struct WordSet **)(p + 0xF8), 0, *(u32 *)(*(char **)(p + 0x154) + 4), 2, 0, 1);
    func_0201EFA4(*(struct WordSet **)(p + 0xF8), 1, *(u32 *)(*(char **)(p + 0x154) + 8), 3, 0, 1);
    func_0201F048(*(struct WordSet **)(p + 0xF8), 2, a);
    func_0201F094(*(struct WordSet **)(p + 0xF8), 3, a, b);
    func_02043B5C(func_02045770(*(struct Descriptor **)(p + 0x3C)), 0);
    func_02043B5C(func_02045770(*(struct Descriptor **)(p + 0x40)), 0);
    func_02043B5C(func_02045770(*(struct Descriptor **)(p + 0x44)), 0);
    func_02043B5C(func_02045770(*(struct Descriptor **)(p + 0x4C)), 0);
    func_02043B5C(func_02045770(*(struct Descriptor **)(p + 0x54)), 0);
    if (idx < *(int *)(p + 0x164)) {
        void *ws;
        void *str;
        n = 8;
        func_02045994((struct Strbuf *)vec, (const u16 *)((char *)tbl + off), n);
        ws = *(void **)(p + 0xE8);
        func_0201C724(ws, (u32)func_02045770(*(struct Descriptor **)(p + 0xC0)), 0, 0, (u32)vec, (u32)(*(void **)(p + 0xC)), 0x3DC0);
        *(u8 *)(p + 0xC4) = 1;
        func_0201F250(*(struct WordSet **)(p + 0xF8), *(void **)(p + 0xFC), *(void **)(p + n + 0xFC));
        ws = *(void **)(p + 0xE8);
        func_0201C724(ws, (u32)func_02045770(*(struct Descriptor **)(p + 0xB0)), 0, 0, (u32)(*(void **)(p + 0xFC)), (u32)(*(void **)(p + 0xC)), 0x3DC0);
        *(u8 *)(p + 0xB4) = 1;
        func_0201F250(*(struct WordSet **)(p + 0xF8), *(void **)(p + 0xFC), *(void **)(p + 0x108));
        ws = *(void **)(p + 0xE8);
        func_0201C724(ws, (u32)func_02045770(*(struct Descriptor **)(p + 0xB8)), 0, 0, (u32)(*(void **)(p + 0xFC)), (u32)(*(void **)(p + 0xC)), 0x3DC0);
        *(u8 *)(p + 0xBC) = 1;
        func_0201F250(*(struct WordSet **)(p + 0xF8), *(void **)(p + 0xFC), *(void **)(p + 0x110));
        ws = *(void **)(p + 0xE8);
        func_0201C724(ws, (u32)func_02045770(*(struct Descriptor **)(p + 0xD0)), 0, 0, (u32)(*(void **)(p + 0xFC)), (u32)(*(void **)(p + 0xC)), 0x3DC0);
        *(u8 *)(p + 0xD4) = 1;
        func_0201F250(*(struct WordSet **)(p + 0xF8), *(void **)(p + 0xFC), *(void **)(p + 0x114));
        ws = *(void **)(p + 0xE8);
        func_0201C724(ws, (u32)func_02045770(*(struct Descriptor **)(p + 0xD0)), 0, 0x10, (u32)(*(void **)(p + 0xFC)), (u32)(*(void **)(p + 0xC)), 0x3DC0);
        *(u8 *)(p + 0xD4) = 1;
        str = func_0202435C((void *)name, 0x80);
        ws = *(void **)(p + 0xE8);
        func_0201C724(ws, (u32)func_02045770(*(struct Descriptor **)(p + 0xE0)), 0, 0, (u32)str, (u32)(*(void **)(p + 0xC)), 0x3DC0);
        *(u8 *)(p + 0xE4) = 1;
        func_02045808((struct U16Vec *)str);
    } else {
        d = *(struct Descriptor **)(p + 0x44);
        func_02045334(d); func_02045374((struct Cfg *)d); func_02041B6C(func_02045730(d));
        d = *(struct Descriptor **)(p + 0x4C);
        func_02045334(d); func_02045374((struct Cfg *)d); func_02041B6C(func_02045730(d));
        d = *(struct Descriptor **)(p + 0x54);
        func_02045334(d); func_02045374((struct Cfg *)d); func_02041B6C(func_02045730(d));
    }
    func_02045808(vec);
}


int func_021BA2A4(char *p)
{
    int k;
    k = func_02035C08(d_021BA5FC);
    if (func_020362DC() & 2) {
        func_020061E4(0x551);
        k = 2;
    }
    func_021BA2D8(p, k);
    return k;
}



void func_021BA2D8(char *o, int k)
{
    switch (k) {
    case 0:
        if (func_021BA400(o, k) != 0) {
            func_020061E4(0x548);
            func_0204B878((struct Obj *)(((struct Obj00432 *)o)->f12C), 12);
            func_021BA438(o, ((struct Obj00432 *)o)->f160);
        }
        break;
    case 1:
        if (func_021BA400(o, k) != 0) {
            func_020061E4(0x548);
            func_0204B878((struct Obj *)(((struct Obj00432 *)o)->f130), 13);
            func_021BA438(o, ((struct Obj00432 *)o)->f160);
        }
        break;
    case 2:
        ((struct Obj00432 *)o)->f158 = 2;
        func_0204B878((struct Obj *)(((struct Obj00432 *)o)->f128), 9);
        break;
    }
}


void func_021BA350(char *p)
{
    ((struct Obj06173 *)p)->f160 = 0;
    ((struct Obj06173 *)p)->f162 = ((struct Obj06173 *)p)->f164 / 10;
    if (((struct Obj06173 *)p)->f164 % 10 != 0)
        (((struct Obj06173 *)p)->f162)++;
}



void func_021BA384(char *o, int i, int n)
{
    if (n == 1) {
        func_0204B3DC((struct Obj *)((struct Obj03659 *)o)->f12C, 0);
        func_0204B3DC((struct Obj *)((struct Obj03659 *)o)->f130, 0);
    } else if (i == 0) {
        func_0204B3DC((struct Obj *)((struct Obj03659 *)o)->f12C, 0);
        func_0204B3DC((struct Obj *)((struct Obj03659 *)o)->f130, 1);
    } else if (i != 0 && i < n - 1) {
        func_0204B3DC((struct Obj *)((struct Obj03659 *)o)->f12C, 1);
        func_0204B3DC((struct Obj *)((struct Obj03659 *)o)->f130, 1);
    } else if (i == n - 1) {
        func_0204B3DC((struct Obj *)((struct Obj03659 *)o)->f12C, 1);
        func_0204B3DC((struct Obj *)((struct Obj03659 *)o)->f130, 0);
    }
}


int func_021BA400(char *p, int k)
{
    int result = 0;
    if (k == 0) {
        if (((struct Obj00432 *)p)->f160 != 0) {
            ((struct Obj00432 *)p)->f160 = ((struct Obj00432 *)p)->f160 - 1;
            result = 1;
        }
    } else if (k == 1) {
        if (((struct Obj00432 *)p)->f160 < ((struct Obj00432 *)p)->f162 - 1) {
            ((struct Obj00432 *)p)->f160 = ((struct Obj00432 *)p)->f160 + 1;
            result = 1;
        }
    }
    return result;
}


/*
 * extent: Two bytes of alignment padding follow.
 * lever: Inline the getter result into the sum; a named result reverses
 * the final adds operands (one concrete byte).
 */
void func_021BA438(char *p, int i)
{
    ((struct Obj00432 *)p)->f160 = i;
    func_021BA384(p, i, ((struct Obj00432 *)p)->f162);
    func_021BA480((struct Obj *)p);
    func_021B9FF0(p, ((struct Obj00432 *)p)->f8, ((struct Obj00432 *)p)->f160 * 10 + func_020260E0(((struct Obj00432 *)p)->f14C));
}


/*
 * Unlabelled leaf: remaining count after a - 10 per page, capped at 10.
 */
int func_021BA470(int a, int b, int c)
{
    int r = c - a * 10;

    if (r > 10)
        r = 10;
    return r;
}



void func_021BA480(Obj *o)
{
    void *buf;
    int n;
    int i;

    buf = func_020457B0(0x10, 0x80);
    n = func_021BA470(o->page, o->f162, o->f164);
    i = 0;
    if (n > 0) {
        do {
            func_02045994(buf, (const u16 *)(o->f8 + (i + o->page * 10) * 0x22), 8);
            func_021BA520((u8 *)o, i, buf, ((Ent *)(o->f8 + (i + o->page * 10) * 0x22))->f1);
            i++;
        } while (i < n);
    }
    for (; i < 10; i++)
        func_0202CC70(o->f4, i);
    func_02045808(buf);
}
