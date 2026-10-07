/*
 * file:     zukan_detail_graphic_p28.c
 * unit:     yes
 * function: func_021C1F50, func_021C1FC4, func_021C1FE0
 * address:  0x021C1F50
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
 *   func_02045EC0  0x02045EC0  arm
 *   func_0201D304  0x0201D304  thumb
 *   func_02045770  0x02045770  arm
 *   func_020437DC  0x020437DC  arm
 *   func_0201C724  0x0201C724  thumb
 *   func_02045808  0x02045808  arm
 *   func_021C0740  0x021C0740  thumb  ov208
 *   func_021C1920 0x021C1920  thumb  ov208
 *   func_0204B3F4 0x0204B3F4 arm
 *   func_0201C6EC 0x0201C6EC thumb
 *   func_02043B5C 0x02043B5C arm
 *   func_02045334 0x02045334 arm
 *   func_0204B3DC 0x0204B3DC arm
 *   func_021C0C8C 0x021C0C8C thumb ov208
 *   func_021C1D30 0x021C1D30 thumb ov208
 *   func_021C2238 0x021C2238 thumb ov208
 */
#include "../../matched/include/Obj00081.h"

#define W(o) (*(u32 *)(p + (o)))
struct MsgBank;
struct Bmp;
struct StrObj;
struct U16Vec;
struct Descriptor;
struct Obj;
struct PrintSys;
struct CharBuf;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef short          s16;

extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern u32 func_0201D304(struct StrObj *s, u32 a, u32 b);
extern void *func_02045770(struct Descriptor *p);
extern u16 func_020437DC(const struct Bmp *bmp);
extern void func_0201C724(void *owner, u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern void func_02045808(struct U16Vec *vec);
extern void func_021C0740(u16 *heap, u8 *p, int key, u8 i);
extern void func_021C1920(u16 *heap, u8 *p, int key, int mode);
extern unsigned func_0204B3F4(struct Obj *);
extern void func_0201C6EC(struct PrintSys *);
extern void func_02043B5C(struct CharBuf *, u8);
extern void func_02045334(struct Descriptor *);
extern void func_0204B3DC(struct Obj *, unsigned);
extern void func_021C0C8C(u16 *, u8 *, int, int);
extern void func_021C1D30(u16 *, u8 *, int);
extern void func_021C2238(u16 *, u8 *, int);
void func_021C1F50(u16 *heap, u8 *p, int key);
void func_021C1FC4(void *a, char *b, int c);
void func_021C1FE0(u16 *heap, u8 *p, int key);


void func_021C1F50(u16 *heap, u8 *p, int key)
{
    void *str;
    u16 tw;
    u32 w;

    str = func_02045EC0((struct MsgBank *)W(0xc), p[0x78] + 0xbe);
    tw = func_0201D304(str, W(4), 0);
    w = func_020437DC(func_02045770((struct Descriptor *)W(0x1c)));
    func_0201C724((void *)W(0x3c), (u32)func_02045770((struct Descriptor *)W(0x1c)), (s16)((u16)((int)(w - tw) / 2)), (s16)1, (u32)str, W(4), 0x3c40);
    func_02045808(str);
    W(0x2c) = 1;
    func_021C0740(heap, p, key, 2);
}


/*
 * Dispatches on the word at +0x6C: state 0 hands a 3, state 5 hands an 8 to func_021C1920.
 */
void func_021C1FC4(void *a, char *b, int c)
{
    int s = ((struct Obj00081 *)b)->f6C;

    if (s == 0) {
        func_021C1920(a, (u8 *)b, c, 3);
        return;
    }
    if (s == 5) {
        func_021C1920(a, (u8 *)b, c, 8);
    }
}

void func_021C1FE0(u16 *heap, u8 *p, int key)
{
    u8 i;
    if (func_0204B3F4(*(struct Obj * *)&((struct Obj00081 *)p)->fC8)) {
        if (((struct Obj00081 *)p)->f90 == 1) {
            ((struct Obj00081 *)p)->f30 = 0;
            func_0201C6EC(*(struct PrintSys * *)&((struct Obj00081 *)p)->f40);
            func_02043B5C(func_02045770(*(struct Descriptor * *)&((struct Obj00081 *)p)->f20), 0);
            func_02045334(*(struct Descriptor * *)&((struct Obj00081 *)p)->f20);
            func_0204B3DC(*(struct Obj * *)&((struct Obj00081 *)p)->fC8, 0);
        }
    } else {
        for (i = 0; i < 61; i++) func_0204B3DC(*(struct Obj **)(p + i * 4 + 0xdc), 0);
        if (((struct Obj00081 *)p)->f90 == 0) {
            func_021C0C8C(heap, p, key, 0);
            p[0x79] = 255;
            func_0204B3DC(*(struct Obj * *)&((struct Obj00081 *)p)->fCC, 0);
            func_0204B3DC(*(struct Obj * *)&((struct Obj00081 *)p)->fD0, 0);
            func_021C1D30(heap, p, key);
            func_021C2238(heap, p, key);
        }
    }
}
