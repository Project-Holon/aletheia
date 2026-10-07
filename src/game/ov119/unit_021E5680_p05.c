/*
 * file:     unit_021E5680_p05.c
 * unit:     yes
 * function: func_021E6790, func_021E67A8, func_021E67C4, func_021E67E0, func_021E68B4, func_021E68F4, func_021E69A4, func_021E69C0, func_021E6AB0, func_021E6B90
 * address:  0x021E6790
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
 *   func_0204B3DC 0x0204B3DC arm
 *   func_0204B3B4 0x0204B3B4 arm
 *   func_0204B878 0x0204B878 arm
 *   func_0204B294 0x0204B294 arm
 *   func_0204B92C 0x0204B92C arm
 *   func_0204B404 0x0204B404 arm
 *   d_021E7DEC 0x021E7DEC data a2
 *   func_0204B454 0x0204B454 arm
 *   func_02040618 0x02040618 arm
 *   func_0204B84C 0x0204B84C arm
 *   func_0204047C 0x0204047C arm
 *   func_0201F5DC 0x0201F5DC thumb
 *   func_020490F4 0x020490F4 arm
 *   func_02049740 0x02049740 arm
 *   func_02049990 0x02049990 arm
 *   func_020403F4 0x020403F4 arm
 *   func_0203FCA0 0x0203FCA0 arm
 *   func_02049238 0x02049238 arm
 *   func_020435F4 0x020435F4 arm
 *   d_021E7E44 0x021E7E44 data a4
 */
#include "../../matched/include/Obj00001.h"
#include "../../matched/include/Obj05337.h"
#include "../../matched/include/Obj22816.h"

struct Obj;
struct Vec2;
struct Actor;
struct PtS;
typedef unsigned short u16;

typedef unsigned char u8;

typedef struct { short x,y,z; u8 a,b; } Create;

typedef struct {
    char pad0[0x5f4];
    u16 heap;
    char pad1[0x884-0x5f6];
    int g884;
    char pad2[0x898-0x888];
    int g898;
    char pad3[0x8b4-0x89c];
    int g8b4;
    char pad4[0x9c4-0x8b8];
    int g9c4;
    char pad5[0x10ac-0x9c8];
    int slot[8];
} Work;

typedef struct { short x,y; } Pt;

typedef struct { Pt pos[6]; } Table;

typedef unsigned int   u32;

struct BgTemplate {
    u32 w[8];
};

extern void func_0204B3DC(struct Obj *p, unsigned int v);
extern void func_0204B3B4(struct Obj *p);
extern void func_0204B878(struct Obj *p, u16 value);
extern struct Obj *func_0204B294(void *,unsigned int,unsigned int,unsigned int,const void *,unsigned short,unsigned short);
extern void func_0204B92C(struct Obj *,unsigned int);
extern void func_0204B404(struct Obj *p, const struct Vec2 *delta, u32 which);
extern void func_0204B454(struct Actor *actor, struct PtS *out, u16 space);
extern void func_02040618(u32 layer, u32 a, u32 b);
extern void func_0204B84C(void *,unsigned int);
extern void func_0204047C(int,unsigned short);
extern void *func_0201F5DC(void *a0, u32 a1, u32 a2, u32 a3);
extern void *func_020490F4(u32 id, u32 heap);
extern u32 func_02049740(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u16 flags);
extern void func_02049990(void *, u32, u32, u32, u16, u32, u32, u16);
extern void func_020403F4(u32 i);
extern void func_0203FCA0(u32 bgId, const struct BgTemplate *tmpl, u32 type);
extern void func_02049238(void *);
extern void func_020435F4(u32 planes);
void func_021E6790(void *p, int i, int a);
void func_021E67A8(void *p, int i);
void func_021E67C4(void *p, int i);
void func_021E67E0(Work *p, int z, int i);
void func_021E68B4(int p, int n);
void func_021E68F4(int p, int i);
void func_021E69A4(char *p);
int func_021E69C0(char *p);
void func_021E6AB0(const char *p);
void func_021E6B90(char *p);
extern const Table d_021E7DEC;
extern const struct BgTemplate d_021E7E44;


void func_021E6790(void *p, int i, int a)
{
    func_0204B3DC((struct Obj *)*(int *)((char *)p + i * 4 + 0x10bc), a);
}


void func_021E67A8(void *p, int i)
{
    if (*(int *)((char *)p + 0x10bc + i * 4)) {
        func_0204B3B4((struct Obj *)(*(int *)((char *)p + 0x10bc + i * 4)));
        *(int *)((char *)p + 0x10bc + i * 4) = 0;
    }
}


void func_021E67C4(void *p, int i)
{
    func_0204B878((struct Obj *)(*(int *)((char *)p + i * 4 + 0x10bc)), (u16)(i + 15));
}

void func_021E67E0(Work *p, int z, int i) {
    Create c;
    c.x=i*206+8; c.y=160; c.z=4; c.a=1; c.b=0;
    if (!p->slot[i*2]) {
        p->slot[i*2]=(int)func_0204B294((void *)p->g9c4,p->g898,p->g884,p->g8b4,&c,0,p->heap);
        func_0204B92C((struct Obj *)p->slot[i*2],1);
        func_0204B3DC((struct Obj *)p->slot[i*2],1);
    } else {
        func_0204B3DC((struct Obj *)p->slot[i*2],1);
    }
    if (!p->slot[i*2+1]) {
        c.a=0; c.z=z;
        p->slot[i*2+1]=(int)func_0204B294((void *)p->g9c4,p->g898,p->g884,p->g8b4,&c,0,p->heap);
        func_0204B92C((struct Obj *)p->slot[i*2+1],1);
        func_0204B3DC((struct Obj *)p->slot[i*2+1],1);
    } else {
        func_0204B878((struct Obj *)p->slot[i*2+1],z);
    }
}

static inline void clear(int p, int i) {
    if (*(int *)(p+i*4+0x10ac)) {
        func_0204B3B4((struct Obj *)(*(int *)(p+i*4+0x10ac)));
        *(int *)(p+(unsigned int)i*4+0x10ac)=0;
    }
}

/*
 * lever: unsigned cast on the store index prevents address CSE with the signed read index; without it 56 bytes, 37 byte DIFF.
 */
void func_021E68B4(int p, int n) {
    int i=n*2;
    clear(p,i+1);
    clear(p,i);
}

void func_021E68F4(int p, int i) {
    Table t=d_021E7DEC;
    Create c;
    if(i==-1) {
        if(((struct Obj00001 *)p)->fFD4) func_0204B3DC((struct Obj *)((struct Obj00001 *)p)->fFD4,0);
    } else {
        if(!((struct Obj00001 *)p)->fFD4) {
            c.x=64;c.y=48;c.z=23;c.a=0;c.b=1;
            ((struct Obj00001 *)p)->fFD4=(int)func_0204B294((void *)((struct Obj00001 *)p)->f9C4,((struct Obj00001 *)p)->f894,((struct Obj00001 *)p)->f880,((struct Obj00001 *)p)->f8B0,&c,1,((struct Obj00001 *)p)->f5F4);
        }
        func_0204B92C((struct Obj *)((struct Obj00001 *)p)->fFD4,1);
        func_0204B3DC((struct Obj *)((struct Obj00001 *)p)->fFD4,1);
        func_0204B404((struct Obj *)(((struct Obj00001 *)p)->fFD4),(const struct Vec2 *)(&t.pos[i]),1);
    }
}


void func_021E69A4(char *p)
{
    if (((struct Obj00001 *)p)->fFD4) {
        func_0204B3B4((struct Obj *)(((struct Obj00001 *)p)->fFD4));
        ((struct Obj00001 *)p)->fFD4 = 0;
    }
}

/*
 * output: 0204B454 writes both halfwords via 0204B53C and 0204CF74/0204B0C8.
 * interface: 02040618 forwards legacy r3 only to 02042360, whose full body
 *            has three inputs and does not read it; caller supplies r0-r2.
 */
int func_021E69C0(char *p)
{
    Pt a,b,c;
    int i;
    if(((struct Obj05337 *)p)->f11DE<128) ((struct Obj05337 *)p)->f11DE+=4;
    else return 1;
    for(i=0;i<8;i++) {
        func_0204B454(*(void **)(p+i*4+0x10cc),(struct PtS *)&a,1);
        if(i/4) a.x+=4; else a.x-=4;
        func_0204B404(*(void **)(p+i*4+0x10cc),(const struct Vec2 *)(&a),1);
    }
    for(i=0;i<3;i++) {
        if(*(void **)(p+i*4+0x1008)) {
            func_0204B454(*(void **)(p+i*4+0x1008),(struct PtS *)&b,1);
            b.x-=4;
            func_0204B404(*(void **)(p+i*4+0x1008),(const struct Vec2 *)(&b),1);
        }
    }
    for(i=0;i<3;i++) {
        if(*(void **)(p+i*4+0x1014)) {
            func_0204B454(*(void **)(p+i*4+0x1014),(struct PtS *)&c,1);
            c.x+=4;
            func_0204B404(*(void **)(p+i*4+0x1014),(const struct Vec2 *)(&c),1);
        }
    }
    func_02040618(5,0,-((struct Obj05337 *)p)->f11DE);
    func_02040618(4,0,((struct Obj05337 *)p)->f11DE-128);
    return 0;
}

/*
 * lever: split temporary for first loop base and second loop index; 10-byte
 *         register swap without them. Permuter budget 300, 271 compiles.
 * output: 0204B454 and its full getter chain write both coordinate halfwords.
 */
void func_021E6AB0(const char *p)
{
    int i,j;
    Pt a,b,c;
    int tmp;
    const char *tmp1;
    for(i=0;i<8;i++) {
        tmp1=p+i*4;
        tmp1=tmp1+0x10cc;
        func_0204B454(((struct Obj22816 *)tmp1)->f0,(struct PtS *)&a,1);
        if(i/4) {
            a.x-=128;
            func_0204B84C(*(void **)(p+i*4+0x10cc),3);
        } else a.x+=128;
        func_0204B404(*(void **)(p+i*4+0x10cc),(const struct Vec2 *)(&a),1);
    }
    for(i=0;i<3;i++) {
        if(*(void **)(p+i*4+0x1008)) {
            func_0204B454(*(void **)(p+i*4+0x1008),(struct PtS *)&b,1);
            b.x+=128;
            tmp=i;
            tmp=tmp*4;
            func_0204B404(*(void **)(p+tmp+0x1008),(const struct Vec2 *)(&b),1);
        }
    }
    for(j=0;j<3;j++) {
        if(*(void **)(p+j*4+0x1014)) {
            func_0204B454(*(void **)(p+j*4+0x1014),(struct PtS *)&c,1);
            c.x-=128;
            func_0204B404(*(void **)(p+j*4+0x1014),(const struct Vec2 *)(&c),1);
            func_0204B84C(*(void **)(p+j*4+0x1014),3);
        }
    }
    func_0204047C(4,2);
    func_0204047C(5,3);
}

void func_021E6B90(char *p)
{
    void *h;
    struct BgTemplate t;
    ((struct Obj00001 *)p)->f644 = func_0201F5DC((void *)6, 15, 0, ((struct Obj00001 *)p)->f5F4);
    h = func_020490F4(0x66, ((struct Obj00001 *)p)->f5F4);
    ((struct Obj00001 *)p)->f870 = func_02049740(h, 13, 5, 0, 0, ((struct Obj00001 *)p)->f5F4);
    func_02049990(h, 7, 4, 0, (u16)((struct Obj00001 *)p)->f870, 0, 0, ((struct Obj00001 *)p)->f5F4);
    func_02049990(h, 7, 5, 0, (u16)((struct Obj00001 *)p)->f870, 0, 0, ((struct Obj00001 *)p)->f5F4);
    t = d_021E7E44;
    func_020403F4(7);
    func_0203FCA0(7, &t, 0);
    func_02049990(h, 8, 7, 0, (u16)((struct Obj00001 *)p)->f870, 0, 0, ((struct Obj00001 *)p)->f5F4);
    func_02040618(4, 0, -0x80);
    func_02040618(7, 0, 0);
    func_0204047C(4, 3);
    func_02049990(h, 11, 2, 0, (u16)((struct Obj00001 *)p)->f86C, 0, 0, ((struct Obj00001 *)p)->f5F4);
    func_02049238(h);
    ((struct Obj00001 *)p)->f11DE = 0;
    func_021E6AB0(p);
    func_020435F4(0x1f);
}
