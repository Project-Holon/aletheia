/*
 * file:     un_select_p04.c
 * unit:     yes
 * function: func_021B9A80, func_021B9AD0, func_021B9AE4, func_021B9B78, func_021B9C00
 * address:  0x021B9A80
 * region:   ov218
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0201CE48 0x0201CE48 thumb
 *   func_020452E8 0x020452E8 arm
 *   func_02045808 0x02045808 arm
 *   func_02045C04 0x02045C04 arm
 *   func_0201C4C0 0x0201C4C0 thumb
 *   func_0201D83C 0x0201D83C thumb
 *   func_02031140 0x02031140 arm
 *   func_0201ED04 0x0201ED04 thumb
 *   func_020307B0 0x020307B0 arm
 *   func_0201C4E4  0x0201C4E4  thumb
 *   func_020310C4  0x020310C4  arm
 *   func_02045CAC 0x02045CAC arm
 *   func_0201EFA4 0x0201EFA4 thumb
 *   func_0201F250 0x0201F250 thumb
 *   func_021B6AE4 0x021B6AE4 thumb ov067
 *   func_0201D2C8 0x0201D2C8 thumb
 *   func_02012FFC 0x02012FFC thumb
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_0201DD78 0x0201DD78 thumb
 *   func_0201CCE4 0x0201CCE4 thumb
 *   func_0201F73C 0x0201F73C thumb
 *   func_02045334 0x02045334 arm
 *   func_02045374 0x02045374 arm
 *   func_02045730 0x02045730 arm
 *   func_02041B6C 0x02041B6C arm
 *   func_0201CE30 0x0201CE30 thumb
 *   func_0201CE38 0x0201CE38 thumb
 *   func_0201CE5C 0x0201CE5C thumb
 *   func_020362DC 0x020362DC arm
 *   func_0203630C 0x0203630C arm
 *   func_02035C60 0x02035C60 arm
 *   func_02035C38 0x02035C38 arm
 *   func_020061E4 0x020061E4 thumb
 */
#include "../../matched/include/Obj02264.h"
#include "../../matched/include/Obj14771.h"
#include "../../matched/include/Obj02265.h"
#include "../../matched/include/Obj05563.h"

struct Rec3;
struct Descriptor;
struct U16Vec;
struct Rec;
struct PrintSys;
struct S02031140;
struct WordSet;
struct Tcbl;
struct MsgBank;
struct StrObj;
struct CharBuf;
struct Cfg;
typedef unsigned int   u32;

typedef unsigned char u8;

typedef unsigned short u16;

extern void func_0201CE48(struct Rec3 *);
extern unsigned int func_020452E8(struct Descriptor *d);
extern void func_02045808(struct U16Vec *);
extern unsigned int func_02045C04(struct Rec *rec);
extern void func_0201C4C0(struct PrintSys *);
extern unsigned int func_0201D83C(void *ptr);
extern void func_02031140(struct S02031140 *);
extern unsigned int func_0201ED04(struct WordSet *p);
extern u32 func_020307B0(void *p);
extern u32 func_0201C4E4(struct PrintSys *ps);
extern void func_020310C4(struct Tcbl *p);
extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
extern void func_0201EFA4(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern void func_021B6AE4(u8 *p, void *a, u16 b, u16 c, u32 s0, u32 s1, u16 s2, u32 s3);
extern u32 func_0201D2C8(struct StrObj *s);
extern signed char func_02012FFC(void);
extern void *func_02045770(struct Descriptor *);
extern void func_02043B5C(struct CharBuf *, u8);
extern void func_0201DD78(u32, u32, u32);
extern u32 func_0201CCE4(u32, u32, u32, u32, u32, u32, u32, u32, u16, u16);
extern void func_0201F73C(void *, int, int, int);
extern void func_02045334(struct Descriptor *);
extern void func_02045374(struct Cfg *);
extern u8 func_02045730(struct Descriptor *);
extern void func_02041B6C(u32);
extern unsigned int func_0201CE30(void *);
extern void func_0201CE38(void *);
extern void func_0201CE5C(struct Rec *, int);
extern u32 func_020362DC(void);
extern unsigned int func_0203630C(void);
extern int func_02035C60(void);
extern int func_02035C38(void);
extern void func_020061E4(unsigned int);
void func_021B9A80(char *p);
void func_021B9AD0(char *p);
void func_021B9AE4(u8 *p, u8 *a, void *b, unsigned long long cd);
void func_021B9B78(char *p, u32 id);
int func_021B9C00(char *p);

void func_021B9A80(char *p)
{
    if (*(struct Rec3 * *)&((struct Obj02264 *)p)->f20 != 0) {
        func_0201CE48(*(struct Rec3 * *)&((struct Obj02264 *)p)->f20);
        *(struct Rec3 * *)&((struct Obj02264 *)p)->f20 = 0;
    }
    func_020452E8(*(struct Descriptor * *)&((struct Obj02264 *)p)->f28);
    func_020452E8(*(struct Descriptor * *)&((struct Obj02264 *)p)->f24);
    func_02045808(*(struct U16Vec * *)&((struct Obj02264 *)p)->f18);
    func_02045808(*(struct U16Vec * *)&((struct Obj02264 *)p)->f1C);
    func_02045C04(*(struct Rec * *)&((struct Obj02264 *)p)->f8);
    func_0201C4C0(*(struct PrintSys * *)&((struct Obj02264 *)p)->f10);
    func_0201D83C(((struct Obj02264 *)p)->fC);
    func_02031140(*(struct S02031140 * *)&((struct Obj02264 *)p)->f4);
    func_0201ED04(*(struct WordSet * *)&((struct Obj02264 *)p)->f14);
    func_020307B0(p);
}


void func_021B9AD0(char *p)
{
    func_0201C4E4((struct PrintSys *)(((struct Obj14771 *)p)->f10));
    func_020310C4((struct Tcbl *)(((struct Obj14771 *)p)->f4));
}

void func_021B9AE4(u8 *p, u8 *a, void *b, unsigned long long cd)
{
    u32 c = (u32)cd; u32 d = (u32)(cd >> 32);
    u32 r = 12;
    u32 t = 0x83 - d;
    func_02045CAC(*(void **)(p + 8), (t == 2) ? 0xF0 : 0xED, *(void **)(p + 0x18));
    func_0201EFA4(*(void **)(p + 0x14), 2, t, 3, 0, 1);
    func_0201F250(*(void **)(p + 0x14), *(void **)(p + 0x1C), *(void **)(p + 0x18));
    func_021B6AE4(a, b, 0, 12, *(u32 *)(p + 0x1C), c, 0x39E0, 0);
    p += 0x2C;
    if (func_0201D2C8((struct StrObj *)(*(u32 *)(p + d * 4))) > 1) r = 4;
    func_021B6AE4(a, b, 0x1E, r, *(u32 *)(p + d * 4), c, 0x39E0, 0);
}

void func_021B9B78(char *p, u32 id)
{
    int value = func_02012FFC();
    struct Descriptor *obj = *(struct Descriptor * *)&((struct Obj02265 *)p)->f24;
    func_02043B5C(func_02045770(obj), 15);
    func_0201DD78(1, 2, 15);
    func_02045CAC(*(struct MsgBank * *)&((struct Obj02265 *)p)->f8, id, ((struct Obj02265 *)p)->f18);
    func_0201F250(*(struct WordSet * *)&((struct Obj02265 *)p)->f14, ((struct Obj02265 *)p)->f1C, ((struct Obj02265 *)p)->f18);
    ((struct Obj02265 *)p)->f20 = func_0201CCE4((u32)obj, 4, 0, *(u32 *)&((struct Obj02265 *)p)->f1C, ((struct Obj02265 *)p)->fC, value, ((struct Obj02265 *)p)->f4, 65535, ((struct Obj02265 *)p)->f0, 15);
    func_0201F73C(((struct Obj02265 *)p)->f24, 2, 1, 15);
    func_02045334(obj);
    func_02045374((struct Cfg *)obj);
    func_02041B6C(func_02045730(obj));
}

int func_021B9C00(char *p)
{
    if (((struct Obj05563 *)p)->f20 != 0) {
        switch (func_0201CE30(((struct Obj05563 *)p)->f20)) {
        case 2:
            func_0201CE48(*(struct Rec3 * *)&((struct Obj05563 *)p)->f20);
            ((struct Obj05563 *)p)->f20 = 0;
            return 1;
        case 1:
            if (func_020362DC() == 1 || func_020362DC() == 2 || func_02035C60() != 0) {
                func_0201CE38(((struct Obj05563 *)p)->f20);
                func_020061E4(1356);
            }
            break;
        case 0:
            if (((unsigned int)func_0203630C() & 3) != 0 || func_02035C38() != 0)
                func_0201CE5C(*(struct Rec * *)&((struct Obj05563 *)p)->f20, 0);
            break;
        }
        return 0;
    }
    return 0;
}
