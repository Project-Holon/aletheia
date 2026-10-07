/*
 * file:     gsync_state_p02.c
 * unit:     yes
 * function: func_021D4A04, func_021D4A64, func_021D4AB4, func_021D4AFC, func_021D4B44, func_021D4BA8, func_021D4C24, func_021D4C4C, func_021D4CA0, func_021D4CBC, func_021D4D40, func_021D4DA4, func_021D4E34, func_021D4E64, func_021D4E7C, func_021D4EF0
 * address:  0x021D4A04
 * region:   ov123
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021D45F4 0x021D45F4 thumb ov123
 *   func_02051B84 0x02051B84 arm
 *   func_021D4778 0x021D4778 thumb ov123
 *   func_021DA9C0 0x021DA9C0 data a4
 *   d_021DA640 0x021DA640 data a4
 *   d_021DA648 0x021DA648 data a4
 *   func_021D4244 0x021D4244 thumb ov123
 *   func_0201DD68 0x0201DD68 thumb
 *   func_021D4730 0x021D4730 thumb ov123
 *   func_02040DA8 0x02040DA8 arm
 *   func_0203FB44 0x0203FB44 arm
 *   func_020403F4 0x020403F4 arm
 *   func_02045C04 0x02045C04 arm
 *   func_0201D83C 0x0201D83C thumb
 *   func_02045808 0x02045808 arm
 *   func_020221A4 0x020221A4 thumb
 *   func_02012138 0x02012138 thumb
 *   func_02026454 0x02026454 thumb
 *   func_02035C60 0x02035C60 arm
 *   func_020061E4 0x020061E4 thumb
 *   func_0204B92C 0x0204B92C arm
 *   func_0204BA00 0x0204BA00 arm
 *   func_0204B9A0 0x0204B9A0 arm
 *   func_021D451C 0x021D451C thumb ov123
 *   func_021D45F0 0x021D45F0 thumb ov123
 *   func_0204B878 0x0204B878 arm
 *   func_0204B898 0x0204B898 arm
 *   func_02051C88  0x02051C88  arm
 *   func_02021518 0x02021518 thumb
 *   func_0202155C 0x0202155C thumb
 *   func_020216D4 0x020216D4 thumb
 *   func_02021FD8 0x02021FD8 thumb
 *   func_02021730 0x02021730 thumb
 *   func_020862F0 0x020862F0 arm
 *   func_0207E5D0 0x0207E5D0 arm
 *   func_0207E468 0x0207E468 arm
 *   func_020215A0 0x020215A0 thumb
 *   func_02021540 0x02021540 thumb
 *   func_02082D44 0x02082D44 arm
 *   func_020457B0 0x020457B0 arm
 *   func_02045CAC 0x02045CAC arm
 *   func_02027778 0x02027778 thumb
 *   func_02027CD8 0x02027CD8 thumb
 *   func_0202F038 0x0202F038 thumb
 *   func_0201F7A8 0x0201F7A8 thumb
 *   func_020456F8 0x020456F8 arm
 *   func_02041B6C 0x02041B6C arm
 *   func_020452E8  0x020452E8  arm
 *   func_020286C4 0x020286C4 thumb
 *   func_0201CE30 0x0201CE30 thumb
 *   func_0201CE48 0x0201CE48 thumb
 *   func_0201CE38 0x0201CE38 thumb
 *   func_0201CE5C 0x0201CE5C thumb
 *   func_02035C38 0x02035C38 arm
 *   func_020450F0 0x020450F0 arm
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_0201DD78 0x0201DD78 thumb
 *   func_02012FFC 0x02012FFC thumb
 *   func_0201CCE4 0x0201CCE4 thumb
 *   func_0201C7A4 0x0201C7A4 thumb
 *   func_0201F73C 0x0201F73C thumb
 *   func_02045334 0x02045334 arm
 *   func_02045374 0x02045374 arm
 */
#include "../../matched/include/Obj10434.h"
#include "../../matched/include/Obj01543.h"
#include "../../matched/include/Obj13969.h"
#include "../../matched/include/Obj00273.h"
#include "../../matched/include/Obj10435.h"
#include "../../matched/include/Obj06458.h"
#include "../../matched/include/Obj05360.h"
#include "../../matched/include/Obj13970.h"
#include "../../matched/include/Obj00626.h"
#include "../../matched/include/Obj04495.h"
#include "../../matched/include/Obj02473.h"

struct Rec;
struct U16Vec;
struct Ctx;
struct Actor;
struct Obj;
struct Cmd;
struct PalAnmSlot;
struct Chan02021FD8;
struct MsgBank;
struct TaskMenu;
struct TaskMenuTmpl;
struct Descriptor;
struct Rec3;
struct Cfg;
struct CharBuf;
typedef unsigned short u16;

typedef unsigned char  u8;

typedef unsigned int u32;

typedef struct { u16 value; char *object; void (*callback)(char *); } Callback;

typedef signed int     s32;

typedef struct { u32 heap; u8 mode; void *data; int flag; u8 a,b,c,d; } Descriptor;

typedef signed short   s16;

extern void func_021D45F4(int, void *, char *, void *, void *, void *);
extern void *func_02051B84(u8 *a0, int a1, int a2, int a3);
extern void func_021D4778(void);
extern void func_021D4244(char *, void *, int);
extern void func_0201DD68(void);
extern void func_021D4730(char *);
extern void func_02040DA8(u32 idx, u32 count, u32 tile);
extern void func_0203FB44(u32 layer, u32 offset, u32 size);
extern void func_020403F4(u32 i);
extern u32 func_02045C04(struct Rec *rec);
extern u32 func_0201D83C(void *ptr);
extern void func_02045808(struct U16Vec *vec);
extern u32 func_020221A4(void);
extern u32 func_02012138(const struct Ctx *p);
extern u32 func_02026454(void *obj);
extern int func_02035C60(void);
extern void func_020061E4(u32 a);
extern void func_0204B92C(struct Obj *p, u32 v);
extern void func_0204BA00(struct Actor *a, const struct Cmd *cmd);
extern void func_0204B9A0(struct Actor *a);
extern void func_021D451C(char *);
extern void func_021D45F0(void);
extern void func_0204B878(struct Obj *p, u16 value);
extern u16 func_0204B898(struct Obj *);
extern s32 func_02051C88(struct Ctx *c);
extern void *func_02021518(u32 heap);
extern void func_0202155C(struct PalAnmSlot *slots, u32 idx, u32 size, u32 heap);
extern void func_020216D4(struct PalAnmSlot *slots, u32 bank, u32 off, u32 size);
extern void func_02021FD8(struct Chan02021FD8 *p, u32 idx, u32 c, u32 count, u8 weight, u16 color);
extern int func_02021730(char *p, int i);
extern void func_020862F0(void *, int);
extern void func_0207E5D0(void *, int, int);
extern void func_0207E468(void *, int, int);
extern void func_020215A0(struct PalAnmSlot *slots, u32 idx);
extern u32 func_02021540(void *a0);
extern void func_02082D44(void *, void *, int);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
extern struct TaskMenu *func_02027778(struct TaskMenuTmpl *tmpl, void *arg1);
extern int func_02027CD8(int a0, int a1);
extern void func_0202F038(u8 *);
extern void func_0201F7A8(void *,u32);
extern void func_020456F8(struct Descriptor *);
extern void func_02041B6C(u32);
extern u32 func_020452E8(struct Descriptor *d);
extern void func_020286C4(struct Ctx *ctx, void *p, void *cell);
extern u32 func_0201CE30(void *p);
extern void func_0201CE48(struct Rec3 *p);
extern void func_0201CE38(void *);
extern void func_0201CE5C(struct Rec *p, s32 v);
extern int func_02035C38(void);
extern u32 func_020450F0(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
extern void *func_02045770(struct Descriptor *p);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_0201DD78(u32 r, u32 g, u32 b);
extern signed char func_02012FFC(void);
extern void *func_0201CCE4(void *, int, int, void *, void *, void *, void *, int, u16, int);
extern void func_0201C7A4(void *x, s16 y, s16 z, void *s, void *w);
extern void func_0201F73C(void *a0, int a1, int a2, int a3);
extern void func_02045334(struct Descriptor *d);
extern void func_02045374(struct Cfg *cfg);
void func_021D4A04(char *p);
void func_021D4A64(char *p);
void func_021D4AB4(char *p);
void func_021D4AFC(char *p);
void func_021D4B44(char *p);
int func_021D4BA8(int n, char *p);
void func_021D4C24(u8 *p, int v);
void func_021D4C4C(char *p);
void func_021D4CA0(char *p);
void func_021D4CBC(char *p, int n, int count);
void func_021D4D40(char *p, int flag);
void func_021D4DA4(char *p);
void func_021D4E34(u8 *p);
void func_021D4E64(u8 *p);
int func_021D4E7C(char *p);
void func_021D4EF0(char *p, int n, int flag);
extern char func_021DA9C0[];
extern int d_021DA640[];
extern int d_021DA648[];

void func_021D4A04(char *p)
{
    struct { int value; } zero = {0};
    func_021D45F4(1, &zero, p, func_021DA9C0, d_021DA640, d_021DA640 + 1);
    ((struct Obj10434 *)p)->f20 = func_02051B84((u8 *)d_021DA648, (int)func_021D4778, (int)p, ((struct Obj10434 *)p)->fC);
    ((struct Obj10434 *)p)->f4 = func_021D4BA8;
    func_021D4244(p, func_021D4CA0, 0x321);
}

void func_021D4A64(char *p)
{
    func_0201DD68();
    func_021D4730(p);
    func_02040DA8(5, 1, 0);
    func_0203FB44((int)5, (u16)(((struct Obj01543 *)p)->f3C), (u16)(((struct Obj01543 *)p)->f3C >> 16));
    func_020403F4(5);
    func_020403F4(4);
    func_02045C04(((struct Obj01543 *)p)->f24);
    func_02045C04(((struct Obj01543 *)p)->f28);
    func_0201D83C(((struct Obj01543 *)p)->f30);
    func_02045808(((struct Obj01543 *)p)->f38);
}

void func_021D4AB4(char *p)
{
    if (func_020221A4() != 0) {
        switch (((struct Obj13969 *)p)->f8) {
        case 2:
        case 3:
            if (func_02026454((void *)func_02012138(((struct Obj13969 *)p)->f264)) == 0)
                func_021D4244(p, 0, 0x345);
            break;
        default:
            func_021D4244(p, 0, 0x349);
            break;
        }
    }
}

void func_021D4AFC(char *p)
{
    if (func_021D4E7C(p) != 0 && func_02035C60() != 0) {
        func_021D4E64((u8 *)p);
        ((struct Obj00273 *)p)->f27C = 0;
        func_020061E4(0x73b);
        func_021D4D40(p, 0);
        func_021D4244(p, func_021D4A04, 0x360);
    }
}

/*
 * evidence: callback 0x021D45F0 resolved by its verified ov123 shard.
 */
void func_021D4B44(char *p)
{
    Callback cb;
    cb.value = 0;
    cb.object = p;
    cb.callback = func_021D451C;
    func_0204B92C(*(void **)(p + ((struct Obj10435 *)p)->f270 * 4 + 0x2a0), 1);
    func_0204BA00(*(void **)(p + ((struct Obj10435 *)p)->f270 * 4 + 0x2a0), (const struct Cmd *)(&cb));
    func_0204B9A0(*(void **)(p + ((struct Obj10435 *)p)->f270 * 4 + 0x2a0));
    func_021D4244(p, func_021D45F0, 0x376);
}

int func_021D4BA8(int n, char *p)
{
    ((struct Obj06458 *)p)->f270 = n;
    switch (n) {
    case 0:
        func_020061E4(0x73b);
        func_0204B878(((struct Obj06458 *)p)->f2A0, 14);
        func_021D4244(p, func_021D4B44, 0x389);
        ((struct Obj06458 *)p)->f8 = 2;
        break;
    case 1:
        func_020061E4(0x73b);
        ((struct Obj06458 *)p)->f8 = 3;
        func_021D4244(p, func_021D4B44, 0x393);
        break;
    case 2:
        func_020061E4(0x73c);
        ((struct Obj06458 *)p)->f8 = 0;
        func_021D4244(p, func_021D4B44, 0x399);
        break;
    }
    return 1;
}

void func_021D4C24(u8 *p, int v) { if(v!=func_0204B898(*(struct Obj * *)&((struct Obj05360 *)p)->f2A0)) { func_0204B92C(*(struct Obj * *)&((struct Obj05360 *)p)->f2A0,1); func_0204B878(*(struct Obj * *)&((struct Obj05360 *)p)->f2A0,v); } }

void func_021D4C4C(char *p)
{
    u32 keys = ((struct Obj05360 *)p)->f278;
    if (keys != ((struct Obj05360 *)p)->f27C) {
        if (keys & 0x40) func_021D4C24((u8 *)p, 0x18);
        else if (keys & 0x80) func_021D4C24((u8 *)p, 0x16);
        else if (keys & 0x100) func_021D4C24((u8 *)p, 0x15);
        else if (keys & 0x200) func_021D4C24((u8 *)p, 0x15);
        else func_021D4C24((u8 *)p, 0xe);
    }
}


/*
 * Addresses are Black-image addresses.
 */
void func_021D4CA0(char *p)
{
    if (func_020221A4() != 0)
        func_02051C88(((struct Obj05360 *)p)->f20);
    func_021D4C4C(p);
}

/*
 * extent: two zero padding bytes at 0x021D4D3E before next labelled function.
 */
void func_021D4CBC(char *p, int n, int count)
{
    void *obj;
    void *buffer;
    int bytes;
    obj = func_02021518(((struct Obj13970 *)p)->fC);
    func_0202155C(obj, n, 0x200, ((struct Obj13970 *)p)->fC);
    bytes = count * 32;
    func_020216D4(obj, n, 0, bytes);
    func_02021FD8(obj, (int)n, (int)0, (u16)(count * 16), (int)6, (int)0);
    buffer = (void *)func_02021730(obj, n);
    func_020862F0(buffer, bytes);
    switch (n) {
    case 3: func_0207E5D0(buffer, 0, bytes); break;
    case 1: func_0207E468(buffer, 0, bytes); break;
    }
    func_020215A0(obj, n);
    func_02021540(obj);
}

void func_021D4D40(char *p, int flag)
{
    if (flag) {
        func_02082D44((void *)0x05000600, ((struct Obj00273 *)p)->f280, 0x200);
        func_02082D44((void *)0x05000400, ((struct Obj00273 *)p)->f284, 0x200);
        func_021D4CBC(p, 3, 14);
        func_021D4CBC(p, 1, 9);
    } else {
        func_0207E5D0(((struct Obj00273 *)p)->f280, 0, 0x1c0);
        func_0207E468(((struct Obj00273 *)p)->f284, 0, 0x120);
    }
}

void func_021D4DA4(char *p)
{
    Descriptor desc;
    desc.heap = ((struct Obj00626 *)p)->fC;
    desc.mode = 2;
    desc.data = p + 0x23c;
    desc.flag = 1;
    desc.a = 32;
    desc.b = 14;
    desc.c = 13;
    desc.d = 3;
    ((struct Obj00626 *)p)->f23C = func_020457B0(100, ((struct Obj00626 *)p)->fC);
    func_02045CAC(((struct Obj00626 *)p)->f24, 4, ((struct Obj00626 *)p)->f23C);
    ((struct Obj00626 *)p)->f240 = 0x39e0;
    ((struct Obj00626 *)p)->f248 = func_020457B0(100, ((struct Obj00626 *)p)->fC);
    func_02045CAC(((struct Obj00626 *)p)->f24, 5, ((struct Obj00626 *)p)->f248);
    ((struct Obj00626 *)p)->f24C = 0x39e0;
    ((struct Obj00626 *)p)->f238 = func_02027778((struct TaskMenuTmpl *)(&desc), ((struct Obj00626 *)p)->f254);
    func_02027CD8((int)(((struct Obj00626 *)p)->f238), 1);
    func_02045808(((struct Obj00626 *)p)->f23C);
    func_02045808(((struct Obj00626 *)p)->f248);
}

void func_021D4E34(u8 *p) { if(*(u8 * *)&((struct Obj04495 *)p)->f288) { func_0202F038(*(u8 * *)&((struct Obj04495 *)p)->f288); *(u32 *)&((struct Obj04495 *)p)->f288=0; } func_0201F7A8(((struct Obj04495 *)p)->f224,2); func_020456F8(*(struct Descriptor * *)&((struct Obj04495 *)p)->f224); func_02041B6C(5); }


void func_021D4E64(u8 *p)
{
    func_021D4E34(p);
    func_020452E8(((struct Obj04495 *)p)->f224);
    *(u32 *)&((struct Obj04495 *)p)->f224 = 0;
}

int func_021D4E7C(char *p)
{
    if (((struct Obj00626 *)p)->f228) {
        if (((struct Obj00626 *)p)->f224)
            func_020286C4(((struct Obj00626 *)p)->f22C, ((struct Obj00626 *)p)->f228, ((struct Obj00626 *)p)->f224);
        switch (func_0201CE30(((struct Obj00626 *)p)->f228)) {
        case 2:
            func_0201CE48(((struct Obj00626 *)p)->f228);
            ((struct Obj00626 *)p)->f228 = 0;
            break;
        case 1:
            if (func_02035C60()) {
                func_020061E4(0x547);
                func_0201CE38(((struct Obj00626 *)p)->f228);
            }
            break;
        case 0:
            if (func_02035C38()) func_0201CE5C(((struct Obj00626 *)p)->f228, 0);
            break;
        }
        return 0;
    }
    return 1;
}

void func_021D4EF0(char *p, int n, int flag)
{
    void *obj;
    if (((struct Obj02473 *)p)->f224 == 0)
        ((struct Obj02473 *)p)->f224 = (void *)func_020450F0(5, 1, 3, 30, (u8)n, 13, 1);
    obj = ((struct Obj02473 *)p)->f224;
    func_02043B5C(func_02045770(obj), 15);
    func_0201DD78(1, 2, 15);
    if (flag) {
        void *value;
        value = (void *)func_02012FFC();
        ((struct Obj02473 *)p)->f228 = func_0201CCE4(obj, 0, 0, ((struct Obj02473 *)p)->f38, ((struct Obj02473 *)p)->f30, value, ((struct Obj02473 *)p)->f230, 2, ((struct Obj02473 *)p)->fC, 15);
    } else {
        func_0201C7A4(func_02045770(obj), 0, 0, ((struct Obj02473 *)p)->f38, ((struct Obj02473 *)p)->f30);
    }
    func_0201F73C(obj, 1, (u16)(((struct Obj02473 *)p)->f3C), 12);
    func_02045334(obj);
    func_02045374(obj);
    func_02041B6C(5);
}
