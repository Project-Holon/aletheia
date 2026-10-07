/*
 * file:     unit_021B9B44_p01.c
 * unit:     yes
 * function: func_021B9B44, func_021B9BF0, func_021B9C44, func_021B9CD8, func_021B9D08, func_021B9DE8, func_021B9DFC, func_021B9E44, func_021B9E5C, func_021B9E74, func_021B9EC0, func_021B9EDC, func_021B9F08
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
 *   func_021BA2A4  0x021BA2A4  thumb  ov069
 *   func_02025D2C  0x02025D2C  thumb
 *   func_021BA2D8  0x021BA2D8  thumb  ov069
 *   func_0204B98C 0x0204B98C arm
 *   func_0202208C 0x0202208C thumb
 */
#include "../../matched/include/Obj01132.h"
#include "../../matched/include/Obj01133.h"
#include "../../matched/include/Obj06172.h"
#include "../../matched/include/Obj20656.h"
#include "../../matched/include/Obj00432.h"
#include "../../matched/include/Obj13147.h"
#include "../../matched/include/Obj20657.h"
#include "../../matched/include/Obj20658.h"

struct Obj_021B9B44;
struct Bank;
struct Descriptor;
struct Cfg;
struct CharBuf;
struct GfFont;
struct PrintSys;
struct Sound;
struct Actor;
typedef unsigned char u8;

typedef short s16;

typedef struct Ent_021B9B44 {
    int a, b, c;
    int d, e, f;
} Ent_021B9B44;

typedef struct Rec {
    s16 a, b, c;
    u8 d, e;
} Rec;

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
extern int func_021BA2A4(char *p);
extern int func_02025D2C(struct Sound *obj);
extern void func_021BA2D8(char *o, int k);
extern u32 func_0204B98C(struct Actor *a);
extern void func_0202208C(void *,u32,u32,u32,u32,u32,u32);
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
extern const Ent_021B9B44 d_021BA6BC[];
extern Ent_021B9C44 *d_021BA874[];
extern Callback d_021BA860[];


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
    Rec r;

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
