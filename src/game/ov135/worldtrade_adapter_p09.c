/*
 * file:     worldtrade_adapter_p09.c
 * unit:     yes
 * function: func_021FCFD8, func_021FD08C, func_021FD0F4, func_021FD104, func_021FD1E0, func_021FD270, func_021FD2FC, func_021FD31C, func_021FD368
 * address:  0x021FCFD8
 * region:   ov135
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
 *   func_02049B68  0x02049B68  arm
 *   func_02049B40  0x02049B40  arm
 *   func_0201F5BC  0x0201F5BC  thumb
 *   func_02049658  0x02049658  arm
 *   func_020498F4  0x020498F4  arm
 *   func_02049238  0x02049238  arm
 *   func_02082BCC  0x02082BCC  arm
 *   func_0204B294  0x0204B294  arm
 *   func_0204B92C  0x0204B92C  arm
 *   func_0204B878  0x0204B878  arm
 *   func_0204B3DC  0x0204B3DC  arm
 *   func_0203D34C  0x0203D34C  arm
 *   func_020450F0  0x020450F0  arm
 *   func_02045334  0x02045334  arm
 *   func_02045374  0x02045374  arm
 *   func_02045730  0x02045730  arm
 *   func_02041B6C  0x02041B6C  arm
 *   tbl_02203668   0x02203668  data  a4
 *   func_02202940  0x02202940  thumb  ov135
 *   sub_020452E8   0x020452E8  arm
 *   sub_020456F8   0x020456F8  arm
 *   unit_02045730  0x02045730  arm
 *   sub_020409B4   0x020409B4  arm
 *   func_020457B0  0x020457B0  arm
 *   func_0201F31C  0x0201F31C  thumb
 *   func_0201F048  0x0201F048  thumb
 *   func_0201F094  0x0201F094  thumb
 *   func_02202670  0x02202670  thumb
 *   func_021F4EC0 0x021F4EC0 thumb ov135
 *   func_021FFD1C 0x021FFD1C thumb ov135
 */
#include "../../matched/include/Obj00240.h"
#include "../../matched/include/Obj18570.h"
#include "../../matched/include/Obj03069.h"
#include "../../matched/include/Obj09237.h"
#include "../../matched/include/Obj06517.h"
#include "../../matched/include/Obj01063.h"

struct Obj;
struct Descriptor;
struct Cfg;
struct U16Vec;
struct WordSet;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed char s8;

typedef signed short s16;

typedef struct {
    u16 x;
    u16 y;
    u16 z;
    u8 pri;
    u8 f7;
} ObjPos;

typedef struct {
    u8 pad0[0xBC0];
    void *res;
    void *set[3];
    u8 padBD0[0xD08 - 0xBD0];
    void *obj;
} Obj;

typedef struct {
    u32 x;
    u32 y;
    u32 w;
    u32 h;
    u32 bg;
} WinDef;

typedef struct {
    u8 pad0[0xD40];
    u32 frame;
    u8 padD44[0xD50 - 0xD44];
    u32 side[2];
    u8 padD58[0xD90 - 0xD58];
    u32 win[16];
    u8 padDD0[0x12FC - 0xDD0];
    u32 flag;
} Menu;

typedef signed int s32;

typedef struct {
    u8 pad0[0x120];
    u8 lang;
    u8 ver;
    u8 pad122[0x128 - 0x122];
} Entry;

typedef struct {
    u8 pad0[0xD4];
    int cur;
    u8 padD8[0x20C - 0xD8];
    Entry arr[8];
    u8 padB4C[0xB68 - 0xB4C];
    void *words;
    void *msg;
    u8 padB70[0xB88 - 0xB70];
    void *str;
    u8 padB8C[4];
    void *name0;
    void *name1;
} Work;

extern void *func_020490F4(u32 id, u32 heap);
extern void func_02049B68(void *a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern void func_02049B40(u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern void func_0201F5BC(u32 a, u32 b, u32 c, u32 d, u16 e);
extern u32 func_02049658(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void func_020498F4(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void func_02049238(void *h);
extern void func_02082BCC(void *p, int v, int n);
extern struct Obj *func_0204B294(void *res, unsigned int a, unsigned int b, unsigned int c, const void *pos, unsigned short f, unsigned short heap);
extern void func_0204B92C(struct Obj *p, u32 v);
extern void func_0204B878(struct Obj *p, u16 value);
extern void func_0204B3DC(struct Obj *p, u32 v);
extern void func_0203D34C(u32 a, u32 b);
extern void func_0204B3B4(struct Obj *p);
extern u32 func_020450F0(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
extern void func_02045334(struct Descriptor *d);
extern void func_02045374(struct Cfg *cfg);
extern u8 func_02045730(struct Descriptor *p);
extern void func_02041B6C(u32 v);
extern void func_02202940(struct Obj *p);
extern u32 sub_020452E8(struct Descriptor *d);
extern void sub_020456F8(struct Descriptor *d);
extern u8 unit_02045730(u32 a);
extern void sub_020409B4(u32 index);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern void func_0201F31C(struct WordSet *p);
extern void func_0201F048(struct WordSet *p, u32 i, u32 n);
extern void func_0201F094(struct WordSet *p, u32 i, u32 a, u32 n);
extern u32 func_02202670(u32 a, u32 b, u32 c, u32 d);
extern void func_02045808(struct U16Vec *vec);
extern void func_0202208C(void *p1, u32 p2, u32 p3, u32 p4, u32 p5, u32 p6, u32 p7);
extern void func_021F4EC0(u8 *p, u32 a, u32 b);
extern void func_021FFD1C(void *, int, int);
extern void func_020061E4(u32);
void func_021FCFD8(u8 *p);
void func_021FD08C(Obj *p);
void func_021FD0F4(u8 *p);
void func_021FD104(Menu *p);
void func_021FD1E0(u8 *p);
void func_021FD270(Work *p);
void func_021FD2FC(u8 *p);
int func_021FD31C(unsigned char *p);
void func_021FD368(unsigned char *p, int i);
extern const WinDef tbl_02203668[];


/*
 * The 0x12fc-field variant: opens the 0x60x0x48 handle, then only when
 * *(u32 *)(p + 0x12fc) == 0 adds the 0xf/0x23 pair through 49658/498F4 and
 * the second 49B40 window.  Both tests reload the same field.
 */
void func_021FCFD8(u8 *p)
{
    void *h;

    func_02049B40(0x17, 5, 0, 0x1a0, 0x20, 0x48);
    func_0201F5BC(4, 1, 2, 0, 0x48);
    h = func_020490F4(0x60, 0x48);
    func_02049658(h, 0x10, 1, 0, 0xc00, 1, 0x48);
    func_02049B68(h, 6, 0, 0, 0x60, 0x48);
    if (((struct Obj00240 *)p)->f12FC == 0) {
        func_02049658(h, 0xf, 6, 0, 0, 0, 0x48);
        func_020498F4(h, 0x23, 6, 0, 0, 0, 0x48);
    }
    func_02049238(h);
    if (((struct Obj00240 *)p)->f12FC == 0) {
        func_02049B40(0x17, 5, 4, 0x20, 0x20, 0x48);
    }
}


void func_021FD08C(Obj *p)
{
    ObjPos pos;

    func_02082BCC(&pos, 0, sizeof(pos));
    pos.x = 0xD0;
    pos.y = 0x3A;
    p->obj = func_0204B294(p->res, (u32)p->set[0], (u32)p->set[1], (u32)p->set[2], &pos, 0, 0x48);
    func_0204B92C(p->obj, 1);
    func_0204B878(p->obj, 0x24);
    func_0204B3DC(p->obj, 1);
    func_0203D34C(0, 0x48);
}


/*
 * Tail call into func_0204B3B4 with the pointer held at +0xd08.
 */
void func_021FD0F4(u8 *p)
{
    func_0204B3B4((struct Obj *)(((struct Obj18570 *)p)->fD08));
}


void func_021FD104(Menu *p)
{
    int i;
    const WinDef *d;
    u32 v;

    p->frame = func_020450F0((u8)4, (u8)2, (u8)0x13, (u8)0x1b, 4, 1, (u16)1);
    if (p->flag == 0) {
        p->side[0] = func_020450F0((u8)4, (u8)1, (u8)0x15, (u8)0xd, 2, 1, (u16)1);
        p->side[1] = func_020450F0((u8)4, (u8)0x11, (u8)0x15, (u8)0xd, 2, 1, (u16)1);
    }
    for (i = 0; i < 16; i++) {
        d = &tbl_02203668[i];
        if (d->bg == 2) {
            p->win[i] = func_020450F0((u8)d->bg, (u8)d->x, (u8)d->y, (u8)d->w, d->h, 0xd, (u16)1);
        } else {
            p->win[i] = func_020450F0((u8)d->bg, (u8)d->x, (u8)d->y, (u8)d->w, d->h, 1, (u16)1);
        }
        v = p->win[i];
        func_02045334((struct Descriptor *)v);
        func_02045374((struct Cfg *)v);
        func_02041B6C(func_02045730((struct Descriptor *)v));
    }
}


/*
 * Tears down the p+0xd90 array of sixteen window handles, each a 020456F8/
 * 02045730/020409B4/020452E8 group, plus the two p+0xd50/p+0xd54 handles
 * and the p+0xd40 window when *(u32 *)(p + 0x12fc) is clear.
 */
void func_021FD1E0(u8 *p)
{
    u32 h;
    s32 i;

    func_02202940((struct Obj *)(p + 0xfa0));
    sub_020452E8((struct Descriptor *)(((struct Obj03069 *)p)->fD40));
    if (((struct Obj03069 *)p)->f12FC == 0) {
        h = ((struct Obj03069 *)p)->fD54;
        sub_020456F8((struct Descriptor *)h);
        sub_020409B4(unit_02045730(h));
        h = ((struct Obj03069 *)p)->fD50;
        sub_020456F8((struct Descriptor *)h);
        sub_020409B4(unit_02045730(h));
        sub_020452E8((struct Descriptor *)(((struct Obj03069 *)p)->fD54));
        sub_020452E8((struct Descriptor *)(((struct Obj03069 *)p)->fD50));
    }
    for (i = 0; i < 0x10; i++) {
        h = *(u32 *)(p + i * 4 + 0xd90);
        sub_020456F8((struct Descriptor *)h);
        sub_020409B4(unit_02045730(h));
        sub_020452E8((struct Descriptor *)(*(u32 *)(p + i * 4 + 0xd90)));
    }
}


void func_021FD270(Work *p)
{
    Entry *e = &p->arr[p->cur];

    p->str = func_020457B0(0xB4, 0x48);
    func_0201F31C(p->words);
    if (e->lang != 0) {
        func_0201F048(p->words, 8, e->lang);
    }
    if (e->ver != 0) {
        func_0201F094(p->words, 9, e->lang, e->ver);
    }
    p->name0 = (void *)func_02202670((u32)p->words, (u32)p->msg, 0x58, 0x48);
    p->name1 = (void *)func_02202670((u32)p->words, (u32)p->msg, 0x59, 0x48);
}


/*
 * Release the +0xb90, +0xb94 and +0xb88 handles.
 */
void func_021FD2FC(u8 *p)
{
    func_02045808((struct U16Vec *)(((struct Obj09237 *)p)->fB90));
    func_02045808((struct U16Vec *)(((struct Obj09237 *)p)->fB94));
    func_02045808((struct U16Vec *)(((struct Obj09237 *)p)->fB88));
}

int func_021FD31C(unsigned char *p)
{
    func_0204B3DC((struct Obj *)((struct Obj06517 *)p)->fD38, 0);
    if (((struct Obj06517 *)p)->f20 == 16) {
        func_0202208C(0, 1, 1, 0, 16, 1, 0x48);
        ((struct Obj06517 *)p)->f28 = 7;
    } else {
        ((struct Obj06517 *)p)->f28 = 1;
        func_0204B3DC((struct Obj *)((struct Obj06517 *)p)->fD34, 1);
    }
    return 2;
}

void func_021FD368(unsigned char *p, int i)
{
    if (i != ((struct Obj01063 *)p)->fD4 && i >= 0) {
        func_0204B878((struct Obj *)(*(u32 *)(p + (i + 1) * 4 + 0xd0c)), i * 4 + 16);
        ((struct Obj01063 *)p)->f28 = 2;
        func_021F4EC0(p, 3, 17);
        ((struct Obj01063 *)p)->fD4 = i;
        func_021FFD1C(p, i, 0);
        func_020061E4(0x54c);
        ((struct Obj01063 *)p)->f12E4 = 1;
        ((struct Obj01063 *)p)->f12FC = 1;
    }
}
