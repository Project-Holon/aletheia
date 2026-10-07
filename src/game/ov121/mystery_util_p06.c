/*
 * file:     mystery_util_p06.c
 * unit:     yes
 * function: func_021DA3EC, func_021DA4A8, func_021DA4DC, func_021DA698
 * address:  0x021DA3EC
 * region:   ov121
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_020457B0 0x020457B0 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_02045838 0x02045838 arm
 *   func_02045CAC 0x02045CAC arm
 *   func_020307B0 0x020307B0 arm
 *   func_021D9BE8 0x021D9BE8 thumb ov121
 *   func_02045770 0x02045770 arm
 *   func_02043814 0x02043814 arm
 *   func_02030734 0x02030734 arm
 *   func_02082BCC 0x02082BCC arm
 *   func_021DA1BC 0x021DA1BC thumb ov121
 *   func_02045EC0 0x02045EC0 arm
 *   func_02045874 0x02045874 arm
 *   func_02045808 0x02045808 arm
 *   func_0204B404 0x0204B404 arm
 *   func_0204B3DC 0x0204B3DC arm
 *   func_0204B878 0x0204B878 arm
 *   func_0204B92C 0x0204B92C arm
 *   d_021DFBA0 0x021DFBA0 data a4
 *   d_021DF7C0 0x021DF7C0 data a4
 *   d_021DF76C 0x021DF76C data a4
 *   d_021DF770 0x021DF770 data a4
 *   func_021DA2A8 0x021DA2A8 thumb ov121
 *   func_021DA280 0x021DA280 thumb ov121
 *   func_020409B4 0x020409B4 arm
 */
#include "../../matched/include/Obj03262.h"
#include "../../matched/include/Obj06449.h"
#include "../../matched/include/Obj22885.h"
#include "../../matched/include/Obj22886.h"
#include "../../matched/include/Obj22887.h"
#include "../../matched/include/Obj22888.h"
#include "../../matched/include/Obj13954.h"
#include "../../matched/include/Obj22889.h"
#include "../../matched/include/Obj03786.h"

struct CharBuf;
struct U16Vec;
struct MsgBank;
struct Bmp;
struct Descriptor;
struct Obj;
struct Vec2;
typedef unsigned int u32;

typedef unsigned short u16;

typedef signed short s16;

typedef unsigned char u8;

typedef struct { int x,y; } Pair;

struct In {
    void *bank;
    u32 f4;
    u32 f8;
    u32 *fC_;
    u32 ids[4];
    u32 f20;
    u16 f24;
    u16 f26;
    u16 f28;
    u16 f2a;
    s16 f2c;
    s16 f2e;
    u16 f30;
    u16 pad32;
    u32 f34;
    u32 f38;
    u32 *f3c;
};

struct Out {
    void *f0;
    u32 f4;
    u32 f8;
    u32 fC;
    u16 pad10;
    u16 pal[5];
    u16 pad1c[3];
    u16 f22;
    u16 f24;
    u16 f26;
    u16 f28;
    u16 f2a;
    u16 f2c;
    u16 f2e;
    u16 f30;
    u16 pad32;
    u32 f34;
    u32 f38;
    u8 pad3c[0x24];
    u32 *f60;
};

struct Rec {
    u8 a;
    u8 b;
    u8 pad[6];
    void *h;
    u8 rest[12];
};

struct Tbl { struct Rec r[4]; };

struct Pt { s16 x; s16 y; };

struct E { u32 a; u32 b; };

extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_02045838(struct U16Vec *dst, struct U16Vec *src);
extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
extern u32 func_020307B0(void *p);
extern void func_021D9BE8(int,Pair *,void *,void *,int,Pair *);
extern void func_0201C724(void *owner, u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern void *func_02045770(struct Descriptor *p);
extern void func_02043814(struct Bmp *dst, const struct Bmp *src);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void func_02082BCC(void *,int,int);
extern void *func_021DA1BC(void *,const char *,u32,u16,u8,u32,u32,int,u16);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern struct U16Vec *func_02045874(struct U16Vec *src, u32 heapId);
extern void func_02045808(struct U16Vec *vec);
extern void func_0204B404(struct Obj *p, const struct Vec2 *delta, u32 which);
extern void func_0204B3DC(struct Obj *p, u32 v);
extern void func_0204B878(struct Obj *p, u16 value);
extern void func_0204B92C(struct Obj *p, u32 v);
extern void func_021DA2A8(u8 *);
extern void func_021DA280(u8 *);
extern void func_020409B4(u32 index);
void func_021DA3EC(char *p,char *desc,void *dst);
void func_021DA4A8(u8 *p);
struct Out *func_021DA4DC(const struct In *in, u16 heap);
void func_021DA698(u8 *p);
extern char d_021DFBA0[];
extern const struct Tbl d_021DF7C0;
extern struct E d_021DF76C[];
extern struct E d_021DF770[];

/*
 * extent: two bytes of zero alignment padding follow the return.
 */
void func_021DA3EC(char *p,char *desc,void *dst)
{
    u32 i;
    Pair pos,out;
    void *text=func_020457B0(512,((struct Obj06449 *)p)->f0);
    for(i=0;i<((struct Obj22885 *)(*(char * *)&((struct Obj06449 *)p)->f4))->f4;i++) {
        char *d=desc+i*24;
        if(((struct Obj03262 *)d)->f0) {
            func_02043B5C(*(void **)(p+i*4+8),(u8)(((struct Obj03262 *)d)->f14&31));
            pos.x=((struct Obj03262 *)d)->f10;
            pos.y=((struct Obj03262 *)d)->f12;
            func_021D9BE8(((struct Obj03262 *)d)->fC,&pos,*(void **)(p+i*4+8),text,((struct Obj22886 *)(*(char * *)&((struct Obj06449 *)p)->f4))->f8,&out);
            if(((struct Obj03262 *)d)->f8) func_02045838(text,(struct U16Vec *)(((struct Obj03262 *)d)->f8));
            else func_02045CAC((struct MsgBank *)(((struct Obj22887 *)(*(char * *)&((struct Obj06449 *)p)->f4))->fC),((struct Obj03262 *)d)->f4,text);
            func_0201C724(dst,(u32)(*(void **)(p+i*4+8)),(s16)out.x,(s16)out.y,(u32)text,((struct Obj22888 *)(*(char * *)&((struct Obj06449 *)p)->f4))->f8,((struct Obj03262 *)d)->f14);
        }
    }
    func_020307B0(text);
}

void func_021DA4A8(u8 *p) { u32 i; for(i=0;i<((struct Obj22889 *)(*(u8 * *)&((struct Obj13954 *)p)->f4))->f4;i++) { void *out=*(void **)(p+8+i*4); func_02043814(out,func_02045770(*(void **)(*(u8 **)(*(u8 * *)&((struct Obj13954 *)p)->f4+16+i*4)+12))); } }

/*
 * note (2026-10-05, lane T7, pengy's share): written bottom-up from the listing.
 *   heap is u16 (callees take it as u16). The input record is const, the
 *   output field f60 is a pointer typed like in->f3c: with a u32 f60 the second
 *   read of in->f3c was merged (4 B short). Struct copy t = d_021DF7C0 (4 records of
 *   24 B). The caller passes a 0x38 B input record and heap.
 */
struct Out *func_021DA4DC(const struct In *in, u16 heap)
{
    struct Tbl t;
    struct Pt pt;
    u32 i;
    u8 c;
    u16 w;
    struct Out *out = func_02030734(heap, 0x64, 0, d_021DFBA0, 0x4e7);
    func_02082BCC(out, 0, 0x64);
    out->fC = in->f20;
    out->f4 = (u32)in->fC_;
    out->f26 = in->f26;
    out->f2a = in->f28;
    out->f2c = in->f2a;
    out->f28 = in->f24;
    out->f34 = in->f34;
    out->f38 = in->f38;
    out->f2e = in->f2c;
    out->f30 = in->f30;
    out->f60 = in->f3c;
    if (in->f3c) {
        u32 v = *in->f3c;
        out->f8 = v;
        out->f8 = (v > out->fC - 1) ? out->fC - 1 : v;
    }
    for (i = 0; i < out->fC; i++)
        out->pal[i] = *(u16 *)(0x05000000 + in->f2a * 32 + (i + 10) * 2);
    out->f22 = *(u16 *)(0x0500001E + in->f2a * 32);
    t = d_021DF7C0;
    for (i = 0; i < out->fC; i++) {
        struct Rec *r = &t.r[i];
        r->b += (u8)in->f2c;
        r->a += (u8)in->f2e;
        if (in->bank) r->h = func_02045EC0(in->bank, in->ids[i]);
        else r->h = func_02045874((struct U16Vec *)in->ids[i], (u16)((heap & 0x7FFF) | 0x8000));
    }
    c = in->f26;
    w = in->f24;
    out->f0 = func_021DA1BC(0, (const char *)&t, out->fC, w, c, in->f8, (u32)in->bank, in->f4, heap);
    for (i = 0; i < out->fC; i++)
        if (t.r[i].h) func_02045808(t.r[i].h);
    pt.x = d_021DF76C[out->f8].a;
    pt.y = d_021DF770[out->f8].a + in->f2c * 8;
    func_0204B404((void *)out->f4, (const struct Vec2 *)(&pt), 0);
    func_0204B3DC((void *)out->f4, 1);
    func_0204B878((void *)out->f4, out->f30);
    func_0204B92C((void *)out->f4, 1);
    return out;
}

void func_021DA698(u8 *p) { if(*(u32 * *)&((struct Obj03786 *)p)->f60 && ((struct Obj03786 *)p)->f8!=3) **(u32 * *)&((struct Obj03786 *)p)->f60=((struct Obj03786 *)p)->f8; func_0204B3DC(((struct Obj03786 *)p)->f4,0); func_021DA2A8(*(u8 * *)&((struct Obj03786 *)p)->f0); func_021DA280(*(u8 * *)&((struct Obj03786 *)p)->f0); func_020409B4((u8)(((struct Obj03786 *)p)->f28)); func_020307B0(p); }
