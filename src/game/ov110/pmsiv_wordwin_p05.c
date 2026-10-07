/*
 * file:     pmsiv_wordwin_p05.c
 * unit:     yes
 * function: func_021BF94C, func_021BF9F0
 * address:  0x021BF94C
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
 *   func_021BAC64 0x021BAC64 thumb ov110
 *   func_021BAC78 0x021BAC78 thumb ov110
 *   func_021BAC50 0x021BAC50 thumb ov110
 *   func_0204B878 0x0204B878 arm
 *   func_0204B3DC 0x0204B3DC arm
 *   func_0204B84C 0x0204B84C arm
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_02045334 0x02045334 arm
 *   func_021BFF60 0x021BFF60 thumb ov110
 *   func_021BFF7C 0x021BFF7C thumb ov110
 *   func_021BF734 0x021BF734 thumb ov110
 */
#include "../../matched/include/Obj02166.h"

struct Obj;
struct V3;
struct Descriptor;
struct CharBuf;
typedef unsigned char u8;

typedef unsigned short u16;

typedef struct { int x,y,z; } Triple;

typedef struct { void *root; void *a; void *b; void *c; void *d; void *first; void *unused; void *second; void *items[10]; } Obj;

typedef unsigned int   u32;

extern void func_021BAC64(void *,Triple *,int,int);
extern struct Obj *func_021BAC78(char *p, unsigned int *r, short x, short y, unsigned int a, int mode);
extern void func_021BAC50(char *p, struct V3 *out, int i);
extern void func_0204B878(struct Obj *p, u16 value);
extern void func_0204B3DC(struct Obj *p, u32 v);
extern void func_0204B84C(void *,int);
extern void *func_02045770(struct Descriptor *p);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_02045334(struct Descriptor *);
extern void func_021BFF60(u8 *);
extern void func_021BFF7C(u8 *,unsigned,unsigned);
extern unsigned func_021BF734(u8 *);
void func_021BF94C(Obj *p);
void func_021BF9F0(u8 *p);

/*
 * extent: two bytes zero alignment padding at 0x021BF9EE.
 * lever: typed items member and z=i preserve indexed base and copied zero.
 */
void func_021BF94C(Obj *p) {
    Triple t;
    Triple s;
    int i;
    int z;
    i=0;
    func_021BAC64(p->root,&t,0,0);
    p->first=func_021BAC78(p->root,(unsigned int *)(&t),62,24,4,1);
    func_0204B878(p->first,8);
    func_0204B3DC(p->first,0);
    p->second=func_021BAC78(p->root,(unsigned int *)(&t),244,18,5,1);
    func_0204B878(p->second,18);
    func_0204B3DC(p->second,0);
    z=i;
    for(;i<10;i++) {
        func_021BAC50(p->root,(struct V3 *)(&s),z);
        p->items[i]=func_021BAC78(p->root,(unsigned int *)(&s),z,z,z,1);
        func_0204B878(p->items[i],i);
        func_0204B3DC(p->items[i],z);
        func_0204B84C(p->items[i],1);
    }
}

void func_021BF9F0(u8 *p) {
    unsigned y,i,n;
    func_02043B5C(func_02045770((struct Descriptor *)((struct Obj02166 *)p)->fC),0);
    func_021BFF60(p);
    n=func_021BF734(*(u8 * *)&((struct Obj02166 *)p)->f4);
    if(n>16) n=16;
    i=0;
    y=((struct Obj02166 *)p)->f94;
    for(;i<n;i++) {
        func_021BFF7C(p,i,y);
        if(i&1) y+=24;
    }
    func_02045334((struct Descriptor *)((struct Obj02166 *)p)->fC);
}
