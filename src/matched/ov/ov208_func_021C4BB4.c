/*
 * function: ov208_func_021C4BB4
 * address: 0x021C4BB4
 * packet: pkt_ov208_021C4BB4
 * region: ov208
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0201C6EC 0x0201C6EC thumb
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   ov208_func_021BC3C0 0x021BC3C0 thumb ov208
 *   func_02045EC0 0x02045EC0 arm
 *   func_0201D304 0x0201D304 thumb
 *   func_020437DC 0x020437DC arm
 *   func_0201C724 0x0201C724 thumb
 *   func_02045808 0x02045808 arm
 *   func_0201EC64 0x0201EC64 thumb
 *   func_020457B0 0x020457B0 arm
 *   func_0201EFA4 0x0201EFA4 thumb
 *   func_0201F250 0x0201F250 thumb
 *   func_0201ED04 0x0201ED04 thumb
 *   ov208_func_021C4B60 0x021C4B60 thumb ov208
 *   data_020A7370 0x020A7370 data a4
 */
#include "../include/Obj01179.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef signed short   s16;
typedef unsigned int   u32;

struct Descriptor; struct MsgBank; struct StrObj; struct Bmp; struct U16Vec; struct WordSet;

struct Ov208Menu {
    u8  pad0[4];
    u32 font;
    u8  pad8[0x554 - 8];
    struct Descriptor *win[5];
    u32 active[5];
    u32 print[5];
};

struct PrintSys;
extern void func_0201C6EC(struct PrintSys *p);
extern void *func_02045770(struct Descriptor *d);
struct CharBuf;
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern u16 ov208_func_021BC3C0(int key);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern u32 func_0201D304(struct StrObj *s, u32 a, u32 b);
extern u16 func_020437DC(const struct Bmp *bmp);
extern void func_0201C724(void *owner, u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern void func_02045808(struct U16Vec *s);
extern struct WordSet *func_0201EC64(u32 heap);
extern struct U16Vec *func_020457B0(u32 size, u32 heap);
extern void func_0201EFA4(struct WordSet *ws, u32 a, u32 b, u32 c, u32 d, u32 e);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern u32 func_0201ED04(struct WordSet *p);
extern void ov208_func_021C4B60(u16 *heap, struct Ov208Menu *p, int key, int i);
extern struct MsgBank *data_020A7370;

void ov208_func_021C4BB4(u16 *heap, struct Ov208Menu *p, int key)
{
    u8 i;
    u16 species;
    u16 width;
    struct Bmp *bmp;
    struct Bmp *bmp2;
    struct StrObj *text;
    struct WordSet *ws;
    struct WordSet *ws2;
    struct U16Vec *str;
    void *src;
    void *src2;
    for (i = 0; i <= 1; i++) {
        p->active[i] = 0;
        func_0201C6EC((struct PrintSys *)p->print[i]);
        func_02043B5C(func_02045770(p->win[i]), 0);
    }
    species = ov208_func_021BC3C0(key);
    bmp = func_02045770(p->win[0]);
    text = func_02045EC0(data_020A7370, species);
    width = func_0201D304(text, p->font, 0);
    func_0201C724((void *)p->print[0], (u32)bmp, (s16)((u16)((func_020437DC(bmp) - width) / 2)), (s16)1, (u32)text, p->font, 0x3c40);
    p->active[0] = 1;
    func_02045808((struct U16Vec *)text);
    bmp2 = func_02045770(p->win[1]);
    ws = func_0201EC64(*heap);
    src = ((struct Obj01179 *)p)->f59C;
    str = func_020457B0(8, *heap);
    func_0201EFA4(ws, 0, ((struct Obj01179 *)p)->f54A, 2, 1, 1);
    func_0201F250(ws, str, src);
    func_0201C724((void *)p->print[1], (u32)bmp2, (s16)0, (s16)1, (u32)str, p->font, 0x3c40);
    func_02045808(str);
    func_0201ED04(ws);
    ws2 = func_0201EC64(*heap);
    src2 = ((struct Obj01179 *)p)->f5A0;
    str = func_020457B0(8, *heap);
    func_0201EFA4(ws2, 0, ((struct Obj01179 *)p)->f54C, 2, 1, 1);
    func_0201F250(ws2, str, src2);
    func_0201C724((void *)p->print[1], (u32)bmp2, (s16)0, (s16)0x11, (u32)str, p->font, 0x3c40);
    func_02045808(str);
    func_0201ED04(ws2);
    p->active[1] = 1;
    for (i = 0; i <= 1; i++)
        ov208_func_021C4B60(heap, p, key, i);
}
