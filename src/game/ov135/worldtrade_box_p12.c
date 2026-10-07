/*
 * file:     worldtrade_box_p12.c
 * unit:     yes
 * function: func_021F6474, func_021F651C, func_021F6548, func_021F656C, func_021F65C8, func_021F65E8, func_021F6604, func_021F663C, func_021F66C8, func_021F66F0
 * address:  0x021F6474
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
 *   func_021F6DE8  0x021F6DE8  thumb
 *   func_021F4E98  0x021F4E98  thumb
 *   func_021F6B40  0x021F6B40  thumb
 *   func_021F4EC0  0x021F4EC0  thumb
 *   func_021F6D14  0x021F6D14  thumb
 *   func_021F4BE0  0x021F4BE0  thumb  ov135
 *   func_021F4D14 0x021F4D14 thumb ov135
 *   func_021F4CE4 0x021F4CE4 thumb ov135
 *   func_021F5CD4  0x021F5CD4  thumb  ov135
 *   func_02202840  0x02202840  thumb  ov135
 *   sub_02045EC0   0x02045EC0  arm
 *   func_0201F250  0x0201F250  thumb
 *   sub_02045770   0x02045770  arm
 *   sub_02043B5C   0x02043B5C  arm
 *   sub_02045334   0x02045334  arm
 *   sub_02045374   0x02045374  arm
 *   unit_02045730  0x02045730  arm
 *   sub_020409B4   0x020409B4  arm
 *   func_0201F73C  0x0201F73C  thumb
 *   sub_02045808   0x02045808  arm
 *   func_02202858  0x02202858  thumb  ov135
 *   func_0201BABC  0x0201BABC  thumb
 *   func_02082B0C  0x02082B0C  arm
 *   func_0201BB5C  0x0201BB5C  thumb
 *   func_020307B0  0x020307B0  arm
 */
#include "../../matched/include/Obj18542.h"
#include "../../matched/include/Obj12196.h"
#include "../../matched/include/Obj12197.h"
#include "../../matched/include/Obj09227.h"
#include "../../matched/include/Obj00018.h"

struct Actor;
struct Cfg;
struct CharBuf;
struct MsgBank;
struct U16Vec;
struct WordSet;
struct Descriptor;
struct ArcFile;
struct NitroFileHeader;
typedef signed char s8;

typedef signed short s16;

typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed int s32;

typedef struct {
    u8 pad0[8];
    void *party;
    void *save;
} Ctx_021F6474;

typedef struct {
    Ctx_021F6474 *ctx;
    u8 pad4[0x28 - 4];
    u32 state;
    u8 pad2C[0xC4 - 0x2C];
    u16 box;
    u16 slot;
    u8 padC8[0xCC - 0xC8];
    void *mon;
    u32 d0;
    int sel;
    u8 padD8[0xE4 - 0xD8];
    u8 deposit[0x20C - 0xE4];
    u8 list[1][0x128];
    u8 pad334[0xEB4 - 0x334];
    u32 eb4;
} Work_021F6474;

typedef struct { u8 pad[8]; void *party; void *save; } Ctx_021F656C;

typedef struct { Ctx_021F656C *ctx; u8 pad4[0x28-4]; unsigned state; u8 pad2c[0xC4-0x2C]; u16 box, slot; unsigned count; void *mon; u8 padD0[0xDD0-0xD0]; void *dd0; } Work_021F656C;

typedef void (*Fn)(void);

typedef struct {
    u8 pad0[0x14];
    void *pixels;
} CharData;

typedef struct {
    u32 vram;
    u32 pal;
    u32 f8;
    u8 pixels[0x200];
} IconRec;

extern int func_021F6DE8(u32 handle);
extern u32 func_0201AA18(void *p);
extern void func_021F4E98(u8 *p, u32 a, u32 b);
extern void *func_021F6B40(void *party, void *save, int box, int slot);
extern void func_021F4EC0(u8 *p, u32 a, u32 b);
extern void func_021F6D14(void *dst, Work_021F6474 *p);
extern void func_021F4BE0(u32 a, u32 b, u32 c, u32 d, u8 e);
extern int func_021F4D14(char *p);
extern void func_021F4CE4(char *p);
extern void func_0201F7A8(void *desc, unsigned kind);
extern u32 func_0204B98C(struct Actor *a);
extern void func_021F5CD4(u8 *p, u32 k);
extern u32 func_02202840(u8 *p);
extern u32 func_020362DC(void);
extern int func_02035C60(void);
extern void *sub_02045EC0(struct MsgBank *bank, u32 index);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern void *sub_02045770(struct Descriptor *p);
extern void sub_02043B5C(struct CharBuf *buf, u8 value);
extern void sub_02045334(struct Descriptor *a);
extern void sub_02045374(struct Cfg *cfg);
extern u8 unit_02045730(u32 a);
extern void sub_020409B4(u32 index);
extern void func_0201F73C(void *a0, int a1, int a2, int a3);
extern void sub_02045808(struct U16Vec *vec);
extern u32 func_02202858(void *p, u8 b, void *s, u32 x, u32 y, void *out);
extern void *func_02049250(struct ArcFile *arc, u32 member, u32 heap);
extern s32 func_02062A4C(struct NitroFileHeader *file, void **out);
extern u32 func_020307B0(void *p);
extern u32 func_0201BABC(u32 species, u32 form, u32 gender, u32 isEgg);
extern void func_02082B0C(const void *src, void *dst, u32 n);
extern u32 func_0201BB5C(u32 species, u32 form, u32 half, u32 isEgg);
int func_021F6474(Work_021F6474 *p);
int func_021F651C(u8 *p);
int func_021F6548(u8 *p);
int func_021F656C(Work_021F656C *p);
int func_021F65C8(u8 *p);
int func_021F65E8(u8 *p);
int func_021F6604(u8 *p);
void func_021F663C(u8 *p, u32 b, u32 c, u32 d, u32 e, u32 sel);
u32 func_021F66C8(u32 a, u32 b, u32 c, u32 d);
void func_021F66F0(u32 species, u32 form, u32 gender, u32 isEgg, u32 slot, u32 f8, u32 arc, IconRec *rec);


int func_021F6474(Work_021F6474 *p)
{
    if (func_021F6DE8((u32)p->list[p->sel]) != 0 && p->box != 0xFF
        && func_0201AA18(p->ctx->party) == 6) {
        func_021F663C((u8 *)p, 0x29, 1, 0, 0xF0F, 1);
        func_021F4E98((u8 *)p, 4, 1);
        return 0;
    }
    p->mon = func_021F6B40(p->ctx->party, p->ctx->save, p->box, p->slot);
    p->state = 2;
    p->eb4 = 1;
    func_021F4EC0((u8 *)p, 7, 9);
    func_021F6D14(p->deposit, p);
    p->d0 = 0;
    return 1;
}


int func_021F651C(u8 *p)
{
    func_021F663C(p, 0x19, 1, 0, 0xf0f, 1);
    func_021F4E98(p, 3, 0xf);
    return 2;
}


/*
 * State setter: build with the fixed 0x12/0x1ad/0x8/0x1 argument pair and latch state 0x10.
 */
int func_021F6548(u8 *p)
{
    func_021F4BE0((u32)p, 0x12, 0x1ad, 0x8, 0x1);
    ((struct Obj18542 *)p)->f28 = 0x10;
    return 2;
}

int func_021F656C(Work_021F656C *p)
{
    unsigned result = func_021F4D14((char *)p);
    if (result == 1) {
        func_021F4CE4((char *)p);
        p->mon = func_021F6B40(p->ctx->party, p->ctx->save, p->box, p->slot);
        p->state = 2;
        func_021F4EC0((u8 *)p, 6, 0);
    } else if (result == 2) {
        func_021F4CE4((char *)p);
        func_0201F7A8(p->dd0, 0);
        p->state = 1;
    }
    return 2;
}


/*
 * While the +0xbfc buffer is free, feed the mode word at +0x20 to the dispatch.
 */
int func_021F65C8(u8 *p)
{
    if (func_0204B98C((struct Actor *)(((struct Obj12196 *)p)->fBFC)) == 0) {
        func_021F5CD4(p, ((struct Obj12196 *)p)->f20);
    }
    return 2;
}


/*
 * When the sub-object at +0xfa0 is idle, re-arm the state word from +0x2c.
 */
int func_021F65E8(u8 *p)
{
    if (func_02202840(p + 0xfa0) == 0) {
        ((struct Obj12197 *)p)->f28 = ((struct Obj12197 *)p)->f2C;
    }
    return 2;
}


/*
 * When the build query answers 0 and either probe is set, release the +0xdd0 word and roll the state.
 */
int func_021F6604(u8 *p)
{
    if (func_02202840(p + 0xfa0) == 0) {
        if (func_020362DC() != 0 || func_02035C60() != 0) {
            func_0201F7A8((void *)(((struct Obj09227 *)p)->fDD0), 0);
            ((struct Obj09227 *)p)->f28 = ((struct Obj09227 *)p)->f2C;
        }
    }
    return 2;
}


/*
 * Window teardown: the handle is the 0xd40 or 0xdd0 window selected by the
 * sixth argument, and that one handle is used by every call in the body.
 */
void func_021F663C(u8 *p, u32 b, u32 c, u32 d, u32 e, u32 sel)
{
    u32 v = (u32)sub_02045EC0((struct MsgBank *)(*(u32 *)&((struct Obj00018 *)p)->fB6C), b);
    u32 h;

    func_0201F250((struct WordSet *)(*(u32 *)&((struct Obj00018 *)p)->fB68), (void *)(((struct Obj00018 *)p)->fB88), (void *)v);
    h = *(u32 *)(p + (sel == 0 ? 0xd40 : 0xdd0));
    sub_02043B5C((struct CharBuf *)((u32)sub_02045770((struct Descriptor *)h)), 0xf);
    sub_02045334((struct Descriptor *)h);
    sub_02045374((struct Cfg *)h);
    sub_020409B4(unit_02045730(h));
    func_0201F73C((void *)h, 0, 1, 0xe);
    func_02202858((void *)h, 0, (void *)(((struct Obj00018 *)p)->fB88), 0, 0, p + 0xfa0);
    sub_02045808((struct U16Vec *)v);
}


u32 func_021F66C8(u32 a, u32 b, u32 c, u32 d)
{
    u32 blk = (u32)func_02049250((struct ArcFile *)a, b, (u16)d);

    if (blk != 0 && func_02062A4C((struct NitroFileHeader *)blk, (void **)c) == 0) {
        func_020307B0((void *)blk);
        return 0;
    }
    return blk;
}


/*
 * Load the icon graphics of a Pokemon (species, form, gender/half, egg)
 * from the archive handle and copy its 0x200 bytes into the sprite
 * record: +0 gets the VRAM offset of slot `slot`, +4 the icon palette
 * (func_0201BB5C + 5), +8 `pal`, the pixels go to +0xC.
 */
void func_021F66F0(u32 species, u32 form, u32 gender, u32 isEgg, u32 slot, u32 f8, u32 arc, IconRec *rec)
{
    CharData *cd;
    void *buf = (void *)func_021F66C8(arc, func_0201BABC(species, form, gender, isEgg), (u32)(&cd), 0x48);

    func_02082B0C(cd->pixels, rec->pixels, 0x200);
    rec->vram = (slot * 16 + 0x1c) * 32;
    rec->f8 = f8;
    rec->pal = func_0201BB5C(species, form, gender, isEgg) + 5;
    func_020307B0(buf);
}
