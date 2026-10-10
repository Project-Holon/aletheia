/*
 * file:     zukan_detail_graphic_p07.c
 * unit:     yes
 * function: func_021BE82C, func_021BE840, func_021BE844, func_021BE854, func_021BE864, func_021BE868, func_021BE8FC, func_021BE920, func_021BE9C8, func_021BE9CC, func_021BEA00, func_021BEA04, func_021BEA90, func_021BEB18, func_021BEE70, func_021BEF9C, func_021BEFA0, func_021BF088, func_021BF1D0, func_021BF280
 * address:  0x021BE82C
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
 *   func_020450F0 0x020450F0 arm
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_02045334 0x02045334 arm
 *   func_0204384C 0x0204384C arm
 *   func_020437EC 0x020437EC arm
 *   func_020437D4 0x020437D4 arm
 *   func_02040B58 0x02040B58 arm
 *   func_0204994C 0x0204994C arm
 *   func_020413B0 0x020413B0 arm
 *   func_02045B38 0x02045B38 arm
 *   func_020490F4        0x020490F4  arm
 *   func_02049BDC        0x02049BDC  arm
 *   func_02049238        0x02049238  arm
 *   func_02043814        0x02043814  arm
 *   func_020437AC        0x020437AC  arm
 *   func_02045EC0        0x02045EC0  arm
 *   func_0201C724        0x0201C724  thumb
 *   func_02045808        0x02045808  arm
 *   data_021C84F4        0x021C84F4  data
 *   func_0201C6C4  0x0201C6C4  thumb
 *   func_02040B1C  0x02040B1C  arm
 *   func_02041B6C  0x02041B6C  arm
 *   func_02034AC4 0x02034AC4 arm
 *   ov067_id 0x00000043 data
 *   ov206_id 0x000000CE data
 *   func_021BC32C 0x021BC32C thumb
 *   func_02082BCC 0x02082BCC arm
 *   func_020056A0 0x020056A0 thumb
 *   func_021BC448 0x021BC448 thumb
 *   func_021BC518 0x021BC518 thumb
 *   func_021BC508 0x021BC508 thumb
 *   func_021BF63C 0x021BF63C thumb ov208
 *   func_021BF61C 0x021BF61C thumb ov208
 *   func_021BA2CC 0x021BA2CC thumb ov206
 *   func_021BF41C 0x021BF41C thumb ov208
 *   func_0201D83C 0x0201D83C thumb
 *   func_02045C04 0x02045C04 arm
 *   func_021BC464 0x021BC464 thumb ov208
 *   func_02030EAC 0x02030EAC arm
 *   func_021BC34C 0x021BC34C thumb ov208
 *   func_02034A5C 0x02034A5C arm
 *   func_021BC3B4 0x021BC3B4 thumb
 *   func_021BC3B8 0x021BC3B8 thumb
 *   func_0201D7EC 0x0201D7EC thumb
 *   func_02040618 0x02040618 arm
 *   func_020414AC 0x020414AC arm
 *   func_021BDAD0 0x021BDAD0 thumb
 *   func_021BC3BC 0x021BC3BC thumb
 *   func_021BDAAC 0x021BDAAC thumb
 *   func_021BDAD4 0x021BDAD4 thumb
 *   func_021BDBB8 0x021BDBB8 thumb
 *   func_021BDC48 0x021BDC48 thumb
 *   func_021BC3A4 0x021BC3A4 thumb
 *   func_02012BF8 0x02012BF8 thumb
 *   func_021BDC14 0x021BDC14 thumb
 *   func_021BE840 0x021BE840 thumb
 *   func_021BE82C 0x021BE82C thumb
 *   func_021BE844 0x021BE844 thumb
 *   func_021BF308 0x021BF308 thumb
 *   func_0200CA1C 0x0200CA1C thumb
 *   func_021BC3A8 0x021BC3A8 thumb
 *   func_021BCF4C 0x021BCF4C thumb
 *   func_0200CA70 0x0200CA70 thumb
 *   func_021BF4FC 0x021BF4FC thumb
 *   func_021BC3B0 0x021BC3B0 thumb
 *   func_021B9E68 0x021B9E68 thumb ov206
 *   func_021BA7C8 0x021BA7C8 thumb ov206
 *   func_021BF4C4 0x021BF4C4 thumb
 *   func_021BF5B8 0x021BF5B8 thumb
 *   func_021BF620 0x021BF620 thumb
 *   func_021BC4D8 0x021BC4D8 thumb
 *   func_021BC4C8 0x021BC4C8 thumb
 *   func_021BDBA0 0x021BDBA0 thumb
 *   func_021BC4E4 0x021BC4E4 thumb
 *   func_021BE854 0x021BE854 thumb
 *   func_021BDAE8 0x021BDAE8 thumb
 *   func_021BF450 0x021BF450 thumb
 *   func_021BA374 0x021BA374 thumb ov206
 *   func_021BF664 0x021BF664 thumb
 *   func_021BC46C 0x021BC46C thumb
 *   func_021BC3C0  0x021BC3C0  thumb  ov208
 *   func_021BC3CC  0x021BC3CC  thumb  ov208
 *   func_021BC40C  0x021BC40C  thumb  ov208
 *   func_021BDC2C  0x021BDC2C  thumb  ov208
 *   func_02012BE0  0x02012BE0  thumb
 *   func_02035D20  0x02035D20  arm
 *   func_0204B3F4  0x0204B3F4  arm
 *   ov208_func_021BF280  0x021BF280  thumb  ov208
 *   func_0204B878  0x0204B878  arm
 *   func_020061E4  0x020061E4  thumb
 *   func_020355D8  0x020355D8  arm
 *   func_0203633C 0x0203633C arm
 *   func_020362DC 0x020362DC arm
 *   func_021BA550 0x021BA550 thumb ov206
 *   func_021BA6B0 0x021BA6B0 thumb ov206
 *   func_021BA814 0x021BA814 thumb ov206
 *   func_021BA64C 0x021BA64C thumb ov206
 */
#include "../../matched/include/Obj05867.h"
#include "../../matched/include/Obj03362.h"
#include "../../matched/include/Obj00442.h"

struct Bmp;
struct Descriptor;
struct CharBuf;
struct MsgBank;
struct Obj020437AC;
struct Rec;
struct U16Vec;
struct PrintSys;
struct Ov208Buf;
struct Node;
struct Ov208Blend;
struct Blk37;
struct GfFont;
struct S;
struct Ov208Cur;
struct Obj;
struct Ov208Scene;
struct Ov208Heap;
typedef unsigned int u32;

struct Ov208Icon_021BE82C {
    u32 pad0[3];
    int fc;
};

typedef unsigned char u8;

struct Ov208Icon_021BE840 {
    u32 f0;
    u32 f4;
    int state;
    int fc;
    u8  step;
};

struct Ov208Icon_021BE844 {
    u32 f0;
    u32 f4;
    int state;
    int fc;
    u8  step;
};

struct Ov208Icon_021BE854 {
    u32 f0;
    u32 f4;
    int state;
    int fc;
    u8  step;
};

typedef unsigned short u16;

struct Ov208Gfx { u16 heap; u16 pad; int f4; int f8; int fc; int f10; u32 f14; void *f18; int f1c; int f20; int f24; };

struct Ov208Icon {
    u16 heap;
    u16 pad2;
    u32 f4;
    u32 f8;
    int fc;
    u32 pad10[2];
    u32 f18;
    u32 f1c;
    u32 f20;
    u32 f24;
    u32 f28;
    u32 f2c;
    u32 f30;
};

struct Ov208PalTbl {
    u32 v[5];
};

struct Ov208Scene {
    int task;
    int f4; int f8;
    void *fc;
    void *f10;
    int f14; int f18;
    char pad[0x94 - 0x1c];
    int f94; int f98;
    char pad2[0x10c - 0x9c];
    int f10c;
};

typedef signed int     s32;

struct Ov208Scn {
    u16 pad0; u16 pad2;
    void *f4; void *f8;
    struct Ov208Blend *fc; struct Ov208Blend *f10;
    int f14; int f18;
    char pad1c[0x94 - 0x1c];
    int f94;
    char pad98[0x110 - 0x98];
    void *font; void *msg0; void *msg1; void *msg2;
};

struct Ov208Heap { u16 heap; };

typedef signed short   s16;

struct S_021BEE70 {
    u8 pad0[0x14];
    u32 f14;
    u32 f18;
};

struct E {
    u8 pad0[0x1c];
    int h1c;
    u8 x0;
    u8 y0;
    u8 w;
    u8 h;
    u8 pad24[2];
    u16 f26;
    u8 pad28[4];
    u32 f2c;
    u8 pad30[4];
};

struct S_021BEFA0 {
    u8 pad0[0x94];
    u32 cur;
    u32 prev;
};

struct Params {u16 a,b,c,d; unsigned x,y,arr[6];};

extern u32 func_020450F0(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
extern void *func_02045770(struct Descriptor *a);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_02045334(struct Descriptor *a);
extern struct Bmp *func_0204384C(u32 arc, u32 member, u32 heap2, u32 heap);
extern u32 func_020437EC(const struct Bmp *bmp);
extern void *func_020437D4(const struct Bmp *bmp);
extern u32 func_02040B58(u32 index, const void *src, u32 size);
extern u32 func_0204994C(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u16 a7);
extern void func_020413B0(u8 index, u8 x0, u8 y0, u8 w, u8 h, u8 pal);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern unsigned int func_02045C04(struct Rec *rec);
extern void func_0203FB44(u32 layer, u32 offset, u32 size);
extern void func_020437AC(struct Obj020437AC *p);
extern u32 func_020452E8(struct Descriptor *d);
extern void *func_020490F4(u32 id, u32 heap);
extern void func_02049BDC(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u16 a6);
extern void func_02049238(void *h);
extern void func_02043814(struct Bmp *dst, const struct Bmp *src);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void func_0201C724(void *owner, u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern void func_02045808(struct U16Vec *vec);
extern u32 func_0201C6C4(struct PrintSys *p, void *v);
extern void func_02040B1C(int index, const void *src, u32 size, u32 tile);
extern void func_02041B6C(u32 layer);
extern int func_02034AC4(s32 handle);
extern void *func_021BC32C(struct Ov208Buf *p, u32 size, u32 heap);
extern void func_02082BCC(void *p, int v, int n);
extern int func_020056A0(void (*fn)(void *), void *arg, int n);
extern void *func_021BC448(u32 heap);
extern void func_021BC518(int *p);
extern void func_021BC508(int flag, int *p);
extern void func_021BF63C(int,char *,unsigned);
extern void func_021BF61C(int,char *,unsigned);
extern void func_021BA2CC(char *);
extern void func_021BF41C(int,char *,unsigned);
extern u32 func_0201D83C(void *ptr);
extern void func_021BC464(void *);
extern void func_02030EAC(struct Node *);
extern void func_021BC34C(char *);
extern void func_02034A5C(int);
extern int func_021BC3B4(int *p);
extern int func_021BC3B8(char *p);
extern struct GfFont *func_0201D7EC(int a0, int a1, int a2, int a3, u32 heapId);
extern void func_02040618(u32 layer, u32 a, u32 b);
extern void func_020414AC(u8 a);
extern int func_021BDAD0(void *s);
extern u16 func_021BC3BC(int *ctx);
extern void func_021BDAAC(void *s, u32 a, u32 b, u32 c);
extern void func_021BDAD4(void *s, int a);
extern void func_021BDBB8(void *s, u32 a);
extern void func_021BDC48(void *s, u32 a);
extern int func_021BC3A4(int *ctx);
extern int func_02012BF8(int a, int b);
extern void func_021BDC14(char *p, int b);
extern int func_021BE840(void *s);
extern void func_021BE82C(void *s, int a);
extern void func_021BE844(void *s);
extern void func_021BF308(u16 *heap, char *p, int key);
extern void *func_0200CA1C(void *a);
extern int func_021BC3A8(int *ctx);
extern int func_021BCF4C(char *p);
extern u32 func_0200CA70(struct Blk37 *p);
extern void func_021BF4FC(const u16 *heap, u8 *p, int key, u16 *out1, u16 *out2, u16 *out3, u16 *out4, u32 *out5, u32 *out6, u32 *out7);
extern int func_021BC3B0(int *ctx);
extern void *func_021B9E68(u32 heap, u16 a1, u16 a2, u16 a3, u16 a4, u32 a5, u32 a6, u32 a7, u32 a8, u32 a9, u8 a10, u32 a11, u32 a12, u32 a13, u32 a14, u32 a15, u32 a16);
extern void func_021BA7C8(void *p);
extern void func_021BF4C4(int unused, char *q, int c, int *tbl);
extern void func_021BF5B8(u16 *heap, u8 *p, int *ctx);
extern void func_021BF620(struct Ov208Heap *unused, int *p, int *ctx);
extern void func_021BC4D8(struct Ov208Blend *b);
extern int func_021BC4C8(struct Ov208Blend *b);
extern void func_021BDBA0(void *s);
extern void func_021BC4E4(struct Ov208Blend *b);
extern void func_021BE854(void *s);
extern void func_021BDAE8(char *p, int v);
extern void func_021BF450(void *unused, char *p, int key);
extern void func_021BA374(char *p);
extern void func_021BF664(struct Ov208Heap *h, struct Ov208Scn *p, int *ctx);
extern void func_021BC46C(struct Ov208Blend *a, struct Ov208Blend *b);
extern u16 func_021BC3C0(void *p);
extern void func_021BC3CC(char *p);
extern void func_021BC40C(struct Ov208Cur *p);
extern int func_021BDC2C(char *p);
extern void func_02012BE0(void *p, u32 a, u32 b);
extern u32 func_02035D20(u32 *outA, u32 *outB);
extern u32 func_0204B3F4(struct Obj *p);
extern void ov208_func_021BF280(void *first, char *q, void *third, int next);
extern void func_0204B878(struct Obj *p, u16 value);
extern void func_020061E4(u32 a);
extern void func_020355D8(u8 v);
extern u32 func_0203633C(void);
extern u32 func_020362DC(void);
extern void func_021BA550(char *p, u16 a1, u16 a2, u16 a3, u16 a4, int a5, int a6);
extern void func_021BA6B0(char *p, u16 a1, u16 a2, u16 a3, u16 a4, int a5, int a6, int a7);
extern void func_021BA814(void *);
extern void func_021BA64C(char *p, int mode);
void ov208_func_021BE82C(struct Ov208Icon_021BE82C *p, int kind);
int ov208_func_021BE840(struct Ov208Icon_021BE840 *p);
void ov208_func_021BE844(struct Ov208Icon_021BE844 *p);
void ov208_func_021BE854(struct Ov208Icon_021BE854 *p);
void ov208_func_021BE864(void *p);
void func_021BE868(struct Ov208Gfx *g);
void func_021BE8FC(char *p);
void ov208_func_021BE920(struct Ov208Icon *p);
void func_021BE9C8(void);
void ov208_func_021BE9CC(struct Ov208Icon *p);
void ov208_func_021BEA00(u16 *p, u16 v);
int func_021BEA04(void *owner, int unused, u16 *heap);
int func_021BEA90(char *first,unsigned unused,int owner,char *q,unsigned heap);
int func_021BEB18(void *unused, int *state, struct Ov208Heap *h, struct Ov208Scn *p, int *ctx);
void func_021BEE70(void *a0, void *a1, void *heap, struct S_021BEE70 *st, int *obj, int key);
void func_021BEF9C(void *p);
int func_021BEFA0(void *a0, struct S_021BEFA0 *st, int *obj);
int func_021BF088(void *first,char *p,int key);
void func_021BF1D0(void *first,char *q,void *third);
void func_021BF280(void *first,char *q,void *third,int next);
extern const struct Ov208PalTbl data_021C84F4;
extern const char ov067_id[];
extern const char ov206_id[];




void ov208_func_021BE82C(struct Ov208Icon_021BE82C *p, int kind)
{
    p->fc = kind;
    func_021BE9C8();
    ov208_func_021BE920((struct Ov208Icon *)p);
}




int ov208_func_021BE840(struct Ov208Icon_021BE840 *p)
{
    return p->state;
}




void ov208_func_021BE844(struct Ov208Icon_021BE844 *p)
{
    if (p->state != 2) {
        p->state = 1;
        p->step = 0;
    }
}




void ov208_func_021BE854(struct Ov208Icon_021BE854 *p)
{
    if (p->state != 0) {
        p->state = 3;
        p->step = 0;
    }
}



void ov208_func_021BE864(void *p)
{
}



/*
 * tail: two zero alignment bytes after the function (listing extent is 2 bytes longer).
 */
void func_021BE868(struct Ov208Gfx *g)
{
    g->f14 = func_020450F0(5, 0, 0, 0x10, 1, 13, 0);
    func_02043B5C((struct CharBuf *)((int)func_02045770((struct Descriptor *)g->f14)), 0);
    func_02045334((struct Descriptor *)g->f14);
    g->f18 = func_0204384C(0x9f, 14, 0, g->heap);
    g->f20 = func_020437EC(g->f18);
    g->f1c = func_02040B58(5, func_020437D4(g->f18), g->f20);
    func_0204994C(0x9f, 0x25, 5, 0, g->f1c, 0xc0, 0, g->heap);
    func_020413B0(5, 0, 0, 0x20, 0x18, 13);
    g->f24 = (int)func_02045B38(0, 2, 0xea, g->heap);
}




void func_021BE8FC(char *p)
{
    func_02045C04((struct Rec *)(((struct Obj05867 *)p)->f24));
    func_0203FB44(5, ((struct Obj05867 *)p)->f1C, ((struct Obj05867 *)p)->f20);
    func_020437AC((struct Obj020437AC *)(((struct Obj05867 *)p)->f18));
    func_020452E8((struct Descriptor *)(((struct Obj05867 *)p)->f14));
}





void ov208_func_021BE920(struct Ov208Icon *p)
{
    struct Ov208PalTbl pal;
    void *h;
    u32 s;

    if (p->fc < 0 || p->fc >= 5)
        return;
    h = func_020490F4(0x9f, p->heap);
    pal = data_021C84F4;
    func_02049BDC(h, 4, 4, pal.v[p->fc] << 5, 0x1a0, 0x20, p->heap);
    func_02049238(h);
    h = func_0204384C(0x9f, 0xe, 0, p->heap);
    func_02043814(h, (const struct Bmp *)p->f18);
    func_020437AC(h);
    s = (u32)func_02045EC0((struct MsgBank *)p->f24, p->fc + 0xb2);
    func_0201C724((void *)p->f2c, p->f18, 0x18, 5, s, p->f4, 0x3dc0);
    func_02045808((struct U16Vec *)s);
    p->f30 = 1;
    ov208_func_021BE9CC(p);
}




void func_021BE9C8(void)
{
}





void ov208_func_021BE9CC(struct Ov208Icon *p)
{
    if (p->f30 != 0 && func_0201C6C4((struct PrintSys *)p->f2c, (void *)p->f18) == 0) {
        func_02040B1C(5, func_020437D4((const struct Bmp *)p->f18), p->f20, p->f1c);
        func_02041B6C(5);
        p->f30 = 0;
    }
}





void ov208_func_021BEA00(u16 *p, u16 v)
{
    *p = v;
}




/*
 * 2026-10-04 (D2-16): callback func_021BEF9C filed EXACT as src/matched/ov/ov208_func_021BEF9C.c (empty void function, bx lr). Still MATCH only
 * because no shard witnesses it yet; the integrator manifest run should make this EXACT. Symbols line now carries the ov208 hint.
 * 2026-10-02: only func_021BEF9C (task callback, no witness yet) blocks EXACT; bytes match.
 */
int func_021BEA04(void *owner, int unused, u16 *heap)
{
    struct Ov208Scene *s;
    func_02034AC4((u32)ov067_id);
    func_02034AC4((u32)ov206_id);
    s = func_021BC32C(owner, 0x120, *heap);
    func_02082BCC(s, 0, 0x120);
    s->task = func_020056A0(func_021BEF9C, s, 1);
    s->f94 = 6;
    s->f98 = 6;
    s->f10c = 0;
    s->fc = func_021BC448(*heap);
    s->f10 = func_021BC448(*heap);
    func_021BC518(s->fc);
    func_021BC518(s->f10);
    func_021BC508(0, s->fc);
    func_021BC508(1, s->f10);
    s->f14 = 0;
    s->f18 = 1;
    return 1;
}




/*
 * matching: full-width stack argument reloads; small pool operands are overlay ID symbols.
 * Caller visibly supplies third arguments to helpers and a live r0 to BC464.
 */
int func_021BEA90(char *first,unsigned unused,int owner,char *q,unsigned heap)
{
    func_021BF63C(owner,q,heap);func_021BF61C(owner,q,heap);
    func_021BA2CC(*(char * *)&((struct Obj03362 *)q)->f8);func_021BA2CC(*(char * *)&((struct Obj03362 *)q)->f4);
    func_021BF41C(owner,q,heap);
    func_0201D83C(((struct Obj03362 *)q)->f110);
    func_02045C04(*(struct Rec * *)&((struct Obj03362 *)q)->f11C);
    func_02045C04(*(struct Rec * *)&((struct Obj03362 *)q)->f118);
    func_02045C04(*(struct Rec * *)&((struct Obj03362 *)q)->f114);
    func_021BC464(((struct Obj03362 *)q)->f10);func_021BC464(((struct Obj03362 *)q)->fC);
    func_02030EAC(*(struct Node * *)&((struct Obj03362 *)q)->f0);func_021BC34C(first);
    func_02034A5C((int)ov206_id);func_02034A5C((int)ov067_id);return 1;
}



/*
 * 2026-10-05 (wD8 lane04): EXACT. The three "ov093" callees are in ov206 (matched there, co-resident with
 *   ov208 as in the matched siblings 021BEA04/021BEA90); the region token on their symbols lines is ov206.
 * 2026-10-05 (D5-03): MATCH. Byte-correct except the five calls to the ov093 callees 0x021B9E68,
 *   0x021BA7C8, 0x021BA374 (no witness label; ov093 below 0x021D4000, pengy). Fixes: the colour loop
 *   calls are func_02040618(i, 0, 0) and (i, 3, 0) (the draft passed i; the image keeps the 0 in r7, which
 *   is why ctx left r7), the first 9E68 call passes (2, 0, 1), locals v54 before v50 before w, the
 *   021BDAD0 test written `!= 2` first, and case 4 writes `*state = 5` in both arms.
 * 2026-10-04 (wD2 lane19): also tried ctx as a one-field struct by value and as u32 with casts: no change (frame 0x74/0x78 vs 0x70,
 *   ctx still in r7). Residue unchanged: image stores ctx back to [sp,#0x88] at entry and keeps state at [sp,#0x34], r7 free.
 * 2026-10-05 (wave D4 lane 02): frame layout check: image has v40 at sp+0x40, v44 0x44, w 0x48, v50 0x50,
 *   v54 0x54, tbl 0x58 (frame 0x70). Ours puts two spilled constant temps (0x17+0xfd and 0xf5+0x27, the
 *   msg field offsets) at 0x40/0x44 because ctx holds r7, so everything shifts by 8 (frame 0x78). Tried:
 *   both state and ctx `*volatile` (882 bytes, worse). Root residue is still ctx kept in r7 instead of its
 *   home slot. Also blocked: func_021B9E68, func_021BA7C8, func_021BA374 have no label (ov093 low, pengy).
 * 2026-10-02 (lane C2-01): control flow, callees and frame layout recovered (tbl[6] at sp+0x58 gives the 0x70 frame);
 * the six-state task body is complete. Still DIFF in register allocation: the image keeps the stack argument ctx in
 * its home slot [sp,#0x88] (reloaded at every use, stored back once at entry) and state in [sp,#0x34], leaving r7
 * free for hoisted constants (0x17 and 0xf5 bases in the font/message setup). Here ctx lands in r7 and the setup
 * spills those constants. Tried: int *volatile ctx (state then takes r7).
 * Also unresolved: func_021B9E68, func_021BA7C8, func_021BA374 (ov093 below 0x021D4000, not ours).
 */
int func_021BEB18(void *unused, int *state, struct Ov208Heap *h, struct Ov208Scn *p, int *ctx)
{
    void *scn = (void *)func_021BC3B4(ctx);
    void *icon = (void *)func_021BC3B8((char *)ctx);
    int v40;
    int v44;
    u32 v54;
    u32 v50;
    u16 w[4];
    u32 tbl[6];
    u8 i;
    int t;
    switch (*state) {
    case 0:
        *state = 1;
        p->font = func_0201D7EC(0x17, 0, 1, 0, h->heap);
        p->msg0 = func_02045B38(1, 2, 0x104, h->heap);
        p->msg1 = func_02045B38(1, 2, 0xf5, h->heap);
        p->msg2 = func_02045B38(1, 2, 0x10c, h->heap);
        for (i = 0; i <= 7; i++) {
            if (i != 1 && i != 5) {
                func_02040618(i, 0, 0);
                func_02040618(i, 3, 0);
                func_020414AC(i);
            }
        }
        if (func_021BDAD0(scn) != 2) {
            func_021BDAAC(scn, 0, 0, func_021BC3BC(ctx) > 1);
            func_021BDAD4(scn, 0);
        } else {
            func_021BDBB8(scn, 0);
        }
        func_021BDC48(scn, 0);
        func_021BDC14(scn, func_02012BF8(func_021BC3A4(ctx), 0x11));
        if (func_021BE840(icon) != 2) {
            func_021BE82C(icon, 0);
            func_021BE844(icon);
        }
        func_021BF308((u16 *)h, (char *)p, (int)ctx);
        t = (int)func_0200CA1C((void *)func_021BC3A4(ctx));
        v40 = func_021BCF4C((char *)func_021BC3A8(ctx));
        v44 = func_0200CA70((void *)t);
        func_021BF4FC((const u16 *)h, (u8 *)p, (int)ctx, &w[3], &w[2], &w[1], &w[0], &v54, &v50, tbl);
        p->f4 = func_021B9E68(h->heap, w[3], w[2], w[1], w[0], v54, v44, v50, 2, 0, 1, v40, (u32)p->font, func_021BC3B0(ctx), (u32)p->msg0, (u32)p->msg1, (u32)p->msg2);
        p->f8 = func_021B9E68(h->heap, w[3], w[2], w[1], w[0], v54, v44, v50, 2, 1, 1, v40, (u32)p->font, func_021BC3B0(ctx), (u32)p->msg0, (u32)p->msg1, (u32)p->msg2);
        func_021BA7C8(p->f8);
        func_021BF4C4((int)h, (char *)p, (int)ctx, (int *)tbl);
        func_021BF5B8((u16 *)h, (u8 *)p, ctx);
        func_021BF620(h, (int *)p, ctx);
        break;
    case 1:
        *state = 2;
        func_021BC4D8(p->fc);
        func_021BC4D8(p->f10);
        break;
    case 2:
        if (func_021BC4C8(p->fc) == 0 && func_021BDAD0(scn) == 2 && func_021BE840(icon) == 2) {
            func_021BDBA0(scn);
            func_021BDC48(scn, 1);
            *state = 3;
        }
        break;
    case 3:
        if (p->f14 != 0) {
            *state = 4;
            func_021BC4E4(p->fc);
            func_021BC4E4(p->f10);
            func_021BE854(icon);
            if (p->f14 == 2)
                func_021BDAE8(scn, 0);
        } else if (p->f18 != 0) {
            if (func_021BEFA0(h, (struct S_021BEFA0 *)((struct S *)p), ctx) == 0)
                func_021BF088(h, (char *)p, (int)ctx);
        }
        break;
    case 4:
        if (func_021BC4C8(p->fc) == 0 && func_021BC4C8(p->f10) == 0 && func_021BE840(icon) == 0) {
            if (p->f14 == 2) {
                if (func_021BDAD0(scn) == 0)
                    *state = 5;
            } else {
                *state = 5;
            }
        }
        break;
    case 5:
        return 1;
    }
    if (*state >= 2) {
        func_021BF450(h, (char *)p, (int)ctx);
        func_021BA374(p->f4);
        func_021BA374(p->f8);
        if (p->f94 == 6)
            func_021BF664(h, p, ctx);
    }
    func_021BC46C(p->fc, p->f10);
    return 0;
}






void func_021BEE70(void *a0, void *a1, void *heap, struct S_021BEE70 *st, int *obj, int key)
{
    int sc;
    u32 flag;

    if (st == 0) {
        return;
    }
    sc = func_021BC3B4(obj);
    flag = 0;
    switch (key) {
    case 15:
        break;
    case 10: case 11: case 12: case 13: case 14: case 16: case 17: case 18:
        st->f18 = flag;
        break;
    }
    switch (key) {
    case 1: case 2: case 3: case 4: case 5: case 7: case 8: case 9:
        flag = 1;
        st->f18 = flag;
        break;
    }
    switch (key) {
    case 12: {
        u16 old = func_021BC3C0(obj);
        func_021BC3CC((char *)obj);
        if (old != func_021BC3C0(obj)) {
            func_021BF1D0(heap, (char *)st, obj);
        }
        break;
    }
    case 13: {
        u16 old = func_021BC3C0(obj);
        func_021BC40C((struct Ov208Cur *)obj);
        if (old != func_021BC3C0(obj)) {
            func_021BF1D0(heap, (char *)st, obj);
        }
        break;
    }
    }
    switch (key) {
    case 0:
        break;
    case 1: case 2:
        st->f14 = 2;
        return;
    case 7: case 8: case 9:
        st->f14 = 1;
        return;
    case 3:
        func_021BDBA0((void *)sc);
        return;
    case 4:
        func_021BDBA0((void *)sc);
        return;
    case 5:
        func_02012BE0((void *)func_021BC3A4(obj), 0x11, func_021BDC2C((char *)sc));
        func_021BDBA0((void *)sc);
        return;
    default:
        if (flag != 0) {
            func_021BDBA0((void *)sc);
        }
        break;
    }
}





void func_021BEF9C(void *p)
{
}





/*
 * note (2026-10-05, integrator): EXACT. The rect bytes are read through a byte pointer with the offset in a local (k = 0x20, c[k] .. c[k + 3]), as in ov208 021C6760; the byte loads then come before x.
 * 2026-10-04 (D2-16): also tried positive forms `x0 <= x && x < x0+w` (13 bytes out, shape changes) and `x0 > x` with u32 or int casts and
 * no locals (13 to 15 bytes out). With `x0 > x` the compare order is right but x0 lands in r0 and x in r1 (the image has x0 in r1);
 * with `x < x0` the registers are right and the compare order flips. The residue is one register colour pair.
 * note:     2026-10-04 (D1-08): f2c store fixed by raw `*(u32 *)((u8 *)st + st->cur * 0x14 + 0x2c) = 1`. Now 4 bytes: the two
 *            bounds tests are `cmp x0,x; bhi` in the image (x0 in r1, x in r0) and `cmp x,x0; blo` here (same registers). Writing
 *            `e->x0 > x` instead flips the registers (x0 in r0) but keeps the compare order; neither gives the image.
 * note:     2026-10-02 lane C2-02: two compare directions (image: cmp x0,x then bhi) and the f2c store constant order differ; tried x0<=x, !(x0>x), locals.
 *
 * 2026-10-05 (D4-18): still 4 bytes. Tried: positive form x >= x0 && x < x0 + w (4 bytes, same as now), !(e->x0 > x || ...) (13 bytes: x0 lands in r0), int-cast compares (17 bytes, bgt). The compare order of the image needs x0 in r1 with the unsigned-greater test; every spelling that gives that order puts x0 in r0.
 */
int func_021BEFA0(void *a0, struct S_021BEFA0 *st, int *obj)
{
    int sc;
    int res;
    u32 x;
    u32 y;
    u8 i;
    struct E *e;
    u8 *c;
    int k;

    sc = func_021BC3B4(obj);
    res = 0;
    if (st->cur == 6 && func_02035D20(&x, &y) != 0) {
        for (i = 0; i < 6; i++) {
            e = (struct E *)((u8 *)st + i * 0x14);
            c = (u8 *)e;
            k = 0x20;
            if (func_0204B3F4((struct Obj *)e->h1c) != 0
                && (u32)c[k] <= x && x < (u32)c[k] + c[k + 2]
                && (u32)c[k + 1] <= y && y < (u32)c[k + 1] + c[k + 3]) {
                if (st->prev == i) break;
                st->cur = i;
                res = 1;
                break;
            }
        }
    }
    if (res != 0) {
        ov208_func_021BF280(a0, (char *)st, obj, st->cur);
        *(u32 *)((u8 *)st + st->cur * 0x14 + 0x2c) = 1;
        e = (struct E *)((u8 *)st + st->cur * 0x14);
        func_0204B878((struct Obj *)e->h1c, e->f26);
        func_020061E4(0x54a);
        func_020355D8(1);
        func_021BDC48((void *)sc, 0);
    }
    return res;
}



int func_021BF088(void *first,char *p,int key)
{
    void *scene;
    int changed;
    u32 buttons,press;
    u8 i,next;
    scene=(void *)func_021BC3B4((int *)key);
    changed=0;
    if(((struct Obj00442 *)p)->f94==6) {
        buttons=func_0203633C();
        press=func_020362DC();
        if(((struct Obj00442 *)p)->f98==6) {
            if((buttons&0x300)||(press&1)) {
                for(i=0;i<6;i++) {
                    if(func_0204B3F4(*(struct Obj **)((u32)p+(u32)i*20+0x1c))!=0) {
                        ((struct Obj00442 *)p)->f94=i; changed=1; break;
                    }
                }
            }
        } else if((buttons&0x100)||(press&1)) {
            for(i=1;i<6;i++) {
                next=(((struct Obj00442 *)p)->f98+i)%6;
                if(func_0204B3F4(*(struct Obj **)((u32)p+(u32)next*20+0x1c))!=0) {
                    ((struct Obj00442 *)p)->f94=next; changed=1; break;
                }
            }
        } else if(buttons&0x200) {
            for(i=1;i<6;i++) {
                next=(((struct Obj00442 *)p)->f98+6-i)%6;
                if(func_0204B3F4(*(struct Obj **)((u32)p+(u32)next*20+0x1c))!=0) {
                    ((struct Obj00442 *)p)->f94=next; changed=1; break;
                }
            }
        }
    }
    if(changed!=0) {
        func_021BF280(first,p,(void *)key,((struct Obj00442 *)p)->f94);
        *(u32 *)((u32)p+*(u32 *)&((struct Obj00442 *)p)->f94*20+0x2c)=1;
        func_0204B878(*(struct Obj **)((u32)p+*(u32 *)&((struct Obj00442 *)p)->f94*20+0x1c),*(u16 *)((u32)p+*(u32 *)&((struct Obj00442 *)p)->f94*20+0x26));
        func_020061E4(0x54a);
        func_020355D8(0);
        func_021BDC48((void *)((int)scene), 0);
    }
    return changed;
}



/*
 * matching: initialize the flag after the output-producing call to keep its zero-cost schedule.
 * Third helper arguments are explicitly live in the original caller.
 */
void func_021BF1D0(void *first,char *q,void *third)
{
    struct Params p;
    int okay,index;
    func_021BF4FC(first,(u8 *)q,(int)third,&p.d,&p.c,&p.b,&p.a,&p.y,&p.x,p.arr);
    okay=1;
    func_021BA550(((struct Obj00442 *)q)->f4,p.d,p.c,p.b,p.a,p.y,p.x);
    index=((struct Obj00442 *)q)->f98;
    if(index!=6) {
        if(p.arr[index]!=0) okay=0;
        else {func_021BF63C((int)first, q, (unsigned)third);((struct Obj00442 *)q)->f98=6;}
    }
    if(okay) func_021BA7C8(((struct Obj00442 *)q)->f8);
    else func_021BA6B0(((struct Obj00442 *)q)->f8,p.d,p.c,p.b,p.a,p.y,p.x,((struct Obj00442 *)q)->f98);
    func_021BF4C4((int)first,q,(int)third,(int *)p.arr);
}



void func_021BF280(void *first,char *q,void *third,int next)
{
    struct Params p;
    int current=((struct Obj00442 *)q)->f98;
    if(current!=next) {
        if(current==6) {
            func_021BF4FC(first,(u8 *)q,(int)third,&p.d,&p.c,&p.b,&p.a,&p.y,&p.x,p.arr);
            func_021BA6B0(((struct Obj00442 *)q)->f8,p.d,p.c,p.b,p.a,p.y,p.x,next);
            func_021BA814(((struct Obj00442 *)q)->f8);
        } else func_021BA64C(((struct Obj00442 *)q)->f8,next);
        func_021BF63C((int)first, q, (unsigned)third);((struct Obj00442 *)q)->f98=next;
        func_021BF620(first,(int *)q,third);
    }
}
