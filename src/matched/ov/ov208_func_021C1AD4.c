/*
 * function: func_021C1AD4
 * address:  0x021C1AD4
 * packet:   pkt_ov208_021C1AD4
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021BC3C0  0x021BC3C0  thumb  ov208
 *   func_021C1F44  0x021C1F44  thumb  ov208
 *   func_021C1F28  0x021C1F28  thumb  ov208
 *   func_0204B3DC  0x0204B3DC  arm
 *   func_021C0C00  0x021C0C00  thumb  ov208
 *   func_021BC3A4  0x021BC3A4  thumb  ov208
 *   func_0200CA1C  0x0200CA1C  thumb
 *   func_0200CC40  0x0200CC40  thumb
 *   func_021C0B6C  0x021C0B6C  thumb  ov208
 *   func_0201C6EC  0x0201C6EC  thumb
 *   func_02045770  0x02045770  arm
 *   func_02043B5C  0x02043B5C  arm
 *   func_0201EC64  0x0201EC64  thumb
 *   func_02045EC0  0x02045EC0  arm
 *   func_020457B0  0x020457B0  arm
 *   func_0201EE60  0x0201EE60  thumb
 *   func_0201F250  0x0201F250  thumb
 *   func_02045808  0x02045808  arm
 *   func_0201ED04  0x0201ED04  thumb
 *   func_0201C724  0x0201C724  thumb
 *   func_021C0740  0x021C0740  thumb  ov208
 *   func_02045334  0x02045334  arm
 *   func_021C1F50  0x021C1F50  thumb  ov208
 *   func_0204B878  0x0204B878  arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct {
    u8 f0;
    u8 f1;
    u8 rest[0x3c];
} Entry;

extern u16  func_021BC3C0(int key);
struct CharBuf;
struct U16Vec;
struct WordSet;
extern void func_021C1F44(int a);
extern Entry *func_021C1F28(u32 a, u32 b, u32 c);
struct Obj;
extern void func_0204B3DC(struct Obj *obj, unsigned int on);
extern void func_021C0C00(u32 a, u32 b);
extern int  func_021BC3A4(int key);
extern void *func_0200CA1C(int a);
extern void func_0200CC40(u8 *p, u16 id, u32 *out1, u32 *out2, u32 *outForm, u16 a5);
extern u32 func_021C0B6C(u32 *slot, u32 a, u32 b, u32 res, u16 heap, u32 species, u32 form, u32 gender, u32 isEgg, u8 x, u8 y);
extern void func_0201C6EC(u32 a);
struct Descriptor;
extern void *func_02045770(struct Descriptor *p);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern struct WordSet *func_0201EC64(u32 heap);
extern void *func_02045EC0(u32 bank, u32 index);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern void func_0201EE60(struct WordSet *p, u32 i, u16 v);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern void func_02045808(struct U16Vec *vec);
extern void func_0201ED04(struct WordSet *p);
extern void func_0201C724(u32 a, void *b, u32 c, u32 d, void *e, u32 f, u16 g);
extern void func_021C0740(u16 *heap, u8 *p, int key, u8 i);
extern void func_02045334(u32 p);
extern void func_021C1F50(u16 *heap, u8 *p, int key);
extern void func_0204B878(u32 obj, u32 anim);

#define W(o) (*(u32 *)(p + (o)))
#define SLOT4C(i) (((u32 *)(p + 0x4c))[i])
#define SLOT5C(i) (((u32 *)(p + 0x5c))[i])

void func_021C1AD4(u16 *heap, u8 *p, int key)
{
    u32 prev;
    u16 id;
    void *win;
    void *str;
    void *buf;
    u32 out1, out2, form;

    prev = W(0x8c);
    id = func_021BC3C0(key);
    func_021C1F44(W(0x94));
    W(0x94) = (u32)func_021C1F28(id, *heap, W(0x40c));
    W(0x8c) = ((Entry *)W(0x94))->f0 == 0;
    if (W(0x8c) == 0)
        W(0x90) = ((Entry *)W(0x94))[0].f1 == 0;
    else
        W(0x90) = ((Entry *)W(0x94))[p[0x78]].f1 == 0;

    if (SLOT5C(*(int *)(p + 0x64)) != 0)
        func_0204B3DC((struct Obj *)SLOT5C(*(int *)(p + 0x64)), 0);
    *(int *)(p + 0x64) = (*(int *)(p + 0x64) + 1) % 2;
    if (SLOT5C(*(int *)(p + 0x64)) != 0) {
        if (SLOT5C(*(int *)(p + 0x64)) != 0)
            func_021C0C00(SLOT4C(*(int *)(p + 0x64)), SLOT5C(*(int *)(p + 0x64)));
        SLOT5C(*(int *)(p + 0x64)) = 0;
    }

    func_0200CC40(func_0200CA1C(func_021BC3A4(key)), id, &out1, &out2, &form, *heap);
    SLOT5C(*(int *)(p + 0x64)) = func_021C0B6C(&SLOT4C(*(int *)(p + 0x64)), W(0x54), W(0x58), W(0),
                                               *heap, id, form, out1, 0, 0x38, 0xb0);
    W(0x24) = 0;
    func_0201C6EC(W(0x34));
    func_02043B5C(func_02045770((struct Descriptor *)W(0x14)), 0);
    win = func_0201EC64(*heap);
    str = func_02045EC0(W(0xc), 0xbd);
    buf = func_020457B0(0x40, *heap);
    func_0201EE60(win, 0, id);
    func_0201F250(win, buf, str);
    func_02045808(str);
    func_0201ED04(win);
    func_0201C724(W(0x34), func_02045770((struct Descriptor *)W(0x14)), 0, 5, buf, W(4), 0x3c40);
    func_02045808(buf);
    W(0x24) = 1;
    func_021C0740(heap, p, key, 0);

    if (W(0x8c) == 0) {
        if (prev == 1) {
            W(0x2c) = 0;
            func_0201C6EC(W(0x3c));
            func_02043B5C(func_02045770((struct Descriptor *)W(0x1c)), 0);
            func_02045334(W(0x1c));
            func_0204B3DC((struct Obj *)W(0xbc), 0);
            func_0204B3DC((struct Obj *)W(0xc4), 0);
            func_0204B3DC((struct Obj *)W(0xc0), 0);
        }
    } else if (prev == 0) {
        func_021C1F50(heap, p, key);
        func_0204B3DC((struct Obj *)W(0xbc), 1);
        func_0204B878(W(0xc4), 2);
        func_0204B3DC((struct Obj *)W(0xc4), 1);
        func_0204B878(W(0xc0), 4);
        func_0204B3DC((struct Obj *)W(0xc0), 1);
    }
}
