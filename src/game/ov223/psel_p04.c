/*
 * file:     psel_p04.c
 * unit:     yes
 * function: func_021B9C90, func_021B9D4C, func_021B9D9C, func_021BA050, func_021BA0AC, func_021BA2B4, func_021BA81C, func_021BA878
 * address:  0x021B9C90
 * region:   ov223
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02048A18 0x02048A18 arm
 *   func_0204779C 0x0204779C arm
 *   func_020477D4 0x020477D4 arm
 *   func_020477A4 0x020477A4 arm
 *   func_0204784C 0x0204784C arm
 *   func_0204B908 0x0204B908 arm
 *   func_02047910 0x02047910 arm
 *   ids 0x021BC710 data a2
 *   banks 0x021BC6FC data a1
 *   motion 0x021BC7F0 data a1
 *   files 0x021BC73C data a1
 *   func_0202D7C8 0x0202D7C8 thumb
 *   func_0202D81C 0x0202D81C thumb
 *   func_0202D7D8 0x0202D7D8 thumb
 *   func_0202D898 0x0202D898 thumb
 *   func_02049238 0x02049238 arm
 *   func_02082BCC 0x02082BCC arm
 *   func_021BC520 0x021BC520 thumb
 *   func_0204B294 0x0204B294 arm
 *   func_0204B324 0x0204B324 arm
 *   func_0204B3DC 0x0204B3DC arm
 *   func_020490F4 0x020490F4 arm
 *   func_0204A6C8 0x0204A6C8 arm
 *   func_0204AF28 0x0204AF28 arm
 *   _fgr 0x0209BBB0 arm
 *   _ffltu 0x0209BE04 arm
 *   _ffix 0x0209C494 arm
 *   _fmul 0x0209C77C arm
 *   _fadd 0x0209C95C arm
 *   _fsub 0x0209CB8C arm
 *   _fdiv 0x0209CE10 arm
 *   func_0204B3B4 0x0204B3B4 arm
 *   func_0204AFD8 0x0204AFD8 arm
 *   func_0204A8D4 0x0204A8D4 arm
 *   func_0204ADA4 0x0204ADA4 arm
 *   func_0204B404 0x0204B404 arm
 *   func_0204B5AC 0x0204B5AC arm
 *   func_0204B454 0x0204B454 arm
 *   func_0204B800 0x0204B800 arm
 *   func_0204B84C 0x0204B84C arm
 *   d_021BC7F0 0x021BC7F0 data
 *   d_021BC8C0 0x021BC8C0 data ov223
 *   func_021BB974 0x021BB974 thumb
 *   func_0204B688 0x0204B688 arm
 *   func_0207D63C 0x0207D63C arm
 */
#include "../../matched/include/Obj02938.h"
#include "../../matched/include/Obj00738.h"
#include "../../matched/include/Obj00211.h"
#include "../../matched/include/Obj01595.h"
#include "../../matched/include/Obj10980.h"
#include "../../matched/include/Obj10981.h"
#include "../../matched/include/Obj26089.h"

#define FIX(x) ((int)(((x)>0)?((x)*4096.0f+.5f):((x)*4096.0f-.5f)))
struct AnmCtl;
struct G3dSys;
struct Owner;
struct Obj;
struct Pair;
struct Actor;
struct Node;
struct PtS;
typedef unsigned short u16;

typedef unsigned char  u8;

typedef signed int     s32;

typedef unsigned int   u32;

struct Request {u16 x,y,z;u8 a,b;};

struct Desc {u16 x,y,z;u8 a,b;u16 c,d;u32 sx,sy;u16 e,f;};

typedef struct {u8 b[14];} Motion;

typedef struct {u8 b[5];} Files;

typedef signed short s16;

typedef struct Vec2 { s16 x, y; } Vec2;

typedef struct FxPair { int x, y; } FxPair;

typedef struct Entry {
    u8 pad0[0x18];
    struct Obj *f18;
    struct Obj *f1C;
    u8 pad20[0x84 - 0x20];
    u16 f84;
    u16 pad86;
    u32 f88;
    int f8C;
    int f90;
} Entry;

typedef struct Main {
    u8 pad0[0x54];
    Entry ents[3];
    u8 pad210[0x230 - 0x210];
    int f230;
} Main;

extern unsigned int func_02048A18(u8 *a0, int i);
extern int func_0204779C(int *p);
extern int func_020477D4(struct Owner *owner, u32 index);
extern u32 func_020477A4(struct G3dSys *sys, u32 idx);
extern u32 func_0204784C(struct AnmCtl *c, u16 idx, s32 *frame);
/* B908 reads only r0, forwarding its live r1 to D478; legacy r2/r3 unused. */
extern void func_0204B908(int a0, int a1);
extern int func_02047910(void *,int,int);
extern int func_0202D7C8(int a0);
extern u32 func_0202D81C(u32,u32,u32,u32,u32,u32,u32,u32,u32,u16);
extern u32 func_0202D7D8(u32,u32,u32,u32,u32,u32,u32,u32,u16,u16);
extern u32 func_0202D898(u32,u32,u32,u32,u32,u32,u32,u32,u16);
extern void func_02049238(u32);
extern void func_02082BCC(void *,int,u32);
extern unsigned func_021BC520(unsigned char *p);
extern struct Obj *func_0204B294(void *, unsigned int, unsigned int, unsigned int, const void *, unsigned short, unsigned short);
extern struct Obj *func_0204B324(u32 owner, u32 i, u32 j, u32 k, u32 e, u16 f, u16 g);
extern void func_0204B3DC(struct Obj *,unsigned int);
extern void *func_020490F4(u32 id, u32 heap);
extern s32 func_0204A6C8(void *a, u32 b, u32 c, u32 a3, u16 flags);
extern s32 func_0204AF28(void *owner, u32 first, u32 second, u32 mode);
extern void func_0204B3B4(struct Obj *p);
extern void func_0204AFD8(unsigned);
extern void func_0204A8D4(unsigned);
extern void func_0204ADA4(unsigned);
extern void func_0204B404(struct Obj *, const Vec2 *, u32);
extern void func_0204B5AC(struct Obj *dst, struct Pair *src);
extern void func_0204B454(struct Actor *actor, struct PtS *out, u16 space);
extern void func_0204B800(struct Node *node, u32 val);
extern void func_0204B84C(struct Obj *, u32);
extern void func_021BB974(unsigned char *p, unsigned index, int cmd);
extern void func_0204B688(struct Actor *actor, u32 value);
extern void func_0207D63C(unsigned,int,int,int,int);
void func_021B9C90(char *p,unsigned next);
void func_021B9D4C(char *p);
void func_021B9D9C(char *p);
void func_021BA050(char *p);
int func_021BA0AC(s16 *pos,int *size,u16 a,u16 b,u8 c,u8 d,u8 e,u8 f,u32 duration,u8 amplitude,u32 time);
void func_021BA2B4(Main *p);
void func_021BA81C(char *p,unsigned selected);
void func_021BA878(char *p);
int func_021BA8BC(char *p);
extern const u16 ids[];
extern const u8 banks[];
extern const Motion motion[];
extern const Files files[];
extern const u8 d_021BC7F0[3][14];
extern const u8 d_021BC8C0[3];

void func_021B9C90(char *p,unsigned next)
{
    void *object;
    unsigned count;
    u16 i;
    int frame;
    if(((struct Obj02938 *)p)->f22C!=4 && ((struct Obj02938 *)p)->f22C!=next) {
        object=(void *)func_02048A18(((struct Obj02938 *)p)->f28,*(u16 *)(*(char * *)&((struct Obj02938 *)p)->f3C+68*(*(u16 *)(p+48+2*(((struct Obj02938 *)p)->f22C+2)))));
        count=func_0204779C(object);
        for(i=0;i<count;i++) func_020477D4(object,i);
    }
    if(next!=4 && ((struct Obj02938 *)p)->f22C!=next) {
        object=(void *)func_02048A18(((struct Obj02938 *)p)->f28,*(u16 *)(*(char * *)&((struct Obj02938 *)p)->f3C+68*(*(u16 *)(p+48+2*(next+2)))));
        count=func_0204779C(object);
        frame=0;
        for(i=0;i<count;i++) {
            func_020477A4(object,i);
            func_0204784C(object,i,&frame);
        }
        func_0204B908((int)(((struct Obj02938 *)p)->f224),0);
    }
    ((struct Obj02938 *)p)->f22C=next;
}

void func_021B9D4C(char *p)
{
    void *object;
    unsigned count;
    u16 i;
    if(((struct Obj00738 *)p)->f22C!=4) {
        object=(void *)func_02048A18(((struct Obj00738 *)p)->f28,*(u16 *)(*(char * *)&((struct Obj00738 *)p)->f3C+68*(*(u16 *)(p+48+2*(((struct Obj00738 *)p)->f22C+2)))));
        count=func_0204779C(object);
        for(i=0;i<count;i++) func_02047910(object,i,2048);
    }
}

/*
 * lever: bind the file table record before the sprite record to reproduce their address scheduling.
 */
void func_021B9D9C(char *p)
{
    struct Desc desc;
    struct Request request;
    u32 arc,other,id;
    char *r;
    const Files *f;
    u8 i,j;
    arc=func_0202D7C8(((struct Obj00211 *)p)->f0);
    for(i=0;i<3;i++) {
        id=ids[i];r=p+i*148;
        ((struct Obj01595 *)r)->f54=func_0202D81C(arc,id,0,0,0,0,0,0,1,((struct Obj00211 *)p)->f0);
        ((struct Obj01595 *)r)->f58=func_0202D7D8(arc,id,0,0,0,0,0,1,(u16)(banks[i]<<5),((struct Obj00211 *)p)->f0);
        ((struct Obj01595 *)r)->f5C=func_0202D898(id,0,0,0,0,0,0,1,((struct Obj00211 *)p)->f0);
    }
    func_02049238(arc);
    for(j=0;j<3;j++) {
        func_02082BCC(&request,0,8);
        request.x=motion[j].b[0];request.y=motion[j].b[1];request.z=0;request.a=2;request.b=3;
        r=p+j*148;
        ((struct Obj01595 *)r)->f6C=(u32)func_0204B294((void *)func_021BC520(((struct Obj00211 *)p)->f14),((struct Obj01595 *)r)->f54,((struct Obj01595 *)r)->f58,((struct Obj01595 *)r)->f5C,&request,1,((struct Obj00211 *)p)->f0);
        func_0204B3DC((struct Obj *)((struct Obj01595 *)r)->f6C,0);
    }
    other=(u32)func_020490F4(205,((struct Obj00211 *)p)->f0);
    for(i=0;i<3;i++) {
        f=files+i;
        r=p+i*148;
        ((struct Obj01595 *)r)->f60=func_0204A6C8((void *)other,f->b[0],0,1,((struct Obj00211 *)p)->f0);
        ((struct Obj01595 *)r)->f68=func_0204AF28((void *)other,f->b[2],f->b[3],((struct Obj00211 *)p)->f0);
    }
    func_02049238(other);
    for(j=0;j<3;j++) {
        func_02082BCC(&desc,0,24);
        desc.x=motion[j].b[0];desc.y=motion[j].b[1];desc.z=0;desc.a=2;desc.b=3;desc.c=0;desc.d=0;
        desc.sx=FIX((float)motion[j].b[6]/16.0f);desc.sy=FIX((float)motion[j].b[6]/16.0f);
        desc.e=0;desc.f=1;
        r=p+j*148;
        ((struct Obj01595 *)r)->f70=(unsigned int)func_0204B324(func_021BC520(((struct Obj00211 *)p)->f14),((struct Obj01595 *)r)->f60,((struct Obj01595 *)r)->f58,((struct Obj01595 *)r)->f68,(u32)(&desc),1,((struct Obj00211 *)p)->f0);
        func_0204B3DC((struct Obj *)((struct Obj01595 *)r)->f70,0);
    }
    for(i=0;i<3;i++) {
        *(u16 *)(p+i*148+216)=0;
        *(u32 *)(p+i*148+220)=0;
        *(u32 *)(p+i*148+224)=0;
        *(u32 *)(p+i*148+228)=0;
    }
    ((struct Obj00211 *)p)->f210=0;((struct Obj00211 *)p)->f214=0;
}

void func_021BA050(char *p)
{
    u8 i,j;
    char *row,*entry;
    for(i=0;i<3;i++) {
        row=p+i*148;
        for(j=0;j<2;j++) {
            func_0204B3B4(*(void **)(row+108+j*4));
            entry=row+j*12;
            func_0204AFD8(((struct Obj10980 *)entry)->f5C);
            func_0204A8D4(((struct Obj10980 *)entry)->f54);
            if(j!=1) func_0204ADA4(((struct Obj10980 *)entry)->f58);
        }
    }
}

int func_021BA0AC(s16 *pos,int *size,u16 a,u16 b,u8 c,u8 d,u8 e,u8 f,u32 duration,u8 amplitude,u32 time)
{
    float x,y,arc,scale;
    s16 px,py,result;
    int fixed;
    x=(float)a+(float)time*((float)c-(float)a)/(float)duration;
    y=(float)b+(float)time*((float)d-(float)b)/(float)duration;
    arc=4.0f*((0.0f-(float)amplitude)*((float)time-(float)duration/2.0f)*((float)time-(float)duration/2.0f))/(float)duration/(float)duration+(float)amplitude;
    scale=(float)e+(float)time*((float)f-(float)e)/(float)duration;
    px=(s16)x;
    py=(s16)(y-arc);
    fixed=FIX(scale/16.0f);
    pos[0]=px;pos[1]=py;
    size[0]=size[1]=fixed;
    result=(s16)y;
    return result;
}

void func_021BA2B4(Main *p)
{
    int flags[3] = {0, 0, 0};
    s16 res[3];
    u8 i;
    for (i = 0; i < 3; i++) {
        Entry *e = &p->ents[i];
        const u8 *t = d_021BC7F0[i];
        int d = 0;
        if (e->f8C == 0)
            continue;
        switch (e->f8C) {
        case 0: break;
        case 1: d = 1; break;
        case 2: d = -1; break;
        }
        if (d < 0) {
            e->f84 = 0;
            e->f88 = 1;
        }
        switch (e->f88) {
        case 0:
            if (d > 0) {
                func_0204B3DC(e->f18, 0);
                func_0204B3DC(e->f1C, 1);
                e->f84 = 0;
                e->f88 = 1;
                e->f90 = 0;
            } else {
                if (e->f8C == 2)
                    e->f8C = 0;
                break;
            }
        case 1:
            if (e->f84 == 0) {
                Vec2 v1;
                FxPair s1;
                u8 n1;
                v1.x = t[0];
                v1.y = t[1];
                n1 = t[6];
                s1.x = s1.y = FIX((float)n1 / 16.0f);
                func_0204B404(e->f1C, &v1, 1);
                func_0204B5AC(e->f1C, (struct Pair *)(&s1));
            } else {
                Vec2 a1;
                FxPair b1;
                res[i] = func_021BA0AC((s16 *)(&a1), (int *)(&b1), t[0], t[1], t[2], t[3], t[6], t[7], t[10], t[12], e->f84);
                flags[i] = 1;
                func_0204B404(e->f1C, &a1, 1);
                func_0204B5AC(e->f1C, (struct Pair *)(&b1));
            }
            if (e->f84 == 0 && d < 0) {
                func_0204B3DC(e->f18, 1);
                func_0204B3DC(e->f1C, 0);
                e->f84 = 0;
                e->f88 = 0;
                e->f90 = 0;
                break;
            }
            e->f84 = e->f84 + d;
            e->f90 = 0;
            if (e->f84 == t[10]) {
                e->f84 = 0;
                e->f88 = 2;
            }
            break;
        case 2: {
            Vec2 v2;
            FxPair s2;
            u8 n2;
            v2.x = t[2];
            v2.y = t[3];
            n2 = t[7];
            s2.x = s2.y = FIX((float)n2 / 16.0f);
            func_0204B404(e->f1C, &v2, 1);
            func_0204B5AC(e->f1C, (struct Pair *)(&s2));
            if (e->f84 == 0 && d < 0) {
                e->f84 = t[10] - 1;
                e->f88 = 1;
                e->f90 = 0;
                break;
            }
            e->f84 = e->f84 + d;
            e->f90 = 0;
            if (e->f84 == t[9]) {
                e->f84 = 0;
                e->f88 = 3;
            }
            break;
        }
        case 3:
            if (e->f84 == 0) {
                Vec2 v3;
                FxPair s3;
                u8 n3;
                v3.x = t[2];
                v3.y = t[3];
                n3 = t[7];
                s3.x = s3.y = FIX((float)n3 / 16.0f);
                func_0204B404(e->f1C, &v3, 1);
                func_0204B5AC(e->f1C, (struct Pair *)(&s3));
            } else {
                Vec2 a3;
                FxPair b3;
                res[i] = func_021BA0AC((s16 *)(&a3), (int *)(&b3), t[2], t[3], t[4], t[5], t[7], t[8], t[11], t[13], e->f84);
                flags[i] = 1;
                func_0204B404(e->f1C, &a3, 1);
                func_0204B5AC(e->f1C, (struct Pair *)(&b3));
            }
            if (e->f84 == 0 && d < 0) {
                e->f84 = t[9] - 1;
                e->f88 = 2;
                e->f90 = 0;
                break;
            }
            e->f84 = e->f84 + d;
            e->f90 = 0;
            if (e->f84 == t[11]) {
                e->f84 = 0;
                e->f88 = 4;
            }
            break;
        case 4: {
            Vec2 v4;
            FxPair s4;
            u8 n4;
            v4.x = t[4];
            v4.y = t[5];
            n4 = t[8];
            s4.x = s4.y = FIX((float)n4 / 16.0f);
            func_0204B404(e->f1C, &v4, 1);
            func_0204B5AC(e->f1C, (struct Pair *)(&s4));
            if (d < 0) {
                func_0204B84C(e->f1C, 3);
                e->f84 = t[11] - 1;
                e->f88 = 3;
                e->f90 = 0;
                break;
            }
            if (e->f8C == 1) {
                func_0204B84C(e->f1C, 2);
                e->f8C = 0;
                if (e->f90 == 0)
                    p->f230 = 1;
            }
            break;
        }
        }
    }
    {
    u8 order[3];
    s16 z[3];
    Vec2 pos;
    u8 j;
    order[0] = d_021BC8C0[0];
    order[1] = d_021BC8C0[1];
    order[2] = d_021BC8C0[2];
    for (i = 0; i < 3; i++) {
        if (flags[i]) {
            z[i] = res[i];
        } else {
            func_0204B454((struct Actor *)p->ents[i].f1C, (struct PtS *)(&pos), 1);
            z[i] = pos.y;
        }
    }
    for (i = 0; i < 3; i++) {
        for (j = 2; j > i; j--) {
            u8 a = order[j - 1];
            u8 b = order[j];
            if (z[b] > z[a]) {
                order[j - 1] = b;
                order[j] = a;
            }
        }
    }
    for (i = 0; i < 3; i++) {
        u32 pr;
        if (order[0] == i)
            pr = 0;
        else {
            pr = 1;
            if (order[1] != i)
                pr = 2;
        }
        func_0204B800((struct Node *)p->ents[i].f1C, pr);
    }
    }
}

void func_021BA81C(char *p,unsigned selected)
{
    u8 i;
    for(i=0;i<3;i++) {
        if(i==selected) func_021BB974((unsigned char *)p,i,0); else func_021BB974((unsigned char *)p,i,2);
        if(i==selected) {
            *(unsigned *)(p+i*148+224)=1;
            *(unsigned *)(p+i*148+228)=1;
        } else {
            *(unsigned *)(p+i*148+224)=2;
            *(unsigned *)(p+i*148+228)=1;
        }
    }
}

void func_021BA878(char *p)
{
    u8 i;
    int alpha;
    for(i=0;i<3;i++) func_0204B688(*(void **)(p+i*148+108),1);
    ((struct Obj10981 *)p)->f210=0;
    ((struct Obj10981 *)p)->f214=1;
    alpha=((struct Obj10981 *)p)->f210;
    func_0207D63C(0x04001050,0,63,alpha,16-alpha);
}

int func_021BA8BC(char *p)
{
    if(((struct Obj26089 *)p)->f214==0) return 1;
    return 0;
}
