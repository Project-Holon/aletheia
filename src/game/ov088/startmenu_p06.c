/*
 * file:     startmenu_p06.c
 * unit:     yes
 * function: func_021BA9D4, func_021BA9E8, func_021BAB20, func_021BAB64, func_021BAC24, func_021BAC64, func_021BAC74, func_021BACD8, func_021BAD08, func_021BB164
 * address:  0x021BA9D4
 * region:   ov088
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0204335C  0x0204335C  arm
 *   func_020433E0  0x020433E0  arm
 *   d_021BD60C     0x021BD60C  data  ov088  a4
 *   func_0203F8F4  0x0203F8F4  arm
 *   func_0203FC28  0x0203FC28  arm
 *   func_0203FCA0  0x0203FCA0  arm
 *   func_020434DC  0x020434DC  arm
 *   func_02043598  0x02043598  arm
 *   d_021BD678     0x021BD678  data  a4
 *   d_021BD724     0x021BD724  data  a4
 *   d_021BD764     0x021BD764  data  a4
 *   d_021BD6C4     0x021BD6C4  data  a4
 *   d_021BD6E4     0x021BD6E4  data  a4
 *   d_021BD744     0x021BD744  data  a4
 *   d_021BD6A4     0x021BD6A4  data  a4
 *   d_021BD704     0x021BD704  data  a4
 *   func_020403F4  0x020403F4  arm
 *   func_0203F9B4  0x0203F9B4  arm
 *   func_020490F4  0x020490F4  arm
 *   func_02049B68  0x02049B68  arm
 *   func_02049658  0x02049658  arm
 *   func_020498F4  0x020498F4  arm
 *   func_02049238  0x02049238  arm
 *   func_0201F5BC  0x0201F5BC  thumb
 *   func_02049B40  0x02049B40  arm
 *   func_0202E940  0x0202E940  thumb
 *   func_0202E9AC  0x0202E9AC  thumb
 *   func_0202EA20  0x0202EA20  thumb
 *   func_02045B38  0x02045B38  arm
 *   func_0201D7EC  0x0201D7EC  thumb
 *   func_0201EC64  0x0201EC64  thumb
 *   func_0201C440  0x0201C440  thumb
 *   func_020457B0  0x020457B0  arm
 *   func_0203101C  0x0203101C  arm
 *   func_02028590  0x02028590  thumb
 *   func_02028604  0x02028604  thumb
 *   func_02031140  0x02031140  arm
 *   func_02045808  0x02045808  arm
 *   func_0201C4C0  0x0201C4C0  thumb
 *   func_0201ED04  0x0201ED04  thumb
 *   func_0201D83C  0x0201D83C  thumb
 *   func_02045C04  0x02045C04  arm
 *   func_02045088  0x02045088  arm
 *   func_020450F0  0x020450F0  arm
 *   func_02045EC0  0x02045EC0  arm
 *   func_02045770  0x02045770  arm
 *   func_0201C724  0x0201C724  thumb
 *   func_0201F02C  0x0201F02C  thumb
 *   func_0201F250  0x0201F250  thumb
 *   func_0201F158  0x0201F158  thumb
 *   func_0201EFA4  0x0201EFA4  thumb
 *   func_02008550  0x02008550  thumb
 *   func_020139B0  0x020139B0  thumb
 *   func_020142E8  0x020142E8  thumb
 *   func_02008854  0x02008854  thumb
 *   func_02008848  0x02008848  thumb
 *   func_0200890C  0x0200890C  thumb
 *   func_02013E4C  0x02013E4C  thumb
 *   func_02013A48  0x02013A48  thumb
 *   func_02008748  0x02008748  thumb
 *   func_0200864C  0x0200864C  thumb
 *   func_02008650  0x02008650  thumb
 *   func_0200CA10  0x0200CA10  thumb
 *   func_0200D0AC  0x0200D0AC  thumb
 *   func_0200C0F0  0x0200C0F0  thumb
 *   func_0200C258  0x0200C258  thumb
 *   d_021BD7C4     0x021BD7C4  data  a1
 *   func_020452E8  0x020452E8  arm
 *   func_020450C8  0x020450C8  arm
 */
#include "../../matched/include/Obj00014.h"
#include "../../matched/include/Obj20816.h"

struct DispVram;
struct BgTemplate;
struct DispConfig;
struct CodeIn;
struct Obj0202EA20;
struct GfFont;
struct MsgBank;
struct Tcbl;
struct U16Vec;
struct WordSet;
struct PrintSys;
struct Rec;
struct S02031140;
struct Descriptor;
struct PlayTime;
struct Sub0200852CObj;
struct Sub02008828Obj;
struct Blk34;
struct Blk37;
struct Sub02008828Rec;
typedef unsigned int   u32;

typedef struct A16 {
    u32 w[4];
} A16;

typedef struct B32 {
    u32 w[8];
} B32;

typedef unsigned short u16;

typedef unsigned char  u8;

struct Ent6 {
    u8 a0, a1, a2, a3, a4, a5;
};

struct Slot {
    void *obj;
    u8 on;
};

struct Menu {
    void *f00;
    void *f04;
    u8 pad08[8];
    void *f10;
    u8 pad14[0x58 - 0x14];
    void *f58;
    void *f5c;
    void *f60;
    void *f64;
    void *f68;
    u8 pad6c[0x80 - 0x6c];
    struct Slot slot[14];
};

typedef signed int     s32;

extern void func_0204335C(u32 keep);
extern void func_020433E0(const struct DispVram *c);
extern void func_0203F8F4(u16 heapId);
extern void func_0203FC28(struct DispConfig *cfg);
extern void func_0203FCA0(u32 bgId, const struct BgTemplate *tmpl, u32 type);
extern void func_020434DC(u32 mask, u32 enable);
extern void func_02043598(u32 mask, u32 enable);
extern void func_020403F4(u32 i);
extern void func_0203F9B4(void);
extern void *func_020490F4(unsigned int id, unsigned int heap);
extern void func_02049B68(void *a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern u32 func_02049658(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void func_020498F4(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void func_02049238(void *);
extern void func_0201F5BC(u32 a, u32 b, u32 c, u32 d, u16 e);
extern void func_02049B40(u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern struct CodeIn *func_0202E940(u16 a0, u16 a1, u32 a2, u16 heap);
extern void func_0202E9AC(struct CodeIn *p, u8 *a1, u32 a2, u32 a3, u32 a4);
extern u32 func_0202EA20(struct Obj0202EA20 *p);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern struct GfFont *func_0201D7EC(int a0, int a1, int a2, int a3, u32 heapId);
extern struct WordSet *func_0201EC64(u32 heap);
extern u32 func_0201C440(void *p);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern struct Tcbl *func_0203101C(u16 heap, u16 tag, u32 count, u32 workSize);
extern u32 func_02028590(u32, u32, u32, u32);
extern int func_02028604(int a0);
extern void func_02031140(struct S02031140 *p);
extern void func_02045808(struct U16Vec *vec);
extern void func_0201C4C0(struct PrintSys *p);
extern unsigned int func_0201ED04(struct WordSet *p);
extern u32 func_0201D83C(void *ptr);
extern u32 func_02045C04(struct Rec *rec);
extern void func_02045088(u16 heapId);
extern u32 func_020450F0(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void *func_02045770(struct Descriptor *p);
extern void func_0201C724(void *owner, u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern void func_0201F02C(struct WordSet *p, u32 i, void *a);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern void func_0201F158(struct WordSet *p, u32 i, u32 v);
extern void func_0201EFA4(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);
extern u8 func_02008550(const struct Sub0200852CObj *obj);
extern void func_020139B0(u32 heap);
extern u32 func_020142E8(void *bitmap, s32 id);
extern struct Sub02008828Obj *func_02008854(void *sys);
extern u16 *func_02008848(void *);
extern void func_0200890C(void *sys, struct Sub02008828Rec *dest);
extern u32 func_02013E4C(u32 id);
extern void func_02013A48(void);
extern struct PlayTime *func_02008748(void *sys);
extern u16 func_0200864C(const struct PlayTime *p);
extern u8 func_02008650(const struct PlayTime *p);
extern void *func_0200CA10(void *);
extern u32 func_0200D0AC(struct Blk37 *p, u32 heap);
extern void *func_0200C0F0(void *);
extern u32 func_0200C258(struct Blk34 *p);
extern u32 func_020452E8(struct Descriptor *d);
extern void func_020450C8(void);
void func_021BA9D4(void);
void func_021BA9E8(void);
void func_021BAB20(void);
void func_021BAB64(void);
void func_021BAC24(char *p);
void func_021BAC64(char *p);
void func_021BAC74(char *p);
void func_021BACD8(int *p);
void func_021BAD08(struct Menu *p);
void func_021BB164(char *p);
extern char d_021BD60C[];
extern A16 d_021BD678;
extern B32 d_021BD724;
extern B32 d_021BD764;
extern B32 d_021BD6C4;
extern B32 d_021BD6E4;
extern B32 d_021BD744;
extern B32 d_021BD6A4;
extern B32 d_021BD704;
extern const struct Ent6 d_021BD7C4[];


void func_021BA9D4(void)
{
    func_0204335C(0);
    func_020433E0((const struct DispVram *)d_021BD60C);
}


void func_021BA9E8(void)
{
    A16 a;
    B32 b0;
    B32 b1;
    B32 b2;
    B32 b3;
    B32 b4;
    B32 b5;
    B32 b6;

    func_0203F8F4(0xb);
    a = d_021BD678;
    func_0203FC28((struct DispConfig *)(&a));
    b0 = d_021BD724;
    func_0203FCA0(0, (const struct BgTemplate *)(&b0), 0);
    b1 = d_021BD764;
    func_0203FCA0(1, (const struct BgTemplate *)(&b1), 0);
    b2 = d_021BD6C4;
    func_0203FCA0(2, (const struct BgTemplate *)(&b2), 0);
    b3 = d_021BD6E4;
    func_0203FCA0(3, (const struct BgTemplate *)(&b3), 0);
    b4 = d_021BD744;
    func_0203FCA0(4, (const struct BgTemplate *)(&b4), 0);
    b5 = d_021BD6A4;
    func_0203FCA0(5, (const struct BgTemplate *)(&b5), 0);
    b6 = d_021BD704;
    func_0203FCA0(6, (const struct BgTemplate *)(&b6), 0);
    func_020434DC(0xf, 1);
    func_02043598(7, 1);
}


/*
 * EXACT*: inferred extent runs two bytes long; the follower at 0x021BAB62 is
 * an unlabelled leaf (no lr save) that disasm.py did not label.
 */
void func_021BAB20(void)
{
    func_020434DC(0xf, 0);
    func_02043598(7, 0);
    func_020403F4(6);
    func_020403F4(5);
    func_020403F4(4);
    func_020403F4(3);
    func_020403F4(2);
    func_020403F4(1);
    func_020403F4(0);
    func_0203F9B4();
}


void func_021BAB64(void)
{
    void *h;
    h = func_020490F4(0x23, 0x800B);
    func_02049B68(h, 4, 0, 0, 0xc0, 0xb);
    func_02049658(h, 3, 2, 0, 0, 1, 0xb);
    func_020498F4(h, 2, 3, 0, 0, 1, 0xb);
    func_02049B68(h, 5, 4, 0, 0xc0, 0xb);
    func_02049658(h, 1, 5, 0, 0, 1, 0xb);
    func_020498F4(h, 0, 6, 0, 0, 1, 0xb);
    func_02049238(h);
    func_0201F5BC(0, 1, 0xe, 0, 0xb);
    func_02049B40(0x17, 5, 0, 0x1e0, 0x20, 0xb);
    func_02049B40(0x17, 5, 4, 0x1e0, 0x20, 0xb);
}


void func_021BAC24(char *p)
{
    void *h;
    h = func_020490F4(0x23, 0x800B);
    ((struct Obj00014 *)p)->f11C = (int)func_0202E940(0x20, 0x10, 2, 0xb);
    func_0202E9AC((struct CodeIn *)(((struct Obj00014 *)p)->f11C), h, 4, 0x20, 0x30);
    func_02049238(h);
}


void func_021BAC64(char *p)
{
    func_0202EA20((struct Obj0202EA20 *)(((struct Obj20816 *)p)->f11C));
}


void func_021BAC74(char *p)
{
    *(u32 *)&((struct Obj00014 *)p)->f5C = (u32)func_02045B38(0, 2, 0xb3, 0xb);
    *(u32 *)&((struct Obj00014 *)p)->f58 = (u32)func_0201D7EC(0x17, 0, 0, 0, 0xb);
    *(u32 *)&((struct Obj00014 *)p)->f60 = (u32)func_0201EC64(0xb);
    *(u32 *)&((struct Obj00014 *)p)->f68 = func_0201C440((void *)0xb);
    *(u32 *)&((struct Obj00014 *)p)->f64 = (u32)func_020457B0(0x400, 0xb);
    ((struct Obj00014 *)p)->f70 = (u32)func_0203101C(0xb, 0xb, 1, 4);
    ((struct Obj00014 *)p)->f74 = func_02028590(0xf, 1, 0, 0xb);
}


void func_021BACD8(int *p)
{
    func_02028604(p[0x74 / 4]);
    func_02031140((struct S02031140 *)p[0x70 / 4]);
    func_02045808((struct U16Vec *)p[0x64 / 4]);
    func_0201C4C0((struct PrintSys *)p[0x68 / 4]);
    func_0201ED04((struct WordSet *)p[0x60 / 4]);
    func_0201D83C((void *)p[0x58 / 4]);
    func_02045C04((struct Rec *)p[0x5c / 4]);
}


void func_021BAD08(struct Menu *p)
{
    u32 i;
    void *a;
    void *s;
    void *b;
    void *bg;
    u16 buf[14];

    func_02045088(11);
    for (i = 0; i < 14; i++) {
        p->slot[i].obj = (void *)func_020450F0(d_021BD7C4[i].a0, d_021BD7C4[i].a1, d_021BD7C4[i].a2,
                                       d_021BD7C4[i].a3, d_021BD7C4[i].a4, d_021BD7C4[i].a5, 1);
    }

    a = func_02045EC0(p->f5c, 0);
    bg = p->f68;
    func_0201C724(bg, (u32)func_02045770(p->slot[0].obj), 0, 4, (u32)a, (u32)p->f58, 0x440);
    p->slot[0].on = 1;
    func_02045808(a);

    a = func_02045EC0(p->f5c, 12);
    func_0201F02C(p->f60, 0, p->f04);
    func_0201F250(p->f60, p->f64, a);
    if (func_02008550(p->f04) == 0) {
        bg = p->f68;
        func_0201C724(bg, (u32)func_02045770(p->slot[1].obj), 0, 0, (u32)p->f64, (u32)p->f58, 0xC80);
        p->slot[1].on = 1;
    } else {
        bg = p->f68;
        func_0201C724(bg, (u32)func_02045770(p->slot[1].obj), 0, 0, (u32)p->f64, (u32)p->f58, 0x14C0);
        p->slot[1].on = 1;
    }
    func_02045808(a);

    a = func_02045EC0(p->f5c, 16);
    func_020139B0(0x800B);
    if (func_020142E8(p->f10, 0x966) == 1) {
        s = (void *)func_02013E4C(func_02008848(func_02008854(p->f00))[2]);
    } else {
        func_0200890C(p->f00, (struct Sub02008828Rec *)buf);
        s = (void *)func_02013E4C(buf[0]);
    }
    func_02013A48();
    func_0201F158(p->f60, 0, (u32)s);
    func_0201F250(p->f60, p->f64, a);
    bg = p->f68;
    func_0201C724(bg, (u32)func_02045770(p->slot[2].obj), 0, 0, (u32)p->f64, (u32)p->f58, 0x440);
    p->slot[2].on = 1;
    func_02045808(a);

    a = func_02045EC0(p->f5c, 9);
    b = func_02008748(p->f00);
    func_0201EFA4(p->f60, 0, func_0200864C(b), 3, 0, 1);
    func_0201EFA4(p->f60, 1, func_02008650(b), 2, 2, 1);
    func_0201F250(p->f60, p->f64, a);
    bg = p->f68;
    func_0201C724(bg, (u32)func_02045770(p->slot[3].obj), 0, 0, (u32)p->f64, (u32)p->f58, 0x440);
    p->slot[3].on = 1;
    func_02045808(a);

    if (func_020142E8(p->f10, 0x962) == 1) {
        a = func_02045EC0(p->f5c, 10);
        func_0201EFA4(p->f60, 0, func_0200D0AC(func_0200CA10(p->f00), 11), 3, 0, 1);
        func_0201F250(p->f60, p->f64, a);
        bg = p->f68;
        func_0201C724(bg, (u32)func_02045770(p->slot[4].obj), 0, 0, (u32)p->f64, (u32)p->f58, 0x440);
        p->slot[4].on = 1;
        func_02045808(a);
    }

    a = func_02045EC0(p->f5c, 11);
    func_0201EFA4(p->f60, 0, func_0200C258(func_0200C0F0(p->f00)), 2, 0, 1);
    func_0201F250(p->f60, p->f64, a);
    bg = p->f68;
    func_0201C724(bg, (u32)func_02045770(p->slot[5].obj), 0, 0, (u32)p->f64, (u32)p->f58, 0x440);
    p->slot[5].on = 1;
    func_02045808(a);

    a = func_02045EC0(p->f5c, 1);
    {
        void *bg = p->f68;
        func_0201C724(bg, (u32)func_02045770(p->slot[6].obj), 0, 4, (u32)a, (u32)p->f58, 0x440);
    }
    p->slot[6].on = 1;
    func_02045808(a);

    a = func_02045EC0(p->f5c, 2);
    {
        void *bg = p->f68;
        func_0201C724(bg, (u32)func_02045770(p->slot[7].obj), 0, 4, (u32)a, (u32)p->f58, 0x440);
    }
    p->slot[7].on = 1;
    func_02045808(a);

    a = func_02045EC0(p->f5c, 4);
    {
        void *bg = p->f68;
        func_0201C724(bg, (u32)func_02045770(p->slot[8].obj), 0, 4, (u32)a, (u32)p->f58, 0x440);
    }
    p->slot[8].on = 1;
    func_02045808(a);

    a = func_02045EC0(p->f5c, 5);
    {
        void *bg = p->f68;
        func_0201C724(bg, (u32)func_02045770(p->slot[9].obj), 0, 4, (u32)a, (u32)p->f58, 0x440);
    }
    p->slot[9].on = 1;
    func_02045808(a);

    a = func_02045EC0(p->f5c, 3);
    {
        void *bg = p->f68;
        func_0201C724(bg, (u32)func_02045770(p->slot[10].obj), 0, 4, (u32)a, (u32)p->f58, 0x440);
    }
    p->slot[10].on = 1;
    func_02045808(a);

    a = func_02045EC0(p->f5c, 7);
    {
        void *bg = p->f68;
        func_0201C724(bg, (u32)func_02045770(p->slot[11].obj), 0, 4, (u32)a, (u32)p->f58, 0x440);
    }
    p->slot[11].on = 1;
    func_02045808(a);

    a = func_02045EC0(p->f5c, 6);
    {
        void *bg = p->f68;
        func_0201C724(bg, (u32)func_02045770(p->slot[12].obj), 0, 4, (u32)a, (u32)p->f58, 0x440);
    }
    p->slot[12].on = 1;
    func_02045808(a);
}


/*
 * Releases the fourteen 8-byte-stride handles at +0x80 created by
 * func_021BAD08, then the shared resource.
 */
void func_021BB164(char *p)
{
    unsigned i;
    for (i = 0; i < 14; i++)
        func_020452E8(*(void **)(p + 0x80 + i * 8));
    func_020450C8();
}
