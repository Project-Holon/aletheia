/*
 * file:     worldtrade_box_p03.c
 * unit:     yes
 * function: func_021F5E44, func_021F5F60, func_021F5F9C, func_021F5FC0, func_021F601C, func_021F6178, func_021F61D4, func_021F632C, func_021F6384, func_021F63A8, func_021F63EC, func_021F6418, func_021F643C, func_021F6474, func_021F651C, func_021F6548, func_021F656C, func_021F65C8, func_021F65E8, func_021F6604, func_021F663C, func_021F66C8, func_021F66F0, func_021F6748, func_021F6754, func_021F67A8
 * address:  0x021F5E44
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
 *   tbl_02202DA4  0x02202DA4  data  a1
 *   func_021F68A4  0x021F68A4  thumb
 *   tbl_02202D24  0x02202D24  data
 *   func_021F4FF4  0x021F4FF4  thumb
 *   func_021F4D50  0x021F4D50  thumb  ov135
 *   func_021F4E30  0x021F4E30  thumb
 *   func_021F4E64  0x021F4E64  thumb
 *   func_021F4EC0  0x021F4EC0  thumb
 *   func_021F6B40  0x021F6B40  thumb
 *   func_021F6BC4  0x021F6BC4  thumb
 *   func_021F4E98  0x021F4E98  thumb
 *   func_021F6BFC  0x021F6BFC  thumb
 *   func_021F6C28  0x021F6C28  thumb
 *   func_021F6B34  0x021F6B34  thumb
 *   func_021F4BE0  0x021F4BE0  thumb  ov135
 *   func_021F4D14 0x021F4D14 thumb ov135
 *   func_021F4CE4 0x021F4CE4 thumb ov135
 *   func_02034714 0x02034714 arm
 *   d_02203B68 0x02203B68 data a4
 *   func_021F6DE8  0x021F6DE8  thumb
 *   func_021F6D14  0x021F6D14  thumb
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
 *   DC_FlushRange  0x020862F0  arm
 *   GX_LoadOBJ     0x0207E780  arm
 *   func_0204B6F4  0x0204B6F4  arm
 *   func_02017DBC  0x02017DBC  thumb
 *   func_02017E88  0x02017E88  thumb
 *   func_02017DE4  0x02017DE4  thumb
 *   func_0204B3DC  0x0204B3DC  arm
 *   func_0202136C  0x0202136C  thumb
 *   func_0204B878  0x0204B878  arm
 */
#include "../../matched/include/Obj00448.h"
#include "../../matched/include/Obj06507.h"
#include "../../matched/include/Obj18540.h"
#include "../../matched/include/Obj00045.h"
#include "../../matched/include/Obj18541.h"
#include "../../matched/include/Obj18542.h"
#include "../../matched/include/Obj12196.h"
#include "../../matched/include/Obj12197.h"
#include "../../matched/include/Obj09227.h"
#include "../../matched/include/Obj00018.h"

struct Obj;
struct Slot;
struct Actor;
struct Cfg;
struct CharBuf;
struct MsgBank;
struct U16Vec;
struct WordSet;
struct Descriptor;
struct ArcFile;
struct NitroFileHeader;
struct Sav;
typedef signed char s8;

typedef signed short s16;

typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed int s32;

typedef struct {
    u8 pad0[0xC4];
    u16 box;
    u16 slot;
    int boxes;
    u8 padCC[0xBF4 - 0xCC];
    u32 cursor;
    u8 padBF8[0xD2C - 0xBF8];
    u32 arrows[2];
} Work_021F5E44;

typedef struct {
    u16 x;
    u16 y;
} Pos;

typedef struct {
    u8 pad0[8];
    void *party;
    void *save;
} Ctx;

typedef struct {
    Ctx *ctx;
    u8 pad4[0x28 - 4];
    u32 state;
    u8 pad2C[0xC4 - 0x2C];
    u16 box;
    u16 slot;
    u8 padC8[0xCC - 0xC8];
    void *mon;
    u8 padD0[0xD40 - 0xD0];
    void *d40;
    u8 padD44[0xDE8 - 0xD44];
    void *de8;
} Work_021F5FC0;

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
} IconRec_021F5E44;

typedef struct {
    u32 vram;
    u32 pal;
    u32 spr;
    u8 pixels[0x200];
} IconRec_021F6748;

typedef struct {
    u8 pad0[0xEB8];
    IconRec_021F6748 *icons;
} Work;

typedef struct {
    u16 species;
    s8 f2;
    u8 f3;
} Info;

typedef struct {
    u32 f0;
    u32 f4;
    u32 f8;
} IconRec;

extern u32 func_020362DC(void);
extern u8 func_020355C4(void);
extern void func_0204B3DC(struct Obj *p, unsigned int v);
extern void func_020355D8(u8 v);
extern void func_020061E4(u32 se);
extern void func_0204B92C(struct Obj *obj, u32 v);
extern void func_0204B878(struct Obj *p, u16 value);
extern void func_021F68A4(Work_021F5E44 *p, int box);
extern void func_021F4FF4(u32 a, u32 b, u32 c);
extern void func_0204B84C(u32 obj, int k);
extern u32 func_0201F81C(u32 a, u32 b);
extern void func_0201F878(struct Slot *table, u32 a, u32 b, u32 tag, u32 heap);
extern void func_021F4D50(u8 *p, u16 a, int count, int b);
extern u32 func_021F4E30(u8 *p);
extern void func_021F4E64(u8 *p);
extern u32 func_0201F868(void *p);
extern void func_0201F7A8(void *desc, u32 kind);
extern void func_021F4EC0(u8 *p, u32 a, u32 b);
extern void *func_021F6B40(void *party, void *save, int box, int slot);
extern u32 func_021F6BC4(void *mon);
extern void func_021F4E98(u8 *p, u32 a, u32 b);
extern int func_021F6BFC(u32 handle);
extern int func_021F6C28(u32 handle);
extern int func_021F6B34(int v);
extern void *func_0201AB28(void *p, u32 idx);
extern u32 func_02017E88(void *p, u32 id, u32 v);
extern int func_020179B8(int a0, int a1);
extern void func_0202208C(void *, u32, u32, u32, u32, u32, u32);
extern void func_021F4BE0(u32 a, u32 b, u32 c, u32 d, u8 e);
extern int func_021F4D14(char *p);
extern void func_021F4CE4(char *p);
extern void func_02034714(const char *expr, u32 line, const char *file);
extern int func_021F6DE8(u32 handle);
extern u32 func_0201AA18(void *p);
extern void func_021F6D14(void *dst, Work_021F6474 *p);
extern u32 func_0204B98C(struct Actor *a);
extern void func_021F5CD4(u8 *p, u32 k);
extern u32 func_02202840(u8 *p);
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
extern u32 func_02018438(void *p);
extern void DC_FlushRange(void *p, u32 size);
extern void GX_LoadOBJ(const void *src, u32 offset, u32 size);
extern void func_0204B6F4(struct Obj *o, u32 v, u32 flag);
extern u32 func_02017DBC(struct Sav *p);
extern u32 func_02017DE4(struct Sav *p, u32 f);
extern u32 func_0202136C(u16 v);
void func_021F5E44(Work_021F5E44 *p);
void func_021F5F60(u32 cursor, int i);
int func_021F5F9C(int a, int b, int c);
int func_021F5FC0(u8 *p);
int func_021F601C(Work_021F5FC0 *p);
int func_021F6178(u8 *p);
int func_021F61D4(Work_021F5FC0 *p);
int func_021F632C(u8 *p);
int func_021F6384(u8 *p);
int func_021F63A8(u8 *p);
int func_021F63EC(u8 *p);
int func_021F6418(u8 *p);
int func_021F643C(u8 *p);
int func_021F6474(Work_021F6474 *p);
int func_021F651C(u8 *p);
int func_021F6548(u8 *p);
int func_021F656C(Work_021F656C *p);
int func_021F65C8(u8 *p);
int func_021F65E8(u8 *p);
int func_021F6604(u8 *p);
void func_021F663C(u8 *p, u32 b, u32 c, u32 d, u32 e, u32 sel);
u32 func_021F66C8(u32 a, u32 b, u32 c, u32 d);
void func_021F66F0(u32 species, u32 form, u32 gender, u32 isEgg, u32 slot, u32 f8, u32 arc, IconRec_021F5E44 *rec);
void func_021F6748(u32 a, u8 *q);
void func_021F6754(Work *p);
void func_021F67A8(void *mon, u32 icon, u32 item_spr, u16 *species, u32 slot, u32 arc, Info *info, IconRec *rec);
extern const u8 tbl_02202DA4[][4];
extern const Pos tbl_02202D24[];
extern const char d_02203B68[];







void func_021F5E44(Work_021F5E44 *p)
{
    int moved = 0;
    int dir = 0;
    u8 k;

    if (func_020362DC() != 0 && func_020355C4() == 1) {
        func_0204B3DC((struct Obj *)p->cursor, 1);
        func_020355D8(moved);
        func_020061E4(0x548);
        return;
    }
    if (func_020362DC() & 0x40) {
        dir = 1;
    } else if (func_020362DC() & 0x80) {
        dir = 2;
    } else if (func_020362DC() & 0x20) {
        dir = 3;
    } else if (func_020362DC() & 0x10) {
        dir = 4;
    }
    if (dir != 0) {
        dir = tbl_02202DA4[p->slot][dir - 1];
        if (dir != p->slot) {
            if (dir == 0x63 || dir == 0x65) {
                k = dir == 0x65 ? 0 : 1;
                func_0204B92C((struct Obj *)p->arrows[k], 1);
                func_0204B878((struct Obj *)p->arrows[k], k + 0x26);
                p->box = func_021F5F9C(p->box, p->boxes, dir - 0x64);
                func_021F68A4((Work_021F5E44 *)p, p->box);
                func_020061E4(0x548);
            } else {
                moved = 1;
                p->slot = dir;
            }
        }
    }
    if (moved) {
        func_020061E4(0x548);
    }
    func_021F5F60(p->cursor, p->slot);
}







void func_021F5F60(u32 cursor, int i)
{
    func_021F4FF4(cursor, tbl_02202D24[i].x, tbl_02202D24[i].y);
    if (i == 0x1F || (i >= 0 && i <= 5)) {
        func_0204B84C(cursor, 0);
    } else {
        func_0204B84C(cursor, 1);
    }
}






/*
 * Byte-index arithmetic with 0xff as the out-of-range marker.
 */
int func_021F5F9C(int a, int b, int c)
{
    if (a == 0xff) {
        if (c > 0) {
            return 0;
        }
        if (c < 0) {
            return b - 1;
        }
        return a;
    }
    a += c;
    if (a < 0) {
        return 0xff;
    }
    if (a == b) {
        return 0xff;
    }
    return a;
}







/*
 * Create the resource, register the three 68/69/6a entries and latch state 0x8.
 */
int func_021F5FC0(u8 *p)
{
    *(u32 *)&((struct Obj00448 *)p)->fDE8 = func_0201F81C(3, 0x48);
    func_0201F878((struct Slot *)(*(u32 *)&((struct Obj00448 *)p)->fDE8), *(u32 *)&((struct Obj00448 *)p)->fB6C, 0x68, 1, 0x48);
    func_0201F878((struct Slot *)(*(u32 *)&((struct Obj00448 *)p)->fDE8), *(u32 *)&((struct Obj00448 *)p)->fB6C, 0x69, 2, 0x48);
    func_0201F878((struct Slot *)(*(u32 *)&((struct Obj00448 *)p)->fDE8), *(u32 *)&((struct Obj00448 *)p)->fB6C, 0x6a, 3, 0x48);
    func_021F4D50(p, 0, 3, 0x14);
    ((struct Obj00448 *)p)->f28 = 0x8;
    return 2;
}







int func_021F601C(Work_021F5FC0 *p)
{
    void *mon;

    switch (func_021F4E30((u8 *)p)) {
    case 1:
        func_021F4E64((u8 *)p);
        func_0201F868(p->de8);
        func_0201F7A8(p->d40, 0);
        p->state = 2;
        func_021F4EC0((u8 *)p, 8, 5);
        break;
    case 2:
        func_021F4E64((u8 *)p);
        func_0201F868(p->de8);
        mon = func_021F6B40(p->ctx->party, p->ctx->save, p->box, p->slot);
        if (func_021F6BC4(mon) != 0) {
            func_021F663C((u8 *)p, 0x2B, 1, 0, 0xF0F, 1);
            func_021F4E98((u8 *)p, 4, 1);
        } else if (func_021F6BFC((u32)mon) != 0) {
            if (func_021F6BFC((u32)mon) == 1) {
                func_021F663C((u8 *)p, 0xBF, 1, 0, 0xF0F, 1);
            } else {
                func_021F663C((u8 *)p, 0xC0, 1, 0, 0xF0F, 1);
            }
            func_021F4E98((u8 *)p, 4, 1);
        } else if (func_021F6C28((u32)mon) != 0) {
            func_021F663C((u8 *)p, 0xC1, 1, 0, 0xF0F, 1);
            func_021F4E98((u8 *)p, 4, 1);
        } else {
            if (func_021F6B34(p->box) != 0) {
                func_0201AB28(p->ctx->party, p->slot);
            }
            p->mon = func_021F6B40(p->ctx->party, p->ctx->save, p->box, p->slot);
            p->state = 2;
            func_021F4EC0((u8 *)p, 6, 0);
        }
        break;
    case 3:
    case (u32)-2:
        func_021F4E64((u8 *)p);
        func_0201F868(p->de8);
        func_0201F7A8(p->d40, 0);
        p->state = 0;
        break;
    }
    return 2;
}







/*
 * Create the resource, register the three 5d/5e/5f entries and latch state 0xa.
 */
int func_021F6178(u8 *p)
{
    *(u32 *)&((struct Obj00448 *)p)->fDE8 = func_0201F81C(3, 0x48);
    func_0201F878((struct Slot *)(*(u32 *)&((struct Obj00448 *)p)->fDE8), *(u32 *)&((struct Obj00448 *)p)->fB6C, 0x5d, 1, 0x48);
    func_0201F878((struct Slot *)(*(u32 *)&((struct Obj00448 *)p)->fDE8), *(u32 *)&((struct Obj00448 *)p)->fB6C, 0x5e, 2, 0x48);
    func_0201F878((struct Slot *)(*(u32 *)&((struct Obj00448 *)p)->fDE8), *(u32 *)&((struct Obj00448 *)p)->fB6C, 0x5f, 3, 0x48);
    func_021F4D50(p, 0, 3, 0x14);
    ((struct Obj00448 *)p)->f28 = 0xa;
    return 2;
}







int func_021F61D4(Work_021F5FC0 *p)
{
    void *mon;

    switch (func_021F4E30((u8 *)p)) {
    case 1:
        func_021F4E64((u8 *)p);
        func_0201F868(p->de8);
        p->state = 2;
        func_021F4EC0((u8 *)p, 8, 6);
        break;
    case 2:
        func_021F4E64((u8 *)p);
        func_0201F868(p->de8);
        func_0201F7A8(p->d40, 0);
        mon = func_021F6B40(p->ctx->party, p->ctx->save, p->box, p->slot);
        if (func_021F6BC4(mon) != 0) {
            func_021F663C((u8 *)p, 0x2B, 1, 0, 0xF0F, 1);
            func_021F4E98((u8 *)p, 4, 1);
        } else if (func_021F6BFC((u32)mon) != 0) {
            if (func_021F6BFC((u32)mon) == 1) {
                func_021F663C((u8 *)p, 0xBF, 1, 0, 0xF0F, 1);
            } else {
                func_021F663C((u8 *)p, 0xC0, 1, 0, 0xF0F, 1);
            }
            func_021F4E98((u8 *)p, 4, 1);
        } else if (func_021F6C28((u32)mon) != 0) {
            func_021F663C((u8 *)p, 0xC1, 1, 0, 0xF0F, 1);
            func_021F4E98((u8 *)p, 4, 1);
        } else {
            if (func_021F6B34(p->box) != 0) {
                func_0201AB28(p->ctx->party, p->slot);
            }
            if (func_02017E88(mon, 5, 0) == 0x1EC) {
                func_020179B8((int)mon, 0);
            }
            func_021F6474((Work_021F6474 *)((Work_021F5FC0 *)p));
        }
        break;
    case 3:
    case (u32)-2:
        func_021F4E64((u8 *)p);
        func_0201F868(p->de8);
        func_0201F7A8(p->d40, 0);
        p->state = 0;
        break;
    }
    return 2;
}






int func_021F632C(u8 *p)
{
    if (((struct Obj06507 *)p)->f14 == 0 || ((struct Obj06507 *)p)->f14 == 8 || ((struct Obj06507 *)p)->f14 == 3) {
        func_0202208C(0, 0, 0, 0, 6, 1, 0x48);
        ((struct Obj06507 *)p)->fEB4 = 1;
    } else {
        func_0202208C((void *)3, 0, 0, 0, 6, 1, 0x48);
    }
    ((struct Obj06507 *)p)->f28 = 0;
    return 3;
}






/*
 * State setter: build with the fixed 0x14/0x1ad/0x8/0x1 argument pair and latch state 0x6.
 */
int func_021F6384(u8 *p)
{
    func_021F4BE0((u32)p, 0x14, 0x1ad, 0x8, 0x1);
    ((struct Obj18540 *)p)->f28 = 0x6;
    return 2;
}





int func_021F63A8(u8 *p)
{
    unsigned result = func_021F4D14((char *)p);
    func_02034714(d_02203B68, 0, d_02203B68);
    if (result == 1) {
        func_021F4CE4((char *)p);
        ((struct Obj00045 *)p)->f28 = 2;
        func_021F4EC0(p, 0, 0);
    } else if (result == 2) {
        func_021F4CE4((char *)p);
        ((struct Obj00045 *)p)->f28 = 0;
    }
    return 2;
}






/*
 * Build through func_021F663C and publish the 3/0xc pair.
 */
int func_021F63EC(u8 *p)
{
    func_021F663C(p, 0x19, 1, 0, 0xf0f, 1);
    func_021F4E98(p, 3, 0xc);
    return 2;
}






/*
 * State setter: build with the fixed 0x12/0x1ad/0x8/0x1 argument pair and latch state 0xd.
 */
int func_021F6418(u8 *p)
{
    func_021F4BE0((u32)p, 0x12, 0x1ad, 0x8, 0x1);
    ((struct Obj18541 *)p)->f28 = 0xd;
    return 2;
}






/*
 * Two-way mode dispatch: mode 1 clears and runs the sub-step, mode 2 clears, releases the +0xdd0 word and latches state 1.
 */
int func_021F643C(u8 *p)
{
    u32 k = func_021F4D14((char *)p);

    if (k == 1) {
        func_021F4CE4((char *)p);
        func_021F6474((Work_021F6474 *)((Work_021F5FC0 *)p));
    } else if (k == 2) {
        func_021F4CE4((char *)p);
        func_0201F7A8((void *)(*(u32 *)&((struct Obj00045 *)p)->fDD0), 0);
        ((struct Obj00045 *)p)->f28 = 1;
    }
    return 2;
}





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
void func_021F66F0(u32 species, u32 form, u32 gender, u32 isEgg, u32 slot, u32 f8, u32 arc, IconRec_021F5E44 *rec)
{
    CharData *cd;
    void *buf = (void *)func_021F66C8(arc, func_0201BABC(species, form, gender, isEgg), (u32)(&cd), 0x48);

    func_02082B0C(cd->pixels, rec->pixels, 0x200);
    rec->vram = (slot * 16 + 0x1c) * 32;
    rec->f8 = f8;
    rec->pal = func_0201BB5C(species, form, gender, isEgg) + 5;
    func_020307B0(buf);
}




/*
 * Store the query byte at +3 of the second argument.
 */
void func_021F6748(u32 a, u8 *q)
{
    q[3] = func_02018438((void *)a);
}




/*
 * Deferred icon upload (installed at +0xEBC by func_021F68A4): for each
 * of the 30 icon records at +0xEB8 that has a sprite (+8), flush and
 * load its 0x200 pixel bytes to its OBJ VRAM offset and set the sprite's
 * palette; then free the record block.
 */
void func_021F6754(Work *p)
{
    int i;
    IconRec_021F6748 *e;

    e = p->icons;
    for (i = 0; i < 30; i++, e++) {
        if (e->spr != 0) {
            DC_FlushRange(e->pixels, 0x200);
            GX_LoadOBJ(e->pixels, e->vram, 0x200);
            func_0204B6F4((struct Obj *)e->spr, (u8)e->pal, 1);
        }
    }
    func_020307B0(p->icons);
}


/*
 * Read one Pokemon's display parameters (presence 0xA9, species 5, form
 * 0x6F, egg 0x4C, held item 6, parameter 0x6E + 1) into the info record,
 * clearing its +3 byte for an egg. A present Pokemon gets its icon loaded
 * (func_021F66F0) and shown; the item sprite is shown with animation 0x29
 * or 0x28 by func_0202136C, or hidden when there is no item. An empty
 * slot hides both sprites and clears the icon record's +8 word.
 */
void func_021F67A8(void *mon, u32 icon, u32 item_spr, u16 *species, u32 slot, u32 arc, Info *info, IconRec *rec)
{
    u32 present;
    u32 item;
    u32 egg;
    u32 form;

    func_02017DBC(mon);
    present = func_02017E88(mon, 0xa9, 0);
    *species = func_02017E88(mon, 5, 0);
    form = func_02017E88(mon, 0x6f, 0);
    egg = func_02017E88(mon, 0x4c, 0);
    item = func_02017E88(mon, 6, 0);
    info->species = *species;
    info->f2 = func_02017E88(mon, 0x6e, 0) + 1;
    if (egg != 0) {
        info->f3 = 0;
    }
    func_02017DE4(mon, 1);
    if (present != 0) {
        func_021F66F0(*species, form, info->f2 - 1, egg, slot, icon, arc, (IconRec_021F5E44 *)rec);
        func_0204B3DC((struct Obj *)icon, 1);
        if (item != 0) {
            func_0204B3DC((struct Obj *)item_spr, 1);
            if (func_0202136C(item) != 0) {
                func_0204B878((struct Obj *)item_spr, 0x29);
            } else {
                func_0204B878((struct Obj *)item_spr, 0x28);
            }
        } else {
            func_0204B3DC((struct Obj *)item_spr, 0);
        }
    } else {
        func_0204B3DC((struct Obj *)icon, 0);
        func_0204B3DC((struct Obj *)item_spr, 0);
        rec->f8 = 0;
    }
}
