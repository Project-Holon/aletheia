/*
 * file:     zknsearch_main_p02.c
 * unit:     yes
 * function: func_021BE324, func_021BE368, func_021BE3B4, func_021BE3D4, func_021BE44C, func_021BE49C, func_021BE4B4, func_021BE564, func_021BE7E4, func_021BE820, func_021BE83C, func_021BE8B8, func_021BE8F8, func_021BE978, func_021BE9D4, func_021BEA54, func_021BEB0C, func_021BEB8C, func_021BEBE8, func_021BEC60, func_021BECAC, func_021BECB8, func_021BECF8, func_021BED04, func_021BED10, func_021BED1C, func_021BED2C, func_021BED54, func_021BED68, func_021BED98, func_021BEDB8, func_021BEDD0, func_021BEDE0, func_021BEDF0, func_021BEE04, func_021BEE14, func_021BEE38, func_021BEE58, func_021BEE80, func_021BEE94, func_021BEEC4
 * address:  0x021BE324
 * region:   ov210
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02012BF8 0x02012BF8 thumb
 *   func_02012BE0 0x02012BE0 thumb
 *   func_02045088 0x02045088 arm
 *   func_020450F0 0x020450F0 arm
 *   d_021C0900 0x021C0900 data a1
 *   func_020452E8 0x020452E8 arm
 *   func_020450C8 0x020450C8 arm
 *   func_0201C4E4 0x0201C4E4 thumb
 *   func_02045770 0x02045770 arm
 *   func_0201C6C4 0x0201C6C4 thumb
 *   func_02045334 0x02045334 arm
 *   func_02045EC0 0x02045EC0 arm
 *   func_021B6AE4 0x021B6AE4 thumb ov067
 *   func_02045808 0x02045808 arm
 *   func_021BCF00 0x021BCF00 thumb ov210
 *   func_02043B5C 0x02043B5C arm
 *   func_0201D304 0x0201D304 thumb
 *   func_021B9394 0x021B9394 thumb ov067
 *   func_02045738 0x02045738 arm
 *   func_021BF0DC 0x021BF0DC thumb ov210
 *   func_020434DC 0x020434DC arm
 *   func_02043598 0x02043598 arm
 *   func_021BF370 0x021BF370 thumb ov210
 *   func_021BF080 0x021BF080 thumb ov210
 *   func_0204A5AC 0x0204A5AC arm
 *   func_0204B944 0x0204B944 arm
 *   func_0204B8D4 0x0204B8D4 arm
 *   func_0204A600 0x0204A600 arm
 *   func_0204B8C4 0x0204B8C4 arm
 *   func_0204B878 0x0204B878 arm
 *   func_0204B92C 0x0204B92C arm
 *   func_0204B898 0x0204B898 arm
 *   func_0204B98C  0x0204B98C  arm
 *   func_0204B3DC 0x0204B3DC arm
 *   func_0204B3F4 0x0204B3F4 arm
 *   func_0204B688 0x0204B688 arm
 *   func_0204B404 0x0204B404 arm
 *   func_0204B454 0x0204B454 arm
 *   func_0204B84C 0x0204B84C arm
 *   func_021BC3E8 0x021BC3E8 thumb ov210
 *   func_0204A48C 0x0204A48C arm
 *   d_021C0990 0x021C0990 data a4 ov210
 *   func_020490F4 0x020490F4 arm
 *   func_0204A6C8 0x0204A6C8 arm
 *   func_0204ABF0 0x0204ABF0 arm
 *   func_0204AF28 0x0204AF28 arm
 *   func_02049238 0x02049238 arm
 *   func_020275E4 0x020275E4 thumb
 *   func_02027618 0x02027618 thumb
 *   func_02027614 0x02027614 thumb
 *   func_0202761C 0x0202761C thumb
 *   func_02027620 0x02027620 thumb
 */
#include "../../matched/include/Obj10921.h"
#include "../../matched/include/Obj08413.h"
#include "../../matched/include/Obj00222.h"
#include "../../matched/include/Obj14680.h"
#include "../../matched/include/Obj25617.h"
#include "../../matched/include/Obj25618.h"
#include "../../matched/include/Obj14681.h"
#include "../../matched/include/Obj04620.h"

struct Descriptor;
struct PrintSys;
struct MsgBank;
struct U16Vec;
struct Cfg;
struct CharBuf;
struct StrObj;
struct Obj021BF0DC;
struct Res021BEEC4;
struct Obj;
struct Actor;
struct Vec2;
struct PtS;
typedef unsigned char u8;

struct Record { u8 a, b, c, d, e, f; };

typedef unsigned int   u32_021BE3B4;

typedef unsigned short u16;

typedef unsigned u32_021BE44C;

typedef unsigned int   u32_021BE49C;

typedef signed short   s16;

typedef signed char    s8;

typedef unsigned int  u32_021BE4B4;

typedef unsigned int u32_021BE564;

typedef unsigned int   u32_021BE7E4;

typedef signed int     s32;

typedef unsigned int   u32_021BE820;

typedef unsigned int  u32_021BE8F8;

typedef unsigned int  u32_021BE9D4;

typedef unsigned int  u32_021BEA54;

typedef unsigned int  u32_021BEB0C;

typedef unsigned int  u32_021BEB8C;

typedef unsigned int u32_021BEC60;

typedef enum { off_ECB8 = 0x1c4 } Offset;

typedef unsigned int   u32_021BED2C;

typedef unsigned int   u32_021BED68;

typedef unsigned int   u32_021BED98;

typedef unsigned int   u32_021BEDE0;

typedef unsigned int   u32_021BEE04;

typedef unsigned int   u32_021BEE14;

typedef unsigned int u32_021BEE94;

typedef struct { u32_021BEE94 w[7]; } Tbl;

typedef unsigned int u32_021BEEC4;

struct Res021BEEC4 {
    u8 pad[0x10C];
    int a[6];
    int b[6];
    int c[4];
};

extern int func_02012BF8(int a0, int a1);
extern void func_02012BE0(void *, unsigned, unsigned);
extern void func_02045088(unsigned short);
extern unsigned func_020450F0(unsigned, unsigned, unsigned, unsigned, u8, u8, u8);
extern u32_021BE3B4 func_020452E8(struct Descriptor *d);
extern void func_020450C8(void);
extern unsigned func_0201C4E4(struct PrintSys *);
extern void *func_02045770(struct Descriptor *);
extern unsigned func_0201C6C4(struct PrintSys *, void *);
extern void func_02045334(struct Descriptor *);
extern void *func_02045EC0(struct MsgBank *, u32_021BE44C);
extern void func_021B6AE4(u8 *p, void *a, u16 b, u16 c, u32_021BE44C s0, u32_021BE44C s1, u16 s2, u32_021BE44C s3);
extern void func_02045808(struct U16Vec *);
extern void func_02045374(struct Cfg *cfg);
extern u8 func_02045730(struct Descriptor *p);
extern void func_02041B6C(u32_021BE49C);
extern u16 func_021BCF00(int a0, int a1);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern u32_021BE564 func_0201D304(struct StrObj *s, u32_021BE564 a, u32_021BE564 b);
extern u32_021BEC60 func_021B9394(char *p);
extern u8 func_02045738(struct Descriptor *p);
extern void func_021BF0DC(struct Obj021BF0DC *p);
extern void func_020434DC(u32_021BED2C mask, u32_021BED2C enable);
extern void func_02043598(u32_021BED2C mask, u32_021BED2C enable);
extern void func_021BF370(int p);
extern void func_021BF080(u8 *p);
extern void func_0204A5AC(void);
extern u32_021BED68 func_0204B944(struct Obj *p);
extern void func_0204B8D4(struct Obj *p, u32_021BED68 arg);
extern void func_0204A600(void);
extern void func_0204B8C4(struct Obj *p, u32_021BED98 value);
extern void func_0204B878(struct Obj *p, u16 value);
extern void func_0204B92C(struct Obj *p, unsigned int v);
extern u16 func_0204B898(struct Obj *p);
extern u32_021BEDE0 func_0204B98C(struct Actor *a);
extern void func_0204B3DC(struct Obj *p, unsigned int v);
extern u32_021BEE04 func_0204B3F4(struct Obj *p);
extern void func_0204B688(struct Actor *actor, u32_021BEE14 value);
extern void func_0204B404(struct Obj *p, const struct Vec2 *delta, u32_021BEE14 which);
extern void func_0204B454(struct Actor *actor, struct PtS *out, u16 space);
extern void func_0204B84C(int h, unsigned v);
extern void *func_021BC3E8(void);
extern void func_0204A48C(const struct Cfg *cfg, u32_021BEE94 arg, u32_021BEE94 heapId);
extern void *func_020490F4(u32_021BEEC4 id, u32_021BEEC4 heap);
extern int func_0204A6C8(void *arc, u32_021BEEC4 idx, u32_021BEEC4 a, u32_021BEEC4 b, u16 heap);
extern int func_0204ABF0(void *arc, u32_021BEEC4 idx, u32_021BEEC4 a, u32_021BEEC4 b, u16 heap);
extern int func_0204AF28(void *arc, u32_021BEEC4 a, u32_021BEEC4 b, u32_021BEEC4 heap);
extern void func_02049238(void *arc);
extern u32_021BEEC4 func_020275E4(void);
extern u32_021BEEC4 func_02027618(void);
extern u32_021BEEC4 func_02027614(void);
extern u32_021BEEC4 func_0202761C(u32_021BEEC4 a);
extern u32_021BEEC4 func_02027620(u32_021BEEC4 a);
void func_021BE324(u8 *p);
void func_021BE368(u8 *p);
void func_021BE3B4(char *p);
void func_021BE3D4(u8 *p);
void func_021BE44C(u8 *p, int slot, u32_021BE44C message, int x, int y, u16 color, u32_021BE44C mode);
void func_021BE49C(u8 *p);
void func_021BE4B4(u8 *p);
void func_021BE564(u8 *p);
void func_021BE7E4(u8 *p);
void func_021BE820(u8 *p);
void func_021BE83C(u8 *p);
void func_021BE8B8(u8 *p);
void func_021BE8F8(u8 *p);
void func_021BE978(u8 *p);
void func_021BE9D4(u8 *p);
void func_021BEA54(u8 *p);
void func_021BEB0C(u8 *p);
void func_021BEB8C(u8 *p);
void func_021BEBE8(u8 *p);
void func_021BEC60(int p, int *a, u32_021BEC60 b);
void func_021BECAC(int a, unsigned *p);
void func_021BECB8(u8 *p, unsigned message);
void func_021BECF8(void *a);
void func_021BED04(void *a);
void func_021BED10(void *a);
void func_021BED1C(int p);
void func_021BED2C(int p);
void func_021BED54(int p);
void func_021BED68(int p);
void func_021BED98(char *p, int idx, int v);
void func_021BEDB8(int p, int i, int v);
int func_021BEDD0(int p, int i);
int func_021BEDE0(int a0, int a1);
void func_021BEDF0(int p, int i, int v);
int func_021BEE04(int p, int i);
void func_021BEE14(char *p, int idx, int flag);
void func_021BEE38(char *p, int idx, int a, short b, unsigned short c);
void func_021BEE58(char *p, int idx, short *outA, short *outB, unsigned short in);
void func_021BEE80(int p, int i, unsigned v);
void func_021BEE94(void);
void func_021BEEC4(struct Res021BEEC4 *p);
extern const struct Record d_021C0900[];
extern const Tbl d_021C0990;

/*
 * tail: 021BE366..021BE368 is zero alignment padding.
 * proof: 071CC forwards to 0319A4, which forwards fixed r1=0x36 to
 *        033B68; their full matched bodies use no incoming r2/r3.
 * ABI: 02012BF8's full 20-byte body preserves r1 across EC0/C404 and
 *      supplies only r0/r1 to C44C. EC0 reads only r0; C404 forwards r0
 *      through C40C/071CC with fixed r1=0x36. C44C reads r0/r1 only.
 *      Legacy trailing a2/a3 are omitted; all original visible inputs remain.
 */
void func_021BE324(u8 *p)
{
    if (func_02012BF8((int)(**(void ** *)&((struct Obj10921 *)p)->f0), 16) == 1) {
        func_02012BE0(**(void ** *)&((struct Obj10921 *)p)->f0, 16, 0);
        func_021BEDB8((int)p, 4, 6);
    } else {
        func_02012BE0(**(void ** *)&((struct Obj10921 *)p)->f0, 16, 1);
        func_021BEDB8((int)p, 4, 7);
    }
}

void func_021BE368(u8 *p)
{
    unsigned i;
    func_02045088(123);
    for (i = 0; i < 16; i++) {
        const struct Record *r = &d_021C0900[i];
        *(unsigned *)(p + i * 8 + 0x14c) = func_020450F0(r->a, r->b, r->c, r->d, r->e, r->f, 1);
    }
    func_021BE4B4(p);
}


void func_021BE3B4(char *p)
{
    unsigned int i;
    for (i = 0; i < 0x10; i++)
    {
        func_020452E8(*(void **)(p + 0x14c + i * 8));
    }
    func_020450C8();
}

/*
 * lever: each int offset is assigned 0x1DC, then its final literal;
 *        spilled locals retain both stores without a reload.
 * note 2026-10-05 (wave D9r lane 131): removed the 4 dead first assignments
 * (`release = 0x1dc;` before `release = 0x14c;`; `clear = 0x1dc;` before
 * `clear = 0x150;` and 2 more). Game code has no line table, so these were
 * stand-ins. The plain single assignment gives EXACT in --lang c99 and
 * --lang c: the output bytes do not change. Older text in this header that
 * asks for the double assignment is superseded.
 */
void func_021BE3D4(u8 *p)
{
    int release, clear, get, flag;
    unsigned i;
    func_0201C4E4(*(struct PrintSys * *)&((struct Obj08413 *)p)->f1DC);
    release = 0x14c;
    clear = 0x150;
    get = 0x14c;
    flag = 0x150;
    for (i = 0; i < 16; i++) {
        struct PrintSys *ps = *(struct PrintSys * *)&((struct Obj08413 *)p)->f1DC;
        u8 *record = p + i * 8;
        if (record[flag] != 0 && func_0201C6C4(ps, func_02045770(*(struct Descriptor **)(record + get))) == 0) {
            func_02045334(*(struct Descriptor **)(record + release));
            record[clear] = 0;
        }
    }
}

void func_021BE44C(u8 *p, int slot, u32_021BE44C message, int x, int y, u16 color, u32_021BE44C mode)
{
    struct U16Vec *text = func_02045EC0(*(struct MsgBank * *)&((struct Obj00222 *)p)->f1D0, message);
    func_021B6AE4(p + 0x14c + slot * 8, (void *)(((struct Obj00222 *)p)->f1DC), x, y, (u32_021BE44C)text, ((struct Obj00222 *)p)->f1CC, color, mode);
    func_02045808(text);
}


/*
 * Addresses are Black-image addresses.
 */
void func_021BE49C(u8 *p)
{
    func_02045374((struct Cfg *)(((struct Obj14680 *)p)->f0));
    func_02041B6C(func_02045730((struct Descriptor *)(((struct Obj14680 *)p)->f0)));
}


void func_021BE4B4(u8 *p)
{
    if (*(u8 *)(*(u32_021BE4B4 *)(*(u32_021BE4B4 *)&((struct Obj00222 *)p)->f0 + 8)) == 0)
        func_021BE44C(p, 0, 0x12, 0, 4, 0x3C40, 0);
    else
        func_021BE44C(p, 0, 0x11, 0, 4, 0x3C40, 0);
    func_021BE44C(p, 2, 0xC, 0x28, 4, 0x3C40, 2);
    func_021BE44C(p, 3, 0xD, 0x28, 4, 0x3C40, 2);
    func_021BE44C(p, 4, 0xE, 0x28, 4, 0x3C40, 2);
    func_021BE44C(p, 5, 0xF, 0x28, 4, 0x3C40, 2);
    func_021BE44C(p, 6, 0x10, 0x28, 4, 0x3C40, 2);
    func_021BE44C(p, 0xB, 0x14, 0x28, 4, 0x3C40, 2);
}


static inline u8 *Bytes021BE564(u8 *p)
{
    return *(u8 * *)&((struct Obj25618 *)(*(u8 * *)&((struct Obj25617 *)p)->f0))->f8;
}


void func_021BE564(u8 *p)
{
    u32_021BE564 v;
    u32_021BE564 s1;
    u32_021BE564 s2;
    u32_021BE564 s3;
    u8 w;
    u8 x;

    func_021BE49C(p + 0x14C);
    func_021BE49C(p + 0x15C);
    func_021BE49C(p + 0x164);
    func_021BE49C(p + 0x16C);
    func_021BE49C(p + 0x174);
    func_021BE49C(p + 0x17C);
    func_021BE49C(p + 0x1A4);
    func_021BE7E4(p);

    func_02043B5C((struct CharBuf *)((u32_021BE564)func_02045770((struct Descriptor *)((struct Obj00222 *)p)->f184)), 0);
    func_021BE44C(p, 7, Bytes021BE564(p)[1] + 0x19, 0x28, 4, 0x3C40, 2);
    func_021BE49C(p + 0x184);

    func_02043B5C((struct CharBuf *)((u32_021BE564)func_02045770((struct Descriptor *)((struct Obj00222 *)p)->f18C)), 0);
    v = Bytes021BE564(p)[2];
    if (v == 0xFF)
        func_021BE44C(p, 8, 0x5F, 8, 4, 0x3C40, 2);
    else
        func_021BE44C(p, 8, v + 0x33, 8, 4, 0x3C40, 2);
    func_021BE49C(p + 0x18C);

    func_02043B5C((struct CharBuf *)((u32_021BE564)func_02045770((struct Descriptor *)((struct Obj00222 *)p)->f194)), 0);
    if (Bytes021BE564(p)[3] == 0xFF) {
        func_021BE44C(p, 9, 0x30, 0x40, 4, 0x3C40, 2);
    } else if (Bytes021BE564(p)[4] == 0xFF) {
        func_021BE44C(p, 9, func_021BCF00((int)p, Bytes021BE564(p)[3]), 0x40, 4, 0x3C40, 2);
    } else {
        s1 = (u32_021BE564)func_02045EC0((struct MsgBank *)(*(u32_021BE564 *)&((struct Obj00222 *)p)->f1D0), 0x31);
        func_021B6AE4(p + 0x194, (void *)(((struct Obj00222 *)p)->f1DC), 0x42, 4, s1, ((struct Obj00222 *)p)->f1CC, 0x3C40, 2);
        w = func_0201D304((struct StrObj *)s1, ((struct Obj00222 *)p)->f1CC, 0);
        func_02045808((struct U16Vec *)s1);
        x = 0x40 - (u8)(w / 2);
        s2 = (u32_021BE564)func_02045EC0((struct MsgBank *)(*(u32_021BE564 *)&((struct Obj00222 *)p)->f1D0), func_021BCF00((int)p, Bytes021BE564(p)[3]));
        func_021B6AE4(p + 0x194, (void *)(((struct Obj00222 *)p)->f1DC), x + 2, 4, s2, ((struct Obj00222 *)p)->f1CC, 0x3C40, 1);
        func_02045808((struct U16Vec *)s2);
        x += w;
        s3 = (u32_021BE564)func_02045EC0((struct MsgBank *)(*(u32_021BE564 *)&((struct Obj00222 *)p)->f1D0), func_021BCF00((int)p, Bytes021BE564(p)[4]));
        func_021B6AE4(p + 0x194, (void *)(((struct Obj00222 *)p)->f1DC), x + 2, 4, s3, ((struct Obj00222 *)p)->f1CC, 0x3C40, 0);
        func_02045808((struct U16Vec *)s3);
    }
    func_021BE49C(p + 0x194);

    func_02043B5C((struct CharBuf *)((u32_021BE564)func_02045770((struct Descriptor *)((struct Obj00222 *)p)->f19C)), 0);
    v = Bytes021BE564(p)[5];
    if (v == 0xFF)
        func_021BE44C(p, 10, 0x6A, 0x28, 4, 0x3C40, 2);
    else
        func_021BE44C(p, 10, v + 0x60, 0x28, 4, 0x3C40, 2);
    func_021BE49C(p + 0x19C);
}


void func_021BE7E4(u8 *p)
{
    u32_021BE7E4 z = 0;

    func_02043B5C((struct CharBuf *)((u32_021BE7E4)func_02045770((struct Descriptor *)*(u32_021BE7E4 *)&((struct Obj00222 *)p)->f154)), 0);
    func_021BE44C(p, 1, 1, 0, 4, 0x440, z);
    func_021BE49C(p + 0x154);
}


void func_021BE820(u8 *p)
{
    func_02043B5C((struct CharBuf *)((u32_021BE820)func_02045770((struct Descriptor *)((struct Obj14681 *)p)->f154)), 0);
    func_02045334((struct Descriptor *)((struct Obj14681 *)p)->f154);
}

void func_021BE83C(u8 *p)
{
    func_021BE49C(p + 0x14c);
    func_02043B5C(func_02045770(*(struct Descriptor * *)&((struct Obj00222 *)p)->f154), 0);
    func_021BE44C(p, 1, 4, 0, 4, 0x440, 0);
    func_021BE49C(p + 0x154);
    func_02043B5C(func_02045770(*(struct Descriptor * *)&((struct Obj00222 *)p)->f1AC), 0);
    func_021BE44C(p, 12, 12, 40, 0, 0x3c40, 2);
    func_021BE49C(p + 0x1ac);
    func_021BE8B8(p);
}

void func_021BE8B8(u8 *p)
{
    func_02043B5C(func_02045770(*(struct Descriptor * *)&((struct Obj00222 *)p)->f1B4), 0);
    func_021BE44C(p, 13, (*(u8 **)(*(u8 * *)&((struct Obj00222 *)p)->f0 + 8))[1] + 25, 48, 0, 0x3c40, 2);
    func_021BE49C(p + 0x1b4);
}


void func_021BE8F8(u8 *p)
{
    func_021BE49C(p + 0x14C);
    func_02043B5C((struct CharBuf *)((u32_021BE8F8)func_02045770((struct Descriptor *)*(u32_021BE8F8 *)&((struct Obj00222 *)p)->f154)), 0);
    func_021BE44C(p, 1, 5, 0, 4, 0x440, 0);
    func_021BE49C(p + 0x154);
    func_02043B5C((struct CharBuf *)((u32_021BE8F8)func_02045770((struct Descriptor *)*(u32_021BE8F8 *)&((struct Obj00222 *)p)->f1AC)), 0);
    func_021BE44C(p, 0xC, 0xD, 0x28, 0, 0x3C40, 2);
    func_021BE49C(p + 0x1AC);
    func_021BE978(p);
}

/*
 * tail: 021BE9D2..021BE9D4 is zero alignment padding.
 */
void func_021BE978(u8 *p)
{
    unsigned message;
    func_02043B5C(func_02045770(*(struct Descriptor * *)&((struct Obj00222 *)p)->f1B4), 0);
    message = (*(u8 **)(*(u8 * *)&((struct Obj00222 *)p)->f0 + 8))[2];
    if (message != 255) func_021BE44C(p, 13, message + 51, 48, 0, 0x3c40, 2);
    else func_021BE44C(p, 13, 95, 48, 0, 0x3c40, 2);
    func_021BE49C(p + 0x1b4);
}


void func_021BE9D4(u8 *p)
{
    func_021BE49C(p + 0x14C);
    func_02043B5C((struct CharBuf *)((u32_021BE9D4)func_02045770((struct Descriptor *)*(u32_021BE9D4 *)&((struct Obj00222 *)p)->f154)), 0);
    func_021BE44C(p, 1, 6, 0, 4, 0x440, 0);
    func_021BE49C(p + 0x154);
    func_02043B5C((struct CharBuf *)((u32_021BE9D4)func_02045770((struct Descriptor *)*(u32_021BE9D4 *)&((struct Obj00222 *)p)->f1AC)), 0);
    func_021BE44C(p, 0xC, 0xE, 0x28, 0, 0x3C40, 2);
    func_021BE49C(p + 0x1AC);
    func_021BEA54(p);
}


void func_021BEA54(u8 *p)
{
    u8 c;

    func_02043B5C((struct CharBuf *)((u32_021BEA54)func_02045770((struct Descriptor *)*(u32_021BEA54 *)&((struct Obj00222 *)p)->f1B4)), 0);
    func_02043B5C((struct CharBuf *)((u32_021BEA54)func_02045770((struct Descriptor *)((struct Obj00222 *)p)->f1BC)), 0);
    c = ((u8 *)*(u32_021BEA54 *)(*(u32_021BEA54 *)&((struct Obj00222 *)p)->f0 + 8))[3];
    if (c != 0xFF)
        func_021BE44C(p, 0xD, func_021BCF00((int)p, c), 0x30, 0, 0x3C40, 2);
    else
        func_021BE44C(p, 0xD, 0x30, 0x30, 0, 0x3C40, 2);
    c = ((u8 *)*(u32_021BEA54 *)(*(u32_021BEA54 *)&((struct Obj00222 *)p)->f0 + 8))[4];
    if (c != 0xFF)
        func_021BE44C(p, 0xE, func_021BCF00((int)p, c), 0x30, 0, 0x3C40, 2);
    else
        func_021BE44C(p, 0xE, 0x30, 0x30, 0, 0x3C40, 2);
    func_021BE49C(p + 0x1B4);
    func_021BE49C(p + 0x1BC);
}


void func_021BEB0C(u8 *p)
{
    func_021BE49C(p + 0x14C);
    func_02043B5C((struct CharBuf *)((u32_021BEB0C)func_02045770((struct Descriptor *)*(u32_021BEB0C *)&((struct Obj00222 *)p)->f154)), 0);
    func_021BE44C(p, 1, 8, 0, 4, 0x440, 0);
    func_021BE49C(p + 0x154);
    func_02043B5C((struct CharBuf *)((u32_021BEB0C)func_02045770((struct Descriptor *)*(u32_021BEB0C *)&((struct Obj00222 *)p)->f1AC)), 0);
    func_021BE44C(p, 0xC, 0xF, 0x28, 0, 0x3C40, 2);
    func_021BE49C(p + 0x1AC);
    func_021BEB8C(p);
}


void func_021BEB8C(u8 *p)
{
    u32_021BEB8C v;
    u8 *b;

    func_02043B5C((struct CharBuf *)((u32_021BEB8C)func_02045770((struct Descriptor *)*(u32_021BEB8C *)&((struct Obj00222 *)p)->f1B4)), 0);
    b = (u8 *)*(u32_021BEB8C *)(*(u32_021BEB8C *)&((struct Obj00222 *)p)->f0 + 8);
    v = b[5];
    if (v != 0xFF)
        func_021BE44C(p, 0xD, v + 0x60, 0x30, 0, 0x3C40, 2);
    else
        func_021BE44C(p, 0xD, 0x6A, 0x30, 0, 0x3C40, 2);
    func_021BE49C(p + 0x1B4);
}


void func_021BEBE8(u8 *p)
{
    func_021BE49C(p + 0x14c);
    func_02043B5C(func_02045770(*(struct Descriptor * *)&((struct Obj00222 *)p)->f154), 0);
    func_021BE44C(p, 1, 7, 0, 4, 0x440, 0);
    func_021BE49C(p + 0x154);
    func_02043B5C(func_02045770(*(struct Descriptor * *)&((struct Obj00222 *)p)->f1AC), 0);
    func_021BE44C(p, 12, 16, 40, 0, 0x3c40, 2);
    func_021BE49C(p + 0x1ac);
}


void func_021BEC60(int p, int *a, u32_021BEC60 b)
{
    u32_021BEC60 x = func_021B9394(*(char * *)&((struct Obj04620 *)p)->f1E0);

    func_021B6AE4((u8 *)a, (void *)x, (u16)(func_02045738((struct Descriptor *)(*a)) * 8 / 2), 4, b,
                  ((struct Obj04620 *)p)->f1CC, 0x39e0, 2);
}


void func_021BECAC(int a, unsigned *p)
{
    func_02045334((struct Descriptor *)*p);
}

void func_021BECB8(u8 *p, unsigned message)
{
    Offset offset = off_ECB8;
    func_02043B5C(func_02045770(*(struct Descriptor **)(p + offset)), 6);
    func_021BE44C(p, 15, message, 120, 0, 0x446, 2);
    func_021BE49C(p + offset);
}


void func_021BECF8(void *a)
{
    func_021BECB8((u8 *)a, 0xb);
}


void func_021BED04(void *a)
{
    func_021BECB8((u8 *)a, 9);
}


void func_021BED10(void *a)
{
    func_021BECB8((u8 *)a, 0xa);
}


void func_021BED1C(int p)
{
    func_021BE49C((u8 *)(p + 0x1a4));
}


void func_021BED2C(int p)
{
    func_021BEE94();
    func_021BEEC4((struct Res021BEEC4 *)p);
    func_021BF0DC((struct Obj021BF0DC *)p);
    func_020434DC(0x10, 1);
    func_02043598(0x10, 1);
}


void func_021BED54(int p)
{
    func_021BF370(p);
    func_021BF080((u8 *)p);
    func_0204A5AC();
}


void func_021BED68(int p)
{
    unsigned i;

    for (i = 0; i < 0x39; i++) {
        int *q = (int *)(p + i * 4);

        if (q[0xa] != 0 && func_0204B944((struct Obj *)q[0xa]) != 1)
            func_0204B8D4((struct Obj *)q[0xa], 0x1000);
    }
    func_0204A600();
}


void func_021BED98(char *p, int idx, int v)
{
    func_0204B8C4(*(void **)(p + 0x28 + idx * 4), 0);
    func_0204B878(*(void **)(p + 0x28 + idx * 4), (unsigned short)v);
}


void func_021BEDB8(int p, int i, int v)
{
    func_021BED98((char *)p, i, v);
    func_0204B92C((struct Obj *)((int *)(p + i * 4))[0xa], 1);
}


int func_021BEDD0(int p, int i)
{
    return func_0204B898((struct Obj *)(((int *)(p + i * 4))[0xa]));
}


int func_021BEDE0(int a0, int a1)
{
    int *p = (int *)(a0 + a1 * 4);

    return func_0204B98C((struct Actor *)p[0xa]);
}


void func_021BEDF0(int p, int i, int v)
{
    int h = ((int *)(p + i * 4))[0xa];

    if (h != 0)
        func_0204B3DC((struct Obj *)h, v);
}


int func_021BEE04(int p, int i)
{
    return func_0204B3F4((struct Obj *)(((int *)(p + i * 4))[0xa]));
}


void func_021BEE14(char *p, int idx, int flag)
{
    if (flag == 1)
    {
        func_0204B688(*(void **)(p + 0x28 + idx * 4), 1);
    }
    else
    {
        func_0204B688(*(void **)(p + 0x28 + idx * 4), 0);
    }
}


void func_021BEE38(char *p, int idx, int a, short b, unsigned short c)
{
    unsigned short buf[2];
    buf[0] = a;
    buf[1] = b;
    func_0204B404(*(void **)(p + idx * 4 + 0x28), (const struct Vec2 *)buf, c);
}


void func_021BEE58(char *p, int idx, short *outA, short *outB, unsigned short in)
{
    short buf[2];
    func_0204B454(*(void **)(p + idx * 4 + 0x28), (struct PtS *)buf, in);
    *outA = buf[0];
    *outB = buf[1];
}


void func_021BEE80(int p, int i, unsigned v)
{
    func_0204B84C(((int *)(p + i * 4))[0xa], (unsigned char)v);
}


void func_021BEE94(void)
{
    Tbl tbl = d_021C0990;

    func_0204A48C((const struct Cfg *)(&tbl), (u32_021BEE94)func_021BC3E8(), 0x7b);
}


void func_021BEEC4(struct Res021BEEC4 *p)
{
    u32_021BEEC4 i;
    void *arc;
    void *arc2;

    for (i = 0; i < 6; i++)
        p->a[i] = -1;
    for (i = 0; i < 6; i++)
        p->b[i] = -1;
    for (i = 0; i < 4; i++)
        p->c[i] = -1;

    arc = func_020490F4(0x9F, 0x807B);
    p->a[1] = func_0204A6C8(arc, 0x4E, 0, 0, 0x7B);
    p->b[1] = func_0204ABF0(arc, 0x4B, 0, 0, 0x7B);
    p->c[1] = func_0204AF28(arc, 0x54, 0x64, 0x7B);
    p->a[2] = func_0204A6C8(arc, 0x4E, 0, 1, 0x7B);
    p->b[2] = func_0204ABF0(arc, 0x4B, 1, 0, 0x7B);
    p->a[5] = func_0204A6C8(arc, 0x4D, 0, 0, 0x7B);
    p->b[5] = func_0204ABF0(arc, 0x48, 0, 0x60, 0x7B);
    p->c[3] = func_0204AF28(arc, 0x53, 0x63, 0x7B);
    p->a[3] = func_0204A6C8(arc, 0x52, 0, 0, 0x7B);
    p->b[3] = func_0204ABF0(arc, 0x4C, 0, 0x80, 0x7B);
    p->c[2] = func_0204AF28(arc, 0x55, 0x65, 0x7B);
    p->a[4] = func_0204A6C8(arc, 0x52, 0, 1, 0x7B);
    p->b[4] = func_0204ABF0(arc, 0x4C, 1, 0x60, 0x7B);
    func_02049238(arc);

    arc2 = func_020490F4(func_020275E4(), 0x807B);
    p->a[0] = func_0204A6C8(arc2, func_02027618(), 0, 0, 0x7B);
    p->b[0] = func_0204ABF0(arc2, func_02027614(), 0, 0xA0, 0x7B);
    p->c[0] = func_0204AF28(arc2, func_0202761C(2), func_02027620(2), 0x7B);
    func_02049238(arc2);
}
