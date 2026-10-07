/*
 * file:     pmsiv_menu_p02.c
 * unit:     yes
 * function: func_021BC1B8, func_021BC23C, func_021BC320
 * address:  0x021BC1B8
 * region:   ov110
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021BC578 0x021BC578 thumb ov110
 *   func_021BAC64 0x021BAC64 thumb ov110
 *   func_021BAC78 0x021BAC78 thumb ov110
 *   func_021BC69C 0x021BC69C thumb ov110
 *   func_0204B878 0x0204B878 arm
 *   func_0204B84C 0x0204B84C arm
 *   func_021BC0CC 0x021BC0CC thumb ov110
 *   func_021BF6D8 0x021BF6D8 thumb ov110
 *   func_021BC58C 0x021BC58C thumb ov110
 *   func_021BF6F0 0x021BF6F0 thumb ov110
 *   func_021BC5BC 0x021BC5BC thumb ov110
 *   func_021BC340 0x021BC340 thumb ov110
 *   func_0204B3DC 0x0204B3DC arm
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_02045334 0x02045334 arm
 *   func_02041B6C 0x02041B6C arm
 */
#include "../../matched/include/Obj01393.h"

struct Obj;
struct CharBuf;
struct Descriptor;
struct Vec2;
typedef unsigned char u8;

typedef unsigned short u16;

typedef short s16;

typedef struct { int a,b,c; } Triple;

typedef struct { s16 x,y; } Pair;

typedef struct { void *root; u8 *state; int pad; void *desc[2]; u8 gap0[8]; void *items[2][2]; u8 gap[12]; Pair pos[2]; int pad40; int count; } Obj;

typedef unsigned int   u32;

extern void func_021BC578(const s16 *a, s16 *b);
extern void func_021BAC64(void *,Triple *,int,int);
extern void *func_021BAC78(void *,Triple *,int,int,int,int);
extern void func_021BC69C(u8 *p, int flag);
extern void func_0204B878(struct Obj *p, u16 value);
extern void func_0204B84C(void *,int);
extern void func_021BC0CC(u8 *p);
extern void func_0204B3DC(struct Obj *p, u32 v);
extern void *func_02045770(struct Descriptor *p);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern unsigned func_021BF6D8(u8 *);
extern void func_021BC58C(void *,Pair *);
extern u32 func_021BF6F0(u8 *p, u32 i);
extern void func_021BC5BC(u8 *p, struct Descriptor *window, const struct Vec2 *input, u32 id, struct Obj *sprite);
extern int func_021BC340(Obj *,void *,u8);
extern void func_02045334(struct Descriptor *d);
extern void func_02041B6C(unsigned);
void func_021BC1B8(u8 *p);
void func_021BC23C(Obj *p);
void func_021BC320(void *a, unsigned char *b, int n);

/*
 * extent: two bytes zero alignment padding after return.
 * lever: coordinate arguments are int; the callee stores low halfwords
 * without caller-side narrowing, including y+192.
 */
void func_021BC1B8(u8 *p)
{
    Triple t;
    Pair pos;
    if (*(int *)&((struct Obj01393 *)p)->f44) func_021BC578((const s16 *)(p+0x38),(s16 *)(&pos));
    else { pos.x=128; pos.y=24; }
    func_021BAC64(((struct Obj01393 *)p)->f0,&t,1,0);
    ((struct Obj01393 *)p)->f18=func_021BAC78(((struct Obj01393 *)p)->f0,&t,pos.x,pos.y+192,0,2);
    func_0204B878(((struct Obj01393 *)p)->f18,1);
    func_0204B84C(((struct Obj01393 *)p)->f18,1);
    func_021BAC64(((struct Obj01393 *)p)->f0,&t,0,0);
    ((struct Obj01393 *)p)->f14=func_021BAC78(((struct Obj01393 *)p)->f0,&t,pos.x,pos.y,0,1);
    func_021BC69C(p,1);
}

/*
 * extent: two bytes zero alignment padding at 0x021BC31E.
 */
void func_021BC23C(Obj *p)
{
    int i,j;
    func_021BC0CC((u8 *)p);
    for(i=0;i<2;i++) {
        for(j=0;j<2;j++) {
            if(p->items[j][i]) func_0204B3DC(p->items[j][i],0);
        }
        func_02043B5C(func_02045770(p->desc[i]),15);
        switch(func_021BF6D8(p->state)) {
        case 0:
            func_021BC58C(p->desc[i],&p->pos[0]);
            func_021BC5BC((u8 *)p,p->desc[i],(const struct Vec2 *)(&p->pos[0]),func_021BF6F0(p->state,0),p->items[0][i]);
            break;
        case 1:
            func_021BC58C(p->desc[i],&p->pos[0]);
            func_021BC58C(p->desc[i],&p->pos[1]);
            func_021BC5BC((u8 *)p,p->desc[i],(const struct Vec2 *)(&p->pos[0]),func_021BF6F0(p->state,0),p->items[0][i]);
            func_021BC5BC((u8 *)p,p->desc[i],(const struct Vec2 *)(&p->pos[1]),func_021BF6F0(p->state,1),p->items[1][i]);
            break;
        case 2:
            p->count=func_021BC340(p,p->desc[i],i);
            break;
        }
        func_02045334(p->desc[i]);
    }
    func_02041B6C(0);
    func_02041B6C(4);
}

/*
 * Unlabelled Thumb leaf in a .word run.  Extent 0x021BC320..0x021BC340
 * (32 bytes).  Packs two s16 coordinates from a[n] into b.
 */
void func_021BC320(void *a, unsigned char *b, int n)
{
    int i = n * 4;

    b[2] = *(short *)((char *)a + i + 0x38) - 0x18;
    b[3] = b[2] + 0x60;
    b[0] = *(short *)((char *)a + i + 0x3a);
    b[1] = b[0] + 0x10;
}
