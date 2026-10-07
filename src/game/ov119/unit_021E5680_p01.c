/*
 * file:     unit_021E5680_p01.c
 * unit:     yes
 * function: func_021E5680, func_021E57A4, func_021E57E8, func_021E57FC, func_021E5868, func_021E58A0, func_021E5958, func_021E5998, func_021E5B6C, func_021E5BE4
 * address:  0x021E5680
 * region:   ov119
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0203FCA0 0x0203FCA0 arm
 *   func_02040C14 0x02040C14 arm
 *   func_02041300 0x02041300 arm
 *   func_020409B4 0x020409B4 arm
 *   d_021E7EE4 0x021E7EE4 data a4
 *   d_021E7F04 0x021E7F04 data a4
 *   d_021E7F64 0x021E7F64 data a4
 *   d_021E7E04 0x021E7E04 data a4
 *   func_02040DA8 0x02040DA8 arm
 *   func_020403F4 0x020403F4 arm
 *   func_0203FC28 0x0203FC28 arm
 *   d_021E7D20 0x021E7D20 data a4
 *   func_020490F4 0x020490F4 arm
 *   func_0204A6C8 0x0204A6C8 arm
 *   func_0204AC18 0x0204AC18 arm
 *   func_0204AF28 0x0204AF28 arm
 *   func_02049238 0x02049238 arm
 *   func_0204A8D4 0x0204A8D4 arm
 *   func_0204ADA4 0x0204ADA4 arm
 *   func_0204AFD8 0x0204AFD8 arm
 *   func_0204B294 0x0204B294 arm
 *   func_0204B92C 0x0204B92C arm
 *   func_0204B3DC 0x0204B3DC arm
 *   func_02049990 0x02049990 arm
 *   func_020355C4 0x020355C4 arm
 *   func_021D8FA4 0x021D8FA4 thumb ov119
 *   func_020185F4 0x020185F4 thumb
 *   func_0201BA68 0x0201BA68 thumb
 *   func_0201BBE8 0x0201BBE8 thumb
 *   func_0204B6F4 0x0204B6F4 arm
 *   func_0204B404 0x0204B404 arm
 *   func_0204B3B4  0x0204B3B4  arm
 */
#include "../../matched/include/Obj00001.h"
#include "../../matched/include/Obj03782.h"
#include "../../matched/include/Obj04483.h"
#include "../../matched/include/Obj00252.h"
#include "../../matched/include/Obj10381.h"
#include "../../matched/include/Obj00285.h"
#include "../../matched/include/Obj08073.h"

struct DispConfig;
struct Obj;
struct Vec2;
typedef unsigned int u32;

typedef unsigned char u8;

typedef struct BgTemplate { u32 a,b,bufSize,d; u8 e,f,g,h; u32 i; u8 j,k,l,m; u32 n; } BgTemplate;

typedef unsigned short u16;

typedef signed int     s32;

typedef struct { u16 x, y, z; u8 a, b; } Sprite;

typedef struct { u16 x, y, prio; u8 pal, mode; } ObjTmpl;

typedef struct { u16 x, y; } Pos;

extern void func_0203FCA0(u32,const BgTemplate *,u32);
extern void func_02040C14(u32,u32,u32,u32),func_02041300(u32,int,int,int,u8,u8,u8),func_020409B4(u32);
extern void func_02040DA8(u32 idx, u32 count, u32 tile);
extern void func_020403F4(u32 i);
extern void func_0203FC28(struct DispConfig *cfg);
extern void *func_020490F4(unsigned int id, unsigned int heap);
extern s32 func_0204A6C8(void *a, u32 b, u32 c, u32 a3, u16 flags);
extern s32 func_0204AC18(void *a, u32 b, u32 c, u32 d, u16 e, u16 f, u16 g);
extern s32 func_0204AF28(void *owner, u32 first, u32 second, u32 mode);
extern void func_02049238(void *);
extern void func_0204A8D4(u32 i);
extern void func_0204ADA4(u32 i);
extern void func_0204AFD8(u32 i);
extern struct Obj *func_0204B294(void *, unsigned int, unsigned int, unsigned int, const void *, u16, u16);
extern void func_0204B92C(struct Obj *p, u32 v);
extern void func_0204B3DC(struct Obj *p, unsigned int v);
extern u32 func_02049990(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u16 a7);
extern u8 func_020355C4(void);
extern void *func_021D8FA4(void *p, int a);
extern void *func_020185F4(void *a);
extern u32 func_0201BA68(void *mon);
extern int func_0201BBE8(void *);
extern void func_0204B6F4(struct Obj *o, u32 v, u32 flag);
extern void func_0204B404(struct Obj *p, const struct Vec2 *delta, u32 which);
extern void func_0204B3B4(struct Obj *p);
void func_021E5680(char *p);
void func_021E57A4(int p);
void func_021E57E8(int i);
void func_021E57FC(int p);
void func_021E5868(char *p);
void func_021E58A0(int p);
void func_021E5958(int p);
void func_021E5998(char *p);
void func_021E5B6C(int p, int b, int c);
void func_021E5BE4(int a);
extern const BgTemplate d_021E7EE4,d_021E7F04,d_021E7F64,d_021E7E04;
extern const char d_021E7D20[];

void func_021E5680(char *p)
{
 BgTemplate a,b,c,d;
 a=d_021E7EE4;func_0203FCA0(4,&a,0);func_02041300(4,0,0,0,32,24,17);
 b=d_021E7F04;func_0203FCA0(5,&b,0);func_02040C14(5,0,1,0);func_02041300(5,0,0,0,32,24,17);func_020409B4(5);
 c=d_021E7F64;func_0203FCA0(7,&c,0);func_02041300(7,0,0,0,64,24,17);func_020409B4(7);
 d=d_021E7E04;func_0203FCA0(6,&d,0);func_02040C14(6,0,1,0);func_02041300(6,0,0,0,32,24,17);func_020409B4(6);
 p[0x11eb]=1;
}

void func_021E57A4(int p)
{
    if (((struct Obj00001 *)p)->f11EB == 1) {
        func_02040DA8(4, 1, 0);
        func_02040DA8(6, 1, 0);
        func_020403F4(4);
        func_020403F4(5);
        func_020403F4(6);
        func_020403F4(7);
        ((struct Obj00001 *)p)->f11EB = 0;
    }
}

void func_021E57E8(int i)
{
    func_0203FC28((struct DispConfig *)(d_021E7D20 + i * 16));
}

void func_021E57FC(int p)
{
    void *a;
    if (((struct Obj03782 *)p)->f898 == 0) {
        a = func_020490F4(0x66, ((struct Obj03782 *)p)->f5F4);
        ((struct Obj03782 *)p)->f898 = func_0204A6C8(a, 0x15, 0, 0, ((struct Obj03782 *)p)->f5F4);
        ((struct Obj03782 *)p)->f884 = func_0204AC18(a, 0x12, 0, 0xc0, 0, 6, ((struct Obj03782 *)p)->f5F4);
        ((struct Obj03782 *)p)->f8B4 = func_0204AF28(a, 0x14, 0x13, ((struct Obj03782 *)p)->f5F4);
        func_02049238(a);
    }
}

void func_021E5868(char *p)
{
    if (((struct Obj04483 *)p)->f898 != 0) {
        func_0204A8D4(((struct Obj04483 *)p)->f898);
        func_0204ADA4(((struct Obj04483 *)p)->f884);
        func_0204AFD8(((struct Obj04483 *)p)->f8B4);
        ((struct Obj04483 *)p)->f898 = 0;
        ((struct Obj04483 *)p)->f884 = 0;
        ((struct Obj04483 *)p)->f8B4 = 0;
    }
}

void func_021E58A0(int p)
{
    void *a;
    Sprite s;
    a = func_020490F4(0x66, ((struct Obj00252 *)p)->f5F4);
    *(int *)&((struct Obj00252 *)p)->f894 = func_0204A6C8(a, 0x18, 0, 1, ((struct Obj00252 *)p)->f5F4);
    *(int *)&((struct Obj00252 *)p)->f880 = func_0204AC18(a, 0x12, 1, 0xc0, 0, 6, ((struct Obj00252 *)p)->f5F4);
    *(int *)&((struct Obj00252 *)p)->f8B0 = func_0204AF28(a, 0x17, 0x16, ((struct Obj00252 *)p)->f5F4);
    func_02049238(a);
    s.x = 0x80; s.y = 0xb4; s.z = 2; s.a = 0xe; s.b = 0;
    ((struct Obj00252 *)p)->fF04 = (int)func_0204B294((void *)*(int *)&((struct Obj00252 *)p)->f9C4, *(int *)&((struct Obj00252 *)p)->f894, *(int *)&((struct Obj00252 *)p)->f880, *(int *)&((struct Obj00252 *)p)->f8B0, &s, 1, ((struct Obj00252 *)p)->f5F4);
    func_0204B92C((struct Obj *)((struct Obj00252 *)p)->fF04, 0);
    func_0204B3DC((struct Obj *)((struct Obj00252 *)p)->fF04, 1);
}

void func_021E5958(int p)
{
    void *a = func_020490F4(0x66, ((struct Obj10381 *)p)->f5F4);
    func_02049990(a, (int)0x1d, (int)2, (int)0, (u16)(((struct Obj10381 *)p)->f86C), (int)0, (int)0, ((struct Obj10381 *)p)->f5F4);
    func_02049238(a);
}

void func_021E5998(char *p)
{
    void *arc;
    void *a, *b;
    int z;
    ObjTmpl u, t;
    u.x = 0x80;
    u.y = 0x10;
    u.prio = 0x13;
    u.pal = 0xe;
    u.mode = 1;
    ((struct Obj00285 *)p)->fF08 = func_0204B294(((struct Obj00285 *)p)->f9C4, (unsigned int)((struct Obj00285 *)p)->f894, (unsigned int)((struct Obj00285 *)p)->f880,
        (unsigned int)((struct Obj00285 *)p)->f8B0, &u, 1, ((struct Obj00285 *)p)->f5F4);
    func_0204B92C(((struct Obj00285 *)p)->fF08, 1);
    func_0204B3DC(((struct Obj00285 *)p)->fF08, 1);
    u.x = 0x60;
    u.y = 0x10;
    u.prio = 0;
    u.pal = 0xb;
    u.mode = 1;
    ((struct Obj00285 *)p)->fF0C = func_0204B294(((struct Obj00285 *)p)->f9C4, (unsigned int)((struct Obj00285 *)p)->f894, (unsigned int)((struct Obj00285 *)p)->f880,
        (unsigned int)((struct Obj00285 *)p)->f8B0, &u, 1, ((struct Obj00285 *)p)->f5F4);
    func_0204B92C(((struct Obj00285 *)p)->fF0C, 1);
    if (func_020355C4()) {
        func_0204B3DC(((struct Obj00285 *)p)->fF0C, 0);
    }
    arc = func_020490F4(7, ((struct Obj00285 *)p)->f5F4);
    z = 0;
    a = func_020185F4(func_021D8FA4(p, 0));
    b = func_020185F4(func_021D8FA4(p, 1));
    ((struct Obj00285 *)p)->f89C = (void *)func_0204A6C8(arc, func_0201BA68(a), z, 1, ((struct Obj00285 *)p)->f5F4);
    ((struct Obj00285 *)p)->f8A0 = (void *)func_0204A6C8(arc, func_0201BA68(b), z, 1, ((struct Obj00285 *)p)->f5F4);
    t.x = 0x60;
    t.y = 0xc;
    t.prio = z;
    t.pal = 0xc;
    t.mode = 1;
    ((struct Obj00285 *)p)->fF10 = func_0204B294(((struct Obj00285 *)p)->f9C4, (unsigned int)((struct Obj00285 *)p)->f89C, (unsigned int)((struct Obj00285 *)p)->f87C,
        (unsigned int)((struct Obj00285 *)p)->f8AC, &t, 1, ((struct Obj00285 *)p)->f5F4);
    func_0204B92C(((struct Obj00285 *)p)->fF10, 0);
    func_0204B3DC(((struct Obj00285 *)p)->fF10, 1);
    func_0204B6F4(((struct Obj00285 *)p)->fF10, func_0201BBE8(a), 1);
    t.x = 0xa0;
    ((struct Obj00285 *)p)->fF14 = func_0204B294(((struct Obj00285 *)p)->f9C4, (unsigned int)((struct Obj00285 *)p)->f8A0, (unsigned int)((struct Obj00285 *)p)->f87C,
        (unsigned int)((struct Obj00285 *)p)->f8AC, &t, 1, ((struct Obj00285 *)p)->f5F4);
    func_0204B92C(((struct Obj00285 *)p)->fF14, 0);
    func_0204B3DC(((struct Obj00285 *)p)->fF14, 1);
    func_0204B6F4(((struct Obj00285 *)p)->fF14, func_0201BBE8(b), 1);
    func_02049238(arc);
}

/*
 * lever: first y ternary is b == 0 ? 8 : 12 to retain branch polarity.
 */
void func_021E5B6C(int p, int b, int c)
{
    Pos pos;
    if (c) {
        pos.x = 96; pos.y = 12;
        func_0204B404((struct Obj *)(((struct Obj08073 *)p)->fF10), (const struct Vec2 *)(&pos), 1);
        pos.x = 160; pos.y = 12;
        func_0204B404((struct Obj *)(((struct Obj08073 *)p)->fF14), (const struct Vec2 *)(&pos), 1);
    } else {
        pos.x = 96; pos.y = b == 0 ? 8 : 12;
        func_0204B404((struct Obj *)(((struct Obj08073 *)p)->fF10), (const struct Vec2 *)(&pos), 1);
        pos.x = 160; pos.y = b ? 8 : 12;
        func_0204B404((struct Obj *)(((struct Obj08073 *)p)->fF14), (const struct Vec2 *)(&pos), 1);
    }
}


void func_021E5BE4(int a)
{
    if (((struct Obj00001 *)a)->fF08 != 0)
        func_0204B3B4((struct Obj *)(((struct Obj00001 *)a)->fF08));
    if (((struct Obj00001 *)a)->fF0C != 0)
        func_0204B3B4((struct Obj *)(((struct Obj00001 *)a)->fF0C));
    if (((struct Obj00001 *)a)->fF10 != 0)
        func_0204B3B4((struct Obj *)(((struct Obj00001 *)a)->fF10));
    if (((struct Obj00001 *)a)->fF14 != 0)
        func_0204B3B4((struct Obj *)(((struct Obj00001 *)a)->fF14));
    ((struct Obj00001 *)a)->fF08 = 0;
    ((struct Obj00001 *)a)->fF0C = 0;
    ((struct Obj00001 *)a)->fF10 = 0;
    ((struct Obj00001 *)a)->fF14 = 0;
    if (((struct Obj00001 *)a)->f89C != 0)
        func_0204A8D4(((struct Obj00001 *)a)->f89C);
    if (((struct Obj00001 *)a)->f8A0 != 0)
        func_0204A8D4(((struct Obj00001 *)a)->f8A0);
    ((struct Obj00001 *)a)->f89C = 0;
    ((struct Obj00001 *)a)->f8A0 = 0;
}
