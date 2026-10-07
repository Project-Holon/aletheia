/*
 * file:     pmsiv_category_p02.c
 * unit:     yes
 * function: func_021BB3F4, func_021BB4F4
 * address:  0x021BB3F4
 * region:   ov110
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   d_021C38C4 0x021C38C4 data ov110 a1
 *   func_021BAC44 0x021BAC44 thumb ov110
 *   func_021B999C 0x021B999C thumb ov110
 *   func_02045B38 0x02045B38 arm
 *   func_02045EC0 0x02045EC0 arm
 *   func_0201DD78 0x0201DD78 thumb
 *   func_020450F0 0x020450F0 arm
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_0201D304 0x0201D304 thumb
 *   func_0201C7A4 0x0201C7A4 thumb
 *   func_02045374 0x02045374 arm
 *   func_02045334 0x02045334 arm
 *   func_02045808 0x02045808 arm
 *   func_02045C04 0x02045C04 arm
 *   func_020457B0 0x020457B0 arm
 *   func_021BB1F4 0x021BB1F4 thumb ov110
 *   func_021BB1F8 0x021BB1F8 thumb ov110
 *   func_021BB224 0x021BB224 thumb ov110
 */
#include "../../matched/include/Obj03240.h"

struct Cfg;
struct CharBuf;
struct Descriptor;
struct MsgBank;
struct Rec;
struct StrObj;
struct U16Vec;
typedef unsigned char u8;

typedef unsigned int u32;

typedef signed short s16_021BB3F4;

typedef short s16_021BB4F4;

extern u32 func_021BAC44(u8 *);
extern u32 func_021B999C(u8 *, int);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void func_0201DD78(u32, u32, u32);
extern u32 func_020450F0(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
extern void *func_02045770(struct Descriptor *p);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern u32 func_0201D304(struct StrObj *s, u32 a, u32 b);
extern void func_0201C7A4(void *, s16_021BB3F4, s16_021BB3F4, void *, void *);
extern void func_02045374(struct Cfg *cfg);
extern void func_02045334(struct Descriptor *d);
extern void func_02045808(struct U16Vec *vec);
extern u32 func_02045C04(struct Rec *rec);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern int func_021BB1F4(void);
extern void func_021BB1F8(u32,void *);
extern void func_021BB224(u32,int *,int *);
u8 *func_021BB3F4(u8 *p, u8 *q);
u8 *func_021BB4F4(u8 *p,u8 *q);
extern const u8 d_021C38C4[];

u8 *func_021BB3F4(u8 *p, u8 *q)
{
    int x, y;
    void *bank;
    u32 font;
    int i;
    void *str, *win;
    u32 width;
    font = func_021BAC44(*(u8 * *)&((struct Obj03240 *)p)->f0);
    bank = func_02045B38(0, 2, 145, 42);
    x = 1;
    y = 9;
    for (i = 0; i < 12; i++) {
        if (i != 0 && i % 3 == 0) { x = 1; y += 3; }
        if (func_021B999C(*(u8 * *)&((struct Obj03240 *)p)->f8, i)) {
            str = func_02045EC0(bank, d_021C38C4[i]);
            func_0201DD78(1, 2, 15);
        } else {
            str = func_02045EC0(bank, 13);
            func_0201DD78(3, 4, 15);
        }
        win = (void *)func_020450F0(1, (u8)x, (u8)y, 9, 2, 12, 1);
        func_02043B5C(func_02045770(win), 15);
        width = 72 - func_0201D304(str, font, 0);
        func_0201C7A4(func_02045770(win), width >> 1, 0, str, (void *)font);
        func_02045374(win);
        func_02045334(win);
        func_02045808(str);
        *(void **)(p + i * 4 + 0x60) = win;
        q += 18;
        x += 10;
    }
    func_02045C04(bank);
    return q;
}

/*
 * extent: trailing two-byte zero padding
 * lever: signed loop counter; string pointer declared before counter.
 */
u8 *func_021BB4F4(u8 *p,u8 *q) {
    u32 n,w,a;
    void *str;
    int i;
    int x,y;
    w=func_021BAC44(*(u8 * *)&((struct Obj03240 *)p)->f0);
    a=func_020450F0(1,1,8,30,14,12,1);
    str=func_020457B0(4,42);
    func_02043B5C(func_02045770((struct Descriptor *)a),15);
    n=func_021BB1F4();
    for(i=0;i<n;i++) {
        func_021BB1F8(i,str);
        func_021BB224(i,&x,&y);
        func_0201DD78(1,2,15);
        func_0201C7A4(func_02045770((struct Descriptor *)a),x+5,y,str,(void *)w);
    }
    func_02045334((struct Descriptor *)a);
    func_02045808(str);
    p+=0x90;
    *(u32 *)&((struct Obj03240 *)p)->f0=a;
    return q+0x1a4;
}
