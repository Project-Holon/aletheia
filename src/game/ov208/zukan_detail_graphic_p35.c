/*
 * file:     zukan_detail_graphic_p35.c
 * unit:     yes
 * function: func_021C2C1C, func_021C2C44, func_021C2D88, func_021C2DE0, func_021C2E6C, func_021C2FEC, func_021C301C
 * address:  0x021C2C1C
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_020490F4  0x020490F4  arm
 *   func_0204AC18  0x0204AC18  arm
 *   func_0204A6C8  0x0204A6C8  arm
 *   func_0204AF28  0x0204AF28  arm
 *   func_02049238  0x02049238  arm
 *   func_02082BCC  0x02082BCC  arm
 *   func_0204B294  0x0204B294  arm
 *   func_0204B3DC  0x0204B3DC  arm
 *   func_0204B688  0x0204B688  arm
 *   func_0204B92C  0x0204B92C  arm
 *   data_021C8704  0x021C8704  data
 *   func_0204B3B4 0x0204B3B4 arm
 *   func_0204ADA4 0x0204ADA4 arm
 *   func_0204A8D4 0x0204A8D4 arm
 *   func_0204AFD8 0x0204AFD8 arm
 *   func_0204B908 0x0204B908 arm
 *   data_021C86EC 0x021C86EC data ov208 a1
 *   func_021BC3C0 0x021BC3C0 thumb ov208
 *   func_021BC3A4 0x021BC3A4 thumb ov208
 *   func_021BC738 0x021BC738 thumb ov208
 *   func_0204B324 0x0204B324 arm
 *   func_0202D7C8 0x0202D7C8 thumb
 *   func_0202D81C 0x0202D81C thumb
 *   func_0202D7D8 0x0202D7D8 thumb
 *   func_0202D898 0x0202D898 thumb
 *   func_0202D060 0x0202D060 thumb
 *   func_0202D0D4 0x0202D0D4 thumb
 *   func_0204B454 0x0204B454 arm
 *   func_0204B5C0 0x0204B5C0 arm
 *   func_0204B404 0x0204B404 arm
 *   func_0204B5AC 0x0204B5AC arm
 *   _fflt 0x0209BDBC arm
 *   _fdiv 0x0209CE10 arm
 *   _fadd 0x0209C95C arm
 *   _fsub 0x0209CB8C arm
 *   _fmul 0x0209C77C arm
 *   _ffix 0x0209C494 arm
 *   _fgr 0x0209BBB0 arm
 *   _fleq 0x0209BC0C arm
 *   _fgeq 0x0209BB54 arm
 */
#include "../../matched/include/Obj00146.h"
#include "../../matched/include/Obj05541.h"
#include "../../matched/include/Obj10906.h"

#define OBJ(p) (*(void **)((p) + *(int *)((p) + 0x5c) * 4 + 0x54))
struct Actor;
struct Obj;
struct Blk37;
struct Ov208Gfx;
struct PtS;
struct Vec2;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed short   s16;

typedef signed int     s32;

typedef struct {
    u16 a;
    u16 b;
    u16 c;
    u8 d;
    u8 e;
} ObjPos;

struct S_021C2C44 {
    u32 f0;
    u8 pad4[0x80];
    int a84[6];
    u32 a9c[7];
};

struct Indices { u8 v[4]; };

struct Tail {u32 s0,s1,s2,s3,s4;u16 key,pad;};

struct Args {u32 w0,w1,w2,w3;u16 key,pad;};

struct Desc {u16 x,y,z;u8 a,b;u16 c,d;u32 sx,sy;u16 e,f;};

struct S_021C2FEC {
    u8 pad[0x3c];
    u32 a3c[2];
    u32 a44[2];
    u32 a4c[2];
    u32 a54[2];
};

struct Pos { s16 x; s16 y; };

struct Pair { int x; int y; };

extern int func_02005E50(void);
extern void func_02005DE4(void *p);
extern int func_02005E64(void);
extern void *func_020490F4(u32 id, u32 heap);
extern s32 func_0204AC18(void *a, u32 b, u32 c, u32 d, u16 e, u16 f, u16 g);
extern s32 func_0204A6C8(void *a, u32 b, u32 c, u32 a3, u16 flags);
extern s32 func_0204AF28(void *owner, u32 first, u32 second, u32 mode);
extern void func_02049238(int a);
extern void func_02082BCC(void *dst, int v, u32 n);
extern struct Obj *func_0204B294(void *owner, u32 i, u32 j, u32 k, const void *position, u16 f, u16 g);
extern void func_0204B3DC(struct Obj *p, u32 v);
extern void func_0204B688(struct Actor *actor, u32 value);
extern void func_0204B92C(struct Obj *p, u32 v);
extern void func_0204B3B4(struct Obj *p);
extern void func_0204ADA4(u32 i);
extern void func_0204A8D4(u32 i);
extern void func_0204AFD8(u32 i);
extern void func_0204B908(int a0, int a1);
extern u16 func_021BC3C0(int);
extern int func_021BC3A4(int *p);
extern void *func_0200CA1C(void *a);
extern void func_0200CC40(void *,u32,u32 *,u32 *,u32 *,u16);
extern u32 func_0200D288(struct Blk37 *p, u32 which);
extern int func_0202D7C8(int a0);
extern u32 func_0202D81C(u32,u32,u32,u32,u32,u32,u32,u32,u32,u16);
extern int func_0202D7D8(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, unsigned short a8, unsigned short a9);
extern u32 func_0202D898(u32,u32,u32,u32,u32,u32,u32,u32,u16);
extern int func_0202D060(void);
extern s32 func_0202D0D4(u32 a0, u32 a1, u32 a2, u32 a3, u32 s5, u32 s6, u32 s7);
extern void func_021BC738(struct Ov208Gfx *p, u32 a, u32 b, u32 c, u32 d, u32 e, u16 f, u16 g);
extern struct Obj *func_0204B324(u32 owner, u32 i, u32 j, u32 k, u32 e, u16 f, u16 g);
extern void func_0204B454(struct Actor *actor, struct PtS *out, u16 space);
extern void func_0204B5C0(const struct Obj *o, struct Pair *p);
extern void func_0204B404(struct Obj *p, const struct Vec2 *delta, u32 which);
extern void func_0204B5AC(struct Obj *dst, struct Pair *src);
void func_021C2C1C(int unused, char *p, int a2);
void func_021C2C44(u16 *heap, struct S_021C2C44 *st, int a2);
void func_021C2D88(void *unused, u8 *p, void *a2);
void func_021C2DE0(void *unused,u8 *p,void *unused2,int first,u16 second);
void func_021C2E6C(u16 *heap,u8 *p,int key,u32 slot);
void func_021C2FEC(void *unused, struct S_021C2FEC *p, u32 unused2, u32 i);
void ov208_func_021C301C(u16 *heap, u8 *p, int key);
extern const u8 data_021C8704[7][9];
extern const struct Indices data_021C86EC;


/*
 * Moves the object at +0xB8 from state 1 to state 2.
 */
void func_021C2C1C(int unused, char *p, int a2)
{
    if (((struct Obj00146 *)p)->fB8 == 1) {
        if (func_02005E50() == 0) {
            func_02005DE4((void *)1);
            func_02005E64();
            ((struct Obj00146 *)p)->fB8 = 2;
        }
    }
}


/*
 * note: 2026-10-05 (wave D4 lane 02): the loop back edge in the image goes to the memset call,
 *         so the memset is the first statement of the loop body. The loop-invariant &pos
 *         (add r7, sp, #0x10) is then hoisted into the preheader, before the call.
 */
void func_021C2C44(u16 *heap, struct S_021C2C44 *st, int a2)
{
    int arc;
    u8 i;
    ObjPos pos;

    arc = (int)func_020490F4(0x9f, *heap);
    i = 0;
    st->a84[1] = func_0204AC18((void *)arc, 3, 0, 0, 0, 4, *heap);
    st->a84[0] = func_0204A6C8((void *)arc, 0xd, 0, 0, *heap);
    st->a84[2] = func_0204AF28((void *)arc, 0x1b, 0x2c, *heap);
    st->a84[4] = func_0204AC18((void *)arc, 8, 1, 0x40, 0, 1, *heap);
    st->a84[3] = func_0204A6C8((void *)arc, 0x18, 0, 1, *heap);
    st->a84[5] = func_0204AF28((void *)arc, 0x1e, 0x2f, *heap);
    func_02049238(arc);
    do {
        const u8 *e;
        func_02082BCC(&pos, 0, 8);
        e = data_021C8704[i];
        pos.a = e[0];
        pos.b = e[1];
        pos.c = e[2];
        pos.d = e[3];
        pos.e = e[4];
        st->a9c[i] = (u32)func_0204B294((void *)st->f0, st->a84[e[5]], st->a84[e[6]], st->a84[e[7]], &pos, e[8], *heap);
        func_0204B3DC((struct Obj *)st->a9c[i], 1);
        func_0204B688((struct Actor *)st->a9c[i], 1);
        i++;
    } while (i < 7);
    func_0204B92C((struct Obj *)st->a9c[6], 1);
}

void func_021C2D88(void *unused, u8 *p, void *a2)
{
    u8 i;
    for (i = 0; i < 7; i++)
        func_0204B3B4(*(struct Obj **)(p + i * 4 + 0x9c));
    func_0204ADA4(((struct Obj05541 *)p)->f88);
    func_0204A8D4(((struct Obj05541 *)p)->f84);
    func_0204AFD8(((struct Obj05541 *)p)->f8C);
    func_0204ADA4(((struct Obj05541 *)p)->f94);
    func_0204A8D4(((struct Obj05541 *)p)->f90);
    func_0204AFD8(((struct Obj05541 *)p)->f98);
}

void func_021C2DE0(void *unused,u8 *p,void *unused2,int first,u16 second)
{
    struct Indices ids;
    u16 digits[4];
    u8 i;
    ids=data_021C86EC;
    digits[0]=first/10;
    if(digits[0]>9)digits[0]=9;
    digits[1]=first%10;
    digits[2]=second/10;
    if(digits[2]>9)digits[2]=9;
    digits[3]=second%10;
    for(i=0;i<4;i++)
        func_0204B908((int)(*(struct Obj **)(p+ids.v[i]*4+0x9c)),digits[i]);
}

void func_021C2E6C(u16 *heap,u8 *p,int key,u32 slot)
{
    struct Desc desc;
    u32 form,b,a;
    u32 arc,special,species;
    void *ctx;
    species=func_021BC3C0(key);
    special=0;
    ctx=func_0200CA1C((void *)func_021BC3A4((int *)key));
    func_0200CC40(ctx,species,&form,&b,&a,*heap);
    if(species==327)special=func_0200D288(ctx,special);
    arc=func_0202D7C8(*heap);
    *(u32 *)((u32)p+0x44+slot*4)=func_0202D81C(arc,species,a,form,b,0,0,special,1,*heap);
    *(u32 *)((u32)p+0x3c+slot*4)=func_0202D7D8(arc,species,a,form,b,0,0,1,(u16)(slot<<5),*heap);
    *(u32 *)((u32)p+0x4c+slot*4)=func_0202D898(species,a,form,b,0,0,2,1,*heap);
    func_021BC738(((struct Obj00146 *)p)->fC8,arc,func_0202D0D4(func_0202D060(),species,a,form,b,0,0),*heap,3,32,(u16)(slot<<4),0);
    func_02049238(arc);
    func_02082BCC(&desc,0,24);
    desc.x=128;desc.y=128;desc.z=0;desc.a=0;desc.b=0;desc.c=0;desc.d=0;
    desc.sx=4096;desc.sy=4096;desc.e=0;desc.f=2;
    *(u32 *)((u32)p+0x54+slot*4)=(u32)func_0204B324(((struct Obj00146 *)p)->f0,*(u32 *)((u32)p+0x44+slot*4),*(u32 *)((u32)p+0x3c+slot*4),*(u32 *)((u32)p+0x4c+slot*4),(u32)(&desc),1,*heap);
    func_0204B688((struct Actor *)(*(u32 *)((u32)p+0x54+slot*4)),0);
    ((struct Obj00146 *)p)->f60=0;
}


void func_021C2FEC(void *unused, struct S_021C2FEC *p, u32 unused2, u32 i)
{
    if (p->a54[i] != 0) {
        func_0204B3B4((struct Obj *)p->a54[i]);
        p->a54[i] = 0;
        func_0204ADA4(p->a3c[i]);
        func_0204A8D4(p->a44[i]);
        func_0204AFD8(p->a4c[i]);
    }
}


void ov208_func_021C301C(u16 *heap, u8 *p, int key)
{
    struct Pos pos;
    struct Pair sc;
    float f;
    switch (((struct Obj10906 *)p)->f60) {
    case 0:
    case 2:
        break;
    case 1:
        func_0204B454(OBJ(p), (struct PtS *)&pos, 1);
        func_0204B5C0(OBJ(p), &sc);
        f = (float)sc.y / 4096.0f;
        f += 0.01f;
        if (f >= 1.1f) {
            f = 1.1f;
            ((struct Obj10906 *)p)->f60 = 2;
        }
        pos.y = 0x80 - (int)(96.0f * (f - 1.0f) / 2.0f);
        if (f > 0.0f)
            sc.y = (int)(4096.0f * f + 0.5f);
        else
            sc.y = (int)(4096.0f * f - 0.5f);
        func_0204B404(OBJ(p), (const struct Vec2 *)(&pos), 1);
        func_0204B5AC(OBJ(p), &sc);
        break;
    case 3:
        func_0204B454(OBJ(p), (struct PtS *)&pos, 1);
        func_0204B5C0(OBJ(p), &sc);
        f = (float)sc.y / 4096.0f - 0.01f;
        if (f <= 1.0f) {
            f = 1.0f;
            ((struct Obj10906 *)p)->f60 = 0;
            pos.y = 0x80;
        } else {
            pos.y = 0x80 - (int)(96.0f * (f - 1.0f) / 2.0f);
        }
        if (f > 0.0f)
            sc.y = (int)(4096.0f * f + 0.5f);
        else
            sc.y = (int)(4096.0f * f - 0.5f);
        func_0204B404(OBJ(p), (const struct Vec2 *)(&pos), 1);
        func_0204B5AC(OBJ(p), &sc);
        break;
    }
}
